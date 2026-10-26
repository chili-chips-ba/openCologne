<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Verifying the opensource SerDes BFM against the vendor model

How do you convince yourself that a hand-written behavioural model really behaves
like the thing it replaces? This is the note that answers that question for the
GateMate SerDes model in this directory, and it doubles as a short introduction
to **Logic Equivalence Checking (LEC)** and **Formal Verification (FV)** and to
where each one does and does not apply.

---

## 1. The three techniques, and what each is good for

| | what it does | what it proves | needs |
|---|---|---|---|
| **Simulation** | run both designs on stimulus, compare outputs | correct on *the stimulus you ran* | anything runnable |
| **LEC** | prove two designs compute the same function | correct on *all* inputs, forever | both sides synthesizable, finite state, a state mapping (or matching I/O timing) |
| **FV / model checking** | prove *properties* of one design | the stated property holds on all inputs | design synthesizable; you must write the properties |

The important row is the "needs" column. It is what decides which technique you
are even allowed to use.

---

## 2. Why full LEC of the whole SerDes is not a well-posed question

The natural first instinct is "just run LEC between the vendor model and my
model". That cannot work here, and it is worth understanding exactly why,
because the reason is not laziness:

1. **The vendor model is not synthesizable, by design.** It is full of things a
   formal tool has no semantics for: real-valued delays, random jitter draws,
   `$realtime` arithmetic, transport delays, `specify` blocks, and
   analog-flavoured primitives that model a differential
   driver and a termination network. LEC operates on a Boolean netlist. There is
   no netlist here.

2. **The two designs are not the same machine.** LEC proves that two
   implementations of the *same* specification match. The whole point of the
   behavioural model is that it is deliberately a *different, smaller* machine:
   no DCO tuning word, no BISC calibration state, no DFE adaptation loop, no eye
   measurement counters. Asking whether they are state-equivalent is asking a
   question whose answer is knowably "no", and that "no" tells you nothing about
   whether the model is fit for purpose.

3. **They do not even have the same latency by construction.** They agree only
   after retiming. Sequential LEC across differing pipeline depths needs a
   latency mapping supplied by hand, which is exactly the fact we want to
   *measure*, not assume.

So the honest answer is: **LEC does not apply to the SerDes as a whole.** What we
do instead is split the problem.

---

## 3. What we actually do

### 3.1 The combinational core: real formal proof

The 8b/10b codec *is* pure combinational logic over a small input space. That is
exactly the shape formal tools are strongest on, so it gets proper proofs.

[`formal_8b10b/fv_8b10b.sv`](../formal_8b10b/fv_8b10b.sv) states each property as a module with a single `ok`
output. Yosys builds the logic cone and asks its SAT solver to find **any** input
that makes `ok` low. "unsat" means no such input exists anywhere in the input
space. That is a proof, not a sample.

```sh
bash 7.SerDes/1.sim-model/formal_8b10b/run-formal.sh   # from the openCologne root
```

| property | statement |
|---|---|
| `fv_enc_disparity` | the encoder never emits a symbol with fewer than 4 or more than 6 ones |
| `fv_enc_rd_tracking` | the running disparity the encoder reports is the one the symbol actually implies |
| `fv_comma_format` | K28.5 at RD- and RD+ encode to exactly the vendor's `ALIGN_PCOMMA_VALUE` / `ALIGN_MCOMMA_VALUE` defaults |
| `fv_injective` | no two different (byte, K) inputs encode to the same symbol under the same running disparity |
| `fv_run_length` | never more than five identical bits in a row, including across a symbol boundary |

Two of these are deliberately anchored to something **outside** the model.
`fv_comma_format` is tied to constants the vendor publishes; `fv_run_length` is
tied to the defining guarantee of the 8b/10b code. Properties that only relate
the model to itself (round trip, injectivity) cannot catch a model that is
consistently wrong, see section 5.

The decode table is a procedurally initialised memory, which SAT cannot take. It
does not need to: its input space is 1024 symbols, so
`fv_8b10b_exhaustive.sv` simply enumerates **all** of it. For a space that small,
exhaustive enumeration is as complete an argument as a SAT proof.

