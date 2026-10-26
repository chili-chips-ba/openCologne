// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      real w, t0; w = 2.0; void'($value$plusargs("wd=%f", w)); wd = w;
      cevery = 1;
      wait (rxdone === 1'b1); t0 = $realtime;
      fork wait (aligned === 1'b1); #60000; join_any
      $display("SLIPDIR wd=%0.1f aligned after %0.1f ns = %0.1f words", w, $realtime - t0, ($realtime - t0) / 32.0);
    end
