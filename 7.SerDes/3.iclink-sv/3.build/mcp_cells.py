# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause

"""Multicycle constraints for the half_clk_strobe logic, proven on the netlist.

The FIFO pump at 5 Gb/s moves only on clocks with half_clk_strobe high,
every other clock, so its paths may take 2 clocks. Which flops really do
is decided here, on the synthesized netlist (Yosys JSON), not by name:
synthesis moves logic across flops (it turns a RAM's write enable into a
flop that loads every clock, D = strobe & we), so a name says too little.

A flop on CLOCK is proven strobe-only when, for every value of everything
else, with the strobe low:
  - its enable is used: the enable is 0, or
  - its enable is constant: D equals Q.
Each proof expands the cone of the enable (or D) through LUTs and muxes,
up to MAX_DEPTH cells and MAX_LEAVES inputs, and tries every value of its
inputs. Anything not expanded (a flop, a RAM, an adder, the depth limit) is
a free input: it can take any value, which only adds cases. So a proof
never passes wrongly; a flop it cannot prove simply keeps its 1-clock
check.

The proven flops are both launch and capture cells of the 2-clock group:
  set_multicycle_path 2 -setup -from [get_cells {...}] -to [get_cells {...}]
Paths into them from anything else (the strobe flop, the every-clock
logic, the RAMs) keep 1 clock. Needs nextpnr with set_multicycle_path in
--sdc (chili-chips-ba/nextpnr, branch multicycle-sdc).

usage: mcp_cells.py top.json STROBE_NET CLOCK_NET out.sdc
"""

import itertools
import json
import sys

MAX_DEPTH = 4
MAX_LEAVES = 16

LOGIC = {"CC_LUT1", "CC_LUT2", "CC_L2T4", "CC_L2T5", "CC_MX2", "CC_MX4"}


def bits(v):
    """A Yosys parameter value (a binary string) as an int."""
    return int(v, 2) if isinstance(v, str) else int(v)


def evaluate(cell, val):
    """The output of a LUT or mux cell, its input bits from val(port)."""
    t, p = cell["type"], cell.get("parameters", {})
    if t == "CC_LUT1":
        return (bits(p["INIT"]) >> val("I0")) & 1
    if t == "CC_LUT2":
        return (bits(p["INIT"]) >> (2 * val("I1") + val("I0"))) & 1
    if t == "CC_L2T4":
        l00 = (bits(p["INIT_L00"]) >> (2 * val("I1") + val("I0"))) & 1
        l01 = (bits(p["INIT_L01"]) >> (2 * val("I3") + val("I2"))) & 1
        return (bits(p["INIT_L10"]) >> (2 * l01 + l00)) & 1
    if t == "CC_L2T5":
        l02 = (bits(p["INIT_L02"]) >> (2 * val("I1") + val("I0"))) & 1
        l03 = (bits(p["INIT_L03"]) >> (2 * val("I3") + val("I2"))) & 1
        l11 = (bits(p["INIT_L11"]) >> (2 * l03 + l02)) & 1
        return (bits(p["INIT_L20"]) >> (2 * l11 + val("I4"))) & 1
    if t == "CC_MX2":
        return val("D1") if val("S0") else val("D0")
    if t == "CC_MX4":
        return val("D%d" % (2 * val("S1") + val("S0")))
    raise ValueError(t)


