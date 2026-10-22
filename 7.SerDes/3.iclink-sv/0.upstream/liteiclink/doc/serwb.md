# SerWB

SerWB extends a Wishbone bus to another FPGA over 3 I/Os (clock + TX + RX), using LVDS (high-speed
PHYs) or single-ended I/Os (generic low-speed PHY). Accesses are encapsulated in Etherbone records
over a small packet layer with 8b10b line coding.

```
          FPGA A                                                       FPGA B
+--------+    +-----------+    +------------+        +------------+    +-----------+    +--------+
|        | WB | SERWBCore |    |  SERWBPHY  |--clk-->|  SERWBPHY  |    | SERWBCore | WB |        |
|  SoC   +--->|  "slave"  +--->|  "master"  |--tx--->|  "slave"   +--->| "master"  +--->| Periph |
|        |<---+           |<---+            |<--rx---+            |<---+           |<---+        |
+--------+    +-----------+    +------------+        +------------+    +-----------+    +--------+
```

- `SERWBCore(mode="slave")`: exposes a Wishbone **slave** (`core.bus`) to the local SoC.
- `SERWBCore(mode="master")`: drives a Wishbone **master** (`core.bus`) on the remote side.
- The PHY in `mode="master"` generates the link clock and controls link initialization. The other
  side must use `mode="slave"`.

## PHYs

| Module                          | Devices                                         | Line rate              |
|---------------------------------|-------------------------------------------------|------------------------|
| `liteiclink.serwb.phy.SERWBPHY` | Xilinx 7-Series (`xc7a/k/v/z/s`)                | 8 bits/cycle (DDR 4x)  |
|                                 | Xilinx UltraScale(+) (`xcku`, `xvu`, `xczu`)    | 8 bits/cycle (DDR 4x)  |
|                                 | Efinix Titanium (`Ti*`), Trion (`T1*`/`T2*`)    | 8 bits/cycle, `clk_ratio` 1:1/1:2/1:4 |
| `liteiclink.serwb.genphy.SERWBPHY` | Vendor agnostic (SDR I/Os)                   | 1 bit/cycle            |

Each 32-bit word is sent as 40 bits on the line (8b10b). For example, a 7-Series PHY with a 156.25MHz
`sys` clock runs at 1.25Gbps, which is 31.25M words/s.

## Link initialization

1. Master sends IDLE patterns (zeroes) to reset Slave.
2. Master sends K28.5 commas. Slave calibrates (delay/bitslip scan, centers the sampling window).
3. Slave sends K28.5 commas. Master calibrates.
4. Master, then Slave, stop sending commas. The link is ready (`phy.init.ready`).

If no valid sampling window is found, `phy.init.error` is set. The master can restart initialization
by writing the `control_reset` CSR. When the link is down, `SERWBCore` holds its internal logic in
reset (`with_rst_on_link_down=True`), and the `"slave"` core answers Wishbone accesses with `err`
instead of stalling the bus.

### CSRs (`<phy>_control_*`)

| CSR                                   | Description                                         |
|---------------------------------------|-----------------------------------------------------|
| `reset` (master only)                 | Restart link initialization.                        |
| `ready`, `error`                      | Link status.                                        |
| `delay`, `delay_min(_found)`, `delay_max(_found)`, `phase` | Sampling window calibration results (high-speed PHYs). |
| `shift`                               | Word alignment (bitslip) result.                    |
| `prbs_start`, `prbs_cycles`, `prbs_errors` | PRBS link test.                                |
| `invalid_errors`                      | Invalid 8b10b words received since link ready.      |

With `with_crc=True`, the core also has a `crc_errors` CSR (packets dropped on CRC error).

## Protocol

Packet layer (32-bit words):

| Word | Content                                            |
|------|----------------------------------------------------|
| 0    | Preamble `0x5aa55aa5`                              |
| 1    | `[7:0]` port, `[23:8]` length (bytes)              |
| 2..  | Payload (`length/4` words)                         |
| last | CRC32 over header + payload (only with `with_crc=True`) |

Port 0 carries Etherbone (one record per packet, 32-bit address/data, no probing/address spaces).
Other ports can be used by user endpoints (`core.add_downstream_endpoint`/`add_upstream_endpoint`),
for example `SERIOCore` (default port 1), which forwards 32 static/slow I/Os. Packets for ports not
registered on the receiving side are dropped. Incomplete packets are dropped after
`depacketizer_timeout` (default 1ms without incoming data).

