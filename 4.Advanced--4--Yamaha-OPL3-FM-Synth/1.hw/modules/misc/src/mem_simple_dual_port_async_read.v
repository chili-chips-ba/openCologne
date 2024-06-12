`default_nettype none
module mem_simple_dual_port_async_read (
	clka,
	wea,
	addra,
	addrb,
	dia,
	dob
);
	reg _sv2v_0;
	parameter DATA_WIDTH = 0;
	parameter DEPTH = 0;
	parameter [DATA_WIDTH - 1:0] DEFAULT_VALUE = 0;
	input wire clka;
	input wire wea;
	input wire [$clog2(DEPTH) - 1:0] addra;
	input wire [$clog2(DEPTH) - 1:0] addrb;
	input wire [DATA_WIDTH - 1:0] dia;
	output reg [DATA_WIDTH - 1:0] dob;
	reg [DATA_WIDTH - 1:0] ram [DEPTH - 1:0];
	initial begin : sv2v_autoblock_1
		reg signed [31:0] i;
		for (i = 0; i < DEPTH; i = i + 1)
			ram[i] = DEFAULT_VALUE;
	end
	always @(posedge clka)
		if (wea)
			ram[addra] <= dia;
	always @(*) begin
		if (_sv2v_0)
			;
		dob = ram[addrb];
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
