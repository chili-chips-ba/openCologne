
// vga 640 x 480 @ 60Hz

module vga(
	input i_clk,			//clock 25MHz
	input i_rst,			//reset
	output [12:0] o_addr,	//address bus
	output o_read,			//read strobe
	input [7:0] i_data,		//data in
	input i_ready,			//ready strobe
	output o_vga_hs,		//vga horizontal sync
	output o_vga_vs,		//vga vertical sync
	output [3:0] o_vga_r,	//vga red
	output [3:0] o_vga_g,	//vga green
	output [3:0] o_vga_b,	//vga blue
	output o_int_96,		//ingerrupt at line 96
	output o_int_224		//interrupt at line 224
);

parameter h_frame   = 800;	//800 = 96 (H-SYNC) + 48 (H-BP) + 640 (H-PIX) + 16 (H-FP)
parameter h_pol     = 1'b0;	//H-SYNC polarity
parameter h_pulse   = 96;	//H-SYNC pulse width 96 * 40 ns (25 Mhz) = 3.84 uS
parameter h_bp      = 48;	//H-BP back porch pulse width
parameter h_cols    = 640;	//H-PIX Number of pixels horizontally
parameter h_fp      = 16;	//H-FP front porch pulse width

parameter v_frame   = 525;	// 525 = 2 (V-SYNC) + 33 (V-BP) + 480 (V-PIX) + 10 (V-FP)
parameter v_pol     = 1'b0;	//V-SYNC polarity (positiv works!!!??)
parameter v_pulse   = 2;	//V-SYNC pulse width
parameter v_bp      = 33;	//V-BP back porch pulse width
parameter v_rows    = 480;	//V-PIX Number of pixels vertically
parameter v_fp      = 10;	//V-FP front porch pulse width

//complete horitontal frame
reg [9:0] r_h;
wire h_last = (r_h == h_frame - 1);
always @(posedge i_clk)
	if (i_rst|h_last) r_h <= 0;
	else r_h <= r_h+1;

//complete vertical frame
reg [9:0] r_v;
wire v_last = (r_v == v_frame - 1);
always @(posedge i_clk)
	if (i_rst) r_v <= 0;
	else if (h_last && v_last) r_v <= 0;
	else if (h_last) r_v <= r_v + 1;

//horizontal sync
reg r_vga_hs;
always @(posedge i_clk)
	if (i_rst | h_last) r_vga_hs <= h_pol;
	else if (r_h==h_pulse-1) r_vga_hs <= ~h_pol;

//vertical sync
reg r_vga_vs;
always @(posedge i_clk)
	if (i_rst | (h_last && v_last)) r_vga_vs <= v_pol;
	else if (h_last && (r_v==v_pulse-1)) r_vga_vs <= ~v_pol;

//visible area
wire [9:0] h_col = r_h - h_pulse - h_bp + 1;
wire [9:0] v_row = r_v - v_pulse - v_bp;

//colors red,green,blue
reg     [3:0]   	r_vga_r;
reg     [3:0]   	r_vga_g;
reg     [3:0]   	r_vga_b;

wire visible = (h_col<h_cols) && (v_row<v_rows);


always @(posedge i_clk)
	if (i_rst|~visible) {r_vga_r,r_vga_g,r_vga_b} <= 12'b000000000000;
	else if ((h_col==0) || (h_col == h_cols-1) || (v_row==0) || (v_row==v_rows-1)) {r_vga_r,r_vga_g,r_vga_b} <= 12'b111100000000;
	else if (p_visible & r_data[0]) {r_vga_r,r_vga_g,r_vga_b} <= green? 12'b000011110000 : red? 12'b111100001100: 12'b111111111111;
	else {r_vga_r,r_vga_g,r_vga_b} <= 12'b000000000000;

wire green = ((h_col > 106) || ((v_row>50) && (v_row<280))) && (h_col<220);
wire red   = (h_col > 480) && (h_col<520);

assign 	o_vga_r 		= r_vga_r;		//assign the output signals for VGA to the VGA registers
assign 	o_vga_g 		= r_vga_g;
assign 	o_vga_b 		= r_vga_b;
assign 	o_vga_hs 		= r_vga_hs;
assign 	o_vga_vs 		= r_vga_vs;

//frame buffer
wire p_visible = (h_col>=64) & (h_col<576) & (v_row>=16) & (v_row <464);

wire [9:0] f_row = (v_row-16)>>1;
wire [9:0] f_col = (h_col-61)>>1;
wire [12:0] addr = {f_row[7:0],f_col[7:3]};
wire strobe = (f_row<224)& (f_col<256) & (r_h[3:0]==4'h8);

//interrupt signals at line 96 and line 224
assign o_int_96 = (f_row==10'd96);
assign o_int_224 = (f_row==10'd224);

//address register
reg [12:0] r_addr;
always @(posedge i_clk)
	if (i_rst) r_addr <= 0;
	else if (strobe) r_addr <= addr;

assign o_addr = r_addr;

//read strobe
reg read;
always @(posedge i_clk)
	if (i_rst|read) read <= 0;
	else if (strobe) read <= 1;

assign o_read = read;

//data register
reg [7:0] r_data;
always @(posedge i_clk)
	if (i_rst) r_data <= 0;
	else if (i_ready) r_data <= i_data;
	else if (shift) r_data <= r_data>>1;
	
wire shift = p_visible & ~r_h[0];
endmodule
