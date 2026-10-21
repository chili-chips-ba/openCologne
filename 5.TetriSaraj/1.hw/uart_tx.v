// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// UART transmitter, the counterpart of uart_rx. Each bit is held for
// RETENTION_DURATION+1 clocks (16 with the default, matching the 16x clock
// of uart_rx). When tx_enable is seen in idle, tx_busy rises and data is
// latched two clocks later, then sent as start bit, FRAME_BITS data bits
// LSB first, the parity bit if PARITY_BIT < 2, and STOP_BITS stop bits.
// The parity bit is the XOR of the data bits for both PARITY_BIT = 0 and 1
// (existing behaviour, kept on purpose). tx idles high.

`timescale 10ns / 1ns

module uart_tx #(
    parameter FRAME_BITS = 8,     // data bits per frame
    PARITY_BIT = 2,               // 0/1: send parity bit, 2: no parity
    STOP_BITS  = 1,               // stop bits per frame
    RETENTION_DURATION = 15       // clocks per bit minus one
)(
    input                  clk,
    input                  tx_enable,
    input [FRAME_BITS-1:0] data,
    output reg             tx,
    output reg             tx_busy
);

    localparam integer HAS_PAR = (PARITY_BIT < 2) ? 1 : 0;
    localparam integer NBITS   = 1 + FRAME_BITS + HAS_PAR + STOP_BITS;
    localparam integer DW      = $clog2(RETENTION_DURATION + 2);
    localparam integer NW      = $clog2(NBITS + 2);

    localparam [DW-1:0] DIV_LAST = RETENTION_DURATION;
    localparam [NW-1:0] N_ALL    = NBITS[NW-1:0];

    localparam [1:0] S_IDLE = 2'd0,
                     S_ARM  = 2'd1,   // first busy clock
                     S_LOAD = 2'd2,   // data is latched here
                     S_SEND = 2'd3;

    // Frame, first bit to send in [0]
    wire [NBITS-1:0] frame;
    generate
        if (HAS_PAR != 0) begin : g_par
            assign frame = {{STOP_BITS{1'b1}}, ^data, data, 1'b0};
        end else begin : g_nopar
            assign frame = {{STOP_BITS{1'b1}}, data, 1'b0};
        end
    endgenerate

    reg [1:0]       state;
    reg [NBITS-1:0] shreg;    // bits still to send, next one in [0]
    reg [DW-1:0]    div;      // clock index within a bit
    reg [NW-1:0]    nsent;    // bits put on tx so far

    // FPGA power-up values (there is no reset)
    initial begin
        state   = S_IDLE;
        shreg   = {NBITS{1'b1}};
        div     = DIV_LAST;
        nsent   = {NW{1'b0}};
        tx      = 1'b1;
        tx_busy = 1'b0;
    end

    always @(posedge clk) begin
        tx_busy <= (state != S_IDLE);

        case (state)
            S_IDLE: begin
                tx    <= 1'b1;
                div   <= DIV_LAST;
                nsent <= {NW{1'b0}};
                if (tx_enable) state <= S_ARM;
            end

            S_ARM:
                state <= S_LOAD;

            S_LOAD: begin
                shreg <= frame;
                state <= S_SEND;
            end

            S_SEND: begin
                div <= (div == DIV_LAST) ? {DW{1'b0}} : div + 1'b1;
                if (div == {DW{1'b0}}) begin
                    tx    <= shreg[0];
                    shreg <= {1'b1, shreg[NBITS-1:1]};
                    nsent <= nsent + 1'b1;
                end
                // back to idle one clock after the last bit went out
                if (nsent == N_ALL) state <= S_IDLE;
            end
        endcase
    end

endmodule
