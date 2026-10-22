#
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
# SPDX-License-Identifier: BSD-3-Clause
#
# GateMate CC_SERDES transceiver PHY for LiteICLink / LiteX.
#
# A thin Migen wrapper around the SystemVerilog core iclink_serdes_gm
# (../1.hw). It offers the interface of LiteICLink's transceiver PHYs
# (liteiclink/serdes, e.g. SerDesECP5): tx/rx clock domains, tx_ready /
# rx_ready, rx_align, PRBS7/15/31 generator and checker, and 8 words of
# 8 bits + K flag per clock through add_stream_endpoints().
#
# The 8b/10b encoder is in the fabric (SV core), the decoder and comma
# alignment run in CC_SERDES. The SV sources are read with Yosys's slang
# front end (platform.yosys_use_slang).

import os
import subprocess

from migen import *
from migen.genlib.cdc import MultiReg
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.gen import *
from litex.soc.interconnect import stream
from litex.soc.interconnect.csr import *

HW_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "1.hw")

# SV sources of the PHY, in compile order (packages first)
SOURCES = [
    "iclink_pkg.sv",
    "iclink_8b10b_enc.sv",
    "iclink_prbs_gen.sv",
    "iclink_prbs_chk.sv",
    "iclink_prbs_tx.sv",
    "iclink_prbs_rx.sv",
    "iclink_phy_pkg.sv",
    "iclink_serdes_gm.sv",
]


