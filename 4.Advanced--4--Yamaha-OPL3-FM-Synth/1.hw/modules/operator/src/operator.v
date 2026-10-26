`default_nettype none
module operator (
	clk,
	reset,
	sample_clk_en,
	is_new,
	bank_num,
	op_num,
	fnum,
	mult,
	block,
	ws,
	vib,
	dvb,
	kon,
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
	bd,
	sd,
	tom,
	tc,
	hh,
	use_feedback_p1,
	fb_p1,
	modulation_p1,
	op_type,
	out_p6
);
	reg _sv2v_0;
	input wire clk;
	input wire reset;
	input wire sample_clk_en;
	input wire is_new;
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
	localparam opl3_pkg_REG_WS_WIDTH = 3;
	input wire [2:0] ws;
	input wire vib;
	input wire dvb;
	input wire kon;
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
	input wire bd;
	input wire sd;
	input wire tom;
	input wire tc;
	input wire hh;
	input wire use_feedback_p1;
	localparam opl3_pkg_REG_FB_WIDTH = 3;
	input wire [2:0] fb_p1;
	localparam opl3_pkg_OP_OUT_WIDTH = 13;
	input wire signed [12:0] modulation_p1;
	input wire [2:0] op_type;
	output wire signed [12:0] out_p6;
	localparam PIPELINE_DELAY = 6;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [6:1] bank_num_p;
	wire [34:5] op_num_p;
	localparam opl3_pkg_PHASE_ACC_WIDTH = 20;
	wire [19:0] phase_inc_p2;
	reg key_on_pulse_p0;
	reg key_off_pulse_p0;
	localparam opl3_pkg_ENV_WIDTH = 9;
	wire [8:0] env_p3;
	reg signed [12:0] feedback_result_p1;
	reg signed [21:0] feedback_result_tmp_p1;
	wire bd_on_pulse;
	wire sd_on_pulse;
	wire tom_on_pulse;
	wire tc_on_pulse;
	wire hh_on_pulse;
	reg rhythm_kon_pulse;
	wire prev_kon_p0;
	reg kon_p1;
	wire [25:0] feedback_p1;
	reg [25:0] feedback_p6;
	wire [181:52] feedback_p;
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
	always @(posedge clk) kon_p1 <= kon;
	mem_multi_bank #(
		.DATA_WIDTH(1),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) kon_mem(
		.clk(clk),
		.wea(sample_clk_en_p[1]),
		.reb(sample_clk_en),
		.banka(bank_num_p[1+:1]),
		.addra(op_num_p[5+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(kon_p1),
		.dob(prev_kon_p0)
	);
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) bd_edge_detect(
		.clk_en((op_type == 3'd1) && sample_clk_en),
		.in(bd),
		.edge_detected(bd_on_pulse),
		.clk(clk)
	);
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) sd_edge_detect(
		.clk_en((op_type == 3'd4) && sample_clk_en),
		.in(sd),
		.edge_detected(sd_on_pulse),
		.clk(clk)
	);
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) tom_edge_detect(
		.clk_en((op_type == 3'd3) && sample_clk_en),
		.in(tom),
		.edge_detected(tom_on_pulse),
		.clk(clk)
	);
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) tc_edge_detect(
		.clk_en((op_type == 3'd5) && sample_clk_en),
		.in(tc),
		.edge_detected(tc_on_pulse),
		.clk(clk)
	);
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) hh_edge_detect(
		.clk_en((op_type == 3'd2) && sample_clk_en),
		.in(hh),
		.edge_detected(hh_on_pulse),
		.clk(clk)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		rhythm_kon_pulse = (((((op_type == 3'd1) && bd_on_pulse) || ((op_type == 3'd4) && sd_on_pulse)) || ((op_type == 3'd3) && tom_on_pulse)) || ((op_type == 3'd5) && tc_on_pulse)) || ((op_type == 3'd2) && hh_on_pulse);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		key_on_pulse_p0 = ((!prev_kon_p0 && kon) || rhythm_kon_pulse) && sample_clk_en;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		key_off_pulse_p0 = (prev_kon_p0 && !kon) && sample_clk_en;
	end
	calc_phase_inc calc_phase_inc(
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.fnum(fnum),
		.mult(mult),
		.block(block),
		.vib(vib),
		.dvb(dvb),
		.phase_inc_p2(phase_inc_p2)
	);
	envelope_generator envelope_generator(
		.egt(egt && (op_type == 3'd0)),
		.clk(clk),
		.reset(reset),
		.sample_clk_en(sample_clk_en),
		.bank_num(bank_num),
		.op_num(op_num),
		.ar(ar),
		.dr(dr),
		.sl(sl),
		.rr(rr),
		.tl(tl),
		.ksr(ksr),
		.ksl(ksl),
		.am(am),
		.dam(dam),
		.nts(nts),
		.fnum(fnum),
		.mult(mult),
		.block(block),
		.key_on_pulse_p0(key_on_pulse_p0),
		.key_off_pulse_p0(key_off_pulse_p0),
		.env_p3(env_p3)
	);
	phase_generator phase_generator(
		.modulation_p1((use_feedback_p1 ? feedback_result_p1 : modulation_p1)),
		.clk(clk),
		.sample_clk_en(sample_clk_en),
		.is_new(is_new),
		.bank_num(bank_num),
		.op_num(op_num),
		.phase_inc_p2(phase_inc_p2),
		.ws(ws),
		.env_p3(env_p3),
		.key_on_pulse_p0(key_on_pulse_p0),
		.op_type(op_type),
		.out_p6(out_p6)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		feedback_p6[0+:13] = out_p6;
		feedback_p6[13+:13] = feedback_p[156+:13];
	end
	mem_multi_bank #(
		.DATA_WIDTH(26),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(1),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) feedback_mem(
		.clk(clk),
		.wea(sample_clk_en_p[6]),
		.reb(sample_clk_en),
		.banka(bank_num_p[6+:1]),
		.addra(op_num_p[30+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(feedback_p6),
		.dob(feedback_p1)
	);
	pipeline_sr #(
		.DATA_WIDTH(26),
		.STARTING_CYCLE(2),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) feedback_sr(
		.clk(clk),
		.in(feedback_p1),
		.out(feedback_p)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		feedback_result_tmp_p1 = (fb_p1 == 0 ? 0 : ($signed(feedback_p1[0+:13]) + $signed(feedback_p1[13+:13])) <<< fb_p1);
		feedback_result_p1 = feedback_result_tmp_p1 >>> 9;
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
