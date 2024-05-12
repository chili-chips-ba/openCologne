![open-cologne](https://github.com/chili-chips-ba/openCologne/assets/67533663/917a1eb9-7c9f-43a9-a9bc-72b73aaac05b)
 
There is currently one and only one FPGA vendor in Europe -- CologneChip. Their GateMate device has a somewhat unique feature set for the 20K class, most notably the high-speed SerDes. It is also one of the rare families designed around 8-input MUX trees, vs. the mainstream microRAM-based LUTs. Given recent appearances of affordable boards, the main GateMate challenge at this moment, and indeed an opportunity, is to get hold and grow roots in the open hardware dev community. 

We are firmly set to help it achieve that goal. How? By using the following, two-pronged approach:

 - Design the third flavor of the popular open hardware ULX3S->ULX4M sequel ->> The **ULX5M**. This new board replaces LatticeSemi with GateMate FPGA and comes in the popular Raspberry Pi CM4 form factor. That makes it plug-and-play compatible with a vast asssortment of baseboards, so opening the first and only EU FPGA to a commendable set of existing peripherals and use-cases.

 - Create and validate a portfolio of **well-documented examples** that selectively put GateMate resources to good use. Be it by tapping into SystemVerilog RTL or HLS design methodologies, demonstrating pure hardware FSM implementations, or HW/SW co-design, utilizing SOC techniques, or possibly even reaching into LiteX framework... The goal is to expand GateMate audience, faciliate its silicon adoption, and ultimately have it gain a foothold in the market.

We have organized this work into 3 game levels with 9 play milestones:

## *Level I – Warm Up*

**Play 1** - Form development team and get to know CologneChip GateMate silicon and dev tools, see our [0.doc](https://github.com/chili-chips-ba/openCologne/tree/main/0.doc) folder. Procure [Olimex](https://www.olimex.com/Products/FPGA/GateMate/GateMateA1-EVB/open-source-hardware) boards and familiarize with hardware platform. Light up onboard LEDs with our very special blinky.

**Play 2** - Port to GateMate a selected subset of four simpler examples from the [ULX3S-MISC](https://github.com/emard/ulx3s-misc/tree/master/examples) portfolio. The goal is to enable support for a few standard PMODs and peripherals, mostly GPIO-based, including HyperRAM.

**Play 3** - To complement the set of peripherals we can test GateMate with, design some extension PMOD PCBs for it.

## *Level II - Bread and Butter*

**Play 4** - Port to GateMate four advanced ULX3S examples. Now free from the restrictions of supporting PCB development track, we shall chose these examples for their purely FPGA value. We may also modify them, create mutations and variants, looking to find a better fit for GateMate internal architecture.

**Play 5** - Adapt [TetriSaraj](https://github.com/chili-chips-ba/openXC7-TetriSaraj) HW/SW project to GateMate. This is a serious SOC. On the hardware side, it includes a RISC-V microkontroller, Instruction, and Data RAM, Frame Buffer with Video Subsystem, and high-speed I/O for VGA. On the software side, it’s a bare-metal "free-standing" C that implements the logic of a Tetrisoid gate.

**Play 6** - Design and manufacture ULX5M board.

## *Level III - Candy Cane*

**Play 7** - Develop an advanced example for CologneChip SerDes and its high-speed PLL.

**Play 8** - Stress test the FPGA device and tools, such as to assess silicon Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits. Work with 
[CologneChip](https://www.colognechip.com/programmable-logic/gatemate">CologneChip) developers to resolve issues identified in this course. 

**Play 9** - Port the barebones of [BetrustedSOC](https://github.com/betrusted-io/betrusted-soc) to GateMate, namely its VexRiscv CPU and UART.

This is a stepping stone for our next CologneChip project, perhaps using one of their yet to be released 40K or 80K devices. For background, BetrustedSOC is hosted in a Spartan7 XC7S50 (50K LUT6 device), with 80% utilization (as of October 2022), implemented using proprietary Vivado 2019.2 toolchain. The framework also employs a 5K LUT4 Lattice UP5 FPGA for housekeeping tasks. 

The full BetrustedSOC would indeed be a very fun thing to eventually do!

## *Beinvolved*
We welcome everyone interested to contribute to this work. Please reach out to fpga@chili-chips.com, or join our <a href="https://discord.gg/F5UPDFFdsH">GateMate Discord Channel</a>. 

**<h3> Acknowledgements </h3>** 
We are grateful to:
  - **NLnet Foundation's** sponsorship for this opportunity to put our minds on GateMate, the unique and EU-first FPGA device for the makers at heart.
  - **[Intergalaktik doo](https://intergalaktik.eu)** for their unreserved sharing of the first-hand insights into open-source community vibe, participation on the project, as well as full openess to our wish to play a part in the ULX unabated evolution.
   
> ![logo_nlnet](https://github.com/chili-chips-ba/openeye/assets/67533663/18e7db5c-8c52-406b-a58e-8860caa327c2)
> <img width="115" alt="NGI-Entrust-Logo" src="https://github.com/chili-chips-ba/openeye-CamSI/assets/67533663/013684f5-d530-42ab-807d-b4afd34c1522">

**<h3>  End of Document </h3>** 