class SerDesGateMate(LiteXModule):
    """GateMate CC_SERDES PHY, 8 words per clock (64-bit data + 8 K flags).

    clk_reg: the bring-up clock of the SV core (a regfile write sequence with
    fixed waits, designed for the 10 MHz board clock of the GateMate EVB).
    linerate: only used to report the tx/rx clock frequency (linerate / 80);
    the line rate itself is set by CC_SERDES's PLL configuration in the core.
    """
    def __init__(self, platform, clk_reg, rst_reg=0, linerate=2.5e9):
        self.nwords = nwords = 8

        # LiteICLink PHY interface ------------------------------------------------------------
        self.tx_ready       = Signal()
        self.tx_prbs_config = Signal(2)
        self.rx_ready       = Signal()
        self.rx_align       = Signal(reset=1)
        self.rx_aligned     = Signal()
        self.rx_prbs_config = Signal(2)
        self.rx_prbs_pause  = Signal()
        self.rx_prbs_errors = Signal(32)

        self.tx_clk_freq = linerate/(10*nwords)
        self.rx_clk_freq = linerate/(10*nwords)

        # Data, packed as the SV structs: phy_word_t = {d[7:0], k} (d word 0 in bits 7:0).
        self.tx_d       = Signal(8*nwords)
        self.tx_k       = Signal(nwords)
        self.rx_d       = Signal(8*nwords)
        self.rx_k       = Signal(nwords)
        self.rx_invalid = Signal(nwords)

        # Clock domains ---------------------------------------------------------------------
        self.cd_tx = ClockDomain()
        self.cd_rx = ClockDomain()
        self.specials += [
            AsyncResetSynchronizer(self.cd_tx, ~self.tx_ready),
            AsyncResetSynchronizer(self.cd_rx, ~self.rx_ready),
        ]

        # SV core ---------------------------------------------------------------------------
        # phy_ctrl_t = {tx_prbs[1:0], rx_prbs[1:0], rx_prbs_pause, rx_align}, MSB first.
        ctrl = Signal(6)
        self.comb += ctrl.eq(Cat(self.rx_align, self.rx_prbs_pause, self.rx_prbs_config, self.tx_prbs_config))

        self.specials += Instance("iclink_serdes_gm",
            i_clk_reg        = clk_reg,
            i_arst_n         = ~rst_reg,
            i_ctrl           = ctrl,
            o_clk_tx         = self.cd_tx.clk,
            o_tx_ready       = self.tx_ready,
            i_tx             = Cat(self.tx_k, self.tx_d),
            o_clk_rx         = self.cd_rx.clk,
            o_rx_ready       = self.rx_ready,
            o_rx_aligned     = self.rx_aligned,
            o_rx             = Cat(self.rx_k, self.rx_d),
            o_rx_invalid     = self.rx_invalid,
            o_rx_prbs_errors = self.rx_prbs_errors,
        )
        self.add_sources(platform)

    @staticmethod
    def add_sources(platform):
        # Yosys's GateMate cell blackboxes, so read_slang knows CC_SERDES.
        datdir = subprocess.check_output(["yosys-config", "--datdir"], text=True).strip()
        platform.add_source(os.path.join(datdir, "gatemate", "cells_bb.v"), language="systemverilog")
        for f in SOURCES:
            platform.add_source(os.path.join(HW_DIR, f), language="systemverilog")
        platform.yosys_use_slang  = True
        platform.yosys_slang_opts = "-D SYNTHESIS"  # CC_SERDES, not the simulation BFM

    def add_stream_endpoints(self):
        """sink (tx domain) and source (rx domain): data = 8 words of 8 bits, ctrl = K flags."""
        self.sink   =   sink = stream.Endpoint([("data", self.nwords*8), ("ctrl", self.nwords)])
        self.source = source = stream.Endpoint([("data", self.nwords*8), ("ctrl", self.nwords)])
        self.comb += [
            sink.ready.eq(1),  # the PHY takes a word every clock
            self.tx_d.eq(sink.data),
            self.tx_k.eq(sink.ctrl),
            source.valid.eq(1),
            source.data.eq(self.rx_d),
            source.ctrl.eq(self.rx_k),
        ]

    def add_base_control(self):
        self._tx_ready   = CSRStatus(description="TX initialized and ready.")
        self._rx_ready   = CSRStatus(description="RX initialized and ready, CDR locked.")
        self._rx_align   = CSRStorage(reset=1, description="Comma alignment enable.")
        self._rx_aligned = CSRStatus(description="Comma alignment acquired.")
        self.specials += [
            MultiReg(self.tx_ready,   self._tx_ready.status),
            MultiReg(self.rx_ready,   self._rx_ready.status),
            MultiReg(self.rx_aligned, self._rx_aligned.status),
        ]
        self.comb += self.rx_align.eq(self._rx_align.storage)  # synchronized in the core

    def add_prbs_control(self):
        prbs_values = [
            ("``0b00``", "PRBS   Disabled."),
            ("``0b01``", "PRBS7  Enabled."),
            ("``0b10``", "PRBS15 Enabled."),
            ("``0b11``", "PRBS31 Enabled."),
        ]
        self._tx_prbs_config = CSRStorage(fields=[CSRField("config", size=2, values=prbs_values)])
        self._rx_prbs_config = CSRStorage(fields=[
            CSRField("config", size=2, values=prbs_values),
            CSRField("pause",  size=1, description="Pause RX PRBS."),
        ])
        self._rx_prbs_errors = CSRStatus(32, description="RX PRBS errors (clocks with an error).")
        self.comb += [
            self.tx_prbs_config.eq(self._tx_prbs_config.fields.config),  # synchronized in the core
            self.rx_prbs_config.eq(self._rx_prbs_config.fields.config),
            self.rx_prbs_pause.eq(self._rx_prbs_config.fields.pause),
        ]
        # Static-ish counter: read it while paused for a consistent value.
        self.specials += MultiReg(self.rx_prbs_errors, self._rx_prbs_errors.status)

    def add_controls(self):
        self.add_base_control()
        self.add_prbs_control()

    def add_clock_cycles(self):
        self.clock_latch     = CSRStorage(description="Write to latch TX/RX clock cycles.")
        self.clock_tx_cycles = CSRStorage(32, description="TX clock cycles.")
        self.clock_rx_cycles = CSRStorage(32, description="RX clock cycles.")
        tx_cycles = Signal(32)
        rx_cycles = Signal(32)
        self.sync.tx += tx_cycles.eq(tx_cycles + 1)
        self.sync.rx += rx_cycles.eq(rx_cycles + 1)
        self.sync += If(self.clock_latch.wr_stb,
            self.clock_tx_cycles.storage.eq(tx_cycles),
            self.clock_rx_cycles.storage.eq(rx_cycles),
        )
