# TetriSaraj on GateMate
## Introduction

This project demonstrates how porting, of a custom SoC with RISC-V CPU and our special Video Controller which emulates a classic game called TetriSaraj in Basys3 Artix7-35T, was done to GateMate1-EVB from Olimex. Design details (game logic, system block diagram, memory mapping etc.) are specified in the original project: https://github.com/chili-chips-ba/openXC7-TetriSaraj.

Besides changes like constraint file, makefile etc., the main difference between the two designs is the clock frequency. Original TetriSaraj on Artix-7 FPGA was ran with a 100 MHz clock which was not possible in GateMate FPGA case. The maximum frequency for an optimized design was around 30 MHz and since VGA expects 25 MHz, the clock frequency used in this design was 25 MHz. This caused multiple timing issues regarding video generation (e.g. _vga_controller.v_, _top.v_), so timing adaptations in modules like these were done!

## Hardware setup

Since SimpleIO Extension Board plugged into Olimex only has 1 user button and 5 are needed to play the game, we had to use SimpleIO Extension Board to make up for the missing buttons like shown on image below:

![image](https://github.com/user-attachments/assets/ae35220d-a01d-4727-a8b0-39b207c47629)

Besides the GateMateA1-EVB and SimpleIO Extension Board plugged into it, a user will need a monitor with VGA port connected with the board.

## Results

The complete hardware setup and the loading screen:

![unnamed-min](https://github.com/user-attachments/assets/62c2cd11-c261-4846-bbc2-cd59c46a0b8e)

TetriSaraj gameplay:

![unnamed (4)](https://github.com/user-attachments/assets/b3558a6a-6a9b-4704-ad9c-fcdc21c5b5f6)

![unnamed (2)](https://github.com/user-attachments/assets/8e191741-83f5-4792-80df-5bba1fc767ef)

![1b](https://github.com/user-attachments/assets/cb28b561-fd35-4a46-918c-065b71d953db)

![unnamed (1)](https://github.com/user-attachments/assets/8e982547-ae1c-4c15-9c74-409e79cbc810)


## Local reproduction

To synthesize and run the design locally, one must install the _CologneChip toolchain_ and adapt the _Makefile_. The whole process is explained in "**3.build/Makefile**"!

#### End of Document
