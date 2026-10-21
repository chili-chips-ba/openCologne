// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: types and constants of the GateMate SerDes PHY
// (iclink_serdes_gm.sv).
//==========================================================================

package iclink_phy_pkg;
  import iclink_pkg::*;

  // CC_SERDES 64-bit datapath (TX/RX_DATAPATH_SEL = 3): 8 symbols per clock
  localparam int PHY_NWORDS = 8;
  localparam int PHY_DW     = 8 * PHY_NWORDS;

  // one clock of the data stream, as LiteICLink's PHY sink/source: data + ctrl (K)
  typedef struct packed {
    byte_t [PHY_NWORDS-1:0] d;
    logic [PHY_NWORDS-1:0]  k;
  } phy_word_t;

  // PHY controls; any clock, synchronized in the PHY
  typedef struct packed {
    prbs_cfg_t tx_prbs;        // PRBS instead of the data stream
    prbs_cfg_t rx_prbs;        // PRBS to check; PRBS_OFF clears the count
    logic      rx_prbs_pause;  // hold the error count
    logic      rx_align;       // comma alignment on; acquires at the first comma
  } phy_ctrl_t;

  // SerDes bring-up: regfile writes, the ones Cologne Chip's PRBS loopback
  // test of the EVB uses (openCologne-PCIE 2.rtl/1.phy/1.serdes-test.STANDALONE)
  localparam int CFG_WRITES = 3;
  localparam int CFG_IDX_W = $clog2(CFG_WRITES);
  localparam int CFG_WAIT_W = 6;  // 2^CFG_WAIT_W clk_reg clocks before and after each write

  typedef struct packed {
    logic [7:0]  addr;
    logic [15:0] data;
  } cfg_write_t;

  localparam logic [7:0] SERDES_CFG_ADDR = 8'h5C;  // SerDes enable

  localparam cfg_write_t [CFG_WRITES-1:0] CFG_SEQ = '{
      '{8'h50, 16'h0C03},  // 2: PLL on
      '{SERDES_CFG_ADDR, 16'h0001},  // 1: SerDes enable
      '{8'h51, 16'h16FA}  // 0: PLL: 2.5 Gb/s from a 100 MHz reference
  };

endpackage : iclink_phy_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
