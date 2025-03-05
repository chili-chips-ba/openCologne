proc read_files {} {
read_verilog {src/serv_1.0.2/rtl/serv_shift.v}
read_verilog {src/serv_1.0.2/rtl/serv_bufreg.v}
read_verilog {src/serv_1.0.2/rtl/serv_alu.v}
read_verilog {src/serv_1.0.2/rtl/serv_csr.v}
read_verilog {src/serv_1.0.2/rtl/serv_ctrl.v}
read_verilog {src/serv_1.0.2/rtl/serv_decode.v}
read_verilog {src/serv_1.0.2/rtl/serv_mem_if.v}
read_verilog {src/serv_1.0.2/rtl/serv_rf_if.v}
read_verilog {src/serv_1.0.2/rtl/serv_rf_ram_if.v}
read_verilog {src/serv_1.0.2/rtl/serv_rf_ram.v}
read_verilog {src/serv_1.0.2/rtl/serv_state.v}
read_verilog {src/serv_1.0.2/rtl/serv_top.v}
read_verilog {src/serv_1.0.2/rtl/serv_rf_top.v}
read_verilog {src/verilog-axis_0-r3/rtl/arbiter.v}
read_verilog {src/verilog-axis_0-r3/rtl/priority_encoder.v}
read_verilog {src/verilog-axis_0-r3/rtl/axis_arb_mux.v}
read_verilog {src/verilog-axis_0-r3/rtl/axis_async_fifo.v}
read_verilog {src/serving_1.0.2/serving/serving_arbiter.v}
read_verilog {src/serving_1.0.2/serving/serving_mux.v}
read_verilog {src/serving_1.0.2/serving/serving_ram.v}
read_verilog {src/serving_1.0.2/serving/serving.v}
read_verilog {src/corescore_0/rtl/wb2axis.v}
read_verilog {src/corescore_0/rtl/base.v}
read_verilog {src/corescore_0/rtl/emitter_uart.v}
read_verilog {src/corescore_0/rtl/cc_gatemate_clock_gen.v}
read_verilog {src/corescore_0/rtl/corescore_gatemate.v}
read_verilog {src/corescore-corescorecore_0/corescorecore.v}
}

proc set_defines {} {
set defines {{CCGM 1}}

foreach d ${defines} {
  set key [lindex $d 0]
  set val [lindex $d 1]
  verilog_defines "-D$key=$val"
}}

proc set_incdirs {} {
verilog_defaults -add -Isrc/serv_1.0.2/rtl}

proc set_params {} {
}

proc synth {top} {
synth_gatemate -nomx8 -top $top
}

set top corescore_gatemate
set name corescore_0
