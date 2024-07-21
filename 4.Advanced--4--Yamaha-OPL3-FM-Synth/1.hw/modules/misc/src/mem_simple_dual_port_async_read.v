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
	function automatic [DATA_WIDTH - 1:0] sv2v_cast_DD846;
		input reg [DATA_WIDTH - 1:0] inp;
		sv2v_cast_DD846 = inp;
	endfunction
	reg [(DEPTH * DATA_WIDTH) - 1:0] ram = {DEPTH {sv2v_cast_DD846(DEFAULT_VALUE)}};
	always @(posedge clka)
		if (wea)
			ram[addra * DATA_WIDTH+:DATA_WIDTH] <= dia;
	always @(*) begin
		if (_sv2v_0)
			;
		dob = ram[addrb * DATA_WIDTH+:DATA_WIDTH];
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
