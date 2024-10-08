// generates triangle wave

module squarewave #(
  parameter DELAY    = 10,              // bits for delay part of the counter
  parameter PCM_BITS = 12               // how many bits for PCM output
) (
  input                        clk,     // required to run PWM
  output signed [PCM_BITS-1:0] pcm      // 12-bit unsigned PCM output
);

    reg [DELAY+PCM_BITS-1:0]   counter; // PWM counter register
    reg                        direction;

    always @(posedge clk) begin
      if(direction == 1'b1)
        counter <= counter + 1;
      else
        counter <= counter - 1;
    end

    always @(posedge clk) begin
      if(counter[DELAY+PCM_BITS-1:DELAY] == ~{12'd1770} && direction == 1'b0)
        direction <= 1'b1; // from now on, count forwards
      if(counter[DELAY+PCM_BITS-1:DELAY] ==   12'd1770 &&  direction == 1'b1)
        direction <= 1'b0; // from now on, count backwards
    end

  assign pcm = {direction, 11'b000_0000_0000};
endmodule
