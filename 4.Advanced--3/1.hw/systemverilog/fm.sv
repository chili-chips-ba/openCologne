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
// Description: fmgen Module
//------------------------------------------------------------------------
// Module: FIR
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

module fm#(
   parameter logic STEREO = 0,
   parameter logic FILTER = 0,
   parameter logic DOWNSAMPLE = 0, // LO-FI LUT-saving option as default
   parameter int   RDS_MSG_LEN = 273, // allocates RAM for RDS binary message
   /*some useful values for C_rds_msg_len
   13 =        1*13 (CT)
   52 =        4*13 (PS)
   260 =   (16+4)*13 (PS+RT)
   273 = (16+4+1)*13 (PS+RT+CT)
   PS:  4 groups, main display 8 characters
   RT: 16 groups, long display 64 characters
   CT:  1 group,  time information
   1 group is 13 bytes long */
   parameter logic READABLE_REG = 0, // make registers readable (can work without, LUT saving)
   // TODO: Check if it is okay to ommit the initial values of the three parameters below(WARNING)
   parameter int   FMDDS_HZ, // Hz clk_fmdds (>2*108 MHz, e.g. 250 MHz, 325 MHz)
   parameter int   RDS_CLOCK_MULTIPLY, // multiply and divide from cpu clk 81.25 MHz
   parameter int   RDS_CLOCK_DIVIDE // to get 1.824 MHz for RDS logic   
)(
   input  logic               clk,
   input  logic               ce, 
   input  logic               bus_write,
   input  logic        [1:0]  addr, // address max 4 registers of 32-bit
   input  logic        [3:0]  byte_sel,
   input  logic        [31:0] bus_in,
   input  logic               clk_fmdds, // DDS clock, must be > 2x max cw_freq, normally > 216 MHz
   input  logic signed [15:0] pcm_in_left,
   input  logic signed [15:0] pcm_in_right,
   output logic        [31:0] bus_out,
   output logic               fm_irq, // interrupt request line (active level high)
   output logic               fm_antenna, // physical output
   output logic               pwm_out_left,
   output logic               pwm_out_right
);
   // TODO: Check difference between 'localparam' and 'const'
   localparam int REGISTERS = 3; // # of registers with memory <= (less or equal of) # of all registers
   localparam BITS = 32; // don't touch, default bit size of memory registers
   localparam int ADDR_BITS = int'(ceil(log2(real'(RDS_MSG_LEN) + 1.0E-6))-1.0E-6);

   // normal registers
   // type fm_reg_type  is std_logic_vector(C_bits-1 downto 0);
   typedef logic [BITS-1:0] fm_regs_type[REGISTERS-1:0];
   fm_reg_type R; // register access from mmapped I/O  R: active register, Rtmp temporary

   // *** REGISTERS ***
   // named constants for fm registers
   // this improves code readability
   // and provides flexible register (re)numbering

   localparam int CW_FREQ = 0; // input: 32-bit set cw frequency, writing resets rds_addr
   localparam int RDS_DATA = 1; // input:  8-bit RDS data sent in circular C_rds_msg_len
   localparam int RDS_ADDR = 2; // output: address currently being sent by RDS, input: address of wraparound

   // FM/RDS RADIO
   logic signed [15:0]          rds_pcm; // modulated PCM with audio and RDS
   logic        [ADDR_BITS-1:0] rds_addr; // RDS modulator reads BRAM from this addr during transmission
   logic        [7:0]           rds_data; // BRAM returns value to RDS for transmission
   logic                        rds_bram_write; // decoded address -> write signal for BRAM
   logic                        R_rds_bram_write; // 1 clock delayed write signal to offload timing constraints
   logic        [31:0]          from_fmrds; // debugging for subcarrier phase, not used

   generate
      if(READABLE_REG == 1'b1) begin : readable_registers
         always_comb begin
            case(addr)
               RDS_ADDR: bus_out = {{(32-ADDR_BITS){1'b0}}, rds_addr}; // Zero Extension
               default:  bus_out = R[addr];
            endcase
         end 
      end
   endgenerate  

   // CPU core writes registers
   generate
      for (genvar i = 0; i < BITS/8 - 1; i++) begin: writereg_intrflags
         always_ff @(posedge clk) begin
            if(byte_sel[i] == 1'b1 && ce == 1'b1 && bus_write == 1'b1) begin
               R[addr][8*i+7:8*i] <= bus_in[8*i+7:8*i];
            end
         end
      end
   endgenerate

   // write to circular RDS memory
   always_comb begin
      if(byte_sel[0] == 1'b1 && ce == 1'b1 && bus_write == 1'b1 && addr == RDS_DATA) begin
         rds_bram_write = 1'b1;
      end else begin
         rds_bram_write = 1'b0;
      end
    end   

   // RAM write delay 1 clock cycle
   always_ff @(posedge clk) begin
      R_rds_bram_write <= rds_bram_write;
   end

   rds #(
      .ADDR_BITS(ADDR_BITS), //number of address bits for RDS message RAM
      // multiply/divide to produce 1.824 MHz clock
      .RDS_CLOCK_MULTIPLY(RDS_CLOCK_MULTIPLY),
      .RDS_CLOCK_DIVIDE(RDS_CLOCK_DIVIDE),
      /*
      example settings for 25 MHz clock
      c_rds_clock_multiply => 228,
      c_rds_clock_divide => 3125,
      settings for super slow (100Hz debug) clock
      c_rds_clock_multiply => 1,
      c_rds_clock_divide => 812500,*/
      .FILTER(FILTER),
      .DOWNSAMPLE(DOWNSAMPLE),
      .STEREO(STEREO)

   )rds_modulator(
      .clk(clk), // RDS and PCM processing clock, same as CPU clock
      .rds_msg_len(R[RDS_ADDR][ADDR_BITS-1:0]),
      .addr(rds_addr),
      .data(rds_data),
      .pcm_in_left(pcm_in_left),
      .pcm_in_right(pcm_in_right),
      .debug(from_fmrds),
      .out_l(pwm_out_left),
      .out_r(pwm_out_right),
      .pcm_out(rds_pcm)
   );
   
   fmgen #(
      .FDDS(real'(FMDDS_HZ))
   )fm_modulator(
      .clk_pcm(clk), // PCM processing clock, same as CPU clock
      .clk_dds(clk_fmdds), // DDS clock must be > 2x cw_freq 
      .cw_freq(R[CW_FREQ]), // Hz FM carrier wave frequency, e.g. 107900000
      .pcm_in(rds_pcm),
      .fm_out(fm_antenna) 
   );
   
   bram_rds#(
      .MEM_BYTES(RDS_MSG_LEN), // allocate RAM for max message size
      .ADDR_BITS(ADDR_BITS) // number of address bits for RDS message RAM
   )rdsbram(
      .clk(clk),
      .imem_addr(rds_addr),
      .imem_data_out(rds_data),
      .dmem_write(R_rds_bram_write),
      .dmem_addr(R[RDS_DATA][16+ADDR_BITS-1:16]),
      .dmem_data_out(),
      .dmem_data_in(R[RDS_DATA][7:0])    
   );
      

endmodule
/*
registers:
- 0: 32-bit CW frequency (write only)
- 1: rds data (write only)
     byte 0:    8-bit address data to write
     byte 2-3: 11-bit address where to write
- 2: byte 0-1: 11-bit address of current byte send (read)
     byte 0-1: 11-bit RDS message length, address wraparound (write)

todo:
[ ] interrupt
[ ] reading from circular memory*/
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 TH: Initial creation

*/