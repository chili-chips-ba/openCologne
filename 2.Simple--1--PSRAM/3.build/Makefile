#=============================================================
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

BLD_DIR := $(CURDIR)
HW_SRC  := $(BLD_DIR)/../1.hw
HW_BLD  := $(BLD_DIR)/hw_build.TCL
SIM_SRC = ../2.sim

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
SYNLIG = ~/0.git-repo/synlig
PLUGIN_PATH := $(SYNLIG)/build/release/systemverilog-plugin/systemverilog.so
#YOSYS = $(SYNLIG)/out/current/bin/yosys
YOSYS = yosys
PR = $(CC_TOOL)/bin/p_r/p_r
OFL = openFPGALoader

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = top# Define TOP MODULE here
CONSTR = $(HW_SRC)/constraints/constraints.ccf
PRFLAGS = -cCP --verbose

# Synthesize Sources
VLOG_SRC = $(HW_SRC)/csr_pkg.sv $(HW_SRC)/csr_if.sv $(HW_SRC)/uart.WITHOUT-FIFO.sv $(HW_SRC)/psram.sv $(HW_SRC)/top.sv 
V_SRC    =  ./*v

## misc tools
RM = rm -rf

#------------------------
# Execute the entire build flow: First SW, then HW
.PHONY: hw_all

#=============================================================
# HW Build
#-------------------------------------------------------------
# This step must be run after SW build, as we first need to
# have SW program to then store it into RTL for IMEM
#-------------------------------------------------------------
# You must have GowinEDA package installed for this.
#
#  1) Download 'Gowin_V1.9.9.01_x64_win.zip' fajl from our WebDisk:
#     https://www.chili-chips.xyz:2078/Gowin_V1.9.9.01_x64_win.zip
#       UserID: student@chili-chips.xyz
#       Pass  : fpga123
#   
#  2) Unzip and install. The license is free, but you have to register on:
#       https://www.gowinsemi.com/en/support/license
#   
#  3) Add Gowin Windows install to your Linux $PATH, such as (for 'tcsh'):
#       setenv GOWIN_ROOT '/mnt/c/Gowin/Gowin_V1.9.9.01_x64/IDE/bin'
#       setenv PATH       "${WIN_ROOT}:${PATH}"
#
#   For more, see: 0.doc/1.README.Tool-Installs.txt  
#=============================================================

#------------------------
hw_all: hw_clean clean convert synth_vlog impl jtag

# Remove all output files created from HW build process
hw_clean:
	rm -rf $(HW_BLD)

convert:
	sv2v --write=./ $(VLOG_SRC)
# Synthesis 
#synth_vlog: $(VLOG_SRC)
#	@test -d log || mkdir log
#	@test -d net || mkdir net
#	$(YOSYS) -ql log/synth.log -p 'plugin -i $(PLUGIN_PATH); read_systemverilog $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
synth_vlog: $(VLOG_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read_verilog -sv $(V_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
# Place and Route
impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf $(CONSTR) $(PRFLAGS) > log/$@.log
# Jtag programming
jtag:
	sudo $(OFL) $(OFLFLAGS) -b gatemate_evb_jtag --cable dirtyJtag --bitstream $(TOP)_00.cfg.bit


#----------------------------
# Other types of programming
#----------------------------
#jtag-flash:
#	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg

#spi:
#	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -m $(TOP)_00.cfg

#spi-flash:
#	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -f --verify $(TOP)_00.cfg


## verilog simulation targets
vlog_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ $(VLOG_SRC) $(SIM_SRC)/tb.sv

synth_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ net/$(TOP)_synth.v $(SIM_SRC)/tb.sv $(CELLS_SYNTH)

impl_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM_SRC)/$@ $(TOP)_00.v $(SIM_SRC)/tb.sv $(CELLS_IMPL)
%sim: %sim.vvp
	$(VVP) -N $(SIM_SRC)/$< -fst
	@$(RM) $(SIM_SRC)/$^

wave:
	$(GTKW) $(SIM_SRC)/tb.vcd $(SIM_SRC)/config.gtkw




clean:
	$(RM) log/*.log
	$(RM) net/*_synth.v
	$(RM) *.history
	$(RM) *.txt
	$(RM) */.v
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
	$(RM) $(SIM_SRC)/*.vcd
	$(RM) $(SIM_SRC)/*.vvp
	$(RM) $(SIM_SRC)/*.gtkw
	$(RM) $(HW_SRC)/*.v

	test ! -d log || rmdir log
	test ! -d net || rmdir net




















#------------------------
# Execute HW Build using Gowin Synth->PNR->Bitgen flow
# hw_build:
#	gw_sh.exe run-hwbuild.tcl



#=============================================================
# End-of-File
#=============================================================
