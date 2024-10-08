// combines resistor DAC and PWM
// upper bits using DAC, lower bit using PWM

module dacpwm #(
  parameter PCM_BITS = 12,                  // input: how many bits PCM (including sign bit)
  parameter DAC_BITS = 4                    // output: how many bits DAC output, unsigned
) (
  input                         clk,        // required to run PWM
  input signed [PCM_BITS-1:0]   pcm,        // 12-bit signed PCM input
  output       [DAC_BITS-1:0]   dac         // 4-bit unsigned DAC output
);
    parameter PWM_BITS = PCM_BITS-DAC_BITS; // how many bits for PWM that increases DAC resolution

    // generate 2 DAC output optional values: PCM+0 and PCM+1
    reg [DAC_BITS-1:0] dac0, dac1;
    reg [PWM_BITS-1:0] pcm_low;
    always @(posedge clk) begin
      dac0    <= { ~pcm[PCM_BITS-1], pcm[PCM_BITS-2:PCM_BITS-DAC_BITS]};
      dac1    <= { ~pcm[PCM_BITS-1], pcm[PCM_BITS-2:PCM_BITS-DAC_BITS]} + 1;
      pcm_low <=    pcm[PWM_BITS-1:0];
    end

    // constantly running PWM counter
    reg [PWM_BITS-1:0] pwm_counter;
    always @(posedge clk) begin
      pwm_counter <= pwm_counter + 1'b1; // constantly running
    end

    // the comparator
    // using PWM to switch between dac0 and dac1
    reg [DAC_BITS-1:0] dac_output;
    always @(posedge clk)begin
      dac_output <= pwm_counter >= pcm_low ? dac0 : dac1;
    end

    assign dac = dac_output;
endmodule
