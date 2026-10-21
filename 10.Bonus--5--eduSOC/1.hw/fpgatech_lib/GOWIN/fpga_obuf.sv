///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin output buffer
///////////////////////////////////////////////////////////////////////////////

module fpga_obuf (
   input  logic  i, // core input,  to be sent to OUT 
   output logic  o  // core output, as received from INP 
);
   
   OBUF u_obuf (.O(o), .I(i));

endmodule: fpga_obuf

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/02/14 TI: initial creation    
*/
