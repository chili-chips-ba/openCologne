// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    begin : st
      integer i;
      if ($test$plusargs("lane1")) clane = 1;
      fork wait (rxdone === 1'b1); #100000; join_any
      $display("%t start, aligned=%b", $time, aligned);
      dump = $test$plusargs("dump0");
      fork wait (aligned === 1'b1); #60000; join_any
      dump = 0;
      #3000;
      $display("%t --- comma to lane %0d", $time, (clane + 1) % LANES); clane = (clane + 1) % LANES;
      dump = $test$plusargs("dump1"); #1500; dump = 0;
      #3000;
      $display("%t --- comma back to lane %0d, then +1 UI on the line", $time, (clane + LANES - 1) % LANES); clane = (clane + LANES - 1) % LANES;
      #2000;
      wd = wd + 0.4;
      dump = $test$plusargs("dump2"); #1500; dump = 0;
      fork wait (aligned === 1'b1); #30000; join_any
      #2000;
      $display("%t --- comma detect off", $time); comma_en = 0; #1000; $display("%t aligned=%b", $time, aligned);
      comma_en = 1; #1000; $display("%t comma detect on: aligned=%b", $time, aligned);
      fork wait (aligned === 1'b1); #30000; join_any
      #1000;
      $display("%t --- m/pcomma off", $time); mcomma = 0; pcomma = 0; #1000; $display("%t aligned=%b", $time, aligned);
      wd = wd + 0.4; #3000; $display("%t +1 UI with align off: aligned=%b realigns=%0d", $time, aligned, realigns);
      $display("%t realigns total %0d", $time, realigns);
    end
