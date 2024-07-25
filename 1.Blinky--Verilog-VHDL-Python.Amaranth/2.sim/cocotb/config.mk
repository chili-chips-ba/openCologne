# General Configuration for Cocotb-based Testbenches

# Simulator configuration
SIM ?= icarus          # Selects which simulator Makefile to use. Attempts to include a simulator specific makefile from cocotb/share/makefiles/simulators/makefile.$(SIM)
WAVES ?= 1             # Set this to 1 to enable wave traces dump for the Aldec Riviera-PRO, Mentor Graphics Questa, and Icarus Verilog simulators. To get wave traces in Verilator see Waveforms.

# Used to inform the makefile scripts which HDL language the top-level design element is written in. Currently it supports the values verilog for Verilog or SystemVerilog tops, and vhdl for VHDL tops. This is used by simulators that support more than one interface (VPI, VHPI, or FLI) to select the appropriate interface to start cocotb.
TOPLEVEL_LANG ?= verilog  # Language of the top-level module (verilog/vhdl) 

# Optional: Specify individual test cases (comma-separated)
# TESTCASE = 

# Any arguments or flags to pass to the compile stage of the simulation.
# COMPILE_ARGS

# SIM_ARGS
# Any arguments or flags to pass to the execution of the compiled simulation.

# Results file
# COCOTB_RESULTS_FILE = results.xml  # Default is results.xml

# Enable coverage reporting
# COVERAGE = 1  # Uncomment to enable Python and HDL coverage reporting

# Drop into pdb on exception
# COCOTB_PDB_ON_EXCEPTION = 1  # Uncomment to enable

# Enable additional scheduler debug output
# COCOTB_SCHEDULER_DEBUG = 1  # Uncomment to enable

# Additional cocotb options

# Reduced log format (default: 1)
COCOTB_REDUCED_LOG_FMT = 0

# Pause to attach debugger (specify time in seconds)
# COCOTB_ATTACH = 

# Enable profiling (output to test_profile.pstat)
# COCOTB_ENABLE_PROFILING = 1

# HTTP port for memory usage debugging
# MEMCHECK = 8088  # Uncomment and set port

# Python library path (automatically determined)
# COCOTB_LIBPYTHON = $(shell cocotb-config --libpython)

# Default logging level (default: INFO)
COCOTB_LOG_LEVEL = INFO

# Resolve X, Z, U, W bits during conversion (default: VALUE_ERROR)
COCOTB_RESOLVE_X = VALUE_ERROR

# GPI_EXTRA
# A comma-separated list of extra libraries that are dynamically loaded at runtime.

# PyGPI(PyGPI is an experimental feature and subject to change.)
# The Python module and callable that starts up the Python cosimulation environment.

# Set this to 1 to enable the GUI mode in the simulator (if supported).
# GUI = 1

# Explicitly sets the simulator interface to use when TOPLEVEL_LANG is vhdl. This includes the initial GPI interface loaded, and GPI_EXTRA library loaded in mixed language simulations. Valid values are vpi, vhpi, or fli. 
# VHDL_GPI_INTERFACE = 

# Include cocotb makefiles to handle simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim

