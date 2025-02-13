module lutram_16x10 (
	clk,
	wdat,
	addr,
	we,
	rdat
);
	reg _sv2v_0;
	input wire clk;
	input wire [9:0] wdat;
	input wire [3:0] addr;
	input wire we;
	output reg [9:0] rdat;
	reg [9:0] dist_mem [0:15];
	always @(*) begin : _read_block
		if (_sv2v_0)
			;
		rdat = dist_mem[addr];
	end
	always @(posedge clk) begin : _write_block
		if (we == 1'b1)
			dist_mem[addr] <= wdat;
	end
	initial _sv2v_0 = 0;
endmodule
