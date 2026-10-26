// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// FIFO pump: a message link between two CPUs over Serial Wishbone port 2,
// W SerWB words per pump clock: W = 2, one 64-bit PHY word a clock; W = 4,
// two PHY words every other clock, for 5 Gb/s.
//
//   CPU    -> TX FIFO ==> scheduler -> packetizer -> line mux -> phy_tx
//   phy_rx -> K filter -> depacketizer -> RX FIFO (commit / rewind) ==> CPU
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
// Clock correction: every PHY_CLKCOR_EVERY PHY words, a burst of
// PHY_CLKCOR_BURST words PHY_CLKCOR_WORD (iclink_phy_pkg), for the far
// side's elastic buffer to drop or repeat one. It takes the line as a flow
// control request does, mid-packet too, and goes first. All K: the far
// side's K filter drops it, and whatever the buffer did to it.
//
// XOFF_LEVEL leaves room for the words still coming after XOFF: the round
// trip of the request (RT_CLKS pump clocks: both directions through the
// PHYs and CC_SERDES, the packetizer and depacketizer pipelines), W words
// a clock. The PHY takes 31 to 37 PHY clocks each way on the SerDes BFM at
// 2.5 Gb/s, 29 to 35 at 5 Gb/s (the RX elastic buffer's fill moves with the
// ppm): half as many pump clocks at W = 4. RT_CLKS = 96 leaves a margin:
// tb_serwb_pump, at the worst latency, sees +82 words after XOFF of 192 at
// W = 2, +96 of 384 at W = 4.
//
// RX drops: a bad CRC, a timeout, an oversized header (depacketizer), a
// port other than PORT, and a packet that found the RX FIFO full. That
// last one counts in drops and in overflows; flow control keeps it from
// happening.
//
// Link down (tx_en low): comma words, K28.5 in lane 0 and K28.0 in lane
// 4, so the far side's K filter takes no word from them. No clock
// correction then: only commas while the far side aligns.
//
// Clock: one, clk (the PHY's PLL_CLK_O), and one reset, released on clk
// here. The CPU side moves every clock. The pump core (scheduler,
// packetizer, line mux, K filter, depacketizer, counters, the FIFOs' line
// sides) moves on clocks with ce: always (W = 2), or every other clock
// (W = 4, from a toggle flop), with a 2:1 / 1:2 gearbox (iclink_gearbox)
// to one PHY word a clock.
//
// MCP set (W = 4): every flop that loads only on ce. From one to another
// is a 2-clock path: set_multicycle_path 2 (setup) / 1 (hold), -from and
// -to this set. It is:
//   u_packetizer, u_depacketizer   all flops
//   u_tx_fifo                      read side: rd_ptr, r_avail, q (RAM out)
//   u_rx_fifo                      write side: ram_we, ram_row, ram_d,
//                                  wr_ptr, com_ptr, w_used
//   g_gear.u_rx_gear               r_word
//   here                           tx_state, tx_words, pend, flush_cnt,
//                                  pause_d, pending, refresh_cnt, cc_cnt,
//                                  cc_left, line_q, remote_paused, ovf_pkt,
//                                  pause, crc_errors, drops, overflows
// In the netlist: the flops whose enable cone holds g_ce.ce_q. Paths into
// the set from the CPU side, the PHY or ce_q stay 1-clock, as do paths out
// of it to them. Upstream nextpnr (GateMate) has no multicycle constraint
// yet: it times the set at the full clock.
//==========================================================================
module iclink_serwb_pump
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter  int         W            = 2,                    // words a pump clock: 2 or 4
    parameter  int         DEPTH        = 1024,                 // words, each FIFO
    parameter  int         PKT_WORDS    = 16,
    parameter  int         MAX_WORDS    = 16,                   // largest payload accepted
    parameter  logic [7:0] PORT         = 8'd2,
    parameter  int         FLUSH_CLKS   = 64,
    parameter  int         RT_CLKS      = 96,                   // XOFF round trip, pump clocks
    parameter  int         XOFF_LEVEL   = DEPTH - RT_CLKS * W,
    parameter  int         XON_LEVEL    = DEPTH / 2,
    parameter  int         REFRESH_CLKS = 1024,
    parameter  int         TIMEOUT_CLKS = 31250,                // 1 ms at 31.25 MHz
    localparam int         AW           = $clog2(DEPTH),
    localparam int         TW           = $clog2(W + 1),
    localparam int         NP           = W / 2                 // PHY words a pump clock
) (
    input logic clk,    // the PHY clock (PLL_CLK_O)
    input logic arst_n,

    // CPU side, every clock
    input  logic         tx_push,
    input  word_t        tx_data,
    output logic         tx_full,
    output logic  [AW:0] tx_used,
    input  logic         tx_hold,   // CTRL.tx_hold: no new packet starts
    input  logic         rx_pop,
    output word_t        rx_data,
    output logic         rx_empty,
    output logic  [AW:0] rx_avail,

    // line side, a PHY word a clock
    input  logic      tx_en,   // link up: data; else commas
    output phy_word_t phy_tx,
    input  logic      rx_en,   // link up: words are taken
    input  phy_word_t phy_rx,

    // status, on pump clocks
    output logic        remote_paused,  // the far side sent XOFF
    output logic        pause,          // we ask the far side to pause
    output logic [15:0] crc_errors,
    output logic [15:0] drops,
    output logic [15:0] overflows
);

  localparam word_t WORD_FILL = {24'h0, 8'h3C};         // K28.1
  localparam word_t WORD_XOFF = {24'h0, 8'h7C};         // K28.3
  localparam word_t WORD_XON  = {24'h0, 8'h9C};         // K28.4
  localparam int    CC_EVERY  = PHY_CLKCOR_EVERY / NP;  // pump clocks
  localparam int    CC_BURST  = PHY_CLKCOR_BURST / NP;

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
  if (CC_EVERY < 2 || (CC_EVERY & (CC_EVERY - 1)) != 0 || CC_BURST < 1 ||
      CC_BURST * NP != PHY_CLKCOR_BURST) begin : g_bad_cc
    $error(
        "iclink_serwb_pump: PHY_CLKCOR_EVERY %0d (a power of 2), PHY_CLKCOR_BURST %0d (of %0d)",
        PHY_CLKCOR_EVERY,
        PHY_CLKCOR_BURST,
        NP
    );
  end : g_bad_cc

  //=======================================================================
  // reset and strobe
  //=======================================================================
  logic rst_meta, rst_n;  // arst_n, released on clk
  logic ce;  // the pump core moves

  always_ff @(posedge clk or negedge arst_n) begin
    if (!arst_n) begin
      rst_meta <= 1'b0;
      rst_n    <= 1'b0;
    end
    else begin
      rst_meta <= 1'b1;
      rst_n    <= rst_meta;
    end
  end

  if (W == 4) begin : g_ce
    logic ce_q;  // high every other clock

    always_ff @(posedge clk or negedge rst_n) begin
      if (!rst_n) begin
        ce_q <= 1'b0;
      end
      else begin
        ce_q <= ~ce_q;
      end
    end

    assign ce = ce_q;
  end : g_ce
  else begin : g_no_ce
    assign ce = 1'b1;
  end : g_no_ce

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
      .arst_n  (rst_n),
      .w_ce    (1'b1),
      .w_word  ((W * 32)'(tx_data)),
      .w_valid (W'(tx_push & !tx_full)),
      .w_commit(1'b0),
      .w_rewind(1'b0),
      .w_used  (tx_used),
      .r_ce    (ce),
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

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      tx_state  <= T_WAIT;
      tx_words  <= '0;
      pend      <= '0;
      flush_cnt <= '0;
    end
    else if (ce) begin
      pend <= pend + ((tx_state == T_HDR && hdr_ready) ? (AW + 1)'(tx_words) : '0) -
          (AW + 1)'(txf_take);

      case (tx_state)
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

        default: begin
          tx_state <= T_WAIT;
        end
      endcase
    end
  end

  iclink_serwb_tx #(
      .W(W)
  ) u_packetizer (
      .clk      (clk),
      .arst_n   (rst_n),
      .ce       (ce),
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

  // the line's turns: clock correction, then flow control requests (on a
  // change of pause, and every REFRESH_CLKS), then the packetizer
  logic pause_d, pending, send_ctrl, send_cc;
  logic [$clog2(REFRESH_CLKS)-1:0] refresh_cnt;
  logic [    $clog2(CC_EVERY)-1:0] cc_cnt;
  logic [  $clog2(CC_BURST+1)-1:0] cc_left;  // clock-correction words to send
  phy_word_t [NP-1:0] line, line_q;  // into phy_tx
  word_t [W-1:0] ln_word;
  logic  [W-1:0] ln_k;

  always_comb begin
    send_cc   = tx_en & (cc_left != '0);
    send_ctrl = tx_en & !send_cc & pending;
    pk_ready  = tx_en & !send_cc & !pending & !remote_paused;
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      pause_d     <= 1'b0;
      pending     <= 1'b0;
      refresh_cnt <= '0;
      cc_cnt      <= '0;
      cc_left     <= '0;
      line_q      <= '0;
    end
    else if (ce) begin
      pause_d <= pause;
      cc_cnt  <= cc_cnt + 1'b1;

      if (cc_cnt == '1) begin
        cc_left <= ($bits(cc_left))'(CC_BURST);
      end
      else if (cc_left != '0) begin
        cc_left <= cc_left - 1'b1;
      end

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

      line_q <= line;
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
    if (send_cc) begin
      line = {NP{PHY_CLKCOR_WORD}};
    end
  end

  //=======================================================================
  // RX: K filter, depacketizer, FIFO
  //=======================================================================
  localparam int DW = $clog2(W / 2 + 1);

  phy_word_t [NP-1:0] rx_line;  // on pump clocks
  word_t [W-1:0] rx_word, dp_word, NC_rx_word;  // NC_: the reader takes one word a clock
  logic [W-1:0] rx_valid, dp_valid, rxf_valid;
  logic [W-1:0] is_xoff, is_xon;
  logic [7:0] dp_port;
  logic dp_commit, dp_rewind, dp_crc_error;
  logic [DW-1:0] dp_drop;
  logic [  AW:0] rxf_used;
  logic room, ovf, ovf_pkt, keep, ctrl_seen, ctrl_xoff;

  // the PHY side: direct (W = 2), or through the gearboxes (W = 4)
  if (W == 4) begin : g_gear
    iclink_gearbox #(
        .IN_N (2),
        .OUT_N(1)
    ) u_tx_gear (
        .clk   (clk),
        .arst_n(rst_n),
        .ce    (ce),
        .w_word(line_q),
        .r_word(phy_tx)
    );

    iclink_gearbox #(
        .IN_N (1),
        .OUT_N(2)
    ) u_rx_gear (
        .clk   (clk),
        .arst_n(rst_n),
        .ce    (ce),
        .w_word(phy_rx),
        .r_word(rx_line)
    );
  end : g_gear
  else begin : g_direct
    assign phy_tx  = line_q;
    assign rx_line = phy_rx;
  end : g_direct

  // a data word has no K flag; K28.1 fill, XON / XOFF, clock correction
  // and commas are not data
  always_comb begin
    ctrl_seen = 1'b0;
    ctrl_xoff = 1'b0;
    for (int s = 0; s < W; s++) begin
      for (int b = 0; b < 4; b++) begin
        rx_word[s][8*b+:8] = rx_line[s/2].d[4*(s%2)+b];
      end
      rx_valid[s] = rx_en && (rx_line[s/2].k[4*(s%2)+:4] == 4'b0000);
      is_xoff[s]  = rx_en && (rx_line[s/2].k[4*(s%2)+:4] == 4'b0001) && (rx_word[s] == WORD_XOFF);
      is_xon[s]   = rx_en && (rx_line[s/2].k[4*(s%2)+:4] == 4'b0001) && (rx_word[s] == WORD_XON);
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
      .arst_n     (rst_n),
      .ce         (ce),
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
      .arst_n  (rst_n),
      .w_ce    (ce),
      .w_word  (dp_word),
      .w_valid (rxf_valid),
      .w_commit(keep),
      .w_rewind((dp_commit && !keep) || dp_rewind),
      .w_used  (rxf_used),
      .r_ce    (1'b1),
      .r_word  (NC_rx_word),
      .r_take  (TW'(rx_pop & !rx_empty)),
      .r_avail (rx_avail)
  );

  assign rx_data  = NC_rx_word[0];
  assign rx_empty = (rx_avail == '0);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ovf_pkt       <= 1'b0;
      pause         <= 1'b0;
      remote_paused <= 1'b0;
      crc_errors    <= '0;
      drops         <= '0;
      overflows     <= '0;
    end
    else if (ce) begin
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
