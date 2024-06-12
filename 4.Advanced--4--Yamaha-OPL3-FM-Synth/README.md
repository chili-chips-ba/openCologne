# openCologne - Yamaha OPL3 FM Audio Synth
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

This is a triple exciting port of @gtaylormb [project](https://github.com/gtaylormb/opl3_fpga) to _Yosys_ and _GateMate_ FPGA.
 - **Excitment#1**: Original design is super cool on its own, as it is about the heart of the uber-popular _SoundblasterPro_ audio card from the turbulent '90s.
 - **Excitment#2**: RTL is written in, for opensource, unusally rich  complement of _SystemVerilog_. The original project had vetted this RTL only with Xilinx-proprietary Vivado. These two circumstances make this codebase a formidable [challenge](https://github.com/chili-chips-ba/openCologne/issues/3) for opensource [Yosys](https://github.com/YosysHQ/yosys) synthesis. And yes, with every challenge comes an opportunity :blush:.
 - **Excitment#3**: As of yet, there are no GateMate designs of this complexity. We are therefore buckled up for a fun, bumpy rollercoaster ride. 

Regarding excitment/challenge#2, having tried [Synlig plugin](https://github.com/chipsalliance/synlig) and [Yosys-Slang](https://github.com/povik/yosys-slang), we ended up converging on @zachjs's [SV2V](https://github.com/zachjs/sv2v). This can also be viewed as an independant validation and confirmation of @pu-cc's advice on the opensource flow that works best for _SystemVerilog_.

To get started, first install SV2V and other tools, as explained in [0.doc](https://github.com/chili-chips-ba/openCologne/blob/main/0.doc/1.README.Tool-Installs.txt). Then:
```
% cd 3.build
% make synth
```

This OPL3 design produces 100% digital audio in I2S format. To hear anything, it needs to be complemented with an external compatible audio CODEC, such as:
> - https://github.com/goran-mahovlic/ulx3s-extensions
> - https://www.waveshare.com/wm8960-audio-board.htm
   
For fun, also see OPL3 software emulators. Beware, they are not as good and not as precise as this pure hardware, re-engineered Yamaha chip. 
> - https://github.com/Wohlstand/libADLMIDI
> - https://github.com/nukeykt/Nuked-OPL3


#### End of Document
