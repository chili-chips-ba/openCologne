`timescale 1ps/1ps
module tb #(
   parameter int RUN_SIM_US = 50000
)();

//--------------------------------------------------------------
// Generate clock and run sim for the specified amount of time
   localparam  HALF_PERIOD_PS = 50_000; // 10MHz
   logic       clk_10, clk_100;

   logic rst_n;
   initial begin
      rst_n = 0;
      clk_10 = 1;
      fork
         forever begin : clk_gen
            #(HALF_PERIOD_PS * 1ps) clk_10 = ~clk_10;
         end

         begin :  run_sim
            #(RUN_SIM_US * 1us);
            $finish();
         end

         begin: reset
            #100ns;
            rst_n = 1;
         end
      join
      
   end

   logic uart_tx;
   corescore_gatemate u_dut (
      .i_clk(clk_10),
      .i_rstn(rst_n),
      .o_uart_tx(uart_tx)
   );

endmodule