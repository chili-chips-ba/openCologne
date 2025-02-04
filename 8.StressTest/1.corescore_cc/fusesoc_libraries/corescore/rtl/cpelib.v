/*
 * cpelib.v
 *
 * Gate level description of a CPE using a set of simplified library elements
 * for post-implementation simulation with back annotated timings.
 *
 * Copyright (C) 2024 Cologne Chip AG <support@colognechip.com>
 *
 * Revision history:
 *   2024-07-24 - Check that CC_PLL OUT_CLK parameter is not zero.
 *   2024-07-12 - Improved simplified CC_PLL simulation model.
 *   2024-03-27 - Fixed CPE_TOBF enable polarity.
 *   2024-01-31 - Added missing C_D, C_DST and C_DRS specify timing constraints.
 *   2023-12-20 - Added CINY2 path for timing simulation.
 *   2023-12-20 - Added CC_PLL lock in time and specify block.
 *   2023-12-19 - Fixed C_ADDF2 and C_ADDF2x CIN signal declaration.
 *   2023-12-19 - Fixed CC_IO_SEL GPIO_EN signal.
 *   2023-12-19 - Added CPE_TOBF module.
 *   2023-06-19 - Prevent implicit declarations.
 *   2023-05-18 - Add FIFO status signals to Block RAM.
 *   2023-03-20 - Enable Block RAM initialization.
 *   2023-02-21 - Added C_D, C_DST and C_DRS initial values.
 *   2023-02-13 - Fixed CADD_{A,S} in C_ADDFx.
 *   2022-12-02 - Added CC_IO_SEL module.
 *   2022-11-01 - C_D, C_DST, C_DRS revision.
 *   2022-08-29 - C_MULT, C_AND and C_OR revision.
 *   2022-06-01 - Initial version.
 */

`timescale 1 ps / 1 ps
module CC_PLL #(
	parameter PLL_CFG = "",
	parameter REF_CLK = 10.0, // e.g. "10.0"
	parameter OUT_CLK = 50.0, // e.g. "50.0"
	parameter PERF_MD = "", // LOWPOWER, ECONOMY, SPEED
	parameter LOCK_REQ = 0,
	parameter LOW_JITTER = 1,
	parameter CI_FILTER_CONST = 2,
	parameter CP_FILTER_CONST = 4
)(
	input  CLK_REF, CLK_FEEDBACK, USR_CLK_REF,
	input  USR_LOCKED_STDY_RST, USR_SET_SEL,
	output reg USR_PLL_LOCKED_STDY,
	output reg USR_PLL_LOCKED,
	output CLK270, CLK180, CLK90, CLK0, CLK_REF_OUT
);

	initial begin
		if (OUT_CLK == 0.0) begin
			$display("ERROR: CC_PLL OUT_CLK parameter may not be zero.");
			$finish();
		end
	end

	// Calculate the delay for the output clock
	// Clock generation
	reg CLK0_reg, CLK90_reg, CLK180_reg, CLK270_reg;
	initial begin
		CLK0_reg   = 0;
		CLK90_reg  = 0;
		CLK180_reg = 0;
		CLK270_reg = 0;
	end

	reg baseclk;
	localparam real clk_period = 1000000.0 / OUT_CLK;  // 15,000 ps (15 ns)
	initial begin
		baseclk = 0;
		forever begin
			#(clk_period/4.0 * 1ps) baseclk = ~baseclk;
		end 
	end

	reg [31:0] clkcnt = 0;
	always @(baseclk)
	begin
		if ((clkcnt > 1) && (clkcnt % 2 == 0)) begin
			CLK0_reg = ~CLK0_reg;
		end
		if ((clkcnt > 2) && ((clkcnt-1) % 2 == 0)) begin
			CLK90_reg = ~CLK90_reg;
		end
		if ((clkcnt > 3) && ((clkcnt-2) % 2 == 0)) begin
			CLK180_reg = ~CLK180_reg;
		end
		if ((clkcnt > 4) && ((clkcnt-3) % 2 == 0)) begin
			CLK270_reg = ~CLK270_reg;
		end
		clkcnt = clkcnt + 1;
	end

	assign CLK0   = LOCK_REQ ? CLK0_reg   & USR_PLL_LOCKED : CLK0_reg;
	assign CLK90  = LOCK_REQ ? CLK90_reg  & USR_PLL_LOCKED : CLK90_reg;
	assign CLK180 = LOCK_REQ ? CLK180_reg & USR_PLL_LOCKED : CLK180_reg;
	assign CLK270 = LOCK_REQ ? CLK270_reg & USR_PLL_LOCKED : CLK270_reg;
	assign CLK_REF_OUT = CLK_REF;

	// USR_PLL_LOCKED and USR_PLL_LOCKED_STDY generation
	integer counter;
	initial begin
		counter = 0;
		USR_PLL_LOCKED = 0;
		USR_PLL_LOCKED_STDY = 0;
	end

	always @(posedge CLK_REF) begin
		if (counter < 57) begin
			counter = counter + 1;
		end else begin
			USR_PLL_LOCKED = 1;
		end
	end

	always @(posedge CLK_REF or posedge USR_LOCKED_STDY_RST) begin
		if (USR_LOCKED_STDY_RST) begin
			USR_PLL_LOCKED_STDY <= 0;
		end else if (USR_PLL_LOCKED) begin
			USR_PLL_LOCKED_STDY <= 1;
		end
	end

`ifdef USE_TIMING
	specify
		(CLK_REF => CLK270) = 0;
		(CLK_REF => CLK180) = 0;
		(CLK_REF => CLK90) = 0;
		(CLK_REF => CLK0) = 0;
	endspecify
`endif
endmodule
