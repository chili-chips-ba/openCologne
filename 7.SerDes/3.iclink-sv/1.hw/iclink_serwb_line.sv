// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// The FIFO pump's line side, and the root of half_clk_strobe.
//
// W = 2 (1.25, 2.5 Gb/s): the pump takes one PHY word a clock, so
// half_clk_strobe is 1 and the words pass straight through.
//
// W = 4 (5 Gb/s): the pump moves two PHY words a clock but cannot close
// timing at the PHY clock, so it runs on that clock, enabled every other
// clock by half_clk_strobe, a flop that toggles. Here the two words a
// strobe become one a clock and back, on the same clock: no second clock,
// no crossing.
//   TX: the pump's pair, launched on a strobe clock, goes out [0] in the
//       next clock and [1] in the one after, from a flop each clock.
//   RX: each clock's word is kept a clock; on a strobe clock the pair
//       {this word, the one before} goes to the pump, [0] first on the line.
//   err: the PHY's per-clock error flag, OR'ed over the pair the same way.
//
// Timing: the pump's cells get a 2-clock setup budget (multicycle path,
// 3.build). Everything they read must change only on strobe clocks: the
// RX pair and err here are such flops, loaded on the strobe, and they
// themselves read the every-clock PHY in one clock. half_clk_strobe itself
// changes every clock: its route must fit in one clock, which 3.build
// checks after routing.
//==========================================================================
module iclink_serwb_line
  import iclink_phy_pkg::*;
#(
    parameter  int W  = 2,     // the pump's SerWB words a clock: 2 or 4
    localparam int NP = W / 2  // PHY words a pump clock
) (
    input  logic clk,
    input  logic arst_n,
    output logic half_clk_strobe, // 1 (W = 2), or every other clock (W = 4)

    input  phy_word_t [NP-1:0] pump_tx,   // from the pump, [0] first on the line
    output phy_word_t          line_tx,   // to the PHY
    input  phy_word_t          line_rx,   // from the PHY
    input  logic               line_err,  // a bad symbol or a buffer error, this clock
    output phy_word_t [NP-1:0] pump_rx,   // to the pump, [0] first on the line
    output logic               pump_err   // line_err, over the words in pump_rx
);

  if (!(W inside {2, 4})) begin : g_bad_w
    $error("iclink_serwb_line: W %0d (2 or 4)", W);
  end : g_bad_w

  if (W == 2) begin : g_w2
    always_comb begin
      half_clk_strobe = 1'b1;
      line_tx         = pump_tx[0];
      pump_rx[0]      = line_rx;
      pump_err        = line_err;
    end
  end : g_w2
  else begin : g_w4
    phy_word_t rx_prev;  // the word of the clock before
    logic      err_prev;

    always_ff @(posedge clk or negedge arst_n) begin
      if (!arst_n) begin
        half_clk_strobe <= 1'b0;
        line_tx         <= PHY_COMMA_WORD;
        rx_prev         <= PHY_COMMA_WORD;
        err_prev        <= 1'b0;
        pump_rx         <= {NP{PHY_COMMA_WORD}};
        pump_err        <= 1'b0;
      end
      else begin
        half_clk_strobe <= !half_clk_strobe;
        // pump_tx is new from a strobe clock on: [0] while the strobe is
        // low, [1] while it is high again
        line_tx         <= half_clk_strobe ? pump_tx[1] : pump_tx[0];
        rx_prev         <= line_rx;
        err_prev        <= line_err;
        if (half_clk_strobe) begin
          pump_rx  <= {line_rx, rx_prev};
          pump_err <= line_err || err_prev;
        end
      end
    end
  end : g_w4

endmodule : iclink_serwb_line

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
