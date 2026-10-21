///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2022 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// Technology-specific GoWin LVDS input buffer
//
//  When a GPIO buffer is configured as a differential receiver, 
//  the input Hysteresis and Bus Keeper are automatically disabled.
//
//  GW1N and GW2A devices that support on-chip programmable 100Ohm 
//  input differential matching resistor are:
//   - Bank 0 of GW1N-4, GW1NR-4, GW1NRF-4B, GW1N-9, GW1NR-9, GW1N-1, GW1NR-1.
//   - Bank 0 and 1 of GW1N-1S, GW1NS-4, GW1NS-4C, GW1NSR-4, GW1NSR-4C, 
//         GW1NSER-4C, GW2A-18, GW2A-55, GW2AN-55, GW2ANR-18, GW2AR-18.
//   - Bank 2 of GW1N-2, GW1NR-2, GW1N-1P5.
//   - Bank 4 and bank 5 of GW2AN-18X, GW2AN-9X.
//
// All single-ended GPIO buffer pairs can be configured to support
// EMULATED differential output standards, such as LVDS25E, MLVDS25E, 
// BLVDS25E, LVPECL33E, RSDS25E. An off-chip impedance matching resistor 
// network is required in such case.
//
// TRUE differential inputs can have internal (on-chip) 100ohm termination
// matching resistors for differential signals. Here is how to enable/disable
// it in the constraints:
//  
//   IO_PORT "xxx" Diff_RESISTOR=ON; # Allowed values are OFF and ON
//
///////////////////////////////////////////////////////////////////////////////

module fpga_ilvds (
   input  logic i,
   input  logic ib,
   output logic o
);

 //ELVDS_IBUF u_ilvds ( // Emulated
   TLVDS_IBUF u_ilvds ( // True
      .I   (i),
      .IB  (ib),

      .O   (o)
    );
    
endmodule: fpga_ilvds

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2022/10/10 JI: initial creation    
*/
