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
#   LINE_RATE=1250|2500|5000  Mb/s (default 2500); the SerDes core clock
#                   clk_core is constrained at LINE_RATE / 80
#                   (31.25 MHz at 2500), the EVB clock (CLK0) at FREQ.
#                   At 5000 the pump's half_clk_strobe logic gets a 2-clock
#                   setup budget: mcp_cells.py proves on the netlist which
#                   flops move only with the strobe and writes build/mcp.sdc
#                   (set_multicycle_path), which needs NEXTPNR_MCP, a nextpnr
#                   with it (chili-chips-ba/nextpnr, branch multicycle-sdc)
#
# Sources: ../1.hw/top.filelist (sources.sh). Pins: GateMateA1-EVB.ccf.
#==========================================================================

DEVICE   ?= CCGM1A1
LINE_RATE ?= 2500
CORE_MHZ := $(shell awk 'BEGIN { print $(LINE_RATE) / 80 }')
# MHz, every clock not named below: the EVB clock (CLK0)
FREQ     ?= 10
SEED     ?= 1
CCF      ?= GateMateA1-EVB.ccf
BOARD    ?= gatemate_evb_jtag

YOSYS    ?= yosys
NEXTPNR  ?= nextpnr-himbaechel-gatemate
NEXTPNR_MCP ?= nextpnr-himbaechel-gatemate-mcp
PYTHON   ?= python3
GMPACK   ?= gmpack
OFL      ?= openFPGALoader

BLD      := build
HW       := $(abspath ../1.hw)
SV       := $(shell bash -c '. ./sources.sh && design_rtl $(HW)')
# the GateMate primitives (CC_SERDES, ...) as blackboxes for read_slang
CELLS    := $(shell $(YOSYS)-config --datdir)/gatemate/cells_bb.v

.PHONY: all load clean FORCE

all: $(BLD)/top.bit

# the options of each step, rewritten only when they change, so that a new
# LINE_RATE synthesizes again and a new SEED or FREQ places and routes again
SYNTH_OPTS := LINE_RATE=$(LINE_RATE)
PNR_OPTS   := $(SYNTH_OPTS) SEED=$(SEED) FREQ=$(FREQ) DEVICE=$(DEVICE)

$(BLD)/synth.opts: FORCE | $(BLD)
	@echo '$(SYNTH_OPTS)' | cmp -s - $@ || echo '$(SYNTH_OPTS)' > $@

$(BLD)/pnr.opts: FORCE | $(BLD)
	@echo '$(PNR_OPTS)' | cmp -s - $@ || echo '$(PNR_OPTS)' > $@

$(BLD)/top.json: $(SV) $(BLD)/synth.opts | $(BLD)
	$(YOSYS) -l $(BLD)/yosys.log -p "read_slang -D SYNTHESIS -G LINE_RATE=$(LINE_RATE) --top top $(CELLS) $(SV); \
	  synth_gatemate -top top -luttree -nomx8 -json $@" > /dev/null

# the SerDes core clocks, by net name
$(BLD)/clocks.py: Makefile $(BLD)/synth.opts | $(BLD)
	printf 'ctx.addClock("clk_core", %s)\n' $(CORE_MHZ) > $@

# 5 Gb/s: the 2-clock group of the half_clk_strobe logic, proven on the netlist
ifeq ($(LINE_RATE),5000)
  PNR     = $(NEXTPNR_MCP)
  MCP_SDC = $(BLD)/mcp.sdc
else
  PNR     = $(NEXTPNR)
  MCP_SDC =
endif

$(BLD)/mcp.sdc: $(BLD)/top.json mcp_cells.py
	$(PYTHON) mcp_cells.py $< half_clk_strobe clk_core $@

$(BLD)/top.txt: $(BLD)/top.json $(BLD)/clocks.py $(MCP_SDC) $(CCF) $(BLD)/pnr.opts
	$(PNR) --device $(DEVICE) --json $< --vopt ccf=$(CCF) --vopt out=$@ \
	  --pre-pack $(BLD)/clocks.py $(if $(MCP_SDC),--sdc $(MCP_SDC)) \
	  --router router2 --freq $(FREQ) --seed $(SEED) -l $(BLD)/nextpnr.log

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
