create_project -name build_proj ./ -pn GW2AR-LV18QN88C8/I7 -device_version C -force
open_project ./build_proj.gprj 
set_option -verilog_std sysv2017 -top_module sd_dac_top
# Add Verilog source files for the project
add_file src/cic1.v
add_file src/cic2.v
add_file src/cic3.v
add_file src/cic4.v
add_file src/halfBandFirst.v
add_file src/halfBandFirstOrg.v
add_file src/halfBandSecond.v
add_file src/halfBandSecondOrg.v
add_file src/interpolatingFilter.v
add_file src/interpolatingFilterOrg.v
add_file src/inverseSinc.v
add_file src/inverseSincOrg.v
add_file src/quarterwave_generator.v
add_file src/quarterwave_table.v
add_file src/sd_dac_top.v
add_file src/sigma_delta_modulator_1st.v
add_file src/sigma_delta_modulator.v

run syn