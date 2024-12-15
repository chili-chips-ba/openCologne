# TetriSaraj on GateMate

## Introduction

This project is a demonstration of a complex digital hardware/software system. 

The hardware consists of a custom SoC with RISC-V CPU and our special _Video Controller_ that operates with _Mega Characters (MC)_, which are a close kin to the infamous _"Sprites"_. 

The software is bare-metal, w/o an OS, and implements a well-known, classic game, now rotated by 90 degrees and mirror-duplicated. 

The whole thing is called _TetriSaraj_, and essentially a port:
- from Digilent _Basys3_ (Artix7-35T) with openXC7 tools
- to Olimex _GateMate1-EVB_ board with CologneChip tools.

For the complete design detail (game logic, system block diagram, memory mapping etc.), please visit the original project repo: 
- https://github.com/chili-chips-ba/openXC7-TetriSaraj

## Surprise, surprise...

Other than the expected changes related to constraints, pinouts, makefile etc., the operating clock frequency emerged as the main (and indeed unexpected) difference between these two designs.

The original TetriSaraj ran on Artix-7 at `100MHz` w/o problems, even when built with openXC7 PNR, as opposed to Xilinx-proprietary Vivado. That was however far from possible on GateMate FPGA, where the `Fmax for the original design was 16MHz`, and for a reduced/optimized version barely reached 31 MHz, even at the highest VDD_CORE setting. 

With VGA sub-system needing at least 25MHz, we decided to scale down the clock of the entire (already reduced) system to the `25MHz`. This then caused multiple timing issues in the video generation section (such as within _vga_controller.v_ and _top.v_), calling for significant timing-driven adaptations, in some instances even an overhaul. 

## Hardware setup

Since Olimex comes with only 1 user button, we had to plug-in _SimpleIO Extension Board_ that brings additional buttons. 

The game needs 5 buttons:
- 4 arrows for the direction of movement
- plus 1 for the rotation.

The complete setup is shown below:

<img width=400 src="https://github.com/user-attachments/assets/ae35220d-a01d-4727-a8b0-39b207c47629">

In addition to the _GateMateA1-EVB_ with _SimpleIO Extension Board_ plugged into it, you also need a monitor with VGA port connected to it.

## The Gameplay

Our progam starts with a small, but full-custom Splash 😄:

<img width=400 src="https://github.com/user-attachments/assets/62c2cd11-c261-4846-bbc2-cd59c46a0b8e">

But, you start with three lives, that is three hearts:

<img width=400 src="https://github.com/user-attachments/assets/b3558a6a-6a9b-4704-ad9c-fcdc21c5b5f6">

As you're playin', you can earn more hearts, or lose them. The more you earn, the harder we make it for you to play and win.

<img width=400 src="https://github.com/user-attachments/assets/8e191741-83f5-4792-80df-5bba1fc767ef">

Sorry, it's _"Game Over"_ when you lose your last heart.

<img width=400 src="https://github.com/user-attachments/assets/cb28b561-fd35-4a46-918c-065b71d953db">

<img width=400 src="https://github.com/user-attachments/assets/8e982547-ae1c-4c15-9c74-409e79cbc810">

## Demo stream

https://github.com/user-attachments/assets/12611cf4-5f7c-42ba-97fa-0026c773a5dd

## How to build TetriSaraj for GateMate?!

To synthesize and run the design locally, one must install the _CologneChip toolchain_ and adapt the _Makefile_. The whole process is explained in `3.build/Makefile`.

## Our next play shall be audible

Stay tuned for the arrival of stereo soundtrack to TetriSaraj play...

## References
1) Also available on [Xilinx Artix7](https://github.com/chili-chips-ba/openXC7-TetriSaraj) and [Gowin LittleBee](https://github.com/chili-chips-ba/openXC7-TetriSaraj/tree/main/99.more-boards/0.tang-nano-9k), thanks to [SymbioticEDA](https://www.symbioticeda.com) support

2) Postings and mentions:
> - [Dec.15, 2024](https://www.linkedin.com/feed/update/urn:li:activity:7273353028055769089?commentUrn=urn%3Ali%3Acomment%3A%28activity%3A7273353028055769089%2C7274166171325607936%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287274166171325607936%2Curn%3Ali%3Aactivity%3A7273353028055769089%29)
> - [Oct.15, 2024](https://www.linkedin.com/posts/chili-chips_tetrisaraj-gatemate-opensource-activity-7252167674741301249-gOgI?utm_source=share&utm_medium=member_desktop)
> - [Oct.11, 2024](https://www.linkedin.com/feed/update/urn:li:activity:7250565052359921665?commentUrn=urn%3Ali%3Acomment%3A%28activity%3A7250565052359921665%2C7250724417754836992%29&replyUrn=urn%3Ali%3Acomment%3A%28activity%3A7250565052359921665%2C7251814253668544513%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287250724417754836992%2Curn%3Ali%3Aactivity%3A7250565052359921665%29&dashReplyUrn=urn%3Ali%3Afsd_comment%3A%287251814253668544513%2Curn%3Ali%3Aactivity%3A7250565052359921665%29)
> - [Oct.1, 2024](https://www.linkedin.com/feed/update/urn:li:ugcPost:7246625338787602434?commentUrn=urn%3Ali%3Acomment%3A%28ugcPost%3A7246625338787602434%2C7247337428045209600%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287247337428045209600%2Curn%3Ali%3AugcPost%3A7246625338787602434%29)
> - [SarajevoMakerFaire 2024](https://sarajevo.makerfaire.com/maker/entry/143)
> - [May 2023](https://www.linkedin.com/posts/chili-chips_fpga-education-riscv-activity-7076630631165689858-wgK_?utm_source=share&utm_medium=member_desktop)
> - [April 2023](https://www.linkedin.com/posts/chili-chips_fpga-foss-yosys-activity-7069758169639505920-LRyG?utm_source=share&utm_medium=member_desktop)
> - and more...

<img width=500 src="0.doc/TetriSaraj-joyIO.png">

#### End of Document
