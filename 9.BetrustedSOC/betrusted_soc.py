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
    def __init__(self, device, *args, toolchain="colognechip", devicename=None, **kwargs):
        CologneChipPlatform.__init__(self,device,*args,toolchain="colognechip",devicename=None,**kwargs)

# CRG ----------------------------------------------------------------------------------------------
class CRG(Module, AutoCSR):
    def __init__(self, platform, sys_clk_freq):
        # self.warm_reset = Signal()
        self.arst_n = platform.request("arst_n")
        self.clock_domains.cd_sys   = ClockDomain()
        self.clock_domains.cd_clk200 = ClockDomain()
        self.clock_domains.cd_clk50 = ClockDomain()

        self.clock_domains.cd_sys_always_on = ClockDomain()
        self.clock_domains.cd_clk50_always_on = ClockDomain()

        clk10 = platform.request("clk10")

        self.cd_clk50_90phase = ClockDomain()
        self.cd_clk50_180phase = ClockDomain()
        self.cd_clk50_270phase = ClockDomain()
        
        self.submodules.pll_1 = pll_1 = GateMatePLL("ECONOMY", 1, 1)
        pll_1.register_clkin(clk10, 10e6)
        pll_1.create_clkout(self.cd_clk50, 50e6)
        pll_1.create_clkout(self.cd_clk50_90phase, 50e6, 90)
        pll_1.create_clkout(self.cd_clk50_180phase, 50e6, 180)
        pll_1.create_clkout(self.cd_clk50_270phase, 50e6, 270)


        self.comb += self.cd_clk50_always_on.clk.eq(self.cd_clk50.clk)
        self.comb += self.cd_sys.clk.eq(clk10)
        self.comb += self.cd_sys_always_on.clk.eq(clk10)
        pll_1.do_finalize()

        reset_combo = Signal()

        self.comb += reset_combo.eq(~self.arst_n | ~pll_1.locked)

        self.specials += [
            AsyncResetSynchronizer(self.cd_clk50, reset_combo),
            AsyncResetSynchronizer(self.cd_sys, reset_combo),
            AsyncResetSynchronizer(self.cd_sys_always_on, reset_combo),
            AsyncResetSynchronizer(self.cd_clk50_always_on, reset_combo),
        ]

# WarmBoot -----------------------------------------------------------------------------------------

# class WarmBoot(Module, AutoCSR):
#     def __init__(self, parent, reset_vector=0):
#         self.soc_reset = CSRStorage(size=8, description="Writing 0xAC to this register will do a full SoC reset, including CRGs and peripherals")
#         self.addr = CSRStorage(size=32, reset=reset_vector, description="The address written here will be used as the next reset vector")
#         self.cpu_reset = CSRStorage(size=1, description="Writing anything to this register resets the CPU, and the CPU only; does not affect CRG or peripherals")
#         self.cpu_hold_reset = CSRStorage(size = 1, description="This bit is wired directly to the CPU's reset line. Thus, when set, the CPU stays in reset until it is cleared. This is intended to be used by external bus masters via USB to hold the CPU in reset.")
#         self.do_reset = Signal()
#         # "Reset Key" is 0xac (0b101011xx)
#         self.comb += self.do_reset.eq((self.soc_reset.storage & 0xfc) == 0xac)

boot_offset    = 0x500000 # enough space to hold 2x FPGA bitstreams before the firmware start
bios_size      = 0x10000
SPI_FLASH_SIZE = 0 #128 * 1024 * 1024
SRAM_EXT_SIZE  = 0x1000000
prefix = ""  # sometimes 'soc_', sometimes '' prefix Litex is attaching to net names

# BetrustedSoC -------------------------------------------------------------------------------------

