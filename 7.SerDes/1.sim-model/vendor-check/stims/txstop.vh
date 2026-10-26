// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      integer stopn; stopn = 40; void'($value$plusargs("stopn=%d", stopn));
      tx_mode = 2;
      fork wait (aligned === 1'b1); #60000; join_any
      #1000;
      $display("%t --- stop TX_CLK_I %0d clocks", $time, stopn);
      @(negedge clk_pll); stop_tx_clk = 1;
      fork
        begin repeat (stopn) @(negedge clk_pll); stop_tx_clk = 0; end
        begin #300; $display("%t line during stop:", $time); line_bits(100, 0.4); $display("tx_err=%b", tx_err); end
      join
      $display("%t resumed, tx_err=%b", $time, tx_err);
      #100; $display("line after:"); line_bits(100, 0.4);
      #2000; $display("%t tx_err=%b", $time, tx_err);
      dump = 1; #100; dump = 0;
    end
