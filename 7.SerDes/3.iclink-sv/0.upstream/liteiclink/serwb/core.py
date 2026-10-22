#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *
from migen.genlib.cdc import MultiReg

from litex.gen import *

from litex.soc.interconnect        import stream
from litex.soc.interconnect.csr    import CSRStatus
from litex.soc.interconnect.packet import Arbiter, Dispatcher

from liteiclink.serwb.packet    import packet_description
from liteiclink.serwb.packet    import Packetizer, Depacketizer, CRCDepacketizer
from liteiclink.serwb.etherbone import Etherbone

# SERWB Core ---------------------------------------------------------------------------------------

class SERWBCore(LiteXModule):
    def __init__(self, phy, clk_freq, mode, with_rst_on_link_down=True, port=0,
        etherbone_buffer_depth = 4,
        tx_buffer_depth        = None,
        rx_buffer_depth        = None,
        depacketizer_timeout   = 1e-3,
        with_crc               = False,
        crc_max_words          = None,
    ):
        # Default buffering: at least one full Etherbone packet (SerWB header + Etherbone header +
        # record header + base address + data words).
        packet_max_words = 2 + 2 + 1 + 1 + etherbone_buffer_depth
        # With PHY flow control, RX buffer also has to absorb the words in flight on the link after
        # a pause request.
        with_flow_control  = hasattr(phy, "pause")
        flow_control_margin = 16
        if tx_buffer_depth is None:
            tx_buffer_depth = max(8, packet_max_words)
        if rx_buffer_depth is None:
            rx_buffer_depth = max(8, packet_max_words)
            if with_flow_control:
                rx_buffer_depth += flow_control_margin

        # Downstream/Upstream Endpoints.
        # ------------------------------
        self.downstream_endpoints = {}
        self.upstream_endpoints   = {}

        # Etherbone.
        # ----------
        self.etherbone = etherbone = ResetInserter()(Etherbone(mode, etherbone_buffer_depth))
        self.add_downstream_endpoint(port=port, endpoint=etherbone.source)
        self.add_upstream_endpoint(  port=port, endpoint=etherbone.sink)

        # Bus.
        # ----
        self.bus = bus = etherbone.wishbone.bus

        # Return an error on accesses when link is down (instead of stalling the bus).
        if mode == "slave":
            self.comb += If(~phy.init.ready, bus.err.eq(bus.cyc & bus.stb))

        # Packetizer / Depacketizer.
        # --------------------------
        # With CRC (must be enabled on both sides), received packets are checked and dropped when
        # invalid; crc_max_words is the largest payload accepted (default: Etherbone packet).
        self.packetizer = packetizer = ResetInserter()(Packetizer(with_crc=with_crc))
        if with_crc:
            if crc_max_words is None:
                crc_max_words = max(16, packet_max_words - 2)
            self.depacketizer = depacketizer = ResetInserter()(CRCDepacketizer(clk_freq,
                timeout   = depacketizer_timeout,
                max_words = crc_max_words,
            ))
            self.crc_errors = CSRStatus(32, description="Number of packets dropped on CRC error.")
            self.sync += If(depacketizer.crc_error & (self.crc_errors.status != (2**32 - 1)),
                self.crc_errors.status.eq(self.crc_errors.status + 1)
            )
        else:
            self.depacketizer = depacketizer = ResetInserter()(Depacketizer(clk_freq, timeout=depacketizer_timeout))

        # Buffering.
        # ----------
        self.tx_fifo = tx_fifo = ResetInserter()(stream.SyncFIFO([("data", 32)], tx_buffer_depth, buffered=True))
        self.rx_fifo = rx_fifo = ResetInserter()(stream.SyncFIFO([("data", 32)], rx_buffer_depth, buffered=True))

        # Data-Path.
        # ----------
        self.comb += [
            # Core -> PHY.
            packetizer.source.connect(tx_fifo.sink),
            tx_fifo.source.connect(phy.sink),

            # PHY -> Core.
            phy.source.connect(rx_fifo.sink),
            rx_fifo.source.connect(depacketizer.sink),
        ]

        # Flow Control.
        # -------------
        # Request remote to pause when RX buffer is almost full.
        if with_flow_control:
            assert rx_buffer_depth > flow_control_margin
            self.comb += phy.pause.eq(rx_fifo.level >= (rx_buffer_depth - flow_control_margin))

        # Reset internal module when link down.
        # -------------------------------------
        if with_rst_on_link_down:
            self.comb += [
                etherbone.reset.eq(    ~phy.init.ready),
                packetizer.reset.eq(   ~phy.init.ready),
                depacketizer.reset.eq( ~phy.init.ready),
                tx_fifo.reset.eq(      ~phy.init.ready),
                rx_fifo.reset.eq(      ~phy.init.ready),
            ]

    def add_downstream_endpoint(self, port, endpoint):
        if port in self.downstream_endpoints.keys():
            raise ValueError(f"Downstream endpoint for port {port} already exists.")
        self.downstream_endpoints[port] = endpoint

    def add_upstream_endpoint(self, port, endpoint):
        if port in self.upstream_endpoints.keys():
            raise ValueError(f"Upstream endpoint for port {port} already exists.")
        self.upstream_endpoints[port] = endpoint

    def do_finalize(self):
        # Downstream Arbitration.
        # -----------------------
        downstream_endpoints = [stream.Endpoint(packet_description(32)) for _ in range(len(self.downstream_endpoints))]
        for i, (k, v) in enumerate(self.downstream_endpoints.items()):
            self.comb += [
                v.connect(downstream_endpoints[i], keep={"valid", "ready", "last", "data", "length"}),
                downstream_endpoints[i].port.eq(k),
            ]
        self.arbiter = Arbiter(
            masters = downstream_endpoints,
            slave   = self.packetizer.sink,
        )

        # Upstream Dispatching.
        # ---------------------
        # Packets for unknown ports are sent to a drop endpoint.
        drop_endpoint = stream.Endpoint(packet_description(32))
        self.comb += drop_endpoint.ready.eq(1)
        self.dispatcher = Dispatcher(
            master  = self.depacketizer.source,
            slaves  = [ep for _, ep in self.upstream_endpoints.items()] + [drop_endpoint],
            one_hot = False,
            keep    = {"valid", "ready", "last", "data", "length"},
        )
        self.comb += self.dispatcher.sel.eq(len(self.upstream_endpoints))
        for i, (k, v) in enumerate(self.upstream_endpoints.items()):
            self.comb += If(self.depacketizer.source.port == k, self.dispatcher.sel.eq(i))

