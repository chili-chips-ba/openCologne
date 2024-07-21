`default_nettype none
module channels (
	clk,
	reset,
	clk_dac,
	opl3_reg_wr,
	sample_clk_en,
	sample_valid,
	sample_l,
	sample_r
);
	reg _sv2v_0;
	input wire clk;
	input wire reset;
	input wire clk_dac;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [17:0] opl3_reg_wr;
	input wire sample_clk_en;
	output wire sample_valid;
	localparam opl3_pkg_DAC_OUTPUT_WIDTH = 24;
	output wire signed [23:0] sample_l;
	output wire signed [23:0] sample_r;
	localparam opl3_pkg_OP_OUT_WIDTH = 13;
	localparam CHANNEL_OUT_WIDTH = 15;
	localparam opl3_pkg_NUM_BANKS = 2;
	localparam opl3_pkg_NUM_OPERATORS_PER_BANK = 18;
	localparam CHANNEL_ACCUMULATOR_WIDTH = 20;
	wire [19:0] operator_out;
	wire signed [12:0] operator_mem_out;
	localparam opl3_pkg_SAMPLE_WIDTH = 16;
	reg signed [15:0] channel_l = 0;
	reg signed [15:0] channel_r = 0;
	reg channel_valid = 0;
	wire ops_done_pulse;
	localparam opl3_pkg_REG_CONNECTION_SEL_WIDTH = 6;
	reg [5:0] connection_sel = 0;
	reg is_new = 0;
	reg ryt = 0;
	wire cha;
	wire chb;
	wire chc;
	wire chd;
	wire cnt;
	localparam opl3_pkg_REG_FB_WIDTH = 3;
	wire [2:0] fb_dummy;
	reg [31:0] state = 32'd0;
	reg [31:0] next_state;
	localparam opl3_pkg_NUM_CHANNELS_PER_BANK = 9;
	reg [76:0] self = 0;
	reg [76:0] next_self;
	reg [29:0] signals;
	always @(posedge clk) begin
		if (opl3_reg_wr[17]) begin
			if ((opl3_reg_wr[16] == 1) && (opl3_reg_wr[15-:8] == 4))
				connection_sel <= opl3_reg_wr[5:0];
			if ((opl3_reg_wr[16] == 1) && (opl3_reg_wr[15-:8] == 5))
				is_new <= opl3_reg_wr[0];
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 'hbd))
				ryt <= opl3_reg_wr[5];
		end
		if (reset) begin
			connection_sel <= 0;
			is_new <= 0;
		end
	end
	localparam [0:0] sv2v_uu_ch_abcd_cnt_mem_ext_reb_1 = 1'sb1;
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h9),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) ch_abcd_cnt_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'hc0)) && (opl3_reg_wr[15-:8] <= 'hc8)),
		.reb(sv2v_uu_ch_abcd_cnt_mem_ext_reb_1),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h9):8]),
		.bankb(self[49]),
		.addrb(signals[23-:4]),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob({chd, chc, chb, cha, fb_dummy, cnt})
	);
	control_operators control_operators(
		.clk(clk),
		.reset(reset),
		.sample_clk_en(sample_clk_en),
		.opl3_reg_wr(opl3_reg_wr),
		.connection_sel(connection_sel),
		.is_new(is_new),
		.ryt(ryt),
		.operator_out(operator_out),
		.ops_done_pulse(ops_done_pulse)
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_OP_OUT_WIDTH),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(1),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) operator_out_mem(
		.clk(clk),
		.wea(operator_out[19]),
		.reb(signals[24]),
		.banka(operator_out[18]),
		.addra(operator_out[17-:5]),
		.bankb(self[49]),
		.addrb(signals[29-:5]),
		.dia($signed(operator_out[12-:opl3_pkg_OP_OUT_WIDTH])),
		.dob(operator_mem_out)
	);
	always @(posedge clk)
		if (sample_clk_en) begin
			state <= 32'd0;
			self <= 0;
		end
		else begin
			state <= next_state;
			self <= next_self;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		next_state = state;
		next_self = self;
		signals = 0;
		(* full_case, parallel_case *)
		case (state)
			32'd0:
				if (ops_done_pulse)
					next_state = 32'd1;
			32'd1: begin
				next_state = 32'd2;
				signals[29-:5] = self[48-:5] + 3;
				signals[24] = 1;
			end
			32'd2: begin
				next_state = 32'd3;
				next_self[62-:13] = operator_mem_out;
				signals[29-:5] = self[48-:5];
				signals[24] = 1;
			end
			32'd3: begin
				signals[23-:4] = self[43-:4];
				signals[19-:15] = (cnt ? operator_mem_out + $signed(self[62-:13]) : $signed(self[62-:13]));
				if (ryt && (self[49] == 0))
					(* full_case, parallel_case *)
					case (self[43-:4])
						6: signals[19-:15] = $signed(self[62-:13]) * 2;
						7, 8: signals[19-:15] = (operator_mem_out + $signed(self[62-:13])) * 2;
						default:
							;
					endcase
				if (self[43-:4] < 3) begin
					if (self[49] == 0) begin
						signals[3] = !is_new || (cha && !connection_sel[self[43-:4]]);
						signals[2] = !is_new || (chb && !connection_sel[self[43-:4]]);
						signals[1] = !is_new || (chc && !connection_sel[self[43-:4]]);
						signals[0] = !is_new || (chd && !connection_sel[self[43-:4]]);
					end
					else begin
						signals[3] = cha && !connection_sel[self[43-:4] + 3];
						signals[2] = chb && !connection_sel[self[43-:4] + 3];
						signals[1] = chc && !connection_sel[self[43-:4] + 3];
						signals[0] = chd && !connection_sel[self[43-:4] + 3];
					end
				end
				else if (self[43-:4] < 6) begin
					if (self[49] == 0) begin
						signals[3] = !is_new || (cha && !connection_sel[self[43-:4] - 3]);
						signals[2] = !is_new || (chb && !connection_sel[self[43-:4] - 3]);
						signals[1] = !is_new || (chc && !connection_sel[self[43-:4] - 3]);
						signals[0] = !is_new || (chd && !connection_sel[self[43-:4] - 3]);
					end
					else begin
						signals[3] = cha && !connection_sel[self[43-:4]];
						signals[2] = chb && !connection_sel[self[43-:4]];
						signals[1] = chc && !connection_sel[self[43-:4]];
						signals[0] = chd && !connection_sel[self[43-:4]];
					end
				end
				else begin
					signals[3] = ((self[49] == 0) && !is_new) || cha;
					signals[2] = ((self[49] == 0) && !is_new) || chb;
					signals[1] = ((self[49] == 0) && !is_new) || chc;
					signals[0] = ((self[49] == 0) && !is_new) || chd;
				end
				(* full_case, parallel_case *)
				case ({signals[3], signals[1]})
					'b1, 'b10: next_self[39-:20] = $signed(self[39-:20]) + $signed(signals[19-:15]);
					'b11: next_self[39-:20] = $signed(self[39-:20]) + ($signed(signals[19-:15]) * 2);
					default:
						;
				endcase
				(* full_case, parallel_case *)
				case ({signals[2], signals[0]})
					'b1, 'b10: next_self[19-:CHANNEL_ACCUMULATOR_WIDTH] = $signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) + $signed(signals[19-:15]);
					'b11: next_self[19-:CHANNEL_ACCUMULATOR_WIDTH] = $signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) + ($signed(signals[19-:15]) * 2);
					default:
						;
				endcase
				if (self[43-:4] == 8) begin
					if (self[49] == 1) begin
						next_state = 32'd4;
						next_self[48-:5] = 0;
						next_self[43-:4] = 0;
						next_self[49] = 0;
					end
					else begin
						next_state = 32'd1;
						next_self[48-:5] = 0;
						next_self[49] = 1;
						next_self[43-:4] = 0;
					end
				end
				else begin
					next_state = 32'd1;
					(* full_case, parallel_case *)
					case (self[43-:4])
						2: next_self[48-:5] = 6;
						5: next_self[48-:5] = 12;
						default: next_self[48-:5] = self[48-:5] + 1;
					endcase
					next_self[43-:4] = self[43-:4] + 1;
				end
			end
			32'd4: begin
				next_state = 32'd5;
				signals[29-:5] = self[43-:4] + 9;
				signals[24] = 1;
			end
			32'd5: begin
				next_state = 32'd6;
				signals[29-:5] = self[43-:4] + 6;
				signals[24] = 1;
				next_self[75-:13] = operator_mem_out;
				signals[23-:4] = self[43-:4] + 3;
				next_self[76] = cnt;
			end
			32'd6: begin
				next_state = 32'd7;
				signals[23-:4] = self[43-:4];
				signals[29-:5] = ({cnt, self[76]} == 'b1 ? self[43-:4] + 3 : self[43-:4]);
				signals[24] = 1;
				next_self[62-:13] = operator_mem_out;
			end
			32'd7: begin
				signals[23-:4] = self[43-:4];
				(* full_case, parallel_case *)
				case ({cnt, self[76]})
					'b0: signals[19-:15] = $signed(self[75-:13]);
					'b1: signals[19-:15] = operator_mem_out + $signed(self[75-:13]);
					'b10: signals[19-:15] = operator_mem_out + $signed(self[75-:13]);
					'b11: signals[19-:15] = (operator_mem_out + $signed(self[62-:13])) + $signed(self[75-:13]);
				endcase
				if (self[49] == 0) begin
					signals[3] = cha && connection_sel[self[43-:4]];
					signals[2] = chb && connection_sel[self[43-:4]];
					signals[1] = chc && connection_sel[self[43-:4]];
					signals[0] = chd && connection_sel[self[43-:4]];
				end
				else begin
					signals[3] = cha && connection_sel[self[43-:4] + 3];
					signals[2] = chb && connection_sel[self[43-:4] + 3];
					signals[1] = chc && connection_sel[self[43-:4] + 3];
					signals[0] = chd && connection_sel[self[43-:4] + 3];
				end
				(* full_case, parallel_case *)
				case ({signals[3], signals[1]})
					'b1, 'b10: next_self[39-:20] = $signed(self[39-:20]) + $signed(signals[19-:15]);
					'b11: next_self[39-:20] = $signed(self[39-:20]) + ($signed(signals[19-:15]) * 2);
					default:
						;
				endcase
				(* full_case, parallel_case *)
				case ({signals[2], signals[0]})
					'b1, 'b10: next_self[19-:CHANNEL_ACCUMULATOR_WIDTH] = $signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) + $signed(signals[19-:15]);
					'b11: next_self[19-:CHANNEL_ACCUMULATOR_WIDTH] = $signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) + ($signed(signals[19-:15]) * 2);
					default:
						;
				endcase
				if (self[43-:4] == 2) begin
					if (self[49] == 1)
						next_state = 32'd8;
					else begin
						next_state = 32'd4;
						next_self[43-:4] = 0;
						next_self[49] = 1;
					end
				end
				else begin
					next_state = 32'd4;
					next_self[43-:4] = self[43-:4] + 1;
				end
			end
			32'd8: begin
				next_state = 32'd0;
				next_self = 0;
				signals[4] = 1;
			end
		endcase
	end
	always @(posedge clk) channel_valid <= signals[4];
	always @(posedge clk)
		if (signals[4]) begin
			if ($signed(self[39-:20]) > 32767)
				channel_l <= 32767;
			else if ($signed(self[39-:20]) < -32768)
				channel_l <= -32768;
			else
				channel_l <= $signed(self[39-:20]);
			if ($signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) > 32767)
				channel_r <= 32767;
			else if ($signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]) < -32768)
				channel_r <= -32768;
			else
				channel_r <= $signed(self[19-:CHANNEL_ACCUMULATOR_WIDTH]);
		end
	dac_prep dac_prep(
		.clk(clk),
		.clk_dac(clk_dac),
		.channel_valid(channel_valid),
		.channel_l(channel_l),
		.channel_r(channel_r),
		.sample_valid(sample_valid),
		.sample_l(sample_l),
		.sample_r(sample_r)
	);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
