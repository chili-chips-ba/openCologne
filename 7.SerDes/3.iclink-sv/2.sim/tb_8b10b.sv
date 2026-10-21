// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Unit test of the SV 8b/10b against LiteX (vectors from
// gen_8b10b_vectors.py, LiteX's own Encoder/Decoder in Migen simulation):
//  1. encoder, 2 symbols per clock: symbol and disparity match LiteX, clock
//     by clock
//  2. decoder, all 1024 symbols: d, k and invalid match LiteX
//  3. round trip: every encoded character decodes back to itself
//  4. running disparity of the encoded stream, checked from the 8b/10b
//     rule itself: each symbol has 4, 5 or 6 ones, and an unbalanced symbol
//     always takes the disparity to the other side
//==========================================================================
module tb_8b10b;
  import iclink_pkg::*;

  localparam int NENC = 4548;
  localparam int NDEC = 1024;

  logic                 clk;
  logic                 arst_n = 1'b0;
  logic        [55:0]   enc_vec [NENC];
  logic        [27:0]   dec_vec [NDEC];
  int                   errors = 0;

  initial begin : _clock
    clk = 1'b0;
    forever #5 clk = ~clk;
  end : _clock

  // DUTs ---------------------------------------------------------------------
  byte_t   [1:0] d;
  logic    [1:0] k;
  symbol_t [1:0] symbol;
  logic    [1:0] disparity;

  iclink_8b10b_enc #(.NWORDS(2)) u_enc (
      .clk      (clk),
      .arst_n   (arst_n),
      .ce       (1'b1),
      .d        (d),
      .k        (k),
      .symbol   (symbol),
      .disparity(disparity)
  );

  byte_t [1:0] rt_d;
  logic  [1:0] rt_k;
  logic  [1:0] rt_invalid;

  for (genvar w = 0; w < 2; w++) begin : g_rt
    iclink_8b10b_dec u_dec (
        .clk    (clk),
        .arst_n (arst_n),
        .ce     (1'b1),
        .symbol (symbol[w]),
        .d      (rt_d[w]),
        .k      (rt_k[w]),
        .invalid(rt_invalid[w])
    );
  end

  symbol_t ex_symbol;
  byte_t   ex_d;
  logic    ex_k;
  logic    ex_invalid;

  iclink_8b10b_dec u_dec_ex (
      .clk    (clk),
      .arst_n (arst_n),
      .ce     (1'b1),
      .symbol (ex_symbol),
      .d      (ex_d),
      .k      (ex_k),
      .invalid(ex_invalid)
  );

  task automatic fail(input string msg);
    errors++;
    if (errors <= 10) $display("%t ERROR: %s", $time, msg);
  endtask

  // 1, 3, 4: encoder vs LiteX, round trip, running disparity --------------
  task automatic run_encoder();
    logic [8:0] in_q[$];  // {k, d} of the characters sent, for the round trip
    int         rd;       // running disparity: -1 or +1
    rd = -1;
    for (int n = 0; n < NENC; n++) begin
      @(negedge clk);
      {d[0], k[0], d[1], k[1]} = {enc_vec[n][55:48], enc_vec[n][44], enc_vec[n][43:36], enc_vec[n][32]};
      in_q.push_back({k[0], d[0]});
      in_q.push_back({k[1], d[1]});
      @(posedge clk);
      #1;
      if (symbol != {enc_vec[n][17:8], enc_vec[n][29:20]}) begin
        fail($sformatf("enc #%0d: symbol %h %h, LiteX %h %h", n, symbol[0], symbol[1],
                       enc_vec[n][29:20], enc_vec[n][17:8]));
      end
      if (disparity != {enc_vec[n][0], enc_vec[n][4]}) begin
        fail($sformatf("enc #%0d: disparity %b, LiteX %b%b", n, disparity, enc_vec[n][0],
                       enc_vec[n][4]));
      end
      if (n >= 1) begin  // a character shows one clock later: stage 1, then the output reg
        for (int w = 0; w < 2; w++) begin
          int ones = $countones(symbol[w]);
          if (!(ones inside {4, 5, 6})) fail($sformatf("enc #%0d: %0d ones", n, ones));
          if (ones != 5) begin
            if ((ones > 5) != (rd < 0)) fail($sformatf("enc #%0d: disparity rule broken", n));
            rd = -rd;
          end
        end
      end
      if (n >= 2) begin  // and is decoded 1 clock after that
        for (int w = 0; w < 2; w++) begin
          logic [8:0] exp = in_q.pop_front();
          if ({rt_k[w], rt_d[w]} != exp || rt_invalid[w]) begin
            fail($sformatf("round trip #%0d word %0d: got k%b %h, sent k%b %h", n, w, rt_k[w],
                           rt_d[w], exp[8], exp[7:0]));
          end
        end
      end
    end
  endtask

  // 2: decoder vs LiteX, all 1024 symbols ----------------------------------
  task automatic run_decoder();
    for (int n = 0; n < NDEC; n++) begin
      @(negedge clk);
      ex_symbol = dec_vec[n][25:16];
      @(posedge clk);
      #1;
      if ({ex_d, ex_k, ex_invalid} != {dec_vec[n][15:8], dec_vec[n][4], dec_vec[n][0]}) begin
        fail($sformatf("dec %h: d %h k %b invalid %b, LiteX d %h k %b invalid %b", ex_symbol,
                       ex_d, ex_k, ex_invalid, dec_vec[n][15:8], dec_vec[n][4], dec_vec[n][0]));
      end
    end
  endtask

  initial begin
    $readmemh("vectors/enc.hex", enc_vec);
    $readmemh("vectors/dec.hex", dec_vec);
    d         = '0;
    k         = '0;
    ex_symbol = '0;
    repeat (3) @(posedge clk);
    arst_n = 1'b1;
    fork
      run_encoder();
      run_decoder();
    join
    $display("TB_8B10B: %s  %0d encoder clocks, %0d decoder symbols, %0d errors",
             errors == 0 ? "PASS" : "FAIL", NENC, NDEC, errors);
    $finish;
  end

endmodule : tb_8b10b
