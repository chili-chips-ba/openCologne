#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *

from litex.gen import *
from litex.gen.genlib.misc import WaitTimer

from litex.soc.interconnect        import stream
from litex.soc.interconnect.packet import HeaderField, Header

from liteeth.mac.crc import LiteEthMACCRCEngine

# Layouts ------------------------------------------------------------------------------------------

def packet_description(dw):
    payload_layout = [("data", dw)]
    param_layout   = [("port", 8), ("length", 16)]
    return stream.EndpointDescription(payload_layout, param_layout)

def phy_description(dw):
    layout = [("data", dw)]
    return stream.EndpointDescription(layout)

# CRC ----------------------------------------------------------------------------------------------

class _CRC32(LiteXModule):
    """CRC32 over 32-bit words (reset to 0xffffffff on `reset`, updated on `update`)."""
    def __init__(self):
        self.reset  = Signal()
        self.update = Signal()
        self.data   = Signal(32)
        self.value  = Signal(32, reset=2**32-1)

        # # #

        self.engine = engine = LiteEthMACCRCEngine(data_width=32, width=32, polynom=0x04c11db7)
        self.comb += [
            engine.data.eq(self.data),
            engine.crc_prev.eq(self.value),
        ]
        self.sync += [
            If(self.reset,
                self.value.eq(2**32-1)
            ).Elif(self.update,
                self.value.eq(engine.crc_next)
            )
        ]

# Packetizer ---------------------------------------------------------------------------------------

class Packetizer(LiteXModule):
    def __init__(self, with_crc=False):
        self.sink   = sink   = stream.Endpoint(packet_description(32))
        self.source = source = stream.Endpoint(phy_description(32))

        # # #

        # Packet description.
        # - Preamble : 4 bytes.
        # - Port     : 1 byte.
        # - Length   : 2 bytes.
        # - Payload  : length bytes.
        # - CRC32    : 4 bytes (optional, over Port/Length and Payload).

        # CRC.
        # ----
        if with_crc:
            self.crc = crc = _CRC32()
            self.comb += [
                crc.data.eq(source.data),
                crc.update.eq(source.valid & source.ready),
            ]

        # FSM.
        # ----
        self.fsm = fsm = FSM(reset_state="PREAMBLE")
        fsm.act("PREAMBLE",
            If(sink.valid,
                source.valid.eq(1),
                source.data.eq(0x5aa55aa5),
                If(source.ready,
                    NextState("PORT-LENGTH")
                )
            )
        )
        if with_crc:
            fsm.act("PREAMBLE", crc.reset.eq(1))
        fsm.act("PORT-LENGTH",
            source.valid.eq(1),
            source.data[0 :8].eq(sink.port),
            source.data[8:24].eq(sink.length),
            If(source.ready,
                NextState("DATA")
            )
        )
        fsm.act("DATA",
            source.valid.eq(sink.valid),
            source.data.eq(sink.data),
            sink.ready.eq(source.ready),
            If(sink.valid & source.ready & sink.last,
                NextState("CRC" if with_crc else "PREAMBLE")
            )
        )
        if with_crc:
            fsm.act("CRC",
                source.valid.eq(1),
                source.data.eq(crc.value),
                crc.update.eq(0),
                If(source.ready,
                    NextState("PREAMBLE")
                )
            )

# Depacketizer -------------------------------------------------------------------------------------

class Depacketizer(LiteXModule):
    def __init__(self, clk_freq, timeout=1e-3):
        self.sink   = sink   = stream.Endpoint(phy_description(32))
        self.source = source = stream.Endpoint(packet_description(32))

        # # #

        # Packet description.
        # - Preamble : 4 bytes.
        # - Port     : 1 byte.
        # - Length   : 2 bytes.
        # - Payload

        # Signals.
        # --------
        port   = Signal(len(source.port))
        count  = Signal(len(source.length))
        length = Signal(len(source.length))

        # Timer.
        # ------
        # Drop incomplete packets after timeout (in seconds) without incoming data (the timer does not
        # run while the packet is only stalled by downstream).
        self.timer = timer = WaitTimer(int(clk_freq*timeout))

        # FSM.
        # ----
        self.fsm = fsm = FSM(reset_state="PREAMBLE")
        fsm.act("PREAMBLE",
            sink.ready.eq(1),
            If(sink.valid &
              (sink.data == 0x5aa55aa5),
                NextState("PORT-LENGTH")
            )
        )
        fsm.act("PORT-LENGTH",
            sink.ready.eq(1),
            If(sink.valid,
                NextValue(count, 0),
                NextValue(port,   sink.data[0:8]),
                NextValue(length, sink.data[8:24]),
                # Packets without payload words are dropped.
                If(sink.data[8+2:24] != 0,
                    NextState("DATA")
                ).Else(
                    NextState("PREAMBLE")
                )
            ),
            timer.wait.eq(~sink.valid)
        )
        fsm.act("DATA",
            source.valid.eq(sink.valid),
            source.last.eq(count == (length[2:] - 1)),
            source.port.eq(port),
            source.length.eq(length),
            source.data.eq(sink.data),
            sink.ready.eq(source.ready),
            If(timer.done,
                NextState("PREAMBLE")
            ).Elif(source.valid & source.ready,
                NextValue(count, count + 1),
                If(source.last,
                    NextState("PREAMBLE")
                )
            ),
            timer.wait.eq(~sink.valid)
        )

