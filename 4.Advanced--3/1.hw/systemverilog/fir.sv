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
// Description: <your text goes here>
//========================================================================

/*
-----------------------------------------------------------------------------
Module: FIR
Description:
Parameters:
Inputs:
Outputs:

-----------------------------------------------------------------------------
*/

module FIR#(
   parameter integer BITS_X = 12, // external IN/OUT port bits
   parameter integer FIR_STAGES = 16  // number of history stages for the FIR sum
)(
   input  logic clock,
   input  logic enable = 1'b1,
   input  logic reset = 1'b0,
   input  logic [BITS_X-1:0] data_in,
   output logic [BITS_X-1:9] data_out 
);

   // function integer ceiling log2
   // returns how many bits are needed to represent a number of states
   // example ceil_log2(255) = 8,  ceil_log2(256) = 8, ceil_log2(257) = 9

   function automatic int ceil_log2(input int x);
      int result;
      real log_value;
      begin
         if(x <= 0)begin
            result = 0;
         end else begin
            log_value = $ln(x + 1.0E-6) / $ln(2.0) - 1.0E-6;
            result = $ceil(log_value);
         end
         return result;
      end   
   endfunction

   localparam int BITS_I = BITS_X + ceil_log2(FIR_STAGES); // internal sum bits: log2(16) = 4
   typedef logic signed [BITS_I-1:0] d_t [FIR_STAGES-1:0];
   d_t d;
   logic signed[BITS_I-BITS_X-1:0] sign_expand;
   logic signed[BITS_I-1:0] sum;

   always_ff@(posedge clock or posedge reset) begin
      if(reset == 1'b1) begin
         d <= '{default: '0};
         sum <= '0;
         data_out <= '0;
      end else if(enable == 1'b1) begin
      /*
         shifting
         for i in 1 to d'length-1 loop
            d(i) <= d(i-1);
         end loop;
         sign_expand <= (others => data_in(C_bits_x-1));
         d(0) <= sign_expand & data_in; -- fill up MSB bits
         sum <= sum + d(0) - d(C_fir_stages-1); -- add first entry, subtract last*/   
         sum <= sum + (data_in - sum[BITS_I-1:BITS_I-BITS_X]);
         data_out <= sum[BITS_I-1:BITS_I-BITS_X];
         // data_out <= sum   
      end
   end 
endmodule