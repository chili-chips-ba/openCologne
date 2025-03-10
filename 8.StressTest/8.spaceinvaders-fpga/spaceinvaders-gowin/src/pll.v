/**
 * PLL configuration
 *
 * This Verilog module was generated automatically
 * using the icepll tool from the IceStorm project.
 * Use at your own risk.
 *
 * Given input frequency:       100.000 MHz
 * Requested output frequency:   25.000 MHz
 * Achieved output frequency:    25.000 MHz
 */

module pll25(
	input  clock_in,
	output clock_out,
	output locked
	);

	wire clk270, clk180, clk90, clk0, usr_ref_out;
	wire usr_pll_lock_stdy, usr_pll_lock;
   wire clkout;

    Gowin_rPLL your_instance_name(
        .clkout(clkout), //output clkout
        .clkoutd(clkoutd), //output clkoutd
        .pll_lock(usr_pll_lock),
        .clkin(clock_in) //input clkin
    );

assign clock_out = clkoutd;
assign locked = usr_pll_lock;
endmodule
