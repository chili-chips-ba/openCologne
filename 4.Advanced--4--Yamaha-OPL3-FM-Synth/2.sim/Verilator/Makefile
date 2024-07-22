######################################################################
# Include Verilator Makefile
######################################################################

include verilator.mk

######################################################################
# Set up directories and tool root
######################################################################

VERILATOR_DIR = $(CURDIR)
SIM_DIR     = $(VERILATOR_DIR)/../
HW_SRC      = $(SIM_DIR)/../1.hw
SW_SRC      = $(SIM_DIR)/../2.sw
TOOL_ROOT   = /home/user/FPGA/tools

SYSTEM_INCLUDE = $(TOOL_ROOT)/systemc-2.3.3/include
SYSTEM_LIBDIR  = $(TOOL_ROOT)/systemc-2.3.3/lib-linux64

######################################################################
# Input files for Verilator
######################################################################

# List of SystemVerilog and Verilog input files for Verilator
VERILATOR_INPUT = $(shell cat $(HW_SRC)/rtl.filelist)

# Main Test Function for Verilator
VERILATOR_INPUT += sim_main.cpp

