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
PR = $(CC_TOOL)/bin/p_r/p_r
OFL = $(TOOL_ROOT)/openFPGALoader/build/openFPGALoader

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = top
CONSTR = $(HW_SRC)/constraints/constraints.ccf
PRFLAGS = -cCP --verbose

# Synthesize Sources
TOP_FILELIST = $(shell perl -ne 's/\$$\{HW_SRC\}\///g ; print unless /^\s*\#/' ${HW_SRC}/rtl.filelist)
VERILOG_SOURCES += $(TOP_FILELIST:%=$(HW_SRC)/%)
SIM_MODELS = $(SIM_SRC)/models/psram_sim.sv

V_SRC    =  ./*v

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
hw_all: hw_clean clean convert synth_vlog impl jtag

# Remove all output files created from HW build process
hw_clean:
	rm -rf $(HW_BLD)

convert:
	sv2v --write=./ $(VERILOG_SOURCES)
# Synthesis 
#synth_vlog: $(VERILOG_SOURCES)
#	@test -d log || mkdir log
#	@test -d net || mkdir net
#	$(YOSYS) -ql log/synth.log -p 'plugin -i $(PLUGIN_PATH); read_systemverilog $(VERILOG_SOURCES); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'
synth_vlog: $(VERILOG_SOURCES)
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
clean:
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
