// SPDX-FileCopyrightText: 2015-2019 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2015 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// PRBS RX of a SerDes datapath: a SystemVerilog port of LiteX's
// litex/soc/cores/prbs.py PRBSRX. Counts the clocks with an error for the
// PRBS that config selects (0 clears the count); pause holds the count.
// The count stops at its top, all ones, rather than wrap.
// Unlike LiteX, pause works there: in LiteX, ~False is -1 in Python, which
// makes ~pause wide and never 0.
//==========================================================================
module iclink_prbs_rx
  import iclink_pkg::*;
#(
    parameter int WIDTH        = 20,
    parameter bit REVERSE      = 1'b1,
    parameter int ERRORS_WIDTH = 32,
    parameter bit PIPE_IDLE    = 1'b0   // see iclink_prbs_chk
) (
    input  logic                         clk,
    input  logic                         arst_n,
    input  prbs_cfg_t                    config_i,
    input  logic                         pause,
    input  logic      [       WIDTH-1:0] i,
    output logic      [ERRORS_WIDTH-1:0] errors
);

  logic [WIDTH-1:0] data, err7, err15, err31;
  prbs_cfg_t config_meta, config_sync;
  logic error;

  always_comb begin : _order
    for (int b = 0; b < WIDTH; b++) begin
      data[b] = REVERSE ? i[WIDTH-1-b] : i[b];
    end
  end : _order

  iclink_prbs_chk #(
      .WIDTH    (WIDTH),
      .NSTATE   (7),
      .TAP0     (5),
      .TAP1     (6),
      .PIPE_IDLE(PIPE_IDLE)
  ) u_chk7 (
      .clk,
      .arst_n,
      .i     (data),
      .errors(err7)
  );
  iclink_prbs_chk #(
      .WIDTH    (WIDTH),
      .NSTATE   (15),
      .TAP0     (13),
      .TAP1     (14),
      .PIPE_IDLE(PIPE_IDLE)
  ) u_chk15 (
      .clk,
      .arst_n,
      .i     (data),
      .errors(err15)
  );
  iclink_prbs_chk #(
      .WIDTH    (WIDTH),
      .NSTATE   (31),
      .TAP0     (27),
      .TAP1     (30),
      .PIPE_IDLE(PIPE_IDLE)
  ) u_chk31 (
      .clk,
      .arst_n,
      .i     (data),
      .errors(err31)
  );

  always_ff @(negedge arst_n or posedge clk) begin : _count
    if (!arst_n) begin
      config_meta <= PRBS_OFF;
      config_sync <= PRBS_OFF;
      error       <= 1'b0;
      errors      <= '0;
    end
    else begin
      config_meta <= config_i;
      config_sync <= config_meta;

      unique case (config_sync)
        PRBS_OFF: begin
          error <= 1'b0;
        end
        PRBS_7: begin
          error <= err7 != '0;
        end
        PRBS_15: begin
          error <= err15 != '0;
        end
        PRBS_31: begin
          error <= err31 != '0;
        end
      endcase

      if (config_sync == PRBS_OFF) begin
        errors <= '0;
      end
      else if (!pause && errors != '1) begin
        errors <= errors + ERRORS_WIDTH'(error);
      end
    end
  end : _count

endmodule : iclink_prbs_rx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
