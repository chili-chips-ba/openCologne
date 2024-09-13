`default_nettype none
module top_fm #(
    parameter abcxyz = 0
) (
    input  wire       clk_10mhz,
    input  wire       btn,
    output wire       led,
    output wire       ant_433mhz,
    output wire       wifi_gpio0
);

  wire clk270_1, clk180_1, clk90_1, clk0_1, usr_ref_out_1;
  wire usr_pll_lock_1;

  CC_PLL #(
      .REF_CLK        ("10.0"),     // reference input in MHz
      .OUT_CLK        ("40.0"),     // pll output frequency in MHz
      .LOCK_REQ       (0),
      .PERF_MD        ("ECONOMY"),  // LOWPOWER, ECONOMY, SPEED
      .LOW_JITTER     (1),          // 0: disable, 1: enable low jitter mode
      .CI_FILTER_CONST(2),          // optional CI filter constant
      .CP_FILTER_CONST(4)           // optional CP filter constant
  ) pll_inst1 (
      .CLK_REF(clk_10mhz),
      .CLK_FEEDBACK(1'b0),
      .USR_CLK_REF(1'b0),
      .USR_LOCKED_STDY_RST(1'b0),
      .USR_PLL_LOCKED_STDY(),
      .USR_PLL_LOCKED(usr_pll_lock_1),
      .CLK270(clk270_1),
      .CLK180(clk180_1),
      .CLK90(clk90_1),
      .CLK0(clk0_1),
      .CLK_REF_OUT(usr_ref_out_1)
  );

  wire clk270_2, clk180_2, clk90_2, clk0_2, usr_ref_out_2;
  wire usr_pll_lock_2;

  CC_PLL #(
      .REF_CLK        ("10.0"),     // reference input in MHz
      .OUT_CLK        ("240.0"),    // pll output frequency in MHz
      .LOCK_REQ       (0),
      .PERF_MD        ("ECONOMY"),  // LOWPOWER, ECONOMY, SPEED
      .LOW_JITTER     (1),          // 0: disable, 1: enable low jitter mode
      .CI_FILTER_CONST(2),          // optional CI filter constant
      .CP_FILTER_CONST(4)           // optional CP filter constant
  ) pll_inst2 (
      .CLK_REF(clk_10mhz),
      .CLK_FEEDBACK(1'b0),
      .USR_CLK_REF(1'b0),
      .USR_LOCKED_STDY_RST(1'b0),
      .USR_PLL_LOCKED_STDY(),
      .USR_PLL_LOCKED(usr_pll_lock_2),
      .CLK270(clk270_2),
      .CLK180(clk180_2),
      .CLK90(clk90_2),
      .CLK0(clk0_2),
      .CLK_REF_OUT(usr_ref_out_2)
  );


  wire clk_locked;
  wire clk = clk0_1;
  wire clk_fmdds = clk0_2;

  reg [15:0] beep;
  always @(posedge clk) beep <= beep + 1;

  reg [7:0] rds_ram[0:51];
  initial $readmemh("message_ps.mem", rds_ram);
  wire [5:0] rds_addr;
  reg  [7:0] rds_data;
  always @(posedge clk) rds_data <= rds_ram[rds_addr];
  fmgen_test  //#(
              //  .C_fmdds_hz(250*1000000),
              //  .C_rds_clock_multiply(228),
              //  .C_rds_clock_divide(3125)
              //)
  fmgen_test_inst (
      .clk(clk),
      .clk_fmdds(clk_fmdds),
      .pcm_in_left(btn ? beep[15:1] : 0),  // beep, may spoil RDS
      .pcm_in_right(btn ? beep[15:1] : 0),  // beep, may spoil RDS
      .cw_freq(107900000),
      .rds_addr(rds_addr),
      .rds_data(rds_data),
      .fm_antenna(ant_433mhz)
  );

  assign led = rds_data[0];

endmodule
`default_nettype wire
