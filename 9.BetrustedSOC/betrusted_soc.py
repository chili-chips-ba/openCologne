#!/usr/bin/env python3

# This variable defines all the external programs that this module
# relies on.  lxbuildenv reads this variable in order to ensure
# the build will finish without exiting due to missing third-party
# programs.

LX_DEPENDENCIES = ["riscv"]

# Import lxbuildenv to integrate the deps/ directory
from re import S
import lxbuildenv
import litex.soc.doc as lxsocdoc
from pathlib import Path
import subprocess
import sys

from random import SystemRandom
import argparse

from migen import *
from migen.genlib.cdc import MultiReg, BlindTransfer, BusSynchronizer
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.build.generic_platform import *
from litex.build.colognechip import CologneChipPlatform
# from litex.build.xilinx import XilinxPlatform, VivadoProgrammer

from litex.soc.interconnect.csr import *
from litex.soc.interconnect.csr_eventmanager import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.integration.doc import AutoDoc, ModuleDoc

from litex.soc.cores.clock import GateMatePLL
from litex.soc.integration.soc import SoCRegion

from litex.soc.interconnect import wishbone
from litex.soc.integration.soc import SoCRegion
from gateware.rom_block import BlockRom

from gateware import info
from gateware import sram_32_cached

from gateware import ticktimer
from gateware.wdt import WDT

from gateware.trng.ring_osc_v2 import TrngRingOscV2
from gateware import aes_opentitan as aes
from gateware import sha2_opentitan as sha2
from gateware import sha512_opentitan as sha512
from gateware.curve25519.engine import Engine
from gateware.timer_alwayson import TimerAlwaysOn
from gateware.keyrom import KeyRom
from gateware import perfcounter

from litex.build.openfpgaloader import OpenFPGALoader

# from custom_valentyusb.usbcore.cpu.eptri import TriEndpointInterface
# from custom_valentyusb.usbcore.io import IoBuf

# IOs ----------------------------------------------------------------------------------------------
_io_gatemate =[
    ("clk10", 0, Pins("IO_SB_A8"), Misc("SCHMITT_TRIGGER=true") ),
    ("serial",0,
        Subsignal("tx", Pins("IO_SA_B6")),
        Subsignal("rx", Pins("IO_SA_A6"), Misc("PULLUP=true"))
    ),
    ("arst_n",0,Pins("IO_SB_B7"),Misc("PULLUP=true")),
]

# Platform -----------------------------------------------------------------------------------------
class Platform(CologneChipPlatform):
    def __init__(self, device, *args, toolchain="peppercorn", devicename=None, **kwargs):
        CologneChipPlatform.__init__(self,device,*args,toolchain=toolchain,devicename=None,**kwargs)
    def create_programmer(self):
        return OpenFPGALoader("gatemate_evb_jtag", "dirtyJtag")


class CRG(Module, AutoCSR):
    def __init__(self, platform, sys_clk_freq=10e6):
        self.arst_n = platform.request("arst_n")
        clk10 = platform.request("clk10")

        # Declare cd_sys
        self.clock_domains.cd_sys = cd_sys = ClockDomain()

        # Instantiate PLL
        self.submodules.pll_1 = pll_1 = GateMatePLL(perf_mode="economy")
        pll_1.register_clkin(clk10, 10e6)
        pll_1.create_clkout(cd_sys, sys_clk_freq, with_reset=False)

        # reset for main cd
        reset_combo = Signal()
        self.comb += reset_combo.eq(~self.arst_n | ~pll_1.locked)

        # Async reset synchronizer
        self.specials += [AsyncResetSynchronizer(cd_sys, reset_combo)]


# BetrustedSoC -------------------------------------------------------------------------------------

