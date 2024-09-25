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
// Synthesizable 1-wire (owr) slave model
// Can be configured either to send or receive bits 
// on a predefined schedule following 1-Wire Master signals  
// Inspo: Iztok Jeras - https://github.com/jeras/sockit_owm
//========================================================================


// RW agreement must be known in advance
module onewire_slave_model #(
   // enable implementation of optional functionality
   parameter WRITE_E = 0,
   parameter OVD_E = 0,
   // time slot (min=15.0, typ=30.0, max=60.0)
   parameter TS = 30.0,
   parameter BTP_N = "5.0", // normal    mode (5.0us, options are "7.5", "5.0" and "6.0")
   parameter BTP_O = "1.0", // overdrive mode (1.0us, options are "1.0",       and "0.5")
   // normal mode timing
   parameter T_RSTH_N = (BTP_N == "7.5") ?  64 : (BTP_N == "5.0") ?  96 :  80,  // reset high
   parameter T_RSTL_N = (BTP_N == "7.5") ?  64 : (BTP_N == "5.0") ?  96 :  80,  // reset low
   parameter T_RSTP_N = (BTP_N == "7.5") ?  10 : (BTP_N == "5.0") ?  15 :  10,  // reset presence pulse
   parameter T_DAT0_N = (BTP_N == "7.5") ?   8 : (BTP_N == "5.0") ?  12 :  10,  // bit 0 low
   parameter T_DAT1_N = (BTP_N == "7.5") ?   1 : (BTP_N == "5.0") ?   1 :   1,  // bit 1 low
   parameter T_BITS_N = (BTP_N == "7.5") ?   2 : (BTP_N == "5.0") ?   3 :   2,  // bit sample
   parameter T_RCVR_N = (BTP_N == "7.5") ?   1 : (BTP_N == "5.0") ?   1 :   1,  // recovery
   parameter T_IDLE_N = (BTP_N == "7.5") ? 128 : (BTP_N == "5.0") ? 200 : 160,  // idle timer
   // overdrive mode timing
   parameter T_RSTH_O = (BTP_O == "1.0") ?  48 :  96,  // reset high
   parameter T_RSTL_O = (BTP_O == "1.0") ?  48 :  96,  // reset low
   parameter T_RSTP_O = (BTP_O == "1.0") ?  10 :  15,  // reset presence pulse
   parameter T_DAT0_O = (BTP_O == "1.0") ?   6 :  12,  // bit 0 low
   parameter T_DAT1_O = (BTP_O == "1.0") ?   1 :   2,  // bit 1 low
   parameter T_BITS_O = (BTP_O == "1.0") ?   2 :   3,  // bit sample
   parameter T_RCVR_O = (BTP_O == "1.0") ?   2 :   4,  // recovery
   parameter T_IDLE_O = (BTP_O == "1.0") ?  96 : 192,  // idle timer
   // clock divider ratios (defaults are for a 2MHz clock)
   parameter CDR_N = 50-1,  // normal mode - description how to set
   parameter CDR_O = 10-1   // overdrive mode
)(
   input  logic  clk,
   input  logic  arst_n,
   output logic [7:0] written_data,
   output logic wrote,
   inout  wire  onewire
);

   localparam CDW = $clog2(CDR_N);
   localparam TDW =       (T_RSTH_O+T_RSTL_O) >       (T_RSTH_N+T_RSTL_N)
                  ? $clog2(T_RSTH_O+T_RSTL_O) : $clog2(T_RSTH_N+T_RSTL_N);

   logic [TDW-1:0] t_rstp;   // reset presence pulse sampling time
   logic [TDW-1:0] t_rsth;   // reset                release  time
   logic [TDW-1:0] t_dat0;   // data bit 0           release  time
   logic [TDW-1:0] t_dat1;   // data bit 1           release  time
   logic [TDW-1:0] t_bits;   // data bit             sampling time
   logic [TDW-1:0] t_bit ;   // data bit             cycle    time

   logic     read_bit;
   logic  [CDW:0] div;
   logic          pls;
   logic      owr_ovd;  
