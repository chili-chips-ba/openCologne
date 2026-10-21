// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// UART receiver, 16 clocks per bit (i_clk = 16x baud rate). A low level on rx
// starts a frame: rx is sampled at clocks 6, 7 and 8 of the start bit and a
// 2-of-3 majority vote at clock 10 confirms it (busy goes high), else the
// receiver returns to idle. Each following bit is voted the same way at clock
// 14 of its 16-clock slot. After FRAME_BITS data bits (LSB first), the parity
// bit (if PARITY_BIT < 2) and STOP_BITS stop bits, data is presented with
// converted = 1 and held until flush. Stop bits are not checked. With parity
// enabled, data_valid compares PARITY_BIT with the XOR of the data register
// value from before this frame (existing behaviour, kept on purpose).

`timescale 10ns/1ns

module uart_rx #(
    parameter FRAME_BITS = 8,  // data bits per frame
    PARITY_BIT = 2,            // 0/1: parity check, 2: no parity
    STOP_BITS  = 1             // stop bits per frame
) (
    input                       rx,
    input                       i_clk,
    input                       flush,
    output reg [FRAME_BITS-1:0] data,
    output reg                  converted,
    output reg                  data_valid,
    output reg                  busy
);

    localparam integer NBITS = FRAME_BITS + STOP_BITS + ((PARITY_BIT < 2) ? 1 : 0);

    localparam [1:0] S_IDLE  = 2'd0,
                     S_START = 2'd1,
                     S_BITS  = 2'd2,
                     S_DONE  = 2'd3;

    reg [1:0]       state;
    reg [3:0]       slot;     // clock index within a bit
    reg [3:0]       nbits;    // bits received so far
    reg [2:0]       vote;     // samples at slot 6, 7, 8
    reg [NBITS-1:0] shreg;    // received bits, first bit ends in [0]

    // FPGA power-up values (there is no reset)
    initial begin
        state      = S_IDLE;
        slot       = 4'd0;
        nbits      = 4'd0;
        vote       = 3'b000;
        shreg      = {NBITS{1'b0}};
        data       = {FRAME_BITS{1'b0}};
        converted  = 1'b0;
        data_valid = 1'b0;
        busy       = 1'b0;
    end

    wire vote_bit = (vote[0] & vote[1]) | (vote[1] & vote[2]) | (vote[0] & vote[2]);
    wire sampling = (slot == 4'd6) || (slot == 4'd7) || (slot == 4'd8);
    wire parity_ok = ((^data) == (PARITY_BIT == 1));

    always @(posedge i_clk) begin
        case (state)
            S_IDLE: begin
                converted  <= 1'b0;
                data_valid <= 1'b0;
                busy       <= 1'b0;
                slot       <= 4'd0;
                nbits      <= 4'd0;
                shreg      <= {NBITS{1'b0}};
                data       <= {FRAME_BITS{1'b0}};
                if (!rx) state <= S_START;
            end

            S_START: begin
                if (sampling) vote <= {rx, vote[2:1]};
                if (slot == 4'd10) busy <= ~vote_bit;   // start bit must vote 0
                if (slot == 4'd11) begin
                    slot  <= 4'd0;
                    state <= busy ? S_BITS : S_IDLE;
                end else begin
                    slot <= slot + 4'd1;
                end
            end

            S_BITS: begin
                if (sampling) vote <= {rx, vote[2:1]};
                if (slot == 4'd14) begin
                    shreg <= {vote_bit, shreg[NBITS-1:1]};
                    nbits <= nbits + 4'd1;
                end
                if (slot == 4'd15 && nbits == NBITS[3:0]) state <= S_DONE;
                slot <= slot + 4'd1;                    // wraps every 16 clocks
            end

            S_DONE: begin
                if (!converted) begin
                    converted  <= 1'b1;
                    data       <= shreg[FRAME_BITS-1:0];
                    data_valid <= (PARITY_BIT < 2) ? parity_ok : 1'b1;
                end
                if (flush) state <= S_IDLE;
            end
        endcase
    end

endmodule
