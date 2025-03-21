# I2C Master

The I2C Master (aka "Controller") is taken from the [openEye-CamSI](https://github.com/chili-chips-ba/openeye-CamSI) project, with some modifications to fit the WM8960 Audio CODEC.

The I2C has two wires, one transmits the clock signal and the other the data signal. Both the wires need to be connected via a pullup resistor which value needs to be calculated. After calculation, the resistor `R` value should be 1kΩ.

![image](https://github.com/user-attachments/assets/43d528dd-e20f-4ad4-ae62-27448d62b9a0)


## WM860 Audio Codec I2C

![image](https://github.com/user-attachments/assets/387093c5-4f7c-4f13-b4ed-931a01ec0e1e)

The image is taken from the WM8960 official documentation and shows the 2-Wire Serial Control Interface needed to set the internal registers of the WM8960 Audio CODEC.


## I2C Controller and Top Module Design
This repository contains a design for an I2C controller, top module, and related components, including both SystemVerilog and Verilog files. 
The design files are organized into multiple folders: 
* `1.hw` has the RTL codes with the rtlfilelist and constraint files
* `2.sim` has the cocotb simulation files
* `3.build` contains useful scripts to generate the rtl.filelist and convert SystemVerilog code to Verilog, and the Makefile

The `1.hw` folder contains the following folder structure:
* `systemverilog/`: Contains SystemVerilog files for the I2C controller (i2c_ctrl.sv), I2C top module (i2c_top.sv), and the general top module (top.sv).
* `verilog/`: Contains Verilog files corresponding to the I2C controller (i2c_ctrl.v), I2C top module (i2c_top.v), and the general top module (top.v).
* `sv2v/`: Contains Verilog files converted from SystemVerilog using the sv2v tool. This folder is generated by the convert_sv2v.sh script.
* `constraints/`: Contains constraint files for the FPGA design.

### Workflow

#### Create the RTL File List:
To generate a file list of the RTL files for synthesis, run the `create_rtlfilelist.sh` script in the `3.build` folder with one of the following flags:
* -v: Generate rtl.filelist with Verilog (.v) files.
* -sv: Generate rtl.filelist with SystemVerilog (.sv) files (default).
* -sv2v: Generate rtl.filelist with SystemVerilog files for conversion to Verilog using sv2v.
```
./create_rtlfilelist.sh -<flag>
```
#### Convert SystemVerilog to Verilog (Optional):

If you want to convert SystemVerilog files to Verilog (e.g., for Yosys synthesis), run the `convert_sv2v.sh` script in the `3.build` folder. This will place the converted files into the sv2v folder:
```
./convert_sv2v.sh
```
### Simulate
To simulate run navigate to the `2.sim` folder and run `make`, after that you can run `gtkwave top_waves.vcd` or `surfer top_waves.vcd` to get the following waveforms:

![image (1)](https://github.com/user-attachments/assets/5c392aa2-a1e8-4c3b-b6af-163694ca50c3)

#### Synthesize, Implement, and Program:

Use the following make commands to synthesize, implement, and program the FPGA:
```
make synth_vlog
make impl
make jtag
```

## Notes

The SystemVerilog files use typedef, which is not yet fully supported in Yosys. If using Yosys, convert these files to Verilog using the sv2v tool.

Ensure that your rtl.filelist accurately reflects the files you intend to use in your design.

#### End of Document
