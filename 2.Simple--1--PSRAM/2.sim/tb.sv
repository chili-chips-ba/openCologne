//==========================================================================
// Copyright (C) 2024 Chili.CHIPS*ba
//--------------------------------------------------------------------------
//                      PROPRIETARY INFORMATION
//
// The information contained in this file is the property of CHILI CHIPS LLC.
// Except as specifically authorized in writing by CHILI CHIPS LLC, the holder
// of this file: (1) shall keep all information contained herein confidential;
// and (2) shall protect the same in whole or in part from disclosure and
// dissemination to all third parties; and (3) shall use the same for operation
// and maintenance purposes only.
//--------------------------------------------------------------------------
// Description: Simulation testbench just stimulating uart at the time
//==========================================================================

`timescale 1ps/1ps
module tb #(
   parameter int RUN_SIM_US = 1_000_00
)();


//--------------------------------------------------------------
// Generate clock and run sim for the specified amount of time
   localparam  HALF_PERIOD_PS = 50_000; // 50MHz
   logic       clk_10, clk_100;
   logic       tick_1us;

   logic uart_rx, uart_tx;
   logic arst_n;
   
   task output_byte;
      input logic [7:0] value;
      uart_rx = 1'b0;  #8.68us; //start
      for (int i = 0; i < 8; i = i+1) begin
         uart_rx = value[i]; #8.68us;
      end
      uart_rx = 1'b1; #8.68us; //STOP
   endtask
   initial begin
      clk_10  = 1'b0;


      $dumpfile("../2.sim/tb.vcd");
		$dumpvars(0, tb);

      fork 
         forever begin: clock_gen
            #(HALF_PERIOD_PS * 1ps) clk_10 = ~clk_10;
         end

         begin: run_sim
            #(RUN_SIM_US * 1us);
            $finish();
         end

         begin: reset
            uart_rx = 1'b1;
            arst_n = 1'b0;
            #100ns
            arst_n = 1'b1;  
            #1000000ns
            output_byte(8'b0); //R
            output_byte(8'h22); //AB
            output_byte(8'h33); //12
            output_byte(8'h44); //CD
            #1000000ns
            output_byte(8'b00000001); //W
            output_byte(8'h2); //AB
            output_byte(8'h3); //12
            output_byte(8'h4); //12
            output_byte(8'h7); //34
            output_byte(8'h7); //56
            #10000ns;
/*             for (int i = 0; i < 12; i = i + 1) begin
               $display("Array Element [%d]: %h",i, dut.command_bytes[i]);   
            end */
            
         end
      join
   end

   logic tick_100ms;
   logic led;
   
   logic data0, data1, data2, data3, data4, data5, data6 , data7;
   logic clk_psram,csn;
//--------------------------------------------------------------
   top dut (
      .clk(clk_10),
      .arst_n(arst_n),
      .tick_1us(tick_1us),
      .uart_tx(uart_tx),
      .uart_rx(uart_rx),
      .o_psram_csn(csn),
      .o_psram_sclk(clk_psram),
      .io_psram_data0(data0),
      .io_psram_data1(data1),
      .io_psram_data2(data2),
      .io_psram_data3(data3),
      .io_psram_data4(data4),
      .io_psram_data5(data5),
      .io_psram_data6(data6),
      .io_psram_data7(data7), 
      .led(led)
   );

endmodule: tb

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/06/12 TarikI: initial creation    
*/
