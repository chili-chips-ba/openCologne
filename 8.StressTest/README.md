# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Assess Fmax and realistic utilization, injecting routing congestion and pushing the clock distribution network to its limits.

Cologne Chip GateMate A1 FPGA makes use of a peculiar and novel architecture in 

Unveiling real potential of the CologneChip GateMate A1 FPGA, we ran several benchmark tests, usually comparing to similar size FPGA's of established vendors. Here below is a list of these benchmarks along with a brief overview of the strategies they employ. To run these tests head over to individual subfolders, where detailed instructions with result analysis await you!
- [Corescore](https://corescore.store) -- popular FPGA benchmark fitting as many [Serv](https://github.com/olofk/serv) cores as possible
- LUTRAM_Stress_test -- address the distributed asynchronous read RAM capacity of the FPGA, **a suspected weakspot**
- [VeerWolves](https://www.linkedin.com/posts/gsteiert_wearealtera-activity-7240773845098323970-Bvlj?utm_source=share&utm_medium=member_desktop) -- similar formulation to corescore, but a different challenge: the SOC has grown!
- [fpga_torture](https://github.com/stnolting/fpga_torture) -- power + utilization test


References:
>- https://github.com/mirekez/pnr_tests
   
        - this is a generic Verilog generator
        - by playing with parameters different part of design can be converted to RAM/SRL/DSP blocks
        - also generates XDC to randomly assign pins, this is auxiliary functionality tied to Xilinx and dialects for other vendors can be done

>- https://www.linkedin.com/posts/gsteiert_wearealtera-activity-7240773845098323970-Bvlj?utm_source=share&utm_medium=member_desktop
>- https://github.com/chipsalliance/VeeRwolf/tree/veerwolves
>- https://aignacio.com/posts/hdls/mpsoc_riscv
>- https://github.com/stnolting/fpga_torture
>- https://corescore.store
>- https://gitlab.com/x653/spaceinvaders-fpga

**<h3>  End of Document </h3>**
