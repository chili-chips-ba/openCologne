// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: Board top for test setup 1: one GateMate EVB (Olimex
// GateMateA1-EVB), its SerDes TX cabled to its own RX.
//
// WORK IN PROGRESS: Etherbone and the eduBOS5 SoC come next; the EVB
// clock, reset and LED stay.
//
// What it does now:
//   - reset synchronizer: the active-low button resets asynchronously and
//     releases synchronously to the clock;
//   - PRBS self-test: PRBS7 TX into the PRBS checker, 20 bits per clock; its
//     error count must not move once the checker has locked;
//   - SerDes link test: the GateMate SerDes PHY (iclink_serdes_gm) sends
//     commas, then PRBS7, out of its TX and back into its RX; once the
//     checker has locked, its error count must not move, and no K
//     character or invalid symbol may arrive;
//   - FIFO pump test: after 2^PRBS_RUN_LOG2 clean PRBS clocks, the FIFO
//     pump (iclink_serwb_pump, SerWB port 2) takes the line. A counter goes
//     into its TX FIFO, and every word out of its RX FIFO must be the next
//     count; no CRC error, drop, overflow or invalid symbol;
//   - LED: blinks (heartbeat) while the link is up and every test passes,
//     stays low after the first error or a link lost once up, until reset.
//
// The PHY, the link tests and the pump run on clk_core. The reset
// synchronizer, the heartbeat, the PRBS self-test, the LED and the PHY
// bring-up run on the board clock clk. rx_ready and tx_ready reset what
// runs on clk_core: they are flops on clk_core, low from reset until the
// SerDes is up, so a lost link restarts the tests.
//
// In simulation the SerDes BFM takes the place of CC_SERDES: its reference
// clock and serial pins are ports of top (tb_top loops them back).
//
// LINE_RATE (Mb/s): 1250, 2500 or 5000, passed to the PHY; a 5 Gb/s build
// needs its clocks constrained at 62.5 MHz (3.build: LINE_RATE=5000).
//
// Pins: 3.build/GateMateA1-EVB.ccf.
//==========================================================================

