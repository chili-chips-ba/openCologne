// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// Unit test of the SV PRBS against LiteX (vectors from gen_prbs_vectors.py,
// LiteX's own PRBSTX looped into PRBSRX in Migen simulation): PRBS7, 15 and
// 31 at 20 bits per clock, bit errors injected on the loop, pause, off
// (pass-through, count cleared), and the idle-input check. TX output and RX
// error count must match LiteX clock by clock.
//==========================================================================
module tb_prbs;
  import iclink_pkg::*;

  localparam int N = 3060;
  localparam int W = 20;

  logic         clk;
  logic         arst_n = 1'b0;
  logic [103:0] vec    [N];
  int           errors = 0;

  initial begin : _clock
    clk = 1'b0;
    forever #5 clk = ~clk;
  end : _clock

  prbs_cfg_t        tx_config, rx_config;
  logic             pause;
  logic     [W-1:0] tx_i, tx_o, flip;
  logic     [ 31:0] rx_errors;

  iclink_prbs_tx #(.WIDTH(W)) u_tx (
      .clk     (clk),
      .arst_n  (arst_n),
      .config_i(tx_config),
      .i       (tx_i),
      .o       (tx_o)
  );

  iclink_prbs_rx #(.WIDTH(W)) u_rx (
      .clk     (clk),
      .arst_n  (arst_n),
      .config_i(rx_config),
      .pause   (pause),
      .i       (tx_o ^ flip),
      .errors  (rx_errors)
  );

  task automatic apply(input int n);
    if (n < N) begin
      tx_config = prbs_cfg_t'(vec[n][101:100]);
      rx_config = prbs_cfg_t'(vec[n][97:96]);
      pause     = vec[n][92];
      tx_i      = vec[n][91:72];
      flip      = vec[n][71:52];
    end
    else begin
      {tx_config, rx_config, pause, tx_i, flip} = '0;
    end
  endtask

  initial begin
    $readmemh("vectors/prbs.hex", vec);
    apply(N);
    repeat (3) @(posedge clk);
    arst_n = 1'b1;
    for (int n = 0; n < N; n++) begin
      @(negedge clk);
      apply(n);
      @(posedge clk);
      #1 apply(n + 1);  // LiteX's read after the clock sees the next inputs
      #1;
      if (tx_o != vec[n][51:32] || rx_errors != vec[n][31:0]) begin
        errors++;
        if (errors <= 10) begin
          $display("ERROR #%0d: tx_o %h errors %0d, LiteX tx_o %h errors %0d", n, tx_o, rx_errors,
                   vec[n][51:32], vec[n][31:0]);
        end
      end
    end
    // pause holds the count (checked here: LiteX PRBSRX ignores pause)
    begin
      logic [31:0] held;
      @(negedge clk);
      {tx_config, rx_config, pause, tx_i, flip} = '0;
      tx_config = PRBS_7;
      rx_config = PRBS_7;
      repeat (8) @(negedge clk);  // config through its synchronizer
      pause = 1'b1;
      flip  = 20'h00001;  // an error every clock
      repeat (3) @(negedge clk);
      held = rx_errors;
      repeat (10) @(negedge clk);
      if (rx_errors != held) begin
        errors++;
        $display("ERROR: pause did not hold the count (%0d -> %0d)", held, rx_errors);
      end
      pause = 1'b0;
      repeat (10) @(negedge clk);
      if (rx_errors <= held) begin
        errors++;
        $display("ERROR: errors not counted after pause (%0d -> %0d)", held, rx_errors);
      end
    end

    $display("TB_PRBS: %s  %0d clocks, %0d errors, final LiteX error count %0d",
             errors == 0 ? "PASS" : "FAIL", N, errors, vec[N-1][31:0]);
    $finish;
  end

endmodule : tb_prbs
