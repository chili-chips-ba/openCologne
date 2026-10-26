// SPDX-FileCopyrightText: 2015-2019 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2015 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// PRBS TX of a SerDes datapath: a SystemVerilog port of LiteX's
// litex/soc/cores/prbs.py PRBSTX. config 0 passes i through; 1, 2, 3 send
// PRBS7, 15, 31. config is synchronized (2 flops) for the pass/PRBS choice;
// the PRBS select uses it as is, as in LiteX, so config_i must come from
// this clock or a synchronizer. config_o is the synchronized choice, for
// logic that must agree with o.
//
// Not in LiteX: while PRBS is on and CLKCOR_EVERY > 0, the last
// CLKCOR_BURST clocks of every CLKCOR_EVERY send CLKCOR_WORD instead
// (clkcor_o high), and the generators hold, so the RX checker skips them
// and stays locked. CLKCOR_EVERY = 0: off, bit-exact with LiteX.
//==========================================================================
module iclink_prbs_tx
  import iclink_pkg::*;
#(
    parameter int               WIDTH        = 20,
    // bit order reversed, as LiteICLink's GateMate PHY uses it
    parameter bit               REVERSE      = 1'b1,
    parameter int               CLKCOR_EVERY = 0,     // clocks; 0: no clock-correction words
    parameter int               CLKCOR_BURST = 4,     // correction words in a row
    parameter logic [WIDTH-1:0] CLKCOR_WORD  = '0
) (
    input  logic                  clk,
    input  logic                  arst_n,
    input  prbs_cfg_t             config_i,
    input  logic      [WIDTH-1:0] i,
    output logic      [WIDTH-1:0] o,
    output prbs_cfg_t             config_o,  // config_i, synchronized: what o follows
    output logic                  clkcor_o   // o is CLKCOR_WORD
);

  logic [WIDTH-1:0] prbs7, prbs15, prbs31, prbs, prbs_ordered;
  prbs_cfg_t config_meta, config_sync;
  logic clkcor;  // a correction word this clock: the generators hold

  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(7),
      .TAP0  (5),
      .TAP1  (6)
  ) u_prbs7 (
      .clk,
      .arst_n,
      .ce(!clkcor),
      .o (prbs7)
  );
  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(15),
      .TAP0  (13),
      .TAP1  (14)
  ) u_prbs15 (
      .clk,
      .arst_n,
      .ce(!clkcor),
      .o (prbs15)
  );
  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(31),
      .TAP0  (27),
      .TAP1  (30)
  ) u_prbs31 (
      .clk,
      .arst_n,
      .ce(!clkcor),
      .o (prbs31)
  );

  always_ff @(negedge arst_n or posedge clk) begin : _sync
    if (!arst_n) begin
      config_meta <= PRBS_OFF;
      config_sync <= PRBS_OFF;
    end
    else begin
      config_meta <= config_i;
      config_sync <= config_meta;
    end
  end : _sync

  if (CLKCOR_EVERY > 0) begin : g_clkcor
    localparam int CNT_W = $clog2(CLKCOR_EVERY);
    logic [CNT_W-1:0] cnt;

    if (CLKCOR_BURST < 1 || CLKCOR_BURST >= CLKCOR_EVERY) begin : g_bad_burst
      $error("iclink_prbs_tx: CLKCOR_BURST %0d: use 1 to CLKCOR_EVERY - 1", CLKCOR_BURST);
    end : g_bad_burst

    always_ff @(negedge arst_n or posedge clk) begin
      if (!arst_n) begin
        cnt    <= '0;
        clkcor <= 1'b0;
      end
      else if (config_sync == PRBS_OFF) begin
        cnt    <= '0;
        clkcor <= 1'b0;
      end
      else begin
        cnt <= (cnt == CNT_W'(CLKCOR_EVERY - 1)) ? '0 : cnt + 1'b1;
        clkcor <= cnt >= CNT_W'(CLKCOR_EVERY - CLKCOR_BURST - 1) && cnt != CNT_W'(CLKCOR_EVERY - 1);
      end
    end
  end : g_clkcor
  else begin : g_no_clkcor
    assign clkcor = 1'b0;
  end : g_no_clkcor

  always_comb begin : _select
    unique case (config_i)
      PRBS_OFF: prbs = '0;
      PRBS_7:   prbs = prbs7;
      PRBS_15:  prbs = prbs15;
      PRBS_31:  prbs = prbs31;
    endcase

    for (int b = 0; b < WIDTH; b++) begin
      prbs_ordered[b] = REVERSE ? prbs[WIDTH-1-b] : prbs[b];
    end

    if (config_sync == PRBS_OFF) begin
      o = i;
    end
    else begin
      o = clkcor ? CLKCOR_WORD : prbs_ordered;
    end
    config_o = config_sync;
    clkcor_o = clkcor;
  end : _select

endmodule : iclink_prbs_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
