<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# 7.SerDes hardware

The chip-to-chip link: LiteX's LiteICLink SerWB over our GateMate `CC_SERDES` PHY. See the [7.SerDes README](../../README.md).

## RTL coding rules

For all new openCologne RTL.

**LiteX code.** The C2C core (SerWB and the GateMate PHY) is SystemVerilog, hand-ported from LiteICLink, and follows the rules below. Only the thin Migen wrapper that hands it to LiteX is Python, in LiteX's own style.

IEEE 1800-2009 SystemVerilog:

- **Declare and size once:** widths, constants and types live in a `_pkg`; no module redeclares them.
- **Fewer, richer ports:** interfaces and struct-typed ports, not many scalars; group internal signals the same way.
- **Packages:** `import` right after the module name, no package prefix on every use.
- **Case:** signals and ports lower case, constants UPPER CASE (parameters, localparams, enum values, macros). Only hard-macro and primitive pins (`CC_SERDES`, `CC_PLL`, ...) keep vendor names.
- **Procedural blocks:** `always_ff` for flip-flops, `always_comb` for combinational logic, never plain `always`. `unique case` for parallel muxes whose items cover every value, `unique0 case` where no item may match, `priority case` for priority encoders; never plain `case`. A `unique case` has no `default`.

  | Keyword | Several items match | No item matches | Synthesis meaning |
  |---|---|---|---|
  | `unique` | violation | violation, unless there is a `default` | `parallel_case` + `full_case` |
  | `unique0` | violation | allowed, nothing happens | `parallel_case` only |
  | `priority` | first one wins | violation, unless there is a `default` | ordered (priority) logic |

- **`logic`, not `wire`:** every signal and port is `logic`, every `input`/`output` typed. Only an `inout` is a `wire`.
- **`initial` blocks:** not in RTL, except `$readmemh` of a memory image. Models and test benches may use them freely.
- **No `` `timescale `` in RTL:** the test bench sets it. RTL has no `#` delays.
- **No initial values on registers:** a register gets its value from the reset branch of its `always_ff`.
- **Arrays, not flat buses:** arrays of lanes or structs, no index arithmetic on flat buses.
- **`/*LINT:OK*/`:** marks an unused *output* pin of a hard macro, primitive or third-party core as reviewed: `.PIN (/*LINT:OK*/),  // reason`. Never on an input; unused inputs are tied off.
- **No-connects:** unused bits of a hard-macro or primitive output go to `NC_` signals, never read.
- **Lint:** fix findings at the root; waive only as a last resort, with a reason, in the waiver file. Don't mold legal, intended code around one tool's quirk: waive it instead.
- **Variants in one file:** a parameter selects the variant inside one module, never a copy of the module; `generate` branches are named.
- **Flopped controls:** a high-fanout control (load enable, mux select) comes from a flop, placed next to the logic it serves.
- **One signal per function:** no `x` plus `x_q` pairs.
- **Minimal logic:** leave out terms that do not change behaviour, and say why in a comment.
- **Assertions:** only under an `ifdef`; the RTL is never changed for them.
- **Clean diffs:** no blank-line or alignment changes beyond what `run-format.sh` makes; check `git diff` before a commit.
- **Models follow the RTL:** a model keeps the ports, names and structure of the RTL it replaces, as our SerDes BFM does for `CC_SERDES`.
- **Formatting:** `run-format.sh` (Verible): every body in `begin` ... `end`, alignment on, LF line endings, at most 100 columns. Run it last, after lint, before a commit; `run-format.sh --check` only lists unformatted files.

-----------
#### End-of-Document
