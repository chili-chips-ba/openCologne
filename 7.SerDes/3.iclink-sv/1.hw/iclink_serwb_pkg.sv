// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Serial Wishbone (SerWB) packet layer, as LiteICLink defines it
// (liteiclink/serwb/packet.py, doc/serwb.md): preamble, the port / length
// word and the CRC32.
//==========================================================================
package iclink_serwb_pkg;

  typedef logic [31:0] word_t;  // one SerWB word, 4 bytes on the line

  localparam word_t SERWB_PREAMBLE = 32'h5AA5_5AA5;

  // CRC32 as LiteICLink's _CRC32 (LiteEth's CRC engine): IEEE polynomial,
  // reset to all ones at each preamble, data bit 0 first, MSB-first shift,
  // no final inversion or reflection
  localparam word_t SERWB_CRC_POLY = 32'h04C1_1DB7;
  localparam word_t SERWB_CRC_INIT = 32'hFFFF_FFFF;

  // the port / length word: [7:0] port, [23:8] length in bytes, [31:24] 0
  function automatic word_t serwb_header(input logic [7:0] port, input logic [13:0] words);
    return {8'h00, words, 2'b00, port};
  endfunction

  // one CRC32 step over a 32-bit word
  function automatic word_t serwb_crc32(input word_t crc, input word_t data);
    word_t c;
    logic  fb;
    c = crc;
    for (int n = 0; n < 32; n++) begin
      fb = c[31] ^ data[n];
      c  = {c[30:0], 1'b0} ^ (fb ? SERWB_CRC_POLY : '0);
    end
    return c;
  endfunction

  // The step is linear over GF(2): serwb_crc32(c, d) = serwb_crc32(c, 0) ^
  // serwb_crc32(0, d). So a pipeline computes the data term on its own,
  // ahead of the CRC register, and the loop keeps only the c term. Both
  // terms are XOR matrices, built here from serwb_crc32 at elaboration: each
  // output bit is the XOR of the input bits its row selects, a flat XOR
  // tree, where the bit-serial form above synthesizes into a deep chain.

  typedef logic [31:0][31:0] mat32_t;  // [output bit] = which of 32 input bits
  typedef logic [31:0][63:0] mat64_t;  // [output bit] = which of 64 input bits

  // c -> the CRC after n words of zeros
  function automatic mat32_t serwb_cmat(input int n);
    mat32_t m;
    word_t  v;
    for (int j = 0; j < 32; j++) begin
      v = word_t'(1) << j;
      for (int k = 0; k < n; k++) begin
        v = serwb_crc32(v, '0);
      end
      for (int i = 0; i < 32; i++) begin
        m[i][j] = v[i];
      end
    end
    return m;
  endfunction

  // {w1, w0} -> the CRC of w0 then w1, from 0; w1 alone: the low 32 columns
  // of SERWB_D1 below
  function automatic mat64_t serwb_dmat2();
    mat64_t m;
    word_t  v;
    for (int j = 0; j < 64; j++) begin
      v = (j < 32) ? serwb_crc32(serwb_crc32('0, word_t'(1) << j), '0) :
          serwb_crc32('0, word_t'(1) << (j - 32));
      for (int i = 0; i < 32; i++) begin
        m[i][j] = v[i];
      end
    end
    return m;
  endfunction

  function automatic mat32_t serwb_dmat1();
    mat32_t m;
    word_t  v;
    for (int j = 0; j < 32; j++) begin
      v = serwb_crc32('0, word_t'(1) << j);
      for (int i = 0; i < 32; i++) begin
        m[i][j] = v[i];
      end
    end
    return m;
  endfunction

  localparam mat32_t SERWB_C1 = serwb_cmat(1);
  localparam mat32_t SERWB_C2 = serwb_cmat(2);
  localparam mat32_t SERWB_D1 = serwb_dmat1();
  localparam mat64_t SERWB_D2 = serwb_dmat2();

  function automatic word_t mul32(input mat32_t m, input word_t x);
    word_t o;
    for (int i = 0; i < 32; i++) begin
      o[i] = ^(m[i] & x);
    end
    return o;
  endfunction

  function automatic word_t mul64(input mat64_t m, input logic [63:0] x);
    word_t o;
    for (int i = 0; i < 32; i++) begin
      o[i] = ^(m[i] & x);
    end
    return o;
  endfunction

  // the data term of 0, 1 or 2 words (mask: slot 0 then slot 1), in order
  function automatic word_t serwb_crc_dterm(input word_t [1:0] w, input logic [1:0] mask);
    case (mask)
      2'b01: begin
        return mul32(SERWB_D1, w[0]);
      end
      2'b10: begin
        return mul32(SERWB_D1, w[1]);
      end
      2'b11: begin
        return mul64(SERWB_D2, {w[1], w[0]});
      end
      default: begin
        return '0;
      end
    endcase
  endfunction

  // the CRC term over n = 0, 1 or 2 words
  function automatic word_t serwb_crc_cterm(input word_t crc, input logic [1:0] n);
    case (n)
      2'd1: begin
        return mul32(SERWB_C1, crc);
      end
      2'd2: begin
        return mul32(SERWB_C2, crc);
      end
      default: begin
        return crc;
      end
    endcase
  endfunction

endpackage : iclink_serwb_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
