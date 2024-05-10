#=============================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

# Toolchain download and setup instructions:
# Download toolchain from: https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
# Extract archive and set CC_TOOL environment variable:
# export CC_TOOL=/path/to/cc-toolchain-linux

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
YOSYS = $(CC_TOOL)/bin/yosys/yosys
PR = $(CC_TOOL)/bin/p_r/p_r
OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Source Directory
SRC = 1.hw

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = top # Define TOP MODULE here
CONSTR = GateMateA1-EVB.ccf

# Synthesize Sources
VLOG_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.v -o -iname \*.sv \))
VHDL_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.vhd -o -iname \*.vhdl \))

# Misc tools
RM = rm -rf

# Synthesis Targets
synth: synth_vlog synth_vhdl

synth_vlog: $(VLOG_SRC)
	$(YOSYS) -qql log/synth.log -p 'read -sv $^; synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vhdl: $(VHDL_SRC)
	$(YOSYS) -ql log/synth.log -p 'ghdl --warn-no-binding -C --ieee=synopsys $^ -e $(TOP); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

# Implementation
impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(CONSTR) -cCP > log/impl.log

# Programming Targets
jtag:
	$(OFL) -b gatemate_evb_jtag $(TOP)_00.cfg

jtag-flash:
	$(OFL) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg

spi:
	$(OFL) -b gatemate_evb_spi $(TOP)_00.cfg

spi-flash:
	$(OFL) -b gatemate_evb_spi -f --verify $(TOP)_00.cfg

# Simulation Targets
%sim: %sim.vvp
	$(VVP) -N sim/$< -fst
	@$(RM) sim/$<

wave:
	$(GTKW) sim/$(TOP)_tb.vcd sim/config.gtkw

# Cleanup
clean:
	$(RM) log/*.log net/* sim/* *.history *.txt *.ref* *.id *.prn *.pos *.pathes *.net *.cfg* *.cdf

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

.PHONY: all synth synth_vlog synth_vhdl impl jtag jtag-flash spi spi-flash clean help %sim %sim.vvp wave

#=============================================================
# End-of-File
#=============================================================

