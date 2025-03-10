# Space Invaders GateMate
## Design Overview

The **Space Invaders** design—adapted from [this repository](https://gitlab.com/x653/spaceinvaders-fpga)—has been ported to the **Gowin GW2AR-18C (20k LUT4)** FPGA. The primary goal is to compare resource utilization and maximum operating frequency (Fmax) between GateMate and Gowin FPGAs when implementing the same design. In essence, the study addresses: **How many logic resources are required by GateMate versus Gowin FPGAs for the same design?**

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

This project embodies a **real-world use case** via a heterogeneous SoC architecture, as opposed to synthetic benchmarks like [corescore_cc](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/1.corescore_cc), [LUTRAM_Stress_Test](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/2.LUTRAM_stress_test), and [fpga_torture](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/5.fpga_torture).

## FPGA Resource Utilization Comparison

| **Resource**         | **CCGM1A1 (GateMate)**            | **GW2AR-18CQN88P C8/I7 (Gowin)**           |
|----------------------|-----------------------------------|------------------------------------------|
| **Logic / CPEs**     | 2339 / 20480 (11.4%)              | 1876 / 20736 (9%)                        |
| **Registers**        | 355 / 40960 (0.9%)                | 338 / 15750 (3%)                         |
| **Block RAM (BRAM)** | 4 / 32 (12.5%)                    | 16 / 46 (35%)                            |

- **Logic Resources:** GateMate requires significantly more logic resources. The higher number of configuration bits (65k vs. 30k) implies that the silicon area occupied by the design on GateMate is more than twice that on the Gowin FPGA.
- **Registers:** Both platforms show similar register utilization.
- **Block RAM:** GateMate excels in BRAM with full true Dual-Port RAM support—a key advantage in memory-intensive applications (e.g., DMA). In contrast, Gowin, despite higher overall BRAM usage in absolute numbers, may not offer the same dual-port capability.

## Fmax Comparison

- **Gowin GW2AR-18C:**  
  - Main clock: 50 MHz  
  - VGA clock: 150 MHz
- **CCGM1A1 (GateMate):**  
  - Main clock: 11 MHz  
  - VGA clock: 50 MHz

Gowin benefits from a higher speed grade, while CCGM1A1 is a low-power chip, albeit manufactured on a more advanced process node.

## Conclusion

GateMate is particularly well-suited for highly pipelined designs (with extensive use of DFFs) and memory-intensive applications due to its superior BRAM capabilities. However, despite its architectural advantages, practical limitations related to design tools may influence how these gains translate in real-world implementations. Conversely, the Gowin platform offers higher Fmax and a more efficient use of logic resources for the same design.

_Disclaimer: This analysis is based on an architectural viewpoint. Tool limitations and specific design constraints may affect the actual performance and resource utilization._
