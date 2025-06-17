open_checkpoint ./build/gateware/betrusted_soc_route.dcp
create_slack_histogram -delay_type max -num_bins 100 -to [get_clocks -of_objects [get_pins MMCME2_ADV/CLKOUT6]] -significant_digits 3 -file histo_max.txt
create_slack_histogram -delay_type min -num_bins 100 -to [get_clocks -of_objects [get_pins MMCME2_ADV/CLKOUT6]] -significant_digits 3 -file histo_min.txt
