///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin ODDR
///////////////////////////////////////////////////////////////////////////////

module fpga_oddr (
   input  logic       clk,
   input  logic [1:0] d,
   output logic       q
);

   ODDR #(
     .INIT      (1'b0),
     .TXCLK_POL (1'b0)  // clock polarity to drive Q1 with
   )
   u_oddr (
     .Q0        (q),
     .Q1        ( ),    // used for IOBUF OE_N 
     .D0        (d[0]), // goes out on rising  edge Q0
     .D1        (d[1]), // goes out on falling edge Q0
     .TX        (1'b0),
     .CLK       (clk)
   );
    
endmodule: fpga_oddr

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
*/
