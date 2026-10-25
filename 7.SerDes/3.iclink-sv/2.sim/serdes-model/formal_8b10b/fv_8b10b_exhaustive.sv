// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// The BFM 8b/10b decoder over its whole input space, see README.md

`timescale 1ns/1ps

module fv_8b10b_exhaustive;
   import ccfpga_serdes_pkg::*;


   integer errors;
   integer checks;
   integer d, r, s;
   logic [10:0] e;
   logic  [9:0] ent;
   logic  [7:0] kc;
   integer    n_valid;
   integer    n_ones;

   initial begin
      errors = 0;
      checks = 0;

      $display("");
      $display("=============================================================");
      $display("  Exhaustive verification - open 8b/10b decode table");
      $display("=============================================================");
      $display("");

      for (d = 0; d < 256; d = d + 1)
        for (r = 0; r < 2; r = r + 1) begin
           e      = enc8b10b(d[7:0], 1'b0, r[0]);
           ent    = dec8b10b(e[9:0]);
           checks = checks + 1;
           if (!ent[9] || ent[8] || (ent[7:0] !== d[7:0])) begin
              if (errors < 10)
                $display("  FAIL data d=%02h rd=%0d -> sym=%010b -> valid=%b k=%b data=%02h",
                         d[7:0], r, e[9:0], ent[9], ent[8], ent[7:0]);
              errors = errors + 1;
           end
        end
      $display("  data round trip      : 512 cases");

      for (d = 0; d < 12; d = d + 1)
        for (r = 0; r < 2; r = r + 1) begin
           kc     = kcode(d);
           e      = enc8b10b(kc, 1'b1, r[0]);
           ent    = dec8b10b(e[9:0]);
           checks = checks + 1;
           if (!ent[9] || !ent[8] || (ent[7:0] !== kc)) begin
              if (errors < 10)
                $display("  FAIL ctrl K=%02h rd=%0d -> sym=%010b -> valid=%b k=%b data=%02h",
                         kc, r, e[9:0], ent[9], ent[8], ent[7:0]);
              errors = errors + 1;
           end
        end
      $display("  control round trip   : 24 cases");

      n_valid = 0;
      for (s = 0; s < 1024; s = s + 1) begin
         ent = dec8b10b(s[9:0]);
         if (ent[9]) begin
            n_valid = n_valid + 1;
            n_ones  = ones10(s[9:0]);
            checks  = checks + 1;
            if ((n_ones < 4) || (n_ones > 6)) begin
               $display("  FAIL sym %010b marked valid but has %0d ones", s[9:0], n_ones);
               errors = errors + 1;
            end
         end
      end
      $display("  valid symbols in table: %0d of 1024", n_valid);

      checks = checks + 1;
      if (n_valid < 256 || n_valid > 1024) begin
         $display("  FAIL implausible table population %0d", n_valid);
         errors = errors + 1;
      end

      $display("");
      $display("=============================================================");
      if (errors == 0)
        $display("  %0d checks, 0 errors - PASSED (exhaustive over the code space)",
                 checks);
      else
        $display("  %0d checks, %0d errors - FAILED", checks, errors);
      $display("=============================================================");
      $display("");

      if (errors != 0) $stop;
      $finish;
   end

endmodule
