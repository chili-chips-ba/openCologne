`default_nettype none
module vibrato (
	clk,
	sample_clk_en,
	fnum,
	dvb,
	vib_val_p2
);
	reg _sv2v_0;
	input wire clk;
	input wire sample_clk_en;
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	input wire [9:0] fnum;
	input wire dvb;
	localparam opl3_pkg_VIB_VAL_WIDTH = 3;
	output reg [2:0] vib_val_p2 = 0;
	localparam VIBRATO_INDEX_WIDTH = 13;
	reg [12:0] vibrato_index_p1 = 0;
	reg [2:0] delta0_p1;
	reg [2:0] delta1_p1;
	reg [2:0] delta2_p1;
	reg [9:0] fnum_p1 = 0;
	reg dvb_p1 = 0;
	always @(posedge clk) begin
		fnum_p1 <= fnum;
		dvb_p1 <= dvb;
	end
	always @(posedge clk)
		if (sample_clk_en)
			vibrato_index_p1 <= vibrato_index_p1 + 1;
	always @(*) begin
		if (_sv2v_0)
			;
		delta0_p1 = fnum_p1 >> 7;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		delta1_p1 = (((vibrato_index_p1 >> 10) & 3) == 3 ? delta0_p1 >> 1 : delta0_p1);
	end
	always @(*) begin
		if (_sv2v_0)
			;
		delta2_p1 = (!dvb_p1 ? delta1_p1 >> 1 : delta1_p1);
	end
	always @(posedge clk) vib_val_p2 <= (((vibrato_index_p1 >> 10) & 4) != 0 ? ~delta2_p1 : delta2_p1);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
