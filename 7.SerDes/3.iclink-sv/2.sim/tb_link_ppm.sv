// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Clock correction between two boards (test setup 2): two sides, each the
// GateMate SerDes PHY on its own SerDes BFM and a FIFO pump, serial lines
// crossed. Each side has its own SerDes reference: B's runs PPM slower
// than A's, so A's words reach B faster than B reads them, and B's reach
// A slower. Only the CC_SERDES RX buffers' clock correction, fed by the
// pumps' clock-correction bursts, keeps the link up:
//
//   1. both PHYs come up and align on commas; then the pumps run;
//   2. RUN_CLKS clocks of a counter each way, at the full CPU rate;
//   3. pass: every word arrives, in order; no CRC error, drop, overflow,
//      invalid symbol or RX buffer error; B's buffer removed correction
//      words and A's inserted them (counted in the BFMs).
//
// Without clock correction (+define+NO_CLKCOR: the pumps send no bursts)
// the RX buffers run over and under, and the test must fail.
//==========================================================================
module tb_link_ppm
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter int  LINE_RATE = 2500,    // Mb/s
    parameter real PPM       = 200.0,   // B's reference slower than A's
    parameter int  RUN_CLKS  = 100000   // clocks of traffic
);

  logic clk_ref_a, clk_ref_b, clk_reg, arst_n;
  logic a_txp, a_txn, b_txp, b_txn;
  logic link;  // the pumps run: data, fill, flow control, clock correction
  logic run;  // the CPUs push words

  initial begin : _clk_ref_a
    clk_ref_a = 1'b0;
    forever #5 clk_ref_a = ~clk_ref_a;  // 100 MHz
  end : _clk_ref_a

  initial begin : _clk_ref_b
    clk_ref_b = 1'b0;
    forever #(5.0 * (1.0 + PPM * 1.0e-6)) clk_ref_b = ~clk_ref_b;
  end : _clk_ref_b

  initial begin : _clk_reg
    clk_reg = 1'b0;
    forever #50 clk_reg = ~clk_reg;  // 10 MHz, the board clock
  end : _clk_reg

  link_side #(
      .LINE_RATE(LINE_RATE),
      .DIR      (1'b0)
  ) u_a (
      .clk_ref(clk_ref_a),
      .clk_reg(clk_reg),
      .arst_n (arst_n),
      .ser_rxp(b_txp),
      .ser_rxn(b_txn),
      .ser_txp(a_txp),
      .ser_txn(a_txn),
      .link   (link),
      .run    (run)
  );

  link_side #(
      .LINE_RATE(LINE_RATE),
      .DIR      (1'b1)
  ) u_b (
      .clk_ref(clk_ref_b),
      .clk_reg(clk_reg),
      .arst_n (arst_n),
      .ser_rxp(a_txp),
      .ser_rxn(a_txn),
      .ser_txp(b_txp),
      .ser_txn(b_txn),
      .link   (link),
      .run    (run)
  );

  initial begin : _run
    int errors;
    errors = 0;
    link   = 1'b0;
    run    = 1'b0;
    arst_n = 1'b0;
    #200;
    arst_n = 1'b1;
    wait (u_a.align_done && u_b.align_done);
    // link and run change on a falling edge: no race with the clocked logic
    repeat (64) @(negedge u_a.clk_core);
    link = 1'b1;
    repeat (64) @(negedge u_a.clk_core);
    run = 1'b1;
    repeat (RUN_CLKS) @(negedge u_a.clk_core);
    run = 1'b0;  // no new words; what is in flight drains
    repeat (4000) @(posedge u_a.clk_core);

    $display("A->B: %0d sent, %0d received, %0d wrong; B->A: %0d sent, %0d received, %0d wrong",
             u_a.sent, u_b.got, u_b.bad, u_b.sent, u_a.got, u_a.bad);
    $display("A RX buffer: %0d insertions, %0d removals; B RX buffer: %0d insertions, %0d removals",
             u_a.ins, u_a.rem, u_b.ins, u_b.rem);
    $display("A: crc %0d drops %0d ovf %0d invalid %0d buf_err %0d; B: crc %0d drops %0d ovf %0d invalid %0d buf_err %0d",
             u_a.crc, u_a.drops, u_a.ovf, u_a.invalid, u_a.buf_errs, u_b.crc, u_b.drops, u_b.ovf,
             u_b.invalid, u_b.buf_errs);
    if (u_b.got != u_a.sent || u_a.got != u_b.sent || u_a.bad != 0 || u_b.bad != 0) begin
      errors++;
      $display("ERROR: words lost or wrong");
    end
    if ((u_a.crc | u_a.drops | u_a.ovf | u_b.crc | u_b.drops | u_b.ovf) != 0 ||
        u_a.invalid != 0 || u_b.invalid != 0 || u_a.buf_errs != 0 || u_b.buf_errs != 0) begin
      errors++;
      $display("ERROR: link errors");
    end
    if (PPM != 0.0 && (u_b.rem == 0 || u_a.ins == 0)) begin
      errors++;
      $display("ERROR: no clock correction seen: the test proves nothing");
    end
    $display("TB_LINK_PPM: %s  %0.0f ppm, %0d clocks", (errors == 0) ? "PASS" : "FAIL", PPM,
             RUN_CLKS);
    $finish;
  end : _run

  initial begin : _watchdog
    #20ms;
    $display("TB_LINK_PPM: FAIL  timeout");
    $finish;
  end : _watchdog

