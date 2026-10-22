#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *
from migen.genlib.io import *

from litex.gen import *
from litex.gen.genlib.misc import WaitTimer

from litex.soc.interconnect import stream

from litex.soc.cores.code_8b10b import K, StreamEncoder, StreamDecoder

from liteiclink.serwb.scrambler import Scrambler, Descrambler

# TX Datapath --------------------------------------------------------------------------------------

class TXDatapath(LiteXModule):
    def __init__(self, phy_dw, with_scrambling=False):
        self.idle   = idle   = Signal()
        self.comma  = comma  = Signal()
        self.wait   = wait   = Signal()
        self.xon    = xon    = Signal()
        self.xoff   = xoff   = Signal()
        self.ctrl_ack = ctrl_ack = Signal() # XON/XOFF character accepted.
        self.sink   = sink   = stream.Endpoint([("data", 32)])
        self.source = source = stream.Endpoint([("data", phy_dw)])

        # # #

        # Scrambler.
        # ----------
        if with_scrambling:
            self.scrambler = scrambler = Scrambler()

        # Line coding.
        # ------------
        self.encoder = encoder = StreamEncoder(nwords=4)

        # Converter.
        # ----------
        self.converter = converter = stream.Converter(40, phy_dw)

        # Data-Path.
        # ----------
        if with_scrambling:
            self.comb += [
                sink.connect(scrambler.sink),
                scrambler.source.connect(encoder.sink),
            ]
        else:
            self.comb += [
                sink.connect(encoder.sink, omit={"data"}),
                encoder.sink.d.eq(sink.data),
            ]
        self.comb += [
            encoder.source.connect(converter.sink),
            converter.source.connect(source),
        ]

        # Encode Idle.
        # ------------
        self.comb += If(idle,
            sink.ready.eq(0),
            converter.sink.valid.eq(1),
            converter.sink.data.eq(0),
        )

        # Encode Comma (K28.5).
        # ---------------------
        self.comb += If(comma,
            sink.ready.eq(0),
            encoder.sink.valid.eq(1),
            encoder.sink.k.eq(0b1),
            encoder.sink.d.eq(K(28, 5)),
        )

        # Encode Wait (K28.1).
        # --------------------
        self.comb += If(wait,
            sink.ready.eq(0),
            encoder.sink.valid.eq(1),
            encoder.sink.k.eq(0b1),
            encoder.sink.d.eq(K(28, 1)),
        )

        # Encode XON (K28.4) / XOFF (K28.3).
        # ----------------------------------
        self.comb += [
            If(xon | xoff,
                sink.ready.eq(0),
                encoder.sink.valid.eq(1),
                encoder.sink.k.eq(0b1),
                encoder.sink.d.eq(Mux(xoff, K(28, 3), K(28, 4))),
            ),
            ctrl_ack.eq((xon | xoff) & encoder.sink.ready),
        ]

# RX Aligner ---------------------------------------------------------------------------------------

class RXAligner(LiteXModule):
    """
    This module aligns the data stream. When shifting is enabled, this module stops forwarding data
    from `sink` to `source` while accepting and ignoring new data on the `sink`.

    This module guarantees the removal of one data element (phy_dw bits) from the stream when
    shift_inc is asserted for one cycle.

    There must be data on the stream between successive shift_inc operations, otherwise this module
    will shift less than expected.

     * ``phy_dw`` the width of the data signal.
     * ``shift_inc`` enable the shifting if != 0
    """
    def __init__(self, phy_dw, shift_inc=None):
        self.shift_inc = Signal() if shift_inc is None else shift_inc
        self.sink      = sink   = stream.Endpoint([("data", phy_dw)])
        self.source    = source = stream.Endpoint([("data", phy_dw)])

        # # #

        _shift = Signal()
        self.sync += [
            If(self.shift_inc,
                _shift.eq(1)
            ).Elif(sink.valid & sink.ready,
                _shift.eq(0)
            )
        ]

        self.comb += [
            sink.connect(source),
            If(_shift,
                source.valid.eq(0),
                sink.ready.eq(1),
            )
        ]

# RXDatapath ---------------------------------------------------------------------------------------

