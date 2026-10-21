<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# IC Link in SystemVerilog

## * WORK IN PROGRESS *

LiteX's LiteICLink (SerWB: Wishbone over a serial link) and a GateMate `CC_SERDES` PHY, in SystemVerilog, for two eduBOS5 SoCs talking to each other. Design, test setups, simulation and build: [7.SerDes README](../README.md).

| Folder | What |
|---|---|
| [1.hw](1.hw) | RTL, `top.filelist`, and our [RTL coding rules](1.hw/README.md#rtl-coding-rules) |
| [2.sim](2.sim) | unit tests, Verilator: `make` |
| [3.build](3.build) | bitstream (`make`, open-source flow), QA (`run-lint.sh`, `run-format.sh`, `run-leq.sh`), EVB pins |

## Status

| Block | RTL | Verified |
|---|---|---|
| 8b/10b encoder (2 symbols/clock) and decoder: `iclink_pkg.sv`, `iclink_8b10b_enc.sv`, `iclink_8b10b_dec.sv` | done, ported from LiteX's `code_8b10b.py` | bit-exact with LiteX: 4548 encoder clocks and all 1024 decoder symbols ([`gen_8b10b_vectors.py`](2.sim/gen_8b10b_vectors.py) runs LiteX's own code); round trip; running disparity; two injected bugs caught |
| PRBS7/15/31 generator, checker, TX, RX: `iclink_prbs_gen/_chk/_tx/_rx.sv` | done, ported from LiteX's `prbs.py` | matches LiteX's PRBSTX looped into PRBSRX over 3060 clocks ([`gen_prbs_vectors.py`](2.sim/gen_prbs_vectors.py)): injected bit errors, pass-through, idle flood; a wrong tap is caught. `pause` is checked on its own: LiteX's does not work (see below) |
| GateMate `CC_SERDES` PHY: `iclink_phy_pkg.sv`, `iclink_serdes_gm.sv` | done | `sim_phy_oneway`, on the SerDes BFM, TX looped to RX: bring-up and comma alignment in 27 us; 2000 words of 8 bytes + K, bit-exact; PRBS7/15/31 0 errors in 1000 clocks each; one flipped line bit is seen every time; pause. Swapping the TX symbol bits 8 and 9 is caught |
| EVB board top: reset, 8b/10b and PRBS7 self-tests, SerDes link test (setup 1), LED | done | `sim_top`: clean run, a flipped line bit, a one-bit symbol error; bitstream, `CC_SERDES` placed, SerDes clocks 34.7 MHz max at 31.25 MHz needed, 2930 LUT trees. Not yet run on the board |
| SerWB (packet, scrambler, Wishbone bridge) | to do | |
| eduBOS5 SoC with PeakRDL CSRs | to do | |

The board top runs the 8b/10b encoder into the decoder, and PRBS7 TX into the checker, in the fabric. It also runs the SerDes link of test setup 1: commas, then PRBS7, out of the PHY's TX and back into its RX. The LED blinks while the link is up and all three pass, and stays low after the first error.

**The PHY.** LiteICLink's PHY interface (8 bytes + 8 K flags per clock each way, PRBS, ready, comma alignment) on `CC_SERDES`, 64-bit datapath, 2.5 Gb/s, 31.25 MHz core clocks.

- **TX:** our 8b/10b encoder in the fabric, as LiteICLink does; `CC_SERDES` sends the raw symbols (its 8b/10b off; bits 8, 9 on `TX_CHAR_DISPMODE_I`, `TX_CHAR_DISPVAL_I`).
- **RX:** the comma alignment and the 8b/10b decoder of `CC_SERDES`. With its 8b/10b off, `CC_SERDES` hands out only bits 7:0 of each symbol, so the fabric cannot decode.
- **PRBS:** over the 64 payload bits, as D characters through 8b/10b; LiteICLink sends it raw on the line instead. Our checker counts the errors, as LiteX does.
- **Flops at the `CC_SERDES` boundary:** every TX input of `CC_SERDES` (data, symbol bits 8 and 9, resets, comma align, regfile) comes straight from a flop; every RX output (data, K, decode errors, aligned, reset done) goes into a flop first, before any logic. One flop stage each way.
- **Bring-up:** the three regfile writes of Cologne Chip's PRBS loopback test (PLL, SerDes enable, PLL on), then TX and RX out of reset.

**Found in LiteX:** `PRBSRX`'s `pause` does nothing. `~with_errors_saturation` is plain Python, and `~False` is `-1`, which widens the Migen expression so that `~self.pause` is never 0. With `pause=1` it still counts every error. Our SV pauses.

```
make -C 2.sim            # unit tests: TB_8B10B, TB_PRBS, TB_PHY_ONEWAY, TB_TOP: PASS
make -C 3.build          # build/top.bit (Yosys, nextpnr-himbaechel-gatemate, gmpack)
make -C 3.build load     # program the EVB
```

-----------
#### End-of-Document
