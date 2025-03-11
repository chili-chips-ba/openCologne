module halfBandSecond (
    input wire clk,
    input wire clk_enable,
    input wire reset,
    input wire signed [20:0] filter_in,
    output signed [19:0] filter_out,
    output ce_out
)  /* synthesis syn_dspstyle = "logic" */;

	reg signed [19:0] coeffs [0:5]; // Register array for coefficients

	initial begin
		 coeffs[0]  = 20'b11111111111101001001; // coeffphase1_12
		 coeffs[1]  = 20'b00000000010100101001; // coeffphase1_11
		 coeffs[2]  = 20'b11111110101100101010; // coeffphase1_10
		 coeffs[3]  = 20'b00000011111010011110; // coeffphase1_9
		 coeffs[4]  = 20'b11110101100000001111; // coeffphase1_8
		 coeffs[5]  = 20'b00100111100110110101; // coeffphase1_7
	end

    // Delay line for input samples and coeff sharing
    reg signed  [20:0] delay_pipeline [0:11]; // sfix16_En15
    wire signed [21:0] tapsum [0:5];

    wire signed [20:0] add_signext; // sfix16_En15
    wire signed [20:0] add_signext_1; // sfix16_En15

    wire signed [20:0] add_signext_2; // sfix16_En15
    wire signed [20:0] add_signext_3; // sfix16_En15

    wire signed [20:0] add_signext_4; // sfix16_En15
    wire signed [20:0] add_signext_5; // sfix16_En15

    wire signed [20:0] add_signext_6; // sfix16_En15
    wire signed [20:0] add_signext_7; // sfix16_En15

    wire signed [20:0] add_signext_8; // sfix16_En15
    wire signed [20:0] add_signext_9; // sfix16_En15

    wire signed [20:0] add_signext_10; // sfix16_En15
    wire signed [20:0] add_signext_11; // sfix16_En15


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
        end
    end

    assign add_signext = delay_pipeline[0];
    assign add_signext_1 = delay_pipeline[11];
    assign tapsum[0] = add_signext + add_signext_1;

    assign add_signext_2 = delay_pipeline[1];
    assign add_signext_3 = delay_pipeline[10];
    assign tapsum[1] = add_signext_2 + add_signext_3;

    assign add_signext_4 = delay_pipeline[2];
    assign add_signext_5 = delay_pipeline[9];
    assign tapsum[2] = add_signext_4 + add_signext_5;

    assign add_signext_6 = delay_pipeline[3];
    assign add_signext_7 = delay_pipeline[8];
    assign tapsum[3] = add_signext_6 + add_signext_7;

    assign add_signext_8 = delay_pipeline[4];
    assign add_signext_9 = delay_pipeline[7];
    assign tapsum[4] = add_signext_8 + add_signext_9;

    assign add_signext_10 = delay_pipeline[5];
    assign add_signext_11 = delay_pipeline[6];
    assign tapsum[5] = add_signext_10 + add_signext_11;



	 localparam [1:0] INIT          = 2'd0,
					      MAC           = 2'd1,
					      OUTPUT_PHASE  = 2'd2;

	 reg[1:0] state_reg, state_nxt;
    reg signed [41:0] product_nxt ;
	 reg signed [44:0] product_cast_nxt;
    reg signed [44:0] acc_reg , acc_nxt;         // Accumulated MAC result
    reg  [5:0] counter_reg, counter_nxt;
    reg signed [19:0] output_typeconvert_reg, output_typeconvert_nxt;

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
						counter_nxt = 6'b000_001;  // Increment counter immediately in INIT
				  end

				  MAC: begin
						counter_nxt = counter_reg + 6'b000_001;

						if (counter_reg == 6'd6) begin
							 state_nxt = OUTPUT_PHASE;
						end

						product_nxt = coeffs[counter_reg - 1] * tapsum[counter_reg - 1];
						product_cast_nxt = $signed({{3{product_nxt[41]}}, product_nxt});
						acc_nxt = acc_reg + product_cast_nxt;
				  end

				  OUTPUT_PHASE: begin
						if (counter_reg == 6'd63) begin
							 counter_nxt = 6'd0;
							 state_nxt = INIT;
							 output_typeconvert_nxt = delay_pipeline[5];
						end
						else if (counter_reg > 6'd31) begin
							 output_typeconvert_nxt = (acc_reg[37:0] + {acc_reg[18], {17{~acc_reg[18]}}}) >>> 18;
							 counter_nxt = counter_reg + 6'b000_001;
						end
						else begin
							 counter_nxt = counter_reg + 6'b000_001;
						end
				  end

				  default: state_nxt = INIT;
			 endcase
		end

    assign filter_out = output_typeconvert_reg;
    assign ce_out = phase_1;

endmodule
