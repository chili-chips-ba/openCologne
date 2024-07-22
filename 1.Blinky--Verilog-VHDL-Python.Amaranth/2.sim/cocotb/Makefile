# Include the general configuration file
include config.mk

COCOTB_DIR = $(CURDIR)
SIM_DIR =  $(COCOTB_DIR)/../
HW_SRC  := $(SIM_DIR)/../1.hw

# Verilog sources
VERILOG_SOURCES = $(HW_SRC)/blink.v

# Top-level module name
TOPLEVEL = blink

# Python test module(s)
MODULE = blink_tb

# Define the clean target
.PHONY: clean
clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd
