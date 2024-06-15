//  (c) Cologne Chip AG
//  FPGA Verilog netlist writer     Version: Version 4.2 (1 May 2024)
//  Compile Time: 2024-06-04 20:41:17
//  Program Run:  2024-06-10 00:54:55
//  Program Call: /home/tibrahimovic/0.git-repo/cc-toolchain-linux/cc-toolchain-linux/bin/p_r/p_r -i net/top_synth.v -o top -ccf /home/tibrahimovic/projects/2.Simple--1/3.build/../1.hw/constraints/constraints.ccf -cCP --verbose 
//  File Type:    Verilog

// Gatecount:    190
module top (arst_n , clk , uart_rx ,
       led , received , sent , tick_1us , uart_tx 
       ) ;

input  arst_n;
input  clk;
input  uart_rx;

output led;
output received;
output sent;
output tick_1us;
output uart_tx;



wire clk;
wire led;
wire sent;
wire na1_2;
wire na1_2_i;
wire na2_1;
wire na2_2;
wire na4_1;
wire na4_1_i;
wire na6_1;
wire na6_1_i;
wire na6_2;
wire na6_2_i;
wire na7_1;
wire na7_1_i;
wire na7_2;
wire na7_2_i;
wire na9_1;
wire na9_1_i;
wire arst_n;
wire na10_1;
wire na10_1_i;
wire na10_2;
wire na10_2_i;
wire na12_1;
wire na12_2;
wire na13_1;
wire na16_1;
wire na16_1_i;
wire na18_1;
wire na19_1;
wire na20_2;
wire na21_1;
wire na24_2;
wire na25_1;
wire na26_1;
wire na27_2;
wire na27_2_i;
wire na28_2;
wire na29_2;
wire na30_1;
wire na31_1;
wire na31_1_i;
wire na32_1;
wire na33_1;
wire na33_1_i;
wire na35_2;
wire na36_1;
wire na38_1;
wire na40_1;
wire na40_2;
wire na41_1;
wire na45_2;
wire na45_2_i;
wire na46_1;
wire na46_1_i;
wire na47_1;
wire na49_1;
wire na49_2;
wire na52_2;
wire na54_1;
wire na54_2;
wire na58_1;
wire na58_1_i;
wire na58_2;
wire na58_2_i;
wire na59_2;
wire na61_1;
wire na61_1_i;
wire na63_2;
wire na65_1;
wire na65_2;
wire na66_1;
wire na67_1;
wire na67_1_i;
wire na68_1;
wire na68_1_i;
wire na73_2;
wire na74_2;
wire na75_2;
wire na78_2;
wire na78_2_i;
wire na82_1;
wire na87_2;
wire na87_2_i;
wire na90_1;
wire na91_1;
wire na94_1;
wire na95_2;
wire na96_1;
wire na97_1;
wire na98_2;
wire na99_1;
wire na100_1;
wire na101_2;
wire na102_1;
wire na103_1;
wire na103_1_i;
wire na105_1;
wire na106_1;
wire na108_1;
wire na108_2;
wire na108_4;
wire na110_1;
wire na110_2;
wire na110_4;
wire na112_1;
wire na113_1;
wire na113_4;
wire na115_1;
wire na115_1_i;
wire na115_2;
wire na115_2_i;
wire na115_4;
wire na117_1;
wire na117_1_i;
wire na117_2;
wire na117_2_i;
wire na117_4;
wire na119_1;
wire na119_1_i;
wire na119_2;
wire na119_2_i;
wire na119_4;
wire na121_1;
wire na121_1_i;
wire na121_2;
wire na121_2_i;
wire na121_4;
wire na123_1;
wire na123_1_i;
wire na123_2;
wire na123_2_i;
wire na123_4;
wire na124_1;
wire na124_1_i;
wire na124_2;
wire na124_2_i;
wire na124_4;
wire na126_1;
wire na126_1_i;
wire na126_2;
wire na126_2_i;
wire na126_4;
wire na128_1;
wire na128_1_i;
wire na128_2;
wire na128_2_i;
wire na128_4;
wire na130_1;
wire na130_1_i;
wire na130_2;
wire na130_2_i;
wire na130_4;
wire na132_1;
wire na132_1_i;
wire na134_1;
wire na134_1_i;
wire na134_2;
wire na134_2_i;
wire na134_4;
wire na136_1;
wire na136_1_i;
wire na136_2;
wire na136_2_i;
wire na136_4;
wire na138_1;
wire na138_1_i;
wire na138_2;
wire na138_2_i;
wire na138_4;
wire na140_1;
wire na140_1_i;
wire na140_2;
wire na140_2_i;
wire na140_4;
wire na141_1;
wire na141_4;
wire na142_1;
wire na142_2;
wire na144_1;
wire na144_4;
wire na145_1;
wire na145_2;
wire na145_4;
wire na147_1;
wire na148_1;
wire na148_4;
wire na149_1;
wire na149_2;
wire na149_4;
wire na151_1;
wire na153_1;
wire na172_1;
wire na172_1_i;
wire na175_2;
wire na175_2_i;
wire na176_1;
wire na176_1_i;
wire na176_2;
wire na176_2_i;
wire na177_1;
wire na177_1_i;
wire na177_2;
wire na177_2_i;
wire na178_1;
wire na178_1_i;
wire na178_2;
wire na178_2_i;
wire na179_2;
wire na179_2_i;
wire na183_1;
wire na183_1_i;
wire na184_2;
wire na184_2_i;
wire na186_1;
wire na186_1_i;
wire na188_2;
wire na188_2_i;
wire na189_1;
wire na189_1_i;
wire na190_2;
wire na190_2_i;
wire na196_1;
wire na196_1_i;
wire na197_2;
wire na197_2_i;
wire na198_1;
wire na198_1_i;
wire na199_2;
wire na199_2_i;
wire na200_1;
wire na200_1_i;
wire na201_2;
wire na201_2_i;
wire na202_1;
wire na202_1_i;
wire na203_2;
wire na203_2_i;
wire na208_1;
wire na208_1_i;
wire na209_2;
wire na209_2_i;
wire na210_1;
wire na210_1_i;
wire na211_2;
wire na211_2_i;
wire na212_1;
wire na212_1_i;
wire na213_2;
wire na213_2_i;
wire na214_1;
wire na214_1_i;
wire na215_2;
wire na215_2_i;
wire na218_1;
wire na218_1_i;
wire na219_2;
wire na219_2_i;
wire na220_1;
wire na220_1_i;
wire na220_2;
wire na220_2_i;
wire na222_1;
wire na222_1_i;
wire na223_1;
wire na223_1_i;
wire na223_2;
wire na223_2_i;
wire na225_1;
wire na225_1_i;
wire na225_2;
wire na225_2_i;
wire na227_2;
wire na227_2_i;
wire na229_1;
wire na229_1_i;
wire na230_2;
wire na230_2_i;
wire na231_1;
wire na231_1_i;
wire na232_2;
wire na232_2_i;
wire na233_1;
wire na233_1_i;
wire na234_2;
wire na234_2_i;
wire na235_1;
wire na235_1_i;
wire na236_2;
wire na236_2_i;
wire na237_1;
wire na237_1_i;
wire na241_2;
wire na241_2_i;
wire na242_1;
wire na242_1_i;
wire na258_1;
wire na259_1;
wire na260_1;
wire na261_1;
wire na266_1;
wire na268_3;
wire na268_4;
wire na268_5;
wire na268_6;
wire na269_1;
wire na270_1;
wire na270_4;
wire na271_1;
wire na274_1;
wire na279_1;
wire na281_2;
wire na282_1;
wire na283_1;
wire na284_2;
wire na285_2;
wire na289_1;
wire na290_1;
wire na291_1;
wire na292_1;
wire na294_1;
wire na299_1;
wire na304_1;
wire na305_2;
wire na306_2;
wire na307_2;
wire na308_2;
wire na309_2;
wire na310_2;
wire na311_2;
wire na312_2;
wire na313_2;
wire na314_2;
wire na315_2;
wire na316_2;
wire na317_2;
wire na318_2;
wire na319_2;
wire na320_2;
wire na321_2;
wire na322_2;
wire na323_2;
wire na324_2;
wire na325_2;
wire na326_2;
wire na327_2;
wire na328_2;
wire na329_2;
wire na330_2;
wire na331_2;
wire na332_2;
wire na333_2;
wire uart_rx;
wire uart_tx;
wire na305_10;
wire na306_10;
wire na307_10;
wire na308_10;
wire na309_10;
wire received;
wire tick_1us;

