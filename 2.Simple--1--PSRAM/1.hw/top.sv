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
// Description: PCB PSRAM test module: - UART for communication
//========================================================================

/* verilator lint_off PINMISSING */
`timescale 1ns/1ps
module top 
   import csr_pkg::*;
(
   input   logic clk,
   input   logic arst_n,
   
   output  logic tick_02us, 
   output  logic sent,

   input   logic uart_rx,
   output  logic uart_tx,
   
   output  logic o_psram_csn,
   output  logic o_psram_sclk,
   inout   wire [7:0] io_psram_data,
   
   output  logic led
);
 
   logic  clk_out;

   assign clk_out = clk;

   //*************************************
   // Uncomment when addressing the issue
   // logic tick_02us;
   assign sent = uart_tx;
   //-----------------------------------------
   // Generating 0.2us ticks 
   // left flexible for different tick periods
   logic counter; 
   logic tick_02us_reg;

   always_ff @(posedge clk_out or negedge arst_n) begin
      if(arst_n == 1'b0) begin
         counter <= '0;
      end
      else begin
         if(counter == 1) begin
            tick_02us_reg <= 1'b1;
            counter      <= 0;
         end
         else begin
            tick_02us_reg <= 1'b0;
            counter <= counter + 1;
         end
      end
   end
   assign tick_02us = tick_02us_reg;
   //---------------------------------------------------------------
   // UART instance: a precise uart needed (RPi bridge is sensitive)

   logic [7:0] uart_tx_data;
   logic uart_tx_write;
   logic uart_rx_read, uart_tx_busy, uart_rx_flop; 
   uart_rx_t uart_rx_arr;

   uart u_uart(
      .arst_n(arst_n),                     //i
      .clk(clk_out),                       //i

      .tick_02us(tick_02us),                 //i

      .uart_tx_write(uart_tx_write),       //i
      .uart_tx_data(uart_tx_data),         //i
      .uart_rx_read(uart_rx_read),         //i
      .uart_rx(uart_rx),              //i

      .uart_tx_busy(uart_tx_busy),         //o
      .uart_tx(uart_tx),                   //o

      .uart_rx_arr(uart_rx_arr)            //o (uart_rx_t)
   );  

   //---------------------------
   // PSRAM controller
   logic psram_stb, psram_we, psram_busy;
   logic [15:0] psram_rdat;
   logic [7:0] command_bytes [5:0];
 
   psram u_psram (
      .arst_n(arst_n),     //i
      .i_clk(clk_out),         //i 10 MHz by design

      .i_stb(psram_stb),
      .i_we(psram_we),

      .i_addr({command_bytes[3],command_bytes[2],command_bytes[1]}),
      .i_din({command_bytes[5],command_bytes[4]}),

      .psram_busy(psram_busy),

      .o_dout(psram_rdat),

      .o_psram_csn(o_psram_csn),
      .o_psram_sclk(o_psram_sclk),
      .io_psram_data(io_psram_data)
   ); 

   //----------------------------------------------------------
   // State machine: - decoding uart commands and  
   //                - communicating to psram controller
   typedef enum  logic [1:0]  {IDLE = 2'b0, 
                               READ_COMMAND = 2'b1, 
                               WAIT_PSRAM = 2'b10,
                               PROCESS_COMMAND = 2'b11 } psram_state_t;
   psram_state_t psram_state;
   //---------------------------------------------------------------------
   // command buffer: B0    -> 0 - Read, 1 - Write
   //                 B1-7  -> PSRAM address
   //                 B8-11 -> PSRAM wdat (optional, left out for reading)
   logic [2:0] byte_count;
   
   always_ff @(posedge clk_out or negedge arst_n) begin
      if(arst_n == 1'b0) begin
         psram_state   <= IDLE;
         byte_count    <= '0;
      end
      else begin
         unique case (psram_state)
            IDLE: begin
               if(uart_rx == 1'b0) begin
                  psram_state <= READ_COMMAND;   
                  byte_count  <= '0;
               end
            end
            READ_COMMAND: begin                             //fill up the command buffer
               if(uart_rx_arr.valid == 1'b1) begin
                  command_bytes[byte_count] <= uart_rx_arr.data;
                  byte_count  <= byte_count + 3'b1;
               end
               if(byte_count == 3'd6 | (byte_count == 3'd4 & command_bytes[0] == '0)) begin
                  psram_state <= WAIT_PSRAM;
                  psram_stb   <= 1'b1;
                  psram_we    <= (byte_count == 3'd6);
               end
            end
            WAIT_PSRAM: begin
               psram_stb   <= 1'b0;
               psram_we    <= 1'b0;       
               psram_state <= PROCESS_COMMAND;        
            end
            PROCESS_COMMAND: begin
               if(psram_busy == 1'b0) begin
                  psram_state <= IDLE;               
               end
            end
         endcase
      end
   end
   
   //-------------------------
   // UART buffer for sending
   logic [15:0] uart_buffer;
   logic [1:0]  uart_buffer_state;

   always_ff @(posedge clk_out) begin : _uart_buffer
      if (arst_n == 1'b0) begin
         uart_buffer       <= '0;
         uart_buffer_state <= '0;
      end
      else begin
         if(psram_busy == 1'b0 & psram_state == PROCESS_COMMAND & command_bytes[0] == '0) begin
            uart_buffer       <= psram_rdat;   
            uart_buffer_state <= 2'd2;

         end
         if(uart_tx_write) begin
            uart_buffer_state <= uart_buffer_state - 2'b1;
         end
      end
   end 

   //----------------------------
   // Write out read data on UART
   assign uart_tx_data  = (uart_buffer_state == 2'd2)? uart_buffer[15:8] : uart_buffer[7:0];
   assign uart_tx_write = uart_tx_busy == 1'b0 & uart_buffer_state != 2'b0; 
   assign uart_rx_read  = uart_rx_arr.valid;      

   //------------------------------------
   // Driving LED:
   // Store rx/tx in a buffer then output
   logic [27:0] u_counter; 

   always_ff @(posedge clk_out or negedge arst_n) begin
      if(arst_n == 1'b0) begin
         u_counter <= '0;
      end
      else begin
         u_counter <= u_counter + 28'b1;
      end
   end

   //-------------
   // Buffer fill
   logic buffer [7:0];
   logic buffer_full;

   logic [2:0] in;
   logic uart_tx_prev;

   always_ff @(posedge clk_out) begin
      if(buffer_full == 1'b0 & uart_tx_prev != uart_tx) begin
         buffer [in] <= uart_tx ;
         in          <= in + 3'b1;
         if(in == '1) begin
            buffer_full <= 1'b1;
            in <= 3'b0;
         end
      end
      else if(u_counter[27:25] == '1) begin
         buffer_full <= 1'b0;
      end
      uart_tx_prev <= uart_tx;
   end
   //--------------
   // Buffer empty
   logic counter_24_prev;

   always_ff @(posedge clk_out) begin
      if(u_counter[24] == 1'b1 & counter_24_prev == 1'b0 & buffer_full == 1'b1) begin
         led <= buffer [u_counter[27:25]];   
      end
      counter_24_prev <= u_counter[24];
   end

endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/6/7 Tarik Ibrahimovic: Initial Creation
*/
