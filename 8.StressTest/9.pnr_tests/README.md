# PNR_TESTS

These tests were originaly written by Mike Reznikov and they can be found on the link: https://github.com/mirekez/pnr_tests

The tests present a generic Verilog generator. By playing with parameters, different parts of design can be converted to RAM/SRL/DSP blocks. It also generates a constraints file to randomly assign pins.

We have ported these tests to run for the CologneChip CCGM1A1. The resaults that we got by running these tests can be found in the table below:

|            CCGM1A1            | TestMesh | TestPipeline | TestStar |
|-------------------------------|----------|--------------|----------|
| Number of wires:              | 3214     | 385          | 15627   |
| Number of wire bits:          | 26257    | 2535         | 136324  |
| Number of public wires:       | 554      | 134          | 4890    |
| Number of public wire bits:   | 10566    | 1386         | 51507   |
| Number of ports:              | 8        | 8            | 8       |
| Number of port bits:          | 70       | 70           | 134     |
| Number of memories:           | 0        | 0            | 0       |
| Number of memory bits:        | 0        | 0            | 0       |
| Number of processes:          | 0        | 0            | 0       |
| Number of cells:              | 8195     | 781          | 55996   |
| $scopeinfo                    | 52       | 18           | 503     |
| CC_ADDF                       | 3124     | 190          | 18756   |
| CC_BRAM_20K                   | 9        | 5            | 1       |
| CC_BUFG                       | 1        | 1            | 14140   |
| CC_DFF                        | 1385     | 171          | 68      |
| CC_IBUF                       | 36       | 171          | 166     |
| CC_LUT1                       | 18       | 36           | 3519    |
| CC_LUT2                       | 640      | 50           | 8825    |
| CC_LUT3                       | 1650     | 109          | 7268    |
| CC_LUT4                       | 1210     | 159          | 59      |
| CC_MX4                        | 30       | 1            | 2597    |
| CC_MX8                        | 6        | /            | 28      |
| CC_OBUF                       | 34       | 34           | 66      |



## WIP
At the moment we are still working on porting these tests onto the Gowin GW2AR-18C with the goal of comparing it with CCGM1A1.

### End-of-Document
