# Include the general configuration file
include ../config.mk

# Verilog sources
#VERILOG_SOURCES = hdl/systemverilog/lowpass.sv

# VHDL sources
VHDL_SOURCES = hdl/vhdl/lowpass.vhd

# Top-level module name
TOPLEVEL = lowpass

# Python test module(s)
MODULE = lowpass_tb

# Define the clean target
.PHONY: clean
clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd

# Targets for running the tests
.PHONY: test_vhdl
test_vhdl:
	@echo "Running VHDL test..."
	make SIM=questa TOPLEVEL_LANG=vhdl

.PHONY: test_sv
test_sv:
	@echo "Running SystemVerilog test..."
	make SIM=icarus TOPLEVEL_LANG=verilog
