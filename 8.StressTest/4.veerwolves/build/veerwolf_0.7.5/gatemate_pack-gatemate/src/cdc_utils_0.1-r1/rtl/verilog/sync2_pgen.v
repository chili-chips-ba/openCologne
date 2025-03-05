/*
cdc_utils by Olof Kindgren <olof.kindgren@gmail.com>
To the extent possible under law, the person who associated CC0 with
cdc_utils has waived all copyright and related or neighboring rights
to cdc_utils

You should have received a copy of the CC0 legalcode along with this
work. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

Verilog implementation of "Synchronized pulse generation logic"
from chapter 5.6.1 in Clifford Cummings "Clock Domain Crossing (CDC) Design &
Verification Techniques Using SystemVerilog"
http://www.sunburst-design.com/papers/CummingsSNUG2008Boston_CDC.pdf
*/
module sync2_pgen
  (input  c,
   input  d,
   output p,
   output q);

   reg 	  q1, q2, q3;
   
   always @(posedge c) begin
      q1 <= d;
      q2 <= q1;
      q3  <= q2;
   end

   assign p = q2 ^ q3;
   assign q = q3;
   
endmodule
