# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Unit tests of the IC Link RTL, Verilator.
#   make            all unit tests
#   make sim_8b10b  8b/10b against LiteX's vectors (vectors/*.hex, committed)
#   make sim_prbs   PRBS7/15/31 against LiteX's vectors, and pause
#   make sim_phy_oneway  the SerDes PHY on the SerDes BFM, TX looped to RX
#                        (WAVES=1: also writes phy_oneway.fst, for WaveCrux)
#   make sim_phy_twoway  two PHYs on two SerDes BFMs, serial lines crossed
#                        (WAVES=1: also writes phy_twoway.fst)
#   make sim_phy_rates   both PHY tests at 1250, 2500 and 5000 Mb/s, and 2500
#                        with the hard TX 8b/10b
#   make sim_phy_ppm     sim_phy_twoway with the two reference clocks +-300 ppm and
#                        +-20 ppm apart, each CDR_MODEL: PRBS error-free, the RX
#                        elastic buffers insert and remove correction words
#   make sim_serwb_tx  SerWB packetizer against LiteICLink's Packetizer (vectors/serwb_*)
#   make sim_serwb_rx  SerWB depacketizer against LiteICLink's CRCDepacketizer (vectors/serwb_rx_*)
#   make sim_serwb_pump  FIFO pump, two sides on the digital bus (SerDes out of the loop), flow control;
#                        then again with the line dropping / repeating clock-correction words
#   make sim_serwb_w4  the three SerWB tests with W = 4 words a pump clock (5 Gb/s): every other
#                      PHY clock, through gearboxes
#                      (SERWB_W=4 does the same for any one of them)
#   make sim_top    the board top: self-tests and the SerDes link, clean and with errors
#   make sim_modes, sim_icarus  the SerDes BFM's own tests, in its home ../../0.gm_serdes_bfm
#   make vectors    regenerate vectors/*.hex from LiteX (needs LiteX in python3)
#   make clean
# Settings (make ... NAME=VALUE):
#   CDR_MODEL=NONE|FAST|ACCURATE  the SerDes BFM mode, PHY and top tests (default NONE)
#   SEED=N        the simulator seed, PHY and top tests: it sets the BFM's random RX word
#                 phase. None: Verilator's fixed default seed; 0: a new seed every run
#   RANDOM_PHASE=0  the RX word phase fixed at 0, PHY and top tests (default: random)
#   LINE_RATE=1250|2500|5000  Mb/s, PHY tests (default 2500)
#   PPM_A=N PPM_B=N  sim_phy_twoway: each side's reference clock N ppm off 100 MHz
#                 (default 0, one clock)
#   HARD=1|0      the TX 8b/10b in CC_SERDES or the fabric, PHY tests (default: CC_SERDES
#                 at 5000 only)
#   WAVES=1       also write an FST waveform, PHY tests
#   SERWB_W=2|4   SerWB words a clock, SerWB tests (default 2)

# a simulator that fails in a pipe (| tee) fails the target
SHELL       := /bin/bash
.SHELLFLAGS := -o pipefail -ec

HW  := ../1.hw
BFM_DIR := ../../0.gm_serdes_bfm
BFM     := $(BFM_DIR)/ccfpga_serdes_pkg.sv $(BFM_DIR)/ccfpga_serdes.sv
CDR_MODEL    ?=
RANDOM_PHASE ?=
BFM_DEF := $(if $(CDR_MODEL),+define+CDR_MODEL=$(CDR_MODEL)) \
           $(if $(RANDOM_PHASE),+define+BHV_RX_WORD_PHASE_RANDOM=$(RANDOM_PHASE))
OUT := obj_8b10b

WAVES ?= 0
SERWB_W ?= 2
TRACE := $(if $(filter 1,$(WAVES)),--trace-fst --trace-structs,)
SEED  ?=
PLUS  := $(if $(filter 1,$(WAVES)),+waves,) $(if $(SEED),+verilator+seed+$(SEED))

