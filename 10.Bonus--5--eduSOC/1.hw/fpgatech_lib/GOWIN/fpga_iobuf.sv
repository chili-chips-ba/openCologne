///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin tri-stateable IOBUF
///////////////////////////////////////////////////////////////////////////////

module fpga_iobuf (
   input  logic  i,   // core input,  to be sent to OUT pad
   output logic  o,   // core output, as received from INP pad
   input  logic  hiz, // core 1 to tri-state OUT, turning it into INP pad
    
   inout  wire   pad  // IO pad for off-chip signals
);

   IOBUF u_iobuf (
     .I   (i),
     .O   (o),
     .OEN (hiz),
     .IO  (pad)
   );
    
endmodule: fpga_iobuf

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2023/10/9 JI: initial creation    
*/
