#!/bin/bash

# Initialize RTL_FILES array
RTL_FILES=()

# Check for the parameter and set the file extensions accordingly
if [ "$1" == "-v" ]; then
    EXT=".v"
    RTL_FILES+=("modules/misc/src/afifo.v")
    echo "Using extension: .v"
elif [ "$1" == "-sv" ] || [ -z "$1" ]; then
    # Default to -sv if no parameter is provided
    EXT=".sv"
    RTL_FILES+=("modules/misc/src/afifo.v")
    echo "Using extension: .sv"
elif [ "$1" == "-sv2v" ]; then
    EXT=".sv"
    echo "Using extension: .sv for sv2v"
else
    echo "Invalid parameter. Use -v, -sv, or -sv2v."
    exit 1
fi

# Toolchain Directories and Executable Commands
BLD_DIR=$(pwd)  # Using `pwd` to get the current directory
HW_SRC="$BLD_DIR/../1.hw"
SW_SRC="$BLD_DIR/../2.sw"

# Ensure the HW_SRC directory exists
if [ ! -d "$HW_SRC" ]; then
    echo "Directory $HW_SRC does not exist. Creating it..."
    mkdir -p "$HW_SRC"
fi

# Define the list of RTL files with the correct extensions
RTL_FILES+=(
    "modules/top_level/pkg/opl3_pkg$EXT"
    "modules/clks/src/clk_div$EXT"
    "modules/clks/src/reset_sync$EXT"
    "modules/channels/src/dac_prep$EXT"
    "modules/i2s/src/i2s$EXT"
    "modules/misc/src/edge_detector$EXT"
    "modules/misc/src/mem_multi_bank$EXT"
    "modules/misc/src/pipeline_sr$EXT"
    "modules/misc/src/mem_simple_dual_port_async_read$EXT"
    "modules/host_if/src/host_if$EXT"
    "modules/misc/src/mem_multi_bank_reset$EXT"
    "modules/operator/src/operator$EXT"
    "modules/top_level/src/opl3$EXT"
    "modules/channels/src/channels$EXT"
    "modules/channels/src/control_operators$EXT"
    "modules/operator/src/calc_rhythm_phase$EXT"
    "modules/operator/src/phase_generator$EXT"
    "modules/operator/src/vibrato$EXT"
    "modules/operator/src/envelope_generator$EXT"
    "modules/operator/src/ksl_add_rom$EXT"
    "modules/operator/src/env_rate_counter$EXT"
    "modules/operator/src/tremolo$EXT"
    "modules/operator/src/opl3_log_sine_lut$EXT"
    "modules/operator/src/opl3_exp_lut$EXT"
    "modules/timers/src/timers$EXT"
    "modules/timers/src/timer$EXT"
    "modules/misc/src/synchronizer$EXT"
    "modules/misc/src/leds$EXT"
    "modules/host_if/src/trick_sw_detection$EXT"
    "modules/misc/src/mem_simple_dual_port$EXT"
    "modules/operator/src/calc_phase_inc$EXT"
)

# Path to the rtl.filelist in 1.hw directory
RTL_FILELIST="$HW_SRC/rtl.filelist"

# Create or overwrite the rtl.filelist file
echo "Creating rtl.filelist with RTL files in $HW_SRC..."
> "$RTL_FILELIST"

# Add each file to rtl.filelist with full path
for file in "${RTL_FILES[@]}"; do
    echo "$HW_SRC/$file" >> "$RTL_FILELIST"
done

echo "rtl.filelist created successfully in $HW_SRC using extension $EXT."

