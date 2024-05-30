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
// Description: message_ps_rt package
//------------------------------------------------------------------------
// Module: message_ps_rt
// Description:
// Parameters:
// Inputs:
// Outputs:
//========================================================================

package message;

  typedef logic[7:0] rds_msg_type[0:259];

  // PI=0xCAFE
  // STEREO=No
  // TA=No
  // AF=107.9 MHz
  // PS="TEST1234"
  // RT="ABCDEFGHIJKLMNOPQRSTUVWXYZ    ABCDEFGHIJKLMNOPQRSTUVWXYZ    1234"
  const rds_msg_type rds_msg_map = '{
    8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h2e, 8'h8e, 8'h1c, 8'hc2, 8'h31, 8'h51, 8'h15, 8'hfb,
    8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h75, 8'h1c, 8'hdc, 8'hda, 8'hcd, 8'h4d, 8'h51, 8'he9,
    8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'h99, 8'hac, 8'hdc, 8'hda, 8'hcc, 8'hc4, 8'hcb, 8'hc6,
    8'hca, 8'hfe, 8'ha0, 8'h01, 8'h00, 8'hc2, 8'h3c, 8'hdc, 8'hda, 8'hcc, 8'hcc, 8'hd2, 8'h51,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h00, 8'h14, 8'h74, 8'h14, 8'h20, 8'h59, 8'h0d, 8'h11, 8'h5d,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h00, 8'h4f, 8'he4, 8'h54, 8'h60, 8'hed, 8'h1d, 8'h22, 8'h73,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h00, 8'ha3, 8'h54, 8'h94, 8'ha1, 8'h31, 8'h2d, 8'h31, 8'h07,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h00, 8'hf8, 8'hc4, 8'hd4, 8'he1, 8'h85, 8'h3d, 8'h41, 8'h96,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h01, 8'h21, 8'ha5, 8'h15, 8'h22, 8'h89, 8'h4d, 8'h51, 8'he9,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h01, 8'h7a, 8'h35, 8'h55, 8'h62, 8'h3d, 8'h5d, 8'h62, 8'hc7,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h01, 8'h96, 8'h85, 8'h95, 8'ha3, 8'he0, 8'h80, 8'h80, 8'hdc,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h01, 8'hcd, 8'h12, 8'h02, 8'h00, 8'h01, 8'h05, 8'h08, 8'hca,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h02, 8'h24, 8'h44, 8'h34, 8'h46, 8'h05, 8'h15, 8'h18, 8'he7,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h02, 8'h7f, 8'hd4, 8'h74, 8'h8a, 8'hbd, 8'h25, 8'h28, 8'h90,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h02, 8'h93, 8'h64, 8'hb4, 8'hc7, 8'h6d, 8'h35, 8'h38, 8'hbd,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h02, 8'hc8, 8'hf4, 8'hf5, 8'h05, 8'h29, 8'h45, 8'h48, 8'h7e,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h03, 8'h11, 8'h95, 8'h35, 8'h44, 8'hd5, 8'h55, 8'h58, 8'h53,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h03, 8'h4a, 8'h05, 8'h75, 8'h88, 8'h6d, 8'h65, 8'h68, 8'h24,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h03, 8'ha6, 8'hb2, 8'h02, 8'h00, 8'h00, 8'h80, 8'h80, 8'hdc,
    8'hca, 8'hfe, 8'ha0, 8'h09, 8'h03, 8'hfd, 8'h23, 8'h13, 8'h2c, 8'h68, 8'hcc, 8'hd2, 8'h51
  };
endpackage

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/30 TH: Initial creation

*/