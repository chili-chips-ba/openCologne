// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      integer stopn; stopn = 12; void'($value$plusargs("stopn=%d", stopn));
      tx_mode = 2;
      fork wait (aligned === 1'b1); #60000; join_any
      $display("%t aligned=%b", $time, aligned);
      #1000; dump = 1; #400; dump = 0;
      $display("%t --- stop TX_CLK_I %0d clocks", $time, stopn);
      @(negedge clk_pll); stop_tx_clk = 1; repeat (stopn) @(negedge clk_pll); stop_tx_clk = 0;
      #300; dump = 1; #300; dump = 0;
      $display("%t tx_err=%b; line now:", $time, tx_err);
      line_bits(60, 0.4);
      #2000; $display("%t tx_err still %b", $time, tx_err);
      tx_pcs = 1; #100; tx_pcs = 0;
      #1500; $display("%t after TX_PCS_RESET: tx_err=%b txdone=%b", $time, tx_err, txdone);
      dump = 1; #300; dump = 0;
    end
