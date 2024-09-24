# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Due to the CologneChips GateMate having a scarce number of GPIO pins, here is provided and tested a 1-Wire controller, plug-and-play into a ready-valid SoC bus. 
## The Design
The used 1-Wire controller is based on the jeras' [implementation](https://github.com/jeras/sockit_owm), supporting single slave configuration, doing it barebones, as opposed to a full 1-Wire slave bus with custom 64-bit ROM codes. This simplification is justified by the intended use case of this 1-Wire controller, usually interfacing with a single sensor. 
<!-- 
The testing platform is 2 FPGAs, one being a 1-Wire master device, the other slave. Both have UART TXs integrated in them and send a hard-coded message or read to one another. The messages are then read on the respective UARTs as sent or received. -->

<!-- The master device (CCGM1A1) sends if nothing is pressed and receives if the button is pressed.  -->
## Build steps
To get the design synthesized and run PnR:
```
cd 3.build
make hw_all
```

## Simulation steps
Change directory to the 2.sim:
```
cd 2.sim
```
Then the following options are avaliable, all run in **Verilator**:
- `make`  to run RTL simulation
- `make all_synth` to run post-synthesis simulation
- `make all_impl` to run post-PnR simulation

**iverilog** is too supported as a simulator:
- `make vlog_sim` - RTL sim
- `make synth_sim`- post-synthesis simulation
- `make impl_sim`- post-PnR simulation

Also provided are `make wave`, `make wave_iverilog` and `make clean`, `make clean_iverilog` targets which run the waveform viewer and clean the output files of simulation runs.
T
**<h3>  End of Document </h3>** 


[def]: drawing.svg