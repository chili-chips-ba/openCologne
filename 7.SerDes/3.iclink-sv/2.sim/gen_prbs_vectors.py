#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause

"""
Golden vectors for the SV PRBS (1.hw/iclink_prbs*.sv): runs LiteX's own
PRBSTX(20, reverse=True) looped into PRBSRX(20, reverse=True) in Migen
simulation, with bit errors injected on the loop, and writes per clock the
inputs and the outputs. tb_prbs.sv runs the same loop and must match bit
for bit.

  prbs.hex  tx_config rx_config pause tx_i flip | tx_o rx_errors
            (1, 1, 1, 5, 5 | 5, 8 hex digits)

A value a Migen generator writes takes effect at the next clock, so the
outputs are read one iteration later. tx_o is partly combinational: that
read sees the next line's inputs with the registers after this line's,
which tb_prbs.sv reproduces by applying the next inputs just after the edge.

Needs LiteX. Usage: gen_prbs_vectors.py <out dir>
"""

import random
import sys

from migen import Module, Signal
from migen.sim import run_simulation
from litex.soc.cores.prbs import PRBSTX, PRBSRX

WIDTH = 20


class Loop(Module):
    def __init__(self):
        self.tx_config = Signal(2)
        self.rx_config = Signal(2)
        self.pause     = Signal()
        self.tx_i      = Signal(WIDTH)
        self.flip      = Signal(WIDTH)
        self.submodules.tx = PRBSTX(WIDTH, reverse=True)
        self.submodules.rx = PRBSRX(WIDTH, reverse=True)
        self.comb += [
            self.tx.config.eq(self.tx_config),
            self.rx.config.eq(self.rx_config),
            self.rx.pause.eq(self.pause),
            self.tx.i.eq(self.tx_i),
            self.rx.i.eq(self.tx.o ^ self.flip),
        ]


def stimulus():
    rnd = random.Random(2026)
    seq = []
    for cfg in (1, 2, 3):
        for n in range(600):
            flip = 0
            pause = 1 if 450 <= n < 480 else 0
            # no errors while paused: LiteX PRBSRX ignores pause (~False is -1
            # in Python, which makes ~pause wide and never 0); tb_prbs.sv
            # checks pause on its own
            if n in (200, 201, 350) or (n > 400 and not 440 <= n < 490 and rnd.random() < 0.02):
                flip = 1 << rnd.randrange(WIDTH)
            seq.append((cfg, cfg, pause, rnd.randrange(1 << WIDTH), flip))
        for n in range(20):                       # off: pass-through, count cleared
            seq.append((0, 0, 0, rnd.randrange(1 << WIDTH), 0))
    # RX on PRBS7 while TX passes a constant: the idle check floods errors
    for n in range(1200):
        seq.append((0, 1, 0, 0x5A5A5, 0))
    return seq


def main(out):
    dut = Loop()
    seq = stimulus()
    outs = []

    def tb():
        for tcfg, rcfg, pause, tx_i, flip in seq + [(0, 0, 0, 0, 0)]:
            yield dut.tx_config.eq(tcfg)
            yield dut.rx_config.eq(rcfg)
            yield dut.pause.eq(pause)
            yield dut.tx_i.eq(tx_i)
            yield dut.flip.eq(flip)
            yield
            outs.append(((yield dut.tx.o), (yield dut.rx.errors)))

    run_simulation(dut, tb())
    with open(f"{out}/prbs.hex", "w") as f:
        for (tcfg, rcfg, pause, tx_i, flip), (tx_o, err) in zip(seq, outs[1:]):
            f.write(f"{tcfg:01x}{rcfg:01x}{pause:01x}{tx_i:05x}{flip:05x}{tx_o:05x}{err:08x}\n")
    print("prbs.hex:", len(seq), "vectors")


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else ".")
