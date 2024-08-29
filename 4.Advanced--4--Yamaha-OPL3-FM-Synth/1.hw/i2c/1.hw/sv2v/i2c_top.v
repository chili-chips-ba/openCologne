module i2c_top (
	clk,
	strobe_100kHz,
	areset_n,
	i2c_scl,
	i2c_sda
);
	parameter I2C_SLAVE_ADDR = 7'd16;
	input wire clk;
	input wire strobe_100kHz;
	input wire areset_n;
	inout wire i2c_scl;
	inout wire i2c_sda;
	wire i2c_enable;
	wire [15:0] i2c_reg_addr;
	reg [6:0] i2c_reg_cnt;
	wire i2c_reg_done;
	reg [15:0] i2c_data_init [0:64];
	wire i2c_scl_do;
	wire i2c_scl_di;
	wire i2c_sda_do;
	wire i2c_sda_di;
	i2c_ctrl u_ctrl(
		.clk(clk),
		.strobe_100kHz(strobe_100kHz),
		.areset_n(areset_n),
		.enable(i2c_enable),
		.slave_address(I2C_SLAVE_ADDR),
		.register_address(i2c_reg_addr),
		.register_done(i2c_reg_done),
		.scl_do(i2c_scl_do),
		.scl_di(i2c_scl_di),
		.sda_do(i2c_sda_do),
		.sda_di(i2c_sda_di)
	);
	initial $readmemh("../i2c_init.mem", i2c_data_init);
	assign i2c_enable = i2c_reg_cnt < 7'd65;
	assign i2c_reg_addr = i2c_data_init[i2c_reg_cnt];
	always @(negedge areset_n or posedge clk)
		if (areset_n == 1'b0)
			i2c_reg_cnt <= 1'sb0;
		else if ({strobe_100kHz, i2c_enable} == 2'b11) begin
			if (i2c_reg_done == 1'd1) begin
				if (i2c_reg_cnt < 7'd65)
					i2c_reg_cnt <= i2c_reg_cnt + 7'd1;
			end
		end
	CC_IOBUF #(
		.PIN_NAME("IO_NA_B0"),
		.V_IO("2.5"),
		.DRIVE("12"),
		.SLEW("SLOW"),
		.PULLUP(0),
		.PULLDOWN(0),
		.KEEPER(0),
		.SCHMITT_TRIGGER(0),
		.DELAY_IBF(4'd0),
		.DELAY_OBF(4'd0),
		.FF_IBF(1'b0),
		.FF_OBF(1'b0)
	) i2c_iobuf_sda(
		.IO(i2c_sda),
		.Y(i2c_sda_do),
		.A(1'b0),
		.T(i2c_sda_di)
	);
	CC_IOBUF #(
		.PIN_NAME("IO_NA_B1"),
		.V_IO("2.5"),
		.DRIVE("12"),
		.SLEW("SLOW"),
		.PULLUP(0),
		.PULLDOWN(0),
		.KEEPER(0),
		.SCHMITT_TRIGGER(0),
		.DELAY_IBF(4'd0),
		.DELAY_OBF(4'd0),
		.FF_IBF(1'b0),
		.FF_OBF(1'b0)
	) i2c_iobuf_scl(
		.IO(i2c_scl),
		.Y(i2c_scl_do),
		.A(1'b0),
		.T(i2c_scl_di)
	);
endmodule