.PHONY: all sim_8b10b sim_prbs sim_phy_oneway sim_phy_twoway sim_phy_rates sim_phy_ppm sim_serwb_tx sim_serwb_rx sim_serwb_pump sim_serwb_w4 sim_top sim_modes sim_icarus vectors clean

all: sim_icarus sim_8b10b sim_prbs sim_phy_oneway sim_phy_twoway sim_serwb_tx sim_serwb_rx sim_serwb_pump sim_serwb_w4 sim_top sim_modes

sim_8b10b:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_8b10b -Mdir $(OUT) \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_8b10b_enc.sv $(HW)/iclink_8b10b_dec.sv tb_8b10b.sv
	./$(OUT)/Vtb_8b10b | tee sim_8b10b.log
	@grep -q "TB_8B10B: PASS" sim_8b10b.log

sim_prbs:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_prbs -Mdir obj_prbs \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_prbs_gen.sv $(HW)/iclink_prbs_chk.sv $(HW)/iclink_prbs_tx.sv $(HW)/iclink_prbs_rx.sv tb_prbs.sv
	./obj_prbs/Vtb_prbs | tee sim_prbs.log
	@grep -q "TB_PRBS: PASS" sim_prbs.log

# line rate in Mb/s (1250, 2500, 5000); HARD=1/0 forces the TX 8b/10b in
# CC_SERDES on or off (default: on at 5000 only)
LINE_RATE ?= 2500
HARD      ?=
RATE_G    := -GLINE_RATE=$(LINE_RATE) $(if $(HARD),-GTX_HARD_8B10B=$(HARD))
PPM_A     ?=
PPM_B     ?=
PPM_G     := $(if $(PPM_A),-GPPM_A=$(PPM_A)) $(if $(PPM_B),-GPPM_B=$(PPM_B))

