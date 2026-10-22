#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *

from litex.gen import *
from litex.gen.genlib.misc import WaitTimer

from litex.soc.interconnect import stream
from litex.soc.interconnect.csr import *

from liteiclink.serwb.kuserdes import KUSerdes
from liteiclink.serwb.s7serdes import S7Serdes
from liteiclink.serwb.efinixserdes import EfinixSerdes
from liteiclink.serwb.datapath     import FlowControl


# SerDes Initialization/Synchronisation ------------------------------------------------------------
#
# - 1) Master sends IDLE patterns (zeroes) to Slave to reset it.
# - 2) Master sends K28.5 commas to allow Slave to calibrate, Slave sends IDLE patterns.
# - 3) Slave sends K28.5 commas to allow Master to calibrate, Master sends K28.5 commas.
# - 4) Master stops sending K28.5 commas.
# - 5) Slave stops sending K28.5 commas.
# - 6) Physical link is ready.
# --------------------------------------------------------------------------------------------------

# Serdes Master Init -------------------------------------------------------------------------------

@ResetInserter()
class _SerdesMasterInit(LiteXModule):
    def __init__(self, serdes, taps, timeout, clk_ratio="1:1"):
        self.ready = Signal()
        self.error = Signal()

        # # #

        self.delay           = delay           = Signal(max=taps)
        self.delay_min       = delay_min       = Signal(max=taps)
        self.delay_min_found = delay_min_found = Signal()
        self.delay_max       = delay_max       = Signal(max=taps)
        self.delay_max_found = delay_max_found = Signal()
        self.shift           = shift           = Signal(max=40)
        self.phase_sel       = phase_sel       = Signal(2)

        # Timer.
        # ------
        self.timer = timer = WaitTimer(timeout)

        # FSM.
        # ----
        self.fsm = fsm = FSM(reset_state="RESET")
        fsm.act("RESET",
            NextValue(phase_sel, 0),
            NextState("IDLE")
        )
        fsm.act("IDLE",
            NextValue(delay,           0),
            NextValue(delay_min,       0),
            NextValue(delay_min_found, 0),
            NextValue(delay_max,       0),
            NextValue(delay_max_found, 0),
            NextValue(shift,           0),
            serdes.rx.delay_rst.eq(1),
            NextState("RESET-SLAVE"),
            serdes.tx.idle.eq(1)
        )
        fsm.act("RESET-SLAVE",
            timer.wait.eq(1),
            If(timer.done,
                timer.wait.eq(0),
                NextState("SEND-PATTERN")
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("SEND-PATTERN",
            If(~serdes.rx.idle,
                timer.wait.eq(1),
                If(timer.done,
                    NextState("CHECK-PATTERN")
                )
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("WAIT-STABLE",
            timer.wait.eq(1),
            If(timer.done,
                timer.wait.eq(0),
                NextState("CHECK-PATTERN")
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("CHECK-PATTERN",
            If(~delay_min_found,
                If(serdes.rx.comma,
                    timer.wait.eq(1),
                    If(timer.done,
                        timer.wait.eq(0),
                        NextValue(delay_min, delay),
                        NextValue(delay_min_found, 1),
                    )
                ).Else(
                    NextState("INC-DELAY-SHIFT")
                ),
            ).Else(
                If(~serdes.rx.comma | (delay == (taps - 1)),
                    NextValue(delay_max, delay),
                    NextValue(delay_max_found, 1),
                    NextState("CHECK-SAMPLING-WINDOW")
                ).Else(
                    NextState("INC-DELAY-SHIFT")
                )
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("INC-DELAY-SHIFT",
            NextState("WAIT-STABLE"),
            If(delay == (taps - 1),
                If(shift == (40 - 1),
                    NextState("INC-PHASE-SEL")
                ).Else(
                    NextValue(delay_min_found, 0),
                    NextValue(delay_min,       0),
                    NextValue(delay_max_found, 0),
                    NextValue(delay_max,       0),
                    NextValue(shift, shift + 1),
                    serdes.rx.shift_inc.eq(1)
                ),
                NextValue(delay, 0),
                serdes.rx.delay_rst.eq(1)
            ).Else(
                NextValue(delay, delay + 1),
                serdes.rx.delay_inc.eq(1)
            ),
            serdes.tx.comma.eq(1)
        )
        if hasattr(serdes.rx, "phase_sel"):
            self.comb += serdes.rx.phase_sel.eq(phase_sel)
        fsm.act("INC-PHASE-SEL",
            NextValue(phase_sel, phase_sel + 1),
            If(phase_sel == ({"1:1":1, "1:2":2, "1:4":4}[clk_ratio] - 1),
                NextState("ERROR")
            ).Else(
                NextState("IDLE")
            )
        )
        fsm.act("CHECK-SAMPLING-WINDOW",
            If((delay_max - delay_min) < taps//16,
               NextValue(delay_min_found, 0),
               NextValue(delay_max_found, 0),
               NextState("WAIT-STABLE")
            ).Else(
                NextValue(delay, 0),
                serdes.rx.delay_rst.eq(1),
                NextState("CONFIGURE-SAMPLING-WINDOW")
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("CONFIGURE-SAMPLING-WINDOW",
            If(delay == (delay_min + (delay_max - delay_min)[1:]),
                NextState("READY")
            ).Else(
                NextValue(delay, delay + 1),
                serdes.rx.delay_inc.eq(1)
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("READY",
            self.ready.eq(1)
        )
        fsm.act("ERROR",
            self.error.eq(1)
        )

# Serdes Slave Init --------------------------------------------------------------------------------

@ResetInserter()
class _SerdesSlaveInit(LiteXModule):
    def __init__(self, serdes, taps, timeout, clk_ratio="1:1"):
        self.ready = Signal()
        self.error = Signal()

        # # #

        self.delay           = delay           = Signal(max=taps)
        self.delay_min       = delay_min       = Signal(max=taps)
        self.delay_min_found = delay_min_found = Signal()
        self.delay_max       = delay_max       = Signal(max=taps)
        self.delay_max_found = delay_max_found = Signal()
        self.shift           = shift           = Signal(max=40)
        self.phase_sel       = phase_sel       = Signal(2)

        # Timer.
        # ------
        self.timer = timer = WaitTimer(timeout)

        # FSM.
        # ----
        self.fsm = fsm = FSM(reset_state="RESET")
        fsm.act("RESET",
            NextValue(phase_sel, 0),
            NextState("IDLE")
        )
        fsm.act("IDLE",
            NextValue(delay,           0),
            NextValue(delay_min,       0),
            NextValue(delay_min_found, 0),
            NextValue(delay_max,       0),
            NextValue(delay_max_found, 0),
            NextValue(shift,           0),
            serdes.rx.delay_rst.eq(1),
            timer.wait.eq(1),
            If(timer.done,
                timer.wait.eq(0),
                NextState("WAIT-STABLE"),
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("WAIT-STABLE",
            timer.wait.eq(1),
            If(timer.done,
                timer.wait.eq(0),
                NextState("CHECK-PATTERN")
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("CHECK-PATTERN",
            If(~delay_min_found,
                If(serdes.rx.comma,
                    timer.wait.eq(1),
                    If(timer.done,
                        timer.wait.eq(0),
                        NextValue(delay_min, delay),
                        NextValue(delay_min_found, 1),
                    )
                ).Else(
                    NextState("INC-DELAY-SHIFT")
                ),
            ).Else(
                If(~serdes.rx.comma | (delay == (taps - 1)),
                    NextValue(delay_max, delay),
                    NextValue(delay_max_found, 1),
                    NextState("CHECK-SAMPLING-WINDOW")
                ).Else(
                    NextState("INC-DELAY-SHIFT")
                )
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("INC-DELAY-SHIFT",
            NextState("WAIT-STABLE"),
            If(delay == (taps - 1),
                If(shift == (40 - 1),
                    NextState("INC-PHASE-SEL")
                ).Else(
                    NextValue(delay_min_found, 0),
                    NextValue(delay_min,       0),
                    NextValue(delay_max_found, 0),
                    NextValue(delay_max,       0),
                    NextValue(shift, shift + 1),
                    serdes.rx.shift_inc.eq(1)
                ),
                NextValue(delay, 0),
                serdes.rx.delay_rst.eq(1)
            ).Else(
                NextValue(delay, delay + 1),
                serdes.rx.delay_inc.eq(1)
            ),
            serdes.tx.idle.eq(1)
        )
        if hasattr(serdes.rx, "phase_sel"):
            self.comb += serdes.rx.phase_sel.eq(phase_sel)
        fsm.act("INC-PHASE-SEL",
            NextValue(phase_sel, phase_sel + 1),
            If(phase_sel == ({"1:1":1, "1:2":2, "1:4":4}[clk_ratio] - 1),
                NextState("ERROR")
            ).Else(
                NextState("IDLE")
            )
        )
        fsm.act("CHECK-SAMPLING-WINDOW",
            If((delay_max - delay_min) < taps//16,
               NextValue(delay_min_found, 0),
               NextValue(delay_max_found, 0),
               NextState("WAIT-STABLE")
            ).Else(
                NextValue(delay, 0),
                serdes.rx.delay_rst.eq(1),
                NextState("CONFIGURE-SAMPLING-WINDOW")
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("CONFIGURE-SAMPLING-WINDOW",
            If(delay == (delay_min + (delay_max - delay_min)[1:]),
                NextState("SEND-PATTERN")
            ).Else(
                NextValue(delay, delay + 1),
                serdes.rx.delay_inc.eq(1),
            ),
            serdes.tx.idle.eq(1)
        )
        fsm.act("SEND-PATTERN",
            timer.wait.eq(1),
            If(timer.done,
                If(~serdes.rx.comma,
                    NextState("READY")
                )
            ),
            serdes.tx.comma.eq(1)
        )
        fsm.act("READY",
            self.ready.eq(1)
        )
        fsm.act("ERROR",
            self.error.eq(1)
        )

# Serdes Init Control ------------------------------------------------------------------------------

class _SerdesControl(LiteXModule):
    def __init__(self, serdes, init, mode="master"):
        if mode == "master":
            self.reset = CSR()
        self.ready = CSRStatus()
        self.error = CSRStatus()

        self.delay           = CSRStatus(9)
        self.delay_min_found = CSRStatus()
        self.delay_min       = CSRStatus(9)
        self.delay_max_found = CSRStatus()
        self.delay_max       = CSRStatus(9)
        self.shift           = CSRStatus(6)
        self.phase           = CSRStatus(2)

        self.prbs_error  = Signal()
        self.prbs_start  = CSR()
        self.prbs_cycles = CSRStorage(32)
        self.prbs_errors = CSRStatus(32)

        self.invalid_errors = CSRStatus(32, description="Number of invalid 8b10b words received (link ready).")

        # # #

        # Invalid 8b10b Words Counter (cleared on link reset).
        # ----------------------------------------------------
        invalid_errors = self.invalid_errors.status
        self.sync += [
            If(~init.ready,
                invalid_errors.eq(0)
            ).Elif(serdes.rx.datapath.invalid & (invalid_errors != (2**32 - 1)),
                invalid_errors.eq(invalid_errors + 1)
            )
        ]

        # Master Mode.
        # ------------
        if mode == "master":
            # In Master mode, reset is coming from CSR, it resets the Master that will also reset
            # the Slave by putting the link in IDLE state.
            self.sync += init.reset.eq(self.reset.wr_stb)
        # Slave Mode.
        # -----------
        if mode == "slave":
            # In Slave mode, reset is coming from link, Master reset the Slave by putting the link
            # in IDLE state.
            self.sync += [
                init.reset.eq(serdes.rx.idle),
                serdes.reset.eq(serdes.rx.idle)
            ]
        # Control/Status.
        # ---------------
        self.comb += [
            self.ready.status.eq(init.ready),
            self.error.status.eq(init.error),
            self.delay.status.eq(init.delay),
            self.delay_min_found.status.eq(init.delay_min_found),
            self.delay_min.status.eq(init.delay_min),
            self.delay_max_found.status.eq(init.delay_max_found),
            self.delay_max.status.eq(init.delay_max),
            self.shift.status.eq(init.shift),
            self.phase.status.eq(init.phase_sel)
        ]

        # PRBS.
        # -----
        prbs_cycles = Signal(32)
        prbs_errors = self.prbs_errors.status
        self.prbs_fsm = prbs_fsm = FSM(reset_state="IDLE")
        prbs_fsm.act("IDLE",
            NextValue(prbs_cycles, 0),
            If(self.prbs_start.wr_stb,
                NextValue(prbs_errors, 0),
                NextState("CHECK")
            )
        )
        prbs_fsm.act("CHECK",
            NextValue(prbs_cycles, prbs_cycles + 1),
            If(self.prbs_error,
                NextValue(prbs_errors, prbs_errors + 1),
            ),
            If(prbs_cycles == self.prbs_cycles.storage,
                NextState("IDLE")
            )
        )

# SERWB PHY ----------------------------------------------------------------------------------------

class SERWBPHY(LiteXModule):
    def __init__(self, device, pads, mode="master", init_timeout=2**16, clk="sys", clk4x="sys4x", clk_ratio="1:1", clk_delay_taps=0, rx_delay_taps=0, usp=False, with_flow_control=False):
        self.sink   = sink   = stream.Endpoint([("data", 32)])
        self.source = source = stream.Endpoint([("data", 32)])
        assert mode in ["master", "slave"]

        # # #

        # SerDes.
        # -------

        # Xilinx Ultrascale(+).
        if device[:4] in ["xcku", "xvu", "xczu"]:
            assert clk_ratio == "1:1"
            taps = 512
            self.serdes = KUSerdes(pads, mode, usp=usp)

        # Xilinx 7-Series.
        elif device[:4] in ["xc7a", "xc7k", "xc7v", "xc7z", "xc7s"]:
            assert clk_ratio == "1:1"
            taps = 32
            self.serdes = S7Serdes(pads, mode)


        # Efinix Titanium.
        elif device[:2] == "Ti":
            taps = 64
            self.serdes = EfinixSerdes(pads, mode,
                clk       = clk,
                clk4x     = clk4x,
                clk_ratio = clk_ratio,
            )

        # Efinix Trion.
        elif device[:2] in ["T1", "T2"]:
            taps = 4 # No dynamic delay
            self.serdes = EfinixSerdes(pads, mode,
                clk            = clk,
                clk4x          = clk4x,
                clk_ratio      = clk_ratio,
                clk_delay_taps = clk_delay_taps,
                rx_delay_taps  = rx_delay_taps
            )
        else:
            raise NotImplementedError

        # SerDes Init.
        # ------------
        init_cls = {
            "master" : _SerdesMasterInit,
            "slave"  : _SerdesSlaveInit,
        }[mode]
        self.init = init_cls(self.serdes, taps, init_timeout, clk_ratio)

        # SerDes Control.
        # ---------------
        self.control = _SerdesControl(self.serdes, self.init, mode)

        # Data-Path.
        # ----------
        # Optional link level flow control (XON/XOFF, K28.1 fill characters when idle). Must be
        # enabled on both sides of the link. The core drives `pause` from its RX buffer level.
        if with_flow_control:
            self.flow_control = FlowControl(
                tx        = self.serdes.tx.datapath,
                rx        = self.serdes.rx.datapath,
                tx_sink   = self.serdes.tx.sink,
                rx_source = self.serdes.rx.source,
                ready     = self.init.ready,
            )
            self.pause = self.flow_control.pause
            self.comb += [
                sink.connect(self.flow_control.sink),
                self.flow_control.source.connect(source),
            ]
        else:
            self.comb += [
                If(self.init.ready,
                    If(sink.valid,
                        sink.connect(self.serdes.tx.sink),
                    ),
                    self.serdes.rx.source.connect(source)
                ).Else(
                    self.serdes.rx.source.ready.eq(1)
                ),
                self.serdes.tx.sink.valid.eq(1) # Always transmitting
            ]

        # PRBS.
        # -----
        # The PRBS test is using the scrambler/descrambler as PRBS, sending 0 to the scrambler and
        # checking that descrambler output is always 0.
        self.comb += self.control.prbs_error.eq(source.valid & source.ready & (source.data != 0))
