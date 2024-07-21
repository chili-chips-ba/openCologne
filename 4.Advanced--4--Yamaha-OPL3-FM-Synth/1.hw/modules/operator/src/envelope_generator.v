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
	key_on_p0,
	env_p3,
	pg_reset_p2
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
	input wire key_on_p0;
	localparam opl3_pkg_FINAL_ENV_WIDTH = 11;
	output reg [10:0] env_p3 = SILENCE;
	output reg pg_reset_p2;
	localparam PIPELINE_DELAY = 3;
	localparam ENV_WIDTH = 9;
	wire [3:0] state_p0;
	reg [3:0] state_p1 = 4'b1000;
	reg [3:0] state_p2 = 4'b1000;
	reg [3:0] next_state_p2;
	reg [3:0] state_p3 = 4'b1000;
	localparam opl3_pkg_KSL_ADD_WIDTH = 8;
	wire [7:0] ksl_add_p2;
	wire [8:0] env_int_p0;
	reg [8:0] env_int_pre_p2;
	reg [8:0] eg_inc_p2;
	reg eg_off_p2;
	reg [11:0] env_int_extra_bits_p2;
	reg [8:0] env_int_new_p3 = 0;
	localparam opl3_pkg_TREMOLO_MAX_COUNT = 13312;
	localparam opl3_pkg_TREMOLO_INDEX_WIDTH = 14;
	localparam opl3_pkg_AM_VAL_WIDTH = 6;
	wire [5:0] am_val_p2;
	reg [3:0] requested_rate_p0;
	localparam opl3_pkg_ENV_SHIFT_WIDTH = 2;
	wire [1:0] env_shift_p2;
	wire [3:0] rate_hi_p2;
	reg eg_reset_p0;
	reg [7:0] tl_shifted_p2;
	reg [opl3_pkg_REG_ENV_WIDTH:0] sl_increased_p2;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [3:1] bank_num_p;
	wire [19:5] op_num_p;
	wire [23:6] tl_p;
	wire [15:4] sl_p;
	wire [35:9] env_int_p;
	wire [PIPELINE_DELAY:1] key_on_p;
	wire [PIPELINE_DELAY:1] eg_reset_p;
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
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_REG_ENV_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) sl_sr(
		.clk(clk),
		.in(sl),
		.out(sl_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(ENV_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) env_int_sr(
		.clk(clk),
		.in(env_int_p0),
		.out(env_int_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(1),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) key_on_sr(
		.clk(clk),
		.in(key_on_p0),
		.out(key_on_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(1),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) eg_reset_sr(
		.clk(clk),
		.in(eg_reset_p0),
		.out(eg_reset_p)
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
		.wea(sample_clk_en_p[3]),
		.reb(sample_clk_en),
		.banka(bank_num_p[3+:1]),
		.addra(op_num_p[15+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia({state_p3}),
		.dob({state_p0}),
		.reset_mem_done_pulse()
	);
	always @(*) begin
		if (_sv2v_0)
			;
		eg_reset_p0 = 0;
		requested_rate_p0 = 0;
		if (key_on_p0 && (state_p0 == 4'b1000)) begin
			eg_reset_p0 = 1;
			requested_rate_p0 = ar;
		end
		else
			(* full_case, parallel_case *)
			case (state_p0)
				4'b0001: requested_rate_p0 = ar;
				4'b0010: requested_rate_p0 = dr;
				4'b0100: requested_rate_p0 = (!egt ? rr : 0);
				4'b1000: requested_rate_p0 = rr;
			endcase
	end
	calc_envelope_shift calc_envelope_shift(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.ksr(ksr),
		.nts(nts),
		.fnum(fnum),
		.block(block),
		.requested_rate_p0(requested_rate_p0),
		.rate_hi_p2(rate_hi_p2),
		.env_shift_p2(env_shift_p2)
	);
	mem_multi_bank #(
		.DATA_WIDTH(ENV_WIDTH),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(SILENCE),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) env_int_mem(
		.clk(clk),
		.wea(sample_clk_en_p[3]),
		.reb(sample_clk_en),
		.banka(bank_num_p[3+:1]),
		.addra(op_num_p[15+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(env_int_new_p3),
		.dob(env_int_p0)
	);
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
		pg_reset_p2 = eg_reset_p[2];
		env_int_pre_p2 = env_int_p[18+:9];
		eg_inc_p2 = 0;
		eg_off_p2 = 0;
		next_state_p2 = state_p2;
		env_int_extra_bits_p2 = env_int_p[18+:9];
		sl_increased_p2 = (sl_p[8+:4] == 'hf ? 'h1f : sl_p[8+:4]);
		if (eg_reset_p[2] && (rate_hi_p2 == 'hf))
			env_int_pre_p2 = 0;
		if ((env_int_p[18+:9] & 'h1f8) == 'h1f8)
			eg_off_p2 = 1;
		if (((state_p2 != 4'b0001) && !eg_reset_p[2]) && eg_off_p2)
			env_int_pre_p2 = SILENCE;
		(* full_case, parallel_case *)
		case (state_p2)
			4'b0001:
				if (env_int_p[18+:9] == 0)
					next_state_p2 = 4'b0010;
				else if ((key_on_p[2] && (env_shift_p2 > 0)) && (rate_hi_p2 != 'hf))
					eg_inc_p2 = ~env_int_extra_bits_p2 >> (4 - env_shift_p2);
			4'b0010:
				if ((env_int_p[18+:9] >> 4) == sl_increased_p2)
					next_state_p2 = 4'b0100;
				else if ((!eg_off_p2 && !eg_reset_p[2]) && (env_shift_p2 > 0))
					eg_inc_p2 = 1 << (env_shift_p2 - 1);
			4'b0100, 4'b1000:
				if ((!eg_off_p2 && !eg_reset_p[2]) && (env_shift_p2 > 0))
					eg_inc_p2 = 1 << (env_shift_p2 - 1);
		endcase
		if (eg_reset_p[2])
			next_state_p2 = 4'b0001;
		if (!key_on_p[2])
			next_state_p2 = 4'b1000;
	end
	always @(posedge clk) begin
		state_p1 <= state_p0;
		state_p2 <= state_p1;
		state_p3 <= next_state_p2;
		env_int_new_p3 <= env_int_pre_p2 + eg_inc_p2;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		tl_shifted_p2 = tl_p[12+:6] << 2;
	end
	always @(posedge clk) env_p3 <= ((env_int_p[18+:9] + tl_shifted_p2) + ksl_add_p2) + (am ? am_val_p2 : 0);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
