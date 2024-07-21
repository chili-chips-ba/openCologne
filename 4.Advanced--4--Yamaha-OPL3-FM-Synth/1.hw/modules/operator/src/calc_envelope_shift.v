`default_nettype none
module calc_envelope_shift (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	ksr,
	nts,
	fnum,
	block,
	requested_rate_p0,
	rate_hi_p2,
	env_shift_p2
);
	reg _sv2v_0;
	input wire clk;
	input wire sample_clk_en;
	localparam opl3_pkg_NUM_BANKS = 2;
	localparam opl3_pkg_BANK_NUM_WIDTH = 1;
	input wire [0:0] bank_num;
	localparam opl3_pkg_NUM_OPERATORS_PER_BANK = 18;
	localparam opl3_pkg_OP_NUM_WIDTH = 5;
	input wire [4:0] op_num;
	input wire ksr;
	input wire nts;
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	input wire [9:0] fnum;
	localparam opl3_pkg_REG_BLOCK_WIDTH = 3;
	input wire [2:0] block;
	localparam opl3_pkg_REG_ENV_WIDTH = 4;
	input wire [3:0] requested_rate_p0;
	output reg [3:0] rate_hi_p2 = 0;
	localparam opl3_pkg_ENV_SHIFT_WIDTH = 2;
	output reg [1:0] env_shift_p2 = 0;
	localparam EG_TIMER_WIDTH = 13;
	localparam PIPELINE_DELAY = 3;
	localparam EG_ADD_WIDTH = 4;
	localparam [15:0] EG_INC_STEP = 16'b0000100010101110;
	reg [12:0] eg_timer = 0;
	reg eg_state = 0;
	reg [3:0] eg_add = 0;
	reg [opl3_pkg_REG_BLOCK_WIDTH:0] block_shifted;
	reg [opl3_pkg_REG_BLOCK_WIDTH:0] ksv_p0;
	reg [opl3_pkg_REG_BLOCK_WIDTH:0] ks_p0;
	reg [5:0] requested_rate_shifted_p0;
	reg [6:0] rate_p1 = 0;
	reg [4:0] rate_hi_pre_p1;
	reg [3:0] rate_hi_p1;
	reg [1:0] rate_lo_p1;
	reg [1:0] eg_timer_lo = 0;
	reg [5:0] eg_shift_p1;
	reg requested_rate_not_zero_p1;
	reg [opl3_pkg_ENV_SHIFT_WIDTH:0] env_shift_pre_p1;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [3:1] bank_num_p;
	wire [19:5] op_num_p;
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
	always @(*) begin
		if (_sv2v_0)
			;
		block_shifted = block << 1;
		ksv_p0 = block_shifted | (nts ? fnum[8] : fnum[9]);
		ks_p0 = (ksr ? ksv_p0 : ksv_p0 >> 2);
		requested_rate_shifted_p0 = requested_rate_p0 << 2;
	end
	always @(posedge clk) rate_p1 <= ks_p0 + requested_rate_shifted_p0;
	always @(*) begin
		if (_sv2v_0)
			;
		rate_hi_pre_p1 = rate_p1 >> 2;
		rate_hi_p1 = (rate_hi_pre_p1[4] ? 'hf : rate_hi_pre_p1);
		rate_lo_p1 = rate_p1[1:0];
		eg_shift_p1 = rate_hi_p1 + eg_add;
		env_shift_pre_p1 = rate_hi_p1[1:0] + EG_INC_STEP[(rate_lo_p1 * 4) + eg_timer_lo];
	end
	always @(posedge clk) begin
		requested_rate_not_zero_p1 <= requested_rate_p0 != 0;
		env_shift_p2 <= 0;
		rate_hi_p2 <= rate_hi_p1;
		if (requested_rate_not_zero_p1) begin
			if (rate_hi_p1 < 12) begin
				if (eg_state)
					(* full_case, parallel_case *)
					case (eg_shift_p1)
						12: env_shift_p2 <= 1;
						13: env_shift_p2 <= rate_lo_p1[1];
						14: env_shift_p2 <= rate_lo_p1[0];
						default:
							;
					endcase
			end
			else begin
				env_shift_p2 <= env_shift_pre_p1;
				if (env_shift_pre_p1[2])
					env_shift_p2 <= 'h3;
				if (env_shift_pre_p1 == 0)
					env_shift_p2 <= eg_state;
			end
		end
	end
	always @(posedge clk)
		if ((sample_clk_en_p[3] && (bank_num_p[3+:1] == 1)) && (op_num_p[15+:5] == 17)) begin
			if (eg_state) begin
				(* full_case, parallel_case *)
				casez (eg_timer)
					'b0: eg_add <= 0;
					'b1000000000000: eg_add <= 13;
					'bz100000000000: eg_add <= 12;
					'bz10000000000: eg_add <= 11;
					'bz1000000000: eg_add <= 10;
					'bz100000000: eg_add <= 9;
					'bz10000000: eg_add <= 8;
					'bz1000000: eg_add <= 7;
					'bz100000: eg_add <= 6;
					'bz10000: eg_add <= 5;
					'bz1000: eg_add <= 4;
					'bz100: eg_add <= 3;
					'bz10: eg_add <= 2;
					'bz1: eg_add <= 1;
				endcase
				eg_timer <= eg_timer + 1;
				eg_timer_lo <= eg_timer[1:0];
			end
			eg_state <= !eg_state;
		end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
