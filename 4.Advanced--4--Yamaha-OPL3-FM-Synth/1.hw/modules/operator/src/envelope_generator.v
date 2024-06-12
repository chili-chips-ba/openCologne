`default_nettype none
module envelope_generator (
	clk,
	reset,
	sample_clk_en,
	bank_num,
	op_num,
	ar,
	dr,
	sl,
	rr,
	tl,
	ksr,
	ksl,
	egt,
	am,
	dam,
	nts,
	fnum,
	mult,
	block,
	key_on_pulse_p0,
	key_off_pulse_p0,
	env_p3
);
	reg _sv2v_0;
	parameter SILENCE = 511;
	input wire clk;
	input wire reset;
	input wire sample_clk_en;
	localparam opl3_pkg_NUM_BANKS = 2;
	localparam opl3_pkg_BANK_NUM_WIDTH = 1;
	input wire [0:0] bank_num;
	localparam opl3_pkg_NUM_OPERATORS_PER_BANK = 18;
	localparam opl3_pkg_OP_NUM_WIDTH = 5;
	input wire [4:0] op_num;
	localparam opl3_pkg_REG_ENV_WIDTH = 4;
	input wire [3:0] ar;
	input wire [3:0] dr;
	input wire [3:0] sl;
	input wire [3:0] rr;
	localparam opl3_pkg_REG_TL_WIDTH = 6;
	input wire [5:0] tl;
	input wire ksr;
	localparam opl3_pkg_REG_KSL_WIDTH = 2;
	input wire [1:0] ksl;
	input wire egt;
	input wire am;
	input wire dam;
	input wire nts;
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	input wire [9:0] fnum;
	localparam opl3_pkg_REG_MULT_WIDTH = 4;
	input wire [3:0] mult;
	localparam opl3_pkg_REG_BLOCK_WIDTH = 3;
	input wire [2:0] block;
	input wire key_on_pulse_p0;
	input wire key_off_pulse_p0;
	localparam opl3_pkg_ENV_WIDTH = 9;
	output reg [8:0] env_p3 = SILENCE;
	localparam PIPELINE_DELAY = 3;
	wire [3:0] state_p0;
	reg [3:0] next_state_p0;
	reg [3:0] state_p1 = 4'b1000;
	localparam opl3_pkg_KSL_ADD_WIDTH = 8;
	wire [7:0] ksl_add_p2;
	wire [8:0] env_int_p0;
	reg [8:0] env_int_p1 = 0;
	reg [8:0] env_int_p2 = 0;
	reg [opl3_pkg_ENV_WIDTH:0] env_add_p1;
	localparam opl3_pkg_TREMOLO_MAX_COUNT = 13312;
	localparam opl3_pkg_TREMOLO_INDEX_WIDTH = 14;
	localparam opl3_pkg_AM_VAL_WIDTH = 6;
	wire [5:0] am_val_p2;
	reg [3:0] requested_rate_p0;
	localparam opl3_pkg_ENV_RATE_COUNTER_OVERFLOW_WIDTH = 3;
	wire [2:0] rate_counter_overflow_p1;
	reg [10:0] env_tmp_p2;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [3:1] bank_num_p;
	wire [19:5] op_num_p;
	wire [23:6] tl_p;
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
		.DATA_WIDTH(opl3_pkg_REG_TL_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) tl_sr(
		.clk(clk),
		.in(tl),
		.out(tl_p)
	);
	ksl_add_rom ksl_add_rom(
		.clk(clk),
		.fnum(fnum),
		.block(block),
		.ksl(ksl),
		.ksl_add_p2(ksl_add_p2)
	);
	localparam [0:0] sv2v_uu_state_mem_ext_reset_0 = 1'sb0;
	mem_multi_bank_reset #(
		.DATA_WIDTH(4),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(4'b1000),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) state_mem(
		.clk(clk),
		.reset(sv2v_uu_state_mem_ext_reset_0),
		.reset_mem(reset),
		.wea(sample_clk_en_p[1]),
		.reb(sample_clk_en),
		.banka(bank_num_p[1+:1]),
		.addra(op_num_p[5+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia({state_p1}),
		.dob({state_p0}),
		.reset_mem_done_pulse()
	);
	always @(posedge clk)
		if (sample_clk_en)
			state_p1 <= next_state_p0;
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (state_p0)
			4'b0001: next_state_p0 = (env_int_p0 == 0 ? 4'b0010 : 4'b0001);
			4'b0010: next_state_p0 = ((env_int_p0 >> 4) >= sl ? 4'b0100 : 4'b0010);
			4'b0100: next_state_p0 = (!egt ? 4'b1000 : 4'b0100);
			4'b1000: next_state_p0 = 4'b1000;
		endcase
		if (key_on_pulse_p0)
			next_state_p0 = (env_int_p0 == 0 ? 4'b0010 : 4'b0001);
		else if (key_off_pulse_p0)
			next_state_p0 = 4'b1000;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (next_state_p0)
			4'b0001: requested_rate_p0 = ar;
			4'b0010: requested_rate_p0 = dr;
			4'b0100: requested_rate_p0 = 0;
			4'b1000: requested_rate_p0 = rr;
		endcase
	end
	env_rate_counter env_rate_counter(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.ksr(ksr),
		.nts(nts),
		.fnum(fnum),
		.block(block),
		.requested_rate_p0(requested_rate_p0),
		.key_on_pulse_p0(key_on_pulse_p0),
		.rate_counter_overflow_p1(rate_counter_overflow_p1)
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_ENV_WIDTH),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(SILENCE),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) env_int_mem(
		.clk(clk),
		.wea(sample_clk_en_p[2]),
		.reb(sample_clk_en),
		.banka(bank_num_p[2+:1]),
		.addra(op_num_p[10+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(env_int_p2),
		.dob(env_int_p0)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		env_add_p1 = env_int_p1 + rate_counter_overflow_p1;
	end
	always @(posedge clk) begin
		env_int_p1 <= env_int_p0;
		env_int_p2 <= env_int_p1;
		if (sample_clk_en_p[1]) begin
			if ((state_p1 == 4'b0001) && (rate_counter_overflow_p1 != 0))
				env_int_p2 <= env_int_p1 - (((env_int_p1 * rate_counter_overflow_p1) >> 3) + 1);
			else if ((state_p1 == 4'b0010) || (state_p1 == 4'b1000)) begin
				if (env_add_p1[opl3_pkg_ENV_WIDTH])
					env_int_p2 <= SILENCE;
				else
					env_int_p2 <= env_add_p1;
			end
		end
	end
	tremolo tremolo(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.dam(dam),
		.am_val_p2(am_val_p2)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		if (am)
			env_tmp_p2 = ((env_int_p2 + (tl_p[12+:6] << 2)) + ksl_add_p2) + am_val_p2;
		else
			env_tmp_p2 = (env_int_p2 + (tl_p[12+:6] << 2)) + ksl_add_p2;
	end
	always @(posedge clk)
		if (env_tmp_p2[10:opl3_pkg_ENV_WIDTH] != 0)
			env_p3 <= SILENCE;
		else
			env_p3 <= env_tmp_p2;
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
