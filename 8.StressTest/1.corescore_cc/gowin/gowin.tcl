create_project -name gowin_corescore ./ -pn GW2AR-LV18QN88C8/I7 -device_version C -force
open_project ./gowin_corescore.gprj 

set_option -verilog_std sysv2017 -top_module corescore_gowin_yosys
set_option -place_option 1
set_option -route_option 0

add_file ./src/constraints.cst
add_file ./src/corescore_0/rtl/base.v ./src/corescore_0/rtl/corescore_gowin_yosys.v ./src/corescore_0/rtl/emitter_uart.v ./src/corescore_0/rtl/gw2a18_clk_gen.v ./src/corescore_0/rtl/wb2axis.v
add_file ./src/corescore-corescorecore_0/corescorecore.v
add_file ./src/serv_1.0.2/rtl/serv_alu.v ./src/serv_1.0.2/rtl/serv_bufreg.v ./src/serv_1.0.2/rtl/serv_csr.v ./src/serv_1.0.2/rtl/serv_ctrl.v ./src/serv_1.0.2/rtl/serv_decode.v ./src/serv_1.0.2/rtl/serv_mem_if.v ./src/serv_1.0.2/rtl/serv_rf_if.v ./src/serv_1.0.2/rtl/serv_rf_ram_if.v ./src/serv_1.0.2/rtl/serv_rf_ram.v ./src/serv_1.0.2/rtl/serv_rf_top.v ./src/serv_1.0.2/rtl/serv_shift.v ./src/serv_1.0.2/rtl/serv_state.v ./src/serv_1.0.2/rtl/serv_top.v
add_file ./src/serving_1.0.2/serving/serving_arbiter.v ./src/serving_1.0.2/serving/serving_mux.v ./src/serving_1.0.2/serving/serving_ram.v ./src/serving_1.0.2/serving/serving.v
add_file ./src/verilog-axis_0-r3/rtl/arbiter.v ./src/verilog-axis_0-r3/rtl/axis_arb_mux.v ./src/verilog-axis_0-r3/rtl/axis_async_fifo.v ./src/verilog-axis_0-r3/rtl/priority_encoder.v

run all