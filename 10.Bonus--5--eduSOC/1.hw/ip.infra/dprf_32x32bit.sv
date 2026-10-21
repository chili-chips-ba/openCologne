//==========================================================================
// SPDX-FileCopyrightText: 2023 Chili.CHIPS
//--------------------------------------------------------------------------
// SPDX-License-Identifier: BSD-3-Clause
//--------------------------------------------------------------------------
// Description: 
//   Dual-Port register file of 32 entries, each 32-bit wide.
//
//   This is behavioral description. The idea is replace it with technology
//   specific DistributedRAM, or ShadowSRAM, so mimimizing area and maximizing 
//   performance
//==========================================================================

module dprf_32x32bit (
   input  logic        clk,

// One WRITE port: Synchronous
   input  logic        wen,
   input  logic [6:2]  waddr,
   input  logic [31:0] wdata,

// Two READ ports: Asynchronous
   input  logic [6:2]  raddr1,
   output logic [31:0] rdata1,

   input  logic [6:2]  raddr2,
   output logic [31:0] rdata2
);

`ifdef YOSYS
   (* ram_style = "distributed" *) logic [31:0] rf[32];

`else // Gowin
   logic [31:0] rf [32] /* synthesis syn_ramstyle = "distributed_ram" */;
`endif
   
   always_ff @(posedge clk) begin
      if (wen == 1'b1) rf[waddr] <= wdata;
   end

   assign rdata1 = rf[raddr1];
   assign rdata2 = rf[raddr2];

endmodule: dprf_32x32bit

/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/1/4 JI: initial creation    
*/
