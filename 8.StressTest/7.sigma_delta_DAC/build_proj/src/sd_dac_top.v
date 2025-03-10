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

    rPLL #(
        //.DEVICE           ("GW1NR-9C"),
        //.DEVICE           ("GW2AR-18C"),
        .DEVICE           ("GW2AR-18C"),
        .FCLKIN           ("27"), 
        .DYN_IDIV_SEL     ("false"),
        .IDIV_SEL         (4),
        .DYN_FBDIV_SEL    ("false"),
        .FBDIV_SEL        (2),
        .DYN_ODIV_SEL     ("false"),
        .ODIV_SEL         (32),
        .PSDA_SEL         ("0000"),
        .DYN_DA_EN        ("true"),
        .DUTYDA_SEL       ("1000"),
        .CLKOUT_FT_DIR    (1'b1),
        .CLKOUTP_FT_DIR   (1'b1),
        .CLKOUT_DLY_STEP  (0),
        .CLKOUTP_DLY_STEP (0),
        .CLKFB_SEL        ("internal"),
        .CLKOUT_BYPASS    ("false"),
        .CLKOUTP_BYPASS   ("false"),
        .CLKOUTD_BYPASS   ("false"),
        .DYN_SDIV_SEL     (2),
        .CLKOUTD_SRC      ("CLKOUT"),
        .CLKOUTD3_SRC     ("CLKOUT")
     )
     u_pll (
        .CLKOUT   (clk0),
        .LOCK     (usr_pll_lock),
        .CLKOUTP  (),
        .CLKOUTD  (),
        .CLKOUTD3 (),
         
        .RESET    (1'b0),
        .RESET_P  (1'b0),
        .CLKIN    (clk),
        .CLKFB    (1'b0),
        .FBDSEL   ('0),
        .IDSEL    ('0),
        .ODSEL    ('0),
        .PSDA     ('0),
        .DUTYDA   ('0),
        .FDLY     ('0)
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
