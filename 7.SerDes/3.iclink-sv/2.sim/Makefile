# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Unit tests of the IC Link RTL, Verilator.
#   make            all unit tests
#   make sim_8b10b  8b/10b against LiteX's vectors (vectors/*.hex, committed)
#   make sim_prbs   PRBS7/15/31 against LiteX's vectors, and pause
#   make sim_top    the board top: its 8b/10b self-test, clean and with an error
#   make vectors    regenerate vectors/*.hex from LiteX (needs LiteX in python3)
#   make clean

HW  := ../1.hw
OUT := obj_8b10b

.PHONY: all sim_8b10b sim_prbs sim_top vectors clean

all: sim_8b10b sim_prbs sim_top

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

sim_top:
	verilator --binary --timing --timescale 1ns/1ps -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL 	  --top-module tb_top -Mdir obj_top 	  $$(sed -e "s|\$${HW_SRC}|$(HW)|" -e "/^#/d" -e "/^$$/d" $(HW)/top.filelist) tb_top.sv
	./obj_top/Vtb_top | tee sim_top.log
	@grep -q "TB_TOP: PASS" sim_top.log

vectors:
	mkdir -p vectors && python3 gen_8b10b_vectors.py vectors && python3 gen_prbs_vectors.py vectors

clean:
	rm -rf $(OUT) obj_prbs obj_top sim_8b10b.log sim_prbs.log sim_top.log
