// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerWB packetizer, W words per clock (2 or 4): LiteICLink's Packetizer
// with CRC (liteiclink/serwb/packet.py). The same packet words in the same
// order; each clock carries up to W of them, slot 0 (bytes 0-3) first.
// W = 2 fits the 64-bit PHY; W = 4 runs at half its clock, through a 2:1
// gearbox.
//
//   W = 2   beat 0:      preamble | port / length
//           beats 1 ..:  data     | data
//           last beat:   data     | CRC32          (odd word count)
//                    or  CRC32    | -              (even word count)
//   W = 4   beat 0:      preamble | port / length | data | data
//           beats 1 ..:  data x 4
//           last beat:   the rest of the data, then the CRC32
//
// A packet always starts in slot 0; the slots after its CRC stay empty
// (o_valid low), and the line mux after this module fills them with K28.1.
//
// Three stages, all held by o_ready low (the far side sent XOFF):
//   1. framing: the state machine places the words; a CRC slot is empty
//   2. data term: the CRC of this beat's words alone, from 0
//   3. CRC: the running CRC takes the data term; a CRC slot gets the result
// The CRC is linear, so the data term needs no running CRC, and the CRC loop
// is one shallow XOR tree (iclink_serwb_pkg).
//
// hdr: one request per packet, port and word count (1 .. 16383). All of
// the packet's words must be waiting by then: d_word shows the next W, and
// the packetizer takes d_take of them a clock (the pump's TX FIFO).
//==========================================================================
module iclink_serwb_tx
  import iclink_serwb_pkg::*;
#(
    parameter  int W  = 2,             // words a clock: 2 or 4
    localparam int TW = $clog2(W + 1)
) (
    input logic clk,
    input logic arst_n,

    input  logic        hdr_valid,
    input  logic [ 7:0] hdr_port,
    input  logic [13:0] hdr_words,
    output logic        hdr_ready,

    input  word_t [ W-1:0] d_word,  // the next W payload words, d_word[0] first
    output logic  [TW-1:0] d_take,  // how many of them go this clock

    output word_t [W-1:0] o_word,
    output logic  [W-1:0] o_valid,
    input  logic          o_ready
);

  typedef enum logic [1:0] {
    S_IDLE,
    S_DATA,
    S_CRC
  } state_t;

  // what a stage carries for one beat
  typedef struct packed {
    word_t [W-1:0] word;
    logic [W-1:0]  valid;
    logic [W-1:0]  crcd;     // slots the CRC covers: port / length and data
    logic [W-1:0]  crcslot;  // the slot that takes the CRC
    logic          init;     // a preamble: the CRC starts again
  } beat_t;

  state_t state, state_next;
  logic [13:0] left, left_next;  // data words still to send
  logic [TW-1:0] take;  // words this beat takes, if it goes
  beat_t f_next, f, t;  // into stage 1, after stage 1, after stage 2
  word_t       t_dterm;  // stage 2: the data term of t's CRC slots, and the INIT term on a start
  logic  [2:0] t_n;  // stage 2: how many words t's CRC slots hold
  word_t       crc;  // stage 3: the CRC over the packet so far
  word_t       crc_now;  // the CRC including this beat's words

  assign hdr_ready = (state == S_IDLE) & o_ready;
  assign d_take    = o_ready ? take : '0;

  // 1. framing
  always_comb begin
    f_next     = '0;
    take       = '0;
    state_next = state;
    left_next  = left;

    unique case (state)
      S_IDLE: begin
        if (hdr_valid) begin
          f_next.word[0]    = SERWB_PREAMBLE;
          f_next.word[1]    = serwb_header(hdr_port, hdr_words);
          f_next.valid[1:0] = 2'b11;
          f_next.crcd[1]    = 1'b1;
          f_next.init       = 1'b1;
          for (int s = 2; s < W; s++) begin  // W = 4: data from slot 2
            if (14'(s - 2) < hdr_words) begin
              f_next.word[s]  = d_word[s-2];
              f_next.valid[s] = 1'b1;
              f_next.crcd[s]  = 1'b1;
              take            = take + 1'b1;
            end
            else if (14'(s - 2) == hdr_words) begin
              f_next.valid[s]   = 1'b1;
              f_next.crcslot[s] = 1'b1;
            end
          end
          left_next = hdr_words - 14'(take);
          if (hdr_words + 14'd2 < 14'(W)) begin  // the CRC fits in this beat
            state_next = S_IDLE;
          end
          else if (hdr_words + 14'd2 == 14'(W)) begin
            state_next = S_CRC;
          end
          else begin
            state_next = S_DATA;
          end
        end
      end

      S_DATA: begin
        for (int s = 0; s < W; s++) begin
          if (14'(s) < left) begin
            f_next.word[s]  = d_word[s];
            f_next.valid[s] = 1'b1;
            f_next.crcd[s]  = 1'b1;
            take            = take + 1'b1;
          end
          else if (14'(s) == left) begin
            f_next.valid[s]   = 1'b1;
            f_next.crcslot[s] = 1'b1;
          end
        end
        left_next = left - 14'(take);
        if (left < 14'(W)) begin  // the CRC fits in this beat
          state_next = S_IDLE;
        end
        else if (left == 14'(W)) begin
          state_next = S_CRC;
        end
      end

      S_CRC: begin
        f_next.valid[0]   = 1'b1;
        f_next.crcslot[0] = 1'b1;
        state_next        = S_IDLE;
      end

      default: begin
        state_next = S_IDLE;
      end
    endcase
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      state <= S_IDLE;
      left  <= '0;
      f     <= '0;
    end
    else if (o_ready) begin
      state <= state_next;
      left  <= left_next;
      f     <= f_next;
    end
  end

  // 2. data term: each covered word's own term, by how many covered words
  // follow it in the beat
  logic  [1:0] k;
  word_t       dterm;
  logic  [2:0] n;

  always_comb begin
    k     = '0;
    dterm = '0;
    for (int s = W - 1; s >= 0; s--) begin
      if (f.crcd[s]) begin
        dterm = dterm ^ serwb_crc_mterm(f.word[s], k);
        k     = k + 1'b1;
      end
    end
    n = '0;
    for (int s = 0; s < W; s++) begin
      n = n + 3'(f.crcd[s]);
    end
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      t       <= '0;
      t_dterm <= '0;
      t_n     <= '0;
    end
    else if (o_ready) begin
      t       <= f;
      t_n     <= n;
      t_dterm <= dterm ^ (f.init ? serwb_crc_iterm(n) : '0);
    end
  end

  // 3. CRC: the running CRC takes the data term; a CRC slot gets the result
  always_comb begin
    // crc is 0 between packets (cleared after the CRC slot), so a start needs
    // no gating here: its INIT term is in t_dterm
    crc_now = serwb_crc_cterm(crc, t_n) ^ t_dterm;
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      crc     <= '0;
      o_word  <= '0;
      o_valid <= '0;
    end
    else if (o_ready) begin
      crc     <= (t.crcslot != '0) ? '0 : crc_now;
      o_valid <= t.valid;
      for (int s = 0; s < W; s++) begin
        o_word[s] <= t.crcslot[s] ? crc_now : t.word[s];
      end
    end
  end

endmodule : iclink_serwb_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
