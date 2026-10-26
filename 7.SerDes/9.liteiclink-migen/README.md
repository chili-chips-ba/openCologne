# LiteICLink port, Migen prototype
## Block Diagram

```
                           ┌────────────────────────────────────────────────────────────────────────────┐
                           │                                sys_clk Domain                              │
                           │────────────────────────────────────────────────────────────────────────────│
                           │ • Inputs:                                                                  │
                           │     – sys_clk                                                              │
                           │     – CSR writes: _tx_enable(1), _rx_enable(1),                            │
                           │       _tx_prbs_config(2), _rx_prbs_config(2), _rx_prbs_pause(1)            │
                           │ • CSRStatus reads: _tx_ready(1), _rx_ready(1), _rx_prbs_errors(32)         │
                           │ • MultiReg synchronizers → “tx” and “rx” clock domains                     │
                           │ • Reset & Lock FSM:                                                        │
                           │     - reset_cnt → adpll_reset                                              │
                           │     - lock_cnt → cdr_locked                                                │
                           │     - drives tx_reset_done → tx_ready, rx_reset_done → rx_ready            │
                           └──────────────────────────────────┬─────────────────────────────────────────┘
                                                              |
                       ┌───────────────────────────┐          |                 ┌───────────────────────────┐
                       │      Clock Buffering      |          |                 │      Clock Buffering      | 
                       │───────────────────────────|          |                 │───────────────────────────|            
                       │ • Instance CC_BUFG:       |◀────────┘───────────────▶│ • Instance CC_BUFG:       |
                       |    - txoutclk → cd_tx.clk │                            |    - rxoutclk → cd_rx.clk │                      
                       └────────────┬──────────────┘                            └─────────────┬─────────────┘
                                    |                                                         |
┌───────────────────────────────────▼──────────────────────┐     ┌────────────────────────────▼─────────────────────────────┐
│                   cd_tx Domain                           |     │                       cd_rx Domain                       |       
│──────────────────────────────────────────────────────────|     │──────────────────────────────────────────────────────────|
│ 1) 8b/10b Encoder (ClockDomainsRenamer “tx”)             |     │ 1) Bus Unpacking                                         │
│     – Inputs: sink.data[8·nbytes], sink.ctrl[nbytes]     │     │     – rx_data[8*i:8*(i+1)] ← rx_bus[8*i:8*(i+1)]         |
│     – Outputs: encoder.output (10-bit symbols + K flags) │     │     – disp_flags (K bits)                                |
│                                                          │     │                                                          │
│ 2) PRBSTX                                                │     │ 2) PRBSRX                                                │
│     – i ← encoder.output                                 │     │     – i ← rx_data                                        │
│     – config ← synced tx_prbs_config                     │     │     – config ← synced rx_prbs_config                     │
│     – o → PRBS bit-stream                                │     │     – errors → MultiReg → sys_clk (rx_prbs_errors)       │
│                                                          │     │                                                          │
│ 3) Datapath MUX                                          │     │ 3) 8b/10b Decoders                                       │
│     – If prbs_config ≠ 0: tx_data ← PRBS.o               │     │     – d,i ← rx_data, disp_flags                          │
│       Else:            tx_data ← encoder.output          |     │     – outputs: decoder.d → source.data,                  |
|                                                          |     |                decoder.k → source.ctrl                   │
|                                                          │     │ 4) source.valid = 1                                      │
│ 4) Bus Packing                                           │     └─────────────────────────┬────────────────────────────────┘
│     – tx_bus[8*i:8*(i+1)] ← tx_data[8*i:8*(i+1)          │                               |
│                                                          │                               |
│ 5) sink.ready = 1                                        |                               |
└─────────────────────────┬────────────────────────────────┘                               | 
                          |                                                                |
                          |                                                                |
                          |                                                                |
                          |                                                                |
              ┌───────────▼────────────────────────────────────────────────────────────────▼───────────────┐ 
              │                                     CC_SERDES Primitive                                    │
              │────────────────────────────────────────────────────────────────────────────────────────────│
              │ • Params p_PLL_…, p_TX_…, p_RX_…, loopback, 8b/10b enable, comma align…                    │
              │                                                                                            │
              │ • Clocks & resets:                                                                         │
              │     – i_TX_CLK_I = cd_tx.clk                                                               │
              │     – i_TX_RESET_I = tx_reset (from FSM)                                                   │
              │     – o_TX_RESET_DONE_O → tx_reset_done                                                    │
              │     – o_PLL_CLK_O → txoutclk                                                               │
              │     – i_RX_CLK_I = cd_rx.clk                                                               │
              │     – i_RX_RESET_I = rx_reset                                                              │
              │     – o_RX_RESET_DONE_O → rx_reset_done                                                    │
              │     – o_RX_CLK_O → rxoutclk                                                                │
              │                                                                                            │
              │ • Data I/O:                                                                                │
              │     – i_TX_DATA_I  = tx_bus                                                                │
              │     – o_RX_DATA_O  = rx_bus                                                                │
              │     – i_LOOPBACK_I = internal_loopback ? 0b010 : 0b000                                     │
              │                                                                                            │
              │ • Physical pads (optional):                                                                │
              │     – o_TXP/o_TXN                                                                          │
              │     – i_RXP/i_RXN                                                                          │
              └────────────────────────────────────────────────────────────────────────────────────────────┘
                                                           

   ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────┐
   │                                               Stream Interface                                          │
   │─────────────────────────────────────────────────────────────────────────────────────────────────────────│
   │ • sink Endpoint (sys_clk):                                                                              │
   │     – data[8·nbytes] → cd_tx.encoder.d                                                                  │
   │     – ctrl[nbytes]  → cd_tx.encoder.k                                                                   │
   │     – ready = 1                                                                                         │
   │ • source Endpoint (cd_rx):                                                                              │
   │     – data[8·nbytes] ← cd_rx.decoder.d                                                                  │
   │     – ctrl[nbytes]  ← cd_rx.decoder.k                                                                   │
   │     – valid = 1                                                                                         │
   └─────────────────────────────────────────────────────────────────────────────────────────────────────────┘

```


