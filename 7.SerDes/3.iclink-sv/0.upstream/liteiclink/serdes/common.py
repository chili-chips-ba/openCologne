#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *

from litex.gen import *

from litex.soc.interconnect.csr import *

# DRP Layout ---------------------------------------------------------------------------------------

_drp_layout = [
    ("clk",                1, DIR_M_TO_S),
    ("en",                 1, DIR_M_TO_S),
    ("we",                 1, DIR_M_TO_S),
    ("rdy",                1, DIR_S_TO_M),
    ("addr", "address_width", DIR_M_TO_S),
    ("di",      "data_width", DIR_M_TO_S),
    ("do",      "data_width", DIR_S_TO_M),
]

# DRP Interface ------------------------------------------------------------------------------------

class DRPInterface(Record):
    def __init__(self, address_width=9, data_width=16):
        Record.__init__(self, set_layout_parameters(_drp_layout,
            address_width = address_width,
            data_width    = data_width,
        ))

# DRP Mux ------------------------------------------------------------------------------------------

class DRPMux(LiteXModule, DRPInterface):
    def __init__(self, **kwargs):
        DRPInterface.__init__(self, **kwargs)
        self.sel = Signal(4)
        self.interfaces = []

    def add_interface(self, interface):
        self.interfaces.append(interface)

    def do_finalize(self):
        assert len(self.interfaces) <= 16
        cases = {}
        for i, interface in enumerate(self.interfaces):
            cases[i] = interface.connect(self)
        self.comb += Case(self.sel, cases)

# DRP Control --------------------------------------------------------------------------------------

class DRPControl(LiteXModule):
    def __init__(self, drp):
        self._addr  = CSRStorage(9,  description="DRP Address (9 bits).")
        self._di    = CSRStorage(16, description="DRP Data In (16 bits) for write operation.")
        self._do    = CSRStatus(16,  description="DRP Data Out (16 bits) for read operation.")
        self._we    = CSRStorage(1,  description="DRP Write Enable.")
        self._start = CSRStorage(1,  description="Write to initiate DRP operation.")
        self._done  = CSRStatus(1,   description="DRP operation is complete.")

        # # #

        # Clk.
        self.comb += drp.clk.eq(ClockSignal("sys"))

        # FSM.
        self.fsm = fsm = ResetInserter()(FSM(reset_state="IDLE"))
        self.comb += fsm.reset.eq(self._start.wr_stb)

        fsm.act("IDLE",
            NextState("ACCESS")
        )
        fsm.act("ACCESS",
            drp.en.eq(1),
            drp.we.eq(self._we.storage),
            drp.addr.eq(self._addr.storage),
            drp.di.eq(self._di.storage),
            NextState("WAIT")
        )
        fsm.act("WAIT",
            If(drp.rdy,
                NextValue(self._do.status, drp.do),
                NextState("DONE")
            )
        )
        fsm.act("DONE",
            self._done.status.eq(1)
        )
