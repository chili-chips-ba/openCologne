`default_nettype none
module clk_div (
	clk,
	clk_en
);
	parameter CLK_DIV_COUNT = 0;
	input wire clk;
	output reg clk_en = 0;
	reg [$clog2(CLK_DIV_COUNT) - 1:0] counter = 0;
	always @(posedge clk)
		if (counter == (CLK_DIV_COUNT - 1))
			counter <= 0;
		else
			counter <= counter + 1;
	always @(posedge clk) clk_en <= counter == (CLK_DIV_COUNT - 1);
endmodule
`default_nettype wire
