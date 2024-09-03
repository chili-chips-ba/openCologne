//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//------------------------------------------------------------------------
//                   Copyright (C) 2024 Chili.CHIPS*ba
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
// 1. Redistributions of source code must retain the above copyright 
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright 
// notice, this list of conditions and the following disclaimer in the 
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its 
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//              https://opensource.org/license/bsd-3-clause
//------------------------------------------------------------------------
// TurboVega's PSRAM controller (stripped down a bit)
//========================================================================
`default_nettype none

typedef enum logic [5:0] {
    RESET_JUST_NOW = 0,
    RESET_CLOCK_WAIT = 1,
    RESET_CLOCK_DONE = 2,
    MODE_SELECT_CMD_7 = 3,
    MODE_CMD_6 = 4,
    MODE_CMD_5 = 5,
    MODE_CMD_4 = 6,
    MODE_CMD_3 = 7,
    MODE_CMD_2 = 8,
    MODE_CMD_1 = 9,
    MODE_CMD_0 = 10,
    MODE_DESELECT = 11,
    IDLE = 12,
    READ_CMD_3_0 = 13,
    READ_ADDR_23_20 = 14,
    READ_ADDR_19_16 = 15,
    READ_ADDR_15_12 = 16,
    READ_ADDR_11_8 = 17,
    READ_ADDR_7_4 = 18,
    READ_ADDR_3_0 = 19,
    READ_WAIT = 20,
    READ_DATA_7_4 = 21,
    READ_DATA_3_0 = 22,
    READ_DESELECT = 23,
    WRITE_CMD_3_0 = 24,
    WRITE_ADDR_23_20 = 25,
    WRITE_ADDR_19_16 = 26,
    WRITE_ADDR_15_12 = 27,
    WRITE_ADDR_11_8 = 28,
    WRITE_ADDR_7_4 = 29,
    WRITE_ADDR_3_0 = 30,
    WRITE_DATA_7_4 = 31,
    WRITE_DATA_3_0 = 32,
    WRITE_DESELECT = 33
} MachineState;


module psram (
	input   logic arst_n,
	input   logic i_clk,

    // begin read/write
    input   logic i_stb,
	input   logic i_we,

    // input address and data
	input   logic [23:0] i_addr,
	input   logic [15:0] i_din,
    // read and ready signals
    output  logic psram_busy,

    output  logic o_done,    
    // outputs 
	output  logic [15:0] o_dout,

	output  logic o_psram_csn,
	output  logic o_psram_sclk,
    inout   wire [7:0] io_psram_data
);

// The main clock (i_clk) here is 100 MHz, which ticks every
// 10 nS. In order to wait 150 uS upon reset, we must count
// at least 15000 ticks. So, we wait 20000, to be safe.
logic [14:0] long_delay;

MachineState o_state;
logic [34:0] states_hit;

logic [3:0] short_delay;
logic hold_clk_lo;
logic [7:0] out_enable;
logic [7:0] data_to_chip;

assign o_psram_sclk = (hold_clk_lo ? 0 : i_clk);
genvar i;
generate
    for (i = 0; i<8 ; i++) begin
        assign io_psram_data[i] = out_enable[i] ? data_to_chip[i] : 1'bz;
    end
endgenerate

always @(negedge arst_n or posedge i_clk) begin
    if (arst_n == 1'b0) begin
        // Reset the SPI machine
        long_delay <= 0;
        o_state <= RESET_JUST_NOW;
        psram_busy <= 1;
        o_done <= 0;
        o_psram_csn <= 1; // deselect
        o_dout <= 0;
        hold_clk_lo <= 1;
        data_to_chip <= 8'd0;
        states_hit <= 0;
        out_enable <= 8'hFF;
    end else begin
        states_hit[o_state] <= 1;
        case (o_state)
            // Startup long_delay
            RESET_JUST_NOW: begin
                    if (long_delay == 19999)
                        o_state <= RESET_CLOCK_WAIT;
                    else
                        long_delay <= long_delay + 1;
                end

            // Post-reset clock wait start
            RESET_CLOCK_WAIT: begin
                    hold_clk_lo <= 0;
                    o_state <= RESET_CLOCK_DONE;
                end
            
            // Post-reset clock wait end
            RESET_CLOCK_DONE: begin
                    psram_busy <= 0;
                    out_enable <= 8'h00;
                    o_state <= MODE_SELECT_CMD_7;
                end

            // Entering QPI mode is done by command 35H
            // The command bits are sent 1-at-a-time, on both PSRAM chips
            MODE_SELECT_CMD_7: begin
                    o_psram_csn <= 0; // select
                    out_enable[0] <= 1;
                    out_enable[4] <= 1;
                    data_to_chip <= 8'h00;
                    o_state <= MODE_CMD_6;
                end

            MODE_CMD_6: begin
                    data_to_chip <= 8'h00;
                    o_state <= MODE_CMD_5;
                end

            MODE_CMD_5: begin
                    data_to_chip <= 8'hFF;
                    o_state <= MODE_CMD_4;
                end

            MODE_CMD_4: begin
                    data_to_chip <= 8'hFF;
                    o_state <= MODE_CMD_3;
                end

            MODE_CMD_3: begin
                    data_to_chip <= 8'h00;
                    o_state <= MODE_CMD_2;
                end

            MODE_CMD_2: begin
                    data_to_chip <= 8'hFF;
                    o_state <= MODE_CMD_1;
                end

            MODE_CMD_1: begin
                    data_to_chip <= 8'h00;
                    o_state <= MODE_CMD_0;
                end

            MODE_CMD_0: begin
                    data_to_chip <= 8'hFF;
                    o_state <= MODE_DESELECT;
                end

            MODE_DESELECT: begin
                    o_psram_csn <= 1; // deselect
                    out_enable <= 8'h00;
                    psram_busy <= 0;
                    o_done <= 1;
                    o_state <= IDLE;
                end

            // Idle, awaiting command
            IDLE: begin
                    if (i_stb) begin
                        if (i_we) begin
                            // A write to PSRAM is done by command 38H
                            // The command bits are sent 4-at-a-time, on both PSRAM chips
                            data_to_chip[3:0] <= 4'h3;
                            data_to_chip[7:4] <= 4'h3;
                            o_state <= WRITE_CMD_3_0;
                        end else begin
                            // A read from PSRAM is done by command EBH
                            // The command bits are sent 4-at-a-time, on both PSRAM chips
                            data_to_chip[3:0] <= 4'hE;
                            data_to_chip[7:4] <= 4'hE;
                            o_state <= READ_CMD_3_0;
                        end
                        o_psram_csn <= 0; // select
                        psram_busy <= 1;
                        o_done <= 0; //get this signal out a clock earlier
                        out_enable <= 8'hFF;
                    end
                end

            READ_CMD_3_0: begin
                    data_to_chip[3:0] <= 4'hB;
                    data_to_chip[7:4] <= 4'hB;
                    o_state <= READ_ADDR_23_20;
                end

            READ_ADDR_23_20: begin
                    data_to_chip[3:0] <= i_addr[23:20];
                    data_to_chip[7:4] <= i_addr[23:20];
                    o_state <= READ_ADDR_19_16;
                end

            READ_ADDR_19_16: begin
                    data_to_chip[3:0] <= i_addr[19:16];
                    data_to_chip[7:4] <= i_addr[19:16];
                    o_state <= READ_ADDR_15_12;
                end

            READ_ADDR_15_12: begin
                    data_to_chip[3:0] <= i_addr[15:12];
                    data_to_chip[7:4] <= i_addr[15:12];
                    o_state <= READ_ADDR_11_8;
                end

            READ_ADDR_11_8: begin
                    data_to_chip[3:0] <= i_addr[11:8];
                    data_to_chip[7:4] <= i_addr[11:8];
                    o_state <= READ_ADDR_7_4;
                end

            READ_ADDR_7_4: begin
                    data_to_chip[3:0] <= i_addr[7:4];
                    data_to_chip[7:4] <= i_addr[7:4];
                    o_state <= READ_ADDR_3_0;
                end

            READ_ADDR_3_0: begin
                    data_to_chip[3:0] <= i_addr[3:0];
                    data_to_chip[7:4] <= i_addr[3:0];
                    short_delay <= 0;
                    o_state <= READ_WAIT;
                end

            READ_WAIT: begin
                    out_enable <= 8'h00;
                    if (short_delay == 5)//not sure about this?
                        o_state <= READ_DATA_7_4;
                    else
                        short_delay <= short_delay + 1;
                end

            READ_DATA_7_4: begin
                    o_dout[15:8] <= io_psram_data;
                    o_state      <= READ_DATA_3_0;
                end

            READ_DATA_3_0: begin
                    o_dout[7:0] <= io_psram_data;
                    o_state     <= READ_DESELECT;
                end

            READ_DESELECT: begin
                    o_psram_csn <= 1; // deselect
                    psram_busy <= 0;
                    o_done <= 1;
                    o_state <= IDLE;
                end

            WRITE_CMD_3_0: begin
                    data_to_chip[3:0] <= 4'h8;
                    data_to_chip[7:4] <= 4'h8;
                    o_state <= WRITE_ADDR_23_20;
                end

            WRITE_ADDR_23_20: begin
                    data_to_chip[3:0] <= i_addr[23:20];
                    data_to_chip[7:4] <= i_addr[23:20];
                    o_state <= WRITE_ADDR_19_16;
                end

            WRITE_ADDR_19_16: begin
                    data_to_chip[3:0] <= i_addr[19:16];
                    data_to_chip[7:4] <= i_addr[19:16];
                    o_state <= WRITE_ADDR_15_12;
                end

            WRITE_ADDR_15_12: begin
                    data_to_chip[3:0] <= i_addr[15:12];
                    data_to_chip[7:4] <= i_addr[15:12];
                    o_state <= WRITE_ADDR_11_8;
                end

            WRITE_ADDR_11_8: begin
                    data_to_chip[3:0] <= i_addr[11:8];
                    data_to_chip[7:4] <= i_addr[11:8];
                    o_state <= WRITE_ADDR_7_4;
                end

            WRITE_ADDR_7_4: begin
                    data_to_chip[3:0] <= i_addr[7:4];
                    data_to_chip[7:4] <= i_addr[7:4];
                    o_state <= WRITE_ADDR_3_0;
                end

            WRITE_ADDR_3_0: begin
                    data_to_chip[3:0] <= i_addr[3:0];
                    data_to_chip[7:4] <= i_addr[3:0];
                    o_state <= WRITE_DATA_7_4;
                end

            WRITE_DATA_7_4: begin
                    data_to_chip[7:0] <= i_din[15:8];
                    o_state <= WRITE_DATA_3_0;
                end

            WRITE_DATA_3_0: begin
                    data_to_chip[7:0] <= i_din[7:0];
                    o_state <= WRITE_DESELECT;
                end

            WRITE_DESELECT: begin
                    o_psram_csn <= 1; // deselect
                    out_enable <= 8'h00;
                    psram_busy <= 0; // get this signal out a clock earlier
                    o_done <= 1;
                    o_state <= IDLE;
                end
            default: o_state <= IDLE;
        endcase
    end
end

endmodule
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/6/7 Tarik Ibrahimovic: Initial Creation
 2024/8/25 Tarik Ibrahimovic: code correcting

*/
