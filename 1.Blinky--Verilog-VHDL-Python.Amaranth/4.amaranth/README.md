# GateMate Support for Amaranth

To install GateMate support for Amaranth, you need to install the contents from the forked repositories linked in the submodules in `4.amaranth`. Alternatively, you can visit the links provided here for [amaranth](https://github.com/TarikHamedovic/amaranth) and [amaranth-boards](https://github.com/TarikHamedovic/amaranth-boards).

## Installation Steps

### Install Amaranth
```
git clone https://github.com/TarikHamedovic/amaranth
cd amaranth
pip install --editable .[builtin-yosys]
```
### Install Amaranth-Boards
```
git clone https://github.com/TarikHamedovic/amaranth-boards.git
cd amaranth-boards
pip install --editable .[builtin-yosys]
```

If you already have a working Amaranth installation, you can copy-paste the following files into your respective folders:

* `amaranth-boards/amaranth_boards/gatemate_a1_evb.py`
* `amaranth/amaranth/vendor/__init__.py`
* `amaranth/amaranth/vendor/_gatemate.py`

## Examples
Navigate to the `examples/` folder to run the examples.
### Blinky Example
1. Navigate to the `Blinky/` folder.
2. To see the commands for the Blinky example on the Olimex GateMateA1-EVB Board, run:
```
python3 Blinky.py -h
usage: Blinky.py [-h] [-s] [-b] [-v] [-p PLATFORM] [-n NUM_LEDS]
                 [-cd CLOCK_DIVIDER] [-cf CLOCK_FREQUENCY] [-rt RUNTIME] [-c]
                 [-dp] [-gw]

options:
  -h, --help            show this help message and exit
  -s, --simulate        Simulate Blinky Example
  -b, --build           Build The Blinky Example
  -v, --verilog         Generate Verilog for Blinky Example
  -p PLATFORM, --platform PLATFORM
                        Platform module (e.g.,
                        amaranth_boards.ulx3s.ULX3S_85F_Platform)
  -n NUM_LEDS, --num-leds NUM_LEDS
                        Number of LEDs
  -cd CLOCK_DIVIDER, --clock-divider CLOCK_DIVIDER
                        Clock divider (bit width of the counter)
  -cf CLOCK_FREQUENCY, --clock-frequency CLOCK_FREQUENCY
                        Clock frequency in MHz
  -rt RUNTIME, --runtime RUNTIME
                        Testbench runtime in clock cycles
  -c, --clean           Clean generated files and build directory
  -dp, --do-program     Program the device after building
```
3. To program the board, run:
```
python3 Blinky.py -b -p amaranth_boards.gatemate_a1_evb.GateMate_A1_EVB -dp
```
### UART Example

This is a simple UART Receiver Example. (Transmitter is work in progress).

1. Navigate to the `Uart/` folder.
2. To see the commands for the UART example on the Olimex GateMateA1-EVB Board, run:
```
python3 top_rx.py -h
usage: top_rx.py [-h] [-cpb CLKS_PER_BIT] [-cf CLOCK_FREQUENCY] [-s] [-gw] [-b] [-dp] [-v] [-p PLATFORM] [-rt RUNTIME] [-c]

options:
  -h, --help            show this help message and exit
  -cpb CLKS_PER_BIT, --clks-per-bit CLKS_PER_BIT
                        Clocks per bit
  -cf CLOCK_FREQUENCY, --clock-frequency CLOCK_FREQUENCY
                        Clock frequency in MHz for simulation
  -s, --simulate        Simulate Blinky Example
  -gw, --gtkwave        Open GTKWave after simulation
  -b, --build           Build The Blinky Example
  -dp, --do-program     Program the device after building
  -v, --verilog         Generate Verilog for Blinky Example
  -p PLATFORM, --platform PLATFORM
                        Platform module (e.g., amaranth_boards.ulx3s.ULX3S_85F_Platform)
  -rt RUNTIME, --runtime RUNTIME
                        Testbench runtime in clock cycles
  -c, --clean           Clean generated files and build directory
```
3. To program the board, run:
```
python3 top_rx.py -b -p amaranth_boards.gatemate_a1_evb.GateMate_A1_EVB -dp
```