# SERIO Core ---------------------------------------------------------------------------------------

class SERIOPacketizer(LiteXModule):
    def __init__(self):
        self.i      = Signal(32)
        self.source = source = stream.Endpoint(packet_description(32))

        # # #

        # Signals.
        # --------
        i   = Signal(32)
        i_d = Signal(32)

        # Re-Synchronize Inputs.
        # ----------------------
        # Note: Each bit is re-synchronized independently, so multi-bit values changing at the same
        # time are not guaranteed to be transferred coherently.
        self.specials += MultiReg(self.i, i)

        # Generate Packet.
        # ----------------
        # Latch the changed value and hold it until accepted (stream protocol).
        self.sync += [
            If(source.valid & source.ready,
                source.valid.eq(0),
            ),
            If(~source.valid | source.ready,
                If(i != i_d,
                    source.valid.eq(1),
                    source.data.eq(i),
                    i_d.eq(i),
                )
            )
        ]
        self.comb += [
            source.last.eq(1),
            source.length.eq(4),
        ]

class SERIODepacketizer(LiteXModule):
    def __init__(self):
        self.sink = sink = stream.Endpoint(packet_description(32))
        self.o    = Signal(32)

        # # #

        # Generate Outputs.
        # -----------------
        self.comb += sink.ready.eq(1)
        self.sync += If(sink.valid & sink.last, self.o.eq(sink.data))

class SERIOCore(LiteXModule):
    def __init__(self, serwb_core, port=1):
        self.i = Signal(32)
        self.o = Signal(32)

        # # #

        # Packetizer.
        # -----------
        self.packetizer = SERIOPacketizer()
        self.comb += self.packetizer.i.eq(self.i)

        # Depacketizer.
        # -------------
        self.depacketizer = SERIODepacketizer()
        self.comb += self.o.eq(self.depacketizer.o)

        # Add to SERWB Downstreams/Upstreams Endpoints.
        # ---------------------------------------------
        serwb_core.add_downstream_endpoint(port=port, endpoint=self.packetizer.source)
        serwb_core.add_upstream_endpoint  (port=port, endpoint=self.depacketizer.sink)
