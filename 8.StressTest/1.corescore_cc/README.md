# CORESCORE - how many Servs can a FPGA serv?
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

This is a popular metric, determining FPGA's logic capacity, routing algortihm and architectural ability to use all of the FPGA. We were able to achieve **54** cores with Fmax of **22.93 MHz**, when using `-tm 3` PnR "worst" timing setting. PnR log avaliable under `fusesoc_libraries/corescore/pnr51.log`

## Results and analysis
### Tools disclosure
Obviously, comparing results obtained pushing the test sources through open-source yosys and propriatary softwares isn't an apples to apples comparison. In an attempt to minimize this gap, and find the real potential of the GateMate's architecture we conducted a reference yosys benchmark to the "golden standard" propriatary syntehsis tool (Gowin). Later, all results can potentially be adjusted to account for the defficiencies in tools. We didn't test the PnR tools since there are no alternatives for them usually. 
Through testing on a single data point of 10 Serv cores, the following data was obtained, comparing propriatary Gowin syntehsis with open-source yosys synthesis.
| **Resource** | **Yosys**                     | **Proprietary**                   |
|--------------|-------------------------------|-----------------------------------|
| **LUT**      | 1784 / 20736     | 1603 / 20736         |
| **Register** | 1451 / 15750     | 1229 / 15750         |
| **Block RAM**| 5 / 46           | 5 / 46              |

### Test results
These tests have been verified on the real system.
```
Utilization Report

 CPEs                  20037 /  20480  ( 97.8 %)
 -----------------------------------------------
   CPE Registers       13921 /  40960  ( 34.0 %)
     Flip-flops        13921
     Latches               0

 GPIOs                     3 /    144  (  2.1 %)
 -----------------------------------------------
   Single-ended            3 /    144  (  2.1 %)
     IBF                   2
     OBF                   1
     TOBF                  0
     IOBF                  0


 Block RAMs             26.0 /     32  ( 81.3 %)
 -----------------------------------------------
   BRAM_20K                1 /     64  (  1.6 %)
   BRAM_40K               25 /     32  ( 78.1 %)
   FIFO_40K                0 /     32  (  0.0 %)

 PLLs                      1 /      4  ( 25.0 %)
 GLBs                      1 /      4  ( 25.0 %)
 SerDes                    0 /      1  (  0.0 %)
```

Considering that only 34% of sequential logic is utilized, but all Cologne Programmable Elements (CPEs) are fully utilized, it can be concluded that nearly all combinatorial elements are consumed. This positions the 20.5k CPE CologneChip GateMate FPGA alongside other FPGAs with similar capacities. 


Notably, the GateMate's architecture, with 20.5k CPEs, effectively provides 41k LUT4 equivalents, as each CPE comprises an 8-input LUT-tree, which can be configured as two 4-input L2T4 primitives. Due to the reduced number of configuration bits required by this architecture, we can compute the normalized metric of **configuration bits per core** (the lower, the better). Throughput is computed by this formula: `core_count/technology`

| FPGA Model         | Core Count | Configuration Bits per Core | LUT4 Count | Technology | Throughput |
|--------------------|-----------|-----------------------------|------------|------------|-------------|
| 10CL025YU256C8G   | 60        | 6666                        | 25k          | LP 20nm    | 3        |
| CCGM1A1-BGA324    | 55        | 9102                        | 41k        | LP 28nm    |    1.964     |
| LFE5U-25F-6BG256C | 61        | 7069                        | 24.3k      | LP 40nm    | 1.525        |
| EP4CE10F17I7N     | 54        | 5770                        | 22k       | 60nm       | 0.9        |

This indicates that the CCGM1A1 has a lower effective logic density per area unit, as measured by configuration bits per core. Conversely, CCGM1A1 shines in throughput per dollar, holding strong against the competition.

## Build steps
Put Yosys and GateMate p_r in PATH, and make sure you have FuseSoC installed:
```
pip install fusesoc
```
Navigate to 1.corescore_cc
```
cd 8.StressTest/1.corescore_cc/
```
Build FuseSoC target cc_gatemate
```
fusesoc run --target=cc_gatemate corescore
```

At this point your design should've successfully generated a bitstream. Uploading the bitstream to your board:
```
cd 8.StressTest/1.corescore_cc/
make program
```
Listen to serial port at **57600 baud rate 8b no parity, 1 stop bit**, your output should be something like this, with xx ranging from `00` to `number_of_cores-1`:
```
core xx says hello
```

If for any reason you want to change the number of cores instantated, simply go to `fusesoc_libraries/corescore/corescore.core`, under targets find `cc_gatemate`, and change the count in the following line to a desired number of cores
```
generate: [corescorecore: {count: 55}]
```
**RTL functional simulation**:
If for any reason you need debugging, there's a `sim` target provided, requiring Verilator. Waveform visualisation is left to the user.

