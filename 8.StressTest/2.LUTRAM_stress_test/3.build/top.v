module top (
	clk,
	addr,
	we,
	wdat,
	rdat
);
	reg _sv2v_0;
	parameter LUTRAM16X10 = 10;
	input wire clk;
	input wire [$clog2(LUTRAM16X10 * 16) - 1:0] addr;
	input wire we;
	input wire [9:0] wdat;
	output reg [9:0] rdat;
	localparam ADDR_BITS = $clog2(LUTRAM16X10 * 16) - 1;
	wire [9:0] read_all [0:LUTRAM16X10 - 1];
	reg [LUTRAM16X10 - 1:0] we_dec;
	always @(*) begin : _decode
		if (_sv2v_0)
			;
		we_dec = 1'sb0;
		if (LUTRAM16X10 > 1) begin
			we_dec[addr[ADDR_BITS:4]] = 1'b1 & we;
			rdat = read_all[addr[ADDR_BITS:4]];
		end
		else begin
			we_dec = we;
			rdat = read_all[0];
		end
	end
	genvar _gv_i_1;
	generate
		for (_gv_i_1 = 0; _gv_i_1 < LUTRAM16X10; _gv_i_1 = _gv_i_1 + 1) begin : genblk1
			localparam i = _gv_i_1;
			lutram_16x10 u_lut(
				.clk(clk),
				.addr(addr[3:0]),
				.rdat(read_all[i]),
				.wdat(wdat),
				.we(we_dec[i])
			);
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
