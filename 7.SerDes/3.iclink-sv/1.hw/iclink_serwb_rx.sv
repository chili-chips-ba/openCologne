// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerWB depacketizer, W words per clock (2 or 4): LiteICLink's
// CRCDepacketizer (liteiclink/serwb/packet.py). The same state machine,
// stepped W times per clock, slot 0 (bytes 0-3) first:
//
//   PREAMBLE  wait for 0x5AA55AA5; any other word is dropped
//   HEADER    port / length; 0 words or more than MAX_WORDS: drop
//   DATA      the payload words, into the CRC and out on o_*
//   CHECK     the CRC32 word: o_commit if it matches, else o_crc_error
//
// A packet may start in any slot and may have gaps (i_valid low, a K symbol
// on the line) anywhere. The data words go out compacted, slot 0 first
// (o_valid 0, 1, 3, 7 ..), as soon as they arrive; o_commit, or o_rewind,
// then ends the packet, so the RX FIFO keeps or drops what it took. This
// replaces LiteICLink's store-and-forward buffer: the FIFO is the buffer.
//
// One packet ends per clock at most (a packet is 4 words or more). With
// W = 4, the next packet's header and first data word can share the clock
// with that end (A, then B, below). A commit covers all of a clock's words,
// so B's words wait a clock in a carry register and go out with B's next
// ones; B's own end comes with a CRC slot, which makes room for them. B
// follows A's CRC and its own preamble, so its header is in slot 2 or
// later and its data in slot 3 or later: at most W - 3 words to carry. The
// framing masks the slots B cannot use, so synthesis drops their logic.
//
// Five stages: input flops; framing (the state machine, no CRC); the data
// terms of the beat's words; the running CRC; the check and the outputs.
// The CRC is linear, so the data terms need no running CRC, and the CRC
// loop is one shallow XOR tree (iclink_serwb_pkg). Every output comes out
// of the last stage, so words, commits and drops keep their order.
//
// Timeout as LiteICLink: TIMEOUT_CLKS clocks without a word in DATA or
// CHECK drops the packet.
//==========================================================================
module iclink_serwb_rx
  import iclink_serwb_pkg::*;
