#-- Lattice Semiconductor Corporation Ltd.
#-- Synplify OEM project file

#device options
set_option -technology ECP5U
set_option -part LFE5U_85F
set_option -package BG381C
set_option -speed_grade -6

#compilation/mapping options
set_option -symbolic_fsm_compiler true
set_option -resource_sharing true

#use verilog 2001 standard option
set_option -vlog_std v2001

#map options
set_option -frequency 200
set_option -maxfan 1000
set_option -auto_constrain_io 0
set_option -disable_io_insertion false
set_option -retiming false; set_option -pipe true
set_option -force_gsr false
set_option -compiler_compatible 0
set_option -dup false

set_option -default_enum_encoding default

#simulation options


#timing analysis options



#automatic place and route (vendor) options
set_option -write_apr_constraint 1

#synplifyPro options
set_option -fix_gated_and_generated_clocks 1
set_option -update_models_cp 0
set_option -resolve_multiple_driver 0


set_option -seqshift_no_replicate 0

#-- add_file options
set_option -include_path {/home/user/openCologne/4.Advanced--4}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/top_level/pkg/opl3_pkg.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/channels/src/channels.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/channels/src/control_operators.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/channels/src/dac_prep.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/clks/src/clk_div.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/clks/src/reset_sync.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/host_if/src/trick_sw_detection.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/host_if/src/host_if.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/i2s/src/i2s.sv}
add_file -verilog -vlog_std v2001 {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/afifo.v}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/edge_detector.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/leds.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/mem_multi_bank.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/mem_multi_bank_reset.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/mem_simple_dual_port.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/pipeline_sr.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/misc/src/synchronizer.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/calc_phase_inc.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/calc_rhythm_phase.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/env_rate_counter.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/envelope_generator.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/ksl_add_rom.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/operator.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/opl3_exp_lut.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/opl3_log_sine_lut.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/phase_generator.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/tremolo.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/operator/src/vibrato.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/timers/src/timer.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/timers/src/timers.sv}
add_file -verilog -vlog_std sysv {/home/user/openCologne/4.Advanced--4/1.hw/modules/top_level/src/opl3.sv}

#-- top module name
set_option -top_module opl3

#-- set result format/file last
project -result_file {/home/user/openCologne/4.Advanced--4/First_Implementation/OPL3Test_First_Implementation.edi}

#-- error message log file
project -log_file {OPL3Test_First_Implementation.srf}

#-- set any command lines input by customer


#-- run Synplify with 'arrange HDL file'
project -run
