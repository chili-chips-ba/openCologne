<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# SerDes BFM: an open-source model of the GateMate SerDes

`ccfpga_serdes.sv` is an open-source behavioural model of the GateMate SerDes hard macro (`CC_SERDES`), for simulation. It has the module name, ports, parameter names and defaults of Cologne Chip's simulation model, so it is a drop-in replacement: point the file list here, and nothing else in the design or the testbench changes. It needs no NDA and no vendor tools, and runs in Verilator and Icarus Verilog.

For hardware, the design instantiates the `CC_SERDES` primitive. This model stands in for it in simulation only.

It was developed in [openCologne](https://github.com/chili-chips-ba/openCologne) (7.SerDes) and is used by [openCologne-PCIE](https://github.com/chili-chips-ba/openCologne-PCIE). This folder is the master copy.

| File | Content |
|---|---|
| [`ccfpga_serdes.sv`](ccfpga_serdes.sv) | the model |
| [`ccfpga_serdes_pkg.sv`](ccfpga_serdes_pkg.sv) | 8b/10b codec and PRBS as functions, the model settings (`CDR_MODEL`, `BHV_*`) |
| [`Makefile`](Makefile) | its own tests: `make -C 7.SerDes/1.sim-model` runs `sim_modes`, `sim_icarus` and `formal` |
| [`tb_modes.sv`](tb_modes.sv) | one model looped back: the three `CDR_MODEL`s against each other, PRBS, decode table, registers |
| [`tb_rules.sv`](tb_rules.sv) | the model's behaviour at its ports, rule by rule, as the vendor's model behaves; runs on that model too |
| [`ccfpga_serdes.vlt`](ccfpga_serdes.vlt) | Verilator: no lint on the model |
| [`formal_8b10b/`](formal_8b10b) | formal proofs of the 8b/10b codec (`run-formal.sh`) |
| [`vendor-check/`](vendor-check/vendor-check.sh) | runs against the vendor model, which you bring (NDA): `tb_rules`, side-by-side equivalence, port probes |
| [`0.doc/equivalence-checking.md`](0.doc/equivalence-checking.md) | how the model is checked against the vendor's |

## Why

The vendor model is under NDA and slow: 10 to 19 times slower than this one in Icarus (see [Speed](#speed)), and Verilator can't build it. This model is fast, open, and runs your RTL as built: no co-simulation, no VProc. It also behaves like the silicon where a careless model wouldn't: the RX word counter starts at a random phase, so a comma can land in any lane the configuration allows, and logic that assumes lane 0 fails in simulation, not on the board.

## Quick start

Compile the package first, then the model, then your design and testbench.

```sh
# Verilator
verilator --binary --timing --timescale 1ns/1ps \
  ccfpga_serdes_pkg.sv ccfpga_serdes.sv <design and testbench>

# Icarus Verilog
iverilog -g2012 ccfpga_serdes_pkg.sv ccfpga_serdes.sv <design and testbench>
```

The model is not lint-clean by our RTL rules, on purpose (see [Implementation](#implementation)). Verilator users can turn lint off for it, as [`ccfpga_serdes.vlt`](ccfpga_serdes.vlt) does.

**Bring-up** is the silicon's: enable the SerDes in the config file (`0x5C = 0x0001`), set the PLL in the regfile, then release the TX and RX resets. Two working examples:

- openCologne: [`iclink_serdes_gm.sv`](../3.iclink-sv/1.hw/iclink_serdes_gm.sv), a bring-up FSM of 3 writes (`iclink_phy_pkg::cfg_seq()`): the PLL for the line rate (`0x51`), SerDes enable, PLL on (`0x50`).
- openCologne-PCIE: `2.rtl/4.dll/sim/phy_model.sv`, and `writeCfg` / `writeRegfile` tasks in `2.rtl/1.phy/3.sim/tb_phy.sv`.

## Settings

Everything the vendor model has is a parameter, with its name and default. The model's own settings are not: they live in the package, one value for every instance, so the parameter list stays the vendor's.

| Setting | Default | Set by | What it does |
|---|---|---|---|
| `CDR_MODEL` | `NONE` | define | The serial line and receiver: `NONE`, `FAST` or `ACCURATE` (below) |
| `BHV_RX_WORD_PHASE_RANDOM` | `1` | define | The RX word counter starts at a random symbol, from the simulator seed, as on the silicon. `0`: it starts at 0, the comma in lane 0 |
| `BHV_PLL_LOCK_TIME_NS` | `500.0` | package | PLL reset to lock. `35200.0` matches the vendor model |
| `BHV_REF_CLK_MHZ` | `0.0` | package | Reference clock; `0.0`: measured at run time |
| `BHV_RX_PRESENT` | `1` | package | What receiver detection finds |
| `BHV_RX_DETECT_TIME_NS` | `120.0` | package | Receiver detection time |
| `BHV_CDR_KP` | `0.125` | package | `ACCURATE`: CDR loop gain |
| `BHV_CDR_LOCK_EDGES` | `32` | package | Line edges to CDR lock |
| `BHV_RX_PIPE_STAGES` | `3` | package | RX output delay, in clocks |
| `BHV_RX_TCO_NS` | `0.1` | package | RX clock to outputs |
| `BHV_VERBOSE` | `0` | package | Debug prints |

Defines: `+define+CDR_MODEL=FAST` in Verilator, `-DCDR_MODEL=FAST` in Icarus. Edit the others in [`ccfpga_serdes_pkg.sv`](ccfpga_serdes_pkg.sv).

## Three levels of line and receiver: `CDR_MODEL`

`CDR_MODEL` picks how the serial line and the receiver are modelled, one level for every instance in a simulation. Everything else, from the fabric ports to the deserializer, is the same in all three.

| | `NONE` | `FAST` | `ACCURATE` |
|---|---|---|---|
| The line (`TX_SERIO_P/N`) | no bits: whole words travel beside the pins, through the package, at the far TX's pace. P and N only tell each RX, once at start, which TX is its peer | real bits, one event a UI | real bits, one event a UI |
| The receiver | takes the peer's word as a line would hand it over: up to the next word boundary of the alignment, the rest with the next word | an ideal sampler: bit centres on a UI grid, taken in bulk at each line edge, and after a word without one (a stuck line). An edge within UI/4 of the grid moves the grid (the CDR, at once); others, like a glitch, don't, until lock is lost | a sampler every UI, steered by a first-order CDR loop: each line edge measures the phase error against mid-UI and moves the next sample by `BHV_CDR_KP` times it |
| CDR lock | at once | `BHV_CDR_LOCK_EDGES` edges on the grid lock it, as many off it lose it | the same, edges within UI/4 |
| Latency against `ACCURATE` | +0.5 UI | +0.5 to 2.5 UI: it knows a bit only at the next edge, and 8b/10b runs are 5 bits at most | reference |
| A glitch on the pins | inverts the bits it covers | is seen as edges, as on a wire | is seen as edges |
| Speed (Verilator, `tb_modes`) | 0.016 s, fastest | 0.058 s | 0.098 s |
| Both ends must be | `NONE` | anything with a real line | anything with a real line |
| Use it for | regressions, long runs, protocol work | the line in waves, a peer that is not this model (the vendor's, a cross-link) | CDR lock and tracking, frequency offset between ends |

The three agree word for word, with latencies within 4 UI of each other (`sim_modes`, below). `NONE` puts no bits on the line, so a vendor-model receiver can't decode it.

## Parameters

The model takes all 115 parameters of the vendor model, with their names and defaults, so any instantiation of it works unchanged. It acts on 38. 7 more only set a register value to read back. The other 70 tune what a digital model doesn't have; it accepts them for drop-in compatibility. A value the datasheet doesn't allow (UG1001 Tables 7.12 to 7.14, DS1001 Tables 2.15 to 2.17), or one the model doesn't model, stops the simulation (`$error`, then `$fatal`). So do a bad `PLL_CFG1` or `RX_BUF_CFG` written at run time, when it takes effect. Example: `PLL_OUT_DIVSEL = 2`, n.a. in DS1001 Table 2.15.

**Modelled (34):**

| Group | Parameters | What they do in the model |
|---|---|---|
| PLL and clocks (8) | `PLL_FCNTRL`, `PLL_MAIN_DIVSEL`, `PLL_OUT_DIVSEL` | the line rate, 2 x f_ref x N1·N2·N3 / M3, and the core clock, line rate / (2 x M1 x M4): e.g. 2.5 Gb/s and 31.25 MHz from 100 MHz, with `PLL_OUT_DIVSEL` = 1 (M3 = 2) and 64 bits (DS1001 Tables 2.15 to 2.17) |
| | `PLL_EN_ADPLL_CTRL` | `PLL_CFG0` bit 0 after reset: the PLL on |
| | `PLL_REF_SEL`, `PLL_REF_RTERM` | `PLL_CFG0` bits 10, 11, out on `REFCLK_SEL_O`, `REFCLK_RTERM_O` |
| | `PLL_CONFIG_SEL` | `PLL_CFG0` bit 1: 1, the line rate from `PLL_CFG1`; 0, fixed from `PLL_OUT_DIVSEL` |
| | `PLL_REF_BYPASS` | `PLL_CFG0` bit 9: `PLL_CLK_O` straight from the reference |
| Datapath (2) | `RX_DATAPATH_SEL`, `TX_DATAPATH_SEL` | 16, 32 or 64 bits a word; `TX_DATAPATH_SEL[1]` is M4 = 2 |
| Resets (10) | `RX_PMA_RESET_TIME`, `RX_EQA_RESET_TIME`, `RX_CDR_RESET_TIME`, `RX_PCS_RESET_TIME`, `RX_BUF_RESET_TIME`, `TX_PMA_RESET_TIME`, `TX_PCS_RESET_TIME` | the TX and RX reset sequences, in timer ticks |
| | `RX_RESET_TIMER_PRESC` | the timers tick every 2^N clocks |
| | `RX_WAIT_CDR_LOCK` | RX reset done waits for the CDR lock |
| | `RX_RESETDONE_GATE` | 1: RX reset done stays low |
| CDR (1) | `RX_CDR_FORCE_LOCK` | the CDR reports lock at once |
| Comma alignment (5) | `ALIGN_MCOMMA_VALUE`, `ALIGN_PCOMMA_VALUE`, `ALIGN_COMMA_ENABLE` | the comma patterns, 10 bits in line order, and the bits compared |
| | `ALIGN_COMMA_WORD` | where an aligned comma lands: any lane, an even lane, lane 0 or 4. `RX_ALIGN_COMMA_WORD` on `CC_SERDES` |
| | `RX_SLIDE_MODE` | `RX_SLIDE_I`: off, one bit, one byte |
| RX buffer (8) | `RX_BUF_BYPASS` | no RX buffer: one write stage |
| | `RX_CLKCOR_USE`, `RX_CLKCOR_MIN_LAT`, `RX_CLKCOR_MAX_LAT`, `RX_CLKCOR_SEQ_1_0` to `_1_3` | clock correction: the sequence, and the fill levels that insert and remove it ([below](#rx-buffer-and-clock-correction)) |
| TX buffer (1) | `TX_BUFFER_ADDR_WIDTH` | must stay 5: the TX buffer is 32 words |
| Loopback (1) | `TX_PMA_LOOPBACK` | TX to RX inside the PMA, as `LOOPBACK_I` |
| Electrical idle (2) | `RX_EI_BIAS`, `RX_EI_BW_SEL` | `RX_EI_EN_O`: 0 turns the detector off; idle for `RX_EI_BW_SEL` reference clocks (1 to 8), as DS1001 Table 2.43 |

**Read back only (7):** `PLL_SET_OP_LOCK`, `PLL_ENFORCE_LOCK`, `PLL_DISABLE_LOCK`, `PLL_LOCK_WINDOW`, `PLL_FAST_LOCK`, `PLL_SYNC_BYPASS`, `PLL_PFD_SELECT`. They set their bits of `PLL_CFG0`, which reads back as written; the PLL ignores them.

**Accepted for compatibility (70):** analog and calibration, which a digital model doesn't have. Their status registers report done or locked.

| Group | Parameters |
|---|---|
| RX front end, termination, equaliser (21) | `RX_CALIB_OVR`, `RX_CALIB_VAL`, `RX_RTERM_VCMSEL`, `RX_RTERM_PD`, `RX_EQA_CKP_HF`, `RX_EQA_CKP_LF`, `RX_EQA_CONFIG`, `RX_EQA_CKP_OFFSET`, `RX_EN_EQA`, `RX_EQA_LOCK_CFG`, `RX_TH_MON1_OVR`, `RX_TH_MON2_OVR`, `RX_TAPW_OVR`, `RX_AFE_OFFSET_OVR`, `RX_TH_MON1`, `RX_TH_MON2`, `RX_TAPW`, `RX_AFE_OFFSET`, `RX_AFE_VCMSEL`, `RX_AFE_GAIN`, `RX_AFE_PEAK` |
| CDR loop (6) | `RX_CDR_CKP` (the model's own: `BHV_CDR_KP`), `RX_CDR_CKI`, `RX_CDR_LOCK_CFG` (the model's own: `BHV_CDR_LOCK_EDGES`), `RX_CDR_SET_ACC_CONFIG`, `RX_CDR_FREQ_ACC`, `RX_CDR_PHASE_ACC` |
| Eye monitor, debug (5) | `RX_EYE_MEAS_CFG`, `RX_MON_PH_OFFSET`, `RX_DBG_SRAM_DELAY`, `RX_DBG_SEL`, `RX_DBG_MODE` |
| TX driver (16) | `TX_SEL_PRE`, `TX_SEL_POST`, `TX_TAIL_CASCODE`, `TX_BRANCH_EN_PRE`, `TX_BRANCH_EN_MAIN`, `TX_BRANCH_EN_POST`, `TX_DC_ENABLE`, `TX_AMP`, `TX_DC_OFFSET`, `TX_CM_RAISE`, `TX_CM_THRESHOLD_0`, `TX_CM_THRESHOLD_1`, `TX_CALIB_OVR`, `TX_CALIB_VAL`, `TX_CM_REG_EN`, `TX_CM_REG_KI` |
| PLL loop, calibration (22) | `PLL_CI`, `PLL_CP`, `PLL_AO`, `PLL_SCAP`, `PLL_SCAP_AUTO_CAL`, `PLL_FILTER_SHIFT`, `PLL_SAR_LIMIT`, `PLL_FT`, `PLL_OPEN_LOOP`, `PLL_BISC_MODE`, `PLL_BISC_TIMER_MAX`, `PLL_BISC_CP_MIN`, `PLL_BISC_CP_MAX`, `PLL_BISC_CP_START`, `PLL_BISC_OPT_DET_IND`, `PLL_BISC_PFD_SEL`, `PLL_BISC_DLY_DIR`, `PLL_BISC_CAL_SIGN`, `PLL_BISC_CAL_AUTO`, `PLL_BISC_DLY_PFD_MON_REF`, `PLL_BISC_DLY_PFD_MON_DIV`, `PLL_BISC_COR_DLY` |

## Features

- **Register and config file:** the address map (`0x00` to `0x42` RX/TX, `0x50` to `0x5B` PLL, `0x5C` SerDes config), masked writes, the `regfile_rdy_o` handshake. Status registers of blocks not modelled read back as converged, so code that polls them goes on. `PLL_CFG5` bit 0 reads the PLL lock.
- **PLL:** the line rate from `PLL_FCNTRL`, `PLL_MAIN_DIVSEL` and `PLL_OUT_DIVSEL`, from the measured reference; the core clock for the datapath width. On an absolute time grid, so rates off the 100 fs grid don't drift (tested: 3 Gb/s for 5 ms).
- **TX:** 8b/10b with running disparity, `tx_char_dispmode` / `dispval` forcing, per-byte bypass, the TX buffer (32 words; `TX_BUFFER_ADDR_WIDTH` must stay 5) with its errors, serializer, electrical idle, polarity, PRBS7/15/23/31 with error injection (each rising edge of `TX_PRBS_FORCE_ERR_I` makes one bit wrong, which the checker counts as 3). PRBS23 and 31 are extensions: DS1001 lists PRBS7 and 15.
- **RX:** the receiver by [`CDR_MODEL`](#three-levels-of-line-and-receiver-cdr_model), deserializer, comma detection, byte and word alignment by `ALIGN_MCOMMA_VALUE`, `ALIGN_PCOMMA_VALUE`, `ALIGN_COMMA_ENABLE` and `ALIGN_COMMA_WORD` (= `RX_ALIGN_COMMA_WORD` of `CC_SERDES`), bit slide, polarity, 8b/10b decode with `not_in_table` and `disp_err`, the RX buffer with clock correction (below), PRBS checker. While comma alignment is on, a comma off the word boundary realigns (DS1001 Table 2.50).
- **Reset sequencers,** TX and RX, with the PMA/PCS/CDR/EQA/BUF reset timers.
- **Receiver detection, electrical-idle detection, PCS and PMA loopback.** Electrical idle is P = N for 20 UI, like an envelope detector; 8b/10b has an edge at least every 5 UI, so live traffic never looks idle. In `NONE` one TX can feed any number of receivers.

### Not modelled

None of it is visible at the fabric interface: analog and PMA internals (driver taps and emphasis, termination calibration, AFE gain and peaking, equaliser adaptation, eye monitor), ADPLL internals (DCO tuning, calibration: the PLL locks after `BHV_PLL_LOCK_TIME_NS`), scan and debug capture. Signal integrity, jitter tolerance and equalisation belong to board measurement, not to a digital model.

### Where DS1001 is silent: as the vendor model

Where the datasheet says nothing, the model does at its ports what Cologne Chip's simulation model does. [`tb_rules.sv`](tb_rules.sv) checks it: 55 checks at 64 bits, each a PASS or FAIL line, and runs unchanged on the vendor model ([`vendor-check`](vendor-check/vendor-check.sh)). The main ones:

- **Comma alignment** locks after 16 aligned commas. Once locked, a comma in another lane is not corrected, while a comma off the symbol boundary still realigns. `RX_BYTE_REALIGN_O` is a pulse.
- **16 and 32-bit TX:** the line takes the quarters (halves) of `TX_DATA_I` in turn.
- **Running disparity** starts at RD+.
- **Register file:** `REGFILE_RDY_O` after 3 clocks (no register), 5 (a config register) or 16 (PLL status); a write that comes while the file is busy is lost.
- **Resets:** each reset input reruns its stage and the later ones; done comes 12 to 28 clocks after, as measured on the vendor model.
- **TX buffer:** `TX_BUF_ERR_O` is sticky until `TX_PCS_RESET_I`; with `TX_CLK_I` stopped, zero symbols go out and no error is flagged.
- **PLL:** `PLL_CONFIG_SEL` = 0 ignores `PLL_CFG1`; `PLL_REF_BYPASS` puts the reference on `PLL_CLK_O`. With the PLL on, a write drops any change to `PLL_CFG0[9:1]` or `PLL_CFG1`, and the model gives a `$warning`: set them with bit 0 = 0, then turn the PLL on. Our own IC Link bring-up fell into this one.

Where the vendor model contradicts DS1001, the model follows DS1001 and its rule is tagged `DS`: `RX_EI_EN_O` at the default `RX_EI_BW_SEL`, and register defaults. On the vendor model, those rules fail, as they should.

### RX buffer and clock correction

DS1001 (Tables 2.56, 2.57) gives the rule: below `RX_CLKCOR_MIN_LAT` the buffer repeats incoming clock-correction sequences, above `RX_CLKCOR_MAX_LAT` it removes them. The sequence is 4 symbols (`RX_CLKCOR_SEQ_1_0..3`), `RX_BUF_ERR_O` flags overflow and underflow, and `RX_CLKCOR_USE = 0` uses the buffer for phase only. It doesn't give the depth, how a sequence is matched, or what an insertion repeats. The model fills these in as below: to check on silicon.

| | Model behaviour |
|---|---|
| Unit | The buffer holds whole datapath words (16, 32 or 64 bits), 64 of them. `MIN_LAT` / `MAX_LAT` count words. |
| Sequence | 4 symbols, each `{comma, K, byte}` as decoded (`RX_CLKCOR_SEQ_1_0..3`, default `10'h1F7`: K23.7). The whole word must match: a 64-bit word holds the sequence twice. Lanes outside the datapath width always match; disparity and table errors take no part. |
| Remove | Occupancy above `MAX_LAT`: of two matching words in a row, the second is not written. |
| Insert | Occupancy below `MIN_LAT` - 1: the read stalls on a matching word, and the output repeats the word **before** it. |
| Off (`RX_CLKCOR_USE = 0`) | Phase only, limits fixed at 4 and 60. |
| Error | `RX_BUF_ERR_O` for occupancy below 3 or above 60, until `RX_BUF_RESET_I`. |

If the silicon works the same, three things follow for a protocol:

1. A single sequence word is never removed. It takes two in a row.
2. An insertion repeats the previous word. It is safe only when that word is harmless to repeat: another sequence word, or idle.
3. The sequence must sit aligned in the datapath word.

PCIe's SKP ordered set meets none of these, so a PCIe endpoint should keep `RX_CLKCOR_USE = 0` and run from the host's REFCLK. How 7.SerDes uses clock correction, and the PCIe details: [clock correction](../0.doc/clock-correction.md). Questions to Cologne Chip: [gatemate-pipe#14](https://github.com/colognechip/gatemate-pipe/issues/14).

### Implementation

A behavioural model, not RTL: `#` delays (the serializer, sampler, CDR, clocks and PLL lock run in real time), queues and events. Processes are plain `always`, assignments blocking, in reverse pipeline order; non-blocking only where another process samples the same clock edge: outputs to the fabric, and what crosses between the RX buffer's two sides. The RX outputs change `BHV_RX_TCO_NS` after the `clk_core_rx_i` edge, like a flop, so logic on a clock derived from the same edge samples them cleanly. The 8b/10b codec and the PRBS are functions in the package.

## Verification

| Check | What | Where | Result |
|---|---|---|---|
| Formal | the 8b/10b codec: disparity, running disparity, comma format, injectivity, run length; exhaustive decode | [`formal_8b10b/`](formal_8b10b/README.md) | 6 of 6 |
| `sim_modes` | the three `CDR_MODEL`s against each other at 16, 32 and 64 bits, comma in every lane: data bit-exact, latency within 4 UI; PRBS with forced errors; 5 ms at 3 Gb/s; the random word phase; the decode table (all 1024 symbols), comma defaults, register readback, buffer errors. Then `tb_rules` | `make -C 7.SerDes/1.sim-model sim_modes` | 38 runs, 9 mode comparisons, 6 `tb_rules` runs: all pass |
| `sim_icarus` | `tb_modes` and `tb_rules` in Icarus, each `CDR_MODEL`: keeps the model Icarus-clean | same, `make sim_icarus` | 15 + 6 runs, all pass |
| `tb_rules` on the vendor model | the same 55 rules (64 bits), on Cologne Chip's model | `vendor-check/vendor-check.sh rules 3 0` (needs the NDA model) | 54 of 55: the one `DS` rule fails, as it should |
| Side by side with the vendor model | both models, same configuration and symbols: each looped back, and crossed (each one's TX into the other's RX); 8b/10b in the SerDes or in the fabric; 16, 32 and 64 bits | `vendor-check/vendor-check.sh equiv`; openCologne-PCIE `run-phy.sh equiv --ref [--cross]` | 32 and 64 bits: 0 divergences, every case. 16 bits: gaps on the vendor side (below) |
| Vendor's own testcase | the PIPE test of Cologne Chip's PIPE testbench | openCologne-PCIE, `run-phy.sh pipe64` | pass, 101 checks |

**Against the vendor model** (2026-10-24, 2.5 Gb/s, 64 bits, 400 words): logic equivalence checking doesn't fit, since the vendor model is not synthesizable and the two pipelines differ on purpose. So both run side by side, and each one's received words, from a start marker on, are compared as streams: equivalence modulo latency. Cross-linking makes each model decode the other's serial format, which a model talking only to itself can't show. The method in full: [`0.doc/equivalence-checking.md`](0.doc/equivalence-checking.md).

| Check | NONE | FAST | ACCURATE |
|---|---|---|---|
| Self-loopback | 0 divergences, latency 736.0 ns on both models | same | same |
| Cross-linked | n/a (no bits on the line) | 0 divergences | 0 divergences |

**2026-10-26, after the move to the vendor model's behaviour** (`vendor-check.sh equiv`, 200 words, 36 cases, `FAST` and `ACCURATE`):

| Datapath | Looped back | Crossed |
|---|---|---|
| 64 bits (IC Link, PCIe PIPE 64) | 0 divergences | 0 divergences |
| 32 bits, 8b/10b in the fabric | 0 divergences | 0 divergences |
| 16 bits | the vendor model's own loop disagrees with the data sent, the model's doesn't | 0 divergences, but `FAST` with the 8b/10b in the SerDes: 77 symbols |

**At 16 and 32 bits, the built-in 8b/10b encoder is not self-sufficient.** On its own it puts wrong disparity on the line; the fabric has to encode, or fix the disparity.

| 8b/10b in the SerDes | Data and K | `RX_DISP_ERR_O` set |
|---|---|---|
| 64 bits | right | 0 symbols |
| 32 bits | right | 80 to 92 of 800 |
| 16 bits | right | 84 of 400 |

- **Why:** the encoder chains the running disparity lane 0 to 7 in each word, but at 16 and 32 bits the line takes the quarters / halves of the words in turn (DS1001 2.5.5.1). So a lane sent, past the first quarter / half, takes its disparity from a lane of the same word that is not sent. At 64 bits every lane is sent, in chain order.
- **Data dependent:** with the word in every quarter / half, a copy is right only if the copies before it leave the disparity as it was. Both models do this, so it is the vendor's design, as modelled; on silicon it is not checked (asked of Cologne Chip).
- **Workarounds:** encode in the fabric (done here, 0 errors). Untested: keep the 8b/10b in the SerDes, track the disparity in the fabric and force it per lane with `TX_CHAR_DISPMODE_I` / `TX_CHAR_DISPVAL_I`.

IC Link and PCIe PIPE 64 use 64 bits only, so neither is affected.

The 80 or 92 at 32 bits depends only on the testbench: whether the payload starts an odd or even number of clocks after the TX reset, that is, which half goes out first. Both models' TXs and RXs agree: one line into both RXs flags the same symbols.

So the model is the vendor's equal at 32 and 64 bits. At 16 bits the gaps are on the vendor side. Its RX buffer flags `RX_BUF_ERR_O` for 150 to 260 clocks around start-up, and once for about 1.6 µs in its own loop, while the payload goes through, so that data is wrong; an `RX_BUF_RESET` doesn't shorten it. The 77 symbols are the same window: with `FAST`, the payload starts earlier. Its cause, inside the vendor model, is not found yet. Not lane rotation: both models' TX lines decode cleanly on the other's RX.

`FAST` used to lose the vendor model's line at 16 and 32 bits. At its TX reset, that line carries 150 ns of X, then a 44 ns run with no edges. `FAST` takes bits only at edges, so its words stopped, and the RX buffer underflowed. Now a watchdog takes the bits when a word passes without an edge, as `ACCURATE`'s sampler does.

### Speed

Wall clock on one PC, best of 3. PIPE 64: the openCologne-PCIE PHY test, about 280 µs simulated, which runs any of the models. `tb_modes`: the model looped back, 64 bits.

| Model | Icarus, PIPE 64 | Icarus, `tb_modes` | Verilator, `tb_modes` |
|---|---|---|---|
| this model, `NONE` | 4.5 s | 0.71 s | 0.016 s |
| this model, `FAST` | 8.9 s | 1.22 s | 0.058 s |
| this model, `ACCURATE` | 8.5 s | 1.19 s | 0.098 s |
| vendor model (NDA) | 86 s | - | - |

In Icarus the vendor model is 10 to 19 times slower (86 s against 8.9 and 4.5 s). The [equivalence-checking](0.doc/equivalence-checking.md) run gives about 20 times on the vendor's own testcase, wall clock with compilation. Verilator is 12 to 44 times faster than Icarus, and can't build the vendor model. In Icarus, `FAST` and `ACCURATE` cost about the same, since `FAST` still follows every line edge; in Verilator, `ACCURATE` costs 1.7 times `FAST`. `NONE` skips the serial line and is the fastest.

## Where it is used

| Project | Flow |
|---|---|
| openCologne | [7.SerDes](../3.iclink-sv/2.sim/README.md): the IC Link PHY, one-way and two-way; the board top with the FIFO pump; `sim_link_ppm`, two boards 200 ppm apart kept in step by the RX buffer's clock correction (`MIN_LAT` 8, `MAX_LAT` 12, K23.7 bursts); `sim_modes`, `sim_icarus` |
| openCologne-PCIE | `2.rtl/1.phy/3.sim` (`run-phy.sh pipe64`, `equiv`): the PIPE test and the vendor comparison; `2.rtl/4.dll/sim`: DLL, MAC/LTSSM, PIPE and this SerDes, two link partners |

## License

BSD-3-Clause, Chili.CHIPS. The vendor model is not part of this repository; the vendor comparison takes it from outside the tree (openCologne-PCIE `2.rtl/1.phy/3.sim/serdes_nda_env.sh`).
