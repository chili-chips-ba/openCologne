<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Formal proofs of the 8b/10b codec

The proofs read `ccfpga_serdes_pkg.sv`, the package the SerDes BFM uses. They check its encoder and its decode function, `dec8b10b()`. The BFM decodes with a faster table, `dec_lut`, built at time 0; `tb_modes` checks all 1024 entries against `dec8b10b()`, in every `sim_modes` run.

From the repo root:

```sh
bash 7.SerDes/1.sim-model/formal_8b10b/run-formal.sh
```

Needs `yosys` with `read_slang` (tested with 0.69, openXC7) and `iverilog` (13.0). The build goes to `~/.cache/opencologne/formal_8b10b`.

| Property | Proved by | Statement |
|---|---|---|
| `fv_enc_disparity` | Yosys SAT | No symbol has illegal disparity. |
| `fv_enc_rd_tracking` | Yosys SAT | The running disparity reported matches the symbol. |
| `fv_comma_format` | Yosys SAT | K28.5 encodes to the `ALIGN_PCOMMA_VALUE` / `ALIGN_MCOMMA_VALUE` defaults (UG1001). |
| `fv_injective` | Yosys SAT | No two inputs share a symbol, at either running disparity. |
| `fv_run_length` | Yosys SAT | No run of more than five equal bits on the line. |
| exhaustive decode | Icarus | Every data and control character decodes back to itself, in both disparities. |

Result: 6 pass (5 SAT, 1 Icarus).

Each SAT property is a combinational module with one output, `ok`. Yosys looks for any input that makes `ok` 0. "No model found" means the property holds for every input.

Two properties are tied to something outside the model: `fv_comma_format` to the comma values in UG1001, `fv_run_length` to the defining rule of 8b/10b. A model that talks only to itself can't catch a consistent mistake. These two can.

The rest of the BFM is checked in simulation: [the model README](../README.md#verification).
