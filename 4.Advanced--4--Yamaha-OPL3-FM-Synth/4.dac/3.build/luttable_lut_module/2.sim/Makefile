# Include the general configuration file
include config.mk


# Verilog sources
#VERILOG_SOURCES += ../1.hw/sinewave_generator.v
#VERILOG_SOURCES += ../1.hw/sinewave_table.v
VERILOG_SOURCES += ../1.hw/sinewave_generator.sv
VERILOG_SOURCES += ../1.hw/sinewave_table.sv                  

# VHDL sources (if any)
VHDL_SOURCES = 

# Top-level module name
TOPLEVEL = sinewave_generator

# Python test module(s)
MODULE = sinewave_generator_tb

# Define the clean target
.PHONY: clean

clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd
