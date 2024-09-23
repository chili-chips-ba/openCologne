module PCM5102 #(
  parameter DAC_WIDTH        = 16,
  parameter DAC_CLK_DIV_BITS = 2 // 1 = ca 384Khz, 2 = 192Khz, 3 = 96Khz, 4 = 48Khz
)(
    input  wire                 clk,
    input  wire                 arst,
    input  wire [DAC_WIDTH-1:0] left,  // left  16bit samples Uint16
    input  wire [DAC_WIDTH-1:0] right, // right 16bit samples Uint16
    output reg                  din,   // pin on pcm5102 data
    output reg                  bck,   // pin on pcm5102 bit clock
    output reg                  lrck,  // pin on pcm5102 l/r clock can be used outside of this module to create new samples
    output wire                 clk_strobe
);

  reg [DAC_CLK_DIV_BITS:0] i2s_clk;  // 2 Bit Counter 48MHz -> 6,0 MHz bck = ca 187,5 Khz SampleRate 4% tolerance ok by datasheet
  always @(posedge clk or posedge arst) begin
    if(arst == 1'b1) begin
      i2s_clk  <= {DAC_CLK_DIV_BITS+1{1'b0}};
    end else begin
      i2s_clk  <= i2s_clk + 1;
    end
  end

  reg  [DAC_WIDTH-1:0] l2c;
  reg  [DAC_WIDTH-1:0] r2c;
  wire [ 4:0]          index;
  reg  [ 5:0]          i2sword;  // 6 bit = 16 steps for left + right

  always @(negedge i2sword[5] or posedge arst) begin
    if(arst == 1'b1) begin
       l2c <= {DAC_WIDTH{1'b0}};
       r2c <= {DAC_WIDTH{1'b0}};
    end else begin
       l2c <= left;
       r2c <= right;
    end
  end

  always @(negedge i2s_clk[DAC_CLK_DIV_BITS] or posedge arst) begin
    if(arst == 1'b1) begin
      i2sword <= 6'd0;
      din     <= 1'b0;
      bck     <= 1'b0;
      lrck    <= 1'b0;
    end else begin
      lrck    <= i2sword[5];
      din     <= lrck ? r2c[index] : l2c[index];  // blit data bits
      bck     <= i2sword[0];
      i2sword <= i2sword + 1;
    end
  end

  assign index      = (DAC_WIDTH-1) - i2sword[4:1];
  assign clk_strobe =  i2sword[5];

endmodule
