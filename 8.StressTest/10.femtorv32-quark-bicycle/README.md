# FemtoRV32-Quark-Bicycle - A Minimalist RV32I RISC-V Implementation

## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

## Resource Utilization
FemtoRV32-Quark-Bicycle is a compact, 400-line RV32I implementation derived from the [learn_fpga](https://github.com/BrunoLevy/learn-fpga) repository. This project originates from a [discussion](https://github.com/chili-chips-ba/openCologne/issues/57) aimed at identifying optimal design cases where GateMate FPGA can excel and demonstrate strengths in specific scenarios. **In this case, we're porting only the CPU, without any periferals, as a theoretical consideration on how well the FPGA hosts CPUs.**

Below are the resource utilization figures. The [discussion](https://github.com/chili-chips-ba/openCologne/issues/57) highlights the potential advantages of GateMate's multiplexing capabilities, particularly in scenarios involving wide multiplexers for register file writebacks and program counter control. While this test case is comparable in terms of resource usage, GateMate's efficiency per configuration bit (area) still falls short of being a clear winner.

>Note: Contrary to [spaceinvaders-fpga](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/8.spaceinvaders-fpga), Gowin uses Semi-Dual Port BRAM in this design which brings the two chips equal in BRAM blocks utilization.

| **Resource**   | **GW2AR-18C**                              | **CCGM1A1**                           |
|----------------|--------------------------------------------|---------------------------------------|
| **Logic/CPE**  | 1019 (877 LUT, 142 ALU) / 20736 (~5% usage) | 1116 CPEs / 20480 (5.4% usage)        |
| **Registers**  | 89 / 15730 (<1% usage)                     | 90 / 40960 (<1% usage)                |
| **Block RAM**  | 2 / 46 (~5% usage)                         | 2 / 32 (6.3% usage)                   |
