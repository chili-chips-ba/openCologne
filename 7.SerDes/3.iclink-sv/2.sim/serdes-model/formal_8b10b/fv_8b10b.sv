// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// SAT properties of the BFM 8b/10b encoder, see README.md. The decode
// round trip is in fv_8b10b_exhaustive.sv.

`timescale 1ns/1ps

module fv_enc_disparity
   import ccfpga_serdes_pkg::*;
(
   input  logic [7:0] d,
   input  logic       k,
   input  logic       rd_in,
   output logic       ok
   );


   logic [10:0] e;
   assign e = enc8b10b(d, k, rd_in);
   logic  [3:0] ones;
   assign ones = ones10(e[9:0]);

   assign ok = (ones >= 4) && (ones <= 6);
endmodule

module fv_enc_rd_tracking
   import ccfpga_serdes_pkg::*;
(
   input  logic [7:0] d,
   input  logic       k,
   input  logic       rd_in,
   output logic       ok
   );


   logic [10:0] e;
   assign e = enc8b10b(d, k, rd_in);
   logic  [3:0] ones;
   assign ones = ones10(e[9:0]);
   logic        rd_out;
   assign rd_out = e[10];

   logic        rd_expect;
   assign rd_expect = (ones == 6) ? 1'b1 :
                        (ones == 4) ? 1'b0 : rd_in;

   assign ok = (rd_out == rd_expect);
endmodule

module fv_comma_format
   import ccfpga_serdes_pkg::*;
(
   output logic ok
   );


   // the ALIGN_P/MCOMMA_VALUE defaults of DS1001 (tb_modes checks the
   // BFM's against the encoder too)
   localparam [9:0] ALIGN_PCOMMA_VALUE = 10'b0101111100;
   localparam [9:0] ALIGN_MCOMMA_VALUE = 10'b1010000011;

   logic [10:0] k285_rdm;
   assign k285_rdm = enc8b10b(8'hBC, 1'b1, 1'b0);
   logic [10:0] k285_rdp;
   assign k285_rdp = enc8b10b(8'hBC, 1'b1, 1'b1);

   assign ok = (k285_rdm[9:0] == ALIGN_PCOMMA_VALUE) &&
               (k285_rdp[9:0] == ALIGN_MCOMMA_VALUE);
endmodule

module fv_run_length
   import ccfpga_serdes_pkg::*;
(
   input  logic [7:0] d0,
   input  logic       k0,
   input  logic [7:0] d1,
   input  logic       k1,
   input  logic       rd_in,
   output logic       ok
   );


   function legal;
      input [7:0] d;
      input       k;
      begin
         legal = (!k) || (d == 8'h1C) || (d == 8'h3C) || (d == 8'h5C) ||
                 (d == 8'h7C) || (d == 8'h9C) || (d == 8'hBC) ||
                 (d == 8'hDC) || (d == 8'hFC) || (d == 8'hF7) ||
                 (d == 8'hFB) || (d == 8'hFD) || (d == 8'hFE);
      end
   endfunction

   logic [10:0] e0;
   assign e0 = enc8b10b(d0, k0, rd_in);
   logic [10:0] e1;
   assign e1 = enc8b10b(d1, k1, e0[10]);

   logic [19:0] stream;
   assign stream = {e1[9:0], e0[9:0]};

   logic  [14:0] bad;
   integer     i;
   always @(*)
     for (i = 0; i < 15; i = i + 1)
       bad[i] = (stream[i +: 6] == 6'b000000) || (stream[i +: 6] == 6'b111111);

   logic applicable;
   assign applicable = legal(d0, k0) && legal(d1, k1);

   assign ok = !applicable || (bad == 15'h0);
endmodule

module fv_injective
   import ccfpga_serdes_pkg::*;
(
   input  logic [7:0] d0,
   input  logic       k0,
   input  logic [7:0] d1,
   input  logic       k1,
   input  logic       rd0,
   input  logic       rd1,
   output logic       ok
   );


   function legal;
      input [7:0] d;
      input       k;
      begin
         legal = (!k) || (d == 8'h1C) || (d == 8'h3C) || (d == 8'h5C) ||
                 (d == 8'h7C) || (d == 8'h9C) || (d == 8'hBC) ||
                 (d == 8'hDC) || (d == 8'hFC) || (d == 8'hF7) ||
                 (d == 8'hFB) || (d == 8'hFD) || (d == 8'hFE);
      end
   endfunction

   logic [10:0] e0;
   assign e0 = enc8b10b(d0, k0, rd0);
   logic [10:0] e1;
   assign e1 = enc8b10b(d1, k1, rd1);

   logic        different;
   assign different = (d0 != d1) || (k0 != k1);
   logic        applicable;
   assign applicable = legal(d0, k0) && legal(d1, k1) && different;

   assign ok = !applicable || (e0[9:0] != e1[9:0]);
endmodule
