// SPDX-FileCopyrightText: 2016-2017 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2019-2020 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// IC Link common types. The 8b/10b tables live in the simulation
// (2.sim/iclink_8b10b_pkg.sv): on the chip CC_SERDES encodes and decodes.
//==========================================================================

package iclink_pkg;

  typedef logic [7:0] byte_t;  // a character before 8b/10b

  // PRBS pattern (LiteX prbs.py PRBS_CONFIG_*); 0 = off
  typedef enum logic [1:0] {
    PRBS_OFF = 2'b00,
    PRBS_7   = 2'b01,
    PRBS_15  = 2'b10,
    PRBS_31  = 2'b11
  } prbs_cfg_t;

endpackage : iclink_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
