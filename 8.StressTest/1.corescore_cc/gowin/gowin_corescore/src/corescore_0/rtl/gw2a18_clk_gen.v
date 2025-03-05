module clkgen (
   input wire i_clk,
   input wire i_rstn,
   output wire o_clk_core,
   output wire o_rst_core
);

wire pll_lock;

   rPLL #(
      //.DEVICE           ("GW1NR-9C"),
      //.DEVICE           ("GW2AR-18C"),
      .DEVICE           ("GW2AR-18C"),
      .FCLKIN           ("27"), 
      .DYN_IDIV_SEL     ("false"),
      .IDIV_SEL         (4),
      .DYN_FBDIV_SEL    ("false"),
      .FBDIV_SEL        (2),
      .DYN_ODIV_SEL     ("false"),
      .ODIV_SEL         (32),
      .PSDA_SEL         ("0000"),
      .DYN_DA_EN        ("true"),
      .DUTYDA_SEL       ("1000"),
      .CLKOUT_FT_DIR    (1'b1),
      .CLKOUTP_FT_DIR   (1'b1),
      .CLKOUT_DLY_STEP  (0),
      .CLKOUTP_DLY_STEP (0),
      .CLKFB_SEL        ("internal"),
      .CLKOUT_BYPASS    ("false"),
      .CLKOUTP_BYPASS   ("false"),
      .CLKOUTD_BYPASS   ("false"),
      .DYN_SDIV_SEL     (2),
      .CLKOUTD_SRC      ("CLKOUT"),
      .CLKOUTD3_SRC     ("CLKOUT")
   )
   u_pll (
      .CLKOUT   (o_clk_core),
      .LOCK     (pll_lock),
      .CLKOUTP  (),
      .CLKOUTD  (),
      .CLKOUTD3 (),
       
      .RESET    (1'b0),
      .RESET_P  (1'b0),
      .CLKIN    (i_clk),
      .CLKFB    (1'b0),
      .FBDSEL   ('0),
      .IDSEL    ('0),
      .ODSEL    ('0),
      .PSDA     ('0),
      .DUTYDA   ('0),
      .FDLY     ('0)
   );

//--------------------------------------------------
// Reset synchronizer
//--------------------------------------------------
   reg  srst_n_pipe;
   wire  final_rst;
   assign final_rst = ~i_rstn | ~pll_lock;
   reg srst_n;

   always @(posedge final_rst or posedge o_clk_core) begin
      if (final_rst == 1'b1) begin
         srst_n_pipe <= 1'b0;
         srst_n      <= 1'b0;
      end
      else begin   
         srst_n_pipe <= 1'b1;
         srst_n      <= srst_n_pipe;
      end
   end

   assign o_rst_core = ~srst_n;
endmodule