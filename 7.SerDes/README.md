# SerDes App for GateMate

Design a high-speed serial, **memory-mapped Chip-to-Chip (C2C) Interconnect**. The goal of such IP is to set the stage for creating compute clusters and Hyper Cubes made of GateMate FPGAs, all physically interconnected with SerDes, with this C2C on top of it, serving as logical and transport layer.

## References:
- CologneChip [SerDes example design](https://github.com/pu-cc/gm_serdes_lb) and latest [datasheet](https://colognechip.com/docs/ds1001-gatemate1-datasheet-latest.pdf)
- Xilinx PG046 - [Aurora 8B/10B](https://docs.amd.com/r/en-US/pg046-aurora-8b10b/Introduction?tocId=Tqe8wtK9r1zAUq13hUnVEw)
    - Xilinx SP002 - [Aurora 8B/10B Protocol Spec](https://docs.amd.com/v/u/en-US/aurora_8b10b_protocol_spec_sp002)
- BerkeleyLab [ChitChat](https://berkeleylab.github.io/Bedrock/_gen_md/serial_io/chitchat/README_md.html) protocol
- LiteX [IC Link](https://github.com/enjoy-digital/liteiclink)
- [MesaBusProtocol](https://github.com/blackmesalabs/MesaBusProtocol)
- openCologne-PCIE [SerDes BFM](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/2.serdes-model) and [SerDes loopback tests](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/1.serdes-test.STANDALONE)
- [Transputer](http://www.bitsavers.org/components/inmos/transputer/C011_Link_Adaptor.pdf)
- [LiteX 1000basex](https://github.com/pu-cc/liteeth/tree/gatemate1000basex)
- [Seding Data Structures from chip to chip](https://www.reddit.com/r/FPGA/comments/1m8gl5o/how_to_send_a_struct_from_one_dev_board_to_another)
  
- Timing-aware/better PNR for this high-speed design:
    - [Project Peppercorn](https://github.com/YosysHQ/prjpeppercorn)
    - [nextpnr for GateMate](https://github.com/YosysHQ/nextpnr/tree/main/himbaechel/uarch/gatemate)

- Primer on [Eye Diagrams](https://incompliancemag.com/eye-diagram-part1) and [Equivalent Time Sampling](https://www.tek.com/en/documents/application-note/real-time-versus-equivalent-time-sampling) (vs. real-time)

<p align="center" width="100%">
    <img width="65%" src="0.doc/Eye-Diagrams.png">
</p>

- Gowin primer on SerDes Signal Integrity ([SI](https://www.gowinsemi.com/en/market/market_detail/48)) measurements 

- Altera [Serial Link Analyzer](https://www.altera.com/products/development-tools/quartus-prime/advanced-link-analyzer)

- Xilinx UG908 - In-System [IBERT](https://docs.amd.com/r/en-US/ug908-vivado-programming-debugging/Using-Vivado-Serial-I/O-Analyzer-to-Debug-the-Design)

    
## Plan of Record
Having thoroughly studied all options, the developers presented them in a project meeting on _July 11, 2025_, where team unanimously decided for the GateMate Chip2Chip SerDes:
- not to mimic the semi-proprietary _Xilinx/AMD Aurora_
- not to be based on _BerkeleyLab ChitChat_ 
- not to be based on _MesaBusProtocol_
- not to invent _our own scheme_ (which was the original plan of Chili.CHIPS*ba developers)
- but rather to port `LiteX IC Link`, thus honoring CologneChip guidance and strong preference **<== WINNER!**

The _IC Link_ comes with a worked out interface to the CPU. Its interface to SerDes will leverage from Patrick's _1000basex Ethernet MAC_ project. The best part of the _IC Link_ is that it opens the full power of LiteX integration, making it available for CologneChip customers almosts instantly, and so with minimal coding burden. As such, the _IC Link_ is the Chip2Chip interconnect that CologneChip would benefit the most from for their SerDes. 

Given that GateMate proprietary (aka "legacy") PnR is rather unreliable and insensitive to timing constraints, while the new opensource PnR (Project Peppercorn) has already saved the day for our WP9-[BetrustedSOC](https://github.com/chili-chips-ba/openCologne/tree/main/9.BetrustedSOC), the _Chip2Chip SerDes_ will be delivered solely and exclusively for the _nextpnr_.


For details on the work completed so far and the planned next steps, please refer to the [4.liteiclink](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/2.liteiclink) section of the repository.

## Implementation
We strongly recommend to start with standalone [SerDes loopback test](1.serdestool_by_gm/README.md) to get used to the hardware platform, SerDes settings, cabling and work with RF-class signaling in general. 

Then move onto our [Lite IC Link](2.liteiclink/README.md) port for GateMate SerDes. You will find more detail in the respective project folders.

| Folder | What | Status |
|---|---|---|
| [1.serdestool_by_gm](1.serdestool_by_gm) | standalone SerDes loopback test | works |
| [2.liteiclink](2.liteiclink) | LiteICLink port, Python (Migen): GateMate PHY `serdes_gm.py`, LiteX target, demo firmware | prototype, WIP |
| [3.iclink-sv](3.iclink-sv) | the same IC Link in SystemVerilog: our reference example, with the full QA flow | WIP |

## IC Link in SystemVerilog (3.iclink-sv)

We build on LiteX's [LiteICLink](https://github.com/enjoy-digital/liteiclink) rather than a new protocol. Its **SerWB** is a Wishbone bridge over a serial link: a bus master on one chip reads and writes memory and CSRs on the other. Upstream LiteICLink has transceiver PHYs for Xilinx (GTP, GTX, GTH, GTY) and Lattice ECP5, but none for GateMate; [2.liteiclink](2.liteiclink) prototypes one (`serdes_gm.py`).

LiteICLink is Python (Migen). We hand-port it to **SystemVerilog**, to our [RTL coding rules](3.iclink-sv/1.hw/README.md#rtl-coding-rules), so it goes through our full QA flow: lint, Verible, LEQ. The protocol stays LiteICLink's, so it interoperates with it. LiteX takes it in as an external core, through a thin Migen wrapper (`Instance` + `add_source`):

| Layer | What | From |
|---|---|---|
| C2C bus | SerWB master/slave, Wishbone over the link | LiteICLink, ported to SV |
| Packet, scrambler | SerWB datapath | LiteICLink, ported to SV |
| PHY | **GateMate `CC_SERDES` transceiver**: 8b10b, comma alignment, reset/lock sequence | **ours, new**, SV, from the `serdes_gm.py` prototype |
| LiteX integration | Migen wrapper for the SV core | ours, new, offered to LiteX |
| SoC | one per chip: [eduBOS5](https://github.com/chili-chips-ba/openPCIE/tree/main/2.rtl/0.common.opensource/src/CPU.eduBOS5) RV32I, RAM, UART; two eduBOS5 instances talk to each other over the link | eduBOS5 from openPCIE |
| CSRs | register map in SystemRDL, RTL and C headers generated by [PeakRDL](https://peakrdl.readthedocs.io), not LiteX's CSR generator | ours, PeakRDL |

The SoC is ours, so the core needs no LiteX to run. LiteX users take only the SV core, through the wrapper.

## Build

### From the legacy GateMate tools to Project Peppercorn

The older openCologne examples build with Cologne Chip's own tools: their Yosys and the proprietary `p_r` place & route (`CC_TOOL`). We found `p_r` [unreliable](https://github.com/chili-chips-ba/openCologne/issues/30), with weak [timing reports](https://github.com/chili-chips-ba/openCologne/issues/35). 7.SerDes uses the fully open-source flow only (see the Plan of Record):

| Step | Legacy | Now |
|---|---|---|
| Synthesis | Cologne Chip's Yosys build | Yosys `synth_gatemate` |
| Place & route | `p_r` (proprietary) | nextpnr-himbaechel, `gatemate` uarch |
| Bitstream | `p_r` | `gmpack`, [Project Peppercorn](https://github.com/YosysHQ/prjpeppercorn) |
| Programming | openFPGALoader | openFPGALoader |

Our versions (a blinky and a `CC_SERDES` design pack to bitstreams): Yosys 0.69, nextpnr main `6b438a1c` (built with `-DHIMBAECHEL_UARCH=gatemate`, installed as `nextpnr-himbaechel-gatemate`) and Project Peppercorn v1.14. No vendor tools.

The core builds two ways, so it is usable with or without LiteX.

### Standalone, without LiteX

The SV core is plain RTL: drop it into any GateMate design. The flow is LiteX's, below, with our sources and pins, for the EVB (`CCGM1A1`):

```
yosys -p "read_slang <sources>; synth_gatemate -top top -luttree -nomx8 -json top.json"
nextpnr-himbaechel-gatemate --device CCGM1A1 --json top.json --vopt ccf=GateMateA1-EVB.ccf \
    --vopt out=top.txt --router router2 --freq <MHz> --seed 1
gmpack top.txt top.bit
openFPGALoader -b gatemate_evb_jtag top.bit
```

Unlike LiteX, we leave out `--timing-allow-fail`: a timing failure stops the build. [`3.iclink-sv/3.build`](3.iclink-sv/3.build) wraps it (`make`, `make load`); the sources come from [`3.iclink-sv/1.hw/top.filelist`](3.iclink-sv/1.hw/top.filelist).

### Within LiteX

LiteX takes the SV core through its Migen wrapper (`platform.add_source` + `Instance`). Its GateMate platform has both flows: `toolchain="colognechip"` (Yosys + `p_r`) and `toolchain="peppercorn"` (Yosys + nextpnr + `gmpack`); LiteX-Boards' GateMate targets default to `peppercorn`. For example, LiteX's own EVB SoC:

```
python3 -m litex_boards.targets.colognechip_gatemate_evb --toolchain peppercorn --cpu-type serv --build
```

LiteX writes `build/<target>/gateware/build_<target>.sh` and runs it. For the EVB SoC it is:

```
yosys -l <target>.rpt <target>.ys        # read_verilog ...; synth_gatemate -luttree -nomx8 -top <target>
nextpnr-himbaechel-gatemate --json <target>.json --vopt out=<target>.txt --device CCGM1A1 \
    --vopt ccf=<target>.ccf --router router2 --timing-allow-fail --seed 1 --freq 24
gmpack <target>.txt <target>.bit
```

LiteX picks `nextpnr-himbaechel-gatemate` from `PATH` when it exists, else `nextpnr-himbaechel`. Its BIOS needs a RISC-V GCC on `PATH` (e.g. `riscv-none-elf-gcc`). That SoC builds in 36 s. Our versions: LiteX `8e0e71c`, LiteICLink `cb6cd0c` (2026-10-20).

## Test setups

| # | Hardware | Link | Tests |
|---|---|---|---|
| 1 | one GateMate EVB | one way: its SerDes TX cabled to its own RX | PHY: lock, comma alignment, PRBS bit-error count |
| 2 | two ULX5M-GS boards | two way: TX of each to RX of the other | PHY both ways, then SerWB: board A reads and writes board B's memory and CSRs |

SerWB needs both directions (a read returns data), so it runs on setup 2 only. Setup 1 checks the PHY before two boards are involved.

## Simulation

The SerDes in simulation is our open-source [SerDes BFM](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/1.phy/2.serdes-model) from openCologne-PCIE: a behavioural `CC_SERDES` with the vendor model's module name, ports and parameters, checked against it. No NDA model needed. Verilator runs our RTL with the BFM in place of the hard macro: the eduBOS5 RTL executes the test firmware, so no co-simulation (VProc) is needed. Each test case passes or fails on its own.

| Test case | Mirrors | Setup | Pass |
|---|---|---|---|
| `phy_oneway` | setup 1 | one PHY, BFM TX looped to its RX | lock and alignment within a bound; 0 PRBS errors; a flipped bit on the line is counted |
| `serwb_twoway` | setup 2 | two eduBOS5 SoCs, two BFMs, lines crossed | eduBOS5 A writes then reads back B's RAM and a B CSR (PeakRDL); data matches; the link recovers after one side is reset |

Unit tests, run now (`make -C 3.iclink-sv/2.sim`):

| Test | Checks |
|---|---|
| `sim_8b10b` | the SV 8b/10b against LiteX's own `code_8b10b.py`, bit for bit; round trip; running disparity |
| `sim_top` | the board top's 8b/10b self-test: a clean run, then a one-bit error must light the error |

## QA

Our standard RTL QA flow, the same as openPCIE, wireguard-fpga and openCologne-PCIE. Scripts in `3.iclink-sv/3.build/`, sources from `3.iclink-sv/1.hw/top.filelist`. Run from the repo root:

| Command | Checks |
|---|---|
| `bash 7.SerDes/3.iclink-sv/3.build/run-lint.sh` | Lint, 0 findings to pass: `/*LINT:OK*/` tags, Verilator `-Wall`, Yosys `check` (loops, drivers, latches), slang `-Wextra`, Verible style rules. Waivers: `run-lint-waivers.txt` |
| `bash 7.SerDes/3.iclink-sv/3.build/run-format.sh [--check]` | Verible format in the project style (`begin`/`end`, alignment, 100 columns); `--check` only lists unformatted files |
| `bash 7.SerDes/3.iclink-sv/3.build/run-leq.sh <gold 1.hw> <gate 1.hw>` | Yosys formal equivalence of two RTL versions: proves a cleanup changes no behaviour |

Tools: Yosys with read_slang (openXC7 or OSS CAD Suite), Verilator, Verible, python3. CI runs lint (`.github/workflows/lint.yml`) and Verible (`verible.yml`) on every push and pull request.

### Community Outreach
- [2025-08-10](https://www.linkedin.com/feed/update/urn:li:activity:7359764905572376577?commentUrn=urn%3Ali%3Acomment%3A%28activity%3A7359764905572376577%2C7360217016948985856%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287360217016948985856%2Curn%3Ali%3Aactivity%3A7359764905572376577%29)
- [2025-02-21](https://www.linkedin.com/posts/patrick-urban-086177251_gatemate-fpga-colognechip-activity-7298662301677551616-4sw0?utm_source=share&utm_medium=member_desktop&rcm=ACoAAAJv-TcBSi_5ff0VNMrInrT-xg44YF3jnyU)

### End of Document