Note what `fv_injective` buys us. The decode table is *built from the encoder* at
time zero. If the encoder is injective, no table entry can ever be overwritten by
a different input, and therefore `decode(encode(x)) == x` holds **by
construction** for the whole code space. One formal property discharges a whole
class of decoder bugs.

### 3.2 The sequential whole: equivalence by simulation, modulo latency

For the full SerDes, the model check in openCologne-PCIE's [`2.rtl/1.phy/3.sim/tb_phy.sv`](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/3.sim/tb_phy.sv) (`TB_PHY_EQUIV`) instantiates **both** models side
by side, gives them a bit-identical configuration sequence and a bit-identical
symbol stream, and compares what comes back.

Crucially it does **not** compare outputs at the same simulation instant. Each
instance's received word stream is captured into its own queue, keyed off a
unique start marker, and the queues are then compared element by element. That
is *sequential equivalence modulo latency* — the right relation to check between
a functional model and an implementation that may be pipelined differently. The
latency of each model is measured and reported separately.

```sh
# in openCologne-PCIE; --ref needs the NDA vendor model
bash 2.rtl/1.phy/3.sim/run-phy.sh equiv                 # open model self-check, ~2 s
bash 2.rtl/1.phy/3.sim/run-phy.sh equiv --ref           # vs the vendor model
bash 2.rtl/1.phy/3.sim/run-phy.sh equiv --ref --cross   # the two models talking to EACH OTHER
```

### 3.3 Self-loopback is not enough — the `--cross` mode

By default each instance loops its own transmitter back to its own receiver.
That checks the datapath, but it has a blind spot you must understand:

> **A model that talks only to itself is self-consistent by construction.**
> A wrong 8b/10b bit ordering, or a control character encoded with the wrong
> disparity variant, passes a self-loopback test *perfectly* — the receiver
> simply undoes whatever the transmitter did — and then fails against real
> silicon.

`--cross` wires the two instances to each other: the open model's transmitter
drives the vendor model's receiver, and vice versa. Now the open model has to
interoperate over the actual serial format. This is the test that matters for
talking to a real Root Complex.

---

## 4. Results

Configuration: Gen1, 2.5 Gb/s, x1, 64-bit datapath, `ALIGN_COMMA_WORD = 2'b11`.

**Formal (`formal_8b10b/run-formal.sh`)**

```
  fv_enc_disparity     PROVED
  fv_enc_rd_tracking   PROVED
  fv_comma_format      PROVED
  fv_injective         PROVED
  fv_run_length        PROVED
  exhaustive decode    PASSED (complete over the code space)
  6 proved, 0 failed
```

**Equivalence, self-loopback (`run-phy.sh equiv --ref`)**

```
  CHECK 1  behavioural model vs expected payload : 400 words, 0 mismatches
  CHECK 2  vendor model      vs expected payload : 400 words, 0 mismatches
  CHECK 3  behavioural vs vendor  (EQUIVALENCE)  : 400 words, 0 divergences

  LATENCY  BHV 736.0 ns   REF 736.0 ns   delta 0.0 ns
```

**Interoperability, cross-linked (`run-phy.sh equiv --ref --cross`)**

The open model's transmitter driving the vendor model's receiver, and the vendor
model's transmitter driving the open model's receiver:

```
  CHECK 1  open model decoding the VENDOR's transmission : 400 words, 0 mismatches
  CHECK 2  vendor model decoding the OPEN model's output : 400 words, 0 mismatches
  CHECK 3  the two received streams agree                : 400 words, 0 divergences
```

The two models interoperate over the actual serial format, in both directions.
That is the result that matters for talking to real silicon.

Also run: 6000 payload words through the open model with no mismatch, to check
that nothing drifts over a long stream (elastic buffers, CDR tracking).

**The vendor's own testcase** (the PIPE test in `tb_phy.sv`, from `testcase_pipe.v` of the
CologneChip/FH Dortmund PIPE testbench):

| model | wall clock | result |
|---|---|---|
| vendor `ccfpga_serdes` | 5 min 16 s | PASSED |
| open behavioural model | ~14 s | PASSED, 101 check tasks, 0 errors |

