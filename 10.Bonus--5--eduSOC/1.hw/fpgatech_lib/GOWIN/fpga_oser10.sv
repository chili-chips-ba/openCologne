///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin OSERDES10. It provides 10-1 muxing within output pad
///////////////////////////////////////////////////////////////////////////////

module fpga_oser10 (
   input  logic       arst,    // active-high async reset
   input  logic       clk_par, // slower/parallel clock
   input  logic       clk_ser, // faster/serial clock
   input  logic [9:0] d,

   output logic       q
);

   OSER10 #(
     .GSREN ("false"),
     .LSREN ("true")
   )
   u_oser10 (
     .Q     (q),
    
     .D0    (d[0]),
     .D1    (d[1]),
     .D2    (d[2]),
     .D3    (d[3]),
     .D4    (d[4]),
     .D5    (d[5]),
     .D6    (d[6]),
     .D7    (d[7]),
     .D8    (d[8]),
     .D9    (d[9]),
    
     .PCLK  (clk_par),
     .FCLK  (clk_ser),
     .RESET (arst)
  );

endmodule: fpga_oser10

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
*/
