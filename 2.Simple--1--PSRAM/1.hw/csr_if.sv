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
// Description: 
//  - SOC-specific interface for Config and Status Registers (CSR)
//  - Provides structured CSR I/O
//========================================================================

interface csr_if ();
   import csr_pkg::*;
   
// UART_TX
   logic        uart_tx_write;
   logic        uart_tx_busy;
   logic [7:0]  uart_tx_data;

// UART_RX
   logic        uart_rx_read;
   uart_rx_t    uart_rx;


  //---------------------------------------- 
  // master/CPU side
  //---------------------------------------- 
   modport MST (
      output uart_tx_write,
             uart_tx_data,
             uart_rx_read,

      input  uart_tx_busy,
             uart_rx
   );

  //---------------------------------------- 
  // Slave/Peripheral side
  //---------------------------------------- 
   modport SLV_UART (
     input  uart_tx_write,
            uart_tx_data,
            uart_rx_read,

     output uart_tx_busy,
            uart_rx
   );

endinterface: csr_if

/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/6/7 Tarik Ibrahimovic: initial creation
*/
