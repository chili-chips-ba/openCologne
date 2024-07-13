/*
 * cpelib.v
 *
 * Gate level description of a CPE using a set of simplified library elements
 * for post-implementation simulation with back annotated timings.
 *
 * Copyright (C) 2024 Cologne Chip AG <support@colognechip.com>
 *
 * Revision history:
 *   2024-03-27 - Fixed CPE_TOBF enable polarity.
 *   2024-01-31 - Added missing C_D, C_DST and C_DRS specify timing constraints.
 *   2023-12-20 - Added CINY2 path for timing simulation.
 *   2023-12-20 - Added CC_PLL lock in time and specify block.
 *   2023-12-19 - Fixed C_ADDF2 and C_ADDF2x CIN signal declaration.
 *   2023-12-19 - Fixed CC_IO_SEL GPIO_EN signal.
 *   2023-12-19 - Added CPE_TOBF module.
 *   2023-06-19 - Prevent implicit declarations.
 *   2023-05-18 - Add FIFO status signals to Block RAM.
 *   2023-03-20 - Enable Block RAM initialization.
 *   2023-02-21 - Added C_D, C_DST and C_DRS initial values.
 *   2023-02-13 - Fixed CADD_{A,S} in C_ADDFx.
 *   2022-12-02 - Added CC_IO_SEL module.
 *   2022-11-01 - C_D, C_DST, C_DRS revision.
 *   2022-08-29 - C_MULT, C_AND and C_OR revision.
 *   2022-06-01 - Initial version.
 */

`timescale 1 ps / 1 ps

`define USE_PLL
`define xUSE_RAM
`define xUSE_TIMING
`define xUSE_TIMINGCHECKS

module CPE_IBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  I,
	output Y
);
	assign Y = I;

`ifdef USE_TIMING
	specify
		(I => Y) = 0;
	endspecify
`endif
endmodule


module CPE_OBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  A,
	output O
);
	assign O = A;

`ifdef USE_TIMING
	specify
		(A => O) = 0;
	endspecify
`endif
endmodule


module CPE_TOBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  A, EN,
	output O
);
	assign O = EN ? A : 1'bz;

endmodule


module CPE_IOBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  A, EN,
	output Y,
	inout  O
);
	assign O = EN ? A : 1'bz;
	assign Y = O;

`ifdef USE_TIMING
	specify
		(A  => O) = 0;
		(EN => O) = 0;
		(A  => Y) = 0;
		(EN => Y) = 0;
		(O  => Y) = 0;
	endspecify
`endif
endmodule


module CPE_LVDS_IBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  I, IB,
	output Y
);

	assign Y = I;

`ifdef USE_TIMING
	specify
		(I => Y) = 0;
		(IB => Y) = 0;
	endspecify
`endif
endmodule


module CPE_LVDS_OBF #(
	parameter [71:0] BUF_CFG = 72'b0
)(
	input  A,
	output O, OB
);

	assign O = A;
	assign OB = ~A;

`ifdef USE_TIMING
	specify
		(A => O) = 0;
		(A => OB) = 0;
	endspecify
`endif
endmodule


module CC_IO_SEL #(
	parameter [71:0] IO_SEL_CFG = 72'b0
)(
	output IN1_O, IN2_O,
	output GPIO_OUT, GPIO_EN,
	input  CLOCK1, CLOCK2, CLOCK3, CLOCK4,
	input  OUT1_I, OUT2_I, OUT3_I, OUT4_I,
	input  GPIO_IN,
	input  RESET, // does not exist
	input  DDR_I
);
	reg q0_o = 1'bx;
	reg q1_o = 1'bx;
	reg q2_o = 1'bx;
	reg q3_o = 1'bx;

	wire q0_i = IO_SEL_CFG[9]  ? OUT4_I : OUT1_I;
	wire q1_i = IO_SEL_CFG[10] ? OUT3_I : OUT2_I;
	wire q2_i = GPIO_IN;
	wire q3_i = GPIO_IN;

	wire q0mx_o = IO_SEL_CFG[20] ? q0_o : q0_i;
	wire q1mx_o = IO_SEL_CFG[21] ? q1_o : q1_i;

	wire OMUX_SEL = (IO_SEL_CFG[13] & ~IO_SEL_CFG[12]) ? DDR_I : IO_SEL_CFG[11];
	assign GPIO_OUT = IO_SEL_CFG[8] ? (OMUX_SEL ? q1mx_o : q0mx_o) : (OMUX_SEL ? 1'b1 : 1'b0);

	wire clk_o = IO_SEL_CFG[25] ? (IO_SEL_CFG[24] ? CLOCK4 : CLOCK3) : (IO_SEL_CFG[24] ? CLOCK2 : CLOCK1);
	wire clk_i = IO_SEL_CFG[29] ? (IO_SEL_CFG[28] ? CLOCK4 : CLOCK3) : (IO_SEL_CFG[28] ? CLOCK2 : CLOCK1);

	wire q0clk = IO_SEL_CFG[26] ^ clk_o;
	wire q1clk = IO_SEL_CFG[27] ^ clk_o;
	wire q2clk = IO_SEL_CFG[30] ^ clk_i;
	wire q3clk = IO_SEL_CFG[31] ^ clk_i;

	assign IN1_O = IO_SEL_CFG[22] ? q2_o : q2_i;
	assign IN2_O = IO_SEL_CFG[23] ? q3_o : q3_i;

	assign GPIO_EN = IO_SEL_CFG[17] ? (IO_SEL_CFG[18] ? OUT4_I : OUT2_I) : (IO_SEL_CFG[18] ? OUT3_I : IO_SEL_CFG[16]);

	always @(posedge q0clk)
	begin
		q0_o <= q0_i;
	end

	always @(posedge q1clk)
	begin
		q1_o <= q1_i;
	end

	always @(posedge q2clk)
	begin
		q2_o <= q2_i;
	end

	always @(posedge q3clk)
	begin
		q3_o <= q3_i;
	end

endmodule


module C_L2T4(
	output O,
	input I0, I1, I2, I3
);
	parameter [3:0] INIT_L00 = 4'b0000;
	parameter [3:0] INIT_L01 = 4'b0000;
	parameter [3:0] INIT_L10 = 4'b0000;

	wire [1:0] l00_s1 = I1 ? INIT_L00[3:2] : INIT_L00[1:0];
	wire l00 = I0 ? l00_s1[1] : l00_s1[0];

	wire [1:0] l01_s1 = I3 ? INIT_L01[3:2] : INIT_L01[1:0];
	wire l01 = I2 ? l01_s1[1] : l01_s1[0];

	wire [1:0] l10_s1 = l01 ? INIT_L10[3:2] : INIT_L10[1:0];
	assign O = l00 ? l10_s1[1] : l10_s1[0];

endmodule


module C_L2T5(
	output O,
	input I0, I1, I2, I3, I4
);
	parameter [3:0] INIT_L02 = 4'b0000;
	parameter [3:0] INIT_L03 = 4'b0000;
	parameter [3:0] INIT_L11 = 4'b0000;
	parameter [3:0] INIT_L20 = 4'b0000;

	wire [1:0] l02_s1 = I1 ? INIT_L02[3:2] : INIT_L02[1:0];
	wire l02 = I0 ? l02_s1[1] : l02_s1[0];

	wire [1:0] l03_s1 = I3 ? INIT_L03[3:2] : INIT_L03[1:0];
	wire l03 = I2 ? l03_s1[1] : l03_s1[0];

	wire [1:0] l11_s1 = l03 ? INIT_L11[3:2] : INIT_L11[1:0];
	wire l11 = l02 ? l11_s1[1] : l11_s1[0];

	wire [1:0] l20_s1 = l11 ? INIT_L20[3:2] : INIT_L20[1:0];
	assign O = I4 ? l20_s1[1] : l20_s1[0];

endmodule


module C_AND #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire CIN = CPE_CFG[6] ? CINX : CINY1; // C_HORIZ
	wire L10 = &cpe_i[4:1];
	wire L20 = (&cpe_i[6:5]) & (CPE_CFG[4] ? CINY1 : &cpe_i[8:7]); // handle C_EN_CIN
	wire LUT = (L10 & L20) ^ (CPE_CFG[5] & CIN);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_OR #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire L10 = |cpe_i[4:1];
	wire L20 = (|cpe_i[6:5]) | (CPE_CFG[4] ? CINY1 : |cpe_i[8:7]); // handle C_EN_CIN
	wire LUT = (L10 | L20);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_XOR #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire LUT = ^cpe_i[8:1];
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_ORAND #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire LUT = (|cpe_i[2:1]) & (|cpe_i[4:3]) & (|cpe_i[6:5]) & (|cpe_i[8:7]);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_ANDXOR #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire LUT = (~&cpe_i[2:1]) ^ (~&cpe_i[4:3]) ^ (~&cpe_i[6:5]) ^ (~&cpe_i[8:7]);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_ICOMP #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire LUT = (~^cpe_i[2:1]) & (~^cpe_i[4:3]) & (~^cpe_i[6:5]) & (~^cpe_i[8:7]);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_C_OR #(
	parameter [6:0] CPE_CFG = 7'b0
)(
	output OUT, COUTY1, POUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;

	assign COUTY1 = (|cpe_i[6:1]) | CINY1;
	assign POUTY1 = (|cpe_i[6:1]) | PINY1;

`ifdef USE_TIMING
	specify
		(IN1   => COUTY1) = 0;
		(IN2   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN4   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN6   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(IN1   => POUTY1) = 0;
		(IN2   => POUTY1) = 0;
		(IN3   => POUTY1) = 0;
		(IN4   => POUTY1) = 0;
		(IN5   => POUTY1) = 0;
		(IN6   => POUTY1) = 0;
		(IN7   => POUTY1) = 0;
		(IN8   => POUTY1) = 0;
		(CINX  => POUTY1) = 0;
		(PINY1 => POUTY1) = 0;
	endspecify
`endif
endmodule


module C_C_XOR #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTY1, POUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	//assign COUTY1 = (|cpe_i[6:1]) ^ CINY1;
	//assign POUTY1 = (|cpe_i[6:1]) ^ PINY1;
	wire LUT = (^cpe_i[8:1]) ^ CINY1;
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_MX2a #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire s1 = (IN7 & IN8);
	wire s0 = (IN5 & IN6);

	wire LUT = s1 ? (s0 ? IN4 : IN3) : (s0 ? IN2 : IN1);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1 => OUT) = 0;
		(IN2 => OUT) = 0;
		(IN3 => OUT) = 0;
		(IN4 => OUT) = 0;
		(IN5 => OUT) = 0;
		(IN6 => OUT) = 0;
		(IN7 => OUT) = 0;
		(IN8 => OUT) = 0;
	endspecify
`endif
endmodule


module C_MX2b #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire s0 = (IN1 & IN2);
	wire s1 = (IN3 & IN4);

	wire LUT = s1 ? (s0 ? IN8 : IN7) : (s0 ? IN6 : IN5);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1 => OUT) = 0;
		(IN2 => OUT) = 0;
		(IN3 => OUT) = 0;
		(IN4 => OUT) = 0;
		(IN5 => OUT) = 0;
		(IN6 => OUT) = 0;
		(IN7 => OUT) = 0;
		(IN8 => OUT) = 0;
	endspecify
`endif
endmodule


module C_MX4a #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire s1 = (IN7 & IN8);
	wire s0 = (IN5 & IN6);

	wire LUT = s1 ? (s0 ? IN4 : IN3) : (s0 ? IN2 : IN1);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1 => OUT) = 0;
		(IN2 => OUT) = 0;
		(IN3 => OUT) = 0;
		(IN4 => OUT) = 0;
		(IN5 => OUT) = 0;
		(IN6 => OUT) = 0;
		(IN7 => OUT) = 0;
		(IN8 => OUT) = 0;
	endspecify
`endif
endmodule


module C_MX4b #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	wire s0 = (IN1 & IN2);
	wire s1 = (IN3 & IN4);

	wire LUT = s1 ? (s0 ? IN8 : IN7) : (s0 ? IN6 : IN5);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

`ifdef USE_TIMING
	specify
		(IN1 => OUT) = 0;
		(IN2 => OUT) = 0;
		(IN3 => OUT) = 0;
		(IN4 => OUT) = 0;
		(IN5 => OUT) = 0;
		(IN6 => OUT) = 0;
		(IN7 => OUT) = 0;
		(IN8 => OUT) = 0;
	endspecify
`endif
endmodule


module C_O_MUX (
	output COMP_OUT,
	input COMB1, COMB2
);

	assign COMP_OUT = COMB1;

`ifdef USE_TIMING
	specify
		(COMB1 => COMP_OUT) = 0;
	endspecify
`endif
endmodule


module C_O_OR2 (
	output COMP_OUT,
	input COMB1, COMB2
);

	assign COMP_OUT = COMB1 | COMB2;

`ifdef USE_TIMING
	specify
		(COMB1 => COMP_OUT) = 0;
		(COMB2 => COMP_OUT) = 0;
	endspecify
`endif
endmodule


module C_0 #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	assign OUT = 0;

endmodule


module C_1 #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	assign OUT = 1;

endmodule


module C_C_0_1 #(
	parameter [7:0] CPE_CFG = 8'b0
)(
	output OUT, COUTY1,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);

	assign OUT = SR;

endmodule


module C_C_CAT #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	// COMB01
	wire OROUT = ~(~((IN1 & IN2) | (IN3 & IN4)) & ~(IN5 & IN6));
	wire L11 = IN7 & IN8;
	wire COMBOUT = IN7 & IN8;

	// COMB02
	wire CADD_S = L11;
	wire CADD_A = OROUT;

	// COMB03
	assign COUTY1 = CADD_S ? CADD_A : CINY1;

	// SEQ01
	assign OUT = COMBOUT;

endmodule


