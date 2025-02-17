#=============================================================
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

BLD_DIR := $(CURDIR)
HW_SRC  := $(BLD_DIR)/../1.hw
HW_BLD  := $(BLD_DIR)/hw_build.TCL
SIM_SRC = ../2.sim

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
TOOL_ROOT = /home/tibrahimovic/0.git-repo/

#PLUGIN_PATH := $(SYNLIG)/build/release/systemverilog-plugin/systemverilog.so
YOSYS = $(TOOL_ROOT)/yosys/yosys
MODULE = -m ghdl
PR = $(CC_TOOL)/bin/p_r/p_r
OFL = $(TOOL_ROOT)/openFPGALoader/build/openFPGALoader
GHDL = 

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP=fpga_torture
CONSTR = $(HW_SRC)/constraints/constraints.ccf
PRFLAGS = -cCP --verbose

# Synthesize Sources
TOP_FILELIST = $(shell perl -ne 's/\$$\{HW_SRC\}\///g ; print unless /^\s*\#/' ${HW_SRC}/rtl.filelist)
VHDL_SOURCES += $(TOP_FILELIST:%=$(HW_SRC)/%)

## misc tools
RM = rm -rf

#------------------------
# Execute the entire build flow: First SW, then HW
.PHONY: hw_all

#=============================================================
# HW Build
#-------------------------------------------------------------
#=============================================================

#------------------------
hw_all: hw_clean clean vhdl_analyze synth_vlog impl jtag

# Remove all output files created from HW build process
hw_clean:
	rm -rf $(HW_BLD)

vhdl_analyze:
	ghdl -a --std=08 --work=work $(VHDL_SOURCES)
# Synthesis 
synth_vlog: $(VHDL_SOURCES) vhdl_analyze
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) $(MODULE) -ql log/synth.log -p 'ghdl --std=08 ../1.hw/fpga_torture.vhd -e; synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
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
clean:
	$(RM) *.of
	$(RM) *.cf
	$(RM) log/*.log
	$(RM) net/*_synth.v
	$(RM) *.history
	$(RM) *.txt
	$(RM) ./*.v
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

#=============================================================
# End-of-File
#=============================================================
