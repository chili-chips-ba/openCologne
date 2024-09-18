module top #(
  parameter DAC_WIDTH   = 16, // Bit-width of DAC
  parameter PHASE_WIDTH = 64, // NCO phase accumulator width
  parameter LUT_DEPTH   = 8   // Lookup table depth for sinewave generator
)(
    input wire  clk,   // 48 MHz input clock
    input wire  arst,  // Asynchronous reset
    output      lrck,  // Left-right clock
    output      din,   // Data input to DAC
    output      bck    // Bit clock for DAC
);

  // NCO configuration (adjustable phase increment)
  localparam PHASE_INCREMENT = 64'd196765270119568550; // Pre-calculated value for NCO

  // Outputs from NCO for left and right channels
  wire [DAC_WIDTH-1:0] left_out;
  wire [DAC_WIDTH-1:0] right_out;

  // Clock strobe signal used by the sinewave generator, generated from an external clock divider
  wire clk_strobe;

  // Sinewave generator with divided clock
  sinewave_generator #(
      .DATA_WIDTH (DAC_WIDTH),      // DAC bit width
      .LUT_DEPTH  (LUT_DEPTH),      // Lookup table depth
      .PHASE_WIDTH(PHASE_WIDTH)     // Phase accumulator width
  ) sine_gen_inst (
      .clk            (clk_strobe),              // Divided clock goes here
      .arst           (arst),                    // Asynchronous reset
      .sample_clk_ce  (1'b1),                    // Clock enable
      .phase_increment(PHASE_INCREMENT),         // NCO phase increment for 1kHz
      .sinewave       (left_out)                 // Sinewave output
  );

  // PCM5102 DAC instance
  PCM5102 #(
    .DAC_WIDTH(DAC_WIDTH)
  ) dac (
      .clk  (clk),                   // Master clock
      .arst (arst),                  // Reset
      .left (left_out),              // Left channel input
      .right(right_out),             // Right channel input
      .din  (din),                   // DAC data input
      .bck  (bck),                   // DAC bit clock
      .lrck (lrck),                   // DAC left-right clock
      .clk_strobe(clk_strobe)
  );

  // The right channel mirrors the left channel (stereo, same output)
  assign right_out = left_out;

  //============================//
  //    For simulation only     //
  //============================//
  //`ifdef SIMULATION
  initial begin
    $dumpfile("dac_waves.vcd");
    $dumpvars(0, top);
  end
  //`endif

endmodule
