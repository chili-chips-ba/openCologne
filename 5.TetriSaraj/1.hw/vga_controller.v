// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//
// 640x480 VGA timing generator. x and y count every clk (one clk = one pixel,
// so clk must be the ~25 MHz pixel clock): x runs 0..HMAX, y advances at the
// end of each line and runs 0..VMAX. hsync/vsync are active high during the
// retrace window and are registered, so they lag x/y by one clock. video_on
// marks the visible area. p_tick is clk passed through.

`timescale 1ns / 1ps

module vga_controller (
    input  wire       clk,
    input  wire       reset,     // async, active high
    output wire       video_on,
    output wire       hsync,
    output wire       vsync,
    output wire       p_tick,
    output wire [9:0] x,         // 0..HMAX
    output wire [9:0] y          // 0..VMAX
);

    // Horizontal timing in pixels. Note: the sync window starts at HD+HB,
    // so HB is the porch before sync (the "front porch" in VESA terms).
    parameter HD   = 640;
    parameter HF   = 48;
    parameter HB   = 16;
    parameter HR   = 96;
    parameter HMAX = HD+HF+HB+HR-1;
    // Vertical timing in lines, same convention
    parameter VD   = 480;
    parameter VF   = 10;
    parameter VB   = 33;
    parameter VR   = 2;
    parameter VMAX = VD+VF+VB+VR-1;

    localparam [9:0] H_LAST    = HMAX;
    localparam [9:0] V_LAST    = VMAX;
    localparam [9:0] H_SYNC_LO = HD+HB;
    localparam [9:0] H_SYNC_HI = HD+HB+HR-1;
    localparam [9:0] V_SYNC_LO = VD+VB;
    localparam [9:0] V_SYNC_HI = VD+VB+VR-1;
    localparam [9:0] H_VIS     = HD;
    localparam [9:0] V_VIS     = VD;

    reg [9:0] hcnt, vcnt;
    reg       hs, vs;

    wire line_end = (hcnt == H_LAST);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            hcnt <= 10'd0;
            vcnt <= 10'd0;
            hs   <= 1'b0;
            vs   <= 1'b0;
        end else begin
            hcnt <= line_end ? 10'd0 : hcnt + 10'd1;
            if (line_end)
                vcnt <= (vcnt == V_LAST) ? 10'd0 : vcnt + 10'd1;
            hs <= (hcnt >= H_SYNC_LO) && (hcnt <= H_SYNC_HI);
            vs <= (vcnt >= V_SYNC_LO) && (vcnt <= V_SYNC_HI);
        end
    end

    assign video_on = (hcnt < H_VIS) && (vcnt < V_VIS);
    assign hsync    = hs;
    assign vsync    = vs;
    assign x        = hcnt;
    assign y        = vcnt;
    assign p_tick   = clk;

endmodule
