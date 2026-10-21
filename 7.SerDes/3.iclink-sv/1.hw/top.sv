// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: Board top for test setup 1: one GateMate EVB (Olimex
// GateMateA1-EVB), its SerDes TX cabled to its own RX.
//
// SKELETON: this is only the board frame, so the QA flow (run-lint,
// run-format, run-leq) has a real design to check. The SerDes PHY (our
// GateMate CC_SERDES PHY for LiteICLink) and the LiteX SoC replace its body;
// the EVB clock, reset and LED stay.
//
// What it does now:
//   - reset synchronizer: the active-low button resets asynchronously and
//     releases synchronously to the clock;
//   - heartbeat: the LED blinks while the clock runs and reset is released.
//
// Pins: 3.build/GateMateA1-EVB.ccf.
//==========================================================================

module top
  import top_pkg::*;
(
    input  logic clk,    // CLK0: 10 MHz EVB oscillator
    input  logic btn_n,  // FPGA_BUT: user button, low when pressed, used as reset
    output logic led     // FPGA_LED: heartbeat
);

  //-----------------------------------------------------------------------
  // Reset synchronizer: asynchronous assert, synchronous release
  //-----------------------------------------------------------------------
  logic rst_meta;  // first stage, may go metastable on release; read only by rst_n
  logic rst_n;  // the synchronized reset, low = in reset

  always_ff @(posedge clk or negedge btn_n) begin
    if (!btn_n) begin
      rst_meta <= 1'b0;
      rst_n    <= 1'b0;
    end
    else begin
      rst_meta <= 1'b1;
      rst_n    <= rst_meta;
    end
  end

  //-----------------------------------------------------------------------
  // Heartbeat: a free-running counter, its top bit drives the LED
  //-----------------------------------------------------------------------
  logic [HEARTBEAT_W-1:0] heartbeat;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      heartbeat <= '0;
    end
    else begin
      heartbeat <= heartbeat + 1'b1;
    end
  end

  always_comb begin
    led = heartbeat[HEARTBEAT_W-1];
  end

endmodule : top

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
