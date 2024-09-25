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
// 1-wire (owr) master  
// Inspo: Iztok Jeras - https://github.com/jeras/sockit_owm
//========================================================================

//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// The clock divider parameter is computed with the next formula:           //
//                                                                          //
// CDR_N = f_CLK * BTP_N - 1  (example: CDR_N = 1MHz * 5.0us - 1 = 5-1)     //
// CDR_O = f_CLK * BTP_O - 1  (example: CDR_O = 1MHz * 1.0us - 1 = 1-1)     //
//                                                                          //
// If the dividing factor is not a round integer, than the timing of the    //
// controller will be slightly off, and would support only a subset of      //
// 1-wire devices with timing closer to the typical 30us slot.              //
//                                                                          //
// Base time periods BTP_N = "5.0" and BTP_O = "1.0" are optimized for      //
// onewire timing. The default timing restricts the range of available      //
// frequences to multiples of 1MHz.                                         //
//                                                                          //
// If even this restrictions are too strict use timing BTP_N = "6.0" and    //
// BTP_O = "0.5", where the actual periods can be in the range:             //
// 6.0us <= BTP_N <= 7.5us                                                  //
// 0.5us <= BTP_O <= 0.66us                                                 //
//                                                                          //
// A third timing option is available for normal mode BTP_N = "7.5", this   //
// option is optimized for logic size.                                      //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

module onewire_master #(
   // enable implementation of optional functionality
   parameter OVD_E =    0,  // overdrive functionality is implemented by default
   // interface parameters
   parameter OWN   =    1,  // number of 1-wire ports
   // base time period
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
   // system signals
   input   logic       clk,
   input   logic       arst_n,
   // CPU bus interface
   inout   logic       onewire,

   input   logic [3:0] bits_to_rw, //8 max
   output  logic [7:0] onewire_rdat,
   input   logic [7:0] onewire_wdat,

   input   logic       vld,
   output  logic       rdy,
   
   input   logic       we,
   output  logic       read
);

//-----------------
// local parameters
//-----------------
   // size of boudrate generator counter (divider for normal mode is largest)
   localparam CDW = $clog2(CDR_N);
   // size of port select signal
   localparam SDW = $clog2(OWN);
   // size of cycle timing counter
   localparam TDW =       (T_RSTH_O+T_RSTL_O) >       (T_RSTH_N+T_RSTL_N)
                  ? $clog2(T_RSTH_O+T_RSTL_O) : $clog2(T_RSTH_N+T_RSTL_N);

//--------------
// local signals
//--------------
   // clock divider
   logic  [CDW:0] div;
   logic          pls;
   // cycle control and status
   logic  [TDW-1:0] cnt;      // cycle counter
   // onewire signals
   logic            owr_ovd;  // overdrive
   logic            owr_oe;  // output enable
   // timing signals
   logic [TDW-1:0] t_idl ;   // idle                 cycle    time
   logic [TDW-1:0] t_rst ;   // reset                cycle    time
   logic [TDW-1:0] t_bit ;   // data bit             cycle    time
   logic [TDW-1:0] t_rstp;   // reset presence pulse sampling time
   logic [TDW-1:0] t_rsth;   // reset                release  time
   logic [TDW-1:0] t_dat0;   // data bit 0           release  time
   logic [TDW-1:0] t_dat1;   // data bit 1           release  time
   logic [TDW-1:0] t_bits;   // data bit             sampling time
   logic [TDW-1:0] t_zero;   // end of               cycle    time
   logic [TDW-1:0] t_rcvr;   // recovery             cycle    time

//--------------
// cycle timing
//--------------
   // idle time
   assign t_idl  = owr_ovd ? T_IDLE_O                       : T_IDLE_N                      ;
   // reset cycle time (reset low + reset hight)
   assign t_rst  = owr_ovd ? T_RSTL_O + T_RSTH_O            : T_RSTL_N + T_RSTH_N           ;
   // data bit cycle time (write 0 + recovery)
   assign t_bit  = owr_ovd ? T_DAT0_O +          + T_RCVR_O : T_DAT0_N +            T_RCVR_N;
   // reset presence pulse sampling time (reset high - reset presence)
   assign t_rstp = owr_ovd ? T_RSTH_O - T_RSTP_O            : T_RSTH_N - T_RSTP_N           ;
   // reset      release time (reset high)
   assign t_rsth = owr_ovd ? T_RSTH_O                       : T_RSTH_N                      ;
   // data bit 0 release time (write bit 0 - write bit 0 + recovery)
   assign t_dat0 = owr_ovd ? T_DAT0_O - T_DAT0_O + T_RCVR_O : T_DAT0_N - T_DAT0_N + T_RCVR_N;
   // data bit 1 release time (write bit 0 - write bit 1 + recovery)
   assign t_dat1 = owr_ovd ? T_DAT0_O - T_DAT1_O + T_RCVR_O : T_DAT0_N - T_DAT1_N + T_RCVR_N;
   // data bit sampling time (write bit 0 - write bit 1 + recovery)
   assign t_bits = owr_ovd ? T_DAT0_O - T_BITS_O + T_RCVR_O : T_DAT0_N - T_BITS_N + T_RCVR_N;
   // recovery
   assign t_rcvr = owr_ovd ? T_RCVR_O : T_RCVR_N;
   // end of cycle time
   assign t_zero = 'd0;
   // overdrive request
   assign owr_ovd = OVD_E;

