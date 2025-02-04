/* verilator lint_off PINMISSING */
/* verilator lint_off ASCRANGE */
module clkgen (
   input wire i_clk,
   input wire i_rstn,
   output wire o_clk_core,
   output wire o_rst_core
);

reg rst_reg1;
reg rst_reg2;

wire o_clk_pll;
wire usr_pll_lock_1;

CC_PLL #(
   .REF_CLK("10.0"),    // reference input in MHz
   .OUT_CLK(5'd16),   // pll output frequency in MHz
   .PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED
   .LOCK_REQ(1),       // 0: disable, 1: enable lock request
   .LOW_JITTER(1)       // 0: disable, 1: enable low jitter mode
) pll_inst_ila (
   .CLK_REF(i_clk), 
   .CLK_FEEDBACK(1'b0), 
   .USR_CLK_REF(1'b0),
   .USR_LOCKED_STDY_RST(1'b0), 
   .USR_PLL_LOCKED_STDY(), 
   .USR_PLL_LOCKED(usr_pll_lock_1),
   .CLK270(), .CLK180(), .CLK90(), .CLK0(o_clk_pll), 
   .CLK_REF_OUT()
);

// reset synchronizing
always @(posedge i_clk) begin
   if(!usr_pll_lock_1 || !i_rstn) begin
      rst_reg1 <= 1'b1;
      rst_reg2 <= 1'b1;
   end else begin
      rst_reg1 <= 1'b0;
      rst_reg2 <= rst_reg1;
   end
end

assign o_rst_core = rst_reg2;
assign o_clk_core = o_clk_pll;


endmodule