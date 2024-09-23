# Include the general configuration file
include config.mk

SIM_DIR = $(CURDIR)
HW_SRC  := $(SIM_DIR)/../1.hw

# Verilog sources
VERILOG_SOURCES = $(HW_SRC)/top.v
VERILOG_SOURCES += $(HW_SRC)/PCM5102.v
VERILOG_SOURCES += $(HW_SRC)/sinewave_generator.v
VERILOG_SOURCES += $(HW_SRC)/sinewave_table.v

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

