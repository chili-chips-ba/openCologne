# CORESCORE - how many Servs can a FPGA serv?
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

This is a popular metric, determining FPGA's logic capacity, routing algortihm and architectural ability to use all of the FPGA. We were able to achieve 54 cores on the following utilization numbers: on 22.93 MHz. PnR log avaliable under `fusesoc_libraries/corescore/pnr51.log`

## Build steps
### Prerequisites

## Results and analysis
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
   LVDS pairs              0 /     72  (  0.0 %)
     IBF                   0
     OBF                   0
     TOBF                  0
     IOBF                  0

 GPIO Registers            0 /    288  (  0.0 %)
 -----------------------------------------------
   FF_IBF                  0
   FF_OBF                  0
   IDDR                    0
   ODDR                    0

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
- de0_nano	61 [22k LUT4]
- cyc1000	60 [25k LUT4]
- colorlight_5a75b	55 [24.3k LUT4]

Notably, the GateMate's architecture, with 20.5k CPEs, effectively provides 41k LUT4 equivalents, as each CPE comprises an 8-input LUT-tree, which can be configured as two 4-input L2T4 primitives. Due to the reduced number of configuration bits required by this architecture, we can compute the normalized metric of **configuration bits per core** (the lower, the better). Throughput is computed by this formula: `core_count/technology`

| FPGA Model         | Core Count | Configuration Bits per Core | LUT4 Count | Cores per Dollar | Technology | Throughput per Dollar |
|--------------------|-----------|-----------------------------|------------|------------------|------------|----------------------|
| 10CL025YU256C8G   | 60        | 6666                        | 25k        | 2.158            | LP 20nm    | 108                  |
| CCGM1A1-BGA324    | 55        | 9102                        | 41k        | 2.347            | LP 28nm    | 83.85                |
| LFE5U-25F-6BG256C | 61        | 7069                        | 24.3k      | 2.77             | LP 40nm    | 72.37                |
| EP4CE10F17I7N     | 54        | 5770                        | 22k        | 1.07             | 60nm       | 17.83                |

This indicates that the CCGM1A1 has a lower effective logic density per area unit, as measured by configuration bits per core.