class BetrustedSoC(SoCCore):
    # I/O range: 0x80000000-0xfffffffff (not cacheable)
    SoCCore.mem_map = {
        "csr":             0xf0000000,
    }

    def __init__(self, platform, revision, sys_clk_freq=int(10e6), legacy_spi=False,
                 xous=False, usb_type='debug', uart_name="serial", bios_path='boot/boot.bin',
                 puppet=False, use_perfcounter=False, app_uart=False,
                 **kwargs):
        assert sys_clk_freq in [int(10e6), int(10e6)]
        global bios_size

        # CPU cluster
        reset_address = 0x80000000

        # SoCCore ----------------------------------------------------------------------------------
        SoCCore.__init__(self, platform, sys_clk_freq, csr_data_width=32,
            integrated_rom_size  = 0x8000,    # don't use default ROM 32kB
            integrated_rom_init  = None, # bios_path,
            integrated_sram_size = 0x8000,    # Use external SRAM for boot code 32kB
            ident                = "", # Was :"Precursor SoC " + revision, but not used by firmware so eliminated
            cpu_type             = "vexriscv",
            csr_paging           = 4096,  # increase paging to 1 page size
            csr_address_width    = 16,    # increase to accommodate larger page size
            with_uart            = True, #False # implemented manually to allow for UART mux
            uart_name            = uart_name,
            cpu_reset_address    = reset_address,
            with_ctrl            = False,
            with_timer           = False, # override default timer with a timer that operates in a low-power clock domain
            **kwargs)

        # Fix the location of CSRs and IRQs so we can do firmware updates between generations of the SoC
        self.csr.locs = {
            # 'reboot': 0,
            'crg': 2,
            # 'uart_phy': 4,
            'uart': 5,
            #'app_uart_phy': 8,
            #'app_uart': 9,
            # 'wdt': 34,
        }

        # CPU --------------------------------------------------------------------------------------
        self.cpu.use_external_variant("VexRiscv/VexRiscv_BetrustedSoC.v")
        # self.submodules.reboot = WarmBoot(self, reset_address)
        # self.add_csr("reboot", use_loc_if_exists=True)
        # warm_reset = Signal()
        # wdt_reset = Signal()
        # self.comb += warm_reset.eq(self.reboot.do_reset | wdt_reset) # this is patched into the GSR via the SPINOR block (because that's where the STARTUPE2 block lives)
        # self.cpu.cpu_params.update(i_externalResetVector=self.reboot.addr.storage)
        # # override the default CPU reset so there's more margin on the signal
        # # we do *not* patch this into the system reset because it also kicks the Wishbone USB debug bridge, which complicates firmware updates!
        # reset_cycles = 32
        # cpu_res_ctr = Signal(log2_int(reset_cycles), reset=reset_cycles - 1)
        # cpu_reset = Signal(reset=1)
        # reset_hold = Signal()
        # self.sync += [
        #     If(self.reboot.cpu_reset.re,
        #         cpu_reset.eq(1),
        #         cpu_res_ctr.eq(reset_cycles - 1),
        #     ).Elif(cpu_res_ctr != 0,
        #         cpu_res_ctr.eq(cpu_res_ctr - 1)
        #     ).Else(
        #         cpu_reset.eq(0)
        #     ),
        #     reset_hold.eq(self.reboot.cpu_hold_reset.storage),
        # ]
        # if puppet:
        #     self.comb += self.cpu.reset.eq(1)
        # else:
        #     self.sync += self.cpu.reset.eq(cpu_reset | reset_hold)

        self.logger.info("Block ROM {} {} {}.".format(
            "rom",
            "added",
            self.bus.regions["rom"]))
        # Clockgen cluster -------------------------------------------------------------------------
        self.submodules.crg = CRG(platform, sys_clk_freq)
        # self.add_csr("crg", use_loc_if_exists=True) # this isn't used by Xous, so don't export it to save on registers.
        # self.comb += self.crg.warm_reset.eq(warm_reset) # mirror signal here to hit the Async reset injectors

        # UART mux ---------------------------------------------------------------------------------
        from litex.soc.cores import uart
        for resource, obj in platform.constraint_manager.matched:
            print(f"Resource: {resource}")
            print(f"Assigned to: {obj}")
       
# Build --------------------------------------------------------------------------------------------

