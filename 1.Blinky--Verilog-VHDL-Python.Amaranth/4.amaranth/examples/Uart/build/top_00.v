//  (c) Cologne Chip AG
//  FPGA Verilog netlist writer     Version: Version 4.2 (1 July 2024)
//  Compile Time: 1970-01-01 00:59:59
//  Program Run:  2024-07-23 18:03:28
//  Program Call: p_r -v -i net/top_synth.v -o top -ccf top.ccf -cCP 
//  File Type:    Verilog

// Gatecount:    112
module top (clk0_0__io , uart_0__rx__io ,
       led_0__io , uart_0__tx__io 
       ) ;

input  clk0_0__io;
input  uart_0__rx__io;

output led_0__io;
output uart_0__tx__io;



wire na1_1;
wire na1_1_i;
wire na1_2;
wire na1_2_i;
wire na2_1;
wire na3_1;
wire na4_1;
wire na6_1;
wire na7_2;
wire na8_1;
wire na9_1;
wire na9_2;
wire na11_1;
wire na14_2;
wire na15_1;
wire na17_1;
wire na19_2;
wire na20_1;
wire na20_1_i;
wire na21_1;
wire na23_1;
wire na23_2;
wire na25_2;
wire na26_1;
wire na26_1_i;
wire na26_2;
wire na26_2_i;
wire na27_1;
wire na28_1;
wire na28_1_i;
wire na28_2;
wire na28_2_i;
wire na31_1;
wire na31_2;
wire na32_1;
wire na32_1_i;
wire na32_2;
wire na32_2_i;
wire na34_2;
wire na34_2_i;
wire na36_2;
wire na38_1;
wire na38_2;
wire na40_1;
wire na40_1_i;
wire na41_1;
wire na42_2;
wire na43_2;
wire na44_2;
wire na44_2_i;
wire na45_1;
wire na45_1_i;
wire na46_1;
wire na46_1_i;
wire na47_1;
wire na49_1;
wire na49_1_i;
wire na51_1;
wire na52_1;
wire na52_1_i;
wire na52_2;
wire na52_2_i;
wire na53_2;
wire na54_1;
wire na54_1_i;
wire na54_2;
wire na54_2_i;
wire na55_2;
wire na57_2;
wire na58_1;
wire na58_1_i;
wire na58_2;
wire na58_2_i;
wire na59_1;
wire na60_2;
wire na60_2_i;
wire na61_2;
wire na62_1;
wire na62_1_i;
wire na63_1;
wire na64_1;
wire na64_1_i;
wire na65_2;
wire na67_1;
wire na85_1;
wire na85_1_i;
wire na85_2;
wire na85_2_i;
wire na88_4;
wire na90_4;
wire na92_4;
wire na93_4;
wire na95_4;
wire na97_4;
wire na99_4;
wire led_0__io;
wire na101_4;
wire na102_1;
wire na102_4;
wire na104_1;
wire na104_2;
wire na104_4;
wire na106_1;
wire na106_2;
wire na106_4;
wire na108_1;
wire na109_1;
wire na109_2;
wire na109_4;
wire na111_1;
wire na111_2;
wire na111_4;
wire na113_1;
wire na113_2;
wire na113_4;
wire na115_1;
wire na115_2;
wire na115_4;
wire na117_1;
wire na117_2;
wire na117_4;
wire na118_1;
wire na118_4;
wire na119_1;
wire na119_2;
wire na122_1;
wire na123_1;
wire na123_1_i;
wire na150_1;
wire na152_1;
wire na154_2;
wire na154_2_i;
wire na155_2;
wire na156_2;
wire na158_1;
wire na159_1;
wire na160_1;
wire na161_1;
wire na161_4;
wire na163_2;
wire na164_1;
wire na167_2;
wire na171_1;
wire na171_2;
wire na175_1;
wire na179_2;
wire na187_1;
wire na187_2;
wire na194_1;
wire na197_1;
wire na200_1;
wire na204_1;
wire na208_2;
wire na212_2;
wire na216_1;
wire na220_2;
wire na224_1;
wire na227_1;
wire na228_1;
wire na229_2;
wire na230_2;
wire na231_2;
wire na232_2;
wire na233_2;
wire na234_2;
wire na235_2;
wire na236_2;
wire na237_2;
wire na238_2;
wire na239_2;
wire na240_2;
wire na241_2;
wire na242_2;
wire clk0_0__io;
wire na229_10;
wire na230_10;
wire uart_0__rx__io;
wire uart_0__tx__io;

