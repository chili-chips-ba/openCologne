// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Board-top test: the self-tests in top.sv run error-free and the SerDes
// link comes up (PRBS7 with clock-correction bursts), on the SerDes BFM
// with its serial TX looped to its RX;
// one bit flipped on the serial line, and one corrupted 8b/10b symbol,
// must each be reported, and the LED must go low.
//==========================================================================
module tb_top;

  logic clk, clk_ref;
  logic btn_n;
  logic led;
  logic ser_txp, ser_txn, ser_rxp, ser_rxn;
  logic flip;  // inverts the serial line while high
  int   errors = 0;

  initial begin : _clock
    clk = 1'b0;
    forever #50 clk = ~clk;  // 10 MHz, the EVB clock
  end : _clock

  initial begin : _clock_ref
    clk_ref = 1'b0;
    forever #5 clk_ref = ~clk_ref;  // 100 MHz SerDes reference
  end : _clock_ref

  always_comb begin
    ser_rxp = ser_txp ^ flip;
    ser_rxn = ser_txn ^ flip;
  end

  top dut (
      .clk_ref(clk_ref),
      .ser_rxp(ser_rxp),
      .ser_rxn(ser_rxn),
      .ser_txp(ser_txp),
      .ser_txn(ser_txn),
      .clk    (clk),
      .btn_n  (btn_n),
      .led    (led)
  );

  initial begin
    flip  = 1'b0;
    btn_n = 1'b0;
    repeat (4) @(posedge clk);
    btn_n = 1'b1;

    // 1. a clean run: 4096 clocks, 256 commas, no error; the link is up
    repeat (4096) @(posedge clk);
    if (dut.st_error || dut.prbs_error) begin
      errors++;
      $display("ERROR: self-test reports an error on a clean run");
    end
    if (!dut.link_up_sync[1] || dut.link_error_sync[1]) begin
      errors++;
      $display("ERROR: SerDes link: up %b, error %b on a clean run", dut.link_up_sync[1],
               dut.link_error_sync[1]);
    end
    else begin
      $display("SerDes link: up, PRBS7 error-free");
    end

    // 2. one bit flipped on the serial line must be caught
    @(posedge dut.clk_core);
    #3.1;
    flip = 1'b1;
    #0.4;  // one UI at 2.5 Gb/s
    flip = 1'b0;
    repeat (24) @(posedge clk);  // PHY (~33 clk_core), checks and sync: about 1.3 us
    if (!dut.link_error_sync[1] || led) begin
      errors++;
      $display("ERROR: a flipped serial bit was not reported (link_error %b, led %b)",
               dut.link_error_sync[1], led);
    end
    else begin
      $display("SerDes link: a flipped serial bit was reported");
    end

    // 3. a symbol with one bit flipped must be caught, and the LED must go low
    @(negedge clk);
    force dut.symbol[1] = dut.symbol[1] ^ 10'h001;  // one bit: the complement would decode the same
    @(negedge clk);
    release dut.symbol[1];
    repeat (4) @(posedge clk);
    #1;
    if (!dut.st_error || led) begin
      errors++;
      $display("ERROR: a corrupted symbol was not reported (st_error %b, led %b)", dut.st_error,
               led);
    end

    $display("TB_TOP: %s  %0d errors", errors == 0 ? "PASS" : "FAIL", errors);
    $finish;
  end

  // a test that never ends fails
  initial begin : _watchdog
    #4ms;
    $display("ERROR: timeout at %0t", $time);
    $display("TB_TOP: FAIL");
    $finish;
  end : _watchdog

endmodule : tb_top
