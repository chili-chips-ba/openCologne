proc read_files {} {
    read_verilog -sv out.v
}

proc set_defines {} {
set defines {{CCGM 1}}

foreach d ${defines} {
  set key [lindex $d 0]
  set val [lindex $d 1]
  verilog_defines "-D$key=$val"
}}

proc set_incdirs {} {
verilog_defaults -add -Isrc/veerwolf-veer_el2_pack_config_0.7.5 -Isrc/pulp-platform.org__common_cells_1.20.0/include -Isrc/uart16550_1.5.5-r1/rtl/verilog -Isrc/wb_common_1.0.3 -Isrc/pulp-platform.org__axi_0.25.0/include -Isrc/veerwolf-intercon_0.7.5 -Isrc/veerwolf-wb_nospi_intercon_0.7.5}

proc set_params {} {
chparam -set cpu_type {"EL2"} veerwolf_pack_cc}

proc synth {top} {
synth_gatemate -nomx8 -top $top
}

set top veerwolf_pack_cc
set name veerwolf_0.7.5
