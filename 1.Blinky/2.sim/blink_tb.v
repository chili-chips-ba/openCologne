//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//------------------------------------------------------------------------
//                   Copyright (C) 2024 Chili.CHIPS*ba
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
// 1. Redistributions of source code must retain the above copyright 
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright 
// notice, this list of conditions and the following disclaimer in the 
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its 
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//              https://opensource.org/license/bsd-3-clause
//------------------------------------------------------------------------
// Description: Blink Testbench taken from official toolchain
//========================================================================

// <modify as needed>

`timescale 1 ns / 1 ps

// simplified CC_PLL model
// Commented out so that make impl_sim command can work
/*module CC_PLL #(
	parameter REF_CLK = "10.0", // e.g. "10.0"
	parameter OUT_CLK = "100.0", // e.g. "50.0"
	parameter PERF_MD = "", // LOWPOWER, ECONOMY, SPEED
	parameter LOW_JITTER = 1,
	parameter CI_FILTER_CONST = 2,
	parameter CP_FILTER_CONST = 4
)(
	input  CLK_REF, CLK_FEEDBACK, USR_CLK_REF,
	input  USR_LOCKED_STDY_RST, USR_SET_SEL,
	output USR_PLL_LOCKED_STDY, USR_PLL_LOCKED,
	output CLK270, CLK180, CLK90, CLK0, CLK_REF_OUT
);

	reg r_user_pll_locked_stdy;
	reg r_user_pll_locked;
	reg r_clk270;
	reg r_clk180;
	reg r_clk90;
	reg r_clk0;
	reg r_clk_ref_out;

	assign USR_PLL_LOCKED_STDY = r_user_pll_locked_stdy;
	assign USR_PLL_LOCKED      = r_user_pll_locked;
	assign CLK270              = r_clk270;
	assign CLK180              = r_clk180;
	assign CLK90               = r_clk90;
	assign CLK0                = r_clk0;
	assign CLK_REF_OUT         = CLK_REF | USR_CLK_REF;

	integer clkcnt = 0;
	initial begin
		r_user_pll_locked_stdy = 1'b0;
		r_user_pll_locked = 1'b0;
		r_clk270 = 1'b0;
		r_clk180 = 1'b0;
		r_clk90 = 1'b0;
		r_clk0 = 1'b0;
	end

	always @(CLK_REF or USR_CLK_REF)
	begin
		if ((clkcnt > 1) && (clkcnt % 2 == 0)) begin
			r_clk0 = ~r_clk0;
		end
		if ((clkcnt > 2) && ((clkcnt-1) % 2 == 0)) begin
			r_clk90 = ~r_clk90;
		end
		if ((clkcnt > 3) && ((clkcnt-2) % 2 == 0)) begin
			r_clk180 = ~r_clk180;
		end
		if ((clkcnt > 4) && ((clkcnt-3) % 2 == 0)) begin
			r_clk270 = ~r_clk270;
		end
		clkcnt = clkcnt + 1;
	end
endmodule 
*/
module tb;

	reg clk;
	reg rst;
	wire led;
 reg clk_pll;

	initial begin
`ifdef CCSDF
		$sdf_annotate("blink_00.sdf", dut);
`endif
		$dumpfile("../2.sim/blink_tb.vcd");
		$dumpvars(0, tb);
		clk = 0;
		rst = 0;
	end

	always clk = #50 ~clk;

	blink dut (
		.clk(clk),
		.rst(rst),
		.led(led),
		.clk_pll(clk_pll)
	);

	initial begin
		#2000;
		rst = 1;
		#4000;
		$finish;
	end

endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/11 Tarik Hamedović: Initial creation
*/
