#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# SerWB packet vectors from LiteICLink's own Packetizer (with CRC), run in
# Migen: random packets in, the word stream out. Part of the interoperability
# proof (1.hw/README.md#interoperability-proof): our packetizer must produce
# these words, bit for bit.
#
# usage: gen_serwb_vectors.py <outdir>
#   serwb_packets.txt  one packet per line: port, word count, data words (hex)
#   serwb_wire.hex     LiteICLink's packetizer output, one 32-bit word per line

import random
import sys

from migen import *
from litex.gen.sim import run_simulation

from liteiclink.serwb.packet import Packetizer

N_PACKETS = 200
PREAMBLE  = 0x5AA55AA5


def make_packets(prng):
    packets = []
    for i in range(N_PACKETS):
        n     = prng.choice([1, 2, 3, 15, 16]) if i < 20 else prng.randint(1, 16)
        words = [prng.getrandbits(32) for _ in range(n)]
        if i % 7 == 3:  # payload words that look like a preamble
            words[prng.randrange(n)] = PREAMBLE
        packets.append((prng.getrandbits(8), words))
    return packets


def main():
    outdir  = sys.argv[1]
    prng    = random.Random(2026)
    packets = make_packets(prng)
    dut     = Packetizer(with_crc=True)
    wire    = []
    done    = []

    def gen():
        for port, words in packets:
            for i, w in enumerate(words):
                yield dut.sink.valid.eq(1)
                yield dut.sink.port.eq(port)
                yield dut.sink.length.eq(4 * len(words))
                yield dut.sink.data.eq(w)
                yield dut.sink.last.eq(i == len(words) - 1)
                yield
                while not (yield dut.sink.ready):
                    yield
        yield dut.sink.valid.eq(0)
        done.append(1)

    def mon():
        yield dut.source.ready.eq(1)
        idle = 0
        while idle < 50:
            yield
            if (yield dut.source.valid):
                wire.append((yield dut.source.data))
                idle = 0
            elif done:
                idle += 1

    run_simulation(dut, [gen(), mon()])

    with open(f"{outdir}/serwb_packets.txt", "w") as f:
        for port, words in packets:
            f.write(f"{port:02x} {len(words):04x} " + " ".join(f"{w:08x}" for w in words) + "\n")
    with open(f"{outdir}/serwb_wire.hex", "w") as f:
        for w in wire:
            f.write(f"{w:08x}\n")
    total = sum(len(w) + 3 for _, w in packets)
    print(f"{len(packets)} packets, {len(wire)} wire words (expected {total})")
    assert len(wire) == total


if __name__ == "__main__":
    main()
