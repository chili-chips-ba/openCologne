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


#========================================================================================
# Miscellaneous Tools
#========================================================================================
# Clock Domain Crossing Tool
# See https://github.com/BerkeleyLab/Bedrock/blob/master/build-tools/cdc_snitch.md
CDC_TOOLDIR = $(TOOL_ROOT)/Bedrock/build-tools
CDC_SNITCH_PROC := $(CDC_TOOLDIR)/cdc_snitch_proc.ys
CDC_SNITCH := $(CDC_TOOLDIR)/cdc_snitch.py

# Python
PYTHON = python3

#========================================================================================
# Plugins
#========================================================================================

## SYNLIG Plugin
#DONT_USE--| # NOTE: SYNLIG is outdated and not working with the latest version of yosys so 'synth_svlog'
#DONT_USE--| #       is not recommended as of now. Using the read -sv command that comes with yosys is 
#DONT_USE--| #       very rudimentary and results in lots of errors. As of now, SystemVerilog support for 
#DONT_USE--| #       yosys isn't the best for large projects. We will see how it goes. Also see:
#DONT_USE--| #       https://github.com/chili-chips-ba/openCologne/issues/3
#DONT_USE--| SYNLIG = $(<path-to-your-Synlig-install-directory>)/synlig
#DONT_USE--| PLUGIN_PATH := $(SYNLIG)/build/release/systemverilog-plugin/systemverilog.so

# GHDL Plugin Installation
# See: https://github.com/chili-chips-ba/openCologne/issues/24

# Step 1---| Install Yosys from source
#    git clone https://github.com/YosysHQ/yosys.git
#    cd yosys
#    make config-clang
#    git submodule update --init
#    make -j$(nproc)
#    sudo make install

# Step 2---| Install GHDL from source
#    git clone https://github.com/ghdl/ghdl.git
#    cd ghdl
#    ./configure --prefix=/usr/local
#    make -j$(nproc)
#    sudo make install

# Step 3---| Install the GHDL-Yosys Plugin
#    git clone https://github.com/ghdl/ghdl-yosys-plugin.git
#    cd ghdl-yosys-plugin
#    make GHDL=/usr/local/bin/ghdl -j$(nproc)
#    sudo make GHDL=/usr/local/bin/ghdl install

#IMPORTANT--| Make sure to test out `yosys -m ghdl` command in terminal, and then in yosys run `help ghdl`
#IMPORTANT--| Its should give back details how to use ghdl plugin for yosys. If not see the link above.
#IMPORTANT--| Check if your ghdl.so plugin is installed in the correct directory

#========================================================================================
# Tools
#========================================================================================

# sv2v Installation
# Github reference: https://github.com/zachjs/sv2v
# Build requirements: Install stack https://docs.haskellstack.org/en/stable/
#    git clone https://github.com/zachjs/sv2v.git
#    cd sv2v
#    make
# This creates the executable at ./bin/sv2v. Stack takes care of installing exact (compatible) versions of the compiler and sv2v's build dependencies. 
# You can install the binary to your local bin path (typically ~/.local/bin) by running stack install, or copy over the executable manually, or just add ./bin.sv2v to your path.

#========================================================================================
# Linters
#========================================================================================
# Slang Installation
# Github reference: https://github.com/MikePopoloski/slang

# Build requirements: python3, CMake(3.20 or later), C++20 Compatible compiler(GCC 11, clang 16, Xcode 15)
#     git clone https://github.com/MikePopoloski/slang.git
#     cmake -B build
#     cmake --build build -j8 

# Verible Installation
# Github reference: https://github.com/chipsalliance/verible
# Best way to install is to use the binary releases: https://github.com/chipsalliance/verible?tab=readme-ov-file#installation
# Dont forget to add them to your /usr/local/bin or /opt directories and source them
# Check if the commands work directly from the terminal  


#========================================================================================
# Clock Domain Checking
#========================================================================================

# Clock Domain Checking is done by using the tool from Bedrock: https://github.com/BerkeleyLab/Bedrock/blob/master/build-tools/cdc_snitch.md
# In the documentation it says that is is compatible with yosys 0.23, I tried it out with yosys 0.4 and it works fine
# For more information see: https://github.com/BerkeleyLab/Bedrock/blob/master/build-tools/cdc_snitch.md
#                           https://github.com/YosysHQ/yosys/discussions/3956
#                           https://github.com/YosysHQ/yosys/issues/4493#issuecomment-2246025920
# How to use:
# Go to your TOOL_ROOT(if you haven't exported it yet, export it)
# git clone https://github.com/BerkeleyLab/Bedrock.git
# That's it!

#========================================================================================
# Simulation Tools and Flags
#========================================================================================
GTKW = gtkwave
IVL  = iverilog
VVP  = vvp

IVLFLAGS = -g2012 -gspecify -Ttyp
OFLFLAGS = --cable dirtyJtag # BEWARE: When using Olimex GateMate it is a must to add this

#-------------------------------
# Icarus Verilog
#-------------------------------
# Github reference: https://github.com/steveicarus/iverilog
# Installation reference: https://steveicarus.github.io/iverilog/usage/installation.html

