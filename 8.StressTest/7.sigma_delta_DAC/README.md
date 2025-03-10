# Sigma-Delta Digital-to-Analog Converter — A DSP Case

This repository presents an implementation of a Sigma-Delta Digital-to-Analog Converter (DAC) on an FPGA, with a focus on evaluating logic utilization across different FPGA architectures. The design is based on the [Sigma-Delta-DAC](https://github.com/aimamovic6/Sigma-Delta-DAC) repository; please refer there for more details on the implementation.

We synthesized the RTL through the respective proprietary toolchains and obtained utilization results. The target comparison FPGA is the Gowin Arora GW2AR-18CQN88 I8/I7 (20k LUT4).

## Sigma-Delta DAC and GateMate Architecture

This test evaluates how well the GateMate platform handles DSP applications—a key area of interest. Note that **CCGM1A1 does not include any dedicated DSP hardware macros (DSP HMs)**, whereas the Gowin alternative does, which puts GateMate at a disadvantage from the start.

The Sigma-Delta DAC design is highly pipelined and features digital filtering and Sigma-Delta modulation—operations that are mathematically intensive. The CC CPEs are capable of performing standalone arithmetic, so we do not expect significant drawbacks in logic utilization. These CPEs can be configured to:
- Implement a 1-bit or 2-bit full adder, expandable to any length in horizontal or vertical arrangements.
- Function as a 2×2-bit multiplier, expandable to any multiplier size.


![alt text](image.png)  

In this implementation, the digital interpolation filter used is a Cascaded Integrator-Comb (CIC) filter, which requires no multiplication and has limited storage requirements, as shown in the image below. Consequently, the design relies primarily on pipelining and addition. This scenario favors GateMate, since multiplication would typically be offloaded to HM macros in Gowin—but for this comparison, we are focusing solely on the logic resources.


![alt text](image-1.png)


## Logic Utilization in Sigma-Delta DAC Implementations

Contrary to expectations, the CCGM1A1 uses 33% more logic resources than the Gowin LUT4-based alternative—likely due to the limitations of LUT-tree logic. The number of flip-flops is nearly identical between the two platforms, and other resource differences are negligible.

| **Resource Type**         | **GW2AR-18CQN88 C8/I7** | **CCGM1A1**       |
|---------------------------|-------------------------|-------------------|
| **Logic (LUT + ALU / CPEs)**   | 2,306                   | 3,528 (CPEs)     |
| **Registers (Flip-Flops)**     | 2,230                   | 2,238            |

### Conclusion

Even in highly pipelined structures featuring mostly basic arithmetic, LUT-tree logic struggles to match the efficiency of traditional LUT4 implementations.