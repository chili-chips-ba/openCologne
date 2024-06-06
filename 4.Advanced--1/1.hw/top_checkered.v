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




module top_checkered (
   input  wire clk,
   input  wire btn,
   output wire oled_csn,
   output wire oled_clk,
   output wire oled_mosi,
   output wire oled_dc,
   output wire oled_resn,
   output wire led
);
   wire [7:0] x ;
   wire [7:0] y ;
   //                  checkered      red   green   blue     red    green  blue
   wire [15:0] color = x[4] ^ y[4] ? {5'd0, x[7:3], 6'd0} : {y[7:3], 6'd0, 5'd0};

   wire clk270, clk180, clk90, clk_25mhz, usr_ref_out;
   wire usr_pll_lock_stdy, usr_pll_lock;
   
   reg [26:0] counter;
   
   CC_PLL #(
   	  .REF_CLK("10.0"),    // reference input in MHz
   	  .OUT_CLK("25.0"),   // pll output frequency in MHz
   	  .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
   	  .LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
   	  .CI_FILTER_CONST(2), // optional CI filter constant
   	  .CP_FILTER_CONST(4)  // optional CP filter constant
   ) pll_inst (
   	  .CLK_REF(clk), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
   	  .USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy), .USR_PLL_LOCKED(usr_pll_lock),
   	  .CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(clk_25mhz), .CLK_REF_OUT(usr_ref_out)
   );



   lcd_video #(
      .c_clk_spi_mhz(25),
      .c_init_file("st7789_linit.mem"),
      .c_init_size(35),
      .c_color_bits(16)
   ) lcd_video_inst (
	//clk_pixel(clk_25mhz),
	//.clk_pixel_ena(1'b0),
      .clk_spi(clk_25mhz),
      .reset(~btn),
      .x(x),
      .y(y),
      .color(color),
      .spi_clk(oled_clk),
      .spi_mosi(oled_mosi),
      .spi_dc(oled_dc),
      .spi_resn(oled_resn)//,
	 //.spi_csn (oled_csn)
   );

   assign led = counter[26];
   
   always @(posedge clk_25mhz)
   begin
   	  if (!btn) begin
   	     counter <= 0;
   	  end else begin
   	     counter <= counter + 1'b1;
   	  end
   end
   assign oled_csn = 0; // oled_csn is connected to BLK (backlight enable pin)

endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 Ahmed Imamović: Initial creation
           Adapted from: https://github.com/emard/ulx3s-misc/tree/master/examples/spi_display
*/

