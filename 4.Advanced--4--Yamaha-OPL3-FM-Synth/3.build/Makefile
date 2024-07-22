#========================================================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#========================================================================================

#========================================================================================
# Toolchain Download and Setup Instructions
#========================================================================================

# Download the Toolchain
# Download the toolchain from the following link:
# https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
#
# There are two options available:
# - Toolchain for Linux
# - Toolchain for Windows
#
# Extract the Archive
# Extract the downloaded archive to your preferred location.
#
# Set the CC_TOOL Environment Variable
#
# Option 1: Persistent Setup
# The easiest way to set the environment variable is by adding it to your `.bashrc` file. 
# This ensures that the variable is set every time you open a new terminal.
#
# 1. Open your terminal and run the following command (replace `/path/to/cc-toolchain-linux` with the actual path to the extracted toolchain):
#     echo 'export CC_TOOL="/path/to/cc-toolchain-linux"' >> ~/.bashrc
#     echo "CC_TOOL environment variable added to .bashrc"
#
# 2. After running the command, either restart your terminal or source the `.bashrc` file to apply the changes:
#     source ~/.bashrc
#     echo "Sourced .bashrc to apply CC_TOOL environment variable"
#
# Option 2: Temporary Setup
# You can also set the environment variable temporarily for the current terminal session. 
# This method requires you to export the variable each time you open a new terminal.
#
# 1. Open your terminal and run the following command (replace `/path/to/cc-toolchain-linux` with the actual path to the extracted toolchain):
#     export CC_TOOL="/path/to/cc-toolchain-linux"
#     echo "CC_TOOL environment variable set for current session"
#
# Note: Every time you open a new terminal, you will need to export the variable again if you use this method.
#
#
# Set the TOOL_ROOT Environment Variable
# It is also needed to set the TOOL_ROOT environment variable, which is used for your tool path. 
# If you don't place all your tools in one place then the path is needed to change accordingly
# You can also declare the variable here in the Makefile instead of placing it in your PATH
#========================================================================================

# Set EXE for platform-specific executable extensions, if necessary
EXE =

#========================================================================================
# Toolchain Directories and Executable Commands
#========================================================================================

BLD_DIR = $(CURDIR)
HW_SRC  := $(BLD_DIR)/../1.hw
SW_SRC  := $(BLD_DIR)/../2.sw

BLD_PATH = /usr/local/bin

#========================================================================================
# GateMate CologneChip Tools
#========================================================================================

YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)
#OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE) # This doesn't work for me, if not programming update OFL to the newest version

# Uncomment to use newer/other version of tools
# YOSYS = $(TOOL_ROOT)/yosys/yosys
# OFL = $(TOOL_ROOT)/openFPGALoader/build/openFPGALoader$(EXE)

#========================================================================================
# Plugin Paths
#========================================================================================

## NOTE: SYNLIG is outdated and not working with the latest version of yosys so 'synth_svlog' is not recommended as of now
##       Using the read -sv command that comes with yosys is very rudimentary and results in lots of errors
##       As of now, SystemVerilog support for yosys isn't the best for large projects
##       We will see how it goes...
SYNLIG = $(TOOL_ROOT)/synlig
PLUGIN_PATH := $(SYNLIG)/build/release/systemverilog-plugin/systemverilog.so

#========================================================================================
# Simulation Tools and Flags
#========================================================================================

GTKW = gtkwave
IVL = iverilog
VVP = vvp

IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp
OFLFLAGS = --cable dirtyJtag # When using Olimex GateMate it is a must to add this

#========================================================================================
# Simulation Directories
#========================================================================================
SIM = \
    $(HW_SRC)/modules/top_level/sim/opl3_tb.sv \
    $(HW_SRC)/modules/operator/sim/save_dac_input.sv

#========================================================================================
# Package Directories
#========================================================================================

#V_PKG = $(HW_SRC)/modules/top_level/pkg/opl3_pkg.v # This file is generated but empty
SV_PKG = $(HW_SRC)/modules/top_level/pkg/opl3_pkg.sv 

#========================================================================================
# Simulation Libraries
#========================================================================================

CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

#========================================================================================
# Project Configuration
#========================================================================================

TOP = opl3# Define TOP MODULE here
CONSTR = $(HW_SRC)/constraints/blink.ccf # Define Constraint file here
PRFLAGS += -ccf $blink.ccf -cCP # Constraint file as of right now is not used so it is just blinky.ccf file

#========================================================================================
# Synthesize Sources
#========================================================================================

VLOG_SRC = $(shell cat $(HW_SRC)/rtl.filelist)
#VHDL_SRC = $(shell find $(SRC) -type f \( -iname \*.vhd -o -iname \*.vhdl \))

#========================================================================================
# Toolchain Targets
#========================================================================================

v_gen:
	@echo "=============================================="
	@echo "Generating rtl.filelist with -v parameter..."
	@echo "=============================================="
	./create_rtl_filelist.sh -v

sv_gen:
	@echo "=============================================="
	@echo "Generating rtl.filelist with -sv parameter..."
	@echo "=============================================="
	./create_rtl_filelist.sh -sv

rtl_gen:
	@echo "=============================================="
	@echo "Running convert_sv2v.sh"
	@echo "=============================================="
	./convert_sv2v.sh
	./create_rtl_filelist.sh -v