//--------------------------------
// clock divider - pls is tick_Xus
//--------------------------------
   always_ff @(posedge clk) begin
      if (arst_n == 1'b0) begin
         div <= 'd0;
      end
      else begin
         div <=  pls ? 'd0 : div + 1'b1; // + owr_cyc; not exac sure
      end
   end
   // divided clock pulse
   assign owr_ovd = OVD_E;
   assign pls = (div == (owr_ovd ? CDR_O : CDR_N));

   assign t_rstp  = owr_ovd ? T_RSTH_O - T_RSTP_O            : T_RSTH_N - T_RSTP_N           ;
   assign t_bit   = owr_ovd ? T_DAT0_O +          + T_RCVR_O : T_DAT0_N +            T_RCVR_N;
   assign t_dat1  = owr_ovd ? T_DAT0_O - T_DAT1_O + T_RCVR_O : T_DAT0_N - T_DAT1_N + T_RCVR_N;
   assign t_dat0  = owr_ovd ? T_DAT0_O - T_DAT0_O + T_RCVR_O : T_DAT0_N - T_DAT0_N + T_RCVR_N;
   assign t_bits  = owr_ovd ? T_DAT0_O - T_BITS_O + T_RCVR_O : T_DAT0_N - T_BITS_N + T_RCVR_N;

   // ---------------------
   // sim only sending part
   // ---------------------
   logic [7:0] bits_send;
   logic [2:0] num_bits, total_bits;
   initial begin
      bits_send  = 8'd65; //Ascii a
      total_bits = 3'd7;
   end

   typedef enum logic [3:0] { 
      IDLE       = 4'd0,
      RESET      = 4'd1,
      PRESENCE   = 4'd2,
      WAIT_4_COM = 4'd3,
      READ       = 4'd4,
      WRITE      = 4'd5,
      RECOVERY   = 4'd6
   } onewire_state_t;

   onewire_state_t slave_state;
   logic owr_oe;
   logic [TDW-1:0] cnt;      // cycle counter
   logic [7:0] shift;  
   assign onewire    = owr_oe? 1'b0 : 1'bz;

   always_ff @(posedge clk) begin
      if(arst_n == 1'b0) begin
         slave_state <= IDLE;
      end
      unique case(slave_state)
         IDLE: begin
            owr_oe         <= 1'b0;
            if(onewire == 1'b0) begin
               slave_state <= RESET;  
               shift       <= '0;        
               num_bits    <= '0;
            end
         end

         RESET: begin
            if(onewire == 1'b1) begin
               slave_state <= PRESENCE;
               cnt         <= t_rstp;
            end
         end

         PRESENCE: begin
            if(pls) begin
               cnt         <= cnt -'d1;  
            end
            if(cnt == t_rstp >> 1) begin
               owr_oe      <= 1'b1;
            end 
            if(cnt == '0) begin
               slave_state <= WAIT_4_COM; //this is known in the protocol
               cnt         <= t_bit;
               owr_oe      <= 1'b0;
            end
         end

         WAIT_4_COM: begin
            if(pls) begin
               read_bit <= onewire;
               if({onewire, read_bit} == 2'b01) begin // when line goes low comm starts
                  //go to r/w
                  if(WRITE_E) slave_state <= WRITE;
                  else        slave_state <= READ;
                  cnt                     <= t_bit;
               end
            end
         end

         READ: begin //master read
            if(cnt == t_bits) begin
               if(bits_send [num_bits] == 0) begin
                  owr_oe <= 1'b1;
               end
            end
            if(pls) begin
               cnt            <= cnt - 'd1;
               if(cnt == 'd1) begin     //shorten the time a bit
                  slave_state <= WAIT_4_COM; 
                  owr_oe      <= 1'b0;
                  num_bits    <= num_bits + 'd1;
                  read_bit    <= onewire;
               end
            end
         end

         WRITE: begin //master wire
         //sample after 45 us
            if(pls) begin
               cnt      <= cnt - 'd1;          
               if(cnt == t_bits >> 1) begin //sampling time half of set sampling time
                  read_bit       <= onewire;
                  shift[num_bits]<= onewire; 
               end

               if(cnt == 'd1) begin
                  slave_state    <= WAIT_4_COM;
                  owr_oe         <= 1'b0;
                  num_bits       <= num_bits + 'd1;
               end
            end
         end

         default: slave_state <= IDLE;
      endcase
   end

   assign written_data = shift;
   assign wrote   = (num_bits == 'd7);

endmodule
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/09/22 TarikI: initial creation    
*/