# CRC Depacketizer ---------------------------------------------------------------------------------

class CRCDepacketizer(LiteXModule):
    """Depacketizer for packets with CRC32 (see Packetizer(with_crc=True)).

    Packets are stored (with backpressure, so compatible with link flow control), checked and only
    forwarded when the CRC is valid. Packets with invalid CRC, payload larger than `max_words` or
    timing out are dropped (`crc_error`/`drop` pulse per dropped packet).
    """
    def __init__(self, clk_freq, timeout=1e-3, max_words=64):
        self.sink      = sink   = stream.Endpoint(phy_description(32))
        self.source    = source = stream.Endpoint(packet_description(32))
        self.crc_error = Signal()
        self.drop      = Signal()

        # # #

        # Signals.
        # --------
        port   = Signal(len(source.port))
        length = Signal(len(source.length))
        words  = Signal(len(source.length) - 2)
        count  = Signal(len(source.length) - 2)

        # Payload Buffer.
        # ---------------
        self.fifo = fifo = stream.SyncFIFO([("data", 32)], max_words)

        # CRC.
        # ----
        self.crc = crc = _CRC32()
        self.comb += crc.data.eq(sink.data)

        # Timer.
        # ------
        # Drop incomplete packets after timeout (in seconds) without incoming data.
        self.timer = timer = WaitTimer(int(clk_freq*timeout))

        # FSM.
        # ----
        self.fsm = fsm = FSM(reset_state="PREAMBLE")
        fsm.act("PREAMBLE",
            sink.ready.eq(1),
            crc.reset.eq(1),
            If(sink.valid &
              (sink.data == 0x5aa55aa5),
                NextState("PORT-LENGTH")
            )
        )
        fsm.act("PORT-LENGTH",
            sink.ready.eq(1),
            If(sink.valid,
                crc.update.eq(1),
                NextValue(count,  0),
                NextValue(port,   sink.data[0:8]),
                NextValue(length, sink.data[8:24]),
                NextValue(words,  sink.data[8+2:24]),
                # Packets without payload words or too large to be stored are dropped.
                If((sink.data[8+2:24] != 0) & (sink.data[8+2:24] <= max_words),
                    NextState("STORE")
                ).Else(
                    self.drop.eq(1),
                    NextState("PREAMBLE")
                )
            ),
            timer.wait.eq(~sink.valid)
        )
        fsm.act("STORE",
            fifo.sink.valid.eq(sink.valid),
            fifo.sink.data.eq(sink.data),
            sink.ready.eq(fifo.sink.ready),
            If(timer.done,
                NextValue(count, 0),
                self.drop.eq(1),
                NextState("FLUSH")
            ).Elif(sink.valid & sink.ready,
                crc.update.eq(1),
                NextValue(count, count + 1),
                If(count == (words - 1),
                    NextState("CHECK")
                )
            ),
            timer.wait.eq(~sink.valid)
        )
        fsm.act("CHECK",
            sink.ready.eq(1),
            NextValue(count, 0),
            If(timer.done,
                self.drop.eq(1),
                NextState("FLUSH")
            ).Elif(sink.valid,
                If(sink.data == crc.value,
                    NextState("FORWARD")
                ).Else(
                    self.crc_error.eq(1),
                    self.drop.eq(1),
                    NextState("FLUSH")
                )
            ),
            timer.wait.eq(~sink.valid)
        )
        fsm.act("FORWARD",
            source.valid.eq(fifo.source.valid),
            source.last.eq(count == (words - 1)),
            source.port.eq(port),
            source.length.eq(length),
            source.data.eq(fifo.source.data),
            fifo.source.ready.eq(source.ready),
            If(source.valid & source.ready,
                NextValue(count, count + 1),
                If(source.last,
                    NextState("PREAMBLE")
                )
            )
        )
        fsm.act("FLUSH",
            fifo.source.ready.eq(1),
            If(~fifo.source.valid & (fifo.level == 0),
                NextState("PREAMBLE")
            )
        )
