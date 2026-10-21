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
  localparam int         HEARTBEAT_W      = 24;

  // 8b/10b self-test: two characters per clock, word 0 a counter with a
  // K28.5 comma every 2^COMMA_LOG2 clocks, word 1 its inverse
  localparam int         ST_WORDS         = 2;
  localparam int         COMMA_LOG2       = 4;
  localparam logic [7:0] K28_5            = 8'hBC;
  // encoder (2 clocks) + decoder (1 clock)
  localparam int         ST_LATENCY       = 3;

  // PRBS self-test: PRBS7, 20 bits per clock (the SerDes datapath width);
  // the checker locks within 2^PRBS_WARMUP_LOG2 clocks of reset
  localparam int         PRBS_W           = 20;
  localparam int         PRBS_WARMUP_LOG2 = 4;

endpackage : top_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
