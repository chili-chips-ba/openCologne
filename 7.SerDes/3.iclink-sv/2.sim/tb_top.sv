// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Board-top test: the 8b/10b self-test in top.sv runs error-free, and a
// corrupted symbol makes it report the error on the LED.
//==========================================================================
module tb_top;

  logic clk;
  logic btn_n;
  logic led;
  int   errors = 0;

  initial begin : _clock
    clk = 1'b0;
    forever #50 clk = ~clk;  // 10 MHz, the EVB clock
  end : _clock

  top dut (
      .clk  (clk),
      .btn_n(btn_n),
      .led  (led)
  );

  initial begin
    btn_n = 1'b0;
    repeat (4) @(posedge clk);
    btn_n = 1'b1;

    // 1. a clean run: 4096 clocks, 256 commas, no error
    repeat (4096) @(posedge clk);
    if (dut.st_error) begin
      errors++;
      $display("ERROR: self-test reports an error on a clean run");
    end

    // 2. a symbol with one bit flipped must be caught, and the LED must go low
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

endmodule : tb_top
