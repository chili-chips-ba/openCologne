#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause

"""
Golden vectors for the SV 8b/10b (1.hw/iclink_8b10b_enc.sv, _dec.sv): runs
LiteX's own Encoder(nwords=2, lsb_first=True) and Decoder(lsb_first=True) in
Migen simulation and writes, per clock, the inputs and the outputs after the
clock edge that takes them in, as RTL sees it (a value a Migen generator
writes takes effect one clock later, so the outputs are read one iteration
later). tb_8b10b.sv applies the same inputs and must match bit for bit.

  enc.hex  d0 k0 d1 k1 | symbol0 symbol1 disparity0 disparity1
  dec.hex  symbol | d k invalid       (all 1024 symbols)

Needs LiteX (python3 -c "import litex"). Usage: gen_8b10b_vectors.py <out dir>
"""

import random
import sys

from migen.sim import run_simulation
from litex.soc.cores.code_8b10b import Encoder, Decoder

K_CODES = [0x1C, 0x3C, 0x5C, 0x7C, 0x9C, 0xBC, 0xDC, 0xFC, 0xF7, 0xFB, 0xFD, 0xFE]


def stimulus():
    rnd = random.Random(8010)
    seq = []
    for d in range(256):                    # every D in both words, two disparities
        seq.append((d, 0, 255 - d, 0))
        seq.append((d, 0, d, 0))
    for kc in K_CODES:                      # every K in both words
        seq.append((kc, 1, rnd.randrange(256), 0))
        seq.append((rnd.randrange(256), 0, kc, 1))
        seq.append((kc, 1, kc, 1))
    for _ in range(4000):                   # random mix
        w = []
        for _ in range(2):
            if rnd.random() < 0.15:
                w += [rnd.choice(K_CODES), 1]
            else:
                w += [rnd.randrange(256), 0]
        seq.append(tuple(w))
    return seq


def gen_enc(path):
    enc = Encoder(nwords=2, lsb_first=True)
    seq = stimulus()
    lines = []

    outs = []

    def tb():
        for d0, k0, d1, k1 in seq + [(0, 0, 0, 0)]:
            yield enc.d[0].eq(d0)
            yield enc.k[0].eq(k0)
            yield enc.d[1].eq(d1)
            yield enc.k[1].eq(k1)
            yield
            outs.append(((yield enc.output[0]), (yield enc.output[1]),
                         (yield enc.disparity[0]), (yield enc.disparity[1])))

    run_simulation(enc, tb())
    for (d0, k0, d1, k1), (o0, o1, p0, p1) in zip(seq, outs[1:]):
        lines.append(f"{d0:02x}{k0:01x}{d1:02x}{k1:01x}{o0:03x}{o1:03x}{p0:01x}{p1:01x}")

    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")
    return len(lines)


def gen_dec(path):
    dec = Decoder(lsb_first=True)
    lines = []

    outs = []

    def tb():
        for s in list(range(1024)) + [0]:
            yield dec.input.eq(s)
            yield
            outs.append(((yield dec.d), (yield dec.k), (yield dec.invalid)))

    run_simulation(dec, tb())
    for s, (d, k, inv) in zip(range(1024), outs[1:]):
        lines.append(f"{s:03x}{d:02x}{k:01x}{inv:01x}")
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")
    return len(lines)


if __name__ == "__main__":
    out = sys.argv[1] if len(sys.argv) > 1 else "."
    print("enc.hex:", gen_enc(f"{out}/enc.hex"), "vectors")
    print("dec.hex:", gen_dec(f"{out}/dec.hex"), "vectors")
