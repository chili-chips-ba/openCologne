# Include the general configuration file
include config.mk

SIM_DIR =  $(CURDIR)/..
HW_SRC  := $(SIM_DIR)/../1.hw
SW_SRC  := $(SIM_DIR)/../2.sw

# Verilog sources
VERILOG_SOURCES = \
    $(HW_SRC)/modules/top_level/pkg/opl3_pkg.sv \
    $(HW_SRC)/modules/misc/src/afifo.v \
    $(HW_SRC)/modules/clks/src/clk_div.sv \
    $(HW_SRC)/modules/clks/src/reset_sync.sv \
    $(HW_SRC)/modules/channels/src/dac_prep.sv \
    $(HW_SRC)/modules/i2s/src/i2s.sv \
    $(HW_SRC)/modules/misc/src/edge_detector.sv \
    $(HW_SRC)/modules/misc/src/mem_multi_bank.sv \
    $(HW_SRC)/modules/misc/src/pipeline_sr.v \
    $(HW_SRC)/modules/misc/src/mem_simple_dual_port_async_read.sv \
    $(HW_SRC)/modules/host_if/src/host_if.sv \
    $(HW_SRC)/modules/misc/src/mem_multi_bank_reset.sv \
    $(HW_SRC)/modules/operator/src/operator.sv \
    $(HW_SRC)/modules/top_level/src/opl3.sv \
    $(HW_SRC)/modules/channels/src/channels.sv \
    $(HW_SRC)/modules/channels/src/control_operators.v \
    $(HW_SRC)/modules/operator/src/calc_rhythm_phase.sv \
    $(HW_SRC)/modules/operator/src/phase_generator.sv \
    $(HW_SRC)/modules/operator/src/vibrato.sv \
    $(HW_SRC)/modules/operator/src/envelope_generator.sv \
    $(HW_SRC)/modules/operator/src/ksl_add_rom.sv \
    $(HW_SRC)/modules/operator/src/env_rate_counter.sv \
    $(HW_SRC)/modules/operator/src/tremolo.sv \
    $(HW_SRC)/modules/operator/src/opl3_log_sine_lut.sv \
    $(HW_SRC)/modules/operator/src/opl3_exp_lut.sv \
    $(HW_SRC)/modules/timers/src/timers.sv \
    $(HW_SRC)/modules/timers/src/timer.sv \
    $(HW_SRC)/modules/misc/src/synchronizer.sv \
    $(HW_SRC)/modules/misc/src/leds.sv \
    $(HW_SRC)/modules/host_if/src/trick_sw_detection.sv \
    $(HW_SRC)/modules/misc/src/mem_simple_dual_port.sv \
    $(HW_SRC)/modules/operator/src/calc_phase_inc.sv \



# Top-level module name
TOPLEVEL = opl3

# Python test module(s)
MODULE = OPL3_tb

# Define the clean target
.PHONY: clean
clean::
	$(RM) -r __pycache__
	$(RM) -r sim_build
	$(RM) results.xml
	$(RM) *.vcd
