	// verilator_coverage annotation
	// DESCRIPTION: Verilator: Verilog example module
	//
	// This file ONLY is placed under the Creative Commons Public Domain, for
	// any use, without warranty, 2003 by Wilson Snyder.
	// SPDX-License-Identifier: CC0-1.0
	// ======================================================================
	
	module top
 000206	  (input logic clk,
 000001	   input logic reset);
	
	   // Create 100 cycles of example stimulus
 000197	   reg [31:0] count_c;
 000206	   always_ff @ (posedge clk) begin
	      //$display("[%0t] clk=%b reset=%b", $time, clk, reset);
 000006	      if (reset) begin
 000100	      verilator_coverage: (next point on previous line)

 000003		 count_c <= 0;
	      end
 000100	      else begin
 000100		 count_c <= count_c + 1;
 000002		 if (count_c >= 99) begin
 000099		 verilator_coverage: (next point on previous line)

 000001	            $write("*-* All Finished *-*\n");
 000001	            $finish;
		 end
	      end
	   end
	
	   // Example coverage analysis
 000002	   cover property (@(posedge clk) count_c == 30);  // Hit
%000000	   cover property (@(posedge clk) count_c == 300);  // Not covered
	
	   // Example toggle analysis
 000002	   wire count_hit_50;  // Hit
%000000	   wire count_hit_500;  // Not covered
	
	   assign count_hit_50 = (count_c == 50);
	   assign count_hit_500 = (count_c == 500);
	
	   // Example line and block coverage
%000000	   always_comb begin
 000002	      if (count_hit_50) begin  // Hit	
 000102	      verilator_coverage: (next point on previous line)

 000001	         $write("[%0t] got 50\n", $time);  // Hit
	      end
%000000	      if (count_hit_500) begin  // Not covered
 000103	      verilator_coverage: (next point on previous line)

%000000	         $write("[%0t] got 600\n", $time);  // Not covered
	      end
	   end
	
	endmodule
	