// C_ORAND/D//ORAND/D      x8y74     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a1_1 ( .OUT(na1_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na155_2), .IN8(na2_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a1_2 ( .OUT(na1_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na1_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a1_4 ( .OUT(na1_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na224_1), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a1_5 ( .OUT(na1_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na1_2_i) );
// C_AND////      x8y76     80'h00_0018_00_0000_0C88_5CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a2_1 ( .OUT(na2_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na106_2), .IN7(~na156_2), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
CLKIN      #(.CLKIN_CFG (32'h0000_0000)) 
           _a3 ( .PCLK0(na3_1), .PCLK1(_d0), .PCLK2(_d1), .PCLK3(_d2), .CLK0(na150_1), .CLK1(1'b0), .CLK2(1'b0), .CLK3(1'b0), .SER_CLK(1'b0),
                 .SPI_CLK(1'b0), .JTAG_CLK(1'b0) );
// C_AND////      x10y76     80'h00_0018_00_0000_0888_2185
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a4_1 ( .OUT(na4_1), .IN1(~na28_2), .IN2(1'b1), .IN3(na7_2), .IN4(na8_1), .IN5(~na28_1), .IN6(~na235_2), .IN7(na6_1), .IN8(~na1_2),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x8y73     80'h00_0018_00_0000_0C88_11FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a6_1 ( .OUT(na6_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na233_2), .IN6(~na26_1), .IN7(~na32_2), .IN8(~na1_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x8y73     80'h00_0060_00_0000_0C08_FF24
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a7_4 ( .OUT(na7_2), .IN1(~na239_2), .IN2(na60_2), .IN3(na54_2), .IN4(~na58_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x8y72     80'h00_0018_00_0000_0C88_42FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a8_1 ( .OUT(na8_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na52_2), .IN6(~na238_2), .IN7(~na20_1), .IN8(na58_2),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x10y75     80'h00_0078_00_0000_0C88_2311
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a9_1 ( .OUT(na9_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na34_2), .IN7(na240_2), .IN8(~na85_2),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a9_4 ( .OUT(na9_2), .IN1(~na44_2), .IN2(~na34_2), .IN3(~na240_2), .IN4(~na85_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x8y78     80'h00_0018_00_0000_0888_1111
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a11_1 ( .OUT(na11_1), .IN1(~na28_2), .IN2(~na234_2), .IN3(~na32_1), .IN4(~na1_1), .IN5(~na233_2), .IN6(~na26_1), .IN7(~na32_2),
                    .IN8(~na1_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x9y78     80'h00_0060_00_0000_0C08_FF3C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a14_4 ( .OUT(na14_2), .IN1(1'b1), .IN2(na34_2), .IN3(1'b1), .IN4(~na85_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x11y72     80'h00_0018_00_0000_0C88_2FFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a15_1 ( .OUT(na15_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na160_1), .IN8(~na85_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y80     80'h00_0018_00_0000_0C88_C4FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a17_1 ( .OUT(na17_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na38_2), .IN6(na14_2), .IN7(1'b1), .IN8(na85_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x8y72     80'h00_0060_00_0000_0C08_FF1F
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a19_4 ( .OUT(na19_2), .IN1(1'b1), .IN2(1'b1), .IN3(~na156_2), .IN4(~na58_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D///      x8y71     80'h00_FE00_00_0000_0C88_E5FF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a20_1 ( .OUT(na20_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na21_1), .IN8(na167_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a20_2 ( .OUT(na20_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na20_1_i) );
// C_AND////      x4y71     80'h00_0018_00_0000_0C88_5AFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a21_1 ( .OUT(na21_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na115_1), .IN6(1'b1), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x4y76     80'h00_0078_00_0000_0C88_5A5C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a23_1 ( .OUT(na23_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na115_2), .IN6(1'b1), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a23_4 ( .OUT(na23_2), .IN1(1'b1), .IN2(na106_1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x12y73     80'h00_0060_00_0000_0C08_FF5C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a25_4 ( .OUT(na25_2), .IN1(1'b1), .IN2(na117_1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x7y80     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a26_1 ( .OUT(na26_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na179_2), .IN8(na27_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a26_2 ( .OUT(na26_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na26_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a26_4 ( .OUT(na26_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na25_2), .IN4(na175_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a26_5 ( .OUT(na26_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na26_2_i) );
// C_AND////      x4y74     80'h00_0018_00_0000_0C88_5CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a27_1 ( .OUT(na27_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na117_2), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x9y73     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a28_1 ( .OUT(na28_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na187_2), .IN8(na31_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a28_2 ( .OUT(na28_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na28_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a28_4 ( .OUT(na28_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na187_1), .IN4(na31_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a28_5 ( .OUT(na28_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na28_2_i) );
// C_AND///AND/      x10y72     80'h00_0078_00_0000_0C88_5A5A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a31_1 ( .OUT(na31_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na104_2), .IN6(1'b1), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a31_4 ( .OUT(na31_2), .IN1(na104_1), .IN2(1'b1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x8y75     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a32_1 ( .OUT(na32_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na171_2), .IN8(na23_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a32_2 ( .OUT(na32_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na32_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a32_4 ( .OUT(na32_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na171_1), .IN4(na23_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a32_5 ( .OUT(na32_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na32_2_i) );
// C_///ORAND/D      x5y76     80'h00_FE00_80_0000_0C08_FFE5
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a34_4 ( .OUT(na34_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na36_2), .IN4(na194_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a34_5 ( .OUT(na34_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na34_2_i) );
// C_///AND/      x6y77     80'h00_0060_00_0000_0C08_FF85
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a36_4 ( .OUT(na36_2), .IN1(~na44_2), .IN2(1'b1), .IN3(na9_1), .IN4(na4_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x11y75     80'h00_0078_00_0000_0C88_C8AA
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a38_1 ( .OUT(na38_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na64_1), .IN6(na62_1), .IN7(1'b1), .IN8(na40_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a38_4 ( .OUT(na38_2), .IN1(na158_1), .IN2(1'b1), .IN3(na164_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D///      x8y80     80'h00_FE00_00_0000_0C88_E5FF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a40_1 ( .OUT(na40_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na42_2), .IN8(na197_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a40_2 ( .OUT(na40_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na40_1_i) );
// C_ORAND////      x13y76     80'h00_0018_00_0000_0888_3F37
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a41_1 ( .OUT(na41_1), .IN1(~na38_2), .IN2(~na34_2), .IN3(1'b0), .IN4(~na85_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b0), .IN8(~na85_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x10y77     80'h00_0060_00_0000_0C08_FF25
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a42_4 ( .OUT(na42_2), .IN1(~na38_2), .IN2(1'b1), .IN3(na43_2), .IN4(~na40_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x10y79     80'h00_0060_00_0000_0C08_FF34
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a43_4 ( .OUT(na43_2), .IN1(~na38_1), .IN2(na14_2), .IN3(1'b1), .IN4(~na85_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND*/D      x9y75     80'h00_FE00_80_0000_0C07_FFF1
C_AND      #(.CPE_CFG (9'b1_1000_0000)) 
           _a44_4 ( .OUT(na44_2_i), .IN1(~na123_1), .IN2(~na45_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0100)) 
           _a44_5 ( .OUT(na44_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na44_2_i) );
// C_AND*/D///      x11y76     80'h00_FE00_00_0000_0388_55FF
C_AND      #(.CPE_CFG (9'b1_0000_0000)) 
           _a45_1 ( .OUT(na45_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b1), .IN7(~na152_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0000)) 
           _a45_2 ( .OUT(na45_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na45_1_i) );
// C_MX4b/D///      x8y81     80'h00_FE00_00_0040_0A50_003A
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a46_1 ( .OUT(na46_1_i), .IN1(na123_1), .IN2(1'b1), .IN3(1'b1), .IN4(~na47_1), .IN5(na44_2), .IN6(1'b0), .IN7(na46_1), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a46_2 ( .OUT(na46_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na46_1_i) );
// C_AND////      x12y78     80'h00_0018_00_0000_0888_3134
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a47_1 ( .OUT(na47_1), .IN1(~na64_1), .IN2(na14_2), .IN3(1'b1), .IN4(~na85_1), .IN5(~na38_2), .IN6(~na62_1), .IN7(1'b1),
                    .IN8(~na40_1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x7y82     80'h00_FE00_00_0040_0AA0_00C5
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a49_1 ( .OUT(na49_1_i), .IN1(~na123_1), .IN2(1'b1), .IN3(1'b1), .IN4(na17_1), .IN5(1'b0), .IN6(na49_1), .IN7(1'b0), .IN8(na237_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a49_2 ( .OUT(na49_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na49_1_i) );
// C_AND////      x8y69     80'h00_0018_00_0000_0C88_5CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a51_1 ( .OUT(na51_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na113_1), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x9y71     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a52_1 ( .OUT(na52_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na204_1), .IN8(na53_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a52_2 ( .OUT(na52_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na52_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a52_4 ( .OUT(na52_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na51_1), .IN4(na200_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a52_5 ( .OUT(na52_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na52_2_i) );
// C_///AND/      x4y74     80'h00_0060_00_0000_0C08_FF5C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a53_4 ( .OUT(na53_2), .IN1(1'b1), .IN2(na113_2), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x10y69     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a54_1 ( .OUT(na54_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na208_2), .IN8(na55_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a54_2 ( .OUT(na54_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na54_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a54_4 ( .OUT(na54_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na57_2), .IN4(na212_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a54_5 ( .OUT(na54_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na54_2_i) );
// C_///AND/      x8y70     80'h00_0060_00_0000_0C08_FF5A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a55_4 ( .OUT(na55_2), .IN1(na111_2), .IN2(1'b1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x8y71     80'h00_0060_00_0000_0C08_FF5A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a57_4 ( .OUT(na57_2), .IN1(na111_1), .IN2(1'b1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND/D//ORAND/D      x8y68     80'h00_FE00_80_0000_0C88_E5E5
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a58_1 ( .OUT(na58_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b0), .IN7(na59_1), .IN8(na216_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a58_2 ( .OUT(na58_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na58_1_i) );
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a58_4 ( .OUT(na58_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na163_2), .IN4(na19_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a58_5 ( .OUT(na58_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na58_2_i) );
// C_AND////      x4y69     80'h00_0018_00_0000_0C88_5CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a59_1 ( .OUT(na59_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na109_2), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND/D      x5y70     80'h00_FE00_80_0000_0C08_FFE5
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a60_4 ( .OUT(na60_2_i), .IN1(~na123_1), .IN2(1'b0), .IN3(na61_2), .IN4(na220_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a60_5 ( .OUT(na60_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na60_2_i) );
// C_///AND/      x8y69     80'h00_0060_00_0000_0C08_FF5C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a61_4 ( .OUT(na61_2), .IN1(1'b1), .IN2(na109_1), .IN3(~na156_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x11y78     80'h00_FE00_00_0040_0A30_00C3
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a62_1 ( .OUT(na62_1_i), .IN1(1'b1), .IN2(~na41_1), .IN3(1'b1), .IN4(na242_2), .IN5(na63_1), .IN6(na62_1), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a62_2 ( .OUT(na62_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na62_1_i) );
// C_AND////      x11y81     80'h00_0018_00_0000_0C88_8FFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a63_1 ( .OUT(na63_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na43_2), .IN8(na119_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x9y81     80'h00_FE00_00_0040_0A30_00CC
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a64_1 ( .OUT(na64_1_i), .IN1(1'b1), .IN2(na41_1), .IN3(1'b1), .IN4(na242_2), .IN5(na64_1), .IN6(na65_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a64_2 ( .OUT(na64_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na64_1_i) );
// C_///AND/      x9y82     80'h00_0060_00_0000_0C08_FF8F
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a65_4 ( .OUT(na65_2), .IN1(1'b1), .IN2(1'b1), .IN3(na43_2), .IN4(na119_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x10y74     80'h00_0018_00_0000_0C88_5AFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a67_1 ( .OUT(na67_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na108_1), .IN6(1'b1), .IN7(~na156_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND/D//AND/D      x6y78     80'h00_FE00_80_0000_0C88_3544
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a85_1 ( .OUT(na85_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na123_1), .IN6(1'b1), .IN7(1'b1), .IN8(~na228_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a85_2 ( .OUT(na85_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na85_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a85_4 ( .OUT(na85_2_i), .IN1(~na38_2), .IN2(na14_2), .IN3(~na241_2), .IN4(na85_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a85_5 ( .OUT(na85_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na85_2_i) );
// C_ADDF2///ADDF2/      x6y74     80'h00_0078_00_0020_0C66_0505
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a88_1 ( .OUT(na88_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na28_1), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(na101_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a88_4 ( .OUT(na88_2), .COUTY1(na88_4), .IN1(~na28_2), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(~na28_1), .IN6(1'b1), .IN7(1'b0),
                    .IN8(1'b0), .CINX(1'b0), .CINY1(na101_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y75     80'h00_0078_00_0020_0C66_5030
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a90_1 ( .OUT(na90_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(~na32_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(na88_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a90_4 ( .OUT(na90_2), .COUTY1(na90_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(~na1_1), .IN5(1'b0), .IN6(1'b0), .IN7(~na32_1),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(na88_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x6y76     80'h00_0018_00_0010_0666_0030
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a92_1 ( .OUT(na92_1), .COUTY1(na92_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(~na1_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0),
                    .IN8(1'b0), .CINX(1'b0), .CINY1(na90_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y69     80'h00_0078_00_0020_0C66_333F
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a93_1 ( .OUT(na93_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na60_2), .IN7(1'b1), .IN8(~na58_2),
                    .CINX(1'b0), .CINY1(na102_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a93_4 ( .OUT(na93_2), .COUTY1(na93_4), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(~na58_1), .IN5(1'b1), .IN6(~na60_2), .IN7(1'b1),
                    .IN8(~na58_2), .CINX(1'b0), .CINY1(na102_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y70     80'h00_0078_00_0020_0C66_505F
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a95_1 ( .OUT(na95_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(~na54_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(na93_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a95_4 ( .OUT(na95_2), .COUTY1(na95_4), .IN1(1'b1), .IN2(1'b1), .IN3(~na54_1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(~na54_2),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(na93_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y71     80'h00_0078_00_0020_0C66_05F5
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a97_1 ( .OUT(na97_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na52_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(na95_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a97_4 ( .OUT(na97_2), .COUTY1(na97_4), .IN1(~na52_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na52_2), .IN6(1'b1), .IN7(1'b0),
                    .IN8(1'b0), .CINX(1'b0), .CINY1(na95_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y72     80'h00_0078_00_0020_0C66_5050
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a99_1 ( .OUT(na99_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(~na20_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(na97_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a99_4 ( .OUT(na99_2), .COUTY1(na99_4), .IN1(1'b0), .IN2(1'b0), .IN3(~na32_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(~na20_1),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(na97_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x6y73     80'h00_0078_00_0020_0C66_0303
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a101_1 ( .OUT(na101_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na26_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na99_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a101_4 ( .OUT(na101_2), .COUTY1(na101_4), .IN1(1'b1), .IN2(~na26_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na26_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na99_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x6y68     80'h00_3F00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a102_2 ( .OUT(na102_1), .CLK(1'b1), .EN(1'b0), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a102_6 ( .COUTY1(na102_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na102_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x7y75     80'h00_0078_00_0020_0C66_0A0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a104_1 ( .OUT(na104_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na28_1), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na117_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a104_4 ( .OUT(na104_2), .COUTY1(na104_4), .IN1(na28_2), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(na28_1), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na117_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y76     80'h00_0078_00_0020_0C66_A0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a106_1 ( .OUT(na106_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na32_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na104_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a106_4 ( .OUT(na106_2), .COUTY1(na106_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na1_1), .IN5(1'b0), .IN6(1'b0), .IN7(na32_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na104_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x7y77     80'h00_0018_00_0010_0666_00C0
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a108_1 ( .OUT(na108_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na1_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na106_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y70     80'h00_0078_00_0020_0C66_CCC0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a109_1 ( .OUT(na109_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na60_2), .IN7(1'b1), .IN8(na58_2),
                     .CINX(1'b0), .CINY1(na118_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a109_4 ( .OUT(na109_2), .COUTY1(na109_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na58_1), .IN5(1'b1), .IN6(na60_2), .IN7(1'b1),
                     .IN8(na58_2), .CINX(1'b0), .CINY1(na118_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y71     80'h00_0078_00_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a111_1 ( .OUT(na111_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na54_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na109_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a111_4 ( .OUT(na111_2), .COUTY1(na111_4), .IN1(1'b0), .IN2(1'b0), .IN3(na54_1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na54_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na109_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y72     80'h00_0078_00_0020_0C66_0A0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a113_1 ( .OUT(na113_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na52_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na111_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a113_4 ( .OUT(na113_2), .COUTY1(na113_4), .IN1(na52_1), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(na52_2), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na111_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y73     80'h00_0078_00_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a115_1 ( .OUT(na115_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na20_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na113_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a115_4 ( .OUT(na115_2), .COUTY1(na115_4), .IN1(1'b0), .IN2(1'b0), .IN3(na32_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na20_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na113_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y74     80'h00_0078_00_0020_0C66_0C0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a117_1 ( .OUT(na117_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na26_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na115_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a117_4 ( .OUT(na117_2), .COUTY1(na117_4), .IN1(1'b1), .IN2(na26_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na26_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na115_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x7y69     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a118_2 ( .OUT(na118_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a118_6 ( .COUTY1(na118_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na118_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x10y80     80'h00_0078_00_0020_0C66_CA0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a119_1 ( .OUT(na119_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na64_1), .IN6(1'b1), .IN7(1'b1), .IN8(na40_1),
                     .CINX(1'b0), .CINY1(na161_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a119_4 ( .OUT(na119_2), .IN1(1'b1), .IN2(na62_1), .IN3(1'b0), .IN4(1'b0), .IN5(na64_1), .IN6(1'b1), .IN7(1'b1), .IN8(na40_1),
                     .CINX(1'b0), .CINY1(na161_4), .PINX(1'b0), .PINY1(1'b0) );
GLBOUT     #(.GLBOUT_CFG (64'h0000_0000_0000_0010)) 
           _a122 ( .GLB0(na122_1), .GLB1(_d3), .GLB2(_d4), .GLB3(_d5), .CLK_FB0(_d6), .CLK_FB1(_d7), .CLK_FB2(_d8), .CLK_FB3(_d9),
                   .CLK0_0(1'b0), .CLK0_90(1'b0), .CLK0_180(1'b0), .CLK0_270(1'b0), .CLK0_BYP(na3_1), .CLK1_0(1'b0), .CLK1_90(1'b0),
                   .CLK1_180(1'b0), .CLK1_270(1'b0), .CLK1_BYP(1'b0), .CLK2_0(1'b0), .CLK2_90(1'b0), .CLK2_180(1'b0), .CLK2_270(1'b0),
                   .CLK2_BYP(1'b0), .CLK3_0(1'b0), .CLK3_90(1'b0), .CLK3_180(1'b0), .CLK3_270(1'b0), .CLK3_BYP(1'b0), .USR_GLB0(1'b0),
                   .USR_GLB1(1'b0), .USR_GLB2(1'b0), .USR_GLB3(1'b0), .USR_FB0(1'b0), .USR_FB1(1'b0), .USR_FB2(1'b0), .USR_FB3(1'b0) );
// C_AND/D///      x5y73     80'h00_FE00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a123_1 ( .OUT(na123_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na154_2), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0000)) 
           _a123_2 ( .OUT(na123_1), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na123_1_i) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000090)) 
           _a150 ( .Y(na150_1), .I(clk0_0__io) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a151 ( .O(led_0__io), .A(na229_10) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000010)) 
           _a152 ( .Y(na152_1), .I(uart_0__rx__io) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a153 ( .O(uart_0__tx__io), .A(na230_10) );
// C_///AND/D      x7y78     80'h00_FE00_80_0000_0C08_FF00
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a154_4 ( .OUT(na154_2_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0100)) 
           _a154_5 ( .OUT(na154_2), .CLK(na122_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na154_2_i) );
// C_///AND/      x4y77     80'h00_0060_00_0000_0C08_FFC3
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a155_4 ( .OUT(na155_2), .IN1(1'b1), .IN2(~na15_1), .IN3(1'b1), .IN4(na1_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND/      x4y73     80'h00_0060_00_0000_0C08_FFD7
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a156_4 ( .OUT(na156_2), .IN1(~na38_2), .IN2(~na14_2), .IN3(~na9_1), .IN4(na4_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR////      x11y71     80'h00_0018_00_0000_0EEE_A7CA
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a158_1 ( .OUT(na158_1), .IN1(na52_2), .IN2(1'b0), .IN3(1'b0), .IN4(na58_2), .IN5(~na52_1), .IN6(~na159_1), .IN7(na20_1),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x7y68     80'h00_0018_00_0000_0888_8C4F
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a159_1 ( .OUT(na159_1), .IN1(1'b1), .IN2(1'b1), .IN3(~na54_2), .IN4(na58_1), .IN5(1'b1), .IN6(na60_2), .IN7(na54_1), .IN8(na11_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR////      x10y77     80'h00_0018_00_0000_0CEE_7500
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a160_1 ( .OUT(na160_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na44_2), .IN6(1'b0), .IN7(~na9_1), .IN8(~na4_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x10y79     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a161_2 ( .OUT(na161_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a161_6 ( .COUTY1(na161_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na161_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_///AND/      x4y71     80'h00_0060_00_0000_0C08_FFC3
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a163_4 ( .OUT(na163_2), .IN1(1'b1), .IN2(~na15_1), .IN3(1'b1), .IN4(na58_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_Route1////      x6y77     80'h00_0018_00_0050_0C66_0000
C_Route1   #(.CPE_CFG (9'b0_0001_0000)) 
           _a164_1 ( .OUT(na164_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0), .CINX(1'b0),
                     .CINY1(na92_4), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x10y74     80'h00_0060_00_0000_0C08_FFA3
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a167_4 ( .OUT(na167_2), .IN1(1'b1), .IN2(~na15_1), .IN3(na20_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x10y73     80'h00_0078_00_0000_0C88_A3A3
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a171_1 ( .OUT(na171_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na15_1), .IN7(na32_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a171_4 ( .OUT(na171_2), .IN1(1'b1), .IN2(~na15_1), .IN3(na32_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y74     80'h00_0018_00_0000_0C88_F4FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a175_1 ( .OUT(na175_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na231_2), .IN6(na26_2), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x4y75     80'h00_0060_00_0000_0C08_FFF4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a179_4 ( .OUT(na179_2), .IN1(~na231_2), .IN2(na26_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x12y75     80'h00_0078_00_0000_0C88_F2F2
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a187_1 ( .OUT(na187_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na28_2), .IN6(~na15_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a187_4 ( .OUT(na187_2), .IN1(na28_1), .IN2(~na15_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x10y78     80'h00_0018_00_0000_0C88_BCFF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a194_1 ( .OUT(na194_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(na14_2), .IN7(na236_2), .IN8(~na85_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x14y80     80'h00_0018_00_0000_0C88_C3FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a197_1 ( .OUT(na197_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na41_1), .IN7(1'b1), .IN8(na40_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x4y72     80'h00_0018_00_0000_0C88_F2FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a200_1 ( .OUT(na200_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na52_2), .IN6(~na15_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x4y75     80'h00_0018_00_0000_0C88_F2FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a204_1 ( .OUT(na204_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na52_1), .IN6(~na15_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x10y71     80'h00_0060_00_0000_0C08_FFA3
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a208_4 ( .OUT(na208_2), .IN1(1'b1), .IN2(~na15_1), .IN3(na54_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x12y72     80'h00_0060_00_0000_0C08_FFA3
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a212_4 ( .OUT(na212_2), .IN1(1'b1), .IN2(~na15_1), .IN3(na54_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x8y70     80'h00_0018_00_0000_0C88_C3FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a216_1 ( .OUT(na216_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na15_1), .IN7(1'b1), .IN8(na58_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x4y70     80'h00_0060_00_0000_0C08_FFF4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a220_4 ( .OUT(na220_2), .IN1(~na232_2), .IN2(na60_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y77     80'h00_0018_00_0000_0C88_C3FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a224_1 ( .OUT(na224_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na15_1), .IN7(1'b1), .IN8(na1_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b////      x11y77     80'h00_0018_00_0040_0A17_00CA
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a227_1 ( .OUT(na227_1), .IN1(na38_2), .IN2(1'b1), .IN3(1'b1), .IN4(na85_1), .IN5(~na38_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x14y74     80'h00_0018_00_0000_0888_5FDB
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a228_1 ( .OUT(na228_1), .IN1(na227_1), .IN2(~na14_2), .IN3(~na9_1), .IN4(na4_1), .IN5(1'b1), .IN6(1'b1), .IN7(~na9_2), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x1y95     80'h08_0060_00_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a229_4 ( .OUT(na229_2), .IN1(1'b1), .IN2(na49_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a229_6 ( .RAM_O2(na229_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na229_2), .COMP_OUT(1'b0) );
// C_///AND/      x1y51     80'h08_0060_00_0000_0C08_FFF0
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a230_4 ( .OUT(na230_2), .IN1(1'b0), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1), .CINX(1'b0),
                     .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a230_6 ( .RAM_O2(na230_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na230_2), .COMP_OUT(1'b0) );
// C_////Bridge      x5y75     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a231_5 ( .OUT(na231_2), .IN1(1'b0), .IN2(na15_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x5y69     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a232_5 ( .OUT(na232_2), .IN1(1'b0), .IN2(na15_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x5y73     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a233_5 ( .OUT(na233_2), .IN1(1'b0), .IN2(na26_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x9y76     80'h00_00A4_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a234_5 ( .OUT(na234_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na28_1), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x11y74     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a235_5 ( .OUT(na235_2), .IN1(1'b0), .IN2(1'b0), .IN3(na32_1), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x12y77     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a236_5 ( .OUT(na236_2), .IN1(na38_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x10y82     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a237_5 ( .OUT(na237_2), .IN1(1'b0), .IN2(1'b0), .IN3(na46_1), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x9y72     80'h00_00A4_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a238_5 ( .OUT(na238_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na52_1), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x5y71     80'h00_00A6_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a239_5 ( .OUT(na239_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na54_1), .IN8(1'b0) );
// C_////Bridge      x14y77     80'h00_00A7_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a240_5 ( .OUT(na240_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(na85_1) );
// C_////Bridge      x8y77     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a241_5 ( .OUT(na241_2), .IN1(na123_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x12y80     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a242_5 ( .OUT(na242_2), .IN1(na123_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
endmodule
