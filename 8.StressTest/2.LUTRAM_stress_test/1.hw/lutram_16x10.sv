//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//==========================================================================
// SPDX-FileCopyrightText: 2023 Chili.CHIPS
//--------------------------------------------------------------------------
// SPDX-License-Identifier: BSD-3-Clause
//--------------------------------------------------------------------------
// Description: 
//   
//==========================================================================
module lutram_16x10(
    input logic clk,
    input logic [9:0] wdat,
    input logic [3:0] addr,
    input logic we,
    output logic [9:0] rdat
);

logic [9:0] dist_mem [16];

always_comb begin : _read_block
    rdat = dist_mem[addr];
end: _read_block

always_ff @(posedge clk) begin : _write_block
    if(we == 1'b1) begin
        dist_mem[addr] <= wdat;
    end
end: _write_block
    
endmodule
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/8/20 Tarik Ibrahimovic: Initial Creation
*/
