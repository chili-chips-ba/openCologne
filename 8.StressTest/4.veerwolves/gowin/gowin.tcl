create_project -name gowin_veerwolf ./ -pn GW2AR-LV18QN88C8/I7 -device_version C -force
open_project ./gowin_veerwolf.gprj 

set_option -verilog_std sysv2017 -top_module veerwolf_pack_cc
set_option -place_option 1
set_option -route_option 0

# add_file src/config/common_defines.vh
# add_file src/veerwolf_0.7.5/rtl/axi_ram.v src/veerwolf_0.7.5/rtl/axi2wb.v src/veerwolf_0.7.5/rtl/clk_gen_cc.v src/veerwolf_0.7.5/rtl/dpram64.v src/veerwolf_0.7.5/rtl/veer_el2_wrapper.sv src/veerwolf_0.7.5/rtl/veerwolf_nospi.v src/veerwolf_0.7.5/rtl/veerwolf_pack_cc.v src/veerwolf_0.7.5/rtl/veerwolf_syscon.v src/veerwolf_0.7.5/rtl/veerwolf_tile.v src/veerwolf_0.7.5/rtl/wb_mem_wrapper.v
# add_file src/chipsalliance.org_cores_VeeR_EL2_1.4/chipsalliance.org_cores_VeeR_EL2_1.4/design/include/el2_def.sv

# add_file src/veerwolf-wolfpack_0.7.5/veerwolf_pack.v

# add_file src/uart16550_1.5.5-r1/rtl/verilog/raminfr.v src/uart16550_1.5.5-r1/rtl/verilog/uart_defines.v src/uart16550_1.5.5-r1/rtl/verilog/uart_receiver.v src/uart16550_1.5.5-r1/rtl/verilog/uart_regs.v src/uart16550_1.5.5-r1/rtl/verilog/uart_rfifo.v src/uart16550_1.5.5-r1/rtl/verilog/uart_sync_flops.v src/uart16550_1.5.5-r1/rtl/verilog/uart_tfifo.v src/uart16550_1.5.5-r1/rtl/verilog/uart_top.v src/uart16550_1.5.5-r1/rtl/verilog/uart_transmitter.v src/uart16550_1.5.5-r1/rtl/verilog/uart_wb.v

# add_file src/veerwolf-intercon_0.7.5/axi_intercon.v

# foreach f [glob -nocomplain src/pulp-platform.org__axi_0.25.0/src/*.sv] {
#     add_file $f
# }

add_file src/out.v 
run all