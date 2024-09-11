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
//   SOC top-level design.
//
//   Standardized template, then customized to each particular SOC design.
//   We hereby instantiate all Master(s) and Slave(s), and connect to form
//   the complete System On Chip. 
//
//   Customized for Sipeed TangNano20K board and Elreg nextgen Sonar+Doppler
//==========================================================================

module top 
   import soc_pkg::*;
(

//___Common infrastructure
   input  logic        clk_27,    // 27MHz clock oscillator on TangNano20K
   input  logic [2:0]  clk_fpll,  // clock from onboard FractionalPLL (MS5351)
   input  logic [2:1]  key,       // active-HI, S1:UserFunction S2:Reset
   output logic [3:2]  led_n,     // active-LO onboard LEDs
                        
   input  logic        uart_rx,   // -\ UART towards BL616
   output logic        uart_tx,   // -/ 

 //input  logic        ser422_rx, //-\ UART towards RS422 
 //output logic        ser422_tx, //-/ 

//___Embedded SDRAM
   output logic        O_sdram_clk,
   output logic        O_sdram_cke,
   output logic        O_sdram_cs_n,
                                 
   output logic        O_sdram_ras_n,
   output logic        O_sdram_cas_n,
   output logic        O_sdram_wen_n,
                                
   output logic [1:0]  O_sdram_ba,  
   output logic [10:0] O_sdram_addr,
   output logic [3:0]  O_sdram_dqm,

   inout  wire  [31:0] IO_sdram_dq,

//___2-channel ADC
   output logic [2:1]  adc_ssr,
   output logic [2:1]  adc_inject,
   output logic [2:1]  adc_pwdn_n,
   output logic [2:1]  adc_start,
   output logic [2:1]  adc_clk,
   input  logic [2:1]  adc_dout_p,
   input  logic [2:1]  adc_dout_n,

//___2-channel DAC
   output logic        dac_clk_out,
   output logic        dac_pwd, // 1= Power Down
   output logic [9:0]  dac_data // DDR: negedge=capture CH2
);

//=================================
// Clock and reset generation
//=================================
   logic       clk_54;
   logic       srst54_n;
                
   logic       strobe_27;
   logic       tick_1us;
   logic       tick_cca15us;
   logic       key1_clean;
   
   clk_rst_gen u_clk_rst (
      .clk_27    (clk_27),       //i
      .clk_fpll  (clk_fpll),     //i
      .force_rst (key[2]),       //i            

      .clk_54    (clk_54),       //o
      .srst54_n  (srst54_n),     //o

      .strobe_27 (strobe_27),    //o
      .tick_1us  (tick_1us)      //o
   );

   debounce #(.ACTIVE(1'b1)) u_debounce (
      .arst_n    (srst54_n),     //i
      .clk       (clk_54),       //i
      .tick_15us (tick_cca15us), //i
      .inp       (key[1]),       //i
      .out       (key1_clean)    //o
   );

//=================================
// CPU Subsystem
//=================================
   localparam NUM_WORDS_IMEM = 8192; //=> 32kB InstructionRAM
   localparam NUM_WORDS_DMEM = 8192; //=> 32kB DataRAM

   soc_if bus_cpu   (.arst_n(srst54_n), .clk(clk_54));
   soc_if bus_adc   (.arst_n(srst54_n), .clk(clk_54));
   soc_if bus_dmem  (.arst_n(srst54_n), .clk(clk_54));
   soc_if bus_csr   (.arst_n(srst54_n), .clk(clk_54));
   soc_if bus_sdram (.arst_n(srst54_n), .clk(clk_54));

   csr_if csr ();

   logic        imem_we;
   logic [31:2] imem_waddr;
   logic [31:0] imem_wdat;

//---------------------------------   
   soc_cpu #(
     .ADDR_RESET     (32'h 0000_0000),
     .NUM_WORDS_IMEM (NUM_WORDS_IMEM)
   ) 
   u_cpu (
     .bus        (bus_cpu),    //MST

     .imem_we    (imem_we),    //-\ access point for 
     .imem_waddr (imem_waddr), // | reloading CPU 
     .imem_wdat  (imem_wdat)   //-/ program memory 
   ); 

