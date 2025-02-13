# Veerwolves - daisy chain Veerwolf core SoCs
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

This work was inspired by the link referenced in the main README of the Stress Test folder. In particular, it investigates how Cologne Chip's GateMate handles larger cores and explores the maximum number of these that can be integrated into a daisy chain configuration. Given that a 222,400 LUT6 FPGA can accommodate roughly 18 cores, successfully fitting even one or two cores would be considered a success.

Unlike Corescore, this design features a more homogenous logic mapping (Corescore was just a lot of independent cores feeding into a wide mux) . Each SoC incorporates several interconnect conversions—primarily from AXI to WB and back—which are confined locally due to the daisy chain configuration. This setup exemplifies the FPGA’s short-wiring capabilities and raises questions about how densely the logic can be packed and what impact this may have on timing performance.

## Build steps

## Results and analysis