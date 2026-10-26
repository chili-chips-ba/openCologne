# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
#==========================================================================
# Open-source GateMate build of 7.SerDes/3.iclink-sv: Yosys (synth_gatemate)
# -> nextpnr-himbaechel (gatemate uarch) -> gmpack (Project Peppercorn).
# The same flow LiteX's toolchain="peppercorn" runs, but a timing failure
# stops the build (no --timing-allow-fail).
#
#   make            bitstream: build/top.bit
#   make load       program the EVB over JTAG (openFPGALoader)
#   make clean
#   LINE_RATE=1250|2500|5000  Mb/s (default 2500); the one core clock,
#                   clk_core (CC_SERDES PLL_CLK_O), is constrained at
#                   LINE_RATE / 80 (31.25 MHz at 2500), the EVB clock (CLK0)
#                   at FREQ
#   BLD=dir         the build directory (default build)
#
# Sources: ../1.hw/top.filelist (sources.sh). Pins: GateMateA1-EVB.ccf.
#==========================================================================

DEVICE   ?= CCGM1A1
LINE_RATE ?= 2500
CORE_MHZ := $(shell awk 'BEGIN { print $(LINE_RATE) / 80 }')
FREQ     ?= 10                   # MHz, every clock not named below: the EVB clock (CLK0)
SEED     ?= 1
CCF      ?= GateMateA1-EVB.ccf
BOARD    ?= gatemate_evb_jtag

YOSYS    ?= yosys
NEXTPNR  ?= nextpnr-himbaechel-gatemate
GMPACK   ?= gmpack
OFL      ?= openFPGALoader

BLD      ?= build
HW       := $(abspath ../1.hw)
SV       := $(shell bash -c '. ./sources.sh && design_rtl $(HW)')
# the GateMate primitives (CC_SERDES, ...) as blackboxes for read_slang
CELLS    := $(shell $(YOSYS)-config --datdir)/gatemate/cells_bb.v

.PHONY: all load clean

all: $(BLD)/top.bit

$(BLD)/top.json: $(SV) | $(BLD)
	$(YOSYS) -l $(BLD)/yosys.log -p "read_slang -D SYNTHESIS -G LINE_RATE=$(LINE_RATE) --top top $(CELLS) $(SV); \
	  synth_gatemate -top top -luttree -nomx8 -json $@" > /dev/null

# the core clock, by net name
$(BLD)/clocks.py: Makefile | $(BLD)
	printf 'ctx.addClock("clk_core", %s)\n' $(CORE_MHZ) > $@

$(BLD)/top.txt: $(BLD)/top.json $(BLD)/clocks.py $(CCF)
	$(NEXTPNR) --device $(DEVICE) --json $< --vopt ccf=$(CCF) --vopt out=$@ \
	  --pre-pack $(BLD)/clocks.py --router router2 --freq $(FREQ) --seed $(SEED) \
	  -l $(BLD)/nextpnr.log

$(BLD)/top.bit: $(BLD)/top.txt
	$(GMPACK) $< $@

$(BLD):
	mkdir -p $@

load: $(BLD)/top.bit
	$(OFL) -b $(BOARD) $<

clean:
	find $(BLD) -delete 2>/dev/null || true

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
