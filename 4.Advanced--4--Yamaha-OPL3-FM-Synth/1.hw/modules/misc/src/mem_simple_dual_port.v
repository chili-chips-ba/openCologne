`default_nettype none
module mem_simple_dual_port (
	clka,
	clkb,
	wea,
	reb,
	addra,
	addrb,
	dia,
	dob
);
	reg _sv2v_0;
	parameter DATA_WIDTH = 0;
	parameter DEPTH = 0;
	parameter OUTPUT_DELAY = 0;
	parameter [DATA_WIDTH - 1:0] DEFAULT_VALUE = 0;
	input wire clka;
	input wire clkb;
	input wire wea;
	input wire reb;
	input wire [$clog2(DEPTH) - 1:0] addra;
	input wire [$clog2(DEPTH) - 1:0] addrb;
	input wire [DATA_WIDTH - 1:0] dia;
	output reg [DATA_WIDTH - 1:0] dob;
	reg [DATA_WIDTH - 1:0] dob_p0;
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
		dob_p0 = ram[addrb * DATA_WIDTH+:DATA_WIDTH];
	end
	generate
		if (OUTPUT_DELAY != 0) begin : genblk1
			reg [DATA_WIDTH - 1:0] dob_p1 = DEFAULT_VALUE;
			always @(posedge clkb)
				if (reb)
					dob_p1 <= dob_p0;
			if (OUTPUT_DELAY == 1) begin : genblk1
				always @(*) begin
					if (_sv2v_0)
						;
					dob = dob_p1;
				end
			end
			else if (OUTPUT_DELAY == 2) begin : genblk1
				reg [DATA_WIDTH - 1:0] dob_p2 = DEFAULT_VALUE;
				always @(posedge clkb) dob_p2 <= dob_p1;
				always @(*) begin
					if (_sv2v_0)
						;
					dob = dob_p2;
				end
			end
		end
		else begin : genblk1
			always @(*) begin
				if (_sv2v_0)
					;
				dob = dob_p0;
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
