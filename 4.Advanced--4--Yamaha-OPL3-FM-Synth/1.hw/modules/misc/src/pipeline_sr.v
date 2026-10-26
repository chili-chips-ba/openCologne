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
	output reg [(ENDING_CYCLE >= STARTING_CYCLE ? (((ENDING_CYCLE - STARTING_CYCLE) + 1) * DATA_WIDTH) + ((STARTING_CYCLE * DATA_WIDTH) - 1) : (((STARTING_CYCLE - ENDING_CYCLE) + 1) * DATA_WIDTH) + ((ENDING_CYCLE * DATA_WIDTH) - 1)):(ENDING_CYCLE >= STARTING_CYCLE ? STARTING_CYCLE * DATA_WIDTH : ENDING_CYCLE * DATA_WIDTH)] out;
	initial begin : sv2v_autoblock_1
		reg signed [31:0] i;
		for (i = STARTING_CYCLE; i <= ENDING_CYCLE; i = i + 1)
			out[(ENDING_CYCLE >= STARTING_CYCLE ? i : STARTING_CYCLE - (i - ENDING_CYCLE)) * DATA_WIDTH+:DATA_WIDTH] = POR_VALUE;
	end
	always @(posedge clk) begin
		begin : sv2v_autoblock_2
			reg signed [31:0] i;
			for (i = ENDING_CYCLE; i > STARTING_CYCLE; i = i - 1)
				out[(ENDING_CYCLE >= STARTING_CYCLE ? i : STARTING_CYCLE - (i - ENDING_CYCLE)) * DATA_WIDTH+:DATA_WIDTH] <= out[(ENDING_CYCLE >= STARTING_CYCLE ? i - 1 : STARTING_CYCLE - ((i - 1) - ENDING_CYCLE)) * DATA_WIDTH+:DATA_WIDTH];
		end
		out[(ENDING_CYCLE >= STARTING_CYCLE ? STARTING_CYCLE : STARTING_CYCLE - (STARTING_CYCLE - ENDING_CYCLE)) * DATA_WIDTH+:DATA_WIDTH] <= in;
	end
endmodule
`default_nettype wire
