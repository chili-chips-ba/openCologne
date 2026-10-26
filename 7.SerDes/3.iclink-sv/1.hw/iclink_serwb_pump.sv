// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// FIFO pump: a message link between two CPUs over Serial Wishbone port 2,
// W SerWB words per line clock: W = 2 on the 64-bit PHY clock, W = 4 at
// half that clock, through a 2:1 gearbox (iclink_gearbox), for 5 Gb/s.
//
//   sys    -> TX FIFO ==> scheduler -> packetizer -> line mux -> phy_tx
//   phy_rx -> K filter -> depacketizer -> RX FIFO (commit / rewind) ==> sys
//
// Packets: PKT_WORDS words once that many wait, or what waits after
// FLUSH_CLKS clocks. tx_hold (CTRL.tx_hold) keeps a new packet from
// starting, so the TX FIFO can fill and then go out at line rate; a packet
// already started ends first. On the line between packets: K28.1 fill,
// held or not. Flow control as LiteICLink's FlowControl
// (serwb/datapath.py): the RX FIFO at XOFF_LEVEL words or more asks the far
// side to pause (K28.3), below XON_LEVEL to resume (K28.4); the request
// takes one clock from the packetizer, even in the middle of a packet, and
// is sent again every REFRESH_CLKS. A K28.3 from the far side holds the
// packetizer until a K28.4, mid-packet too: while we ask for a pause, the
// depacketizer's timeout waits, so a long pause drops nothing.
//
// XOFF_LEVEL leaves room for the words still coming after XOFF: the round
// trip of the request (RT_CLKS pump clocks: both directions through the
// PHYs and CC_SERDES, the packetizer and depacketizer pipelines), W words
// a clock. RT_CLKS = 96 leaves a margin over what tb_serwb_pump measures.
//
// RX drops: a bad CRC, a timeout, an oversized header (depacketizer), a
// port other than PORT, and a packet that found the RX FIFO full. That
// last one counts in drops and in overflows; flow control keeps it from
// happening.
//
// Link down (tx_en low): comma words, K28.5 in lane 0 and K28.0 in lane
// 4, so the far side's K filter takes no word from them.
//
// Clock correction, for two boards on two oscillators: every CLKCOR_CLKS
// clocks the line carries a burst of CC_PHY PHY words, a fill word and
// then clock-correction words (iclink_phy_pkg: PHY_CLKCOR_WORD), even in
// the middle of a packet, which waits. The far side's CC_SERDES RX buffer
// removes one of two correction words in a row, or repeats the word
// before a correction word. The fill word in front keeps that from ever
// being a data word. Three correction words leave two whole ones in a row
// at the far end even when its comma sits in lane 4 and each PHY word
// arrives split over two. The far side's K filter drops all of them.
// 40 ppm between boards is one word in 25,000; one burst every 1024
// clocks costs 0.4% of the line.
//
// One clock: the CPU, both FIFOs, the packetizer, the depacketizer and
// the line all run on clk, the PHY clock (W = 2) or half of it (W = 4).
// The PHY's RX comes out on that clock too, through the CC_SERDES RX
// buffer, so the FIFOs are synchronous and no signal crosses a clock.
//==========================================================================
module iclink_serwb_pump
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter int W = 2,  // words a line clock: 2 or 4
    parameter int DEPTH = 1024,  // words, each FIFO
    parameter int PKT_WORDS = 16,
    parameter int MAX_WORDS = 16,  // largest payload accepted
    parameter logic [7:0] PORT = 8'd2,
    parameter int FLUSH_CLKS = 64,
    parameter int RT_CLKS = 96,  // XOFF round trip, pump clocks
    parameter int XOFF_LEVEL = DEPTH - RT_CLKS * W,
    parameter int XON_LEVEL = DEPTH / 2,
    parameter int REFRESH_CLKS = 1024,
    parameter int CLKCOR_CLKS = 1024,  // a clock-correction burst
    parameter int TIMEOUT_CLKS = 31250,  // 1 ms at 31.25 MHz
    localparam int AW = $clog2(DEPTH),
    localparam int TW = $clog2(W + 1),
    localparam int NP = W / 2,  // PHY words a line clock
    localparam int CC_PHY = 4,  // PHY words a clock-correction burst
    localparam int CC_CLKS = CC_PHY / NP  // its clocks
) (
    input logic clk,
    input logic arst_n,

    // CPU side
    input  logic         tx_push,
    input  word_t        tx_data,
    output logic         tx_full,
    output logic  [AW:0] tx_used,
    input  logic         tx_hold,   // CTRL.tx_hold: no new packet starts
    input  logic         rx_pop,
    output word_t        rx_data,
    output logic         rx_empty,
    output logic  [AW:0] rx_avail,

    // line side
    input  logic               tx_en,   // link up: data; else commas
    output phy_word_t [NP-1:0] phy_tx,  // [0] first on the line
    input  logic               rx_en,   // link up: words are taken
    input  phy_word_t [NP-1:0] phy_rx,

    // status
    output logic        remote_paused,  // the far side sent XOFF
    output logic        pause,          // we ask the far side to pause
    output logic [15:0] crc_errors,
    output logic [15:0] drops,
    output logic [15:0] overflows
);

  localparam word_t WORD_FILL = {24'h0, 8'h3C};  // K28.1
  localparam word_t WORD_XOFF = {24'h0, 8'h7C};  // K28.3
  localparam word_t WORD_XON  = {24'h0, 8'h9C};  // K28.4

  if (!(W inside {2, 4}) || (DEPTH & (DEPTH - 1)) != 0) begin : g_bad_w
    $error("iclink_serwb_pump: W %0d (2 or 4), DEPTH %0d (a power of 2)", W, DEPTH);
  end : g_bad_w
  if (PKT_WORDS < 1 || PKT_WORDS > MAX_WORDS || MAX_WORDS > 16383) begin : g_bad_pkt
    $error(
        "iclink_serwb_pump: 1 <= PKT_WORDS %0d <= MAX_WORDS %0d (the far side's) <= 16383",
        PKT_WORDS,
        MAX_WORDS
    );
  end : g_bad_pkt
  if (!(XON_LEVEL > 0 && XON_LEVEL < XOFF_LEVEL && XOFF_LEVEL <= DEPTH - W)) begin : g_bad_lvl
    $error(
        "iclink_serwb_pump: 0 < XON_LEVEL %0d < XOFF_LEVEL %0d <= DEPTH - W", XON_LEVEL, XOFF_LEVEL
    );
  end : g_bad_lvl
  if (FLUSH_CLKS < 2 || (FLUSH_CLKS & (FLUSH_CLKS - 1)) != 0 || REFRESH_CLKS < 2 ||
      (REFRESH_CLKS & (REFRESH_CLKS - 1)) != 0) begin : g_bad_clks
    $error(
        "iclink_serwb_pump: FLUSH_CLKS %0d and REFRESH_CLKS %0d: powers of 2, 2 or more",
        FLUSH_CLKS,
        REFRESH_CLKS
    );
  end : g_bad_clks
  if (CLKCOR_CLKS < 2 * CC_CLKS || (CLKCOR_CLKS & (CLKCOR_CLKS - 1)) != 0) begin : g_bad_clkcor
    $error(
        "iclink_serwb_pump: CLKCOR_CLKS %0d: a power of 2, %0d or more", CLKCOR_CLKS, 2 * CC_CLKS
    );
  end : g_bad_clkcor

  //=======================================================================
  // TX: FIFO, scheduler, packetizer, line
  //=======================================================================
  word_t [ W-1:0] txf_word;
  logic  [TW-1:0] txf_take;
  logic  [  AW:0] txf_avail;

  iclink_serwb_fifo #(
      .DEPTH (DEPTH),
      .W     (W),
      .WN    (1),
      .COMMIT(1'b0)
  ) u_tx_fifo (
      .clk     (clk),
      .arst_n  (arst_n),
      .w_word  (tx_data),
      .w_valid (tx_push & !tx_full),
      .w_commit(1'b0),
      .w_rewind(1'b0),
      .w_used  (tx_used),
      .r_word  (txf_word),
      .r_take  (txf_take),
      .r_avail (txf_avail)
  );

  assign tx_full = (tx_used >= (AW + 1)'(DEPTH));

  // scheduler: a packet of PKT_WORDS, or of what waits after FLUSH_CLKS.
  // The packetizer takes a packet's words from the FIFO as it sends them;
  // pend counts the ones it was given and has not taken yet, so the next
  // header can wait ready while a packet is still going out
  typedef enum logic {
    T_WAIT,
    T_HDR
  } tx_state_t;

  tx_state_t        tx_state;
  logic      [13:0] tx_words;  // the next packet's word count
  logic [AW:0] pend, free;  // free: words in the FIFO for the next packet
  logic [$clog2(FLUSH_CLKS)-1:0] flush_cnt;
  logic hdr_ready, pk_ready;
  word_t [W-1:0] pk_word;
  logic  [W-1:0] pk_valid;

  always_comb begin
    free = txf_avail - pend;
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      tx_state  <= T_WAIT;
      tx_words  <= '0;
      pend      <= '0;
      flush_cnt <= '0;
    end
    else begin
      pend <= pend + ((tx_state == T_HDR && hdr_ready) ? (AW + 1)'(tx_words) : '0) -
          (AW + 1)'(txf_take);

      unique case (tx_state)
        T_WAIT: begin
          if (tx_hold) begin
            flush_cnt <= '0;
          end
          else if (free >= (AW + 1)'(PKT_WORDS)) begin
            tx_words  <= 14'(PKT_WORDS);
            tx_state  <= T_HDR;
            flush_cnt <= '0;
          end
          else if (free != '0 && flush_cnt == '1) begin
            tx_words  <= 14'(free);
            tx_state  <= T_HDR;
            flush_cnt <= '0;
          end
          else if (free != '0) begin
            flush_cnt <= flush_cnt + 1'b1;
          end
          else begin
            flush_cnt <= '0;
          end
        end

        T_HDR: begin
          if (hdr_ready) begin
            tx_state <= T_WAIT;
          end
        end
      endcase
    end
  end

  iclink_serwb_tx #(
      .W(W)
  ) u_packetizer (
      .clk      (clk),
      .arst_n   (arst_n),
      .hdr_valid(tx_state == T_HDR),
      .hdr_port (PORT),
      .hdr_words(tx_words),
      .hdr_ready(hdr_ready),
      .d_word   (txf_word),
      .d_take   (txf_take),
      .o_word   (pk_word),
      .o_valid  (pk_valid),
      .o_ready  (pk_ready)
  );

  // flow control requests: on a change of pause, and every REFRESH_CLKS
  logic pause_d, pending, send_ctrl;
  logic      [$clog2(REFRESH_CLKS)-1:0] refresh_cnt;
  phy_word_t [                  NP-1:0] line;  // into phy_tx
  word_t     [                   W-1:0] ln_word;
  logic      [                   W-1:0] ln_k;

  // clock correction: a burst every CLKCOR_CLKS clocks, CC_CLKS clocks long
  logic      [ $clog2(CLKCOR_CLKS)-1:0] cc_cnt;
  logic                                 cc_on;  // the burst is on the line
  logic      [     $clog2(CC_CLKS)-1:0] cc_idx;  // its clock

  always_comb begin
    send_ctrl = tx_en & pending & !cc_on;
    pk_ready  = tx_en & !pending & !cc_on & !remote_paused;
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      cc_cnt <= '0;
      cc_on  <= 1'b0;
      cc_idx <= '0;
    end
    else if (!tx_en) begin
      cc_cnt <= '0;
      cc_on  <= 1'b0;
      cc_idx <= '0;
    end
    else begin
      cc_cnt <= cc_cnt + 1'b1;
      if (cc_cnt == '1) begin
        cc_on <= 1'b1;
      end
      else if (cc_on && cc_idx == ($clog2(CC_CLKS))'(CC_CLKS - 1)) begin
        cc_on <= 1'b0;
      end
      cc_idx <= cc_on ? cc_idx + 1'b1 : '0;
    end
  end

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      pause_d     <= 1'b0;
      pending     <= 1'b0;
      refresh_cnt <= '0;
      phy_tx      <= '0;
    end
    else begin
      pause_d <= pause;

      if (!tx_en) begin
        pending     <= 1'b0;
        refresh_cnt <= '0;
      end
      else if (pause != pause_d || refresh_cnt == '1) begin
        pending     <= 1'b1;
        refresh_cnt <= '0;
      end
      else if (send_ctrl) begin
        pending <= 1'b0;
      end
      else begin
        refresh_cnt <= refresh_cnt + 1'b1;
      end

      phy_tx <= line;
    end
  end

  // the line: slot s = bytes 0-3 (s even) or 4-7 (s odd) of PHY word s / 2,
  // byte 0 first
  always_comb begin
    line    = '0;
    ln_word = '0;
    ln_k    = '0;
    for (int s = 0; s < W; s++) begin
      ln_k[s] = 1'b1;
      if (!tx_en) begin  // link not up: K28.5 in lane 0, K28.0 in lane 4
        ln_word[s] = {24'h0, (s % 2 == 0) ? PHY_COMMA : PHY_IDLE};
      end
      else if (cc_on) begin  // the burst's first PHY word; the others below
        ln_word[s] = WORD_FILL;
      end
      else if (send_ctrl) begin
        ln_word[s] = (s == 0) ? (pause ? WORD_XOFF : WORD_XON) : WORD_FILL;
      end
      else if (pk_ready && pk_valid[s]) begin
        ln_word[s] = pk_word[s];
        ln_k[s]    = 1'b0;
      end
      else begin
        ln_word[s] = WORD_FILL;
      end
      for (int b = 0; b < 4; b++) begin
        line[s/2].d[4*(s%2)+b] = ln_word[s][8*b+:8];
      end
      line[s/2].k[4*(s%2)] = ln_k[s];
    end
    // the burst: a fill word first, then clock-correction words
    for (int p = 0; p < NP; p++) begin
      if (tx_en && cc_on && (cc_idx != '0 || p != 0)) begin
        line[p] = PHY_CLKCOR_WORD;
      end
    end
  end

  //=======================================================================
  // RX: K filter, depacketizer, FIFO
  //=======================================================================
  localparam int DW = $clog2(W / 2 + 1);

  word_t [W-1:0] rx_word, dp_word;
  logic [W-1:0] rx_valid, dp_valid, rxf_valid;
  logic [W-1:0] is_xoff, is_xon;
  logic [7:0] dp_port;
  logic dp_commit, dp_rewind, dp_crc_error;
  logic [DW-1:0] dp_drop;
  logic [  AW:0] rxf_used;
  logic room, ovf, ovf_pkt, keep, ctrl_seen, ctrl_xoff;

  // a data word has no K flag; K28.1 fill, XON / XOFF and commas are not data
  always_comb begin
    ctrl_seen = 1'b0;
    ctrl_xoff = 1'b0;
    for (int s = 0; s < W; s++) begin
      for (int b = 0; b < 4; b++) begin
        rx_word[s][8*b+:8] = phy_rx[s/2].d[4*(s%2)+b];
      end
      rx_valid[s] = rx_en && (phy_rx[s/2].k[4*(s%2)+:4] == 4'b0000);
      is_xoff[s]  = rx_en && (phy_rx[s/2].k[4*(s%2)+:4] == 4'b0001) && (rx_word[s] == WORD_XOFF);
      is_xon[s]   = rx_en && (phy_rx[s/2].k[4*(s%2)+:4] == 4'b0001) && (rx_word[s] == WORD_XON);
      if (is_xoff[s] || is_xon[s]) begin  // the later slot wins
        ctrl_seen = 1'b1;
        ctrl_xoff = is_xoff[s];
      end
    end
  end

  iclink_serwb_rx #(
      .W           (W),
      .MAX_WORDS   (MAX_WORDS),
      .TIMEOUT_CLKS(TIMEOUT_CLKS)
  ) u_depacketizer (
      .clk        (clk),
      .arst_n     (arst_n),
      .i_hold     (pause),        // we asked the far side to pause: no timeout
      .i_word     (rx_word),
      .i_valid    (rx_valid),
      .o_word     (dp_word),
      .o_valid    (dp_valid),
      .o_port     (dp_port),
      .o_commit   (dp_commit),
      .o_rewind   (dp_rewind),
      .o_drop     (dp_drop),
      .o_crc_error(dp_crc_error)
  );

  // a packet that finds no room writes nothing more and is rewound at its end
  always_comb begin
    room      = rxf_used <= (AW + 1)'(DEPTH - W);  // a flop and a compare: off the write path
    ovf       = ovf_pkt | (dp_valid != '0 && !room);
    rxf_valid = ovf ? '0 : dp_valid;
    keep      = dp_commit && !ovf && dp_port == PORT;
  end

  iclink_serwb_fifo #(
      .DEPTH (DEPTH),
      .W     (W),
      .RN    (1),
      .COMMIT(1'b1)
  ) u_rx_fifo (
      .clk     (clk),
      .arst_n  (arst_n),
      .w_word  (dp_word),
      .w_valid (rxf_valid),
      .w_commit(keep),
      .w_rewind((dp_commit && !keep) || dp_rewind),
      .w_used  (rxf_used),
      .r_word  (rx_data),
      .r_take  (TW'(rx_pop & !rx_empty)),
      .r_avail (rx_avail)
  );

  assign rx_empty = (rx_avail == '0);

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      ovf_pkt       <= 1'b0;
      pause         <= 1'b0;
      remote_paused <= 1'b0;
      crc_errors    <= '0;
      drops         <= '0;
      overflows     <= '0;
    end
    else begin
      ovf_pkt <= ovf && !(dp_commit || dp_rewind);

      if (rxf_used >= (AW + 1)'(XOFF_LEVEL)) begin
        pause <= 1'b1;
      end
      else if (rxf_used < (AW + 1)'(XON_LEVEL)) begin
        pause <= 1'b0;
      end

      if (!rx_en) begin
        remote_paused <= 1'b0;
      end
      else if (ctrl_seen) begin
        remote_paused <= ctrl_xoff;
      end

      crc_errors <= crc_errors + 16'(dp_crc_error);
      drops      <= drops + 16'(dp_drop) + 16'(dp_commit && !keep);
      overflows  <= overflows + 16'(dp_commit && ovf);
    end
  end

endmodule : iclink_serwb_pump

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
