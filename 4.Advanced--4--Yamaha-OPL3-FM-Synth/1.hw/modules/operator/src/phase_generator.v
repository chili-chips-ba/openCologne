`default_nettype none
module phase_generator (
	clk,
	sample_clk_en,
	is_new,
	bank_num,
	op_num,
	phase_inc_p2,
	ws,
	env_p3,
	pg_reset_p2,
	modulation_p1,
	op_type_p0,
	out_p6
);
	reg _sv2v_0;
	input wire clk;
	input wire sample_clk_en;
	input wire is_new;
	localparam opl3_pkg_NUM_BANKS = 2;
	localparam opl3_pkg_BANK_NUM_WIDTH = 1;
	input wire [0:0] bank_num;
	localparam opl3_pkg_NUM_OPERATORS_PER_BANK = 18;
	localparam opl3_pkg_OP_NUM_WIDTH = 5;
	input wire [4:0] op_num;
	localparam opl3_pkg_PHASE_ACC_WIDTH = 20;
	input wire [19:0] phase_inc_p2;
	localparam opl3_pkg_REG_WS_WIDTH = 3;
	input wire [2:0] ws;
	localparam opl3_pkg_FINAL_ENV_WIDTH = 11;
	input wire [10:0] env_p3;
	input wire pg_reset_p2;
	localparam opl3_pkg_OP_OUT_WIDTH = 13;
	input wire [12:0] modulation_p1;
	input wire [2:0] op_type_p0;
	output reg signed [12:0] out_p6 = 0;
	localparam LOG_SIN_OUT_WIDTH = 12;
	localparam EXP_OUT_WIDTH = 10;
	localparam PIPELINE_DELAY = 6;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [19:0] phase_acc_p2;
	localparam opl3_pkg_PHASE_FINAL_WIDTH = 10;
	reg [9:0] phase_acc_shifted_p2;
	reg [19:0] phase_acc_p3 = 0;
	reg [9:0] final_phase_p3;
	reg [7:0] theta_p3;
	wire [9:0] rhythm_phase_p3;
	wire [11:0] log_sin_out_p4;
	reg [12:0] pre_gain_p4;
	reg [14:0] post_gain_p4;
	reg [2:0] ws_post_opl_p0;
	wire [20:3] ws_post_opl_p;
	wire [6:1] bank_num_p;
	wire [34:5] op_num_p;
	wire [20:3] op_type_p;
	wire [90:26] modulation_p;
	wire [69:40] final_phase_p;
	reg [13:0] env_shifted_p4 = 0;
	reg [12:0] level_p4;
	reg [12:0] level_p5 = 0;
	wire [9:0] exp_out_p5;
	reg [12:0] exp_out_post_level_p5;
	reg [12:0] neg_p5 = 0;
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) sample_clk_en_sr(
		.clk(clk),
		.in(sample_clk_en),
		.out(sample_clk_en_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_BANK_NUM_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) bank_num_sr(
		.clk(clk),
		.in(bank_num),
		.out(bank_num_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_OP_NUM_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) op_num_sr(
		.clk(clk),
		.in(op_num),
		.out(op_num_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(3),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) op_type_sr(
		.clk(clk),
		.in(op_type_p0),
		.out(op_type_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_OP_OUT_WIDTH),
		.STARTING_CYCLE(2),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) modulation_sr(
		.clk(clk),
		.in(modulation_p1),
		.out(modulation_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_PHASE_FINAL_WIDTH),
		.STARTING_CYCLE(4),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) final_phase_sr(
		.clk(clk),
		.in(final_phase_p3),
		.out(final_phase_p)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		ws_post_opl_p0 = ws;
		ws_post_opl_p0[2] = ws[2] && is_new;
	end
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_REG_WS_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) ws_post_opl_sr(
		.clk(clk),
		.in(ws_post_opl_p0),
		.out(ws_post_opl_p)
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_PHASE_ACC_WIDTH),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(2),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) phase_acc_mem(
		.clk(clk),
		.wea(sample_clk_en_p[3]),
		.reb(sample_clk_en),
		.banka(bank_num_p[3+:1]),
		.addra(op_num_p[15+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(phase_acc_p3),
		.dob(phase_acc_p2)
	);
	always @(posedge clk)
		if (pg_reset_p2)
			phase_acc_p3 <= 0;
		else
			phase_acc_p3 <= phase_acc_p2 + phase_inc_p2;
	always @(*) begin
		if (_sv2v_0)
			;
		phase_acc_shifted_p2 = phase_acc_p2 >> 9;
	end
	calc_rhythm_phase calc_rhythm_phase(
		.phase_p2(phase_acc_shifted_p2),
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.op_type_p0(op_type_p0),
		.rhythm_phase_p3(rhythm_phase_p3)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		final_phase_p3 = rhythm_phase_p3 + modulation_p[39+:13];
		(* full_case, parallel_case *)
		case (ws_post_opl_p[9+:3])
			0, 1, 2: theta_p3 = (final_phase_p3[8] ? final_phase_p3[7:0] ^ 'hff : final_phase_p3[7:0]);
			3: theta_p3 = final_phase_p3[7:0];
			4, 5: theta_p3 = (final_phase_p3[7] ? (final_phase_p3[7:0] ^ 'hff) << 1 : final_phase_p3[7:0] << 1);
			default: theta_p3 = final_phase_p3[7:0];
		endcase
	end
	opl3_log_sine_lut log_sine_lut_inst(
		.theta(theta_p3),
		.out(log_sin_out_p4),
		.clk(clk)
	);
	always @(posedge clk) env_shifted_p4 <= env_p3 << 3;
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (ws_post_opl_p[12+:3])
			0, 2: pre_gain_p4 = log_sin_out_p4;
			1, 4, 5: pre_gain_p4 = (final_phase_p[49] ? 'h1000 : log_sin_out_p4);
			3: pre_gain_p4 = (final_phase_p[48] ? 'h1000 : log_sin_out_p4);
			6: pre_gain_p4 = 0;
			7: pre_gain_p4 = (final_phase_p[49] ? final_phase_p[48-:9] ^ 'h1ff : final_phase_p[49-:10]) << 3;
		endcase
		post_gain_p4 = pre_gain_p4 + env_shifted_p4;
		level_p4 = (post_gain_p4 > 'h1fff ? 'h1fff : post_gain_p4);
	end
	opl3_exp_lut exp_lut_inst(
		.in(~post_gain_p4[7:0]),
		.out(exp_out_p5),
		.clk(clk)
	);
	always @(posedge clk) begin
		level_p5 <= level_p4;
		(* full_case, parallel_case *)
		case (ws_post_opl_p[12+:3])
			0, 6, 7: neg_p5 <= (final_phase_p[49] ? {13 {1'sb1}} : 0);
			4: neg_p5 <= (final_phase_p[49-:2] == 1 ? {13 {1'sb1}} : 0);
			default: neg_p5 <= 0;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		exp_out_post_level_p5 = ((exp_out_p5 | 'h400) << 1) >> (level_p5 >> 8);
	end
	always @(posedge clk) out_p6 <= exp_out_post_level_p5 ^ neg_p5;
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
