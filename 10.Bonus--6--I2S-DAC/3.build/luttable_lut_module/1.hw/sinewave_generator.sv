
module sinewave_generator #(
    parameter DATA_WIDTH  = 16,
              LUT_DEPTH   = 8,
              PHASE_WIDTH = 64
) (
    input  logic                          clk,
    input  logic                          arst,
    input  logic                          sample_clk_ce,
    input  logic signed [PHASE_WIDTH-1:0] phase_increment,
    output logic [DATA_WIDTH -1:0] sinewave,
    output logic [DATA_WIDTH -1:0] cosinewave
);

  logic [PHASE_WIDTH-1:0] phase_accumulator;

  sinewave_table #(
    .DATA_WIDTH(DATA_WIDTH),
    .LUT_DEPTH(LUT_DEPTH)
  ) sinewave_inst (
    .address(phase_accumulator[PHASE_WIDTH-1:PHASE_WIDTH-LUT_DEPTH]),
    .value(sinewave)
  );

  sinewave_table #(
    .DATA_WIDTH(DATA_WIDTH),
    .LUT_DEPTH(LUT_DEPTH)
  ) cosinewave_inst (
    .address((phase_accumulator[PHASE_WIDTH-1:PHASE_WIDTH-LUT_DEPTH] + (1<<(LUT_DEPTH-2))) % (1<<LUT_DEPTH)),
    .value(cosinewave)
  );

  always @(posedge clk or posedge arst) begin
    if (arst == 1'b1)
      phase_accumulator <= '0;
    else if (sample_clk_ce == 1'b1)
      phase_accumulator <= PHASE_WIDTH'(phase_accumulator + phase_increment);
  end

  //=============================//
  //       For sim only          //
  //=============================//
  //`ifdef SIMULATION
  initial begin
    $dumpfile("sinewave_waves.vcd");
    $dumpvars(0, sinewave_generator);
  end
  //`endif


endmodule
