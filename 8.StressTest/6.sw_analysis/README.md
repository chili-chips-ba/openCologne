# Theoretical analysis of the architecture


## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Along with benchmark designs we've dedicated this folder to theoretical analysis of the GateMate's architecture through means of software. For now we're addressing logic capabilities of the LUT trees and the quality of the unique routing network. 
## LUT tree logic capacity
LUT trees are missing some logic functionality of the traditional LUTs and here we assess the difference by the means of brute-force. The provided `lut_logic.py` python program  counts the number of feasible distinict logic functions by each LUT4, L2T4 and L2T5. Although there are more possible combinations of configurations in LUT tree topologies, there seem to be a lot of truth table copies in the end. Here are the numbers:

|                           | LUT4   | L2T5 | L2T4 |
|--------------------------------------|--------|------|------|
| # of distinct 4-input logic functions | 65,536 | 912  | 520  |
### Reproduction steps
```
python3 lut_logic.py
```

## Routing network architecture assessment

This part relies on network theory and provided documentation from CologneChip to derive some theoretical limits of the routing architecture, ruling out the routing tool's ability when evaluating the quality of the architecture.

Work is organized in a python notebook, generating the network model and running tests on the model. Sometimes later a VTR approach might replace the python framework, but for now it remains a purely theoretical consideration.