// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// Signed PCM to unsigned resistor-ladder DAC code, with PWM on the low bits.
// The top DAC_BITS of pcm (sign bit inverted, i.e. offset binary) give the
// base level L. The remaining PWM_BITS give the fraction f: a free-running
// PWM counter outputs L+1 while counter < f and L otherwise, so the average
// output is L + f/2^PWM_BITS. Inputs are registered first, so dac follows
// pcm with two clocks of latency. L+1 wraps to 0 at full scale (existing
// behaviour, kept on purpose).

module dacpwm #(
    parameter PCM_BITS = 12,                   // signed PCM input width
    parameter DAC_BITS = 4                     // unsigned DAC output width
) (
    input  wire                       clk,
    input  wire signed [PCM_BITS-1:0] pcm,
    output wire        [DAC_BITS-1:0] dac
);

    localparam PWM_BITS = PCM_BITS - DAC_BITS;

    localparam [DAC_BITS-1:0] SIGN_FLIP = {1'b1, {(DAC_BITS-1){1'b0}}};

    // Stage 1: split the sample
    reg [DAC_BITS-1:0] level, level_up;
    reg [PWM_BITS-1:0] frac;

    wire [DAC_BITS-1:0] top_bits = pcm[PCM_BITS-1:PWM_BITS] ^ SIGN_FLIP;

    always @(posedge clk) begin
        level    <= top_bits;
        level_up <= top_bits + 1'b1;
        frac     <= pcm[PWM_BITS-1:0];
    end

    // Stage 2: PWM between level and level+1
    reg [PWM_BITS-1:0] pwm_cnt;
    reg [DAC_BITS-1:0] dac_q;

    // FPGA power-up values (there is no reset)
    initial begin
        level    = {DAC_BITS{1'b0}};
        level_up = {DAC_BITS{1'b0}};
        frac     = {PWM_BITS{1'b0}};
        pwm_cnt  = {PWM_BITS{1'b0}};
        dac_q    = {DAC_BITS{1'b0}};
    end

    always @(posedge clk) begin
        pwm_cnt <= pwm_cnt + 1'b1;
        dac_q   <= (pwm_cnt < frac) ? level_up : level;
    end

    assign dac = dac_q;

endmodule
