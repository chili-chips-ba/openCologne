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

**Note**: Make sure to uncomment and adapt this line "export CC_TOOL="/path/to/cc-toolchain-linux"" in makefile of your project.

## Synthesis
To run synthesis for the Verilog file, use the following command:

`make synth_vlog`

## Simulation

For post-synthesis simulation, you'll need a third-party simulator and a waveform viewer such as [Icarus Verilog](https://steveicarus.github.io/iverilog/usage/installation.html) and [GTKWave](https://gtkwave.sourceforge.net/).

To run the post-synthesis simulation, use:

`make synth_sim`

Then, to view the waveform in the third-party simulator, use:

`make wave`

**Note**: For this example, for the simulation, the simplified `CC_PLL` module from the `blink_tb.v` file needs to be present.
## Place & Route
The Cologne Chip Place & Route tool loads the Verilog netlist from the net directory. Constraints for pin assignments or CPE pre-placement are set with the CCF file in the src directory.

To run the implementation, use:

`make impl`
## Post-Synthesis Simulation

`make impl_sim`

The resulting VCD file can be opened with any waveform viewer:

`make wave`

**Note** For this example, for the post-synthesis simulation, the simplified `CC_PLL` module from the `blink_tb.v` file needs to be removed or commented out.


## Programming the Board
### Linux
It is important to use the latest version of openFPGALoader as specified above. If you specify in the makefile your path to the latest openFPGALoader in the variable `OFL` you can program the board by running the following command:
`make jtag`

The above command is just running the command below:

`openFPGALoader -b gatemate_evb_jtag --cable dirtyJtag --bitstream blink_00.cfg.bit`
### WSL
Since WSL does not natively see physical ports, it is necessary to use the usbipd tool.

Go to the [latest](https://github.com/dorssel/usbipd-win/releases) release page for the usbipd-win project.
Select the .msi file, which will download the installer.
Run the downloaded usbipd-win_x.msi installer file.

After installing usbipd, connect your board to the USB port. List all of the USB devices connected to Windows by opening PowerShell in administrator mode and entering the following command:

`PS> usbipd list`

If everything is correct, you should see the following output:

`PS> <busid>    1209:c0ca  DirtyJTAG      Not shared`

Before attaching USB device, the usbipd bind command must be used to share the device, allowing it to be attached to WSL:

`PS> usbipd bind --busid <busid>`

After running the command, verify that the device is shared using the usbipd list command again:

`PS> usbipd list`

Ensure that a WSL command prompt is open to keep the WSL 2 lightweight VM active. To attach the USB device, run the following command:

`PS> usbipd attach --wsl --busid <busid>`

Open WSL and list the attached USB devices using the command:

`$ lsusb`

If everything is correct, you should see the following output:

`$ Bus 00y Device 00x: ID 1209:c0ca Generic Jean THOMAS DirtyJTAG`

Changing the permissions of a USB device file to 666 (read and write for everyone) can be necessary in situations where a non-root user needs to access the USB device directly. Use the following command:

`$ sudo chmod 666 /dev/bus/usb/00x`

Finally, to program the board, you can use:

`$ sudo openFPGALoader -b gatemate_evb_jtag --cable dirtyJtag --bitstream blink_00.cfg.bit`

**<h3>  End of Document </h3>** 