Same testbench, same testcase, same checks, ~20x faster (wall clock including compilation). The [model README](../README.md#speed) times the simulation alone, on the PIPE 64 test: 10 to 19x.

---

## 5. What each check covers

The part of 8b/10b that is easiest to get wrong is the choice between the RD-
and RD+ variant of a sub-block. The general rule is: an unbalanced code is
complemented for RD+, a balanced code is sent unchanged. The standard tables
have three exceptions, balanced codes that are still complemented:

| exception | example | covered by |
|---|---|---|
| control characters K.x.1/2/3/5/6 | K28.5 is `0101111100` at RD-, `1010000011` at RD+ | `fv_comma_format` |
| D.7 in the 5b/6b block (`111000`) | every D7.x character | `fv_run_length` |
| D.x.3 in the 3b/4b block (`1100`) | every Dx.3 character | `run-phy.sh equiv --ref --cross` |

A model looped back to itself decodes its own symbols no matter which variant
it chose, because its decode table is built from its own encoder. These cases
are therefore covered by checks that compare against something outside the
model:

* **`fv_comma_format`** compares against constants the vendor publishes.
* **`fv_run_length`** checks the defining guarantee of 8b/10b, at most five
  identical bits in a row.
* **`--cross`** makes the vendor receiver decode the open model's symbols and
  the other way round. The D.x.3 case does not create a run of six, so only
  this check sees it.

Formal covers what can be stated as an invariant, cross-linked simulation covers
the wire format as a whole. Both are needed.

---

## 6. What is still not verified, and how you would go further

Being explicit about the gaps:

* **Analog behaviour** — signal integrity, jitter tolerance, equalisation, return
  loss. Not modelled at all, so not verified at all. This model will happily lock
  onto a stream that a real receiver would fail on.

  These belong to SI analysis, hardware measurement or S-parameters with
  IBIS-AMI / SPICE models, not to a digital simulation. On this project that is
  openCologne-PCIE's [`2.rtl/1.phy/1.serdes-test.STANDALONE`](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/1.serdes-test.STANDALONE) on the GateMate EVK.
* **Reset and power-state corner cases** — covered by the PIPE test, not
  formally.
* **PRBS and loopback modes** — PRBS7 and PRBS31 with forced errors, in every `CDR_MODEL`, in openCologne's `sim_modes`; not against the vendor model.
* **5 Gb/s** — runs in openCologne's PHY tests (`sim_phy_rates`: 1.25, 2.5 and 5 Gb/s); not yet against the vendor model.

The natural next step, if you want a stronger result on the sequential part, is
**bounded model checking** of the reset sequencers and the alignment FSM: state
them as SystemVerilog assertions, wrap them with SymbiYosys, and prove properties
like "once `rx_byte_is_aligned_o` is high, it stays high until a reset or a fresh
alignment request", or "`tx_resetdone_o` cannot rise before the PLL reports lock"
over an unbounded number of cycles by temporal induction. That is genuine formal
verification of the model's control logic, and unlike whole-design LEC it *is*
a well-posed problem.

---

## 7. Terminology, since these get mixed up

* **LEC / LEQ** (Logic Equivalence Checking) — proves two designs implement the
  same function. The classic use is RTL vs the gate netlist after synthesis:
  same specification, two implementations, no properties to write. Standard
  tools: Cadence Conformal, Synopsys Formality, and in open source
  `yosys equiv_make` / `miter` + `sat`.
* **FV** (Formal Verification) — the umbrella term. In practice it usually means
  **property checking**: you write assertions and a model checker proves them
  over all reachable states, or hands you a counterexample trace. Open-source
  route: SystemVerilog assertions plus SymbiYosys plus a SAT/SMT solver
  (Yices, Z3, Boolector).
* **Model checking** — the algorithm underneath FV. **BMC** (bounded model
  checking) proves a property for the first N cycles; **temporal induction**
  (k-induction) lifts that to all cycles when it succeeds.
* **Equivalence modulo retiming / latency** — what section 3.2 does: the designs
  agree as *streams*, after allowing for a pipeline-depth difference. This is
  the right relation whenever the two sides are not cycle-identical.

#### References
- [Yosys formal verification](https://yosyshq.readthedocs.io/projects/yosys/en/latest/using_yosys/more_scripting/interactive_investigation.html)
- [SymbiYosys documentation](https://symbiyosys.readthedocs.io)
- IEEE 802.3 Clause 36 — the 8b/10b transmission code tables