#-------------------------------
# Verilator
#-------------------------------
# Github reference: https://github.com/verilator/verilator
# Installation reference: https://verilator.org/guide/latest/install.html
# To use Verilator for simulation you need to make a `sim_main.cpp` file and a Makefile suited for Verilator
# See: https://github.com/chili-chips-ba/openCologne/tree/main/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim 
# Where I have verilator.mk file that takes care of the Verilator side of things and a Makefile that is specific to the project
#-------------------------------
# cocotb
#-------------------------------
# Github reference: https://github.com/cocotb/cocotb
# Documentation reference: https://docs.cocotb.org/en/stable/
# Installation: 
# Dependencies: python3.6+, GNU Make 3+, An HDL Simulator(Icarus, Verilator, GHDL...) 
#    pip install cocotb 

# See: https://github.com/chili-chips-ba/openCologne/tree/main/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/cocotb
# There is a config.mk file for cocotb with setups for different flags that can be found in the documentation
# There is a Makefile that takes into account all of the needed simulation files and their names(RTL file, testbench...)
# And the testbench written in python  

#========================================================================================
# Waveform viewers
#========================================================================================

#-------------------------------
# GTKWave
#-------------------------------
# Github reference: https://github.com/gtkwave/gtkwave.git
# Installation tutorial is given on the github for different Operating Systems

#-------------------------------
# Surfer
#-------------------------------
# Gitlab reference: https://gitlab.com/surfer-project/surfer/-/tree/main?ref_type=heads
# Easiest way is to download pre-built binaries and add them to your path, you can also build from source checking the link above 

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
# Define TOP MODULE here
TOP = opl3
CONSTR = $(HW_SRC)/constraints/blink.ccf
PRFLAGS += -ccf $blink.ccf -cCP # Constraint file as of right now is not used so it is just blinky.ccf file

#========================================================================================
# Synthesize Sources
#========================================================================================
VLOG_SRC = $(shell cat $(HW_SRC)/rtl.filelist)
#VHDL_SRC = $(shell find $(SRC) -type f \( -iname \*.vhd -o -iname \*.vhdl \))

#========================================================================================
# Misc Utilities
#========================================================================================
RM = rm -rf

#========================================================================================
# Toolchain Targets
#========================================================================================

#-------------------------------
# rtl.fileslist generators
#-------------------------------
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

sv2v_gen:
	@echo "=============================================="
	@echo "Running convert_sv2v.sh"
	@echo "=============================================="
	./convert_sv2v.sh
	./create_rtl_filelist.sh -v

#-------------------------------
# Clock Domain Crossing targets
#-------------------------------

opl3_cdc.json: $(VLOG_SRC)
#	$(YOSYS) $(YOSYS_QUIET) -p 'read_verilog $(VLOG_SRC); script $(CDC_SNITCH_PROC); write_json $@'
#	$(YOSYS) $(YOSYS_QUIET) -p 'read_verilog $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8; script $(CDC_SNITCH_PROC); write_json $@'
	$(YOSYS) $(YOSYS_QUIET) -p 'read_verilog $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -json opl3_cdc.json; script $(CDC_SNITCH_PROC)'

opl3_cdc.txt: $(CDC_SNITCH) opl3_cdc.json
	$(PYTHON) $^ -o $@

cdc: v_gen opl3_cdc.txt
.PHONY:cdc

#-------------------------------
# Lint targets
#-------------------------------
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

#-------------------------------
# Synth targets
#-------------------------------
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
synth_sv2v: sv2v_gen synth_vlog

# Synthesize with normal SystemVerilog
synth_sv:
	@echo "Generating rtl.filelist with -sv parameter..."
	./create_rtl_filelist.sh -sv
	$(MAKE) synth_vlog

# Default synthesis target
synth: synth_sv2v

#-------------------------------
# PNR
#-------------------------------
impl:
	@echo "=============================================="
	@echo "Running place and route..."
	@echo "=============================================="
	$(PNR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(CONSTR) -cCP > log/$@.log || { tail -n 50 log/$@.log; exit 1; }
	@echo "=============================================="
	@echo "Place and route completed"
	@echo "=============================================="

#-------------------------------
# FPGA Programming
#-------------------------------	
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

#-------------------------------
# All
#-------------------------------
all: lint cdc synth impl jtag

#========================================================================================
# Verilog Simulation Targets
#========================================================================================
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


wave_gtkwave:
	@echo "=============================================="	
	@echo "Opening GTKwave..."
	@echo "=============================================="
	$(GTKW) $(SIM)/$(TOP)_tb.vcd $(SIM)/config.gtkw
	@echo "=============================================="	
	@echo "GTKWave opened."
	@echo "=============================================="
	
wave_surfer:
	@echo "=============================================="	
	@echo "Opening Surfer..."
	@echo "=============================================="
	surfer $(SIM)/$(TOP)_tb.vcd $(SIM)/config.gtkw
	@echo "=============================================="	
	@echo "Surfer opened."
	@echo "=============================================="

wave: wave_gtkwave

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
	$(RM) $(SIM)/*.vcd
	$(RM) $(SIM)/*.vvp
	$(RM) $(SIM)/*.gtkw
	$(RM) $(JSON_OUTPUT).json $(JSON_OUTPUT).txt
	test ! -d log || rmdir log
	test ! -d net || rmdir net
	@echo "=============================================="
	@echo "Cleanup complete."
	@echo "=============================================="
.PHONY:clean
#=============================================================
# End-of-File
#=============================================================

