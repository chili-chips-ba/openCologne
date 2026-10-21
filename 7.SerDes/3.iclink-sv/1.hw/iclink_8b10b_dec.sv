// SPDX-FileCopyrightText: 2016-2017 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2019-2020 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// IBM 8b/10b decoder for one symbol: a SystemVerilog port of LiteX's
// litex/soc/cores/code_8b10b.py, Decoder (sync=True). Latency 1 clock (with
// ce). It does not check the running disparity. invalid flags a symbol
// without 4, 5 or 6 ones: not every bad symbol, but enough to see a broken
// link, as in LiteX.
//==========================================================================
module iclink_8b10b_dec
  import iclink_pkg::*;
#(
    parameter bit LSB_FIRST = 1'b1  // bit 0 of the symbol came first on the line
) (
    input  logic    clk,
    input  logic    arst_n,
    input  logic    ce,
    input  symbol_t symbol,
    output byte_t   d,
    output logic    k,       // 1: d is a K (control) character
    output logic    invalid
);

  symbol_t       msb_first;
  logic    [5:0] code6b;
  logic    [3:0] code4b;
  logic    [4:0] code5b;
  logic    [2:0] code3b;
  logic    [3:0] ones;

  assign msb_first = LSB_FIRST ? bit_reverse_10(symbol) : symbol;
  assign code6b    = msb_first[9:4];
  assign code4b    = msb_first[3:0];

  always_ff @(negedge arst_n or posedge clk) begin : _decode
    if (!arst_n) begin
      code5b <= '0;
      code3b <= '0;
      k      <= 1'b0;
      ones   <= '0;
    end
    else if (ce) begin
      code5b <= dec_6b5b(code6b);
      ones   <= 4'($countones(symbol));

      if (code6b == 6'b001111) begin
        k      <= 1'b1;
        code3b <= dec_4b3b_kn(code4b);
      end
      else if (code6b == 6'b110000) begin
        k      <= 1'b1;
        code3b <= dec_4b3b_kp(code4b);
      end
      else begin
        // D.x.A7 / K.x.7: the alternative x.7 is a K unless the 6b allows it
        k <= (code4b == 4'b0111 || code4b == 4'b1000) &&
             !(code6b inside {6'b100011, 6'b010011, 6'b001011,
                              6'b110100, 6'b101100, 6'b011100});
        code3b <= dec_4b3b(code4b);
      end
    end
  end : _decode

  assign d       = {code3b, code5b};
  assign invalid = !(ones inside {4'd4, 4'd5, 4'd6});

endmodule : iclink_8b10b_dec

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
