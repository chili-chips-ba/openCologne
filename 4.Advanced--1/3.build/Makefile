#=============================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

# Toolchain download and setup instructions:
# Download toolchain from: https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
# Extract archive and set CC_TOOL environment variable:
# export CC_TOOL=/path/to/cc-toolchain-linux

# Set EXE for platform-specific executable extensions, if necessary
EXE =

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)
OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE)

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Source Directory
SRC = ../1.hw
SIM = ../2.sim

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = top_checkered# Define TOP MODULE here
CONSTR = $(TOP).ccf
PRFLAGS += -ccf $(TOP).ccf -cCP

# Synthesize Sources
VLOG_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.v -o -iname \*.sv \))
VHDL_SRC = $(shell find ./$(SRC)/ -type f \( -iname \*.vhd -o -iname \*.vhdl \))

## misc tools
RM = rm -rf

## toolchain targets
synth: synth_vlog

synth_vlog: $(VLOG_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $^; synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vhdl: $(VHDL_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'ghdl --warn-no-binding -C --ieee=synopsys $^ -e $(TOP); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(TOP).ccf -cCP > log/$@.log

jtag:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag $(TOP)_00.cfg

jtag-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg

spi:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -m $(TOP)_00.cfg

spi-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -f --verify $(TOP)_00.cfg

all: synth impl jtag

## verilog simulation targets
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

clean:
	$(RM) log/*.log
	$(RM) net/*_synth.v
	$(RM) *.history
	$(RM) *.txt
	$(RM) *.refwire
	$(RM) *.refparam
	$(RM) *.refcomp
	$(RM) *.pos
	$(RM) *.pathes
	$(RM) *.path_struc
	$(RM) *.net
	$(RM) *.id
	$(RM) *.prn
	$(RM) *_00.v
	$(RM) *.used
	$(RM) *.sdf
	$(RM) *.place
	$(RM) *.pin
	$(RM) *.cfg*
	$(RM) *.cdf
	$(RM) $(SIM)/*.vcd
	$(RM) $(SIM)/*.vvp
	$(RM) $(SIM)/*.gtkw
	test ! -d log || rmdir log
	test ! -d net || rmdir net
#=============================================================
# End-of-File
#=============================================================

