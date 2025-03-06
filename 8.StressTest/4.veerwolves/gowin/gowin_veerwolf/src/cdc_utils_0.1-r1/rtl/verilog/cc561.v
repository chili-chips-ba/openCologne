/*
cdc_utils by Olof Kindgren <olof.kindgren@gmail.com>
To the extent possible under law, the person who associated CC0 with
cdc_utils has waived all copyright and related or neighboring rights
to cdc_utils

You should have received a copy of the CC0 legalcode along with this
work. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

Verilog implementation of "MCP formulation using a synchronized enable pulse"
from chapter 5.6.1 in Clifford Cummings "Clock Domain Crossing (CDC) Design &
Verification Techniques Using SystemVerilog"
http://www.sunburst-design.com/papers/CummingsSNUG2008Boston_CDC.pdf
*/

module cc561
  #(parameter DW=0)
  (input 	       aclk,
   input 	       arst,
   input [DW-1:0]      adata,
   input 	       aen,
   input 	       bclk,
   output reg [DW-1:0] bdata,
   output reg 	       ben);

   reg [DW-1:0]    adata_r;
   reg 		   aen_r = 1'b0;
   wire 	   bpulse;
   
   always @(posedge aclk) begin
      if (aen)
	adata_r <= adata;

      aen_r <= aen ^ aen_r;
      if (arst)
	aen_r <= 1'b0;
   end

   always @(posedge bclk) begin
      if (bpulse)
	bdata <= adata_r; //CDC
      ben <= bpulse;
   end
   
   sync2_pgen sync2_pgen
     (.c (bclk),
      .d (aen_r), //CDC
      .p (bpulse),
      .q ());

endmodule
