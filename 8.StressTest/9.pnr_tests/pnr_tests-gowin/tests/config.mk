# Gowin Toolchain Paths
# TODO: Update with your actual Gowin IDE installation path
GOWIN_IDE_DIR ?= /home/nikola/ChiliChips/Gowin_V1.9.11.01_linux
# Path to Gowin synthesis tools
GOWIN_SYNTH_DIR ?= ${GOWIN_IDE_DIR}/IDE/bin
# Path to Gowin place and route tools
GOWIN_PNR_DIR ?= ${GOWIN_IDE_DIR}/IDE/bin

# Project Configuration
PROJECT ?= my_design
TOP ?= ${PROJECT}
TOP_MODULE ?= ${TOP}
TOP_VERILOG ?= ${TOP}.v
# Gowin uses .cst for constraints instead of .ccf
CST ?= ${PROJECT}.cst

# Device Configuration
# Specify the Gowin device
DEVICE ?= GW2AR-18C
PACKAGE ?= LQFP176
PART ?= ${DEVICE}-${PACKAGE}

# Additional Settings
BOARD ?= GW2AR-18CLQFP176
JTAG_LINK ?= --board ${BOARD}

# Synthesis: Convert Verilog to JSON (for Yosys)
${PROJECT}.json: ${TOP_VERILOG} ${ADDITIONAL_SOURCES}
	yosys -p "synth_gowin -top ${TOP_MODULE} -json ${PROJECT}.json" $< ${ADDITIONAL_SOURCES}

# Alternatively, use Gowin's native synthesis tool:
${PROJECT}.fs: ${TOP_VERILOG} ${ADDITIONAL_SOURCES}
	# TODO: Update with correct parameters for your design
	${GOWIN_SYNTH_DIR}/gw_sh -synthesize -prj ${PROJECT}.tcl

# Place and Route: Using Gowin's tool to generate bitstream
${PROJECT}.fs: ${PROJECT}.json ${CST}
	# TODO: Create appropriate TCL script for your design
	${GOWIN_PNR_DIR}/gw_sh -run -prj ${PROJECT}_pnr.tcl

# Convert to binary format if needed
${PROJECT}.bin: ${PROJECT}.fs
	# TODO: If necessary, use appropriate conversion tool
	# Gowin typically produces .fs files that can be used directly
	cp ${PROJECT}.fs ${PROJECT}.bin

# Programming target
.PHONY: program
program: ${PROJECT}.fs
	# Using openFPGALoader if compatible
	#openFPGALoader ${JTAG_LINK} --bitstream $
	# Alternatively, use Gowin's programmer:
	 ${GOWIN_IDE_DIR}/Programmer/bin/programmer_cli --run --device ${DEVICE} --fsFile ${PROJECT}.fs

.PHONY: clean
clean:
	rm -f *.bin *.fs *.json

.PHONY: pnrclean
pnrclean:
	rm -f *.fs *.bin