// C_///AND/D      x51y41     80'h00_EE00_80_0000_0C08_FFF1
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a1_4 ( .OUT(na1_2_i), .IN1(~na1_2), .IN2(~na2_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a1_5 ( .OUT(na1_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na1_2_i) );
// C_AND////D      x53y42     80'h00_FA18_00_0000_0888_3C82
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a2_1 ( .OUT(na2_1), .IN1(na1_2), .IN2(~na7_1), .IN3(na4_1), .IN4(na6_2), .IN5(1'b1), .IN6(na7_2), .IN7(1'b1), .IN8(~na6_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a2_5 ( .OUT(na2_2), .CLK(na153_1), .EN(na260_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na2_1) );
// C_AND/D///      x52y41     80'h00_EE00_00_0000_0C88_C3FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a4_1 ( .OUT(na4_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na2_1), .IN7(1'b1), .IN8(na108_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a4_2 ( .OUT(na4_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na4_1_i) );
// C_AND/D//AND/D      x54y44     80'h00_EE00_80_0000_0C88_A3C3
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a6_1 ( .OUT(na6_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na2_1), .IN7(na110_1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a6_2 ( .OUT(na6_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na6_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a6_4 ( .OUT(na6_2_i), .IN1(1'b1), .IN2(~na2_1), .IN3(1'b1), .IN4(na108_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a6_5 ( .OUT(na6_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na6_2_i) );
// C_AND/D//AND/D      x53y44     80'h00_EE00_80_0000_0C88_A3C3
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a7_1 ( .OUT(na7_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na2_1), .IN7(na110_2), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a7_2 ( .OUT(na7_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na7_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a7_4 ( .OUT(na7_2_i), .IN1(1'b1), .IN2(~na2_1), .IN3(1'b1), .IN4(na112_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a7_5 ( .OUT(na7_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na7_2_i) );
// C_MX2b/D///      x46y59     80'h00_FA00_00_0040_0A30_000C
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a9_1 ( .OUT(na9_1_i), .IN1(1'b1), .IN2(na326_2), .IN3(1'b0), .IN4(1'b0), .IN5(na258_1), .IN6(na259_1), .IN7(1'b0), .IN8(1'b0),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a9_2 ( .OUT(na9_1), .CLK(na153_1), .EN(na101_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na9_1_i) );
// C_AND/D//AND/D      x45y58     80'h00_FA00_80_0000_0C88_AC5C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a10_1 ( .OUT(na10_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na269_1), .IN7(na142_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a10_2 ( .OUT(na10_1), .CLK(na153_1), .EN(na65_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na10_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a10_4 ( .OUT(na10_2_i), .IN1(1'b1), .IN2(na269_1), .IN3(~na311_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a10_5 ( .OUT(na10_2), .CLK(na153_1), .EN(na65_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na10_2_i) );
// C_AND////D      x47y50     80'h00_EE18_00_0000_0888_F3CA
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a12_1 ( .OUT(na12_1), .IN1(na13_1), .IN2(1'b1), .IN3(1'b1), .IN4(na175_2), .IN5(1'b1), .IN6(~na12_2), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a12_5 ( .OUT(na12_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na12_1) );
// C_AND////      x55y47     80'h00_0018_00_0000_0888_31F4
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a13_1 ( .OUT(na13_1), .IN1(~na31_1), .IN2(na2_2), .IN3(1'b1), .IN4(1'b1), .IN5(~na27_2), .IN6(~na103_1), .IN7(1'b1), .IN8(~na16_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND*/D///      x54y46     80'h00_EE00_00_0000_0788_5F3D
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a16_1 ( .OUT(na16_1_i), .IN1(~na24_2), .IN2(na20_2), .IN3(1'b0), .IN4(~na18_1), .IN5(1'b1), .IN6(1'b1), .IN7(~na87_2), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a16_2 ( .OUT(na16_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na16_1_i) );
// C_AND////      x56y46     80'h00_0018_00_0000_0888_1431
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a18_1 ( .OUT(na18_1), .IN1(~na27_2), .IN2(~na103_1), .IN3(1'b1), .IN4(~na16_1), .IN5(~na31_1), .IN6(na2_2), .IN7(~na19_1),
                    .IN8(~na175_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x54y47     80'h00_0018_00_0000_0C88_13FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a19_1 ( .OUT(na19_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na68_1), .IN7(~na178_1), .IN8(~na331_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x49y46     80'h00_0060_00_0000_0C08_FF1A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a20_4 ( .OUT(na20_2), .IN1(na13_1), .IN2(1'b1), .IN3(~na21_1), .IN4(~na175_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x52y47     80'h00_0018_00_0000_0888_311F
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a21_1 ( .OUT(na21_1), .IN1(1'b1), .IN2(1'b1), .IN3(~na177_1), .IN4(~na329_2), .IN5(~na179_2), .IN6(~na176_2), .IN7(1'b1),
                    .IN8(~na328_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///XOR/      x49y47     80'h00_0060_00_0000_0C06_FFCC
C_XOR      #(.CPE_CFG (9'b0_1000_0000)) 
           _a24_4 ( .OUT(na24_2), .IN1(1'b0), .IN2(na25_1), .IN3(1'b0), .IN4(na16_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x51y44     80'h00_0018_00_0000_0C88_ACFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a25_1 ( .OUT(na25_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na2_2), .IN7(na274_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x46y50     80'h00_0018_00_0000_0C88_11FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a26_1 ( .OUT(na26_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na330_2), .IN6(~na68_1), .IN7(~na178_2), .IN8(~na175_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND*/D      x47y49     80'h00_EE00_80_0000_0C07_FFE3
C_ORAND    #(.CPE_CFG (9'b1_1000_0000)) 
           _a27_4 ( .OUT(na27_2_i), .IN1(1'b0), .IN2(~na28_2), .IN3(na29_2), .IN4(na30_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a27_5 ( .OUT(na27_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na27_2_i) );
// C_///AND/      x49y48     80'h00_0060_00_0000_0C08_FF12
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a28_4 ( .OUT(na28_2), .IN1(na13_1), .IN2(~na324_2), .IN3(~na19_1), .IN4(~na175_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND/      x54y51     80'h00_0060_00_0000_0C08_FF3E
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a29_4 ( .OUT(na29_2), .IN1(na13_1), .IN2(na324_2), .IN3(1'b0), .IN4(~na175_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2b////      x50y46     80'h00_0018_00_0040_0A33_0003
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a30_1 ( .OUT(na30_1), .IN1(1'b1), .IN2(~na25_1), .IN3(1'b0), .IN4(1'b0), .IN5(~na145_1), .IN6(~na313_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR/D///      x51y47     80'h00_EE00_00_0000_0CEE_EC00
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a31_1 ( .OUT(na31_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(na20_2), .IN7(na87_2), .IN8(na32_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a31_2 ( .OUT(na31_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na31_1_i) );
// C_MX4b////      x52y52     80'h00_0018_00_0040_0A30_00CC
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a32_1 ( .OUT(na32_1), .IN1(1'b1), .IN2(na25_1), .IN3(1'b1), .IN4(na18_1), .IN5(na31_1), .IN6(na147_1), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR/DST///      x50y47     80'h20_BA00_00_0000_0EEE_57CE
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a33_1 ( .OUT(na33_1_i), .IN1(na285_2), .IN2(na283_1), .IN3(1'b0), .IN4(na281_2), .IN5(~na282_1), .IN6(~na284_2), .IN7(~na279_1),
                    .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_DST      #(.CPE_CFG (9'bX_0100_0000)) 
           _a33_2 ( .OUT(na33_1), .CLK(na153_1), .EN(na106_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                    .D_IN(na33_1_i) );
// C_///AND/      x46y46     80'h00_0060_00_0000_0C08_FFA8
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a35_4 ( .OUT(na35_2), .IN1(na196_1), .IN2(na315_2), .IN3(na67_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x45y43     80'h00_0018_00_0000_0C88_11FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a36_1 ( .OUT(na36_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na58_1), .IN6(~na61_1), .IN7(~na46_1), .IN8(~na322_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x49y51     80'h00_0018_00_0000_0C88_C8FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a38_1 ( .OUT(na38_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na316_2), .IN6(na41_1), .IN7(1'b1), .IN8(na40_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x50y50     80'h00_0078_00_0000_0C88_3515
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a40_1 ( .OUT(na40_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na223_2), .IN6(1'b1), .IN7(1'b1), .IN8(~na219_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a40_4 ( .OUT(na40_2), .IN1(~na223_1), .IN2(1'b1), .IN3(~na67_1), .IN4(~na220_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x47y52     80'h00_0018_00_0000_0C88_13FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a41_1 ( .OUT(na41_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na222_1), .IN7(~na225_2), .IN8(~na220_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/D      x46y60     80'h00_FA00_80_0000_0C08_FFAC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a45_4 ( .OUT(na45_2_i), .IN1(1'b1), .IN2(na269_1), .IN3(na142_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a45_5 ( .OUT(na45_2), .CLK(na153_1), .EN(na65_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na45_2_i) );
// C_ORAND*/D///      x50y43     80'h00_EE00_00_0000_0788_5F5E
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a46_1 ( .OUT(na46_1_i), .IN1(na47_1), .IN2(na289_1), .IN3(~na54_1), .IN4(1'b0), .IN5(1'b1), .IN6(1'b1), .IN7(~na78_2), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a46_2 ( .OUT(na46_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na46_1_i) );
// C_AND////      x49y47     80'h00_0018_00_0000_0C88_8FFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a47_1 ( .OUT(na47_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na290_1), .IN8(na40_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x51y49     80'h00_0078_00_0000_0C88_F84C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a49_1 ( .OUT(na49_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na36_1), .IN6(na2_2), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a49_4 ( .OUT(na49_2), .IN1(1'b1), .IN2(na41_1), .IN3(~na225_1), .IN4(na40_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x49y41     80'h00_0060_00_0000_0C08_FF1C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a52_4 ( .OUT(na52_2), .IN1(1'b1), .IN2(na2_2), .IN3(~na46_1), .IN4(~na292_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND///AND/      x48y43     80'h00_0078_00_0000_0C88_3838
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a54_1 ( .OUT(na54_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na36_1), .IN6(na2_2), .IN7(1'b1), .IN8(~na40_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a54_4 ( .OUT(na54_2), .IN1(na149_1), .IN2(na2_2), .IN3(1'b1), .IN4(~na292_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND/D//AND/D      x47y41     80'h00_EE00_80_0000_0C88_55F1
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a58_1 ( .OUT(na58_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na47_1), .IN6(1'b1), .IN7(~na299_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a58_2 ( .OUT(na58_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na58_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a58_4 ( .OUT(na58_2_i), .IN1(~na47_1), .IN2(~na294_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a58_5 ( .OUT(na58_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na58_2_i) );
// C_///AND/      x47y42     80'h00_0060_00_0000_0C08_FF38
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a59_4 ( .OUT(na59_2), .IN1(na149_2), .IN2(na2_2), .IN3(1'b1), .IN4(~na292_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND*/D///      x45y46     80'h00_EE00_00_0000_0788_FD53
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a61_1 ( .OUT(na61_1_i), .IN1(1'b0), .IN2(~na304_1), .IN3(~na78_2), .IN4(1'b0), .IN5(~na49_1), .IN6(na318_2), .IN7(1'b1),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a61_2 ( .OUT(na61_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na61_1_i) );
// C_///AND/      x49y45     80'h00_0060_00_0000_0C08_FF32
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a63_4 ( .OUT(na63_2), .IN1(na310_2), .IN2(~na151_1), .IN3(1'b1), .IN4(~na292_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ICOMP////D      x45y61     80'h00_F618_00_0000_0888_FF65
C_ICOMP    #(.CPE_CFG (9'b0_0000_0000)) 
           _a65_1 ( .OUT(na65_1), .IN1(na65_2), .IN2(1'b0), .IN3(na241_2), .IN4(~na266_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a65_5 ( .OUT(na65_2), .CLK(na153_1), .EN(~na73_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na65_1) );
// C_AND////      x45y50     80'h00_0018_00_0000_0C88_ACFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a66_1 ( .OUT(na66_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na12_2), .IN7(na78_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND*/D///      x44y47     80'h00_EE00_00_0000_0388_D3FF
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a67_1 ( .OUT(na67_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(~na66_1), .IN7(~na67_1), .IN8(na317_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a67_2 ( .OUT(na67_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na67_1_i) );
// C_ORAND*/D///      x51y50     80'h00_EE00_00_0000_0388_DBFF
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a68_1 ( .OUT(na68_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na13_1), .IN6(~na68_1), .IN7(~na87_2), .IN8(na266_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a68_2 ( .OUT(na68_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na68_1_i) );
// C_///AND/      x50y59     80'h00_0060_00_0000_0C08_FF33
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a73_4 ( .OUT(na73_2), .IN1(1'b1), .IN2(~na75_2), .IN3(1'b1), .IN4(~na74_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x48y60     80'h00_0060_00_0000_0C08_FF88
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a74_4 ( .OUT(na74_2), .IN1(na65_1), .IN2(na10_1), .IN3(na311_2), .IN4(na45_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x49y58     80'h00_0060_00_0000_0C08_FF84
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a75_4 ( .OUT(na75_2), .IN1(~na65_1), .IN2(na325_2), .IN3(na132_1), .IN4(na130_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND*/DST      x46y45     80'h20_BE00_80_0000_0C07_FFD7
C_ORAND    #(.CPE_CFG (9'b1_1000_0000)) 
           _a78_4 ( .OUT(na78_2_i), .IN1(~na49_1), .IN2(~na218_1), .IN3(~na78_2), .IN4(na312_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_DST      #(.CPE_CFG (9'bX_0100_0100)) 
           _a78_5 ( .OUT(na78_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na78_2_i) );
// C_AND////      x50y52     80'h00_0018_00_0000_0C88_1AFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a82_1 ( .OUT(na82_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na13_1), .IN6(1'b1), .IN7(~na87_2), .IN8(~na175_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND*/DST      x50y49     80'h20_BE00_80_0000_0C07_FF77
C_ORAND    #(.CPE_CFG (9'b1_1000_0000)) 
           _a87_4 ( .OUT(na87_2_i), .IN1(~na13_1), .IN2(~na327_2), .IN3(~na87_2), .IN4(~na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_DST      #(.CPE_CFG (9'bX_0100_0100)) 
           _a87_5 ( .OUT(na87_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na87_2_i) );
// C_AND////      x49y52     80'h00_0018_00_0000_0888_4F4C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a90_1 ( .OUT(na90_1), .IN1(1'b1), .IN2(na41_1), .IN3(~na225_1), .IN4(na40_1), .IN5(1'b1), .IN6(1'b1), .IN7(~na78_2), .IN8(na40_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b////      x50y45     80'h00_0018_00_0040_0A6C_003C
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a91_1 ( .OUT(na91_1), .IN1(1'b1), .IN2(na2_2), .IN3(1'b1), .IN4(~na219_2), .IN5(1'b0), .IN6(na314_2), .IN7(~na67_1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x46y60     80'h00_0018_00_0000_0C88_82FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a94_1 ( .OUT(na94_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na65_1), .IN6(~na10_1), .IN7(na311_2), .IN8(na45_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x45y60     80'h00_0060_00_0000_0C08_FF22
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a95_4 ( .OUT(na95_2), .IN1(na65_1), .IN2(~na10_1), .IN3(na311_2), .IN4(~na45_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x45y59     80'h00_0018_00_0000_0C88_42FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a96_1 ( .OUT(na96_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na65_1), .IN6(~na10_1), .IN7(~na311_2), .IN8(na45_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x45y60     80'h00_0018_00_0000_0C88_28FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a97_1 ( .OUT(na97_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na65_1), .IN6(na10_1), .IN7(na311_2), .IN8(~na45_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x46y61     80'h00_0060_00_0000_0C08_FF12
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a98_4 ( .OUT(na98_2), .IN1(na65_1), .IN2(~na10_1), .IN3(~na311_2), .IN4(~na45_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x46y61     80'h00_0018_00_0000_0C88_48FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a99_1 ( .OUT(na99_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na65_1), .IN6(na10_1), .IN7(~na311_2), .IN8(na45_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x47y62     80'h00_0018_00_0000_0C88_18FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a100_1 ( .OUT(na100_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na65_1), .IN6(na10_1), .IN7(~na311_2), .IN8(~na45_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x45y57     80'h00_0060_00_0000_0C08_FFA4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a101_4 ( .OUT(na101_2), .IN1(~na237_1), .IN2(na323_2), .IN3(na128_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2b////      x49y49     80'h00_0018_00_0040_0A30_0003
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a102_1 ( .OUT(na102_1), .IN1(1'b1), .IN2(~na25_1), .IN3(1'b0), .IN4(1'b0), .IN5(na145_2), .IN6(na103_1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND*/D///      x51y48     80'h00_EE00_00_0000_0788_5F3D
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a103_1 ( .OUT(na103_1_i), .IN1(~na102_1), .IN2(na20_2), .IN3(1'b0), .IN4(~na18_1), .IN5(1'b1), .IN6(1'b1), .IN7(~na87_2),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a103_2 ( .OUT(na103_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na103_1_i) );
// C_OR////      x45y48     80'h00_0018_00_0000_0EEE_EAEE
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a105_1 ( .OUT(na105_1), .IN1(na223_1), .IN2(na222_1), .IN3(na225_1), .IN4(na220_1), .IN5(na223_2), .IN6(1'b0), .IN7(na225_2),
                     .IN8(na220_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x44y48     80'h00_0018_00_0000_0888_FBA3
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a106_1 ( .OUT(na106_1), .IN1(1'b0), .IN2(~na90_1), .IN3(na91_1), .IN4(1'b0), .IN5(na49_1), .IN6(~na105_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x52y44     80'h00_0078_00_0020_0C66_AAC0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a108_1 ( .OUT(na108_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na1_2), .IN6(1'b1), .IN7(na4_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na113_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a108_4 ( .OUT(na108_2), .COUTY1(na108_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na6_2), .IN5(na1_2), .IN6(1'b1), .IN7(na4_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na113_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x52y45     80'h00_0078_00_0020_0C66_C00C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a110_1 ( .OUT(na110_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na6_1),
                     .CINX(1'b0), .CINY1(na108_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a110_4 ( .OUT(na110_2), .COUTY1(na110_4), .IN1(1'b1), .IN2(na7_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na6_1), .CINX(1'b0), .CINY1(na108_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x52y46     80'h00_0018_00_0010_0666_000C
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a112_1 ( .OUT(na112_1), .IN1(1'b1), .IN2(na7_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na110_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x52y43     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a113_2 ( .OUT(na113_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a113_6 ( .COUTY1(na113_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na113_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2/D//ADDF2/D      x48y51     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a115_1 ( .OUT(na115_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na115_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na140_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a115_2 ( .OUT(na115_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na115_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a115_4 ( .OUT(na115_2_i), .COUTY1(na115_4), .IN1(1'b0), .IN2(1'b0), .IN3(na115_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na115_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na140_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a115_5 ( .OUT(na115_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na115_2_i) );
// C_ADDF2/D//ADDF2/D      x48y52     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a117_1 ( .OUT(na117_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na117_1),
                     .CINX(1'b0), .CINY1(na115_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a117_2 ( .OUT(na117_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na117_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a117_4 ( .OUT(na117_2_i), .COUTY1(na117_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na117_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na117_1), .CINX(1'b0), .CINY1(na115_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a117_5 ( .OUT(na117_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na117_2_i) );
// C_ADDF2/D//ADDF2/D      x48y53     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a119_1 ( .OUT(na119_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na119_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na117_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a119_2 ( .OUT(na119_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na119_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a119_4 ( .OUT(na119_2_i), .COUTY1(na119_4), .IN1(1'b0), .IN2(1'b0), .IN3(na119_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na119_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na117_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a119_5 ( .OUT(na119_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na119_2_i) );
// C_ADDF2/D//ADDF2/D      x48y54     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a121_1 ( .OUT(na121_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na121_1),
                     .CINX(1'b0), .CINY1(na119_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a121_2 ( .OUT(na121_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na121_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a121_4 ( .OUT(na121_2_i), .COUTY1(na121_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na121_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na121_1), .CINX(1'b0), .CINY1(na119_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a121_5 ( .OUT(na121_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na121_2_i) );
// C_ADDF2/D//ADDF2/D      x48y55     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a123_1 ( .OUT(na123_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na123_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na121_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a123_2 ( .OUT(na123_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na123_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a123_4 ( .OUT(na123_2_i), .COUTY1(na123_4), .IN1(1'b0), .IN2(1'b0), .IN3(na123_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na123_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na121_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a123_5 ( .OUT(na123_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na123_2_i) );
// C_ADDF2/D//ADDF2/D      x48y46     80'h00_EE00_80_0020_0C66_CCC0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a124_1 ( .OUT(na124_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na242_1), .IN7(1'b1), .IN8(na124_1),
                     .CINX(1'b0), .CINY1(na141_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a124_2 ( .OUT(na124_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na124_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a124_4 ( .OUT(na124_2_i), .COUTY1(na124_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na124_2), .IN5(1'b1), .IN6(na242_1),
                     .IN7(1'b1), .IN8(na124_1), .CINX(1'b0), .CINY1(na141_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a124_5 ( .OUT(na124_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na124_2_i) );
// C_ADDF2/D//ADDF2/D      x48y56     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a126_1 ( .OUT(na126_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na126_1),
                     .CINX(1'b0), .CINY1(na123_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a126_2 ( .OUT(na126_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na126_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a126_4 ( .OUT(na126_2_i), .COUTY1(na126_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na126_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na126_1), .CINX(1'b0), .CINY1(na123_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a126_5 ( .OUT(na126_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na126_2_i) );
// C_ADDF2/D//ADDF2/D      x48y57     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a128_1 ( .OUT(na128_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na128_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na126_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a128_2 ( .OUT(na128_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na128_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a128_4 ( .OUT(na128_2_i), .COUTY1(na128_4), .IN1(1'b0), .IN2(1'b0), .IN3(na128_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na128_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na126_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a128_5 ( .OUT(na128_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na128_2_i) );
// C_ADDF2/D//ADDF2/D      x48y58     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a130_1 ( .OUT(na130_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na130_1),
                     .CINX(1'b0), .CINY1(na128_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a130_2 ( .OUT(na130_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na130_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a130_4 ( .OUT(na130_2_i), .COUTY1(na130_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na130_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na130_1), .CINX(1'b0), .CINY1(na128_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a130_5 ( .OUT(na130_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na130_2_i) );
// C_ADDF/D///      x48y59     80'h00_EE00_00_0010_0666_00A0
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a132_1 ( .OUT(na132_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(na132_1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na130_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a132_2 ( .OUT(na132_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na132_1_i) );
// C_ADDF2/D//ADDF2/D      x48y47     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a134_1 ( .OUT(na134_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na134_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na124_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a134_2 ( .OUT(na134_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na134_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a134_4 ( .OUT(na134_2_i), .COUTY1(na134_4), .IN1(1'b0), .IN2(1'b0), .IN3(na134_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na134_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na124_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a134_5 ( .OUT(na134_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na134_2_i) );
// C_ADDF2/D//ADDF2/D      x48y48     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a136_1 ( .OUT(na136_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na136_1),
                     .CINX(1'b0), .CINY1(na134_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a136_2 ( .OUT(na136_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na136_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a136_4 ( .OUT(na136_2_i), .COUTY1(na136_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na136_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na136_1), .CINX(1'b0), .CINY1(na134_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a136_5 ( .OUT(na136_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na136_2_i) );
// C_ADDF2/D//ADDF2/D      x48y49     80'h00_EE00_80_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a138_1 ( .OUT(na138_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na138_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na136_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a138_2 ( .OUT(na138_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na138_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a138_4 ( .OUT(na138_2_i), .COUTY1(na138_4), .IN1(1'b0), .IN2(1'b0), .IN3(na138_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na138_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na136_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a138_5 ( .OUT(na138_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na138_2_i) );
// C_ADDF2/D//ADDF2/D      x48y50     80'h00_EE00_80_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a140_1 ( .OUT(na140_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na140_1),
                     .CINX(1'b0), .CINY1(na138_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a140_2 ( .OUT(na140_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na140_1_i) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a140_4 ( .OUT(na140_2_i), .COUTY1(na140_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na140_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na140_1), .CINX(1'b0), .CINY1(na138_4), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a140_5 ( .OUT(na140_2), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na140_2_i) );
// C_/C_0_1///      x48y45     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a141_2 ( .OUT(na141_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a141_6 ( .COUTY1(na141_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na141_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x50y57     80'h00_0078_00_0020_0C66_CC0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a142_1 ( .OUT(na142_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na10_2), .IN7(1'b1), .IN8(na45_2),
                     .CINX(1'b0), .CINY1(na144_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a142_4 ( .OUT(na142_2), .IN1(1'b1), .IN2(na10_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na10_2), .IN7(1'b1), .IN8(na45_2),
                     .CINX(1'b0), .CINY1(na144_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x50y56     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a144_2 ( .OUT(na144_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a144_6 ( .COUTY1(na144_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na144_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x47y47     80'h00_0078_00_0020_0C66_CAFC
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a145_1 ( .OUT(na145_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na27_2), .IN6(1'b1), .IN7(1'b1), .IN8(na16_1),
                     .CINX(1'b0), .CINY1(na148_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a145_4 ( .OUT(na145_2), .COUTY1(na145_4), .IN1(1'b1), .IN2(na103_1), .IN3(1'b1), .IN4(1'b1), .IN5(na27_2), .IN6(1'b1), .IN7(1'b1),
                     .IN8(na16_1), .CINX(1'b0), .CINY1(na148_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x47y48     80'h00_0018_00_0010_0666_00FA
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a147_1 ( .OUT(na147_1), .IN1(na31_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na145_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x47y46     80'h00_3F00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a148_2 ( .OUT(na148_1), .CLK(1'b1), .EN(1'b0), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a148_6 ( .COUTY1(na148_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na148_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x47y43     80'h00_0078_00_0020_0C66_AAFA
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a149_1 ( .OUT(na149_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na58_2), .IN6(1'b1), .IN7(na46_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na270_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a149_4 ( .OUT(na149_2), .COUTY1(na149_4), .IN1(na58_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na58_2), .IN6(1'b1), .IN7(na46_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na270_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x47y44     80'h00_0018_00_0010_0666_00FC
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a151_1 ( .OUT(na151_1), .IN1(1'b1), .IN2(na61_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na149_4), .PINX(1'b0), .PINY1(1'b0) );
GLBOUT     #(.GLBOUT_CFG (64'h0000_0000_0000_0014)) 
           _a153 ( .GLB0(na153_1), .GLB1(_d0), .GLB2(_d1), .GLB3(_d2), .CLK_FB0(_d3), .CLK_FB1(_d4), .CLK_FB2(_d5), .CLK_FB3(_d6),
                   .CLK0_0(na268_6), .CLK0_90(na268_5), .CLK0_180(na268_4), .CLK0_270(na268_3), .CLK0_BYP(1'b0), .CLK1_0(1'b0), .CLK1_90(1'b0),
                   .CLK1_180(1'b0), .CLK1_270(1'b0), .CLK1_BYP(1'b0), .CLK2_0(1'b0), .CLK2_90(1'b0), .CLK2_180(1'b0), .CLK2_270(1'b0),
                   .CLK2_BYP(1'b0), .CLK3_0(1'b0), .CLK3_90(1'b0), .CLK3_180(1'b0), .CLK3_270(1'b0), .CLK3_BYP(1'b0), .USR_GLB0(1'b0),
                   .USR_GLB1(1'b0), .USR_GLB2(1'b0), .USR_GLB3(1'b0), .USR_FB0(1'b0), .USR_FB1(1'b0), .USR_FB2(1'b0), .USR_FB3(1'b0) );
// C_AND/D///      x43y58     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a172_1 ( .OUT(na172_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na266_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a172_2 ( .OUT(na172_1), .CLK(na153_1), .EN(na74_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na172_1_i) );
// C_///AND/D      x54y50     80'h00_EA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a175_4 ( .OUT(na175_2_i), .IN1(1'b1), .IN2(na176_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a175_5 ( .OUT(na175_2), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na175_2_i) );
// C_AND/D//AND/D      x51y46     80'h00_EA00_80_0000_0C88_AFAF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a176_1 ( .OUT(na176_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na178_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a176_2 ( .OUT(na176_1), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na176_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a176_4 ( .OUT(na176_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na178_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a176_5 ( .OUT(na176_2), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na176_2_i) );
// C_AND/D//AND/D      x54y49     80'h00_EA00_80_0000_0C88_FAFC
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a177_1 ( .OUT(na177_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na179_2), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a177_2 ( .OUT(na177_1), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na177_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a177_4 ( .OUT(na177_2_i), .IN1(1'b1), .IN2(na176_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a177_5 ( .OUT(na177_2), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na177_2_i) );
// C_AND/D//AND/D      x52y51     80'h00_EA00_80_0000_0C88_AFAF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a178_1 ( .OUT(na178_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na177_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a178_2 ( .OUT(na178_1), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na178_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a178_4 ( .OUT(na178_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na177_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a178_5 ( .OUT(na178_2), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na178_2_i) );
// C_///AND/D      x53y47     80'h00_EA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a179_4 ( .OUT(na179_2_i), .IN1(1'b1), .IN2(na68_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a179_5 ( .OUT(na179_2), .CLK(na153_1), .EN(na13_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na179_2_i) );
// C_AND/D///      x47y57     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a183_1 ( .OUT(na183_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na266_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a183_2 ( .OUT(na183_1), .CLK(na153_1), .EN(na94_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na183_1_i) );
// C_///AND/D      x47y58     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a184_4 ( .OUT(na184_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a184_5 ( .OUT(na184_2), .CLK(na153_1), .EN(na96_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na184_2_i) );
// C_AND/D///      x50y59     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a186_1 ( .OUT(na186_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na266_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a186_2 ( .OUT(na186_1), .CLK(na153_1), .EN(na95_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na186_1_i) );
// C_///AND/D      x45y59     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a188_4 ( .OUT(na188_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a188_5 ( .OUT(na188_2), .CLK(na153_1), .EN(na99_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na188_2_i) );
// C_AND/D///      x50y58     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a189_1 ( .OUT(na189_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na266_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a189_2 ( .OUT(na189_1), .CLK(na153_1), .EN(na97_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na189_1_i) );
// C_///AND/D      x52y59     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a190_4 ( .OUT(na190_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a190_5 ( .OUT(na190_2), .CLK(na153_1), .EN(na100_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na190_2_i) );
// C_AND/D///      x53y51     80'h00_EA00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a196_1 ( .OUT(na196_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na208_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a196_2 ( .OUT(na196_1), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na196_1_i) );
// C_///AND/D      x45y50     80'h00_EA00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a197_4 ( .OUT(na197_2_i), .IN1(na209_2), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a197_5 ( .OUT(na197_2), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na197_2_i) );
// C_AND/D///      x45y51     80'h00_EA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a198_1 ( .OUT(na198_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na210_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a198_2 ( .OUT(na198_1), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na198_1_i) );
// C_///AND/D      x46y51     80'h00_EA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a199_4 ( .OUT(na199_2_i), .IN1(1'b1), .IN2(na211_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a199_5 ( .OUT(na199_2), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na199_2_i) );
// C_AND/D///      x46y51     80'h00_EA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a200_1 ( .OUT(na200_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na212_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a200_2 ( .OUT(na200_1), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na200_1_i) );
// C_///AND/D      x47y52     80'h00_EA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a201_4 ( .OUT(na201_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na213_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a201_5 ( .OUT(na201_2), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na201_2_i) );
// C_AND/D///      x46y52     80'h00_EA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a202_1 ( .OUT(na202_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na214_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a202_2 ( .OUT(na202_1), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na202_1_i) );
// C_///AND/D      x45y52     80'h00_EA00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a203_4 ( .OUT(na203_2_i), .IN1(na215_2), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a203_5 ( .OUT(na203_2), .CLK(na153_1), .EN(na66_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na203_2_i) );
// C_AND/D///      x51y52     80'h00_EA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a208_1 ( .OUT(na208_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na229_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a208_2 ( .OUT(na208_1), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na208_1_i) );
// C_///AND/D      x45y53     80'h00_EA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a209_4 ( .OUT(na209_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na230_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a209_5 ( .OUT(na209_2), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na209_2_i) );
// C_AND/D///      x45y53     80'h00_EA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a210_1 ( .OUT(na210_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na231_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a210_2 ( .OUT(na210_1), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na210_1_i) );
// C_///AND/D      x49y54     80'h00_EA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a211_4 ( .OUT(na211_2_i), .IN1(1'b1), .IN2(na232_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a211_5 ( .OUT(na211_2), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na211_2_i) );
// C_AND/D///      x44y50     80'h00_EA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a212_1 ( .OUT(na212_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na233_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a212_2 ( .OUT(na212_1), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na212_1_i) );
// C_///AND/D      x44y50     80'h00_EA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a213_4 ( .OUT(na213_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na234_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a213_5 ( .OUT(na213_2), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na213_2_i) );
// C_AND/D///      x43y51     80'h00_EA00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a214_1 ( .OUT(na214_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na235_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a214_2 ( .OUT(na214_1), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na214_1_i) );
// C_///AND/D      x45y49     80'h00_EA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a215_4 ( .OUT(na215_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na236_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a215_5 ( .OUT(na215_2), .CLK(na153_1), .EN(na12_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na215_2_i) );
// C_AND/D///      x49y50     80'h00_EA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a218_1 ( .OUT(na218_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na225_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a218_2 ( .OUT(na218_1), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na218_1_i) );
// C_///AND/D      x46y50     80'h00_EA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a219_4 ( .OUT(na219_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na225_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a219_5 ( .OUT(na219_2), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na219_2_i) );
// C_AND/D//AND/D      x46y48     80'h00_EA00_80_0000_0C88_FCAF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a220_1 ( .OUT(na220_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na222_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a220_2 ( .OUT(na220_1), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na220_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a220_4 ( .OUT(na220_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na67_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a220_5 ( .OUT(na220_2), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na220_2_i) );
// C_AND/D///      x47y54     80'h00_EA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a222_1 ( .OUT(na222_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na220_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a222_2 ( .OUT(na222_1), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na222_1_i) );
// C_AND/D//AND/D      x47y51     80'h00_EA00_80_0000_0C88_CFFA
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a223_1 ( .OUT(na223_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na219_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a223_2 ( .OUT(na223_1), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na223_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a223_4 ( .OUT(na223_2_i), .IN1(na223_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a223_5 ( .OUT(na223_2), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na223_2_i) );
// C_AND/D//AND/D      x50y51     80'h00_EA00_80_0000_0C88_FACF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a225_1 ( .OUT(na225_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na223_2), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a225_2 ( .OUT(na225_1), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na225_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a225_4 ( .OUT(na225_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na220_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a225_5 ( .OUT(na225_2), .CLK(na153_1), .EN(na49_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na225_2_i) );
// C_///AND/D      x46y62     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a227_4 ( .OUT(na227_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a227_5 ( .OUT(na227_2), .CLK(na153_1), .EN(na98_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na227_2_i) );
// C_AND/D///      x50y53     80'h00_EA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a229_1 ( .OUT(na229_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na230_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a229_2 ( .OUT(na229_1), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na229_1_i) );
// C_///AND/D      x50y52     80'h00_EA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a230_4 ( .OUT(na230_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na231_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a230_5 ( .OUT(na230_2), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na230_2_i) );
// C_AND/D///      x44y52     80'h00_EA00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a231_1 ( .OUT(na231_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na232_2), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a231_2 ( .OUT(na231_1), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na231_1_i) );
// C_///AND/D      x45y54     80'h00_EA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a232_4 ( .OUT(na232_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na233_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a232_5 ( .OUT(na232_2), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na232_2_i) );
// C_AND/D///      x44y53     80'h00_EA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a233_1 ( .OUT(na233_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na234_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a233_2 ( .OUT(na233_1), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na233_1_i) );
// C_///AND/D      x44y52     80'h00_EA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a234_4 ( .OUT(na234_2_i), .IN1(1'b1), .IN2(na235_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a234_5 ( .OUT(na234_2), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na234_2_i) );
// C_AND/D///      x43y54     80'h00_EA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a235_1 ( .OUT(na235_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na236_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a235_2 ( .OUT(na235_1), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na235_1_i) );
// C_///AND/D      x44y49     80'h00_EA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a236_4 ( .OUT(na236_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a236_5 ( .OUT(na236_2), .CLK(na153_1), .EN(na82_1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0),
                     .D_IN(na236_2_i) );
// C_AND/D///      x51y59     80'h00_FE00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a237_1 ( .OUT(na237_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na128_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a237_2 ( .OUT(na237_1), .CLK(na153_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na237_1_i) );
// C_///AND/D      x54y59     80'h00_FE00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a241_4 ( .OUT(na241_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a241_5 ( .OUT(na241_2), .CLK(na153_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na241_2_i) );
// C_AND/D///      x49y46     80'h00_EE00_00_0000_0C88_F3FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a242_1 ( .OUT(na242_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na242_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a242_2 ( .OUT(na242_1), .CLK(na153_1), .EN(1'b1), .SR(na260_1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na242_1_i) );
// C_MX4b////      x47y59     80'h00_0018_00_0040_0AF0_0033
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a258_1 ( .OUT(na258_1), .IN1(1'b1), .IN2(~na325_2), .IN3(1'b1), .IN4(~na130_2), .IN5(na183_1), .IN6(na184_2), .IN7(na186_1),
                     .IN8(na227_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b////      x47y60     80'h00_0018_00_0040_0AF0_003C
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a259_1 ( .OUT(na259_1), .IN1(1'b1), .IN2(na325_2), .IN3(1'b1), .IN4(~na130_2), .IN5(na188_2), .IN6(na172_1), .IN7(na190_2),
                     .IN8(na189_1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000050)) 
           _a260 ( .Y(na260_1), .I(arst_n) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000090)) 
           _a261 ( .Y(na261_1), .I(clk) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a262 ( .O(led), .A(na305_10) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a263 ( .O(received), .A(na306_10) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a264 ( .O(sent), .A(na307_10) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a265 ( .O(tick_1us), .A(na308_10) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000010)) 
           _a266 ( .Y(na266_1), .I(uart_rx) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a267 ( .O(uart_tx), .A(na309_10) );
CC_PLL     #(.PLL_CFG (96'h01_CB_01_10_64_00_04_05_08_0A_20_82)) 
           _a268 ( .USR_PLL_LOCKED_STDY(_d7), .USR_PLL_LOCKED(_d8), .CLK270(na268_3), .CLK180(na268_4), .CLK90(na268_5), .CLK0(na268_6),
                   .CLK_REF_OUT(_d9), .CLK_REF(na271_1), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0), .USR_LOCKED_STDY_RST(1'b0), .USR_SET_SEL(1'b0) );
// C_OR////      x47y58     80'h00_0018_00_0000_0CEE_7300
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a269_1 ( .OUT(na269_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(~na10_1), .IN7(~na311_2), .IN8(~na45_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x47y42     80'h00_3F00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a270_2 ( .OUT(na270_1), .CLK(1'b1), .EN(1'b0), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a270_6 ( .COUTY1(na270_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na270_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
CLKIN      #(.CLKIN_CFG (32'h0000_0000)) 
           _a271 ( .PCLK0(na271_1), .PCLK1(_d10), .PCLK2(_d11), .PCLK3(_d12), .CLK0(na261_1), .CLK1(1'b0), .CLK2(1'b0), .CLK3(1'b0),
                   .SER_CLK(1'b0), .SPI_CLK(1'b0), .JTAG_CLK(1'b0) );
// C_OR////      x52y49     80'h00_0018_00_0000_0EEE_ACBE
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a274_1 ( .OUT(na274_1), .IN1(na179_2), .IN2(na176_1), .IN3(na177_2), .IN4(~na26_1), .IN5(1'b0), .IN6(na176_2), .IN7(na177_1),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x46y53     80'h00_0018_00_0000_0888_7735
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a279_1 ( .OUT(na279_1), .IN1(~na38_1), .IN2(1'b0), .IN3(1'b0), .IN4(~na35_2), .IN5(~na223_2), .IN6(~na203_2), .IN7(~na199_2),
                     .IN8(~na220_1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x42y48     80'h00_0060_00_0000_0C08_FFCA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a281_4 ( .OUT(na281_2), .IN1(na223_1), .IN2(1'b1), .IN3(1'b1), .IN4(na202_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR////      x45y49     80'h00_0018_00_0000_0CEE_0700
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a282_1 ( .OUT(na282_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na198_1), .IN6(~na222_1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x43y48     80'h00_0018_00_0000_0C88_CCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a283_1 ( .OUT(na283_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na197_2), .IN7(1'b1), .IN8(na220_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///OR/      x47y54     80'h00_0060_00_0000_0C0E_FF33
C_OR       #(.CPE_CFG (9'b0_1000_0000)) 
           _a284_4 ( .OUT(na284_2), .IN1(1'b0), .IN2(~na201_2), .IN3(1'b0), .IN4(~na219_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x43y51     80'h00_0060_00_0000_0C08_FFAC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a285_4 ( .OUT(na285_2), .IN1(1'b1), .IN2(na332_2), .IN3(na200_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x49y48     80'h00_0018_00_0000_0C88_75FF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a289_1 ( .OUT(na289_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na52_2), .IN6(1'b0), .IN7(~na46_1), .IN8(~na333_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2b////      x46y49     80'h00_0018_00_0040_0A50_00A0
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a290_1 ( .OUT(na290_1), .IN1(1'b0), .IN2(1'b0), .IN3(na319_2), .IN4(1'b1), .IN5(na49_1), .IN6(1'b0), .IN7(na78_2), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR////      x51y41     80'h00_0018_00_0000_0CEE_C300
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a291_1 ( .OUT(na291_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(~na2_2), .IN7(1'b0), .IN8(na292_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x50y48     80'h00_0018_00_0000_0888_4CC3
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a292_1 ( .OUT(na292_1), .IN1(1'b1), .IN2(~na218_1), .IN3(1'b1), .IN4(na40_1), .IN5(1'b1), .IN6(na41_1), .IN7(~na225_1), .IN8(na40_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x51y42     80'h00_0018_00_0000_0888_5F57
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a294_1 ( .OUT(na294_1), .IN1(~na291_1), .IN2(~na321_2), .IN3(~na54_1), .IN4(1'b0), .IN5(1'b1), .IN6(1'b1), .IN7(~na54_2),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x50y41     80'h00_0018_00_0000_0888_F357
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a299_1 ( .OUT(na299_1), .IN1(~na291_1), .IN2(~na320_2), .IN3(~na54_1), .IN4(1'b0), .IN5(1'b0), .IN6(~na59_2), .IN7(1'b1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////      x49y44     80'h00_0018_00_0000_0888_F55D
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a304_1 ( .OUT(na304_1), .IN1(~na291_1), .IN2(na61_1), .IN3(~na54_1), .IN4(1'b0), .IN5(~na63_2), .IN6(1'b0), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x1y95     80'h08_0060_00_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a305_4 ( .OUT(na305_2), .IN1(1'b1), .IN2(1'b1), .IN3(na9_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a305_6 ( .RAM_O2(na305_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na305_2), .COMP_OUT(1'b0) );
// C_///AND/      x160y69     80'h08_0060_00_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a306_4 ( .OUT(na306_2), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a306_6 ( .RAM_O2(na306_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na306_2), .COMP_OUT(1'b0) );
// C_///AND/      x57y1     80'h08_0060_00_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a307_4 ( .OUT(na307_2), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na266_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a307_6 ( .RAM_O2(na307_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na307_2), .COMP_OUT(1'b0) );
// C_///AND/      x101y1     80'h08_0060_00_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a308_4 ( .OUT(na308_2), .IN1(1'b1), .IN2(na2_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a308_6 ( .RAM_O2(na308_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na308_2), .COMP_OUT(1'b0) );
// C_///AND/      x1y51     80'h08_0060_00_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a309_4 ( .OUT(na309_2), .IN1(1'b1), .IN2(1'b1), .IN3(na33_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a309_6 ( .RAM_O2(na309_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na309_2), .COMP_OUT(1'b0) );
// C_////Bridge      x51y45     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a310_5 ( .OUT(na310_2), .IN1(1'b0), .IN2(na2_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x48y59     80'h00_00A5_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a311_5 ( .OUT(na311_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(na10_2), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x48y44     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a312_5 ( .OUT(na312_2), .IN1(1'b0), .IN2(na12_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x51y44     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a313_5 ( .OUT(na313_2), .IN1(na27_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x47y44     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a314_5 ( .OUT(na314_2), .IN1(na36_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x45y46     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a315_5 ( .OUT(na315_2), .IN1(na36_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x51y51     80'h00_00A7_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a316_5 ( .OUT(na316_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(na40_2) );
// C_////Bridge      x44y46     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a317_5 ( .OUT(na317_2), .IN1(na49_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x47y46     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a318_5 ( .OUT(na318_2), .IN1(na49_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x46y47     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a319_5 ( .OUT(na319_2), .IN1(na49_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x51y40     80'h00_00A4_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a320_5 ( .OUT(na320_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na58_1), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x53y40     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a321_5 ( .OUT(na321_2), .IN1(na58_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x48y42     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a322_5 ( .OUT(na322_2), .IN1(na58_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x47y56     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a323_5 ( .OUT(na323_2), .IN1(na65_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x53y50     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a324_5 ( .OUT(na324_2), .IN1(1'b0), .IN2(1'b0), .IN3(na87_2), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x49y60     80'h00_00A7_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a325_5 ( .OUT(na325_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(na130_1) );
// C_////Bridge      x43y58     80'h00_00A6_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a326_5 ( .OUT(na326_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na132_1), .IN8(1'b0) );
// C_////Bridge      x51y50     80'h00_00A3_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a327_5 ( .OUT(na327_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(na175_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x54y48     80'h00_00A5_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a328_5 ( .OUT(na328_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(na176_1), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x52y46     80'h00_00A6_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a329_5 ( .OUT(na329_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na177_2), .IN8(1'b0) );
// C_////Bridge      x45y47     80'h00_00A6_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a330_5 ( .OUT(na330_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na178_1), .IN8(1'b0) );
// C_////Bridge      x54y46     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a331_5 ( .OUT(na331_2), .IN1(1'b0), .IN2(1'b0), .IN3(na178_2), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x43y50     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a332_5 ( .OUT(na332_2), .IN1(1'b0), .IN2(1'b0), .IN3(na225_2), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x52y48     80'h00_00A4_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a333_5 ( .OUT(na333_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na291_1), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
endmodule
