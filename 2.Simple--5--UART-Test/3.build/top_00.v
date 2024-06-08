//  (c) Cologne Chip AG
//  FPGA Verilog netlist writer     Version: Version 4.2 (1 May 2024)
//  Compile Time: 2024-05-10 11:57:45
//  Program Run:  2024-06-08 21:00:06
//  Program Call: /home/user/FPGA/GateMate/cc-toolchain-linux/bin/p_r/p_r -i net/top_synth.v -o top -ccf top.ccf -cCP 
//  File Type:    Verilog

// Gatecount:    193
module top (clk , i_Rx_Serial ,
       o_Tx_Serial 
       ) ;

input  clk;
input  i_Rx_Serial;

output o_Tx_Serial;



wire clk;
wire na1_1;
wire na1_1_i;
wire na1_2;
wire na1_2_i;
wire na2_2;
wire na3_2;
wire na4_2;
wire na5_1;
wire na6_1;
wire na6_1_i;
wire na7_1;
wire na8_1;
wire na8_1_i;
wire na9_1;
wire na10_1;
wire na12_1;
wire na13_2;
wire na14_1;
wire na15_2;
wire na16_2;
wire na16_2_i;
wire na18_1;
wire na18_1_i;
wire na18_2;
wire na18_2_i;
wire na19_1;
wire na19_1_i;
wire na19_2;
wire na19_2_i;
wire na20_2;
wire na21_1;
wire na23_1;
wire na25_1;
wire na26_1;
wire na27_1;
wire na31_1;
wire na31_1_i;
wire na31_2;
wire na31_2_i;
wire na33_2;
wire na33_2_i;
wire na35_1;
wire na35_1_i;
wire na36_1;
wire na36_1_i;
wire na36_2;
wire na36_2_i;
wire na37_1;
wire na37_1_i;
wire na37_2;
wire na37_2_i;
wire na39_1;
wire na39_1_i;
wire na39_2;
wire na39_2_i;
wire na41_1;
wire na41_1_i;
wire na41_2;
wire na41_2_i;
wire na42_1;
wire na42_1_i;
wire na42_2;
wire na42_2_i;
wire na45_1;
wire na45_1_i;
wire na46_1;
wire na47_2;
wire na50_1;
wire na51_1;
wire na51_2;
wire na52_1;
wire na52_1_i;
wire na53_1;
wire na54_1;
wire na54_2;
wire na57_2;
wire na60_1;
wire na60_1_i;
wire na61_1;
wire na62_2;
wire na62_2_i;
wire na63_1;
wire na63_1_i;
wire na63_2;
wire na63_2_i;
wire na65_2;
wire na66_1;
wire na67_1;
wire na67_1_i;
wire na68_2;
wire na68_2_i;
wire na72_1;
wire na72_1_i;
wire na72_2;
wire na72_2_i;
wire na73_2;
wire na73_2_i;
wire na74_1;
wire na74_1_i;
wire na74_2;
wire na74_2_i;
wire na75_1;
wire na75_1_i;
wire na76_1;
wire na76_1_i;
wire na76_2;
wire na76_2_i;
wire na77_1;
wire na77_1_i;
wire na77_2;
wire na77_2_i;
wire na78_1;
wire na78_1_i;
wire na78_2;
wire na78_2_i;
wire na79_2;
wire na79_2_i;
wire na80_2;
wire na82_1;
wire na83_1;
wire na83_1_i;
wire na84_1;
wire na85_1;
wire na86_2;
wire na87_2;
wire na87_2_i;
wire na88_1;
wire na88_1_i;
wire na89_2;
wire na90_1;
wire na90_1_i;
wire na91_2;
wire na92_1;
wire na92_1_i;
wire na93_2;
wire na94_1;
wire na94_1_i;
wire na95_2;
wire na96_1;
wire na96_1_i;
wire na97_2;
wire na98_1;
wire na98_1_i;
wire na99_1;
wire na99_1_i;
wire na100_1;
wire na100_1_i;
wire na139_1;
wire na140_1;
wire na141_1;
wire na141_1_i;
wire na144_4;
wire na146_4;
wire na148_4;
wire na149_4;
wire na151_4;
wire na153_4;
wire na155_4;
wire na157_4;
wire na158_1;
wire na158_4;
wire na160_4;
wire na162_4;
wire na164_4;
wire na165_4;
wire na167_4;
wire na169_4;
wire na171_4;
wire na173_4;
wire na174_1;
wire na174_4;
wire na176_1;
wire na176_2;
wire na176_4;
wire na178_1;
wire na178_2;
wire na178_4;
wire na180_1;
wire na181_1;
wire na181_2;
wire na181_4;
wire na183_1;
wire na183_2;
wire na183_4;
wire na185_1;
wire na185_2;
wire na185_4;
wire na187_1;
wire na187_2;
wire na187_4;
wire na189_1;
wire na189_2;
wire na189_4;
wire na190_1;
wire na190_4;
wire na191_1;
wire na191_2;
wire na193_1;
wire na193_4;
wire na194_1;
wire na194_2;
wire na194_4;
wire na196_1;
wire na196_4;
wire na197_1;
wire na198_1;
wire na198_2;
wire na200_1;
wire na200_4;
wire na202_1;
wire na202_2;
wire na202_4;
wire na204_1;
wire na204_2;
wire na204_4;
wire na206_1;
wire na207_1;
wire na207_2;
wire na207_4;
wire na209_1;
wire na209_2;
wire na209_4;
wire na211_1;
wire na211_2;
wire na211_4;
wire na213_1;
wire na213_2;
wire na213_4;
wire na215_1;
wire na215_2;
wire na215_4;
wire na217_2;
wire na217_2_i;
wire na218_1;
wire na218_1_i;
wire na219_2;
wire na219_2_i;
wire na220_1;
wire na220_1_i;
wire na221_2;
wire na221_2_i;
wire na222_1;
wire na222_1_i;
wire na223_2;
wire na223_2_i;
wire na224_1;
wire na224_1_i;
wire na225_2;
wire na225_2_i;
wire na226_1;
wire na228_1;
wire na228_1_i;
wire na229_2;
wire na229_2_i;
wire na230_1;
wire na230_1_i;
wire na231_2;
wire na231_2_i;
wire na232_1;
wire na232_1_i;
wire na233_2;
wire na233_2_i;
wire na234_1;
wire na234_1_i;
wire na235_2;
wire na235_2_i;
wire na239_1;
wire na239_1_i;
wire na241_2;
wire na241_2_i;
wire na242_1;
wire na242_1_i;
wire na283_2;
wire na283_2_i;
wire na284_2;
wire na284_2_i;
wire na285_1;
wire na285_1_i;
wire na286_1;
wire na286_1_i;
wire na287_2;
wire na287_2_i;
wire na288_1;
wire na288_1_i;
wire na289_1;
wire na289_1_i;
wire na290_2;
wire na290_2_i;
wire na294_1;
wire na294_1_i;
wire na295_2;
wire na295_2_i;
wire na296_1;
wire na296_1_i;
wire na297_2;
wire na297_2_i;
wire na298_1;
wire na298_1_i;
wire na299_2;
wire na299_2_i;
wire na300_1;
wire na300_1_i;
wire na301_2;
wire na301_2_i;
wire na310_1;
wire na311_1;
wire na312_1;
wire na313_1;
wire na316_1;
wire na318_1;
wire na319_1;
wire na319_4;
wire na320_1;
wire na321_1;
wire na334_1;
wire na342_2;
wire na344_2;
wire na345_1;
wire na347_2;
wire na348_1;
wire na351_1;
wire na352_2;
wire na353_2;
wire na354_2;
wire na355_2;
wire na356_2;
wire na357_2;
wire na358_2;
wire na359_2;
wire na360_2;
wire na361_2;
wire na362_2;
wire na363_2;
wire na364_2;
wire na365_2;
wire na366_2;
wire na367_2;
wire na368_2;
wire na369_2;
wire na370_2;
wire na371_2;
wire na352_10;
wire i_Rx_Serial;
wire o_Tx_Serial;

