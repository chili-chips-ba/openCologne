`default_nettype none
module env_rate_counter (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	ksr,
	nts,
	fnum,
	block,
	requested_rate_p0,
	key_on_pulse_p0,
	rate_counter_overflow_p1
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
	input wire key_on_pulse_p0;
	localparam opl3_pkg_ENV_RATE_COUNTER_OVERFLOW_WIDTH = 3;
	output reg [2:0] rate_counter_overflow_p1 = 0;
	localparam COUNTER_WIDTH = 15;
	localparam OVERFLOW_TMP_MAX_VALUE = 229376;
	localparam PIPELINE_DELAY = 2;
	reg rate_tmp0_p0;
	reg [3:0] rate_tmp1_p0;
	reg [3:0] rate_tmp2_p0;
	reg [5:0] effective_rate_p1 = 0;
	reg [3:0] rate_value_p1;
	reg [5:0] requested_rate_shifted_p0;
	reg [1:0] rof_p1;
	wire [14:0] counter_fifo_out_p1;
	reg [14:0] counter_p1;
	reg [14:0] counter_new_p2;
	reg [17:0] overflow_tmp_p1;
	wire [PIPELINE_DELAY:1] requested_rate_not_zero_p;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [2:1] bank_num_p;
	wire [14:5] op_num_p;
	reg key_on_pulse_p1 = 0;
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
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) requested_rate_not_zero_sr(
		.clk(clk),
		.in(requested_rate_p0 != 0),
		.out(requested_rate_not_zero_p)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		rate_tmp0_p0 = (nts ? fnum[8] : fnum[9]);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rate_tmp1_p0 = rate_tmp0_p0 | (block << 1);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rate_tmp2_p0 = (ksr ? rate_tmp1_p0 : rate_tmp1_p0 >> 2);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		requested_rate_shifted_p0 = requested_rate_p0 << 2;
	end
	always @(posedge clk)
		if ((rate_tmp2_p0 + requested_rate_shifted_p0) > 60)
			effective_rate_p1 <= 60;
		else
			effective_rate_p1 <= rate_tmp2_p0 + requested_rate_shifted_p0;
	always @(*) begin
		if (_sv2v_0)
			;
		rate_value_p1 = effective_rate_p1 >> 2;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rof_p1 = effective_rate_p1[1:0];
	end
	mem_multi_bank #(
		.DATA_WIDTH(COUNTER_WIDTH),
		.DEPTH(opl3_pkg_NUM_OPERATORS_PER_BANK),
		.OUTPUT_DELAY(1),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) counter_mem(
		.clk(clk),
		.wea(sample_clk_en_p[2] && requested_rate_not_zero_p[2]),
		.reb(sample_clk_en),
		.banka(bank_num_p[2+:1]),
		.addra(op_num_p[10+:5]),
		.bankb(bank_num),
		.addrb(op_num),
		.dia(counter_new_p2),
		.dob(counter_fifo_out_p1)
	);
	always @(posedge clk) key_on_pulse_p1 <= key_on_pulse_p0;
	always @(*) begin
		if (_sv2v_0)
			;
		counter_p1 = (key_on_pulse_p1 ? 0 : counter_fifo_out_p1);
		overflow_tmp_p1 = counter_p1 + ((4 | rof_p1) << rate_value_p1);
		rate_counter_overflow_p1 = overflow_tmp_p1 >> 15;
	end
	always @(posedge clk) counter_new_p2 <= overflow_tmp_p1;
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
