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
#   make sim_serwb_tx  SerWB packetizer against LiteICLink's Packetizer (vectors/serwb_*)
#   make sim_serwb_rx  SerWB depacketizer against LiteICLink's CRCDepacketizer (vectors/serwb_rx_*)
#   make sim_top    the board top: self-tests and the SerDes link, clean and with errors
#   make vectors    regenerate vectors/*.hex from LiteX (needs LiteX in python3)
#   make clean

HW  := ../1.hw
BFM := serdes-model/ccfpga_serdes_pkg.sv serdes-model/ccfpga_serdes.sv
OUT := obj_8b10b

WAVES ?= 0
TRACE := $(if $(filter 1,$(WAVES)),--trace-fst --trace-structs,)
PLUS  := $(if $(filter 1,$(WAVES)),+waves,)

.PHONY: all sim_8b10b sim_prbs sim_phy_oneway sim_phy_twoway sim_serwb_tx sim_serwb_rx sim_top vectors clean

all: sim_8b10b sim_prbs sim_phy_oneway sim_phy_twoway sim_serwb_tx sim_serwb_rx sim_top

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

sim_phy_oneway:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_phy_oneway -Mdir obj_phy $(TRACE) serdes-model.vlt \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_phy_pkg.sv $(HW)/iclink_8b10b_enc.sv \
	  $(HW)/iclink_prbs_gen.sv $(HW)/iclink_prbs_chk.sv $(HW)/iclink_prbs_tx.sv $(HW)/iclink_prbs_rx.sv \
	  $(HW)/iclink_serdes_gm.sv $(BFM) \
	  tb_phy_oneway.sv
	./obj_phy/Vtb_phy_oneway $(PLUS) | tee sim_phy_oneway.log
	@grep -q "TB_PHY_ONEWAY: PASS" sim_phy_oneway.log

sim_phy_twoway:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_phy_twoway -Mdir obj_phy2 $(TRACE) serdes-model.vlt \
	  $(HW)/iclink_pkg.sv $(HW)/iclink_phy_pkg.sv $(HW)/iclink_8b10b_enc.sv \
	  $(HW)/iclink_prbs_gen.sv $(HW)/iclink_prbs_chk.sv $(HW)/iclink_prbs_tx.sv $(HW)/iclink_prbs_rx.sv \
	  $(HW)/iclink_serdes_gm.sv $(BFM) \
	  tb_phy_twoway.sv
	./obj_phy2/Vtb_phy_twoway $(PLUS) | tee sim_phy_twoway.log
	@grep -q "TB_PHY_TWOWAY: PASS" sim_phy_twoway.log

sim_serwb_tx:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_serwb_tx -Mdir obj_serwb_tx \
	  $(HW)/iclink_serwb_pkg.sv $(HW)/iclink_serwb_tx.sv tb_serwb_tx.sv
	./obj_serwb_tx/Vtb_serwb_tx | tee sim_serwb_tx.log
	@grep -q "TB_SERWB_TX: PASS" sim_serwb_tx.log

sim_serwb_rx:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_serwb_rx -Mdir obj_serwb_rx \
	  $(HW)/iclink_serwb_pkg.sv $(HW)/iclink_serwb_rx.sv tb_serwb_rx.sv
	./obj_serwb_rx/Vtb_serwb_rx | tee sim_serwb_rx.log
	@grep -q "TB_SERWB_RX: PASS" sim_serwb_rx.log

sim_top:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
	  --top-module tb_top -Mdir obj_top serdes-model.vlt \
	  $$(sed -e "s|\$${HW_SRC}|$(HW)|" -e "/^#/d" -e "/^$$/d" $(HW)/top.filelist) \
	  $(BFM) tb_top.sv
	./obj_top/Vtb_top | tee sim_top.log
	@grep -q "TB_TOP: PASS" sim_top.log

vectors:
	mkdir -p vectors && python3 gen_8b10b_vectors.py vectors && python3 gen_prbs_vectors.py vectors && python3 gen_serwb_vectors.py vectors && python3 gen_serwb_rx_vectors.py vectors

clean:
	rm -rf $(OUT) obj_prbs obj_phy obj_phy2 obj_serwb_tx obj_serwb_rx obj_top sim_8b10b.log sim_prbs.log sim_phy_oneway.log sim_phy_twoway.log sim_serwb_tx.log sim_serwb_rx.log sim_top.log phy_oneway.fst phy_twoway.fst
