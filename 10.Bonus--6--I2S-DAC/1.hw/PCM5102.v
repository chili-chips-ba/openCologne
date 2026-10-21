// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// I2S transmitter for the TI PCM5102 DAC (no MCLK, the DAC derives it from
// bck). clk is divided by 2^(DAC_CLK_DIV_BITS+1); on each falling edge of
// that divided clock a 6-bit slot counter steps. Bit 0 of the counter is bck,
// bit 5 is the word select, so each 32-bck frame carries 16 bits per channel,
// MSB first; din takes its channel from the registered lrck. left/right are latched on the falling edge of clk_strobe (= counter bit 5),
// which also serves as the sample clock for the generator feeding them.
// For DAC_WIDTH > 16 only the top 16 bits are sent. arst is async, active high.

module PCM5102 #(
    parameter DAC_WIDTH        = 16,
    parameter DAC_CLK_DIV_BITS = 2   // 1: ~384 kHz, 2: ~192 kHz, 3: ~96 kHz, 4: ~48 kHz
)(
    input  wire                 clk,
    input  wire                 arst,
    input  wire [DAC_WIDTH-1:0] left,
    input  wire [DAC_WIDTH-1:0] right,
    output reg                  din,
    output reg                  bck,
    output reg                  lrck,
    output wire                 clk_strobe
);

    localparam integer IW     = $clog2(DAC_WIDTH);
    localparam integer TOP_I  = DAC_WIDTH - 1;
    localparam [IW-1:0] TOP_BIT = TOP_I[IW-1:0];

    // Clock divider
    reg [DAC_CLK_DIV_BITS:0] div;

    always @(posedge clk or posedge arst) begin
        if (arst) div <= {(DAC_CLK_DIV_BITS+1){1'b0}};
        else      div <= div + 1'b1;
    end

    wire slot_clk = div[DAC_CLK_DIV_BITS];

    // Slot counter: [0] = bck, [4:1] = bit number, [5] = channel
    reg  [5:0] slot;
    wire [IW-1:0] bit_sel = TOP_BIT - slot[4:1];   // MSB first

    // Sample latch, once per frame
    reg [DAC_WIDTH-1:0] smp_l, smp_r;

    always @(negedge slot[5] or posedge arst) begin
        if (arst) begin
            smp_l <= {DAC_WIDTH{1'b0}};
            smp_r <= {DAC_WIDTH{1'b0}};
        end else begin
            smp_l <= left;
            smp_r <= right;
        end
    end

    always @(negedge slot_clk or posedge arst) begin
        if (arst) begin
            slot <= 6'd0;
            din  <= 1'b0;
            bck  <= 1'b0;
            lrck <= 1'b0;
        end else begin
            slot <= slot + 6'd1;
            bck  <= slot[0];
            lrck <= slot[5];
            din  <= lrck ? smp_r[bit_sel] : smp_l[bit_sel];
        end
    end

    assign clk_strobe = slot[5];

endmodule
