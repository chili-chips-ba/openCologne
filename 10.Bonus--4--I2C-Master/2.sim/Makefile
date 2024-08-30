# Set the simulator
SIM           ?= icarus
WAVES         ?= 1        # Set this to 1 to enable wave traces dump for the Aldec Riviera-PRO, Mentor Graphics Questa, and Icarus Verilog simulators.
TOPLEVEL_LANG ?= verilog  # Language of the top-level module (verilog/vhdl) 


include $(shell cocotb-config --makefiles)/Makefile.sim # Include cocotb makefiles to handle simulator setup

# Set the default target for the Makefile
all: sim

# Source directories
SIM_SRC  = $(PWD)
HW_SRC   = ../1.hw
V_SRC    = $(HW_SRC)/verilog
SV_SRC   = $(HW_SRC)/systemverilog
SV2V_SRC = $(HW_SRC)/sv2v

# Verilog sources
#VERILOG_SOURCES += $(V_SRC)/i2c_ctrl.v
#VERILOG_SOURCES += $(V_SRC)/i2c_top.v
#VERILOG_SOURCES += $(V_SRC)/top.v

# SystemVerilog sources
VERILOG_SOURCES += $(SV_SRC)/i2c_ctrl.sv
VERILOG_SOURCES += $(SV_SRC)/i2c_top.sv
VERILOG_SOURCES += $(SV_SRC)/top.sv

# sv2v sources
#VERILOG_SOURCES += $(SV2V_SRC)/i2c_ctrl.v
#VERILOG_SOURCES += $(SV2V_SRC)/i2c_top.v
#VERILOG_SOURCES += $(SV2V_SRC)/top.v


VERILOG_SOURCES += /usr/local/share/yosys/gatemate/cells_sim.v

# Top-level module name
TOPLEVEL = top

# Python test module(s)
MODULE = i2c_tb

SIM_ARGS ?= 

# Define the clean target
.PHONY: clean
clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd

# Help target to describe the usage of the Makefile
.PHONY: help
help:
	@echo "Usage: make [target] [SIM=<simulator>]"
	@echo "Targets:"
	@echo "  all     - Build and run the simulation"
	@echo "  sim     - Run the simulation only"
	@echo "  clean   - Clean the simulation build and output files"
	@echo "  help    - Show this help message"
	@echo "Simulators Supported:"
	@echo "  iverilog - Icarus Verilog (default)"
	@echo "  vcs      - Synopsys VCS"
	@echo "  modelsim - Mentor Graphics ModelSim"