//--------------------------------
// clock divider - pls is tick_Xus
//--------------------------------
   always_ff @ (posedge clk) begin
      if (arst_n == 1'b0) begin
         div <= 'd0;
      end
      else begin
         div <=  pls ? 'd0 : div + 1'b1; // + owr_cyc; not exac sure
      end
   end
   // divided clock pulse
   assign pls = (div == (owr_ovd ? CDR_O : CDR_N));

//----------------------------
// State machine
//----------------------------
   typedef enum logic [3:0] { 
      IDLE       = 4'd0, // waiting on rw vld signal
      RESET      = 4'd1, // reset procedure before starting com with slave
      PRESENCE   = 4'd2, // waiting presence signal from slave
      WAIT_4_RDY = 4'd3, // slave lets the line go after presence
      READ       = 4'd4, // read sequence
      WRITE      = 4'd5, // write sequence
      RECOVERY   = 4'd6  // recovery after every rw 
   } onewire_state_t;

   onewire_state_t state;
   logic owr_wing;                       // owr master in writing procedure
   logic [3:0] bits_rw_cur, bits_rw;
   logic [7:0] data_to_write, data_read;

   assign onewire      = owr_oe? 1'b0 : 1'bz; // line pulled down or z
   assign onewire_rdat = data_read;

   always_ff @(posedge clk) begin : _state_machine
      if(arst_n == 1'b0) begin
         state     <= RESET;
         owr_oe    <= 1'b1;
         cnt       <= t_rst;
         data_read <= '0;
      end
      else begin
         unique case(state) 
         
            IDLE: begin
               if(vld) begin
                  state         <= RECOVERY;
                  bits_rw       <= bits_to_rw; // how many bits to r/w
                  data_to_write <= onewire_wdat;
                  bits_rw_cur   <= '0;
                  owr_wing      <= we;
                  owr_oe        <= 1'b0;
                  read          <= 1'b0;
               end
            end

            RESET: begin
               if(pls) begin
                  cnt      <= cnt - 'd1;          
               end
               if(cnt == t_rsth) begin
                  owr_oe  <= 1'b0;        // wire to z 
               end
               if(cnt == t_rstp) begin   // opet ide low 
                  state   <= PRESENCE;
               end
            end

            PRESENCE: begin              // device is present if 0 is put
               if(pls) begin
                  cnt        <= cnt - 'd1;          
                  if(onewire == 1'b0) begin
                     state   <= WAIT_4_RDY;
                  end
                  if(cnt == 0)        begin
                     state   <= IDLE;
                  end
               end
            end

            WAIT_4_RDY: begin
               if(onewire == 1'b1) begin
                  state    <= IDLE;
                  rdy      <= 1'b1;
                  cnt      <= t_rcvr;
               end
            end

            WRITE: begin
            // writing sequence for number of bits
            // pull down 1-15 us for write 1 then release 
            // pull down 60-120us for write 0 then release
            // slave samples after some while and finds a one or 0 on the line
               if(pls) begin
                     cnt      <= cnt - 'd1;     
                     if(cnt == 'd0) begin
                        bits_rw_cur <= bits_rw_cur + 'd1;
                        state    <= RECOVERY;
                        cnt      <= t_rcvr;
                     end     
               end
               if(cnt == t_dat0  && data_to_write[bits_rw_cur[2:0]] == 1'b0 ||
                  cnt == t_dat1  && data_to_write[bits_rw_cur[2:0]] == 1'b1 ||
                  cnt == 'd0 ) begin  //for now [0]
                  
                  owr_oe <= 1'b0; // release line
               end
            end

            READ: begin
            // reading sequence for number of bits
            // host write 1 sequence, then sample later, 0 or 1 gets sampled
               if(pls) begin
                  cnt      <= cnt - 'd1;
                  if(cnt == t_dat1) begin
                     owr_oe <= 1'b0; 
                  end
                  if(cnt == t_bits >> 1) begin //sampling time half of set sampling time
                     data_read[bits_rw_cur[2:0]] <= onewire;
                  end
                  if(cnt == '0) begin
                     state    <= RECOVERY;
                     bits_rw_cur <= bits_rw_cur + 'd1;
                     cnt      <= t_rcvr;
                  end
               end
            end

            RECOVERY: begin
               if(pls) begin
                  cnt      <= cnt - 'd1;          
               end
               if(cnt == 0) begin
                  if(bits_rw_cur == bits_rw) begin
                     state    <= IDLE;
                     rdy      <= 1'b1;
                     if(owr_wing == 1'b0) begin
                        read  <= 1'b1;
                     end
                  end 
                  else begin
                     cnt      <= t_bit;
                     owr_oe   <= 1'b1;
                     if(owr_wing) begin
                        state <= WRITE;
                     end
                     else begin
                        state <= READ;
                     end
                  end
               end
            end

            default: state <= IDLE;
         endcase
      end
   end
endmodule
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/09/22 TarikI: initial creation    
*/