//==========================================================================
// SPDX-FileCopyrightText: 2023 Chili.CHIPS
//--------------------------------------------------------------------------
// SPDX-License-Identifier: BSD-3-Clause
//--------------------------------------------------------------------------
// Description: LUTRAM arrays for capacity stress testing different FPGAs
//==========================================================================

/* verilator lint_off PINMISSING */
module top 
#(
   parameter LUTRAM16X10 = 30
)
(
   input   logic clk,

   input logic [$clog2(LUTRAM16X10 * 16)-1 : 0] addr,
   input logic we,
   input logic [9:0] wdat,
   output logic [9:0] rdat
);
localparam ADDR_BITS = $clog2(LUTRAM16X10 * 16)-1;

logic [9:0] read_all [LUTRAM16X10];


logic [LUTRAM16X10-1:0] we_dec;

always_comb begin : _decode
   we_dec = '0;  // Initialize to 0
   if(LUTRAM16X10 > 1) begin
      we_dec [addr[ADDR_BITS:4]] = 1'b1 & we;
      rdat = read_all [addr[ADDR_BITS:4]];   
   end
   else begin // corner cases
      we_dec = we;
      rdat = read_all[0];
   end
   
end
genvar i;
generate
   for(i = 0; i < LUTRAM16X10; i++) begin
      lutram_16x10 u_lut(
         .clk(clk),
         .addr(addr[3:0]),
         .rdat(read_all[i]), //maybe ill need a better description of a read mux
         .wdat(wdat),
         .we(we_dec[i])
      );
   end 
endgenerate

endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/8/20 Tarik Ibrahimovic: Initial Creation
*/
