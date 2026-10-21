///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin ISERDES8. It provides 8-1 demuxing within input pad
///////////////////////////////////////////////////////////////////////////////

module fpga_iser8 (
   input  logic       arst,    // active-high async reset
   input  logic       clk_par, // slower/parallel clock
   input  logic       clk_ser, // faster/serial clock
   input  logic       d,

   output logic [7:0] q
);

//   ISER8 #(
//     .GSREN ("false"), // Disable Global Reset
//     .LSREN ("true")   // Enable Local Reset
//   )
//   u_iser8 (
//     .D     (d),
//    
//     .Q0    (q[0]),
//     .Q1    (q[1]),
//     .Q2    (q[2]),
//     .Q3    (q[3]),
//     .Q4    (q[4]),
//     .Q5    (q[5]),
//     .Q6    (q[6]),
//     .Q7    (q[7]),
//    
//     .PCLK  (clk_par),
//     .FCLK  (clk_ser),
//     .CALIB (1'b0),
//     .RESET (arst)
//  );

endmodule: fpga_iser8

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
*/
