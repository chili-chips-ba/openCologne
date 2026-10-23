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
// packetizer until a K28.4.
//
// RX drops: a bad CRC, a timeout, an oversized header (depacketizer), a
// port other than PORT, and a packet that found the RX FIFO full (counted
// as an overflow; flow control keeps it from happening).
//
// Clocks: sys (CPU side of both FIFOs), clk_tx (TX FIFO read, packetizer,
// line), clk_rx (depacketizer, RX FIFO write). The counters and pause are
// on clk_rx, remote_paused on clk_tx.
//==========================================================================
module iclink_serwb_pump
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter  int         W            = 2,               // words a line clock: 2 or 4
    parameter  int         DEPTH        = 1024,            // words, each FIFO
    parameter  int         PKT_WORDS    = 16,
    parameter  int         MAX_WORDS    = 16,              // largest payload accepted
    parameter  logic [7:0] PORT         = 8'd2,
    parameter  int         FLUSH_CLKS   = 64,
    parameter  int         XOFF_LEVEL   = DEPTH - 64 * W,  // the margin covers the words in flight
    parameter  int         XON_LEVEL    = DEPTH / 2,
    parameter  int         REFRESH_CLKS = 1024,
    parameter  int         TIMEOUT_CLKS = 31250,           // 1 ms at 31.25 MHz
    localparam int         AW           = $clog2(DEPTH),
    localparam int         TW           = $clog2(W + 1),
    localparam int         NP           = W / 2            // PHY words a line clock
) (
    // CPU side
    input  logic         clk_sys,
    input  logic         sys_arst_n,
    input  logic         tx_push,
    input  word_t        tx_data,
    output logic         tx_full,
    output logic  [AW:0] tx_used,
    input  logic         tx_hold,     // CTRL.tx_hold: no new packet starts
    input  logic         rx_pop,
    output word_t        rx_data,
    output logic         rx_empty,
    output logic  [AW:0] rx_avail,

    // line side
    input  logic               clk_tx,
    input  logic               tx_arst_n,
    input  logic               tx_en,      // link up: data; else commas
    output phy_word_t [NP-1:0] phy_tx,     // [0] first on the line
    input  logic               clk_rx,
    input  logic               rx_arst_n,
    input  logic               rx_en,      // link up: words are taken
    input  phy_word_t [NP-1:0] phy_rx,

    // status
    output logic        remote_paused,  // on clk_tx: the far side sent XOFF
    output logic        pause,          // on clk_rx: we ask the far side to pause
    output logic [15:0] crc_errors,     // on clk_rx, all three
    output logic [15:0] drops,
    output logic [15:0] overflows
);

  localparam word_t       WORD_FILL = {24'h0, 8'h3C};  // K28.1
  localparam word_t       WORD_XOFF = {24'h0, 8'h7C};  // K28.3
  localparam word_t       WORD_XON  = {24'h0, 8'h9C};  // K28.4
  localparam logic  [7:0] K28_5     = 8'hBC;

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
      .w_clk   (clk_sys),
      .w_arst_n(sys_arst_n),
      .w_word  ((W * 32)'(tx_data)),
      .w_valid (W'(tx_push & !tx_full)),
      .w_commit(1'b0),
      .w_rewind(1'b0),
      .w_used  (tx_used),
      .r_clk   (clk_tx),
      .r_arst_n(tx_arst_n),
      .r_word  (txf_word),
      .r_take  (txf_take),
      .r_avail (txf_avail)
  );

  assign tx_full = (tx_used == (AW + 1)'(DEPTH));

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
  logic [                   1:0] hold_sync;  // tx_hold, from clk_sys
  logic hdr_ready, pk_ready;
  word_t [W-1:0] pk_word;
  logic  [W-1:0] pk_valid;

  always_comb begin
    free = txf_avail - pend;
  end

  always_ff @(posedge clk_tx or negedge tx_arst_n) begin
    if (!tx_arst_n) begin
      tx_state  <= T_WAIT;
      tx_words  <= '0;
      pend      <= '0;
      flush_cnt <= '0;
      hold_sync <= '0;
    end
    else begin
      hold_sync <= {hold_sync[0], tx_hold};
      pend      <= pend + ((tx_state == T_HDR && hdr_ready) ? (AW + 1)'(tx_words) : '0) -
          (AW + 1)'(txf_take);

      unique case (tx_state)
        T_WAIT: begin
          if (hold_sync[1]) begin
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
      .clk      (clk_tx),
      .arst_n   (tx_arst_n),
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
  logic [1:0] pause_sync, remote_sync;  // from clk_rx
  logic pause_d, pending, send_ctrl;
  logic      [$clog2(REFRESH_CLKS)-1:0] refresh_cnt;
  logic                                 remote_paused_rx;  // on clk_rx
  phy_word_t [                  NP-1:0] line;  // into phy_tx
  word_t     [                   W-1:0] ln_word;
  logic      [                   W-1:0] ln_k;

  always_comb begin
    send_ctrl = tx_en & pending;
    pk_ready  = tx_en & !pending & !remote_paused;
  end

  always_ff @(posedge clk_tx or negedge tx_arst_n) begin
    if (!tx_arst_n) begin
      pause_sync    <= '0;
      remote_sync   <= '0;
      pause_d       <= 1'b0;
      pending       <= 1'b0;
      refresh_cnt   <= '0;
      remote_paused <= 1'b0;
      phy_tx        <= '0;
    end
    else begin
      pause_sync    <= {pause_sync[0], pause};
      remote_sync   <= {remote_sync[0], remote_paused_rx};
      remote_paused <= remote_sync[1];
      pause_d       <= pause_sync[1];

      if (!tx_en) begin
        pending     <= 1'b0;
        refresh_cnt <= '0;
      end
      else if (pause_sync[1] != pause_d || refresh_cnt == '1) begin
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
      if (!tx_en) begin
        ln_word[s] = '0;
      end
      else if (send_ctrl) begin
        ln_word[s] = (s == 0) ? (pause_sync[1] ? WORD_XOFF : WORD_XON) : WORD_FILL;
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
      line[s/2].k[4*(s%2)] = tx_en && ln_k[s];
    end
    if (!tx_en) begin
      for (int p = 0; p < NP; p++) begin
        line[p].d[0] = K28_5;  // link not up: a comma in lane 0, as the PHY test sends
        line[p].k[0] = 1'b1;
      end
    end
  end

  //=======================================================================
  // RX: K filter, depacketizer, FIFO
  //=======================================================================
  localparam int DW = $clog2(W / 2 + 1);

  word_t [W-1:0] rx_word, dp_word, NC_rx_word;  // NC_: the reader takes one word a clock
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
      .clk        (clk_rx),
      .arst_n     (rx_arst_n),
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
      .w_clk   (clk_rx),
      .w_arst_n(rx_arst_n),
      .w_word  (dp_word),
      .w_valid (rxf_valid),
      .w_commit(keep),
      .w_rewind((dp_commit && !keep) || dp_rewind),
      .w_used  (rxf_used),
      .r_clk   (clk_sys),
      .r_arst_n(sys_arst_n),
      .r_word  (NC_rx_word),
      .r_take  (TW'(rx_pop & !rx_empty)),
      .r_avail (rx_avail)
  );

  assign rx_data  = NC_rx_word[0];
  assign rx_empty = (rx_avail == '0);

  always_ff @(posedge clk_rx or negedge rx_arst_n) begin
    if (!rx_arst_n) begin
      ovf_pkt          <= 1'b0;
      pause            <= 1'b0;
      remote_paused_rx <= 1'b0;
      crc_errors       <= '0;
      drops            <= '0;
      overflows        <= '0;
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
        remote_paused_rx <= 1'b0;
      end
      else if (ctrl_seen) begin
        remote_paused_rx <= ctrl_xoff;
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
