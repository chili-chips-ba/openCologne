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
// Description: onewire tb
//==========================================================================
`timescale 1ps/1ps
module tb #(
   parameter int RUN_SIM_US = 1_100_0
)();

//--------------------------------------------------------------
// Generate clock and run sim for the specified amount of time
   localparam  HALF_PERIOD_PS = 50_000; // 50MHz
   logic       clk_10;
   logic arst_n;

   logic vld, rdy, we, read, led;
   logic [7:0] onewire_rdat, onewire_wdat;
   logic [4:0] bits_to_rw;

   wire onewire;
   pullup(onewire);   

   // task to input commands through UART rx
   logic uart_rx, uart_tx;

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
            
            arst_n  = 1'b0;
            #1000ns
            arst_n = 1'b1;  
            #5000ns

            onewire_wdat = 8'b1111_1111;
            vld          = 1'b0;
            we           = 1'b0;
            bits_to_rw   = 5'h8;
            // #2ms     vld = 1;
            // #0.1ms   vld = 0;
            // #1ms     vld = 1;
            // #0.1ms   vld = 0;
            #2ms
            output_byte(8'd11); //for now whenever anything is received it sends something
         end
      join
   end

   assign onewire = 1'bz;

//-----------------------------
// dut and onewire slave model
   // onewire_master dut (
   //    .clk    (clk_10),                //i
   //    .arst_n    (arst_n),                //i
   //    .onewire(onewire),               //io
   //    .bits_to_rw  (bits_to_rw),       //i
   //    .onewire_rdat(onewire_rdat),     //o
   //    .onewire_wdat(onewire_wdat),     //i
   //    .vld (vld),                      //i
   //    .rdy (rdy),                      //o
   //    .we  (we),                       //i
   //    .read(read)                      //o
   // );
   top u_dut(
      .clk_10 (clk_10),
      .arst_n (arst_n),
      .led    (led),
      .uart_rx(uart_rx),
      .uart_tx(uart_tx),
      .onewire_mst(onewire),
      .onewire_slv(onewire)
   );


   

endmodule: tb

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/06/12 TarikI: initial creation    
*/
