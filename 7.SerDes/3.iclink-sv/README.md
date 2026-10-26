<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# IC Link in SystemVerilog

## * WORK IN PROGRESS *

LiteX's LiteICLink (SerWB: Wishbone over a serial link) and a GateMate `CC_SERDES` PHY, in SystemVerilog, for two eduBOS5 SoCs talking to each other. What it is, what is done and what comes next: [7.SerDes README](../README.md).

## Quick start

Needs: Verilator 5 (`--binary --timing`; we use 5.052), Icarus Verilog 13, GNU make, bash. For the bitstream: Yosys with `read_slang`, `nextpnr-himbaechel-gatemate` and `gmpack` (versions: [3.build](3.build/README.md)). Only for `make vectors`: python3 with LiteX and LiteICLink. Only for the pump plot: matplotlib.

From the repo root:

```
make -C 7.SerDes/3.iclink-sv/2.sim          # every test, each prints PASS
make -C 7.SerDes/3.iclink-sv/3.build        # build/top.bit (Yosys, nextpnr-himbaechel-gatemate, gmpack)
make -C 7.SerDes/3.iclink-sv/3.build load   # program the EVB
bash 7.SerDes/3.iclink-sv/3.build/run-lint.sh
bash 7.SerDes/3.iclink-sv/3.build/run-format.sh --check
```

The board top runs a PRBS7 self-test in the fabric, and the SerDes link of test setup 1: commas, then PRBS7, then the FIFO pump, out of the PHY's TX and back into its RX. The LED blinks while the link is up and every test passes. It stays off after the first error, or after the link drops once it was up, until reset.

## Folders

| Folder | What | For whom |
|---|---|---|
| [0.upstream](0.upstream/README.md) | snapshot of the LiteX / LiteICLink sources we port, for reference and diffs | porting |
| [1.hw](1.hw/README.md) | the RTL: modules, the PHY, clocks and line rates, SI settings; `eduBOS5/` from openPCIE | RTL designers |
| [2.sim](2.sim/README.md) | every test, its settings, the negative tests, waves for WaveCrux | verification |
| [3.build](3.build/README.md) | bitstream (open-source flow), timing results, QA scripts (`run-lint.sh`, `run-format.sh`, `run-leq.sh`), EVB pins | builds, QA |
| [4.litex](4.litex/README.md) | LiteX integration: `SerDesGateMate` and a demo SoC | LiteX users |

#### End-of-Document
