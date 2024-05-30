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
// Description: fmgen_test Module
//------------------------------------------------------------------------
// Module: fmgen_test
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

module#(
   parameter int ADDR_BITS = 6, // must fit 2**n >= C_rds_msg_len
   parameter int RDS_MSG_LEN = 52, // RAM address range 0..n-1 for RDS binary message
   /*
   some useful values for C_rds_msg_len
   13 =        1*13 (CT)
   52 =        4*13 (PS)
   260 =   (16+4)*13 (PS+RT)
   273 = (16+4+1)*13 (PS+RT+CT)
   PS:  4 groups, main display 8 characters
   RT: 16 groups, long display 64 characters
   CT:  1 group,  time information
   1 group is 13 bytes long*/
   parameter int FMDDS_HZ = 240000000, // Hz clk_fmdds (>2*108 MHz, e.g. 250 MHz)
   
   // C_rds_clock_multiply: integer := 228; -- multiply and divide from clk 25 MHz
   // C_rds_clock_divide:   integer := 3125 -- to get 1.824 MHz for RDS logic*/
   parameter int RDS_CLOCK_MULTIPLY = 57, // multiply and divide from clk 40 MHz
   parameter int RDS_CLOCK_DIVIDE = 1250 // to get 1.824 MHz for RDS logic
)
fmgen_test
(
   input logic                        clk,
   input logic                        clk_fmdds, // DDS clock, must be > 2x max cw_freq, normally > 216 MHz
   input logic        [31:0]          cw_freq,
   input logic signed [15:0]          pcm_in_left,
   input logic signed [15:0]          pcm_in_right,
   input logic        [7:0]           rds_data, // read data byte from RDS RAM
   output logic       [ADDR_BITS-1:0] rds_addr, // set byte address to RDS RAM
	  output logic       [7:0]           led,
   output logic                       fm_antenna //physical output

);
   // localparam int ADDR_BITS = int'(ceil(log(real(RDS_MSG_LEN)+1.0E-6))-1.0E-6);
   localparam logic [ADDR_BITS-1:0] SET_RDS_MSG_LEN = logic'(RDS_MSG_LEN);

   // FM/RDS RADIO
   logic signed [15:0] rds_pcm; // modulated PCM with audio and RDS
   // logic [ADDR_BITS-1:0] rds_addr; // RDS modulator reads BRAM from this addr during transmission
   // logic [7:0] rds_data; // BRAM returns value to RDS for transmission
   logic rds_bram_write; // decoded address -> write signal for BRAM
   logic R_rds_bram_write; // 1 clock delayed write signal to offload timing constraints
   logic [31:0] from_fmrds; // debugging for subcarrier phase, not used

   rds_modulator #(
      .c_addr_bits(ADDR_BITS), // number of address bits for RDS message RAM
      // multiply/divide to produce 1.824 MHz clock
      .c_rds_clock_multiply(RDS_CLOCK_MULTIPLY),
      .c_rds_clock_divide(RDS_CLOCK_DIVIDE),
      .c_filter(1'b1),
      .c_downsample(1'b0),
      .c_stereo(1'b1)
   ) rds_modulator (
    /* example settings for 25 MHz clock
       c_rds_clock_multiply => 228,
       c_rds_clock_divide   => 3125,
       example settings for 40 MHz clock
       c_rds_clock_multiply => 57,
       c_rds_clock_divide   => 1250,
       settings for super slow (100Hz debug) clock
       c_rds_clock_multiply => 1,
       c_rds_clock_divide => 812500,*/
       .clk(clk), // RDS and PCM processing clock, same as CPU clock
       .rds_msg_len(SET_RDS_MSG_LEN),
       .addr(rds_addr)
       .data(rds_data),
       .pcm_in_left(pcm_in_left),
       .pcm_in_right(pcm_in_right),
       .pcm_out(rds_pcm)
   );

   fmgen #(
        .c_fdds(real'(FMDDS_HZ))
   ) fm_modulator (
        .clk_pcm(clk), // PCM processing clock, same as CPU clock
        .clk_dds(clk_fmdds), // DDS clock must be > 2x cw_freq 
        .cw_freq(cw_freq), // Hz FM carrier wave frequency, e.g. 107900000
        .pcm_in(rds_pcm),
        .fm_out(fm_antenna)
    );

    // Uncomment and complete if the bram_rds module is required
    /*
    rdsbram #(
        .c_mem_bytes(C_rds_msg_len), // allocate RAM for max message size
        .c_addr_bits(C_addr_bits) // number of address bits for RDS message RAM
    ) rdsbram_inst (
        .clk(clk),
        .imem_addr(rds_addr),
        .imem_data_out(rds_data),
        .dmem_write(R_rds_bram_write),
        .dmem_addr({default: '0}),
        .dmem_data_out(),
        .dmem_data_in({default: '0})
    );

    assign led = rds_data[7:0];
    assign led = rds_addr[7:0];
    */

endmodule
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 TH: Initial creation

*/