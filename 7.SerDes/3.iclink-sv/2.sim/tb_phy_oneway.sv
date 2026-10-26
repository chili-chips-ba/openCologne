// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// PHY test, one way (test setup 1): the GateMate SerDes PHY on the SerDes
// BFM, its serial TX looped to its own RX.
//
//   1. bring-up: PLL, TX and RX ready, comma alignment acquired;
//   2. data: a counter stream with K28.5 commas and clock-correction
//      bursts, compared word for word (8 bytes + 8 K flags) with what went
//      in, the correction words skipped: bit-exact, no invalid symbol; the
//      latency, TX data in to RX data out;
//   3. one serial bit flipped: must show as an invalid symbol or a mismatch;
//   4. PRBS7, PRBS15, PRBS31: error count stays at 0, then one serial bit
//      flip must count; with pause, a flip must not count;
//   5. RX_BUF_ERR_O never set (rx_buf_err).
//==========================================================================
module tb_phy_oneway
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter int LINE_RATE     = 2500,                // Mb/s: 1250, 2500 or 5000
    parameter bit TX_HARD_8B10B = (LINE_RATE >= 5000)
);

  localparam int DATA_WORDS = 2000;  // words checked in step 2
  localparam int PRBS_CLOCKS = 1000;  // clean PRBS clocks per pattern

  logic clk_ref, clk_reg, arst_n;
  logic ser_txp, ser_txn, ser_rxp, ser_rxn;
  logic flip;  // inverts the serial line while high
  logic clk, tx_ready, rx_ready, rx_aligned, rx_buf_err;
  phy_ctrl_t ctrl;
  phy_word_t tx, rx;
  logic [PHY_NWORDS-1:0] rx_invalid;
  logic rx_clkcor;  // must flag exactly the correction words
  logic [31:0] rx_prbs_errors;
  int errors = 0;

  initial begin : _waves
    if ($test$plusargs("waves")) begin
      $dumpfile("phy_oneway.fst");  // make sim_phy_oneway WAVES=1
      $dumpvars(0, tb_phy_oneway);
    end
  end : _waves

  initial begin : _clk_ref
    clk_ref = 1'b0;
    forever #5 clk_ref = ~clk_ref;  // 100 MHz SerDes reference
  end : _clk_ref

  initial begin : _clk_reg
    clk_reg = 1'b0;
    forever #50 clk_reg = ~clk_reg;  // 10 MHz, the EVB clock
  end : _clk_reg

  always_comb begin
    ser_rxp = ser_txp ^ flip;
    ser_rxn = ser_txn ^ flip;
  end

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

  //-----------------------------------------------------------------------
  // TX: idle (comma words) until `send`, then the counter stream, with a
  // clock-correction burst every PHY_CLKCOR_EVERY clocks, as a PHY user does
  //-----------------------------------------------------------------------
  logic      send;
  int        tx_cnt;
  int        tx_clk = 0;  // clocks, for the bursts
  phy_word_t sent[$];  // words sent while `send`, oldest first
  realtime   sent_t[$];  // ... the clock edge that put each on tx

  function automatic phy_word_t word_of(int n);
    phy_word_t w;
    for (int b = 0; b < PHY_NWORDS; b++) begin
      w.d[b] = byte_t'(n * PHY_NWORDS + b);
      w.k[b] = 1'b0;
    end
    w.d[PHY_NWORDS-1] = byte_t'(n >> 5);  // no two words alike within 8192
    if (n % 16 == 0) begin  // a comma every 16 words, in lane 0
      w.d[0] = PHY_COMMA;
      w.k[0] = 1'b1;
    end
    return w;
  endfunction

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
      tx     <= word_of(tx_cnt);
      sent.push_back(word_of(tx_cnt));
      sent_t.push_back($realtime);
    end
  end : _tx

  //-----------------------------------------------------------------------
  // RX: word-for-word compare against `sent`, once the first word is found
  //-----------------------------------------------------------------------
  logic      check;  // compare while high
  logic      locked;  // the first sent word was found in the RX stream
  int        rx_words, rx_bad;
  real       lat_min = 1.0e9, lat_max = -1.0e9;  // clocks, TX data in to RX data out

  initial forever begin : _rx
    real lat;
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
      // the RX stream starts somewhere in `sent`: find it, drop what is older
      for (int i = 0; i < sent.size(); i++) begin
        if (sent[i] == rx) begin
          sent   = sent[i+1:$];
          sent_t = sent_t[i+1:$];
          locked <= 1'b1;
          break;
        end
      end
    end
    else begin
      rx_words <= rx_words + 1;
      if (sent.size() == 0 || sent[0] != rx || rx_invalid != '0) begin
        rx_bad <= rx_bad + 1;
      end
      if (sent.size() > 0) begin
        // clocks of flops: the PHY takes tx a clock after sent_t, the TB
        // sees rx at the edge after the PHY puts it out
        lat = ($realtime - sent_t[0]) * LINE_RATE / 80000.0 - 1.0;
        if (lat < lat_min) lat_min = lat;
        if (lat > lat_max) lat_max = lat;
        void'(sent.pop_front());
        void'(sent_t.pop_front());
      end
    end
  end : _rx

  task automatic flip_bit();
    @(posedge clk);
    #3.1;  // somewhere inside a word
    flip = 1'b1;
    #(1000.0 / LINE_RATE);  // one UI
    flip = 1'b0;
  endtask

  task automatic prbs_test(prbs_cfg_t cfg, string name);
    logic [31:0] base;
    ctrl.tx_prbs = cfg;
    ctrl.rx_prbs = cfg;
    repeat (64) @(posedge clk);  // the checker locks
    base = rx_prbs_errors;
    repeat (PRBS_CLOCKS) @(posedge clk);
    if (rx_prbs_errors != base) begin
      errors++;
      $display("ERROR: %s: %0d errors on a clean link", name, rx_prbs_errors - base);
    end
    flip_bit();
    repeat (32) @(posedge clk);
    if (rx_prbs_errors == base) begin
      errors++;
      $display("ERROR: %s: a flipped bit was not counted", name);
    end
    $display("%s: 0 errors in %0d clocks; one flipped bit: %0d clock(s) with an error", name,
             PRBS_CLOCKS, rx_prbs_errors - base);
    ctrl.rx_prbs = PRBS_OFF;  // clears the count
    repeat (8) @(posedge clk);
  endtask

  initial begin
    logic [31:0] base;
    $timeformat(-6, 2, " us", 0);
    arst_n = 1'b0;
    flip   = 1'b0;
    send   = 1'b0;
    check  = 1'b0;
    ctrl   = '{tx_prbs: PRBS_OFF, rx_prbs: PRBS_OFF, rx_prbs_pause: 1'b0, rx_align: 1'b1};
    tx_cnt   = 0;
    rx_words = 0;
    rx_bad   = 0;
    repeat (4) @(posedge clk_reg);
    arst_n = 1'b1;

    // 1. bring-up
    fork
      begin
        wait (!dut.serdes_reset);
        $display("bring-up: regfile writes done at %0t", $time);
        wait (tx_ready);
        $display("bring-up: TX ready at %0t", $time);
        wait (rx_ready);
        $display("bring-up: RX ready at %0t", $time);
      end
    join_none
    fork
      begin
        wait (tx_ready && rx_ready && rx_aligned);
      end
      begin
        #300us;
        $display("ERROR: no bring-up: tx_ready %b rx_ready %b rx_aligned %b", tx_ready, rx_ready,
                 rx_aligned);
        $display("TB_PHY_ONEWAY: FAIL");
        $finish;
      end
    join_any
    disable fork;
    $display("bring-up: TX and RX ready, aligned at %0t", $time);
    // the iclink_serdes_gm policy: comma alignment off once aligned, so a
    // flipped line bit cannot move the word boundary
    repeat (32) @(posedge clk);
    ctrl.rx_align = 1'b0;
    repeat (8) @(posedge clk);

    // 2. data, bit-exact
    @(posedge clk);
    send = 1'b1;
    repeat (32) @(posedge clk);
    check = 1'b1;
    wait (rx_words == DATA_WORDS);
    if (!locked || rx_bad != 0) begin
      errors++;
      $display("ERROR: data: %0d of %0d words wrong (locked %b)", rx_bad, rx_words, locked);
    end
    else begin
      $display("data: %0d words of 8 bytes + K, bit-exact", rx_words);
      $display("latency: TX data in to RX data out: %0.2f to %0.2f clocks", lat_min, lat_max);
    end

    // 3. one flipped bit must be seen
    flip_bit();
    repeat (64) @(posedge clk);
    if (rx_bad == 0) begin
      errors++;
      $display("ERROR: data: a flipped bit was not seen");
    end
    else begin
      $display("data: one flipped bit: %0d word(s) wrong", rx_bad);
    end
    check = 1'b0;
    send  = 1'b0;
    @(posedge clk);
    sent.delete();

    // 4. PRBS
    prbs_test(PRBS_7, "PRBS7");
    prbs_test(PRBS_15, "PRBS15");
    prbs_test(PRBS_31, "PRBS31");

    // pause holds the count
    ctrl.tx_prbs = PRBS_7;
    ctrl.rx_prbs = PRBS_7;
    repeat (64) @(posedge clk);
    ctrl.rx_prbs_pause = 1'b1;
    repeat (8) @(posedge clk);
    base = rx_prbs_errors;
    flip_bit();
    repeat (32) @(posedge clk);
    if (rx_prbs_errors != base) begin
      errors++;
      $display("ERROR: PRBS7: a flipped bit was counted during pause");
    end
    else begin
      $display("PRBS7: pause: a flipped bit was not counted");
    end

    // the core clock follows the PLL setting: LINE_RATE / 80
    begin : _clk_check
      realtime t0, t1;
      real mhz;
      @(posedge clk);
      t0 = $realtime;
      repeat (100) @(posedge clk);
      t1  = $realtime;
      mhz = 100.0 * 1000.0 / (t1 - t0);
      if (mhz < LINE_RATE / 80.0 * 0.99 || mhz > LINE_RATE / 80.0 * 1.01) begin
        errors++;
        $display("ERROR: clk %0.3f MHz, expected %0.3f", mhz, LINE_RATE / 80.0);
      end
      else begin
        $display("clk %0.3f MHz at %0d Mb/s, TX 8b/10b in %0s", mhz, LINE_RATE,
                 TX_HARD_8B10B ? "CC_SERDES" : "the fabric");
      end
    end : _clk_check

    if (rx_buf_err || !rx_ready) begin
      errors++;
      $display("ERROR: rx_buf_err %b, rx_ready %b at the end", rx_buf_err, rx_ready);
    end

    $display("TB_PHY_ONEWAY: %s", (errors == 0) ? "PASS" : "FAIL");
    $finish;
  end

  // a test that never ends fails
  initial begin : _watchdog
    #2ms;
    $display("ERROR: timeout at %0t", $time);
    $display("TB_PHY_ONEWAY: FAIL");
    $finish;
  end : _watchdog

endmodule : tb_phy_oneway

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
