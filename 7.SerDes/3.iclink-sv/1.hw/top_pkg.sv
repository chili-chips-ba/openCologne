// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: Constants of the 7.SerDes board top (top.sv).
//==========================================================================

package top_pkg;

  // Heartbeat counter width: the LED shows its top bit. At the 10 MHz EVB
  // clock (CLK0) it toggles every 2^23 / 10 MHz = 0.84 s.
  localparam int HEARTBEAT_W = 24;

endpackage : top_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
