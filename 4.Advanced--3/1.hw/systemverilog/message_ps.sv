//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//------------------------------------------------------------------------
//                   Copyright (C) 2024 Chili.CHIPS*ba
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
// 1. Redistributions of source code must retain the above copyright 
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright 
// notice, this list of conditions and the following disclaimer in the 
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its 
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//              https://opensource.org/license/bsd-3-clause
//------------------------------------------------------------------------
// Description: message_ps module
//------------------------------------------------------------------------
// Module: message_ps
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

package message;

    typedef logic [7:0] rds_msg_type [0:51];

    // PI=0xCAFE
    // STEREO=No
    // TA=No
    // AF=107.9 MHz
    // PS="TEST1234"
    const rds_msg_type rds_msg_map = '{
        8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h2e, 8'h8e, 8'h1c, 8'hc2, 8'h31, 8'h51, 8'h15, 8'hfb,
        8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h75, 8'h1c, 8'hdc, 8'hda, 8'hcd, 8'h4d, 8'h51, 8'he9,
        8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h99, 8'hac, 8'hdc, 8'hda, 8'hcc, 8'hc4, 8'hcb, 8'hc6,
        8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'hc2, 8'h3c, 8'hdc, 8'hda, 8'hcc, 8'hcc, 8'hd2, 8'h51,
        8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00
    };

endpackage
/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/29 TH: Initial creation

*/