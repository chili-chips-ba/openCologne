///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin LVDS output buffer
///////////////////////////////////////////////////////////////////////////////

module fpga_olvds (
   input  logic i,
   output logic o,
   output logic ob
);

  //ELVDS_OBUF u_olvds ( // Emulated
    TLVDS_OBUF u_olvds ( // True
      .O   (o),
      .OB  (ob),

      .I   (i)
    );
    
endmodule: fpga_olvds

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/10 JI: initial creation    
*/