endmodule : tb_link_ppm

// One side: the PHY on its BFM, the FIFO pump on clk_core, a counter into
// the pump, a checker out of it. Comma alignment as the board top does it.
module link_side
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;
#(
    parameter int LINE_RATE = 2500,
    parameter bit DIR       = 1'b0   // which way: the counter pattern
) (
    input  logic clk_ref,
    input  logic clk_reg,
    input  logic arst_n,
    input  logic ser_rxp,
    input  logic ser_rxn,
    output logic ser_txp,
    output logic ser_txn,
    input  logic link,
    input  logic run
);
  logic clk_core, tx_ready, rx_ready, rx_aligned, rx_buf_err;
  phy_word_t tx, rx;
  phy_ctrl_t ctrl;
  logic [PHY_NWORDS-1:0] rx_invalid;
  logic [31:0] NC_prbs;
  logic [4:0] align_cnt;
  logic align_done;
  logic full, empty, NC_paused, NC_pause;
  word_t rdata;
  logic [10:0] NC_used, NC_avail;
  logic [15:0] crc, drops, ovf;
  int sent, got, bad, invalid, buf_errs, ins, rem;

  initial begin : _counts
    sent     = 0;
    got      = 0;
    bad      = 0;
    invalid  = 0;
    buf_errs = 0;
    ins      = 0;
    rem      = 0;
  end : _counts

  function automatic word_t pattern(input logic dir, input int n);
    return word_t'(n * 32'h9E37_79B1) ^ (dir ? 32'hB0B0_0000 : 32'hA0A0_0000);
  endfunction

  iclink_serdes_gm #(
      .LINE_RATE(LINE_RATE)
  ) u_phy (
      .clk_ref       (clk_ref),
      .ser_rxp       (ser_rxp),
      .ser_rxn       (ser_rxn),
      .ser_txp       (ser_txp),
      .ser_txn       (ser_txn),
      .clk_reg       (clk_reg),
      .arst_n        (arst_n),
      .ctrl          (ctrl),
      .clk_core      (clk_core),
      .tx_ready      (tx_ready),
      .tx            (tx),
      .rx_ready      (rx_ready),
      .rx_aligned    (rx_aligned),
      .rx            (rx),
      .rx_invalid    (rx_invalid),
      .rx_buf_err    (rx_buf_err),
      .rx_prbs_errors(NC_prbs)
  );

  always_comb begin
    ctrl = '{tx_prbs: PRBS_OFF, rx_prbs: PRBS_OFF, rx_prbs_pause: 1'b0, rx_align: !align_done};
  end

  // comma alignment on until 16 aligned commas came in, then off
  initial align_cnt = '0;

  always @(posedge clk_core) begin : _align
    if (!align_cnt[4] && rx_aligned && rx.k[0] && rx.d[0] == PHY_COMMA) begin
      align_cnt <= align_cnt + 1'b1;
    end
  end : _align
  assign align_done = align_cnt[4];

  // NO_CLKCOR, the negative test: the first burst would come after 2^20
  // clocks, long after the run
`ifdef NO_CLKCOR
  localparam int CLKCOR_CLKS = 1 << 20;
`else
  localparam int CLKCOR_CLKS = 1024;
`endif

  iclink_serwb_pump #(
      .W          (2),
      .CLKCOR_CLKS(CLKCOR_CLKS)
  ) u_pump (
      .clk          (clk_core),
      .arst_n       (rx_ready),
      .tx_push      (run && !full),
      .tx_data      (pattern(DIR, sent)),
      .tx_full      (full),
      .tx_used      (NC_used),
      .tx_hold      (1'b0),
      .rx_pop       (!empty),
      .rx_data      (rdata),
      .rx_empty     (empty),
      .rx_avail     (NC_avail),
      .tx_en        (link),
      .phy_tx       (tx),
      .rx_en        (link),
      .phy_rx       (rx),
      .remote_paused(NC_paused),
      .pause        (NC_pause),
      .crc_errors   (crc),
      .drops        (drops),
      .overflows    (ovf)
  );

  always @(posedge clk_core) begin : _check
    if (run && !full) begin
      sent <= sent + 1;
    end
    if (!empty) begin
      if (rdata !== pattern(!DIR, got)) begin
        if (bad < 5) begin
          $display("ERROR: %m: word %0d is %h, should be %h", got, rdata, pattern(!DIR, got));
        end
        bad <= bad + 1;
      end
      got <= got + 1;
    end
    if (link && rx_invalid != '0) begin
      invalid <= invalid + 1;
    end
    if (link && rx_buf_err) begin
      buf_errs <= buf_errs + 1;
    end
  end : _check

  // the BFM's RX buffer: a stalled read repeats a word (insertion), a
  // word not written is a removal; sampled half a clock after the update
  always @(negedge clk_core) begin : _ins
    if (link && !u_phy.u_serdes.eb_r_en) begin
      ins <= ins + 1;
    end
  end : _ins

  always @(negedge u_phy.u_serdes.clk_core_rx_o) begin : _rem
    if (link && !u_phy.u_serdes.eb_w_en) begin
      rem <= rem + 1;
    end
  end : _rem

endmodule : link_side

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
