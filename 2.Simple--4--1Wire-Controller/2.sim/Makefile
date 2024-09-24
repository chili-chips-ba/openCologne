#=============================================================
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

HW_SRC	:= $(CURDIR)/../1.hw
BLD_DIR := $(CURDIR)/../3.build
TB_NAME := tb
SIM_SRC := $(CURDIR)

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL_DIR)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL_DIR)/bin/p_r/cpelib.v

export HW_SRC BLD_DIR TB_NAME SIM_SRC CC_TOOL_DIR

# Project Configuration
TOP = top

#------------------------
.PHONY: all
all: clean compile execute wave
all_synth: clean compile_synth execute wave
all_impl: clean compile_impl execute wave

#------------------------
clean:
	rm -rf ./output

#-------------------------------------------------------------
#___Global macros___
#   +define+SIM_ONLY \    to speed-up things for sim
#   +define+MIPI_4_LANE \
#-------------------------------------------------------------


#---------------------------------------------------
# Option 1: verilator simulations: 
#					Source RTL make, make all
#					Post synth make all_synth
#                   Post PnR   make all_impl
# May produce some warnings since primitives are
# differing from source modules in port declarations
#---------------------------------------------------

# Read verilog sources from 1.hw/rtl.filelist
TOP_FILELIST = $(shell perl -ne 's/\$$\{HW_SRC\}\///g ; print unless /^\s*\#/' ${HW_SRC}/rtl.filelist)
VERILOG_SOURCES += $(TOP_FILELIST:%=$(HW_SRC)/%)
SIM_MODELS = ${SIM_SRC}/models/onewire_slave_model.sv


compile: 
	verilator \
		--cc \
		--timing \
		--trace-fst \
		--trace-structs \
		--timescale-override 1ps/1ps \
		--exe versimSV.cpp \
		--Mdir ./output \
		-Wno-fatal \
		\
		+define+SIM_ONLY \
		+define+HACKED_UNISIM \
		\
		-f ${HW_SRC}/rtl.filelist \
		\
		$(SIM_MODELS) \
		${TB_NAME}.sv \
		--top-module ${TB_NAME}


compile_impl: 
	verilator \
		--cc \
		--timing \
		--trace-fst \
		--trace-structs \
		--timescale-override 1ps/1ps \
		--exe versimSV.cpp \
		--Mdir ./output \
		-Wno-fatal \
		\
		$(CELLS_SYNTH) \
		$(CELLS_IMPL) \
		$(SIM_MODELS) \
		./../3.build/top_00.v \
		\
		${TB_NAME}.sv \
		--top-module ${TB_NAME}

compile_synth: 
	verilator \
		--cc \
		--timing \
		--trace-fst \
		--trace-structs \
		--timescale-override 1ps/1ps \
		--exe versimSV.cpp \
		--Mdir ./output \
		-Wno-fatal \
		\
		$(CELLS_SYNTH) \
		$(CELLS_IMPL) \
		$(SIM_MODELS) \
		$(BLD_DIR)/net/$(TOP)_synth.v \
		\
		${TB_NAME}.sv \
		--top-module ${TB_NAME}
#		-O1 \
#		-O3 \
#		-Wno-fatal \
#		--debug \
#		--trace-threads 1 \
#
#		--x-assign fast \
#		--x-initial fast \
#		--noassert \
#		--no-timing \
#		--trace-depth 10 \
#		--trace-max-array 1024 \    Maximum array depth for tracing
#		--trace-max-width 32 \      Maximum bit width for tracing
#
#		--assert \  read //synopsys full_case or //synopsys parallel_case
#		     //ambit synthesis, //cadence or //pragma directives
#		     Also asserts any "unique" or "priority" SV keywords on
#		     case statements, as well as "unique" on if statements.
#		     However, "priority if" is currently ignored.


#------------------------
execute: 
	cd output; \
	make -f V${TB_NAME}.mk  V${TB_NAME}; \
	./V${TB_NAME} | tee sim.log

#------------------------
wave: xml2stems
	cd output; \
	gtkwave --saveonexit \
		--slider-zoom \
		--stems   ../tb.stems \
		--logfile sim.log \
		-rc       ../.gtkwaverc \
		--dump    wave.fst &

#		--wish \
#		--save ../wave.gtkw 

#------------------------
wave-alt: 
	cd output; \
	surfer.exe -s ../wave.surfer.ron wave.fst &

#------------------------
xml2stems: 
	verilator \
		--timing \
		-xml-only \
		-xml-output tb.xml \
		-Wno-fatal \
		--timescale 1ps/1ps \
		-f ${HW_SRC}/rtl.filelist \
		${SIM_MODELS} \
		${TB_NAME}.sv \
                \
		+define+SIM_ONLY \
                \
		--top-module ${TB_NAME}
	xml2stems tb.xml tb.stems


#------------------------
rtlbrowse: xml2stems
	rtlbrowse tb.stems   

#-------------------------------------------------
# Option 2: iverilog simulations:
#					1. Source RTL     -> vlog_sim 
#					2. Post Synthesis -> synth_sim
#					3. Post PnR       -> impl_sim
# May or may not work, depending on which 
# 	      IP cores are used in the design
# (Some have different port declarations )
#-------------------------------------------------


vlog_sim.vvp:
	iverilog \
		-Winfloop \
		-g2012 \
		-gspecify \
		-Ttyp \
		-DSIM_ONLY \
		-o $(SIM_SRC)/$@ \
		$(VERILOG_SOURCES) \
		$(SIM_MODELS) \
		$(SIM_SRC)/tb.sv

# Run make vlog_synth   first in 3.build
synth_sim.vvp: clean_iverilog
	iverilog \
		-Winfloop \
		-g2012 \
		-gspecify \
		-Ttyp \
		-o $(SIM_SRC)/$@ \
		$(CELLS_SYNTH) \
		$(SIM_MODELS) \
		$(BLD_DIR)/net/$(TOP)_synth.v \
		$(SIM_SRC)/tb.sv 

# Run make vlog_synth \ make impl  first in 3.build
impl_sim.vvp: clean_iverilog
	iverilog \
		-Winfloop \
		-g2012 \
		-gspecify \
		-Ttyp \
		-o $(SIM_SRC)/$@ \
		$(SIM_MODELS) \
		$(BLD_DIR)/$(TOP)_00.v \
		$(SIM_SRC)/tb.sv \
		$(CELLS_IMPL)

# Run make vlog_synth first in 3.build
%sim: %sim.vvp
	vvp -N $(SIM_SRC)/$< -fst
	@$(RM) $(SIM_SRC)/$^
	$(MAKE) wave_iverilog


wave_iverilog: 
	gtkwave --saveonexit \
		--slider-zoom \
		--logfile sim.log \
		-rc       ../.gtkwaverc \
		--dump    tb.vcd &

clean_iverilog:
	$(RM) $(SIM_SRC)/*.vcd
	$(RM) $(SIM_SRC)/*.vvp
	$(RM) $(SIM_SRC)/*.gtkw
	test ! -d log || rmdir log
	test ! -d net || rmdir net



#=============================================================
# End-of-File
#=============================================================
