<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Serial Wishbone: the protocol

LiteICLink's Serial Wishbone (SerWB) as our port keeps it, so it interoperates: why the link needs Etherbone and the packetizer, the frame, how interoperability is proven, whether data can look like a preamble, and how SerWB compares with PCIe. The RTL: [`3.iclink-sv/1.hw`](../3.iclink-sv/1.hw/README.md). Back to the [7.SerDes README](../README.md).

## Why Etherbone and the packetizer

They make the link memory-mapped: eduBOS5 on chip A loads or stores to an address window, and the access runs on chip B's bus with no software on B.

- **Etherbone** turns one Wishbone access (address, data, read or write, byte enables) into a record and runs it on the far bus; a read returns its data, so A's load just waits.
- **The packetizer** frames each record (preamble, port, length, optional CRC32), so the receiver finds its start, drops broken ones and resyncs after an error.

When B only needs to receive data, Etherbone is not needed, but the packetizer still is: it carries user streams on its other ports. The [FIFO pump](fifo-pump.md) moves words between the two CPUs on port 2, in standard SerWB packets, so it interoperates with LiteICLink.

## Serial Wishbone frame

The format of LiteICLink `8ef8d79`, which our port keeps so it interoperates. The packet layer is in RTL (`iclink_serwb_tx.sv`, `iclink_serwb_rx.sv`); Etherbone is not yet. Sources:

