module soc(
	input	      i_clk,
	input	      i_clk25,
	input	      i_rst,
	input		  i_ps2_data,
	input		  i_ps2_clk,
	input			i_dip1,
	input			i_dip2,
	input			i_dip3,
	input			i_dip4,
	output        o_vga_hs,
	output        o_vga_vs,
	output  [3:0] o_vga_r,
	output  [3:0] o_vga_g,
	output  [3:0] o_vga_b,
	output isR
);
//BUS
wire [15:0] addr;
wire [7:0] data_r;
wire [7:0]  data_w;
wire write;
wire read;
wire io;
wire b_inta;
//CPU Intel 8080
i8080 I8080(
	.i_clk(i_clk),
	.i_rst(i_rst),
	.o_addr(addr),
	.o_write(write),
	.o_read(read),
	.o_io(io),
	.i_int(is_int1|is_int2),
	.o_inta(b_inta),
	.i_ready(io_ready | mem_ready),
	.i_dat_r(b_inta? (is_int1? 8'hCF : 8'hD7) : (io_ready?io_port:data_r)),
	//.i_dat_r(io_ready ? io_port1 : data_r),
	.o_dat_w(data_w)
);
wire [7:0] io_port = (addr[7:0] == 8'h00)? io_port0 : 8'h00 |
		             (addr[7:0] == 8'h01)? io_port1 : 8'h00 |
		             (addr[7:0] == 8'h02)? io_port2 : 8'h00 |
		             (addr[7:0] == 8'h03)? data_shifter : 8'h00;
		
reg [7:0] io_port0;
always @(posedge i_clk)
	//if (i_rst) io_port0 <= 0;
	//else 
	io_port0 <= {1'b0,isX,isZ,isS,4'b1110};
reg [7:0] io_port1;
always @(posedge i_clk)
	//if (i_rst) io_port1 <= 0;
	//else
	io_port1 <= {1'b0,isX,isZ,isS,1'b1,is1,is2,isC};
reg [7:0] io_port2;
always @(posedge i_clk)
	//if (i_rst) io_port2 <= 0;
	//else
	io_port2 <= {1'b0,isX,isZ,isS,i_dip3,isT,i_dip2,i_dip1};
wire mem_read = ~io & read;
wire io_read = io & read;
wire mem_write = ~io & write;
wire io_write = io & write;


reg io_ready;
always @(posedge i_clk)
	if (i_rst|io_ready) io_ready <= 0;	//i_rst
	else if (io_write|io_read) io_ready <= 1;
	
wire mem_ready;
mem MEM(
	.i_clk(i_clk),
	.i_clk25(i_clk25),
	.i_rst(i_rst),
	.i_addr(addr[13:0]),
	.i_read(mem_read),
	.i_write(mem_write),
	.i_data(data_w),
	.o_data(data_r),
	.o_data2(vga_data),
	.o_ready(mem_ready),
	.i_read2(vga_read),
	.i_addr2(14'h2400 + vga_addr),
	.o_ready2(vga_ready)
);

reg r_int1;
always @(posedge i_clk)
	if (i_rst) r_int1 <= 0;
	else r_int1 <= int1;

reg r_int2;
always @(posedge i_clk)
	if (i_rst) r_int2 <= 0;
	else r_int2 <= int2;

reg is_int1;
always @(posedge i_clk)
	if (i_rst) is_int1 <= 0;
	else if (is_int1 & b_inta) is_int1 <= 0;
	else if (int1 & ~r_int1) is_int1 <= 1;

reg is_int2;
always @(posedge i_clk)
	if (i_rst) is_int2 <= 0;
	else if (is_int2 & ~is_int1 & b_inta) is_int2 <= 0;
	else if (int2 & ~r_int2) is_int2 <= 1;

wire int1,int2;
wire [12:0] vga_addr;
wire vga_read;
wire vga_ready;
wire [7:0] vga_data;
vga VGA(
	.i_clk(i_clk25),
	.i_rst(i_rst),
	.o_read(vga_read),
	.o_addr(vga_addr),
	.i_data(vga_data),
	.i_ready(vga_ready),
	.o_vga_r(o_vga_r),
	.o_vga_g(o_vga_g),
	.o_vga_b(o_vga_b),
	.o_vga_hs(o_vga_hs),
	.o_vga_vs(o_vga_vs),
	.o_int_96(int1),
	.o_int_224(int2)
);
wire [7:0] data_shifter;
shifter SHIFT(
	.i_clk(i_clk),
	.i_rst(i_rst),
	.i_wr_data(io_write & (addr[7:0] == 8'h04)),
	.i_wr_offset(io_write & (addr[7:0] == 8'h02)),
	.i_data(data_w),
	.o_data(data_shifter)
);

wire isR;
wire isC;
wire is1;
wire is2;
wire isS;
wire isZ;
wire isX;
wire isT;
ps2 PS2(
	.clk(i_clk),
	.rst(i_rst),
	.ps2_data(i_ps2_data),
	.ps2_clk(i_ps2_clk),
	.isR(isR),
	.isC(isC),
	.is1(is1),
	.is2(is2),
	.isS(isS),
	.isZ(isZ),
	.isT(isT),
	.isX(isX)
);

endmodule

