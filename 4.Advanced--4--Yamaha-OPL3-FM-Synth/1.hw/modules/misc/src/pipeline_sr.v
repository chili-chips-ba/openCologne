`default_nettype none
module pipeline_sr (
	clk,
	in,
	out
);
	parameter DATA_WIDTH = 1;
	parameter STARTING_CYCLE = 0;
	parameter ENDING_CYCLE = 1;
	parameter POR_VALUE = 0;
	input wire clk;
	input wire [DATA_WIDTH - 1:0] in;
	function automatic [DATA_WIDTH - 1:0] sv2v_cast_DD846;
		input reg [DATA_WIDTH - 1:0] inp;
		sv2v_cast_DD846 = inp;
	endfunction
	output reg [(ENDING_CYCLE >= STARTING_CYCLE ? (((ENDING_CYCLE - STARTING_CYCLE) + 1) * DATA_WIDTH) + ((STARTING_CYCLE * DATA_WIDTH) - 1) : (((STARTING_CYCLE - ENDING_CYCLE) + 1) * DATA_WIDTH) + ((ENDING_CYCLE * DATA_WIDTH) - 1)):(ENDING_CYCLE >= STARTING_CYCLE ? STARTING_CYCLE * DATA_WIDTH : ENDING_CYCLE * DATA_WIDTH)] out = {(ENDING_CYCLE >= STARTING_CYCLE ? (ENDING_CYCLE - STARTING_CYCLE) + 1 : (STARTING_CYCLE - ENDING_CYCLE) + 1) {sv2v_cast_DD846(POR_VALUE)}};
	always @(posedge clk) begin
		out <= out << DATA_WIDTH;
		out[(ENDING_CYCLE >= STARTING_CYCLE ? STARTING_CYCLE : STARTING_CYCLE - (STARTING_CYCLE - ENDING_CYCLE)) * DATA_WIDTH+:DATA_WIDTH] <= in;
	end
endmodule
`default_nettype wire
