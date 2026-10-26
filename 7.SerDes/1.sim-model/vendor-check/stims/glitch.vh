// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      real t1, w; integer n, h[0:9]; integer i;
      for (i = 0; i < 10; i = i + 1) h[i] = 0;
      fork wait (aligned === 1'b1); #60000; join_any
      #1000;
      n = 0; t1 = $realtime;
      repeat (20000) begin @(txp); w = $realtime - t1; t1 = $realtime; if (w < 0.4) begin i = $rtoi(w / 0.04); h[i] = h[i] + 1; n = n + 1; end end
      $display("GLITCH pulses under 1 UI in 20000 edges: %0d", n);
      for (i = 0; i < 10; i = i + 1) $display("GLITCH %0d..%0d ps: %0d", i*40, i*40+40, h[i]);
    end
