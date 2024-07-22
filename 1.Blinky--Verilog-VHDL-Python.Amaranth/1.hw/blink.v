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
// Description: Blink Example taken from official toolchain
//========================================================================


`timescale 1ns / 1ps

module blink (
    input  wire clk,
    input  wire rst,
    output wire led,
    output wire clk_pll
);

  reg [26:0] counter;

  wire clk270, clk180, clk90, clk0, usr_ref_out;
  wire usr_pll_lock_stdy, usr_pll_lock;

  CC_PLL #(
      .REF_CLK        ("10.0"),     // reference input in MHz
      .OUT_CLK        ("100.0"),    // pll output frequency in MHz
      .PERF_MD        ("ECONOMY"),  // LOWPOWER, ECONOMY, SPEED
      .LOW_JITTER     (1),          // 0: disable, 1: enable low jitter mode
      .CI_FILTER_CONST(2),          // optional CI filter constant
      .CP_FILTER_CONST(4)           // optional CP filter constant
  ) pll_inst (
      .CLK_REF(clk),
      .CLK_FEEDBACK(1'b0),
      .USR_CLK_REF(1'b0),
      .USR_LOCKED_STDY_RST(1'b0),
      .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy),
      .USR_PLL_LOCKED(usr_pll_lock),
      .CLK270(clk270),
      .CLK180(clk180),
      .CLK90(clk90),
      .CLK0(clk0),
      .CLK_REF_OUT(usr_ref_out)
  );

  assign led = counter[26];

  assign clk_pll = clk0;

  always @(posedge clk0) begin
    if (!rst) begin
      counter <= 0;
    end else begin
      counter <= counter + 1'b1;
    end
  end

endmodule



/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/10 Tarik Hamedović: Initial creation
*/