module C_ADDF #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire CIN = CPE_CFG[6] ? CINX : CINY1; // C_HORIZ
	wire LUT = (&cpe_i[2:1]) ^ (&cpe_i[4:3]) ^ (&cpe_i[6:5]) ^ (&cpe_i[8:7] ^ CIN);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

	wire CADD_A = (&cpe_i[2:1]) | (&cpe_i[4:3]) | (&cpe_i[6:5]); // OR3
	wire CADD_S = (&cpe_i[2:1]) ^ (&cpe_i[4:3]) ^ (&cpe_i[6:5]) ^ (&cpe_i[8:7]);

	generate
		if (CPE_CFG[6]) begin
			assign COUTX = CADD_S ? CIN : CADD_A;
		end
		else begin
			assign COUTY1 = CADD_S ? CIN : CADD_A;
		end
	endgenerate

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINY1 => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;

		(IN1   => COUTY1) = 0;
		(IN2   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN4   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN6   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(PINX  => COUTY1) = 0;
	endspecify
`endif
endmodule


module C_ADDFx #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire CIN = CPE_CFG[6] ? CINX : CINY1; // C_HORIZ
	wire LUT = (^cpe_i[2:1]) ^ (^cpe_i[4:3]) ^ (^cpe_i[6:5]) ^ (^cpe_i[8:7] ^ CIN);
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

	wire CADD_A = (^cpe_i[2:1]) | (^cpe_i[4:3]) | (^cpe_i[6:5]); // OR3
	wire CADD_S = (^cpe_i[2:1]) ^ (^cpe_i[4:3]) ^ (^cpe_i[6:5]) ^ (^cpe_i[8:7]);

	generate
		if (CPE_CFG[6]) begin
			assign COUTX = CADD_S ? CIN : CADD_A;
		end
		else begin
			assign COUTY1 = CADD_S ? CIN : CADD_A;
		end
	endgenerate

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINY1 => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;

		(IN1   => COUTY1) = 0;
		(IN2   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN4   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN6   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(PINX  => COUTY1) = 0;
	endspecify
`endif
endmodule


module C_ADDF2 #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	wire [8:1] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire L10 = (&cpe_i[2:1]) ^ (&cpe_i[4:3]);
	wire L11 = (&cpe_i[6:5]) ^ (&cpe_i[8:7]);
	wire L02 =  &cpe_i[6:5];

	wire CIN = CPE_CFG[6] ? CINX : CINY1; // C_HORIZ

	wire na2_1 = ~(~CIN & L11);
	wire na2_2 = ~(L02 & ~L11);
	wire na3_1 = ~(na2_1 & na2_1);

	wire na2_3 = ~(L10 & na3_1);
	wire or2_1 = (L10 | na3_1);
	wire COMB2OUT = ~(na2_3 & or2_1);
	wire COMB1OUT = CIN ^ L11; // CIN ? 0 : L11;

	wire o2 = ~(L10 ^ (L11 ? ~CIN : ~L02));
	wire LUT = CPE_CFG[7] ? o2 : COMB1OUT;
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

	wire CADD_A = (L10) ? (&cpe_i[6:5]) : ((&cpe_i[2:1]) | (&cpe_i[4:3]));
	wire CADD_S = (L10) & (L11);

	generate
		if (CPE_CFG[6]) begin
			assign COUTX = CADD_S ? CIN : CADD_A;
		end
		else begin
			assign COUTY1 = CADD_S ? CIN : CADD_A;
		end
	endgenerate

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINY1 => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;

		(IN1   => COUTY1) = 0;
		(IN2   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN4   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN6   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(PINX  => COUTY1) = 0;
	endspecify
`endif
endmodule


module C_ADDF2x #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, COUTX, COUTY1,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);

	wire [8:1] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = CPE_CFG[0] ? PINY1 : IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = CPE_CFG[1] ? CINX : IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = CPE_CFG[2] ? PINY1 : IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = CPE_CFG[3] ? PINX : IN8;

	wire L10 = (^cpe_i[2:1]) ^ (^cpe_i[4:3]);
	wire L11 = (^cpe_i[6:5]) ^ (^cpe_i[8:7]);
	wire L02 =  ^cpe_i[6:5];

	wire CIN = CPE_CFG[6] ? CINX : CINY1; // C_HORIZ

	wire na2_1 = ~(~CIN & L11);
	wire na2_2 = ~(L02 & ~L11);
	wire na3_1 = ~(na2_1 & na2_1);

	wire na2_3 = ~(L10 & na3_1);
	wire or2_1 = (L10 | na3_1);
	wire COMB2OUT = ~(na2_3 & or2_1);
	wire COMB1OUT = CIN ^ L11; // CIN ? 0 : L11;

	wire o2 = ~(L10 ^ (L11 ? ~CIN : ~L02));
	wire LUT = CPE_CFG[7] ? o2 : COMB1OUT;
	assign OUT = CPE_CFG[8] ? ~LUT : LUT;

	wire CADD_A = (L10) ? (^cpe_i[6:5]) : ((^cpe_i[2:1]) | (^cpe_i[4:3]));
	wire CADD_S = (L10) & (L11);

	generate
		if (CPE_CFG[6]) begin
			assign COUTX = CADD_S ? CIN : CADD_A;
		end
		else begin
			assign COUTY1 = CADD_S ? CIN : CADD_A;
		end
	endgenerate

`ifdef USE_TIMING
	specify
		(IN1   => OUT) = 0;
		(IN2   => OUT) = 0;
		(IN3   => OUT) = 0;
		(IN4   => OUT) = 0;
		(IN5   => OUT) = 0;
		(IN6   => OUT) = 0;
		(IN7   => OUT) = 0;
		(IN8   => OUT) = 0;
		(CINY1 => OUT) = 0;
		(PINY1 => OUT) = 0;
		(CINX  => OUT) = 0;
		(PINX  => OUT) = 0;

		(IN1   => COUTX) = 0;
		(IN2   => COUTX) = 0;
		(IN3   => COUTX) = 0;
		(IN4   => COUTX) = 0;
		(IN5   => COUTX) = 0;
		(IN6   => COUTX) = 0;
		(IN7   => COUTX) = 0;
		(IN8   => COUTX) = 0;
		(CINY1 => COUTX) = 0;
		(PINY1 => COUTX) = 0;
		(CINX  => COUTX) = 0;
		(PINX  => COUTX) = 0;

		(IN1   => COUTY1) = 0;
		(IN2   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN4   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN6   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(PINX  => COUTY1) = 0;
	endspecify
`endif
endmodule


module C_Carry #(
	parameter [7:0] CPE_CFG = 8'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	assign OUT = CP_O;

`ifdef USE_TIMING
	specify
		(CP_O => OUT) = 0;
	endspecify
`endif
endmodule


module C_MULT #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT1, OUT2,
	output COUTX, POUTX,
	output COUTY1, POUTY1,
	output COUTY2, POUTY2,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CLK, EN, SR,
	input  CINX, CINY1, CINY2,
	input  PINX, PINY1, PINY2,
	input  RAM_I1, RAM_I2
);

	wire [8:1] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = PINY1;
	assign cpe_i[4] = CINX;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = PINY1;
	assign cpe_i[8] = PINX;

	wire L10 = ~((&cpe_i[2:1]) ^ CINX);
	wire L11 = ~((&cpe_i[6:5]) ^ PINX);
	wire L02OUT = &cpe_i[6:5];
	wire NOROUT = ~((&cpe_i[2:1]) | CINX);

	// COMB02 ADDF2
	wire CADD_A = ((~NOROUT | ~L10) & ~(~L02OUT & ~L10));
	wire CADD_S = (~L10) & (~L11);
	wire ADDF2 = ~(~(~L11 & ~CINY1) & ~(~L02OUT & L11));

	// COMB02 MULT
	wire nand2_0 = ~(PINY2 & IN5);
	wire nand2_1 = ~(PINY2 & IN8);
	wire xnor3_0 = ~(nand2_0 ^ ~L10 ^ ~ADDF2);
	wire xnor3_1 = ~(nand2_1 ^ CINY1 ^ ~L11);
	wire mx2_0 = ~(( nand2_0 | xnor3_0) & (nand2_1 | ~xnor3_0));
	wire mx2_1 = ~((~nand2_1 | xnor3_1) & (CINY2 | ~xnor3_1));

	wire COY2_A = mx2_0;
	wire COY2_S = ~(~xnor3_0 | ~xnor3_1);
	wire MULTO1 = ~(xnor3_1 ^ ~CINY2);
	wire MULTO2 = ~(xnor3_0 ^ mx2_1);

	// COMB03
	assign COUTX  = MULTO2;
	assign COUTY1 = CADD_S ? CINY1 : CADD_A;
	assign COUTY2 = COY2_S ? CINY2 : COY2_A;
	assign OUT2   = COUTX;

	// COMB04
	assign POUTX  = MULTO1;
	assign POUTY1 = CPE_CFG[4] ? COUTX : PINY1;
	assign POUTY2 = PINY2;
	assign OUT1   = CPE_CFG[4] ? COUTX : POUTX;

`ifdef USE_TIMING
	specify
		(IN1   => OUT1) = 0;
		(IN3   => OUT1) = 0;
		(IN5   => OUT1) = 0;
		(IN7   => OUT1) = 0;
		(IN8   => OUT1) = 0;
		(CINY1 => OUT1) = 0;
		(CINY2 => OUT1) = 0;
		(PINY1 => OUT1) = 0;
		(PINY2 => OUT1) = 0;
		(CINX  => OUT1) = 0;
		(PINX  => OUT1) = 0;
		(IN1   => OUT2) = 0;
		(IN3   => OUT2) = 0;
		(IN5   => OUT2) = 0;
		(IN7   => OUT2) = 0;
		(IN8   => OUT2) = 0;
		(CINY1 => OUT2) = 0;
		(CINY2 => OUT2) = 0;
		(PINY1 => OUT2) = 0;
		(PINY2 => OUT2) = 0;
		(CINX  => OUT2) = 0;
		(PINX  => OUT2) = 0;
		(IN1   => COUTX) = 0;
		(IN3   => COUTX) = 0;
		(IN5   => COUTX) = 0;
		(IN7   => COUTX) = 0;
		(IN8   => COUTX) = 0;
		(CINY1 => COUTX) = 0;
		(CINY2 => COUTX) = 0;
		(PINY1 => COUTX) = 0;
		(PINY2 => COUTX) = 0;
		(CINX  => COUTX) = 0;
		(PINX  => COUTX) = 0;
		(IN1   => POUTX) = 0;
		(IN3   => POUTX) = 0;
		(IN5   => POUTX) = 0;
		(IN7   => POUTX) = 0;
		(IN8   => POUTX) = 0;
		(CINY1 => POUTX) = 0;
		(CINY2 => POUTX) = 0;
		(PINY1 => POUTX) = 0;
		(PINY2 => POUTX) = 0;
		(CINX  => POUTX) = 0;
		(PINX  => POUTX) = 0;
		(IN1   => COUTY1) = 0;
		(IN3   => COUTY1) = 0;
		(IN5   => COUTY1) = 0;
		(IN7   => COUTY1) = 0;
		(IN8   => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(CINY2 => COUTY1) = 0;
		(PINY1 => COUTY1) = 0;
		(PINY2 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(PINX  => COUTY1) = 0;
		(PINY1 => POUTY1) = 0;
		(IN1   => COUTY2) = 0;
		(IN3   => COUTY2) = 0;
		(IN5   => COUTY2) = 0;
		(IN7   => COUTY2) = 0;
		(IN8   => COUTY2) = 0;
		(CINY1 => COUTY2) = 0;
		(CINY2 => COUTY2) = 0;
		(PINY1 => COUTY2) = 0;
		(PINY2 => COUTY2) = 0;
		(CINX  => COUTY2) = 0;
		(PINX  => COUTY2) = 0;
		(PINY2 => POUTY2) = 0;
	endspecify
`endif
endmodule


module C_MULTFa #(
	parameter [7:0] CPE_CFG = 8'b0
)(
	output COUTX, POUTX,
	output COUTY1, POUTY1,
	output COUTY2,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CLK, EN, SR,
	input  CINX, CINY1, CINY2,
	input  PINX, PINY1, PINY2,
	input  RAM_I1, RAM_I2
);

	assign COUTY1 = PINY1 ^ CINX;
	assign COUTY2 = CINY2;
	assign COUTX  = CINY2;
	assign POUTY1 = CINY1 ^ (PINY1 & CINX);

`ifdef USE_TIMING
	specify
		(CINY2 => COUTX) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(CINY1 => POUTY1) = 0;
		(PINY1 => POUTY1) = 0;
		(CINX  => POUTY1) = 0;
		(CINY2 => COUTY2) = 0;
	endspecify
`endif
endmodule


module C_MULTFb #(
	parameter [7:0] CPE_CFG = 8'b0
)(
	output COUTX, POUTX,
	output COUTY1, POUTY1,
	output COUTY2, POUTY2,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CLK, EN, SR,
	input  CINX, CINY1, CINY2,
	input  PINX, PINY1, PINY2,
	input  RAM_I1, RAM_I2
);

	assign COUTY1 = PINY1 ^ CINX;
	assign COUTY2 = CINY2;
	assign COUTX  = CINY2;
	assign POUTY1 = CINY1 ^ (PINY1 | CINX);

`ifdef USE_TIMING
	specify
		(CINY2 => COUTX) = 0;
		(PINY1 => COUTY1) = 0;
		(CINX  => COUTY1) = 0;
		(CINY1 => POUTY1) = 0;
		(PINY1 => POUTY1) = 0;
		(CINX  => POUTY1) = 0;
		(CINY2 => COUTY2) = 0;
	endspecify
`endif
endmodule


module C_O_O1 #(
	parameter CPE_CFG = 0
)(
	output COMP_OUT,
	input  COMB1, COMB2
);
	assign COMP_OUT = COMB1;

`ifdef USE_TIMING
	specify
		(COMB1 => COMP_OUT) = 0;
	endspecify
`endif
endmodule


module C_O_O2 #(
	parameter CPE_CFG = 0
)(
	output COMP_OUT,
	input  COMB1, COMB2
);
	assign COMP_OUT = COMB2;

`ifdef USE_TIMING
	specify
		(COMB2 => COMP_OUT) = 0;
	endspecify
`endif
endmodule


module C_O_0 #(
	parameter CPE_CFG = 0
)(
	output COMP_OUT,
	input  COMB1, COMB2
);
	assign COMP_OUT = 1'b0;
endmodule


module C_D #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	wire CP_i, EN_i, SR_i, D_i;
	reg  q_i = CPE_CFG[8];

	assign D_i  = D_IN;
	assign SR_i = ~SR; // reset
	assign CP_i = CPE_CFG[4] ? CINY2 : CLK; // C_CLKSEL
	assign EN_i  = CPE_CFG[5] ? PINY2 : EN;  // C_ENSEL

	assign OUT = q_i;
	assign RAM_O = CPE_CFG[7] ? RAM_I : q_i;

	always @(posedge CP_i or posedge SR_i)
	begin
		if (SR_i) begin
			q_i <= 1'b0;
		end
		else if (EN_i) begin
			q_i <= D_i;
		end
	end

`ifdef USE_TIMING
	reg notifier;
	specify
		(CLK => OUT) = 0;
		(CINY2 => OUT) = 0;
		(SR => OUT) = 0;
`ifdef USE_TIMINGCHECKS
		// clock via CLK
		$period (posedge CLK &&& EN, 0, notifier);
		$width(posedge CLK &&& EN, 0, 0, notifier);
		$width(negedge CLK &&& EN, 0, 0, notifier);
		$width(posedge SR, 0, 0, notifier);
		$width(negedge SR, 0, 0, notifier);
		$recrem(posedge SR, posedge CLK, 0, 0, notifier,,, SR_i, CP_i);
		$setuphold(posedge CLK, posedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, negedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, posedge EN, 0, 0, notifier,,, CP_i, EN_i);
		$setuphold(posedge CLK, negedge EN, 0, 0, notifier,,, CP_i, EN_i);
		// clock via CINY2
		//$period (posedge CINY2 &&& EN, 0, notifier);
		//$width(posedge CINY2 &&& EN, 0, 0, notifier);
		//$width(negedge CINY2 &&& EN, 0, 0, notifier);
		//$width(posedge SR, 0, 0, notifier);
		//$width(negedge SR, 0, 0, notifier);
		//$recrem(posedge SR, posedge CINY2, 0, 0, notifier,,, SR_i, CP_i);
		//$setuphold(posedge CINY2, posedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		//$setuphold(posedge CINY2, negedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		//$setuphold(posedge CINY2, posedge EN, 0, 0, notifier,,, CP_i, EN_i);
		//$setuphold(posedge CINY2, negedge EN, 0, 0, notifier,,, CP_i, EN_i);
`endif
	endspecify
`endif
endmodule


module C_DST #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	wire CP_i, EN_i, SR_i, D_i;
	reg  q_i = CPE_CFG[8];

	assign D_i  = D_IN;
	assign SR_i = ~SR; // set
	assign CP_i = CPE_CFG[4] ? CINY2 : CLK; // C_CLKSEL
	assign EN_i  = CPE_CFG[5] ? PINY2 : EN;  // C_ENSEL

	assign OUT = q_i;
	assign RAM_O = CPE_CFG[7] ? RAM_I : q_i;

	always @(posedge CP_i or posedge SR_i)
	begin
		if (SR_i) begin
			q_i <= 1'b1;
		end
		else if (EN_i) begin
			q_i <= D_i;
		end
	end

`ifdef USE_TIMING
	reg notifier;
	specify
		(CLK => OUT) = 0;
		(CINY2 => OUT) = 0;
		(SR => OUT) = 0;
`ifdef USE_TIMINGCHECKS
		$period (posedge CLK &&& EN, 0, notifier);
		$width(posedge CLK &&& EN, 0, 0, notifier);
		$width(negedge CLK &&& EN, 0, 0, notifier);
		$width(posedge SR, 0, 0, notifier);
		$width(negedge SR, 0, 0, notifier);
		$recrem(posedge SR, posedge CLK, 0, 0, notifier,,, SR_i, CP_i);
		$setuphold(posedge CLK, posedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, negedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, posedge EN, 0, 0, notifier,,, CP_i, EN_i);
`endif
	endspecify
`endif
endmodule


module C_DRS #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR, // EN is SET, SR is RST
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	wire CP_i, EN_i, SR_i, D_i;
	reg  q_i = CPE_CFG[9];

	assign D_i  = D_IN;
	assign SR_i = ~SR; // reset
	assign CP_i = CPE_CFG[4] ? CINY2 : CLK; // C_CLKSEL
	assign EN_i = CPE_CFG[5] ? PINY2 : EN;  // C_ENSEL // set

	assign OUT = q_i;
	assign RAM_O = CPE_CFG[7] ? RAM_I : q_i; // C_ENSEL

	always @(posedge CP_i or posedge SR_i or posedge EN_i)
	begin
		if (EN_i) begin
			q_i <= 1'b1;
		end
		else if (SR_i) begin
			q_i <= 1'b0;
		end
		else begin
			q_i <= D_i;
		end
	end

`ifdef USE_TIMING
	reg notifier;
	specify
		(CLK => OUT) = 0;
		(CINY2 => OUT) = 0;
		(SR => OUT) = 0;
`ifdef USE_TIMINGCHECKS
		$period (posedge CLK &&& EN, 0, notifier);
		$width(posedge CLK &&& EN, 0, 0, notifier);
		$width(negedge CLK &&& EN, 0, 0, notifier);
		$width(posedge SR, 0, 0, notifier);
		$width(negedge SR, 0, 0, notifier);
		$width(negedge EN, 0, 0, notifier);
		$recrem(posedge SR, posedge CLK, 0, 0, notifier,,, SR_i, CP_i);
		$recrem(posedge EN, posedge CLK, 0, 0, notifier,,, EN_i, CP_i);
		$setuphold(posedge CLK, posedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, negedge D_IN, 0, 0, notifier,,, CP_i, D_i);
		$setuphold(posedge CLK, posedge EN, 0, 0, notifier,,, CP_i, EN_i);
`endif
	endspecify
`endif
endmodule


module C_CPlines #(
	parameter [18:0] CPE_CFG = 19'b0
)(
	output RAM_O1, RAM_O2,
	output COUTX, POUTX,
	output COUTY1, POUTY1,
	output COUTY2, POUTY2,
	input  OUT1, OUT2, COMP_OUT,
	input  CINX, CINY1, CINY2,
	input  PINX, PINY1, PINY2,
	input  RAM_I1, RAM_I2
);

	// Decode
	wire C_SELX  = CPE_CFG[6];
	wire C_SELY1 = CPE_CFG[7];
	wire C_SELY2 = CPE_CFG[8];
	wire C_SEL_C = CPE_CFG[9];
	wire C_SEL_P = CPE_CFG[10];
	wire C_Y12   = CPE_CFG[11];
	wire C_CX_I  = CPE_CFG[12];
	wire C_CY1_I = CPE_CFG[13];
	wire C_CY2_I = CPE_CFG[14];
	wire C_PX_I  = CPE_CFG[15];
	wire C_PY1_I = CPE_CFG[16];
	wire C_PY2_I = CPE_CFG[17];

	wire CIY12 = C_Y12 ? CINY2 : CINY1;
	wire PIY12 = C_Y12 ? PINY2 : PINY1;

	wire CX_VAL  = C_SEL_C ? (C_SELX ? CIY12 : COMP_OUT) : (C_SELX  ? OUT2 : OUT1);
	wire PX_VAL  = C_SEL_P ? (C_SELX ? PIY12 : COMP_OUT) : (C_SELX  ? OUT1 : OUT2);
	wire CY1_VAL = C_SEL_C ? (C_SELY1 ? CINX : COMP_OUT) : (C_SELY1 ? OUT1 : OUT2);
	wire PY1_VAL = C_SEL_P ? (C_SELY1 ? PINX : COMP_OUT) : (C_SELY1 ? OUT2 : OUT1);
	wire CY2_VAL = C_SEL_C ? (C_SELY2 ? CINX : COMP_OUT) : (C_SELY2 ? OUT2 : OUT1);
	wire PY2_VAL = C_SEL_P ? (C_SELY2 ? PINX : COMP_OUT) : (C_SELY2 ? OUT1 : OUT2);

	assign RAM_O1 = OUT1;
	assign RAM_O2 = OUT2;
	assign COUTX  = C_CX_I  ? CX_VAL  : CINX;
	assign COUTY1 = C_CY1_I ? CY1_VAL : CINY1;
	assign COUTY2 = C_CY2_I ? CY2_VAL : CINY2;
	assign POUTX  = C_PX_I  ? PX_VAL  : PINX;
	assign POUTY1 = C_PY1_I ? PY1_VAL : PINY1;
	assign POUTY2 = C_PY2_I ? PY2_VAL : PINY2;

`ifdef USE_TIMING
	specify
		(OUT1  => RAM_O1) = 0;
		(OUT2  => RAM_O2) = 0;
		(CINX  => COUTX) = 0;
		(CINY1 => COUTX) = 0;
		(CINY2 => COUTX) = 0;
		(COMP_OUT  => COUTX) = 0;
		(OUT1  => COUTX) = 0;
		(OUT2  => COUTX) = 0;
		(CINX  => COUTY1) = 0;
		(CINY1 => COUTY1) = 0;
		(COMP_OUT  => COUTY1) = 0;
		(OUT1  => COUTY1) = 0;
		(OUT2  => COUTY1) = 0;
		(CINX  => COUTY2) = 0;
		(CINY2 => COUTY2) = 0;
		(COMP_OUT  => COUTY2) = 0;
		(OUT1  => COUTY2) = 0;
		(OUT2  => COUTY2) = 0;
		(PINX  => POUTX) = 0;
		(PINY1 => POUTX) = 0;
		(PINY2 => POUTX) = 0;
		(COMP_OUT  => POUTX) = 0;
		(OUT1  => POUTX) = 0;
		(OUT2  => POUTX) = 0;
		(PINX  => POUTY1) = 0;
		(PINY1 => POUTY1) = 0;
		(COMP_OUT  => POUTY1) = 0;
		(OUT1  => POUTY1) = 0;
		(OUT2  => POUTY1) = 0;
		(PINX  => POUTY2) = 0;
		(PINY2 => POUTY2) = 0;
		(COMP_OUT  => POUTY2) = 0;
		(OUT1  => POUTY2) = 0;
		(OUT2  => POUTY2) = 0;
	endspecify
`endif
endmodule


module C_Route1 #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	assign OUT = CPE_CFG[8] ? ~CINY1 : CINY1;

`ifdef USE_TIMING
	specify
		(CINY1 => OUT) = 0;
	endspecify
`endif
endmodule


module C_Route2 #(
	parameter [8:0] CPE_CFG = 9'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	assign OUT = CPE_CFG[8] ? ~CINY1 : CINY1;
endmodule


module C_CP_route #(
	parameter [6:0] CPE_CFG = 7'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8,
	input  CINX, CINY1,
	input  PINX, PINY1
);
	// blackbox
endmodule


module C_Bridge #(
	parameter [8:0] CPE_CFG = 8'b0
)(
	output OUT,
	input  IN1, IN2, IN3, IN4,
	input  IN5, IN6, IN7, IN8
);
	wire [8:0] cpe_i;

	assign cpe_i[1] = IN1;
	assign cpe_i[2] = IN2;
	assign cpe_i[3] = IN3;
	assign cpe_i[4] = IN4;
	assign cpe_i[5] = IN5;
	assign cpe_i[6] = IN6;
	assign cpe_i[7] = IN7;
	assign cpe_i[8] = IN8;

	assign OUT = |cpe_i[8:1];

`ifdef USE_TIMING
	specify
		(IN1 => OUT) = 0;
		(IN2 => OUT) = 0;
		(IN3 => OUT) = 0;
		(IN4 => OUT) = 0;
		(IN5 => OUT) = 0;
		(IN6 => OUT) = 0;
		(IN7 => OUT) = 0;
		(IN8 => OUT) = 0;
	endspecify
`endif
endmodule


module C_RAM_I1 #(
	parameter [8:0] CPE_CFG = 8'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	assign OUT = RAM_I;
endmodule


module C_RAM_I2 #(
	parameter [8:0] CPE_CFG = 8'b0
)(
	output OUT, RAM_O,
	input  CLK, EN, SR,
	input  CINY2, PINY2,
	input  RAM_I, CP_O, D_IN
);
	assign OUT = RAM_I;
endmodule


`ifdef USE_PLL
module CC_PLL #(
	parameter PLL_CFG = "",
	parameter REF_CLK = "", // e.g. "10.0"
	parameter OUT_CLK = "", // e.g. "50.0"
	parameter PERF_MD = "", // LOWPOWER, ECONOMY, SPEED
	parameter LOCK_REQ = 0,
	parameter LOW_JITTER = 1,
	parameter CI_FILTER_CONST = 2,
	parameter CP_FILTER_CONST = 4
)(
	input  CLK_REF, CLK_FEEDBACK, USR_CLK_REF,
	input  USR_LOCKED_STDY_RST, USR_SET_SEL,
	output USR_PLL_LOCKED_STDY, USR_PLL_LOCKED,
	output CLK270, CLK180, CLK90, CLK0, CLK_REF_OUT
);

	reg r_user_pll_locked_stdy = 0;
	reg r_user_pll_locked = 0;
	reg r_clk270 = 0;
	reg r_clk180 = 0;
	reg r_clk90 = 0;
	reg r_clk0 = 0;
	reg r_clk_ref_out;
	reg r_init = 0;

	assign USR_PLL_LOCKED_STDY = r_user_pll_locked_stdy;
	assign USR_PLL_LOCKED      = r_user_pll_locked;
	assign CLK270              = r_clk270 & r_user_pll_locked;
	assign CLK180              = r_clk180 & r_user_pll_locked;
	assign CLK90               = r_clk90  & r_user_pll_locked;
	assign CLK0                = r_clk0   & r_user_pll_locked;
	assign CLK_REF_OUT         = CLK_REF | USR_CLK_REF;

	reg [31:0] clkcnt = 0;
	always @(CLK_REF or USR_CLK_REF)
	begin
		if (CLK_REF_OUT) begin
			r_init = 1;
		end
		if (clkcnt > 57) begin
			r_user_pll_locked = 1;
		end
		if ((clkcnt > 1) && (clkcnt % 2 == 0)) begin
			r_clk0 = ~r_clk0;
		end
		if ((clkcnt > 2) && ((clkcnt-1) % 2 == 0)) begin
			r_clk90 = ~r_clk90;
		end
		if ((clkcnt > 3) && ((clkcnt-2) % 2 == 0)) begin
			r_clk180 = ~r_clk180;
		end
		if ((clkcnt > 4) && ((clkcnt-3) % 2 == 0)) begin
			r_clk270 = ~r_clk270;
		end
		clkcnt = r_init ? clkcnt + 1 : 0;
	end

`ifdef USE_TIMING
	specify
		(CLK_REF => CLK270) = 0;
		(CLK_REF => CLK180) = 0;
		(CLK_REF => CLK90) = 0;
		(CLK_REF => CLK0) = 0;
	endspecify
`endif
endmodule
`endif

module CLKIN #(
	parameter [31:0] CLKIN_CFG = 32'h0
)(
	output PCLK0, PCLK1, PCLK2, PCLK3,
	input  CLK0, CLK1, CLK2, CLK3,
	input  SER_CLK, SPI_CLK, JTAG_CLK
);

	wire C4_7_NC, C4_6_NC, C4_5_NC, C4_4_NC, C4_3, C4_2, C4_1, C4_0;
	wire C3_7_NC, C3_6_NC, C3_5_NC, C3_4_NC, C3_3, C3_2, C3_1, C3_0;
	wire C2_7_NC, C2_6_NC, C2_5_NC, C2_4_NC, C2_3, C2_2, C2_1, C2_0;
	wire C1_7_NC, C1_6_NC, C1_5_NC, C1_4_NC, C1_3, C1_2, C1_1, C1_0;

	assign {C4_7_NC, C4_6_NC, C4_5_NC, C4_4_NC, C4_3, C4_2, C4_1, C4_0} = CLKIN_CFG[31:24];
	assign {C3_7_NC, C3_6_NC, C3_5_NC, C3_4_NC, C3_3, C3_2, C3_1, C3_0} = CLKIN_CFG[23:16];
	assign {C2_7_NC, C2_6_NC, C2_5_NC, C2_4_NC, C2_3, C2_2, C2_1, C2_0} = CLKIN_CFG[15:8];
	assign {C1_7_NC, C1_6_NC, C1_5_NC, C1_4_NC, C1_3, C1_2, C1_1, C1_0} = CLKIN_CFG[7:0];

	wire CLK1MX = C1_2 ? (C1_1 ? (C1_0 ? 1'b0 : JTAG_CLK) : (C1_0 ? SPI_CLK : SER_CLK)) : (C1_1 ? (C1_0 ? CLK3 : CLK2) : (C1_0 ? CLK1 : CLK0));
	wire CLK2MX = C2_2 ? (C1_1 ? (C2_0 ? 1'b0 : JTAG_CLK) : (C2_0 ? SPI_CLK : SER_CLK)) : (C2_1 ? (C2_0 ? CLK3 : CLK2) : (C2_0 ? CLK1 : CLK0));
	wire CLK3MX = C3_2 ? (C1_1 ? (C3_0 ? 1'b0 : JTAG_CLK) : (C3_0 ? SPI_CLK : SER_CLK)) : (C3_1 ? (C3_0 ? CLK3 : CLK2) : (C3_0 ? CLK1 : CLK0));
	wire CLK4MX = C4_2 ? (C1_1 ? (C4_0 ? 1'b0 : JTAG_CLK) : (C4_0 ? SPI_CLK : SER_CLK)) : (C4_1 ? (C4_0 ? CLK3 : CLK2) : (C4_0 ? CLK1 : CLK0));

	assign PCLK0 = CLK1MX ^ C1_3;
	assign PCLK1 = CLK2MX ^ C2_3;
	assign PCLK2 = CLK3MX ^ C3_3;
	assign PCLK3 = CLK4MX ^ C3_3;

`ifdef USE_TIMING
	specify
		(CLK0 => PCLK0) = 0;
		(CLK0 => PCLK1) = 0;
		(CLK0 => PCLK2) = 0;
		(CLK0 => PCLK3) = 0;
		(CLK1 => PCLK0) = 0;
		(CLK1 => PCLK1) = 0;
		(CLK1 => PCLK2) = 0;
		(CLK1 => PCLK3) = 0;
		(CLK2 => PCLK0) = 0;
		(CLK2 => PCLK1) = 0;
		(CLK2 => PCLK2) = 0;
		(CLK2 => PCLK3) = 0;
		(CLK3 => PCLK0) = 0;
		(CLK3 => PCLK1) = 0;
		(CLK3 => PCLK2) = 0;
		(CLK3 => PCLK3) = 0;
		(JTAG_CLK => PCLK0) = 0;
		(JTAG_CLK => PCLK1) = 0;
		(JTAG_CLK => PCLK2) = 0;
		(JTAG_CLK => PCLK3) = 0;
		(SER_CLK => PCLK0) = 0;
		(SER_CLK => PCLK1) = 0;
		(SER_CLK => PCLK2) = 0;
		(SER_CLK => PCLK3) = 0;
		(SPI_CLK => PCLK0) = 0;
		(SPI_CLK => PCLK1) = 0;
		(SPI_CLK => PCLK2) = 0;
		(SPI_CLK => PCLK3) = 0;
	endspecify
`endif
endmodule


module GLBOUT #(
	parameter [63:0] GLBOUT_CFG = 64'h0
)(
	output GLB0, GLB1, GLB2, GLB3,
	output CLK_FB0, CLK_FB1, CLK_FB2, CLK_FB3,
	input  CLK0_0, CLK0_90, CLK0_180, CLK0_270, CLK0_BYP,
	input  CLK1_0, CLK1_90, CLK1_180, CLK1_270, CLK1_BYP,
	input  CLK2_0, CLK2_90, CLK2_180, CLK2_270, CLK2_BYP,
	input  CLK3_0, CLK3_90, CLK3_180, CLK3_270, CLK3_BYP,
	input  USR_GLB0, USR_GLB1, USR_GLB2, USR_GLB3,
	input  USR_FB0, USR_FB1, USR_FB2, USR_FB3
);
	wire C_63,C_62,C_61,C_60,C_59,C_58,C_57,C_56;
	wire C_55,C_54,C_53,C_52,C_51,C_50,C_49,C_48;
	wire C_47,C_46,C_45,C_44,C_43,C_42,C_41,C_40;
	wire C_39,C_38,C_37,C_36,C_35,C_34,C_33,C_32;
	wire C_31,C_30,C_29,C_28,C_27,C_26,C_25,C_24;
	wire C_23,C_22,C_21,C_20,C_19,C_18,C_17,C_16;
	wire C_15,C_14,C_13,C_12,C_11,C_10, C_9, C_8;
	wire  C_7, C_6, C_5, C_4, C_3, C_2, C_1, C_0;

	assign {C_63,C_62,C_61,C_60,C_59,C_58,C_57,C_56} = GLBOUT_CFG[63:56];
	assign {C_55,C_54,C_53,C_52,C_51,C_50,C_49,C_48} = GLBOUT_CFG[55:48];
	assign {C_47,C_46,C_45,C_44,C_43,C_42,C_41,C_40} = GLBOUT_CFG[47:40];
	assign {C_39,C_38,C_37,C_36,C_35,C_34,C_33,C_32} = GLBOUT_CFG[39:32];
	assign {C_31,C_30,C_29,C_28,C_27,C_26,C_25,C_24} = GLBOUT_CFG[31:24];
	assign {C_23,C_22,C_21,C_20,C_19,C_18,C_17,C_16} = GLBOUT_CFG[23:16];
	assign {C_15,C_14,C_13,C_12,C_11,C_10, C_9, C_8} = GLBOUT_CFG[15: 8];
	assign { C_7, C_6, C_5, C_4, C_3, C_2, C_1, C_0} = GLBOUT_CFG[ 7: 0];

	wire CLK1MXO =  C_2 ? ( C_1 ? ( C_0 ? CLK0_270 : CLK0_180) : ( C_0 ? CLK0_90 : CLK0_0)) : ( C_1 ? ( C_0 ? CLK3_0 : CLK2_0) : ( C_0 ? CLK1_0 : CLK0_BYP));
	wire CLK2MXO = C_18 ? (C_17 ? (C_16 ? CLK1_270 : CLK1_180) : (C_16 ? CLK1_90 : CLK1_0)) : (C_17 ? (C_16 ? CLK3_0 : CLK2_0) : (C_16 ? CLK1_0 : CLK1_BYP));
	wire CLK3MXO = C_34 ? (C_33 ? (C_32 ? CLK2_270 : CLK2_180) : (C_32 ? CLK2_90 : CLK2_0)) : (C_33 ? (C_32 ? CLK3_0 : CLK2_0) : (C_32 ? CLK1_0 : CLK2_BYP));
	wire CLK4MXO = C_50 ? (C_49 ? (C_48 ? CLK3_270 : CLK3_180) : (C_48 ? CLK3_90 : CLK3_0)) : (C_49 ? (C_48 ? CLK3_0 : CLK2_0) : (C_48 ? CLK1_0 : CLK3_BYP));

	assign GLB0 =  C_4 ? ( C_3 ? USR_GLB0 : CLK1MXO) : 1'b0;
	assign GLB1 = C_20 ? (C_19 ? USR_GLB1 : CLK2MXO) : 1'b0;
	assign GLB2 = C_36 ? (C_35 ? USR_GLB2 : CLK3MXO) : 1'b0;
	assign GLB3 = C_52 ? (C_51 ? USR_GLB3 : CLK4MXO) : 1'b0;

	wire CLK1MXI =  C_9 ? ( C_8 ? GLB3 : GLB2) : ( C_8 ? GLB1 : GLB0);
	wire CLK2MXI = C_25 ? (C_24 ? GLB3 : GLB2) : (C_24 ? GLB1 : GLB0);
	wire CLK3MXI = C_41 ? (C_40 ? GLB3 : GLB2) : (C_40 ? GLB1 : GLB0);
	wire CLK4MXI = C_57 ? (C_56 ? GLB3 : GLB2) : (C_56 ? GLB1 : GLB0);

	assign CLK_FB0 = C_10 ? USR_FB0 : CLK1MXI;
	assign CLK_FB1 = C_26 ? USR_FB1 : CLK2MXI;
	assign CLK_FB2 = C_42 ? USR_FB2 : CLK3MXI;
	assign CLK_FB3 = C_58 ? USR_FB3 : CLK4MXI;

`ifdef USE_TIMING
	specify
		(CLK0_0 => GLB0) = 0;
		(CLK0_90 => GLB0) = 0;
		(CLK0_90 => GLB1) = 0;
		(CLK0_180 => GLB0) = 0;
		(CLK0_180 => GLB2) = 0;
		(CLK0_270 => GLB0) = 0;
		(CLK0_270 => GLB3) = 0;
		(CLK0_BYP => GLB0) = 0;
		(CLK1_0 => GLB0) = 0;
		(CLK1_0 => GLB1) = 0;
		(CLK1_90 => GLB1) = 0;
		(CLK1_180 => GLB1) = 0;
		(CLK1_180 => GLB2) = 0;
		(CLK1_270 => GLB1) = 0;
		(CLK1_270 => GLB3) = 0;
		(CLK1_BYP => GLB1) = 0;
		(CLK2_0 => GLB0) = 0;
		(CLK2_0 => GLB2) = 0;
		(CLK2_90 => GLB1) = 0;
		(CLK2_90 => GLB2) = 0;
		(CLK2_180 => GLB2) = 0;
		(CLK2_270 => GLB2) = 0;
		(CLK2_270 => GLB3) = 0;
		(CLK2_BYP => GLB2) = 0;
		(CLK3_0 => GLB0) = 0;
		(CLK3_0 => GLB3) = 0;
		(CLK3_90 => GLB1) = 0;
		(CLK3_90 => GLB3) = 0;
		(CLK3_180 => GLB2) = 0;
		(CLK3_180 => GLB3) = 0;
		(CLK3_270 => GLB3) = 0;
		(CLK3_BYP => GLB3) = 0;
		(USR_GLB0 => GLB0) = 0;
		(USR_GLB1 => GLB1) = 0;
		(USR_GLB2 => GLB2) = 0;
		(USR_GLB3 => GLB3) = 0;
		(USR_FB0 => CLK_FB0) = 0;
		(USR_FB1 => CLK_FB1) = 0;
		(USR_FB2 => CLK_FB2) = 0;
		(USR_FB3 => CLK_FB3) = 0;
	endspecify
`endif
endmodule

`ifdef USE_RAM
module FPGA_RAM  ( DOA, DOAX, DOB, DOBX,
	ECC1B_ERRA,
	ECC1B_ERRB,
	ECC2B_ERRA,
	ECC2B_ERRB,
	CLKA,
	CLKB,
	ENA,
	ENB,
	GLWEA,
	GLWEB,
	ADDRA0,
	ADDRA1,
	ADDRA0X,
	ADDRA1X,
	ADDRB0,
	ADDRB0X,
	ADDRB1,
	ADDRB1X,
	C_ADDRA,
	C_ADDRB,
	DIA,
	DIB,
	WEA,
	WEB,

	F_RSTN,
	F_FULL,
	F_EMPTY,
	F_AL_FULL,
	F_AL_EMPTY,
	FRD_ERR,
	FWR_ERR,
	FRD_ADDR,
	FWR_ADDR,
	FRD_ADDRX,
	FWR_ADDRX,

	FORW_CAS_WRAO,
	FORW_CAS_WRBO,
	FORW_CAS_BMAO,
	FORW_CAS_BMBO,
	FORW_CAS_RDAO,
	FORW_CAS_RDBO,

	FORW_UADDRAO,
	FORW_LADDRAO,
	FORW_UADDRBO,
	FORW_LADDRBO,

	FORW_UA0CLKO, FORW_UA0ENO, FORW_UA0WEO, FORW_LA0CLKO, FORW_LA0ENO, FORW_LA0WEO,
	FORW_UA1CLKO, FORW_UA1ENO, FORW_UA1WEO, FORW_LA1CLKO, FORW_LA1ENO, FORW_LA1WEO,
	FORW_UB0CLKO, FORW_UB0ENO, FORW_UB0WEO, FORW_LB0CLKO, FORW_LB0ENO, FORW_LB0WEO,
	FORW_UB1CLKO, FORW_UB1ENO, FORW_UB1WEO, FORW_LB1CLKO, FORW_LB1ENO, FORW_LB1WEO,

	CLOCKA, CLOCKB,
	CLOCK1, CLOCK2, CLOCK3, CLOCK4,

	FORW_CAS_WRAI, FORW_CAS_WRBI, FORW_CAS_BMAI, FORW_CAS_BMBI,

	FORW_CAS_RDAI, FORW_CAS_RDBI,
	FORW_LADDRAI, FORW_UADDRAI, FORW_LADDRBI, FORW_UADDRBI,

	FORW_LA0CLKI, FORW_LA0ENI, FORW_LA0WEI, FORW_UA0CLKI, FORW_UA0ENI, FORW_UA0WEI,
	FORW_LA1CLKI, FORW_LA1ENI, FORW_LA1WEI, FORW_UA1CLKI, FORW_UA1ENI, FORW_UA1WEI,
	FORW_LB0CLKI, FORW_LB0ENI, FORW_LB0WEI, FORW_UB0CLKI, FORW_UB0ENI, FORW_UB0WEI,
	FORW_LB1CLKI, FORW_LB1ENI, FORW_LB1WEI, FORW_UB1CLKI, FORW_UB1ENI, FORW_UB1WEI
	);

	parameter RAM_CFG = 216'h00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00;

	parameter INIT_00 = 320'hx; parameter INIT_01 = 320'hx; parameter INIT_02 = 320'hx; parameter INIT_03 = 320'hx;
	parameter INIT_04 = 320'hx; parameter INIT_05 = 320'hx; parameter INIT_06 = 320'hx; parameter INIT_07 = 320'hx;
	parameter INIT_08 = 320'hx; parameter INIT_09 = 320'hx; parameter INIT_0A = 320'hx; parameter INIT_0B = 320'hx;
	parameter INIT_0C = 320'hx; parameter INIT_0D = 320'hx; parameter INIT_0E = 320'hx; parameter INIT_0F = 320'hx;
	parameter INIT_10 = 320'hx; parameter INIT_11 = 320'hx; parameter INIT_12 = 320'hx; parameter INIT_13 = 320'hx;
	parameter INIT_14 = 320'hx; parameter INIT_15 = 320'hx; parameter INIT_16 = 320'hx; parameter INIT_17 = 320'hx;
	parameter INIT_18 = 320'hx; parameter INIT_19 = 320'hx; parameter INIT_1A = 320'hx; parameter INIT_1B = 320'hx;
	parameter INIT_1C = 320'hx; parameter INIT_1D = 320'hx; parameter INIT_1E = 320'hx; parameter INIT_1F = 320'hx;
	parameter INIT_20 = 320'hx; parameter INIT_21 = 320'hx; parameter INIT_22 = 320'hx; parameter INIT_23 = 320'hx;
	parameter INIT_24 = 320'hx; parameter INIT_25 = 320'hx; parameter INIT_26 = 320'hx; parameter INIT_27 = 320'hx;
	parameter INIT_28 = 320'hx; parameter INIT_29 = 320'hx; parameter INIT_2A = 320'hx; parameter INIT_2B = 320'hx;
	parameter INIT_2C = 320'hx; parameter INIT_2D = 320'hx; parameter INIT_2E = 320'hx; parameter INIT_2F = 320'hx;
	parameter INIT_30 = 320'hx; parameter INIT_31 = 320'hx; parameter INIT_32 = 320'hx; parameter INIT_33 = 320'hx;
	parameter INIT_34 = 320'hx; parameter INIT_35 = 320'hx; parameter INIT_36 = 320'hx; parameter INIT_37 = 320'hx;
	parameter INIT_38 = 320'hx; parameter INIT_39 = 320'hx; parameter INIT_3A = 320'hx; parameter INIT_3B = 320'hx;
	parameter INIT_3C = 320'hx; parameter INIT_3D = 320'hx; parameter INIT_3E = 320'hx; parameter INIT_3F = 320'hx;
	parameter INIT_40 = 320'hx; parameter INIT_41 = 320'hx; parameter INIT_42 = 320'hx; parameter INIT_43 = 320'hx;
	parameter INIT_44 = 320'hx; parameter INIT_45 = 320'hx; parameter INIT_46 = 320'hx; parameter INIT_47 = 320'hx;
	parameter INIT_48 = 320'hx; parameter INIT_49 = 320'hx; parameter INIT_4A = 320'hx; parameter INIT_4B = 320'hx;
	parameter INIT_4C = 320'hx; parameter INIT_4D = 320'hx; parameter INIT_4E = 320'hx; parameter INIT_4F = 320'hx;
	parameter INIT_50 = 320'hx; parameter INIT_51 = 320'hx; parameter INIT_52 = 320'hx; parameter INIT_53 = 320'hx;
	parameter INIT_54 = 320'hx; parameter INIT_55 = 320'hx; parameter INIT_56 = 320'hx; parameter INIT_57 = 320'hx;
	parameter INIT_58 = 320'hx; parameter INIT_59 = 320'hx; parameter INIT_5A = 320'hx; parameter INIT_5B = 320'hx;
	parameter INIT_5C = 320'hx; parameter INIT_5D = 320'hx; parameter INIT_5E = 320'hx; parameter INIT_5F = 320'hx;
	parameter INIT_60 = 320'hx; parameter INIT_61 = 320'hx; parameter INIT_62 = 320'hx; parameter INIT_63 = 320'hx;
	parameter INIT_64 = 320'hx; parameter INIT_65 = 320'hx; parameter INIT_66 = 320'hx; parameter INIT_67 = 320'hx;
	parameter INIT_68 = 320'hx; parameter INIT_69 = 320'hx; parameter INIT_6A = 320'hx; parameter INIT_6B = 320'hx;
	parameter INIT_6C = 320'hx; parameter INIT_6D = 320'hx; parameter INIT_6E = 320'hx; parameter INIT_6F = 320'hx;
	parameter INIT_70 = 320'hx; parameter INIT_71 = 320'hx; parameter INIT_72 = 320'hx; parameter INIT_73 = 320'hx;
	parameter INIT_74 = 320'hx; parameter INIT_75 = 320'hx; parameter INIT_76 = 320'hx; parameter INIT_77 = 320'hx;
	parameter INIT_78 = 320'hx; parameter INIT_79 = 320'hx; parameter INIT_7A = 320'hx; parameter INIT_7B = 320'hx;
	parameter INIT_7C = 320'hx; parameter INIT_7D = 320'hx; parameter INIT_7E = 320'hx; parameter INIT_7F = 320'hx;

	output[39:0] DOA, DOAX, DOB,DOBX;
	output [3:0] ECC1B_ERRA, ECC1B_ERRB, ECC2B_ERRA, ECC2B_ERRB;
	output FORW_CAS_WRAO, FORW_CAS_WRBO, FORW_CAS_BMAO, FORW_CAS_BMBO, FORW_CAS_RDAO, FORW_CAS_RDBO;
	output [15:0] FORW_UADDRAO, FORW_LADDRAO, FORW_UADDRBO, FORW_LADDRBO;
	output FORW_UA0CLKO, FORW_UA0ENO, FORW_UA0WEO, FORW_LA0CLKO, FORW_LA0ENO, FORW_LA0WEO;
	output FORW_UA1CLKO, FORW_UA1ENO, FORW_UA1WEO, FORW_LA1CLKO, FORW_LA1ENO, FORW_LA1WEO;
	output FORW_UB0CLKO, FORW_UB0ENO, FORW_UB0WEO, FORW_LB0CLKO, FORW_LB0ENO, FORW_LB0WEO;
	output FORW_UB1CLKO, FORW_UB1ENO, FORW_UB1WEO, FORW_LB1CLKO, FORW_LB1ENO, FORW_LB1WEO;

	output [3:0] CLOCKA;
	output [3:0] CLOCKB;

	input CLOCK1, CLOCK2, CLOCK3, CLOCK4;
	input FORW_CAS_WRAI, FORW_CAS_WRBI, FORW_CAS_BMAI, FORW_CAS_BMBI, FORW_CAS_RDAI, FORW_CAS_RDBI;
	input [15:0] FORW_LADDRAI, FORW_UADDRAI, FORW_LADDRBI, FORW_UADDRBI;

	input FORW_LA0CLKI, FORW_LA0ENI, FORW_LA0WEI, FORW_UA0CLKI, FORW_UA0ENI, FORW_UA0WEI;
	input FORW_LA1CLKI, FORW_LA1ENI, FORW_LA1WEI, FORW_UA1CLKI, FORW_UA1ENI, FORW_UA1WEI;
	input FORW_LB0CLKI, FORW_LB0ENI, FORW_LB0WEI, FORW_UB0CLKI, FORW_UB0ENI, FORW_UB0WEI;
	input FORW_LB1CLKI, FORW_LB1ENI, FORW_LB1WEI, FORW_UB1CLKI, FORW_UB1ENI, FORW_UB1WEI;

	input [3:0] CLKA,CLKB,ENA,ENB, GLWEA,GLWEB;
	input [15:0] ADDRA0,ADDRA1, ADDRA0X, ADDRA1X, ADDRB0,ADDRB1, ADDRB0X, ADDRB1X;
	input [39:0] DIA,DIB,WEA,WEB;
	input [7:0] C_ADDRA, C_ADDRB;

	input  F_RSTN;
	output [1:0] F_FULL;
	output [1:0] F_EMPTY;
	output [1:0] F_AL_FULL;
	output [1:0] F_AL_EMPTY;
	output [1:0] FRD_ERR;
	output [1:0] FWR_ERR;
	output [15:0] FRD_ADDR;
	output [15:0] FWR_ADDR;
	output [15:0] FRD_ADDRX;
	output [15:0] FWR_ADDRX;

	wire a0_clk1_in = CLKA[0];
	wire a0_clk2_in = CLKA[1];
	wire a1_clk1_in = CLKA[2];
	wire a1_clk2_in = CLKA[3];

	wire b0_clk1_in = CLKB[0];
	wire b0_clk2_in = CLKB[1];
	wire b1_clk1_in = CLKB[2];
	wire b1_clk2_in = CLKB[3];

	// forward_up
	wire forward_up_a0_en_in, forward_up_a1_en_in, forward_up_b0_en_in, forward_up_b1_en_in;
	wire forward_up_a0_we_in, forward_up_a1_we_in, forward_up_b0_we_in, forward_up_b1_we_in;
	wire forward_up_a0_clk_in, forward_up_a1_clk_in, forward_up_b0_clk_in, forward_up_b1_clk_in;
	// EN
	assign forward_up_a0_en_in = FORW_UA0ENI;
	assign forward_up_a1_en_in = FORW_UA1ENI;
	assign forward_up_b0_en_in = FORW_UB0ENI;
	assign forward_up_b1_en_in = FORW_UB1ENI;
	// WE
	assign forward_up_a0_we_in = FORW_UA0WEI;
	assign forward_up_a1_we_in = FORW_UA1WEI;
	assign forward_up_b0_we_in = FORW_UB0WEI;
	assign forward_up_b1_we_in = FORW_UB1WEI;
	// CLK
	assign forward_up_a0_clk_in = FORW_UA0CLKI;
	assign forward_up_a1_clk_in = FORW_UA1CLKI;
	assign forward_up_b0_clk_in = FORW_UB0CLKI;
	assign forward_up_b1_clk_in = FORW_UB1CLKI;

	// forward_low
	wire forward_low_a0_en_in, forward_low_a1_en_in,forward_low_b0_en_in, forward_low_b1_en_in;
	wire forward_low_a0_we_in, forward_low_a1_we_in, forward_low_b0_we_in, forward_low_b1_we_in;
	wire forward_low_a0_clk_in, forward_low_a1_clk_in, forward_low_b0_clk_in, forward_low_b1_clk_in;
	// EN
	assign forward_low_a0_en_in = FORW_LA0ENI;
	assign forward_low_a1_en_in = FORW_LA1ENI;
	assign forward_low_b0_en_in = FORW_LB0ENI;
	assign forward_low_b1_en_in = FORW_LB1ENI;
	// WE
	assign forward_low_a0_we_in = FORW_LA0WEI;
	assign forward_low_a1_we_in = FORW_LA1WEI;
	assign forward_low_b0_we_in = FORW_LB0WEI;
	assign forward_low_b1_we_in = FORW_LB1WEI;
	// CLK
	assign forward_low_a0_clk_in = FORW_LA0CLKI;
	assign forward_low_a1_clk_in = FORW_LA1CLKI;
	assign forward_low_b0_clk_in = FORW_LB0CLKI;
	assign forward_low_b1_clk_in = FORW_LB1CLKI;


	wire [7:0] cdyn_cfg_forward_a_addr, cdyn_cfg_forward_b_addr;
	assign cdyn_cfg_forward_a_addr = 8'b0;
	assign cdyn_cfg_forward_b_addr = 8'b0;

	wire [15:0] a0_addr1_in;
	assign a0_addr1_in = ADDRA0;

	wire [15:0] a1_addr1_in;
	assign a1_addr1_in = ADDRA1;


	wire [15:0] b0_addr1_in;
	assign b0_addr1_in = ADDRB0;

	wire [15:0] b1_addr1_in;
	assign b1_addr1_in = ADDRB1;


	wire [7:0] a0_addr2_in;
	assign a0_addr2_in = {ADDRA0X[14],ADDRA0X[12],ADDRA0X[11],ADDRA0X[9],ADDRA0X[7],ADDRA0X[5],ADDRA0X[3],ADDRA0X[1]};

	wire [7:0] a1_addr2_in;
	assign a1_addr2_in = {ADDRA1X[14],ADDRA1X[12],ADDRA1X[11],ADDRA1X[9],ADDRA1X[7],ADDRA1X[5],ADDRA1X[3],ADDRA1X[1]};

	wire [7:0] b0_addr2_in;
	assign b0_addr2_in = {ADDRB0X[15],ADDRB0X[13],ADDRB0X[10],ADDRB0X[8],ADDRB0X[6],ADDRB0X[4],ADDRB0X[2],ADDRB0X[0]};

	wire [7:0] b1_addr2_in;
	assign b1_addr2_in = {ADDRB1X[15],ADDRB1X[13],ADDRB1X[10],ADDRB1X[8],ADDRB1X[6],ADDRB1X[4],ADDRB1X[2],ADDRB1X[0]};

	wire [19:0] a0_wrdata_in;
	assign a0_wrdata_in = DIA[19:0];

	wire [19:0] a1_wrdata_in;
	assign a1_wrdata_in = DIA[39:20];

	wire [19:0] b0_wrdata_in;
	assign b0_wrdata_in = DIB[19:0];

	wire [19:0] b1_wrdata_in;
	assign b1_wrdata_in = DIB[39:20];

	wire [19:0] a0_bitmask_in;
	assign a0_bitmask_in = WEA[19:0];

	wire [19:0] a1_bitmask_in;
	assign a1_bitmask_in = WEA[39:20];

	wire [19:0] b0_bitmask_in;
	assign b0_bitmask_in = WEB[19:0];

	wire [19:0] b1_bitmask_in;
	assign b1_bitmask_in = WEB[39:20];

	wire [19:0] a0_rddata_out;
	assign DOA[19:0] = a0_rddata_out;
	assign DOAX[19:0] = a0_rddata_out;

	wire [19:0] a1_rddata_out;
	assign DOA[39:20] = a1_rddata_out;
	assign DOAX[39:20] = a1_rddata_out;

	wire [19:0] b0_rddata_out;
	assign DOB[19:0] = b0_rddata_out;
	assign DOBX[19:0] = b0_rddata_out;

	wire [19:0] b1_rddata_out;
	assign DOB[39:20] = b1_rddata_out;
	assign DOBX[39:20] = b1_rddata_out;

	wire a0_en1_in = ENA[0];
	wire a0_en2_in = ENA[1];
	wire a1_en1_in = ENA[2];
	wire a1_en2_in = ENA[3];

	wire a0_we1_in = GLWEA[0];
	wire a0_we2_in = GLWEA[1];
	wire a1_we1_in = GLWEA[2];
	wire a1_we2_in = GLWEA[3];

	wire b0_en1_in = ENB[0];
	wire b0_en2_in = ENB[1];
	wire b1_en1_in = ENB[2];
	wire b1_en2_in = ENB[3];

	wire b0_we1_in = GLWEB[0];
	wire b0_we2_in = GLWEB[1];
	wire b1_we1_in = GLWEB[2];
	wire b1_we2_in = GLWEB[3];

	wire [1:0] lo_left_ecc_single_error_flag_out;
	wire [1:0] up_left_ecc_single_error_flag_out;
	wire [1:0] lo_right_ecc_single_error_flag_out;
	wire [1:0] up_right_ecc_single_error_flag_out;

	wire [1:0] lo_left_ecc_double_error_flag_out;
	wire [1:0] up_left_ecc_double_error_flag_out;
	wire [1:0] lo_right_ecc_double_error_flag_out;
	wire [1:0] up_right_ecc_double_error_flag_out;

	assign ECC1B_ERRA[0] = lo_left_ecc_single_error_flag_out[0];
	assign ECC1B_ERRA[1] = up_left_ecc_single_error_flag_out[0];
	assign ECC1B_ERRA[2] = lo_right_ecc_single_error_flag_out[0];
	assign ECC1B_ERRA[3] = up_right_ecc_single_error_flag_out[0];

	assign ECC2B_ERRA[0] = lo_left_ecc_double_error_flag_out[0];
	assign ECC2B_ERRA[1] = up_left_ecc_double_error_flag_out[0];
	assign ECC2B_ERRA[2] = lo_right_ecc_double_error_flag_out[0];
	assign ECC2B_ERRA[3] = up_right_ecc_double_error_flag_out[0];

	assign ECC1B_ERRB[0] = lo_left_ecc_single_error_flag_out[1];
	assign ECC1B_ERRB[1] = up_left_ecc_single_error_flag_out[1];
	assign ECC1B_ERRB[2] = lo_right_ecc_single_error_flag_out[1];
	assign ECC1B_ERRB[3] = up_right_ecc_single_error_flag_out[1];

	assign ECC2B_ERRB[0] = lo_left_ecc_double_error_flag_out[1];
	assign ECC2B_ERRB[1] = up_left_ecc_double_error_flag_out[1];
	assign ECC2B_ERRB[2] = lo_right_ecc_double_error_flag_out[1];
	assign ECC2B_ERRB[3] = up_right_ecc_double_error_flag_out[1];

	// initialize memory arrays to 0
	integer i;

	dpsram_block_4x512x20
	i_dpsram_block
	(
	.testmode_i   (1'b0),
	.testmode_o   (),
	// Configuration interface
	.ram_cfg(RAM_CFG),
	.cfg_gx_i     (1'b0     ),
	.lo_y1CFG_GLOBAL_DEC_Y_i     (1'b0     ),
	.cfg_addr_i   (5'b0),
	.cfg_data_i   (8'b0),
	.cfg_set_all_i(1'b0),

	.cfg_gx_o     (),
	.cfg_addr_o   (),
	.cfg_data_o   (),
	.cfg_set_all_o(),

	.left_clock1_o(CLOCKA[0]),
	.left_clock2_o(CLOCKA[1]),
	.left_clock3_o(CLOCKA[2]),
	.left_clock4_o(CLOCKA[3]),

	.right_clock1_o(CLOCKB[0]),
	.right_clock2_o(CLOCKB[1]),
	.right_clock3_o(CLOCKB[2]),
	.right_clock4_o(CLOCKB[3]),


	//.cdyn_almost_empty_offset_i(cdyn_almost_empty_offset_in),
	//.cdyn_almost_full_offset_i (cdyn_almost_full_offset_in ),
	.cdyn_cfg_forward_a_addr_i (cdyn_cfg_forward_a_addr),
	.cdyn_cfg_forward_b_addr_i (cdyn_cfg_forward_b_addr),

	// Interface for BIST and preloading
	.bist_enable_i (1'b0),
	.bist_wrdata_i (40'b0),
	.bist_rddata_i (40'b0),
	.bist_enable_o (),
	.bist_wrdata_o (),
	.bist_rddata_o (),

	// Global clocks
	.global_clk_x1_i(CLOCK1),
	.global_clk_x2_i(CLOCK2),
	.global_clk_y1_i(CLOCK3),
	.global_clk_y2_i(CLOCK4),

	// DPSRAM-block port A0
	.a0_clk1_i   (a0_clk1_in   ),
	.a0_clk2_i   (a0_clk2_in   ),
	.a0_en1_i    (a0_en1_in    ),
	.a0_en2_i    (a0_en2_in    ),
	.a0_we1_i    (a0_we1_in    ),
	.a0_we2_i    (a0_we2_in    ),
	.a0_addr1_i  (a0_addr1_in   ),
	.a0_addr2_dblin_i  (a0_addr2_in   ),
	.a0_wrdata_i (a0_wrdata_in ),
	.a0_bitmask_i(a0_bitmask_in),
	.a0_rddata_o (a0_rddata_out ),

	// DPSRAM-block port A1
	.a1_clk1_i   (a1_clk1_in   ),
	.a1_clk2_i   (a1_clk2_in   ),
	.a1_en1_i    (a1_en1_in    ),
	.a1_en2_i    (a1_en2_in    ),
	.a1_we1_i    (a1_we1_in    ),
	.a1_we2_i    (a1_we2_in    ),
	.a1_addr1_i  (a1_addr1_in   ),
	.a1_addr2_dblin_i  (a1_addr2_in   ),
	.a1_wrdata_i (a1_wrdata_in ),
	.a1_bitmask_i(a1_bitmask_in),
	.a1_rddata_o (a1_rddata_out ),

	// DPSRAM-block port B0
	.b0_clk1_i   (b0_clk1_in   ),
	.b0_clk2_i   (b0_clk2_in   ),
	.b0_en1_i    (b0_en1_in    ),
	.b0_en2_i    (b0_en2_in    ),
	.b0_we1_i    (b0_we1_in    ),
	.b0_we2_i    (b0_we2_in    ),
	.b0_addr1_i  (b0_addr1_in   ),
	.b0_addr2_dblin_i  (b0_addr2_in   ),
	.b0_wrdata_i (b0_wrdata_in ),
	.b0_bitmask_i(b0_bitmask_in),
	.b0_rddata_o (b0_rddata_out ),

	// DPSRAM-block port B1
	.b1_clk1_i   (b1_clk1_in   ),
	.b1_clk2_i   (b1_clk2_in   ),
	.b1_en1_i    (b1_en1_in    ),
	.b1_en2_i    (b1_en2_in    ),
	.b1_we1_i    (b1_we1_in    ),
	.b1_we2_i    (b1_we2_in    ),
	.b1_addr1_i  (b1_addr1_in   ),
	.b1_addr2_dblin_i  (b1_addr2_in   ),
	.b1_wrdata_i (b1_wrdata_in ),
	.b1_bitmask_i(b1_bitmask_in),
	.b1_rddata_o (b1_rddata_out ),


	// forward signals addr
	.forward_low_a_addr_i(16'b0),
	.forward_up_a_addr_i (16'b0 ),
	.forward_low_a_addr_o(),
	.forward_up_a_addr_o ( ),
	.forward_low_b_addr_i(16'b0),
	.forward_up_b_addr_i (16'b0 ),
	.forward_low_b_addr_o(),
	.forward_up_b_addr_o ( ),


	// forward signals cascade mode
	.forward_cascade_wrdata_a_i (1'b0),
	.forward_cascade_wrdata_b_i (1'b0),
	.forward_cascade_wrdata_a_o (FORW_CAS_WRAO),
	.forward_cascade_wrdata_b_o (FORW_CAS_WRBO),
	.forward_cascade_bitmask_a_i(1'b0),
	.forward_cascade_bitmask_b_i(1'b0),
	.forward_cascade_bitmask_a_o(FORW_CAS_BMAO),
	.forward_cascade_bitmask_b_o(FORW_CAS_BMBO),
	.forward_cascade_rddata_a_i (1'b0),
	.forward_cascade_rddata_b_i (1'b0),
	.forward_cascade_rddata_a_o (FORW_CAS_RDAO),
	.forward_cascade_rddata_b_o (FORW_CAS_RDBO),


	// forward signals port A0
	.forward_low_a0_clk_i(forward_low_a0_clk_in),
	.forward_low_a0_en_i (forward_low_a0_en_in ),
	.forward_low_a0_we_i (forward_low_a0_we_in ),
	.forward_up_a0_clk_i (forward_up_a0_clk_in ),
	.forward_up_a0_en_i  (forward_up_a0_en_in  ),
	.forward_up_a0_we_i  (forward_up_a0_we_in  ),
	.forward_low_a0_clk_o(),
	.forward_low_a0_en_o ( ),
	.forward_low_a0_we_o ( ),
	.forward_up_a0_clk_o ( ),
	.forward_up_a0_en_o  (  ),
	.forward_up_a0_we_o  (  ),

	// forward signals port A1
	.forward_low_a1_clk_i(forward_low_a1_clk_in),
	.forward_low_a1_en_i (forward_low_a1_en_in ),
	.forward_low_a1_we_i (forward_low_a1_we_in ),
	.forward_up_a1_clk_i (forward_up_a1_clk_in ),
	.forward_up_a1_en_i  (forward_up_a1_en_in  ),
	.forward_up_a1_we_i  (forward_up_a1_we_in  ),
	.forward_low_a1_clk_o(),
	.forward_low_a1_en_o ( ),
	.forward_low_a1_we_o ( ),
	.forward_up_a1_clk_o ( ),
	.forward_up_a1_en_o  (  ),
	.forward_up_a1_we_o  (  ),

	// forward signals port B0
	.forward_low_b0_clk_i(forward_low_b0_clk_in),
	.forward_low_b0_en_i (forward_low_b0_en_in ),
	.forward_low_b0_we_i (forward_low_b0_we_in ),
	.forward_up_b0_clk_i (forward_up_b0_clk_in ),
	.forward_up_b0_en_i  (forward_up_b0_en_in  ),
	.forward_up_b0_we_i  (forward_up_b0_we_in  ),
	.forward_low_b0_clk_o(),
	.forward_low_b0_en_o ( ),
	.forward_low_b0_we_o ( ),
	.forward_up_b0_clk_o ( ),
	.forward_up_b0_en_o  (  ),
	.forward_up_b0_we_o  (  ),

	// forward signals port B1
	.forward_low_b1_clk_i(forward_low_b1_clk_in),
	.forward_low_b1_en_i (forward_low_b1_en_in ),
	.forward_low_b1_we_i (forward_low_b1_we_in ),
	.forward_up_b1_clk_i (forward_up_b1_clk_in ),
	.forward_up_b1_en_i  (forward_up_b1_en_in  ),
	.forward_up_b1_we_i  (forward_up_b1_we_in  ),
	.forward_low_b1_clk_o(),
	.forward_low_b1_en_o ( ),
	.forward_low_b1_we_o ( ),
	.forward_up_b1_clk_o ( ),
	.forward_up_b1_en_o  (  ),
	.forward_up_b1_we_o  (  ),


	// ECC status
	.lo_left_ecc_single_error_flag_o(lo_left_ecc_single_error_flag_out),
	.up_left_ecc_single_error_flag_o(up_left_ecc_single_error_flag_out),
	.lo_right_ecc_single_error_flag_o(lo_right_ecc_single_error_flag_out),
	.up_right_ecc_single_error_flag_o(up_right_ecc_single_error_flag_out),

	.lo_left_ecc_double_error_flag_o(lo_left_ecc_double_error_flag_out),
	.up_left_ecc_double_error_flag_o(up_left_ecc_double_error_flag_out),
	.lo_right_ecc_double_error_flag_o(lo_right_ecc_double_error_flag_out),
	.up_right_ecc_double_error_flag_o(up_right_ecc_double_error_flag_out),


	// FIFO ctrl/status data
	.fifo_rstn_i               (F_RSTN),
	.left1_fifo_full_o         (F_FULL[0]),
	.left1_fifo_empty_o        (F_EMPTY[0]),
	.left1_fifo_almost_full_o  (F_AL_FULL[0]),
	.left1_fifo_almost_empty_o (F_AL_EMPTY[0]),
	.left1_fifo_write_error_o  (FWR_ERR[0]),
	.left1_fifo_read_error_o   (FRD_ERR[0]),
	.left2_fifo_full_o         (F_FULL[1]),
	.left2_fifo_empty_o        (F_EMPTY[1]),
	.left2_fifo_almost_full_o  (F_AL_FULL[1]),
	.left2_fifo_almost_empty_o (F_AL_EMPTY[1]),
	.left2_fifo_write_error_o  (FWR_ERR[1]),
	.left2_fifo_read_error_o   (FRD_ERR[1]),
	.fifo_write_address_o(FWR_ADDR),
	.fifo_read_address_o (FRD_ADDR)
	);

	integer k;

	initial begin

		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[0],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[0],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[0],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[0]} = INIT_00[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[1],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[1],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[1],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[1]} = INIT_00[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[2],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[2],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[2],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[2]} = INIT_00[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[3],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[3],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[3],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[3]} = INIT_00[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[4],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[4],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[4],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[4]} = INIT_01[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[5],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[5],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[5],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[5]} = INIT_01[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[6],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[6],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[6],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[6]} = INIT_01[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[7],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[7],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[7],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[7]} = INIT_01[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[8],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[8],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[8],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[8]} = INIT_02[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[9],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[9],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[9],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[9]} = INIT_02[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[10],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[10],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[10],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[10]} = INIT_02[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[11],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[11],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[11],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[11]} = INIT_02[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[12],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[12],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[12],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[12]} = INIT_03[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[13],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[13],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[13],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[13]} = INIT_03[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[14],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[14],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[14],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[14]} = INIT_03[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[15],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[15],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[15],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[15]} = INIT_03[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[16],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[16],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[16],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[16]} = INIT_04[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[17],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[17],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[17],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[17]} = INIT_04[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[18],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[18],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[18],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[18]} = INIT_04[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[19],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[19],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[19],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[19]} = INIT_04[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[20],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[20],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[20],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[20]} = INIT_05[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[21],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[21],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[21],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[21]} = INIT_05[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[22],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[22],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[22],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[22]} = INIT_05[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[23],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[23],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[23],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[23]} = INIT_05[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[24],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[24],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[24],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[24]} = INIT_06[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[25],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[25],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[25],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[25]} = INIT_06[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[26],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[26],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[26],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[26]} = INIT_06[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[27],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[27],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[27],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[27]} = INIT_06[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[28],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[28],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[28],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[28]} = INIT_07[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[29],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[29],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[29],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[29]} = INIT_07[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[30],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[30],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[30],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[30]} = INIT_07[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[31],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[31],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[31],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[31]} = INIT_07[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[32],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[32],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[32],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[32]} = INIT_08[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[33],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[33],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[33],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[33]} = INIT_08[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[34],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[34],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[34],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[34]} = INIT_08[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[35],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[35],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[35],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[35]} = INIT_08[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[36],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[36],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[36],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[36]} = INIT_09[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[37],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[37],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[37],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[37]} = INIT_09[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[38],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[38],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[38],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[38]} = INIT_09[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[39],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[39],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[39],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[39]} = INIT_09[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[40],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[40],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[40],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[40]} = INIT_0A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[41],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[41],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[41],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[41]} = INIT_0A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[42],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[42],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[42],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[42]} = INIT_0A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[43],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[43],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[43],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[43]} = INIT_0A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[44],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[44],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[44],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[44]} = INIT_0B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[45],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[45],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[45],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[45]} = INIT_0B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[46],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[46],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[46],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[46]} = INIT_0B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[47],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[47],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[47],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[47]} = INIT_0B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[48],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[48],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[48],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[48]} = INIT_0C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[49],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[49],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[49],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[49]} = INIT_0C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[50],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[50],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[50],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[50]} = INIT_0C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[51],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[51],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[51],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[51]} = INIT_0C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[52],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[52],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[52],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[52]} = INIT_0D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[53],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[53],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[53],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[53]} = INIT_0D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[54],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[54],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[54],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[54]} = INIT_0D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[55],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[55],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[55],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[55]} = INIT_0D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[56],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[56],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[56],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[56]} = INIT_0E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[57],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[57],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[57],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[57]} = INIT_0E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[58],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[58],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[58],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[58]} = INIT_0E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[59],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[59],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[59],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[59]} = INIT_0E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[60],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[60],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[60],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[60]} = INIT_0F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[61],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[61],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[61],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[61]} = INIT_0F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[62],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[62],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[62],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[62]} = INIT_0F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[63],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[63],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[63],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[63]} = INIT_0F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[64],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[64],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[64],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[64]} = INIT_10[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[65],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[65],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[65],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[65]} = INIT_10[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[66],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[66],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[66],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[66]} = INIT_10[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[67],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[67],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[67],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[67]} = INIT_10[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[68],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[68],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[68],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[68]} = INIT_11[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[69],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[69],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[69],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[69]} = INIT_11[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[70],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[70],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[70],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[70]} = INIT_11[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[71],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[71],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[71],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[71]} = INIT_11[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[72],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[72],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[72],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[72]} = INIT_12[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[73],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[73],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[73],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[73]} = INIT_12[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[74],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[74],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[74],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[74]} = INIT_12[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[75],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[75],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[75],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[75]} = INIT_12[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[76],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[76],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[76],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[76]} = INIT_13[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[77],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[77],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[77],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[77]} = INIT_13[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[78],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[78],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[78],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[78]} = INIT_13[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[79],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[79],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[79],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[79]} = INIT_13[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[80],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[80],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[80],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[80]} = INIT_14[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[81],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[81],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[81],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[81]} = INIT_14[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[82],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[82],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[82],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[82]} = INIT_14[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[83],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[83],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[83],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[83]} = INIT_14[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[84],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[84],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[84],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[84]} = INIT_15[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[85],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[85],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[85],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[85]} = INIT_15[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[86],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[86],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[86],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[86]} = INIT_15[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[87],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[87],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[87],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[87]} = INIT_15[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[88],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[88],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[88],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[88]} = INIT_16[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[89],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[89],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[89],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[89]} = INIT_16[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[90],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[90],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[90],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[90]} = INIT_16[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[91],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[91],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[91],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[91]} = INIT_16[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[92],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[92],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[92],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[92]} = INIT_17[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[93],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[93],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[93],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[93]} = INIT_17[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[94],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[94],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[94],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[94]} = INIT_17[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[95],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[95],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[95],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[95]} = INIT_17[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[96],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[96],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[96],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[96]} = INIT_18[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[97],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[97],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[97],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[97]} = INIT_18[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[98],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[98],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[98],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[98]} = INIT_18[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[99],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[99],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[99],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[99]} = INIT_18[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[100],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[100],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[100],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[100]} = INIT_19[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[101],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[101],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[101],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[101]} = INIT_19[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[102],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[102],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[102],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[102]} = INIT_19[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[103],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[103],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[103],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[103]} = INIT_19[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[104],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[104],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[104],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[104]} = INIT_1A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[105],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[105],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[105],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[105]} = INIT_1A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[106],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[106],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[106],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[106]} = INIT_1A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[107],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[107],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[107],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[107]} = INIT_1A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[108],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[108],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[108],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[108]} = INIT_1B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[109],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[109],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[109],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[109]} = INIT_1B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[110],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[110],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[110],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[110]} = INIT_1B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[111],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[111],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[111],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[111]} = INIT_1B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[112],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[112],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[112],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[112]} = INIT_1C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[113],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[113],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[113],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[113]} = INIT_1C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[114],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[114],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[114],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[114]} = INIT_1C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[115],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[115],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[115],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[115]} = INIT_1C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[116],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[116],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[116],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[116]} = INIT_1D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[117],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[117],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[117],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[117]} = INIT_1D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[118],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[118],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[118],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[118]} = INIT_1D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[119],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[119],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[119],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[119]} = INIT_1D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[120],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[120],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[120],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[120]} = INIT_1E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[121],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[121],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[121],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[121]} = INIT_1E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[122],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[122],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[122],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[122]} = INIT_1E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[123],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[123],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[123],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[123]} = INIT_1E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[124],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[124],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[124],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[124]} = INIT_1F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[125],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[125],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[125],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[125]} = INIT_1F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[126],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[126],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[126],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[126]} = INIT_1F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[127],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[127],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[127],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[127]} = INIT_1F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[128],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[128],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[128],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[128]} = INIT_20[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[129],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[129],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[129],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[129]} = INIT_20[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[130],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[130],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[130],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[130]} = INIT_20[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[131],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[131],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[131],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[131]} = INIT_20[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[132],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[132],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[132],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[132]} = INIT_21[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[133],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[133],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[133],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[133]} = INIT_21[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[134],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[134],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[134],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[134]} = INIT_21[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[135],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[135],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[135],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[135]} = INIT_21[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[136],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[136],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[136],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[136]} = INIT_22[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[137],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[137],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[137],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[137]} = INIT_22[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[138],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[138],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[138],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[138]} = INIT_22[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[139],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[139],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[139],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[139]} = INIT_22[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[140],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[140],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[140],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[140]} = INIT_23[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[141],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[141],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[141],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[141]} = INIT_23[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[142],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[142],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[142],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[142]} = INIT_23[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[143],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[143],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[143],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[143]} = INIT_23[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[144],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[144],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[144],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[144]} = INIT_24[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[145],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[145],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[145],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[145]} = INIT_24[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[146],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[146],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[146],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[146]} = INIT_24[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[147],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[147],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[147],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[147]} = INIT_24[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[148],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[148],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[148],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[148]} = INIT_25[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[149],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[149],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[149],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[149]} = INIT_25[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[150],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[150],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[150],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[150]} = INIT_25[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[151],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[151],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[151],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[151]} = INIT_25[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[152],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[152],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[152],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[152]} = INIT_26[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[153],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[153],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[153],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[153]} = INIT_26[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[154],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[154],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[154],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[154]} = INIT_26[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[155],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[155],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[155],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[155]} = INIT_26[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[156],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[156],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[156],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[156]} = INIT_27[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[157],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[157],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[157],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[157]} = INIT_27[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[158],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[158],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[158],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[158]} = INIT_27[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[159],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[159],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[159],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[159]} = INIT_27[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[160],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[160],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[160],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[160]} = INIT_28[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[161],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[161],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[161],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[161]} = INIT_28[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[162],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[162],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[162],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[162]} = INIT_28[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[163],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[163],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[163],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[163]} = INIT_28[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[164],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[164],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[164],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[164]} = INIT_29[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[165],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[165],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[165],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[165]} = INIT_29[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[166],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[166],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[166],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[166]} = INIT_29[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[167],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[167],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[167],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[167]} = INIT_29[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[168],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[168],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[168],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[168]} = INIT_2A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[169],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[169],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[169],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[169]} = INIT_2A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[170],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[170],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[170],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[170]} = INIT_2A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[171],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[171],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[171],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[171]} = INIT_2A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[172],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[172],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[172],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[172]} = INIT_2B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[173],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[173],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[173],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[173]} = INIT_2B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[174],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[174],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[174],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[174]} = INIT_2B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[175],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[175],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[175],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[175]} = INIT_2B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[176],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[176],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[176],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[176]} = INIT_2C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[177],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[177],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[177],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[177]} = INIT_2C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[178],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[178],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[178],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[178]} = INIT_2C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[179],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[179],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[179],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[179]} = INIT_2C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[180],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[180],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[180],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[180]} = INIT_2D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[181],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[181],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[181],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[181]} = INIT_2D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[182],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[182],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[182],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[182]} = INIT_2D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[183],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[183],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[183],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[183]} = INIT_2D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[184],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[184],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[184],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[184]} = INIT_2E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[185],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[185],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[185],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[185]} = INIT_2E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[186],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[186],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[186],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[186]} = INIT_2E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[187],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[187],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[187],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[187]} = INIT_2E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[188],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[188],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[188],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[188]} = INIT_2F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[189],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[189],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[189],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[189]} = INIT_2F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[190],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[190],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[190],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[190]} = INIT_2F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[191],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[191],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[191],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[191]} = INIT_2F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[192],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[192],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[192],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[192]} = INIT_30[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[193],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[193],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[193],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[193]} = INIT_30[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[194],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[194],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[194],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[194]} = INIT_30[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[195],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[195],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[195],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[195]} = INIT_30[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[196],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[196],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[196],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[196]} = INIT_31[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[197],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[197],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[197],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[197]} = INIT_31[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[198],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[198],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[198],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[198]} = INIT_31[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[199],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[199],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[199],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[199]} = INIT_31[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[200],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[200],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[200],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[200]} = INIT_32[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[201],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[201],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[201],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[201]} = INIT_32[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[202],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[202],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[202],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[202]} = INIT_32[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[203],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[203],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[203],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[203]} = INIT_32[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[204],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[204],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[204],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[204]} = INIT_33[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[205],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[205],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[205],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[205]} = INIT_33[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[206],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[206],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[206],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[206]} = INIT_33[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[207],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[207],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[207],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[207]} = INIT_33[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[208],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[208],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[208],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[208]} = INIT_34[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[209],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[209],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[209],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[209]} = INIT_34[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[210],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[210],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[210],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[210]} = INIT_34[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[211],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[211],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[211],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[211]} = INIT_34[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[212],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[212],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[212],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[212]} = INIT_35[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[213],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[213],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[213],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[213]} = INIT_35[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[214],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[214],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[214],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[214]} = INIT_35[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[215],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[215],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[215],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[215]} = INIT_35[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[216],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[216],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[216],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[216]} = INIT_36[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[217],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[217],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[217],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[217]} = INIT_36[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[218],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[218],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[218],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[218]} = INIT_36[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[219],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[219],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[219],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[219]} = INIT_36[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[220],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[220],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[220],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[220]} = INIT_37[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[221],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[221],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[221],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[221]} = INIT_37[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[222],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[222],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[222],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[222]} = INIT_37[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[223],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[223],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[223],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[223]} = INIT_37[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[224],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[224],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[224],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[224]} = INIT_38[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[225],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[225],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[225],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[225]} = INIT_38[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[226],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[226],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[226],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[226]} = INIT_38[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[227],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[227],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[227],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[227]} = INIT_38[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[228],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[228],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[228],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[228]} = INIT_39[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[229],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[229],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[229],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[229]} = INIT_39[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[230],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[230],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[230],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[230]} = INIT_39[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[231],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[231],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[231],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[231]} = INIT_39[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[232],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[232],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[232],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[232]} = INIT_3A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[233],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[233],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[233],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[233]} = INIT_3A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[234],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[234],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[234],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[234]} = INIT_3A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[235],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[235],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[235],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[235]} = INIT_3A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[236],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[236],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[236],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[236]} = INIT_3B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[237],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[237],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[237],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[237]} = INIT_3B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[238],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[238],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[238],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[238]} = INIT_3B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[239],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[239],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[239],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[239]} = INIT_3B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[240],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[240],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[240],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[240]} = INIT_3C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[241],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[241],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[241],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[241]} = INIT_3C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[242],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[242],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[242],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[242]} = INIT_3C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[243],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[243],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[243],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[243]} = INIT_3C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[244],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[244],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[244],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[244]} = INIT_3D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[245],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[245],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[245],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[245]} = INIT_3D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[246],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[246],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[246],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[246]} = INIT_3D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[247],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[247],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[247],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[247]} = INIT_3D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[248],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[248],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[248],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[248]} = INIT_3E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[249],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[249],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[249],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[249]} = INIT_3E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[250],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[250],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[250],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[250]} = INIT_3E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[251],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[251],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[251],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[251]} = INIT_3E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[252],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[252],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[252],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[252]} = INIT_3F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[253],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[253],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[253],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[253]} = INIT_3F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[254],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[254],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[254],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[254]} = INIT_3F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[255],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[255],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[255],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[255]} = INIT_3F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[256],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[256],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[256],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[256]} = INIT_40[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[257],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[257],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[257],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[257]} = INIT_40[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[258],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[258],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[258],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[258]} = INIT_40[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[259],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[259],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[259],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[259]} = INIT_40[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[260],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[260],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[260],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[260]} = INIT_41[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[261],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[261],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[261],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[261]} = INIT_41[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[262],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[262],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[262],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[262]} = INIT_41[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[263],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[263],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[263],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[263]} = INIT_41[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[264],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[264],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[264],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[264]} = INIT_42[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[265],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[265],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[265],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[265]} = INIT_42[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[266],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[266],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[266],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[266]} = INIT_42[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[267],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[267],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[267],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[267]} = INIT_42[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[268],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[268],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[268],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[268]} = INIT_43[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[269],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[269],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[269],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[269]} = INIT_43[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[270],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[270],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[270],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[270]} = INIT_43[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[271],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[271],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[271],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[271]} = INIT_43[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[272],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[272],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[272],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[272]} = INIT_44[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[273],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[273],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[273],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[273]} = INIT_44[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[274],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[274],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[274],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[274]} = INIT_44[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[275],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[275],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[275],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[275]} = INIT_44[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[276],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[276],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[276],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[276]} = INIT_45[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[277],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[277],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[277],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[277]} = INIT_45[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[278],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[278],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[278],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[278]} = INIT_45[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[279],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[279],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[279],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[279]} = INIT_45[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[280],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[280],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[280],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[280]} = INIT_46[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[281],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[281],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[281],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[281]} = INIT_46[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[282],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[282],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[282],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[282]} = INIT_46[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[283],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[283],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[283],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[283]} = INIT_46[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[284],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[284],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[284],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[284]} = INIT_47[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[285],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[285],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[285],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[285]} = INIT_47[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[286],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[286],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[286],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[286]} = INIT_47[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[287],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[287],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[287],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[287]} = INIT_47[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[288],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[288],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[288],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[288]} = INIT_48[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[289],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[289],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[289],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[289]} = INIT_48[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[290],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[290],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[290],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[290]} = INIT_48[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[291],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[291],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[291],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[291]} = INIT_48[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[292],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[292],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[292],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[292]} = INIT_49[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[293],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[293],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[293],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[293]} = INIT_49[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[294],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[294],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[294],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[294]} = INIT_49[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[295],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[295],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[295],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[295]} = INIT_49[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[296],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[296],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[296],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[296]} = INIT_4A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[297],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[297],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[297],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[297]} = INIT_4A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[298],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[298],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[298],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[298]} = INIT_4A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[299],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[299],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[299],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[299]} = INIT_4A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[300],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[300],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[300],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[300]} = INIT_4B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[301],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[301],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[301],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[301]} = INIT_4B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[302],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[302],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[302],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[302]} = INIT_4B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[303],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[303],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[303],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[303]} = INIT_4B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[304],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[304],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[304],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[304]} = INIT_4C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[305],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[305],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[305],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[305]} = INIT_4C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[306],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[306],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[306],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[306]} = INIT_4C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[307],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[307],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[307],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[307]} = INIT_4C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[308],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[308],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[308],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[308]} = INIT_4D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[309],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[309],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[309],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[309]} = INIT_4D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[310],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[310],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[310],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[310]} = INIT_4D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[311],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[311],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[311],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[311]} = INIT_4D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[312],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[312],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[312],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[312]} = INIT_4E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[313],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[313],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[313],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[313]} = INIT_4E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[314],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[314],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[314],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[314]} = INIT_4E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[315],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[315],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[315],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[315]} = INIT_4E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[316],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[316],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[316],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[316]} = INIT_4F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[317],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[317],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[317],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[317]} = INIT_4F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[318],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[318],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[318],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[318]} = INIT_4F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[319],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[319],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[319],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[319]} = INIT_4F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[320],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[320],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[320],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[320]} = INIT_50[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[321],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[321],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[321],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[321]} = INIT_50[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[322],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[322],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[322],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[322]} = INIT_50[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[323],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[323],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[323],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[323]} = INIT_50[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[324],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[324],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[324],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[324]} = INIT_51[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[325],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[325],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[325],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[325]} = INIT_51[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[326],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[326],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[326],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[326]} = INIT_51[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[327],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[327],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[327],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[327]} = INIT_51[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[328],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[328],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[328],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[328]} = INIT_52[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[329],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[329],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[329],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[329]} = INIT_52[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[330],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[330],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[330],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[330]} = INIT_52[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[331],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[331],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[331],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[331]} = INIT_52[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[332],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[332],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[332],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[332]} = INIT_53[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[333],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[333],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[333],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[333]} = INIT_53[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[334],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[334],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[334],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[334]} = INIT_53[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[335],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[335],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[335],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[335]} = INIT_53[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[336],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[336],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[336],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[336]} = INIT_54[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[337],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[337],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[337],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[337]} = INIT_54[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[338],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[338],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[338],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[338]} = INIT_54[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[339],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[339],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[339],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[339]} = INIT_54[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[340],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[340],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[340],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[340]} = INIT_55[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[341],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[341],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[341],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[341]} = INIT_55[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[342],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[342],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[342],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[342]} = INIT_55[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[343],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[343],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[343],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[343]} = INIT_55[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[344],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[344],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[344],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[344]} = INIT_56[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[345],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[345],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[345],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[345]} = INIT_56[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[346],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[346],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[346],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[346]} = INIT_56[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[347],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[347],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[347],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[347]} = INIT_56[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[348],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[348],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[348],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[348]} = INIT_57[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[349],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[349],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[349],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[349]} = INIT_57[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[350],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[350],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[350],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[350]} = INIT_57[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[351],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[351],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[351],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[351]} = INIT_57[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[352],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[352],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[352],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[352]} = INIT_58[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[353],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[353],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[353],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[353]} = INIT_58[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[354],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[354],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[354],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[354]} = INIT_58[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[355],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[355],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[355],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[355]} = INIT_58[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[356],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[356],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[356],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[356]} = INIT_59[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[357],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[357],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[357],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[357]} = INIT_59[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[358],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[358],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[358],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[358]} = INIT_59[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[359],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[359],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[359],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[359]} = INIT_59[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[360],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[360],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[360],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[360]} = INIT_5A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[361],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[361],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[361],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[361]} = INIT_5A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[362],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[362],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[362],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[362]} = INIT_5A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[363],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[363],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[363],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[363]} = INIT_5A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[364],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[364],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[364],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[364]} = INIT_5B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[365],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[365],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[365],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[365]} = INIT_5B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[366],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[366],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[366],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[366]} = INIT_5B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[367],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[367],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[367],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[367]} = INIT_5B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[368],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[368],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[368],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[368]} = INIT_5C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[369],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[369],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[369],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[369]} = INIT_5C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[370],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[370],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[370],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[370]} = INIT_5C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[371],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[371],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[371],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[371]} = INIT_5C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[372],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[372],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[372],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[372]} = INIT_5D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[373],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[373],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[373],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[373]} = INIT_5D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[374],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[374],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[374],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[374]} = INIT_5D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[375],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[375],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[375],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[375]} = INIT_5D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[376],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[376],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[376],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[376]} = INIT_5E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[377],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[377],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[377],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[377]} = INIT_5E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[378],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[378],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[378],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[378]} = INIT_5E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[379],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[379],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[379],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[379]} = INIT_5E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[380],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[380],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[380],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[380]} = INIT_5F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[381],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[381],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[381],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[381]} = INIT_5F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[382],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[382],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[382],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[382]} = INIT_5F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[383],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[383],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[383],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[383]} = INIT_5F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[384],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[384],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[384],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[384]} = INIT_60[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[385],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[385],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[385],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[385]} = INIT_60[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[386],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[386],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[386],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[386]} = INIT_60[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[387],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[387],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[387],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[387]} = INIT_60[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[388],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[388],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[388],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[388]} = INIT_61[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[389],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[389],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[389],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[389]} = INIT_61[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[390],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[390],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[390],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[390]} = INIT_61[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[391],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[391],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[391],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[391]} = INIT_61[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[392],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[392],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[392],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[392]} = INIT_62[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[393],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[393],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[393],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[393]} = INIT_62[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[394],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[394],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[394],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[394]} = INIT_62[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[395],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[395],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[395],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[395]} = INIT_62[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[396],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[396],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[396],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[396]} = INIT_63[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[397],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[397],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[397],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[397]} = INIT_63[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[398],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[398],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[398],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[398]} = INIT_63[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[399],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[399],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[399],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[399]} = INIT_63[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[400],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[400],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[400],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[400]} = INIT_64[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[401],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[401],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[401],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[401]} = INIT_64[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[402],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[402],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[402],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[402]} = INIT_64[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[403],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[403],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[403],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[403]} = INIT_64[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[404],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[404],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[404],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[404]} = INIT_65[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[405],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[405],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[405],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[405]} = INIT_65[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[406],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[406],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[406],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[406]} = INIT_65[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[407],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[407],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[407],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[407]} = INIT_65[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[408],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[408],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[408],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[408]} = INIT_66[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[409],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[409],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[409],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[409]} = INIT_66[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[410],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[410],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[410],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[410]} = INIT_66[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[411],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[411],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[411],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[411]} = INIT_66[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[412],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[412],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[412],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[412]} = INIT_67[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[413],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[413],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[413],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[413]} = INIT_67[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[414],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[414],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[414],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[414]} = INIT_67[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[415],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[415],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[415],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[415]} = INIT_67[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[416],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[416],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[416],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[416]} = INIT_68[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[417],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[417],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[417],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[417]} = INIT_68[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[418],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[418],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[418],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[418]} = INIT_68[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[419],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[419],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[419],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[419]} = INIT_68[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[420],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[420],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[420],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[420]} = INIT_69[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[421],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[421],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[421],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[421]} = INIT_69[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[422],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[422],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[422],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[422]} = INIT_69[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[423],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[423],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[423],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[423]} = INIT_69[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[424],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[424],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[424],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[424]} = INIT_6A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[425],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[425],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[425],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[425]} = INIT_6A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[426],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[426],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[426],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[426]} = INIT_6A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[427],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[427],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[427],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[427]} = INIT_6A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[428],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[428],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[428],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[428]} = INIT_6B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[429],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[429],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[429],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[429]} = INIT_6B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[430],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[430],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[430],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[430]} = INIT_6B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[431],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[431],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[431],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[431]} = INIT_6B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[432],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[432],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[432],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[432]} = INIT_6C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[433],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[433],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[433],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[433]} = INIT_6C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[434],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[434],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[434],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[434]} = INIT_6C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[435],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[435],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[435],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[435]} = INIT_6C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[436],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[436],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[436],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[436]} = INIT_6D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[437],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[437],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[437],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[437]} = INIT_6D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[438],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[438],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[438],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[438]} = INIT_6D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[439],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[439],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[439],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[439]} = INIT_6D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[440],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[440],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[440],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[440]} = INIT_6E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[441],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[441],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[441],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[441]} = INIT_6E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[442],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[442],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[442],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[442]} = INIT_6E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[443],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[443],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[443],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[443]} = INIT_6E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[444],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[444],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[444],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[444]} = INIT_6F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[445],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[445],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[445],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[445]} = INIT_6F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[446],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[446],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[446],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[446]} = INIT_6F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[447],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[447],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[447],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[447]} = INIT_6F[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[448],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[448],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[448],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[448]} = INIT_70[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[449],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[449],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[449],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[449]} = INIT_70[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[450],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[450],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[450],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[450]} = INIT_70[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[451],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[451],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[451],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[451]} = INIT_70[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[452],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[452],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[452],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[452]} = INIT_71[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[453],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[453],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[453],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[453]} = INIT_71[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[454],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[454],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[454],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[454]} = INIT_71[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[455],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[455],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[455],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[455]} = INIT_71[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[456],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[456],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[456],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[456]} = INIT_72[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[457],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[457],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[457],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[457]} = INIT_72[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[458],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[458],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[458],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[458]} = INIT_72[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[459],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[459],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[459],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[459]} = INIT_72[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[460],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[460],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[460],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[460]} = INIT_73[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[461],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[461],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[461],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[461]} = INIT_73[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[462],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[462],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[462],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[462]} = INIT_73[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[463],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[463],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[463],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[463]} = INIT_73[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[464],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[464],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[464],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[464]} = INIT_74[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[465],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[465],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[465],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[465]} = INIT_74[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[466],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[466],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[466],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[466]} = INIT_74[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[467],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[467],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[467],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[467]} = INIT_74[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[468],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[468],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[468],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[468]} = INIT_75[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[469],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[469],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[469],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[469]} = INIT_75[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[470],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[470],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[470],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[470]} = INIT_75[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[471],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[471],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[471],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[471]} = INIT_75[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[472],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[472],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[472],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[472]} = INIT_76[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[473],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[473],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[473],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[473]} = INIT_76[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[474],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[474],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[474],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[474]} = INIT_76[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[475],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[475],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[475],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[475]} = INIT_76[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[476],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[476],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[476],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[476]} = INIT_77[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[477],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[477],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[477],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[477]} = INIT_77[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[478],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[478],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[478],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[478]} = INIT_77[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[479],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[479],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[479],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[479]} = INIT_77[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[480],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[480],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[480],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[480]} = INIT_78[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[481],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[481],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[481],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[481]} = INIT_78[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[482],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[482],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[482],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[482]} = INIT_78[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[483],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[483],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[483],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[483]} = INIT_78[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[484],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[484],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[484],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[484]} = INIT_79[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[485],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[485],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[485],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[485]} = INIT_79[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[486],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[486],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[486],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[486]} = INIT_79[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[487],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[487],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[487],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[487]} = INIT_79[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[488],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[488],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[488],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[488]} = INIT_7A[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[489],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[489],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[489],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[489]} = INIT_7A[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[490],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[490],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[490],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[490]} = INIT_7A[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[491],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[491],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[491],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[491]} = INIT_7A[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[492],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[492],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[492],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[492]} = INIT_7B[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[493],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[493],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[493],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[493]} = INIT_7B[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[494],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[494],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[494],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[494]} = INIT_7B[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[495],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[495],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[495],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[495]} = INIT_7B[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[496],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[496],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[496],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[496]} = INIT_7C[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[497],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[497],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[497],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[497]} = INIT_7C[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[498],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[498],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[498],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[498]} = INIT_7C[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[499],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[499],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[499],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[499]} = INIT_7C[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[500],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[500],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[500],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[500]} = INIT_7D[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[501],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[501],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[501],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[501]} = INIT_7D[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[502],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[502],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[502],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[502]} = INIT_7D[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[503],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[503],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[503],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[503]} = INIT_7D[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[504],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[504],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[504],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[504]} = INIT_7E[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[505],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[505],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[505],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[505]} = INIT_7E[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[506],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[506],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[506],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[506]} = INIT_7E[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[507],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[507],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[507],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[507]} = INIT_7E[319:240];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[508],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[508],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[508],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[508]} = INIT_7F[79:0];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[509],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[509],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[509],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[509]} = INIT_7F[159:80];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[510],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[510],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[510],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[510]} = INIT_7F[239:160];
		{i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[511],i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[511],i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[511],i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.mem_arr[511]} = INIT_7F[319:240];

		i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_a_r=20'b0;
		i_dpsram_block.RAM_i1.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_b_r=20'b0;
		i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_a_r=20'b0;
		i_dpsram_block.RAM_i2.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_b_r=20'b0;
		i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_a_r=20'b0;
		i_dpsram_block.RAM_i3.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_b_r=20'b0;
		i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_a_r=20'b0;
		i_dpsram_block.RAM_i4.RM_GF28SLP_2P_512x20_c2_inst.SRAM_2P_behavioral_i.dr_b_r=20'b0;

		i_dpsram_block.output_registering_i.r_a0_rddata=20'b0;
		i_dpsram_block.output_registering_i.r_a1_rddata=20'b0;
		i_dpsram_block.output_registering_i.r_b0_rddata=20'b0;
		i_dpsram_block.output_registering_i.r_b1_rddata=20'b0;

		i_dpsram_block.output_registering_i.r_ecc_single_error_flag=2'b0;
		i_dpsram_block.output_registering_i.r_ecc_double_error_flag=2'b0;
	end

