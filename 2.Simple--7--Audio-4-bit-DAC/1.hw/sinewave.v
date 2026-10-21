// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// Sine oscillator without a table: a discrete-time spring-mass model.
// Every 2^DELAY clocks the position is advanced by speed >> SPD_TO_POS_SHIFT,
// and one clock later the speed is reduced by position >> POS_TO_SPD_SHIFT
// (arithmetic shifts). Position and speed then trace a stable sine/cosine
// pair. pcm is the position. POS_INIT and SPD_INIT set phase and amplitude.
// Needs SPD_BITS < PCM_BITS and DELAY >= 2.

module sinewave #(
    parameter DELAY            = 8,    // update period = 2^DELAY clocks
    parameter PCM_BITS         = 12,   // output width
    parameter SPD_BITS         = 10,   // speed register width
    parameter POS_TO_SPD_SHIFT = 8,    // spring stiffness = 2^-n
    parameter SPD_TO_POS_SHIFT = 3,    // 1/mass = 2^-n
    parameter POS_INIT         = 0,
    parameter SPD_INIT         = 277   // amplitude, 277 fits 12 bits
) (
    input  wire                       clk,
    output wire signed [PCM_BITS-1:0] pcm
);

    reg signed [PCM_BITS-1:0] pos;
    reg signed [SPD_BITS-1:0] spd;
    reg        [DELAY-1:0]    tick_cnt;

    // FPGA power-up values (there is no reset)
    initial begin
        pos      = POS_INIT;
        spd      = SPD_INIT;
        tick_cnt = {DELAY{1'b0}};
    end

    // Scaled terms, sign-extended to the width of their target
    wire signed [SPD_BITS-1:0] spd_sh = spd >>> SPD_TO_POS_SHIFT;
    // top bits of pos_sh are only sign copies, the low SPD_BITS are used
    /* verilator lint_off UNUSEDSIGNAL */
    wire signed [PCM_BITS-1:0] pos_sh = pos >>> POS_TO_SPD_SHIFT;
    /* verilator lint_on UNUSEDSIGNAL */
    wire signed [PCM_BITS-1:0] d_pos  = {{(PCM_BITS-SPD_BITS){spd_sh[SPD_BITS-1]}}, spd_sh};
    wire signed [SPD_BITS-1:0] d_spd  = pos_sh[SPD_BITS-1:0];

    wire step_pos = (tick_cnt == {DELAY{1'b0}});
    wire step_spd = (tick_cnt == {{(DELAY-1){1'b0}}, 1'b1});

    always @(posedge clk) begin
        tick_cnt <= tick_cnt + 1'b1;
        if (step_pos) pos <= pos + d_pos;
        if (step_spd) spd <= spd - d_spd;
    end

    assign pcm = pos;

endmodule
