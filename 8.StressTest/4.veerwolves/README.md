# Veerwolves - daisy chain Veerwolf core SoCs
## * WORK IN PROGRESS * UNDER CONSTRUCTION * KNOWN ISSUES!!!!!!!
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

This work was inspired by the Intel [whitepaper](https://cdrdv2-public.intel.com/833305/comparing-the-real-world-capacity-of-agilex-5-fpgas-whitepaper.pdf) comparing Intel Agilex 5 series to Lattice Avant-E, addressing true logic capacity of these FPGA families. In particular, it investigates how Cologne Chip's GateMate handles larger cores and explores the maximum number of these that can be integrated into a daisy chain configuration. Given that a 222k LUT6 FPGA can accommodate roughly 18 cores, successfully fitting even one or two cores would be considered a considerable achievement.

## Testing strategy
We'll quickly explain the benchmark setup and what it aims to achieve, for a more detailed explanation please refer to this  [whitepaper](https://cdrdv2-public.intel.com/833305/comparing-the-real-world-capacity-of-agilex-5-fpgas-whitepaper.pdf). This test realizes a daisy-chain serial SoC connection via UART (as shown in the figure below), with the maximum number of SoCs instantiated being the output metric.

Unlike Corescore, this design features a more homogenous logic mapping (Corescore was just a lot of independent cores feeding into a wide mux). Each SoC incorporates several interconnect conversions—primarily from AXI to WB and back—which are confined locally due to the daisy chain configuration. This setup exemplifies the FPGA’s short-wiring capabilities and raises questions about how densely the logic can be packed and what impact this may have on timing performance.

![SOC](0.doc/veerwolf-chain.png)


The VeeR EL2 CPU serves as the core of the SoC and integrates the previously described AXI and WB conversions. This RV32IMC-compliant RISC-V core, complete with a branch predictor, represents the first instance of the CCGM1A1 handling multiplication and implementing a more complex architecture. The figure below illustrates the CPU design.

![veerwolves](0.doc/veerwolf_core.png) 
## Build steps
FuseSoC is again the framework for generating an arbitrary number of cores. Add FuseSoC libraries after entering this folder:
```
cd 4.veerwolves
fusesoc library add veerwolf ./
fusesoc library add fusesoc-cores ./fusesoc_libraries/fusesoc-cores
```
Generating the bitstream for CologneChip is done by running:
```
fusesoc run --target=gatemate_pack veerwolf
```


## Results and analysis
Due to known issues with the current implementation, no results have been obtained to date.