<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# GateMate SerDes BFM: an open-source model of CC_SERDES

`ccfpga_serdes.sv` is a behavioural model of `CC_SERDES`, the GateMate SerDes hard macro, for simulation only. It has the module name (`ccfpga_serdes`), ports, parameters and defaults of Cologne Chip's simulation model, so it is a drop-in replacement. Hardware instantiates `CC_SERDES`.

Running it needs no NDA model. On a 64-bit link at 2.5 Gb/s it matches the vendor model word for word ([Verification](#verification)); where it still differs is [listed](#not-yet-as-the-vendor-model). This directory is its home; [openCologne-PCIE](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/2.serdes-model) carries a copy.

| File | Content |
|---|---|
| `ccfpga_serdes.sv` | the model |
| `ccfpga_serdes_pkg.sv` | its settings (`CDR_MODEL`, `BHV_*`), the 8b/10b codec, PRBS, PLL divider, register types, as functions |
| `tb_modes.sv` | the BFM's own testbench: one BFM looped back, every mode, width and comma lane |
| `Makefile` | `sim_modes`, `sim_icarus`, `formal` |
| `ccfpga_serdes.vlt` | Verilator waivers for the model: it is a model, not RTL |
| [`formal_8b10b/`](formal_8b10b/README.md) | proofs of the 8b/10b codec in the package |

## Usage

Compile the package first:

```sh
verilator --binary --timing -Wall ccfpga_serdes.vlt ccfpga_serdes_pkg.sv ccfpga_serdes.sv <design and testbench>
iverilog -g2012 ccfpga_serdes_pkg.sv ccfpga_serdes.sv <design and testbench>
```

Pick the mode at compile time, the same for every BFM: `+define+CDR_MODEL=FAST` (Verilator), `-DCDR_MODEL=FAST` (Icarus).

| `CDR_MODEL` | The line | Use |
|---|---|---|
| `NONE` (default) | no bits on the pins: words go beside them, through the package | fastest; both ends `NONE` |
| `FAST` | a real serial line; bits from the time between its edges | waves, serial decoders, the vendor model on the far end |
| `ACCURATE` | a real serial line; a sampler every UI, steered by a CDR loop | ppm and CDR behaviour |

Bring-up is the silicon's, through the config file and the register file: enable the SerDes (`0x5C` = `0x0001`), set the PLL (`PLL_CFG1`, `0x51`), turn it on (`PLL_CFG0`, `0x50`), wait for lock, release the TX and RX resets. openCologne 7.SerDes writes `0x51`, then `0x50` = `0x0C03`; Cologne Chip's PIPE wrapper writes `0x50` = `0x0002`, then `0x0003`.

Verilator is the reference simulator. The BFM also runs in Icarus Verilog 13. It is written as a model, not RTL: `#` delays, queues and events, plain `always`, blocking assignments in reverse pipeline order.

## Settings

The parameter list is the vendor's, nothing added. The BFM's own settings are in the package, one for every BFM.

| Setting | Default | What it does |
|---|---|---|
| `CDR_MODEL` | `NONE` | the mode, above (define) |
| `BHV_RX_WORD_PHASE_RANDOM` | on | the RX word counter starts at a random symbol, as on the silicon (define) |
| `BHV_PLL_LOCK_TIME_NS` | 500 | PLL reset to lock; 35200 is the vendor model's |
| `BHV_REF_CLK_MHZ` | 0 | reference clock; 0: measured at run time |
| `BHV_RX_PRESENT` | 1 | receiver detection finds a far end |
| `BHV_RX_DETECT_TIME_NS` | 120 | receiver detection time |
| `BHV_CDR_KP` | 0.125 | `ACCURATE`: CDR loop gain; 1.0 relocks on every edge |
| `BHV_CDR_LOCK_EDGES` | 32 | line edges to CDR lock |
| `BHV_RX_PIPE_STAGES` | 3 | RX output delay, in clocks |
| `BHV_RX_TCO_NS` | 0.1 | RX clock to outputs |
| `BHV_VERBOSE` | 0 | debug prints |

**Random RX word phase.** With `ALIGN_COMMA_WORD` = 1X the comma lands in byte lane 0 or 4, a coin toss at each link-up (DS1001 Figure 2.41). The BFM does the same, from the simulator's seed. So a lane-0 assumption fails in simulation, before it fails on the board. `BHV_RX_WORD_PHASE_RANDOM=0` turns it off.

## What is modelled

It takes all 115 vendor parameters and acts on 34: resets, comma alignment and slide, RX buffer and clock correction, datapath widths, loopback, PLL rates and lock, the TX buffer. 9 more only set a register value to read back (`PLL_CFG0`). The other 72 tune what a digital model doesn't have ([below](#what-is-not-modelled)).

- **Register file and config file:** the address map (`0x00` to `0x42` RX/TX, `0x50` to `0x5B` PLL, `0x5C` SerDes enable), masked writes, the `regfile_rdy_o` handshake, readback. `PLL_CFG5` bit 0 reads the PLL lock. Status registers of blocks not modelled read back "done", so code that polls them goes on.
- **PLL:** line rate = f_ref · N1·N2·N3·2 / M3 (`PLL_MAIN_DIVSEL`, `PLL_OUT_DIVSEL`). The core clock `clk_core_pll_o` (`PLL_CLK_O`) = line rate / (2 · M1 · M4): M1 from the 64-entry `PLL_FCNTRL` table, M4 = 2 for the 64-bit datapath (DS1001 Eq. 2.2, 2.3, Tables 2.16, 2.17). A `PLL_CFG1` write at run time changes the rate.
- **Datapath:** 16, 32 or 64 bits (`TX/RX_DATAPATH_SEL`), with the lanes each width uses.
- **TX:** 8b/10b with running disparity, or bypassed per byte: bit 9 on `tx_char_dispmode_i`, bit 8 on `tx_char_dispval_i` (DS1001 Figure 2.34). TX buffer (32 words), serializer, polarity, electrical idle, PRBS7/15/23/31 with error injection.
- **Line:** in `FAST` and `ACCURATE` a bit-level serial line on `TX_SERIO_P_B`/`N_B`. TX timing runs on an absolute time grid: rates off the 100 fs grid don't drift (tested: 3 Gb/s for 5 ms).
- **RX:** electrical-idle detection, CDR and lock, deserializer, comma detection and alignment (`ALIGN_*COMMA*`, `ALIGN_COMMA_WORD`), bit or byte slide, polarity, 8b/10b decode with `rx_not_in_table_o` and `rx_disp_err_o` per 6b/4b sub-block, or bypassed: bits 8, 9 of each symbol on `rx_char_is_k_o`, `rx_disp_err_o` (DS1001 Figure 2.39). RX elastic buffer with clock correction ([below](#rx-elastic-buffer-and-clock-correction)), PRBS checker.
- **Resets:** TX and RX sequencers with their PMA/PCS/CDR/EQA/BUF reset timers and `RX_RESET_TIMER_PRESC`; `rx_resetdone_o` waits for CDR lock when `RX_WAIT_CDR_LOCK` is set.
- **Receiver detection, PCS and PMA loopback.**

**Behaviour worth knowing.**
- **Electrical idle is time-filtered:** P = N for 20 UI, as the silicon's envelope detector. At every bit edge P and N read equal for a delta cycle; 8b/10b has an edge at least every 5 UI, so traffic never looks idle.
- **Comma alignment realigns while it is on:** a comma off the word boundary moves the framing (DS1001 Table 2.50). A K28.5 bit pattern can also straddle two data symbols, and a line error can make one, so turn alignment off once aligned. Cologne Chip's word-align FSM does: it raises the align enables, and drops them once `rx_byte_is_aligned_o` is set.
- **RX outputs have a clock-to-q:** data, K, comma and error outputs change `BHV_RX_TCO_NS` after the `clk_core_rx_i` edge, like a flop. Logic on a clock derived from the same edge, such as a 64-bit PIPE PCLK divided from `clk_core_pll_o`, samples them cleanly.
- In `NONE` one TX serves any number of receivers. `NONE` BFMs learn who talks to whom in the first 10 ns.
- Each rising edge of `tx_prbs_force_err_i` makes one bit wrong, which the checker counts as 3. PRBS23 and PRBS31 (`PRBS_SEL` 011, 100) are in the vendor model too; DS1001 lists them as reserved.

## RX elastic buffer and clock correction

DS1001 (Tables 2.56, 2.57) gives the rule: below `RX_CLKCOR_MIN_LAT` the buffer repeats incoming clock-correction sequences, above `RX_CLKCOR_MAX_LAT` it removes them. The BFM fills in what the datasheet leaves out, as the vendor model behaves:

| | BFM behaviour |
|---|---|
| Unit | whole datapath words (16, 32 or 64 bits), 64 of them; `MIN_LAT`/`MAX_LAT` count words |
| Sequence | 4 symbols, `RX_CLKCOR_SEQ_1_0..3`, each 10 bits: {comma flag, K flag, byte}. No comma needed: the default 0x1F7 is K23.7 |
| Match | symbol *i* of the word against sequence symbol *i* mod 4: a 64-bit word holds the sequence twice. Lanes outside the datapath always match; disparity and table errors take no part |
| Remove | occupancy above `MAX_LAT`: of two matching words in a row, the second is not written |
| Insert | occupancy below `MIN_LAT` − 1: the read stalls on a matching word, and the output repeats the word before it |
| Off (`RX_CLKCOR_USE` = 0) | phase only, limits fixed at 4 and 60 |
| Error | `rx_buf_err_o` for occupancy below 3 or above 60, until `rx_buf_reset_i` |

So the sequence must sit aligned in the word, come in bursts (an insertion repeats the word before), and two in a row for a removal. PCIe SKP ordered sets meet none of this: [what it means for PCIe](../README.md#cc_serdes-clock-correction-what-it-can-and-cannot-do).

## Parameter checks

A value the datasheet doesn't allow (UG1001 Tables 7.12 to 7.14, DS1001 Tables 2.15 to 2.17), or the BFM doesn't model, stops the simulation: `$error`, then `$fatal`. Example: `PLL_OUT_DIVSEL` = 2, n.a. in DS1001 Table 2.15. `TX_BUFFER_ADDR_WIDTH` must stay 5. `PLL_CFG1` and `RX_BUF_CFG` are checked the same way when they take effect. `ALIGN_COMMA_WORD` is `CC_SERDES`'s `RX_ALIGN_COMMA_WORD`.

## What is not modelled

- **Analog front end:** TX driver, emphasis and slew, termination and its calibration, AFE gain and peaking, DFE and equaliser adaptation, the electrical-idle detector's bias and bandwidth.
- **Loops:** the CDR and ADPLL internals (DCO, BISC, SAR calibration). The PLL locks after `BHV_PLL_LOCK_TIME_NS`, the CDR after `BHV_CDR_LOCK_EDGES` line edges.
- **Monitors and debug:** eye monitor, scan chain, debug capture.
- **Bitstream-only settings:** register `0x5C` beyond the SerDes enable (auto init, testmode).

Their 72 parameters are taken, range-checked and ignored; their status registers read "done" or "locked". Signal integrity, jitter tolerance and equalisation belong to board measurement.

## Not yet as the vendor model

Found by a cross-check of the vendor model against DS1001 (2026-10-25), to fix:

- comma alignment: the vendor model locks after 16 aligned commas and then ignores a comma in another lane; `rx_byte_realign_o` is a pulse;
- 16 and 32-bit TX: the vendor model rotates the lanes;
- running disparity starts at RD+, not RD-;
- `tx_buf_err_o` is sticky; `tx_prbs_force_err_i` acts on its level; the PRBS error counter counts words;
- the RX reset prescaler is linear (2·N+1) and RX only; a sub-reset reruns only its stage and the later ones;
- `loopback_i` decoding; `PLL_CONFIG_SEL`, `PLL_REF_BYPASS`; M1 for `PLL_FCNTRL` 10, 53, 54, 55.

## Verification

From the repo root:

```sh
make -C 7.SerDes/0.gm_serdes_bfm sim_modes    # 38 runs, Verilator, about 1 min
make -C 7.SerDes/0.gm_serdes_bfm sim_icarus   # 15 runs, Icarus
make -C 7.SerDes/0.gm_serdes_bfm formal       # the 8b/10b proofs
```

- **`sim_modes`:** the three modes against each other at 2.5 Gb/s, 9 cases: 16-bit (comma in byte lane 0, 1), 32-bit (0, 1, 3), 64-bit (0, 3, 5, 7); data bit-exact; latency within 4 UI of `ACCURATE` (`FAST` knows a bit only at the next line edge). Then, in each mode, PRBS7 and PRBS31 with forced errors; 5 ms at 3 Gb/s in `NONE` and `FAST`; the random word phase with `ALIGN_COMMA_WORD` = 11. Every run also checks the decode table against `dec8b10b()` (all 1024 symbols), the comma defaults, register readback and buffer errors. `tb_modes` takes `+cfg1=HEX`, `+run_us=N`, `+prbs=SEL`.
- **`sim_icarus`:** `tb_modes` in Icarus, each mode, 15 runs, so the BFM stays Icarus-clean. Icarus catches a name used before its declaration; Verilator `-Wall` doesn't.
- **Formal:** the 8b/10b encoder and decoder are proved, 6 properties ([formal_8b10b](formal_8b10b/README.md)).
- **Against the vendor model** (NDA, not runnable from this repo). Logic equivalence checking doesn't fit: the vendor model is not synthesizable (real-valued delays, jitter, `specify`), the BFM is a smaller machine on purpose, and the pipelines differ. So both models run side by side with the same configuration and symbol stream, and their received words are compared as streams: equivalence modulo latency. Self-loopback, and cross-linked (each TX into the other's RX), so each decodes the other's serial format. The harness is openCologne-PCIE's `tb_phy` (`run-phy.sh equiv --ref [--cross]`); it reads the vendor model from `$CCFPGA_SERDES_SRC` and works on a copy outside the repo. 2026-10-24, 2.5 Gb/s, 400 words: 0 divergences in every `CDR_MODEL`, latency 736.0 ns on both. `NONE` sends no bits on the pins, so the cross-linked check needs `FAST` or `ACCURATE`.

Speed, 2.5 Gb/s, wall clock with compilation:

| Model | Icarus, PIPE test, 64-bit | Icarus, `tb_modes` | Verilator, `tb_modes` |
|---|---|---|---|
| BFM, `NONE` | 4.5 s | 0.71 s | 0.016 s |
| BFM, `FAST` | 8.9 s | 1.22 s | 0.058 s |
| BFM, `ACCURATE` | 8.5 s | 1.19 s | 0.098 s |
| Vendor model (NDA) | 86 s | - | - |

The PIPE test is openCologne-PCIE's `tb_phy` (`run-phy.sh pipe64`). Verilator can't build the vendor model.

## Where it is used

| Project | Flow |
|---|---|
| openCologne [7.SerDes](../README.md#simulation) | the IC Link PHY, top and SerWB tests, `3.iclink-sv/2.sim` |
| [openCologne-PCIE](https://github.com/chili-chips-ba/openCologne-PCIE) | `2.rtl/1.phy/3.sim` `run-phy.sh pipe64` (gatemate-pipe's PIPE test) and `equiv`; `2.rtl/4.dll/sim` `run-dll-phy.sh` (DLL, MAC/LTSSM, PIPE and SerDes, two link partners) |
