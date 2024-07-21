`default_nettype none
module edge_detector (
	clk,
	clk_en,
	in,
	edge_detected
);
	reg _sv2v_0;
	parameter EDGE_LEVEL = 1;
	parameter CLK_DLY = 0;
	parameter INITIAL_INPUT_LEVEL = 0;
	input wire clk;
	input wire clk_en;
	input wire in;
	output reg edge_detected = 0;
	reg in_r0 = INITIAL_INPUT_LEVEL;
	reg in_r1 = INITIAL_INPUT_LEVEL;
	always @(posedge clk)
		if (clk_en) begin
			if (!CLK_DLY)
				in_r0 <= in;
			else begin
				in_r0 <= in;
				in_r1 <= in_r0;
			end
		end
	always @(*) begin
		if (_sv2v_0)
			;
		if (EDGE_LEVEL) begin
			if (!CLK_DLY)
				edge_detected = (clk_en && in) && !in_r0;
			else
				edge_detected = in_r0 && !in_r1;
		end
		else if (!CLK_DLY)
			edge_detected = (clk_en && !in) && in_r0;
		else
			edge_detected = !in_r0 && in_r1;
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
