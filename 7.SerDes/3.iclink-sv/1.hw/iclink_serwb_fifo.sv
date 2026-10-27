// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Synchronous FIFO of 32-bit words for the FIFO pump: 0 .. W words in and
// 0 .. W words out per clock (W = 2 or 4, the pump's words a line clock).
// One clock for both sides: the pump, the CPU and the PHY share it, so no
// pointer crosses a clock domain.
//
// Storage: W RAMs of DEPTH/W x 32, word p in RAM p mod W, so W neighbouring
// words are always in different RAMs: one write port and one registered
// read port each, which maps to block RAM. WN and RN cap the words in and
// out a clock where a side moves fewer (the CPU side: one), so its port
// and muxes shrink.
//
// Commit / rewind (COMMIT = 1, the RX FIFO): the writer's words stay
// invisible to the reader until w_commit; w_rewind drops all words since
// the last commit. So the FIFO is the depacketizer's packet buffer: a
// packet with a bad CRC never reaches the reader. With COMMIT = 0 (the TX
// FIFO) every word is visible once written.
//
// Levels: w_used counts all words written and not yet read (committed or
// not); r_avail counts committed words not yet read. Both are flops and
// exact, but for the clocks below.
//
// Timing: the write port is registered in front of the RAM, so a word
// lands a clock later; the commit pointer reaches the reader through one
// flop (com_ptr_r) for the same clock, so the RAM always holds what the
// reader may take. A word written in clock t can be taken in clock t + 3.
// On the read side, the rows for taking 0 .. W words come from rd_ptr
// alone, and the late r_take only picks one.
//
// The writer must keep w_used + (words written) <= DEPTH; the reader must
// not take more than r_avail.
//
// half_clk_strobe: every flop and RAM port moves only on clocks with it high, so
// all of the above counts in those clocks.
//==========================================================================
module iclink_serwb_fifo
  import iclink_serwb_pkg::*;
