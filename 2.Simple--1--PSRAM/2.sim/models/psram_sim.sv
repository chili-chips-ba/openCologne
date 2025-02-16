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
// PSRAM sim model: QPI
//========================================================================

module psram_sim (
    input   logic psram_csn,
    input   logic psram_sclk,
    input   logic arst_n,

    inout   wire [7:0] io_psram_data
);

    typedef enum logic [5:0] {
        RESET_JUST_NOW    = 6'd0,
        RESET_CLOCK_WAIT  = 6'd1,
        RESET_CLOCK_DONE  = 6'd2,
        MODE_SELECT_CMD_7 = 6'd3,
        MODE_CMD_6        = 6'd4,
        MODE_CMD_5        = 6'd5,
        MODE_CMD_4        = 6'd6,
        MODE_CMD_3        = 6'd7,
        MODE_CMD_2        = 6'd8,
        MODE_CMD_1        = 6'd9,
        MODE_CMD_0        = 6'd10,
        MODE_DESELECT     = 6'd11,
        IDLE              = 6'd12,
        READ_CMD_3_0      = 6'd13,
        READ_ADDR_23_20   = 6'd14,
        READ_ADDR_19_16   = 6'd15,
        READ_ADDR_15_12   = 6'd16,
        READ_ADDR_11_8    = 6'd17,
        READ_ADDR_7_4     = 6'd18,
        READ_ADDR_3_0     = 6'd19,
        READ_WAIT         = 6'd20,
        READ_DATA_7_4     = 6'd21,
        READ_DATA_3_0     = 6'd22,
        READ_DESELECT     = 6'd23,
        WRITE_CMD_3_0     = 6'd24,
        WRITE_ADDR_23_20  = 6'd25,
        WRITE_ADDR_19_16  = 6'd26,
        WRITE_ADDR_15_12  = 6'd27,
        WRITE_ADDR_11_8   = 6'd28,
        WRITE_ADDR_7_4    = 6'd29,
        WRITE_ADDR_3_0    = 6'd30,
        WRITE_DATA_7_4    = 6'd31,
        WRITE_DATA_3_0    = 6'd32,
        WRITE_DESELECT    = 6'd33
    } MachineState_t;

    typedef enum logic [7:0] { 
        WRITE_0   = 8'h33,
        WRITE_1   = 8'h88,
        READ_0    = 8'hEE,
        READ_1    = 8'hBB
    } psram_codes_t;

    MachineState_t psram_state;

    logic [3:0] short_delay;
    logic [7:0] data_to_chip;
    logic [23:0] addr ;

    logic [7:0] psram_mem_ary [2**23:0]; // 2^24 locations of 8 bits;


    assign data_to_chip = io_psram_data;


    always_ff @(posedge psram_sclk or negedge arst_n) begin 
        if (arst_n == 1'b0) begin
            psram_state <= RESET_JUST_NOW;
        end
        else begin
            case (psram_state)
                RESET_JUST_NOW   : psram_state <= RESET_CLOCK_WAIT;
                RESET_CLOCK_WAIT : psram_state <= RESET_CLOCK_DONE;
                RESET_CLOCK_DONE : psram_state <= MODE_SELECT_CMD_7;
                MODE_SELECT_CMD_7: psram_state <= MODE_CMD_6;
                MODE_CMD_6       : psram_state <= MODE_CMD_5;
                MODE_CMD_5       : psram_state <= MODE_CMD_4;
                MODE_CMD_4       : psram_state <= MODE_CMD_3;
                MODE_CMD_3       : psram_state <= MODE_CMD_2;
                MODE_CMD_2       : psram_state <= MODE_CMD_1;
                MODE_CMD_1       : psram_state <= MODE_CMD_0;
                MODE_CMD_0       : psram_state <= MODE_DESELECT;
                MODE_DESELECT    : psram_state <= IDLE;

                IDLE: begin
                    if(data_to_chip[7:0] == WRITE_0 && psram_csn == 0) begin
                        psram_state <= WRITE_CMD_3_0;
                    end
                    if(data_to_chip[7:0] == READ_0  && psram_csn == 0) begin
                        psram_state <= READ_CMD_3_0;
                    end
                end

                READ_CMD_3_0: begin
                    if(data_to_chip == READ_1) begin
                        psram_state <= READ_ADDR_23_20;                
                    end
                end
                // sequential address load 24 bits: done
                READ_ADDR_23_20: begin
                    addr [23:20] <= data_to_chip[3:0];
                    psram_state  <= READ_ADDR_19_16;
                end

                READ_ADDR_19_16: begin
                    addr [19:16] <= data_to_chip[3:0];
                    psram_state <= READ_ADDR_15_12;
                end

                READ_ADDR_15_12: begin
                    addr [15:12] <= data_to_chip[3:0];
                    psram_state <= READ_ADDR_11_8;
                end

                READ_ADDR_11_8: begin
                    addr [11:8] <= data_to_chip[3:0];
                    psram_state <= READ_ADDR_7_4;
                end

                READ_ADDR_7_4: begin
                    addr [7:4] <= data_to_chip[3:0];
                    psram_state <= READ_ADDR_3_0;
                end

                READ_ADDR_3_0: begin
                    addr [3:0] <= data_to_chip[3:0];
                    psram_state <= READ_WAIT;
                    short_delay <= '0;
                end
                // read wait: done
                READ_WAIT: begin
                    if (short_delay == 4) begin
                        psram_state <= READ_DATA_7_4;
                        short_delay <= 0;
                    end
                    else begin
                        short_delay <= short_delay + 1;
                    end
                end
                // read data : done i think
                READ_DATA_7_4: begin
                    psram_state  <= READ_DATA_3_0;
                end
                        
                READ_DATA_3_0: begin
                    psram_state  <= READ_DESELECT;
                end

                READ_DESELECT: begin
                    psram_state  <= IDLE;
                end
                // write data: tbd
                WRITE_CMD_3_0: begin
                    if(data_to_chip == WRITE_1)
                    psram_state <= WRITE_ADDR_23_20;
                end
                // write address load: done
                WRITE_ADDR_23_20: begin
                    addr[23:20] <= data_to_chip[3:0];
                    psram_state <= WRITE_ADDR_19_16;
                end

                WRITE_ADDR_19_16: begin
                    addr[19:16] <= data_to_chip[3:0];
                    psram_state <= WRITE_ADDR_15_12;
                end

                WRITE_ADDR_15_12: begin
                    addr[15:12] <= data_to_chip[3:0];
                    psram_state <= WRITE_ADDR_11_8;
                end

                WRITE_ADDR_11_8: begin
                    addr[11:8] <= data_to_chip[3:0];
                    psram_state <= WRITE_ADDR_7_4;
                end

                WRITE_ADDR_7_4: begin
                    addr[7:4] <= data_to_chip[3:0];
                    psram_state <= WRITE_ADDR_3_0;
                end

                WRITE_ADDR_3_0: begin
                    addr[3:0] <= data_to_chip[3:0];
                    psram_state <= WRITE_DATA_7_4;
                end
                // write data: done
                WRITE_DATA_7_4: begin
                    psram_mem_ary[addr] <= data_to_chip[7:0];
                    psram_state <= WRITE_DATA_3_0;
                end

                WRITE_DATA_3_0: begin
                    psram_mem_ary[addr + 1] <= data_to_chip[7:0];
                    psram_state <= WRITE_DESELECT;
                end

                WRITE_DESELECT: begin
                    if(psram_csn == 1) 
                        psram_state <= IDLE;
                end
            default: psram_state <= IDLE;
            endcase      
        end
    end

    logic [7:0] data_read;
    logic oe;

    assign data_read = (psram_state == READ_DATA_7_4)? psram_mem_ary[addr] :
                                                    psram_mem_ary[addr+1];

    assign oe = (psram_state == READ_DATA_7_4) | (psram_state == READ_DATA_3_0);

    assign io_psram_data = oe? data_read : 8'bz;

endmodule
/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/8/17 Tarik Ibrahimovic: initial creation
 2024/8/25 Tarik Ibrahimovic: code correcting
*/