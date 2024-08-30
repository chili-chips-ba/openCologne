module top (
	clk_10MHz,
	areset_n,
	led,
	i2c_scl,
	i2c_sda
);
	input wire clk_10MHz;
	input wire areset_n;
	output wire led;
	inout wire i2c_scl;
	inout wire i2c_sda;
	localparam integer NUM_CLK_FOR_100kHZ = 50;
	reg strobe_100kHz;
	reg [5:0] cnt_100kHz;
	function automatic [5:0] sv2v_cast_0E791;
		input reg [5:0] inp;
		sv2v_cast_0E791 = inp;
	endfunction
	always @(posedge clk_10MHz or negedge areset_n)
		if (areset_n == 1'b0) begin
			cnt_100kHz <= 1'sb0;
			strobe_100kHz <= 1'b0;
		end
		else if (cnt_100kHz == sv2v_cast_0E791(NUM_CLK_FOR_100kHZ - 1)) begin
			cnt_100kHz <= 1'sb0;
			strobe_100kHz <= 1'b1;
		end
		else begin
			cnt_100kHz <= sv2v_cast_0E791(cnt_100kHz + sv2v_cast_0E791(1));
			strobe_100kHz <= 1'b0;
		end
	localparam integer COUNTER_WIDTH = 24;
	reg [COUNTER_WIDTH - 1:0] counter;
	always @(posedge clk_10MHz)
		if (areset_n == 1'b0)
			counter <= 1'sb0;
		else
			counter <= counter + 1'b1;
	assign led = counter[COUNTER_WIDTH - 1];
	i2c_top #(.I2C_SLAVE_ADDR(7'd52)) u_i2c_top(
		.clk(clk_10MHz),
		.strobe_100kHz(strobe_100kHz),
		.areset_n(areset_n),
		.i2c_scl(i2c_scl),
		.i2c_sda(i2c_sda)
	);
endmodule
