module sd_dac_top(
    input clk,         //10Mhz
    input reset,           // Reset signal
    output output_pdm_p,
    output output_pdm_n
    //output output_pdm_p_1st,
    //output output_pdm_n_1st
);

    wire ce_out;
    //wire ce_out1;
    wire clk_enable = 1'b1;
    localparam PHASE_WIDTH=32;
  // ------------- NCO Signals ---------------- //
  wire signed  [   PHASE_WIDTH-1:0] phase_increment;
  wire signed [15:0]               lo_cosinewave;
  wire signed [15:0]               lo_sinewave, lo_sinewave_int, output_data_opt;
  // NOTE: sinewave_generator that uses quarter of LUT Table
  //===========================//
  //          NCO              //
  //===========================//
    //assign phase_increment = 32'd429497;
      //assign phase_increment = 32'd87652394; //1 kHz
    //assign phase_increment = 32'd175304787; //2kHz
    assign phase_increment = 32'd38469662; // 441Hz
    //assign phase_increment = 32'd262957181; // 3kHz

    //assign phase_increment = 32'd80530637; //3 at 48 kHz
    quarterwave_generator #(
      .DATA_WIDTH (16),
      .QLUT_DEPTH (8),
      .PHASE_WIDTH(PHASE_WIDTH)
  ) nco_inst (
      .clk            (clk44),
      .arst           (reset),
      .sample_clk_ce  (1'b1),
      .phase_increment(phase_increment),
      .sinewave         (lo_sinewave),
      .cosinewave     (lo_cosinewave)
  );

        // Interpolating filter instance
    interpolatingFilter u_interpolatingFilter (
        .clk(clk0),          // Use the global clock (128x44.1 kHz)
        .clk_enable(clk_enable),
        .reset(!reset),
        .input_data(lo_sinewave), // Connect sine wave to filter input
        .output_data(lo_sinewave_int),
        .ce_out(ce_out)
    );

    //interpolatingFilterOrg uut_opt (
        //.clk(clk0),
        //.clk_enable(clk_enable),
        //.reset(!reset),
        //.input_data(lo_sinewave),
        //.output_data(output_data_opt),
        //.ce_out(ce_out1)
    //);

    // Sigma-delta modulator instance
     sigma_delta_modulator u_sigma_delta_modulator(
        .clk(clk0),
        .rst_n(reset),
        .in(lo_sinewave_int),
        .out(output_pdm_p)
    );

     //sigma_delta_modulator_1st u_sigma_delta_modulator_1st(
        //.clk(clk0),
        //.rst_n(reset),
        //.in(lo_sinewave_int),
        //.out(output_pdm_p_1st)
    //);

	wire clk270, clk180, clk90, clk0, usr_ref_out;
	wire usr_pll_lock_stdy, usr_pll_lock;

	CC_PLL #(
		.REF_CLK(10.0),      // reference input in MHz
		.OUT_CLK(5.6448),     // pll output frequency in MHz .OUT_CLK(5.6448)6.144,
		.PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
		.LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
		.CI_FILTER_CONST(2), // optional CI filter constant
		.CP_FILTER_CONST(4)  // optional CP filter constant
	) pll_inst (
		.CLK_REF(clk), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
		.USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy), .USR_PLL_LOCKED(usr_pll_lock),
		.CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(clk0), .CLK_REF_OUT(usr_ref_out)
	);

	reg [6:0] counter44;
    reg clk44;

    always @(posedge clk0 or negedge reset) begin
        if (!reset) begin
            counter44 <= 7'd0;
            clk44 <= 1'b0;

        end else begin
            // 44.1 kHz output
            if (counter44 == 7'd63) begin
                counter44 <= 7'd0;
                clk44 <= ~clk44;
            end else begin
                counter44 <= counter44 + 7'd1;
            end

        end
    end

    assign output_pdm_n = ~ output_pdm_p;
    //assign output_pdm_n_1st = ~output_pdm_p_1st;

endmodule
