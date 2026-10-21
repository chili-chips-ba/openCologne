// SPDX-FileCopyrightText: 2015-2019 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2015 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// PRBS generator, WIDTH bits per clock: a SystemVerilog port of LiteX's
// litex/soc/cores/prbs.py PRBSGenerator (same LFSR, same bit order).
//==========================================================================
module iclink_prbs_gen #(
    parameter int WIDTH  = 20,
    parameter int NSTATE = 7,
    parameter int TAP0   = 5,
    parameter int TAP1   = 6
) (
    input  logic             clk,
    input  logic             arst_n,
    output logic [WIDTH-1:0] o
);

  localparam int LEN = (NSTATE > WIDTH) ? NSTATE : WIDTH;

  logic [NSTATE-1:0] state;
  logic [   LEN-1:0] cur;

  // WIDTH steps of the LFSR: each new bit enters at [0], the oldest drops out
  always_comb begin : _lfsr
    cur             = '0;
    cur[NSTATE-1:0] = state;
    for (int i = 0; i < WIDTH; i++) begin
      cur = {cur[LEN-2:0], cur[TAP0] ^ cur[TAP1]};
    end
  end : _lfsr

  always_ff @(negedge arst_n or posedge clk) begin : _state
    if (!arst_n) begin
      state <= NSTATE'(1);
      o     <= '0;
    end
    else begin
      state <= cur[NSTATE-1:0];
      o     <= cur[WIDTH-1:0];
    end
  end : _state

endmodule : iclink_prbs_gen

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
