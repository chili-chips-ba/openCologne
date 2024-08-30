#!/bin/bash

# Initialize the RTL_FILES array
RTL_FILES=()

# Function to print usage instructions
usage() {
    echo "Usage: $0 [-v | -sv | -sv2v]"
    echo "  -v     : Generate rtl.filelist with .v extensions from verilog directory"
    echo "  -sv    : Generate rtl.filelist with .sv extensions from systemverilog directory (default)"
    echo "  -sv2v  : Generate rtl.filelist with .sv extensions for sv2v conversion"
    exit 1
}

echo "----------------------------------"
echo "Running create_rtl_filelist script"

# Determine the file extension and directory based on the provided parameter
# If no parameter is provided, default to -sv
case "$1" in
    -v)
        EXT=".v"
        DIR="verilog"
        echo "Using extension: .v from verilog directory"
        ;;
    -sv | "")
        EXT=".sv"
        DIR="systemverilog"
        echo "Using extension: .sv from systemverilog directory"
        ;;
    -sv2v)
        EXT=".v"
        DIR="sv2v"
        echo "Using extension: .sv for sv2v conversion from sv2v directory"
        ;;
    *)
        usage
        ;;
esac

# Toolchain Directories and Executable Commands
BLD_DIR=$(pwd)
HW_SRC="$BLD_DIR/../1.hw"
SRC_DIR="$HW_SRC/$DIR"  # Subdirectory for verilog, systemverilog, or sv2v

# Ensure the HW_SRC directory and the specific directory exist
if [ ! -d "$SRC_DIR" ]; then
    echo "Directory $SRC_DIR does not exist. Creating it..."
    mkdir -p "$SRC_DIR"
fi

# Define the list of RTL files with the correct extensions
rtl_files=(
    "top"
    "i2c_top"
    "i2c_ctrl"
)

# Add each file with the appropriate extension to the RTL_FILES array
for file in "${rtl_files[@]}"; do
    RTL_FILES+=("${file}${EXT}")
done

# Path to the rtl.filelist in 1.hw directory
RTL_FILELIST="$HW_SRC/rtl.filelist"

# Create or overwrite the rtl.filelist file
echo "Creating rtl.filelist with RTL files in $SRC_DIR..."
> "$RTL_FILELIST"  # This truncates the file if it exists or creates a new one

# Add each file to rtl.filelist with the full path
for file in "${RTL_FILES[@]}"; do
    echo "$SRC_DIR/$file" >> "$RTL_FILELIST"
done

echo "rtl.filelist created successfully in $SRC_DIR using extension $EXT."
echo "Finished create_rtl_filelist script"
echo "-----------------------------------"

