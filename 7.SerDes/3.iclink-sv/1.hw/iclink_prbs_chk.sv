// SPDX-FileCopyrightText: 2015-2019 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2015 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// PRBS checker, WIDTH bits per clock: a SystemVerilog port of LiteX's
// litex/soc/cores/prbs.py PRBSChecker. It predicts each bit from the bits
// before it (self-synchronizing), one error bit per bit; all bits flag an
// error after IDLE_CLOCKS clocks of an unchanging input.
//==========================================================================
module iclink_prbs_chk #(
    parameter int WIDTH       = 20,
    parameter int NSTATE      = 7,
    parameter int TAP0        = 5,
    parameter int TAP1        = 6,
    parameter int IDLE_CLOCKS = 1024
) (
    input  logic             clk,
    input  logic             arst_n,
    input  logic [WIDTH-1:0] i,
    output logic [WIDTH-1:0] errors
);

  logic [               NSTATE-1:0] state;
  logic [               NSTATE-1:0] cur;
  logic [                WIDTH-1:0] err_next;
  logic [                WIDTH-1:0] i_last;
  logic [$clog2(IDLE_CLOCKS+1)-1:0] idle_cnt;  // counts down while the input stays the same
  logic                             idle;

  // the bits arrive MSB first: predict each from the NSTATE bits before it
  always_comb begin : _check
    cur = state;
    for (int b = WIDTH - 1; b >= 0; b--) begin
      err_next[b] = i[b] != (cur[TAP0] ^ cur[TAP1]);
      cur         = {cur[NSTATE-2:0], i[b]};
    end
  end : _check

  assign idle = idle_cnt == '0;

  always_ff @(negedge arst_n or posedge clk) begin : _state
    if (!arst_n) begin
      state    <= NSTATE'(1);
      errors   <= '0;
      i_last   <= '0;
      idle_cnt <= ($clog2(IDLE_CLOCKS + 1))'(IDLE_CLOCKS);
    end
    else begin
      state  <= cur;
      errors <= idle ? '1 : err_next;
      i_last <= i;
      if (i != i_last) begin
        idle_cnt <= ($clog2(IDLE_CLOCKS + 1))'(IDLE_CLOCKS);
      end
      else if (!idle) begin
        idle_cnt <= idle_cnt - 1'b1;
      end
    end
  end : _state

endmodule : iclink_prbs_chk

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
