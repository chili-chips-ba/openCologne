// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      integer z;
      fork wait (aligned === 1'b1); #60000; join_any
      #1000;
      tx_mode = 1; txd_c = 64'hBCBCBCBCBCBCBCBC; txk_c = 8'hFF;
      #500;
      tx_rst = 1; #200; tx_rst = 0;
      z = 0; while (z < 20) begin #0.4; z = (txp === 1'b0) ? z + 1 : 0; end
      $display("%t zeros seen", $time);
      @(posedge txp); #0.2;
      line_bits(80, 0.4);
      #3000; $display("later:"); @(posedge txp); #0.2; line_bits(80, 0.4);
    end
