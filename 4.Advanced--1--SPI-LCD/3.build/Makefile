<<<<<<< HEAD
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
YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)

#OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE) # Path to OFL needs to be latest version of OFL or you will get errors when programming the board
## EDIT THIS SO IT IS the path to your installation of openFPGALoader!!! ##
OFL = /home/user/FPGA/tools/openFPGALoader/build/openFPGALoader$(EXE) 

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
TOP = blink# Define TOP MODULE here
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
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag --cable dirtyJtag --bitstream $(TOP)_00.cfg

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

=======
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

>>>>>>> 6d9bbe57d8f55e3dcee7fdcfda3f86a5710e74bd
