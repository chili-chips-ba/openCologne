// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// PHY test, two ways (test setup 2 at the PHY level): two GateMate SerDes
// PHYs, each on its own SerDes BFM, the serial lines crossed (TX of A to RX
// of B, TX of B to RX of A).
//   1. bring-up of both: PLL, TX and RX ready, comma alignment acquired;
//   2. data both ways at once: a counter stream with K28.5 commas, a
//      different one per side, each checked word for word on the other side
//      (8 bytes + 8 K flags): bit-exact, no invalid symbol;
//   3. one serial bit flipped on the A->B line: B must see it, A must not;
//   4. PRBS both ways at once (A sends PRBS15, B sends PRBS31): 0 errors,
//      then a flip on B->A is counted by A only.
module tb_phy_twoway;
  import iclink_pkg::*;
  import iclink_phy_pkg::*;

  localparam int DATA_WORDS = 2000;  // words checked per side in step 2
  localparam int PRBS_CLOCKS = 1000;  // clean PRBS clocks
  localparam int SEED_A = 0;  // the A stream; B's differs
  localparam int SEED_B = 101;

  logic clk_ref, clk_reg, arst_n;
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

  initial begin : _clk_ref
    clk_ref = 1'b0;
    forever #5 clk_ref = ~clk_ref;  // 100 MHz SerDes reference, shared
  end : _clk_ref

  initial begin : _clk_reg
    clk_reg = 1'b0;
    forever #50 clk_reg = ~clk_reg;  // 10 MHz, the board clock
  end : _clk_reg

  phy_side #(
      .SEED_TX(SEED_A),
      .SEED_RX(SEED_B)
  ) u_a (
      .clk_ref(clk_ref),
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
      .SEED_TX(SEED_B),
      .SEED_RX(SEED_A)
  ) u_b (
      .clk_ref(clk_ref),
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
    @(posedge u_a.clk_tx);
    #3.1;  // somewhere inside a word
    if (ab) flip_ab = 1'b1;
    else flip_ba = 1'b1;
    #0.4;  // one UI at 2.5 Gb/s
    flip_ab = 1'b0;
    flip_ba = 1'b0;
  endtask

  initial begin
    logic [31:0] base_a, base_b;
    $timeformat(-6, 2, " us", 0);
    arst_n  = 1'b0;
    flip_ab = 1'b0;
    flip_ba = 1'b0;
    send    = 1'b0;
    check   = 1'b0;
    ctrl_a  = '{tx_prbs: PRBS_OFF, rx_prbs: PRBS_OFF, rx_prbs_pause: 1'b0, rx_align: 1'b1};
    ctrl_b  = ctrl_a;
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

    // 2. data both ways, bit-exact
    send = 1'b1;
    repeat (32) @(posedge u_a.clk_rx);
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
    repeat (64) @(posedge u_b.clk_rx);
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
    repeat (64) @(posedge u_a.clk_rx);  // the checkers lock
    base_a = u_a.rx_prbs_errors;
    base_b = u_b.rx_prbs_errors;
    repeat (PRBS_CLOCKS) @(posedge u_a.clk_rx);
    if (u_a.rx_prbs_errors != base_a || u_b.rx_prbs_errors != base_b) begin
      errors++;
      $display("ERROR: PRBS: errors on clean lines: A %0d, B %0d", u_a.rx_prbs_errors - base_a,
               u_b.rx_prbs_errors - base_b);
    end
    flip_line(1'b0);  // B->A
    repeat (32) @(posedge u_a.clk_rx);
    if (u_a.rx_prbs_errors == base_a || u_b.rx_prbs_errors != base_b) begin
      errors++;
      $display("ERROR: PRBS: flip B->A: A %0d, B %0d", u_a.rx_prbs_errors - base_a,
               u_b.rx_prbs_errors - base_b);
    end
    else begin
      $display("PRBS15 A->B and PRBS31 B->A: 0 errors in %0d clocks; flip B->A: A %0d, B 0",
               PRBS_CLOCKS, u_a.rx_prbs_errors - base_a);
    end

    $display("TB_PHY_TWOWAY: %s", (errors == 0) ? "PASS" : "FAIL");
    $finish;
  end

endmodule : tb_phy_twoway

// One side: the PHY on its BFM, a TX counter stream and an RX checker that
// finds the word number in the received word, then expects the next ones.
module phy_side
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter int SEED_TX = 0,  // our stream
    parameter int SEED_RX = 0   // the peer's stream
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
  logic clk_tx, clk_rx, tx_ready, rx_ready, rx_aligned;
  phy_word_t tx, rx;
  logic [PHY_NWORDS-1:0] rx_invalid;
  logic [31:0] rx_prbs_errors;
  int tx_cnt = 0;
  int rx_words = 0, rx_bad = 0, expect_n = 0;
  logic locked = 1'b0;

  iclink_serdes_gm dut (
      .clk_ref       (clk_ref),
      .ser_rxp       (ser_rxp),
      .ser_rxn       (ser_rxn),
      .ser_txp       (ser_txp),
      .ser_txn       (ser_txn),
      .clk_reg       (clk_reg),
      .arst_n        (arst_n),
      .ctrl          (ctrl),
      .clk_tx        (clk_tx),
      .tx_ready      (tx_ready),
      .tx            (tx),
      .clk_rx        (clk_rx),
      .rx_ready      (rx_ready),
      .rx_aligned    (rx_aligned),
      .rx            (rx),
      .rx_invalid    (rx_invalid),
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
      w.d[0] = 8'hBC;
      w.k[0] = 1'b1;
    end
    return w;
  endfunction

  // the word number from bytes 1 and 7 (byte 0 may be a comma)
  function automatic int n_of(phy_word_t w, int seed);
    return (int'(w.d[PHY_NWORDS-1]) << 5) | ((int'(byte_t'(w.d[1] - byte_t'(1 + seed))) >> 3) & 31);
  endfunction

  initial forever begin : _tx
    @(posedge clk_tx);
    tx_cnt <= tx_cnt + 1;
    tx     <= word_of(send ? tx_cnt : 0, SEED_TX);
  end : _tx

  initial forever begin : _rx
    int n;
    @(posedge clk_rx);
    if (!check) begin
      locked <= 1'b0;
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

endmodule : phy_side

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
