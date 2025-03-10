module top(
   input CLK,
   output LED,
   input BUT,
   output VGA_HS,
   output VGA_VS,
   output [3:0] VGA_R,
   output [3:0] VGA_G,
   output [3:0] VGA_B,
   input PS2_DATA,
   input PS2_CLK,
   input DIP1,
   input DIP2,
   input DIP3,
   input DIP4
);
	wire clk270, clk180, clk90, usr_ref_out,clk10;
	wire usr_pll_lock_stdy, usr_pll_lock;

 assign clk10 = CLK;
wire clk;
wire locked;
pll25 PLL(.clock_in(CLK),.clock_out(clk),.locked(locked));
wire isR;
reg [1:0] reset;
initial reset =0;
always @(posedge clk10)
	if (isR|~BUT) reset <= 0;
	else if (rst) reset <= reset +1;
wire rst = ~reset[1];
assign LED = ~rst;
soc SOC(
	.i_clk25(clk),
	.i_clk(clk10),
	.i_rst(rst),
	.i_ps2_data(PS2_DATA),
	.i_ps2_clk(PS2_CLK),
	.o_vga_hs(VGA_HS),
	.o_vga_vs(VGA_VS),
	.o_vga_r(VGA_R),
	.o_vga_g(VGA_G),
	.o_vga_b(VGA_B),
	.isR(isR),
	.i_dip1(DIP1),
	.i_dip2(DIP2),
	.i_dip3(DIP3),
	.i_dip4(DIP4)
);
   
endmodule