- the SerWB spec: [LiteICLink `doc/serwb.md`, Protocol](https://github.com/enjoy-digital/liteiclink/blob/master/doc/serwb.md#protocol), implemented in [`serwb/packet.py`](https://github.com/enjoy-digital/liteiclink/blob/master/liteiclink/serwb/packet.py); our copy: [`3.iclink-sv/0.upstream/liteiclink/doc/serwb.md`](../3.iclink-sv/0.upstream/liteiclink/doc/serwb.md). LiteICLink added this document on 2026-10-21 (`175c81e`), with its SerWB review; before, the format was only in the code;
- Etherbone: CERN's [Etherbone core](https://ohwr.org/projects/etherbone-core), as implemented in LiteEth's [`frontend/etherbone.py`](https://github.com/enjoy-digital/liteeth/blob/master/liteeth/frontend/etherbone.py), which LiteICLink reuses.

At a glance:

<p align="center"><img width="100%" alt="A Serial Wishbone packet, left to right: idle fill, preamble, port, length, zero byte, payload (Etherbone on port 0, FIFO pump on port 2), CRC32, idle fill" src="serwb-packet-simple.drawio.png"></p>

In detail, word by word and on the line:

<p align="center"><img width="100%" alt="Serial Wishbone packet: preamble, port and length, payload (Etherbone on port 0, FIFO pump on port 2), CRC32; on the line, 8b/10b symbols with K28.1 fill, K28.5 comma and XON/XOFF between packets" src="serwb-packet.drawio.png"></p>

**Packet**, in 32-bit words:

| Word | Content |
|---|---|
| 0 | preamble `0x5AA55AA5` |
| 1 | `[7:0]` port, `[23:8]` payload length in bytes, `[31:24]` 0 |
| 2 .. | payload, length / 4 words |
| last | CRC32 over the header and payload, only with `with_crc` (both sides) |

**Packet size.** The format allows up to 65532 payload bytes (16383 words, `length[23:10]`); the receiver ignores `length[9:8]`, so the payload is whole words. A real receiver sets a smaller limit:

| Receiver | Largest payload | Set by |
|---|---|---|
| LiteICLink without CRC (`Depacketizer`) | 16383 words | the format only; it buffers nothing |
| LiteICLink with CRC (`CRCDepacketizer`) | `max_words`: 64 by default; in `SERWBCore` `crc_max_words`, default max(16, the Etherbone packet): 16 | its store-and-forward buffer |
| This core, FIFO pump (port 2) | `MAX_WORDS`, default 16 (`PKT_WORDS`) | the parameter; the RX FIFO is the buffer |

A larger payload is dropped at the header and counted. Both ends must agree: the sender's `PKT_WORDS` must not exceed the receiver's limit. The packet on the line is the payload + 3 words (preamble, port/length, CRC32).

The receiver hunts for the preamble, reads port and length, and forwards the payload to that port. Unknown ports are dropped; a packet that stops arriving is dropped after a 1 ms timeout; with CRC, a bad packet is dropped and counted in `crc_errors`.

**Port 0 carries Etherbone**, one record per packet, 32-bit addresses and data (CERN's Etherbone, as cut down in LiteICLink: no probing, no address spaces):

| Payload word | Content |
|---|---|
| 0 | Etherbone header: magic `0x4E6F`, version 1, flags `nr` / `pr` / `pf`, `addr_size`, `port_size` |
| 1 | Etherbone header, rest (zero) |
| 2 | record header: flags (`bca`, `rca`, `rff`, `cyc`, `wca`, `wff`), `byte_enable`, `wcount`, `rcount` |
| 3 | write: base address; read: return address |
| 4 .. | write: `wcount` data words; read: `rcount` addresses to read |

**One 32-bit write**, A to B: 7 words, 8 with CRC.

| Word | Value |
|---|---|
| 0 | `0x5AA55AA5` |
| 1 | port 0, length 20 bytes |
| 2, 3 | Etherbone header |
| 4 | record header, `wcount` = 1, `rcount` = 0 |
| 5 | address |
| 6 | data |
| (7) | CRC32 |

Writes are posted: acknowledged once sent. **A read** is a round trip: A sends a record with `rcount` = 1 (return address, then the address to read); B reads its bus and answers with a record with `wcount` = 1 (return address, then the data).

**On the line.** Each 32-bit word is 4 bytes, each an 8b/10b symbol (data as D characters). Between packets the line carries control symbols, K flag set, in byte 0 of a word:

| Symbol | Use |
|---|---|
| K28.5 | comma: alignment at link start-up |
| K28.1 | fill when there is nothing to send (with flow control; without it, zero words). Ours, while the link is down: K28.5 in byte lane 0 and K28.0 in lane 4 |
| K28.3 / K28.4 | XOFF / XON: pause and resume the far transmitter (flow control, both sides) |

**On our PHY**, 8 symbols per clock: two SerWB words per 31.25 MHz clock (W = 2; at W = 4, four on every other clock, [FIFO pump](fifo-pump.md)), the first in bytes 0-3, the second in bytes 4-7, each K flag with its byte. LiteICLink's 4-symbol SerWB encoder is then replaced by the PHY's 8-symbol path ([compared with LiteICLink](../3.iclink-sv/1.hw/README.md#compared-with-liteiclink)): interoperability is at the packet layer.

**Will it work with Lattice and others?** SerWB is not a standard; it is LiteICLink's own protocol, and LiteICLink is its only reference. It works with another vendor when the other side runs LiteICLink's SerWB core, and both sides agree below it:

- **8b/10b:** standard (IBM), the same code tables in LiteX and in `CC_SERDES`;
- **bit and byte order on the line, polarity:** set by each SerDes; to be measured on test setup 3 (ECP5);
- **framing and Etherbone:** identical by construction, when we port the core bit-exact and check it against LiteX's model, as for 8b/10b.

So it is proven only by test.

### Interoperability proof

Read the [frame](#serial-wishbone-frame) above; prove interoperability against LiteX's own code.

**The proof uses LiteX's own SerWB code.** LiteICLink's packetizer, depacketizer, CRC and Etherbone (Python / Migen) generate the traffic our RTL must produce, and check the traffic our RTL sends. An error in our understanding of the format then shows up as a mismatch against LiteX itself. Three levels, each with LiteX on the other side:

| Level | LiteX side (generator / checker) | Our side | Proves |
|---|---|---|---|
| 1. Vectors | LiteICLink `Packetizer` / `Depacketizer` (`serwb/packet.py`), run in Migen, write packet vectors, as `gen_8b10b_vectors.py` does for 8b/10b | our packetizer and depacketizer in Verilator | bit-exact packets: preamble, port, length, payload, CRC32 |
| 2. LiteICLink's tests | its own test cases (`test/test_serwb_packet.py`: loopback, CRC loopback, corrupted packet dropped, oversized packet dropped, zero length, timeout; `test_serwb_link.py`: Wishbone, byte enables, unknown port) | the same cases run against our RTL | same behaviour, error cases included |
| 3. Silicon | LiteICLink SoC on the ECP5 (test setup 3) | IC Link on the GateMate | the same over a real link, both directions |

The 8b/10b, PRBS and SerWB packet ports pass level 1 against LiteX's own models (`code_8b10b.py`, `prbs.py`, `serwb/packet.py`). Level 1 runs with `make -C 7.SerDes/3.iclink-sv/2.sim`. Level 2: planned. Level 3: on the bench.

## Can data look like a preamble?

**Short answer:** yes, and SerWB does not prevent it. Any 32-bit payload word can dress up as `0x5AA55AA5`. The link stays safe because the receiver does not rely on the preamble alone.

### How the receiver keeps its place

The receiver (`Depacketizer`, `serwb/packet.py`) is a small state machine:

1. **Between packets** it compares each word with the preamble.
2. **On a match** it reads the next word: port and length. A zero length ends the packet there.
3. **Inside the packet** it counts `length` bytes and passes them on, **without looking at what they hold**. A payload word that equals the preamble is just data here.
4. **After the last word** (and the CRC32, when on) it goes back to step 1.

So while the receiver is in step, data can never be taken for a preamble: it never searches inside a packet.

### When it can go wrong

Only after the receiver has **lost count**: a bit error in the length, a word lost on the line, or a reset in the middle of a packet. It may then be back at step 1 while the sender is still in a payload, and a payload word that equals the preamble starts a **false packet**. That false packet still has to pass:

| Check | Without CRC | With CRC (`with_crc`) |
|---|---|---|
| the port is one the receiver knows | yes | yes |
| the length is not zero | yes | yes |
| the length is at most `crc_max_words` | no | yes |
| the CRC32 over header and payload matches | no | yes: a false packet passes 1 time in 2^32 |
| a packet that stops arriving is dropped after 1 ms | yes | yes |

With CRC, a false packet is dropped and counted in `crc_errors`; the receiver finds the next real preamble and is back in step. Without CRC, a false packet can reach the bus.

### How likely

- A random payload word equals the preamble 1 time in 2^32 (4.3 x 10^9).
- A false packet that gets through needs three things in a row: a lost count (itself an error event), a preamble-like word, and a passing CRC32. That is about 2^-64 after an already rare framing error.
- For scale: at 2.5 Gb/s and a bit error rate of 10^-12, the line sees one bit error about every 400 s.

### What we do

- **CRC on**, both sides: the default for the FIFO pump.
- **A sequence number** in the first word of each pump message, so the firmware notices a dropped or false message.

### The structural alternative

Protocols that must never mistake data for framing mark each packet start with an 8b/10b **K symbol**, which data cannot produce: PCIe uses STP and SDP. With that, a lost count is found at the next packet start, whatever the data. SerWB uses K symbols only between packets, not to start one, so adding a K-symbol start would break compatibility with LiteICLink. We keep SerWB as it is, with CRC.

### Compared with PCIe

In SerWB the K symbols do not delimit packets: they fill the gaps and carry flow control, and packets are found by the preamble and the length. PCIe Gen1/Gen2 (also 8b/10b) is the opposite: K symbols are the framing.

| Symbol | Code | PCIe role |
|---|---|---|
| STP | K27.7 | start of a TLP (transaction packet) |
| SDP | K28.2 | start of a DLLP (link packet: ACK/NAK, flow-control credits) |
| END | K29.7 | end of a good packet |
| EDB | K30.7 | end of a bad (nullified) packet |
| COM | K28.5 | starts every ordered set (training, SKP); alignment |
| SKP | K28.0 | clock compensation between the two ends' clocks |
| FTS / IDL / PAD | K28.1 / K28.3 / K23.7 | fast training, electrical idle, padding |

Data never produces these symbols, so a PCIe receiver that lost its place finds the next packet at the next STP or SDP, whatever the data held.

| | SerWB (LiteICLink) | PCIe Gen1/2 |
|---|---|---|
| Packet start | preamble `0x5AA55AA5`, a data word | STP / SDP, a K symbol |
| Packet end | counting `length` | END / EDB, a K symbol |
| Integrity | CRC32, optional | LCRC always; ECRC optional |
| A bad packet | dropped, never resent | NAK, then replayed from the sender's buffer: no loss |
| Flow control | XOFF / XON (K28.3 / K28.4) | credits in UpdateFC DLLPs |
| Clock compensation | none in LiteICLink; ours: a clock-correction burst every 1024 clocks ([clock correction](clock-correction.md)) | SKP ordered sets |

The same codes mean different things: K28.3 is SerWB's XOFF and PCIe's IDL, K28.1 is SerWB's fill and PCIe's FTS. The two framings cannot share a lane.

**For openCologne-PCIE**, which reuses the FIFO pump's eduBOS5 <-> FIFO architecture ([`2.rtl/6.soc`](https://github.com/chili-chips-ba/openCologne-PCIE/tree/main/2.rtl/6.soc)): the CPU side (FIFOs, CSRs, firmware) carries over unchanged. On the line side the PCIe transaction and data link layers replace the SerWB packetizer. They frame each TLP with STP, sequence number, LCRC and END, and hand data plus K flags to the PIPE: the same byte + K flag shape as this PHY. PCIe Gen3 and later (128b/130b) have no K symbols at all; they frame with tokens and sync headers. That does not apply to GateMate, whose SerDes tops out at 5 Gb/s (Gen2).

#### End-of-Document
