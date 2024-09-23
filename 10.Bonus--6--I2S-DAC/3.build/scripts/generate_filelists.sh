#!/bin/bash

# Define the path to the 1.hw directory (relative to the script location)
HW_DIR="../../../1.hw"
OUTPUT_DIR="$HW_DIR/filelists"
OUTPUT_FILE="$OUTPUT_DIR/rtl_verilog.filelist"

# Create the filelists directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Check if the HW_DIR exists
if [ ! -d "$HW_DIR" ]; then
  echo "Error: $HW_DIR does not exist."
  exit 1
fi

# Find all .v and .sv files in 1.hw, get absolute paths, and output them into rtl_verilog.filelist
find "$HW_DIR" -type f \( -name "*.v" -o -name "*.sv" \) -exec readlink -f {} \; > "$OUTPUT_FILE"

# Provide feedback to the user
echo "Verilog and SystemVerilog file list generated: $OUTPUT_FILE"

