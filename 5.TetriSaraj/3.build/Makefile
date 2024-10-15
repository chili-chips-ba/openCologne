#========================================================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#========================================================================================

#========================================================================================
# Toolchain Download and Setup Instructions
#========================================================================================
# 1.Download the toolchain from the following link:
#    https://www.colognechip.com/programmable-logic/gatemate/gatemate-download
#
#    There are two options available:
#     - Toolchain for Linux
#     - Toolchain for Windows
#    The remainder of instrcutions is for Linux or WSL
#
# 2.Extract the downloaded archive to your preferred location
#
# 3.Set the CC_TOOL Environment Variable
#
#   Option 1: Persistent Setup
#     The easiest way to set the environment variable is by adding it to your `.bashrc` file. 
#     This ensures that the variable is set every time you open a new terminal.
#
#      1a. Open terminal and run the following command 
#          (replace `/path/to/cc-toolchain-linux` with the actual path to the extracted toolchain):
#          % echo 'export CC_TOOL="/path/to/cc-toolchain-linux"' >> ~/.bashrc
#
#      1b. After running the command, either restart your terminal or source the `.bashrc` file to apply the changes:
#          % source ~/.bashrc
#
#   Option 2: Temporary Setup
#     You can also set the environment variable temporarily for the current terminal session. 
#     This method requires you to export the variable each time you open a new terminal.
#
#      2a. Open terminal and run the following command 
#          (replace `/path/to/cc-toolchain-linux` with the actual path to the extracted toolchain):
#          % export CC_TOOL="/path/to/cc-toolchain-linux"

#========================================================================================
# Set EXE for platform-specific executable extensions, if necessary
#========================================================================================
EXE =

#========================================================================================
# Toolchain Directories and Executable Commands
#========================================================================================
BLD_DIR  = $(CURDIR)
HW_SRC  := $(BLD_DIR)/../1.hw
SIM_SRC  := $(BLD_DIR)/../2.sim

TOOL_ROOT = /home/user/FPGA/tools

#========================================================================================
# GateMate CologneChip Tools
#========================================================================================
#YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
PNR   = $(CC_TOOL)/bin/p_r/p_r$(EXE)
#DONT_USE--| This OFL line does not work for me. If you have the same problem, update OFL to the newest 
#DONT_USE--| version, next paragraph. Also see: https://github.com/chili-chips-ba/openCologne/issues/7
#DONT_USE--| OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE) 

# Uncomment to use newer/other version of Yosys synthesizer
# See: https://github.com/chili-chips-ba/openCologne/issues/13
YOSYS = yosys
YOSYS_QUIET = -q
OFL = openFPGALoader$(EXE) 

# Python
PYTHON = python3


IVLFLAGS = -g2012 -gspecify -Ttyp
OFLFLAGS = --cable dirtyJtag # BEWARE: When using Olimex GateMate it is a must to add this

#========================================================================================
# Project Configuration
#========================================================================================
# Define TOP MODULE here
TOP      = top
CONSTR   = $(TOP).ccf
PRFLAGS += -ccf $(TOP).ccf -cCP

#========================================================================================
# Synthesize Sources
#========================================================================================
VLOG_SRC = $(shell find $(HW_SRC)/ -type f \( -iname \*.v -o -iname \*.sv \))

#========================================================================================
# Misc Utilities
#========================================================================================
RM = rm -rf

#-------------------------------
# Synth targets
#-------------------------------
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

synth: synth_vlog
.PHONY:synth

#-------------------------------
# PNR
#-------------------------------
impl:
	@echo "=============================================="
	@echo "Running Place and Route..."
	@echo "=============================================="
	$(PNR) -v -i net/$(TOP)_synth.v -o $(TOP) -ccf $(TOP).ccf -cCP > log/$@.log
	@echo "=============================================="
	@echo "Place and Route complete. Logs in log/impl.log."
	@echo "=============================================="

#-------------------------------
# FPGA Programming
#-------------------------------
jtag:
	@echo "=============================================="
	@echo "Programming via JTAG..."
	@echo "=============================================="
	sudo $(OFL) -b gatemate_evb_jtag --cable dirtyJtag --bitstream $(TOP)_00.cfg.bit
	@echo "=============================================="
	@echo "JTAG programming complete."
	@echo "=============================================="

#-------------------------------
# All
#-------------------------------
all: synth impl jtag
.PHONY:all

#========================================================================================
# Housekeeping
#========================================================================================
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
	test ! -d log || rmdir log
	test ! -d net || rmdir net
	@echo "=============================================="
	@echo "Cleanup complete."
	@echo "=============================================="
.PHONY:clean
#=============================================================
# End-of-File
#=============================================================
