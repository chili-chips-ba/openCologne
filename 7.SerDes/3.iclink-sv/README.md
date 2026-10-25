<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# IC Link in SystemVerilog

## * WORK IN PROGRESS *

LiteX's LiteICLink (SerWB: Wishbone over a serial link) and a GateMate `CC_SERDES` PHY, in SystemVerilog, for two eduBOS5 SoCs talking to each other. Design, test setups, simulation and build: [7.SerDes README](../README.md).

## Quick start

Needs: Verilator 5 (`--binary --timing`; we use 5.052), Icarus Verilog 13, GNU make, bash. For the bitstream: Yosys with `read_slang`, `nextpnr-himbaechel-gatemate` and `gmpack` (versions: [Build](../README.md#build)). Only for `make vectors`: python3 with LiteX and LiteICLink. Only for the pump plot: matplotlib.

From the repo root:

```
make -C 7.SerDes/3.iclink-sv/2.sim          # every unit test, each prints PASS
make -C 7.SerDes/3.iclink-sv/3.build        # build/top.bit (Yosys, nextpnr-himbaechel-gatemate, gmpack)
make -C 7.SerDes/3.iclink-sv/3.build load   # program the EVB
```

| Folder | What |
|---|---|
| [0.upstream](0.upstream) | snapshot of the LiteX / LiteICLink sources we port, for reference |
| [1.hw](1.hw) | RTL, `top.filelist`, and our [RTL coding rules](1.hw/README.md#rtl-coding-rules) |
| [2.sim](2.sim) | unit and PHY tests, Verilator and Icarus: `make`; `WAVES=1` writes FSTs for WaveCrux |
| [3.build](3.build) | standalone build: bitstream (`make`, open-source flow), QA (`run-lint.sh`, `run-format.sh`, `run-leq.sh`), EVB pins |
| [4.litex](4.litex) | LiteX integration: `SerDesGateMate` and a demo SoC |

## Status

| Block | RTL | Verified |
|---|---|---|
| 8b/10b encoder (`NWORDS` symbols/clock: 2 as in LiteX, 8 in the PHY) and decoder: `iclink_pkg.sv`, `iclink_8b10b_enc.sv`, `iclink_8b10b_dec.sv` | done, ported from LiteX's `code_8b10b.py` | bit-exact with LiteX: 4548 encoder clocks and all 1024 decoder symbols ([`gen_8b10b_vectors.py`](2.sim/gen_8b10b_vectors.py) runs LiteX's own code); round trip; running disparity; two injected bugs caught |
| PRBS7/15/31 generator, checker, TX, RX: `iclink_prbs_gen/_chk/_tx/_rx.sv` | done, ported from LiteX's `prbs.py` | matches LiteX's PRBSTX looped into PRBSRX over 3060 clocks ([`gen_prbs_vectors.py`](2.sim/gen_prbs_vectors.py)): injected bit errors, pass-through, idle flood; a wrong tap is caught. `pause` is checked on its own: LiteX's does not work (see below) |
| GateMate `CC_SERDES` PHY: `iclink_phy_pkg.sv`, `iclink_serdes_gm.sv` | done | `sim_phy_oneway`, on the SerDes BFM, TX looped to RX: bring-up and comma alignment in 27 us; 2000 words of 8 bytes + K, bit-exact; PRBS7/15/31 0 errors in 1000 clocks each; one flipped line bit is seen every time; pause. Swapping the TX symbol bits 8 and 9 is caught. `sim_phy_twoway`: two PHYs, lines crossed, data and PRBS both ways at once; a flip is seen on its own side only |
| EVB board top: reset, 8b/10b and PRBS7 self-tests, SerDes link test (setup 1), LED | done | `sim_top`: clean run, a flipped line bit, a one-bit symbol error; bitstream, `CC_SERDES` placed, 4 seeds: clk_tx 36.6 to 39.1 MHz, clk_rx 57.9 to 73.7 MHz (31.25 MHz needed); at 5 Gb/s (`LINE_RATE=5000`) 100.6 to 141.4 and 66.2 to 71.9 MHz (62.5 needed). Not yet run on the board |
| SerWB packetizer, depacketizer: `iclink_serwb_tx.sv`, `iclink_serwb_rx.sv` | done, ported from LiteICLink's `serwb/packet.py` | bit-exact with LiteICLink's own `Packetizer` and `CRCDepacketizer` (`sim_serwb_tx`, `sim_serwb_rx`), at 2 and 4 words a clock |
| FIFO pump: `iclink_serwb_pump.sv`, `iclink_serwb_fifo.sv`, `iclink_cdc_ptr.sv`, `iclink_gearbox.sv` | done; not yet in the top | `sim_serwb_pump`, `sim_serwb_w4`: words in order both ways, flow control, no word lost |
| SerWB Etherbone (Wishbone bridge), scrambler | to do | |
| eduBOS5 SoC with PeakRDL CSRs | to do | |

The board top runs the 8b/10b encoder into the decoder, and PRBS7 TX into the checker, in the fabric. It also runs the SerDes link of test setup 1: commas, then PRBS7, out of the PHY's TX and back into its RX. The LED blinks while the link is up and all three pass, and stays low after the first error.

**The PHY.** LiteICLink's PHY interface (8 bytes + 8 K flags per clock each way, PRBS, ready, comma alignment) on `CC_SERDES`, 64-bit datapath, 2.5 Gb/s, 31.25 MHz core clocks.

- **TX:** our 8b/10b encoder in the fabric, as LiteICLink does; `CC_SERDES` sends the raw symbols (its 8b/10b off; bit 9 on `TX_CHAR_DISPMODE_I`, bit 8 on `TX_CHAR_DISPVAL_I`, DS1001 Figure 2.34). Or `CC_SERDES`'s own encoder (`TX_HARD_8B10B`), the default at 5 Gb/s.
- **RX:** the comma alignment and the 8b/10b decoder of `CC_SERDES`, then a lane aligner. `rx_align` is on while commas come in and off before data, since `CC_SERDES` realigns on any off-boundary comma while it is on (DS1001 Table 2.50). It costs no fabric. A fabric decoder would also work: with the decoder off, bits 8 and 9 come out on `RX_CHAR_IS_K_O` and `RX_DISP_ERR_O` (DS1001 Figure 2.39).
- **PRBS:** over the 64 payload bits, as D characters through 8b/10b; LiteICLink sends it raw on the line instead. Our checker counts the errors, as LiteX does.
- **Flops at the `CC_SERDES` boundary:** every TX input of `CC_SERDES` (data, symbol bits 8 and 9, resets, comma align, regfile) comes straight from a flop; every RX output (data, K, decode errors, aligned, reset done) goes into a flop first, before any logic. One flop stage each way.
- **Bring-up:** the three regfile writes of Cologne Chip's PRBS loopback test (PLL, SerDes enable, PLL on), then TX and RX out of reset.

**Found in LiteX:** `PRBSRX`'s `pause` does nothing. `~with_errors_saturation` is plain Python, and `~False` is `-1`, which widens the Migen expression so that `~self.pause` is never 0. With `pause=1` it still counts every error. Our SV pauses.


-----------
#### End-of-Document
