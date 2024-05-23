#=============================================================
# Makefile for GateMate FPGA Projects
# Copyright (C) 2024 Chili.CHIPS*ba
#=============================================================

# Toolchain download and setup instructions:
# Download toolchain from: https://www.colognechip.com/programmable-logic/gatemate/gatemate-download/
# Extract archive and set CC_TOOL environment variable:
# export CC_TOOL=/path/to/cc-toolchain-linux

# Set EXE for platform-specific executable extensions, if necessary
EXE =

# Toolchain Directories and Executable Commands
CC_TOOL_DIR = $(CC_TOOL)
#YOSYS = $(CC_TOOL)/bin/yosys/yosys$(EXE)
YOSYS = /home/user/FPGA/tools/synlig/out/current/bin/yosys$(EXE)
PR = $(CC_TOOL)/bin/p_r/p_r$(EXE)
OFL = $(CC_TOOL)/bin/openFPGALoader/openFPGALoader$(EXE)

# Simulation Tools and Flags
GTKW = gtkwave
IVL = iverilog
VVP = vvp
IVLFLAGS = -Winfloop -g2012 -gspecify -Ttyp

# Source Directory
SRC = \
	modules/top_level/src/opl3.sv \
	modules/top_level/pkg/opl3_pkg.sv \
	modules/channels/src/dac_prep.sv \
	modules/channels/src/channels.sv \
	modules/channels/src/control_operators.sv \
	modules/clks/src/clk_div.sv \
	modules/clks/src/reset_sync.sv \
	modules/i2s/src/i2s.sv \
	modules/operator/src/operator.sv \
	modules/operator/src/calc_phase_inc.sv \
	modules/operator/src/calc_rhythm_phase.sv \
	modules/operator/src/phase_generator.sv \
	modules/operator/src/vibrato.sv \
	modules/operator/src/envelope_generator.sv \
	modules/operator/src/ksl_add_rom.sv \
	modules/operator/src/env_rate_counter.sv \
	modules/operator/src/tremolo.sv \
	modules/operator/src/opl3_log_sine_lut.sv \
	modules/operator/src/opl3_exp_lut.sv \
	modules/timers/src/timers.sv \
	modules/timers/src/timer.sv \
	modules/misc/src/afifo.v \
	modules/misc/src/edge_detector.sv \
	modules/misc/src/mem_simple_dual_port_async_read.sv \
	modules/misc/src/mem_simple_dual_port.sv \
	modules/misc/src/mem_multi_bank.sv \
	modules/misc/src/mem_multi_bank_reset.sv \
	modules/misc/src/pipeline_sr.sv \
	modules/misc/src/synchronizer.sv \
	modules/misc/src/leds.sv \
	modules/host_if/src/host_if.sv \
	modules/host_if/src/trick_sw_detection.sv 


SIM = \
	modules/top_level/sim/opl3_tb.sv \
	modules/operator/sim/save_dac_input.sv
	
PKG = modules/top_level/pkg/opl3_pkg.sv


# Simulation Libraries
CELLS_SYNTH = $(CC_TOOL)/bin/yosys/share/gatemate/cells_sim.v
CELLS_IMPL = $(CC_TOOL)/bin/p_r/cpelib.v

# Project Configuration
TOP = opl3# Define TOP MODULE here
CONSTR = constraints/blink.ccf
PRFLAGS += -ccf $blink.ccf -cCP
PLUGIN_PATH := /home/user/FPGA/tools/synlig/build/release/systemverilog-plugin/systemverilog.so

# Synthesize Sources
VLOG_SRC = $(shell find $(SRC) -type f \( -iname \*.v -o -iname \*.sv \))
VHDL_SRC = $(shell find $(SRC) -type f \( -iname \*.vhd -o -iname \*.vhdl \))

## misc tools
RM = rm -rf

## toolchain targets
synth: synth_vlog


synth_svlog: $(VLOG_SRC) $(PKG)
	@test -d log || mkdir -p log
	@test -d net || mkdir -p net
	$(YOSYS) -ql log/synth.log -p 'plugin -i $(PLUGIN_PATH); read_systemverilog $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'


synth_vlog: $(VLOG_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -sv $(PKG); read -sv $(VLOG_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

synth_vhdl: $(VHDL_SRC)
	@test -d log || mkdir log
	@test -d net || mkdir net
	$(YOSYS) -ql log/synth.log -p 'read -vhdl $(PKG); read -vhdl $(VHDL_SRC); synth_gatemate -top $(TOP) -nomx8 -vlog net/$(TOP)_synth.v'

impl:
	$(PR) -i net/$(TOP)_synth.v -o $(TOP) -ccf blink.ccf -cCP > log/$@.log

jtag:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag $(TOP)_00.cfg

jtag-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_jtag -f --verify $(TOP)_00.cfg

spi:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -m $(TOP)_00.cfg

spi-flash:
	$(OFL) $(OFLFLAGS) -b gatemate_evb_spi -f --verify $(TOP)_00.cfg

all: synth impl jtag

## verilog simulation targets
vlog_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(VLOG_SRC) $(SIM)/$(TOP)_tb.v

synth_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ net/$(TOP)_synth.v $(SIM)/$(TOP)_tb.v $(CELLS_SYNTH)

impl_sim.vvp:
	$(IVL) $(IVLFLAGS) -o $(SIM)/$@ $(TOP)_00.v $(SIM)/$(TOP)_tb.v $(CELLS_IMPL)

.PHONY: %sim %sim.vvp
%sim: %sim.vvp
	$(VVP) -N $(SIM)/$< -fst
	@$(RM) $(SIM)/$^

wave:
	$(GTKW) $(SIM)/$(TOP)_tb.vcd $(SIM)/config.gtkw

clean:
	$(RM) log/*.log
	$(RM) net/*_synth.v
	$(RM) *.history
	$(RM) *.txt
	$(RM) *.refwire
	$(RM) *.refparam
	$(RM) *.refcomp
	$(RM) *.pos
	$(RM) *.pathes
	$(RM) *.path_struc
	$(RM) *.net
	$(RM) *.id
	$(RM) *.prn
	$(RM) *_00.v
	$(RM) *.used
	$(RM) *.sdf
	$(RM) *.place
	$(RM) *.pin
	$(RM) *.cfg*
	$(RM) *.cdf
	$(RM) $(SIM)/*.vcd
	$(RM) $(SIM)/*.vvp
	$(RM) $(SIM)/*.gtkw
	test ! -d log || rmdir log
	test ! -d net || rmdir net
#=============================================================
# End-of-File
#=============================================================

