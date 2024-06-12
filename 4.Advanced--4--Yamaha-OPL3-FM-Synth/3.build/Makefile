#=============================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================


#=============================================================
# Toolchain download and setup instructions
#=============================================================
# Download toolchain from: 
# https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
# There are two options: toolchain for linux and toolchain for windows
# Extract archive and set CC_TOOL environment variable:
# 1.
# Easiest way to do it is by running the following command: 
#     $ echo 'export CC_TOOL="/path/to/cc-toolchain-linux"' >> ~/.bashrc
# After that you either need to restart your terminal or source it with:
#     $ source ~/.bashrc
# (NOTE: By doing it this way you don't need to export the path everytime you open a new terminal)
#
# 2.
# Running the following command in terminal:
#     $ export CC_TOOL="/path/to/cc-toolchain-linux"
# NOTE: Everytime you open a new terminal you need to export the command if you do it this way
#
#=============================================================

# Set EXE for platform-specific executable extensions, if necessary
EXE =

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
TOOL_ROOT = /home/user/FPGA/tools
BLD_DIR = $(CURDIR)
HW_SRC  := $(BLD_DIR)/../1.hw
SW_SRC  := $(BLD_DIR)/../2.sw

SYNLIG = $(TOOL_ROOT)/synlig
PLUGIN_PATH := $(SYNLIG)/build/release/systemverilog-plugin/systemverilog.so

#YOSYS = $(SYNLIG)/out/current/bin/yosys$(EXE)
#YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
YOSYS = $(TOOL_ROOT)/yosys/yosys
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)
OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE)

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Source Directory
V_SRC = $(shell cat $(HW_SRC)/rtl.filelist)

SIM = \
	$(HW_SRC)/modules/top_level/sim/opl3_tb.sv \
	$(HW_SRC)/modules/operator/sim/save_dac_input.sv

V_PKG = $(HW_SRC)/modules/top_level/pkg/opl3_pkg.v
SV_PKG = $(HW_SRC)/modules/top_level/pkg/opl3_pkg.sv

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
# Define TOP MODULE here
TOP = opl3
# Define Constraint file here
CONSTR = $(HW_SRC)/constraints/blink.ccf
PRFLAGS += -ccf $blink.ccf -cCP

# Synthesize Sources
VLOG_SRC = $(shell cat $(HW_SRC)/rtl.filelist)
#VHDL_SRC = $(shell find $(SRC) -type f \( -iname \*.vhd -o -iname \*.vhdl \))

## misc tools
RM = rm -rf

## toolchain targets
synth: synth_vlog

synth_svlog: $(VLOG_SRC) $(SV_PKG)
	@test -d log || mkdir -p log
	@test -d net || mkdir -p net
	$(YOSYS) -ql log/synth.log -p 'plugin -i $(PLUGIN_PATH); read_systemverilog $(SV_PKG) $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vlog: $(VLOG_SRC) $(V_PKG)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $(V_PKG) $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vhdl: $(VHDL_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -vhdl $(PKG); read -vhdl $(VHDL_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(CONSTR) -cCP > log/$@.log || { tail -n 50 log/$@.log; exit 1; }

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
	find $(HW_SRC) -maxdepth 1 -type f -name "*.v" ! -name "afifo.v" -exec $(RM) {} +
	test ! -d log || rmdir log
	test ! -d net || rmdir net

# New target for generating rtl.filelist and converting files
rtl_gen:
	@echo "Generating rtl.filelist with -sv parameter..."
	./create_rtl_filelist.sh -sv
	@echo "Converting RTL files to Verilog..."
	SRC=$(shell cat $(HW_SRC)/rtl.filelist)
	sv2v --write=adjacent $${SRC}
	@echo "Conversion completed. Converted files are located adjacent to their respective source files."
	./create_rtl_filelist.sh -v

# Synthesize with sv2v
synth_sv2v: rtl_gen synth_vlog

# Synthesize with normal SystemVerilog
synth_sv: 
	@echo "Generating rtl.filelist with -sv parameter..."
	./create_rtl_filelist.sh -sv
	$(MAKE) synth_vlog

# Default synthesis target
synth: synth_sv

#=============================================================
# End-of-File
#=============================================================