`ifdef USE_TIMING
	specify
		(CLOCK1 => DOA[0]) = 0;
		(CLOCK1 => DOA[1]) = 0;
		(CLOCK1 => DOA[2]) = 0;
		(CLOCK1 => DOA[3]) = 0;
		(CLOCK1 => DOA[4]) = 0;
		(CLOCK1 => DOA[5]) = 0;
		(CLOCK1 => DOA[6]) = 0;
		(CLOCK1 => DOA[7]) = 0;
		(CLOCK1 => DOA[8]) = 0;
		(CLOCK1 => DOA[9]) = 0;
		(CLOCK1 => DOA[10]) = 0;
		(CLOCK1 => DOA[11]) = 0;
		(CLOCK1 => DOA[12]) = 0;
		(CLOCK1 => DOA[13]) = 0;
		(CLOCK1 => DOA[14]) = 0;
		(CLOCK1 => DOA[15]) = 0;
		(CLOCK1 => DOA[16]) = 0;
		(CLOCK1 => DOA[17]) = 0;
		(CLOCK1 => DOA[18]) = 0;
		(CLOCK1 => DOA[19]) = 0;
		(CLOCK1 => DOA[20]) = 0;
		(CLOCK1 => DOA[21]) = 0;
		(CLOCK1 => DOA[22]) = 0;
		(CLOCK1 => DOA[23]) = 0;
		(CLOCK1 => DOA[24]) = 0;
		(CLOCK1 => DOA[25]) = 0;
		(CLOCK1 => DOA[26]) = 0;
		(CLOCK1 => DOA[27]) = 0;
		(CLOCK1 => DOA[28]) = 0;
		(CLOCK1 => DOA[29]) = 0;
		(CLOCK1 => DOA[30]) = 0;
		(CLOCK1 => DOA[31]) = 0;
		(CLOCK1 => DOA[32]) = 0;
		(CLOCK1 => DOA[33]) = 0;
		(CLOCK1 => DOA[34]) = 0;
		(CLOCK1 => DOA[35]) = 0;
		(CLOCK1 => DOA[36]) = 0;
		(CLOCK1 => DOA[37]) = 0;
		(CLOCK1 => DOA[38]) = 0;
		(CLOCK1 => DOA[39]) = 0;
		(CLOCK1 => DOB[0]) = 0;
		(CLOCK1 => DOB[1]) = 0;
		(CLOCK1 => DOB[2]) = 0;
		(CLOCK1 => DOB[3]) = 0;
		(CLOCK1 => DOB[4]) = 0;
		(CLOCK1 => DOB[5]) = 0;
		(CLOCK1 => DOB[6]) = 0;
		(CLOCK1 => DOB[7]) = 0;
		(CLOCK1 => DOB[8]) = 0;
		(CLOCK1 => DOB[9]) = 0;
		(CLOCK1 => DOB[10]) = 0;
		(CLOCK1 => DOB[11]) = 0;
		(CLOCK1 => DOB[12]) = 0;
		(CLOCK1 => DOB[13]) = 0;
		(CLOCK1 => DOB[14]) = 0;
		(CLOCK1 => DOB[15]) = 0;
		(CLOCK1 => DOB[16]) = 0;
		(CLOCK1 => DOB[17]) = 0;
		(CLOCK1 => DOB[18]) = 0;
		(CLOCK1 => DOB[19]) = 0;
		(CLOCK1 => DOB[20]) = 0;
		(CLOCK1 => DOB[21]) = 0;
		(CLOCK1 => DOB[22]) = 0;
		(CLOCK1 => DOB[23]) = 0;
		(CLOCK1 => DOB[24]) = 0;
		(CLOCK1 => DOB[25]) = 0;
		(CLOCK1 => DOB[26]) = 0;
		(CLOCK1 => DOB[27]) = 0;
		(CLOCK1 => DOB[28]) = 0;
		(CLOCK1 => DOB[29]) = 0;
		(CLOCK1 => DOB[30]) = 0;
		(CLOCK1 => DOB[31]) = 0;
		(CLOCK1 => DOB[32]) = 0;
		(CLOCK1 => DOB[33]) = 0;
		(CLOCK1 => DOB[34]) = 0;
		(CLOCK1 => DOB[35]) = 0;
		(CLOCK1 => DOB[36]) = 0;
		(CLOCK1 => DOB[37]) = 0;
		(CLOCK1 => DOB[38]) = 0;
		(CLOCK1 => DOB[39]) = 0;
	endspecify
`endif

endmodule
`endif // USE_RAM
