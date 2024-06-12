######################################################################
#
# DESCRIPTION: Make Verilator model and run
#
# This calls the object directory makefile.  That allows the objects to
# be placed in the "current directory" which simplifies the Makefile.
#
# This file is placed under the Creative Commons Public Domain, for
# any use, without warranty, 2020 by Wilson Snyder.
# SPDX-License-Identifier: CC0-1.0
#
######################################################################

SIM_DIR = $(CURDIR)
HW_SRC  := $(SIM_DIR)/../1.hw
SW_SRC  := $(SIM_DIR)/../2.sw
TOOL_ROOT := /home/user/FPGA/tools

SYSTEM_INCLUDE := $(TOOL_ROOT)/systemc-2.3.3/include
SYSTEM_LIBDIR  := $(TOOL_ROOT)/systemc-2.3.3/lib-linux64

ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

# This example started with the Verilator example files.
# Please see those examples for commented sources, here:
# https://github.com/verilator/verilator/tree/master/examples

######################################################################
# Set up variables

# If $VERILATOR_ROOT isn't in the environment, we assume it is part of a
# package install, and verilator is in your path. Otherwise find the
# binary relative to $VERILATOR_ROOT (such as when inside the git sources).
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

VERILATOR_FLAGS =
# Generate C++ in executable form
VERILATOR_FLAGS += -cc --exe
# Generate makefile dependencies (not shown as complicates the Makefile)
#VERILATOR_FLAGS += -MMD
# Optimize
VERILATOR_FLAGS += --x-assign 0
# Warn abount lint issues; may not want this on less solid designs
VERILATOR_FLAGS += -Wall
# Make waveforms
#VERILATOR_FLAGS += --trace
# Check SystemVerilog assertions
VERILATOR_FLAGS += --assert
# Run make to compile model, with as many CPUs as are free
VERILATOR_FLAGS += --build -j
VERILATOR_FLAGS += --timescale 1ns/1ps
# Warnings Ignore 
#VERILATOR_FLAGS += -Wno-TIMESCALEMOD
#VERILATOR_FLAGS += -Wno-LITENDIAN
#VERILATOR_FLAGS += -Wno-WIDTH
VERILATOR_FLAGS += -Wno-UNOPTFLAT
VERILATOR_FLAGS += -Wno-CASEINCOMPLETE
VERILATOR_FLAGS += -Wno-UNDRIVEN
VERILATOR_FLAGS += -Wno-VARHIDDEN
VERILATOR_FLAGS += -Wno-IMPORTSTAR
VERILATOR_FLAGS += -Wno-REALCVT
VERILATOR_FLAGS += -Wno-UNUSED

VERILATOR_FLAGS += -CFLAGS "-I$(SYSTEM_INCLUDE) -DVL_TIME_CONTEXT" \
                   -LDFLAGS "-L$(SYSTEM_LIBDIR) -lsystemc"
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt

# Input files for Verilator
# List of SystemVerilog and Verilog input files for Verilator
VERILATOR_INPUT = $(shell cat $(HW_SRC)/rtl.filelist)
# Main Test Function for Verilator
VERILATOR_INPUT += sim_main.cpp

######################################################################

default: run

run:
	@echo
	@echo "-- Verilator example"

	@echo
	@echo "-- VERILATE ----------------"
	$(VERILATOR) --version
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module opl3 $(VERILATOR_INPUT)

	@echo
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vopl3

	@echo
	@echo "-- DONE --------------------"

# Other targets

show-config:
	$(VERILATOR) -V

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd core

