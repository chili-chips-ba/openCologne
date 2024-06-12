`default_nettype none
module tremolo (
	clk,
	sample_clk_en,
	bank_num,
	op_num,
	dam,
	am_val_p2
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
	input wire dam;
	localparam opl3_pkg_TREMOLO_MAX_COUNT = 13312;
	localparam opl3_pkg_TREMOLO_INDEX_WIDTH = 14;
	localparam opl3_pkg_AM_VAL_WIDTH = 6;
	output reg [5:0] am_val_p2 = 0;
	localparam PIPELINE_DELAY = 2;
	reg [13:0] tremolo_index_p1 = 1'sb0;
	reg [5:0] am_val_tmp0_p1;
	reg [5:0] am_val_tmp1_p1;
	reg dam_p1 = 0;
	always @(posedge clk)
		if ((sample_clk_en && (bank_num == 0)) && (op_num == 0)) begin
			if (tremolo_index_p1 == 13311)
				tremolo_index_p1 <= 0;
			else
				tremolo_index_p1 <= tremolo_index_p1 + 1;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		am_val_tmp0_p1 = tremolo_index_p1 >> 8;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		if (am_val_tmp0_p1 > 26)
			am_val_tmp1_p1 = 52 + ~am_val_tmp0_p1;
		else
			am_val_tmp1_p1 = am_val_tmp0_p1;
	end
	always @(posedge clk) begin
		dam_p1 <= dam;
		if (dam_p1)
			am_val_p2 <= am_val_tmp1_p1;
		else
			am_val_p2 <= am_val_tmp1_p1 >> 2;
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
