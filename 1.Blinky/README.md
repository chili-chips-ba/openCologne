# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

# Project Setup and Usage

This tutorial is intended for Linux OS.
## Toolchain Setup
1. Download the correct toolchain for the GateMate FPGA Board from one of the following links:
* [Windows Toolchain](https://colognechip.com/downloads/cc-toolchain-win.zip)
* [Linux Toolchain](https://colognechip.com/downloads/cc-toolchain-linux.zip)
2. Unzip the downloaded file and export the location to your terminal or bashrc script with the command:

`export CC_TOOL=/path/to/cc-toolchain-linux`

## openFPGALoader Installation

Install the latest version of openFPGALoader from [here](https://trabucayre.github.io/openFPGALoader/guide/install.html). **Note**: Using the toolchain version will result in errors.

## Directory Structure

Ensure you are in the desired project directory where all configuration files and the makefile are located in the 3.build directory.

## Synthesis
To run synthesis for the Verilog file, use the following command:

`make synth_vlog`

## Simulation

For post-synthesis simulation, you'll need a third-party simulator and a waveform viewer such as Icarus Verilog and GTKWave.

To run the post-synthesis simulation, use:

`make synth_sim`

Then, to view the waveform in the third-party simulator, use:

`make wave`

## Place & Route
The Cologne Chip Place & Route tool loads the Verilog netlist from the net directory. Constraints for pin assignments or CPE pre-placement are set with the CCF file in the src directory.

To run the implementation, use:

`make_impl`
## Post-Synthesis Simulation

`make impl_sim`

The resulting VCD file can be opened with any waveform viewer:

`make wave`

## Programming the Board
To program the board, use the following command:

`openFPGALoader -b gatemate_evb_jtag --cable dirtyJtag --bitstream blink_00.cfg.bit`

**<h3>  End of Document </h3>** 
