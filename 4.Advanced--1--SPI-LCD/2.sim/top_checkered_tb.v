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

`timescale 1 ns / 1 ps

module top_checkered_tb;

   reg clk;
   reg btn;
   wire oled_csn;
   wire oled_clk;
   wire oled_mosi;
   wire oled_dc;
   wire oled_resn;
   wire led;

   initial begin
   `ifdef CCSDF
      $sdf_annotate("top_checkered_00.sdf", dut);
   `endif
      $dumpfile("../2.sim/top_checkered_tb.vcd");
      $dumpvars(0, top_checkered_tb);
      clk = 0;
      btn = 1;
   end

   always clk = #50 ~clk;

   top_checkered dut (
      .clk(clk),
      .btn(btn),
      .oled_csn(oled_csn),
      .oled_clk(oled_clk),
      .oled_mosi(oled_mosi),
      .oled_dc(oled_dc),
      .oled_resn(oled_resn),
      .led(led)
   );

   initial begin
      clk = 0;
      btn = 0;
      #200;
      btn = 1;
      #500;
      $display("c_oled_init contents:");
      for (int i = 0; i < dut.lcd_video_inst.c_init_size; i = i + 1) begin
         $display("c_oled_init[%0d] = %h", i, dut.lcd_video_inst.c_oled_init[i]);
      end
      #10_000_000;
      $finish;
   end

endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 Ahmed Imamović: Initial creation
           Adapted from: https://github.com/emard/ulx3s-misc/tree/master/examples/spi_display
*/
