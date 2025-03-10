
module quarterwave_table #(
    parameter QLUT_DEPTH = 8,
    parameter DATA_WIDTH = 16
)(
    input  wire        [QLUT_DEPTH-3:0] address, // 6-bit address signal for 64 values
    output reg signed [DATA_WIDTH-1:0] value    // 16-bit output signal
);

    always @* begin
         case(address)
            6'd0: value = 16'h192;
            6'd1: value = 16'h4B6;
            6'd2: value = 16'h7D9;
            6'd3: value = 16'hAFB;
            6'd4: value = 16'hE1B;
            6'd5: value = 16'h1139;
            6'd6: value = 16'h1455;
            6'd7: value = 16'h176D;
            6'd8: value = 16'h1A82;
            6'd9: value = 16'h1D93;
            6'd10: value = 16'h209F;
            6'd11: value = 16'h23A6;
            6'd12: value = 16'h26A7;
            6'd13: value = 16'h29A3;
            6'd14: value = 16'h2C98;
            6'd15: value = 16'h2F86;
            6'd16: value = 16'h326D;
            6'd17: value = 16'h354D;
            6'd18: value = 16'h3824;
            6'd19: value = 16'h3AF2;
            6'd20: value = 16'h3DB7;
            6'd21: value = 16'h4073;
            6'd22: value = 16'h4325;
            6'd23: value = 16'h45CC;
            6'd24: value = 16'h4869;
            6'd25: value = 16'h4AFA;
            6'd26: value = 16'h4D80;
            6'd27: value = 16'h4FFA;
            6'd28: value = 16'h5268;
            6'd29: value = 16'h54C9;
            6'd30: value = 16'h571D;
            6'd31: value = 16'h5963;
            6'd32: value = 16'h5B9C;
            6'd33: value = 16'h5DC6;
            6'd34: value = 16'h5FE2;
            6'd35: value = 16'h61F0;
            6'd36: value = 16'h63EE;
            6'd37: value = 16'h65DD;
            6'd38: value = 16'h67BC;
            6'd39: value = 16'h698B;
            6'd40: value = 16'h6B4A;
            6'd41: value = 16'h6CF8;
            6'd42: value = 16'h6E95;
            6'd43: value = 16'h7022;
            6'd44: value = 16'h719D;
            6'd45: value = 16'h7306;
            6'd46: value = 16'h745E;
            6'd47: value = 16'h75A4;
            6'd48: value = 16'h76D8;
            6'd49: value = 16'h77F9;
            6'd50: value = 16'h7908;
            6'd51: value = 16'h7A04;
            6'd52: value = 16'h7AEE;
            6'd53: value = 16'h7BC4;
            6'd54: value = 16'h7C88;
            6'd55: value = 16'h7D38;
            6'd56: value = 16'h7DD5;
            6'd57: value = 16'h7E5E;
            6'd58: value = 16'h7ED4;
            6'd59: value = 16'h7F37;
            6'd60: value = 16'h7F86;
            6'd61: value = 16'h7FC1;
            6'd62: value = 16'h7FE8;
            6'd63: value = 16'h7FFC;

            default: value = 16'd0;
        endcase
    end

endmodule
