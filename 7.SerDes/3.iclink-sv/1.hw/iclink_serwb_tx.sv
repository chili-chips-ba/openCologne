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
// hdr: one request per packet, port and word count (1 .. 16383); the
// words then come on d_* one pair per clock, the last pair with only
// d_word[0] used when the count is odd. o_ready low (the far side sent
// XOFF) holds everything.
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

  state_t        state;
  word_t         crc;  // CRC32 over the port / length word and the data so far
  logic   [13:0] left;  // data words still to send

  assign hdr_ready = (state == S_IDLE) & o_ready;
  assign d_ready   = (state == S_DATA) & o_ready;

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      state   <= S_IDLE;
      crc     <= SERWB_CRC_INIT;
      left    <= '0;
      o_word  <= '0;
      o_valid <= '0;
    end
    else if (o_ready) begin
      o_valid <= '0;

      unique case (state)
        S_IDLE: begin
          if (hdr_valid) begin
            o_word[0] <= SERWB_PREAMBLE;
            o_word[1] <= serwb_header(hdr_port, hdr_words);
            o_valid   <= 2'b11;
            crc       <= serwb_crc32(SERWB_CRC_INIT, serwb_header(hdr_port, hdr_words));
            left      <= hdr_words;
            state     <= S_DATA;
          end
        end

        S_DATA: begin
          if (d_valid) begin
            o_word[0] <= d_word[0];
            o_valid   <= 2'b11;
            if (left == 14'd1) begin  // odd count: the CRC fills slot 1
              o_word[1] <= serwb_crc32(crc, d_word[0]);
              state     <= S_IDLE;
            end
            else begin
              o_word[1] <= d_word[1];
              crc       <= serwb_crc32(serwb_crc32(crc, d_word[0]), d_word[1]);
              left      <= left - 14'd2;
              if (left == 14'd2) begin  // even count: the CRC takes the next beat
                state <= S_CRC;
              end
            end
          end
        end

        S_CRC: begin
          o_word[0] <= crc;
          o_valid   <= 2'b01;
          state     <= S_IDLE;
        end
      endcase
    end
  end

endmodule : iclink_serwb_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