Without CRC, bit errors on the link corrupt accesses silently. `with_crc=True` (on both sides) adds a
CRC32 word to each packet. The receiver stores each packet, checks it, and forwards it only when
valid. A dropped write is lost and a dropped read times out on the SoC bus, but corrupted data never
reaches the bus.

A single 32-bit access costs 7 words on the link (2 packet + 2 Etherbone + 1 record header + 1
address + 1 data). Writes are posted (acked once sent), reads are blocking round trips.

## Parameters

`SERWBCore(phy, clk_freq, mode, with_rst_on_link_down=True, port=0, ...)`:

| Parameter                | Default | Description                                                   |
|--------------------------|---------|---------------------------------------------------------------|
| `etherbone_buffer_depth` | 4       | Etherbone record buffering (data words).                      |
| `tx_buffer_depth`        | auto    | TX FIFO depth (default: one full packet, min 8).              |
| `rx_buffer_depth`        | auto    | RX FIFO depth (default: one full packet, min 8, +16 with flow control). |
| `depacketizer_timeout`   | 1e-3    | Incomplete packet timeout (seconds without incoming data).    |
| `with_crc`               | False   | Per-packet CRC32. Invalid packets are dropped (both sides).   |
| `crc_max_words`          | auto    | Largest payload accepted with CRC (default: Etherbone packet, min 16). |

`SERWBPHY(..., with_flow_control=False)`: optional link level flow control. It must be enabled on
**both** sides because it changes the wire format. Idle words are sent as K28.1 fill characters
(not zeroes), and the receiving core pauses the remote transmitter with XOFF (K28.3) / XON (K28.4)
characters when its RX buffer is almost full. Enable it when the remote side can be slower than the
link (slow peripherals, posted write bursts, user ports with backpressure). Without it, RX
overflows silently lose data.

## Integration

### Wishbone SoC

```python
from liteiclink.serwb.phy  import SERWBPHY
from liteiclink.serwb.core import SERWBCore

# FPGA A (SoC side).
self.serwb_phy  = SERWBPHY(platform.device, platform.request("serwb"), mode="master")
self.serwb_core = SERWBCore(self.serwb_phy, sys_clk_freq, mode="slave")
self.bus.add_slave("serwb", self.serwb_core.bus, SoCRegion(origin=0x30000000, size=0x10000000))

# FPGA B (remote side).
self.serwb_phy  = SERWBPHY(platform.device, platform.request("serwb"), mode="slave")
self.serwb_core = SERWBCore(self.serwb_phy, sys_clk_freq, mode="master")
self.bus.add_master("serwb", self.serwb_core.bus)
```

### AXI-Lite / AXI SoC

SerWB natively exposes Wishbone. In a LiteX SoC with `bus_standard="axi-lite"` or `"axi"`,
`add_slave`/`add_master` insert the LiteX bridges automatically (`AXILite2Wishbone`,
`AXI2Wishbone`/`Wishbone2AXI*` in `litex.soc.interconnect.axi`). Outside a SoC, bridge explicitly:

```python
from litex.soc.interconnect.axi import AXILiteInterface, AXILite2Wishbone

axi_lite = AXILiteInterface(data_width=32, address_width=32)
self.axi2wb = AXILite2Wishbone(axi_lite, self.serwb_core.bus)
```

Limitations:
- AXI bursts are split into single beats by the bridges, and each beat is a separate SerWB access.
- `AXILite2Wishbone` does not translate Wishbone `err` into `SLVERR`, so with the link down, AXI
  accesses stall until the SoC bus timeout instead of returning an error.

## Tests and benches

- Unit tests: `python3 -m pytest -v test/test_serwb_*.py` (init, packet layer, end-to-end link
  over loopback/datapath PHY models, flow control, CRC, SerIO, AXI-Lite).
- Simulation: `bench/serwb/sim.py` (LiteX/Verilator with the generic PHY, `--write-stress`,
  `--read-stress`, `--alt-stress`, `--with-serio`, `--with-debug` for latency measurements).
- Hardware: `bench/serwb/` board targets and `bench/serwb/test_serwb.py`.

## Possible improvements

- Burst/coalesced Etherbone records (multiple words per record) for higher throughput.
- Scrambling (`with_scrambling` in the datapath) is experimental and not exposed by the PHYs.
