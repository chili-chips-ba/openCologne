#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# SerWB depacketizer vectors from LiteICLink's own CRCDepacketizer, run in
# Migen: a word stream with good packets and broken ones in, the packets it
# forwards and its error counts out. Our depacketizer must forward the same
# packets and count the same errors.
#
# Broken on purpose: a flipped bit in the payload or the CRC, 0-word and
# oversized packets, a corrupted header, a lost preamble, garbage between
# packets; good packets carry preamble look-alikes in their payload.
#
# usage: gen_serwb_rx_vectors.py <outdir>
#   serwb_rx_wire.hex    the stream, one 32-bit word per line
#   serwb_rx_expect.txt  forwarded packets: port, word count, data (hex)
#   serwb_rx_counts.txt  crc_errors drops

import random
import sys

from migen import *
from litex.gen.sim import run_simulation

from liteiclink.serwb.packet import CRCDepacketizer

N_ITEMS   = 400
MAX_WORDS = 16
PREAMBLE  = 0x5AA55AA5
POLY      = 0x04C11DB7


def crc32(c, d):
    for n in range(32):
        fb = ((c >> 31) ^ (d >> n)) & 1
        c  = ((c << 1) & 0xFFFFFFFF) ^ (POLY if fb else 0)
    return c


def packet(port, words):
    hdr = (4 * len(words)) << 8 | port
    c   = crc32(0xFFFFFFFF, hdr)
    for w in words:
        c = crc32(c, w)
    return [PREAMBLE, hdr] + words + [c]


def make_stream(prng):
    stream = []
    for _ in range(N_ITEMS):
        port  = prng.getrandbits(8)
        words = [prng.getrandbits(32) for _ in range(prng.randint(1, MAX_WORDS))]
        kind  = prng.choices(["good", "lookalike", "flip_data", "flip_crc", "zero", "oversize",
                              "bad_header", "lost_preamble", "garbage"],
                             [50, 8, 8, 6, 4, 4, 4, 4, 6])[0]
        p = packet(port, words)
        if kind == "lookalike":
            words[prng.randrange(len(words))] = PREAMBLE
            p = packet(port, words)
        elif kind == "flip_data":
            p[2 + prng.randrange(len(words))] ^= 1 << prng.randrange(32)
        elif kind == "flip_crc":
            p[-1] ^= 1 << prng.randrange(32)
        elif kind == "zero":
            p = [PREAMBLE, port]
        elif kind == "oversize":
            p = packet(port, [prng.getrandbits(32) for _ in range(prng.randint(MAX_WORDS + 1, 24))])
        elif kind == "bad_header":
            p[1] ^= 1 << prng.randrange(8, 24)
        elif kind == "lost_preamble":
            p[0] ^= 1 << prng.randrange(32)
        elif kind == "garbage":
            p = [prng.getrandbits(32) for _ in range(prng.randint(1, 3))]
        stream += p
    # a broken header can leave the reference mid-packet: end on clean packets
    for _ in range(3):
        stream += packet(0x55, [prng.getrandbits(32) for _ in range(MAX_WORDS)])
    return stream


def main():
    outdir = sys.argv[1]
    prng   = random.Random(2027)
    stream = make_stream(prng)
    dut    = CRCDepacketizer(clk_freq=int(1e6), timeout=10, max_words=MAX_WORDS)
    got    = []
    counts = {"crc_error": 0, "drop": 0}
    done   = []

    def gen():
        for w in stream:
            yield dut.sink.valid.eq(1)
            yield dut.sink.data.eq(w)
            yield
            while not (yield dut.sink.ready):
                yield
        yield dut.sink.valid.eq(0)
        done.append(1)

    def mon():
        yield dut.source.ready.eq(1)
        cur, idle = [], 0
        while idle < 100:
            yield
            if (yield dut.crc_error):
                counts["crc_error"] += 1
            if (yield dut.drop):
                counts["drop"] += 1
            if (yield dut.source.valid):
                cur.append((yield dut.source.data))
                if (yield dut.source.last):
                    got.append(((yield dut.source.port), cur))
                    cur = []
                idle = 0
            elif done:
                idle += 1

    run_simulation(dut, [gen(), mon()])

    with open(f"{outdir}/serwb_rx_wire.hex", "w") as f:
        for w in stream:
            f.write(f"{w:08x}\n")
    with open(f"{outdir}/serwb_rx_expect.txt", "w") as f:
        for port, words in got:
            f.write(f"{port:02x} {len(words):04x} " + " ".join(f"{w:08x}" for w in words) + "\n")
    with open(f"{outdir}/serwb_rx_counts.txt", "w") as f:
        f.write(f"{counts['crc_error']} {counts['drop']}\n")
    print(f"{len(stream)} words, {len(got)} packets forwarded, "
          f"{counts['crc_error']} CRC errors, {counts['drop']} drops")


if __name__ == "__main__":
    main()
