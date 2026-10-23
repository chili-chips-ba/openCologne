// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// FIFO pump: a message link between two CPUs over Serial Wishbone port 2,
// two SerWB words per clock on the 64-bit PHY.
//
//   sys    -> TX FIFO ==> scheduler -> packetizer -> line mux -> phy_tx
//   phy_rx -> K filter -> depacketizer -> RX FIFO (commit / rewind) ==> sys
//
// Packets: PKT_WORDS words once that many wait, or what waits after
// FLUSH_CLKS clocks. tx_hold (CTRL.tx_hold) keeps a new packet from
// starting, so the TX FIFO can fill and then go out at line rate; a packet
// already started ends first. On the line between packets: K28.1 fill,
// held or not. Flow control
// as LiteICLink's FlowControl (serwb/datapath.py): the RX FIFO at XOFF_LEVEL
// words or more asks the far side to pause (K28.3), below XON_LEVEL to
// resume (K28.4); the request takes one clock from the packetizer, even in
// the middle of a packet, and is sent again every REFRESH_CLKS. A K28.3
// from the far side holds the packetizer until a K28.4.
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
    parameter  int         DEPTH        = 1024,          // words, each FIFO
    parameter  int         PKT_WORDS    = 16,
    parameter  int         MAX_WORDS    = 16,            // largest payload accepted
    parameter  logic [7:0] PORT         = 8'd2,
    parameter  int         FLUSH_CLKS   = 64,
    parameter  int         XOFF_LEVEL   = DEPTH - 128,
    parameter  int         XON_LEVEL    = DEPTH / 2,
    parameter  int         REFRESH_CLKS = 1024,
    parameter  int         TIMEOUT_CLKS = 31250,         // 1 ms at 31.25 MHz
    localparam int         AW           = $clog2(DEPTH)
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
    input  logic      clk_tx,
    input  logic      tx_arst_n,
    input  logic      tx_en,      // link up: data; else commas
    output phy_word_t phy_tx,
    input  logic      clk_rx,
    input  logic      rx_arst_n,
    input  logic      rx_en,      // link up: words are taken
    input  phy_word_t phy_rx,

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
  word_t [ 1:0] txf_word;
  logic  [ 1:0] txf_take;
  logic  [AW:0] txf_avail;

  iclink_serwb_fifo #(
      .DEPTH (DEPTH),
      .COMMIT(1'b0)
  ) u_tx_fifo (
      .w_clk   (clk_sys),
      .w_arst_n(sys_arst_n),
      .w_word  ({32'h0, tx_data}),
      .w_valid ({1'b0, tx_push & !tx_full}),
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

  // scheduler: a packet of PKT_WORDS, or of what waits after FLUSH_CLKS
  typedef enum logic [1:0] {
    T_WAIT,
    T_HDR,
    T_DATA
  } tx_state_t;

  tx_state_t tx_state;
  logic [13:0] tx_left;  // words of this packet still to give
  logic tx_left_ge2;  // tx_left >= 2, from a flop: the FIFO read address waits on it
  logic [$clog2(FLUSH_CLKS)-1:0] flush_cnt;
  logic [1:0] hold_sync;  // tx_hold, from clk_sys
  logic hdr_ready, d_ready, pk_ready;
  word_t [1:0] pk_word;
  logic  [1:0] pk_valid;

  always_comb begin
    txf_take = '0;
    if (tx_state == T_DATA && d_ready) begin
      txf_take = tx_left_ge2 ? 2'd2 : 2'd1;
    end
  end

  always_ff @(posedge clk_tx or negedge tx_arst_n) begin
    if (!tx_arst_n) begin
      tx_state    <= T_WAIT;
      tx_left     <= '0;
      tx_left_ge2 <= 1'b0;
      flush_cnt   <= '0;
      hold_sync   <= '0;
    end
    else begin
      hold_sync <= {hold_sync[0], tx_hold};

      unique case (tx_state)
        T_WAIT: begin
          if (hold_sync[1]) begin
            flush_cnt <= '0;
          end
          else if (txf_avail >= (AW + 1)'(PKT_WORDS)) begin
            tx_left     <= 14'(PKT_WORDS);
            tx_left_ge2 <= PKT_WORDS >= 2;
            tx_state    <= T_HDR;
            flush_cnt   <= '0;
          end
          else if (txf_avail != '0 && flush_cnt == '1) begin
            tx_left     <= 14'(txf_avail);
            tx_left_ge2 <= txf_avail >= (AW + 1)'(2);
            tx_state    <= T_HDR;
            flush_cnt   <= '0;
          end
          else if (txf_avail != '0) begin
            flush_cnt <= flush_cnt + 1'b1;
          end
          else begin
            flush_cnt <= '0;
          end
        end

        T_HDR: begin
          if (hdr_ready) begin
            tx_state <= T_DATA;
          end
        end

        T_DATA: begin
          if (d_ready) begin
            tx_left     <= tx_left - 14'(txf_take);
            tx_left_ge2 <= tx_left >= 14'd4;  // 2 go now
            if (!tx_left_ge2 || tx_left == 14'd2) begin
              tx_state <= T_WAIT;
            end
          end
        end

        default: begin
          tx_state <= T_WAIT;
        end
      endcase
    end
  end

  iclink_serwb_tx u_packetizer (
      .clk      (clk_tx),
      .arst_n   (tx_arst_n),
      .hdr_valid(tx_state == T_HDR),
      .hdr_port (PORT),
      .hdr_words(tx_left),
      .hdr_ready(hdr_ready),
      .d_valid  (tx_state == T_DATA),
      .d_word   (txf_word),
      .d_ready  (d_ready),
      .o_word   (pk_word),
      .o_valid  (pk_valid),
      .o_ready  (pk_ready)
  );

  // flow control requests: on a change of pause, and every REFRESH_CLKS
  logic [1:0] pause_sync, remote_sync;  // from clk_rx
  logic pause_d, pending, send_ctrl;
  logic      [$clog2(REFRESH_CLKS)-1:0] refresh_cnt;
  logic                                 remote_paused_rx;  // on clk_rx
  phy_word_t                            line;  // into phy_tx
  word_t     [                     1:0] ln_word;
  logic      [                     1:0] ln_k;

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

  // the line: slot 0 = bytes 0-3, slot 1 = bytes 4-7, byte 0 first
  always_comb begin
    line    = '0;
    ln_word = {WORD_FILL, WORD_FILL};
    ln_k    = 2'b11;
    if (!tx_en) begin
      line.d[0] = K28_5;  // link not up: a comma in lane 0, as the PHY test sends
      line.k[0] = 1'b1;
    end
    else begin
      for (int s = 0; s < 2; s++) begin
        ln_k[s] = 1'b1;
        if (send_ctrl) begin
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
          line.d[4*s+b] = ln_word[s][8*b+:8];
        end
        line.k[4*s] = ln_k[s];
      end
    end
  end

  //=======================================================================
  // RX: K filter, depacketizer, FIFO
  //=======================================================================
  word_t [1:0] rx_word, dp_word;
  logic [1:0] rx_valid, dp_valid, rxf_valid;
  logic [1:0] is_xoff, is_xon;
  logic [7:0] dp_port;
  logic dp_commit, dp_drop, dp_crc_error;
  logic [AW:0] rxf_used;
  logic room, ovf, ovf_pkt, keep;
  word_t NC_rx_word1;  // the reader takes one word a clock

  // a data word has no K flag; K28.1 fill, XON / XOFF and commas are not data
  always_comb begin
    for (int s = 0; s < 2; s++) begin
      for (int b = 0; b < 4; b++) begin
        rx_word[s][8*b+:8] = phy_rx.d[4*s+b];
      end
      rx_valid[s] = rx_en && (phy_rx.k[4*s+:4] == 4'b0000);
      is_xoff[s]  = rx_en && (phy_rx.k[4*s+:4] == 4'b0001) && (rx_word[s] == WORD_XOFF);
      is_xon[s]   = rx_en && (phy_rx.k[4*s+:4] == 4'b0001) && (rx_word[s] == WORD_XON);
    end
  end

  iclink_serwb_rx #(
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
      .o_drop     (dp_drop),
      .o_crc_error(dp_crc_error)
  );

  // a packet that finds no room writes nothing more and is rewound at its end
  always_comb begin
    room      = rxf_used <= (AW + 1)'(DEPTH - 2);  // a flop and a compare: off the write path
    ovf       = ovf_pkt | (dp_valid != '0 && !room);
    rxf_valid = ovf ? 2'b00 : dp_valid;
    keep      = dp_commit && !ovf && dp_port == PORT;
  end

  iclink_serwb_fifo #(
      .DEPTH (DEPTH),
      .COMMIT(1'b1)
  ) u_rx_fifo (
      .w_clk   (clk_rx),
      .w_arst_n(rx_arst_n),
      .w_word  (dp_word),
      .w_valid (rxf_valid),
      .w_commit(keep),
      .w_rewind((dp_commit && !keep) || dp_drop),
      .w_used  (rxf_used),
      .r_clk   (clk_sys),
      .r_arst_n(sys_arst_n),
      .r_word  ({NC_rx_word1, rx_data}),
      .r_take  ({1'b0, rx_pop & !rx_empty}),
      .r_avail (rx_avail)
  );

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
      ovf_pkt <= ovf && !(dp_commit || dp_drop);

      if (rxf_used >= (AW + 1)'(XOFF_LEVEL)) begin
        pause <= 1'b1;
      end
      else if (rxf_used < (AW + 1)'(XON_LEVEL)) begin
        pause <= 1'b0;
      end

      if (!rx_en) begin
        remote_paused_rx <= 1'b0;
      end
      else if (is_xoff[1] || (is_xoff[0] && !is_xon[1])) begin  // the later slot wins
        remote_paused_rx <= 1'b1;
      end
      else if (is_xon[1] || is_xon[0]) begin
        remote_paused_rx <= 1'b0;
      end

      crc_errors <= crc_errors + 16'(dp_crc_error);
      drops      <= drops + 16'(dp_drop || (dp_commit && !keep));
      overflows  <= overflows + 16'(dp_commit && ovf);
    end
  end

endmodule : iclink_serwb_pump

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
