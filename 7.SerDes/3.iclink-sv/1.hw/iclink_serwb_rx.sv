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
// Five stages: input flops; framing (the state machine, no CRC); the data
// term of the beat's words; the running CRC; the check. The CRC is
// linear, so the data term needs no running CRC, and the CRC loop is one
// shallow XOR tree (iclink_serwb_pkg). Every output comes out of the last
// stage, so words, commits and drops keep their order.
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
    logic [13:0] left;   // data words still to come
    logic [7:0]  port;
  } ctx_t;

  // what a stage carries for one beat
  typedef struct packed {
    word_t [1:0] word;
    logic [1:0]  data;  // payload words, to the FIFO
    logic [1:0]  crcd;  // slots the CRC covers: port / length and data
    logic [1:0]  chk;   // the slot with the received CRC
    logic        init;  // a header: the CRC starts again
    logic        drop;  // a header out of range, or a timeout
    logic [7:0]  port;
  } beat_t;

  // one word through the state machine
  function automatic void step(input ctx_t c, input word_t w, output ctx_t n, output logic data,
                               output logic crcd, output logic chk, output logic init,
                               output logic drop);
    n    = c;
    data = 1'b0;
    crcd = 1'b0;
    chk  = 1'b0;
    init = 1'b0;
    drop = 1'b0;
    unique case (c.state)
      S_PREAMBLE: begin
        if (w == SERWB_PREAMBLE) begin
          n.state = S_HEADER;
        end
      end

      S_HEADER: begin
        n.port = w[7:0];
        n.left = w[23:10];
        if (w[23:10] != '0 && w[23:10] <= 14'(MAX_WORDS)) begin
          n.state = S_DATA;
          crcd    = 1'b1;
          init    = 1'b1;
        end
        else begin
          n.state = S_PREAMBLE;
          drop    = 1'b1;
        end
      end

      S_DATA: begin
        data   = 1'b1;
        crcd   = 1'b1;
        n.left = c.left - 14'd1;
        if (c.left == 14'd1) begin
          n.state = S_CHECK;
        end
      end

      S_CHECK: begin
        n.state = S_PREAMBLE;
        chk     = 1'b1;
      end
    endcase
  endfunction

  //-----------------------------------------------------------------------
  // 0. input flops
  //-----------------------------------------------------------------------
  word_t [1:0] r_word;
  logic  [1:0] r_valid;

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      r_word  <= '0;
      r_valid <= '0;
    end
    else begin
      r_word  <= i_word;
      r_valid <= i_valid;
    end
  end

  //-----------------------------------------------------------------------
  // 1. framing
  //-----------------------------------------------------------------------
  ctx_t ctx, ctx_mid, ctx_next;
  beat_t f_next, f;
  logic [1:0] init, drop;
  logic                              timeout;
  logic [$clog2(TIMEOUT_CLKS+1)-1:0] timer;  // clocks without a word, inside a packet

  always_comb begin : _steps
    ctx_mid  = ctx;
    ctx_next = ctx;
    f_next   = '0;
    init     = '0;
    drop     = '0;
    if (r_valid[0]) begin
      step(ctx, r_word[0], ctx_mid, f_next.data[0], f_next.crcd[0], f_next.chk[0], init[0],
           drop[0]);
    end
    ctx_next = ctx_mid;
    if (r_valid[1]) begin
      step(ctx_mid, r_word[1], ctx_next, f_next.data[1], f_next.crcd[1], f_next.chk[1], init[1],
           drop[1]);
    end
    // as LiteICLink, the timer drops in DATA and CHECK only, never in HEADER
    timeout = (r_valid == '0) && (ctx.state inside {S_DATA, S_CHECK}) &&
        (timer == $bits(timer)'(TIMEOUT_CLKS - 1));
    if (timeout) begin
      ctx_next.state = S_PREAMBLE;
    end
    f_next.word = r_word;
    f_next.init = |init;
    f_next.drop = (|drop) | timeout;
    f_next.port = ctx.port;  // a CHECK comes a clock or more after its HEADER
  end : _steps

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      ctx   <= '{state: S_PREAMBLE, left: '0, port: '0};
      timer <= '0;
      f     <= '0;
    end
    else begin
      ctx <= ctx_next;
      f   <= f_next;
      if (r_valid != '0 || timeout || ctx.state == S_PREAMBLE) begin
        timer <= '0;
      end
      else begin
        timer <= timer + 1'b1;
      end
    end
  end

  //-----------------------------------------------------------------------
  // 2. data term, and the INIT term on a packet start
  //-----------------------------------------------------------------------
  beat_t       t;
  word_t       t_dterm;
  logic  [1:0] t_n;  // how many words t's CRC slots hold

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      t       <= '0;
      t_dterm <= '0;
      t_n     <= '0;
    end
    else begin
      t <= f;
      t_n <= {1'b0, f.crcd[0]} + {1'b0, f.crcd[1]};
      t_dterm <= serwb_crc_dterm(
          f.word, f.crcd
      ) ^ (f.init ? serwb_crc_iterm(
          {1'b0, f.crcd[0]} + {1'b0, f.crcd[1]}
      ) : '0);
    end
  end

  //-----------------------------------------------------------------------
  // 3. running CRC
  //-----------------------------------------------------------------------
  beat_t g;
  word_t crc, crc_now;  // crc: the running CRC, 0 between packets
  word_t g_crc;  // the CRC over the packet up to and with g's words
  word_t g_rcvd;  // the received CRC, if g has one

  // crc is 0 between packets (cleared at a check or a drop), so a start
  // needs no gating here: its INIT term is in t_dterm
  always_comb begin
    crc_now = serwb_crc_cterm(crc, t_n) ^ t_dterm;
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      crc    <= '0;
      g      <= '0;
      g_crc  <= '0;
      g_rcvd <= '0;
    end
    else begin
      crc    <= (t.chk != '0 || t.drop) ? '0 : crc_now;
      g      <= t;
      g_crc  <= crc_now;
      g_rcvd <= t.chk[0] ? t.word[0] : t.word[1];
    end
  end

  //-----------------------------------------------------------------------
  // 4. check, outputs
  //-----------------------------------------------------------------------
  logic good;

  always_comb begin
    good = (g_rcvd == g_crc);
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      o_word      <= '0;
      o_valid     <= '0;
      o_port      <= '0;
      o_commit    <= 1'b0;
      o_drop      <= 1'b0;
      o_crc_error <= 1'b0;
    end
    else begin
      // compacted, slot 0 first
      o_word[0]   <= g.data[0] ? g.word[0] : g.word[1];
      o_word[1]   <= g.word[1];
      o_valid     <= {g.data[0] & g.data[1], g.data[0] | g.data[1]};

      o_port      <= g.port;
      o_commit    <= (g.chk != '0) && good;
      o_crc_error <= (g.chk != '0) && !good;
      o_drop      <= g.drop || ((g.chk != '0) && !good);
    end
  end

endmodule : iclink_serwb_rx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
