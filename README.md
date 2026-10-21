[![NLnet:Funded](https://badgen.net/badge/NLnet/Funded/08C)](https://nlnet.nl/)
[![Stars](https://badgen.net/github/stars/chili-chips-ba/openCologne?label=Stars)](https://github.com/chili-chips-ba/openCologne/stargazers)
[![License:BSD-3](https://badgen.net/badge/License/BSD-3/blue)](LICENSES)
[![Lint](https://badgen.net/github/checks/chili-chips-ba/openCologne/main/run-lint?label=Lint)](https://github.com/chili-chips-ba/openCologne/actions/workflows/lint.yml)
[![Verible](https://badgen.net/github/checks/chili-chips-ba/openCologne/main/verible?label=Verible)](https://github.com/chili-chips-ba/openCologne/actions/workflows/verible.yml)
[![SerDes:Pass](https://badgen.net/badge/SerDes/Pass/green)](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/1.serdes-test.STANDALONE)
[![PrjPeppercorn:Pass](https://badgen.net/badge/PrjPeppercorn/Pass/green)](https://github.com/YosysHQ/prjpeppercorn)
[![LiteX:YES](https://badgen.net/badge/LiteX/YES/green)](7.SerDes#build)
[![eduBOS5:YES](https://badgen.net/badge/eduBOS5/YES/green)](https://github.com/chili-chips-ba/openPCIE/blob/main/2.rtl/0.common.opensource/src/CPU.eduBOS5/README.md)
[![PeakRDL:YES](https://badgen.net/badge/PeakRDL/YES/green)](7.SerDes)

[Click here](https://github.com/chili-chips-ba/openCologne-PCIE) if interested in our new CologneChip project, which is about designing the first fully open-source **PCIE EndPoint**.

----
Currently there are few FPGA vendors in Europe. One of these vendors, CologneChip. Their GateMate device has a somewhat unique feature set for the 20K class, most notably the high-speed SerDes. It is also one of the rare families designed around 2-input [LUT trees and muxes](https://github.com/chili-chips-ba/openCologne/issues/28#issue-2442939220), vs. the mainstream microRAM-based LUTs with 4, 5 or 6 address inputs. 
<p align="center">
   <img width=250 src="https://github.com/chili-chips-ba/openCologne/blob/main/0.doc/artwork/opencologne.logo.svg">
</p>
Given recent appearances of affordable boards, GateMate challenge at the moment is to get hold of, and grow roots in the open hardware dev community... which is also an opportunity. We are firmly set to help GateMate achieve this goal. 

How? By pursuing a three-pronged approach:

1) Design the third flavor of the popular open hardware ULX3S->ULX4M sequel ->>> The **ULX5M**! While LatticeSemi FPGA will on this new board be replaced with GateMate, it will otherwise come in the same popular Raspberry Pi Compute Module 4 (CM4) form-factor. That makes it plug-and-play compatible with a vast asssortment of baseboards, so opening the first and only EU FPGA to a commendable set of existing peripherals and apps.

2) Create and validate a portfolio of **well-documented examples** that put GateMate resources to good use. Be it by tapping into SystemVerilog or VHDL RTL, HLS design methodologies, demonstrating pure hardware FSM implementations, or HW/SW co-design, utilizing SOC techniques, or possibly even reaching into Amaranth and LiteX build frameworks... the goal is to expand GateMate audience, faciliate silicon adoption, and ultimately have it gain a foothold in the market.

3) Engage with [CologneChip](https://www.colognechip.com/programmable-logic/gatemate) staff to resolve [issues](https://github.com/chili-chips-ba/openCologne/issues) identified in this course.


The practical execution of this strategy is organized into 3 game levels with 9 play milestones.

## *Level I – Warm Up*

**Play 1** - Form development team and get to know CologneChip GateMate silicon and dev tools, see our [0.doc](https://github.com/chili-chips-ba/openCologne/tree/main/0.doc) folder. Procure [Olimex](https://www.olimex.com/Products/FPGA/GateMate/GateMateA1-EVB/open-source-hardware) boards and familiarize with hardware platform. Light up onboard LEDs with our very special [blinky](https://github.com/chili-chips-ba/openCologne/tree/main/1.Blinky--Verilog-VHDL-Python.Amaranth/3.build). It contains _Verilog_, _VHDL_ and _Amaranth_ versions, as well as an example of how to use **CologneChip Internal Logic Analyzer (ILA)** for Olimex board. The **Makefile** and **CCF** in there are your essential _Getting Started Guide_, and golden reference to leverage from for your project.

**Play 2** - Port to GateMate a selected subset of simpler examples from the [ULX3S-MISC](https://github.com/emard/ulx3s-misc/tree/master/examples) portfolio. The goal is to enable a few standard PMODs and peripherals, mostly GPIO-based, including PSRAM/HyperRAM.

**Play 3** - To complement the set of peripherals that GateMate can be tested with, as well as design additional PMOD extensions for it.

## *Level II - Bread and Butter*

**Play 4** - Port to GateMate a couple of advanced ULX3S examples. Now without restrictions related to PCB development support, we are choosing these examples for their purely FPGA value. We may also modify them, write mutations and variants, looking to find a better fit for GateMate internal architecture, or letting creativity a free hand to play and experiment.

**Play 5** - Adapt [TetriSaraj](https://github.com/chili-chips-ba/openXC7-TetriSaraj) HW/SW project to GateMate. This is a serious SOC. Its hardware includes a RISC-V microkontroller, Instruction, and Data RAM, Frame Buffer with Video Subsystem, and high-speed I/O for VGA. On the software side, this is a bare-metal, "free-standing" C that implements the logic of a Tetrisoid gate.

**Play 6** - Design and manufacture the ULX5M board.

## *Level III - Candy Cane*

**Play 7** - Develop an advanced example for CologneChip SerDes and its high-speed PLL.

**Play 8** - Stress-test the FPGA device and tools, such as to assess silicon Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits. 

**Play 9** - Port the barebones of [BetrustedSOC](https://github.com/betrusted-io/betrusted-soc) to GateMate, namely its VexRiscv CPU and UART.

This is a stepping stone for our next CologneChip project, perhaps using one of their yet to be released 40K or 80K devices. 

For background, BetrustedSOC is currently hosted in a Spartan7 XC7S50 (50K LUT6 device), with 80% utilization (as of October 2022), implemented using proprietary Vivado 2019.2 toolchain, also enjoying a 5K LUT4 Lattice UP5 FPGA on the side for housekeeping tasks. The full BetrustedSOC would indeed be fun to eventually port to GateMate!

## Project Completion Matrix

--- Level I
- ✅ Play 1 - **DONE, includes bonus examples**
   - ✅ 1.Blinky--ILA-Test
   - ✅ 1.Blinky--Verilog-VHDL-Python.Amaranth

- ✅ Play 2 - **DONE, with bonus examples**
   - ✅ 2.Simple--1--PSRAM
   - ✅ 2.Simple--2--QSPI-Flash, done by @pu-cc outside of this project
   - ✅ 2.Simple--3--Ethernet, done by @pu-cc outside of this project
   - ✅ 2.Simple--4--1Wire-Controller
   - ✅ 2.Simple--5--UART-Test
   - ✅ 2.Simple--6--PS2-Keyboard
   - ✅ 2.Simple--7--Audio-4-bit-DAC

- ✅ Play 3 - **DONE, with bonus I/O cards**
   - ✅ **PCB repo1**: Design additional [extension boards](https://github.com/intergalaktik/Extension_Boards_for_Olimex_GateMate)

--- Level II
- ✅ Play 4 - **DONE**
   - ✅ 4.Advanced--1--SPI-LCD
   - ✅ 4.Advanced--2--LED64x64
   - ✅ 4.Advanced--3--FM-Transmitter
   - [ ] 4.Advanced--4--Yamaha-OPL3-FM-Synth, partly done, on hold due to issues with GateMate legacy tools. To be revisited when Project Peppercorn opensource PNR for GateMate is made available

- ✅ Play 5 - **DONE**
   - ✅ 5.TetriSaraj

- ✅ Play 6 - **DONE**
   - ✅ **PCB repo2**: Design and manufacture the [ULX5M board](https://github.com/intergalaktik/ulx5m-gs)

--- Level III
- ✅ Play 7 - **DONE, with Doc still WIP**
   - ✅ 7.SerDes

- ✅ Play 8 - **DONE**
   - ✅ 8.StressTest

- ✅ Play 9 - **DONE**
   - ✅ 9.BetrustedSOC

--- Bonus
- [ ] Play 10, even more examples
   - [ ] 10.Bonus--1--Amaranth-7Segment, WIP
   - [ ] 10.Bonus--2--Amaranth-Rotary-Encoder, WIP
   - [ ] 10.Bonus--3--Amaranth-eduRISC5
   - ✅ 10.Bonus--4--I2C-Master
   - ✅ 10.Bonus--5--eduSOC, moved to 8.StressTest
   - ✅ 10.Bonus--6--I2S-DAC

We fell in love with what we were doing and, as makers at heart, could not resist the temptation to keep designing for GateMate. Hence this additional output that was not originally planned for, nor commissioned by NLnet.

---
Please click on the folder with individual examples for additional detail, documenation and specific instructions.


## Bonus+, from CologneChip direct input/needs
- Comps with Gowin, Lattice and Xilinx design flows:
    - overall execution speed
    - ease of use
    - straighforwardness (or not) of the work flow
    - completeness of tool suite
    - bugs and idiosyncrasies
    - ideas for enhancement and automation of the development process

- Comps with Gowin, Lattice and Xilinx silicon in the 20K LUT category
    - Fmax
    - utilization metrics
    - practically achievable design sizes in LUTs and FFs, i.e. the overall efficiency of GateMate architecture

- Misc.
    - help prepare demos and marketing material for trade shows
  
While doing our best to fulfill these special requests that are outside the NLnet task list, we'd better plan for a follow up project for other CologneChip needs that are emerging through this work.

For example, we've already established that TetriSaraj (PicoSOC with PicoRV32) can on GateMate barely run at `31MHz` in its high Voltage setting `-om 3, -tm 3`, see this [issue](https://github.com/chili-chips-ba/openCologne/issues/35#issue-2529092332). On the other hand, the lowest speed-grade Artix7 (xc7a35tcpg236-1) had no problem with `100MHz+`. Moreover, this is not even an apples-to-apples comparison since, to make GateMate go over 25MHz (which is the absolute minimum for our VGA video sub-system), we had to strip the PicoSOC down to barebones, i.e. take out its features that were not critical for TetriSaraj. Without that, the original GateMate Fmax for the 100% identical RTL was on the order of `16MHz`.

Similarly, we found that GateMate [timing reporting](https://github.com/chili-chips-ba/openCologne/issues/35#issue-2529092332) was sub-standard, its [constraints-driven](https://github.com/chili-chips-ba/openCologne/issues/38) property questionable, [SystemVerilog](https://github.com/chili-chips-ba/openCologne/issues/3) support not built-in, simulation [models](https://github.com/chili-chips-ba/openCologne/issues/14) and [Verilator](https://github.com/chili-chips-ba/openCologne/issues/8) compatibility lacking. 

Most importantly, the `GateMate proprietary P_R tool has repeatedly proved to be erroneous and unreliable`, see issues https://github.com/chili-chips-ba/openCologne/issues/30 and https://github.com/chili-chips-ba/openCologne/issues/25. For the complete account, please review all discussions and issues we've raised, both open and closed.

> The good news is that, just as our project is uncovering issues, so is CologneChip addressing them... to slowly, step by step, turn GateMate tools and silicon into an FPGA platform that's actually useable in the real-life designs. 

We are proud to have initiated GateMate enablement in opensource [Amaranth](https://github.com/amaranth-lang/amaranth) and [PipelineC](https://github.com/JulianKemmerer/PipelineC) dev frameworks. This project has also introduced GateMate to [Source Code Linting](https://github.com/chipsalliance/verible) for not only style, format, syntax and semantics, but also the [CDC](https://github.com/chili-chips-ba/openCologne/issues/29), a topic that is admittedly insufficiently covered by opensource chip design movement in general.

## A peek into our PCB track
<p align="center">
  <img width=500 src="0.doc/Intergalaktik/IO-boards.jpg">
</p>
   
Click [here](https://github.com/intergalaktik/Extension_Boards_for_Olimex_GateMate) for more on extension cards. For ULX5M, check [this](https://github.com/chili-chips-ba/openCologne/tree/main/6.PCB.advanced).

#### ULX5M-v02 bringup
[![ULX5M blinks LEDs on its own](6.PCB.advanced/0.doc/ulx5m-gs.v02.4.debug.jpg)](https://www.youtube.com/watch?v=LA20pfW7X00 "ULX5M is counting!")

#### ULX5M-v02 mounted on the CM4-BB3 carrier card, with HDMI test image
<p align="center">
   <img width=600 src="6.PCB.advanced/0.doc/ulx5m-gs.v02.5.with-CM4_BB3.jpg">
   <img width=600 src="6.PCB.advanced/0.doc/ulx5m-gs.v02.6.with-CM4_BB3.HDMI.jpg">
</p>

#### ULX5M-v02 mounted on the CM4 "Piunora" carrier card, with HDMI test image
<p align="center">
   <img width=600 src="6.PCB.advanced/0.doc/ulx5m-gs.v02.7.with-CM4_Piunora.jpg">
   <img width=600 src="6.PCB.advanced/0.doc/ulx5m-gs.v02.8.with-CM4_Piunora.HDMI.jpg">
</p>


## GateMate SerDes as InterChip Link

Our flagship: two GateMate chips talk over their SerDes, as one memory-mapped system. One CPU reads and writes the other chip's registers and memory as if they were its own. It is LiteX's [LiteICLink](https://github.com/enjoy-digital/liteiclink), hand-ported to SystemVerilog, so it can be linted, simulated with open tools, and dropped into LiteX as an SV core.

```mermaid
flowchart LR
  subgraph A["GateMate A"]
    direction TB
    CPUA["eduBOS5<br/>RISC-V"] --> CSRA["CSRs<br/>(PeakRDL)"] --> SWA["SerWB<br/>bus bridge"] --> PHYA["8b/10b + PRBS<br/>CC_SERDES"]
  end
  subgraph B["GateMate B"]
    direction TB
    PHYB["8b/10b + PRBS<br/>CC_SERDES"] --> SWB["SerWB<br/>bus bridge"] --> CSRB["CSRs<br/>(PeakRDL)"] --> CPUB["eduBOS5<br/>RISC-V"]
  end
  PHYA <== "serial link<br/>(sim: SerDes BFM)" ==> PHYB
```

- **Full end-to-end sim with open tools.** In sim, our [SerDes BFM](7.SerDes/3.iclink-sv/2.sim/serdes-model) (from [openCologne-PCIE](https://github.com/chili-chips-ba/openCologne-PCIE)) stands in for the wire and the `CC_SERDES` hard macro. No VProc, no vendor model: the RTL runs as built.
- **Bit-exact with LiteX.** Every block is checked against LiteX's own Python model, clock for clock.
- **Done:** 8b/10b, PRBS7/15/31, the `CC_SERDES` PHY with a one-way link sim, a bitstream with the open Peppercorn flow.
- **Next:** SerWB, two eduBOS5 SoCs end to end, then the boards: one EVB looped TX to RX, then two ULX5M-GS.

More in [7.SerDes](7.SerDes).

## Additional References
- https://github.com/YosysHQ/prjpeppercorn
   - https://github.com/YosysHQ/prjpeppercorn-test-cases
   - https://projectf.io/demos
- https://github.com/yuri-panchul/basics-graphics-music
- https://github.com/PythonLinks/awesome-gatemate
- https://colognechip.com/wp-content/uploads/Novel-GateMate-FPGA-Architecture-FPL2021.pdf
  
## Acknowledgements
We are grateful to:
  - **NLnet Foundation's** sponsorship for this opportunity to put our hand and brains on GateMate.
  - **[Intergalaktik doo](https://intergalaktik.eu)** for their unreserved sharing of the first-hand insights into open-source community vibe, participation on the project, and openess to our wish to play a part in the ULX* unabated evolution.

<p align="center">
    <img src="https://github.com/chili-chips-ba/openeye/assets/67533663/18e7db5c-8c52-406b-a58e-8860caa327c2">
    <img width="115" alt="NGI-Entrust-Logo" src="https://github.com/chili-chips-ba/openeye-CamSI/assets/67533663/013684f5-d530-42ab-807d-b4afd34c1522">
</p>

This project was funded through the NGI0 Entrust Fund, a fund established by NLnet with financial support from the European Commission's Next Generation Internet programme, under the aegis of DG Communications Networks, Content and Technology under grant agreement No 101069594.

### Partners and Contributors

<p align="center">
  <a href="https://intergalaktik.eu"><img width="50%" alt="Intergalaktik logo" src="0.doc/artwork/Intergalaktik.logo.png"></a>
  <a href="https://radiona.org"><img width="20%" alt="Radiona logo" src="0.doc/artwork/Radiona.logo.png"></a>
</p>

<p align="center">
  <a href="https://colognechip.com"><img width="45%" alt="Cologne Chip logo" src="0.doc/artwork/Cologne-Chip.logo.png"></a>
  <a href="https://colognechip.com/programmable-logic/gatemate"><img width="20%" alt="GateMate FPGA logo" src="0.doc/artwork/GateMate.png"></a>
</p>

<p align="center">
  <a href="https://github.com/chili-chips-ba/openCologne-PCIE"><img width="15%" alt="openCologne-PCIE project logo: SerDes BFM" src="0.doc/artwork/openCologne-PCIE.hex.png"></a>
</p>

<p align="center">
  <a href="https://oshwa.org"><img width="20%" alt="Open Source Hardware Association logo" src="0.doc/artwork/oshw-logo-filled-black.png"></a>
  <a href="https://www.kicad.org"><img width="25%" alt="KiCad logo" src="0.doc/artwork/kicad_logo.png"></a>
</p>

### Tools and Building Blocks

<p align="center">
  <a href="https://github.com/enjoy-digital/litex"><img width="25%" alt="LiteX logo" src="0.doc/artwork/LiteX.logo.png"></a>
  <a href="https://github.com/tarik-ibrahimovic/eduBOS5"><img width="17%" alt="eduBOS5 logo" src="0.doc/artwork/eduBOS5.logo.png"></a>
  <a href="https://riscv.org"><img width="12%" alt="RISC-V logo" src="0.doc/artwork/RISC-V-logo.svg"></a>
  <a href="https://peakrdl.readthedocs.io"><img width="14%" alt="PeakRDL logo" src="0.doc/artwork/PeakRDL.logo.png"></a>
</p>

<p align="center">
  <a href="https://github.com/yosyshq"><img width="20%" alt="Yosys logo" src="0.doc/artwork/Yosys.logo.png"></a>
  <a href="https://github.com/YosysHQ/prjpeppercorn"><img width="20%" alt="prjpeppercorn logo: nextpnr for GateMate" src="0.doc/artwork/prjpeppercorn.logo.png"></a>
  <a href="https://github.com/trabucayre/openFPGALoader"><img width="20%" alt="openFPGALoader logo" src="0.doc/artwork/openFPGAloader.logo.png"></a>
  <a href="https://www.veripool.org/verilator"><img width="20%" alt="Verilator logo" src="0.doc/artwork/Verilator.logo.png"></a>
  <a href="https://github.com/steveicarus/iverilog"><img width="20%" alt="Icarus Verilog logo" src="0.doc/artwork/Icarus-Verilog.logo.png"></a>
</p>

<p align="center">
  <a href="https://github.com/MikePopoloski/slang"><img width="25%" alt="MikePopoloski slang logo" src="0.doc/artwork/slang.logo.png"></a>
  <a href="https://www.chipsalliance.org/projects"><img width="15%" alt="Chips Alliance SV Tools logo" src="0.doc/artwork/ChipsAlliance-SV-Tools.logo.png"></a>
  <a href="https://github.com/chipsalliance/verible"><img width="25%" alt="Verible logo" src="0.doc/artwork/Verible.logo.png"></a>
  <a href="https://www.drawio.com"><img width="25%" alt="draw.io logo" src="0.doc/artwork/drawio.logo.png"></a>
</p>

## Community Outreach
- [Project impact](https://www.linkedin.com/feed/update/urn:li:activity:7366484946456137732?commentUrn=urn%3Ali%3Acomment%3A%28activity%3A7366484946456137732%2C7367058727419461634%29&replyUrn=urn%3Ali%3Acomment%3A%28activity%3A7366484946456137732%2C7367071208963534851%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287367058727419461634%2Curn%3Ali%3Aactivity%3A7366484946456137732%29&dashReplyUrn=urn%3Ali%3Afsd_comment%3A%287367071208963534851%2Curn%3Ali%3Aactivity%3A7366484946456137732%29)
- [CologneChip News](https://colognechip.com/news/new-extensions-for-the-olimex-gatemate-fpga-board)
- [IO cards](https://www.linkedin.com/posts/goran-mahovlic_fpga-opensource-openhardware-activity-7272630456599138304-nB8K?utm_source=share&utm_medium=member_desktop)
- [IO cards2](https://www.linkedin.com/posts/goran-mahovlic_fpga-opensource-openhardware-activity-7273353028055769089-qn1x?utm_source=share&utm_medium=member_desktop)
- [TetriSaraj](https://www.linkedin.com/posts/chili-chips_tetrisaraj-gatemate-opensource-activity-7252167674741301249-gOgI?utm_source=share&utm_medium=member_desktop)
- [LED 64x64](https://www.linkedin.com/posts/ahmed-imamovic_etfpga-fpga-rtl-activity-7242253055411331073-E36f?utm_source=share&utm_medium=member_desktop)
- [LCD](https://www.linkedin.com/posts/chili-chips_gatemate-spi-lcd-activity-7233383297500733441-F4PM?utm_source=share&utm_medium=member_desktop)

## Community Involvement

Feel like helping the GateMate community grow better and larger?! Reach out to fpga@chili-chips.com, or join our <a href="https://discord.gg/F5UPDFFdsH">GateMate Discord Channel</a>.

Don't feel shy to ask for help ===> [![issues](https://badgen.net/github/open-issues/chili-chips-ba/openCologne?label=issues)](https://github.com/chili-chips-ba/openCologne/issues).

## Contribution Guidelines

See [Contributions](CONTRIBUTING.md): how to report an issue, the QA steps a change goes through (lint, format, simulation, build, LEQ), the license, and GenAI use. [7.SerDes/3.iclink-sv](7.SerDes/3.iclink-sv) is our reference example: it carries the full QA flow, so start there.

## RTL Coding Rules

New RTL follows our [RTL coding rules](7.SerDes/3.iclink-sv/1.hw/README.md#rtl-coding-rules), as in [openPCIE](https://github.com/chili-chips-ba/openPCIE/blob/main/2.rtl/README.md#rtl-coding-rules) and [wireguard-fpga](https://github.com/chili-chips-ba/wireguard-fpga/blob/main/1.hw/README.md#rtl-coding-rules). The older examples predate them.

## GenAI

Our repo may contain elements of work facilitated by the modern GenAI tools <img alt="Claude" height="16" src="https://cdn.simpleicons.org/claude/D97757">, used under strict guidance and tight supervision of the blood-and-flesh developers, and solely as suggestions.

In the end, it is us, the human devs, who are fully responsible for any shortfalls you may uncover while tapping into repo resources.

--------------------
#### End of Document
