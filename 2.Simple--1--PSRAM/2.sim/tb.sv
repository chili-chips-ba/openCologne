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
// Description: Simulation testbench for the PSRAM example
// PSRAM is operated by sending in commands
// Format of the commands sent to PSRAM through the UART RX is: 1st byte: <Read(0)/Write(1)>
//                                                              2-5 byte: <24 bit Address>
//                                                Write case:   6-7 byte: <16 bit Data>
//==========================================================================
`timescale 1ps/1ps
module tb #(
   parameter int RUN_SIM_US = 1_000_0
)();

//--------------------------------------------------------------
// Generate clock and run sim for the specified amount of time
   localparam  HALF_PERIOD_PS = 50_000; // 50MHz
   logic       clk_10, clk_100;
   logic       tick_02us;

   logic uart_rx, uart_tx;
   logic arst_n;
   // tasl to input commands through UART rx
   task output_byte;
      input logic [7:0] value;
      uart_rx = 1'b0;  #8.68us; //start
      for (int i = 0; i < 8; i = i+1) begin
         uart_rx = value[i]; #8.68us;
      end
      uart_rx = 1'b1; #8.68us; //STOP
   endtask

   // 
   localparam logic [23:0] addr = 24'h040302;
   localparam logic [15:0] data = 16'h0708;

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
            #5000000ns
            for (int i = 0; i<10; i++) begin
               #1000ns;
               output_byte(8'b1);          //W  - write
               output_byte(addr[7:0]);     //22 - address: 0x443322
               output_byte(addr[15:8]);    //33
               output_byte(addr[23:16]);   //44
               output_byte(data[7:0]);     //CD - data   : 0xAB
               output_byte(data[15:8]);    //AB
               #10000ns;
               // For RTL sim: check what is written in the intended locations
               // $display("Written at location %h: %h",addr, u_psram.psram_mem_ary[addr]);
               // $display("Writen at location %h: %h",addr+1, u_psram.psram_mem_ary[addr+1]);
               output_byte(8'b0);         //R  - read
               output_byte(addr[7:0]);    //22 - address: 0x443322
               output_byte(addr[15:8]);   //33
               output_byte(addr[23:16]);  //44
               end
         end
      join
   end
   // For RTL sim: check if written data is equal to read data
   // always_comb begin 
   //    if (dut.u_psram.o_state == READ_DESELECT) begin
   //       // $display("Data: %h", dut.u_psram.o_dout);
   //       if(data != dut.u_psram.o_dout) begin
   //          // $display("Error: written and read data don't match:");
   //          // $display("Written: %h, Read: %h", data, dut.u_psram.o_dout);
   //       end
   //    end
      
   // end

   logic tick_100ms;
   logic led;
   logic sent;
   
   wire io_psram_data0, io_psram_data1, io_psram_data2, io_psram_data3, io_psram_data4, io_psram_data5, io_psram_data6 , io_psram_data7;
   logic clk_psram,csn;
//--------------------------------------------------------------
   top dut (
      .clk(clk_10),
      .arst_n(arst_n),
      .uart_tx(uart_tx),
      .uart_rx(uart_rx),
      .tick_02us(tick_02us),
      .o_psram_csn(csn),
      .o_psram_sclk(clk_psram),
      .io_psram_data0(io_psram_data0),
      .io_psram_data1(io_psram_data1),
      .io_psram_data2(io_psram_data2),
      .io_psram_data3(io_psram_data3),
      .io_psram_data4(io_psram_data4),
      .io_psram_data5(io_psram_data5),
      .io_psram_data6(io_psram_data6),
      .io_psram_data7(io_psram_data7), 
      .led(led)
   );
   psram_sim u_psram(
      .psram_csn(csn),
      .psram_sclk(clk_psram),
      .arst_n (arst_n),
      .io_psram_data0(io_psram_data0),
      .io_psram_data1(io_psram_data1),
      .io_psram_data2(io_psram_data2),
      .io_psram_data3(io_psram_data3),
      .io_psram_data4(io_psram_data4),
      .io_psram_data5(io_psram_data5),
      .io_psram_data6(io_psram_data6),
      .io_psram_data7(io_psram_data7)
   );

endmodule: tb

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/06/12 TarikI: initial creation    
*/
