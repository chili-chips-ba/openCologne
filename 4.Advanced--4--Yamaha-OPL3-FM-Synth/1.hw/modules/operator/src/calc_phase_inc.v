`default_nettype none
module calc_phase_inc (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	fnum,
	mult,
	block,
	vib,
	dvb,
	phase_inc_p2
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
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	input wire [9:0] fnum;
	localparam opl3_pkg_REG_MULT_WIDTH = 4;
	input wire [3:0] mult;
	localparam opl3_pkg_REG_BLOCK_WIDTH = 3;
	input wire [2:0] block;
	input wire vib;
	input wire dvb;
	localparam opl3_pkg_PHASE_ACC_WIDTH = 20;
	output reg [19:0] phase_inc_p2 = 0;
	localparam PIPELINE_DELAY = 2;
	reg signed [19:0] pre_mult_p0;
	reg signed [19:0] pre_mult_p1 = 0;
	reg signed [19:0] post_mult_p2 = 0;
	localparam opl3_pkg_VIB_VAL_WIDTH = 3;
	wire [2:0] vib_val_p2;
	wire [PIPELINE_DELAY:1] vib_p;
	reg [4:0] multiplier_p1 = 0;
	always @(*) begin
		if (_sv2v_0)
			;
		pre_mult_p0 = fnum << block;
	end
	always @(posedge clk)
		(* full_case, parallel_case *)
		case (mult)
			'h0: multiplier_p1 <= 1;
			'h1: multiplier_p1 <= 2;
			'h2: multiplier_p1 <= 4;
			'h3: multiplier_p1 <= 6;
			'h4: multiplier_p1 <= 8;
			'h5: multiplier_p1 <= 10;
			'h6: multiplier_p1 <= 12;
			'h7: multiplier_p1 <= 14;
			'h8: multiplier_p1 <= 16;
			'h9: multiplier_p1 <= 18;
			'ha: multiplier_p1 <= 20;
			'hb: multiplier_p1 <= 20;
			'hc: multiplier_p1 <= 24;
			'hd: multiplier_p1 <= 24;
			'he: multiplier_p1 <= 30;
			'hf: multiplier_p1 <= 30;
		endcase
	always @(posedge clk) begin
		pre_mult_p1 <= pre_mult_p0;
		post_mult_p2 <= (pre_mult_p1 * multiplier_p1) >> 1;
	end
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) vib_sr(
		.clk(clk),
		.in(vib),
		.out(vib_p)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		if (vib_p[2])
			phase_inc_p2 = post_mult_p2 + vib_val_p2;
		else
			phase_inc_p2 = post_mult_p2;
	end
	vibrato vibrato(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.fnum(fnum),
		.dvb(dvb),
		.vib_val_p2(vib_val_p2)
	);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
