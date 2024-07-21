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
// Description: top_fm Module
//------------------------------------------------------------------------
// Module: top_fm
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

module top_fm
#(
   parameter abcxyz =  0,
   parameter USE_ECP5PLL = 1,
   parameter USE_GM = 0
)
(
   input  logic       clk_25mhz,
   input  logic [6:0] btn,
   output logic [7:0] led,
   output logic       ant_433mhz,
   output logic       wifi_gpio0
);

   generate 
      if(USE_ECP5PLL == 1'b1) begin
          // TODO: Check if this initialization is okay
          // clock generator
          logic clk_locked;
          logic [3:0] clocks;
          logic clk = clocks[0];
          logic clk_fmdds = clocks[1];

           // For ECP5 //
           ecp5pll
           #(
               .in_hz( 25*1000000),
             .out0_hz( 40*1000000),
             .out1_hz(240*1000000)
            )
            ecp5pll_inst
            (
               .clk_i(clk_25mhz),
               .clk_o(clocks),
              .locked(clk_locked)
            );

           
      end else if(USE_GM == 1'b1) begin
         // For GateMate // 


         logic clk270_1, clk180_1, clk90_1, clk0_1, usr_ref_out_1;
	     logic usr_pll_lock_stdy_1, usr_pll_lock_1;

         CC_PLL #(
            .REF_CLK("25.0"),    // reference input in MHz
            .OUT_CLK("40.0"),   // pll output frequency in MHz
            .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
            .LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
            .CI_FILTER_CONST(2), // optional CI filter constant
            .CP_FILTER_CONST(4)  // optional CP filter constant
         ) pll_inst_1 (
            .CLK_REF(clk_25mhz), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
            .USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy_1), .USR_PLL_LOCKED(usr_pll_lock_1),
            .CLK270(clk270_1), .CLK180(clk180_1), .CLK90(clk90_1), .CLK0(clk0_1), .CLK_REF_OUT(usr_ref_out_1)
         );

         logic clk270_2, clk180_2, clk90_2, clk0_2, usr_ref_out_2;
	        logic usr_pll_lock_stdy_2, usr_pll_lock_2;

         CC_PLL #(
            .REF_CLK("25.0"),    // reference input in MHz
            .OUT_CLK("240.0"),   // pll output frequency in MHz
            .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
            .LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
            .CI_FILTER_CONST(2), // optional CI filter constant
            .CP_FILTER_CONST(4)  // optional CP filter constant
         ) pll_inst_2 (
            .CLK_REF(clk_25mhz), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
            .USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy_2), .USR_PLL_LOCKED(usr_pll_lock_2),
            .CLK270(clk270_2), .CLK180(clk180_2), .CLK90(clk90_2), .CLK0(clk0_2), .CLK_REF_OUT(usr_ref_out_2)
         );
		 
		  logic clk = clk0_1;
          logic clk_fmdds = clk0_2;

      end
   endgenerate

   // TODO: Add generate for Lattice Diamond


  logic [15:0] beep; // TODO: Maybe typedef counter_t?
  always @(posedge clk) begin
    beep <= beep + 1;
  end

  reg [7:0] rds_ram[0:51];

  initial begin
    $readmemh("message_ps.mem", rds_ram);
  end

  logic  [5:0] rds_addr;
  logic  [7:0] rds_data;

  always_ff @(posedge clk) begin
     rds_data <= rds_ram[rds_addr];
  end

   fmgen_test
   //#(
   //  .C_fmdds_hz(250*1000000),
   //  .C_rds_clock_multiply(228),
   //  .C_rds_clock_divide(3125)
   //)
   fmgen_test_inst
   (
     .clk(clk),
     .clk_fmdds(clk_fmdds),
     .pcm_in_left(btn[1] ? beep[15:1] : 0), // beep, may spoil RDS
     .pcm_in_right(btn[2] ? beep[15:1] : 0), // beep, may spoil RDS
     .cw_freq(107900000),
     .rds_addr(rds_addr),
     .rds_data(rds_data),
     .fm_antenna(ant_433mhz)
   );

   always_comb led = rds_data;

endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 TH: Initial creation

*/
