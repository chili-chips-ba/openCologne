// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Gearbox between the 64-bit PHY clock and a clock of half its rate: IN_N
// PHY words in per write clock, OUT_N out per read clock, (IN_N, OUT_N) =
// (2, 1) on TX, (1, 2) on RX. It lets the W = 4 FIFO pump run at half the
// PHY clock, for 5 Gb/s (iclink_serwb_pump).
//
// The two clocks come from one source (the slow one divided from the fast
// one), so the word rates match exactly and nothing pushes back: the write
// side writes every clock, the read side reads every clock once START words
// wait. Underneath it is an async FIFO of DEPTH PHY words, the write
// pointer crossing in Gray code (one step a write clock). The reader sees
// that pointer 3 or 4 of its clocks late, so it trails the writer by START
// plus those words, well inside DEPTH. Until START words wait, and again
// should the fill ever leave its range (run dry, or overrun: the clocks
// drifted), the read side sends comma words, K28.5 in lane 0 and K28.0 in
// lane 4, which the far side's K filter drops, and starts again START
// words behind the writer.
//
// Reset: either side's reset resets both, each released on its own clock,
// so the pointers always start together.
//
// CDC: the Gray pointer must reach the reader with less skew between its
// bits than one write clock; keep its synchronizer flops (gray_s1) close.
//
// Timing: the read decision comes from flops. The synchronized pointer is
// decoded into a flop, and "a read is safe" is registered a clock ahead,
// with a margin of one read (2 * OUT_N words), since the writer only adds.
//
// Storage: two RAMs, even and odd PHY words, so the wide side reads or
// writes one row of both and the narrow side one RAM. Each has one write
// port and one registered read port, on their own clocks: block RAM.
//==========================================================================
module iclink_gearbox
  import iclink_phy_pkg::*;
