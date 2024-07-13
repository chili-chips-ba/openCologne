#=============================================================
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================
SHELL   := /bin/bash

HW_SRC	:= $(CURDIR)/../1.hw
BLD_DIR := $(CURDIR)/../3.build
TB_NAME := tb
SIM_SRC := $(CURDIR)

export HW_SRC BLD_DIR TB_NAME SIM_SRC

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)

# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = top
VLOG_SRC = $(HW_SRC)/csr_pkg.sv  $(HW_SRC)/uart.WITHOUT-FIFO.sv $(HW_SRC)/psram.sv $(HW_SRC)/top.sv 

#------------------------
.PHONY: all
all: clean execute wave

#------------------------
clean:
	rm -rf output

#-------------------------------------------------------------
#___Global macros___
#   +define+SIM_ONLY \    to speed-up things for sim
#   +define+MIPI_4_LANE \
#
#___Xilinx macros___
#   +define+XIL_TIMING \
#   +define+HACKED_UNISIM \
#
#-------------------------------------------------------------


#---------------------------------------------------
# Option 1: verilator simulations: 
#					Source RTL
# May produce some warnings since primitives are
# differing from source modules in port declarations
#---------------------------------------------------


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
		-f ${HW_SRC}/top.filelist \
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
execute: compile
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
		-f ${HW_SRC}/top.filelist \
		${TB_NAME}.sv \
                \
		+define+SIM_ONLY \
		+define+HACKED_UNISIM \
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
		$(CELLS_IMPL) \
		$(VLOG_SRC) \
		$(SIM_SRC)/tb.sv

# Run make vlog_synth   first in 3.build
synth_sim.vvp:
	iverilog \
		-Winfloop \
		-g2012 \
		-gspecify \
		-Ttyp \
		-o $(SIM_SRC)/$@ \
		$(CELLS_SYNTH) \
		$(CELLS_IMPL) \
		$(BLD_DIR)/net/$(TOP)_synth.v \
		$(SIM_SRC)/tb.sv \
		

# Run make vlog_synth \ make impl  first in 3.build
impl_sim.vvp:
	iverilog \
		-Winfloop \
		-g2012 \
		-gspecify \
		-Ttyp \
		-o $(SIM_SRC)/$@ \
		$(BLD_DIR)/$(TOP)_00.v \
		$(SIM_SRC)/tb.sv \
		$(CELLS_IMPL)


# Run make vlog_synth first in 3.build
%sim: %sim.vvp
	vvp -N $(SIM_SRC)/$< -fst
	@$(RM) $(SIM_SRC)/$^

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
