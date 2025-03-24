# PNR_TESTS

These tests were originaly written by Mike Reznikov and they can be found on the link: https://github.com/mirekez/pnr_tests

There are three different topologies implemented in pnr_tests, with the flexibility to add more. Each topology is composed of Nodes, where each Node implements a combinational logic function and currently contains no registers. An array of data is collected from random inputs, passed through the entire pipeline, and routed to random output pins. Additionally, a small random subset of data bits is designated as control signals and connected to both the logic function control inputs and flow control pins. Each Node randomly implements functions like MUX/DEMUX, QUEUE, MATH (MUL/DIV), ENCODER/DECODER, and possibly more.

## Pipeline
The simplest topology is a PIPELINE, a linear sequence of Nodes. Currently, registers between Nodes are inserted randomly, often resulting in very long chains. A small patch was added to enforce register insertion between Nodes, helping to shorten these chains.

![pnr_tests](doc/Pipeline.png) 

## Mesh
The MESH topology consists of an X×Y two-dimensional array of Nodes. Signals are broadcast to all rows simultaneously. Neighboring row pairs randomly exchange portions of their data between corresponding Nodes, resulting in multiple diagonal data paths across the mesh.

![pnr_tests](doc/Mesh.png) 

## Star
The last topology, referred to as STAR, closely resembles the PIPELINE structure but differs in that control signals from the first Node are distributed to all other Nodes. This results in random high fanout during data processing. Integrating multiple topologies within a single design is beneficial and not difficult to implement.

![pnr_tests](doc/Star.png) 


## Test results (WIP)
The tables below show the results of our comparison between the GateMate CCGM1A1 and Gowin's GW2AR-18 LQ176.


### Mesh test results

|          **GateMate**        |**CCGM1A1**|          **Gowin**     | **GW2AR-18LQ176** |  **Delta**   |
|------------------------------|----------|-----------------------------|------------|-----------------|
| Number of wires:             | 3214     | Number of wires:            | 3791       |       -577      |
| Number of wire bits:         | 26257    | Number of wire bits:        | 15027      |       11230     |
| Number of public wires:      | 554      | Number of public wires:     | 3791       |       -3237     |
| Number of public wire bits:  | 10566    | Number of public wire bits: | 15027      |       -4461     |
| Number of ports:             | 8        | Number of ports:            | 8          |       0         |
| Number of port bits:         | 70       | Number of port bits:        | 70         |       0         |       
| Number of memories:          | 0        | Number of memories:         | 0          |       0         |
| Number of memory bits:       | 0        | Number of memory bits:      | 0          |       0         |
| Number of processes:         | 0        | Number of processes:        | 0          |       0         |
| Number of cells:             | 8195     | Number of cells:            | 3834       |       4361      |
| $scopeinfo:                  | 52       | $scopeinfo:                 | 52         |       0         |
| CC_ADDF:                     | 3124     | ALU:                        | 933        |       /         |
| CC_BRAM_20K:                 | 9        | DFFE:                       | 54         |       /         |
| CC_BUFG:                     | 1        | DFFR:                       | 249        |       /         |
| CC_DFF:                      | 1385     | DFF:                        | 715        |       670       |
| CC_IBUF:                     | 36       | IBUF:                       | 36         |       0         |
| CC_LUT1:                     | 18       | LUT1:                       | 123        |       -105      |
| CC_LUT2:                     | 640      | LUT2:                       | 135        |       505       |
| CC_LUT3:                     | 1650     | LUT3:                       | 773        |       877       |
| CC_LUT4:                     | 1210     | LUT4:                       | 413        |       797       |
| CC_MX4:                      | 30       | MUX2_LUT5:                  | 161        |       /         |
| CC_MX8:                      | 6        | RAM16SDP4:                  | 72         |       /         |
| CC_OBUF:                     | 34       | OBUF:                       | 34         |       0         |


### Pipeline test results

