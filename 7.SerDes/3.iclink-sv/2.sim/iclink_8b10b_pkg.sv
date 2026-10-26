// SPDX-FileCopyrightText: 2016-2017 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2019-2020 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// The 8b/10b tables of the reference encoder and decoder
// (iclink_8b10b_enc.sv, iclink_8b10b_dec.sv), ported from LiteX's
// litex/soc/cores/code_8b10b.py. The decode tables are the inverse of the
// encode tables, built the same way as LiteX's reverse_table_flip() and
// reverse_table(), so the two cannot disagree.
//
// Simulation only: on the chip CC_SERDES encodes and decodes 8b/10b. These
// stay as the bit-exact LiteX reference (sim_8b10b), and as the fabric
// 8b/10b of an ECP5-like peer in simulation (interop_twoway, planned).
//==========================================================================

package iclink_8b10b_pkg;
  import iclink_pkg::*;

  typedef logic [9:0] symbol_t;  // a 10-bit symbol on the line

  // 5b/6b ------------------------------------------------------------------
  function automatic logic [5:0] enc_5b6b(input logic [4:0] x);
    unique case (x)
      5'd0:  return 6'b011000;
      5'd1:  return 6'b100010;
      5'd2:  return 6'b010010;
      5'd3:  return 6'b110001;
      5'd4:  return 6'b001010;
      5'd5:  return 6'b101001;
      5'd6:  return 6'b011001;
      5'd7:  return 6'b000111;
      5'd8:  return 6'b000110;
      5'd9:  return 6'b100101;
      5'd10: return 6'b010101;
      5'd11: return 6'b110100;
      5'd12: return 6'b001101;
      5'd13: return 6'b101100;
      5'd14: return 6'b011100;
      5'd15: return 6'b101000;
      5'd16: return 6'b100100;
      5'd17: return 6'b100011;
      5'd18: return 6'b010011;
      5'd19: return 6'b110010;
      5'd20: return 6'b001011;
      5'd21: return 6'b101010;
      5'd22: return 6'b011010;
      5'd23: return 6'b000101;
      5'd24: return 6'b001100;
      5'd25: return 6'b100110;
      5'd26: return 6'b010110;
      5'd27: return 6'b001001;
      5'd28: return 6'b001110;
      5'd29: return 6'b010001;
      5'd30: return 6'b100001;
      5'd31: return 6'b010100;
    endcase
  endfunction

  function automatic logic unbalanced_6b(input logic [5:0] c);
    return $countones(c) != 3;
  endfunction

  // D.7 is balanced but has a complement too
  function automatic logic flip_5b6b(input logic [4:0] x);
    return unbalanced_6b(enc_5b6b(x)) || x == 5'd7;
  endfunction

  // 3b/4b ------------------------------------------------------------------
  function automatic logic [3:0] enc_3b4b(input logic [2:0] x);
    unique case (x)
      3'd0: return 4'b0100;
      3'd1: return 4'b1001;
      3'd2: return 4'b0101;
      3'd3: return 4'b0011;
      3'd4: return 4'b0010;
      3'd5: return 4'b1010;
      3'd6: return 4'b0110;
      3'd7: return 4'b0001;  // primary D.x.7
    endcase
  endfunction

  function automatic logic unbalanced_4b(input logic [3:0] c);
    return $countones(c) != 2;
  endfunction

  // D.x.3 is balanced but has a complement too
  function automatic logic flip_3b4b(input logic [2:0] x);
    return unbalanced_4b(enc_3b4b(x)) || x == 3'd3;
  endfunction

  // decode -----------------------------------------------------------------
  function automatic logic [4:0] dec_6b5b(input logic [5:0] c);
    logic [4:0] r;
    r = '0;  // not a code: 0, as LiteX
    for (int i = 0; i < 32; i++) begin
      if (enc_5b6b(5'(i)) == c || (flip_5b6b(5'(i)) && ~enc_5b6b(5'(i)) == c)) begin
        r = 5'(i);
      end
    end
    if (c == 6'b001111 || c == 6'b110000) begin
      r = 5'd28;  // K.28
    end
    return r;
  endfunction

  function automatic logic [2:0] dec_4b3b(input logic [3:0] c);
    logic [2:0] r;
    r = '0;
    for (int i = 0; i < 8; i++) begin
      if (enc_3b4b(3'(i)) == c || (flip_3b4b(3'(i)) && ~enc_3b4b(3'(i)) == c)) begin
        r = 3'(i);
      end
    end
    if (c == 4'b0111 || c == 4'b1000) begin
      r = 3'd7;  // alternative D.x.7
    end
    return r;
  endfunction

  // the 3b/4b part of a K.28.y, after a negative 6b (001111)
  function automatic logic [2:0] dec_4b3b_kn(input logic [3:0] c);
    logic [2:0] r;
    r = '0;
    for (int i = 0; i < 8; i++) begin
      if (enc_3b4b(3'(i)) == c) begin
        r = 3'(i);
      end
    end
    if (c == 4'b0001) begin
      r = 3'd0;  // primary D.x.7 is not used
    end
    if (c == 4'b1000) begin
      r = 3'd7;
    end
    return r;
  endfunction

  // the 3b/4b part of a K.28.y, after a positive 6b (110000)
  function automatic logic [2:0] dec_4b3b_kp(input logic [3:0] c);
    logic [2:0] r;
    r = '0;
    for (int i = 0; i < 8; i++) begin
      if (~enc_3b4b(3'(i)) == c) begin
        r = 3'(i);
      end
    end
    if (c == 4'b1110) begin
      r = 3'd0;
    end
    if (c == 4'b0111) begin
      r = 3'd7;
    end
    return r;
  endfunction

  function automatic symbol_t bit_reverse_10(input symbol_t s);
    symbol_t r;
    for (int i = 0; i < 10; i++) begin
      r[i] = s[9-i];
    end
    return r;
  endfunction

endpackage : iclink_8b10b_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
