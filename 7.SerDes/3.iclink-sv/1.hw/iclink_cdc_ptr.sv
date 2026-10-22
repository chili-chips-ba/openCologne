// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// A FIFO pointer into another clock domain, by toggle handshake. The source
// holds a snapshot while a toggle crosses (2 flops) and comes back (2
// flops); the destination copies the snapshot, which is stable by then.
// Any jump is safe, so a pointer may move by 2 words a clock or by a whole
// packet at a commit; a Gray-coded pointer may only step by one. The copy
// lags by about 3 destination clocks and is refreshed every 6 or so.
//
// Both sides reset to 0, so they may leave reset at different times.
//==========================================================================
module iclink_cdc_ptr #(
    parameter int W = 11
) (
    input logic         src_clk,
    input logic         src_arst_n,
    input logic [W-1:0] src_ptr,

    input  logic         dst_clk,
    input  logic         dst_arst_n,
    output logic [W-1:0] dst_ptr
);

  logic [W-1:0] hold;  // src: the snapshot in flight
  logic req, ack;  // toggles: src sends, dst returns
  logic [1:0] ack_sync;  // src: ack, synchronized
  logic [1:0] req_sync;  // dst: req, synchronized

  always_ff @(posedge src_clk or negedge src_arst_n) begin
    if (!src_arst_n) begin
      hold     <= '0;
      req      <= 1'b0;
      ack_sync <= '0;
    end
    else begin
      ack_sync <= {ack_sync[0], ack};
      if (ack_sync[1] == req) begin  // the last snapshot was taken: send a new one
        hold <= src_ptr;
        req  <= ~req;
      end
    end
  end

  always_ff @(posedge dst_clk or negedge dst_arst_n) begin
    if (!dst_arst_n) begin
      req_sync <= '0;
      ack      <= 1'b0;
      dst_ptr  <= '0;
    end
    else begin
      req_sync <= {req_sync[0], req};
      if (req_sync[1] != ack) begin
        dst_ptr <= hold;
        ack     <= req_sync[1];
      end
    end
  end

endmodule : iclink_cdc_ptr

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
