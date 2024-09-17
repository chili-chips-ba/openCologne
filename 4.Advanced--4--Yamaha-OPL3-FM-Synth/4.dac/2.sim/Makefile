# Include the general configuration file
include config.mk

SIM_DIR =  $(CURDIR)
HW_SRC  := $(SIM_DIR)/../1.hw
SW_SRC  := $(SIM_DIR)/../2.sw

# Verilog sources
VERILOG_SOURCES = $(HW_SRC)/top.v

# Top-level module name
TOPLEVEL = top

# Python test module(s)
MODULE = dac_tb

# Define the clean target
.PHONY: clean
clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd
