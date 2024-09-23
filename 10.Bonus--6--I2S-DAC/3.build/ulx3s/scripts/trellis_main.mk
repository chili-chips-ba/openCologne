#========================================================================================
# Tools Installation
#========================================================================================

#-------------------------------
# VHD2VL
#-------------------------------
# Github reference: https://github.com/ldoolitt/vhd2vl
# Installation: Clone the repository, run make and copy the executable from src to your path
#               $ git clone https://github.com/ldoolitt/vhd2vl.git
#               $ cd vhd2vl
#               $ make
#               $ cd src
#               $ sudo cp /home/user/FPGA/tools/vhd2vl/src/vhdl2vl /usr/local/bin/ 
#               Or add src/vhd2vl to your PATH
VHD2VL        ?= vhd2vl 
#-------------------------------
# YOSYS
#-------------------------------
# Github reference: https://github.com/YosysHQ/yosys
# Installation:
#              $ git clone https://github.com/YosysHQ/yosys.git
#              $ cd yosys
#              $ make config-clang
#              $ git submodule update --init
#              $ make -j$(nproc)
#              $ sudo make install

YOSYS        ?= yosys

#-------------------------------
# PRJTRELLIS
#-------------------------------
# Github reference: https://github.com/SymbiFlow/prjtrellis
# Dependencies: 
#   *Python 3.5 or later, including development libraries (python3-dev on Ubuntu)
#   *A modern C++14 compiler (Clang is recommended)
#   *CMake 3.5 or later
#   *Boost
#   *Git
#   *Recent OpenOCD for device programming (--enable-ftdi required if building from source)
# Installation:
#             $ git clone --recursive https://github.com/YosysHQ/prjtrellis
#             $ cd libtrellis
#             $ cmake -DCMAKE_INSTALL_PREFIX=/usr/local .
#             $ make
#             $ sudo make install

TRELLIS        ?= /home/user/FPGA/tools/prjtrellis

#-------------------------------
# NEXTPNR
#-------------------------------
# Github reference nextpnr: https://github.com/YosysHQ/nextpnr
# Github reference nextpnr-ecp5 : https://github.com/YosysHQ/nextpnr?tab=readme-ov-file#nextpnr-ecp5
# Installation: For ECP5 support, install Project Trellis to /usr/local or another location, which should be passed as -DTRELLIS_INSTALL_PREFIX=/usr/local to CMake. Then build and install nextpnr-ecp5 using the following commands:

#              $ cmake . -DARCH=ecp5 -DTRELLIS_INSTALL_PREFIX=/usr/local
#              $ make -j$(nproc)
#              $ sudo make install

NEXTPNR-ECP5 ?= nextpnr-ecp5


#========================================================================================
# Project, Board, and Chip Name
#========================================================================================
FPGA_PACKAGE ?= CABGA381

#========================================================================================
# Design Files
#========================================================================================
VHDL_FILES ?=


#========================================================================================
# Open Source Synthesis Tools
#========================================================================================
TRELLISDB      ?= $(TRELLIS)/database
LIBTRELLIS     ?= $(TRELLIS)/libtrellis
ECPPLL         ?= LANG=C ecppll # LANG=C LD_LIBRARY_PATH=$(LIBTRELLIS) $(TRELLIS)/libtrellis/ecppll
ECPPACK        ?= LANG=C ecppack # LANG=C LD_LIBRARY_PATH=$(LIBTRELLIS) $(TRELLIS)/libtrellis/ecppack --db $(TRELLISDB)
BIT2SVF        ?= $(TRELLIS)/tools/bit_to_svf.py
#BASECFG       ?= $(TRELLIS)/misc/basecfgs/empty_$(FPGA_CHIP_EQUIVALENT).config
# yosys options: sometimes those can be used: -noccu2 -nomux -nodram
YOSYS_OPTIONS  ?=
# nextpnr options
NEXTPNR_OPTIONS ?=

ifeq ($(FPGA_CHIP), lfe5u-12f)
  CHIP_ID = 0x21111043
endif
ifeq ($(FPGA_CHIP), lfe5u-25f)
  CHIP_ID = 0x41111043
endif
ifeq ($(FPGA_CHIP), lfe5u-45f)
  CHIP_ID = 0x41112043
endif
ifeq ($(FPGA_CHIP), lfe5u-85f)
  CHIP_ID = 0x41113043
endif

FPGA_K             = $(FPGA_PREFIX)$(FPGA_SIZE)
IDCODE_CHIPID      =
FPGA_CHIP_EQUIVALENT ?= lfe5u-$(FPGA_K)f

#========================================================================================
# Clock Generator
#========================================================================================
CLK0_NAME       ?= clk0
CLK0_FILE_NAME  ?= clocks/$(CLK0_NAME).v
CLK0_OPTIONS    ?= --input 25 --output 100 --s1 50 --p1 0 --s2 25 --p2 0 --s3 125 --p3 0
CLK1_NAME       ?= clk1
CLK1_FILE_NAME  ?= clocks/$(CLK1_NAME).v
CLK1_OPTIONS    ?= --input 25 --output 100 --s1 50 --p1 0 --s2 25 --p2 0 --s3 125 --p3 0
CLK2_NAME       ?= clk2
CLK2_FILE_NAME  ?= clocks/$(CLK2_NAME).v
CLK2_OPTIONS    ?= --input 25 --output 100 --s1 50 --p1 0 --s2 25 --p2 0 --s3 125 --p3 0
CLK3_NAME       ?= clk3
CLK3_FILE_NAME  ?= clocks/$(CLK3_NAME).v
CLK3_OPTIONS    ?= --input 25 --output 100 --s1 50 --p1 0 --s2 25 --p2 0 --s3 125 --p3 0

#========================================================================================
# Closed Source Synthesis Tools
#========================================================================================
DIAMOND_BASE    ?= /home/user/FPGA/tools/diamond/usr/local/diamond
ifneq ($(wildcard $(DIAMOND_BASE)),)
  DIAMOND_BIN   := $(shell find ${DIAMOND_BASE}/ -maxdepth 2 -name bin | sort -rn | head -1)
  DIAMONDC      := $(shell find ${DIAMOND_BIN}/ -name diamondc)
  DDTCMD        := $(shell find ${DIAMOND_BIN}/ -name ddtcmd)
endif

#========================================================================================
# Programming Tools
#========================================================================================
UJPROG                 ?= fujprog
OPENFPGALOADER         ?= openFPGALoader
OPENFPGALOADER_OPTIONS ?= --board ulx3s
FLEAFPGA_JTAG          ?= FleaFPGA-JTAG 
OPENOCD                ?= openocd
OPENOCD_INTERFACE      ?= $(SCRIPTS)/ft231x.ocd
DFU_UTIL               ?= dfu-util
TINYFPGASP             ?= tinyfpgasp

#========================================================================================
# Helper Scripts Directory
#========================================================================================
SCRIPTS ?= scripts

# Rest of the Include Makefile
FPGA_CHIP_UPPERCASE := $(shell echo $(FPGA_CHIP) | tr '[:lower:]' '[:upper:]')


#========================================================================================
# Toolchain Targets
#========================================================================================

do_all: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).svf

all: synth pnr bitstream prog

#-------------------------------
# VHDL to Verilog Conversion
#-------------------------------
# Convert all *.vhd filenames to .v extension
VHDL_TO_VERILOG_FILES = $(VHDL_FILES:.vhd=.v)
# Implicit conversion rule
%.v: %.vhd
	$(VHDL2VL) $< $@

#-------------------------------
# Synth targets
#-------------------------------

#Define the log directory
LOG_DIR = log

# Synth target
synth: $(PROJECT).json

$(PROJECT).json: $(VERILOG_FILES) $(VHDL_TO_VERILOG_FILES)
	@mkdir -p $(LOG_DIR)
	$(YOSYS) \
	-p "read -sv $(VERILOG_FILES) $(VHDL_TO_VERILOG_FILES)" \
	-p "hierarchy -top ${TOP_MODULE}" \
	-p "synth_ecp5 ${YOSYS_OPTIONS} -json $(PROJECT).json" \
	2>&1 | tee $(LOG_DIR)/synth.log

#-------------------------------
# PNR
#-------------------------------
# PNR target
pnr: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).config

$(BOARD)_$(FPGA_SIZE)f_$(PROJECT).config: $(PROJECT).json $(BASECFG)
	@mkdir -p $(LOG_DIR)
	$(NEXTPNR-ECP5) $(NEXTPNR_OPTIONS) \
	--$(FPGA_K)k --package $(FPGA_PACKAGE) \
	--json $(PROJECT).json \
	--lpf $(CONSTRAINTS) \
	--textcfg $@ \
	2>&1 | tee $(LOG_DIR)/pnr.log

#-------------------------------
# Bitstream Generation
#-------------------------------
bitstream: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
$(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).config
	$(ECPPACK) $(IDCODE_CHIPID) --compress --freq $(FLASH_READ_MHZ) --input $< --bit $@
#	$(ECPPACK) $(IDCODE_CHIPID) --compress --freq $(FLASH_READ_MHZ) --spimode $(FLASH_READ_MODE) --input $< --bit $@

#-------------------------------
# Clock File Generation
#-------------------------------
$(CLK0_FILE_NAME):
	$(ECPPLL) $(CLK0_OPTIONS) --file $@

$(CLK1_FILE_NAME):
	$(ECPPLL) $(CLK1_OPTIONS) --file $@

$(CLK2_FILE_NAME):
	$(ECPPLL) $(CLK2_OPTIONS) --file $@

$(CLK3_FILE_NAME):
	$(ECPPLL) $(CLK3_OPTIONS) --file $@

#-------------------------------
# XCF Programming File Generation for DDTCMD
#-------------------------------
$(BOARD)_$(FPGA_SIZE)f.xcf: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit $(SCRIPTS)/$(BOARD)_sram.xcf $(SCRIPTS)/xcf.xsl $(DTD_FILE)
	xsltproc \
	  --stringparam FPGA_CHIP $(FPGA_CHIP_UPPERCASE) \
	  --stringparam CHIP_ID $(CHIP_ID) \
	  --stringparam BITSTREAM_FILE $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit \
	  $(SCRIPTS)/xcf.xsl $(SCRIPTS)/$(BOARD)_sram.xcf > $@

# Run DDTCMD to Generate VME File
$(BOARD)_$(FPGA_SIZE)f_$(PROJECT).vme: $(BOARD)_$(FPGA_SIZE)f.xcf $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	LANG=C ${DDTCMD} -oft -fullvme -if $(BOARD)_$(FPGA_SIZE)f.xcf -nocompress -noheader -of $@

# Generate SVF File by prjtrellis Python Script
$(BOARD)_$(FPGA_SIZE)f_$(PROJECT).svf: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).config
	$(ECPPACK) $(IDCODE_CHIPID) $< --compress --freq $(FLASH_READ_MHZ) --svf-rowsize 800000 --svf $@
#	$(ECPPACK) $(IDCODE_CHIPID) $< --compress --freq $(FLASH_READ_MHZ) --spimode $(FLASH_READ_MODE) --svf-rowsize 800000 --svf $@

#========================================================================================
# Programming Targets
#========================================================================================

# Program SRAM with UJPROG
prog: program
program: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(UJPROG) $<

# Program SRAM with OPENFPGALOADER
prog_ofl: program_ofl
program_ofl: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(OPENFPGALOADER) $(OPENFPGALOADER_OPTIONS) $<

# Program SRAM with FleaFPGA-JTAG
program_flea: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).vme
	$(FLEAFPGA_JTAG) $<

# Program FLASH over US1 Port with UJPROG (Permanent)
flash: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(UJPROG) -j flash $<

# Program FLASH over US1 Port with openFPGALoader (Permanent)
flash_ofl: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(OPENFPGALOADER) $(OPENFPGALOADER_OPTIONS) -f $<

# Program FLASH over US2 Port with DFU Bootloader (Permanent)
flash_dfu: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(DFU_UTIL) -a 0 -D $<
	$(DFU_UTIL) -a 0 -e

# Program FLASH over US2 Port with tinyfpgasp Bootloader (Permanent)
flash_tiny: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
	$(TINYFPGASP) -w $<

# Generate Chip-Specific OpenOCD Programming File
$(BOARD)_$(FPGA_SIZE)f.ocd: $(SCRIPTS)/ecp5-ocd.sh
	$(SCRIPTS)/ecp5-ocd.sh $(CHIP_ID) $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).svf > $@

# Program SRAM with OPENOCD
prog_ocd: program_ocd
program_ocd: $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).svf $(BOARD)_$(FPGA_SIZE)f.ocd
	$(OPENOCD) --file=$(OPENOCD_INTERFACE) --file=$(BOARD)_$(FPGA_SIZE)f.ocd

#========================================================================================
# Clean Targets
#========================================================================================
JUNK = *~
#JUNK += $(PROJECT).ys
JUNK += $(PROJECT).json
JUNK += $(VHDL_TO_VERILOG_FILES)
JUNK += $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).config
JUNK += $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).bit
JUNK += $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).vme
JUNK += $(BOARD)_$(FPGA_SIZE)f_$(PROJECT).svf
JUNK += $(BOARD)_$(FPGA_SIZE)f.xcf
JUNK += $(BOARD)_$(FPGA_SIZE)f.ocd
JUNK += $(CLK0_FILE_NAME) $(CLK1_FILE_NAME) $(CLK2_FILE_NAME) $(CLK3_FILE_NAME)

# Remove log directory
clean:
	rm -f $(JUNK)
	rm -rf $(LOG_DIR)
