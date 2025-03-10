module halfBandFirst (
    input wire clk,
    input wire clk_enable,
    input wire reset,
    input wire signed [15:0] filter_in,
    output signed [20:0] filter_out,
    output ce_out
);

   reg signed [21:0] coeffs [0:32]; // Register array for coefficients

	initial begin
		 coeffs[0]  = 22'b0000000000000000010110; // COEFFPHASE1_66
		 coeffs[1]  = 22'b1111111111111111011010; // COEFFPHASE1_65
		 coeffs[2]  = 22'b0000000000000001000101; // COEFFPHASE1_64
		 coeffs[3]  = 22'b1111111111111110001101; // COEFFPHASE1_63
		 coeffs[4]  = 22'b0000000000000010110111; // COEFFPHASE1_62
		 coeffs[5]  = 22'b1111111111111011101010; // COEFFPHASE1_61
		 coeffs[6]  = 22'b0000000000000110011000; // COEFFPHASE1_60
		 coeffs[7]  = 22'b1111111111110110111011; // COEFFPHASE1_59
		 coeffs[8]  = 22'b0000000000001100101000; // COEFFPHASE1_58
		 coeffs[9]  = 22'b1111111111101110110100; // COEFFPHASE1_57
		 coeffs[10] = 22'b0000000000010110111110; // COEFFPHASE1_56
		 coeffs[11] = 22'b1111111111100001110010; // COEFFPHASE1_55
		 coeffs[12] = 22'b0000000000100111001011; // COEFFPHASE1_54
		 coeffs[13] = 22'b1111111111001101111000; // COEFFPHASE1_53
		 coeffs[14] = 22'b0000000000111111011010; // COEFFPHASE1_52
		 coeffs[15] = 22'b1111111110110000100111; // COEFFPHASE1_51
		 coeffs[16] = 22'b0000000001100010100000; // COEFFPHASE1_50
		 coeffs[17] = 22'b1111111110000110110010; // COEFFPHASE1_49
		 coeffs[18] = 22'b0000000010010100001001; // COEFFPHASE1_48
		 coeffs[19] = 22'b1111111101001100000011; // COEFFPHASE1_47
		 coeffs[20] = 22'b0000000011011001100101; // COEFFPHASE1_46
		 coeffs[21] = 22'b1111111011111001110111; // COEFFPHASE1_45
		 coeffs[22] = 22'b0000000100111011001101; // COEFFPHASE1_44
		 coeffs[23] = 22'b1111111010000101000011; // COEFFPHASE1_43
		 coeffs[24] = 22'b0000000111001000100011; // COEFFPHASE1_42
		 coeffs[25] = 22'b1111110111010111001001; // COEFFPHASE1_41
		 coeffs[26] = 22'b0000001010100011101110; // COEFFPHASE1_40
		 coeffs[27] = 22'b1111110010111001001111; // COEFFPHASE1_39
		 coeffs[28] = 22'b0000010000101011110000; // COEFFPHASE1_38
		 coeffs[29] = 22'b1111101001110101111001; // COEFFPHASE1_37
		 coeffs[30] = 22'b0000011111110010001000; // COEFFPHASE1_36
		 coeffs[31] = 22'b1111001010001010100111; // COEFFPHASE1_35
		 coeffs[32] = 22'b0010100010110011111000; // COEFFPHASE1_34
	end


    // Delay line for input samples and coeff sharing
    reg signed [15:0] delay_pipeline [0:65]; // sfix16_En15
    wire signed [16:0] tapsum [0:32];

    wire signed [15:0] add_signext; // sfix16_En15
    wire signed [15:0] add_signext_1; // sfix16_En15

    wire signed [15:0] add_signext_2; // sfix16_En15
    wire signed [15:0] add_signext_3; // sfix16_En15

    wire signed [15:0] add_signext_4; // sfix16_En15
    wire signed [15:0] add_signext_5; // sfix16_En15

    wire signed [15:0] add_signext_6; // sfix16_En15
    wire signed [15:0] add_signext_7; // sfix16_En15

    wire signed [15:0] add_signext_8; // sfix16_En15
    wire signed [15:0] add_signext_9; // sfix16_En15

    wire signed [15:0] add_signext_10; // sfix16_En15
    wire signed [15:0] add_signext_11; // sfix16_En15

    wire signed [15:0] add_signext_12; // sfix16_En15
    wire signed [15:0] add_signext_13; // sfix16_En15

    wire signed [15:0] add_signext_14; // sfix16_En15
    wire signed [15:0] add_signext_15; // sfix16_En15

    wire signed [15:0] add_signext_16; // sfix16_En15
    wire signed [15:0] add_signext_17; // sfix16_En15

    wire signed [15:0] add_signext_18; // sfix16_En15
    wire signed [15:0] add_signext_19; // sfix16_En15

    wire signed [15:0] add_signext_20; // sfix16_En15
    wire signed [15:0] add_signext_21; // sfix16_En15

    wire signed [15:0] add_signext_22; // sfix16_En15
    wire signed [15:0] add_signext_23; // sfix16_En15

    wire signed [15:0] add_signext_24; // sfix16_En15
    wire signed [15:0] add_signext_25; // sfix16_En15

    wire signed [15:0] add_signext_26; // sfix16_En15
    wire signed [15:0] add_signext_27; // sfix16_En15

    wire signed [15:0] add_signext_28; // sfix16_En15
    wire signed [15:0] add_signext_29; // sfix16_En15

    wire signed [15:0] add_signext_30; // sfix16_En15
    wire signed [15:0] add_signext_31; // sfix16_En15

    wire signed [15:0] add_signext_32; // sfix16_En15
    wire signed [15:0] add_signext_33; // sfix16_En15

    wire signed [15:0] add_signext_34; // sfix16_En15
    wire signed [15:0] add_signext_35; // sfix16_En15

    wire signed [15:0] add_signext_36; // sfix16_En15
    wire signed [15:0] add_signext_37; // sfix16_En15

    wire signed [15:0] add_signext_38; // sfix16_En15
    wire signed [15:0] add_signext_39; // sfix16_En15

    wire signed [15:0] add_signext_40; // sfix16_En15
    wire signed [15:0] add_signext_41; // sfix16_En15

    wire signed [15:0] add_signext_42; // sfix16_En15
    wire signed [15:0] add_signext_43; // sfix16_En15

    wire signed [15:0] add_signext_44; // sfix16_En15
    wire signed [15:0] add_signext_45; // sfix16_En15

    wire signed [15:0] add_signext_46; // sfix16_En15
    wire signed [15:0] add_signext_47; // sfix16_En15

    wire signed [15:0] add_signext_48; // sfix16_En15
    wire signed [15:0] add_signext_49; // sfix16_En15

    wire signed [15:0] add_signext_50; // sfix16_En15
    wire signed [15:0] add_signext_51; // sfix16_En15

    wire signed [15:0] add_signext_52; // sfix16_En15
    wire signed [15:0] add_signext_53; // sfix16_En15

    wire signed [15:0] add_signext_54; // sfix16_En15
    wire signed [15:0] add_signext_55; // sfix16_En15

    wire signed [15:0] add_signext_56; // sfix16_En15
    wire signed [15:0] add_signext_57; // sfix16_En15

    wire signed [15:0] add_signext_58; // sfix16_En15
    wire signed [15:0] add_signext_59; // sfix16_En15

    wire signed [15:0] add_signext_60; // sfix16_En15
    wire signed [15:0] add_signext_61; // sfix16_En15

    wire signed [15:0] add_signext_62; // sfix16_En15
    wire signed [15:0] add_signext_63; // sfix16_En15

    wire signed [15:0] add_signext_64; // sfix16_En15
    wire signed [15:0] add_signext_65; // sfix16_En15


    reg  [1:0] cur_count; // ufix2
    wire phase_1; // boolean

    // Phase control logic


    always @ (posedge clk or posedge reset)
    begin: ce_output
      if (reset == 1'b1) begin
        cur_count <= 2'b00;

      end
      else begin
        if (clk_enable == 1'b1) begin

          if (cur_count >= 2'b01) begin
            cur_count <= 2'b00;
          end
          else begin
            cur_count <= cur_count + 2'b01;
          end
        end

	  end
    end // ce_output

    assign  phase_1 = (cur_count == 2'b01 && clk_enable == 1'b1) ? 1'b1 : 1'b0;


      // Delay pipeline for input samples
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            delay_pipeline[0] <= 0;
            delay_pipeline[1] <= 0;
            delay_pipeline[2] <= 0;
            delay_pipeline[3] <= 0;
            delay_pipeline[4] <= 0;
            delay_pipeline[5] <= 0;
            delay_pipeline[6] <= 0;
            delay_pipeline[7] <= 0;
            delay_pipeline[8] <= 0;
            delay_pipeline[9] <= 0;
            delay_pipeline[10] <= 0;
            delay_pipeline[11] <= 0;
            delay_pipeline[12] <= 0;
            delay_pipeline[13] <= 0;
            delay_pipeline[14] <= 0;
            delay_pipeline[15] <= 0;
            delay_pipeline[16] <= 0;
            delay_pipeline[17] <= 0;
            delay_pipeline[18] <= 0;
            delay_pipeline[19] <= 0;
            delay_pipeline[20] <= 0;
            delay_pipeline[21] <= 0;
            delay_pipeline[22] <= 0;
            delay_pipeline[23] <= 0;
            delay_pipeline[24] <= 0;
            delay_pipeline[25] <= 0;
            delay_pipeline[26] <= 0;
            delay_pipeline[27] <= 0;
            delay_pipeline[28] <= 0;
            delay_pipeline[29] <= 0;
            delay_pipeline[30] <= 0;
            delay_pipeline[31] <= 0;
            delay_pipeline[32] <= 0;
            delay_pipeline[33] <= 0;
            delay_pipeline[34] <= 0;
            delay_pipeline[35] <= 0;
            delay_pipeline[36] <= 0;
            delay_pipeline[37] <= 0;
            delay_pipeline[38] <= 0;
            delay_pipeline[39] <= 0;
            delay_pipeline[40] <= 0;
            delay_pipeline[41] <= 0;
            delay_pipeline[42] <= 0;
            delay_pipeline[43] <= 0;
            delay_pipeline[44] <= 0;
            delay_pipeline[45] <= 0;
            delay_pipeline[46] <= 0;
            delay_pipeline[47] <= 0;
            delay_pipeline[48] <= 0;
            delay_pipeline[49] <= 0;
            delay_pipeline[50] <= 0;
            delay_pipeline[51] <= 0;
            delay_pipeline[52] <= 0;
            delay_pipeline[53] <= 0;
            delay_pipeline[54] <= 0;
            delay_pipeline[55] <= 0;
            delay_pipeline[56] <= 0;
            delay_pipeline[57] <= 0;
            delay_pipeline[58] <= 0;
            delay_pipeline[59] <= 0;
            delay_pipeline[60] <= 0;
            delay_pipeline[61] <= 0;
            delay_pipeline[62] <= 0;
            delay_pipeline[63] <= 0;
            delay_pipeline[64] <= 0;
            delay_pipeline[65] <= 0;
        end else if (phase_1 == 1'b1) begin
            delay_pipeline[0] <= filter_in;
            delay_pipeline[1] <= delay_pipeline[0];
            delay_pipeline[2] <= delay_pipeline[1];
            delay_pipeline[3] <= delay_pipeline[2];
            delay_pipeline[4] <= delay_pipeline[3];
            delay_pipeline[5] <= delay_pipeline[4];
            delay_pipeline[6] <= delay_pipeline[5];
            delay_pipeline[7] <= delay_pipeline[6];
            delay_pipeline[8] <= delay_pipeline[7];
            delay_pipeline[9] <= delay_pipeline[8];
            delay_pipeline[10] <= delay_pipeline[9];
            delay_pipeline[11] <= delay_pipeline[10];
            delay_pipeline[12] <= delay_pipeline[11];
            delay_pipeline[13] <= delay_pipeline[12];
            delay_pipeline[14] <= delay_pipeline[13];
            delay_pipeline[15] <= delay_pipeline[14];
            delay_pipeline[16] <= delay_pipeline[15];
            delay_pipeline[17] <= delay_pipeline[16];
            delay_pipeline[18] <= delay_pipeline[17];
            delay_pipeline[19] <= delay_pipeline[18];
            delay_pipeline[20] <= delay_pipeline[19];
            delay_pipeline[21] <= delay_pipeline[20];
            delay_pipeline[22] <= delay_pipeline[21];
            delay_pipeline[23] <= delay_pipeline[22];
            delay_pipeline[24] <= delay_pipeline[23];
            delay_pipeline[25] <= delay_pipeline[24];
            delay_pipeline[26] <= delay_pipeline[25];
            delay_pipeline[27] <= delay_pipeline[26];
            delay_pipeline[28] <= delay_pipeline[27];
            delay_pipeline[29] <= delay_pipeline[28];
            delay_pipeline[30] <= delay_pipeline[29];
            delay_pipeline[31] <= delay_pipeline[30];
            delay_pipeline[32] <= delay_pipeline[31];
            delay_pipeline[33] <= delay_pipeline[32];
            delay_pipeline[34] <= delay_pipeline[33];
            delay_pipeline[35] <= delay_pipeline[34];
            delay_pipeline[36] <= delay_pipeline[35];
            delay_pipeline[37] <= delay_pipeline[36];
            delay_pipeline[38] <= delay_pipeline[37];
            delay_pipeline[39] <= delay_pipeline[38];
            delay_pipeline[40] <= delay_pipeline[39];
            delay_pipeline[41] <= delay_pipeline[40];
            delay_pipeline[42] <= delay_pipeline[41];
            delay_pipeline[43] <= delay_pipeline[42];
            delay_pipeline[44] <= delay_pipeline[43];
            delay_pipeline[45] <= delay_pipeline[44];
            delay_pipeline[46] <= delay_pipeline[45];
            delay_pipeline[47] <= delay_pipeline[46];
            delay_pipeline[48] <= delay_pipeline[47];
            delay_pipeline[49] <= delay_pipeline[48];
            delay_pipeline[50] <= delay_pipeline[49];
            delay_pipeline[51] <= delay_pipeline[50];
            delay_pipeline[52] <= delay_pipeline[51];
            delay_pipeline[53] <= delay_pipeline[52];
            delay_pipeline[54] <= delay_pipeline[53];
            delay_pipeline[55] <= delay_pipeline[54];
            delay_pipeline[56] <= delay_pipeline[55];
            delay_pipeline[57] <= delay_pipeline[56];
            delay_pipeline[58] <= delay_pipeline[57];
            delay_pipeline[59] <= delay_pipeline[58];
            delay_pipeline[60] <= delay_pipeline[59];
            delay_pipeline[61] <= delay_pipeline[60];
            delay_pipeline[62] <= delay_pipeline[61];
            delay_pipeline[63] <= delay_pipeline[62];
            delay_pipeline[64] <= delay_pipeline[63];
            delay_pipeline[65] <= delay_pipeline[64];
        end
    end

    assign add_signext = delay_pipeline[0];
    assign add_signext_1 = delay_pipeline[65];
    assign tapsum[0] = add_signext + add_signext_1;

    assign add_signext_2 = delay_pipeline[1];
    assign add_signext_3 = delay_pipeline[64];
    assign tapsum[1] = add_signext_2 + add_signext_3;

    assign add_signext_4 = delay_pipeline[2];
    assign add_signext_5 = delay_pipeline[63];
    assign tapsum[2] = add_signext_4 + add_signext_5;

    assign add_signext_6 = delay_pipeline[3];
    assign add_signext_7 = delay_pipeline[62];
    assign tapsum[3] = add_signext_6 + add_signext_7;

    assign add_signext_8 = delay_pipeline[4];
    assign add_signext_9 = delay_pipeline[61];
    assign tapsum[4] = add_signext_8 + add_signext_9;

    assign add_signext_10 = delay_pipeline[5];
    assign add_signext_11 = delay_pipeline[60];
    assign tapsum[5] = add_signext_10 + add_signext_11;

    assign add_signext_12 = delay_pipeline[6];
    assign add_signext_13 = delay_pipeline[59];
    assign tapsum[6] = add_signext_12 + add_signext_13;

    assign add_signext_14 = delay_pipeline[7];
    assign add_signext_15 = delay_pipeline[58];
    assign tapsum[7] = add_signext_14 + add_signext_15;

    assign add_signext_16 = delay_pipeline[8];
    assign add_signext_17 = delay_pipeline[57];
    assign tapsum[8] = add_signext_16 + add_signext_17;

    assign add_signext_18 = delay_pipeline[9];
    assign add_signext_19 = delay_pipeline[56];
    assign tapsum[9] = add_signext_18 + add_signext_19;

    assign add_signext_20 = delay_pipeline[10];
    assign add_signext_21 = delay_pipeline[55];
    assign tapsum[10] = add_signext_20 + add_signext_21;

    assign add_signext_22 = delay_pipeline[11];
    assign add_signext_23 = delay_pipeline[54];
    assign tapsum[11] = add_signext_22 + add_signext_23;

    assign add_signext_24 = delay_pipeline[12];
    assign add_signext_25 = delay_pipeline[53];
    assign tapsum[12] = add_signext_24 + add_signext_25;

    assign add_signext_26 = delay_pipeline[13];
    assign add_signext_27 = delay_pipeline[52];
    assign tapsum[13] = add_signext_26 + add_signext_27;

    assign add_signext_28 = delay_pipeline[14];
    assign add_signext_29 = delay_pipeline[51];
    assign tapsum[14] = add_signext_28 + add_signext_29;

    assign add_signext_30 = delay_pipeline[15];
    assign add_signext_31 = delay_pipeline[50];
    assign tapsum[15] = add_signext_30 + add_signext_31;

    assign add_signext_32 = delay_pipeline[16];
    assign add_signext_33 = delay_pipeline[49];
    assign tapsum[16] = add_signext_32 + add_signext_33;

    assign add_signext_34 = delay_pipeline[17];
    assign add_signext_35 = delay_pipeline[48];
    assign tapsum[17] = add_signext_34 + add_signext_35;

    assign add_signext_36 = delay_pipeline[18];
    assign add_signext_37 = delay_pipeline[47];
    assign tapsum[18] = add_signext_36 + add_signext_37;

    assign add_signext_38 = delay_pipeline[19];
    assign add_signext_39 = delay_pipeline[46];
    assign tapsum[19] = add_signext_38 + add_signext_39;

    assign add_signext_40 = delay_pipeline[20];
    assign add_signext_41 = delay_pipeline[45];
    assign tapsum[20] = add_signext_40 + add_signext_41;

    assign add_signext_42 = delay_pipeline[21];
    assign add_signext_43 = delay_pipeline[44];
    assign tapsum[21] = add_signext_42 + add_signext_43;

    assign add_signext_44 = delay_pipeline[22];
    assign add_signext_45 = delay_pipeline[43];
    assign tapsum[22] = add_signext_44 + add_signext_45;

    assign add_signext_46 = delay_pipeline[23];
    assign add_signext_47 = delay_pipeline[42];
    assign tapsum[23] = add_signext_46 + add_signext_47;

    assign add_signext_48 = delay_pipeline[24];
    assign add_signext_49 = delay_pipeline[41];
    assign tapsum[24] = add_signext_48 + add_signext_49;

    assign add_signext_50 = delay_pipeline[25];
    assign add_signext_51 = delay_pipeline[40];
    assign tapsum[25] = add_signext_50 + add_signext_51;

    assign add_signext_52 = delay_pipeline[26];
    assign add_signext_53 = delay_pipeline[39];
    assign tapsum[26] = add_signext_52 + add_signext_53;

    assign add_signext_54 = delay_pipeline[27];
    assign add_signext_55 = delay_pipeline[38];
    assign tapsum[27] = add_signext_54 + add_signext_55;

    assign add_signext_56 = delay_pipeline[28];
    assign add_signext_57 = delay_pipeline[37];
    assign tapsum[28] = add_signext_56 + add_signext_57;

    assign add_signext_58 = delay_pipeline[29];
    assign add_signext_59 = delay_pipeline[36];
    assign tapsum[29] = add_signext_58 + add_signext_59;

    assign add_signext_60 = delay_pipeline[30];
    assign add_signext_61 = delay_pipeline[35];
    assign tapsum[30] = add_signext_60 + add_signext_61;

    assign add_signext_62 = delay_pipeline[31];
    assign add_signext_63 = delay_pipeline[34];
    assign tapsum[31] = add_signext_62 + add_signext_63;

    assign add_signext_64 = delay_pipeline[32];
    assign add_signext_65 = delay_pipeline[33];
    assign tapsum[32] = add_signext_64 + add_signext_65;


	 localparam[1:0] INIT          = 2'd0,
					     MAC           = 2'd1,
					     OUTPUT_PHASE  = 2'd2;

	 reg[1:0] state_reg, state_nxt;
    reg signed [38:0] product_nxt;
	 reg signed [44:0] product_cast_nxt;
    reg signed [44:0] acc_reg , acc_nxt;
    reg  [6:0] counter_reg, counter_nxt;
    reg signed [20:0] output_typeconvert_reg, output_typeconvert_nxt;

	 always @(posedge clk or posedge reset) begin
			 if(reset) begin
				  state_reg <= INIT;
				  acc_reg <= 0;
				  counter_reg <= 0;
				  output_typeconvert_reg <= 0;
			 end
			 else begin
				  state_reg <= state_nxt;
				  acc_reg <= acc_nxt;
				  counter_reg <= counter_nxt;
				  output_typeconvert_reg <= output_typeconvert_nxt;
			 end
		end

		// FSM next-state and output logic
		always @(*) begin
			 state_nxt = state_reg;
			 acc_nxt = acc_reg;
			 counter_nxt = counter_reg;  // Initialize next state counter to current state
			 output_typeconvert_nxt = output_typeconvert_reg;
			 case(state_reg)
				  INIT: begin
						acc_nxt = 0;
						state_nxt = MAC;
						counter_nxt = 7'b0000_001;  // Increment counter immediately in INIT
				  end

				  MAC: begin
						counter_nxt = counter_reg + 7'b0000_001;

						if (counter_reg == 7'd33) begin
							 state_nxt = OUTPUT_PHASE;
						end

						product_nxt = coeffs[counter_reg - 1] * tapsum[counter_reg - 1];
						product_cast_nxt = $signed({{6{product_nxt[38]}}, product_nxt});
						acc_nxt = acc_reg + product_cast_nxt;
				  end

				  OUTPUT_PHASE: begin
						if (counter_reg == 7'd127) begin
							 counter_nxt = 7'd0;
							 state_nxt = INIT;
							 output_typeconvert_nxt = $signed({{5{delay_pipeline[32][15]}}, delay_pipeline[32]});

						end
						else if (counter_reg > 7'd63) begin
							 output_typeconvert_nxt = (acc_reg[40:0] + {acc_reg[20], {19{~acc_reg[20]}}}) >>> 20;

							 counter_nxt = counter_reg + 7'b0000_001;
						end
						else begin
							 counter_nxt = counter_reg + 7'b0000_001;
						end
				  end

				  default: state_nxt = INIT;
			 endcase
		end

    assign filter_out = output_typeconvert_reg;
    assign ce_out = phase_1;

endmodule
