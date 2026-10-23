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
// that pointer 2 or 3 of its clocks late, so it trails the writer by START
// plus those words, well inside DEPTH. Until START words wait, and again
// should the FIFO ever run dry, the read side sends K28.5 commas, which the
// far side's K filter drops.
//
// Storage: two RAMs, even and odd PHY words, so the wide side reads or
// writes one row of both and the narrow side one RAM. Each has one write
// port and one registered read port, on their own clocks: block RAM.
//==========================================================================
module iclink_gearbox
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter  int IN_N  = 2,
    parameter  int OUT_N = 1,
    parameter  int DEPTH = 32,                    // PHY words, a power of 2
    localparam int START = 2 * OUT_N,             // words waiting before the first read
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

  localparam logic [7:0] K28_5 = 8'hBC;

  typedef logic [AW-2:0] row_t;

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

  always_ff @(posedge w_clk or negedge w_arst_n) begin
    if (!w_arst_n) begin
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
  logic [AW:0] wr_r, rd, fill;  // in PHY words
  logic run, go, go_d, sel_d;
  phy_word_t [1:0] q;  // RAM outputs, even and odd
  phy_word_t       comma;

  always_comb begin
    wr_u_r = '0;
    for (int b = UW - 1; b >= 0; b--) begin  // Gray to binary
      wr_u_r[b] = (b == UW - 1) ? gray_s2[b] : (wr_u_r[b+1] ^ gray_s2[b]);
    end
    wr_r       = (AW + 1)'(wr_u_r * IN_N);
    fill       = wr_r - rd;
    go         = run && fill >= (AW + 1)'(OUT_N);

    comma      = '0;
    comma.d[0] = K28_5;
    comma.k[0] = 1'b1;
  end

  always_ff @(posedge r_clk or negedge r_arst_n) begin
    if (!r_arst_n) begin
      gray_s1 <= '0;
      gray_s2 <= '0;
      rd      <= '0;
      run     <= 1'b0;
      go_d    <= 1'b0;
      sel_d   <= 1'b0;
      r_word  <= '0;
    end
    else begin
      gray_s1 <= wr_gray;
      gray_s2 <= gray_s1;
      go_d    <= go;
      sel_d   <= rd[0];
      if (go) begin
        rd <= rd + (AW + 1)'(OUT_N);
      end
      else begin
        run <= fill >= (AW + 1)'(START);
        if (!run) begin  // start START words behind; a word pair starts even
          rd <= (wr_r - (AW + 1)'(START)) & ~(AW + 1)'(OUT_N - 1);
        end
      end
      // a clock after the RAM read
      for (int i = 0; i < OUT_N; i++) begin
        if (!go_d) begin
          r_word[i] <= comma;
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
