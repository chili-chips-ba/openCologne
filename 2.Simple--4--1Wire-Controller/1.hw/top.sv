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
// Description: 1-Wire test module: - UART for communication
// 1-Wire Slave and Master modules are connected externally together
// emulating both on the same chip and testing the functionality 
//========================================================================

/* verilator lint_off PINMISSING */
`timescale 1ns/1ps

module top 
   import csr_pkg::*;
(
   input  logic clk_10,
   input  logic arst_n,
   output logic led,

   input  logic uart_rx,
   output logic uart_tx,

   inout  wire  onewire_mst,
   inout  wire  onewire_slv
);

   //-----------------------------------
   // Generating 0.2us ticks 
   // customizable to other tick periods
   logic cnt; 
   logic tick_02us_reg;
   logic tick_02us;

   always_ff @(posedge clk_10 or negedge arst_n) begin
      if(arst_n == 1'b0) begin
         cnt           <= '0;
         tick_02us_reg <= '0;
      end
      else begin
         if(cnt == 1) begin
            tick_02us_reg <= 1'b1;
            cnt           <= '0;
         end
         else begin
            tick_02us_reg <= 1'b0;
            cnt           <= cnt + 1;
         end
      end
   end
   
   assign tick_02us = tick_02us_reg;
   //---------------------------------------------------------------
   // UART instance: a precise uart needed (RPi bridge is sensitive)

   logic [7:0] uart_tx_data;
   logic       uart_tx_write;
   logic       uart_rx_read, uart_tx_busy, uart_rx_flop;
   
   uart_rx_t   uart_rx_arr;

   uart u_uart(
      .arst_n        (arst_n),        //i
      .clk           (clk_10),        //i

      .tick_02us     (tick_02us),     //i

      .uart_tx_write (uart_tx_write), //i
      .uart_tx_data  (uart_tx_data),  //i
      .uart_rx_read  (uart_rx_read),  //i
      .uart_rx       (uart_rx),       //i

      .uart_tx_busy  (uart_tx_busy),  //o
      .uart_tx       (uart_tx),       //o

      .uart_rx_arr   (uart_rx_arr)    //o (uart_rx_t)
   );  


   logic tick_10ms;
   logic [17:0] counter;

   always_ff @(posedge clk_10) begin 
      if(arst_n == 1'b0) begin
         counter <= '0;
      end
      else begin
         if(counter == 18'd10_0000) begin
            counter <= '0;
         end
         else begin
            counter <= counter + 18'd1;
         end
      end
   end // always_ff @ (posedge clk_10)

   
   assign tick_10ms = (counter == 18'd10_0000);
 
   //----------------------------------
   // 1-Wire instance
   // 1 byte input and output data
   logic [7:0] onewire_wdat, onewire_rdat, slv_written_data;
   logic       onewire_we,   onewire_read, slv_wrote;
   logic       onewire_rdy,  onewire_vld;

   
   onewire_master u_onewire_master (
      .clk          (clk_10),        //i
      .arst_n       (arst_n),        //i
      .onewire      (onewire_mst),       //io

      .bits_to_rw   (4'h8),          //i 

      .onewire_wdat (onewire_wdat),  //i
      .onewire_rdat (onewire_rdat),  //o
      .we           (onewire_we),    //i

      .rdy          (onewire_rdy),   //o
      .vld          (onewire_vld),   //i
      .read         (onewire_read)   //o
   );


   onewire_slave_model #(
      .WRITE_E(0) // 0-reading; 1-writing
   )
   u_owr_slv (
      .clk          (clk_10),
      .arst_n       (arst_n),
      .written_data (slv_written_data),
      .wrote        (slv_wrote),
      .onewire      (onewire_slv)
   );

   
   //----------------------------
   // Write out read data on UART
   assign uart_tx_data  = onewire_rdat;   // reading from the 1-Wire slave
   assign uart_tx_write = onewire_read;  

   // assign uart_tx_data  = slv_written_data; // writing to the 1-Wire slave
   // assign uart_tx_write = slv_wrote;

   assign uart_rx_read  = 1'b0;      

   // debug signal
   always_comb begin 
      onewire_we   = 1'b0;      // 0-reading  1-writing
      onewire_vld  = tick_10ms; // read/write every 10ms 
      onewire_wdat = 8'd65;     // ascii A character to be written
   end

   
   //-----------------------------
   // Driving LED:
   // Store onewire mst/slv in a buffer then output
   logic [27:0] u_counter; 

   always_ff @(posedge clk_10 or negedge arst_n) begin
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
   logic       onewire_slv_prev;

   always_ff @(posedge clk_10) begin
      if((buffer_full == 1'b0) && (onewire_slv_prev != onewire_slv)) begin
         buffer [in] <= onewire_slv ;
         in          <= in + 3'b1;

         if(in == '1) begin
            buffer_full <= 1'b1;
            in <= 3'b0;
         end
      end
      else if(u_counter[27:25] == '1) begin
         buffer_full <= 1'b0;
      end

      onewire_slv_prev <= onewire_slv;
   end

   
   //--------------
   // Buffer empty
   logic counter_24_prev;

   always_ff @(posedge clk_10) begin
      if(    (u_counter[24] == 1'b1) 
          && (counter_24_prev == 1'b0) 
          && (buffer_full == 1'b1)
      ) begin
         led <= buffer [u_counter[27:25]];   
      end
      
      counter_24_prev <= u_counter[24];
   end

endmodule: top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/9/22 Tarik Ibrahimovic: Initial Creation
 2024/9/22 Tarik Ibrahimovic: First edit
*/
