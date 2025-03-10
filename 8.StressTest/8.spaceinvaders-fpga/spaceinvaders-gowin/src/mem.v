// Memory map of spaceinvaders arcade machine
// 0000-1FFF 8K ROM
// 2000-23FF 1k RAM
// 2400-3FFF 7K video RAM
module mem(
	input	i_clk,
	input	i_clk25,
	input	i_rst,
	input [13:0] i_addr,
	output reg [7:0] o_data,
	input [7:0] i_data,
	input i_read,
	input i_write,
	output reg o_ready,
	input [13:0] i_addr2,
	output reg [7:0] o_data2,
	input i_read2,
	output reg o_ready2
);

reg [7:0] MEM[0:16383];
initial $readmemb("code.bin",MEM); 

always @(posedge i_clk)
	if (i_rst) o_data <= 8'h00;
	else if (i_write&i_addr[13]) MEM[i_addr]<=i_data;
	else o_data <= MEM[i_addr];
always @(posedge i_clk)
	if (i_rst) o_ready <= 0;
	else o_ready <= i_read|i_write;
always @(posedge i_clk25)
	//if (i_rst) o_data2 <= 8'h00;
	//else
	if (i_read2) o_data2 <= MEM[i_addr2];
always @(posedge i_clk25)
	if (o_ready2) o_ready2 <= 0; //i_rst
	else o_ready2 <= i_read2;

endmodule
