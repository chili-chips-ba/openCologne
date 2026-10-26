// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      real t0, tp;
      #200;
      rd(8'h50); $display("RST 50 = %h lat %0d", rf_v, rf_lat);
      rd(8'h51); $display("RST 51 = %h lat %0d", rf_v, rf_lat);
      rd(8'h55); $display("RST 55 = %h lat %0d", rf_v, rf_lat);
      rd(8'h00); $display("RST 00 = %h lat %0d", rf_v, rf_lat);
      rd(8'h47); $display("RST 47 = %h lat %0d", rf_v, rf_lat);
      rd(8'h25); $display("RST 25 = %h lat %0d", rf_v, rf_lat);
      wr(8'h51, 16'h16FA, 16'hFFFF); $display("WR 51 lat %0d do=%h", rf_lat, do_);
      wr(8'h50, 16'h0FFE, 16'hFFFF); rd(8'h50); $display("50: FFE -> %h (wlat?)", rf_v);
      wr(8'h50, 16'h0000, 16'hFFFF); rd(8'h50); $display("50: 000 -> %h", rf_v);
      wr(8'h50, 16'h0C03, 16'hFFFF); rd(8'h50); $display("50: off, write C03 -> %h", rf_v);
      wr(8'h50, 16'h0FFF, 16'hFFFF); rd(8'h50); $display("50: on, write FFF -> %h", rf_v);
      wr(8'h50, 16'h0002, 16'h0FFE); rd(8'h50); $display("50: on, write 002 mask FFE (bit0 not written) -> %h", rf_v);
      wr(8'h50, 16'h0C02, 16'hFFFF); rd(8'h50); $display("50: on, write C02 (turns off) -> %h", rf_v);
      wr(8'h50, 16'h0C03, 16'hFFFF); rd(8'h50); $display("50: off, write C03 -> %h", rf_v);
      wr(8'h51, 16'h06FA, 16'hFFFF); rd(8'h51); $display("51 while on: write 06FA -> %h", rf_v);
      #3000; rd(8'h55); $display("55 after 3us = %h lat %0d", rf_v, rf_lat);
      @(posedge clk_pll); t0 = $realtime; repeat (20) @(posedge clk_pll); tp = ($realtime - t0) / 20.0;
      $display("PLL_CLK_O period %0.3f ns (CONFIG_SEL %0d)", tp, rf_v);
      // busy: two EN edges 2 cycles apart
      @(posedge clk_reg); addr <= 8'h50; en <= 1; we <= 0; @(posedge clk_reg); en <= 0; @(posedge clk_reg); addr <= 8'h51; en <= 1; @(posedge clk_reg); en <= 0;
      begin : busy integer n, r; r = 0; for (n = 0; n < 40; n = n + 1) begin @(posedge clk_reg); if (rdy) begin r = r + 1; $display("BUSY rdy at +%0d do=%h", n, do_); end end end
      // EN held high
      @(posedge clk_reg); addr <= 8'h50; en <= 1; we <= 0;
      begin : hold integer n; for (n = 0; n < 30; n = n + 1) begin @(posedge clk_reg); if (rdy) $display("HOLD rdy at +%0d", n); end end
      en <= 0;
      repeat (5) @(posedge clk_reg);
      // clock correction: ignored writes
      wr(8'h25, 16'h0000 | (16'd39 << 8) | (16'd32 << 2) | 16'h0002, 16'hFFFF); rd(8'h25); $display("25 use=1: %h", rf_v);
      wr(8'h25, 16'h0000 | (16'd30 << 8) | (16'd20 << 2) | 16'h0002, 16'hFFFF); rd(8'h25); $display("25 use=1, new MIN/MAX: %h", rf_v);
      wr(8'h26, 16'h0055, 16'hFFFF); rd(8'h26); $display("26 use=1, write 055: %h", rf_v);
      wr(8'h25, 16'h0000 | (16'd30 << 8) | (16'd20 << 2) | 16'h0000, 16'hFFFF); rd(8'h25); $display("25 use=1, write use=0 + new MIN/MAX: %h", rf_v);
      wr(8'h25, 16'h0000 | (16'd30 << 8) | (16'd20 << 2) | 16'h0000, 16'hFFFF); rd(8'h25); $display("25 use=0, write new MIN/MAX: %h", rf_v);
      wr(8'h26, 16'h0055, 16'hFFFF); rd(8'h26); $display("26 use=0, write 055: %h", rf_v);
      // write latency, DO on write
      @(posedge clk_reg); addr <= 8'h26; di <= 16'h0123; en <= 1; we <= 1; @(posedge clk_reg); en <= 0; we <= 0;
      begin : wl integer n; for (n = 0; n < 30; n = n + 1) begin @(posedge clk_reg); if (rdy) $display("WRITE rdy at +%0d do=%h", n, do_); end end
      cfgw(8'h50, 16'h0C03); rd(8'h50); $display("cfg path 50 C03 (PLL on) -> %h", rf_v);
    end
