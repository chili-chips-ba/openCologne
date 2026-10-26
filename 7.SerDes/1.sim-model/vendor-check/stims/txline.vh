// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      // raw line bits after TX reset: first symbols and RD, then PRBS
      tx_mode = 1; txd_c = 64'hBCBCBCBCBCBCBCBC; txk_c = 8'hFF;
      tx_rst = 1; #100;
      @(posedge clk_ref); tx_rst = 0;
      wait (txdone === 1'b1);
      begin : w integer n; n = 0; while (txp === 1'b0 && n < 20000) begin #0.1; n = n + 1; end end
      $display("%t first line 1 after done; bits:", $time);
      #0.2; line_bits(120, 0.4);
      tx_prbs = 3'b001; #3000;
      $display("%t PRBS7 bits:", $time); line_bits(200, 0.4);
    end
