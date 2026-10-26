<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# LiteX integration

The GateMate SerDes PHY ([`../1.hw/iclink_serdes_gm.sv`](../1.hw/iclink_serdes_gm.sv)) as a LiteX core. Goal: offer it to LiteICLink as its GateMate transceiver PHY, next to the ECP5 and Xilinx ones.

| File | What |
|---|---|
| [`serdes_gatemate.py`](serdes_gatemate.py) | `SerDesGateMate`: Migen wrapper (`Instance`) around the SV core, with LiteICLink's transceiver PHY interface |
| [`gatemate_evb_serdes.py`](gatemate_evb_serdes.py) | demo SoC on the GateMate EVB: the PHY, its CSRs, UARTBone to the host, no CPU |
| [`gatemate_evb_serdes.bit`](gatemate_evb_serdes.bit) | its bitstream, 2.5 Gb/s, built 2026-10-25 from this RTL |

## Interface

As LiteICLink's `SerDesECP5`:

- clock domains `tx` and `rx`, both on one clock: `CC_SERDES` `PLL_CLK_O`, line rate / 80 (31.25 MHz at 2.5 Gb/s); the `CC_SERDES` RX buffer moves RX onto it. Reset until `tx_ready` / `rx_ready`;
- `add_stream_endpoints()`: `sink` (tx) and `source` (rx), 8 words of 8 bits + 8 K flags per clock;
- `add_controls()`: CSRs `tx_ready`, `rx_ready`, `rx_align`, `rx_aligned`, `rx_buf_err`, `tx_prbs_config`, `rx_prbs_config` (+ pause), `rx_prbs_errors`; `add_clock_cycles()` as in LiteICLink.

Differences from the ECP5 PHY:

- PRBS travels as 8b/10b D characters, not raw: `CC_SERDES` decodes 8b/10b on RX in the hard macro.
- `clk_reg` runs the bring-up (regfile writes with fixed waits). Use the 10 MHz board clock, as the demo does.
- `linerate`: 1.25e9, 2.5e9 or 5e9. It sets the core's `LINE_RATE` (the PLL setting), passed to `read_slang` as `-G LINE_RATE`.
- RX clock correction is on in the core. Between two boards, the far side must send clock-correction bursts, as the FIFO pump does ([clock correction](../../0.doc/clock-correction.md)); otherwise the RX buffer runs over or dry (`rx_buf_err`). The demo is a loopback on one board and needs none.
- No `tx_enable`, `tx_inhibit`, square wave or loopback controls yet.

## Use

```python
from serdes_gatemate import SerDesGateMate

self.serdes = serdes = SerDesGateMate(platform, clk_reg=ClockSignal("serdes_reg"))
serdes.add_stream_endpoints()
serdes.add_controls()
```

The SV sources go in through Yosys's slang front end (`platform.yosys_use_slang`, `-D SYNTHESIS`), with Yosys's GateMate cell blackboxes.

## Demo build

```
./gatemate_evb_serdes.py --toolchain peppercorn --build [--load]
litex_server --uart --uart-port /dev/ttyUSB0
litex_cli --regs
```

PRBS test on test setup 1 (EVB TX cabled to its RX): write 1, 2 or 3 to `serdes_tx_prbs_config` and `serdes_rx_prbs_config` (PRBS7/15/31), then read `serdes_rx_prbs_errors`.

Built 2026-10-25 with LiteX `d2b47282a`, LiteICLink `8ef8d79`, litex-boards `448c5c1a`, Yosys 0.69, nextpnr `6b438a1c`, Peppercorn flow: 69 s, 3757 CPE_LT (9%), 1552 CPE_FF (3%), 1 `SERDES`.

| Clock | Fmax, seed 1 | Needed |
|---|---|---|
| `tx` = `rx` (one net, `rx_clk` in nextpnr) | 61.30 MHz | 31.25 MHz |
| `sys` | 38.18 MHz | 24 MHz |

## Timing

The `tx` clock (31.25 MHz) is the tight one. What we found getting the demo to close:

| Step | `tx` Fmax |
|---|---|
| first LiteX build, PRBS mux feeding the encoder in the same clock | 24.95 MHz, seeds 2-5: 26.4-27.9 MHz, all fail |
| encoder input registered (+1 clock TX latency) | 30.41 MHz; seeds 2 and 6 pass (31.27, 31.53 MHz), 3, 4, 5 and 7 fail |
| same RTL, LiteX `d2b47282a` / LiteICLink `8ef8d79` | 31.76 MHz at seed 1, pass |
| one clock: RX on `PLL_CLK_O` through the `CC_SERDES` RX buffer (`tx` and `rx` on one net) | 29.29 MHz at seed 1, fail |
| 8b/10b in `CC_SERDES`, no fabric encoder | 63.24 MHz at seed 1, pass |
| clock correction on, `rx_buf_err` out | 61.30 MHz at seed 1, pass |

The fabric encoder chained its running disparity through all 8 words of a clock (LiteICLink chains 2 or 4): that chain was the critical path in every row above but the last two. With `CC_SERDES` encoding, it is gone.

## Status

- Builds; not yet tested on the board.
- Closes timing with a 2x margin (61 MHz against 31).
- `rx_prbs_errors` crosses to `sys` through `MultiReg`: pause the checker before reading it.
- Serial Wishbone is not on this PHY yet.

#### End-of-Document
