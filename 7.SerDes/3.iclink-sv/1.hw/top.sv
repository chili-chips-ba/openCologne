// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: Board top for test setup 1: one GateMate EVB (Olimex
// GateMateA1-EVB), its SerDes TX cabled to its own RX.
//
// WORK IN PROGRESS: SerWB and the eduBOS5 SoC come next; the EVB clock,
// reset and LED stay.
//
// What it does now:
//   - reset synchronizer: the active-low button resets asynchronously and
//     releases synchronously to the clock;
//   - 8b/10b self-test: the IC Link encoder and decoder, back to back in the
//     fabric (no SerDes yet). A counter with a K28.5 comma goes in, and what
//     comes out is compared with it;
//   - PRBS self-test: PRBS7 TX into the PRBS checker, 20 bits per clock; its
//     error count must not move once the checker has locked;
//   - SerDes link test: the GateMate SerDes PHY (iclink_serdes_gm) sends
//     commas, then PRBS7, out of its TX and back into its RX; once the
//     checker has locked, its error count must not move, and no K
//     character or invalid symbol may arrive;
//   - LED: blinks (heartbeat) while the link is up and every test passes,
//     stays low after the first error, until reset.
//
// In simulation the SerDes BFM takes the place of CC_SERDES: its reference
// clock and serial pins are ports of top (tb_top loops them back).
//
// Pins: 3.build/GateMateA1-EVB.ccf.
//==========================================================================

module top
  import top_pkg::*;
