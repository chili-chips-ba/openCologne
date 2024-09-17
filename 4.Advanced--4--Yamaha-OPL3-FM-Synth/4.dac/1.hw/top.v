module top (
    input wire  clk, // 48 MHz
    output      LRCK,
    output      DIN,
    output      BCK
);

  wire [15:0] left_out;
  wire [15:0] right_out;

  //----- NCO Signals ------ //
  wire [15:0] nco_sinewave;
  reg  [63:0] nco_phase_increment;
  assign      nco_phase_increment = 64'd384307168202282; // 1kHz for 48Mhz input
/*
  sinewave_generator #(
      .DATA_WIDTH (16),
      .LUT_DEPTH  (8),
      .PHASE_WIDTH(64)
  ) sine_gen_inst (
      .clk            (clk),
      .arst           (1'b0),
      .sample_clk_ce  (1'b1),
      .phase_increment(nco_phase_increment),
      .sinewave       (nco_sinewave)
  );
*/
  assign left_out            = nco_sinewave;
  assign right_out           = nco_sinewave;

/*
  // PCM5102 DAC instance
  PCM5102 dac (
      .clk  (clk),
      .left (left_out),
      .right(right_out),
      .din  (DIN),
      .bck  (BCK),
      .lrck (LRCK)
  );
*/
endmodule
