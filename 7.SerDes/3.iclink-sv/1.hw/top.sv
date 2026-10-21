// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: Board top for test setup 1: one GateMate EVB (Olimex
// GateMateA1-EVB), its SerDes TX cabled to its own RX.
//
// WORK IN PROGRESS: the GateMate CC_SERDES PHY and the eduBOS5 SoC come
// next; the EVB clock, reset and LED stay.
//
// What it does now:
//   - reset synchronizer: the active-low button resets asynchronously and
//     releases synchronously to the clock;
//   - 8b/10b self-test: the IC Link encoder and decoder, back to back in the
//     fabric (no SerDes yet). A counter with a K28.5 comma goes in, and what
//     comes out is compared with it;
//   - LED: blinks (heartbeat) while the self-test passes, stays low after
//     the first mismatch, until reset.
//
// Pins: 3.build/GateMateA1-EVB.ccf.
//==========================================================================

module top
  import top_pkg::*;
(
    input  logic clk,    // CLK0: 10 MHz EVB oscillator
    input  logic btn_n,  // FPGA_BUT: user button, low when pressed, used as reset
    output logic led     // FPGA_LED: heartbeat; low after a self-test error
);
  import iclink_pkg::*;

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

  always_comb begin
    led = heartbeat[HEARTBEAT_W-1] & !st_error;
  end

endmodule : top

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
