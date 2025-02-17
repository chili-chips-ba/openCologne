#!/usr/bin/env bash

set -e

# Analyse sources
ghdl -a ../rtl/fpga_torture.vhd
ghdl -a fpga_torture_tb.vhd

# Elaborate top entity
ghdl -e fpga_torture_tb

# Run simulation
ghdl -e fpga_torture_tb
ghdl -r fpga_torture_tb --stop-time=1ms --vcd=fpga_torture.vcd
