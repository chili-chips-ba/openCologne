///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin IDDR
///////////////////////////////////////////////////////////////////////////////

module fpga_iddr (
  input  logic       clk,
  input  logic       d,
  output logic [1:0] q
);

  IDDR #(
    .Q0_INIT (1'b0),
    .Q1_INIT (1'b0)
  )
  u_iddr (
    .Q0      (q[0]), // D captured with posedge
    .Q1      (q[1]), // D captured with negedge
    .D       (d),
    .CLK     (clk)
  );
    
endmodule: fpga_iddr

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/9 JI: initial creation    
*/
