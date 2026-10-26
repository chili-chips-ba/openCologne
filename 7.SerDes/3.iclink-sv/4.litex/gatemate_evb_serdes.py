#!/usr/bin/env python3
#
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
# SPDX-License-Identifier: BSD-3-Clause
#
# LiteX SoC on the GateMate EVB with the GateMate SerDes PHY (serdes_gatemate.py).
# Test setup 1: the EVB's SerDes TX cabled to its own RX. Control and status are
# CSRs, reached from the host through UARTBone (litex_server + litex_cli):
#
#   ./gatemate_evb_serdes.py --build [--load]
#   litex_server --uart --uart-port /dev/ttyUSB0
#   litex_cli --regs                      # serdes_* registers
#
# PRBS test: write serdes_tx_prbs_config and serdes_rx_prbs_config (1 = PRBS7,
# 2 = PRBS15, 3 = PRBS31), then read serdes_rx_prbs_errors.

from migen import *

from litex.gen import *
from litex.build.parser import LiteXArgumentParser
from litex.soc.cores.clock.colognechip import GateMatePLL
from litex.soc.integration.soc_core import SoCMini
from litex.soc.integration.builder import Builder

from litex_boards.platforms import colognechip_gatemate_evb
from litex_boards.extensions.pmod import PmodUSBUART

from serdes_gatemate import SerDesGateMate


class _CRG(LiteXModule):
    """sys from the PLL; serdes_reg is the 10 MHz board clock itself, for the PHY bring-up."""
    def __init__(self, platform, sys_clk_freq):
        self.rst           = Signal()
        self.cd_sys        = ClockDomain()
        self.cd_serdes_reg = ClockDomain()

        clk10 = platform.request("clk10")
        rst_n = platform.request("user_btn_n", 0)
        self.comb += self.cd_serdes_reg.clk.eq(clk10)
        self.comb += self.cd_serdes_reg.rst.eq(~rst_n | self.rst)

        self.pll = pll = GateMatePLL(perf_mode="economy")
        self.comb += pll.reset.eq(~rst_n | self.rst)
        pll.register_clkin(clk10, 10e6)
        pll.create_clkout(self.cd_sys, sys_clk_freq)
        platform.add_period_constraint(self.cd_sys.clk, 1e9/sys_clk_freq)


class SerDesSoC(SoCMini):
    def __init__(self, sys_clk_freq=24e6, toolchain="peppercorn", **kwargs):
        platform = colognechip_gatemate_evb.Platform(toolchain, "A1")
        platform.add_extension(PmodUSBUART("PMODB"))

        self.crg = _CRG(platform, sys_clk_freq)
        kwargs["with_uart"] = False
        kwargs["cpu_type"]  = "None"  # no CPU: the host reads the CSRs through UARTBone
        SoCMini.__init__(self, platform, sys_clk_freq, ident="GateMate SerDes PHY test", **kwargs)
        self.add_uartbone(uart_name="usb_uart")

        self.serdes = serdes = SerDesGateMate(platform,
            clk_reg = ClockSignal("serdes_reg"),
            rst_reg = ResetSignal("serdes_reg"),
        )
        serdes.add_stream_endpoints()
        serdes.add_controls()
        serdes.add_clock_cycles()
        platform.add_period_constraint(serdes.cd_tx.clk, 1e9/serdes.tx_clk_freq)  # rx: the same clock

        # No data source yet: send K28.5 commas when PRBS is off, so RX can align.
        self.comb += [
            serdes.sink.valid.eq(1),
            serdes.sink.data.eq(Replicate(C(0xBC, 8), 8)),
            serdes.sink.ctrl.eq(0xFF),
        ]


def main():
    parser = LiteXArgumentParser(platform=colognechip_gatemate_evb.Platform,
                                 description="GateMate SerDes PHY test on the GateMate EVB.")
    parser.add_target_argument("--sys-clk-freq", default=24e6, type=float, help="System clock frequency.")
    args = parser.parse_args()

    soc = SerDesSoC(sys_clk_freq=args.sys_clk_freq, toolchain=args.toolchain, **parser.soc_argdict)
    builder = Builder(soc, **parser.builder_argdict)
    if args.build:
        builder.build(**parser.toolchain_argdict)
    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"))


if __name__ == "__main__":
    main()
