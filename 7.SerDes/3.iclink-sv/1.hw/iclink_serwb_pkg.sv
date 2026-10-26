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

  localparam word_t SERWB_PREAMBLE  = 32'h5AA5_5AA5;

  // a packet's payload in words, 1 .. SERWB_MAX_WORDS: length[23:10]
  localparam int    SERWB_MAX_WORDS = 16383;
  typedef logic [13:0] serwb_len_t;

  // K words between packets, the K flag on byte 0 (doc/serwb.md)
  localparam word_t SERWB_FILL         = {24'h0, 8'h3C};  // K28.1
  localparam word_t SERWB_XOFF         = {24'h0, 8'h7C};  // K28.3
  localparam word_t SERWB_XON          = {24'h0, 8'h9C};  // K28.4

  // the depacketizer timeout, as LiteICLink: 1 ms at 2.5 Gb/s (31.25 MHz)
  localparam int    SERWB_TIMEOUT_CLKS = 31250;

  // a status counter (CRC errors, drops, overflows): adds n, stops at all ones
  typedef logic [15:0] serwb_cnt_t;

  function automatic serwb_cnt_t serwb_count(input serwb_cnt_t c, input logic [1:0] n);
    logic [16:0] s;
    s = {1'b0, c} + 17'(n);
    return s[16] ? '1 : s[15:0];
  endfunction

  // CRC32 as LiteICLink's _CRC32 (LiteEth's CRC engine): IEEE polynomial,
  // reset to all ones at each preamble, data bit 0 first, MSB-first shift,
  // no final inversion or reflection
  localparam word_t SERWB_CRC_POLY = 32'h04C1_1DB7;
  localparam word_t SERWB_CRC_INIT = 32'hFFFF_FFFF;

  // the port / length word: [7:0] port, [23:8] length in bytes, [31:24] 0
  function automatic word_t serwb_header(input logic [7:0] port, input serwb_len_t words);
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
  // ahead of the CRC register, and the loop keeps only the c term. Over one
  // clock of words, the data term is the XOR of each word's own term, which
  // depends only on how many covered words follow it in that clock. All
  // terms are XOR matrices, built here from serwb_crc32 at elaboration: each
  // output bit is the XOR of the input bits its row selects, a flat XOR
  // tree, where the bit-serial form above synthesizes into a deep chain.

  typedef logic [31:0][31:0] mat32_t;  // [output bit] = which of 32 input bits

  localparam int SERWB_W_MAX = 4;  // words a clock, at most

  typedef mat32_t [SERWB_W_MAX:0] mats_t;
  typedef word_t [SERWB_W_MAX:0] words_t;

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

  // w -> the CRC of w, then of k words of zeros, from 0: the data term of
  // a word with k covered words after it in the same clock
  function automatic mat32_t serwb_mmat(input int k);
    mat32_t m;
    word_t  v;
    for (int j = 0; j < 32; j++) begin
      v = serwb_crc32('0, word_t'(1) << j);
      for (int n = 0; n < k; n++) begin
        v = serwb_crc32(v, '0);
      end
      for (int i = 0; i < 32; i++) begin
        m[i][j] = v[i];
      end
    end
    return m;
  endfunction

  function automatic mats_t serwb_cmats();
    mats_t m;
    for (int n = 0; n <= SERWB_W_MAX; n++) begin
      m[n] = serwb_cmat(n);
    end
    return m;
  endfunction

  function automatic mats_t serwb_mmats();
    mats_t m;
    for (int k = 0; k <= SERWB_W_MAX; k++) begin
      m[k] = serwb_mmat(k);
    end
    return m;
  endfunction

  // SERWB_CRC_INIT after n words of zeros
  function automatic words_t serwb_iwords();
    words_t v;
    v[0] = SERWB_CRC_INIT;
    for (int n = 1; n <= SERWB_W_MAX; n++) begin
      v[n] = serwb_crc32(v[n-1], '0);
    end
    return v;
  endfunction

  localparam mats_t  SERWB_C = serwb_cmats();
  localparam mats_t  SERWB_M = serwb_mmats();
  localparam words_t SERWB_I = serwb_iwords();

  function automatic word_t mul32(input mat32_t m, input word_t x);
    word_t o;
    for (int i = 0; i < 32; i++) begin
      o[i] = ^(m[i] & x);
    end
    return o;
  endfunction

  // Each branch below multiplies by a constant matrix, a flat XOR tree, and
  // the case only picks a result. Indexing SERWB_C by a signal instead would
  // put a matrix mux in front of the AND gates.

  // the CRC term over n = 0 .. 4 words
  function automatic word_t serwb_crc_cterm(input word_t crc, input logic [2:0] n);
    word_t r;
    unique case (n)
      3'd0: begin
        r = crc;
      end
      3'd1: begin
        r = mul32(SERWB_C[1], crc);
      end
      3'd2: begin
        r = mul32(SERWB_C[2], crc);
      end
      3'd3: begin
        r = mul32(SERWB_C[3], crc);
      end
      3'd4: begin
        r = mul32(SERWB_C[4], crc);
      end
    endcase
    return r;
  endfunction

  // the data term of one word with k = 0 .. 3 covered words after it
  function automatic word_t serwb_crc_mterm(input word_t w, input logic [1:0] k);
    unique case (k)
      2'd0: begin
        return mul32(SERWB_M[0], w);
      end
      2'd1: begin
        return mul32(SERWB_M[1], w);
      end
      2'd2: begin
        return mul32(SERWB_M[2], w);
      end
      2'd3: begin
        return mul32(SERWB_M[3], w);
      end
    endcase
  endfunction

  // the INIT term of a packet start with n = 0 .. 4 covered words after it:
  // a constant per n, so a start costs the CRC loop nothing (it goes into
  // the data term)
  function automatic word_t serwb_crc_iterm(input logic [2:0] n);
    word_t r;
    unique case (n)
      3'd0: begin
        r = SERWB_I[0];
      end
      3'd1: begin
        r = SERWB_I[1];
      end
      3'd2: begin
        r = SERWB_I[2];
      end
      3'd3: begin
        r = SERWB_I[3];
      end
      3'd4: begin
        r = SERWB_I[4];
      end
    endcase
    return r;
  endfunction

endpackage : iclink_serwb_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
