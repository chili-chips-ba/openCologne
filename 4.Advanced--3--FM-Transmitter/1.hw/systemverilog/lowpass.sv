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
// Description: <your text goes here>
//========================================================================

/*
-----------------------------------------------------------------------------
Module: lowpass
Description:


This module simulates a simple RC low-pass filter using a clock and enable signal to define the sampling frequency.
The low-pass frequency is determined by the ratio of input bits to output bits, adjusted by an attenuation factor.

Lowpass frequency is:
f_lowpass = f_sampling / 2^(C_bits_out-C_bits_in)

Time factor: RC = 2^(C_bits_out-C_bits_in)

At each sample this iteration is done:
-sum = sum + data_in - sum/RC
-sum is connected to output

RC low pass filter analogy: 
voltage difference between input signal and charged capacitor C makes a charging current through resistor R
sum = voltage of capacitor
data_in - sum/RC = charging current

Inputs:
- clock: Clock signal.
- enable: Enable signal to reduce the sampling frequency.
- data_in: Input data signal.

Outputs:
- data_out: Output data signal.

Parameters:
- C_bits_in: Number of bits for the input signal (default is 12).
- C_attenuation: Attenuation factor, represented as a power of 2 (default is 0).
- C_bits_out: Number of bits for the output signal (default is 16).
-----------------------------------------------------------------------------
*/

module lowpass#(
   parameter integer BITS_IN = 12, // input bits, must be less than C_bits_out
   parameter integer ATTENUATION = 0, // attenuation factor 2^n 
   parameter integer BITS_OUT = 16 // output bits(integrator sum)
)(
   input  logic clock, // can run at high freq (CPU)
   input  logic enable, // enable signal is a way to reduce sampling frequency
   input  logic signed [BITS_IN -1:0] data_in,
   output logic signed [BITS_OUT-1:0] data_out
);

 reg signed [BITS_IN -1:0] r_data_in;
 reg signed [BITS_OUT-1:0] sum;

always_ff @(posedge clock) begin
   
   if(enable == 1'b1) begin
      r_data_in <= data_in;
      sum <= (sum + (r_data_in >>> ATTENUATION)) - (sum >>> 2**(BITS_OUT-BITS_IN));
      data_out <= sum;
   end
end
endmodule

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/27 TH: Initial creation

*/

