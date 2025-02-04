module corescore_gatemate
  (
   input i_clk,
   input i_rstn,
   output wire o_uart_tx);

   wire        clk;
   wire        o_rst;

  //Create a 16MHz clock from 10MHz using PLL
  clkgen clkgen
    (.i_clk     (i_clk),
     .i_rstn    (i_rstn),
     .o_clk_core(clk),
     .o_rst_core(o_rst));

   wire [7:0]  tdata;
   wire        tlast;
   wire        tvalid;
   wire        tready;

   corescorecore corescorecore
     (.i_clk     (clk),
      .i_rst     (o_rst),
      .o_tdata   (tdata),
      .o_tlast   (tlast),
      .o_tvalid  (tvalid),
      .i_tready  (tready));

   emitter_uart emitter
     (.i_clk     (clk),
      .i_rst     (o_rst),
      .i_tdata    (tdata),
      .i_tvalid   (tvalid),
      .o_tready   (tready),
      .o_uart_tx (o_uart_tx));

endmodule
