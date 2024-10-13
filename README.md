There is currently one and only one FPGA vendor in Europe -- CologneChip. Their GateMate device has a somewhat unique feature set for the 20K class, most notably the high-speed SerDes. It is also one of the rare families designed around 2-input [LUT trees and muxes](https://github.com/chili-chips-ba/openCologne/issues/28#issue-2442939220), vs. the mainstream microRAM-based LUTs with 4, 5 or 6 address inputs. 

Given recent appearances of affordable boards, GateMate challenge at the moment is to get hold of, and grow roots in the open hardware dev community. We view it as an opportunity, and are firmly set to help it achieve that goal. 

How? By pursuing a three-pronged approach:

 1) Design the third flavor of the popular open hardware ULX3S->ULX4M sequel ->>> The **ULX5M**! While LatticeSemi FPGA will on this new board be replaced with GateMate, it will otherwise come in the same popular Raspberry Pi Compute Module 4 (CM4) form-factor. That makes it plug-and-play compatible with a vast asssortment of baseboards, so opening the first and only EU FPGA to a commendable set of existing peripherals and apps.

 2) Create and validate a portfolio of **well-documented examples** that put GateMate resources to good use. Be it by tapping into SystemVerilog or VHDL RTL, HLS design methodologies, demonstrating pure hardware FSM implementations, or HW/SW co-design, utilizing SOC techniques, or possibly even reaching into Amaranth and LiteX build frameworks... the goal is to expand GateMate audience, faciliate silicon adoption, and ultimately have it gain a foothold in the market.

  3) Engage with [CologneChip](https://www.colognechip.com/programmable-logic/gatemate">CologneChip) developers to resolve [issues](https://github.com/chili-chips-ba/openCologne/issues) identified in this course.
     
![open-cologne](https://github.com/chili-chips-ba/openCologne/assets/67533663/917a1eb9-7c9f-43a9-a9bc-72b73aaac05b)

We have organized this work into 3 game levels with 9 play milestones:

## *Level I – Warm Up*

**Play 1** - Form development team and get to know CologneChip GateMate silicon and dev tools, see our [0.doc](https://github.com/chili-chips-ba/openCologne/tree/main/0.doc) folder. Procure [Olimex](https://www.olimex.com/Products/FPGA/GateMate/GateMateA1-EVB/open-source-hardware) boards and familiarize with hardware platform. Light up onboard LEDs with our very special [blinky](https://github.com/chili-chips-ba/openCologne/tree/main/1.Blinky--Verilog-VHDL-Python.Amaranth/3.build). It contains _Verilog_, _VHDL_ and _Amaranth_ versions, as well as an example of how to use **CologneChip Internal Logic Analyzer (ILA)** for Olimex board. The **Makefile** and **CCF** in there are your essential _Getting Started Guide_, and golden reference to leverage from for your project.

**Play 2** - Port to GateMate a selected subset of simpler examples from the [ULX3S-MISC](https://github.com/emard/ulx3s-misc/tree/master/examples) portfolio. The goal is to enable a few standard PMODs and peripherals, mostly GPIO-based, including PSRAM/HyperRAM.

**Play 3** - To complement the set of peripherals that GateMate can be tested with, as well as design additional PMOD extensions for it.

## *Level II - Bread and Butter*

**Play 4** - Port to GateMate a couple of advanced ULX3S examples. Now without restrictions related to support of PCB development, we are choosing these examples for their purely FPGA value. We may also modify them, write mutations and variants, looking to find a better fit for GateMate internal architecture, or letting our creativity a free hand to play and experiment.

**Play 5** - Adapt [TetriSaraj](https://github.com/chili-chips-ba/openXC7-TetriSaraj) HW/SW project to GateMate. This is a serious SOC. On the hardware side, it includes a RISC-V microkontroller, Instruction, and Data RAM, Frame Buffer with Video Subsystem, and high-speed I/O for VGA. On the software side, it’s a bare-metal, "free-standing" C that implements the logic of a Tetrisoid gate.

**Play 6** - Design and manufacture ULX5M board.

## *Level III - Candy Cane*

**Play 7** - Develop an advanced example for CologneChip SerDes and its high-speed PLL.

**Play 8** - Stress test the FPGA device and tools, such as to assess silicon Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits. 

**Play 9** - Port the barebones of [BetrustedSOC](https://github.com/betrusted-io/betrusted-soc) to GateMate, namely its VexRiscv CPU and UART.

This is a stepping stone for our next CologneChip project, perhaps using one of their yet to be released 40K or 80K devices. 

For background, BetrustedSOC is currently hosted in a Spartan7 XC7S50 (50K LUT6 device), with 80% utilization (as of October 2022), implemented using proprietary Vivado 2019.2 toolchain, and also enjoying a 5K LUT4 Lattice UP5 FPGA on the side, for housekeeping tasks. The full BetrustedSOC would indeed be a very fun thing to eventually put into GateMate!

## Project Completion Matrix

[x] Level I, Play 1 - DONE, includes bonus examples

[x] Level I, Play 2 - DONE, includes bonus examples

[ ] Level I, Play 3 - WIP

---
[x] Level II, Play 4 - DONE, includes bonus examples

[x] Level II, Play 5 - DONE, includes bonus audio player for any soundtrack, in addition to the original video-only game

[ ] Level II, Play 6

---
[ ] Level III, Play 7

[ ] Level III, Play 8, WIP

[ ] Level III, Play 9

---
[ ] Bonus#1, Play 10, WIP
> We fell in love with what we were doing and, as hackers at heart, could not resist the temptation to keep designing for GateMate. Hence this additional output that was not originally planned for.

---
Please go into individual examples for additional detail, documenation and specific instructions.


## Bonus#2, based on direct CologneChip input
- Tool comps wrt Gowin, Lattice i Xilinx design flows:
    - overall execution speed
    - ease of use
    - straighforwardness (or not) of the work flow
    - completeness of tool suite
    - bugs and idiosyncrasies
    - ideas for enhancement and automation of the development process

- Silicon comps wrt comparable Gowin, Lattice i Xilinx parts
    - size: LUTs and FFs
    - Fmax
    - utilization metrics

- Misc.
    - help preparing demos and marketing material for trade shows
  
While we'll do our best to fulfill this special, direct CologneChip request, yet better is to plan for a follow up project based on CologneChips needs that will undoubtly emerge and refine through our ongoing work.

## Beinvolved
We welcome everyone interested to contribute. Please reach out to fpga@chili-chips.com, or join our <a href="https://discord.gg/F5UPDFFdsH">GateMate Discord Channel</a>. 

### Acknowledgements
We are grateful to:
  - **NLnet Foundation's** sponsorship for this opportunity to put our minds on GateMate, the unique and EU-first FPGA device for the makers at heart.
  - **[Intergalaktik doo](https://intergalaktik.eu)** for their unreserved sharing of the first-hand insights into open-source community vibe, participation on the project, as well as full openess to our wish to play a part in the ULX* unabated evolution.
   
> ![logo_nlnet](https://github.com/chili-chips-ba/openeye/assets/67533663/18e7db5c-8c52-406b-a58e-8860caa327c2)
> <img width="115" alt="NGI-Entrust-Logo" src="https://github.com/chili-chips-ba/openeye-CamSI/assets/67533663/013684f5-d530-42ab-807d-b4afd34c1522">

### End of Document
