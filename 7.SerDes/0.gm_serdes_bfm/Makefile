# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# The GateMate SerDes BFM's own tests (tb_modes.sv: one BFM looped back).
#   make            all of them
#   make sim_modes  the CDR_MODELs against each other, Verilator: 9 datapath width and
#                   comma lane cases, data bit-exact, latencies within MODES_TOL_NS; then
#                   PRBS7/31 with forced errors, 5 ms at 3 Gb/s, the random RX word phase
#   make sim_icarus  the same testbench in Icarus: each CDR_MODEL at 16, 32 and 64 bits,
#                    ALIGN_COMMA_WORD 01 (even lane) and 11 (lane 0 or 4)
#   make formal     the 8b/10b proofs (formal_8b10b/run-formal.sh)
#   make clean
# Settings: MODES_TOL_NS  sim_modes: how far a mode's latency may be from ACCURATE's
#                         (default 1.6)

# a simulator that fails in a pipe (| tee) fails the target
SHELL       := /bin/bash
.SHELLFLAGS := -o pipefail -ec

BFM := ccfpga_serdes_pkg.sv ccfpga_serdes.sv

.PHONY: all sim_modes sim_icarus formal clean

all: sim_icarus sim_modes formal

# The SerDes BFM modes against each other, at each datapath width and comma
# lane: data bit-exact, and the latency of every comma within MODES_TOL_NS
# of ACCURATE's (4 UI at 2.5 Gb/s: FAST knows a bit only at the next edge)
# The RX word phase is fixed here: the comma lane is swept instead. Then,
# 64 bits: PRBS7 and PRBS31 with forced errors, each mode; 5 ms at 3 Gb/s
# (a UI off the 100 fs grid), NONE and FAST; the random RX word phase with
# ALIGN_COMMA_WORD = 11, ACCURATE, seeds 1 to 3.
MODES_TOL_NS ?= 1.6
MODES_RUNS   := 0:0 0:1 1:0 1:1 1:3 3:0 3:3 3:5 3:7
MODES_VLT    := verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
                -Wno-PINCONNECTEMPTY --top-module tb_modes ccfpga_serdes.vlt

sim_modes:
	@for m in NONE FAST ACCURATE; do for dp in 0 1 3; do \
	  $(MODES_VLT) -GDP_SEL=$$dp -Mdir obj_modes_$${m}_$$dp +define+CDR_MODEL=$$m +define+BHV_RX_WORD_PHASE_RANDOM=0 \
	    $(BFM) tb_modes.sv > /dev/null; \
	done; done
	@$(MODES_VLT) -GDP_SEL=3 -GALIGN="2'b11" -Mdir obj_modes_rand +define+CDR_MODEL=ACCURATE $(BFM) tb_modes.sv > /dev/null
	@rm -f sim_modes.log; for r in $(MODES_RUNS); do \
	  dp=$${r%%:*}; c=$${r##*:}; \
	  rm -f modes_NONE.txt modes_FAST.txt modes_ACCURATE.txt; \
	  for m in NONE FAST ACCURATE; do \
	    ./obj_modes_$${m}_$$dp/Vtb_modes +comma=$$c +words=modes_$$m.txt | grep "TB_MODES" | tee -a sim_modes.log; \
	  done; \
	  paste modes_ACCURATE.txt modes_NONE.txt modes_FAST.txt | awk -v tol=$(MODES_TOL_NS) \
	    '{ for (i = 2; i <= 3; i++) { d = $$i - $$1; if (NR == 1 || d < lo[i]) lo[i] = d; if (NR == 1 || d > hi[i]) hi[i] = d; \
	         if (d > tol || -d > tol) bad++ } a = $$1 } \
	     END { printf "MODES: ACCURATE %.1f ns, NONE %+.1f..%+.1f, FAST %+.1f..%+.1f, %d commas: %s\n", \
	           a, lo[2], hi[2], lo[3], hi[3], NR, (bad || NR == 0) ? "FAIL" : "PASS" }' | tee -a sim_modes.log; \
	done
	@for m in NONE FAST ACCURATE; do for p in 1 4; do \
	  ./obj_modes_$${m}_3/Vtb_modes +prbs=$$p | grep "TB_MODES" | tee -a sim_modes.log; \
	done; done
	@for m in NONE FAST; do \
	  ./obj_modes_$${m}_3/Vtb_modes +cfg1=063A +run_us=5000 | grep "TB_MODES" | tee -a sim_modes.log; \
	done
	@for s in 1 2 3; do \
	  ./obj_modes_rand/Vtb_modes +comma=3 +verilator+seed+$$s | grep "TB_MODES" | tee -a sim_modes.log; \
	done
	@test $$(grep -c "^TB_MODES: .*: PASS$$" sim_modes.log) -eq 38
	@test $$(grep -c "^MODES: .*: PASS$$" sim_modes.log) -eq 9

# Verilator resolves names after the whole module is read, so a name used
# before its declaration passes, even with -Wall. Icarus (and the LRM)
# stop on it. Icarus has no `unique case` checks: its "sorry" notes on them
# are filtered out. The decode-table check (+nolut) is left to sim_modes:
# it takes Icarus 12 s. Runs: datapath:comma lane:ALIGN_COMMA_WORD; the RX
# word phase is random (Icarus's fixed seed)
ICARUS_RUNS := 0:1:0 1:3:0 1:1:1 3:0:0 3:3:3

sim_icarus:
	@rm -f sim_icarus.log; for m in NONE FAST ACCURATE; do for r in $(ICARUS_RUNS); do \
	  dp=$${r%%:*}; c=$${r#*:}; c=$${c%%:*}; al=$${r##*:}; v=obj_icarus_$${m}_$${dp}_$$al.vvp; \
	  rm -f $$v; \
	  iverilog -g2012 -DCDR_MODEL=$$m -Ptb_modes.DP_SEL=$$dp -Ptb_modes.ALIGN=$$al -o $$v $(BFM) tb_modes.sv 2>&1 \
	    | { grep -v "sorry: Case unique" || true; }; \
	  test -f $$v; \
	  vvp -N $$v +model=$$m +comma=$$c +nolut | grep "TB_MODES" | tee -a sim_icarus.log; \
	done; done
	@test $$(grep -c "^TB_MODES: .*: PASS$$" sim_icarus.log) -eq 15

formal:
	bash formal_8b10b/run-formal.sh

# build directories (obj_*, recursively) and outputs
clean:
	find . -maxdepth 1 -name 'obj_*' -exec find {} -delete \;
	rm -f sim_*.log modes_*.txt
