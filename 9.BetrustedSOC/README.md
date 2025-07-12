# Betrusted SOC

The [Betrusted](https://github.com/betrusted-io/betrusted-soc) SoC is a LiteX-based, secure, privacy-focused system-on-chip built around the VexRiscv core, originally designed to run on Xilinx Spartan FPGAs for the [Precursor](https://www.crowdsupply.com/sutajio-kosagi/precursor) mobile device. The complete SoC integrates various peripherals such as external SRAM, SPI flash, audio, timers, TRNGs, and cryptographic cores. It also relies on features such as bitstream encryption, false path constraints for timing closure, and other capabilities specific to the Xilinx propriatary toolchain.

 It's worth noting that BetrustedSOC is hosted in a Spartan7 (XC7S50), which is a 50K LUT6 device, 80% utilized as of October 2022, meaning the complete design is severly oversized for our 20k LUT GateMate. On top of that some of these features are **not available** on the Olimex GateMate platform. Therefore, for this project, we are targeting a **minimal port** of Betrusted SoC that includes only the **VexRiscv CPU** (Betrusted version) and **UART** peripheral. This simplified version is intended to serve as a prototype for future work on larger GateMate-based designs (e.g., with 40K or 80K LUT devices).

 This repository covers every step of porting and building the minimal betrusted-soc on GateMate. **This is the first part covering the project peppercorn's new PnR for Gatemate**
<!-- Within this work package, we also plan to create a comprehensive blog that describes all FPGA/RTL developed for the project. -->
---

## Prerequisites

Please refer to the [betrusted-soc repository](https://github.com/betrusted-io/betrusted-soc) for the full list of prerequisites. The project provides building with both [GateMate](https://www.colognechip.com/programmable-logic/gatemate/#tab-313425) toolchain and/or the new [nextpnr](https://www.colognechip.com/programmable-logic/gatemate/#tab-313425) toolchain. We strongly suggest proceeding with the nextpnr toolchain since the latest propriatary toolchain (June 2025) fails in routing the design. Easiest way to install nextpnr is through **oss-cad-suite** prebuilt binaries, building from sources isn't well documented as of July 2025.

To initialize all the dependencies in the 9.BetrustedSOC folder:
```bash
cd ../ #cd to openCologne/
git submodule update --init --recursive
```

To build the 9.BetrustedSOC it’s recommended to use an **isolated Python environment** (e.g., via `venv`) to avoid conflicts with global or newer tool versions, as this project depends on specific versions of LiteX and related tools. 

If you decide to use an isolated Python environment after activating it you have to install litex locally:
```
cd deps/litex/
./litex_setup.py --init --install --config=standard
```

---

## Porting to GateMate
Here we list intricaties of the porting process in detail, explaining common pitfalls with litex and what to look out for. We will not put entire sections of code in this section, but leave to the reader to deduce what each snippet refers to.
### IO and Platform
Accessing IO is easy since the Olimex board is included in `/deps/litex_boards/platforms/olimex_gatemate_a1_evb.py`, you can just import the python file as a package and have access to the programmer, and the whole list of ios (similar to Vivado board files). We defined the IO manually in `betrusted_soc.py`, as well as the programmer in the platform class - like in Betrusted SOC. 

Platform class sets the default toolchain to `peppercorn` with the other option of `colognechip`.
### CRG (Clock and Reset Generation)
Litex intends to obscure the clock and reset generation process, but you still want some control over it. Betrusted-soc has 7 internal clock domains: some always on, some gated for less power consumption when idle; here we stick to only one, tied to a PLL.

Reset is defined as `!pll_lock & arst_n` where arst_n is an external button input, which is then synchronized (with `AsyncResetSynchronizer`) into the PLLs system clock domain. We run into some very important stuff here.

When calling `pll.create_clkout` Litex by default generates a reset tied to the specified clock domain, if not explicitly turned off with an option(`with_reset=False`) as in our case. If you're calling `create_clkout` with it's default settings the reset will be just `!pll_lock`, and trying to specify your own will result in multiple drivers for a `reset`.

Everything connected to a clock domain is tied with it's reset, to obtain full control over the resets and learn more about CRG in Litex visit this [issue](https://github.com/enjoy-digital/litex/issues/1805).

### SoC definition
Litex has a lot of default behaviors which can suprise you, here we will try to explain some which were important in the porting process.

Litex has it's own relatively small bios code which is built when `builder.build()` gets called and intialized in memory. Using the litex bios you need to specify a ROM(exact name of the memory must be ROM) of at least 25kB and a 8kB SRAM(exact name of the memory must be SRAM). Motivation to use litex bios for the price of some memory is because it allows for easy app binary reloading through a serial connection when the SoC is running, without rebuilding the SoC to initialize memory. 

But then where does the real app binary go? We specify a `main_ram` memory(exactly that name) of 32 kB in which we will later load and run our app binary through the serial port. `rom`, `main_ram` and `sram` memory names have specific engrained behaviors in litex. Whatever memory map you specify with `soc.mem_map['rom':0x1000000...]` it gets overwritten with defualt values listed below, which are also defined in `regions.ld` used for building the app.
```
'rom': 0x00000000
'sram': 0x10000000
'main_ram': 0x40000000
```
The Betrusted implementation overrides this behavior with redefining each region after the soc constructor is called if it got overwritten with the default addresses, however we keep things as default. We're already almost out of memory on the GateMate(30/32 blocks used, rest taken by VexRiscv internal caches and UART FIFOs), therefore the betrusted soc relies on external SRAM, which isn't available in our case. This means we're memory limited (except if we get rid of the litex bios), and beyond software and maybe some clever DMA there's not much left to do regarding memory.

We're using 48% of the CPEs and only 8% of DFFs after porting the SoC.

---
## Notes on the Hardware Build Process
To build the hardware and the bios simply run:
```bash
python3 betrusted_soc.py --toolchain=[peppercorn(default), colognechip] > build.log 2>&1
```
Latest Colognechip toolchain(June 2025) fails in routing, a temporary fix is to use previous [versions](https://github.com/chili-chips-ba/openCologne/issues/70), or just stick to peppercorn. **Nextpnr unlike colognechip is timing driven, you can set timing constraints such as false paths.**

### Maximum frequency and nextpnr seeds
`Colognechip`(January 2025) routes to a Fmax of 19 MHz (-tm 3 [proven](https://github.com/chili-chips-ba/openCologne/issues/62)).

Nextpnr is a more complicated story, we've raised an [issue](https://github.com/chili-chips-ba/openCologne/issues/73) explaining it's unpredictable behavior regarding Fmax. However, we've reliably got the design running @ 25 MHz with the nextpnr toolchain.

---


## Notes on Software Build Process

There are two ways to build software in LiteX:

1. **Integrated build** using `Builder(compile_software=True)`: builds the LiteX BIOS along with an application. Useful for ROM-booted systems.
2. **Manual standalone build**: allows targeting bare-metal apps directly. Useful when BIOS integration is not desired or not working.

Challenges encountered so far:

*  The LiteX project offers limited documentation for bare-metal software development. As a reference, we're using the example in `deps/litex/litex/soc/software/demo`, which requires manual adjustment to build correctly.
*  Signed boot support (as in the original Betrusted setup) has been excluded due to incompatibilities in tool versions (Rust).
*  The software stack relies on **Picolibc**, a minimal embedded C library. However, `picolibc.h` is not generated by default in the LiteX environment. We've temporarily worked around this by providing a manually-created stub header.
*  The hardware build process generates `include/` headers and software build paths within the `build/` directory, but since this directory is wiped on rebuilds, we are developing software externally in `software/` to avoid accidental data loss.

---

## Current Status

* [x] Strip down Betrusted SoC to VexRiscv(Betrusted version) and UART
* [x] Update and adapt LiteX build system for GateMate
* [x] Build and run a simple bare-metal test application
* [x] Simulate and validate the hardware build
* [x] Enable boot-time UART binary loading using LiteX BIOS

<!-- **EXTRA**: Incrementally reintroduce additional Betrusted SoC peripherals and features -->

---
## References

* [betrusted-io/betrusted-soc](https://github.com/betrusted-io/betrusted-soc)