#!/bin/bash

# Initialize the RTL_FILES array
RTL_FILES=()

# Function to print usage instructions
usage() {
    echo "Usage: $0 [-v | -sv | -sv2v]"
    echo "  -v     : Generate rtl.filelist with .v extensions"
    echo "  -sv    : Generate rtl.filelist with .sv extensions (default)"
    echo "  -sv2v  : Generate rtl.filelist with .sv extensions for sv2v"
    exit 1
}

echo "----------------------------------"
echo "Running create_rtl_filelist script"

# Determine the file extension based on the provided parameter
# If no parameter is provided, default to -sv

case "$1" in
    -v)
        EXT=".v"
        echo "Using extension: .v"
        ;;
    -sv | "")
        EXT=".sv"
        echo "Using extension: .sv"
        ;;
    -sv2v)
        EXT=".sv"
        echo "Using extension: .sv for sv2v"
        ;;
    *)
        usage
        ;;
esac

# Add the anomaly file which is always .v because there is no need to convert it to Verilog from SystemVerilog
RTL_FILES+=("modules/misc/src/afifo.v")

# Toolchain Directories and Executable Commands
BLD_DIR=$(pwd)
HW_SRC="$BLD_DIR/../1.hw"
SW_SRC="$BLD_DIR/../2.sw"

# Ensure the HW_SRC directory exists
if [ ! -d "$HW_SRC" ]; then
    echo "Directory $HW_SRC does not exist. Creating it..."
    mkdir -p "$HW_SRC"
fi

# Define the list of RTL files with the correct extensions
rtl_files=(
    "modules/top_level/pkg/opl3_pkg"
    "modules/clks/src/clk_div"
    "modules/clks/src/reset_sync"
    "modules/channels/src/dac_prep"
    "modules/i2s/src/i2s"
    "modules/misc/src/edge_detector"
    "modules/misc/src/mem_multi_bank"
    "modules/misc/src/pipeline_sr"
    "modules/misc/src/mem_simple_dual_port_async_read"
    "modules/host_if/src/host_if"
    "modules/misc/src/mem_multi_bank_reset"
    "modules/operator/src/operator"
    "modules/top_level/src/opl3"
    "modules/channels/src/channels"
    "modules/channels/src/control_operators"
    "modules/operator/src/calc_rhythm_phase"
    "modules/operator/src/phase_generator"
    "modules/operator/src/vibrato"
    "modules/operator/src/envelope_generator"
    "modules/operator/src/ksl_add_rom"
    "modules/operator/src/env_rate_counter"
    "modules/operator/src/tremolo"
    "modules/operator/src/opl3_log_sine_lut"
    "modules/operator/src/opl3_exp_lut"
    "modules/timers/src/timers"
    "modules/timers/src/timer"
    "modules/misc/src/synchronizer"
    "modules/misc/src/leds"
    "modules/host_if/src/trick_sw_detection"
    "modules/misc/src/mem_simple_dual_port"
    "modules/operator/src/calc_phase_inc"
)

# Add each file with the appropriate extension to the RTL_FILES array
for file in "${rtl_files[@]}"; do
    RTL_FILES+=("${file}${EXT}")
done

# Path to the rtl.filelist in 1.hw directory
RTL_FILELIST="$HW_SRC/rtl.filelist"

# Create or overwrite the rtl.filelist file
echo "Creating rtl.filelist with RTL files in $HW_SRC..."
> "$RTL_FILELIST"  # This truncates the file if it exists or creates a new one

# Add each file to rtl.filelist with the full path
for file in "${RTL_FILES[@]}"; do
    echo "$HW_SRC/$file" >> "$RTL_FILELIST"
done

echo "rtl.filelist created successfully in $HW_SRC using extension $EXT."
echo "Finished create_rtl_filelist script"
echo "-----------------------------------"

