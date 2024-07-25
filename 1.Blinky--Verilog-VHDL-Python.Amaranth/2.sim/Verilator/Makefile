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


######################################################################
# Input files for Verilator
######################################################################

VERILATOR_INPUT = $(wildcard $(HW_SRC)/*.v $(HW_SRC)/*.sv)

# Main Test Function for Verilator
VERILATOR_INPUT += sim_main.cpp

