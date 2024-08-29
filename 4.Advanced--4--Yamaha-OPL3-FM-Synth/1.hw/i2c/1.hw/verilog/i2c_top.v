// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2024 Chili.CHIPS*ba

module i2c_top #(
   parameter I2C_SLAVE_ADDR = 7'd16
)(
   input  wire  clk,
   input  wire  strobe_100kHz,
   input  wire  areset_n,
   inout  wire  i2c_scl,
   inout  wire  i2c_sda
);

//--------------------------------
// I2C Master Signals
//--------------------------------
   wire        i2c_enable;
   wire [15:0] i2c_reg_addr; 
   reg [6:0]   i2c_reg_cnt;
   wire        i2c_reg_done;

   reg [15:0]  i2c_data_init[0:64];

   wire        i2c_scl_do;
   wire        i2c_scl_di;

   wire        i2c_sda_do;
   wire        i2c_sda_di;

//--------------------------------
// I2C Controller Instantiation
//--------------------------------
   i2c_ctrl u_ctrl (
      .clk              (clk),
      .strobe_100kHz    (strobe_100kHz),
      .areset_n         (areset_n),

      .enable           (i2c_enable),
      .slave_address    (I2C_SLAVE_ADDR),
      .register_address (i2c_reg_addr),
      .register_done    (i2c_reg_done),

      .scl_do           (i2c_scl_do),
      .scl_di           (i2c_scl_di),

      .sda_do           (i2c_sda_do),
      .sda_di           (i2c_sda_di)
   );

//--------------------------------
// Initial Block for Register Data
//--------------------------------
`ifndef SIM_ONLY
   initial begin
      $readmemh("../i2c_init.mem", i2c_data_init);
   end
`else
   reg [255:0] i2c_init_mem_file;

   initial begin
      if ($value$plusargs("../i2c_init_mem_file=%s", i2c_init_mem_file)) begin
         $readmemh(i2c_init_mem_file, i2c_data_init);
      end
      else begin
         $readmemh("../i2c_init.mem", i2c_data_init);
      end
   end
`endif

//--------------------------------
// I2C Enable Signal
//--------------------------------
   assign i2c_enable = (i2c_reg_cnt < 7'd65);
   assign i2c_reg_addr = i2c_data_init[i2c_reg_cnt];

//--------------------------------
// Register Counter for I2C Transactions
//--------------------------------
   always @(negedge areset_n or posedge clk) begin
      if (areset_n == 1'b0) begin
         i2c_reg_cnt <= 7'd0;
      end
      else if (strobe_100kHz && i2c_enable) begin
         if (i2c_reg_done) begin
            if (i2c_reg_cnt < 7'd65) begin
               i2c_reg_cnt <= i2c_reg_cnt + 7'd1;
            end
         end
      end
   end

//--------------------------------
// I/O Buffers for I2C Lines
//--------------------------------
   CC_IOBUF #(
      .PIN_NAME("IO_NA_B0"), // IO_<Dir><Bank>_<Pin><Pin#>
      .V_IO("2.5"),          // "1.2", "1.8" or "2.5" Volt
      .DRIVE("12"),          // "3", "6", "9" or "12" mA
      .SLEW("SLOW"),         // "SLOW" or "FAST"
      .PULLUP(0),            // 0: disable, 1: enable
      .PULLDOWN(0),          // 0: disable, 1: enable
      .KEEPER(0),            // 0: disable, 1: enable
      .SCHMITT_TRIGGER(0),   // 0: disable, 1: enable
      .DELAY_IBF(4'd0),      // input delay:  0..15
      .DELAY_OBF(4'd0),      // output delay: 0..15
      .FF_IBF(1'b0),         // 0: disable, 1: enable
      .FF_OBF(1'b0)          // 0: disable, 1: enable
   ) i2c_iobuf_sda (
      .IO(i2c_sda),
      .Y(i2c_sda_do),
      .A(1'b0),
      .T(i2c_sda_di)
   );

   CC_IOBUF #(
      .PIN_NAME("IO_NA_B1"), // IO_<Dir><Bank>_<Pin><Pin#>
      .V_IO("2.5"),          // "1.2", "1.8" or "2.5" Volt
      .DRIVE("12"),          // "3", "6", "9" or "12" mA
      .SLEW("SLOW"),         // "SLOW" or "FAST"
      .PULLUP(0),            // 0: disable, 1: enable
      .PULLDOWN(0),          // 0: disable, 1: enable
      .KEEPER(0),            // 0: disable, 1: enable
      .SCHMITT_TRIGGER(0),   // 0: disable, 1: enable
      .DELAY_IBF(4'd0),      // input delay:  0..15
      .DELAY_OBF(4'd0),      // output delay: 0..15
      .FF_IBF(1'b0),         // 0: disable, 1: enable
      .FF_OBF(1'b0)          // 0: disable, 1: enable
   ) i2c_iobuf_scl (
      .IO(i2c_scl),
      .Y(i2c_scl_do),
      .A(1'b0),
      .T(i2c_scl_di)
   );

endmodule // top

