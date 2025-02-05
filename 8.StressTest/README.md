# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

<!-- Assess Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits. -->

This part is dedicated to assessing the performance (Fmax) and realistic utilization of the Cologne Chip GateMate A1 FPGA by injecting routing congestion and pushing its clock distribution network to the limit.

## Notable Architectural Features

CologneChip's CCGM1A1 employs a peculiar architecture for implementing combinatorial logic, while its routing network remains mostly standard with a few twists. Notably, the FPGA does not implement distributed RAM as an integrated primitive but rather emulates it using flip-flops. This unusual characteristic motivated us to conduct benchmarking to observe how these design choices affect performance.

### LUT-tree Logic

The most notable feature of the CCGM1A1 is its LUT-tree logic element for combinatorial logic. Rather than using full LUTs, the design splits them into a tree structure, as illustrated in the figure below. This diagram shows a LUT element in a CPE implementing two L2T4 LUT trees instead of two standard LUT4s.

There's a trade-off between using an L2T4 and a LUT4:
- **Less area consumed:** A single L2T4 requires only 12 configuration bits compared to 16 for a LUT4.
- **Reduced combinatorial versatility:** An L2T4 can implement 4,096 different 4-input logic functions, whereas a LUT4 can implement 65,536.

![Lut-tree](0.doc/LUT_CPE.png)

### Routing Network Architecture

The FPGA features a standard island-style network architecture, consisting of big and small switch boxes that implement 6 and 2 unidirectional ports, respectively, on each of its NWSE sides. In addition to these Manhattan-style interconnects, diagonal connections are provided to allow signals to traverse several rows and columns more quickly—a useful feature for control logic. It is also worth mentioning that the CPE's input and output muxes supplement this routing network.

## Benchmarks

To unveil the real potential of the CologneChip GateMate A1 FPGA, we ran several benchmark tests targeting different aspects of its performance—often comparing it to similarly sized FPGAs from established vendors. Below is an overview of these benchmarks along with a brief description of their strategies. For detailed instructions and result analysis, please refer to the individual subfolders:

- [Corescore](https://corescore.store) — A popular FPGA benchmark that fits as many [Serv](https://github.com/olofk/serv) cores as possible.
- [LUTRAM_Stress_test](https://github.com/tarik-ibrahimovic/LUTRAM_Stress_Test) — Evaluates the capacity of the emulated distributed asynchronous read RAM, a suspected weak spot.
- [VeerWolves](https://www.linkedin.com/posts/gsteiert_wearealtera-activity-7240773845098323970-Bvlj?utm_source=share&utm_medium=member_desktop) — Similar in concept to Corescore, but with the added challenge of an expanding SOC.
- [fpga_torture](https://github.com/stnolting/fpga_torture) — A combined power and utilization stress test.


References:
>- https://github.com/mirekez/pnr_tests
   
        - this is a generic Verilog generator
        - by playing with parameters different part of design can be converted to RAM/SRL/DSP blocks
        - also generates XDC to randomly assign pins, this is auxiliary functionality tied to Xilinx and dialects for other vendors can be done

>- https://www.linkedin.com/posts/gsteiert_wearealtera-activity-7240773845098323970-Bvlj?utm_source=share&utm_medium=member_desktop
>- https://github.com/chipsalliance/VeeRwolf/tree/veerwolves
>- https://aignacio.com/posts/hdls/mpsoc_riscv
>- https://github.com/stnolting/fpga_torture
>- https://corescore.store
>- https://gitlab.com/x653/spaceinvaders-fpga

**<h3>  End of Document </h3>**
