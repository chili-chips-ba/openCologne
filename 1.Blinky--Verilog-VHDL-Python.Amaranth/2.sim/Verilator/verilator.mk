######################################################################
# DESCRIPTION: Make Verilator model and run
#
# This calls the object directory makefile.  That allows the objects to
# be placed in the "current directory" which simplifies the Makefile.
#
# This file is placed under the Creative Commons Public Domain, for
# any use, without warranty, 2020 by Wilson Snyder.
# SPDX-License-Identifier: CC0-1.0
######################################################################

ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

# This example started with the Verilator example files.
# Please see those examples for commented sources, here:
# https://github.com/verilator/verilator/tree/master/examples

######################################################################
# Set up variables

# Determine Verilator binary location
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

# Verilator flags
VERILATOR_FLAGS = -cc --exe \
                  --x-assign 0 \
                  -Wall \
                  --assert \
                  --build -j \
                  --timescale 1ns/1ps \
                  -Wno-UNOPTFLAT \
                  -Wno-CASEINCOMPLETE \
                  -Wno-UNDRIVEN \
                  -Wno-VARHIDDEN \
                  -Wno-IMPORTSTAR \
                  -Wno-REALCVT \
                  -Wno-UNUSED \
                  -Wno-
                  -CFLAGS "-I$(SYSTEM_INCLUDE) -DVL_TIME_CONTEXT" \
                  -LDFLAGS "-L$(SYSTEM_LIBDIR) -lsystemc"
# Additional options
# VERILATOR_FLAGS += -MMD
# VERILATOR_FLAGS += --trace
# VERILATOR_FLAGS += --debug
# VERILATOR_FLAGS += --gdbbt

######################################################################
# Default target

default: run

######################################################################
# Run Verilator

run:
	@echo
	@echo "-- Verilator example"

	@echo
	@echo "-- VERILATE ----------------"
	$(VERILATOR) --version
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module blink $(VERILATOR_INPUT)

	@echo
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vblink

	@echo
	@echo "-- DONE --------------------"

######################################################################
# Other targets

show-config:
	$(VERILATOR) -V

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd core

