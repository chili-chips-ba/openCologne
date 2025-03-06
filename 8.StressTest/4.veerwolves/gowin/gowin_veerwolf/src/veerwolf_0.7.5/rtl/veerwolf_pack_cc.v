`default_nettype none
module veerwolf_pack_cc
  #(parameter bootrom_file = "pack_rom.vh",
    parameter cpu_type = "EL2")
   (input wire 	       clk,
    input wire 	       rstn,
    input wire 	       i_uart_rx,
    output wire        o_uart_tx,
    input wire [15:0]  i_sw,
    output reg [15:0]  o_led);

   wire [63:0] 	       gpio_out;
   reg [15:0] 	       led_int_r;

   wire 	 clk_core;
   wire 	 rst_core;

   clkgen clk_gen
     (.i_clk (clk),
      .i_rst (~rstn),
      .o_clk_core (clk_core),
      .o_rst_core (rst_core));



   veerwolf_pack
     #(.pack_code (bootrom_file))
   veerwolfs
    (.clk_core (clk_core),
     .rst_core (rst_core),
     .i_uart_rx (i_uart_rx),
     .o_uart_tx (o_uart_tx),
     .i_sw (i_sw),
     .o_led (o_led));

endmodule