class RXDatapath(LiteXModule):
    def __init__(self, phy_dw, with_scrambling=False):
        self.shift_inc  = shift_inc  = Signal()
        self.sink       = sink       = stream.Endpoint([("data", phy_dw)])
        self.source     = source     = stream.Endpoint([("data", 32)])
        self.idle       = idle       = Signal()
        self.comma      = comma      = Signal()
        self.wait       = wait       = Signal()
        self.xon        = xon        = Signal()
        self.xoff       = xoff       = Signal()
        self.invalid    = invalid    = Signal() # Invalid 8b10b symbol(s) received.

        # # #

        # Aligner.
        # --------
        self.aligner = aligner = RXAligner(phy_dw, shift_inc)

        # Converter.
        # ----------
        self.converter = converter = stream.Converter(phy_dw, 40)

        # Line Coding.
        # ------------
        self.decoder = decoder = StreamDecoder(nwords=4)

        # Descrambler.
        # ------------
        if with_scrambling:
            self.descrambler = descrambler = Descrambler()

        # Data-Path.
        # ----------
        self.comb += [
            sink.connect(aligner.sink),
            aligner.source.connect(converter.sink),
            converter.source.connect(decoder.sink),
         ]
        if with_scrambling:
            self.comb += [
                decoder.source.connect(descrambler.sink),
                descrambler.source.connect(source),
            ]
        else:
            self.comb += [
                decoder.source.connect(source, omit={"d", "k"}),
                source.data.eq(decoder.source.d),
                If(wait | xon | xoff,
                    source.valid.eq(0),
                    decoder.source.ready.eq(1),
                )
            ]

        # Detect Invalid 8b10b Symbols.
        # ----------------------------
        # Basic detection (as in litex.soc.cores.code_8b10b): valid symbols have 4, 5 or 6 ones.
        symbols_invalid = []
        for i in range(4):
            ones = Signal(4)
            self.comb += ones.eq(Reduce("ADD", [converter.source.data[10*i + j] for j in range(10)]))
            symbols_invalid.append((ones != 4) & (ones != 5) & (ones != 6))
        self.comb += invalid.eq(converter.source.valid & converter.source.ready & Reduce("OR", symbols_invalid))

        # Decode Idle.
        # ------------
        self.idle_timer = idle_timer = WaitTimer(32)
        self.sync += If(converter.source.valid,
            idle_timer.wait.eq(
                (converter.source.data == 0) |
                (converter.source.data == (2**40-1))
            )
        )
        self.comb += idle.eq(idle_timer.done)

        # Decode Comma (K28.5).
        # ---------------------
        self.sync += If(decoder.source.valid,
            comma.eq(
                (decoder.source.k == 1) &
                (decoder.source.d == K(28, 5))
            )
        )

        # Decode Wait (K28.1).
        # --------------------
        self.comb += If(decoder.source.valid,
            wait.eq(
                (decoder.source.k == 1) &
                (decoder.source.d == K(28, 1))
            )
        )

        # Decode XON (K28.4) / XOFF (K28.3).
        # ----------------------------------
        self.comb += If(decoder.source.valid,
            xon.eq( (decoder.source.k == 1) & (decoder.source.d == K(28, 4))),
            xoff.eq((decoder.source.k == 1) & (decoder.source.d == K(28, 3))),
        )

# Flow Control -------------------------------------------------------------------------------------

class FlowControl(LiteXModule):
    """Link level flow control (XON/XOFF).

    - When ``pause`` (local RX buffer almost full) changes, an XOFF/XON character is inserted in the
      TX stream (it preempts data for one word only, so local TX traffic is never blocked) and is
      periodically re-sent to recover from a lost character.
    - Received XOFF/XON characters pause/resume local TX data: while paused or without data to
      send, K28.1 fill characters are transmitted (and dropped by the remote RX) instead of zeros.
    """
    def __init__(self, tx, rx, tx_sink, rx_source, ready, refresh=1024):
        # tx/rx: TX/RXDatapath (control), tx_sink/rx_source: SerDes data endpoints.
        self.pause  = pause  = Signal() # Input: request remote to pause.
        self.paused = paused = Signal() # Output: paused by remote.
        self.sink   = sink   = stream.Endpoint([("data", 32)])
        self.source = source = stream.Endpoint([("data", 32)])

        # # #

        # Remote state.
        # -------------
        self.sync += [
            If(~ready,
                paused.eq(0)
            ).Elif(rx.xoff,
                paused.eq(1)
            ).Elif(rx.xon,
                paused.eq(0)
            )
        ]

        # Local state.
        # ------------
        pause_d = Signal()
        pending = Signal()
        self.refresh_timer = refresh_timer = WaitTimer(refresh)
        self.comb += refresh_timer.wait.eq(ready & ~pending)
        self.sync += [
            pause_d.eq(pause),
            If(~ready,
                pending.eq(0),
            ).Elif((pause != pause_d) | refresh_timer.done,
                pending.eq(1),
            ).Elif(tx.ctrl_ack,
                pending.eq(0),
            )
        ]
        self.comb += [
            tx.xoff.eq(ready & pending &  pause),
            tx.xon.eq( ready & pending & ~pause),
        ]

        # Data-Path.
        # ----------
        self.comb += [
            If(ready,
                If(~paused,
                    sink.connect(tx_sink),
                ),
                tx.wait.eq(~sink.valid | paused),
                rx_source.connect(source),
            ).Else(
                rx_source.ready.eq(1),
            ),
            tx_sink.valid.eq(1), # Always transmitting.
        ]
