// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      real t0, tp, tl;
      integer n;
      #200;
      if ($test$plusargs("two")) begin wr(8'h51, 16'(cfg1), 16'hFFFF); wr(8'h50, 16'(cfg0) & 16'hFFFE, 16'hFFFF); end
      else wr(8'h51, 16'(cfg1), 16'hFFFF);
      t0 = $realtime;
      wr(8'h50, 16'(cfg0), 16'hFFFF);
      rd(8'h50); $display("50 = %h", rf_v);
      fork begin @(posedge clk_pll); tl = $realtime - t0; $display("first PLL_CLK_O edge %0.1f ns after the on-write", tl); end #20000; join_any
      @(posedge clk_pll); t0 = $realtime; repeat (20) @(posedge clk_pll); tp = ($realtime - t0) / 20.0;
      $display("PLL_CLK_O period %0.3f ns", tp);
      wait (txdone === 1'b1); #500;
      // shortest line pulse over 2000 UI-ish
      begin : ui_m real m, t1; m = 100.0; t1 = $realtime; repeat (400) begin @(txp); if ($realtime - t1 < m) m = $realtime - t1; t1 = $realtime; end $display("shortest TX pulse %0.4f ns", m); end
      rd(8'h55); $display("55 = %h", rf_v);
    end
