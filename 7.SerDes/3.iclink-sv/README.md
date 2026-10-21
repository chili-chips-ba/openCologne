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
| EVB board top: reset, 8b/10b self-test, LED | done | `sim_top`: clean run and a one-bit error; bitstream, 42 MHz max at a 10 MHz clock |
| PRBS, GateMate `CC_SERDES` PHY | next | with the SerDes BFM |
| SerWB (packet, scrambler, Wishbone bridge) | to do | |
| eduBOS5 SoC with PeakRDL CSRs | to do | |

The board top runs the 8b/10b encoder into the decoder in the fabric (no SerDes yet). The LED blinks while what comes out matches what went in, and stays low after the first error.

```
make -C 2.sim            # unit tests: TB_8B10B: PASS, TB_TOP: PASS
make -C 3.build          # build/top.bit (Yosys, nextpnr-himbaechel-gatemate, gmpack)
make -C 3.build load     # program the EVB
```

-----------
#### End-of-Document