#(
    parameter  int W            = 2,                 // words a clock: 2 or 4
    parameter  int MAX_WORDS    = 16,
    parameter  int TIMEOUT_CLKS = 31250,             // 1 ms at 31.25 MHz
    localparam int DW           = $clog2(W / 2 + 1)  // a count of the drops in one clock
) (
    input logic clk,
    input logic arst_n,

    input word_t [W-1:0] i_word,
    input logic  [W-1:0] i_valid,

    output word_t [ W-1:0] o_word,
    output logic  [ W-1:0] o_valid,
    output logic  [   7:0] o_port,
    output logic           o_commit,
    output logic           o_rewind,    // drop this packet's words: a CRC error or a timeout
    output logic  [DW-1:0] o_drop,      // packets dropped, CRC errors included
    output logic           o_crc_error
);

  localparam int CW = (W > 3) ? W - 3 : 0;  // B's data words in A's last beat, at most
  localparam int CWD = (CW > 0) ? CW : 1;  // the carry register, declared
  localparam bit CARRY = CW > 0;  // with W = 2, B has no data in A's last beat
  localparam logic [W-1:0] B_CRCD = ~W'(3);  // slots B's CRC can cover: 2 ..
  localparam logic [W-1:0] B_DATA = ~W'(7);  // slots B's data can be in: 3 ..

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

  // what a stage carries for one beat. Packet A: the one open at the start
  // of the beat, or the first to start in it. Packet B: one that starts
  // after A's CRC, in the same beat.
  typedef struct packed {
    word_t [W-1:0] word;
    logic [W-1:0]  data;   // A's payload words, to the FIFO
    logic [W-1:0]  crcd;   // slots A's CRC covers: port / length and data
    logic [W-1:0]  chk;    // the slot with A's received CRC
    logic          init;   // A's header is in this beat: its CRC starts here
    logic [W-1:0]  bdata;  // B's payload words
    logic [W-1:0]  bcrcd;  // slots B's CRC covers
    logic          binit;  // B's header is in this beat
    logic [DW-1:0] drops;  // headers out of range, a timeout
    logic          tmo;    // the timeout: A's words are dropped
    logic [7:0]    port;   // A's
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

  // the data term of the covered words of one packet in a beat, each by how
  // many covered words follow it (as in iclink_serwb_tx)
  function automatic word_t dterm(input word_t [W-1:0] w, input logic [W-1:0] cov);
    word_t       d;
    logic  [1:0] k;
    d = '0;
    k = '0;
    for (int j = W - 1; j >= 0; j--) begin
      if (cov[j]) begin
        d = d ^ serwb_crc_mterm(w[j], k);
        k = k + 1'b1;
      end
    end
    return d;
  endfunction

  function automatic logic [2:0] count(input logic [W-1:0] v);
    logic [2:0] n;
    n = '0;
    for (int j = 0; j < W; j++) begin
      n = n + 3'(v[j]);
    end
    return n;
  endfunction

  //-----------------------------------------------------------------------
  // 0. input flops
  //-----------------------------------------------------------------------
  word_t [W-1:0] r_word;
  logic  [W-1:0] r_valid;

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
  ctx_t ctx, c, ctx_next;
  beat_t f_next, f;
  logic s_data, s_crcd, s_chk, s_init, s_drop;  // one step's results
  logic                              ended;  // A's CRC has passed, in this beat
  logic                              timeout;
  logic [$clog2(TIMEOUT_CLKS+1)-1:0] timer;  // clocks without a word, inside a packet

  always_comb begin : _steps
    c        = ctx;
    ctx_next = ctx;
    f_next   = '0;
    ended    = 1'b0;
    s_data   = 1'b0;
    s_crcd   = 1'b0;
    s_chk    = 1'b0;
    s_init   = 1'b0;
    s_drop   = 1'b0;
    for (int s = 0; s < W; s++) begin
      if (r_valid[s]) begin
        if (!ended && c.state == S_CHECK) begin
          f_next.port = c.port;
        end
        step(c, r_word[s], c, s_data, s_crcd, s_chk, s_init, s_drop);
        f_next.drops = f_next.drops + DW'(s_drop);
        if (!ended) begin
          f_next.data[s] = s_data;
          f_next.crcd[s] = s_crcd;
          f_next.chk[s]  = s_chk;
          f_next.init    = f_next.init | s_init;
          ended          = s_chk;
        end
        else begin
          f_next.bdata[s] = s_data;
          f_next.bcrcd[s] = s_crcd;
          f_next.binit    = f_next.binit | s_init;
        end
      end
    end
    // as LiteICLink, the timer drops in DATA and CHECK only, never in HEADER
    timeout = (r_valid == '0) && (ctx.state inside {S_DATA, S_CHECK}) &&
        (timer == $bits(timer)'(TIMEOUT_CLKS - 1));
    ctx_next = c;
    if (timeout) begin
      ctx_next.state = S_PREAMBLE;
      f_next.drops   = DW'(1);
      f_next.tmo     = 1'b1;
    end
    f_next.word  = r_word;
    f_next.bdata = f_next.bdata & B_DATA;
    f_next.bcrcd = f_next.bcrcd & B_CRCD;
    f_next.binit = f_next.binit & CARRY;
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
  // 2. data terms of A and B, with the INIT term on a start
  //-----------------------------------------------------------------------
  beat_t       t;
  word_t       t_dterm;  // A's
  logic  [2:0] t_n;  // how many words A's CRC slots hold
  word_t       t_bcrc;  // B's CRC after this beat: B starts here, so it is all data term

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      t       <= '0;
      t_dterm <= '0;
      t_n     <= '0;
      t_bcrc  <= '0;
    end
    else begin
      t       <= f;
      t_n     <= count(f.crcd);
      t_dterm <= dterm(f.word, f.crcd) ^ (f.init ? serwb_crc_iterm(count(f.crcd)) : '0);
      t_bcrc  <= CARRY ? (dterm(f.word, f.bcrcd) ^ serwb_crc_iterm(count(f.bcrcd))) : '0;
    end
  end

  //-----------------------------------------------------------------------
  // 3. running CRC
  //-----------------------------------------------------------------------
  beat_t g;
  word_t crc, crc_now;  // crc: the running CRC, 0 between packets
  word_t g_crc;  // A's CRC up to and with g's words
  word_t g_rcvd;  // A's received CRC, if g has one

  // crc is 0 between packets (cleared at a check or a timeout), so a start
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
      if (t.chk != '0) begin
        crc <= t.binit ? t_bcrc : '0;
      end
      else begin
        crc <= t.tmo ? '0 : crc_now;
      end
      g     <= t;
      g_crc <= crc_now;
      for (int s = 0; s < W; s++) begin
        if (t.chk[s]) begin
          g_rcvd <= t.word[s];
        end
      end
    end
  end

  //-----------------------------------------------------------------------
  // 4. check, outputs. The queue: the carry, then A's words, compacted;
  // W of them go out. After A's end, B's words become the carry.
  //-----------------------------------------------------------------------
  logic good, bad, ends;
  word_t [          W+CWD-1:0] q;
  logic  [$clog2(W+CWD+1)-1:0] nq;
  word_t [CWD-1:0] bq, carry;
  logic [$clog2(CWD+1)-1:0] nb, ncarry;

  always_comb begin
    good = (g_rcvd == g_crc);
    bad  = (g.chk != '0) && !good;
    ends = (g.chk != '0) || g.tmo;
    q    = '0;
    nq   = '0;
    for (int i = 0; i < CWD; i++) begin
      if (CARRY && 4'(i) < 4'(ncarry)) begin
        q[nq] = carry[i];
        nq    = nq + 1'b1;
      end
    end
    for (int s = 0; s < W; s++) begin
      if (g.data[s]) begin
        q[nq] = g.word[s];
        nq    = nq + 1'b1;
      end
    end
    bq = '0;
    nb = '0;
    for (int s = 0; s < W; s++) begin
      if (g.bdata[s] && 4'(nb) < 4'(CWD)) begin
        bq[nb] = g.word[s];
        nb     = nb + 1'b1;
      end
    end
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      o_word      <= '0;
      o_valid     <= '0;
      o_port      <= '0;
      o_commit    <= 1'b0;
      o_rewind    <= 1'b0;
      o_drop      <= '0;
      o_crc_error <= 1'b0;
      carry       <= '0;
      ncarry      <= '0;
    end
    else begin
      o_word <= q[W-1:0];
      for (int i = 0; i < W; i++) begin
        o_valid[i] <= !g.tmo && 4'(i) < 4'(nq);
      end
      o_port      <= g.port;
      o_commit    <= (g.chk != '0) && good;
      o_crc_error <= bad;
      o_rewind    <= bad || g.tmo;
      o_drop      <= g.drops + DW'(bad);
      if (CARRY) begin
        if (ends) begin
          carry  <= bq;
          ncarry <= nb;
        end
        else begin
          carry  <= q[W+:CWD];
          ncarry <= (nq > $bits(nq)'(W)) ? $bits(ncarry)'(nq - $bits(nq)'(W)) : '0;
        end
      end
    end
  end

endmodule : iclink_serwb_rx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