// C_AND/D//AND/D      x18y66     80'h00_F600_80_0000_0C88_CC3C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a1_1 ( .OUT(na1_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na2_2), .IN7(1'b1), .IN8(na191_2),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a1_2 ( .OUT(na1_1), .CLK(na226_1), .EN(~na84_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na1_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a1_4 ( .OUT(na1_2_i), .IN1(1'b1), .IN2(na2_2), .IN3(1'b1), .IN4(~na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a1_5 ( .OUT(na1_2), .CLK(na226_1), .EN(~na84_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na1_2_i) );
// C_///AND/      x13y64     80'h00_0060_00_0000_0C08_FFF4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a2_4 ( .OUT(na2_2), .IN1(~na5_1), .IN2(na3_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x15y66     80'h00_0060_00_0000_0C08_FFF4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a3_4 ( .OUT(na3_2), .IN1(~na45_1), .IN2(na4_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x9y66     80'h00_0060_00_0000_0C08_FFF2
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a4_4 ( .OUT(na4_2), .IN1(na52_1), .IN2(~na54_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x17y63     80'h00_0018_00_0000_0C88_8AFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a5_1 ( .OUT(na5_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na6_1), .IN6(1'b1), .IN7(na353_2), .IN8(na1_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND/D///      x15y67     80'h00_F600_00_0000_0C88_CCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a6_1 ( .OUT(na6_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na2_2), .IN7(1'b1), .IN8(na191_1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a6_2 ( .OUT(na6_1), .CLK(na226_1), .EN(~na84_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na6_1_i) );
CLKIN      #(.CLKIN_CFG (32'h0000_0000)) 
           _a7 ( .PCLK0(na7_1), .PCLK1(_d0), .PCLK2(_d1), .PCLK3(_d2), .CLK0(na312_1), .CLK1(1'b0), .CLK2(1'b0), .CLK3(1'b0), .SER_CLK(1'b0),
                 .SPI_CLK(1'b0), .JTAG_CLK(1'b0) );
// C_AND/D///      x13y62     80'h00_F600_00_0000_0C88_8CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a8_1 ( .OUT(na8_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na206_1), .IN7(na9_1), .IN8(na15_2),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a8_2 ( .OUT(na8_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na8_1_i) );
// C_AND////      x10y61     80'h00_0018_00_0000_0C88_F2FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a9_1 ( .OUT(na9_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na197_1), .IN6(~na10_1), .IN7(1'b1), .IN8(1'b1),
                   .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x13y60     80'h00_0018_00_0000_0888_1328
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a10_1 ( .OUT(na10_1), .IN1(na13_2), .IN2(na12_1), .IN3(na14_1), .IN4(~na18_1), .IN5(1'b1), .IN6(~na8_1), .IN7(~na16_2),
                    .IN8(~na18_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x15y64     80'h00_0018_00_0000_0C88_11FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a12_1 ( .OUT(na12_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na73_2), .IN6(~na366_2), .IN7(~na76_1), .IN8(~na74_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x7y61     80'h00_0060_00_0000_0C08_FF11
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a13_4 ( .OUT(na13_2), .IN1(~na78_2), .IN2(~na77_2), .IN3(~na76_2), .IN4(~na72_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y59     80'h00_0018_00_0000_0C88_88FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a14_1 ( .OUT(na14_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na78_1), .IN6(na77_1), .IN7(na79_2), .IN8(na72_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///ORAND/      x16y60     80'h00_0060_00_0000_0C08_FFE3
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a15_4 ( .OUT(na15_2), .IN1(1'b0), .IN2(~na68_2), .IN3(na367_2), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/D      x10y63     80'h00_F600_80_0000_0C08_FF8A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a16_4 ( .OUT(na16_2_i), .IN1(na204_2), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a16_5 ( .OUT(na16_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na16_2_i) );
// C_AND/D//AND/D      x12y62     80'h00_F600_80_0000_0C88_8C8A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a18_1 ( .OUT(na18_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na202_2), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a18_2 ( .OUT(na18_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na18_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a18_4 ( .OUT(na18_2_i), .IN1(na204_1), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a18_5 ( .OUT(na18_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na18_2_i) );
// C_AND/D//AND/D      x12y67     80'h00_FA00_80_0000_0C88_1F3C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a19_1 ( .OUT(na19_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(~na19_1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a19_2 ( .OUT(na19_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na19_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a19_4 ( .OUT(na19_2_i), .IN1(1'b1), .IN2(na185_1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a19_5 ( .OUT(na19_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na19_2_i) );
// C_///ORAND/      x10y66     80'h00_0060_00_0000_0C08_FFC7
C_ORAND    #(.CPE_CFG (9'b0_1000_0000)) 
           _a20_4 ( .OUT(na20_2), .IN1(~na23_1), .IN2(~na21_1), .IN3(1'b0), .IN4(na26_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x11y66     80'h00_0018_00_0000_0888_A12C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a21_1 ( .OUT(na21_1), .IN1(1'b1), .IN2(na31_2), .IN3(na19_1), .IN4(~na35_1), .IN5(~na33_2), .IN6(~na31_1), .IN7(na19_2),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x9y67     80'h00_0018_00_0000_0888_5441
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a23_1 ( .OUT(na23_1), .IN1(~na36_1), .IN2(~na42_1), .IN3(~na37_1), .IN4(na25_1), .IN5(~na36_2), .IN6(na42_2), .IN7(~na37_2),
                    .IN8(1'b1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y68     80'h00_0018_00_0000_0C88_11FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a25_1 ( .OUT(na25_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na39_1), .IN6(~na41_1), .IN7(~na357_2), .IN8(~na356_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y64     80'h00_0018_00_0000_0C88_A1FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a26_1 ( .OUT(na26_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na52_1), .IN6(~na54_2), .IN7(na358_2), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x10y65     80'h00_0018_00_0000_0C88_2CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a27_1 ( .OUT(na27_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na4_2), .IN7(na320_1), .IN8(~na318_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND/D//AND/D      x5y64     80'h00_FA00_80_0000_0C88_3C3A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a31_1 ( .OUT(na31_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na181_2), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a31_2 ( .OUT(na31_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na31_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a31_4 ( .OUT(na31_2_i), .IN1(na183_1), .IN2(1'b1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a31_5 ( .OUT(na31_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na31_2_i) );
// C_///AND/D      x11y65     80'h00_FA00_80_0000_0C08_FF3A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a33_4 ( .OUT(na33_2_i), .IN1(na183_2), .IN2(1'b1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a33_5 ( .OUT(na33_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na33_2_i) );
// C_AND/D///      x6y64     80'h00_FA00_00_0000_0C88_3CFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a35_1 ( .OUT(na35_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na185_2), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a35_2 ( .OUT(na35_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na35_1_i) );
// C_AND/D//AND/D      x5y67     80'h00_FA00_80_0000_0C88_3A3C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a36_1 ( .OUT(na36_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na187_1), .IN6(1'b1), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a36_2 ( .OUT(na36_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na36_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a36_4 ( .OUT(na36_2_i), .IN1(1'b1), .IN2(na178_2), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a36_5 ( .OUT(na36_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na36_2_i) );
// C_AND/D//AND/D      x10y69     80'h00_FA00_80_0000_0C88_3A3A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a37_1 ( .OUT(na37_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na187_2), .IN6(1'b1), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a37_2 ( .OUT(na37_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na37_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a37_4 ( .OUT(na37_2_i), .IN1(na180_1), .IN2(1'b1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a37_5 ( .OUT(na37_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na37_2_i) );
// C_AND/D//AND/D      x5y65     80'h00_FA00_80_0000_0C88_3C3C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a39_1 ( .OUT(na39_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na189_2), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a39_2 ( .OUT(na39_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na39_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a39_4 ( .OUT(na39_2_i), .IN1(1'b1), .IN2(na189_1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a39_5 ( .OUT(na39_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na39_2_i) );
// C_AND/D//AND/D      x5y68     80'h00_FA00_80_0000_0C88_3A3A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a41_1 ( .OUT(na41_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na176_2), .IN6(1'b1), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a41_2 ( .OUT(na41_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na41_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a41_4 ( .OUT(na41_2_i), .IN1(na176_1), .IN2(1'b1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a41_5 ( .OUT(na41_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na41_2_i) );
// C_AND/D//AND/D      x5y66     80'h00_FA00_80_0000_0C88_3C3C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a42_1 ( .OUT(na42_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na178_1), .IN7(1'b1), .IN8(~na316_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a42_2 ( .OUT(na42_1), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na42_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a42_4 ( .OUT(na42_2_i), .IN1(1'b1), .IN2(na181_1), .IN3(1'b1), .IN4(~na316_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a42_5 ( .OUT(na42_2), .CLK(na226_1), .EN(na80_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na42_2_i) );
// C_OR/D///      x13y65     80'h00_FE00_00_0000_0CEE_EE00
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a45_1 ( .OUT(na45_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na47_2), .IN6(na334_1), .IN7(na50_1), .IN8(na20_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a45_2 ( .OUT(na45_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na45_1_i) );
// C_ORAND////      x13y68     80'h00_0018_00_0000_0C88_DCFF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a46_1 ( .OUT(na46_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(na3_2), .IN7(~na320_1), .IN8(na318_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x9y65     80'h00_0060_00_0000_0C08_FF28
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a47_4 ( .OUT(na47_2), .IN1(na45_1), .IN2(na4_2), .IN3(na320_1), .IN4(~na318_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x12y63     80'h00_0018_00_0000_0C88_31FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a50_1 ( .OUT(na50_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na51_1), .IN6(~na54_2), .IN7(1'b1), .IN8(~na371_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND*////D      x13y63     80'h00_FA18_00_0000_0788_F5F5
C_AND      #(.CPE_CFG (9'b1_0000_0000)) 
           _a51_1 ( .OUT(na51_1), .IN1(~na52_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na45_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a51_5 ( .OUT(na51_2), .CLK(na226_1), .EN(na85_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na51_1) );
// C_OR/D///      x13y61     80'h00_FE00_00_0000_0CEE_EC00
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a52_1 ( .OUT(na52_1_i), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(na3_2), .IN7(na27_1), .IN8(na53_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a52_2 ( .OUT(na52_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na52_1_i) );
// C_AND////      x14y68     80'h00_0018_00_0000_0C88_48FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a53_1 ( .OUT(na53_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na23_1), .IN6(na21_1), .IN7(~na370_2), .IN8(na26_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND////D      x13y66     80'h00_FE18_00_0000_0888_FADC
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a54_1 ( .OUT(na54_1), .IN1(1'b0), .IN2(na4_2), .IN3(~na320_1), .IN4(na318_1), .IN5(na45_1), .IN6(1'b0), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a54_5 ( .OUT(na54_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na54_1) );
// C_///AND/      x5y62     80'h00_0060_00_0000_0C08_FF44
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a57_4 ( .OUT(na57_2), .IN1(~na141_1), .IN2(na342_2), .IN3(~na364_2), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x8y55     80'h00_F600_00_0040_0A55_00CC
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a60_1 ( .OUT(na60_1_i), .IN1(1'b1), .IN2(na68_2), .IN3(1'b1), .IN4(na67_1), .IN5(~na141_1), .IN6(1'b0), .IN7(~na344_2),
                    .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a60_2 ( .OUT(na60_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na60_1_i) );
// C_MX2b////      x6y62     80'h00_0018_00_0040_0A55_0050
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a61_1 ( .OUT(na61_1), .IN1(1'b0), .IN2(1'b0), .IN3(~na63_1), .IN4(1'b1), .IN5(~na311_1), .IN6(1'b0), .IN7(~na310_1), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/D      x10y60     80'h00_FA00_80_0000_0C08_FFF8
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a62_4 ( .OUT(na62_2_i), .IN1(na198_1), .IN2(na57_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a62_5 ( .OUT(na62_2), .CLK(na226_1), .EN(na86_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na62_2_i) );
// C_AND/D//AND/D      x6y63     80'h00_FA00_80_0000_0C88_F85C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a63_1 ( .OUT(na63_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na198_2), .IN6(na57_2), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a63_2 ( .OUT(na63_1), .CLK(na226_1), .EN(na86_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na63_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a63_4 ( .OUT(na63_2_i), .IN1(1'b1), .IN2(na57_2), .IN3(~na63_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a63_5 ( .OUT(na63_2), .CLK(na226_1), .EN(na86_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na63_2_i) );
// C_///AND/      x10y59     80'h00_0060_00_0000_0C08_FF42
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a65_4 ( .OUT(na65_2), .IN1(na197_1), .IN2(~na10_1), .IN3(~na364_2), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x6y60     80'h00_0018_00_0000_0C88_21FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a66_1 ( .OUT(na66_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na141_1), .IN6(~na68_2), .IN7(na75_1), .IN8(~na67_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x6y58     80'h00_FE00_00_0040_0AA0_00A3
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a67_1 ( .OUT(na67_1_i), .IN1(1'b1), .IN2(~na68_2), .IN3(na9_1), .IN4(1'b1), .IN5(1'b0), .IN6(na345_1), .IN7(1'b0), .IN8(na67_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a67_2 ( .OUT(na67_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na67_1_i) );
// C_///AND/D      x7y58     80'h00_FE00_80_0000_0C08_FF42
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a68_4 ( .OUT(na68_2_i), .IN1(na141_1), .IN2(~na68_2), .IN3(~na9_1), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a68_5 ( .OUT(na68_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na68_2_i) );
// C_AND/D//AND/D      x12y58     80'h00_F600_80_0000_0C88_8C8C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a72_1 ( .OUT(na72_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na209_2), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a72_2 ( .OUT(na72_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na72_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a72_4 ( .OUT(na72_2_i), .IN1(1'b1), .IN2(na209_1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a72_5 ( .OUT(na72_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na72_2_i) );
// C_///AND/D      x13y59     80'h00_F600_80_0000_0C08_FF8C
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a73_4 ( .OUT(na73_2_i), .IN1(1'b1), .IN2(na202_1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a73_5 ( .OUT(na73_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na73_2_i) );
// C_AND/D//AND/D      x12y60     80'h00_F600_80_0000_0C88_8A8A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a74_1 ( .OUT(na74_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na215_2), .IN6(1'b1), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a74_2 ( .OUT(na74_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na74_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a74_4 ( .OUT(na74_2_i), .IN1(na215_1), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a74_5 ( .OUT(na74_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na74_2_i) );
// C_ORAND*/D///      x8y59     80'h00_FE00_00_0000_0388_D5FF
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a75_1 ( .OUT(na75_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na217_2), .IN6(1'b0), .IN7(~na75_1), .IN8(na83_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a75_2 ( .OUT(na75_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na75_1_i) );
// C_AND/D//AND/D      x12y57     80'h00_F600_80_0000_0C88_8C8C
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a76_1 ( .OUT(na76_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na213_2), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a76_2 ( .OUT(na76_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na76_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a76_4 ( .OUT(na76_2_i), .IN1(1'b1), .IN2(na213_1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a76_5 ( .OUT(na76_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na76_2_i) );
// C_AND/D//AND/D      x15y58     80'h00_F600_80_0000_0C88_8A8A
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a77_1 ( .OUT(na77_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na211_2), .IN6(1'b1), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a77_2 ( .OUT(na77_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na77_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a77_4 ( .OUT(na77_2_i), .IN1(na211_1), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a77_5 ( .OUT(na77_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na77_2_i) );
// C_AND/D//AND/D      x7y57     80'h00_F600_80_0000_0C88_8A85
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a78_1 ( .OUT(na78_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na207_2), .IN6(1'b1), .IN7(na9_1), .IN8(na15_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a78_2 ( .OUT(na78_1), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na78_1_i) );
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a78_4 ( .OUT(na78_2_i), .IN1(~na78_2), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a78_5 ( .OUT(na78_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na78_2_i) );
// C_///AND/D      x12y55     80'h00_F600_80_0000_0C08_FF8A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a79_4 ( .OUT(na79_2_i), .IN1(na207_1), .IN2(1'b1), .IN3(na9_1), .IN4(na15_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a79_5 ( .OUT(na79_2), .CLK(na226_1), .EN(~na68_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na79_2_i) );
// C_///AND/      x5y63     80'h00_0060_00_0000_0C08_FF53
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a80_4 ( .OUT(na80_2), .IN1(1'b1), .IN2(~na54_2), .IN3(~na347_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4a////      x7y59     80'h00_0018_00_0040_0C18_CA00
C_MX4a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a82_1 ( .OUT(na82_1), .IN1(1'b1), .IN2(1'b0), .IN3(1'b0), .IN4(na348_1), .IN5(na141_1), .IN6(1'b1), .IN7(1'b1), .IN8(na67_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b/D///      x8y58     80'h00_FA00_00_0040_0A98_00C3
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a83_1 ( .OUT(na83_1_i), .IN1(1'b1), .IN2(~na363_2), .IN3(1'b1), .IN4(na365_2), .IN5(na141_1), .IN6(1'b0), .IN7(1'b0), .IN8(~na368_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a83_2 ( .OUT(na83_1), .CLK(na226_1), .EN(na82_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na83_1_i) );
// C_ORAND////      x11y65     80'h00_0018_00_0000_0C88_E3FF
C_ORAND    #(.CPE_CFG (9'b0_0000_0000)) 
           _a84_1 ( .OUT(na84_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b0), .IN6(~na46_1), .IN7(na359_2), .IN8(na360_2),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_OR////      x10y63     80'h00_0018_00_0000_0CEE_0D00
C_OR       #(.CPE_CFG (9'b0_0000_0000)) 
           _a85_1 ( .OUT(na85_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na51_1), .IN6(na54_1), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x8y60     80'h00_0060_00_0000_0C08_FF51
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a86_4 ( .OUT(na86_2), .IN1(~na141_1), .IN2(~na68_2), .IN3(~na65_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/D      x14y62     80'h00_FE00_80_0000_0C08_FF3A
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a87_4 ( .OUT(na87_2_i), .IN1(na51_2), .IN2(1'b1), .IN3(1'b1), .IN4(~na239_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a87_5 ( .OUT(na87_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na87_2_i) );
// C_MX2b/D///      x18y64     80'h00_FA00_00_0040_0AA0_005F
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a88_1 ( .OUT(na88_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(~na89_2), .IN4(1'b1), .IN5(1'b0), .IN6(na241_2), .IN7(1'b0), .IN8(na88_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a88_2 ( .OUT(na88_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na88_1_i) );
// C_///AND/      x16y61     80'h00_0060_00_0000_0C08_FF12
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a89_4 ( .OUT(na89_2), .IN1(na321_1), .IN2(~na194_1), .IN3(~na369_2), .IN4(~na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2a/D///      x17y65     80'h00_FA00_00_0040_0C03_0800
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a90_1 ( .OUT(na90_1_i), .IN1(na90_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na91_2), .IN6(na194_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a90_2 ( .OUT(na90_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na90_1_i) );
// C_///AND/      x15y59     80'h00_0060_00_0000_0C08_FFC4
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a91_4 ( .OUT(na91_2), .IN1(~na321_1), .IN2(na194_1), .IN3(1'b1), .IN4(na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2a/D///      x17y61     80'h00_FA00_00_0040_0C03_0800
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a92_1 ( .OUT(na92_1_i), .IN1(na92_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na93_2), .IN6(na194_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a92_2 ( .OUT(na92_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na92_1_i) );
// C_///AND/      x13y61     80'h00_0060_00_0000_0C08_FF34
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a93_4 ( .OUT(na93_2), .IN1(~na321_1), .IN2(na194_1), .IN3(1'b1), .IN4(~na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2a/D///      x17y59     80'h00_FA00_00_0040_0C03_0800
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a94_1 ( .OUT(na94_1_i), .IN1(na94_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na95_2), .IN6(na194_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a94_2 ( .OUT(na94_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na94_1_i) );
// C_///AND/      x17y57     80'h00_0060_00_0000_0C08_FFC1
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a95_4 ( .OUT(na95_2), .IN1(~na321_1), .IN2(~na194_1), .IN3(1'b1), .IN4(na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2b/D///      x14y66     80'h00_FA00_00_0040_0AA0_003F
C_MX2b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a96_1 ( .OUT(na96_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(~na97_2), .IN5(1'b0), .IN6(na241_2), .IN7(1'b0), .IN8(na96_1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a96_2 ( .OUT(na96_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na96_1_i) );
// C_///AND/      x14y60     80'h00_0060_00_0000_0C08_FF21
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a97_4 ( .OUT(na97_2), .IN1(~na321_1), .IN2(~na194_1), .IN3(na369_2), .IN4(~na1_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX2a/D///      x19y63     80'h00_FA00_00_0040_0C03_0200
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a98_1 ( .OUT(na98_1_i), .IN1(na98_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na91_2), .IN6(~na194_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a98_2 ( .OUT(na98_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na98_1_i) );
// C_MX2a/D///      x15y63     80'h00_FA00_00_0040_0C03_0200
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a99_1 ( .OUT(na99_1_i), .IN1(na99_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na93_2), .IN6(~na194_2), .IN7(1'b0), .IN8(1'b0),
                    .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a99_2 ( .OUT(na99_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na99_1_i) );
// C_MX2a/D///      x19y65     80'h00_FA00_00_0040_0C03_0200
C_MX2a     #(.CPE_CFG (9'b0_0000_0000)) 
           _a100_1 ( .OUT(na100_1_i), .IN1(na100_1), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(na95_2), .IN6(~na194_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a100_2 ( .OUT(na100_1), .CLK(na226_1), .EN(na46_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na100_1_i) );
// C_AND////      x10y60     80'h00_0018_00_0000_0C88_88FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a139_1 ( .OUT(na139_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na362_2), .IN6(na363_2), .IN7(na63_1), .IN8(na62_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b////      x5y59     80'h00_0018_00_0040_0AD0_003C
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a140_1 ( .OUT(na140_1), .IN1(1'b1), .IN2(na10_1), .IN3(1'b1), .IN4(~na368_2), .IN5(na197_1), .IN6(1'b0), .IN7(na351_1), .IN8(na139_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_ORAND*/D///      x5y57     80'h00_FE00_00_0000_0388_3DFF
C_ORAND    #(.CPE_CFG (9'b1_0000_0000)) 
           _a141_1 ( .OUT(na141_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na140_1), .IN6(na68_2), .IN7(1'b0), .IN8(~na66_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a141_2 ( .OUT(na141_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na141_1_i) );
// C_ADDF2///ADDF2/      x9y62     80'h00_0078_00_0020_0C66_0530
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a144_1 ( .OUT(na144_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na73_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na157_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a144_4 ( .OUT(na144_2), .COUTY1(na144_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(~na18_1), .IN5(~na73_2), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na157_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y63     80'h00_0078_00_0020_0C66_3050
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a146_1 ( .OUT(na146_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(~na18_2),
                     .CINX(1'b0), .CINY1(na144_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a146_4 ( .OUT(na146_2), .COUTY1(na146_4), .IN1(1'b0), .IN2(1'b0), .IN3(~na16_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(~na18_2), .CINX(1'b0), .CINY1(na144_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x9y64     80'h00_0018_00_0010_0666_0003
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a148_1 ( .OUT(na148_1), .COUTY1(na148_4), .IN1(1'b1), .IN2(~na8_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na146_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y57     80'h00_0078_00_0020_0C66_55F5
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a149_1 ( .OUT(na149_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na78_2), .IN6(1'b1), .IN7(~na79_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na158_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a149_4 ( .OUT(na149_2), .COUTY1(na149_4), .IN1(~na78_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(~na78_2), .IN6(1'b1), .IN7(~na79_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na158_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y58     80'h00_0078_00_0020_0C66_303F
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a151_1 ( .OUT(na151_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(~na72_2),
                     .CINX(1'b0), .CINY1(na149_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a151_4 ( .OUT(na151_2), .COUTY1(na151_4), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(~na72_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(~na72_2), .CINX(1'b0), .CINY1(na149_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y59     80'h00_0078_00_0020_0C66_03F3
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a153_1 ( .OUT(na153_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na77_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na151_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a153_4 ( .OUT(na153_2), .COUTY1(na153_4), .IN1(1'b1), .IN2(~na77_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na77_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na151_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y60     80'h00_0078_00_0020_0C66_5050
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a155_1 ( .OUT(na155_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(~na76_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na153_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a155_4 ( .OUT(na155_2), .COUTY1(na155_4), .IN1(1'b0), .IN2(1'b0), .IN3(~na76_1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(~na76_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na153_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x9y61     80'h00_0078_00_0020_0C66_3030
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a157_1 ( .OUT(na157_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(~na74_2),
                     .CINX(1'b0), .CINY1(na155_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a157_4 ( .OUT(na157_2), .COUTY1(na157_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(~na74_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(~na74_2), .CINX(1'b0), .CINY1(na155_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x9y56     80'h00_3F00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a158_2 ( .OUT(na158_1), .CLK(1'b1), .EN(1'b0), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a158_6 ( .COUTY1(na158_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na158_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x8y66     80'h00_0078_00_0020_0C66_0303
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a160_1 ( .OUT(na160_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na41_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na173_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a160_4 ( .OUT(na160_2), .COUTY1(na160_4), .IN1(1'b1), .IN2(~na41_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na41_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na173_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y67     80'h00_0078_00_0020_0C66_0305
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a162_1 ( .OUT(na162_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na42_1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na160_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a162_4 ( .OUT(na162_2), .COUTY1(na162_4), .IN1(~na36_2), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na42_1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na160_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x8y68     80'h00_0018_00_0010_0666_0050
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a164_1 ( .OUT(na164_1), .COUTY1(na164_4), .IN1(1'b0), .IN2(1'b0), .IN3(~na37_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na162_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y61     80'h00_0078_00_0020_0C66_53F3
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a165_1 ( .OUT(na165_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na42_2), .IN7(~na19_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na174_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a165_4 ( .OUT(na165_2), .COUTY1(na165_4), .IN1(1'b1), .IN2(~na31_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na42_2), .IN7(~na19_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na174_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y62     80'h00_0078_00_0020_0C66_03F5
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a167_1 ( .OUT(na167_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(~na31_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na165_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a167_4 ( .OUT(na167_2), .COUTY1(na167_4), .IN1(~na33_2), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na31_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na165_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y63     80'h00_0078_00_0020_0C66_503F
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a169_1 ( .OUT(na169_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(~na19_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na167_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a169_4 ( .OUT(na169_2), .COUTY1(na169_4), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(~na35_1), .IN5(1'b0), .IN6(1'b0), .IN7(~na19_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na167_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y64     80'h00_0078_00_0020_0C66_0550
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a171_1 ( .OUT(na171_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na36_1), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na169_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a171_4 ( .OUT(na171_2), .COUTY1(na171_4), .IN1(1'b0), .IN2(1'b0), .IN3(~na37_1), .IN4(1'b1), .IN5(~na36_1), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na169_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x8y65     80'h00_0078_00_0020_0C66_0505
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a173_1 ( .OUT(na173_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na39_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na171_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a173_4 ( .OUT(na173_2), .COUTY1(na173_4), .IN1(~na39_1), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(~na39_2), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na171_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x8y60     80'h00_3F00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a174_2 ( .OUT(na174_1), .CLK(1'b1), .EN(1'b0), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a174_6 ( .COUTY1(na174_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na174_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x7y67     80'h00_0078_00_0020_0C66_0C0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a176_1 ( .OUT(na176_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na41_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na189_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a176_4 ( .OUT(na176_2), .COUTY1(na176_4), .IN1(1'b1), .IN2(na41_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na41_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na189_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y68     80'h00_0078_00_0020_0C66_0C0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a178_1 ( .OUT(na178_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na42_1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na176_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a178_4 ( .OUT(na178_2), .COUTY1(na178_4), .IN1(na36_2), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na42_1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na176_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x7y69     80'h00_0018_00_0010_0666_00A0
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a180_1 ( .OUT(na180_1), .IN1(1'b0), .IN2(1'b0), .IN3(na37_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na178_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y62     80'h00_0078_00_0020_0C66_AC0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a181_1 ( .OUT(na181_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na42_2), .IN7(na19_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na190_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a181_4 ( .OUT(na181_2), .COUTY1(na181_4), .IN1(1'b1), .IN2(na31_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na42_2), .IN7(na19_1),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na190_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y63     80'h00_0078_00_0020_0C66_0C0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a183_1 ( .OUT(na183_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na31_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na181_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a183_4 ( .OUT(na183_2), .COUTY1(na183_4), .IN1(na33_2), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na31_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na181_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y64     80'h00_0078_00_0020_0C66_A0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a185_1 ( .OUT(na185_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na19_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na183_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a185_4 ( .OUT(na185_2), .COUTY1(na185_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na35_1), .IN5(1'b0), .IN6(1'b0), .IN7(na19_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na183_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y65     80'h00_0078_00_0020_0C66_0AA0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a187_1 ( .OUT(na187_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na36_1), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na185_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a187_4 ( .OUT(na187_2), .COUTY1(na187_4), .IN1(1'b0), .IN2(1'b0), .IN3(na37_1), .IN4(1'b1), .IN5(na36_1), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na185_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x7y66     80'h00_0078_00_0020_0C66_0A0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a189_1 ( .OUT(na189_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na39_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na187_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a189_4 ( .OUT(na189_2), .COUTY1(na189_4), .IN1(na39_1), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(na39_2), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na187_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x7y61     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a190_2 ( .OUT(na190_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a190_6 ( .COUTY1(na190_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na190_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x16y66     80'h00_0078_00_0020_0C66_CAC0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a191_1 ( .OUT(na191_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na6_1), .IN6(1'b1), .IN7(1'b1), .IN8(na1_2),
                     .CINX(1'b0), .CINY1(na193_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a191_4 ( .OUT(na191_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na1_1), .IN5(na6_1), .IN6(1'b1), .IN7(1'b1), .IN8(na1_2),
                     .CINX(1'b0), .CINY1(na193_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x16y65     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a193_2 ( .OUT(na193_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a193_6 ( .COUTY1(na193_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na193_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x15y60     80'h00_0078_00_0020_0C66_3530
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a194_1 ( .OUT(na194_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(~na6_1), .IN6(1'b1), .IN7(1'b1), .IN8(~na1_2),
                     .CINX(1'b0), .CINY1(na196_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a194_4 ( .OUT(na194_2), .COUTY1(na194_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(~na1_1), .IN5(~na6_1), .IN6(1'b1), .IN7(1'b1),
                     .IN8(~na1_2), .CINX(1'b0), .CINY1(na196_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x15y59     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a196_2 ( .OUT(na196_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a196_6 ( .COUTY1(na196_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na196_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_Route1////      x9y65     80'h00_0018_00_0050_0C66_0000
C_Route1   #(.CPE_CFG (9'b0_0001_0000)) 
           _a197_1 ( .OUT(na197_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0), .CINX(1'b0),
                     .CINY1(na148_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x5y61     80'h00_0078_00_0020_0C66_ACA0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a198_1 ( .OUT(na198_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na361_2), .IN7(na63_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na200_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a198_4 ( .OUT(na198_2), .IN1(1'b0), .IN2(1'b0), .IN3(na63_1), .IN4(1'b1), .IN5(1'b1), .IN6(na361_2), .IN7(na63_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na200_4), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x5y60     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a200_2 ( .OUT(na200_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a200_6 ( .COUTY1(na200_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na200_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_ADDF2///ADDF2/      x11y62     80'h00_0078_00_0020_0C66_0AC0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a202_1 ( .OUT(na202_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na73_2), .IN6(1'b1), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na215_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a202_4 ( .OUT(na202_2), .COUTY1(na202_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na18_1), .IN5(na73_2), .IN6(1'b1), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na215_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y63     80'h00_0078_00_0020_0C66_C0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a204_1 ( .OUT(na204_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na18_2),
                     .CINX(1'b0), .CINY1(na202_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a204_4 ( .OUT(na204_2), .COUTY1(na204_4), .IN1(1'b0), .IN2(1'b0), .IN3(na16_2), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na18_2), .CINX(1'b0), .CINY1(na202_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF////      x11y64     80'h00_0018_00_0010_0666_000C
C_ADDF     #(.CPE_CFG (9'b0_0010_0000)) 
           _a206_1 ( .OUT(na206_1), .IN1(1'b1), .IN2(na8_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na204_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y57     80'h00_0078_00_0020_0C66_AA0A
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a207_1 ( .OUT(na207_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na78_2), .IN6(1'b1), .IN7(na79_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na319_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a207_4 ( .OUT(na207_2), .COUTY1(na207_4), .IN1(na78_1), .IN2(1'b1), .IN3(1'b0), .IN4(1'b0), .IN5(na78_2), .IN6(1'b1), .IN7(na79_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na319_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y58     80'h00_0078_00_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a209_1 ( .OUT(na209_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na72_2),
                     .CINX(1'b0), .CINY1(na207_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a209_4 ( .OUT(na209_2), .COUTY1(na209_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na72_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na72_2), .CINX(1'b0), .CINY1(na207_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y59     80'h00_0078_00_0020_0C66_0C0C
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a211_1 ( .OUT(na211_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na77_2), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(na209_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a211_4 ( .OUT(na211_2), .COUTY1(na211_4), .IN1(1'b1), .IN2(na77_1), .IN3(1'b0), .IN4(1'b0), .IN5(1'b1), .IN6(na77_2), .IN7(1'b0),
                     .IN8(1'b0), .CINX(1'b0), .CINY1(na209_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y60     80'h00_0078_00_0020_0C66_A0A0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a213_1 ( .OUT(na213_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(na76_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(na211_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a213_4 ( .OUT(na213_2), .COUTY1(na213_4), .IN1(1'b0), .IN2(1'b0), .IN3(na76_1), .IN4(1'b1), .IN5(1'b0), .IN6(1'b0), .IN7(na76_2),
                     .IN8(1'b1), .CINX(1'b0), .CINY1(na211_4), .PINX(1'b0), .PINY1(1'b0) );
// C_ADDF2///ADDF2/      x11y61     80'h00_0078_00_0020_0C66_C0C0
C_ADDF2    #(.CPE_CFG (9'b0_0010_0000)) 
           _a215_1 ( .OUT(na215_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1), .IN8(na74_2),
                     .CINX(1'b0), .CINY1(na213_4), .PINX(1'b0), .PINY1(1'b0) );
C_ADDF2    #(.CPE_CFG (9'b0_1000_0000)) 
           _a215_4 ( .OUT(na215_2), .COUTY1(na215_4), .IN1(1'b0), .IN2(1'b0), .IN3(1'b1), .IN4(na74_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b1),
                     .IN8(na74_2), .CINX(1'b0), .CINY1(na213_4), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/D      x13y65     80'h00_FE00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a217_4 ( .OUT(na217_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na87_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a217_5 ( .OUT(na217_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na217_2_i) );
// C_AND/D///      x14y62     80'h00_FE00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a218_1 ( .OUT(na218_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na283_2), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a218_2 ( .OUT(na218_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na218_1_i) );
// C_///AND/D      x12y61     80'h00_FE00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a219_4 ( .OUT(na219_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na284_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a219_5 ( .OUT(na219_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na219_2_i) );
// C_AND/D///      x16y62     80'h00_FE00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a220_1 ( .OUT(na220_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na285_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a220_2 ( .OUT(na220_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na220_1_i) );
// C_///AND/D      x12y59     80'h00_FE00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a221_4 ( .OUT(na221_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na286_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a221_5 ( .OUT(na221_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na221_2_i) );
// C_AND/D///      x16y58     80'h00_FE00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a222_1 ( .OUT(na222_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na287_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a222_2 ( .OUT(na222_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na222_1_i) );
// C_///AND/D      x16y64     80'h00_FE00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a223_4 ( .OUT(na223_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na288_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a223_5 ( .OUT(na223_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na223_2_i) );
// C_AND/D///      x14y63     80'h00_FE00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a224_1 ( .OUT(na224_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na289_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a224_2 ( .OUT(na224_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na224_1_i) );
// C_///AND/D      x15y65     80'h00_FE00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a225_4 ( .OUT(na225_2_i), .IN1(na290_2), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a225_5 ( .OUT(na225_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na225_2_i) );
GLBOUT     #(.GLBOUT_CFG (64'h0000_0000_0000_0010)) 
           _a226 ( .GLB0(na226_1), .GLB1(_d3), .GLB2(_d4), .GLB3(_d5), .CLK_FB0(_d6), .CLK_FB1(_d7), .CLK_FB2(_d8), .CLK_FB3(_d9),
                   .CLK0_0(1'b0), .CLK0_90(1'b0), .CLK0_180(1'b0), .CLK0_270(1'b0), .CLK0_BYP(na7_1), .CLK1_0(1'b0), .CLK1_90(1'b0),
                   .CLK1_180(1'b0), .CLK1_270(1'b0), .CLK1_BYP(1'b0), .CLK2_0(1'b0), .CLK2_90(1'b0), .CLK2_180(1'b0), .CLK2_270(1'b0),
                   .CLK2_BYP(1'b0), .CLK3_0(1'b0), .CLK3_90(1'b0), .CLK3_180(1'b0), .CLK3_270(1'b0), .CLK3_BYP(1'b0), .USR_GLB0(1'b0),
                   .USR_GLB1(1'b0), .USR_GLB2(1'b0), .USR_GLB3(1'b0), .USR_FB0(1'b0), .USR_FB1(1'b0), .USR_FB2(1'b0), .USR_FB3(1'b0) );
// C_AND/D///      x17y62     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a228_1 ( .OUT(na228_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na218_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a228_2 ( .OUT(na228_1), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na228_1_i) );
// C_///AND/D      x14y59     80'h00_FA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a229_4 ( .OUT(na229_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na219_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a229_5 ( .OUT(na229_2), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na229_2_i) );
// C_AND/D///      x14y59     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a230_1 ( .OUT(na230_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na220_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a230_2 ( .OUT(na230_1), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na230_1_i) );
// C_///AND/D      x16y57     80'h00_FA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a231_4 ( .OUT(na231_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na221_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a231_5 ( .OUT(na231_2), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na231_2_i) );
// C_AND/D///      x14y67     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a232_1 ( .OUT(na232_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na222_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a232_2 ( .OUT(na232_1), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na232_1_i) );
// C_///AND/D      x13y68     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a233_4 ( .OUT(na233_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na223_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a233_5 ( .OUT(na233_2), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na233_2_i) );
// C_AND/D///      x10y64     80'h00_FA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a234_1 ( .OUT(na234_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na224_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a234_2 ( .OUT(na234_1), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na234_1_i) );
// C_///AND/D      x18y68     80'h00_FA00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a235_4 ( .OUT(na235_2_i), .IN1(na225_2), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a235_5 ( .OUT(na235_2), .CLK(na226_1), .EN(na217_2), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na235_2_i) );
// C_AND/D///      x16y68     80'h00_FE00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a239_1 ( .OUT(na239_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na51_2), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a239_2 ( .OUT(na239_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na239_1_i) );
// C_///AND/D      x17y66     80'h00_FE00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a241_4 ( .OUT(na241_2_i), .IN1(1'b1), .IN2(na242_1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0100)) 
           _a241_5 ( .OUT(na241_2), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na241_2_i) );
// C_AND/D///      x17y64     80'h00_FE00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a242_1 ( .OUT(na242_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na313_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b1_0000_0000)) 
           _a242_2 ( .OUT(na242_1), .CLK(na226_1), .EN(1'b1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na242_1_i) );
// C_///AND/D      x14y65     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a283_4 ( .OUT(na283_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na88_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a283_5 ( .OUT(na283_2), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na283_2_i) );
// C_///AND/D      x14y64     80'h00_FA00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a284_4 ( .OUT(na284_2_i), .IN1(na90_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a284_5 ( .OUT(na284_2), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na284_2_i) );
// C_AND/D///      x16y60     80'h00_FA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a285_1 ( .OUT(na285_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na92_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a285_2 ( .OUT(na285_1), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na285_1_i) );
// C_AND/D///      x20y64     80'h00_FA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a286_1 ( .OUT(na286_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na94_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a286_2 ( .OUT(na286_1), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na286_1_i) );
// C_///AND/D      x18y60     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a287_4 ( .OUT(na287_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na96_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a287_5 ( .OUT(na287_2), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na287_2_i) );
// C_AND/D///      x14y64     80'h00_FA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a288_1 ( .OUT(na288_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na98_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a288_2 ( .OUT(na288_1), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na288_1_i) );
// C_AND/D///      x13y64     80'h00_FA00_00_0000_0C88_FAFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a289_1 ( .OUT(na289_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na99_1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0000)) 
           _a289_2 ( .OUT(na289_1), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na289_1_i) );
// C_///AND/D      x17y63     80'h00_FA00_80_0000_0C08_FFFA
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a290_4 ( .OUT(na290_2_i), .IN1(na100_1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'bX_0000_0100)) 
           _a290_5 ( .OUT(na290_2), .CLK(na226_1), .EN(na54_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na290_2_i) );
// C_AND/D///      x10y59     80'h00_FA00_00_0000_0C88_FCFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a294_1 ( .OUT(na294_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(na228_1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a294_2 ( .OUT(na294_1), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na294_1_i) );
// C_///AND/D      x6y60     80'h00_FA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a295_4 ( .OUT(na295_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na229_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a295_5 ( .OUT(na295_2), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na295_2_i) );
// C_AND/D///      x13y57     80'h00_FA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a296_1 ( .OUT(na296_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na230_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a296_2 ( .OUT(na296_1), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na296_1_i) );
// C_///AND/D      x13y58     80'h00_FA00_80_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a297_4 ( .OUT(na297_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(na231_2), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a297_5 ( .OUT(na297_2), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na297_2_i) );
// C_AND/D///      x10y66     80'h00_FA00_00_0000_0C88_AFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a298_1 ( .OUT(na298_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(na232_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a298_2 ( .OUT(na298_1), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na298_1_i) );
// C_///AND/D      x10y65     80'h00_FA00_80_0000_0C08_FFFC
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a299_4 ( .OUT(na299_2_i), .IN1(1'b1), .IN2(na233_2), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a299_5 ( .OUT(na299_2), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na299_2_i) );
// C_AND/D///      x5y62     80'h00_FA00_00_0000_0C88_CFFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a300_1 ( .OUT(na300_1_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(na234_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0000)) 
           _a300_2 ( .OUT(na300_1), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na300_1_i) );
// C_///AND/D      x3y61     80'h00_FA00_80_0000_0C08_FFCF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a301_4 ( .OUT(na301_2_i), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(na235_2), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_D        #(.CPE_CFG (9'b0_0000_0100)) 
           _a301_5 ( .OUT(na301_2), .CLK(na226_1), .EN(na66_1), .SR(1'b1), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN(na301_2_i) );
// C_MX4b////      x6y57     80'h00_0018_00_0040_0AF0_003A
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a310_1 ( .OUT(na310_1), .IN1(na362_2), .IN2(1'b1), .IN3(1'b1), .IN4(~na62_2), .IN5(na296_1), .IN6(na297_2), .IN7(na294_1),
                     .IN8(na295_2), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_MX4b////      x3y59     80'h00_0018_00_0040_0AF0_0035
C_MX4b     #(.CPE_CFG (9'b0_0000_0000)) 
           _a311_1 ( .OUT(na311_1), .IN1(~na362_2), .IN2(1'b1), .IN3(1'b1), .IN4(~na62_2), .IN5(na301_2), .IN6(na300_1), .IN7(na299_2),
                     .IN8(na298_1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000090)) 
           _a312 ( .Y(na312_1), .I(clk) );
CPE_IBF    #(.BUF_CFG (72'h000001000000000050)) 
           _a313 ( .Y(na313_1), .I(i_Rx_Serial) );
CPE_OBF    #(.BUF_CFG (72'h000000000100010900)) 
           _a314 ( .O(o_Tx_Serial), .A(na352_10) );
// C_AND////      x10y68     80'h00_0018_00_0000_0C88_1FFF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a316_1 ( .OUT(na316_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(~na27_1), .IN8(~na20_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x14y70     80'h00_0018_00_0000_0888_4238
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a318_1 ( .OUT(na318_1), .IN1(na23_1), .IN2(na31_1), .IN3(1'b1), .IN4(~na355_2), .IN5(na33_2), .IN6(~na354_2), .IN7(~na19_2),
                     .IN8(na35_1), .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_/C_0_1///      x11y56     80'h00_CF00_12_0800_0C00_FFFF
C_C_0_1    #(.CPE_CFG (9'bX_0000_0000)) 
           _a319_2 ( .OUT(na319_1), .CLK(1'b1), .EN(1'b1), .SR(1'b0), .CINY2(1'b0), .PINY2(1'b0), .RAM_I(1'b0), .CP_O(1'b0), .D_IN() );
C_CPlines  #(.CPE_CFG (19'h1_2080)) 
           _a319_6 ( .COUTY1(na319_4), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(na319_1),
                     .OUT2(1'b0), .COMP_OUT(1'b0) );
// C_Route1////      x8y69     80'h00_0018_00_0050_0C66_0000
C_Route1   #(.CPE_CFG (9'b0_0001_0000)) 
           _a320_1 ( .OUT(na320_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0), .CINX(1'b0),
                     .CINY1(na164_4), .PINX(1'b0), .PINY1(1'b0) );
// C_Route1////      x15y61     80'h00_0018_00_0050_0C66_0000
C_Route1   #(.CPE_CFG (9'b0_0001_0000)) 
           _a321_1 ( .OUT(na321_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0), .CINX(1'b0),
                     .CINY1(na194_4), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x15y66     80'h00_0018_00_0000_0C88_88FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a334_1 ( .OUT(na334_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(na6_1), .IN6(na46_1), .IN7(na353_2), .IN8(na1_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///OR/      x5y60     80'h00_0060_00_0000_0C0E_FF75
C_OR       #(.CPE_CFG (9'b0_1000_0000)) 
           _a342_4 ( .OUT(na342_2), .IN1(~na362_2), .IN2(1'b0), .IN3(~na63_1), .IN4(~na62_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x10y55     80'h00_0060_00_0000_0C08_FFC5
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a344_4 ( .OUT(na344_2), .IN1(~na141_1), .IN2(1'b1), .IN3(1'b1), .IN4(na61_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_XOR////      x13y58     80'h00_0018_00_0000_0C66_CA00
C_XOR      #(.CPE_CFG (9'b0_0000_0000)) 
           _a345_1 ( .OUT(na345_1), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na141_1), .IN6(1'b0), .IN7(1'b0), .IN8(na67_1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x14y67     80'h00_0060_00_0000_0C08_FF88
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a347_4 ( .OUT(na347_2), .IN1(na23_1), .IN2(na21_1), .IN3(na370_2), .IN4(na26_1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x10y58     80'h00_0018_00_0000_0C88_53FF
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a348_1 ( .OUT(na348_1), .IN1(1'b1), .IN2(1'b1), .IN3(1'b1), .IN4(1'b1), .IN5(1'b1), .IN6(~na68_2), .IN7(~na9_1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_AND////      x4y59     80'h00_0018_00_0000_0888_8F85
C_AND      #(.CPE_CFG (9'b0_0000_0000)) 
           _a351_1 ( .OUT(na351_1), .IN1(~na197_1), .IN2(1'b1), .IN3(na63_1), .IN4(na67_1), .IN5(1'b1), .IN6(1'b1), .IN7(na63_2), .IN8(na62_2),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
// C_///AND/      x1y51     80'h08_0060_00_0000_0C08_FFAF
C_AND      #(.CPE_CFG (9'b0_1000_0000)) 
           _a352_4 ( .OUT(na352_2), .IN1(1'b1), .IN2(1'b1), .IN3(na60_1), .IN4(1'b1), .IN5(1'b1), .IN6(1'b1), .IN7(1'b1), .IN8(1'b1),
                     .CINX(1'b0), .CINY1(1'b0), .PINX(1'b0), .PINY1(1'b0) );
C_CPlines  #(.CPE_CFG (19'h0_0000)) 
           _a352_6 ( .RAM_O2(na352_10), .CINX(1'b0), .CINY1(1'b0), .CINY2(1'b0), .PINX(1'b0), .PINY1(1'b0), .PINY2(1'b0), .OUT1(1'b0),
                     .OUT2(na352_2), .COMP_OUT(1'b0) );
// C_////Bridge      x18y63     80'h00_00A3_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a353_5 ( .OUT(na353_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(na1_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x15y70     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a354_5 ( .OUT(na354_2), .IN1(1'b0), .IN2(1'b0), .IN3(na19_1), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x16y70     80'h00_00A5_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a355_5 ( .OUT(na355_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(na31_2), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x14y68     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a356_5 ( .OUT(na356_2), .IN1(na39_2), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x12y65     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a357_5 ( .OUT(na357_2), .IN1(1'b0), .IN2(na41_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x14y61     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a358_5 ( .OUT(na358_2), .IN1(na45_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x14y63     80'h00_00A4_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a359_5 ( .OUT(na359_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(na51_1), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x10y64     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a360_5 ( .OUT(na360_2), .IN1(1'b0), .IN2(na54_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x7y60     80'h00_00A3_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a361_5 ( .OUT(na361_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(na62_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x7y59     80'h00_00A2_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a362_5 ( .OUT(na362_2), .IN1(1'b0), .IN2(1'b0), .IN3(na63_2), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x13y62     80'h00_00A3_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a363_5 ( .OUT(na363_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(na67_1), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x10y57     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a364_5 ( .OUT(na364_2), .IN1(1'b0), .IN2(na68_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x10y58     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a365_5 ( .OUT(na365_2), .IN1(1'b0), .IN2(na68_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x17y64     80'h00_00A3_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a366_5 ( .OUT(na366_2), .IN1(1'b0), .IN2(1'b0), .IN3(1'b0), .IN4(na74_2), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x18y59     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a367_5 ( .OUT(na367_2), .IN1(na141_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x8y56     80'h00_00A0_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a368_5 ( .OUT(na368_2), .IN1(na141_1), .IN2(1'b0), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x18y57     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a369_5 ( .OUT(na369_2), .IN1(1'b0), .IN2(na194_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x16y67     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a370_5 ( .OUT(na370_2), .IN1(1'b0), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
// C_////Bridge      x10y62     80'h00_00A1_00_0000_0C00_FFFF
C_Bridge   #(.CPE_CFG (9'bX_0000_1001)) 
           _a371_5 ( .OUT(na371_2), .IN1(1'b0), .IN2(na241_2), .IN3(1'b0), .IN4(1'b0), .IN5(1'b0), .IN6(1'b0), .IN7(1'b0), .IN8(1'b0) );
endmodule
