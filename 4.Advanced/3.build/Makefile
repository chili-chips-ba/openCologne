#=============================================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================================

# Instructions:
# - Download the toolchain from: https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
# - Extract the archive and set the CC_TOOL environment variable:
#   export CC_TOOL=/path/to/cc-toolchain-linux

# Configuration for platform-specific executable extensions, if necessary
EXE =

# Toolchain directories and executable commands
CC_TOOL_DIR = $(CC_TOOL)
YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)
OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE)

# Simulation tools and flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Project directories
SRC = ../1.hw
SIM = ../2.sim
BUILD = ../3.build

# Simulation libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project configuration
TOP = blink  # Define TOP MODULE here
CONSTR = GateMateA1-EVB.ccf
PRFLAGS += -ccf $(TOP).ccf -cCP

# Source files discovery
VLOG_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.v -o -iname \*.sv \))
VHDL_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.vhd -o -iname \*.vhdl \))

# Miscellaneous tools
RM = rm -rf

#=============================================================================
# Main Targets
#=============================================================================

# Synthesis targets
synth: synth_vlog synth_vhdl

synth_vlog: $(VLOG_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $^; synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vhdl: $(VHDL_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'ghdl --warn-no-binding -C --ieee=synopsys $^ -e $(TOP); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

# Implementation target
impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) $(PRFLAGS) > log/$@.log

# Programming targets
jtag:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag $(TOP)_00.cfg

jtag-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg

spi:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi $(TOP)_00.cfg

spi-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -f --verify $(TOP)_00.cfg

all: synth impl jtag

#=============================================================================
# Simulation Targets
#=============================================================================

vlog_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(VLOG_SRC) $(SIM)/$(TOP)_tb.v

synth_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ net/$(TOP)_synth.v $(SIM)/$(TOP)_tb.v $(CELLS_SYNTH)

impl_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(TOP)_00.v $(SIM)/$(TOP)_tb.v $(CELLS_IMPL)

.PHONY: %sim %sim.vvp
%sim: %sim.vvp
	$(VVP) -N $(SIM)/$< -fst
	@$(RM) $(SIM)/$^

wave:
	$(GTKW) $(SIM)/$(TOP)_tb.vcd $(SIM)/config.gtkw

# Clean target
clean:
	$(RM) log/*.log net/*_synth.v *.history *.txt *.ref* *.id *.prn *_00.v
	$(RM) *.used *.sdf *.place *.pin *.cfg* *.cdf $(SIM)/*.vcd $(SIM)/*.vvp $(SIM)/*.gtkw
	test ! -d log || rmdir log
	test ! -d net || rmdir net

# Help
help:
	@echo "Makefile for synthesizing and programming GateMate FPGA"
	@echo "  make synth       - Run synthesis"
	@echo "  make impl        - Run implementation"
	@echo "  make jtag        - Program FPGA via JTAG"
	@echo "  make jtag-flash  - Program and verify FPGA via JTAG"
	@echo "  make spi         - Program FPGA via SPI"
	@echo "  make spi-flash   - Program and verify FPGA via SPI"
	@echo "  make clean       - Clean build and log files"
	@echo "  make help        - Display this help message"
#=============================================================================
# End-of-File
#=============================================================================

