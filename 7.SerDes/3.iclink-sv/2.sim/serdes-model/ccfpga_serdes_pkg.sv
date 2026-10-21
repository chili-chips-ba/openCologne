// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne-PCIE * NLnet-sponsored open-source implementation
//--------------------------------------------------------------------------
//                   Copyright (C) 2026 Chili.CHIPS
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//              https://opensource.org/license/bsd-3-clause
//--------------------------------------------------------------------------
// Description:
//   8b/10b codec and PRBS of the open GateMate SerDes model
//   (ccfpga_serdes.sv), as pure functions. The same package is the source
//   under proof in 4.build/formal, so the model and the proofs cannot drift
//   apart.
//
//   enc8b10b()    8b/10b encoder: {rd_out, abcdei fghj} from data, K flag
//                 and running disparity in
//   dec8b10b()    decoder of one 10-bit symbol: {valid, k, data}; 0 for a
//                 symbol that is not in the code table
//   dec_rd_class  disparity class of a symbol: 1 = six ones (positive),
//                 2 = four ones (negative), 0 = balanced or not in the table
//   kcode()       the 12 legal K codes, index 0 to 11
//   ones10()      number of ones in a 10-bit symbol
//   prbs_next()   next state of the PRBS7/15/23/31 LFSR
//==========================================================================

