# Theoretical analysis of the architecture


## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Along with benchmark designs we've dedicated this folder to theoretical analysis of the GateMate's architecture through means of software. For now we're addressing logic capabilities of the LUT trees and the quality of the unique routing network. 
## LUT tree logic capacity
LUT trees are missing some logic functionality of the traditional LUTs and here we assess the difference by the means of brute-force. The provided `lut_logic.py` python program  counts the number of feasible distinict logic functions by each LUT4, L2T4 and L2T5. Although there are more possible combinations of configurations in LUT tree topologies, there seem to be a lot of truth table copies in the end. Here are the numbers:

|  Structure(n-input logic functions)                         | LUT4 (4-input) | L2T5 (4-input) | L2T4 (4-input) | 8-input LUT tree (8-input) |
|---------------------------|----------------|----------------|----------------|----------------------------|
| # of distinct logic functions | 65536/65536         | 912/65536            | 520/65536            | 671848/2<sup>256</sup>       |

Interestingly, LUT trees of 8 inputs resulted in 671848 distinct functions of 8 inputs, which is just a fraction of 2<sup>256</sup> possible 8 input logic functions.
### Reproduction steps
8-input LUT tree is analyzed using cuda, running on a GPU since it requires 2<sup>256</sup>  computation operations. You might want to commment out l2t8() line since even with GPU acceleration, requires almost an hout to compute.
```
python3 lut_logic.py
```
The output should look something like this:
```
Number of distinct 4-input logic functions that can be implemented in:
LUT4: 65536 (runtime: 0.22s)
L2T4: 912 (runtime: 0.42s)
L2T5: 520 (runtime: 0.02s)
L2T8: 671848 (runtime: 53m 40.23s) //8-input functions actually
```
## Routing network architecture assessment

This part relies on network theory and provided documentation from CologneChip to derive some theoretical limits of the routing architecture, ruling out the routing tool's ability when evaluating the quality of the architecture.

Work is organized in a python notebook, generating the network model and running tests on the model. Sometimes later a VTR approach might replace the python framework, but for now it remains a purely theoretical consideration.