class BetrustedSoC(SoCCore):
    # I/O range: 0x80000000-0xfffffffff (not cacheable)

    def __init__(self, platform, sys_clk_freq=int(35e6),
                 uart_name="serial", use_perfcounter=False, app_uart=False,
                 **kwargs):
        assert sys_clk_freq in range (int(10e6), int(38e6))

        # Clockgen cluster -------------------------------------------------------------------------
        self.submodules.crg = CRG(platform, sys_clk_freq)

        # Memory map
        SoCCore.mem_map = {
            "main_ram" : 0x40000000
        }

        # CPU will start executing from here
        cpu_reset_address = 0x40000000

        # Call parent constructor with corrected memory map
        SoCCore.__init__(self, platform, sys_clk_freq,
            csr_data_width       = 32,
            integrated_rom_size  = 0x6000,     # disable ROM
            integrated_sram_size = 0x2000,    # 64 KiB internal SRAM
            ident                = "",
            csr_paging           = 4096,
            cpu_type             = "vexriscv",
            cpu_reset_address    = cpu_reset_address,
            csr_address_width    = 16,
            with_uart            = True,
            uart_name            = uart_name,
            with_ctrl            = True,
            with_timer           = True,
            **kwargs)
        # Application memory
        self.add_ram("main_ram", self.mem_map["main_ram"], 32*1024) 

        # CPU --------------------------------------------------------------------------------------
        # Betrusted uses a different VexRiscv version
        self.cpu.use_external_variant("VexRiscv/VexRiscv_BetrustedSoC.v")


# Build --------------------------------------------------------------------------------------------

def main():
    global _io

    if os.environ['PYTHONHASHSEED'] != "1":
        print( "PYTHONHASHEED must be set to 1 for consistent validation results. Failing to set this results in non-deterministic compilation results")
        return 1

    parser = argparse.ArgumentParser(description="Build the Betrusted SoC")
    parser.add_argument(
        "-D", "--document-only", default=False, action="store_true", help="Build docs only"
    )
    parser.add_argument("-l","--load-only", default=False, action="store_true", help="Upload the bitstream only. Don't rebuild")
    parser.add_argument(
        "--toolchain",
        choices=["peppercorn", "colognechip"],
        default="peppercorn",
        help="Toolchain to use (default: peppercorn)"
    )
    parser.add_argument(
        "-p", "--physical-uart", help="Disable physical UART. Enables console UART tunelling over wishbone-tool, deactivatces physical pins.", default=True, action="store_false"
    )
    parser.add_argument(
        "-c", "--perfcounter", default=False, help="Build with the performance counter module.", action="store_true",
    )
    parser.add_argument(
        "--simple-boot", help="Fall back to the simple, unsigned bootloader", default=True, action="store_false",
    )
    parser.add_argument(
        "--app-uart", help="Instantiate an extra UART for app and GDB use", default=False, action="store_true",
    )

    ##### extract user arguments
    args = parser.parse_args()
    compile_gateware = True
    compile_software = True

    if args.document_only:
        compile_gateware = False
        compile_software = False

    io = _io_gatemate
   
    if args.physical_uart:
        uart_name="serial"
    else:
        uart_name="crossover"

    ##### setup platform
    platform = Platform(toolchain=args.toolchain, device="CCGM1A1", io=io)
    programmer = platform.create_programmer()
    
    ##### define the soc
    soc = BetrustedSoC(
        platform,
        uart_name=uart_name,
        sys_clk_freq=int(20e6),
        use_perfcounter=args.perfcounter,
        app_uart=args.app_uart,
    )

    ##### setup the builder and run it
    builder = Builder(soc,
        output_dir="build",
        csr_csv="build/csr.csv",
        csr_svd="build/software/soc.svd",
        compile_software=True,  # disables auto-build (this is okay)
        compile_gateware=compile_gateware,
        bios_console="disable",
    )
    vns = None
    if args.load_only==False:
        vns = builder.build()
    programmer.load_bitstream("./build/gateware/betrusted_soc.bit")
    if args.load_only==True:
        return 0

    ##### post-build routines
    soc.do_exit(vns)
    lxsocdoc.generate_docs(soc, "build/documentation", note_pulses=True, sphinx_extensions=['sphinx_math_dollar', 'sphinx.ext.mathjax'],
            sphinx_extra_config=r"""
mathjax_config = {
   'tex2jax': {
       'inlineMath': [ ["\\(","\\)"] ],
       'displayMath': [["\\[","\\]"] ],
   },
}""")

    # generate the rom-inject library code
    if ~args.document_only:
        if not os.path.exists('fw/rom-inject/src'): # make rom-inject/src if it doesn't exist, e.g. on clean checkout
            os.mkdir('fw/rom-inject/src')
        with open('fw/rom-inject/src/lib.rs', 'w+') as libfile:
            subprocess.call([sys.executable, './key2bits.py', '-c', '-kkeystore.bin', '-rrom.db'], stdout=libfile)
    return 0

if __name__ == "__main__":
    from datetime import datetime
    start = datetime.now()
    ret = main()
    print("Run completed in {}".format(datetime.now()-start))

    sys.exit(ret)
    