## Status: does not build

`4.migen/liteiclink/serdes/serdes_gm.py` (the Migen GateMate PHY prototype) stops before synthesis, with the current LiteX (`d2b47282a`) as with the earlier one: `SyntaxError: keyword argument repeated: p_PLL_REF_RTERM`. The `CC_SERDES` instance sets `p_PLL_REF_RTERM` twice (lines 192 and 212). Its other undefined names were found earlier. The prototype stays as the team left it, for reference; the working PHY is the SystemVerilog one in [`../3.iclink-sv`](../3.iclink-sv), with its LiteX wrapper in [`../3.iclink-sv/4.litex`](../3.iclink-sv/4.litex).

## Workflow Overview
Folder layout and build steps, kept for reference: the prototype does not build (above), and the Makefile still points at `1.hw` and `4.sim`, which this folder doesn't have.

### 2.sw

In the [2.sw](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/2.sw) is a modified version of the [LiteX Demo Application](https://github.com/enjoy-digital/litex/tree/master/litex/soc/software/demo) that will include generated CSR from the migen target file in the `main.c` function. There lie the control function for the datapath in the bare-metal C.
The UART console is built upon the official demo application. 

### 3.build

Here in the [3.build](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/3.build) folder we have the [Makefile](https://github.com/chili-chips-ba/openCologne/blob/main/7.SerDes/9.liteiclink-migen/3.build/Makefile) that divides the LiteX workflow into different parts. Running `make help` lists the commands:

```
$ make help
Usage:
  make open-target     file=<name>
  make open-example    file=<proj>
  make build-board     [FREQ=..] [OPTIONS='..']
  make load            [FREQ=..] [OPTIONS='..']
  make term            [PORT=..]
  make build-sw        [DEMO_FLAGS='..']
  make sim
  make view-sim
  make clean-sim
  make setup-ethernet  [ETH_IFACE=..] [STATIC_IP=..]
  make start-server
  make stop-server
  make litescope
  make clean
  make copy-migen
```

The most important ones are:

* `make build-board` which runs the LiteX build for the GateMate target. The command has parameters `FREQ` and `OPTIONS` which can be overloaded.

* `make build-sw` which compiles the bare-metal C application. Run the command after the build finishes because the compiler depends on the generated files in the `3.build/build` folder.

* `make load` simply loads the bitstream onto the FPGA via the JTAG programmer
  
* `make term` opens up the serial console in the terminal to control the datapath signals. The default port is `/dev/ttyUSB0` while that can be simply changed with `PORT`.

**NOTE**: Run `make term` in a separate terminal before running `make load`

### 4.migen
The [4.migen](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/4.migen) folder contains two subfolders:

* [liteiclink](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/4.migen/liteiclink/serdes) which has the file that should be copied in the liteiclink litex folder
  
* [litex_boards](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/4.migen/litex/litex-boards/litex_boards) which has:
  [platforms](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/4.migen/litex/litex-boards/litex_boards/platforms) which has the specific platform file that specifies the pins of the board
  [targets](https://github.com/chili-chips-ba/openCologne/tree/main/7.SerDes/9.liteiclink-migen/4.migen/litex/litex-boards/litex_boards/targets) has the target file that specifies all of the important parts of the CPU design and instantiates the SoC.

**NOTE**: Right now you need to copy these subfolders with the files manually in your LiteX install, under `litex-boards/litex_boards`.
