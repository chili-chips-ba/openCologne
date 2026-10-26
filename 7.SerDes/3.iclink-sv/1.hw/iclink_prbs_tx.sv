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
//==========================================================================
module iclink_prbs_tx
  import iclink_pkg::*;
#(
    parameter int WIDTH   = 20,
    parameter bit REVERSE = 1'b1  // bit order reversed, as LiteICLink's ECP5 PHY uses it
) (
    input  logic                  clk,
    input  logic                  arst_n,
    input  prbs_cfg_t             config_i,
    input  logic      [WIDTH-1:0] i,
    output logic      [WIDTH-1:0] o,
    output prbs_cfg_t             config_o   // config_i, synchronized: what o follows
);

  logic [WIDTH-1:0] prbs7, prbs15, prbs31, prbs, prbs_ordered;
  prbs_cfg_t config_meta, config_sync;

  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(7),
      .TAP0  (5),
      .TAP1  (6)
  ) u_prbs7 (
      .clk,
      .arst_n,
      .o(prbs7)
  );
  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(15),
      .TAP0  (13),
      .TAP1  (14)
  ) u_prbs15 (
      .clk,
      .arst_n,
      .o(prbs15)
  );
  iclink_prbs_gen #(
      .WIDTH (WIDTH),
      .NSTATE(31),
      .TAP0  (27),
      .TAP1  (30)
  ) u_prbs31 (
      .clk,
      .arst_n,
      .o(prbs31)
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

  always_comb begin : _select
    unique case (config_i)
      PRBS_OFF: begin
        prbs = '0;
      end
      PRBS_7: begin
        prbs = prbs7;
      end
      PRBS_15: begin
        prbs = prbs15;
      end
      PRBS_31: begin
        prbs = prbs31;
      end
    endcase

    for (int b = 0; b < WIDTH; b++) begin
      prbs_ordered[b] = REVERSE ? prbs[WIDTH-1-b] : prbs[b];
    end

    o        = (config_sync != PRBS_OFF) ? prbs_ordered : i;
    config_o = config_sync;
  end : _select

endmodule : iclink_prbs_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
