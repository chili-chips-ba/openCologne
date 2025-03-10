# Sigma-Delta Digital-to-Analog Converter (DAC) on FPGA

This repository presents the implementation of a Sigma-Delta Digital-to-Analog Converter (DAC) on a Field-Programmable Gate Array (FPGA), focusing on evaluating logic utilization across different FPGA architectures.

## Overview of Sigma-Delta DAC

Sigma-Delta DACs employ oversampling and noise-shaping techniques to achieve high-resolution digital-to-analog conversion. By oversampling the input signal and shaping the quantization noise, these converters push noise out of the signal band, allowing for simpler analog filtering and improved signal fidelity.&#8203;:contentReference[oaicite:0]{index=0}

## Logic Utilization in Sigma-Delta DAC Implementations

:contentReference[oaicite:1]{index=1}&#8203;:contentReference[oaicite:2]{index=2}

- **Interpolation Filter (IF):** :contentReference[oaicite:3]{index=3}&#8203;:contentReference[oaicite:4]{index=4}
- **Sigma-Delta Modulator:** :contentReference[oaicite:5]{index=5}&#8203;:contentReference[oaicite:6]{index=6}
- **Digital-to-Analog Conversion and Analog Low-Pass Filter (LPF):** :contentReference[oaicite:7]{index=7}&#8203;:contentReference[oaicite:8]{index=8}

:contentReference[oaicite:9]{index=9} :contentReference[oaicite:10]{index=10}&#8203;:contentReference[oaicite:11]{index=11}

| Resource Type             | Implementation A (GW2AR-18CQN88 C8/I7) | Implementation B (CCGM1A1) |
|----------------------------|----------------------------------------|-----------------------------|
| Logic (LUT + ALU / CPEs)   | 2,306 (1,127 LUT, 1,179 ALU)           | 3,528 (CPEs)                |
| Registers (Flip-Flops)     | 2,230                                  | 2,238                       |

*&#8203;:contentReference[oaicite:12]{index=12}*&#8203;:contentReference[oaicite:13]{index=13}

## Insights from Existing Implementations

:contentReference[oaicite:14]{index=14}&#8203;:contentReference[oaicite:15]{index=15}

- **Simple Accumulator-Based Sigma-Delta DAC:** :contentReference[oaicite:16]{index=16} :contentReference[oaicite:17]{index=17}&#8203;:contentReference[oaicite:18]{index=18}

- **Second-Order Sigma-Delta DACs:** :contentReference[oaicite:19]{index=19} :contentReference[oaicite:20]{index=20}&#8203;:contentReference[oaicite:21]{index=21}

- **FPGA-Based Sigma-Delta Converters:** :contentReference[oaicite:22]{index=22} :contentReference[oaicite:23]{index=23}&#8203;:contentReference[oaicite:24]{index=24}

:contentReference[oaicite:25]{index=25}&#8203;:contentReference[oaicite:26]{index=26}

For more detailed information and access to the implementation files, please refer to the original repository: [Sigma-Delta-DAC](https://github.com/aimamovic6/Sigma-Delta-DAC).
