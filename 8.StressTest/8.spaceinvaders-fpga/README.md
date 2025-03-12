# Space Invaders GateMate
## Design Overview

The **Space Invaders** design—adapted from [this repository](https://gitlab.com/x653/spaceinvaders-fpga)—has been ported to the **Gowin GW2AR-18C (20k LUT4)** FPGA. The primary goal is to compare resource utilization and maximum operating frequency (Fmax) between GateMate and Gowin FPGAs when implementing the same design. In a nutshell, this test tries to answer the question of **How many logic resources are required by GateMate versus Gowin FPGAs for the same input RTL?**

## Key Components

- **Intel 8080 CPU**  
- **Clocking:** Two PLLs generating:
  - 2 MHz for the CPU
  - 25 MHz for VGA video output
- **Memory:**
  - 8 KB ROM (Space Invaders code)
  - 1 KB RAM
  - 7 KB Video RAM
- **Video Output:** VGA (640×480 pixels @ 60 Hz)
- **User Interface:** PS/2 keyboard interface
- **Interrupt System:** For handling external events

This project is a **real-world use case** of a heterogeneous SoC architecture, as opposed to synthetic benchmarks like [corescore_cc](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/1.corescore_cc), [LUTRAM_Stress_Test](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/2.LUTRAM_stress_test), and [fpga-torture](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/5.fpga_torture).

## FPGA Resource Utilization Comparison
| **Resource**         | **CCGM1A1 (GateMate)**            | **GW2AR-18CQN88P C8/I7 (Gowin)**           |
|----------------------|-----------------------------------|------------------------------------------|
| **Logic / CPEs**     | 2339 / 20480 (11.4%)              | 1876 / 20736 (9%)                        |
| **Registers**        |  355 / 40960 (0.9%)               |  338 / 15750 (3%)                        |
| **Block RAM (BRAM)** |    4 / 32   (12.5%)               |   16 / 46 (35%)                          |

- **Logic Resources:** GateMate requires significantly more logic resources. The higher number of configuration bits (65k vs. 30k) implies that the silicon area occupied by the design on GateMate is more than twice that on the Gowin FPGA.
- **Registers:** Both platforms show similar register utilization.
- **Block RAM:** GateMate excels in BRAM with full true Dual-Port RAM support—a key advantage in memory-intensive applications (e.g., DMA). In contrast, Gowin, despite higher overall BRAM capacity in absolute numbers, may not offer the same dual-port capability.

## Fmax Comparison

- **Gowin GW2AR-18C:**  
  - Main clock: 50 MHz  
  - VGA clock: 150 MHz
- **CCGM1A1 (GateMate):**  
  - Main clock: 11 MHz  
  - VGA clock: 50 MHz

Gowin (produced in a rather old 55nm SRAM process) wins the speed race hands-down. On the other hand, CCGM1A1 is a GF 28nm Super-Low-Power (SLP) chip. The difference in performance most likely comes from the architectural choices, and not from the manufacturing process.

## Conclusion

GateMate is particularly well-suited for the highly pipelined designs, extensive use of DFFs, and for the memory-intensive applications. It comes with superior BRAM component with true dual-port I/O. While it boasts even more advantages on paper, GateMate shows limitions in the real-world applications. Some of them may come from design tools. This analysis does not try to distinguish between architectural and tools-related advantages and limitations. That are all considered essential elements of the complete package.
 
Conversely, the Gowin legacy _Arora_ architecture (i.e. not their latest _Arora V_ family), for the same RTL delivers much higher Fmax and more efficient use of logic resources, but lower BRAM efficiency.