|          **GateMate**        |**CCGM1A1**|        **Gowin**      |  **GW2AR-18LQ176**    |  **Delta** |
|------------------------------|----------|------------------------------|------------|-----------------|
| Number of wires:             | 385      | Number of wires:             | 1472       |       -1087     |
| Number of wire bits:         | 2535     | Number of wire bits:         | 3150       |       -615      |
| Number of public wires:      | 134      | Number of public wires:      | 1472       |       -1338     |
| Number of public wire bits:  | 1386     | Number of public wire bits:  | 3150       |       -1764     |
| Number of ports:             | 8        | Number of ports:             | 8          |       0         |
| Number of port bits:         | 70       | Number of port bits:         | 70         |       0         |       
| Number of memories:          | 0        | Number of memories:          | 0          |       0         |
| Number of memory bits:       | 0        | Number of memory bits:       | 0          |       0         |
| Number of processes:         | 0        | Number of processes:         | 0          |       0         |
| Number of cells:             | 781      | Number of cells:             | 1635       |       -854      |
| $scopeinfo:                  | 18       | $scopeinfo:                  | 18         |       0         |
| CC_ADDF:                     | 190      | ALU:                         | 149        |       /         |
| CC_BRAM_20K:                 | 5        | RAM16SDP4:                   | 100        |       /         |
| /                            | /        | DFFRE:                       | 65         |       /         |
| /                            | /        | DFFE:                        | 40         |       /         |
| CC_BUFG:                     | 1        | DFFR:                        | 30         |       /         |
| CC_DFF:                      | 171      | DFF:                         | 66         |       105       |
| CC_IBUF:                     | 36       | IBUF:                        | 36         |       0         |
| CC_LUT1:                     | /        | LUT1:                        | 112        |       -112      |
| CC_LUT2:                     | 50       | LUT2:                        | 114        |       -64       |
| CC_LUT3:                     | 109      | LUT3:                        | 206        |       -97       |
| CC_LUT4:                     | 159      | LUT4:                        | 391        |       -232      |
| CC_MX4:                      | 7        | MUX2_LUT5:                   | 161        |       /         |
| CC_MX8:                      | /        | MUX2_LUT6                    | 46         |       /         |
| /                            | /        | MUX2_LUT7                    | 17         |       /         |
| /                            | /        | MUX2_LUT8                    | 4          |       /         |
| CC_OBUF:                     | 34       | OBUF:                        | 34         |       0         |
| CC_MULT                      | 1        | /                            | /          |       /         |


### Star test results

|          **GateMate**        |**CCGM1A1**|        **Gowin**      |  **GW2AR-18LQ176**    |  **Delta** |
|------------------------------|----------|------------------------------|------------|-----------------|
| Number of wires:             | 15627    | Number of wires:             | 27267      |       -11640    |
| Number of wire bits:         | 136324   | Number of wire bits:         | 67519      |       68805     |
| Number of public wires:      | 4890     | Number of public wires:      | 27267      |       -22377    |
| Number of public wire bits:  | 51507    | Number of public wire bits:  | 67519      |       -16012     |
| Number of ports:             | 8        | Number of ports:             | 8          |       0         |
| Number of port bits:         | 134      | Number of port bits:         | 134        |       0         |       
| Number of memories:          | 0        | Number of memories:          | 0          |       0         |
| Number of memory bits:       | 0        | Number of memory bits:       | 0          |       0         |
| Number of processes:         | 0        | Number of processes:         | 0          |       0         |
| Number of cells:             | 55996    | Number of cells:             | 23995      |       32001     |
| $scopeinfo:                  | 503      | $scopeinfo:                  | 503        |       0         |
| CC_ADDF:                     | 18756    | ALU:                         | 7117       |       /         |
| CC_BRAM_20K:                 | /        | RAM16SDP4:                   | 649        |       /         |
| /                            | /        | DFFRE:                       | 522        |       /         |
| /                            | /        | DFFE:                        | 638        |       /         |
| /                            | /        | DFFR:                        | 325        |       /         |
| CC_BUFG:                     | 1        | DFFS:                        | 55         |       /         |
| CC_DFF:                      | 14140    | DFF:                         | 2894       |       11246     |
| CC_IBUF:                     | 68       | IBUF:                        | 68         |       0         |
| CC_LUT1:                     | 166      | LUT1:                        | 903        |       -737      |
| CC_LUT2:                     | 3519     | LUT2:                        | 3164       |       355       |
| CC_LUT3:                     | 8825     | LUT3:                        | 2959       |       5866      |
| CC_LUT4:                     | 17268    | LUT4:                        | 3212       |       14056     |
| CC_MX4:                      | 2597     | MUX2_LUT5:                   | 918        |       /         |
| CC_MX8:                      | 28       | /                            | /          |       /         |
| CC_OBUF:                     | 66       | OBUF:                        | 66         |       0         |
| CC_MULT                      | 59       | /                            | /          |       /         |


### End-of-Document
