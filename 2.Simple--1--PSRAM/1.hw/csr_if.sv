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
//  - SOC-specific interface for Config and Status Registers (CSR)
//  - Provides structured CSR I/O
//==========================================================================

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
 2024/1/2  JI: initial creation    
 2024/3/1  JI: added ADC1/2_RX, GPO and GPI I/O
 2024/3/28 JI: added DAC1/2
 2024/4/22 JI: added MISC
*/
