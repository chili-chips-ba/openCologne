# vhdl files
TESTBENCH=ws2812_gol_tb
FILES = ../src/*vhd
VHDLEX = .vhd

# testbench
TESTBENCHFILE = ./${TESTBENCH}$(VHDLEX)
SPI_MASTER = ./spi_master.vhd


#GHDL CONFIG
GHDL_CMD = ghdl
GHDL_FLAGS  = 

SIMDIR = simulation
STOP_TIME = 6ms
GHDL_SIM_OPT = --stop-time=$(STOP_TIME) --stop-delta=100000

WAVEFORM_VIEWER = gtkwave

.PHONY: clean

all: clean compile run view

compile:
	@mkdir -p $(SIMDIR)
	@$(GHDL_CMD) -i $(GHDL_FLAGS) --workdir=$(SIMDIR) --work=work $(TESTBENCHFILE) $(SPI_MASTER) $(FILES)
	@$(GHDL_CMD) -m $(GHDL_FLAGS) --workdir=$(SIMDIR) --work=work $(TESTBENCH)


run:
	@$(GHDL_CMD) -r --workdir=$(SIMDIR) --work=work $(TESTBENCH) --wave=$(SIMDIR)/$(TESTBENCH).ghw  $(GHDL_SIM_OPT)

view:
	$(WAVEFORM_VIEWER) --dump=$(SIMDIR)/$(TESTBENCH).ghw --save ./$(TESTBENCH).gtkw 

clean:
	@rm -rf $(SIMDIR)
