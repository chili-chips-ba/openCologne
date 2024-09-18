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

`timescale 1ns/1ps

module top64x64_tb;

   // Inputs
   reg clk;
   reg btn;

   // Outputs
   wire led;
   wire [27:0] gp, gn;


   initial begin
   `ifdef CCSDF
      $sdf_annotate("top64x64_00.sdf", dut);
   `endif
      $dumpfile("../2.sim/top64x64_tb.vcd");
      $dumpvars(0, top64x64_tb);
      clk = 0;
      btn = 1;
   end
   // Instantiate the top64x64 module
   top64x64 dut (
      .clk(clk),
      .btn(btn),
      .led(led),
      .gp(gp),
      .gn(gn)
   );


   initial begin
      clk = 0;
      forever #20 clk = ~clk;  // 25 MHz
   end

   // Test sequence
   initial begin
      // Initial state
      btn = 0;
      #50;


      btn = 1;
      #100;



      #50000;


      $finish;
   end


   initial begin
      $monitor("Time = %0t | LED = %b | GP = %b | GN = %b", $time, led, gp, gn);
   end

endmodule
