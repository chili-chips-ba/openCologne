// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerWB depacketizer, two words per clock: LiteICLink's CRCDepacketizer
// (liteiclink/serwb/packet.py), for the 64-bit PHY. The same state machine,
// stepped twice per clock, slot 0 (bytes 0-3) then slot 1 (bytes 4-7):
//
//   PREAMBLE  wait for 0x5AA55AA5; any other word is dropped
//   HEADER    port / length; 0 words or more than MAX_WORDS: drop
//   DATA      the payload words, into the CRC and out on o_*
//   CHECK     the CRC32 word: o_commit if it matches, else o_crc_error
//
// A packet may start in either slot and may have gaps (i_valid low, a K
// symbol on the line) anywhere. The data words go out compacted, slot 0
// first (o_valid 2'b01 or 2'b11), as soon as they arrive; o_commit or
// o_drop then ends the packet, so the RX FIFO keeps or rewinds what it
// took. This replaces LiteICLink's store-and-forward buffer: the FIFO is
// the buffer.
//
// Timeout as LiteICLink: TIMEOUT_CLKS clocks without a word in DATA or
// CHECK drops the packet. One packet ends per clock at most (a packet is
// 4 words or more), so one o_commit / o_drop per clock is enough.
//==========================================================================
module iclink_serwb_rx
  import iclink_serwb_pkg::*;
#(
    parameter int MAX_WORDS    = 16,
    parameter int TIMEOUT_CLKS = 31250  // 1 ms at 31.25 MHz
) (
    input logic clk,
    input logic arst_n,

    input word_t [1:0] i_word,
    input logic  [1:0] i_valid,

    output word_t [1:0] o_word,
    output logic  [1:0] o_valid,
    output logic  [7:0] o_port,
    output logic        o_commit,
    output logic        o_drop,      // every dropped packet, CRC errors included
    output logic        o_crc_error
);

  typedef enum logic [1:0] {
    S_PREAMBLE,
    S_HEADER,
    S_DATA,
    S_CHECK
  } state_t;

  typedef struct packed {
    state_t      state;
    word_t       crc;
    logic [13:0] left;   // data words still to come
    logic [7:0]  port;
  } ctx_t;

  // one word through the state machine
  function automatic void step(input ctx_t c, input word_t w, output ctx_t n, output logic dv,
                               output logic commit, output logic drop, output logic crc_err);
    n       = c;
    dv      = 1'b0;
    commit  = 1'b0;
    drop    = 1'b0;
    crc_err = 1'b0;
    unique case (c.state)
      S_PREAMBLE: begin
        if (w == SERWB_PREAMBLE) begin
          n.state = S_HEADER;
        end
      end

      S_HEADER: begin
        n.port = w[7:0];
        n.left = w[23:10];
        n.crc  = serwb_crc32(SERWB_CRC_INIT, w);
        if (w[23:10] != '0 && w[23:10] <= 14'(MAX_WORDS)) begin
          n.state = S_DATA;
        end
        else begin
          n.state = S_PREAMBLE;
          drop    = 1'b1;
        end
      end

      S_DATA: begin
        dv     = 1'b1;
        n.crc  = serwb_crc32(c.crc, w);
        n.left = c.left - 14'd1;
        if (c.left == 14'd1) begin
          n.state = S_CHECK;
        end
      end

      S_CHECK: begin
        n.state = S_PREAMBLE;
        if (w == c.crc) begin
          commit = 1'b1;
        end
        else begin
          crc_err = 1'b1;
          drop    = 1'b1;
        end
      end
    endcase
  endfunction

  ctx_t ctx, ctx_mid, ctx_next;
  logic [1:0] dv, commit, drop, crc_err;
  logic                              timeout;
  logic [$clog2(TIMEOUT_CLKS+1)-1:0] timer;  // clocks without a word, inside a packet

  always_comb begin : _steps
    ctx_mid                     = ctx;
    ctx_next                    = ctx;
    {dv, commit, drop, crc_err} = '0;
    if (i_valid[0]) begin
      step(ctx, i_word[0], ctx_mid, dv[0], commit[0], drop[0], crc_err[0]);
    end
    ctx_next = ctx_mid;
    if (i_valid[1]) begin
      step(ctx_mid, i_word[1], ctx_next, dv[1], commit[1], drop[1], crc_err[1]);
    end
    // as LiteICLink, the timer drops in DATA and CHECK only, never in HEADER
    timeout = (i_valid == '0) && (ctx.state inside {S_DATA, S_CHECK}) &&
        (timer == $bits(timer)'(TIMEOUT_CLKS - 1));
    if (timeout) begin
      ctx_next.state = S_PREAMBLE;
    end
  end : _steps

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      ctx         <= '{state: S_PREAMBLE, crc: SERWB_CRC_INIT, left: '0, port: '0};
      timer       <= '0;
      o_word      <= '0;
      o_valid     <= '0;
      o_port      <= '0;
      o_commit    <= 1'b0;
      o_drop      <= 1'b0;
      o_crc_error <= 1'b0;
    end
    else begin
      ctx <= ctx_next;

      if (i_valid != '0 || timeout || ctx.state == S_PREAMBLE) begin
        timer <= '0;
      end
      else begin
        timer <= timer + 1'b1;
      end

      // compacted, slot 0 first
      o_word[0]   <= dv[0] ? i_word[0] : i_word[1];
      o_word[1]   <= i_word[1];
      o_valid     <= {dv[0] & dv[1], dv[0] | dv[1]};

      o_port      <= ctx.port;  // a CHECK comes a clock or more after its HEADER
      o_commit    <= |commit;
      o_drop      <= (|drop) | timeout;
      o_crc_error <= |crc_err;
    end
  end

endmodule : iclink_serwb_rx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
