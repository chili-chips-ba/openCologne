`default_nettype none

module audio (
  input  wire       clk,
  input  wire       rst_n,
  output wire [7:0] led,
  input  wire [3:0] btn,
  output wire [3:0] audio_l, audio_r
);

// ---------- PLL Signals ------------//
wire clk_pix, lock;
//====================================//
//                 PLL                //
//====================================//
pll pll_inst (
    .clock_in (clk),     // 10 MHz
    .rst_in   (~rst_n),
    .clock_out(clk_pix), // 40 MHz, 0 deg
    .locked   (lock)
);

// ---- Trianglewave Signals ---------//
wire [11:0] pcm_trianglewave;
//====================================//
//    triangle wave generator /\/\/\  //
//====================================//
trianglewave# (
  .DELAY   (6), // smaller value -> higher freq
  .PCM_BITS(12)
) trianglewave_inst (
  .clk     (clk_pix),
  .pcm     (pcm_trianglewave)
);

// -------- Sinewave Signals ---------//
wire [11:0] pcm_sinewave;
//====================================//
//    sine wave generator ~~~~~~~     //
//====================================//
sinewave #(
  .DELAY           (10), // smaller value -> higher freq
  .PCM_BITS        (12),
  .SPD_BITS        (10),
  .POS_TO_SPD_SHIFT(8),
  .SPD_TO_POS_SHIFT(3),
  .POS_INIT        (0),
  .SPD_INIT        (277)
) sinewave_instance (
  .clk  (clk_pix),
  .pcm  (pcm_sinewave)
);

// ---------- DAC Signals ------------//
wire [3:0]  dac; // analog output to classic headphones
wire [11:0] pcm;

assign pcm = btn[1] ? pcm_trianglewave : pcm_sinewave;
assign led = pcm[11:4];
//====================================//
//                 DAC                //
//====================================//
dacpwm dacpwm_instance (
  .clk(clk_pix),
  .pcm(pcm),
  .dac(dac)
);

assign audio_l = dac;
assign audio_r = dac;

endmodule
