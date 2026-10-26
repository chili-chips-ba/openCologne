// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Gearbox for the W = 4 FIFO pump (5 Gb/s): a 2:1 / 1:2 width converter
// on the PHY clock. The pump's core moves 2 PHY words on clocks with ce,
// which is high every other clock; the PHY moves 1 word every clock.
//
//   TX (IN_N, OUT_N) = (2, 1): takes 2 words on ce, gives [0] in the
//      clock after, [1] in the next.
//   RX (IN_N, OUT_N) = (1, 2): collects 2 words, the one before ce and the
//      one with it, and gives them as a pair on ce.
//
// One clock, a fixed phase: no FIFO, no bubbles, a fixed latency (one
// clock out TX, two in RX). The pair boundary on RX is wherever ce falls:
// the far side's K filter and depacketizer take words in any slot.
//
// Timing: the TX input (the pump's phy_tx) and the RX output (r_word)
// change only on ce: r_word is in the pump's MCP set. Every other flop
// here loads every clock and is timed in one.
//==========================================================================
module iclink_gearbox
  import iclink_phy_pkg::*;
#(
    parameter int IN_N  = 2,
    parameter int OUT_N = 1
) (
    input  logic                  clk,
    input  logic                  arst_n,
    input  logic                  ce,      // the pump's strobe: every other clock
    input  phy_word_t [ IN_N-1:0] w_word,  // [0] w_prev on the line
    output phy_word_t [OUT_N-1:0] r_word   // [0] w_prev on the line
);

  if (!((IN_N == 2 && OUT_N == 1) || (IN_N == 1 && OUT_N == 2))) begin : g_bad_n
    $error("iclink_gearbox: (IN_N, OUT_N) must be (2, 1) or (1, 2)");
  end : g_bad_n

  if (IN_N == 2) begin : g_tx
    // w_word loads on ce: [0] goes out next, [1] the clock after
    always_ff @(posedge clk or negedge arst_n) begin
      if (!arst_n) begin
        r_word <= '0;
      end
      else begin
        r_word[0] <= ce ? w_word[1] : w_word[0];
      end
    end
  end : g_tx
  else begin : g_rx
    phy_word_t w_prev;  // the word before ce

    always_ff @(posedge clk or negedge arst_n) begin
      if (!arst_n) begin
        w_prev <= '0;
        r_word <= '0;
      end
      else begin
        w_prev <= w_word[0];
        if (ce) begin
          r_word <= {w_word[0], w_prev};
        end
      end
    end
  end : g_rx

endmodule : iclink_gearbox

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
