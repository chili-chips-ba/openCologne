`default_nettype none
module i2s (
	clk,
	sample_valid,
	left_channel,
	right_channel,
	i2s_sclk,
	i2s_ws,
	i2s_sd
);
	reg _sv2v_0;
	input wire clk;
	input wire sample_valid;
	localparam opl3_pkg_DAC_OUTPUT_WIDTH = 24;
	input wire [23:0] left_channel;
	input wire [23:0] right_channel;
	output reg i2s_sclk = 0;
	output reg i2s_ws = 0;
	output reg i2s_sd = 0;
	localparam BITS_PER_FRAME = 64;
	localparam opl3_pkg_ACTUAL_SAMPLE_FREQ = 49715;
	localparam SCLK_FREQ = 3181760;
	localparam opl3_pkg_CLK_FREQ = 12727000;
	localparam signed [31:0] SCLK_DIV = $ceil(1);
	reg i2s_sclk_en;
	reg [$clog2(SCLK_DIV) - 1:0] i2s_sclk_counter = 0;
	reg [5:0] bit_counter = 0;
	reg [47:0] left_channel_r = 0;
	reg [47:0] right_channel_r = 0;
	reg i2s_sclk_p0 = 0;
	always @(posedge clk)
		if (sample_valid) begin
			left_channel_r[0+:24] <= left_channel;
			right_channel_r[0+:24] <= right_channel;
		end
		else if ((bit_counter == 62) && i2s_sclk_en) begin
			left_channel_r[24+:24] <= left_channel_r[0+:24];
			right_channel_r[24+:24] <= right_channel_r[0+:24];
		end
	always @(posedge clk)
		if (i2s_sclk_counter == (SCLK_DIV - 1))
			i2s_sclk_counter <= 0;
		else
			i2s_sclk_counter <= i2s_sclk_counter + 1;
	always @(posedge clk)
		if (i2s_sclk_counter == (SCLK_DIV - 1))
			i2s_sclk_p0 <= !i2s_sclk_p0;
	always @(posedge clk) i2s_sclk <= !i2s_sclk_p0;
	always @(*) begin
		if (_sv2v_0)
			;
		i2s_sclk_en = (i2s_sclk_counter == (SCLK_DIV - 1)) && !i2s_sclk_p0;
	end
	always @(posedge clk)
		if (i2s_sclk_en) begin
			if (bit_counter == 63)
				bit_counter <= 0;
			else
				bit_counter <= bit_counter + 1;
		end
	always @(posedge clk) i2s_ws <= (bit_counter >= 31) && (bit_counter != 63);
	always @(posedge clk)
		(* full_case, parallel_case *)
		case (bit_counter)
			0: i2s_sd <= left_channel_r[47];
			1: i2s_sd <= left_channel_r[46];
			2: i2s_sd <= left_channel_r[45];
			3: i2s_sd <= left_channel_r[44];
			4: i2s_sd <= left_channel_r[43];
			5: i2s_sd <= left_channel_r[42];
			6: i2s_sd <= left_channel_r[41];
			7: i2s_sd <= left_channel_r[40];
			8: i2s_sd <= left_channel_r[39];
			9: i2s_sd <= left_channel_r[38];
			10: i2s_sd <= left_channel_r[37];
			11: i2s_sd <= left_channel_r[36];
			12: i2s_sd <= left_channel_r[35];
			13: i2s_sd <= left_channel_r[34];
			14: i2s_sd <= left_channel_r[33];
			15: i2s_sd <= left_channel_r[32];
			16: i2s_sd <= left_channel_r[31];
			17: i2s_sd <= left_channel_r[30];
			18: i2s_sd <= left_channel_r[29];
			19: i2s_sd <= left_channel_r[28];
			20: i2s_sd <= left_channel_r[27];
			21: i2s_sd <= left_channel_r[26];
			22: i2s_sd <= left_channel_r[25];
			23: i2s_sd <= left_channel_r[24];
			32: i2s_sd <= right_channel_r[47];
			33: i2s_sd <= right_channel_r[46];
			34: i2s_sd <= right_channel_r[45];
			35: i2s_sd <= right_channel_r[44];
			36: i2s_sd <= right_channel_r[43];
			37: i2s_sd <= right_channel_r[42];
			38: i2s_sd <= right_channel_r[41];
			39: i2s_sd <= right_channel_r[40];
			40: i2s_sd <= right_channel_r[39];
			41: i2s_sd <= right_channel_r[38];
			42: i2s_sd <= right_channel_r[37];
			43: i2s_sd <= right_channel_r[36];
			44: i2s_sd <= right_channel_r[35];
			45: i2s_sd <= right_channel_r[34];
			46: i2s_sd <= right_channel_r[33];
			47: i2s_sd <= right_channel_r[32];
			48: i2s_sd <= right_channel_r[31];
			49: i2s_sd <= right_channel_r[30];
			50: i2s_sd <= right_channel_r[29];
			51: i2s_sd <= right_channel_r[28];
			52: i2s_sd <= right_channel_r[27];
			53: i2s_sd <= right_channel_r[26];
			54: i2s_sd <= right_channel_r[25];
			55: i2s_sd <= right_channel_r[24];
			default: i2s_sd <= 0;
		endcase
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