def main():
    global _io

    if os.environ['PYTHONHASHSEED'] != "1":
        print( "PYTHONHASHEED must be set to 1 for consistent validation results. Failing to set this results in non-deterministic compilation results")
        return 1
    # used to be -e blank.nky -u debug -x -s NoTimingRelaxation -r pvt2 -p
    # now is -e blank.nky
    parser = argparse.ArgumentParser(description="Build the Betrusted SoC")
    parser.add_argument(
        "-D", "--document-only", default=False, action="store_true", help="Build docs only"
    )
    parser.add_argument(
        "-e", "--encrypt", help="Format output for encryption using the specified dummy key. Image is re-encrypted at sealing time with a secure key.", type=str
    )
    parser.add_argument(
        "-x", "--xous", help="Build for the Xous runtime environment. Defaults to true. Setting the flag disables this.", default=False, action="store_true"
    )
    parser.add_argument(
        "-r", "--revision", choices=['modnoise', 'pvt', 'pvt2'], help="Build for a particular revision. Defaults to 'pvt2'", default='pvt2', type=str,
    )
    parser.add_argument(
        "-u", "--usb-type", choices=['debug', 'device', 'spinal'], help="Select the USB core. Defaults to 'spinal'", default='spinal', type=str,
    )
    parser.add_argument(
        "--puppet", help="Builds a 'puppet' that can be controlled by the UP5K via a Wishbone UART. Replaces COM with the UART.", default=False, action="store_true",
    )
    parser.add_argument(
        "-b", "--bbram", help="encrypt to bbram, not efuse. Defaults to efuse. Only meaningful in -e is also specified.", default=False, action="store_true"
    )
    parser.add_argument(
        "-p", "--physical-uart", help="Disable physical UART. Enables console UART tunelling over wishbone-tool, deactivatces physical pins.", default=True, action="store_false"
    )
    parser.add_argument(
        "-s", "--strategy", choices=['Explore', 'default'], help="Pick the routing strategy. Defaults to 'default'.", default='default', type=str
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

    bbram = False
    if args.encrypt == None:
        encrypt = False
    else:
        encrypt = True
        if args.bbram:
            bbram = True

    io = _io_gatemate
   
    if args.physical_uart:
        uart_name="serial"
    else:
        uart_name="crossover"

    ##### build the "bios"
    if compile_software:
        if args.simple_boot:
            os.system("riscv64-unknown-elf-as -fpic loader{}loader.S -o loader{}loader.elf".format(os.path.sep, os.path.sep))
            os.system("riscv64-unknown-elf-objcopy -O binary loader{}loader.elf loader{}bios.bin".format(os.path.sep, os.path.sep))
            print("**** WARNING: using 'simple boot' method -- no signature verification checks are done on boot! ****")
            bios_path = 'loader{}bios.bin'.format(os.path.sep)
        else:
            # do a first-pass to create the soc.svd file
            # platform = Platform(io, encrypt=encrypt, bbram=bbram, strategy=args.strategy)
            platform = Platform(None, io,[])
            platform.add_extension(_io_uart_debug_swapped)
            soc = BetrustedSoC(platform, args.revision, xous=args.xous, usb_type=args.usb_type, uart_name=uart_name, bios_path=None, app_uart=args.app_uart)
            builder = Builder(soc, output_dir="build", csr_csv="build/csr.csv", csr_svd="build/software/soc.svd",
                compile_software=False, compile_gateware=False)
            builder.software_packages=[] # necessary to bypass Meson dependency checks required by Litex libc
            vns = builder.build(run=False)

            os.system("cd boot && cargo xtask boot-image")
            bios_path = 'boot{}boot.bin'.format(os.path.sep)
    else:
        bios_path=None

    ##### second pass to build the actual chip. Note any changes below need to be reflected into the first pass...might be a good idea to modularize that
    ##### setup platform
    #platform = Platform(io, encrypt=encrypt, bbram=bbram, strategy=args.strategy)
    platform = Platform(None, io,[])
    # _io_uart_debug wires debug bridge to Rpi; _io_uart_debug_swapped wires console to Rpi

    
    # platform.add_extension(_io_uart_debug_swapped) Commented out, don't know if i need it

    ##### define the soc
    soc = BetrustedSoC(
        platform,
        args.revision,
        xous=args.xous,
        usb_type=args.usb_type,
        uart_name=uart_name,
        bios_path=bios_path,
        puppet=args.puppet,
        use_perfcounter=args.perfcounter,
        app_uart=args.app_uart,
    )

    ##### setup the builder and run it
    builder = Builder(soc,
        output_dir="build",
        csr_csv="build/csr.csv",
        csr_svd="build/software/soc.svd",
        compile_software=False,  # disables auto-build (this is okay)
        compile_gateware=compile_gateware,
        bios_console="disable",
    )
    vns = builder.build()


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
    