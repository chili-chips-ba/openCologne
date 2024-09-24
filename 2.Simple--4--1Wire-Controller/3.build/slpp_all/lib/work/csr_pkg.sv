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
// Description: This is a package with declarations of SOC-specific Control 
//    and Status registers. This is the DNA of register set. It is purposely 
//    structured and formal, to facilitate future automation/scripted generation.
//
//    It is also designed for preservation of FPGA resources. Writeable 
//    registers therefore don't have HW readback path. Instead, SW can use 
//    own variables in places where readback is needed. And, since SW 
//    variables are in RAM, they cost less than FPGA flip-flops and LUTs.
//==========================================================================

package csr_pkg;
 //import soc_pkg::clog2;
   
//-----------------------------------------------------------
// UART_TX
//-----------------------------------------------------------
// To send a byte over UART, SW must:
//   1) wait  for  'UART_TX.busy=0'
//   2) write into 'UART_TX.data' the value it wants to send 
//
// The write into this register, when 'busy=0', triggers UART transfer.
// The SW writes that come while 'busy=1' are ignored. HW therefore does 
// not allow SW to corrupt transfer that may already be going on. Such SW
// writes are lost and must be reattempted until executed for 'busy=0'.
//
// UART parameters are set in HW hardware to 115.2kbps, 1 Stop, 0 Parity.
// It is not possible for SW to change them.

   localparam ADDR_UART_TX = 'h0;

   typedef struct packed {       // MIXED
                                 //-------      
      logic [31:31] busy;        // [31]   RD_ONLY: 1 when HW cannot take another 'data'
    //logic [30:8]  rsvd;        // [30:8]
      logic [7:0]   data;        // [7:0]  WR_ONLY: Data to send out
   } uart_tx_t;                  //------- 
   

//-----------------------------------------------------------
// UART_RX
//-----------------------------------------------------------
// HW is constantly monitoring UART serial input. Whenever a byte is collected,
// HW presents it on 'UART_RX.data' slice, sets 'valid=1', and continues looking
// for more. SW is expected to poll 'valid'. The poll in which SW sees 1 on 'valid'
// is the read from which it should also take 'data'. Such SW read clears 'valid' 
// and 'oflow' flags, indicating to HW that the 'data' has exchanged hands. It 
// also pulls new 'data' value (if any) from the RxFIFO.
//
// SW polling is expected to be frequent enough to free up 'data' before HW comes
// around to place a new value into it. Should HW see that 'data' is still NOT 
// consumed (i.e. 'valid=1') at the time a new value is ready for placement, it
// will drop the new value and raise 'oflow' flag. HW thus conveys to the SW that
// one or  more data bytes have been lost in handoff. This potential loss would 
// be the result of SW inability to keep up with HW.

   localparam ADDR_UART_RX = 'h1;

   typedef struct packed {       // MIXED
                                 //-------      
      logic [31:31] valid;       // [31]    ROL_CLR: 1 when 'data' is valid
      logic [30:30] oflow;       // [30]    ROL_CLR: 1 when some 'data' bytes are lost
    //logic [29:8]  rsvd;        // [29:8]  
      logic [7:0]   data;        // [7:0]   ROL_CLR: Received data. New value is pulled
   } uart_rx_t;                  //-------           from FIFO for read with 'valid=1'



endpackage: csr_pkg

/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/1/2  JI: initial creation    
 2024/3/1  JI: Streamlined HW/SW handshake for area efficiency.
               Added full explanation.
               Added ADC1/2_RX, GPO and GPI registers.
 2024/3/28 JI: Added DAC1/2
 2024/4/22 JI: Added MISC
*/
