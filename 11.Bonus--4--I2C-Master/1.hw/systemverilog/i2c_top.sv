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
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGH
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
// Description: Top-level for I2C Master. It:
//   - implements state machine for sending data to I2C Controller
//   - instantiates the I2C Controller itself
//   - for most part operates in sync with external 100kHz strobe
//========================================================================

module i2c_top #(
   parameter I2C_SLAVE_ADDR = 7'd16
)(
   // Clocks and resets
   input  logic  clk,
   input  logic  strobe_100kHz, // 100kHz strobe synchronous to 'clk'
   input  logic  areset_n,      // Active-low asynchronous reset

   // I/O pads
   inout  wire   i2c_scl,
   inout  wire   i2c_sda
);

//--------------------------------
// I2C Master
//--------------------------------
   logic        i2c_enable;

   logic [15:0] i2c_reg_addr;
   logic [6:0]  i2c_reg_cnt;
   logic        i2c_reg_done;

   logic [15:0] i2c_data_init[65];

   logic        i2c_scl_do;
   logic        i2c_scl_di;

   logic        i2c_sda_do;
   logic        i2c_sda_di;

   i2c_ctrl u_i2c_ctrl (
      .clk              (clk),            // i
      .strobe_100kHz    (strobe_100kHz),  // i
      .areset_n         (areset_n),       // i

      .enable           (i2c_enable),     // i
      .slave_address    (I2C_SLAVE_ADDR), // i[6:0]
      .register_address (i2c_reg_addr),   // i[15:0]
      .register_done    (i2c_reg_done),   // o

      .scl_do           (i2c_scl_do),     // i
      .scl_di           (i2c_scl_di),     // o

      .sda_do           (i2c_sda_do),     // i
      .sda_di           (i2c_sda_di)      // o
   );

`ifndef SIM_ONLY
   initial $readmemh("../i2c_init.mem", i2c_data_init);
`else
   string i2c_init_mem_file;

   initial begin
      if ($value$plusargs("../i2c_init_mem_file=%s", i2c_init_mem_file)) begin
         $readmemh(i2c_init_mem_file, i2c_data_init);
      end else begin
         $readmemh("../i2c_init.mem", i2c_data_init);
      end
   end
`endif

   assign i2c_enable   = (i2c_reg_cnt < 7'd65);
   assign i2c_reg_addr = i2c_data_init[i2c_reg_cnt];

   always_ff @(negedge areset_n or posedge clk) begin
      if (!areset_n) begin
         i2c_reg_cnt <= '0;
      end else if ({strobe_100kHz, i2c_enable} == 2'b11) begin
         if (i2c_reg_done) begin
            if (i2c_reg_cnt < 7'd65) begin
               i2c_reg_cnt <= i2c_reg_cnt + 7'd1;
            end
         end
      end
   end

   CC_IOBUF #(
      .PIN_NAME("IO_EA_B0"),  // IO_<Dir><Bank>_<Pin><Pin#>
      .V_IO("2.5"),           // "1.2", "1.8" or "2.5" Volt
      .DRIVE("12"),           // "3", "6", "9" or "12" mA
      .SLEW("SLOW"),          // "SLOW" or "FAST"
      .PULLUP(0),             // 0: disable, 1: enable
      .PULLDOWN(0),           // 0: disable, 1: enable
      .KEEPER(0),             // 0: disable, 1: enable
      .SCHMITT_TRIGGER(0),    // 0: disable, 1: enable
      .DELAY_IBF(4'd0),       // input delay:  0..15
      .DELAY_OBF(4'd0),       // output delay: 0..15
      .FF_IBF(1'b0),          // 0: disable, 1: enable
      .FF_OBF(1'b0)           // 0: disable, 1: enable
   ) i2c_iobuf_sda (
      .IO(i2c_sda),
      .Y(i2c_sda_do),
      .A(1'b0),
      .T(i2c_sda_di)
   );

   CC_IOBUF #(
      .PIN_NAME("IO_EA_A0"),  // IO_<Dir><Bank>_<Pin><Pin#>
      .V_IO("2.5"),           // "1.2", "1.8" or "2.5" Volt
      .DRIVE("12"),           // "3", "6", "9" or "12" mA
      .SLEW("SLOW"),          // "SLOW" or "FAST"
      .PULLUP(0),             // 0: disable, 1: enable
      .PULLDOWN(0),           // 0: disable, 1: enable
      .KEEPER(0),             // 0: disable, 1: enable
      .SCHMITT_TRIGGER(0),    // 0: disable, 1: enable
      .DELAY_IBF(4'd0),       // input delay:  0..15
      .DELAY_OBF(4'd0),       // output delay: 0..15
      .FF_IBF(1'b0),          // 0: disable, 1: enable
      .FF_OBF(1'b0)           // 0: disable, 1: enable
   ) i2c_iobuf_scl (
      .IO(i2c_scl),
      .Y(i2c_scl_do),
      .A(1'b0),
      .T(i2c_scl_di)
   );

endmodule : i2c_top

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/2/30 Isam Vrce: Initial creation
 2024/6/6  Armin Zunic: More improvements
*/
