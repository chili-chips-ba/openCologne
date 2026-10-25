<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Upstream sources

The LiteX and LiteICLink sources this core is ported from, unchanged, for reference and diffs. BSD-2-Clause, Enjoy-Digital and contributors.

| Upstream | Commit | Files | Ported to |
|---|---|---|---|
| [LiteX](https://github.com/enjoy-digital/litex) | `d2b47282a` (2026-10-21) | `litex/code_8b10b.py`, `litex/prbs.py` | `1.hw/iclink_8b10b_*.sv`, `1.hw/iclink_prbs_*.sv` (bit-exact) |
| [LiteICLink](https://github.com/enjoy-digital/liteiclink) | `8ef8d79` (2026-10-21) | `serwb/*` (Serial Wishbone), `doc/serwb.md` | `1.hw/iclink_serwb_tx.sv`, `iclink_serwb_rx.sv` (the packet layer, bit-exact); Etherbone next |
| LiteICLink | `8ef8d79` | `serdes/serdes_ecp5.py`, `serdes/common.py` | the PHY interface of `4.litex/serdes_gatemate.py` |

To update: move your LiteX and LiteICLink install to the new commit, run `make -C 7.SerDes/3.iclink-sv/2.sim vectors` from the repo root (the generators import the installed packages, not this snapshot), then copy the files here. Unchanged vectors (8b/10b, PRBS, SerWB TX and RX) mean the port still matches.

#### End-of-Document
