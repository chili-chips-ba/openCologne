// SPDX-FileCopyrightText: 2024 Chili.CHIPS*ba
//
// SPDX-License-Identifier: BSD-3-Clause

//========================================================================
// openeye-CamSI * NLnet-sponsored open-source core for Camera I/F with ISP
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
// Description: Simple I2C Controller for configuration of camera.
//  At the moment, it is only capable of I2C writes
//========================================================================

module i2c_ctrl (
   input  wire        clk,
   input  wire        strobe_100kHz,
   input  wire        areset_n,

   input  wire        enable,
   input  wire [6:0]  slave_address,
   input  wire [15:0]  register_address,
   output reg         register_done,

   input  wire        scl_do,
   output reg         scl_di,

   input  wire        sda_do,
   output reg         sda_di
);

   reg  [3:0] state;
   reg  [3:0] post_state;

   reg  [1:0] process_cnt;
   reg  [7:0] slave_address_plus_rw;
   reg  [3:0] bit_cnt;
   wire [3:0] bit_cnt_dec;
   reg        post_serial_data;
   reg        acknowledge_bit;

   assign bit_cnt_dec = bit_cnt - 4'd1;

   always @(negedge areset_n or posedge clk) begin
      if (areset_n == 1'b0) begin
         register_done         <= 1'b0;
         state                 <= 4'd0;  // IDLE
         post_state            <= 4'd0;  // IDLE
         process_cnt           <= 2'd0;
         slave_address_plus_rw <= 8'd0;
         bit_cnt               <= 4'd0;
         post_serial_data      <= 1'b0;
         acknowledge_bit       <= 1'b0;
         scl_di                <= 1'b1;
         sda_di                <= 1'b1;
      end
      else begin
         case (state)
         //----------------------
            4'd0: begin // IDLE
               process_cnt           <= 2'd0;
               bit_cnt               <= 4'd0;
               acknowledge_bit       <= 1'b0;
               slave_address_plus_rw <= {slave_address, 1'b0};
               scl_di                <= 1'b1;
               sda_di                <= 1'b1;

               if (enable == 1'b1) begin
                  register_done   <= 1'b0;
                  state           <= 4'd1;  // START
                  post_state      <= 4'd2;  // WRITE_SLAVE_ADDR
               end
            end

         //----------------------
            4'd1: if (strobe_100kHz == 1'b1) begin // START
               case (process_cnt)
                  2'd0: process_cnt <= 2'd1;
                  2'd1: begin
                     sda_di      <= 1'b0;
                     process_cnt <= 2'd2;
                  end
                  2'd2: begin
                     bit_cnt     <= 4'd8;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     scl_di      <= 1'b0;
                     process_cnt <= 2'd0;
                     state       <= post_state;
                     sda_di      <= slave_address_plus_rw[7];
                  end
               endcase
            end

         //----------------------
            4'd2: if (strobe_100kHz == 1'b1) begin // WRITE_SLAVE_ADDR
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     scl_di      <= 1'b0;
                     bit_cnt     <= bit_cnt_dec;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     process_cnt <= 2'd0;
                     if (bit_cnt == 4'd0) begin
                        post_serial_data <= register_address[15];
                        state      <= 4'd3; // CHECK_ACK
                        post_state <= 4'd4; // WRITE_REG_ADDR_MSB
                        bit_cnt    <= 4'd8;
                     end
                     else begin
                        sda_di <= slave_address_plus_rw[bit_cnt_dec[2:0]];
                     end
                  end
               endcase
            end

         //----------------------
            4'd3: if (strobe_100kHz == 1'b1) begin // CHECK_ACK
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     scl_di <= 1'b0;
                     if (sda_do == 1'b0) acknowledge_bit <= 1'b1;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     if (acknowledge_bit == 1'b1) begin
                        acknowledge_bit <= 1'b0;
                        sda_di          <= post_serial_data;
                        state           <= post_state;
                     end
                     else begin
                        state <= 4'd7; // RESTART
                     end
                     process_cnt <= 2'd0;
                  end
               endcase
            end

         //----------------------
            4'd4: if (strobe_100kHz == 1'b1) begin // WRITE_REG_ADDR_MSB
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     scl_di      <= 1'b0;
                     bit_cnt     <= bit_cnt_dec;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     if (bit_cnt == 4'd0) begin
                        post_serial_data <= register_address[7];
                        state        <= 4'd3; // CHECK_ACK
                        post_state   <= 4'd5; // WRITE_REG_ADDR
                        bit_cnt      <= 4'd8;
                     end
                     else begin
                        sda_di <= register_address[bit_cnt + 7];
                     end
                     process_cnt <= 2'd0;
                  end
               endcase
            end

         //----------------------
            4'd5: if (strobe_100kHz == 1'b1) begin // WRITE_REG_ADDR
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     scl_di      <= 1'b0;
                     bit_cnt     <= bit_cnt_dec;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     if (bit_cnt == 4'd0) begin
                        post_serial_data <= 1'b0;
                        post_state       <= 4'd6; // STOP
                        state            <= 4'd3; // CHECK_ACK
                        bit_cnt          <= 4'd8;
                     end
                     else begin
                        sda_di <= register_address[bit_cnt_dec];
                     end
                     process_cnt <= 2'd0;
                  end
               endcase
            end

         //----------------------
            4'd6: if (strobe_100kHz == 1'b1) begin // STOP
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     sda_di        <= 1'b1;
                     process_cnt   <= 2'd3;
                     register_done <= 1'b1;
                  end
                  2'd3: begin
                     state <= 4'd0; // IDLE
                  end
               endcase
            end

         //----------------------
            4'd7: if (strobe_100kHz == 1'b1) begin // RESTART
               case (process_cnt)
                  2'd0: begin
                     scl_di      <= 1'b1;
                     process_cnt <= 2'd1;
                  end
                  2'd1: begin
                     if (scl_do == 1'b1) process_cnt <= 2'd2; // Check for clock stretching
                  end
                  2'd2: begin
                     sda_di      <= 1'b1;
                     process_cnt <= 2'd3;
                  end
                  2'd3: begin
                     state <= 4'd0; // IDLE
                  end
               endcase
            end
         endcase // case (state)
      end // else: !if(areset_n == 1'b1)
   end // always @ (posedge clk or negedge areset_n)

endmodule // i2c_ctrl

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/2/10 Isam Vrce: Initial creation
 2024/8/29 Tarik Hamedović: Modification to work with WM8960 Audio CODEC

*/
