`default_nettype none
module calc_rhythm_phase (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	phase_p2,
	op_type_p0,
	rhythm_phase_p3
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
	localparam opl3_pkg_PHASE_FINAL_WIDTH = 10;
	input wire [9:0] phase_p2;
	input wire [2:0] op_type_p0;
	output reg [9:0] rhythm_phase_p3 = 0;
	localparam PIPELINE_DELAY = 3;
	localparam RAND_POLYNOMIAL = 'h800302;
	localparam RAND_NUM_WIDTH = $clog2('h800302);
	reg [9:0] hh_phase_friend = 0;
	reg [9:0] tc_phase_friend = 0;
	reg [9:0] hh_phase_p2;
	reg [9:0] tc_phase_p2;
	reg rm_xor_p2;
	reg [RAND_NUM_WIDTH - 1:0] rand_num = 1;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [11:3] op_type_p;
	wire [3:1] bank_num_p;
	wire [19:5] op_num_p;
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) sample_clk_en_sr(
		.clk(clk),
		.in(sample_clk_en),
		.out(sample_clk_en_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(3),
		.ENDING_CYCLE(PIPELINE_DELAY),
		.POR_VALUE(3'd0)
	) op_type_sr(
		.clk(clk),
		.in(op_type_p0),
		.out(op_type_p)
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
	always @(posedge clk) begin
		if ((sample_clk_en_p[2] && (bank_num_p[2+:1] == 0)) && (op_num_p[10+:5] == 13))
			hh_phase_friend <= phase_p2;
		if ((sample_clk_en_p[2] && (bank_num_p[2+:1] == 0)) && (op_num_p[10+:5] == 17))
			tc_phase_friend <= phase_p2;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		hh_phase_p2 = (op_type_p[6+:3] == 3'd2 ? phase_p2 : hh_phase_friend);
		tc_phase_p2 = (op_type_p[6+:3] == 3'd5 ? phase_p2 : tc_phase_friend);
		rm_xor_p2 = ((hh_phase_p2[2] ^ hh_phase_p2[7]) || (hh_phase_p2[3] ^ tc_phase_p2[5])) || (tc_phase_p2[3] ^ tc_phase_p2[5]);
	end
	always @(posedge clk)
		(* full_case, parallel_case *)
		case (op_type_p[6+:3])
			3'd2: rhythm_phase_p3 <= (rm_xor_p2 << 9) | (rm_xor_p2 ^ rand_num[0] ? 'hd0 : 'h34);
			3'd4: rhythm_phase_p3 <= (hh_phase_p2[8] << 9) | ((hh_phase_p2[8] ^ rand_num[0]) << 8);
			3'd5: rhythm_phase_p3 <= (rm_xor_p2 << 9) | 'h80;
			default: rhythm_phase_p3 <= phase_p2;
		endcase
	always @(posedge clk)
		if ((sample_clk_en && (bank_num == 0)) && (op_num == 0)) begin
			if (rand_num & 1)
				rand_num <= (rand_num ^ RAND_POLYNOMIAL) >> 1;
			else
				rand_num <= rand_num >> 1;
		end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
