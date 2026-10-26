<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# CC_SERDES clock correction: what it can and cannot do

Two boards have two oscillators, and they never quite agree on the time. On ULX5M-GS the SerDes reference is a 100 MHz Si511, ±20 ppm, so two boards differ by up to 40 ppm: one word in 25,000. The fabric runs on one clock, `clk_core`, from the local SerDes PLL. So the `CC_SERDES` RX buffer must absorb the difference by clock correction: it removes or repeats a clock-correction word when its fill leaves `MIN_LAT` to `MAX_LAT`. Back to the [7.SerDes README](../README.md).

## Three limits

DS1001 leaves open how a sequence is matched and what an insertion repeats. The SerDes BFM fills that in, to be checked on silicon ([model README, RX buffer and clock correction](../1.sim-model/README.md#rx-buffer-and-clock-correction)). If the silicon works as modelled, three limits follow:

1. A single sequence word is never removed. It takes two in a row.
2. An insertion repeats the word before the sequence. It is safe only when that word is harmless to repeat.
3. The sequence must sit aligned in the datapath word.

## What we did

- **PHY:** clock correction on (`RX_CLKCOR_USE = 1`), the sequence K23.7 four times (the `CC_SERDES` default), `MIN_LAT` 8 and `MAX_LAT` 12 (`iclink_phy_pkg`: `PHY_CLKCOR_*`). The defaults, 32 and 39, would hold the buffer 24 words fuller, which is 24 more clocks of latency. `rx_buf_err` flags an overflow or underflow; the board top counts it as a link error.
- **FIFO pump:** every 1024 clocks a burst of 4 PHY words: a fill word, then 3 clock-correction words (`PHY_CLKCOR_WORD`, the sequence twice). It goes out even mid-packet, as XOFF does; the packet waits. The fill word in front means an insertion never repeats data (limit 2). Three words, not two, because with the comma in lane 4 each PHY word arrives split over two RX words, and two whole correction words in a row must still reach the far buffer (limits 1 and 3). One burst every 1024 clocks is 24 times more often than 40 ppm needs, and costs 0.4% of the line.
- **Test:** `sim_link_ppm`, two sides 200 ppm apart (5 times the board worst case), 100,000 clocks of a counter each way: every word arrives in order, no CRC error, drop or buffer error; A's buffer inserted 20 correction words, B's removed 18. Without the bursts (`NO_CLKCOR`), A's buffer runs dry within about 25,000 clocks and flags errors from then on, and B->A loses 60% of its words.

A LiteX user of the PHY alone ([`4.litex`](../3.iclink-sv/4.litex/README.md)) must send such bursts too when the two ends are on two boards.

## What it means for PCIe

The PCIe clock-compensation unit is the SKP ordered set: COM and three SKP symbols, 4 symbols, one every 1180 to 1538 symbols. It meets none of the three limits:

1. SKP ordered sets do not come two in a row, so none can be removed.
2. The symbols before an SKP ordered set are packet or idle data, so an insertion repeats data and corrupts the stream.
3. The 4 symbols need not sit aligned in the 64-bit word.

Unless the silicon proves otherwise, a PCIe endpoint on `CC_SERDES` must keep `RX_CLKCOR_USE = 0` and run off the host's REFCLK (common clock, 0 ppm, SSC tracked by both sides). With a separate reference clock, SKP insertion and removal must be done in the fabric, symbol by symbol, as the PCIe spec defines it.

Questions to Cologne Chip: [gatemate-pipe#14](https://github.com/colognechip/gatemate-pipe/issues/14).

#### End-of-Document
