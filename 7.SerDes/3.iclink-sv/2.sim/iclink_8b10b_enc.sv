// SPDX-FileCopyrightText: 2016-2017 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2019-2020 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// IBM 8b/10b encoder, NWORDS symbols per clock: a SystemVerilog port of
// LiteX's litex/soc/cores/code_8b10b.py, Encoder (same tables, same
// pipeline, same output), so it talks to LiteICLink unchanged. Simulation
// only: on the chip CC_SERDES encodes (iclink_8b10b_pkg).
//
// Latency 2 clocks (with ce). Stage 1 registers the 5b/6b and 3b/4b table
// lookups; stage 2 applies the running disparity, which chains through the
// NWORDS symbols of one clock and is registered from the last one.
//==========================================================================
module iclink_8b10b_enc
  import iclink_pkg::*;
  import iclink_8b10b_pkg::*;
#(
    parameter int NWORDS    = 2,
    parameter bit LSB_FIRST = 1'b1  // bit 0 of each symbol goes on the line first
) (
    input  logic                 clk,
    input  logic                 arst_n,
    input  logic                 ce,
    input  byte_t   [NWORDS-1:0] d,
    input  logic    [NWORDS-1:0] k,         // 1: d is a K (control) character
    output symbol_t [NWORDS-1:0] symbol,
    output logic    [NWORDS-1:0] disparity  // running disparity after each symbol
);

  // stage 1: table lookups, registered
  logic    [NWORDS-1:0][5:0] code6b;
  logic    [NWORDS-1:0]      code6b_unbalanced;
  logic    [NWORDS-1:0]      code6b_flip;
  logic    [NWORDS-1:0][3:0] code4b;
  logic    [NWORDS-1:0]      code4b_unbalanced;
  logic    [NWORDS-1:0]      code4b_flip;
  logic    [NWORDS-1:0]      alt7_rd0;  // alternative D.x.7 when the disparity is -1
  logic    [NWORDS-1:0]      alt7_rd1;  // alternative D.x.7 when the disparity is +1

  // stage 2: running disparity, per symbol
  logic    [NWORDS-1:0]      disp_in;
  logic    [NWORDS-1:0]      disp_out;
  logic    [NWORDS-1:0]      disp_inter;
  logic    [NWORDS-1:0][5:0] out6b;
  logic    [NWORDS-1:0][3:0] out4b;
  symbol_t [NWORDS-1:0]      msb_first;
  logic                      disp_last;  // disparity after the last symbol of the clock

  for (genvar w = 0; w < NWORDS; w++) begin : g_word
    logic [4:0] code5b;
    logic [2:0] code3b;
    assign code5b = d[w][4:0];
    assign code3b = d[w][7:5];

    always_ff @(negedge arst_n or posedge clk) begin : _stage1
      if (!arst_n) begin
        code6b[w]            <= '0;
        code6b_unbalanced[w] <= 1'b0;
        code6b_flip[w]       <= 1'b0;
        code4b[w]            <= '0;
        code4b_unbalanced[w] <= 1'b0;
        code4b_flip[w]       <= 1'b0;
        alt7_rd0[w]          <= 1'b0;
        alt7_rd1[w]          <= 1'b0;
      end
      else if (ce) begin
        if (k[w] && code5b == 5'd28) begin
          code6b[w]            <= 6'b110000;
          code6b_unbalanced[w] <= 1'b1;
          code6b_flip[w]       <= 1'b1;
        end
        else begin
          code6b[w]            <= enc_5b6b(code5b);
          code6b_unbalanced[w] <= unbalanced_6b(enc_5b6b(code5b));
          code6b_flip[w]       <= flip_5b6b(code5b);
        end

        code4b[w] <= enc_3b4b(code3b);
        code4b_unbalanced[w] <= unbalanced_4b(enc_3b4b(code3b));
        code4b_flip[w] <= k[w] | flip_3b4b(code3b);

        alt7_rd0[w] <= (code3b == 3'd7) &&
                       (k[w] || code5b == 5'd17 || code5b == 5'd18 || code5b == 5'd20);
        alt7_rd1[w] <= (code3b == 3'd7) &&
                       (k[w] || code5b == 5'd11 || code5b == 5'd13 || code5b == 5'd14);
      end
    end : _stage1

    if (w == 0) begin : g_disp_first
      assign disp_in[w] = disp_last;
    end
    else begin : g_disp_chain
      assign disp_in[w] = disp_out[w-1];
    end

    always_comb begin : _stage2
      disp_inter[w] = disp_in[w] ^ code6b_unbalanced[w];
      out6b[w]      = (!disp_in[w] && code6b_flip[w]) ? ~code6b[w] : code6b[w];

      if (!disp_inter[w] && alt7_rd0[w]) begin
        disp_out[w] = !disp_inter[w];
        out4b[w]    = 4'b0111;
      end
      else if (disp_inter[w] && alt7_rd1[w]) begin
        disp_out[w] = !disp_inter[w];
        out4b[w]    = 4'b1000;
      end
      else begin
        disp_out[w] = disp_inter[w] ^ code4b_unbalanced[w];
        out4b[w]    = (!disp_inter[w] && code4b_flip[w]) ? ~code4b[w] : code4b[w];
      end

      msb_first[w] = {out6b[w], out4b[w]};
    end : _stage2

    always_ff @(negedge arst_n or posedge clk) begin : _out
      if (!arst_n) begin
        symbol[w]    <= '0;
        disparity[w] <= 1'b0;
      end
      else if (ce) begin
        symbol[w]    <= LSB_FIRST ? bit_reverse_10(msb_first[w]) : msb_first[w];
        disparity[w] <= disp_out[w];
      end
    end : _out
  end : g_word

  always_ff @(negedge arst_n or posedge clk) begin : _disp_state
    if (!arst_n) begin
      disp_last <= 1'b0;
    end
    else if (ce) begin
      disp_last <= disp_out[NWORDS-1];
    end
  end : _disp_state

endmodule : iclink_8b10b_enc

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