class Netlist:
    def __init__(self, path):
        top = json.load(open(path))["modules"]["top"]
        self.cells, self.nets = top["cells"], top["netnames"]
        self.driver = {}  # bit -> (cell name, port)
        for name, c in self.cells.items():
            for port, d in c.get("port_directions", {}).items():
                if d == "output":
                    for b in c["connections"][port]:
                        if isinstance(b, int):
                            self.driver[b] = (name, port)

    def net(self, name):
        bs = self.nets[name]["bits"]
        assert len(bs) == 1 and isinstance(bs[0], int), name
        return bs[0]

    def cone(self, root, stop):
        """The logic cells in the cone of root, and its free inputs."""
        cells, leaves, frontier = {}, set(), [(root, 0)]
        while frontier:
            b, depth = frontier.pop()
            if b in ("0", "1"):  # a constant
                continue
            if not isinstance(b, int) or b in stop:  # an open input, or a stop
                leaves.add(b)
                continue
            name, _ = self.driver.get(b, (None, None))
            c = self.cells.get(name)
            if c is None or c["type"] not in LOGIC or depth >= MAX_DEPTH:
                leaves.add(b)
                continue
            if b in cells:
                continue
            cells[b] = c
            for port, d in c["port_directions"].items():
                if d == "input":
                    for x in self.inputs(name, c, port):
                        frontier.append((x, depth + 1))
        return cells, leaves

    @staticmethod
    def inputs(name, cell, port):
        """A port's bits; an open or x input is a free input of its own."""
        bs = cell["connections"].get(port, [])
        if not bs:
            return [("open", name, port)]
        return [("open", name, port) if b == "x" else b for b in bs]

    def always(self, root, fixed, stop, test, extra=()):
        """True when test(value of root, inputs) holds for every value of
        the free inputs of root's cone and of extra, with fixed set."""
        cells, leaves = self.cone(root, stop)
        free = sorted((leaves | set(extra)) - set(fixed), key=str)
        if len(free) > MAX_LEAVES:
            return False
        for vals in itertools.product((0, 1), repeat=len(free)):
            env = dict(fixed)
            env.update(zip(free, vals))

            def value(b):
                if b == "0" or b == "1":
                    return int(b)
                if b in env:
                    return env[b]
                c = cells[b]
                name = self.driver[b][0]
                env[b] = evaluate(c, lambda port: value(self.inputs(name, c, port)[0]))
                return env[b]

            if not test(value(root), env):
                return False
        return True


def strobe_only(nl, ff, strobe):
    """The proof for one flop: it moves only with the strobe high."""
    p = ff.get("parameters", {})
    en = ff["connections"]["EN"][0]
    en_inv = bits(p.get("EN_INV", "0"))
    stop = {strobe}
    if isinstance(en, int):  # the enable is used: 0 with the strobe low
        return nl.always(en, {strobe: 0}, stop, lambda v, env: (v ^ en_inv) == 0)
    if (int(en) ^ en_inv) == 0:  # never enabled: a constant
        return True
    q, d = ff["connections"]["Q"][0], ff["connections"]["D"][0]
    if not isinstance(d, int):
        return False
    stop.add(q)  # constant enable: D is Q with the strobe low, for either Q
    return nl.always(d, {strobe: 0}, stop, lambda v, env: v == env[q], extra=(q,))


def main():
    path, strobe_net, clock_net, out = sys.argv[1:5]
    nl = Netlist(path)
    strobe, clock = nl.net(strobe_net), nl.net(clock_net)
    proven, other = [], 0
    for name, c in sorted(nl.cells.items()):
        if c["type"] != "CC_DFF" or c["connections"]["CLK"][0] != clock:
            continue
        if strobe_only(nl, c, strobe):
            proven.append(name)
        else:
            other += 1
    for name in proven:
        assert not any(ch in name for ch in " {}[]\\"), "a name SDC cannot hold: " + name
    group = " ".join(proven)
    with open(out, "w") as f:
        f.write("# generated by mcp_cells.py: flops on %s proven to move only with %s\n"
                % (clock_net, strobe_net))
        f.write("# %d flops; %d others on the clock keep 1-clock checks\n" % (len(proven), other))
        f.write("set_multicycle_path 2 -setup -from [get_cells {%s}] -to [get_cells {%s}]\n"
                % (group, group))
    print("mcp_cells: %d flops on %s move only with %s: 2-clock group; %d others: 1 clock"
          % (len(proven), clock_net, strobe_net, other))


if __name__ == "__main__":
    main()
