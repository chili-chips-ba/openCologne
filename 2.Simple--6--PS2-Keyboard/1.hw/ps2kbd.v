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
// Adapted from ulx3s-misc: https://github.com/emard/ulx3s-misc/blob/master/examples/ps2/kbd/hdl/ps2kbd.v
// Original Author: Paul Ruiz
// PS/2 Keyboard Interface - Input Only
// Algorithm based on a VHDL routine by Grant Searle
//========================================================================

module ps2kbd(
  input wire       clk,
  input wire       ps2_clk,
  input wire       ps2_data,

  output reg [7:0] ps2_code,
  output reg       strobe,
  output reg       err
);

  // sync ps2_data
  reg ser_in;
  always @(posedge clk) begin
     ser_in <= ps2_data;
  end

  // sync & 'debounce' ps2_clock
  parameter integer LEN = 8;

  reg         bitclk = 0;
  reg [LEN:0] stable = 0;

  always @(posedge clk) begin
    stable = { stable[LEN-1:0], ps2_clk };
    if ( &stable) bitclk <= 1;
    if (~|stable) bitclk <= 0;
  end

  wire bitedge = bitclk && (~|stable[LEN-1:0]);

  // clock in KBD bits (start - 8 data - odd parity - stop)
  reg [8:0] shift  = 0;
  reg [3:0] bitcnt = 0;
  reg       parity = 0;

  always @(posedge clk) begin
    strobe <= 1'b0;
    err    <= 1'b0;

    if (bitedge == 1'b1) begin
      // wait for start bit
      if (bitcnt==0) begin
        parity <= 0;
        if (ser_in == 1'b0) begin
           bitcnt <= bitcnt + 4'b0001;
        end
      end
      // shift in 9 bits (8 data + parity)
      else if (bitcnt<10) begin
        shift  <= { ser_in, shift[8:1] };
        parity <= parity ^ ser_in;
        bitcnt <= bitcnt + 4'b0001;
      end else begin
      // check stop bit, parity
        bitcnt <= 4'b0000;
        if (parity == 1'b1 && ser_in == 1'b1) begin
          ps2_code <= shift[7:0];
          strobe   <= 1'b0;
        end else begin
          err      <= 1'b0;
        end
      end
    end
  end

endmodule
