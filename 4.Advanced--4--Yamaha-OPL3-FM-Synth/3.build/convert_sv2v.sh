#!/bin/bash

# Define the source directory
TOOL_ROOT="/home/user/FPGA/tools"
BLD_DIR=$(pwd)
HW_SRC="$BLD_DIR/../1.hw"

# Call create_rtl_filelist.sh with -sv parameter
./create_rtl_filelist.sh -sv

# Define the list of files
SRC=$(cat "$HW_SRC/rtl.filelist")

# Convert all files together and write the outputs adjacent to their respective sources
sv2v --write=adjacent $SRC

echo "Conversion completed. Converted files are located adjacent to their respective source files."

