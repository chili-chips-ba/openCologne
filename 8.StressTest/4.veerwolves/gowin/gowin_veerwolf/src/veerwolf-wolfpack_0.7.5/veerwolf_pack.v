// THIS FILE IS AUTOGENERATED BY verilogwriter.py
// ANY MANUAL CHANGES WILL BE LOST
`default_nettype none
module veerwolf_pack
#(  parameter pack_code = "bootloader.vh")
   (input  wire        clk_core,
    input  wire        rst_core,
    input  wire        i_uart_rx,
    output wire        o_uart_tx,
    input  wire [15:0] i_sw,
    output wire [15:0] o_led);

wire [15:0] gpio0;
wire        uart0;
wire [15:0] gpio1;
wire        uart1;

assign gpio0 = i_sw;
assign o_led = gpio1;
assign uart0 = i_uart_rx;
assign o_uart_tx = uart1;

veerwolf_tile
  #(.bootrom_file (pack_code))
 tile0
   (.clk_core  (clk_core),
    .rst_core  (rst_core),
    .i_uart_rx (uart0),
    .o_uart_tx (uart1),
    .i_sw      (gpio0),
    .o_led     (gpio1));

endmodule
