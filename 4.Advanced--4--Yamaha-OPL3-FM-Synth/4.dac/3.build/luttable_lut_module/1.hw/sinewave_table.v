
module sinewave_table #(
    parameter LUT_DEPTH  = 8,
    parameter DATA_WIDTH = 16
)(
    input  wire [LUT_DEPTH-1:0] address, // 8-bit address signal for 256 values
    output reg [DATA_WIDTH-1:0] value    // 16-bit unsigned output signal
);

    always @(*) begin
        unique case (address)
            8'd0: value = 16'h7FFF;
            8'd1: value = 16'h8323;
            8'd2: value = 16'h8647;
            8'd3: value = 16'h896A;
            8'd4: value = 16'h8C8B;
            8'd5: value = 16'h8FAA;
            8'd6: value = 16'h92C7;
            8'd7: value = 16'h95E1;
            8'd8: value = 16'h98F8;
            8'd9: value = 16'h9C0A;
            8'd10: value = 16'h9F19;
            8'd11: value = 16'hA223;
            8'd12: value = 16'hA527;
            8'd13: value = 16'hA826;
            8'd14: value = 16'hAB1E;
            8'd15: value = 16'hAE10;
            8'd16: value = 16'hB0FB;
            8'd17: value = 16'hB3DE;
            8'd18: value = 16'hB6B9;
            8'd19: value = 16'hB98C;
            8'd20: value = 16'hBC55;
            8'd21: value = 16'hBF16;
            8'd22: value = 16'hC1CD;
            8'd23: value = 16'hC47A;
            8'd24: value = 16'hC71C;
            8'd25: value = 16'hC9B3;
            8'd26: value = 16'hCC3F;
            8'd27: value = 16'hCEBF;
            8'd28: value = 16'hD132;
            8'd29: value = 16'hD39A;
            8'd30: value = 16'hD5F4;
            8'd31: value = 16'hD842;
            8'd32: value = 16'hDA81;
            8'd33: value = 16'hDCB3;
            8'd34: value = 16'hDED6;
            8'd35: value = 16'hE0EB;
            8'd36: value = 16'hE2F1;
            8'd37: value = 16'hE4E7;
            8'd38: value = 16'hE6CE;
            8'd39: value = 16'hE8A5;
            8'd40: value = 16'hEA6C;
            8'd41: value = 16'hEC23;
            8'd42: value = 16'hEDC9;
            8'd43: value = 16'hEF5E;
            8'd44: value = 16'hF0E1;
            8'd45: value = 16'hF254;
            8'd46: value = 16'hF3B4;
            8'd47: value = 16'hF503;
            8'd48: value = 16'hF640;
            8'd49: value = 16'hF76B;
            8'd50: value = 16'hF883;
            8'd51: value = 16'hF989;
            8'd52: value = 16'hFA7C;
            8'd53: value = 16'hFB5C;
            8'd54: value = 16'hFC28;
            8'd55: value = 16'hFCE2;
            8'd56: value = 16'hFD89;
            8'd57: value = 16'hFE1C;
            8'd58: value = 16'hFE9C;
            8'd59: value = 16'hFF08;
            8'd60: value = 16'hFF61;
            8'd61: value = 16'hFFA6;
            8'd62: value = 16'hFFD7;
            8'd63: value = 16'hFFF5;
            8'd64: value = 16'hFFFF;
            8'd65: value = 16'hFFF5;
            8'd66: value = 16'hFFD7;
            8'd67: value = 16'hFFA6;
            8'd68: value = 16'hFF61;
            8'd69: value = 16'hFF08;
            8'd70: value = 16'hFE9C;
            8'd71: value = 16'hFE1C;
            8'd72: value = 16'hFD89;
            8'd73: value = 16'hFCE2;
            8'd74: value = 16'hFC28;
            8'd75: value = 16'hFB5C;
            8'd76: value = 16'hFA7C;
            8'd77: value = 16'hF989;
            8'd78: value = 16'hF883;
            8'd79: value = 16'hF76B;
            8'd80: value = 16'hF640;
            8'd81: value = 16'hF503;
            8'd82: value = 16'hF3B4;
            8'd83: value = 16'hF254;
            8'd84: value = 16'hF0E1;
            8'd85: value = 16'hEF5E;
            8'd86: value = 16'hEDC9;
            8'd87: value = 16'hEC23;
            8'd88: value = 16'hEA6C;
            8'd89: value = 16'hE8A5;
            8'd90: value = 16'hE6CE;
            8'd91: value = 16'hE4E7;
            8'd92: value = 16'hE2F1;
            8'd93: value = 16'hE0EB;
            8'd94: value = 16'hDED6;
            8'd95: value = 16'hDCB3;
            8'd96: value = 16'hDA81;
            8'd97: value = 16'hD842;
            8'd98: value = 16'hD5F4;
            8'd99: value = 16'hD39A;
            8'd100: value = 16'hD132;
            8'd101: value = 16'hCEBF;
            8'd102: value = 16'hCC3F;
            8'd103: value = 16'hC9B3;
            8'd104: value = 16'hC71C;
            8'd105: value = 16'hC47A;
            8'd106: value = 16'hC1CD;
            8'd107: value = 16'hBF16;
            8'd108: value = 16'hBC55;
            8'd109: value = 16'hB98C;
            8'd110: value = 16'hB6B9;
            8'd111: value = 16'hB3DE;
            8'd112: value = 16'hB0FB;
            8'd113: value = 16'hAE10;
            8'd114: value = 16'hAB1E;
            8'd115: value = 16'hA826;
            8'd116: value = 16'hA527;
            8'd117: value = 16'hA223;
            8'd118: value = 16'h9F19;
            8'd119: value = 16'h9C0A;
            8'd120: value = 16'h98F8;
            8'd121: value = 16'h95E1;
            8'd122: value = 16'h92C7;
            8'd123: value = 16'h8FAA;
            8'd124: value = 16'h8C8B;
            8'd125: value = 16'h896A;
            8'd126: value = 16'h8647;
            8'd127: value = 16'h8323;
            8'd128: value = 16'h7FFF;
            8'd129: value = 16'h7CDB;
            8'd130: value = 16'h79B7;
            8'd131: value = 16'h7694;
            8'd132: value = 16'h7373;
            8'd133: value = 16'h7054;
            8'd134: value = 16'h6D37;
            8'd135: value = 16'h6A1D;
            8'd136: value = 16'h6706;
            8'd137: value = 16'h63F4;
            8'd138: value = 16'h60E5;
            8'd139: value = 16'h5DDB;
            8'd140: value = 16'h5AD7;
            8'd141: value = 16'h57D8;
            8'd142: value = 16'h54E0;
            8'd143: value = 16'h51EE;
            8'd144: value = 16'h4F03;
            8'd145: value = 16'h4C20;
            8'd146: value = 16'h4945;
            8'd147: value = 16'h4672;
            8'd148: value = 16'h43A9;
            8'd149: value = 16'h40E8;
            8'd150: value = 16'h3E31;
            8'd151: value = 16'h3B84;
            8'd152: value = 16'h38E2;
            8'd153: value = 16'h364B;
            8'd154: value = 16'h33BF;
            8'd155: value = 16'h313F;
            8'd156: value = 16'h2ECC;
            8'd157: value = 16'h2C64;
            8'd158: value = 16'h2A0A;
            8'd159: value = 16'h27BC;
            8'd160: value = 16'h257D;
            8'd161: value = 16'h234B;
            8'd162: value = 16'h2128;
            8'd163: value = 16'h1F13;
            8'd164: value = 16'h1D0D;
            8'd165: value = 16'h1B17;
            8'd166: value = 16'h1930;
            8'd167: value = 16'h1759;
            8'd168: value = 16'h1592;
            8'd169: value = 16'h13DB;
            8'd170: value = 16'h1235;
            8'd171: value = 16'h10A0;
            8'd172: value = 16'hF1D;
            8'd173: value = 16'hDAA;
            8'd174: value = 16'hC4A;
            8'd175: value = 16'hAFB;
            8'd176: value = 16'h9BE;
            8'd177: value = 16'h893;
            8'd178: value = 16'h77B;
            8'd179: value = 16'h675;
            8'd180: value = 16'h582;
            8'd181: value = 16'h4A2;
            8'd182: value = 16'h3D6;
            8'd183: value = 16'h31C;
            8'd184: value = 16'h275;
            8'd185: value = 16'h1E2;
            8'd186: value = 16'h162;
            8'd187: value = 16'hF6;
            8'd188: value = 16'h9D;
            8'd189: value = 16'h58;
            8'd190: value = 16'h27;
            8'd191: value = 16'h9;
            8'd192: value = 16'h0;
            8'd193: value = 16'h9;
            8'd194: value = 16'h27;
            8'd195: value = 16'h58;
            8'd196: value = 16'h9D;
            8'd197: value = 16'hF6;
            8'd198: value = 16'h162;
            8'd199: value = 16'h1E2;
            8'd200: value = 16'h275;
            8'd201: value = 16'h31C;
            8'd202: value = 16'h3D6;
            8'd203: value = 16'h4A2;
            8'd204: value = 16'h582;
            8'd205: value = 16'h675;
            8'd206: value = 16'h77B;
            8'd207: value = 16'h893;
            8'd208: value = 16'h9BE;
            8'd209: value = 16'hAFB;
            8'd210: value = 16'hC4A;
            8'd211: value = 16'hDAA;
            8'd212: value = 16'hF1D;
            8'd213: value = 16'h10A0;
            8'd214: value = 16'h1235;
            8'd215: value = 16'h13DB;
            8'd216: value = 16'h1592;
            8'd217: value = 16'h1759;
            8'd218: value = 16'h1930;
            8'd219: value = 16'h1B17;
            8'd220: value = 16'h1D0D;
            8'd221: value = 16'h1F13;
            8'd222: value = 16'h2128;
            8'd223: value = 16'h234B;
            8'd224: value = 16'h257D;
            8'd225: value = 16'h27BC;
            8'd226: value = 16'h2A0A;
            8'd227: value = 16'h2C64;
            8'd228: value = 16'h2ECC;
            8'd229: value = 16'h313F;
            8'd230: value = 16'h33BF;
            8'd231: value = 16'h364B;
            8'd232: value = 16'h38E2;
            8'd233: value = 16'h3B84;
            8'd234: value = 16'h3E31;
            8'd235: value = 16'h40E8;
            8'd236: value = 16'h43A9;
            8'd237: value = 16'h4672;
            8'd238: value = 16'h4945;
            8'd239: value = 16'h4C20;
            8'd240: value = 16'h4F03;
            8'd241: value = 16'h51EE;
            8'd242: value = 16'h54E0;
            8'd243: value = 16'h57D8;
            8'd244: value = 16'h5AD7;
            8'd245: value = 16'h5DDB;
            8'd246: value = 16'h60E5;
            8'd247: value = 16'h63F4;
            8'd248: value = 16'h6706;
            8'd249: value = 16'h6A1D;
            8'd250: value = 16'h6D37;
            8'd251: value = 16'h7054;
            8'd252: value = 16'h7373;
            8'd253: value = 16'h7694;
            8'd254: value = 16'h79B7;
            8'd255: value = 16'h7CDB;
            default: value = 16'h0;
        endcase
    end

endmodule