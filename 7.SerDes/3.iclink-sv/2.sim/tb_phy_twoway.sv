// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// PHY test, two ways (test setup 2 at the PHY level): two GateMate SerDes
// PHYs, each on its own SerDes BFM, the serial lines crossed (TX of A to RX
// of B, TX of B to RX of A).
//   1. bring-up of both: PLL, TX and RX ready, comma alignment acquired;
//   2. data both ways at once: a counter stream with K28.5 commas and
//      clock-correction bursts, a different one per side, each checked word
//      for word on the other side (8 bytes + 8 K flags), the correction
//      words skipped: bit-exact, no invalid symbol;
//   3. one serial bit flipped on the A->B line: B must see it, A must not;
//   4. PRBS both ways at once (A sends PRBS15, B sends PRBS31): 0 errors,
//      then a flip on B->A is counted by A only;
//   5. RX_BUF_ERR_O never set on either side.
//
// PPM_A, PPM_B: each side's reference clock off 100 MHz, in ppm (+ is
// faster). With PPM_A != PPM_B the PRBS run of step 4 lasts PPM_CLOCKS, and
// the RX elastic buffers must correct: the faster side inserts correction
// words (its far end writes slower than it reads), the slower one removes
// them. Both are counted in the BFMs; with |PPM_A - PPM_B| >= 100 both must
// have happened. The buffers' fill range is reported: the RX latency moves
// with it, one clock a word.
`timescale 1ns / 100fs

module tb_phy_twoway
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter int LINE_RATE     = 2500,                                     // Mb/s: 1250, 2500 or 5000
    parameter bit TX_HARD_8B10B = (LINE_RATE >= 5000),
    parameter int PPM_A         = 0,
    parameter int PPM_B         = 0,
    // PRBS clocks of step 4 with distinct clocks: 40000, or 8 words of drift
    parameter int PPM_CLOCKS    = (PPM_A == PPM_B) ? 1000 :
        ((8000000 / ((PPM_A > PPM_B) ? PPM_A - PPM_B : PPM_B - PPM_A) > 40000) ?
         8000000 / ((PPM_A > PPM_B) ? PPM_A - PPM_B : PPM_B - PPM_A) : 40000)
);

  localparam int DATA_WORDS = 2000;  // words checked per side in step 2
  localparam int SEED_A = 0;  // the A stream; B's differs
  localparam int SEED_B = 101;
  localparam int DPPM = (PPM_A > PPM_B) ? PPM_A - PPM_B : PPM_B - PPM_A;
  localparam real CORE_NS = 80000.0 / LINE_RATE;

  logic clk_ref_a, clk_ref_b, clk_reg, arst_n;
  logic a_txp, a_txn, b_txp, b_txn;  // serial TX of each side
  logic flip_ab, flip_ba;  // invert a line while high
  logic send, check;
  phy_ctrl_t ctrl_a, ctrl_b;
  int errors = 0;

  initial begin : _waves
    if ($test$plusargs("waves")) begin
      $dumpfile("phy_twoway.fst");  // make sim_phy_twoway WAVES=1
      $dumpvars(0, tb_phy_twoway);
    end
  end : _waves

  // 100 MHz SerDes references, each PPM off; on the 100 fs grid, exact for
  // a ppm that is a multiple of 20
  initial begin : _clk_ref_a
    clk_ref_a = 1'b0;
    forever #(5.0 * (1.0 - PPM_A * 1.0e-6)) clk_ref_a = ~clk_ref_a;
  end : _clk_ref_a

  initial begin : _clk_ref_b
    clk_ref_b = 1'b0;
    forever #(5.0 * (1.0 - PPM_B * 1.0e-6)) clk_ref_b = ~clk_ref_b;
  end : _clk_ref_b

  initial begin : _clk_reg
    clk_reg = 1'b0;
    forever #50 clk_reg = ~clk_reg;  // 10 MHz, the board clock
  end : _clk_reg

  phy_side #(
      .LINE_RATE    (LINE_RATE),
      .TX_HARD_8B10B(TX_HARD_8B10B),
      .SEED_TX      (SEED_A),
      .SEED_RX      (SEED_B)
  ) u_a (
      .clk_ref(clk_ref_a),
      .clk_reg(clk_reg),
      .arst_n (arst_n),
      .ser_rxp(b_txp ^ flip_ba),
      .ser_rxn(b_txn ^ flip_ba),
      .ser_txp(a_txp),
      .ser_txn(a_txn),
      .ctrl   (ctrl_a),
      .send   (send),
      .check  (check)
  );

  phy_side #(
      .LINE_RATE    (LINE_RATE),
      .TX_HARD_8B10B(TX_HARD_8B10B),
      .SEED_TX      (SEED_B),
      .SEED_RX      (SEED_A)
  ) u_b (
      .clk_ref(clk_ref_b),
      .clk_reg(clk_reg),
      .arst_n (arst_n),
      .ser_rxp(a_txp ^ flip_ab),
      .ser_rxn(a_txn ^ flip_ab),
      .ser_txp(b_txp),
      .ser_txn(b_txn),
      .ctrl   (ctrl_b),
      .send   (send),
      .check  (check)
  );

  task automatic flip_line(bit ab);
    @(posedge u_a.clk);
    #3.1;  // somewhere inside a word
    if (ab) flip_ab = 1'b1;
    else flip_ba = 1'b1;
    #(1000.0 / LINE_RATE);  // one UI
    flip_ab = 1'b0;
    flip_ba = 1'b0;
  endtask

  initial begin
    logic [31:0] base_a, base_b;
    int ins_a, ins_b, rem_a, rem_b;
    $timeformat(-6, 2, " us", 0);
    arst_n  = 1'b0;
    flip_ab = 1'b0;
    flip_ba = 1'b0;
    send    = 1'b0;
    check   = 1'b0;
    ctrl_a  = '{tx_prbs: PRBS_OFF, rx_prbs: PRBS_OFF, rx_prbs_pause: 1'b0, rx_align: 1'b1};
    ctrl_b  = ctrl_a;
    if (PPM_A != PPM_B) begin
      $display("references: A %0d ppm, B %0d ppm; PRBS run %0d clocks", PPM_A, PPM_B,
               PPM_CLOCKS);
    end
    repeat (4) @(posedge clk_reg);
    arst_n = 1'b1;

    // 1. bring-up of both sides
    fork
      begin
        wait (u_a.tx_ready && u_a.rx_ready && u_a.rx_aligned &&
              u_b.tx_ready && u_b.rx_ready && u_b.rx_aligned);
      end
      begin
        #300us;
        $display("ERROR: no bring-up: A %b%b%b B %b%b%b", u_a.tx_ready, u_a.rx_ready,
                 u_a.rx_aligned, u_b.tx_ready, u_b.rx_ready, u_b.rx_aligned);
        $display("TB_PHY_TWOWAY: FAIL");
        $finish;
      end
    join_any
    disable fork;
    $display("bring-up: A and B ready and aligned at %0t", $time);
    // the iclink_serdes_gm policy: comma alignment off once aligned
    repeat (32) @(posedge u_a.clk);
    ctrl_a.rx_align = 1'b0;
    ctrl_b.rx_align = 1'b0;
    repeat (8) @(posedge u_a.clk);

    // 2. data both ways, bit-exact
    send = 1'b1;
    repeat (32) @(posedge u_a.clk);
    check = 1'b1;
    wait (u_a.rx_words >= DATA_WORDS && u_b.rx_words >= DATA_WORDS);
    if (!u_a.locked || !u_b.locked || u_a.rx_bad != 0 || u_b.rx_bad != 0) begin
      errors++;
      $display("ERROR: data: A %0d of %0d wrong, B %0d of %0d wrong", u_a.rx_bad, u_a.rx_words,
               u_b.rx_bad, u_b.rx_words);
    end
    else begin
      $display("data: %0d words B->A and %0d words A->B, bit-exact", u_a.rx_words,
               u_b.rx_words);
    end

    // 3. a flip on A->B: B sees it, A does not
    flip_line(1'b1);
    repeat (64) @(posedge u_b.clk);
    if (u_b.rx_bad == 0 || u_a.rx_bad != 0) begin
      errors++;
      $display("ERROR: flip A->B: B %0d wrong, A %0d wrong", u_b.rx_bad, u_a.rx_bad);
    end
    else begin
      $display("flip A->B: B %0d word(s) wrong, A none", u_b.rx_bad);
    end
    check = 1'b0;
    send  = 1'b0;

    // 4. PRBS both ways at once: A sends PRBS15, B sends PRBS31
    ctrl_a.tx_prbs = PRBS_15;
    ctrl_b.rx_prbs = PRBS_15;
    ctrl_b.tx_prbs = PRBS_31;
    ctrl_a.rx_prbs = PRBS_31;
    repeat (64) @(posedge u_a.clk);  // the checkers lock
    base_a = u_a.rx_prbs_errors;
    base_b = u_b.rx_prbs_errors;
    ins_a  = u_a.inserts;
    ins_b  = u_b.inserts;
    rem_a  = u_a.removes;
    rem_b  = u_b.removes;
    repeat (PPM_CLOCKS) @(posedge u_a.clk);
    ins_a = u_a.inserts - ins_a;
    ins_b = u_b.inserts - ins_b;
    rem_a = u_a.removes - rem_a;
    rem_b = u_b.removes - rem_b;
    if (u_a.rx_prbs_errors != base_a || u_b.rx_prbs_errors != base_b) begin
      errors++;
      $display("ERROR: PRBS: errors on clean lines: A %0d, B %0d", u_a.rx_prbs_errors - base_a,
               u_b.rx_prbs_errors - base_b);
    end
    $display("clock correction in %0d PRBS clocks: A %0d inserted, %0d removed; B %0d inserted, %0d removed",
             PPM_CLOCKS, ins_a, rem_a, ins_b, rem_b);
    $display("elastic buffer fill: A %0d to %0d words, B %0d to %0d (MIN_LAT %0d, MAX_LAT %0d)",
             u_a.fill_min, u_a.fill_max, u_b.fill_min, u_b.fill_max, PHY_RX_MIN_LAT,
             PHY_RX_MAX_LAT);
    if (DPPM >= 100 && (ins_a + ins_b == 0 || rem_a + rem_b == 0)) begin
      errors++;
      $display("ERROR: %0d ppm apart: the elastic buffers must insert and remove", DPPM);
    end
    else if (PPM_A != PPM_B && DPPM < 100) begin
      $display("%0d ppm apart: corrections reported, not required", DPPM);
    end
    flip_line(1'b0);  // B->A
    repeat (32) @(posedge u_a.clk);
    if (u_a.rx_prbs_errors == base_a || u_b.rx_prbs_errors != base_b) begin
      errors++;
      $display("ERROR: PRBS: flip B->A: A %0d, B %0d", u_a.rx_prbs_errors - base_a,
               u_b.rx_prbs_errors - base_b);
    end
    else begin
      $display("PRBS15 A->B and PRBS31 B->A: 0 errors in %0d clocks; flip B->A: A %0d, B 0",
               PPM_CLOCKS, u_a.rx_prbs_errors - base_a);
    end

    // 5. the elastic buffers never ran out or over
    if (u_a.rx_buf_err || u_b.rx_buf_err || !u_a.rx_ready || !u_b.rx_ready) begin
      errors++;
      $display("ERROR: rx_buf_err A %b B %b, rx_ready A %b B %b", u_a.rx_buf_err, u_b.rx_buf_err,
               u_a.rx_ready, u_b.rx_ready);
    end

    $display("TB_PHY_TWOWAY: %s", (errors == 0) ? "PASS" : "FAIL");
    $finish;
  end

  // a test that never ends fails
  initial begin : _watchdog
    #(2.0e6 + 2.0 * PPM_CLOCKS * CORE_NS);
    $display("ERROR: timeout at %0t", $time);
    $display("TB_PHY_TWOWAY: FAIL");
    $finish;
  end : _watchdog

endmodule : tb_phy_twoway

// One side: the PHY on its BFM, a TX counter stream with clock-correction
// bursts, and an RX checker that finds the word number in the received
// word, then expects the next ones, skipping correction words. inserts and
// removes count the BFM's elastic-buffer corrections.
module phy_side
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter int LINE_RATE     = 2500,
    parameter bit TX_HARD_8B10B = 1'b0,
    parameter int SEED_TX       = 0,     // our stream
    parameter int SEED_RX       = 0      // the peer's stream
) (
    input  logic      clk_ref,
    input  logic      clk_reg,
    input  logic      arst_n,
    input  logic      ser_rxp,
    input  logic      ser_rxn,
    output logic      ser_txp,
    output logic      ser_txn,
    input  phy_ctrl_t ctrl,
    input  logic      send,
    input  logic      check
);
  logic clk, tx_ready, rx_ready, rx_aligned, rx_buf_err;
  phy_word_t tx, rx;
  logic [PHY_NWORDS-1:0] rx_invalid;
  logic rx_clkcor;  // must flag exactly the correction words
  logic [31:0] rx_prbs_errors;
  int tx_cnt = 0, tx_clk = 0;
  int rx_words = 0, rx_bad = 0, expect_n = 0;
  int inserts = 0, removes = 0;
  int fill_min = 64, fill_max = 0;  // the elastic buffer's fill, words, with rx_ready
  logic locked = 1'b0;

  iclink_serdes_gm #(
      .LINE_RATE    (LINE_RATE),
      .TX_HARD_8B10B(TX_HARD_8B10B)
  ) dut (
      .clk_ref       (clk_ref),
      .ser_rxp       (ser_rxp),
      .ser_rxn       (ser_rxn),
      .ser_txp       (ser_txp),
      .ser_txn       (ser_txn),
      .clk_reg       (clk_reg),
      .arst_n        (arst_n),
      .ctrl          (ctrl),
      .clk           (clk),
      .tx_ready      (tx_ready),
      .tx            (tx),
      .rx_ready      (rx_ready),
      .rx_aligned    (rx_aligned),
      .rx            (rx),
      .rx_invalid    (rx_invalid),
      .rx_clkcor     (rx_clkcor),
      .rx_buf_err    (rx_buf_err),
      .rx_prbs_errors(rx_prbs_errors)
  );

  // word n of the stream with this seed: bytes n*8+b+seed, the top byte
  // carries n>>5; a K28.5 comma in lane 0 every 16 words
  function automatic phy_word_t word_of(int n, int seed);
    phy_word_t w;
    for (int b = 0; b < PHY_NWORDS; b++) begin
      w.d[b] = byte_t'(n * PHY_NWORDS + b + seed);
      w.k[b] = 1'b0;
    end
    w.d[PHY_NWORDS-1] = byte_t'(n >> 5);
    if (n % 16 == 0) begin
      w.d[0] = PHY_COMMA;
      w.k[0] = 1'b1;
    end
    return w;
  endfunction

  // the word number from bytes 1 and 7 (byte 0 may be a comma)
  function automatic int n_of(phy_word_t w, int seed);
    return (int'(w.d[PHY_NWORDS-1]) << 5) | ((int'(byte_t'(w.d[1] - byte_t'(1 + seed))) >> 3) & 31);
  endfunction

  // comma words until `send`; then the stream, with a correction burst
  // every PHY_CLKCOR_EVERY clocks, as a PHY user sends them
  initial forever begin : _tx
    @(posedge clk);
    tx_clk <= tx_clk + 1;
    if (!send) begin
      tx <= PHY_COMMA_WORD;
    end
    else if (tx_clk % PHY_CLKCOR_EVERY < PHY_CLKCOR_BURST) begin
      tx <= PHY_CLKCOR_WORD;
    end
    else begin
      tx_cnt <= tx_cnt + 1;
      tx     <= word_of(tx_cnt, SEED_TX);
    end
  end : _tx

  initial forever begin : _rx
    int n;
    @(posedge clk);
    if (!check) begin
      locked <= 1'b0;
    end
    else if (rx_clkcor != (rx == PHY_CLKCOR_WORD)) begin
      rx_bad <= rx_bad + 1;  // rx_clkcor wrong
    end
    else if (rx_clkcor) begin
      // a correction word: the user drops it
    end
    else if (!locked) begin
      n = n_of(rx, SEED_RX);
      if (rx == word_of(n, SEED_RX) && rx_invalid == '0) begin
        expect_n <= n + 1;
        locked   <= 1'b1;
      end
    end
    else begin
      rx_words <= rx_words + 1;
      expect_n <= expect_n + 1;
      if (rx != word_of(expect_n, SEED_RX) || rx_invalid != '0) begin
        rx_bad <= rx_bad + 1;
      end
    end
  end : _rx

  // the BFM's elastic buffer: a read that stalls repeats a word (insert), a
  // write that is skipped drops one (remove); sampled half a clock after
  // each side's edge, where the BFM has settled
  initial forever begin : _inserts
    @(negedge clk);
    if (rx_ready && !dut.u_serdes.eb_r_en) begin
      inserts++;
    end
    if (rx_ready) begin
      if (int'(dut.u_serdes.eb_r_occ) < fill_min) fill_min = int'(dut.u_serdes.eb_r_occ);
      if (int'(dut.u_serdes.eb_r_occ) > fill_max) fill_max = int'(dut.u_serdes.eb_r_occ);
    end
  end : _inserts

  initial forever begin : _removes
    @(negedge dut.u_serdes.clk_core_rx_o);
    if (rx_ready && !dut.u_serdes.eb_w_en) begin
      removes++;
    end
  end : _removes

endmodule : phy_side

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
