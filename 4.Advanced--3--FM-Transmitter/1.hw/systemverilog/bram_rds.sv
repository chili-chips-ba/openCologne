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
// Description: bram_rds Module
//------------------------------------------------------------------------
// Module: bram_rds
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

import message::*;

module bram_rds#(
   parameter int MEM_BYTES = 260, // bytes
   parameter int ADDR_BITS = 9 // adress bits of BRAM
)(
   input  logic                 clk,
   input  logic [ADDR_BITS-1:0] imem_addr,
   input  logic                 dmem_write,
   input  logic [ADDR_BITS-1:0] dmem_addr,
   input  logic [7:0]           dmem_data_in,
   output logic [7:0] imem_data_out,
   output logic [7:0] dmem_data_out 
);


   typedef logic [7:0] bram_type [0:MEM_BYTES-1];

   logic [7:0] ibram_0;
   logic [7:0] dbram_0;

   // Function to convert initial RDS message type to bram_type
   function bram_type init_bram(input rds_msg_type x, input int lmax);
      int i, n;
      bram_type y;
      begin
         n = 52; // Fixed size of the rds_msg_type array
         if (n > lmax) n = lmax;
         for(i = 0; i < n; i++) begin
            y[i] = x[i];
         end
		 for(i = n; i < lmax; i++) begin
            y[i] = 8'h00; // Initialize remaining elements to 0
         end
         return y;
      end
   endfunction

   // TODO: Check when to initialize, maybe with reset?
   (*ram_style = "block" *)bram_type bram_0 = init_bram(rds_msg_map, MEM_BYTES);


   always_comb begin
      dmem_data_out = dbram_0;
      imem_data_out = ibram_0;
   end

   always_ff @(posedge clk) begin
      if (dmem_write == 1'b1) begin
         // bram_0(conv_integer(dmem_addr)) <= dmem_data_in(7 downto 0);
      end
         // dbram_0 <= bram_0(conv_integer(dmem_adrr));
         ibram_0 <= bram_0[imem_addr];
   end
endmodule
/*
Version History:
-----------------------------------------------------------------------------
2024/5/30 TH: Initial creation
-----------------------------------------------------------------------------
*/
