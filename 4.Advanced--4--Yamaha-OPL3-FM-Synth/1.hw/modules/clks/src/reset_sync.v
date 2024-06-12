`default_nettype none
module reset_sync (
	clk,
	arst_n,
	reset
);
	reg _sv2v_0;
	input wire clk;
	input wire arst_n;
	output reg reset;
	(* ASYNC_REG = "true" *) reg r0 = 1;
	(* ASYNC_REG = "true" *) reg r1 = 1;
	(* ASYNC_REG = "true" *) reg r2 = 1;
	always @(posedge clk or negedge arst_n)
		if (!arst_n) begin
			r0 <= 1;
			r1 <= 1;
			r2 <= 1;
		end
		else begin
			r0 <= 0;
			r1 <= r0;
			r2 <= r1;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		reset = r2;
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
