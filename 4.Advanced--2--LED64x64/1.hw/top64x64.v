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
// Description: 
//========================================================================


module top
(
   input clk,
   input btn,
   output led,
   output [27:0] gp, gn
    //output wifi_gpio0
);
   //  0: PMOD straight male header to flat cable
   // 90: PMOD 90-deg female header
   parameter PMOD_J1 = 0;
   parameter PMOD_J2 = 90;

   // prevent ESP32 firmware from taking control of the board
   // (we don't want it write its "passthru" bitstream)
   //assign wifi_gpio0 = 1'b1;


   wire clk270, clk180, clk90, clk_25mhz, usr_ref_out;
   wire usr_pll_lock_stdy, usr_pll_lock;
   
   CC_PLL #(
   	  .REF_CLK("10.0"),    // reference input in MHz
   	  .OUT_CLK("25.0"),   // pll output frequency in MHz
   	  .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
   	  .LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
   	  .CI_FILTER_CONST(2), // optional CI filter constant
   	  .CP_FILTER_CONST(4)  // optional CP filter constant
   )   pll_inst (
   	  .CLK_REF(clk), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
   	  .USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy), .USR_PLL_LOCKED(usr_pll_lock),
   	  .CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(clk_25mhz), .CLK_REF_OUT(usr_ref_out)
   );
   
   wire pixclk;
   assign pixclk = clk_25mhz;

   // simple animation counter
   parameter anim_bits = 26;
   reg [anim_bits-1:0] ANIM;
   always @(posedge pixclk)
   begin
      ANIM <= ANIM + 1;
   end

   // simple combinatorial logic which also creates some picture
   // assign RGB0 = ADDRX[2:0] == 7 ? 3'b010 : 3'b100; // 3'bBGR
   // assign RGB0 = ADDRX[2:0] == ADDRY[2:0] + ANIM[26:24] ? 3'b010 : 3'b100; // 3'bBGR
   // assign RGB1 = ADDRX[2:0] == ANIM[26:24] ? 3'b011 : 3'b100; // 3'bBGR

   // test picture generator
   wire [7:0] CounterX, CounterY;
   wire [4:0] ADDRY0;
   assign ADDRY0 = ADDRY+1;
   assign CounterX = ADDRX + ANIM[anim_bits-1:anim_bits-7];
   assign CounterY = {1'b0,ADDRY0} + ANIM[anim_bits-1:anim_bits-9];
   wire [7:0] W = {8{CounterX[7:0]==CounterY[7:0]}};
   wire [7:0] A = {8{CounterX[7:5]==3'h2 && CounterY[7:5]==3'h2}};
   reg [7:0] red, green, blue;
   always @(posedge pixclk) red <= ({CounterX[5:0] & {6{CounterY[4:3]==~CounterX[4:3]}}, 2'b00} | W) & ~A;
   always @(posedge pixclk) green = (CounterX[7:0] & {8{CounterY[6]}} | W) & ~A;
   always @(posedge pixclk) blue = CounterY[7:0] | W | A;

   // same as above but for lower half of the display (32 pixels below)
   wire [7:0] CounterY1;
   assign CounterY1 = {1'b1,ADDRY0} + ANIM[anim_bits-1:anim_bits-9];
   wire [7:0] W1 = {8{CounterX[7:0]==CounterY1[7:0]}};
   wire [7:0] A1 = {8{CounterX[7:5]==3'h2 && CounterY1[7:5]==3'h2}};
   reg [7:0] red1, green1, blue1;
   always @(posedge pixclk) red1 = ({CounterX[5:0] & {6{CounterY1[4:3]==~CounterX[4:3]}}, 2'b00} | W1) & ~A1;
   always @(posedge pixclk) green1 = (CounterX[7:0] & {8{CounterY1[6]}} | W1) & ~A1;
   always @(posedge pixclk) blue1 = CounterY[7:0] | W1 | A1;

   wire [2:0] RGB0, RGB1;

   // for 3bpp mode
   // assign RGB0 = {blue[7], green[7], red[7]};
   // assign RGB1 = {blue1[7], green1[7], red1[7]};

   wire [6:0] ADDRX;
   wire [4:0] ADDRY;
   wire BLANK, LATCH;
   ledscan 	
   ledscan_inst
   (
      .clk(pixclk),
      .r0(red),
      .g0(green),
      .b0(blue),
      .r1(red1),
      .g1(green1),
      .b1(blue1),
      .rgb0(RGB0),
      .rgb1(RGB1),
      .addrx(ADDRX),
      .addry(ADDRY),
      .latch(LATCH),
      .blank(BLANK)
   );
   
   reg [22:0] blinky;
   always @(posedge pixclk)
   begin
      blinky <= blinky + 1;
   end
   assign led[7] = blinky[22];

   // output pins mapping to ULX3S board    
   wire [27:0] ogp, ogn;
   assign ogp[14] = ADDRY[4];
   assign ogn[14] = ADDRY[3];
   assign ogp[15] = pixclk; // SCLK display clock
   assign ogn[15] = ADDRY[2];
   assign ogp[16] = LATCH;
   assign ogn[16] = ADDRY[1];
   assign ogp[17] = BLANK;
   assign ogn[17] = ADDRY[0];
   assign ogp[21] = 1'b0; // X1
   assign ogn[21] = 1'b0; // X0
   assign ogp[22] = RGB1[2]; // B1
   assign ogn[22] = RGB0[2]; // B0
   assign ogp[23] = RGB1[1]; // G1
   assign ogn[23] = RGB0[1]; // G0
   assign ogp[24] = RGB1[0]; // R1
   assign ogn[24] = RGB0[0]; // R0

   generate
      if(PMOD_J1 == 90)
      // if ULX3S has 90-deg female header (holes):
      // PMOD is connected directly to header (align 3.3V/GND)
      // directly connect P and N
      begin : J1_90deg
        // J1 connector
        assign gp[3:0] = ogp[17:14];
        assign gn[3:0] = ogn[17:14];
        assign gp[10:7] = ogp[24:21];
        assign gn[10:7] = ogn[24:21];
      end
   endgenerate

   generate
      if(PMOD_J1 == 0)
      // if ULX3S has straight male header (pins):
      // PMOD is connected with flat cable (align 3.3V/GND)
      // swap P and N
      begin : J1_flat_cable
        // J1 connector
        assign gp[3:0] = ogn[17:14];
        assign gn[3:0] = ogp[17:14];
        assign gp[10:7] = ogn[24:21];
        assign gn[10:7] = ogp[24:21];
      end
   endgenerate

   generate
      if(PMOD_J2 == 90)
      // if ULX3S has 90-deg female header (holes):
      // PMOD is connected directly to header (align 3.3V/GND)
      // directly connect P and N
      begin : J2_90deg
        // J2 connector
        assign gp[17:14] = ogp[17:14];
        assign gn[17:14] = ogn[17:14];
        assign gp[24:21] = ogp[24:21];
        assign gn[24:21] = ogn[24:21];
      end
   endgenerate

   generate
      if(PMOD_J2 == 0)
      // if ULX3S has straight male header (pins):
      // PMOD is connected with flat cable (align 3.3V/GND)
      // swap P and N
      begin : J2_flat_cable
        // J2 connector
        assign gp[17:14] = ogn[17:14];
        assign gn[17:14] = ogp[17:14];
        assign gp[24:21] = ogn[24:21];
        assign gn[24:21] = ogp[24:21];
      end
   endgenerate
   
endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 Ahmed Imamović: Initial creation
		   Adapted from: https://github.com/emard/ulx3s-misc/tree/master/examples/led64x64
*/

