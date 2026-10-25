// SPDX-FileCopyrightText: 2015-2019 Florent Kermarrec <florent@enjoy-digital.fr>
// SPDX-FileCopyrightText: 2015 Sebastien Bourdeauducq <sb@m-labs.hk>
// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-2-Clause

//==========================================================================
// PRBS generator, WIDTH bits per clock: a SystemVerilog port of LiteX's
// litex/soc/cores/prbs.py PRBSGenerator (same LFSR, same bit order).
//
// The LFSR is linear, so WIDTH steps are a constant matrix: each bit out,
// and each bit of the next state, is the XOR of some state bits. The
// masks come from the steps at elaboration; the logic is one XOR of up to
// NSTATE bits per bit, not a WIDTH-deep chain (64 bits at 62.5 MHz).
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

  typedef logic [NSTATE-1:0] mask_t;
  typedef mask_t [LEN-1:0] masks_t;

  // WIDTH steps of the LFSR on masks: m[j] holds the state bits whose XOR
  // is bit j; each new bit enters at [0], the oldest drops out
  function automatic masks_t steps();
    masks_t m;
    mask_t  n;
    for (int j = 0; j < LEN; j++) begin
      m[j] = (j < NSTATE) ? mask_t'(1) << j : '0;
    end
    for (int i = 0; i < WIDTH; i++) begin
      n = m[TAP0] ^ m[TAP1];
      for (int j = LEN - 1; j > 0; j--) begin
        m[j] = m[j-1];
      end
      m[0] = n;
    end
    return m;
  endfunction

  localparam masks_t M = steps();

  logic [NSTATE-1:0] state;
  logic [   LEN-1:0] cur;

  always_comb begin : _lfsr
    for (int j = 0; j < LEN; j++) begin
      cur[j] = ^(state & M[j]);
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