(
`ifndef SYNTHESIS
    input  logic clk_ref,  // SerDes reference
    input  logic ser_rxp,
    input  logic ser_rxn,
    output logic ser_txp,
    output logic ser_txn,
`endif
    input  logic clk,      // CLK0: 10 MHz EVB oscillator
    input  logic btn_n,    // FPGA_BUT: user button, low when pressed, used as reset
    output logic led       // FPGA_LED: heartbeat; low after a self-test error
);
  import iclink_pkg::*;
  import iclink_phy_pkg::*;

  //-----------------------------------------------------------------------
  // Reset synchronizer: asynchronous assert, synchronous release
  //-----------------------------------------------------------------------
  logic rst_meta;  // first stage, may go metastable on release; read only by rst_n
  logic rst_n;  // the synchronized reset, low = in reset

  always_ff @(posedge clk or negedge btn_n) begin
    if (!btn_n) begin
      rst_meta <= 1'b0;
      rst_n    <= 1'b0;
    end
    else begin
      rst_meta <= 1'b1;
      rst_n    <= rst_meta;
    end
  end

  //-----------------------------------------------------------------------
  // Heartbeat: a free-running counter, its top bit drives the LED
  //-----------------------------------------------------------------------
  logic [HEARTBEAT_W-1:0] heartbeat;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      heartbeat <= '0;
    end
    else begin
      heartbeat <= heartbeat + 1'b1;
    end
  end

  //-----------------------------------------------------------------------
  // 8b/10b self-test: encoder -> decoder, compared with what went in
  //-----------------------------------------------------------------------
  logic    [           7:0]               st_cnt;  // the character counter
  byte_t   [  ST_WORDS-1:0]               tx_d;
  logic    [  ST_WORDS-1:0]               tx_k;
  symbol_t [  ST_WORDS-1:0]               symbol;
  logic    [  ST_WORDS-1:0]               NC_disparity;  // running disparity: not needed here
  byte_t   [  ST_WORDS-1:0]               rx_d;
  logic    [  ST_WORDS-1:0]               rx_k;
  logic    [  ST_WORDS-1:0]               rx_invalid;

  // what went in, ST_LATENCY clocks ago at [0]
  byte_t   [ST_LATENCY-1:0][ST_WORDS-1:0] exp_d;
  logic    [ST_LATENCY-1:0][ST_WORDS-1:0] exp_k;
  logic    [ST_LATENCY-1:0]               exp_vld;
  logic                                   st_error;

  always_comb begin
    tx_k[0] = st_cnt[COMMA_LOG2-1:0] == '0;
    tx_d[0] = tx_k[0] ? K28_5 : st_cnt;
    tx_k[1] = 1'b0;
    tx_d[1] = ~st_cnt;
  end

  iclink_8b10b_enc #(
      .NWORDS(ST_WORDS)
  ) u_enc (
      .clk      (clk),
      .arst_n   (rst_n),
      .ce       (1'b1),
      .d        (tx_d),
      .k        (tx_k),
      .symbol   (symbol),
      .disparity(NC_disparity)
  );

  for (genvar w = 0; w < ST_WORDS; w++) begin : g_dec
    iclink_8b10b_dec u_dec (
        .clk    (clk),
        .arst_n (rst_n),
        .ce     (1'b1),
        .symbol (symbol[w]),
        .d      (rx_d[w]),
        .k      (rx_k[w]),
        .invalid(rx_invalid[w])
    );
  end : g_dec

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st_cnt   <= '0;
      exp_d    <= '0;
      exp_k    <= '0;
      exp_vld  <= '0;
      st_error <= 1'b0;
    end
    else begin
      st_cnt  <= st_cnt + 1'b1;
      exp_d   <= {tx_d, exp_d[ST_LATENCY-1:1]};
      exp_k   <= {tx_k, exp_k[ST_LATENCY-1:1]};
      exp_vld <= {1'b1, exp_vld[ST_LATENCY-1:1]};
      if (exp_vld[0] && (rx_d != exp_d[0] || rx_k != exp_k[0] || rx_invalid != '0)) begin
        st_error <= 1'b1;
      end
    end
  end

  //-----------------------------------------------------------------------
  // PRBS self-test: PRBS7 TX -> checker; the count must not move after warm-up
  //-----------------------------------------------------------------------
  logic [        PRBS_W-1:0] prbs;
  logic [              31:0] prbs_errors;
  logic [              31:0] prbs_base;  // the count at the end of warm-up
  logic [PRBS_WARMUP_LOG2:0] prbs_warm;  // top bit set: warm-up over
  logic                      prbs_error;

  iclink_prbs_tx #(
      .WIDTH(PRBS_W)
  ) u_prbs_tx (
      .clk     (clk),
      .arst_n  (rst_n),
      .config_i(PRBS_7),
      .i       ('0),
      .o       (prbs)
  );

  iclink_prbs_rx #(
      .WIDTH(PRBS_W)
  ) u_prbs_rx (
      .clk     (clk),
      .arst_n  (rst_n),
      .config_i(PRBS_7),
      .pause   (1'b0),
      .i       (prbs),
      .errors  (prbs_errors)
  );

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      prbs_warm  <= '0;
      prbs_base  <= '0;
      prbs_error <= 1'b0;
    end
    else if (!prbs_warm[PRBS_WARMUP_LOG2]) begin
      prbs_warm <= prbs_warm + 1'b1;
      prbs_base <= prbs_errors;
    end
    else if (prbs_errors != prbs_base) begin
      prbs_error <= 1'b1;
    end
  end

  //-----------------------------------------------------------------------
  // SerDes link test: commas, then PRBS7, TX -> cable -> RX
  //-----------------------------------------------------------------------
  logic clk_tx, clk_rx, tx_ready, rx_ready, rx_aligned;
  phy_ctrl_t link_ctrl;
  phy_word_t link_tx, link_rx;
  logic [    PHY_NWORDS-1:0] link_rx_invalid;
  logic [              31:0] link_errors;
  logic [              31:0] link_base;  // the count at the end of warm-up
  logic [  LINK_IDLE_LOG2:0] link_idle;  // on clk_tx; top bit set: commas sent, PRBS on
  logic [LINK_WARMUP_LOG2:0] link_warm;  // on clk_rx; top bit set: link up
  logic                      link_error;  // on clk_rx
  logic [1:0] link_up_sync, link_error_sync;  // to clk

  iclink_serdes_gm u_phy (
`ifndef SYNTHESIS
      .clk_ref       (clk_ref),
      .ser_rxp       (ser_rxp),
      .ser_rxn       (ser_rxn),
      .ser_txp       (ser_txp),
      .ser_txn       (ser_txn),
`endif
      .clk_reg       (clk),
      .arst_n        (rst_n),
      .ctrl          (link_ctrl),
      .clk_tx        (clk_tx),
      .tx_ready      (tx_ready),
      .tx            (link_tx),
      .clk_rx        (clk_rx),
      .rx_ready      (rx_ready),
      .rx_aligned    (rx_aligned),
      .rx            (link_rx),
      .rx_invalid    (link_rx_invalid),
      .rx_prbs_errors(link_errors)
  );

  always_ff @(posedge clk_tx or negedge tx_ready) begin
    if (!tx_ready) begin
      link_idle <= '0;
    end
    else if (!link_idle[LINK_IDLE_LOG2]) begin
      link_idle <= link_idle + 1'b1;
    end
  end

  always_comb begin
    link_tx = '0;
    link_tx.d[0] = K28_5;  // idle: a comma in lane 0; replaced by PRBS7 after LINK_IDLE_LOG2
    link_tx.k[0] = 1'b1;
    link_ctrl = '{
        tx_prbs: link_idle[LINK_IDLE_LOG2] ? PRBS_7 : PRBS_OFF,
        rx_prbs: PRBS_7,
        rx_prbs_pause: 1'b0,
        rx_align: 1'b1
    };
  end

  // the checker locks on the first PRBS words (no K): then the count must
  // not move, and no K, invalid symbol or all-zero word (a dead link: PRBS7
  // never has more than 6 zeros in a row) may arrive
  always_ff @(posedge clk_rx or negedge rx_ready) begin
    if (!rx_ready) begin
      link_warm  <= '0;
      link_base  <= '0;
      link_error <= 1'b0;
    end
    else if (!link_warm[LINK_WARMUP_LOG2]) begin
      link_warm <= (rx_aligned && link_rx.k == '0) ? link_warm + 1'b1 : '0;
      link_base <= link_errors;
    end
    else if (link_errors != link_base || link_rx.k != '0 || link_rx_invalid != '0
             || link_rx.d == '0) begin
      link_error <= 1'b1;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      link_up_sync    <= '0;
      link_error_sync <= '0;
    end
    else begin
      link_up_sync    <= {link_up_sync[0], link_warm[LINK_WARMUP_LOG2]};
      link_error_sync <= {link_error_sync[0], link_error};
    end
  end

  always_comb begin
    led = heartbeat[HEARTBEAT_W-1] & !st_error & !prbs_error & link_up_sync[1]
          & !link_error_sync[1];
  end

endmodule : top

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
