######################################################################
#
# DESCRIPTION: Make Verilator model and run coverage
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

SYSTEM_INCLUDE := /home/user/FPGA/tools/systemc-2.3.3/include
SYSTEM_LIBDIR := /home/user/FPGA/tools/systemc-2.3.3/lib-linux64

ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

# This example started with the Verilator example files.
# Please see those examples for commented sources, here:
# https://github.com/verilator/verilator/tree/master/examples

######################################################################
# Set up variables

GENHTML = genhtml

# If $VERILATOR_ROOT isn't in the environment, we assume it is part of a
# package install, and verilator is in your path. Otherwise find the
# binary relative to $VERILATOR_ROOT (such as when inside the git sources).
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
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
# Generate coverage analysis
VERILATOR_FLAGS += --coverage
# Run make to compile model, with as many CPUs as are free
VERILATOR_FLAGS += --build -j
VERILATOR_FLAGS += --timescale 1ns/1ps
# Warnings Ignore 
VERILATOR_FLAGS += -Wno-TIMESCALEMOD
VERILATOR_FLAGS += -Wno-WIDTH
VERILATOR_FLAGS += -Wno-UNOPTFLAT
VERILATOR_FLAGS += -Wno-CASEINCOMPLETE
VERILATOR_FLAGS += -Wno-LITENDIAN
VERILATOR_FLAGS += -Wno-UNDRIVEN
VERILATOR_FLAGS += -Wno-VARHIDDEN
VERILATOR_FLAGS += -Wno-IMPORTSTAR
VERILATOR_FLAGS += -Wno-REALCVT

VERILATOR_FLAGS += -CFLAGS "-I$(SYSTEM_INCLUDE) -DVL_TIME_CONTEXT" \
                   -LDFLAGS "-L$(SYSTEM_LIBDIR) -lsystemc"
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt

# Input files for Verilator
# List of SystemVerilog and Verilog input files for Verilator
VERILATOR_INPUT = \
    $(HW_SRC)/modules/top_level/pkg/opl3_pkg.sv \
    $(HW_SRC)/modules/misc/src/afifo.v \
    $(HW_SRC)/modules/clks/src/clk_div.sv \
    $(HW_SRC)/modules/clks/src/reset_sync.sv \
    $(HW_SRC)/modules/channels/src/dac_prep.sv \
    $(HW_SRC)/modules/i2s/src/i2s.sv \
    $(HW_SRC)/modules/misc/src/edge_detector.sv \
    $(HW_SRC)/modules/misc/src/mem_multi_bank.sv \
    $(HW_SRC)/modules/misc/src/pipeline_sr.sv \
    $(HW_SRC)/modules/misc/src/mem_simple_dual_port_async_read.sv \
    $(HW_SRC)/modules/host_if/src/host_if.sv \
    $(HW_SRC)/modules/misc/src/mem_multi_bank_reset.sv \
    $(HW_SRC)/modules/operator/src/operator.sv \
    $(HW_SRC)/modules/top_level/src/opl3.sv \
    $(HW_SRC)/modules/channels/src/channels.sv \
    $(HW_SRC)/modules/channels/src/control_operators.sv \
    $(HW_SRC)/modules/operator/src/calc_rhythm_phase.sv \
    $(HW_SRC)/modules/operator/src/phase_generator.sv \
    $(HW_SRC)/modules/operator/src/vibrato.sv \
    $(HW_SRC)/modules/operator/src/envelope_generator.sv \
    $(HW_SRC)/modules/operator/src/ksl_add_rom.sv \
    $(HW_SRC)/modules/operator/src/env_rate_counter.sv \
    $(HW_SRC)/modules/operator/src/tremolo.sv \
    $(HW_SRC)/modules/operator/src/opl3_log_sine_lut.sv \
    $(HW_SRC)/modules/operator/src/opl3_exp_lut.sv \
    $(HW_SRC)/modules/timers/src/timers.sv \
    $(HW_SRC)/modules/timers/src/timer.sv \
    $(HW_SRC)/modules/misc/src/synchronizer.sv \
    $(HW_SRC)/modules/misc/src/leds.sv \
    $(HW_SRC)/modules/host_if/src/trick_sw_detection.sv \
    $(HW_SRC)/modules/misc/src/mem_simple_dual_port.sv \
    $(HW_SRC)/modules/operator/src/calc_phase_inc.sv \
    sim_main.cpp

######################################################################

# Create annotated source
VERILATOR_COV_FLAGS += --annotate logs/annotated
# A single coverage hit is considered good enough
VERILATOR_COV_FLAGS += --annotate-min 1
# Create LCOV info
VERILATOR_COV_FLAGS += --write-info logs/coverage.info
# Input file from Verilator
VERILATOR_COV_FLAGS += logs/coverage.dat

######################################################################
default: run

run:
	@echo
	@echo "-- Verilator coverage example"

	@echo
	@echo "-- VERILATE ----------------"
	$(VERILATOR) --version
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module opl3 $(VERILATOR_INPUT)

	@echo
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vtop

	@echo
	@echo "-- COVERAGE ----------------"
	@rm -rf logs/annotated
	$(VERILATOR_COVERAGE) $(VERILATOR_COV_FLAGS)

	@echo
	@echo "-- DONE --------------------"


######################################################################
# Other targets

show-config:
	$(VERILATOR) -V

genhtml:
	@echo "-- GENHTML --------------------"
	@echo "-- Note not installed by default, so not in default rule"
	$(GENHTML) logs/coverage.info --output-directory logs/html

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd core
