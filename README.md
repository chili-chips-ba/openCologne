![open-cologne](https://github.com/chili-chips-ba/openCologne/assets/67533663/917a1eb9-7c9f-43a9-a9bc-72b73aaac05b)
 
There is currently one and only one FPGA vendor in Europe -- CologneChip. Their GateMate device has a somewhat unique feature set for the 20K class, most notably the high-speed SerDes. It is also one of the rare families designed around 8-input MUX trees, vs. the mainstream microRAM-based LUTs. Given recent appearances of affordable boards, the main GateMate challenge at this moment, and indeed an opportunity, is to get hold and grow roots in the open hardware developers community. 

We are firmly set to help it achieve that goal. How? Using the following, two-pronged approach:

 - Design the third flavor of the popular open hardware ULX3S->ULX4M sequel ->> The <b>ULX5M</b>. This new board replaces LatticeSemi with GateMate FPGA and comes in the widely-used Raspberry Pi CM4 form factor. That makes it plug-and-play compatible with a vast asssortment of baseboards, so opening the first and only EU FPGA to a commendable set of existing peripherals and use-cases.

 - Create and validate a portfolio of <b>well-documented examples</b> that selectively put GateMate resources to good use, tapping into both Verilog RTL and HLS design methodologies, demonstrating both pure hardware FSM implementations and HW/SW co-design, utilizing SOC techniques, possibly even reaching into LiteX framework.

The goal is to expand the GateMate audience, faciliate its silicon adoption, and ultimately get a foothold in the market. We have organized this work into 3 game levels with 9 play milestones:

<h3>Level I – Warm Up</h3>

<b>Play 1</b> - Form development team and get to know CologneChip GateMate silicon and dev tools (see our <a href="https://github.com/chili-chips-ba/openCologne/tree/main/0.doc">0.doc</a> folder). Procure <a href="https://www.olimex.com/Products/FPGA/GateMate/GateMateA1-EVB/open-source-hardware">Olimex</a> boards and familiarize with hardware platform. Light up onboard LEDs with our very special blinky.

<b>Play 2</b> - Port to GateMate a selected subset of four simpler examples from the <a href="https://github.com/emard/ulx3s-misc/tree/master/examples">ULX3S-MISC</a> portfolio. The goal is to enable support for a few standard PMODs and peripherals, mostly GPIO-based, including HyperRAM.

<b>Play 3</b> - Design extension PMODs for GateMate, to so complement the set of peripherals we can test it with.

<h3>Level II - Bread and Butter</h3>

<b>Play 4</b> - Port to GateMate four advanced ULX3S examples. Now free from the restrictions related to supporting PCB development track, we are chosing these examples for their purely FPGA value. We may also modify them, create mutations and variants, looking to find a better fit for GateMate internal architecture.

<b>Play 5</b> - Adapt the complete <a href="https://github.com/chili-chips-ba/openXC7-TetriSaraj">TetriSaraj</a> HW/SW project to GateMate. This is a serious SOC. It on the hardware side includes a RISC-V microkontroller, Instruction, and Data RAM, Frame Buffer with Video Subsystem, and high-speed I/O for VGA. On the software side, it’s a bare-metal 'C' app that implements the logic of a Tetrisoid gate.

<b>Play 6</b> - Design and manufacture ULX5M board.

<h3>Level III - Candy Cane</h3>

<b>Play 7</b> - Develop an advanced example for CologneChip SerDes and its high-speed PLL.

<b>Play 8</b> - Stress test the FPGA device and tools, such as to assess silicon Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits. Work with 
<a href="https://www.colognechip.com/programmable-logic/gatemate">CologneChip</a> developers to resolve issues identified in this course. 

<b>Play 9</b> - Port the barebones of <a href="https://github.com/betrusted-io/betrusted-soc">BetrustedSOC</a> to GateMate, namely its VexRiscv CPU and UART.

This is a stepping stone for the next NLnet project with CologneChip, perhaps using one of their yet to be released 40K or 80K LUT devices. It’s worth noting that BetrustedSOC is hosted in a Spartan7 (XC7S50), which is a 50K LUT6 device, 80% utilized as of October 2022. The native BetrustedSOC is implemented using proprietary Vivado 2019.2 toolchain, and also employs a 5K LUT4 Lattice UP5 FPGA on the side for housekeeping tasks. 

The full BetrustedSOC would indeed be a very fun thing to eventually do!

**<h3> Beinvolved </h3>**
We are welcoming everyone interested to contribute to this work. Please reach out to fpga@chili-chips.com, or join our <a href="https://discord.gg/F5UPDFFdsH">GateMate Discord Channel</a>. 

**<h3> Acknowledgements </h3>** 
We are grateful to:
  - <b>NLnet Foundation's</b> sponsorship and this opportunity to put our minds on the GateMate, the unique and EU-first FPGA device for the makers.
  - <b>Intergalaktik doo</b> (https://intergalaktik.eu) for their participation in the project, the sharing of first-hand insights into open-source community vibe, and opening up to our desire to play a part in the ULX revolutionary game.
  
    ![logo_nlnet](https://github.com/chili-chips-ba/openeye/assets/67533663/18e7db5c-8c52-406b-a58e-8860caa327c2)

    ![NGI0Entrust_tag](https://github.com/chili-chips-ba/openeye/assets/67533663/19e919e3-6888-43e8-88b3-0a2ff447a80b) 

**<h3>  End of Document </h3>** 
