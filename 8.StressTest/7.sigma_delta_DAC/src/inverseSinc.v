module inverseSinc (
    input wire clk,
    input wire clk_enable,
    input wire reset,
    input wire signed [19:0] filter_in,
    output signed [17:0] filter_out,
    output ce_out
);

	reg signed [15:0] coeffs [0:5]; // Register array for coefficients

	initial begin
		 coeffs[0]  = 16'b0000000100011001; // coeffphase1_1
		 coeffs[1]  = 16'b1111100000000111; // coeffphase1_2
		 coeffs[2]  = 16'b0010001001000000; // coeffphase1_3
		 coeffs[3]  = 16'b0111000011011011; // coeffphase1_4
		 coeffs[4]  = 16'b1111000111101101; // coeffphase1_5
		 coeffs[5]  = 16'b0000000111011001; // coeffphase1_6
	end



    // Delay line for input samples and coeff sharing
    reg signed [19:0] delay_pipeline [0:5]; // sfix16_En15

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


    always @( posedge clk or posedge reset)
    begin: Delay_Pipeline_process
      if (reset == 1'b1) begin
        delay_pipeline[0] <= 0;
        delay_pipeline[1] <= 0;
        delay_pipeline[2] <= 0;
        delay_pipeline[3] <= 0;
        delay_pipeline[4] <= 0;
        delay_pipeline[5] <= 0;
      end
      else begin
        if (phase_1 == 1'b1) begin
          delay_pipeline[0] <= filter_in;
          delay_pipeline[1] <= delay_pipeline[0];
          delay_pipeline[2] <= delay_pipeline[1];
          delay_pipeline[3] <= delay_pipeline[2];
          delay_pipeline[4] <= delay_pipeline[3];
          delay_pipeline[5] <= delay_pipeline[4];
        end
      end
    end // Delay_Pipeline_process

	 localparam [1:0] INIT          = 2'd0,
					      MAC   = 2'd1,
					      OUTPUT_PHASE  = 2'd2;

    reg[1:0] state_reg, state_nxt;
    reg signed [35:0] product_nxt ;
	 reg signed [38:0] product_cast_nxt;
    reg signed [38:0] acc_reg1 , acc_nxt1, acc_reg2 , acc_nxt2;
    reg  [5:0] counter_reg, counter_nxt;
    reg signed [19:0] output_typeconvert_reg, output_typeconvert_nxt;

	 always @(posedge clk or posedge reset) begin
			 if(reset) begin
				  state_reg <= INIT;
				  acc_reg1 <= 0;
				  acc_reg2 <= 0;
				  counter_reg <= 0;
				  output_typeconvert_reg <= 0;
   		 end
			 else begin
				  state_reg <= state_nxt;
				  acc_reg1 <= acc_nxt1;
				  acc_reg2 <= acc_nxt2;
				  counter_reg <= counter_nxt;
				  output_typeconvert_reg <= output_typeconvert_nxt;
			 end
		end

		always @(*) begin
			 state_nxt = state_reg;
			 acc_nxt1 = acc_reg1;
			 acc_nxt2 = acc_reg2;
			 counter_nxt = counter_reg;  // Initialize next state counter to current state
			 output_typeconvert_nxt = output_typeconvert_reg;

			 case(state_reg)
				  INIT: begin
						acc_nxt1 = 39'd0;
						acc_nxt2 = 39'd0;
						state_nxt = MAC;
						counter_nxt = 6'b000_001;
				  end

				  MAC: begin
						counter_nxt = counter_reg + 6'b000_001;

						if (counter_reg > 0 && counter_reg < 6'd7) begin
							 product_nxt = coeffs[counter_reg - 1] * delay_pipeline[counter_reg - 1];
							 product_cast_nxt = $signed({{3{product_nxt[35]}}, product_nxt});
							 acc_nxt1 = acc_reg1 + product_cast_nxt;
						end
						else if (counter_reg == 6'd16) begin
							 output_typeconvert_nxt = (acc_reg1[32:0] + {acc_reg1[15], {14{~acc_reg1[15]}}}) >>> 15;
						end
						else if (counter_reg > 6'd16 && counter_reg < 6'd23) begin
							 product_nxt = coeffs[22 - counter_reg] * delay_pipeline[counter_reg - 17];
							 product_cast_nxt = $signed({{3{product_nxt[35]}}, product_nxt});
							 acc_nxt2 = acc_reg2 + product_cast_nxt;
						end
						else if (counter_reg > 6'd23) begin
							 state_nxt = OUTPUT_PHASE;
						end
				  end

				  OUTPUT_PHASE: begin
						if (counter_reg == 6'd31) begin
							 state_nxt = INIT;
							 output_typeconvert_nxt = (acc_reg2[32:0] + {acc_reg2[15], {14{~acc_reg2[15]}}}) >>> 15;
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
