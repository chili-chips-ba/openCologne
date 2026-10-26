`default_nettype none
module calc_rhythm_phase (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	phase_acc_p3,
	op_type,
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
	localparam opl3_pkg_PHASE_ACC_WIDTH = 20;
	input wire [19:0] phase_acc_p3;
	input wire [2:0] op_type;
	output reg [19:0] rhythm_phase_p3;
	localparam PIPELINE_DELAY = 3;
	localparam RAND_POLYNOMIAL = 'h800302;
	localparam RAND_NUM_WIDTH = $clog2('h800302);
	reg [19:0] hh_phase_friend = 0;
	reg [19:0] hh_phase_p3;
	reg [19:0] phase_bit_p3;
	reg [19:0] noise_bit_p3;
	reg [RAND_NUM_WIDTH - 1:0] rand_num = 1;
	wire [PIPELINE_DELAY:1] sample_clk_en_p;
	wire [11:3] op_type_p;
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
		.in(op_type),
		.out(op_type_p)
	);
	always @(posedge clk)
		if ((sample_clk_en_p[3] && (bank_num == 0)) && (op_num == 13))
			hh_phase_friend <= phase_acc_p3;
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (op_type_p[9+:3])
			3'd4: hh_phase_p3 = (hh_phase_friend & 'h100 ? 'h200 : 'h100);
			3'd5: hh_phase_p3 = hh_phase_friend;
			default: hh_phase_p3 = phase_acc_p3;
		endcase
		phase_bit_p3 = (((hh_phase_p3 & 'h88) ^ ((hh_phase_p3 << 5) & 'h80)) | ((hh_phase_p3 ^ (hh_phase_p3 << 2)) & 'h20) ? 'h2 : 'h0);
		noise_bit_p3 = (op_type_p[9+:3] == 3'd2 ? rand_num[0] << 1 : rand_num[0] << 8);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (op_type_p[9+:3])
			3'd0: rhythm_phase_p3 = phase_acc_p3;
			3'd1: rhythm_phase_p3 = phase_acc_p3;
			3'd2: rhythm_phase_p3 = (phase_bit_p3 << 8) | ('h34 << (phase_bit_p3 ^ noise_bit_p3));
			3'd3: rhythm_phase_p3 = phase_acc_p3;
			3'd4: rhythm_phase_p3 = hh_phase_p3 ^ noise_bit_p3;
			3'd5: rhythm_phase_p3 = (1 + phase_bit_p3) << 8;
		endcase
	end
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
