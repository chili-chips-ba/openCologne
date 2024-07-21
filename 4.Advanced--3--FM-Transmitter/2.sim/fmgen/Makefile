# Include the general configuration file
include ../config.mk

# Verilog sources
VERILOG_SOURCES = hdl/systemverilog/fmgen.sv

# VHDL sources
VHDL_SOURCES = hdl/vhdl/fmgen.vhd

# Top-level module name
TOPLEVEL = fmgen

# Python test module(s)
MODULE = fmgen_tb

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
	make SIM=ghdl TOPLEVEL_LANG=vhdl

.PHONY: test_sv
test_sv:
	@echo "Running SystemVerilog test..."
	make SIM=icarus TOPLEVEL_LANG=verilog

