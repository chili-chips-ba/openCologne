#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2023 Gwenhael Goavec-merou<gwenhael.goavec-merou@trabucayre.com>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *

from litex.gen import *

from litex_boards.platforms import colognechip_gatemate_evb

from litex.build.io import CRG

from litex.soc.cores.clock.colognechip import GateMatePLL
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *

from litex.build.generic_platform import Pins

from litex.soc.cores.led import LedChaser

# CRG ----------------------------------------------------------------------------------------------

class _CRG(LiteXModule):
    def __init__(self, platform, sys_clk_freq):
        self.rst    = Signal()
        rst_n       = Signal()
        self.cd_sys = ClockDomain()

        # # #

        # Clk / Rst
        clk10 = platform.request("clk10")
        self.rst = ~platform.request("user_btn_n", 0)

        self.specials += Instance("CC_USR_RSTN", o_USR_RSTN = rst_n)

        # PLL
        self.pll = pll = GateMatePLL(perf_mode="economy")
        self.comb += pll.reset.eq(~rst_n | self.rst)
        pll.register_clkin(clk10, 10e6)
        pll.create_clkout(self.cd_sys, sys_clk_freq)

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=48e6,
        with_led_chaser = True,
        with_serdes=False,
        **kwargs):
        platform = colognechip_gatemate_evb.Platform()

        # USBUART PMOD as Serial--------------------------------------------------------------------
        platform.add_extension(colognechip_gatemate_evb.usb_pmod_io("PMODB"))
        kwargs["uart_name"] = "usb_uart"

        # CRG --------------------------------------------------------------------------------------
        self.crg = _CRG(platform, sys_clk_freq)

        # SoCCore ----------------------------------------------------------------------------------
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on GateMate EVB", **kwargs)

        # Leds -------------------------------------------------------------------------------------
        if with_led_chaser:
            self.leds = LedChaser(
                pads         = platform.request_all("user_led_n"),
                sys_clk_freq = sys_clk_freq)

        if with_serdes:
            from liteiclink.serdes.serdes_gm import SerDesGM
            serdes = SerDesGM(sys_clk_freq=sys_clk_freq,
                               refclk_freq=125e6,
                               linerate=1.25e9,
                               internal_loopback=True)
            self.submodules.serdes = serdes
            serdes.add_controls(auto_enable=True)

# Build --------------------------------------------------------------------------------------------

def main():
    from litex.build.parser import LiteXArgumentParser
    parser = LiteXArgumentParser(platform=colognechip_gatemate_evb.Platform, description="LiteX SoC on Gatemate EVB")
    parser.add_target_argument("--sys-clk-freq", default=24e6, type=float, help="System clock frequency.")
    parser.add_target_argument("--flash",        action="store_true",      help="Flash bitstream.")
    parser.add_target_argument("--with-serdes", action="store_true",       help="Enable SERDES (1.25 Gbps transceiver loopback test).")
    args = parser.parse_args()

    soc = BaseSoC(
        sys_clk_freq = args.sys_clk_freq,
        with_serdes  = args.with_serdes,
        **parser.soc_argdict)
    builder = Builder(soc, **parser.builder_argdict)
    if args.build:
        builder.build(**parser.toolchain_argdict)

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"))

    if args.flash:
        from litex.build.openfpgaloader import OpenFPGALoader
        prog = OpenFPGALoader("gatemate_evb_spi")
        prog.flash(0, builder.get_bitstream_filename(mode="flash"))

if __name__ == "__main__":
    main()
