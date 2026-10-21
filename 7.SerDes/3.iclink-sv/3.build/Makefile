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
#
# Sources: ../1.hw/top.filelist (sources.sh). Pins: GateMateA1-EVB.ccf.
#==========================================================================

DEVICE   ?= CCGM1A1
FREQ     ?= 32                   # MHz, one constraint for every clock: the SerDes core
                                 # clocks run at 31.25 MHz, the EVB clock (CLK0) at 10
SEED     ?= 1
CCF      ?= GateMateA1-EVB.ccf
BOARD    ?= gatemate_evb_jtag

YOSYS    ?= yosys
NEXTPNR  ?= nextpnr-himbaechel-gatemate
GMPACK   ?= gmpack
OFL      ?= openFPGALoader

BLD      := build
HW       := $(abspath ../1.hw)
SV       := $(shell bash -c '. ./sources.sh && design_rtl $(HW)')
# the GateMate primitives (CC_SERDES, ...) as blackboxes for read_slang
CELLS    := $(shell $(YOSYS)-config --datdir)/gatemate/cells_bb.v

.PHONY: all load clean

all: $(BLD)/top.bit

$(BLD)/top.json: $(SV) | $(BLD)
	$(YOSYS) -l $(BLD)/yosys.log -p "read_slang -D SYNTHESIS --top top $(CELLS) $(SV); \
	  synth_gatemate -top top -luttree -nomx8 -json $@" > /dev/null

$(BLD)/top.txt: $(BLD)/top.json $(CCF)
	$(NEXTPNR) --device $(DEVICE) --json $< --vopt ccf=$(CCF) --vopt out=$@ \
	  --router router2 --freq $(FREQ) --seed $(SEED) -l $(BLD)/nextpnr.log

$(BLD)/top.bit: $(BLD)/top.txt
	$(GMPACK) $< $@

$(BLD):
	mkdir -p $@

load: $(BLD)/top.bit
	$(OFL) -b $(BOARD) $<

clean:
	rm -rf $(BLD)

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
