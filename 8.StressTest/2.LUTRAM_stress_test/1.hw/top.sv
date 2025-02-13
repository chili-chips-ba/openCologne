//==========================================================================
// Copyright (C) 2023 Chili.CHIPS*ba
//--------------------------------------------------------------------------
//                      PROPRIETARY INFORMATION
//
// The information contained in this file is the property of CHILI CHIPS LLC.
// Except as specifically authorized in writing by CHILI CHIPS LLC, the holder
// of this file: (1) shall keep all information contained herein confidential;
// and (2) shall protect the same in whole or in part from disclosure and
// dissemination to all third parties; and (3) shall use the same for operation
// and maintenance purposes only.
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
