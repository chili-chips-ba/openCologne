<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# eduBOS5

The CPU of our SoC: Chili.CHIPS' compact RV32I core. These files are copied unchanged from [openPCIE `2.rtl/0.common.opensource/src/CPU.eduBOS5`](https://github.com/chili-chips-ba/openPCIE/tree/main/2.rtl/0.common.opensource/src/CPU.eduBOS5), commit `54c5409` (2026-10-25). The RTL and the constraints only: the docs, tests and formal proofs stay in openPCIE.

| File | What |
|---|---|
| `edubos5.sv` | the core: control FSM, decode, load and store |
| `edubos5_alu.sv` | ALU, registered output |
| `edubos5_rf.sv` | register file: 2 asynchronous read ports, 1 synchronous write port |
| `edubos5_pkg.sv` | common types and opcodes |
| `edubos5.3STG-ONLY.mcp.xdc` | multicycle paths of the 3-stage pipeline (`EN_WAIT4REGS=1`), for Vivado and openPCIE's SoC hierarchy. A reference for a GateMate version; nextpnr does not read XDC |

Not yet in the 7.SerDes top or its QA flow: that comes with the SoC.

For the parameters, the pipelines and their cycles per instruction, the validation (riscv-formal, the multicycle proof) and the WaveCrux views, see the [eduBOS5 README in openPCIE](https://github.com/chili-chips-ba/openPCIE/blob/main/2.rtl/0.common.opensource/src/CPU.eduBOS5/README.md).

To update: copy these five files again from openPCIE and update the commit above.

#### End-of-Document
