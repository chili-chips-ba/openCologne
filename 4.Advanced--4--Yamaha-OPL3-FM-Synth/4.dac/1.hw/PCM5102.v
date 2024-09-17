module PCM5102 (
    clk,
    arst,
    left,
    right,
    din,
    bck,
    lrck
);
  input clk;  // sysclk 100MHz
  input arst;
  input [15:0] left, right;  // left and right 16bit samples Uint16
  output reg din;  // pin on pcm5102 data
  output reg bck;  // pin on pcm5102 bit clock
  output reg lrck;  // pin on pcm5102 l/r clock can be used outside of this module to create new samples

  parameter DAC_CLK_DIV_BITS = 2;    // 1 = ca 384Khz, 2 = 192Khz, 3 = 96Khz, 4 = 48Khz 

  reg [DAC_CLK_DIV_BITS:0] i2s_clk;  // 2 Bit Counter 48MHz -> 6,0 MHz bck = ca 187,5 Khz SampleRate 4% tolerance ok by datasheet
  always @(posedge clk or posedge arst) begin
    if(arst == 1'b1) begin
      i2s_clk <= '0;
    end else begin
      i2s_clk  <= i2s_clk + 1;
    end
  end

  reg [15:0] l2c;
  reg [15:0] r2c;

  reg [ 5:0] i2sword;  // 6 bit = 16 steps for left + right

  always @(negedge i2sword[5] or posedge arst) begin
    if(arst == 1'b1) begin
       l2c <= '0;
       r2c <= '0;
    end else begin
       l2c     <= left;
       r2c     <= right;
    end
  end

  always @(negedge i2s_clk[DAC_CLK_DIV_BITS] or posedge arst) begin
    if(arst == 1'b1) begin
      i2sword <= '0;
      din     <= '0;
      bck     <= '0;
      lrck    <= '0;
    end else begin
      lrck    <= i2sword[5];
      din     <= lrck ? r2c[16-i2sword[4:1]] : l2c[16-i2sword[4:1]];  // blit data bits
      bck     <= i2sword[0];
      i2sword <= i2sword + 1;
    end
  end
endmodule
