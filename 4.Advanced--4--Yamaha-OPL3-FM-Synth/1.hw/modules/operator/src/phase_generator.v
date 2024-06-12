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
	key_on_pulse_p0,
	modulation_p1,
	op_type,
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
	localparam opl3_pkg_ENV_WIDTH = 9;
	input wire [8:0] env_p3;
	input wire key_on_pulse_p0;
	localparam opl3_pkg_OP_OUT_WIDTH = 13;
	input wire [12:0] modulation_p1;
	input wire [2:0] op_type;
	output reg signed [12:0] out_p6 = 0;
	localparam LOG_SIN_OUT_WIDTH = 12;
	localparam EXP_IN_WIDTH = 8;
	localparam EXP_OUT_WIDTH = 10;
	localparam LOG_SIN_PLUS_GAIN_WIDTH = 13;
	localparam PIPELINE_DELAY = 6;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [PIPELINE_DELAY:1] key_on_pulse_p;
	wire [19:0] phase_acc_p2;
	reg [19:0] phase_acc_p3 = 0;
	reg [19:0] final_phase_p4 = 0;
	reg [19:0] final_phase_p5 = 0;
	wire prev_final_phase_msb_p2;
	reg prev_final_phase_msb_p3 = 0;
	reg prev_final_phase_msb_p4 = 0;
	wire is_odd_period_p2;
	reg is_odd_period_p3 = 0;
	reg is_odd_period_p4 = 0;
	reg is_odd_period_p5 = 0;
	reg is_odd_period_p6 = 0;
	wire [19:0] rhythm_phase_p3;
	wire [11:0] log_sin_out_p5;
	reg [12:0] log_sin_plus_gain_p5 = 0;
	reg [12:0] log_sin_plus_gain_p6 = 0;
	wire [9:0] exp_out_p6;
	reg [12:0] tmp_out0_p6;
	reg signed [12:0] tmp_out1_p6;
	reg signed [12:0] tmp_out2_p6;
	reg signed [12:0] tmp_ws2_p6;
	reg signed [12:0] tmp_ws4_p6;
	reg [11:0] tmp_ws7_p5 = 0;
	reg [2:0] ws_post_opl_p0;
	wire [20:3] ws_post_opl_p;
	reg [8:0] env_p4 = 0;
	reg [8:0] env_p5 = 0;
	wire [6:1] bank_num_p;
	wire [34:5] op_num_p;
	reg [12:0] modulation_p2 = 0;
	reg [22:0] modulation_shifted_p3 = 0;
	wire [20:3] op_type_p;
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) sample_clk_en_sr(
		.clk(clk),
		.in(key_on_pulse_p0),
		.out(key_on_pulse_p)
	);
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) key_on_pulse_sr(
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
		.in(op_type),
		.out(op_type_p)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		ws_post_opl_p0 = ws & (is_new ? 'h7 : 'h3);
	end
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_REG_WS_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) ws_post_opl_sr(
		.clk(clk),
		.in(ws_post_opl_p0),
		.out(ws_post_opl_p)
	);
	always @(posedge clk) begin
		env_p4 <= env_p3;
		env_p5 <= env_p4;
	end
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
	calc_rhythm_phase calc_rhythm_phase(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.phase_acc_p3(phase_acc_p3),
		.op_type(op_type),
		.rhythm_phase_p3(rhythm_phase_p3)
	);
	always @(posedge clk) begin
		modulation_p2 <= modulation_p1;
		modulation_shifted_p3 <= modulation_p2 << 10;
	end
	always @(posedge clk)
		if (sample_clk_en_p[2]) begin
			if (key_on_pulse_p[2])
				phase_acc_p3 <= 0;
			else if ((ws_post_opl_p[6+:3] == 4) || (ws_post_opl_p[6+:3] == 5))
				phase_acc_p3 <= phase_acc_p2 + (phase_inc_p2 << 1);
			else
				phase_acc_p3 <= phase_acc_p2 + phase_inc_p2;
		end
	always @(posedge clk)
		if (sample_clk_en_p[3]) begin
			if (key_on_pulse_p[3])
				final_phase_p4 <= 0;
			else
				final_phase_p4 <= rhythm_phase_p3 + modulation_shifted_p3;
		end
	mem_multi_bank #(
		.DATA_WIDTH(1),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(2),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) final_phase_msb_mem(
		.clk(clk),
		.wea(sample_clk_en_p[4]),
		.reb(sample_clk_en),
		.banka(bank_num_p[4+:1]),
		.addra(op_num_p[20+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(final_phase_p4[19]),
		.dob(prev_final_phase_msb_p2)
	);
	mem_multi_bank #(
		.DATA_WIDTH(1),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(2),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) is_odd_period_msb_mem(
		.clk(clk),
		.wea(sample_clk_en_p[5]),
		.reb(sample_clk_en),
		.banka(bank_num_p[5+:1]),
		.addra(op_num_p[25+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(is_odd_period_p5),
		.dob(is_odd_period_p2)
	);
	always @(posedge clk) begin
		prev_final_phase_msb_p3 <= prev_final_phase_msb_p2;
		prev_final_phase_msb_p4 <= prev_final_phase_msb_p3;
		is_odd_period_p3 <= is_odd_period_p2;
		is_odd_period_p4 <= is_odd_period_p3;
		is_odd_period_p5 <= (prev_final_phase_msb_p4 && !final_phase_p4[19] ? !is_odd_period_p4 : is_odd_period_p4);
		is_odd_period_p6 <= is_odd_period_p5;
	end
	opl3_log_sine_lut log_sine_lut_inst(
		.theta((final_phase_p4[18] ? ~final_phase_p4[17:10] : final_phase_p4[17:10])),
		.out(log_sin_out_p5),
		.clk(clk)
	);
	always @(posedge clk) begin
		(* full_case, parallel_case *)
		case (final_phase_p4[19:18])
			0: tmp_ws7_p5[11] <= 0;
			1: tmp_ws7_p5[11] <= 1;
			2: tmp_ws7_p5[11] <= 1;
			3: tmp_ws7_p5[11] <= 0;
		endcase
		tmp_ws7_p5[10:0] <= (final_phase_p4[19] ? ~final_phase_p4[17:10] << 3 : final_phase_p4[17:10] << 3);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (ws_post_opl_p[15+:3])
			6: log_sin_plus_gain_p5 = env_p5 << 3;
			7: log_sin_plus_gain_p5 = tmp_ws7_p5 + (env_p5 << 3);
			default: log_sin_plus_gain_p5 = log_sin_out_p5 + (env_p5 << 3);
		endcase
	end
	always @(posedge clk) begin
		final_phase_p5 <= final_phase_p4;
		log_sin_plus_gain_p6 <= log_sin_plus_gain_p5;
	end
	opl3_exp_lut exp_lut_inst(
		.in(~log_sin_plus_gain_p5[7:0]),
		.out(exp_out_p6),
		.clk(clk)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		tmp_out0_p6 = (1024 + exp_out_p6) << 1;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		if (final_phase_p5[19])
			tmp_out1_p6 = ~(tmp_out0_p6 >> log_sin_plus_gain_p6[12:8]);
		else
			tmp_out1_p6 = tmp_out0_p6 >> log_sin_plus_gain_p6[12:8];
	end
	always @(*) begin
		if (_sv2v_0)
			;
		tmp_ws2_p6 = (tmp_out1_p6 < 0 ? ~tmp_out1_p6 : tmp_out1_p6);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		tmp_ws4_p6 = (is_odd_period_p6 ? tmp_out1_p6 : 0);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (ws_post_opl_p[18+:3])
			0: tmp_out2_p6 = tmp_out1_p6;
			1: tmp_out2_p6 = (tmp_out1_p6 < 0 ? 0 : tmp_out1_p6);
			2: tmp_out2_p6 = tmp_ws2_p6;
			3: tmp_out2_p6 = (final_phase_p5[18] ? 0 : tmp_ws2_p6);
			4: tmp_out2_p6 = tmp_ws4_p6;
			5: tmp_out2_p6 = (tmp_ws4_p6 < 0 ? ~tmp_ws4_p6 : tmp_ws4_p6);
			6: tmp_out2_p6 = tmp_out1_p6;
			7: tmp_out2_p6 = tmp_out1_p6;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (op_type_p[18+:3])
			3'd0: out_p6 = tmp_out2_p6;
			3'd1: out_p6 = tmp_out2_p6;
			default: out_p6 = tmp_out2_p6 << 1;
		endcase
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
