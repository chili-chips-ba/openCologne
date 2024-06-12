`default_nettype none
module leds (
	clk,
	opl3_reg_wr,
	led
);
	reg _sv2v_0;
	input wire clk;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [17:0] opl3_reg_wr;
	localparam opl3_pkg_NUM_LEDS = 4;
	output reg [3:0] led = 0;
	generate
		if (1) begin : genblk1
			genvar _gv_i_3;
			for (_gv_i_3 = 0; _gv_i_3 < opl3_pkg_NUM_LEDS; _gv_i_3 = _gv_i_3 + 1) begin : led_gen
				localparam i = _gv_i_3;
				always @(posedge clk)
					if ((opl3_reg_wr[17] && (opl3_reg_wr[16] == 0)) && (opl3_reg_wr[15-:8] == ('hb0 + i)))
						led[i] <= opl3_reg_wr[5];
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
