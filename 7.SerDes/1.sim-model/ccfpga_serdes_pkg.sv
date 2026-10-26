// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
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
//   Shared by every SerDes BFM (ccfpga_serdes.sv): its settings, the NONE
//   word channel, and pure functions: the 8b/10b codec, PRBS, PLL divider.
//   formal_8b10b/ proves enc8b10b() and dec8b10b() from this package.
//
//   HI, LO        logic levels; TRUE, FALSE flags
//   CDR_MODEL     NONE, FAST or ACCURATE, one for every BFM
//   BHV_*         the BFM's own settings, e.g. the random RX word phase
//   cdr_none_*    CDR_MODEL = NONE: the words between BFMs, by TX
//   enc8b10b()    8b/10b encoder: {rd_out, abcdei fghj} from data, K flag
//                 and running disparity in
//   dec8b10b()    decoder of one 10-bit symbol: {valid, k, data}; 0 for a
//                 symbol that is not in the code table
//   dec_disp()    running disparity of a symbol, per 6b and 4b sub-block:
//                 {error, rd out} from rd in
//   kcode()       the 12 legal K codes, index 0 to 11
//   ones10()      number of ones in a 10-bit symbol
//   prbs_next()   next state of the PRBS7/15/23/31 LFSR
//   pll_m1_x4()   the PLL word clock divider M1, times 4, from PLL_FCNTRL
//   csr_t         the registers
//   rx_raw_t      one deserializer word, and what the comma aligner lets
//                 through
//   rx_byte_t     one decoded byte in the RX elastic buffer; rx_word_t: 8
//   dp_lanes()    lanes of a 16/32/64-bit datapath word
//   dp_keep()     a word's datapath lanes over another's
//   clkcor_match() a word is the clock-correction sequence
//==========================================================================

package ccfpga_serdes_pkg;

  localparam bit HI    = 1'b1;  // levels
  localparam bit LO    = 1'b0;
  localparam bit TRUE  = 1'b1;  // flags
  localparam bit FALSE = 1'b0;

  // CDR_MODEL, the serial line and the receiver:
  //   NONE      no line: words go beside the pins, both ends NONE (fastest);
  //             P and N only enumerate who talks to whom
  //   FAST      a real line; bits from the time between its edges
  //   ACCURATE  a real line; a sampler every UI, steered by a CDR loop
  typedef enum int {
    NONE,
    FAST,
    ACCURATE
  } cdr_model_t;

  // One mode for every BFM in the simulation: the parameter list stays the
  // SerDes's, and NONE talks only to NONE. Pick it at compile time, e.g.
  // +define+CDR_MODEL=FAST (Verilator), -DCDR_MODEL=FAST (Icarus).
`ifdef CDR_MODEL
  localparam cdr_model_t CDR_MODEL = `CDR_MODEL;
`else
  localparam cdr_model_t CDR_MODEL = NONE;
`endif

  // The BFM's own settings, the same for every BFM; the SerDes has none of
  // them. Edit them here.
  localparam real BHV_PLL_LOCK_TIME_NS  = 500.0;  // PLL reset to lock
  localparam real BHV_REF_CLK_MHZ       = 0.0;    // reference clock; 0: measured
  localparam int  BHV_RX_PRESENT        = 1;      // receiver detection finds a far end
  localparam real BHV_RX_DETECT_TIME_NS = 120.0;  // receiver detection time
  localparam real BHV_CDR_KP            = 0.125;  // ACCURATE: CDR loop gain
  localparam int  BHV_CDR_LOCK_EDGES    = 32;     // line edges to CDR lock
  localparam bit  BHV_VERBOSE           = 0;      // debug prints
  localparam int  BHV_RX_PIPE_STAGES    = 3;      // RX output delay, in clocks
  localparam real BHV_RX_TCO_NS         = 0.1;    // RX clock to outputs

  // The RX word counter starts at a random symbol at each RX start, as on
  // the silicon: the comma then lands in any lane ALIGN_COMMA_WORD allows
  // (any; even; 0 or 4). Logic that assumes lane 0 fails here, not on the
  // board. Off (+define+BHV_RX_WORD_PHASE_RANDOM=0): it starts in phase
  // with PLL_CLK_O.
