// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Async FIFO of 32-bit words for the FIFO pump: 0, 1 or 2 words in per
// write clock, 0, 1 or 2 words out per read clock.
//
// Storage: two DEPTH/2 x 32 RAMs, even words and odd words, so two
// neighbouring words are always in different RAMs: one write port and one
// registered read port each, which maps to block RAM.
//
// Commit / rewind (COMMIT = 1, the RX FIFO): the writer's words stay
// invisible to the reader until w_commit; w_rewind drops all words since
// the last commit. So the FIFO is the depacketizer's packet buffer: a
// packet with a bad CRC never reaches the reader. With COMMIT = 0 (the TX
// FIFO) every word is visible once written.
//
// Levels, each side's view, never too optimistic: w_used counts all words
// written and not yet known as read (committed or not); r_avail counts
// committed words not yet read. The pointers cross by iclink_cdc_ptr.
//
// The writer must keep w_used + (words written) <= DEPTH; the reader must
// not take more than r_avail.
//==========================================================================
module iclink_serwb_fifo
  import iclink_serwb_pkg::*;
#(
    parameter  int DEPTH  = 1024,          // words, a power of 2
    parameter  bit COMMIT = 1'b1,
    localparam int AW     = $clog2(DEPTH)
) (
    input  logic         w_clk,
    input  logic         w_arst_n,
    input  word_t [ 1:0] w_word,
    input  logic  [ 1:0] w_valid,   // 2'b00, 2'b01 or 2'b11: compacted, slot 0 first
    input  logic         w_commit,  // this clock's words included
    input  logic         w_rewind,  // this clock's words dropped too
    output logic  [AW:0] w_used,

    input  logic         r_clk,
    input  logic         r_arst_n,
    output word_t [ 1:0] r_word,    // the next two words, r_word[0] first
    input  logic  [ 1:0] r_take,    // 0, 1 or 2 words taken this clock
    output logic  [AW:0] r_avail
);

  word_t mem0[DEPTH/2];  // even words
  word_t mem1[DEPTH/2];  // odd words

  //-----------------------------------------------------------------------
  // write side
  //-----------------------------------------------------------------------
  logic [AW:0] wr_ptr, wr_ptr_next, com_ptr, rd_ptr_w;
  logic [1:0] w_n;
  logic [AW-2:0] w_row0, w_row1;  // rows of the even and the odd one of wr_ptr, wr_ptr + 1

  // of two neighbouring words p, p + 1: the odd one is in row p >> 1, the
  // even one in row (p >> 1) + p[0]; so the pair always lands in both RAMs
  always_comb begin
    w_n         = {1'b0, w_valid[0]} + {1'b0, w_valid[1]};
    wr_ptr_next = wr_ptr + (AW + 1)'(w_n);
    w_row1      = wr_ptr[AW-1:1];
    w_row0      = wr_ptr[AW-1:1] + (AW - 1)'(wr_ptr[0]);
  end

  // word 0 goes to wr_ptr, word 1 to wr_ptr + 1
  always_ff @(posedge w_clk) begin
    if (wr_ptr[0] ? w_valid[1] : w_valid[0]) begin
      mem0[w_row0] <= wr_ptr[0] ? w_word[1] : w_word[0];
    end
    if (wr_ptr[0] ? w_valid[0] : w_valid[1]) begin
      mem1[w_row1] <= wr_ptr[0] ? w_word[0] : w_word[1];
    end
  end

  always_ff @(posedge w_clk or negedge w_arst_n) begin
    if (!w_arst_n) begin
      wr_ptr  <= '0;
      com_ptr <= '0;
      w_used  <= '0;
    end
    else begin
      if (COMMIT && w_rewind) begin
        wr_ptr <= com_ptr;
      end
      else begin
        wr_ptr <= wr_ptr_next;
      end
      if (!COMMIT || w_commit) begin
        com_ptr <= wr_ptr_next;
      end
      w_used <= ((COMMIT && w_rewind) ? com_ptr : wr_ptr_next) - rd_ptr_w;
    end
  end

  //-----------------------------------------------------------------------
  // read side
  //-----------------------------------------------------------------------
  logic [AW:0] rd_ptr, rd_ptr_next, com_ptr_r;
  logic [AW-2:0] r_row0, r_row1;  // rows of the even and the odd one of the next two words
  word_t q0, q1;  // RAM outputs: words at the even and odd one of them

  always_comb begin
    rd_ptr_next = rd_ptr + (AW + 1)'(r_take);
    r_row1      = rd_ptr_next[AW-1:1];
    r_row0      = rd_ptr_next[AW-1:1] + (AW - 1)'(rd_ptr_next[0]);
  end

  // registered reads at the next pointer, so the words at rd_ptr are ready
  always_ff @(posedge r_clk) begin
    q0 <= mem0[r_row0];
    q1 <= mem1[r_row1];
  end

  always_comb begin
    r_word[0] = rd_ptr[0] ? q1 : q0;
    r_word[1] = rd_ptr[0] ? q0 : q1;
  end

  always_ff @(posedge r_clk or negedge r_arst_n) begin
    if (!r_arst_n) begin
      rd_ptr  <= '0;
      r_avail <= '0;
    end
    else begin
      rd_ptr  <= rd_ptr_next;
      r_avail <= com_ptr_r - rd_ptr_next;
    end
  end

  //-----------------------------------------------------------------------
  // pointers across
  //-----------------------------------------------------------------------
  iclink_cdc_ptr #(
      .W(AW + 1)
  ) u_com_to_r (
      .src_clk   (w_clk),
      .src_arst_n(w_arst_n),
      .src_ptr   (com_ptr),
      .dst_clk   (r_clk),
      .dst_arst_n(r_arst_n),
      .dst_ptr   (com_ptr_r)
  );

  iclink_cdc_ptr #(
      .W(AW + 1)
  ) u_rd_to_w (
      .src_clk   (r_clk),
      .src_arst_n(r_arst_n),
      .src_ptr   (rd_ptr),
      .dst_clk   (w_clk),
      .dst_arst_n(w_arst_n),
      .dst_ptr   (rd_ptr_w)
  );

endmodule : iclink_serwb_fifo

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