package ccfpga_serdes_pkg;

  // Bit order on the wire: abcdei is sent a first, the code tables below
  // are written in table order and reversed on output
  function automatic logic [5:0] rev6(input logic [5:0] v);
    return {v[0], v[1], v[2], v[3], v[4], v[5]};
  endfunction

  function automatic logic [3:0] rev4(input logic [3:0] v);
    return {v[0], v[1], v[2], v[3]};
  endfunction

  // 5b/6b code for running disparity minus
  function automatic logic [5:0] enc6_rdm(input logic [4:0] x);
    logic [5:0] c;
    c = 6'b000000;  // not reached for a known x; an X input gives 0
    unique0 case (x)
      5'd0:  begin c = 6'b100111; end
      5'd1:  begin c = 6'b011101; end
      5'd2:  begin c = 6'b101101; end
      5'd3:  begin c = 6'b110001; end
      5'd4:  begin c = 6'b110101; end
      5'd5:  begin c = 6'b101001; end
      5'd6:  begin c = 6'b011001; end
      5'd7:  begin c = 6'b111000; end
      5'd8:  begin c = 6'b111001; end
      5'd9:  begin c = 6'b100101; end
      5'd10: begin c = 6'b010101; end
      5'd11: begin c = 6'b110100; end
      5'd12: begin c = 6'b001101; end
      5'd13: begin c = 6'b101100; end
      5'd14: begin c = 6'b011100; end
      5'd15: begin c = 6'b010111; end
      5'd16: begin c = 6'b011011; end
      5'd17: begin c = 6'b100011; end
      5'd18: begin c = 6'b010011; end
      5'd19: begin c = 6'b110010; end
      5'd20: begin c = 6'b001011; end
      5'd21: begin c = 6'b101010; end
      5'd22: begin c = 6'b011010; end
      5'd23: begin c = 6'b111010; end
      5'd24: begin c = 6'b110011; end
      5'd25: begin c = 6'b100110; end
      5'd26: begin c = 6'b010110; end
      5'd27: begin c = 6'b110110; end
      5'd28: begin c = 6'b001110; end
      5'd29: begin c = 6'b101110; end
      5'd30: begin c = 6'b011110; end
      5'd31: begin c = 6'b101011; end
    endcase
    return c;
  endfunction

  function automatic logic enc6_unbal(input logic [4:0] x);
    logic [5:0] c;
    logic [2:0] ones;
    c    = enc6_rdm(x);
    ones = 3'd0;
    for (int i = 0; i < 6; i++) begin
      ones = ones + c[i];
    end
    return (ones != 3'd3);
  endfunction

  // D.07 is balanced but still has a positive-disparity form
  function automatic logic enc6_flip(input logic [4:0] x);
    return enc6_unbal(x) || (x == 5'd7);
  endfunction

  // 3b/4b code for running disparity minus; alt7 selects the D.x.A7 form
  function automatic logic [3:0] enc4_rdm(input logic [2:0] y, input logic k, input logic alt7);
    logic [3:0] c;
    c = 4'b0000;  // not reached for a known y; an X input gives 0
    if (k) begin
      unique0 case (y)
        3'd0: begin c = 4'b1011; end
        3'd1: begin c = 4'b0110; end
        3'd2: begin c = 4'b1010; end
        3'd3: begin c = 4'b1100; end
        3'd4: begin c = 4'b1101; end
        3'd5: begin c = 4'b0101; end
        3'd6: begin c = 4'b1001; end
        3'd7: begin c = 4'b0111; end
      endcase
    end
    else begin
      unique0 case (y)
        3'd0: begin c = 4'b1011; end
        3'd1: begin c = 4'b1001; end
        3'd2: begin c = 4'b0101; end
        3'd3: begin c = 4'b1100; end
        3'd4: begin c = 4'b1101; end
        3'd5: begin c = 4'b1010; end
        3'd6: begin c = 4'b0110; end
        3'd7: begin c = alt7 ? 4'b0111 : 4'b1110; end
      endcase
    end
    return c;
  endfunction

  function automatic logic enc4_unbal(input logic [2:0] y, input logic k, input logic alt7);
    logic [3:0] c;
    logic [2:0] ones;
    c    = enc4_rdm(y, k, alt7);
    ones = 3'd0;
    for (int i = 0; i < 4; i++) begin
      ones = ones + c[i];
    end
    return (ones != 3'd2);
  endfunction

  // D.x.3 is balanced but still has a positive-disparity form
  function automatic logic enc4_flip(input logic [2:0] y, input logic k, input logic alt7);
    return k ? 1'b1 : (enc4_unbal(y, k, alt7) || (y == 3'd3));
  endfunction

  function automatic logic [10:0] enc8b10b(input logic [7:0] din, input logic k,
                                           input logic rd_in);
    logic [4:0] x;
    logic [2:0] y;
    logic [5:0] c6;
    logic [3:0] c4;
    logic       rd_mid;
    logic       rd_out;
    logic       alt7;

    x = din[4:0];
    y = din[7:5];

    if (k && (x == 5'd28)) begin
      c6     = rd_in ? 6'b110000 : 6'b001111;
      rd_mid = ~rd_in;
    end
    else begin
      c6     = (rd_in && enc6_flip(x)) ? ~enc6_rdm(x) : enc6_rdm(x);
      rd_mid = rd_in ^ enc6_unbal(x);
    end

    alt7 = 1'b0;
    if (!k && (y == 3'd7)) begin
      if (!rd_mid && ((x == 5'd17) || (x == 5'd18) || (x == 5'd20))) begin
        alt7 = 1'b1;
      end
      if (rd_mid && ((x == 5'd11) || (x == 5'd13) || (x == 5'd14))) begin
        alt7 = 1'b1;
      end
    end

    c4     = (rd_mid && enc4_flip(y, k, alt7)) ? ~enc4_rdm(y, k, alt7) : enc4_rdm(y, k, alt7);
    rd_out = rd_mid ^ enc4_unbal(y, k, alt7);

    return {rd_out, rev4(c4), rev6(c6)};
  endfunction

  function automatic logic [3:0] ones10(input logic [9:0] v);
    logic [3:0] n;
    n = 4'd0;
    for (int i = 0; i < 10; i++) begin
      n = n + v[i];
    end
    return n;
  endfunction

  // The 12 legal K codes: K28.0 to K28.7, K23.7, K27.7, K29.7, K30.7
  function automatic logic [7:0] kcode(input int idx);
    logic [7:0] c;
    c = 8'hFE;  // K30.7, index 11
    unique0 case (idx)
      0:  begin c = 8'h1C; end
      1:  begin c = 8'h3C; end
      2:  begin c = 8'h5C; end
      3:  begin c = 8'h7C; end
      4:  begin c = 8'h9C; end
      5:  begin c = 8'hBC; end
      6:  begin c = 8'hDC; end
      7:  begin c = 8'hFC; end
      8:  begin c = 8'hF7; end
      9:  begin c = 8'hFB; end
      10: begin c = 8'hFD; end
    endcase
    return c;
  endfunction

  // Decode one symbol into {valid, k, data} by searching the encoder: data
  // codes first, then K codes, so that a K code wins where the two share a
  // symbol. 0 = not in the table.
  function automatic logic [9:0] dec8b10b(input logic [9:0] sym);
    logic [10:0] e;
    logic [ 9:0] ent;
    ent = 10'h0;
    for (int d = 0; d < 256; d++) begin
      for (int r = 0; r < 2; r++) begin
        e = enc8b10b(d[7:0], 1'b0, r[0]);
        if (e[9:0] == sym) begin
          ent = {1'b1, 1'b0, d[7:0]};
        end
      end
    end
    for (int d = 0; d < 12; d++) begin
      for (int r = 0; r < 2; r++) begin
        e = enc8b10b(kcode(d), 1'b1, r[0]);
        if (e[9:0] == sym) begin
          ent = {1'b1, 1'b1, kcode(d)};
        end
      end
    end
    return ent;
  endfunction

  function automatic logic [1:0] dec_rd_class(input logic [9:0] sym);
    logic [3:0] ones;
    ones = ones10(sym);
    return (ones == 4'd6) ? 2'd1 : (ones == 4'd4) ? 2'd2 : 2'd0;
  endfunction

  // PRBS7 (sel 1, also the default), PRBS15 (2), PRBS23 (3), PRBS31 (4)
  function automatic logic [30:0] prbs_next(input logic [30:0] state, input logic [2:0] sel);
    logic fb;
    fb = state[6] ^ state[5];
    unique0 case (sel)
      3'b010: begin fb = state[14] ^ state[13]; end
      3'b011: begin fb = state[22] ^ state[17]; end
      3'b100: begin fb = state[30] ^ state[27]; end
    endcase
    return {state[29:0], fb};
  endfunction

endpackage

// -----------------------------------------------------------------------------
// Project:     openCologne-PCIE
// Description: NLnet-sponsored open-source implementation
// Version:     1.0
// Date:        April 2025
// -----------------------------------------------------------------------------