# NOTE: Not sure how to add PKG?
synth_svlog: $(VLOG_SRC) $(SV_PKG)
	@echo "=============================================="
	@echo "Running Yosys synthesis for SystemVerilog sources..."
	@echo "=============================================="
	@test -d log || mkdir -p log
	@test -d net || mkdir -p net
	$(YOSYS) -ql log/synth.log -p 'plugin -i $(PLUGIN_PATH); read_systemverilog $(SV_PKG) $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
	@echo "=============================================="
	@echo "Yosys synthesis complete. Logs in log/synth.log."
	@echo "=============================================="
	
synth_vlog: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Running Yosys synthesis for Verilog sources..."
	@echo "=============================================="
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
	@echo "=============================================="
	@echo "Yosys synthesis complete. Logs in log/synth.log."
	@echo "=============================================="
	
synth_vhdl: $(VHDL_SRC)
	@echo "=============================================="
	@echo "Running Yosys synthesis for VHDL sources..."
	@echo "=============================================="
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -vhdl $(PKG); read -vhdl $(VHDL_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
	@echo "=============================================="
	@echo "Yosys synthesis complete. Logs in log/synth.log."
	@echo "=============================================="
	
# Synthesize with sv2v
synth_sv2v: rtl_gen synth_vlog

# Synthesize with normal SystemVerilog
synth_sv:
	@echo "Generating rtl.filelist with -sv parameter..."
	./create_rtl_filelist.sh -sv
	$(MAKE) synth_vlog

# Default synthesis target
synth: synth_sv2v


# Lint target
lint_verible: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verible..."
	@echo "=============================================="
	verible-verilog-lint $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verible Complete."
	@echo "=============================================="

lint_slang: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Slang..."
	@echo "=============================================="
	slang $(VLOG_SRC) --ignore-unknown-modules # This is because slang doesn't see IPs from vendors
	@echo "=============================================="
	@echo "Linting with Slang Complete."
	@echo "=============================================="
	
lint_verilator: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verilator..."
	@echo "=============================================="
	#verilator --lint-only -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC --top-module $(TOP) $(VLOG_SRC)
	verilator --lint-only -Wall --top-module $(TOP) $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verilator Complete."
	@echo "=============================================="

lint: lint_slang

lint_v: v_gen lint

lint_sv: sv_gen lint

impl:
	@echo "=============================================="
	@echo "Running place and route..."
	@echo "=============================================="
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(CONSTR) -cCP > log/$@.log || { tail -n 50 log/$@.log; exit 1; }
	@echo "=============================================="
	@echo "Place and route completed"
	@echo "=============================================="
	
jtag:
	@echo "=============================================="
	@echo "Programming via JTAG..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag $(TOP)_00.cfg
	#$(OFL) -b olimex_gatemateevb $(TOP)_00.cfg # Alternative
	@echo "=============================================="
	@echo "JTAG programming completed"
	@echo "=============================================="
	
jtag-flash:
	@echo "=============================================="
	@echo "Programming and verifying via JTAG..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg
	@echo "=============================================="
	@echo "JTAG programming and verification complete."
	@echo "=============================================="

spi:
	@echo "=============================================="
	@echo "Programming via SPI..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -m $(TOP)_00.cfg
	@echo "=============================================="
	@echo "SPI programming complete."
	@echo "=============================================="

spi-flash:
	@echo "=============================================="
	@echo "Programming and verifying via SPI..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi-f --verify $(TOP)_00.cfg
	@echo "=============================================="
	@echo "SPI programming and verification complete."
	@echo "=============================================="

all: synth impl jtag

## verilog simulation targets
vlog_sim.vvp:
	@echo "=============================================="
	@echo "Running Verilog simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(VLOG_SRC) $(SIM)/$(TOP)_tb.v
	@echo "=============================================="
	@echo "Verilog simulation complete."
	@echo "=============================================="


synth_sim.vvp:
	@echo "=============================================="
	@echo "Running synthesis simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ net/$(TOP)_synth.v $(SIM)/$(TOP)_tb.v $(CELLS_SYNTH)
	@echo "=============================================="
	@echo "Synthesis simulation complete."
	@echo "=============================================="


impl_sim.vvp:
	@echo "=============================================="
	@echo "Running implementation simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(TOP)_00.v $(SIM)/$(TOP)_tb.v $(CELLS_IMPL)
	@echo "=============================================="
	@echo "Implementation simulation complete."
	@echo "=============================================="

.PHONY: %sim %sim.vvp
%sim: %sim.vvp
	@echo "=============================================="
	@echo "Running simulation with VVP..."
	@echo "=============================================="
	$(VVP) -N $(SIM)/$< -fst
	@$(RM) $(SIM)/$^
	@echo "=============================================="
	@echo "Simulation complete."
	@echo "=============================================="


wave:
	@echo "=============================================="	
	@echo "Opening GTKwave..."
	@echo "=============================================="
	$(GTKW) $(SIM)/$(TOP)_tb.vcd $(SIM)/config.gtkw
	@echo "=============================================="	
	@echo "GTKWave opened."
	@echo "=============================================="

## misc tools
RM = rm -rf

clean:
	@echo "=============================================="
	@echo "Cleaning up project files..."
	@echo "=============================================="
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
	@echo "=============================================="
	@echo "Cleanup complete."
	@echo "=============================================="
#=============================================================
# End-of-File
#=============================================================

