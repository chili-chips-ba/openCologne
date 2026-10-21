//==========================================================================
// SPDX-FileCopyrightText: 2023 Chili.CHIPS
//--------------------------------------------------------------------------
// SPDX-License-Identifier: BSD-3-Clause
//--------------------------------------------------------------------------
// Description: 
//   Simple debouncer of board push-buttons and switches
//==========================================================================

module debounce #(
   parameter bit ACTIVE = 1'b1 // 1 for Active1; 0 for Active0 input
)(
   input  logic  arst_n,
   input  logic  clk,
   input  logic  tick_15us,

   input  logic  inp,
   output logic  out
);

   logic [2:0]  pipe;

   always_ff @ (negedge arst_n or posedge clk) begin

   // intialize to the value opposite from ACTIVE
     if (arst_n == 1'b0) begin
        pipe <= {3{~ACTIVE}};
        out  <=    ~ACTIVE;
     end

   // then, we need to see ACTIVE value three
   // times in a row to pass it to the output
     else if (tick_15us == 1'b1) begin
        pipe <= {pipe[1:0], inp};
        out  <= (pipe == {3{ACTIVE}});
     end
   end
   
endmodule: debounce

/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/1/3  JI: initial creation
 2024/2/12 JI: improved so that it works for both Active1 and Active0  input
*/