# both PHY testbenches at every rate, and 2.5 Gb/s with the hard TX 8b/10b
sim_phy_rates:
	@for r in 1250:: 2500:: 5000:: 2500:1; do \
	  rate=$${r%%:*}; hard=$${r##*:}; \
	  $(MAKE) --no-print-directory sim_phy_oneway LINE_RATE=$$rate HARD=$$hard > /dev/null; \
	  $(MAKE) --no-print-directory sim_phy_twoway LINE_RATE=$$rate HARD=$$hard > /dev/null; \
	  echo "$$rate Mb/s$${hard:+, hard TX 8b/10b}: $$(grep -h PASS sim_phy_oneway.log sim_phy_twoway.log | tr '\n' ' ')"; \
	done | tee sim_phy_rates.log

sim_phy_oneway:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_phy_oneway -Mdir obj_phy $(TRACE) $(RATE_G) $(BFM_DEF) $(BFM_DIR)/ccfpga_serdes.vlt \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_phy_pkg.sv $(HW)/iclink_8b10b_enc.sv \
	  $(HW)/iclink_prbs_gen.sv $(HW)/iclink_prbs_chk.sv $(HW)/iclink_prbs_tx.sv $(HW)/iclink_prbs_rx.sv \
	  $(HW)/iclink_serdes_gm.sv $(BFM) \
	  tb_phy_oneway.sv
	./obj_phy/Vtb_phy_oneway $(PLUS) | tee sim_phy_oneway.log
	@grep -q "TB_PHY_ONEWAY: PASS" sim_phy_oneway.log

sim_phy_twoway:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_phy_twoway -Mdir obj_phy2 $(TRACE) $(RATE_G) $(PPM_G) $(BFM_DEF) $(BFM_DIR)/ccfpga_serdes.vlt \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_phy_pkg.sv $(HW)/iclink_8b10b_enc.sv \
	  $(HW)/iclink_prbs_gen.sv $(HW)/iclink_prbs_chk.sv $(HW)/iclink_prbs_tx.sv $(HW)/iclink_prbs_rx.sv \
	  $(HW)/iclink_serdes_gm.sv $(BFM) \
	  tb_phy_twoway.sv
	./obj_phy2/Vtb_phy_twoway $(PLUS) | tee sim_phy_twoway.log
	@grep -q "TB_PHY_TWOWAY: PASS" sim_phy_twoway.log

# two reference clocks: A +N ppm, B -N ppm, each CDR model
sim_phy_ppm:
	@for m in NONE FAST ACCURATE; do for p in 300 20; do \
	  $(MAKE) --no-print-directory sim_phy_twoway CDR_MODEL=$$m PPM_A=$$p PPM_B=-$$p > /dev/null || true; \
	  echo "$$m +-$$p ppm: $$(grep -h "clock correction\|TB_PHY" sim_phy_twoway.log | tr '\n' ' ')"; \
	done; done | tee sim_phy_ppm.log
	@test $$(grep -c "TB_PHY_TWOWAY: PASS" sim_phy_ppm.log) -eq 6

sim_serwb_tx:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_serwb_tx -GW=$(SERWB_W) -Mdir obj_serwb_tx_w$(SERWB_W) \
	  $(HW)/iclink_serwb_pkg.sv $(HW)/iclink_serwb_tx.sv tb_serwb_tx.sv
	./obj_serwb_tx_w$(SERWB_W)/Vtb_serwb_tx | tee sim_serwb_tx.log
	@grep -q "TB_SERWB_TX: PASS" sim_serwb_tx.log

sim_serwb_rx:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_serwb_rx -GW=$(SERWB_W) -Mdir obj_serwb_rx_w$(SERWB_W) \
	  $(HW)/iclink_serwb_pkg.sv $(HW)/iclink_serwb_rx.sv tb_serwb_rx.sv
	./obj_serwb_rx_w$(SERWB_W)/Vtb_serwb_rx | tee sim_serwb_rx.log
	@grep -q "TB_SERWB_RX: PASS" sim_serwb_rx.log

PUMP_SRC := $(HW)/iclink_pkg.sv $(HW)/iclink_phy_pkg.sv $(HW)/iclink_serwb_pkg.sv \
  $(HW)/iclink_serwb_fifo.sv $(HW)/iclink_serwb_tx.sv $(HW)/iclink_serwb_rx.sv \
  $(HW)/iclink_gearbox.sv $(HW)/iclink_serwb_pump.sv

sim_serwb_pump:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM \
	  --top-module tb_serwb_pump -GW=$(SERWB_W) -Mdir obj_serwb_pump_w$(SERWB_W) $(PUMP_SRC) tb_serwb_pump.sv
	./obj_serwb_pump_w$(SERWB_W)/Vtb_serwb_pump | tee sim_serwb_pump.log
	@grep -q "TB_SERWB_PUMP: PASS" sim_serwb_pump.log
	./obj_serwb_pump_w$(SERWB_W)/Vtb_serwb_pump +elastic | tee sim_serwb_pump_elastic.log
	@grep -q "TB_SERWB_PUMP: PASS" sim_serwb_pump_elastic.log

sim_serwb_w4:
	$(MAKE) SERWB_W=4 sim_serwb_tx sim_serwb_rx sim_serwb_pump

sim_top:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_top -Mdir obj_top $(BFM_DEF) $(BFM_DIR)/ccfpga_serdes.vlt \
	  $$(sed -e "s|\$${HW_SRC}|$(HW)|" -e "/^#/d" -e "/^$$/d" $(HW)/top.filelist) \
	  $(BFM) tb_top.sv
	./obj_top/Vtb_top $(PLUS) | tee sim_top.log
	@grep -q "TB_TOP: PASS" sim_top.log

# The SerDes BFM's own tests run in its home
sim_modes sim_icarus:
	$(MAKE) -C $(BFM_DIR) $@

vectors:
	mkdir -p vectors && python3 gen_8b10b_vectors.py vectors && python3 gen_prbs_vectors.py vectors && python3 gen_serwb_vectors.py vectors && python3 gen_serwb_rx_vectors.py vectors

# build directories (obj_*, recursively) and outputs
# the waves phy_*.fst stay: they are committed, for WaveCrux
clean:
	find . -maxdepth 1 -name 'obj_*' -exec find {} -delete \;
	rm -f sim_*.log pump_levels.csv modes_*.txt
	$(MAKE) -C $(BFM_DIR) clean
