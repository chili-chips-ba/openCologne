/*
 generates sine wave
 using discrete-time evaluation of the
 physical model of a sprung mass lossless mechanical oscillator
*/
module sinewave #(
  parameter DELAY            = 8,  // sample rate = 2^-n
  parameter PCM_BITS         = 12, // output PCM bits
  parameter SPD_BITS         = 10,
  parameter POS_TO_SPD_SHIFT = 8,  // mechanical "spring" stiffness = 2^-n
  parameter SPD_TO_POS_SHIFT = 3,  // mechanical "mass" = 2^-n
  parameter POS_INIT         = 0,  // initial position = 0
  parameter SPD_INIT         = 277 // initial speed 340 sets max amplitude that fits into 12-bit
) (
  input                        clk,
  output signed [PCM_BITS-1:0] pcm // 12-bit signed PCM output
);
    reg  signed [SPD_BITS-1:0] spd = SPD_INIT;
    reg  signed [PCM_BITS-1:0] pos = POS_INIT;
    wire signed [SPD_BITS-1:0] pos_shift;
    wire signed [PCM_BITS-1:0] pos_next;
    wire signed [PCM_BITS-1:0] spd_shift;
    reg         [PCM_BITS-1:0] pcm_reg;
    reg         [DELAY-1:0]    delay_reg; // counter to slow down
    assign spd_shift =
    {
      {(PCM_BITS-(SPD_BITS-SPD_TO_POS_SHIFT)){spd[SPD_BITS-1]}}, // 5 bit sign expansion, 5+7 = 12 bit
      spd[SPD_BITS-1:SPD_TO_POS_SHIFT]                           // 10->7 bit
    };
    assign pos_shift =
    {
      {(SPD_BITS-(PCM_BITS-POS_TO_SPD_SHIFT)){pos[PCM_BITS-1]}}, // 6 bit sign expansion, 6+4 = 10 bit 
      pos[PCM_BITS-1:POS_TO_SPD_SHIFT]                           // 12->4 bit
    };
    assign pos_next = pos + spd_shift;

    always @(posedge clk) begin
      if( (|(delay_reg[DELAY-1:1])) == 1'b0 ) begin
        // every 2nd clock calculates next value of the sine wave
        if( delay_reg[0] == 1'b0) // alternate
          pos <= pos_next;        // apply speed to position
        else
          spd <= spd - pos_shift; // apply acceleration to speed
      end
      delay_reg <= delay_reg + 1;
    end

    assign pcm = pos;
endmodule
