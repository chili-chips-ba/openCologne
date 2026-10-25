`default_nettype none
module ksl_add_rom (
	clk,
	fnum,
	block,
	ksl,
	ksl_add_p2
);
	reg _sv2v_0;
	input wire clk;
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	input wire [9:0] fnum;
	localparam opl3_pkg_REG_BLOCK_WIDTH = 3;
	input wire [2:0] block;
	localparam opl3_pkg_REG_KSL_WIDTH = 2;
	input wire [1:0] ksl;
	localparam opl3_pkg_KSL_ADD_WIDTH = 8;
	output reg [7:0] ksl_add_p2 = 0;
	reg [6:0] rom_out_p1 = 0;
	reg [5:0] tmp0_p1 = 0;
	reg signed [7:0] tmp1_p1;
	reg [3:0] fnum_shifted_p0;
	reg [1:0] ksl_p1 = 0;
	always @(*) begin
		if (_sv2v_0)
			;
		fnum_shifted_p0 = fnum >> 6;
	end
	always @(posedge clk)
		(* full_case, parallel_case *)
		case (fnum_shifted_p0)
			0: rom_out_p1 <= 0;
			1: rom_out_p1 <= 32;
			2: rom_out_p1 <= 40;
			3: rom_out_p1 <= 45;
			4: rom_out_p1 <= 48;
			5: rom_out_p1 <= 51;
			6: rom_out_p1 <= 53;
			7: rom_out_p1 <= 55;
			8: rom_out_p1 <= 56;
			9: rom_out_p1 <= 58;
			10: rom_out_p1 <= 59;
			11: rom_out_p1 <= 60;
			12: rom_out_p1 <= 61;
			13: rom_out_p1 <= 62;
			14: rom_out_p1 <= 63;
			15: rom_out_p1 <= 64;
		endcase
	always @(posedge clk) tmp0_p1 <= block - 8;
	always @(*) begin
		if (_sv2v_0)
			;
		tmp1_p1 = $signed(rom_out_p1 + (tmp0_p1 << 3));
	end
	always @(posedge clk) begin
		ksl_p1 <= ksl;
		(* full_case, parallel_case *)
		case (ksl_p1)
			0: ksl_add_p2 <= 0;
			1: ksl_add_p2 <= (tmp1_p1 <= 0 ? 0 : tmp1_p1 << 1);
			2: ksl_add_p2 <= (tmp1_p1 <= 0 ? 0 : tmp1_p1);
			3: ksl_add_p2 <= (tmp1_p1 <= 0 ? 0 : tmp1_p1 << 2);
		endcase
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
