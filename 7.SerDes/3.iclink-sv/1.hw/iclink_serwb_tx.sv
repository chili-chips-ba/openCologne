// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerWB packetizer, two words per clock: LiteICLink's Packetizer with CRC
// (liteiclink/serwb/packet.py), for the 64-bit PHY. The same packet words
// in the same order; each clock carries two of them, in slot 0 (bytes 0-3)
// then slot 1 (bytes 4-7).
//
//   beat 0:          preamble          | port / length
//   beats 1 ..:      data              | data
//   last beat:       data              | CRC32         (odd word count)
//                or  CRC32             | -             (even word count)
//
// A packet always starts in slot 0, so the data words keep the pairing of
// the input (d_word[0], d_word[1]). An empty slot (o_valid low) is filled
// with K28.1 by the line mux after this module.
//
// Three stages, all held by o_ready low (the far side sent XOFF):
//   1. framing: the state machine places the words; a CRC slot is empty
//   2. data term: the CRC of this beat's words alone, from 0
//   3. CRC: the running CRC takes the data term; a CRC slot gets the result
// The CRC is linear, so the data term needs no running CRC, and the CRC loop
// is one shallow XOR tree (iclink_serwb_pkg).
//
// hdr: one request per packet, port and word count (1 .. 16383); the
// words then come on d_* one pair per clock, the last pair with only
// d_word[0] used when the count is odd.
//==========================================================================
module iclink_serwb_tx
  import iclink_serwb_pkg::*;
(
    input logic clk,
    input logic arst_n,

    input  logic        hdr_valid,
    input  logic [ 7:0] hdr_port,
    input  logic [13:0] hdr_words,
    output logic        hdr_ready,

    input  logic        d_valid,
    input  word_t [1:0] d_word,
    output logic        d_ready,

    output word_t [1:0] o_word,
    output logic  [1:0] o_valid,
    input  logic        o_ready
);

  typedef enum logic [1:0] {
    S_IDLE,
    S_DATA,
    S_CRC
  } state_t;

  // what a stage carries for one beat
  typedef struct packed {
    word_t [1:0] word;
    logic [1:0]  valid;
    logic [1:0]  crcd;     // slots the CRC covers: port / length and data
    logic [1:0]  crcslot;  // the slot that takes the CRC
    logic        init;     // a preamble: the CRC starts again
  } beat_t;

  state_t        state;
  logic   [13:0] left;  // data words still to send
  beat_t f, t;  // after stage 1 and stage 2
  word_t t_dterm;  // stage 2: the data term of t's CRC slots
  word_t crc;  // stage 3: the CRC over the packet so far
  word_t crc_now;  // the CRC including this beat's words

  assign hdr_ready = (state == S_IDLE) & o_ready;
  assign d_ready   = (state == S_DATA) & o_ready;

  // 1. framing
  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      state <= S_IDLE;
      left  <= '0;
      f     <= '0;
    end
    else if (o_ready) begin
      f <= '0;

      unique case (state)
        S_IDLE: begin
          if (hdr_valid) begin
            f.word  <= {serwb_header(hdr_port, hdr_words), SERWB_PREAMBLE};
            f.valid <= 2'b11;
            f.crcd  <= 2'b10;
            f.init  <= 1'b1;
            left    <= hdr_words;
            state   <= S_DATA;
          end
        end

        S_DATA: begin
          if (d_valid) begin
            f.word[0] <= d_word[0];
            f.valid   <= 2'b11;
            if (left == 14'd1) begin  // odd count: the CRC fills slot 1
              f.crcd    <= 2'b01;
              f.crcslot <= 2'b10;
              state     <= S_IDLE;
            end
            else begin
              f.word[1] <= d_word[1];
              f.crcd    <= 2'b11;
              left      <= left - 14'd2;
              if (left == 14'd2) begin  // even count: the CRC takes the next beat
                state <= S_CRC;
              end
            end
          end
        end

        S_CRC: begin
          f.valid   <= 2'b01;
          f.crcslot <= 2'b01;
          state     <= S_IDLE;
        end

        default: begin
          state <= S_IDLE;
        end
      endcase
    end
  end

  // 2. data term
  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      t       <= '0;
      t_dterm <= '0;
    end
    else if (o_ready) begin
      t       <= f;
      t_dterm <= serwb_crc_dterm(f.word, f.crcd);
    end
  end

  // 3. CRC: the running CRC takes the data term; a CRC slot gets the result
  always_comb begin
    crc_now = serwb_crc_cterm(t.init ? SERWB_CRC_INIT : crc,
                              {1'b0, t.crcd[0]} + {1'b0, t.crcd[1]}) ^ t_dterm;
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      crc     <= SERWB_CRC_INIT;
      o_word  <= '0;
      o_valid <= '0;
    end
    else if (o_ready) begin
      crc     <= crc_now;
      o_valid <= t.valid;
      for (int s = 0; s < 2; s++) begin
        o_word[s] <= t.crcslot[s] ? crc_now : t.word[s];
      end
    end
  end

endmodule : iclink_serwb_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
