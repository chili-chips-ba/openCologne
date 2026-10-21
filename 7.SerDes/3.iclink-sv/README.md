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
| [3.build](3.build) | QA: `run-lint.sh`, `run-format.sh`, `run-leq.sh`; EVB pins (`GateMateA1-EVB.ccf`) |

Today `1.hw` holds the EVB board top only (clock, reset, heartbeat LED), which the PHY and SoC replace. Its QA flow already runs in CI.

-----------
#### End-of-Document
