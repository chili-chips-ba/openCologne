`default_nettype none
module synchronizer (
	clk,
	in,
	out
);
	reg _sv2v_0;
	parameter DATA_WIDTH = 1;
	input wire clk;
	input wire [DATA_WIDTH - 1:0] in;
	output reg [DATA_WIDTH - 1:0] out;
	(* ASYNC_REG = "TRUE" *) reg [(2 * DATA_WIDTH) - 1:0] sync_regs = 0;
	always @(posedge clk) {sync_regs[DATA_WIDTH+:DATA_WIDTH], sync_regs[0+:DATA_WIDTH]} <= {sync_regs[0+:DATA_WIDTH], in};
	always @(*) begin
		if (_sv2v_0)
			;
		out = sync_regs[DATA_WIDTH+:DATA_WIDTH];
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
