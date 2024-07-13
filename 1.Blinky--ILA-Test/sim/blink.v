`timescale 1ns / 1ps

module blink(
		input wire clk,
		input wire ILA_rst,
		output [24:0] ila_sample_dut,
		output wire led
	);


reg [24:0] counter;

	assign led = counter[24];
	assign ila_sample_dut = counter;

	always @(posedge clk)
	begin
		if (!ILA_rst) begin
			counter <= 0; //-1000; // 27'b010011111111111100000000000;
		end else begin
			counter <= counter + 1'b1;
		end
	end

	
endmodule
