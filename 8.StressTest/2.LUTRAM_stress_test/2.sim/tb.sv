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
// Description: Simulation testbench for the LUTRAM arrays
//==========================================================================
`timescale 1ps/1ps
module tb #(
   parameter int RUN_SIM_US = 1_000_0
)();

//--------------------------------------------------------------
// Generate clock and run sim for the specified amount of time
   localparam  HALF_PERIOD_PS = 50_000; // 50MHz
   logic       clk_10;

   logic [4:0] addr;
   logic [9:0] wdat;
   logic we;
   logic [9:0] rdat;

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

         begin: seq
            // write to a location
            #200ns
            addr = 5'h0;
            we   = 1;
            wdat = 10'h0BC;
            #200ns
            // read from it
            we = 0;

            #1us
            // write to a location
            #200ns
            addr = 5'b01111;
            we   = 1;
            wdat = 10'h1BC;
            #200ns
            // read from it
            we = 0;

            // write to a location
            #200ns
            addr = 5'b11111;
            we   = 1;
            wdat = 10'h2BC;
            #200ns
            // read from it
            we = 0;


                        // write to a location
            #200ns
            addr = 5'b10000;
            we   = 1;
            wdat = 10'h3BC;
            #200ns
            // read from it
            we = 0;
            
            
            
         end
      join
   end

   top #(
      .LUTRAM16X10(2)
   )
   dut (
      .clk(clk_10),
      .addr(addr),
      .wdat(wdat),
      .we(we),
      .rdat(rdat)
   );

//--------------------------------------------------------------


endmodule: tb

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/08/20 TarikI: initial creation    
*/
