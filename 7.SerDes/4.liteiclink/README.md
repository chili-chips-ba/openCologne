
## Workflow Overview
First, let’s dive into the 4.liteiclink folder and walk through its structure so you can see how each component fits together and how the overall build process comes together

### 2.sw

In the [2.sw](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/2.sw) is a modified version of the [LiteX Demo Application](https://github.com/enjoy-digital/litex/tree/master/litex/soc/software/demo) that will include generated csr from the migen targer file in the `main.c` function. There lie the control function for the datapath in bare-metal C.
The uart console is built upon the official demo application. 

### 3.build

Here in the [3.build]([https://github.com/chili-chips-ba/uberClock/tree/main/2.soc-litex/3.build](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/3.build)) folder we have the [Makefile](https://github.com/chili-chips-ba/openCologne/blob/main/7.SerDes/4.liteiclink/3.build/Makefile) that tries to ease the LiteX workflow into different parts. Running `make help` gives pretty self-exmplanatory commands:

```
$ make help
Usage:
  make open-target    file=<name>
  make open-example   file=<proj>
  make build-board    [FREQ=..] [OPTIONS='..']
  make load           [FREQ=..] [OPTIONS='..']
  make term                [PORT=..]
  make build-sw            [DEMO_FLAGS='..']
  make sim
  make view-sim
  make clean-sim
  make setup-ethernet      [ETH_IFACE=..] [STATIC_IP=..]
  make start-server
  make stop-server
  make litescope
  make clean
  make copy-migen
```

The most important ones are:

* `make build-board` which runs the build process using Vivado(later openXC7 will be used instead). The command has parameters `FREQ` and `OPTIONS` which can be overloaded, but running it without any parameters is going to include `--with-etherbone` and `--with-uberclock` with a frequency of `65MHz`.

* `make build-sw` which compiles the bare-metal C application. The imporant note to add is to run the command after the build finishes because the compiler depends of the generated files in the `3.build/build` folder.

* `make load` simply loads the bitstream onto the FPGA via the JTAG programmer
  
* `make term` opens up the serial console in the terminal to control the datapth signals. The default port is `/dev/ttyUSB0` while that can be simply changed with `PORT`.

**NOTE**: Run `make term` in a seperate terminal before running `make load`

### 4.migen
The [4.migen](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/4.migen) folder contains two subfolders:
* [liteiclink](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/4.migen/liteiclink/serdes) which has the file that should be copied in the liteiclink litex folder
* [litex_boards](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/4.migen/litex/litex-boards/litex_boards) which has:
  [platforms](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/4.migen/litex/litex-boards/litex_boards/platforms) which has the specific platform file that specifies the pins of the board
  [targets](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/4.liteiclink/4.migen/litex/litex-boards/litex_boards/targets) has the target file that specifies all of the important parts of the CPU design and instantiates the SoC.

**NOTE**: Right now you need to copy these subfolders with the files manually in your LiteX installation folder in `litex/litex_board/litex-boards`.
