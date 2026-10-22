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
## Compared with LiteICLink

Upstream: LiteX `d2b47282a`, LiteICLink `8ef8d79` (2026-10-21), snapshot in [`../0.upstream`](../0.upstream).

| | LiteICLink (ECP5, Xilinx GTx PHYs) | This core (GateMate `CC_SERDES`) |
|---|---|---|
| Words per clock | 2 (20-bit SerDes word), or 4 (40-bit) | 8 (80-bit SerDes word) |
| User data per clock | 16 or 32 bits + 2 or 4 K flags | 64 bits + 8 K flags |
| Core clock at 2.5 Gb/s | 125 or 62.5 MHz | 31.25 MHz |
| TX order | 8b/10b encoder, then PRBS mux | PRBS mux, then 8b/10b encoder |
| PRBS on the line | raw bits | 8b/10b D characters |
| 8b/10b TX | fabric (LiteX `Encoder`) | fabric (`iclink_8b10b_enc`, bit-exact port) |
| 8b/10b RX | fabric (LiteX `Decoder`) + word aligner | inside `CC_SERDES`, with comma alignment |
| Encoder pipeline | 2 clocks | 1 input register + 2 clocks |
| Flops at the SerDes | as the PHY needs | one stage on every datapath and control port |

Why the differences:

- **RX in the hard macro.** With its 8b/10b off, `CC_SERDES` hands out only bits 7:0 of each symbol, so the fabric cannot decode. RX decoding and comma alignment stay in `CC_SERDES`.
- **PRBS through 8b/10b.** A raw PRBS would reach the fabric only as decoded bytes, so the PRBS travels as D characters and is checked after the decoder.
- **8 words per clock.** The `CC_SERDES` fabric interface is 64 bits + 8 K flags at line rate / 80. The encoder's running disparity runs through all 8 words in one clock, 2 to 4 times LiteICLink's chain. That chain is the TX critical path at 31.25 MHz; registering the encoder input took the PRBS mux out of it.

## Serial Wishbone frame

The format of LiteICLink `8ef8d79` ([`../0.upstream/liteiclink/doc/serwb.md`](../0.upstream/liteiclink/doc/serwb.md), `serwb/packet.py`), which our port keeps so it interoperates. Not in RTL yet.

**Packet**, in 32-bit words:

| Word | Content |
|---|---|
| 0 | preamble `0x5AA55AA5` |
| 1 | `[7:0]` port, `[23:8]` payload length in bytes, `[31:24]` 0 |
| 2 .. | payload, length / 4 words |
| last | CRC32 over the header and payload, only with `with_crc` (both sides) |

The receiver hunts for the preamble, reads port and length, and forwards the payload to that port. Unknown ports are dropped; a packet that stops arriving is dropped after a 1 ms timeout; with CRC, a bad packet is dropped and counted in `crc_errors`.

**Port 0 carries Etherbone**, one record per packet, 32-bit addresses and data (CERN's Etherbone, as cut down in LiteICLink: no probing, no address spaces):

| Payload word | Content |
|---|---|
| 0 | Etherbone header: magic `0x4E6F`, version 1, flags `nr` / `pr` / `pf`, `addr_size`, `port_size` |
| 1 | Etherbone header, rest (zero) |
| 2 | record header: flags (`bca`, `rca`, `rff`, `cyc`, `wca`, `wff`), `byte_enable`, `wcount`, `rcount` |
| 3 | write: base address; read: return address |
| 4 .. | write: `wcount` data words; read: `rcount` addresses to read |

**One 32-bit write**, A to B: 7 words, 8 with CRC.

| Word | Value |
|---|---|
| 0 | `0x5AA55AA5` |
| 1 | port 0, length 20 bytes |
| 2, 3 | Etherbone header |
| 4 | record header, `wcount` = 1, `rcount` = 0 |
| 5 | address |
| 6 | data |
| (7) | CRC32 |

Writes are posted: acknowledged once sent. **A read** is a round trip: A sends a record with `rcount` = 1 (return address, then the address to read); B reads its bus and answers with a record with `wcount` = 1 (return address, then the data).

**On the line.** Each 32-bit word is 4 bytes, each an 8b/10b symbol (data as D characters). Between packets the line carries control symbols, K flag set, in byte 0 of a word:

| Symbol | Use |
|---|---|
| K28.5 | comma: alignment at link start-up |
| K28.1 | fill when there is nothing to send (with flow control; without it, zero words) |
| K28.3 / K28.4 | XOFF / XON: pause and resume the far transmitter (flow control, both sides) |

**On our PHY**, 8 symbols per clock: two SerWB words per 31.25 MHz clock, the first in bytes 0-3, the second in bytes 4-7, each K flag with its byte. LiteICLink's 4-symbol SerWB encoder is then replaced by the PHY's 8-symbol path (see the table above): interoperability is at the packet layer.

## Conversion process

LiteICLink is Python (Migen). We port it by hand, block by block:

1. Read the Migen module and its tests; pick the SV structure (packages, `always_ff`, one module per Migen class).
2. Write the SV to our [RTL coding rules](#rtl-coding-rules).
3. Generate test vectors from LiteX's own Python model ([`../2.sim/gen_8b10b_vectors.py`](../2.sim/gen_8b10b_vectors.py), [`gen_prbs_vectors.py`](../2.sim/gen_prbs_vectors.py)), and compare clock for clock in Verilator.
4. Lint, format and, for clean-ups, prove equivalence with [`../3.build`](../3.build) (`run-lint.sh`, `run-format.sh`, `run-leq.sh`).
5. When upstream moves, regenerate the vectors: unchanged vectors mean the port still matches.

Where LiteICLink's structure does not fit `CC_SERDES` (the PHY), we keep its interface and write new RTL.

#### End-of-Document
