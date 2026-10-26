#!/bin/bash

# Define constants for directory paths
TOOL_ROOT="/home/user/FPGA/tools"
BLD_DIR=$(pwd)
HW_SRC="$BLD_DIR/../1.hw"
SV2V_DIR="$HW_SRC/sv2v" # Directory for converted Verilog files

# Function to create RTL file list with -sv parameter
create_rtl_filelist() {
    ./create_rtl_filelist.sh -sv
}

# Function to filter out Verilog files from the list
filter_verilog_files() {
    local src_list="$1"
    echo "$src_list" | grep -vE "\.v$"
}

# Function to convert SystemVerilog files to Verilog using sv2v
convert_sv2v() {
    local filtered_src="$1"
    mkdir -p "$SV2V_DIR" # Ensure the sv2v directory exists
    for file in $filtered_src; do
        base_name=$(basename "$file" .sv)
        sv2v "$file" > "$SV2V_DIR/${base_name}.v" # Save converted Verilog file to sv2v directory
    done
}

# Main script execution
main() {

    echo "-----------------------------------"
    echo "Running convert_sv2v script"
    echo "First create rtl_filelist with .sv extensions because of sv2v function"
    # Create RTL file list
    create_rtl_filelist

    # Read the list of files
    local src=$(cat "$HW_SRC/rtl.filelist")

    # Filter out Verilog files
    local filtered_src=$(filter_verilog_files "$src")

    # Convert SystemVerilog files to Verilog
    convert_sv2v "$filtered_src"

    echo "Conversion completed. Converted files are located in the sv2v directory."
    echo "Finished convert_sv2v script"
    echo "-----------------------------------"
}

# Run the main function
main

