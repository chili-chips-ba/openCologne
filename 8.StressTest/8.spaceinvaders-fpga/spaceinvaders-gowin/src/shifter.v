//hardware bitshift unit
//connected to Intel 8080 over IO-port 4 and 6 
//used to do the bitshift math, because I8080 has only limited shift operation

module shifter(
	input i_clk,
	input i_rst,
	input i_wr_data,
	input i_wr_offset,
	input  [7:0] i_data,
	output [7:0] o_data
);

reg [15:0] r_shifter;
always @(posedge i_clk)
	if (i_rst) r_shifter <= 16'h0000;
	else if (i_wr_data) r_shifter <= {i_data,r_shifter[15:8]};

wire  [15:0] shifted = (r_shifter << r_offset);
assign o_data = shifted[15:8];

reg [2:0] r_offset;
always @(posedge i_clk)
	if (i_rst) r_offset <= 3'd0;
	else if (i_wr_offset) r_offset <= i_data[2:0];

endmodule