`ifdef BHV_RX_WORD_PHASE_RANDOM
  localparam bit BHV_RX_WORD_PHASE_RANDOM = `BHV_RX_WORD_PHASE_RANDOM;
`else
  localparam bit BHV_RX_WORD_PHASE_RANDOM = TRUE;
`endif

  // CDR_MODEL = NONE. P and N only enumerate: each RX learns its peer, the
  // TX at the far end of its pins. Then the words go through here, by TX
  // ID: the word each TX started last, and a count of its words, which
  // every RX listening to it waits on. Words are the line bits, the first
  // in bit 0.
  localparam int CDR_NONE_ID_BITS = 8;
  localparam int CDR_NONE_MAX     = 1 << CDR_NONE_ID_BITS;  // NONE BFMs at most

  // static: Icarus 13.0 crashes on an event control on a dynamic array
  int        cdr_none_words[CDR_NONE_MAX];
  int        cdr_none_bytes[CDR_NONE_MAX];  // each TX's symbols a word
  bit [79:0] cdr_none_last [CDR_NONE_MAX];  // each TX's word on the line

  int cdr_none_id = 0;  // the next ID: each NONE BFM takes one at time 0

  function automatic int cdr_none_new_id(int tx_bytes);
    int id = cdr_none_id;
    cdr_none_id++;
    if (id >= CDR_NONE_MAX) begin
      $fatal(1, "more than %0d SerDes BFMs with CDR_MODEL = NONE", CDR_NONE_MAX);
    end
    cdr_none_bytes[id] = tx_bytes;
    return id;
  endfunction

  function automatic bit cdr_none_valid(int id);
    return (id >= 0) && (id < cdr_none_id);
  endfunction

  // M1 x 4 for a PLL_FCNTRL value (DS1001 Table 2.17). 10, 53, 54 and 55
  // give 5.0, 15.0, 16.0 and 16.0 here; the table says 5.25, 15.75, 16.5
  // and 16.5.
  function automatic int pll_m1_x4(input bit [5:0] fcntrl);
    case (int'(fcntrl))
      0, 1: return 4;  // the alternative clock path: param_check stops it
      2: return 12;
      3, 4: return 14;
      5: return 15;
      6, 7: return 16;
      8: return 18;
      9: return 21;
      10: return 20;
      11, 12: return 22;
      13: return 23;
      14, 15, 16, 18: return 24;
      17, 19, 20: return 28;
      21: return 30;
      22, 23: return 32;
      24, 32, 34: return 36;
      26: return 40;
      25, 33, 35, 36: return 42;
      27, 28: return 44;
      37: return 45;
      29: return 46;
      30, 31, 38, 39, 48, 50: return 48;
      40: return 54;
      49, 51, 52: return 56;
      42: return 60;
      41: return 63;
      53: return 60;
      54, 55: return 64;
      43, 44: return 66;
      45: return 69;
      46, 47, 56: return 72;
      58: return 80;
      57: return 84;
      59, 60: return 88;
      61: return 92;
      62, 63: return 96;
      default: return 4;
    endcase
  endfunction

  // Bit order on the wire: abcdei is sent a first, the code tables below
  // are written in table order and reversed on output
  function automatic bit [5:0] rev6(input bit [5:0] v);
    return {v[0], v[1], v[2], v[3], v[4], v[5]};
  endfunction

  function automatic bit [3:0] rev4(input bit [3:0] v);
    return {v[0], v[1], v[2], v[3]};
  endfunction

  // 5b/6b code for running disparity minus
  function automatic bit [5:0] enc6_rdm(input bit [4:0] x);
    bit [5:0] c;
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

  function automatic bit enc6_unbal(input bit [4:0] x);
    bit [5:0] c;
    bit [2:0] ones;
    c    = enc6_rdm(x);
    ones = 3'd0;
    for (int i = 0; i < 6; i++) begin
      ones = ones + c[i];
    end
    return (ones != 3'd3);
  endfunction

  // D.07 is balanced but still has a positive-disparity form
  function automatic bit enc6_flip(input bit [4:0] x);
    return enc6_unbal(x) || (x == 5'd7);
  endfunction

  // 3b/4b code for running disparity minus; alt7 selects the D.x.A7 form
  function automatic bit [3:0] enc4_rdm(input bit [2:0] y, input bit k, input bit alt7);
    bit [3:0] c;
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

  function automatic bit enc4_unbal(input bit [2:0] y, input bit k, input bit alt7);
    bit [3:0] c;
    bit [2:0] ones;
    c    = enc4_rdm(y, k, alt7);
    ones = 3'd0;
    for (int i = 0; i < 4; i++) begin
      ones = ones + c[i];
    end
    return (ones != 3'd2);
  endfunction

  // D.x.3 is balanced but still has a positive-disparity form
  function automatic bit enc4_flip(input bit [2:0] y, input bit k, input bit alt7);
    return k ? TRUE : (enc4_unbal(y, k, alt7) || (y == 3'd3));
  endfunction

  function automatic bit [10:0] enc8b10b(input bit [7:0] din, input bit k,
                                           input bit rd_in);
    bit [4:0] x;
    bit [2:0] y;
    bit [5:0] c6;
    bit [3:0] c4;
    bit       rd_mid;
    bit       rd_out;
    bit       alt7;

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

    alt7 = FALSE;
    if (!k && (y == 3'd7)) begin
      if (!rd_mid && ((x == 5'd17) || (x == 5'd18) || (x == 5'd20))) begin
        alt7 = TRUE;
      end
      if (rd_mid && ((x == 5'd11) || (x == 5'd13) || (x == 5'd14))) begin
        alt7 = TRUE;
      end
    end

    c4     = (rd_mid && enc4_flip(y, k, alt7)) ? ~enc4_rdm(y, k, alt7) : enc4_rdm(y, k, alt7);
    rd_out = rd_mid ^ enc4_unbal(y, k, alt7);

    return {rd_out, rev4(c4), rev6(c6)};
  endfunction

  function automatic bit [3:0] ones10(input bit [9:0] v);
    bit [3:0] n;
    n = 4'd0;
    for (int i = 0; i < 10; i++) begin
      n = n + v[i];
    end
    return n;
  endfunction

  // The 12 legal K codes: K28.0 to K28.7, K23.7, K27.7, K29.7, K30.7
  function automatic bit [7:0] kcode(input int idx);
    bit [7:0] c;
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
  function automatic bit [9:0] dec8b10b(input bit [9:0] sym);
    bit [10:0] e;
    bit [ 9:0] ent;
    ent = 10'h0;
    for (int d = 0; d < 256; d++) begin
      for (int r = 0; r < 2; r++) begin
        e = enc8b10b(d[7:0], FALSE, r[0]);
        if (e[9:0] == sym) begin
          ent = {TRUE, FALSE, d[7:0]};
        end
      end
    end
    for (int d = 0; d < 12; d++) begin
      for (int r = 0; r < 2; r++) begin
        e = enc8b10b(kcode(d), TRUE, r[0]);
        if (e[9:0] == sym) begin
          ent = {TRUE, TRUE, kcode(d)};
        end
      end
    end
    return ent;
  endfunction

  // One sub-block (IEEE 802.3 Clause 36.2.4): the running disparity at its
  // end is positive with more ones, or 000111 / 0011; negative with more
  // zeros, or 111000 / 1100; else as at its start. The form for the other
  // running disparity is an error. {error, rd out}.
  function automatic bit [1:0] dec_sub(input int ones, input int n, input bit pos_sp,
                                       input bit neg_sp, input bit rd);
    if ((2 * ones > n) || pos_sp) begin
      return {(2 * ones > n) ? rd : ~rd, HI};
    end
    if ((2 * ones < n) || neg_sp) begin
      return {(2 * ones < n) ? ~rd : rd, LO};
    end
    return {FALSE, rd};
  endfunction

  // A symbol's running disparity, 6b then 4b sub-block: {error, rd out}
  function automatic bit [1:0] dec_disp(input bit [9:0] sym, input bit rd);
    bit [5:0] c6;
    bit [3:0] c4;
    bit [1:0] a, b;
    int       o6, o4;
    c6 = rev6(sym[5:0]);  // table order: abcdei, fghj
    c4 = rev4(sym[9:6]);
    o6 = 0;
    o4 = 0;
    for (int i = 0; i < 6; i++) begin
      o6 += int'(c6[i]);
    end
    for (int i = 0; i < 4; i++) begin
      o4 += int'(c4[i]);
    end
    a = dec_sub(o6, 6, c6 == 6'b000111, c6 == 6'b111000, rd);
    b = dec_sub(o4, 4, c4 == 4'b0011, c4 == 4'b1100, a[0]);
    return {a[1] | b[1], b[0]};
  endfunction

  // PRBS7 (sel 1), PRBS15 (2), PRBS23 (3), PRBS31 (4): not inverted
  function automatic bit [30:0] prbs_next(input bit [30:0] state, input bit [2:0] sel);
    bit fb;
    fb = state[6] ^ state[5];
    unique0 case (sel)
      3'b010: begin fb = state[14] ^ state[13]; end
      3'b011: begin fb = state[22] ^ state[17]; end
      3'b100: begin fb = state[30] ^ state[27]; end
    endcase
    return {state[29:0], fb};
  endfunction

  // One decoded byte, as the RX elastic buffer holds it
  typedef struct packed {
    bit       comma;
    bit       k;
    bit       disp;  // disparity error
    bit       nit;   // not in table
    bit [7:0] d;
  } rx_byte_t;

  typedef rx_byte_t [7:0] rx_word_t;

  // One deserializer word, and what the comma aligner lets through: pass,
  // the word reaches the decoder; open, the decoder decodes it
  typedef struct packed {
    bit        pass;
    bit        open;
    bit [79:0] sym;
  } rx_raw_t;

  // RX_BUF_CFG (regfile 0x25)
  typedef struct packed {
    bit [1:0] rsvd;
    bit [5:0] max_lat;     // RX_CLKCOR_MAX_LAT
    bit [5:0] min_lat;     // RX_CLKCOR_MIN_LAT
    bit       clkcor_use;  // RX_CLKCOR_USE
    bit       bypass;      // RX_BUF_BYPASS
  } rx_buf_cfg_t;

  // SERDES_CFG (0x5C)
  typedef struct packed {
    bit testmode;
    bit auto_init;  // RX_SERDES_AUTO_INIT
    bit en;         // the SerDes enable
  } serdes_cfg_t;

  // The registers the model uses. PLL_CFG0/1 hold the settings in use: they
  // change only while the PLL is off, or from the config file.
  typedef struct packed {
    rx_buf_cfg_t    rx_buf_cfg;     // 0x25
    bit [3:0][15:0] rx_clkcor_seq;  // 0x26..0x29: RX_CLKCOR_SEQ_1_0..3
    bit [11:0]      pll_cfg0;       // 0x50
    bit [13:0]      pll_cfg1;       // 0x51
    serdes_cfg_t    serdes_cfg;     // 0x5C
  } csr_t;

  // Lanes of a datapath word: 16, 32 or 64 bits (RX_DATAPATH_SEL 0, 1, 2/3)
  function automatic bit [7:0] dp_lanes(input bit [1:0] sel);
    return sel[1] ? 8'hFF : sel[0] ? 8'h0F : 8'h03;
  endfunction

  // w in the lanes of the datapath, old in the others
  function automatic rx_word_t dp_keep(input rx_word_t old, input rx_word_t w,
                                       input bit [1:0] sel);
    rx_word_t r;
    bit [7:0] ln;
    ln = dp_lanes(sel);
    for (int i = 0; i < 8; i++) begin
      r[i] = ln[i] ? w[i] : old[i];
    end
    return r;
  endfunction

  // A clock-correction word: every lane holds byte (lane mod 4) of the
  // sequence, {comma, k, data} = RX_CLKCOR_SEQ_1_0..3. The disparity and
  // not-in-table flags take no part; unused lanes always match.
  function automatic bit clkcor_match(input rx_word_t w, input bit [3:0][9:0] seq,
                                        input bit [1:0] sel);
    bit       ok;
    bit [7:0] ln;
    rx_byte_t b;
    ok = TRUE;
    ln = dp_lanes(sel);
    for (int i = 0; i < 8; i++) begin
      b = w[i];  // Icarus 13.0 takes no w[i].field with a variable i
      if (ln[i] && ({b.comma, b.k, b.d} != seq[i%4])) begin
        ok = FALSE;
      end
    end
    return ok;
  endfunction

endpackage

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
