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

BLD_PATH = /usr/local/bin

#========================================================================================
# GateMate CologneChip Tools
#========================================================================================
#YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
YOSYS = /usr/local/bin/yosys$(EXE)
PNR   = $(CC_TOOL)/bin/p_r/p_r$(EXE)

#DONT_USE--| This OFL line does not work for me. If you have the same problem, update OFL to the newest 
#DONT_USE--| version, next paragraph. Also see: https://github.com/chili-chips-ba/openCologne/issues/7
#DONT_USE--| OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE) 

# Uncomment to use newer/other version of Yosys synthesizer
# See: https://github.com/chili-chips-ba/openCologne/issues/13
# YOSYS = $(BLD_PATH)/yosys/yosys
OFL = $(BLD_PATH)/openFPGALoader$(EXE) 

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

#
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
# Simulation Libraries
#========================================================================================
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL  = $(CC_TOOL)/bin/p_r/cpelib.v

#========================================================================================
# Project Configuration
#========================================================================================
# Define TOP MODULE here
TOP      = blink
CONSTR   = $(TOP).ccf
PRFLAGS += -ccf $(TOP).ccf -cCP

#========================================================================================
# Synthesize Sources
#========================================================================================
VLOG_SRC = $(shell find $(HW_SRC)/ -type f \( -iname \*.v -o -iname \*.sv \))
VHDL_SRC = $(shell find $(HW_SRC)/ -type f \( -iname \*.vhd -o -iname \*.vhdl \))

#========================================================================================
# Misc Utilities
#========================================================================================
RM = rm -rf

#========================================================================================
# Toolchain Targets
#========================================================================================

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
	slang $(VLOG_SRC) --ignore-unknown-modules # This is because slang doesn't see IPs from vendor
	# Tarik, file issue for this on https://github.com/MikePopoloski/slang/issues
	@echo "=============================================="
	@echo "Linting with Slang Complete."
	@echo "=============================================="
	
lint_verilator: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verilator..."
	@echo "=============================================="
	verilator --lint-only -Wall --top-module $(TOP) $(VLOG_SRC)
	@echo "=============================================="
	@echo "Linting with Verilator Complete."
	@echo "=============================================="

lint: lint_verible lint_slang lint_verilator

#-------------------------------
# Synth targets
#-------------------------------
synth_vlog: $(VLOG_SRC)
	@echo "=============================================="
	@echo "Running Yosys synthesis for Verilog sources..."
	@echo "=============================================="
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $(VLOG_SRC); \
	synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
	@echo "=============================================="
	@echo "Yosys synthesis complete. Logs in log/synth.log."
	@echo "=============================================="
	
synth_vhdl: $(VHDL_SRC)
	@echo "=============================================="
	@echo "Running Yosys synthesis for VHDL sources..."
	@echo "=============================================="
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -m ghdl -p 'ghdl --warn-no-binding -C --ieee=synopsys $(VHDL_SRC) -e $(TOP); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
	@echo "=============================================="
	@echo "Yosys synthesis complete. Logs in log/synth.log."
	@echo "=============================================="

synth: synth_vlog

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
	$(OFL) -b gatemate_evb_jtag --cable dirtyJtag --bitstream $(TOP)_00.cfg.bit
	@echo "=============================================="
	@echo "JTAG programming complete."
	@echo "=============================================="

jtag-flash:
	@echo "=============================================="
	@echo "Programming and verifying via JTAG..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag --cable dirtyJtag -f --verify $(TOP)_00.cfg
	@echo "=============================================="
	@echo "JTAG programming and verification complete."
	@echo "=============================================="

spi:
	@echo "=============================================="
	@echo "Programming via SPI..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi --cable dirtyJtag -m $(TOP)_00.cfg
	@echo "=============================================="
	@echo "SPI programming complete."
	@echo "=============================================="

spi-flash:
	@echo "=============================================="
	@echo "Programming and verifying via SPI..."
	@echo "=============================================="
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi --cable dirtyJtag -f --verify $(TOP)_00.cfg
	@echo "=============================================="
	@echo "SPI programming and verification complete."
	@echo "=============================================="

#-------------------------------
# All
#-------------------------------
all: lint synth impl jtag

#========================================================================================
# Verilog Simulation Targets
#========================================================================================
vlog_sim.vvp:
	@echo "=============================================="
	@echo "Running Verilog simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ $(VLOG_SRC) $(SIM_SRC)/$(TOP)_tb.v
	@echo "=============================================="
	@echo "Verilog simulation complete."
	@echo "=============================================="

synth_sim.vvp:
	@echo "=============================================="
	@echo "Running synthesis simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ net/$(TOP)_synth.v $(SIM)/$(TOP)_tb.v $(CELLS_SYNTH)
	@echo "=============================================="
	@echo "Synthesis simulation complete."
	@echo "=============================================="

impl_sim.vvp:
	@echo "=============================================="
	@echo "Running implementation simulation..."
	@echo "=============================================="
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ $(TOP)_00.v $(SIM)/$(TOP)_tb.v $(CELLS_IMPL)
	@echo "=============================================="
	@echo "Implementation simulation complete."
	@echo "=============================================="

.PHONY: %sim %sim.vvp
%sim: %sim.vvp
	@echo "=============================================="
	@echo "Running simulation with VVP..."
	@echo "=============================================="
	$(VVP) -N $(SIM_SRC)/$< -fst
	@$(RM) $(SIM_SRC)/$^
	@echo "=============================================="
	@echo "Simulation complete."
	@echo "=============================================="

wave_gtkwave:
	@echo "=============================================="
	@echo "Opening GTKWave..."
	@echo "=============================================="
	$(GTKW) $(SIM_SRC)/$(TOP)_tb.vcd $(SIM_SRC)/config.gtkw
	@echo "=============================================="
	@echo "GTKWave opened."
	@echo "=============================================="

wave_surfer:
	@echo "=============================================="
	@echo "Opening Surfer..."
	@echo "=============================================="
	surfer $(SIM_SRC)/$(TOP)_tb.vcd 
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
	test ! -d log || rmdir log
	test ! -d net || rmdir net
	@echo "=============================================="
	@echo "Cleanup complete."
	@echo "=============================================="

#=============================================================
# End-of-File
#=============================================================
