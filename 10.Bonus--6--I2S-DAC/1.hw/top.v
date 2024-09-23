module top #(
  parameter DAC_WIDTH   = 16,
  parameter PHASE_WIDTH = 64,
  parameter LUT_DEPTH   = 8
)(
    input  wire       clk,   // 10 MHz input clock
    input  wire       arst_n,
    input  wire       uart_rx_serial,
    output wire [7:0] led,
    output wire       lrck,  // Left-right clock
    output wire       din,   // Data input to DAC
    output wire       bck    // Bit clock for DAC
);

  // NCO configuration (adjustable phase increment)
  //localparam PHASE_INCREMENT = 64'd196765270119568550; // Pre-calculated value for NCO

  reg  [PHASE_WIDTH-1:0] phase_increment;
  // Outputs from NCO for left and right channels
  wire [DAC_WIDTH-1:0]   left_out;
  wire [DAC_WIDTH-1:0]   right_out;

  // Clock strobe signal used by the sinewave generator, generated from an external clock divider
  wire                   clk_strobe;
  wire                   arst;
  assign                 arst = !arst_n;
  // ------------- UART Signals --------------- //
  wire                   uart_rx_data_valid;
  wire         [7:0]     uart_rx_byte;

  //Note: This is GM PLL Block
  //===========================//
  //            PLL            //
  //===========================//
  wire clk270, clk180, clk90, clk0, usr_ref_out;
  wire usr_pll_lock_stdy, usr_pll_lock;

  CC_PLL #(
    .REF_CLK("10.0"),    // reference input in MHz
    .OUT_CLK("48.0"),    // pll output frequency in MHz
    .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
    .LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
    .CI_FILTER_CONST(2), // optional CI filter constant
    .CP_FILTER_CONST(4)  // optional CP filter constant
  ) pll_inst (
    .CLK_REF(clk), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
    .USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy), .USR_PLL_LOCKED(usr_pll_lock),
    .CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(clk0), .CLK_REF_OUT(usr_ref_out)
   );

  //===========================//
  //           NCO             //
  //===========================//
  sinewave_generator #(
      .DATA_WIDTH (DAC_WIDTH),
      .LUT_DEPTH  (LUT_DEPTH),
      .PHASE_WIDTH(PHASE_WIDTH)
  ) sine_gen_inst (
      .clk            (clk_strobe),
      .arst           (arst),
      .sample_clk_ce  (1'b1),
      .phase_increment(phase_increment),
      .sinewave       (left_out)
  );

  //===========================//
  //         PCM5102 DAC       //
  //===========================//
  PCM5102 #(
    .DAC_WIDTH(DAC_WIDTH)
  ) dac (
      .clk  (clk0),
      .arst (arst),
      .left (left_out),
      .right(right_out),
      .din  (din),
      .bck  (bck),
      .lrck (lrck),
      .clk_strobe(clk_strobe)
  );

  // The right channel mirrors the left channel (stereo, same output)
  assign right_out = left_out;
  assign led[7:0]  = ~uart_rx_byte[7:0];

  //===========================//
  //          UART RX          //
  //===========================//
  uart_rx #(
      .CLKS_PER_BIT(417) // 48MHz/115200 --> ~417
  ) uart_rx_inst (
      .osc_clk  (clk0),
      .rx_serial(uart_rx_serial),
      .rx_dv    (uart_rx_data_valid),
      .rx_byte  (uart_rx_byte)
  );

  always @(posedge clk0) begin
    if (uart_rx_data_valid == 1'b1) begin
      case (uart_rx_byte)
        97:      phase_increment <= 64'd196765270119568550;                    // a 1  kHz
        98:      phase_increment <= 64'd983826350597842752;                    // b 5  kHz
        102:     phase_increment <= 64'd1967652701195685505;                   // f 10 kHz
        103:     phase_increment <= 64'd2951479051793528258;                   // g 15 kHz
        110:     phase_increment <= phase_increment - 64'd196765270119568550;  // n - 1kHz
        109:     phase_increment <= phase_increment + 64'd196765270119568550;  // m + 1KHz
        111:     phase_increment <= phase_increment - 64'd19676527011956855;   // o - 100 Hz
        112:     phase_increment <= phase_increment + 64'd19676527011956855;   // p + 100 Hz
        default: phase_increment <= 64'd0;
      endcase
    end
  end

  //============================//
  //    For simulation only     //
  //============================//
  `ifdef SIMULATION
  initial begin
    $dumpfile("dac_waves.vcd");
    $dumpvars(0, top);
  end
  `endif

endmodule
