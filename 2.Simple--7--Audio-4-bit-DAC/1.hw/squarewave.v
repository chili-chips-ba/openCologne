// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// Square wave generator with the same period as trianglewave (same counter
// and turn points). pcm is the most negative value while the internal
// counter runs up and 0 while it runs down.

module squarewave #(
    parameter DELAY    = 10,               // low counter bits (slows the wave)
    parameter PCM_BITS = 12                // output width
) (
    input  wire                       clk,
    output wire signed [PCM_BITS-1:0] pcm
);

    localparam [PCM_BITS-1:0] PEAK   = 1770;
    localparam [PCM_BITS-1:0] TROUGH = ~PEAK;   // -1771

    reg [DELAY+PCM_BITS-1:0] cnt;
    reg                      up;    // 1: counting up

    // FPGA power-up values (there is no reset)
    initial begin
        cnt = {(DELAY+PCM_BITS){1'b0}};
        up  = 1'b0;
    end

    wire [PCM_BITS-1:0] level = cnt[DELAY+PCM_BITS-1:DELAY];

    always @(posedge clk) begin
        cnt <= up ? cnt + 1'b1 : cnt - 1'b1;
        if (!up && level == TROUGH) up <= 1'b1;
        if ( up && level == PEAK)   up <= 1'b0;
    end

    assign pcm = {up, {(PCM_BITS-1){1'b0}}};

endmodule
