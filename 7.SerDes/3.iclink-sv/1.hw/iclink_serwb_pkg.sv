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

endpackage : iclink_serwb_pkg

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
