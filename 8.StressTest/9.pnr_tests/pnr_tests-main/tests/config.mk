# GateMate Toolchain Paths
NEXTPNR_GATEMATE_DIR ?= /home/nikola/ChiliChips/openCologne/cc-toolchain-linux/bin/p_r
GATEMATE_TOOLCHAIN_DIR ?= /home/nikola/ChiliChips/openCologne/cc-toolchain-linux
CHIPDB ?= ${NEXTPNR_GATEMATE_DIR}/chipdb

# Project Configuration
PROJECT ?= my_design
TOP ?= ${PROJECT}
TOP_MODULE ?= ${TOP}
TOP_VERILOG ?= ${TOP}.v
CCF ?= ${PROJECT}.ccf  # GateMate uses .ccf constraints file

#.PHONY: print-ccf
#print-ccf:
#	@echo "CCF file path: $(realpath ${CCF})"



BIT_TO_BIN_SCRIPT ?= /home/nikola/ChiliChips/openCologne/pnr_tests-novi/tests

# Additional Settings
PNR_DEBUG ?= # --verbose --debug
BOARD ?= CCGM1A1
JTAG_LINK ?= --board ${BOARD}

#.PHONY: all
#all: ${PROJECT}.bin

#.PHONY: program
#program: ${PROJECT}.bin
#	openFPGALoader ${JTAG_LINK} --bitstream $<

# Synthesis: Convert Verilog to JSON
${PROJECT}.json: ${TOP_VERILOG} ${ADDITIONAL_SOURCES}
	yosys -p "synth_gatemate -top ${TOP_MODULE}; write_json ${PROJECT}.json" $< ${ADDITIONAL_SOURCES}

# Place and Route: JSON -> Routed Design (asc format)
${PROJECT}.asc: ${PROJECT}.json ${CCF}
	${NEXTPNR_GATEMATE_DIR}/p_r --json ${PROJECT}.json --ccf ${CCF} --asc ${PROJECT}.asc ${PNR_DEBUG}

#make ${PROJECT}.asc  # Ensure .asc is generated

# Convert .asc to .bin (bitstream)
${PROJECT}.bin: ${PROJECT}.asc
	python3 ${BIT_TO_BIN_SCRIPT}/fpga-bit-to-bin.py ${PROJECT}.asc ${PROJECT}.bin


.PHONY: clean
clean:
	rm -f *.bin *.asc *.json

.PHONY: pnrclean
pnrclean:
	rm -f *.asc *.bin