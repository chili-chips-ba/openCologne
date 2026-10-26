// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      real h; h = 17.0; void'($value$plusargs("half=%f", h));
      tx_mode = 2;
      fork wait (aligned === 1'b1); #60000; join_any
      $display("%t aligned=%b, TX_CLK_I half period now %0.2f", $time, aligned, h);
      own_half = h; use_own = 1;
      fork wait (tx_err === 1'b1); #20000; join_any
      $display("%t tx_err=%b", $time, tx_err);
      #200; dump = 1; #200; dump = 0;
      use_own = 0;
      #2000; $display("%t clock back: tx_err=%b", $time, tx_err);
      dump = 1; #200; dump = 0;
      $display("line:"); line_bits(40, 0.4);
      tx_pcs = 1; #100; tx_pcs = 0;
      #1500; $display("%t after TX_PCS_RESET: tx_err=%b txdone=%b", $time, tx_err, txdone);
      dump = 1; #200; dump = 0;
    end