module top
  import top_pkg::*;
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter int LINE_RATE = 2500
) (
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
  // PRBS self-test: PRBS7 TX -> checker; the count must not move after warm-up
  //-----------------------------------------------------------------------
  logic      [        PRBS_W-1:0] prbs;
  logic      [              31:0] prbs_errors;
  logic      [              31:0] prbs_base;  // the count at the end of warm-up
  logic      [PRBS_WARMUP_LOG2:0] prbs_warm;  // top bit set: warm-up over
  logic                           prbs_error;
  prbs_cfg_t                      NC_prbs_cfg;  // PRBS TX's choice: always PRBS7 here

  iclink_prbs_tx #(
      .WIDTH(PRBS_W)
  ) u_prbs_tx (
      .clk     (clk),
      .arst_n  (rst_n),
      .config_i(PRBS_7),
      .i       ('0),
      .o       (prbs),
      .config_o(NC_prbs_cfg)
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
  // SerDes link test: commas, then PRBS7, then the FIFO pump, TX -> cable
  // -> RX, all on clk_core
  //-----------------------------------------------------------------------
  logic clk_core, tx_ready, rx_ready, rx_aligned;
  phy_ctrl_t link_ctrl;
  phy_word_t link_tx, link_rx;
  logic [    PHY_NWORDS-1:0] link_rx_invalid;
  logic                      link_rx_buf_err;  // the CC_SERDES RX buffer over- or underflowed
  logic [              31:0] link_errors;
  logic [              31:0] link_base;  // the count at the end of warm-up
  logic [  LINK_IDLE_LOG2:0] link_idle;  // on clk_core; top bit set: commas sent, PRBS on
  logic [LINK_WARMUP_LOG2:0] link_warm;  // on clk_core; top bit set: link up
  logic                      link_error;  // on clk_core
  logic link_d_k, link_d_bad, link_d_moved;  // on clk_core: this word's checks, a clock late
  logic       link_kx;  // on clk_core: a K, an invalid symbol or a buffer error, a clock late
  logic [1:0] link_z;  // on clk_core: each half of the word all zero, a clock late
  logic [1:0] link_up_sync, link_error_sync;  // to clk
  logic      [ALIGN_COMMAS_LOG2:0] align_cnt;  // on clk_core; top bit set: alignment done, off
  logic      [    PRBS_RUN_LOG2:0] prbs_run;  // top bit set: PRBS7 over, the pump has the line
  phy_word_t                       pump_tx;
  logic pump_up, pump_error;  // on clk_core
  logic [1:0] pump_up_sync;  // to clk
  // on clk, held until reset: link_error and pump_error clear when rx_ready
  // drops, so the LED keeps them here, and a link lost once it was up too
  logic       link_was_up;
  logic       failed;

  // At 5 Gb/s the pump must run at W = 4 on half clk_core, behind gearboxes
  // (README, FIFO pump); this top has no such clock yet, so its 5 Gb/s
  // build keeps the PRBS7 test running instead
  localparam bit WITH_PUMP = (LINE_RATE < 5000);

  iclink_serdes_gm #(
      .LINE_RATE(LINE_RATE)
  ) u_phy (
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
      .clk_core      (clk_core),
      .tx_ready      (tx_ready),
      .tx            (link_tx),
      .rx_ready      (rx_ready),
      .rx_aligned    (rx_aligned),
      .rx            (link_rx),
      .rx_invalid    (link_rx_invalid),
      .rx_buf_err    (link_rx_buf_err),
      .rx_prbs_errors(link_errors)
  );

  always_ff @(posedge clk_core or negedge tx_ready) begin
    if (!tx_ready) begin
      link_idle <= '0;
    end
    else if (!link_idle[LINK_IDLE_LOG2]) begin
      link_idle <= link_idle + 1'b1;
    end
  end

  // idle until LINK_IDLE_LOG2, then PRBS7 in its place, then the pump
  always_comb begin
    link_tx = prbs_run[PRBS_RUN_LOG2] ? pump_tx : PHY_COMMA_WORD;
    link_ctrl = '{
        tx_prbs: (link_idle[LINK_IDLE_LOG2] && !prbs_run[PRBS_RUN_LOG2]) ? PRBS_7 : PRBS_OFF,
        rx_prbs: PRBS_7,
        rx_prbs_pause: 1'b0,
        rx_align: !align_cnt[ALIGN_COMMAS_LOG2]  // off once aligned; on again after rx_ready
    };
  end

  // comma alignment: on from rx_ready until 2^ALIGN_COMMAS_LOG2 comma words
  // have come in aligned, then off, so a line error cannot move the word
  // boundary; a lost link (rx_ready low) turns it on again
  always_ff @(posedge clk_core or negedge rx_ready) begin
    if (!rx_ready) begin
      align_cnt <= '0;
    end
    else if (!align_cnt[ALIGN_COMMAS_LOG2] && rx_aligned && link_rx.k[0]
             && link_rx.d[0] == PHY_COMMA) begin
      align_cnt <= align_cnt + 1'b1;
    end
  end

  // the checker locks on the first PRBS words (no K): then the count must
  // not move, and no K, invalid symbol or all-zero word (a dead link: PRBS7
  // never has more than 6 zeros in a row) may arrive. Each word's checks
  // are flops first: the wide compares get a clock (the zero check two).
  // After 2^PRBS_RUN_LOG2 clean clocks the pump takes the line, and these
  // checks stop: its fill and control words are K characters
  always_ff @(posedge clk_core or negedge rx_ready) begin
    if (!rx_ready) begin
      link_d_k     <= 1'b0;
      link_kx      <= 1'b0;
      link_z       <= '0;
      link_d_bad   <= 1'b0;
      link_d_moved <= 1'b0;
      link_warm    <= '0;
      link_base    <= '0;
      link_error   <= 1'b0;
      prbs_run     <= '0;
    end
    else begin
      link_d_k     <= rx_aligned && link_rx.k == '0;
      link_kx      <= link_rx.k != '0 || link_rx_invalid != '0 || link_rx_buf_err;
      link_z[1]    <= link_rx.d[PHY_NWORDS-1:PHY_NWORDS/2] == '0;
      link_z[0]    <= link_rx.d[PHY_NWORDS/2-1:0] == '0;
      link_d_bad   <= link_kx || (&link_z);
      link_d_moved <= link_errors != link_base;
      if (!link_warm[LINK_WARMUP_LOG2]) begin
        // a K-free word that is not all zero: the RX buffer hands out zero
        // words for a while after alignment, before the commas come through
        link_warm <= (link_d_k && !(&link_z)) ? link_warm + 1'b1 : '0;
        link_base <= link_errors;
      end
      else if (!prbs_run[PRBS_RUN_LOG2]) begin
        prbs_run <= prbs_run + WITH_PUMP;  // without the pump: PRBS7 on and on
        if (link_d_moved || link_d_bad) begin
          link_error <= 1'b1;
        end
      end
    end
  end

  //-----------------------------------------------------------------------
  // FIFO pump on the looped-back link: a counter goes in, every word that
  // comes out must be the next count. Its XOFF loops back too, so it would
  // pause itself; the reader never stops, so it does not. The pump sends
  // commas for 2^PUMP_START_LOG2 clocks first, while the last PRBS words
  // leave the line, then data. Error: a wrong word, a CRC error, a drop,
  // an overflow or an invalid symbol; up: 2^PUMP_UP_LOG2 words checked
  //-----------------------------------------------------------------------
  if (WITH_PUMP) begin : g_pump
    logic [PUMP_START_LOG2:0] pump_start;  // top bit set: the pump sends and takes data
    word_t pump_wdata, pump_rdata, pump_expect;
    logic pump_full, pump_empty, pump_pop;
    logic                  pump_bad;  // a wrong word or an invalid symbol, a clock late
    logic [PUMP_UP_LOG2:0] pump_good;  // words checked; top bit set: pump up
    serwb_cnt_t pump_crc, pump_drops, pump_ovf;
    logic [$clog2(PUMP_DEPTH):0] NC_tx_used, NC_rx_avail;  // unused: the checker pops what comes
    logic NC_remote_paused, NC_pause;  // flow control: on, but the reader never stops

    iclink_serwb_pump #(
        .W    (2),
        .DEPTH(PUMP_DEPTH)
    ) u_pump (
        .clk          (clk_core),
        .arst_n       (rx_ready),
        .tx_push      (pump_start[PUMP_START_LOG2]),
        .tx_data      (pump_wdata),
        .tx_full      (pump_full),
        .tx_used      (NC_tx_used),
        .tx_hold      (1'b0),
        .rx_pop       (pump_pop),
        .rx_data      (pump_rdata),
        .rx_empty     (pump_empty),
        .rx_avail     (NC_rx_avail),
        .tx_en        (pump_start[PUMP_START_LOG2]),
        .phy_tx       (pump_tx),
        .rx_en        (pump_start[PUMP_START_LOG2]),
        .phy_rx       (link_rx),
        .remote_paused(NC_remote_paused),
        .pause        (NC_pause),
        .crc_errors   (pump_crc),
        .drops        (pump_drops),
        .overflows    (pump_ovf)
    );

    always_comb begin
      pump_pop = !pump_empty;
      pump_up  = pump_good[PUMP_UP_LOG2];
    end

    always_ff @(posedge clk_core or negedge rx_ready) begin
      if (!rx_ready) begin
        pump_start  <= '0;
        pump_wdata  <= '0;
        pump_expect <= '0;
        pump_good   <= '0;
        pump_bad    <= 1'b0;
        pump_error  <= 1'b0;
      end
      else begin
        if (prbs_run[PRBS_RUN_LOG2] && !pump_start[PUMP_START_LOG2]) begin
          pump_start <= pump_start + 1'b1;
        end
        if (pump_start[PUMP_START_LOG2] && !pump_full) begin
          pump_wdata <= pump_wdata + 1'b1;
        end
        if (pump_pop) begin
          pump_expect <= pump_expect + 1'b1;
          if (!pump_good[PUMP_UP_LOG2]) begin
            pump_good <= pump_good + 1'b1;
          end
        end
        pump_bad <= (pump_pop && pump_rdata != pump_expect)
          || (pump_start[PUMP_START_LOG2] && (link_rx_invalid != '0 || link_rx_buf_err));
        if (pump_bad || pump_crc != '0 || pump_drops != '0 || pump_ovf != '0) begin
          pump_error <= 1'b1;
        end
      end
    end
  end : g_pump
  else begin : g_no_pump
    always_comb begin
      pump_tx    = PHY_COMMA_WORD;  // never on the line: prbs_run stays low
      pump_up    = 1'b1;
      pump_error = 1'b0;
    end
  end : g_no_pump

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      link_up_sync    <= '0;
      link_error_sync <= '0;
      pump_up_sync    <= '0;
      link_was_up     <= 1'b0;
      failed          <= 1'b0;
    end
    else begin
      link_up_sync    <= {link_up_sync[0], link_warm[LINK_WARMUP_LOG2]};
      link_error_sync <= {link_error_sync[0], link_error | pump_error};
      pump_up_sync    <= {pump_up_sync[0], pump_up};
      link_was_up     <= link_was_up | link_up_sync[1];
      failed          <= failed | link_error_sync[1] | (link_was_up & !link_up_sync[1]);
    end
  end

  always_comb begin
    led = heartbeat[HEARTBEAT_W-1] & !prbs_error & link_up_sync[1] & pump_up_sync[1] & !failed;
  end

endmodule : top

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