#(
    parameter  int DEPTH  = 1024,           // words, a power of 2
    parameter  int W      = 2,              // words a clock, a power of 2
    parameter  int WN     = W,              // words in a clock, at most
    parameter  int RN     = W,              // words out a clock, at most
    parameter  bit COMMIT = 1'b1,
    localparam int AW     = $clog2(DEPTH),
    localparam int LW     = $clog2(W),      // address bits of the RAM select
    localparam int TW     = $clog2(W + 1)   // a count of 0 .. W
) (
    input logic clk,
    input logic arst_n,
    input logic half_clk_strobe, // clock enable, a flop: 1 (W = 2), every other clock (W = 4)

    input  word_t [WN-1:0] w_word,
    input  logic  [WN-1:0] w_valid,   // compacted, slot 0 first: 0, 1, 3, 7 ..
    input  logic           w_commit,  // this clock's words included
    input  logic           w_rewind,  // this clock's words dropped too
    output logic  [  AW:0] w_used,

    output word_t [RN-1:0] r_word,  // the next RN words, r_word[0] first
    input  logic  [TW-1:0] r_take,  // 0 .. W words taken this clock
    output logic  [  AW:0] r_avail
);

  typedef logic [AW-LW-1:0] row_t;

  if ((DEPTH & (DEPTH - 1)) != 0 || !(W inside {2, 4}) || DEPTH < 2 * W) begin : g_bad
    $error("iclink_serwb_fifo: DEPTH %0d (a power of 2), W %0d (2 or 4)", DEPTH, W);
  end : g_bad

  //-----------------------------------------------------------------------
  // write side
  //-----------------------------------------------------------------------
  logic [AW:0] wr_ptr, wr_ptr_next, com_ptr, rd_ptr, rd_ptr_next;
  logic  [TW-1:0] w_n;
  row_t  [ W-1:0] w_row;  // RAM b's row, for the one of the next W words it holds
  logic  [ W-1:0] w_we;
  word_t [ W-1:0] w_d;

  // word i goes to address wr_ptr + i: RAM b takes word (b - wr_ptr) mod W,
  // in row wr_ptr >> LW, or in the row after when b is below wr_ptr's RAM
  always_comb begin
    w_n = '0;
    for (int i = 0; i < WN; i++) begin
      w_n = w_n + TW'(w_valid[i]);
    end
    wr_ptr_next = wr_ptr + (AW + 1)'(w_n);
    for (int b = 0; b < W; b++) begin
      w_row[b] = row_t'(wr_ptr[AW-1:LW]) + row_t'(LW'(b) < wr_ptr[LW-1:0]);
      w_we[b]  = 1'b0;
      w_d[b]   = '0;
      for (int i = 0; i < WN; i++) begin
        if (LW'(LW'(b) - wr_ptr[LW-1:0]) == LW'(i)) begin
          w_we[b] = w_valid[i];
          w_d[b]  = w_word[i];
        end
      end
    end
  end

  // into flops first, then the RAMs
  logic  [W-1:0] ram_we;
  row_t  [W-1:0] ram_row;
  word_t [W-1:0] ram_d;

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      ram_we <= '0;
    end
    else if (half_clk_strobe) begin
      ram_we <= w_we;
    end
  end

  always_ff @(posedge clk) begin
    if (half_clk_strobe) begin
      ram_row <= w_row;
      ram_d   <= w_d;
    end
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      wr_ptr  <= '0;
      com_ptr <= '0;
      w_used  <= '0;
    end
    else if (half_clk_strobe) begin
      if (COMMIT && w_rewind) begin
        wr_ptr <= com_ptr;
      end
      else begin
        wr_ptr <= wr_ptr_next;
      end
      if (!COMMIT || w_commit) begin
        com_ptr <= wr_ptr_next;
      end
      // the words read this clock are free from the next one
      w_used <= ((COMMIT && w_rewind) ? com_ptr : wr_ptr_next) - rd_ptr_next;
    end
  end

  //-----------------------------------------------------------------------
  // read side
  //-----------------------------------------------------------------------
  logic [AW:0] com_ptr_r, r_avail_now;  // com_ptr_r: com_ptr, a clock late (the RAM write)
  logic  [AW-1:0]        p;  // rd_ptr + t, for each take t (the address, no wrap bit)
  row_t  [  RN:0][W-1:0] r_row_t;  // RAM b's row after a take of t words
  row_t  [ W-1:0]        r_row;
  word_t [ W-1:0]        q;  // RAM outputs

  // r_take arrives late: the rows for each take come from rd_ptr alone, and
  // r_take only picks one
  always_comb begin
    rd_ptr_next = rd_ptr + (AW + 1)'(r_take);
    for (int t = 0; t <= RN; t++) begin
      p = rd_ptr[AW-1:0] + AW'(t);
      for (int b = 0; b < W; b++) begin
        r_row_t[t][b] = row_t'(p[AW-1:LW]) + row_t'(LW'(b) < p[LW-1:0]);
      end
    end
    r_row = r_row_t[0];
    for (int t = 1; t <= RN; t++) begin
      if (r_take == TW'(t)) begin
        r_row = r_row_t[t];
      end
    end
    r_avail_now = com_ptr_r - rd_ptr;
  end

  // r_word[i] is the word at rd_ptr + i, in RAM (rd_ptr + i) mod W
  always_comb begin
    r_word = '0;
    for (int i = 0; i < RN; i++) begin
      r_word[i] = q[LW'(rd_ptr[LW-1:0]+LW'(i))];
    end
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      com_ptr_r <= '0;
      rd_ptr    <= '0;
      r_avail   <= '0;
    end
    else if (half_clk_strobe) begin
      com_ptr_r <= com_ptr;
      rd_ptr    <= rd_ptr_next;
      r_avail   <= r_avail_now - (AW + 1)'(r_take);
    end
  end

  //-----------------------------------------------------------------------
  // the RAMs, one per word slot; registered reads at the next pointer, so
  // the words at rd_ptr are ready
  //-----------------------------------------------------------------------
  for (genvar b = 0; b < W; b++) begin : g_ram
    word_t mem[DEPTH/W];

    always_ff @(posedge clk) begin
      if (half_clk_strobe) begin
        if (ram_we[b]) begin
          mem[ram_row[b]] <= ram_d[b];
        end
        q[b] <= mem[r_row[b]];
      end
    end
  end : g_ram

endmodule : iclink_serwb_fifo

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
