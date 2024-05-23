# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Your description goes here
## SystemVerilog Plug-in installation

For SystemVerilog synthesis with yosys the [synlig plugin](https://github.com/chipsalliance/synlig) is needed.
The easiest and secure way to install the plugin is explained below.
### Install dependencies
```
sudo apt install -y gcc-11 g++-11 build-essential cmake tclsh ant default-jre swig google-perftools libgoogle-perftools-dev python3 python3-dev python3-pip uuid uuid-dev tcl-dev flex libfl-dev git pkg-config libreadline-dev bison libffi-dev wget python3-orderedmultidict
```

### Build required binaries
You can build all required binaries using the provided Makefile. make install will build Surelog, Yosys and Synlig, and place them in the out directory. You need to add out/bin to your PATH variable to ensure you are using correct versions of the binaries.

```
git clone https://github.com/chipsalliance/synlig.git
cd synlig
git submodule sync
git submodule update --init --recursive third_party/{surelog,yosys}
make install 
```
To use Yosys built from a submodule, make sure to either use absolute paths, or update the PATH variable before use.
```
export PATH=`pwd`/out/current/bin:$PATH
```

It is needed to export or place into the Makefile your path to the systemverilog.so file which is
```
PLUGIN_PATH= 'pwd'/build/release/systemverilog-plugin/systemverilog.so
```
And the same for yosys
```
YOSYS = 'pwd'/out/current/bin/yosys$(EXE)
```


Based on:
   https://github.com/gtaylormb/opl3_fpga

With audio extension HW:
   https://github.com/goran-mahovlic/ulx3s-extensions
   https://www.waveshare.com/wm8960-audio-board.htm
   
Also see software emulators of OPL3:
   https://github.com/Wohlstand/libADLMIDI
   https://github.com/nukeykt/Nuked-OPL3
   
**<h3>  End of Document </h3>** 
