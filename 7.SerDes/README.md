# SerDes App for GateMate
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Design a high-speed serial, memory-mapped Chip-to-Chip (C2C) Interconnect. The goal of such IP is to set the stage for creating compute clusters and Hyper Cubes made of GateMate FPGAs, all interconnected via SerDes, with our C2C layer on top of it.

# References:
- Xilinx PG046 - [Aurora 8B/10B](https://docs.amd.com/r/en-US/pg046-aurora-8b10b/Introduction?tocId=Tqe8wtK9r1zAUq13hUnVEw)
    - Xilinx SP002 - [Aurora 8B/10B Protocol Spec](https://docs.amd.com/v/u/en-US/aurora_8b10b_protocol_spec_sp002)
- BerkeleyLab [ChitChat](https://berkeleylab.github.io/Bedrock/_gen_md/serial_io/chitchat/README_md.html) protocol
- LiteX [IC Link](https://github.com/enjoy-digital/liteiclink)
- [Transputer](http://www.bitsavers.org/components/inmos/transputer/C011_Link_Adaptor.pdf)-like?
- CologneChip [SerDes example design](https://github.com/pu-cc/gm_serdes_lb) and latest [datasheet](https://colognechip.com/docs/ds1001-gatemate1-datasheet-latest.pdf)
- [MesaBusProtocol](https://github.com/blackmesalabs/MesaBusProtocol)
- Timing-aware/better PNR for this high-speed design:
    - [Project Peppercorn](https://github.com/YosysHQ/prjpeppercorn)
    - [nextpnr for GateMate](https://github.com/YosysHQ/nextpnr/tree/gatemate)

### Public Announcements
[2025-02-21](https://www.linkedin.com/posts/patrick-urban-086177251_gatemate-fpga-colognechip-activity-7298662301677551616-4sw0?utm_source=share&utm_medium=member_desktop&rcm=ACoAAAJv-TcBSi_5ff0VNMrInrT-xg44YF3jnyU)

### End of Document
