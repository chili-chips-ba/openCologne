<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Test setups

The same tests run in simulation and on boards: the sim mirrors each hardware setup ([2.sim](../3.iclink-sv/2.sim/README.md)). Back to the [7.SerDes README](../README.md).

<p align="center">
  <img width="100%" alt="Test jig: simulation with two eduBOS5 SoCs and two SerDes BFMs, lines crossed; setup 1 one GateMate EVB with TX cabled to its own RX; setup 2 two ULX5M-GS boards crossed at 1.25, 2.5 and 5 Gb/s, with a host PC on the UART console; setup 3 a ULX5M-GS (GateMate) to a ULX4M-LD (Lattice ECP5, LiteICLink) at 2.5 Gb/s, the most both sides take" src="iclink-testjig.drawio.png">
</p>

| # | Hardware | Link | Tests | In simulation |
|---|---|---|---|---|
| 1 | one GateMate EVB | one way: its SerDes TX cabled to its own RX | PHY: lock, comma alignment, PRBS bit-error count; the FIFO pump, looped back | `sim_phy_oneway`, `sim_top` |
| 2 | two ULX5M-GS boards | two way: TX of each to RX of the other, at 1.25, 2.5 and 5 Gb/s | PHY both ways, then SerWB: board A reads and writes board B's memory and CSRs | `sim_phy_twoway`, `sim_link_ppm`; `serwb_twoway` (planned) |
| 3 | ULX5M-GS (GateMate) and ULX4M-LD (Lattice ECP5) | two way, GateMate to ECP5, at 2.5 Gb/s: the most both sides take | interoperability with LiteICLink on ECP5: PHY both ways, then Serial Wishbone across the two vendors | `interop_twoway` (planned) |

Setup 1 checks the PHY before two boards are involved. Etherbone needs both directions (a read returns data): setups 2 and 3, with the host PC on board A's UART console. Two boards run on two oscillators, so setups 2 and 3 depend on [clock correction](clock-correction.md).

## Setup 3: GateMate to Lattice ECP5

Our IC Link must talk to LiteICLink on a Lattice ECP5, not only to itself.

| | GateMate side | ECP5 side |
|---|---|---|
| Board | ULX5M-GS (CCGM1A1) | ULX4M-LD v2 (LFE5UM5G-85F; the ULX4M-LS has an LFE5U, without SerDes) |
| SerDes | `CC_SERDES`, our PHY | ECP5 DCU, LiteICLink `SerDesECP5` |
| Words per clock | 8 (64-bit) at 31.25 MHz | 2 (16-bit) at 125 MHz |
| Reference clock | 100 MHz | 100 MHz, own oscillator |
| Line | 2.5 Gb/s, 8b/10b | 2.5 Gb/s, 8b/10b |
| Other rates | 1.25 Gb/s from 100 MHz; 5 Gb/s from 100 MHz | 1.25 Gb/s from 100 MHz; 5 Gb/s needs a 200 or 250 MHz reference |

Both boards are CM4 modules. The ULX4M-LD routes its SerDes lane to the CM4 PCIe pins (`PCIe_TX/RX/CLK` in LiteX-Boards' `radiona_ulx4m_ld_v2`); the ULX5M-GS routing is to be confirmed on its schematic. Two CM4 carriers with a PCIe x1 connector, and a cable crossing TX to RX, make the link. The two reference clocks are independent, so each receiver recovers its own clock.

Steps, each one passing before the next:

1. **PHY, data both ways.** Commas, then a counter stream as 8b/10b data, checked on each side. Not PRBS: LiteICLink sends its PRBS raw on the line, ours travels as 8b/10b D characters (see [Compared with LiteICLink](../3.iclink-sv/1.hw/README.md#compared-with-liteiclink)), so the two PRBS checkers do not match. This step also settles the bit order within a symbol, the byte order within a word, and the pair polarity between the two SerDes.
2. **Serial Wishbone across the vendors.** eduBOS5 on the GateMate writes and reads a RAM and a CSR of a LiteX SoC on the ECP5, then the other way round. Upstream LiteICLink has no Serial Wishbone on the ECP5 transceiver (its SerWB PHYs are Xilinx and Efinix I/O SerDes, and a low-speed generic one). The ECP5 side therefore needs a small adapter: `SERWBCore` on `SerDesECP5`, two 16-bit PHY words per 32-bit SerWB word. We would offer it to LiteICLink together with the GateMate PHY.
3. **CRC across the vendors.** The negative test of setup 2, with one side on each vendor.

This setup is level 3 of the [interoperability proof](serwb-protocol.md#interoperability-proof): LiteICLink itself generates and checks the traffic on the ECP5 side.

In simulation, setup 3 is mirrored by `interop_twoway` (planned): our PHY on the SerDes BFM on one side; on the other, LiteX's own 8b/10b encoder and decoder at 2 words per clock, converted to Verilog, standing in for the ECP5 DCU.

#### End-of-Document
