//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//==========================================================================
// Copyright (C) 2023 Chili.CHIPS*ba
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
