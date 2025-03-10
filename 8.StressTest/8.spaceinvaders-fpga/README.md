
## Design Description

The **Space Invaders** design is adapted from this [repository](https://gitlab.com/x653/spaceinvaders-fpga). For a detailed description, please refer to the original source. In this work, we have ported the design to the **Gowin GW2AR-18C (20k LUT4)** FPGA to evaluate and compare resource utilization and maximum frequency (Fmax). The central question addressed here is:  
**How many logic resources are required by GateMate and Gowin FPGAs to implement the same design?**

The Space Invaders design comprises the following components:
- Intel 8080 CPU
- Two PLLs: 2 MHz for the CPU and 25 MHz for VGA video output
- 8 KB ROM containing the original Space Invaders code
- 1 KB RAM
- 7 KB Video RAM
- VGA video output: 640×480 pixels @ 60 Hz
- PS/2 keyboard interface
- Interrupt system

This project implements a full graphical game with user interaction, utilizing a heterogeneous SoC architecture. It represents a **real-world use case**, in contrast to previous synthetic benchmarks such as [corescore_cc](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/1.corescore_cc), [LUTRAM_Stress_Test](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/2.LUTRAM_stress_test), and [fpga_torture](https://github.com/chili-chips-ba/openCologne/tree/main/8.StressTest/5.fpga_torture).

## FPGA Resource Utilization Comparison – Gowin Arora 20k

It is evident that the **CCGM1A1 (GateMate)** consumes significantly more logic resources than a conventional LUT4-based FPGA like **Gowin GW2AR-18C**. When considering the number of **configuration bits required**—**65k vs 30k**—this difference becomes even more pronounced, indicating that the actual silicon area occupied by the design on GateMate is more than twice as large. However, the number of registers used remains nearly the same on both platforms.

| Resource           | CCGM1A1                                 | GW2AR-18CQN88P C8/I7                        |
|--------------------|-----------------------------------------|---------------------------------------------|
| Logic / CPEs       | 2339 / 20480 (11.4%)                    | 1913 (1863 LUT, 50 ALU) / 20736 (10%)       |
| Registers          | 355 / 40960 (0.9%)                      | 324 / 15750 (3%)                            |
| └─ Flip-flops      | 355                                     | 324                                         |
| Block RAM (BRAM)   | 4 / 32 (12.5%)                          | 8 / 46 (18%)                                |