//---------------------------------
  soc_fabric u_fabric (
     .cpu   (bus_cpu),  //SLV
     .adc   (bus_adc),  //SLV

     .dmem  (bus_dmem), //MST
     .csr   (bus_csr),  //MST
     .sdram (bus_sdram) //MST
  );

//---------------------------------
  soc_ram #(.NUM_WORDS(NUM_WORDS_DMEM)) u_dmem (
     .bus (bus_dmem) //SLV
  );

//---------------------------------
  soc_csr u_csr (
     .bus (bus_csr), //SLV
     .csr (csr)      //MST
  );
                   
//---------------------------------
  soc_sdram u_sdram (
     .O_sdram_clk   (O_sdram_clk),
     .O_sdram_cke   (O_sdram_cke), 
     .O_sdram_cs_n  (O_sdram_cs_n),

     .O_sdram_ras_n (O_sdram_ras_n),
     .O_sdram_cas_n (O_sdram_cas_n),
     .O_sdram_wen_n (O_sdram_wen_n),

     .O_sdram_ba    (O_sdram_ba),
     .O_sdram_addr  (O_sdram_addr),
     .O_sdram_dqm   (O_sdram_dqm),
     .IO_sdram_dq   (IO_sdram_dq),

     .bus           (bus_sdram),   //SLV

     .tick_1us      (tick_1us),    //i
     .tick_cca15us  (tick_cca15us) //o
  );

//---------------------------------
  uart u_uart (
    .arst_n     (srst54_n),   //i 
    .clk        (clk_54),     //i 
    .tick_1us   (tick_1us),   //i 
                               
    .uart_rx    (uart_rx),    //i 
    .uart_tx    (uart_tx),    //o
                               
    .csr        (csr),        //SLV_UART

   // IMEM Write port, for live updates of CPU program
    .imem_we    (imem_we),    //o
    .imem_waddr (imem_waddr), //o[31:2]
    .imem_wdat  (imem_wdat)   //o[31:0]
  );

//=================================
// Custom ADC Interface
//=================================
  adc #(
   `ifdef SIM_ONLY
    .SETTLE_SCLK (6+9)
   `else
    .SETTLE_SCLK (6+1324)
   `endif                      
  )
  u_adc (
    .tick_1us   (tick_1us),   //i 

    .bus        (bus_adc),    //MST              
    .csr        (csr),        //SLV_ADC

   // to/from off-chip ADC 
    .adc_ssr    (adc_ssr   ), //o[2:1] 
    .adc_inject (adc_inject), //o[2:1] 
    .adc_pwdn_n (adc_pwdn_n), //o[2:1]
    .adc_start  (adc_start ), //o[2:1]
    .adc_clk    (adc_clk   ), //o[2:1]
    .adc_dout_p (adc_dout_p), //i[2:1]
    .adc_dout_n (adc_dout_n)  //i[2:1] 
  );

//=================================
// Custom DAC Interface
//=================================
  dac u_dac (
    .arst_n     (srst54_n),   //i 
    .clk_54     (clk_54),     //i 
    .strobe_27  (strobe_27),  //i 

    .csr        (csr),        //SLV_DAC

   // to off-chip DAC
    .dac_clk_out(dac_clk_out),//o
    .dac_pwd    (dac_pwd),    //o
    .dac_data   (dac_data)    //o[9:0]
  );

//=================================
// Misc
//=================================
   assign led_n[3:2]     = csr.gpo.led_off;
   assign csr.gpi.key_on = key1_clean;
   
endmodule: top

/*
-----------------------------------------------------------------------------
Version History:
-----------------------------------------------------------------------------
 2024/1/4 JI: initial creation    
 2024/3/1 JI: added ADC and LED registers
 2024/4/8 JI: added ADC DMA
*/
