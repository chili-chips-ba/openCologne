/*
 * gatemate_25MHz_pll.v
 *
 * Copyright (C) 2022-2024  Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 * SPDX-License-Identifier: MIT
 */
module pll (
    input  wire clock_in,
    input  wire rst_in,
    output wire clock_out,

    output reg  locked
);

    wire pll_clk_nobuf;


	wire clk270, clk180, clk90, clk0, usr_ref_out;
	wire usr_pll_lock_stdy, usr_pll_lock;

	CC_PLL #(
		.REF_CLK(10.0),      // reference input in MHz
		.OUT_CLK(25.0),     // pll output frequency in MHz
		.PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
		.LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
		.CI_FILTER_CONST(2), // optional CI filter constant
		.CP_FILTER_CONST(4)  // optional CP filter constant
	) pll_inst (
		.CLK_REF(clock_in), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
		.USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy), .USR_PLL_LOCKED(usr_pll_lock),
		.CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(pll_clk_nobuf), .CLK_REF_OUT(usr_ref_out)
	);


CC_BUFG pll_bufg (.I(pll_clk_nobuf), .O(clock_out));

// reset is synced the clock
reg locked_s1;
always @(posedge clock_out) begin
    locked_s1 <= usr_pll_lock & ~rst_in;
    locked <= locked_s1;
end

endmodule
