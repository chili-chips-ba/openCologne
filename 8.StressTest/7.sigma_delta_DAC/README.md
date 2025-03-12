# Sigma-Delta Digital-to-Analog Converter — A DSP Use Case

This example is about an FPGA implementation of a Sigma-Delta Digital-to-Analog Converter (SD DAC). It aims to evaluate logic utilization of two different FPGA architectures: GateMate CCGM1A1 (20/40K LUT-Trees) and Gowin Arora GW2AR-18CQN88 I8/I7 (20k LUT4). The RTL comes from @aimamovic6  [Sigma-Delta-DAC](https://github.com/aimamovic6/Sigma-Delta-DAC) repository; please refer to it for the complete design detail.

![alt text](image.png)  


We synthesized the RTL using vendor official toolchains, and extracted utilization metrics from their reports.

## Sigma-Delta DAC and GateMate Architecture

This test evaluates how GateMate handles mathematically intensive DSP applications — a key area of interest (also see [this](https://github.com/chili-chips-ba/openCologne/issues/58) discussion). 

Note that **CCGM1A1 does not feature dedicated Hard Macros for math functions, aka DSP HMs**, whereas Gowin and most other alternatives do. On the other hand, the CologneChip CPEs can be configured as:
- `1 or 2-bit full adder`, expandable to any length in horizontal or vertical arrangements.
- `2×2-bit multiplier`, expandable to any multiplier size.

The Sigma-Delta DAC is a highly pipelined design. It implements digital filtering and Sigma-Delta modulation functions. The filter is of the Cascaded Integrator-Comb (CIC) type, which does not need multiplication. Consequently, this design calls primarily for the full-adder combos and pipeline flops. Such scenario favors GateMate, as the multiplication would for Gowin and others be typically offloaded to DSP HMs.

![alt text](image-1.png)


## Logic Utilization 

Contrary to expectations, the CCGM1A1 uses 33% more logic resources than the Gowin Arora LUT4-based architecture — mostly due to the unavaliability of DSP HMs, which are conveniently and automatically inferred by Gowin tools from the generic RTL. 

As a separate test, we then configured the Gowin tools **not to use the DSP HMs** (which is not their default setting). The GateMate has for such unnatural setting outscored the Gowin by quite a margin for the LUTs, with about the same number of flip-flops.

> Gowin "ALU" is implemented in its LUT, i.e. it is a primitive that utilizes LUTs to generate arithmetic logic. It is in that sense similar to the GateMate CPE arithmetic modes. This Gowin ALU number can serve as a metric for how much of the design is dedicated to math functionality. Even when utilizing the HM DSPs, more than half of this design are math functions, confirming the validity of the SD-DAC design for the math-centric test case.

| **Resource Type**         | **GW2AR-18LVQN88 C8/I7 (default)** | **CCGM1A1**       |  **GW2AR-18LVQN88 C8/I7 w/o DSP HMs**| 
|---------------------------|-------------------------|-------------------|---------------------------------|
| **Logic (LUT / CPEs)**   | 2306(1127 LUT, 1179 ALU) | 3528 (CPEs)     | 	4828(1945 LUT, 2883 ALU) |
| **Registers (Flip-Flops)**     | 2230                   | 2238       | 2230 |
|**DSP HM (MULT36x36)**       | 3                       | N/A             | 0 |
|    **DSP HM MULTALU36X18**|1 | N/A|0|

LUT-trees score a clear win over traditional LUTs w/o DSP HM in math functionality. However, we also ought to account for the number of configuration bits needed to implement this circuit. We use it as a metric of chip area consumed by the design. The LUT-tree structure of a CPE takes up 28 configuration bits, while a single LUT4 takes up 16 configuration bits. Doing some basic math, this ends up to be `3528*28 = 98784` configuration bits for the CCGM1A1, versus `4828*16=77248` configuration bits for the GW2AR-18C. 

This analysis highlights the importance of DSP HM, which is the deciding factor for a clear win in this test. Even in no-DSP-HM comparison of logic capacity, LUT wins over LUT-tree in total area metric.

## Fmax Comparison
CCGM1A1 with all default tool settings outperforms GW2AR-18C in configuration w/o DSP HMs (non-default option), though not by much. When Gowin DSP HM is allowed, the tables turn drasticaly and indisputably in favor of the Gowin FPGA.
- **Gowin GW2AR-18C:**  
  - Clock44KHz: 174.6 MHz  
  - Main Clock:  70.2 MHz
- **Gowin GW2AR-18C w/o DSP:**  
  - Clock44KHz: 169.1 MHz  
  - Main Clock:  16.1 MHz
- **CCGM1A1 (GateMate):**  
  - Clock44KHz: 68.43 MHz  
  - Main Clock: 21.3 MHz

### Conclusion

The lack of DSP HMs is hurting the CCGM1A1 capability in math applications, both in terms of logic capacity and Fmax. Even in the highly pipelined structures with basic arithmetic, the LUT-tree GateMate struggles to match the efficiency of traditional LUT4 + DSM HM architectures. The GateMate, which is a 28nm device, falls behind an older 55nm FPGA. 

GataMate didn't particularly excel in this pipelined math-based design. 
