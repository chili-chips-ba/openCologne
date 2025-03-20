# PNR_TESTS

These tests were originaly written by Mike Reznikov and they can be found on the link: https://github.com/mirekez/pnr_tests

There are three different topologies implemented in pnr_tests, with the flexibility to add more. Each topology is composed of Nodes, where each Node implements a combinational logic function and currently contains no registers. An array of data is collected from random inputs, passed through the entire pipeline, and routed to random output pins. Additionally, a small random subset of data bits is designated as control signals and connected to both the logic function control inputs and flow control pins.

## Pipeline
The simplest topology is a PIPELIN - a linear sequence of Nodes. Currently, registers between Nodes are inserted randomly, often resulting in very long chains. A small patch was added to enforce register insertion between Nodes, helping to shorten these chains.

## Mesh
The next topology is MESH - it is X*Y 2D array of Nodes. Signal arrives to all rows simultaneously. Each pair of neighboring rows randomly swaps portions of their data between corresponding Nodes. This results in a lot of diagonal data paths between them.

## Star
The last topology, referred to as STAR, closely resembles the PIPELINE structure but differs in that control signals from the first Node are distributed to all other Nodes. This results in random high fanout during data processing. Integrating multiple topologies within a single design is beneficial and not difficult to implement.

Each Node randomly implements functions like MUX/DEMUX, QUEUE, MATH (MUL/DIV), ENCODER/DECODER, and possibly more.

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
| CC_BRAM_20K                   | 9        | 5            | /       |
| CC_BUFG                       | 1        | 1            | 1       |
| CC_DFF                        | 1385     | 171          | 14140   |
| CC_IBUF                       | 36       | 36           | 68      |
| CC_LUT1                       | 18       | /            | 166     |
| CC_LUT2                       | 640      | 50           | 3519    |
| CC_LUT3                       | 1650     | 109          | 8825    |
| CC_LUT4                       | 1210     | 159          | 7268    |
| CC_MX4                        | 30       | 7            | 2597    |
| CC_MX8                        | 6        | /            | 28      |
| CC_OBUF                       | 34       | 34           | 66      |
| CC_MULT                       | /        | 1            | 59      |



## WIP
At the moment we are still working on porting these tests onto the Gowin GW2AR-18C with the goal of comparing it with CCGM1A1.

### End-of-Document