#(
    parameter  int IN_N  = 2,
    parameter  int OUT_N = 1,
    parameter  int DEPTH = 32,                    // PHY words, a power of 2
    localparam int START = 2 * OUT_N + 2,         // words waiting before the first read
    localparam int MAXF  = DEPTH - 2 * IN_N,      // the most words that may wait
    localparam int AW    = $clog2(DEPTH),
    localparam int UW    = AW - $clog2(IN_N) + 1  // write pointer, in IN_N-word units
) (
    input logic                 w_clk,
    input logic                 w_arst_n,
    input phy_word_t [IN_N-1:0] w_word,    // [0] first on the line

    input  logic                  r_clk,
    input  logic                  r_arst_n,
    output phy_word_t [OUT_N-1:0] r_word     // [0] first on the line
);

  typedef logic [AW-2:0] row_t;

  if (!((IN_N == 2 && OUT_N == 1) || (IN_N == 1 && OUT_N == 2))) begin : g_bad_n
    $error("iclink_gearbox: (IN_N, OUT_N) must be (2, 1) or (1, 2)");
  end : g_bad_n
  if (DEPTH < 16 || (DEPTH & (DEPTH - 1)) != 0) begin : g_bad_depth
    $error("iclink_gearbox: DEPTH %0d: a power of 2, 16 or more", DEPTH);
  end : g_bad_depth

  //-----------------------------------------------------------------------
  // reset: both sides together
  //-----------------------------------------------------------------------
  logic both_n;  // low while either side is in reset
  logic w_meta, r_meta;  // first stages, read only by the next
  logic w_rst_n, r_rst_n;  // each side's reset, released on its clock

  assign both_n = w_arst_n & r_arst_n;

  always_ff @(posedge w_clk or negedge both_n) begin
    if (!both_n) begin
      w_meta  <= 1'b0;
      w_rst_n <= 1'b0;
    end
    else begin
      w_meta  <= 1'b1;
      w_rst_n <= w_meta;
    end
  end

  always_ff @(posedge r_clk or negedge both_n) begin
    if (!both_n) begin
      r_meta  <= 1'b0;
      r_rst_n <= 1'b0;
    end
    else begin
      r_meta  <= 1'b1;
      r_rst_n <= r_meta;
    end
  end

  //-----------------------------------------------------------------------
  // write side
  //-----------------------------------------------------------------------
  logic [UW-1:0] wr_u, wr_gray;  // units written, binary and Gray
  logic      [AW:0] wr_e;  // words written
  logic      [ 1:0] w_we;
  row_t      [ 1:0] w_row;
  phy_word_t [ 1:0] w_d;

  // word i goes to address wr_e + i: RAM (wr_e + i) mod 2, row (wr_e + i) / 2
  always_comb begin
    wr_e  = (AW + 1)'(wr_u * IN_N);
    w_we  = '0;
    w_row = '0;
    w_d   = '0;
    for (int i = 0; i < IN_N; i++) begin
      w_we[wr_e[0]^i[0]]  = 1'b1;
      w_row[wr_e[0]^i[0]] = row_t'((wr_e + (AW + 1)'(i)) >> 1);
      w_d[wr_e[0]^i[0]]   = w_word[i];
    end
  end

  always_ff @(posedge w_clk or negedge w_rst_n) begin
    if (!w_rst_n) begin
      wr_u    <= '0;
      wr_gray <= '0;
    end
    else begin
      wr_u    <= wr_u + 1'b1;
      wr_gray <= (wr_u + 1'b1) ^ ((wr_u + 1'b1) >> 1);
    end
  end

  //-----------------------------------------------------------------------
  // read side
  //-----------------------------------------------------------------------
  logic [UW-1:0] gray_s1, gray_s2, wr_u_r;  // the write pointer, synchronized
  logic [AW:0] wr_r, rd, fill;  // in PHY words; wr_r a flop
  logic primed;  // START words were written since reset
  logic run, ok, over, go, go_d, sel_d;  // ok: fill was 2 * OUT_N or more a clock ago;
                                         // over: fill was above MAXF
  phy_word_t [1:0] q;  // RAM outputs, even and odd

  always_comb begin
    wr_u_r = '0;
    for (int b = UW - 1; b >= 0; b--) begin  // Gray to binary
      wr_u_r[b] = (b == UW - 1) ? gray_s2[b] : (wr_u_r[b+1] ^ gray_s2[b]);
    end
    fill = wr_r - rd;
    go   = run && ok && !over;
  end

  always_ff @(posedge r_clk or negedge r_rst_n) begin
    if (!r_rst_n) begin
      gray_s1 <= '0;
      gray_s2 <= '0;
      wr_r    <= '0;
      rd      <= '0;
      primed  <= 1'b0;
      run     <= 1'b0;
      ok      <= 1'b0;
      over    <= 1'b0;
      go_d    <= 1'b0;
      sel_d   <= 1'b0;
      r_word  <= '0;
    end
    else begin
      gray_s1 <= wr_gray;
      gray_s2 <= gray_s1;
      wr_r    <= (AW + 1)'(wr_u_r * IN_N);
      ok      <= fill >= (AW + 1)'(2 * OUT_N);
      over    <= fill > (AW + 1)'(MAXF);  // also a fill below 0: it wraps
      primed  <= primed || (wr_r >= (AW + 1)'(START));
      go_d    <= go;
      sel_d   <= rd[0];
      if (go) begin
        rd <= rd + (AW + 1)'(OUT_N);
      end
      else begin
        run <= primed && (fill >= (AW + 1)'(START)) && !over;  // no read of a row never written
        if (!run) begin  // start START words behind; a word pair starts even
          rd <= (wr_r - (AW + 1)'(START)) & ~(AW + 1)'(OUT_N - 1);
        end
      end
      // a clock after the RAM read
      for (int i = 0; i < OUT_N; i++) begin
        if (!go_d) begin
          r_word[i] <= PHY_COMMA_WORD;  // no half of it is data for the far side's K filter
        end
        else if (OUT_N == 2) begin
          r_word[i] <= q[i];
        end
        else begin
          r_word[i] <= q[sel_d];
        end
      end
    end
  end

  //-----------------------------------------------------------------------
  // the RAMs: write on w_clk, registered read on r_clk
  //-----------------------------------------------------------------------
  for (genvar b = 0; b < 2; b++) begin : g_ram
    (* ram_style = "block" *) phy_word_t mem[DEPTH/2];

    always_ff @(posedge w_clk) begin
      if (w_we[b]) begin
        mem[w_row[b]] <= w_d[b];
      end
    end

    always_ff @(posedge r_clk) begin
      q[b] <= mem[rd[AW-1:1]];
    end
  end : g_ram

endmodule : iclink_gearbox

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
