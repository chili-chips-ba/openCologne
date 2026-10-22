# LiteX integration

The GateMate SerDes PHY ([`../1.hw/iclink_serdes_gm.sv`](../1.hw/iclink_serdes_gm.sv)) as a LiteX core. Goal: offer it to LiteICLink as its GateMate transceiver PHY, next to the ECP5 and Xilinx ones.

| File | What |
|---|---|
| [`serdes_gatemate.py`](serdes_gatemate.py) | `SerDesGateMate`: Migen wrapper (`Instance`) around the SV core, with LiteICLink's transceiver PHY interface |
| [`gatemate_evb_serdes.py`](gatemate_evb_serdes.py) | demo SoC on the GateMate EVB: the PHY, its CSRs, UARTBone to the host, no CPU |
| [`gatemate_evb_serdes.bit`](gatemate_evb_serdes.bit) | its bitstream |

## Interface

As LiteICLink's `SerDesECP5`:

- clock domains `tx` and `rx`: `CC_SERDES` `PLL_CLK_O` and `RX_CLK_O`, line rate / 80 (31.25 MHz at 2.5 Gb/s); reset until `tx_ready` / `rx_ready`;
- `add_stream_endpoints()`: `sink` (tx) and `source` (rx), 8 words of 8 bits + 8 K flags per clock;
- `add_controls()`: CSRs `tx_ready`, `rx_ready`, `rx_align`, `rx_aligned`, `tx_prbs_config`, `rx_prbs_config` (+ pause), `rx_prbs_errors`; `add_clock_cycles()` as in LiteICLink.

Differences from the ECP5 PHY:

- PRBS travels as 8b/10b D characters, not raw: `CC_SERDES` decodes 8b/10b on RX in the hard macro.
- `clk_reg` runs the bring-up (regfile writes with fixed waits). Use the 10 MHz board clock, as the demo does.
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
./gatemate_evb_serdes.py --build [--load]
litex_server --uart --uart-port /dev/ttyUSB0
litex_cli --regs
```

PRBS test on test setup 1 (EVB TX cabled to its RX): write 1, 2 or 3 to `serdes_tx_prbs_config` and `serdes_rx_prbs_config` (PRBS7/15/31), then read `serdes_rx_prbs_errors`.

Built 2026-10-21 with LiteX `d2b47282a`, LiteICLink `8ef8d79`, litex-boards `448c5c1a`, Yosys 0.69, nextpnr `6b438a1c`, Peppercorn flow: 1 min, 5125 CPE_LT (12%), 1801 CPE_FF (4%), 1 `SERDES`.

| Clock | Fmax | Needed |
|---|---|---|
| `tx` | 31.76 MHz | 31.25 MHz |
| `rx` | 46.69 MHz | 31.25 MHz |
| `sys` | 34.59 MHz | 24 MHz |

## Status

- Builds; not yet tested on the board.
- `tx` closes timing with under 2% margin, and not on every placement seed. The critical path is the 8b/10b encoder's running-disparity chain across 8 words. Next: pipeline it.
- `rx_prbs_errors` crosses to `sys` through `MultiReg`: pause the checker before reading it.
- Serial Wishbone is not on this PHY yet.
