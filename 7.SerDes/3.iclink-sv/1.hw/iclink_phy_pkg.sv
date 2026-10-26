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
  // test of the EVB uses (openCologne-PCIE 2.rtl/1.phy/1.serdes-test.STANDALONE),
  // then the RX elastic buffer (RX_BUF_CFG and the clock-correction sequence)
  localparam int CFG_WRITES = 8;
  localparam int CFG_IDX_W  = (CFG_WRITES > 1) ? $clog2(CFG_WRITES) : 1;
  // 2^CFG_WAIT_W clk_reg clocks before the first write and after each
  localparam int CFG_WAIT_W = 6;

  typedef struct packed {
    logic [7:0]  addr;
    logic [15:0] data;
  } cfg_write_t;

  localparam logic [7:0] SERDES_CFG_ADDR = 8'h5C;  // SerDes enable
  localparam logic [7:0] PHY_COMMA = 8'hBC;  // K28.5: the lane aligner seeks it in lanes 0, 4
  localparam logic [7:0] PHY_IDLE = 8'h1C;  // K28.0: a K, but no comma

  // the idle word: K28.5 in lane 0 for comma alignment, K28.0 in lane 4 so
  // that no half of it reads as data (a SerWB K filter drops it)
  localparam phy_word_t PHY_COMMA_WORD = '{
      d: {8'h00, 8'h00, 8'h00, PHY_IDLE, 8'h00, 8'h00, 8'h00, PHY_COMMA},
      k: 8'b0001_0001
  };

  // the clock-correction word: CC_SERDES's RX elastic buffer matches its
  // 4-symbol sequence, here K28.0 four times, in each half, and repeats or
  // drops a word to take up the ppm between two reference clocks. No comma
  // in it: a K28.5 in both halves would let the lane aligner pick either
  // half. Sent in bursts (PHY_CLKCOR_BURST words in a row, every
  // PHY_CLKCOR_EVERY clocks): of two in a row the buffer may drop one, and
  // an insertion repeats the word before. All K, so a SerWB K filter drops it.
  localparam logic [9:0] PHY_CLKCOR_SEQ = {1'b0, 1'b1, PHY_IDLE};  // {comma, K, data}
  localparam phy_word_t PHY_CLKCOR_WORD = '{d: {PHY_NWORDS{PHY_IDLE}}, k: '1};
  localparam int PHY_CLKCOR_BURST = 4;
  localparam int PHY_CLKCOR_EVERY = 1024;

  // RX elastic buffer fill, in 64-bit words: a correction word is repeated
  // below MIN_LAT - 1, dropped above MAX_LAT; RX_BUF_ERR_O below 3 or above
  // 60 (DS1001 Table 2.57). Reads start MIN_LAT words behind, so the RX
  // latency is MIN_LAT to MAX_LAT clocks. MIN_LAT 8: 4 words above the error
  // limit, for the count crossing, the recovered clock's wander and a burst
  // of inserts. MAX_LAT 12: a window wider than one burst moves the fill
  // (3 words), so an insert never leads to a drop or back.
  localparam logic [5:0] PHY_RX_MIN_LAT = 6'd8;
  localparam logic [5:0] PHY_RX_MAX_LAT = 6'd12;
  // RX_BUF_CFG (0x25) = {2'b00, MAX_LAT, MIN_LAT, CLKCOR_USE, BUF_BYPASS}
  localparam logic [15:0] PHY_RX_BUF_CFG = {2'b00, PHY_RX_MAX_LAT, PHY_RX_MIN_LAT, 1'b1, 1'b0};

  typedef cfg_write_t [CFG_WRITES-1:0] cfg_seq_t;

  // PLL_CFG1 (0x51) for a line rate in Mb/s, from a 100 MHz reference:
  // FCNTRL 58, MAIN_DIVSEL 27 (N1 1, N2 5, N3 5); OUT_DIVSEL [13:12] picks
  // M3 = 1, 2 or 4, so 5, 2.5 or 1.25 Gb/s, with the core clock at 62.5,
  // 31.25 or 15.625 MHz
  function automatic logic [15:0] pll_cfg1(input int line_rate);
    case (line_rate)
      1250: begin
        return 16'h36FA;
      end
      5000: begin
        return 16'h06FA;
      end
      default: begin
        return 16'h16FA;  // 2500
      end
    endcase
  endfunction

  function automatic cfg_seq_t cfg_seq(input int line_rate);
    return
    '{
        '{8'h29, {6'h0, PHY_CLKCOR_SEQ}},  // 7: RX_CLKCOR_SEQ_1_3
        '{8'h28, {6'h0, PHY_CLKCOR_SEQ}},  // 6: RX_CLKCOR_SEQ_1_2
        '{8'h27, {6'h0, PHY_CLKCOR_SEQ}},  // 5: RX_CLKCOR_SEQ_1_1
        '{8'h26, {6'h0, PHY_CLKCOR_SEQ}},  // 4: RX_CLKCOR_SEQ_1_0
        '{8'h25, PHY_RX_BUF_CFG},  // 3: RX buffer on, clock correction
        '{8'h50, 16'h0C03},  // 2: PLL on
        '{SERDES_CFG_ADDR, 16'h0001},  // 1: SerDes enable
        '{8'h51, pll_cfg1(line_rate)}  // 0: PLL: the line rate
    }
    ;
  endfunction

endpackage : iclink_phy_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
