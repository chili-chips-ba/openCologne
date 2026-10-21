// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// Push-button debouncer with rising-edge detect. The button is sampled once
// every 25000 clocks into a 3-stage shift register. The output is high for
// one sample period (25000 clocks) after the sampled button goes from 0 to 1.
// Runs in the clk domain, using a clock enable instead of a divided clock.

module debounce (
    input  wire clk,
    input  wire in,
    output wire out
);

    localparam [14:0] DIV_LAST = 15'd24999;  // sample every 25000 clocks

    reg  [14:0] div_cnt;
    reg  [2:0]  smp;      // smp[0] is the newest sample, smp[2] the oldest
    wire        sample = (div_cnt == DIV_LAST);

    // FPGA power-up values (there is no reset)
    initial begin
        div_cnt = 15'd0;
        smp     = 3'b000;
    end

    always @(posedge clk) begin
        if (sample) div_cnt <= 15'd0;
        else        div_cnt <= div_cnt + 15'd1;
    end

    always @(posedge clk) begin
        if (sample) smp <= {smp[1:0], in};
    end

    assign out = smp[1] & ~smp[2];

endmodule
