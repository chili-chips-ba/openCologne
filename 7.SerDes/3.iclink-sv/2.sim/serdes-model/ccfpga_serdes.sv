// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne-PCIE * NLnet-sponsored open-source implementation
//--------------------------------------------------------------------------
//                   Copyright (C) 2026 Chili.CHIPS
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
//--------------------------------------------------------------------------
// Description:
//   Open-source behavioural model of the GateMate SerDes hard macro, for
//   simulation only (hardware instantiates CC_SERDES). Module name, ports,
//   parameters and defaults are those of the CologneChip simulation model,
//   so it is a drop-in replacement; see README.md for what is modelled.
//
//   A behavioural model, not RTL: it keeps `timescale and # delays (the
//   serializer, sampler, CDR, clocks and PLL lock run in real time), and
//   its state gets its time-0 value from initial blocks. Those processes
//   stay plain always: always_ff/always_comb allow neither delays nor a
//   second writer. The 8b/10b codec and the PRBS are ccfpga_serdes_pkg.
//==========================================================================

`timescale 1ns / 100fs

module ccfpga_serdes
  import ccfpga_serdes_pkg::*;
#(
    parameter int TX_BUFFER_ADDR_WIDTH = 5,

    parameter int          RX_WAIT_CDR_LOCK         = 1,
    parameter int          RX_RESETDONE_GATE        = 0,
    parameter logic [ 4:0] RX_RESET_TIMER_PRESC     = 0,
    parameter logic [ 4:0] RX_PMA_RESET_TIME        = 3,
    parameter logic [ 4:0] RX_EQA_RESET_TIME        = 3,
    parameter logic [ 4:0] RX_CDR_RESET_TIME        = 3,
    parameter logic [ 4:0] RX_PCS_RESET_TIME        = 3,
    parameter logic [ 4:0] RX_BUF_RESET_TIME        = 3,
    parameter int          RX_CALIB_OVR             = 0,
    parameter logic [ 3:0] RX_CALIB_VAL             = 0,
    parameter logic [ 2:0] RX_RTERM_VCMSEL          = 4,
    parameter int          RX_RTERM_PD              = 0,
    parameter logic [ 7:0] RX_EQA_CKP_HF            = 8'b101_00011,
    parameter logic [ 7:0] RX_EQA_CKP_LF            = 8'b101_00011,
    parameter logic [15:0] RX_EQA_CONFIG            = 16'h01C0,
    parameter logic [ 7:0] RX_EQA_CKP_OFFSET        = 8'b000_00001,
    parameter int          RX_EN_EQA                = 0,
    parameter logic [ 3:0] RX_EQA_LOCK_CFG          = 0,
    parameter int          RX_TH_MON1_OVR           = 0,
    parameter int          RX_TH_MON2_OVR           = 0,
    parameter int          RX_TAPW_OVR              = 0,
    parameter int          RX_AFE_OFFSET_OVR        = 0,
    parameter logic [ 4:0] RX_TH_MON1               = 8,
    parameter logic [ 4:0] RX_TH_MON2               = 8,
    parameter logic [ 4:0] RX_TAPW                  = 8,
    parameter logic [ 4:0] RX_AFE_OFFSET            = 8,
    parameter logic [ 2:0] RX_AFE_VCMSEL            = 4,
    parameter logic [ 3:0] RX_AFE_GAIN              = 8,
    parameter logic [ 4:0] RX_AFE_PEAK              = 16,
    parameter logic [ 7:0] RX_CDR_CKP               = {3'b101, 5'b01111},
    parameter logic [ 7:0] RX_CDR_CKI               = {3'b000, 5'b00000},
    parameter logic [14:0] RX_CDR_LOCK_CFG          = 15'b000_1000_1101_0101,
    parameter logic [ 1:0] RX_CDR_SET_ACC_CONFIG    = 2'b00,
    parameter int          RX_CDR_FORCE_LOCK        = 0,
    parameter logic [14:0] RX_CDR_FREQ_ACC          = 15'h0,
    parameter logic [15:0] RX_CDR_PHASE_ACC         = 16'h0,
    parameter logic [ 9:0] ALIGN_MCOMMA_VALUE       = 10'b1010000011,
    parameter logic [ 9:0] ALIGN_PCOMMA_VALUE       = 10'b0101111100,
    parameter logic [ 9:0] ALIGN_COMMA_ENABLE       = 10'b1111111111,
    parameter logic [ 1:0] ALIGN_COMMA_WORD         = 2'b00,
    parameter logic [ 1:0] RX_SLIDE_MODE            = 0,
    parameter logic [14:0] RX_EYE_MEAS_CFG          = 0,
    parameter logic [ 5:0] RX_MON_PH_OFFSET         = 0,
    parameter logic [ 3:0] RX_EI_BIAS               = 4,
    parameter logic [ 3:0] RX_EI_BW_SEL             = 4,
    parameter int          RX_BUF_BYPASS            = 0,
    parameter int          RX_CLKCOR_USE            = 0,
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_0        = 10'b0111110111,
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_1        = 10'b0111110111,
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_2        = 10'b0111110111,
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_3        = 10'b0111110111,
    parameter logic [ 5:0] RX_CLKCOR_MIN_LAT        = 32,
    parameter logic [ 5:0] RX_CLKCOR_MAX_LAT        = 39,
    parameter logic [ 1:0] RX_DATAPATH_SEL          = 3,
    parameter logic [ 5:0] RX_DBG_SRAM_DELAY        = 6'b00_01_01,
    parameter logic [ 3:0] RX_DBG_SEL               = 0,
    parameter int          RX_DBG_MODE              = 0,
    parameter logic [ 4:0] TX_SEL_PRE               = 0,
    parameter logic [ 4:0] TX_SEL_POST              = 0,
    parameter logic [ 2:0] TX_TAIL_CASCODE          = 3'b100,
    parameter logic [ 4:0] TX_BRANCH_EN_PRE         = 0,
    parameter logic [ 5:0] TX_BRANCH_EN_MAIN        = 6'b111111,
    parameter logic [ 4:0] TX_BRANCH_EN_POST        = 0,
    parameter logic [ 6:0] TX_DC_ENABLE             = 63,
    parameter logic [ 4:0] TX_AMP                   = 15,
    parameter logic [ 4:0] TX_DC_OFFSET             = 0,
    parameter logic [ 4:0] TX_CM_RAISE              = 0,
    parameter logic [ 4:0] TX_CM_THRESHOLD_0        = 14,
    parameter logic [ 4:0] TX_CM_THRESHOLD_1        = 16,
    parameter int          TX_CALIB_OVR             = 0,
    parameter logic [ 3:0] TX_CALIB_VAL             = 0,
    parameter int          TX_CM_REG_EN             = 1,
    parameter logic [ 7:0] TX_CM_REG_KI             = 8'h80,
    parameter logic [ 4:0] TX_PMA_RESET_TIME        = 3,
    parameter logic [ 4:0] TX_PCS_RESET_TIME        = 3,
    parameter int          TX_PMA_LOOPBACK          = 0,
    parameter logic [ 1:0] TX_DATAPATH_SEL          = 3,
    parameter int          PLL_EN_ADPLL_CTRL        = 0,
    parameter int          PLL_CONFIG_SEL           = 0,
    parameter int          PLL_SET_OP_LOCK          = 1,
    parameter int          PLL_ENFORCE_LOCK         = 0,
    parameter int          PLL_DISABLE_LOCK         = 0,
    parameter int          PLL_LOCK_WINDOW          = 1,
    parameter int          PLL_FAST_LOCK            = 1,
    parameter int          PLL_SYNC_BYPASS          = 0,
    parameter int          PLL_PFD_SELECT           = 0,
    parameter int          PLL_REF_BYPASS           = 0,
    parameter int          PLL_REF_SEL              = 0,
    parameter int          PLL_REF_RTERM            = 1,
    parameter logic [ 5:0] PLL_FCNTRL               = 58,
    parameter logic [ 5:0] PLL_MAIN_DIVSEL          = 27,
    parameter logic [ 1:0] PLL_OUT_DIVSEL           = 0,
    parameter logic [ 4:0] PLL_CI                   = 1,
    parameter logic [ 9:0] PLL_CP                   = 60,
    parameter logic [ 3:0] PLL_AO                   = 0,
    parameter logic [ 2:0] PLL_SCAP                 = 0,
    parameter int          PLL_SCAP_AUTO_CAL        = 1,
    parameter logic [ 1:0] PLL_FILTER_SHIFT         = 2,
    parameter logic [ 2:0] PLL_SAR_LIMIT            = 2,
    parameter logic [10:0] PLL_FT                   = 512,
    parameter int          PLL_OPEN_LOOP            = 0,
    parameter logic [ 2:0] PLL_BISC_MODE            = 3'b100,
    parameter logic [ 3:0] PLL_BISC_TIMER_MAX       = 15,
    parameter logic [ 4:0] PLL_BISC_CP_MIN          = 4,
    parameter logic [ 4:0] PLL_BISC_CP_MAX          = 18,
    parameter logic [ 4:0] PLL_BISC_CP_START        = 12,
    parameter int          PLL_BISC_OPT_DET_IND     = 0,
    parameter int          PLL_BISC_PFD_SEL         = 0,
    parameter int          PLL_BISC_DLY_DIR         = 0,
    parameter int          PLL_BISC_CAL_SIGN        = 0,
    parameter int          PLL_BISC_CAL_AUTO        = 1,
    parameter logic [ 4:0] PLL_BISC_DLY_PFD_MON_REF = 0,
    parameter logic [ 4:0] PLL_BISC_DLY_PFD_MON_DIV = 2,
    parameter logic [ 2:0] PLL_BISC_COR_DLY         = 1,

    // Additions to the vendor parameter list (README.md, "Parameters")
    parameter real BHV_PLL_LOCK_TIME_NS  = 500.0,
    parameter real BHV_REF_CLK_MHZ       = 0.0,
    parameter int  BHV_RX_PRESENT        = 1,
    parameter real BHV_RX_DETECT_TIME_NS = 120.0,
    parameter real BHV_CDR_KP            = 0.125,
    parameter int  BHV_CDR_LOCK_EDGES    = 32,
    parameter int  BHV_VERBOSE           = 0,
    parameter int  BHV_RX_PIPE_STAGES    = 9,
    parameter real BHV_RX_TCO_NS         = 0.1
) (
    input  logic        clk_ref_i,
    input  logic        clk_reg_i,
    input  logic        clk_cfg_i,
    input  logic        clk_core_tx_i,
    input  logic        clk_core_rx_i,
    output logic        clk_core_rx_o,
    input  logic        reset_n_i,
    input  logic        reset_reg_n_i,
    input  logic        reset_core_tx_n_i,
    input  logic        reset_core_rx_n_i,
    input  logic        testmode_i,
    input  logic        scan_enable_i,
    input  logic [ 6:0] scan_in_i,
    output logic [ 6:0] scan_out_o,
    input  logic [ 2:0] loopback_i,
    input  logic        pll_reset_i,
    output logic        clk_core_pll_o,
    output logic        reset_core_pll_n_o,
    output logic        refclk_sel_o,
    output logic        refclk_rterm_o,
    input  logic        RX_SERIO_P_B,
    input  logic        RX_SERIO_N_B,
    output logic        TX_SERIO_P_B,
    output logic        TX_SERIO_N_B,
    input  logic        regfile_we_i,
    input  logic        regfile_en_i,
    input  logic [ 7:0] regfile_addr_i,
    input  logic [15:0] regfile_mask_i,
    input  logic [15:0] regfile_di_i,
    output logic [15:0] regfile_do_o,
    output logic        regfile_rdy_o,
    input  logic        cfg_en_i,
    input  logic        reset_cfg_i,
    input  logic [15:0] cfgfile_di_i,
    input  logic        cfgfile_valid_i,
    input  logic [ 7:0] cfgfile_addr_i,
    input  logic        tx_reset_i,
    input  logic        tx_pcs_reset_i,
    input  logic        tx_pma_reset_i,
    input  logic        tx_elec_idle_i,
    input  logic        tx_detect_rx_i,
    input  logic [ 2:0] tx_prbs_sel_i,
    input  logic        tx_prbs_force_err_i,
    input  logic        tx_powerdown_n_i,
    input  logic [63:0] tx_data_i,
    input  logic [ 7:0] tx_char_is_k_i,
    input  logic        tx_polarity_i,
    input  logic        tx_8b10b_en_i,
    input  logic [ 7:0] tx_8b10b_bypass_i,
    input  logic [ 7:0] tx_char_dispmode_i,
    input  logic [ 7:0] tx_char_dispval_i,
    output logic        tx_buf_err_o,
    output logic        tx_resetdone_o,
    output logic        rx_detect_done_o,
    output logic        rx_present_o,
    output logic        TERM_SERIO_O,
    input  logic        rx_reset_i,
    input  logic        rx_pma_reset_i,
    input  logic        rx_eqa_reset_i,
    input  logic        rx_cdr_reset_i,
    input  logic        rx_pcs_reset_i,
    input  logic        rx_buf_reset_i,
    input  logic [ 2:0] rx_prbs_sel_i,
    input  logic        rx_prbs_cnt_reset_i,
    input  logic        rx_powerdown_n_i,
    input  logic        rx_en_ei_detector_i,
    input  logic        rx_comma_detect_en_i,
    input  logic        rx_slide_i,
    input  logic        rx_polarity_i,
    input  logic        rx_8b10b_en_i,
    input  logic [ 7:0] rx_8b10b_bypass_i,
    input  logic        rx_mcomma_align_i,
    input  logic        rx_pcomma_align_i,
    output logic        rx_prbs_err_o,
    output logic [63:0] rx_data_o,
    output logic [ 7:0] rx_char_is_k_o,
    output logic [ 7:0] rx_char_is_comma_o,
    output logic [ 7:0] rx_not_in_table_o,
    output logic [ 7:0] rx_disp_err_o,
    output logic        rx_buf_err_o,
    output logic        rx_byte_is_aligned_o,
    output logic        rx_byte_realign_o,
    output logic        rx_resetdone_o,
    output logic        rx_ei_en_o
);

  //=========================================================================
  // 8b/10b decode table, built at time 0 from the package decoder
  //=========================================================================
  logic [9:0] dec_lut[1024];  // {valid, k, data}
  logic [1:0] dec_rd [1024];  // dec_rd_class()

  initial begin : build_dec_lut
    for (int s = 0; s < 1024; s++) begin
      dec_lut[s] = dec8b10b(s[9:0]);
      dec_rd[s]  = dec_rd_class(s[9:0]);
    end
  end

  //=========================================================================
  // Register file and config file
  //=========================================================================
  localparam logic [7:0] PLL_CFG0_ADDR = 8'h50;
  localparam logic [7:0] PLL_CFG1_ADDR = 8'h51;
  localparam logic [7:0] PLL_CFG5_ADDR = 8'h55;
  localparam logic [7:0] PLL_CFG6_ADDR = 8'h56;
  localparam logic [7:0] SERDES_CFG_ADDR = 8'h5C;

  // PLL_CFG0 / PLL_CFG1 after reset, from the parameters
  localparam logic [11:0] PLL_OP_RESET = {
    PLL_REF_RTERM[0],
    PLL_REF_SEL[0],
    PLL_REF_BYPASS[0],
    PLL_PFD_SELECT[0],
    PLL_SYNC_BYPASS[0],
    PLL_FAST_LOCK[0],
    PLL_LOCK_WINDOW[0],
    PLL_DISABLE_LOCK[0],
    PLL_ENFORCE_LOCK[0],
    PLL_SET_OP_LOCK[0],
    PLL_CONFIG_SEL[0],
    PLL_EN_ADPLL_CTRL[0]
  };
  localparam logic [13:0] PLL_DIV_RESET = {PLL_OUT_DIVSEL, PLL_MAIN_DIVSEL, PLL_FCNTRL};

  localparam logic [15:0] PLL_STATUS_LO = 16'h0001;
  localparam logic [15:0] PLL_STATUS_HI = 16'h0000;

  logic [15:0] rf[256];

  logic        serdes_en;
  logic        rx_serdes_auto_init;
  logic        serdes_testmode;

  logic [11:0] pll_op;
  logic [13:0] pll_div;

  logic        regfile_rdy_r;
  logic [15:0] regfile_do_r;
  logic        regfile_en_d;

  logic [ 7:0] rf_addr;
  logic [15:0] rf_di;
  logic [15:0] rf_mask;
  logic        cfg_write;
  logic        cfg_rst;
  logic        rf_write;
  logic        rf_read;

  assign rf_addr   = cfg_en_i ? cfgfile_addr_i : regfile_addr_i;
  assign rf_di     = cfg_en_i ? cfgfile_di_i : regfile_di_i;
  assign rf_mask   = cfg_en_i ? 16'hFFFF : regfile_mask_i;
  assign cfg_write = cfg_en_i & cfgfile_valid_i;
  assign cfg_rst   = cfg_en_i & reset_cfg_i;
  assign rf_write  = (regfile_en_i & ~regfile_en_d & ~cfg_en_i & regfile_we_i) | cfg_write;
  assign rf_read   = regfile_en_i & ~regfile_en_d & ~cfg_en_i & ~regfile_we_i;

  assign regfile_do_o   = regfile_do_r;
  assign regfile_rdy_o  = regfile_rdy_r;

  assign refclk_sel_o   = pll_op[10];
  assign refclk_rterm_o = pll_op[11];

  task automatic rf_reset();
    for (int i = 0; i < 256; i++) begin
      rf[i] <= 16'h0;
    end
    serdes_en           <= 1'b0;
    rx_serdes_auto_init <= 1'b0;
    serdes_testmode     <= 1'b0;
    pll_op              <= PLL_OP_RESET;
    pll_div             <= PLL_DIV_RESET;
    rf[PLL_CFG0_ADDR]   <= {4'h0, PLL_OP_RESET};
    rf[PLL_CFG1_ADDR]   <= {2'h0, PLL_DIV_RESET};
    rf[SERDES_CFG_ADDR] <= 16'h0;
  endtask

  always_ff @(posedge clk_reg_i or negedge reset_reg_n_i) begin
    if (!reset_reg_n_i) begin
      rf_reset();
      regfile_en_d  <= 1'b0;
      regfile_rdy_r <= 1'b0;
      regfile_do_r  <= 16'h0;
    end
    else begin
      regfile_en_d  <= regfile_en_i;
      regfile_rdy_r <= 1'b0;

      if (cfg_rst) begin
        rf_reset();
      end
      else begin
        if (rf_write) begin
          rf[rf_addr] <= (rf[rf_addr] & ~rf_mask) | (rf_di & rf_mask);

          unique0 case (rf_addr)
            SERDES_CFG_ADDR: begin
              if (cfg_write) begin
                serdes_en           <= rf_di[0];
                rx_serdes_auto_init <= rf_di[1];
                serdes_testmode     <= rf_di[2];
              end
            end
            PLL_CFG0_ADDR: begin
              if (rf_mask[0]) begin
                pll_op[0] <= rf_di[0];
              end
              if (!rf_di[0] || cfg_write) begin
                pll_op[9:1] <= (pll_op[9:1] & ~rf_mask[9:1]) | (rf_di[9:1] & rf_mask[9:1]);
              end
              if (rf_mask[10]) begin
                pll_op[10] <= rf_di[10];
              end
              if (rf_mask[11]) begin
                pll_op[11] <= rf_di[11];
              end
            end
            PLL_CFG1_ADDR: begin
              if (!pll_op[0] || cfg_write) begin
                pll_div <= (pll_div & ~rf_mask[13:0]) | (rf_di[13:0] & rf_mask[13:0]);
              end
            end
          endcase
          regfile_rdy_r <= ~cfg_en_i;
        end
        else if (rf_read) begin
          regfile_do_r <= rf[rf_addr];
          unique0 case (rf_addr)
            PLL_CFG0_ADDR: begin regfile_do_r <= {4'h0, pll_op}; end
            PLL_CFG1_ADDR: begin regfile_do_r <= {2'h0, pll_div}; end
            PLL_CFG5_ADDR: begin regfile_do_r <= PLL_STATUS_LO; end
            PLL_CFG6_ADDR: begin regfile_do_r <= PLL_STATUS_HI; end
            SERDES_CFG_ADDR: begin
              regfile_do_r <= {13'h0, serdes_testmode, rx_serdes_auto_init, serdes_en};
            end
          endcase
          regfile_rdy_r <= 1'b1;
        end
      end
    end
  end

  //=========================================================================
  // PLL: line rate f_ref * N1*N2*N3*2 / M3, core clock = line rate / 80
  //=========================================================================
  logic [5:0] cfg_main_divsel;
  logic [1:0] cfg_out_divsel;

  assign cfg_main_divsel = pll_div[11:6];
  assign cfg_out_divsel  = pll_div[13:12];

  integer n1, n2, n3, m3;

  assign n1 = (cfg_main_divsel[2] == 1'b0) ? 1 : 2;
  assign n2 = (cfg_main_divsel[1:0] == 2'b00) ? 3 :
              (cfg_main_divsel[1:0] == 2'b01) ? 2 :
              (cfg_main_divsel[1:0] == 2'b10) ? 4 : 5;
  assign n3 = (cfg_main_divsel[4:3] == 2'b00) ? 3 :
              (cfg_main_divsel[4:3] == 2'b10) ? 4 :
              (cfg_main_divsel[4:3] == 2'b11) ? 5 : 1;
  assign m3 = (cfg_out_divsel == 2'b01) ? 2 : (cfg_out_divsel == 2'b11) ? 4 : 1;

  real  ref_period;
  real  ref_last_edge;
  real  ui;
  real  core_period;

  logic ref_seen;

  initial begin
    ref_period    = (BHV_REF_CLK_MHZ > 0.0) ? (1000.0 / BHV_REF_CLK_MHZ) : 10.0;
    ref_last_edge = -1.0;
    ref_seen      = (BHV_REF_CLK_MHZ > 0.0);
  end

  // The reference period is measured unless BHV_REF_CLK_MHZ gives it
  always @(posedge clk_ref_i) begin
    if (BHV_REF_CLK_MHZ <= 0.0) begin
      if (ref_last_edge >= 0.0) begin
        ref_period = $realtime - ref_last_edge;
        ref_seen   = 1'b1;
      end
      ref_last_edge = $realtime;
    end
  end

  // 0.4 ns / 32 ns (Gen1) until the reference period is known; ref_seen never
  // clears and ref_period is only ever set positive, so nothing is latched
  always_comb begin
    if (ref_seen && (ref_period > 0.0)) begin
      ui = (ref_period * m3) / (1.0 * n1 * n2 * n3 * 2);
    end
    else begin
      ui = 0.4;
    end
    core_period = ui * 80.0;
  end

  logic pll_enabled;
  logic pll_locked;
  logic clk_core_pll_r;

  assign pll_enabled        = reset_n_i & ~pll_reset_i & serdes_en & pll_op[0];

  assign clk_core_pll_o     = clk_core_pll_r;
  assign reset_core_pll_n_o = pll_locked & reset_n_i;

  initial begin
    pll_locked     = 1'b0;
    clk_core_pll_r = 1'b0;
  end

  always @(pll_enabled) begin : pll_lock_seq
    if (!pll_enabled) begin
      pll_locked = 1'b0;
    end
    else begin
      pll_locked = 1'b0;
      fork
        begin : lock_wait
          #(BHV_PLL_LOCK_TIME_NS);
          if (pll_enabled) begin
            pll_locked = 1'b1;
            if (BHV_VERBOSE) begin
              $display("[%0t] %m: PLL locked, line rate %.3f Gb/s, core clk %.3f MHz", $time,
                       1.0 / ui, 1000.0 / core_period);
            end
          end
        end
        begin : lock_abort
          @(pll_enabled);
        end
      join_any
      disable fork;
    end
  end

  always begin : core_clk_gen
    if (pll_locked && (core_period > 0.0)) begin
      #(core_period / 2.0);
      clk_core_pll_r = ~clk_core_pll_r;
    end
    else begin
      clk_core_pll_r = 1'b0;
      @(pll_locked);
    end
  end

  //=========================================================================
  // Resets and reset-done
  //=========================================================================
  localparam int RST_PRESC = (1 << RX_RESET_TIMER_PRESC);

  logic tx_core_rst_n;
  logic rx_core_rst_n;
  logic tx_pcs_rst_n;
  logic tx_pma_rst_n;
  logic rx_pcs_rst_n;
  logic rx_pma_rst_n;
  logic rx_cdr_rst_n;
  logic rx_buf_rst_n;

  assign tx_core_rst_n = reset_core_pll_n_o & reset_core_tx_n_i & tx_powerdown_n_i & ~tx_reset_i
                         & serdes_en;
  assign rx_core_rst_n = reset_core_pll_n_o & reset_core_rx_n_i & rx_powerdown_n_i & ~rx_reset_i
                         & serdes_en;

  assign tx_pcs_rst_n  = tx_core_rst_n & ~tx_pcs_reset_i;
  assign tx_pma_rst_n  = tx_core_rst_n & ~tx_pma_reset_i;

  assign rx_pcs_rst_n  = rx_core_rst_n & ~rx_pcs_reset_i;
  assign rx_pma_rst_n  = rx_core_rst_n & ~rx_pma_reset_i;
  assign rx_cdr_rst_n  = rx_core_rst_n & ~rx_cdr_reset_i;
  assign rx_buf_rst_n  = rx_core_rst_n & ~rx_buf_reset_i;

  logic        tx_resetdone_r;
  logic [15:0] tx_rst_cnt;

  assign tx_resetdone_o = tx_resetdone_r;

  initial begin
    tx_resetdone_r = 1'b0;
    tx_rst_cnt     = 16'h0;
  end

  always @(posedge clk_core_pll_r or negedge tx_core_rst_n) begin
    if (!tx_core_rst_n) begin
      tx_resetdone_r <= 1'b0;
      tx_rst_cnt     <= 16'h0;
    end
    else if (!tx_pma_rst_n || !tx_pcs_rst_n) begin
      tx_resetdone_r <= 1'b0;
      tx_rst_cnt     <= 16'h0;
    end
    else if (tx_rst_cnt < ((TX_PMA_RESET_TIME + TX_PCS_RESET_TIME + 2) * RST_PRESC)) begin
      tx_rst_cnt <= tx_rst_cnt + 16'd1;
    end
    else begin
      tx_resetdone_r <= 1'b1;
    end
  end

  logic        rx_cdr_locked;

  logic        rx_resetdone_r;
  logic [15:0] rx_rst_cnt;
  logic        rx_rst_gate;

  assign rx_resetdone_o = rx_resetdone_r;

  initial begin
    rx_resetdone_r = 1'b0;
    rx_rst_cnt     = 16'h0;
  end

  assign rx_rst_gate = (RX_WAIT_CDR_LOCK != 0) ? rx_cdr_locked : 1'b1;

  always @(posedge clk_core_pll_r or negedge rx_core_rst_n) begin
    if (!rx_core_rst_n) begin
      rx_resetdone_r <= 1'b0;
      rx_rst_cnt     <= 16'h0;
    end
    else if (!rx_pma_rst_n || !rx_pcs_rst_n || !rx_cdr_rst_n || !rx_buf_rst_n) begin
      rx_resetdone_r <= 1'b0;
      rx_rst_cnt     <= 16'h0;
    end
    else if (rx_rst_cnt < ((RX_PMA_RESET_TIME + RX_EQA_RESET_TIME + RX_CDR_RESET_TIME
                            + RX_PCS_RESET_TIME + RX_BUF_RESET_TIME + 5) * RST_PRESC)) begin
      rx_rst_cnt <= rx_rst_cnt + 16'd1;
    end
    else if (rx_rst_gate) begin
      rx_resetdone_r <= 1'b1;
    end
  end

  //=========================================================================
  // TX: 8b/10b encoder and elastic buffer
  //=========================================================================
  localparam int TX_BYTES = (TX_DATAPATH_SEL == 2'b00) ? 2 : (TX_DATAPATH_SEL == 2'b01) ? 4 : 8;
  localparam int RX_BYTES = (RX_DATAPATH_SEL == 2'b00) ? 2 : (RX_DATAPATH_SEL == 2'b01) ? 4 : 8;
  localparam int TX_WORD_BITS = TX_BYTES * 10;

  logic pcs_loopback;
  logic pma_loopback;

  assign pcs_loopback = loopback_i[1] | loopback_i[2];
  assign pma_loopback = loopback_i[0] | (TX_PMA_LOOPBACK != 0);

  logic [30:0] tx_prbs_lfsr;
  logic        tx_prbs_bit;

  logic        tx_rd;

  logic [79:0] tx_fifo     [16];
  logic [ 4:0] tx_wptr;
  logic [ 4:0] tx_rptr;
  logic        tx_buf_err_r;
  logic [ 4:0] tx_fifo_cnt;

  assign tx_fifo_cnt  = tx_wptr - tx_rptr;
  assign tx_buf_err_o = tx_buf_err_r;

  logic [10:0] tb_enc;
  logic [ 7:0] tb_byte;
  logic        tb_k;
  logic [79:0] tx_word_v;
  logic        tx_rd_v;

  logic [63:0] tx_src_data;
  logic [ 7:0] tx_src_k;

  assign tx_src_data = pcs_loopback ? rx_data_o : tx_data_i;
  assign tx_src_k    = pcs_loopback ? rx_char_is_k_o : tx_char_is_k_i;

  initial begin
    tx_rd        = 1'b0;
    tx_wptr      = 5'h0;
    tx_rptr      = 5'h0;
    tx_buf_err_r = 1'b0;
    tx_prbs_lfsr = 31'h7FFF_FFFF;
    tx_prbs_bit  = 1'b0;
    for (int i = 0; i < 16; i++) begin
      tx_fifo[i] = 80'h0;
    end
  end

  always @(posedge clk_core_tx_i or negedge tx_pcs_rst_n) begin
    if (!tx_pcs_rst_n) begin
      tx_rd        <= 1'b0;
      tx_wptr      <= 5'h0;
      tx_buf_err_r <= 1'b0;
    end
    else begin
      tx_buf_err_r <= 1'b0;
      tx_rd_v   = tx_rd;
      tx_word_v = 80'h0;

      for (int i = 0; i < 8; i++) begin
        if (i < TX_BYTES) begin
          tb_byte = tx_src_data[i*8+:8];
          tb_k    = tx_src_k[i];

          if (!tx_8b10b_en_i || tx_8b10b_bypass_i[i]) begin
            tx_word_v[i*10+:10] = {tx_char_dispval_i[i], tx_char_dispmode_i[i], tb_byte};
          end
          else begin
            if (tx_char_dispmode_i[i]) begin
              tx_rd_v = tx_char_dispval_i[i];
            end
            tb_enc              = enc8b10b(tb_byte, tb_k, tx_rd_v);
            tx_word_v[i*10+:10] = tb_enc[9:0];
            tx_rd_v             = tb_enc[10];
          end
        end
      end

      tx_rd <= tx_rd_v;

      if (tx_fifo_cnt < 5'd15) begin
        tx_fifo[tx_wptr[3:0]] <= tx_word_v;
        tx_wptr               <= tx_wptr + 5'd1;
      end
      else begin
        tx_buf_err_r <= 1'b1;
        if (BHV_VERBOSE) begin
          $display("[%0t] %m: TX elastic buffer overflow", $time);
        end
      end
    end
  end

  //=========================================================================
  // TX serializer, one bit per UI
  //=========================================================================
  logic [79:0] tx_shift;
  logic [ 6:0] tx_bit_idx;
  logic        tx_bit;
  logic        tx_ser_run;
  logic        tx_serio_p_r;
  logic        tx_serio_n_r;
  logic        tx_fifo_ready;

  assign tx_fifo_ready = (tx_fifo_cnt >= 5'd2);

  assign TX_SERIO_P_B  = tx_serio_p_r;
  assign TX_SERIO_N_B  = tx_serio_n_r;
  assign TERM_SERIO_O  = 1'b0;

  initial begin
    tx_shift     = 80'h0;
    tx_bit_idx   = 7'd0;
    tx_bit       = 1'b0;
    tx_serio_p_r = 1'b0;
    tx_serio_n_r = 1'b0;
  end

  always_comb begin
    tx_ser_run = pll_locked & tx_pma_rst_n & tx_resetdone_r;
  end

  always begin : tx_serializer
    if (tx_ser_run && (ui > 0.0)) begin
      #(ui);
      if (tx_bit_idx == 7'd0) begin
        if (tx_fifo_ready || (tx_fifo_cnt != 5'd0)) begin
          tx_shift = tx_fifo[tx_rptr[3:0]];
          tx_rptr  = tx_rptr + 5'd1;
        end
        else begin
          tx_buf_err_r = 1'b1;  // underflow: tx_shift is sent again
        end
      end

      if (tx_prbs_sel_i != 3'b000) begin
        tx_prbs_lfsr = prbs_next(tx_prbs_lfsr, tx_prbs_sel_i);
        tx_prbs_bit  = tx_prbs_lfsr[0] ^ tx_prbs_force_err_i;
        tx_bit       = tx_prbs_bit;
      end
      else begin
        tx_bit = tx_shift[tx_bit_idx];
      end

      tx_bit_idx = (tx_bit_idx == (TX_WORD_BITS - 1)) ? 7'd0 : tx_bit_idx + 7'd1;

      if (tx_elec_idle_i || !tx_powerdown_n_i) begin
        tx_serio_p_r = 1'b0;
        tx_serio_n_r = 1'b0;
      end
      else begin
        tx_serio_p_r = tx_bit ^ tx_polarity_i;
        tx_serio_n_r = ~(tx_bit ^ tx_polarity_i);
      end
    end
    else begin
      tx_bit_idx   = 7'd0;
      tx_serio_p_r = 1'b0;
      tx_serio_n_r = 1'b0;
      @(tx_ser_run or pll_locked);
    end
  end

  //=========================================================================
  // RX: electrical-idle detector
  //=========================================================================
  logic rx_pad_p;
  logic rx_pad_n;
  logic rx_serial_bit;

  assign rx_pad_p      = pma_loopback ? tx_serio_p_r : RX_SERIO_P_B;
  assign rx_pad_n      = pma_loopback ? tx_serio_n_r : RX_SERIO_N_B;
  assign rx_serial_bit = rx_pad_p ^ rx_polarity_i;

  localparam real EI_WINDOW_UI = 20.0;

  logic rx_ei_filt;
  real  rx_ei_deadline;

  assign rx_ei_en_o = rx_en_ei_detector_i & rx_ei_filt;

  initial begin
    rx_ei_filt     = 1'b1;
    rx_ei_deadline = 0.0;
  end

  always @(rx_pad_p or rx_pad_n) begin
    rx_ei_filt     = 1'b0;
    rx_ei_deadline = $realtime + (EI_WINDOW_UI * ui);
  end

  always begin : ei_watchdog
    if (!rx_ei_filt) begin
      if ($realtime >= rx_ei_deadline) begin
        rx_ei_filt = 1'b1;
      end
      else begin
        #(rx_ei_deadline - $realtime);
      end
    end
    else begin
      @(rx_pad_p or rx_pad_n);
    end
  end

  //=========================================================================
  // RX: CDR phase detector
  //=========================================================================
  real    rx_last_sample_t;
  real    rx_phase_adj;
  real    rx_err;  // last phase error, for the waveform
  integer rx_lock_cnt;
  logic   rx_cdr_locked_r;
  logic   rx_sampler_run;

  assign rx_cdr_locked = rx_cdr_locked_r | (RX_CDR_FORCE_LOCK != 0);

  initial begin
    rx_last_sample_t = 0.0;
    rx_phase_adj     = 0.0;
    rx_err           = 0.0;
    rx_lock_cnt      = 0;
    rx_cdr_locked_r  = 1'b0;
  end

  always_comb begin
    rx_sampler_run = pll_locked & rx_pma_rst_n & rx_cdr_rst_n & ~rx_ei_filt;
  end

  always @(rx_pad_p or rx_pad_n) begin : cdr_phase_detector
    real edge_t, ideal_t, e;
    if (rx_sampler_run && (ui > 0.0)) begin
      edge_t  = $realtime;
      ideal_t = rx_last_sample_t + (ui / 2.0);
      e       = edge_t - ideal_t;
      while (e > ui / 2.0) begin
        e = e - ui;
      end
      while (e <= -ui / 2.0) begin
        e = e + ui;
      end

      rx_err       = e;
      rx_phase_adj = rx_phase_adj + e * BHV_CDR_KP;

      if ((e < ui / 4.0) && (e > -ui / 4.0)) begin
        if (rx_lock_cnt < BHV_CDR_LOCK_EDGES) begin
          rx_lock_cnt = rx_lock_cnt + 1;
        end
        else if (!rx_cdr_locked_r) begin
          rx_cdr_locked_r = 1'b1;
          if (BHV_VERBOSE) begin
            $display("[%0t] %m: RX CDR locked", $time);
          end
        end
      end
      else begin
        rx_lock_cnt = 0;
      end
    end
  end

  always @(negedge rx_sampler_run) begin
    rx_cdr_locked_r = 1'b0;
    rx_lock_cnt     = 0;
    rx_phase_adj    = 0.0;
  end

  //=========================================================================
  // RX: sampler, comma alignment, deserializer and PRBS checker
  //=========================================================================
  logic   [ 9:0] rx_shift;
  logic   [ 6:0] rx_bit_cnt;
  logic   [ 3:0] rx_sym_cnt;
  logic   [79:0] rx_word;
  logic          rx_word_valid;
  logic          rx_aligned_r;
  logic          rx_realign_r;

  logic          rx_slide_pending;
  logic          rx_realign_tog;
  logic          rx_realign_tog_d;

  integer        rx_bits_seen;

  initial begin
    rx_shift         = 10'h0;
    rx_bit_cnt       = 7'd0;
    rx_sym_cnt       = 4'd0;
    rx_word          = 80'h0;
    rx_word_valid    = 1'b0;
    rx_aligned_r     = 1'b0;
    rx_realign_r     = 1'b0;
    rx_realign_tog   = 1'b0;
    rx_realign_tog_d = 1'b0;
    rx_slide_pending = 1'b0;
    rx_bits_seen     = 0;
  end

  assign rx_byte_is_aligned_o = rx_aligned_r;
  assign rx_byte_realign_o    = rx_realign_r;

  localparam logic [9:0] COMMA_MASK = ALIGN_COMMA_ENABLE;

  logic comma_align_en;
  logic comma_align_en_d;

  assign comma_align_en = rx_comma_detect_en_i & (rx_mcomma_align_i | rx_pcomma_align_i);

  initial begin
    comma_align_en_d = 1'b0;
  end

  logic   [30:0] rx_prbs_lfsr;
  logic          rx_prbs_synced;
  logic          rx_prbs_err_r;
  logic   [15:0] rx_prbs_err_cnt;  // PRBS error count, for the waveform
  integer        rx_prbs_good;

  assign rx_prbs_err_o = rx_prbs_err_r;

  initial begin
    rx_prbs_lfsr    = 31'h7FFF_FFFF;
    rx_prbs_synced  = 1'b0;
    rx_prbs_err_r   = 1'b0;
    rx_prbs_err_cnt = 16'h0;
    rx_prbs_good    = 0;
  end

  always begin : rx_sampler
    logic [9:0] win;
    logic       matched;
    logic       comma_on_boundary;
    real        step;
    if (rx_sampler_run && (ui > 0.0)) begin
      step = ui + rx_phase_adj;
      if (step < (ui / 8.0)) begin
        step = ui / 8.0;
      end
      if (step > (ui * 2.0)) begin
        step = ui * 2.0;
      end
      rx_phase_adj = 0.0;
      #(step);
      rx_last_sample_t = $realtime;
      rx_bits_seen     = rx_bits_seen + 1;

      rx_shift         = {rx_serial_bit, rx_shift[9:1]};

      if (rx_prbs_sel_i != 3'b000) begin
        if (!rx_prbs_synced) begin
          rx_prbs_lfsr = {rx_prbs_lfsr[29:0], rx_serial_bit};
          rx_prbs_good = rx_prbs_good + 1;
          if (rx_prbs_good > 40) begin
            rx_prbs_synced = 1'b1;
          end
        end
        else begin
          rx_prbs_lfsr = prbs_next(rx_prbs_lfsr, rx_prbs_sel_i);
          if (rx_prbs_lfsr[0] !== rx_serial_bit) begin
            rx_prbs_err_r   = 1'b1;
            rx_prbs_err_cnt = rx_prbs_err_cnt + 16'd1;
            rx_prbs_lfsr    = {rx_prbs_lfsr[29:0], rx_serial_bit};
          end
          else begin
            rx_prbs_err_r = 1'b0;
          end
        end
        if (rx_prbs_cnt_reset_i) begin
          rx_prbs_err_cnt = 16'h0;
          rx_prbs_err_r   = 1'b0;
        end
      end

      if (comma_align_en && !comma_align_en_d) begin
        rx_aligned_r = 1'b0;
      end
      comma_align_en_d = comma_align_en;

      win              = rx_shift;
      matched          = 1'b0;
      if (comma_align_en && !rx_aligned_r && rx_bits_seen >= 10) begin
        if (rx_mcomma_align_i && ((win & COMMA_MASK) == (ALIGN_MCOMMA_VALUE & COMMA_MASK))) begin
          matched = 1'b1;
        end
        if (rx_pcomma_align_i && ((win & COMMA_MASK) == (ALIGN_PCOMMA_VALUE & COMMA_MASK))) begin
          matched = 1'b1;
        end
      end

      if (matched && !rx_aligned_r) begin
        comma_on_boundary = (rx_bit_cnt == 7'd9);
        if (!comma_on_boundary) begin
          rx_realign_tog = ~rx_realign_tog;
        end
        rx_bit_cnt   = 7'd9;
        rx_sym_cnt   = 4'd0;
        rx_aligned_r = 1'b1;
        if (BHV_VERBOSE) begin
          $display("[%0t] %m: RX byte alignment acquired", $time);
        end
      end

      if (rx_slide_i && !rx_slide_pending) begin
        rx_slide_pending = 1'b1;
        rx_bit_cnt       = (rx_bit_cnt == 7'd0) ? 7'd9 : rx_bit_cnt - 7'd1;
      end
      if (!rx_slide_i) begin
        rx_slide_pending = 1'b0;
      end

      if (rx_bit_cnt == 7'd9) begin
        rx_word[rx_sym_cnt*10+:10] = rx_shift;
        rx_bit_cnt                 = 7'd0;
        if (rx_sym_cnt == (RX_BYTES - 1)) begin
          rx_sym_cnt    = 4'd0;
          rx_word_valid = ~rx_word_valid;
        end
        else begin
          rx_sym_cnt = rx_sym_cnt + 4'd1;
        end
      end
      else begin
        rx_bit_cnt = rx_bit_cnt + 7'd1;
      end
    end
    else begin
      rx_bit_cnt   = 7'd0;
      rx_sym_cnt   = 4'd0;
      rx_bits_seen = 0;
      rx_aligned_r = 1'b0;
      @(rx_sampler_run or pll_locked);
    end
  end

  always @(posedge clk_core_rx_i or negedge rx_pcs_rst_n) begin
    if (!rx_pcs_rst_n) begin
      rx_realign_tog_d <= rx_realign_tog;
      rx_realign_r     <= 1'b0;
    end
    else begin
      rx_realign_tog_d <= rx_realign_tog;
      rx_realign_r     <= (rx_realign_tog ^ rx_realign_tog_d);
    end
  end

  //=========================================================================
  // RX: recovered core clock
  //=========================================================================
  logic clk_core_rx_r;

  assign clk_core_rx_o = clk_core_rx_r;

  initial begin
    clk_core_rx_r = 1'b0;
  end

  always begin : rx_rec_clk_gen
    if (pll_locked && (core_period > 0.0)) begin
      #(core_period / 2.0);
      clk_core_rx_r = ~clk_core_rx_r;
    end
    else begin
      clk_core_rx_r = 1'b0;
      @(pll_locked);
    end
  end

  //=========================================================================
  // RX: elastic buffer
  //=========================================================================
  logic [79:0] rx_fifo     [16];
  logic [ 4:0] rx_wptr;
  logic [ 4:0] rx_rptr;
  logic        rx_buf_err_r;
  logic        rx_run;
  logic [ 4:0] rx_fifo_cnt;

  assign rx_fifo_cnt  = rx_wptr - rx_rptr;
  assign rx_buf_err_o = rx_buf_err_r;

  initial begin
    rx_wptr      = 5'h0;
    rx_rptr      = 5'h0;
    rx_buf_err_r = 1'b0;
    rx_run       = 1'b0;
    for (int i = 0; i < 16; i++) begin
      rx_fifo[i] = 80'h0;
    end
  end

  always @(rx_word_valid) begin
    if (rx_buf_rst_n) begin
      if (rx_fifo_cnt < 5'd15) begin
        rx_fifo[rx_wptr[3:0]] = rx_word;
        rx_wptr               = rx_wptr + 5'd1;
      end
      else begin
        rx_buf_err_r = 1'b1;
        if (BHV_VERBOSE) begin
          $display("[%0t] %m: RX elastic buffer overflow", $time);
        end
      end
    end
  end

  always @(negedge rx_buf_rst_n) begin
    rx_wptr = 5'h0;
    rx_rptr = 5'h0;
    rx_run  = 1'b0;
  end

  //=========================================================================
  // RX: 8b/10b decoder
  //=========================================================================
  logic [63:0] rx_data_r;
  logic [ 7:0] rx_k_r;
  logic [ 7:0] rx_comma_r;
  logic [ 7:0] rx_nit_r;
  logic [ 7:0] rx_disp_r;
  logic        rx_rd;

  logic [79:0] rd_word;
  logic [ 9:0] rd_sym;
  logic [ 9:0] rd_ent;
  logic [ 1:0] rd_cls;
  logic        rd_rd_v;
  logic [63:0] rd_data_v;
  logic [ 7:0] rd_k_v;
  logic [ 7:0] rd_com_v;
  logic [ 7:0] rd_nit_v;
  logic [ 7:0] rd_disp_v;

  initial begin
    rx_data_r  = 64'h0;
    rx_k_r     = 8'h0;
    rx_comma_r = 8'h0;
    rx_nit_r   = 8'h0;
    rx_disp_r  = 8'h0;
    rx_rd      = 1'b0;
  end

  always @(posedge clk_core_rx_i or negedge rx_pcs_rst_n) begin
    if (!rx_pcs_rst_n) begin
      rx_data_r    <= 64'h0;
      rx_k_r       <= 8'h0;
      rx_comma_r   <= 8'h0;
      rx_nit_r     <= 8'h0;
      rx_disp_r    <= 8'h0;
      rx_rd        <= 1'b0;
      rx_rptr      <= 5'h0;
      rx_run       <= 1'b0;
      rx_buf_err_r <= 1'b0;
    end
    else begin
      if (!rx_run) begin
        if (rx_fifo_cnt >= 5'd2) begin
          rx_run <= 1'b1;
        end
      end
      else if (rx_fifo_cnt == 5'd0) begin
        rx_buf_err_r <= 1'b1;
        rx_run       <= 1'b0;
      end
      else begin
        rd_word = rx_fifo[rx_rptr[3:0]];
        rx_rptr <= rx_rptr + 5'd1;

        rd_rd_v   = rx_rd;
        rd_data_v = 64'h0;
        rd_k_v    = 8'h0;
        rd_com_v  = 8'h0;
        rd_nit_v  = 8'h0;
        rd_disp_v = 8'h0;

        for (int i = 0; i < 8; i++) begin
          if (i < RX_BYTES) begin
            rd_sym = rd_word[i*10+:10];

            if (!rx_8b10b_en_i || rx_8b10b_bypass_i[i]) begin
              rd_data_v[i*8+:8] = rd_sym[7:0];
            end
            else begin
              rd_ent            = dec_lut[rd_sym];
              rd_cls            = dec_rd[rd_sym];

              rd_data_v[i*8+:8] = rd_ent[7:0];
              rd_k_v[i]         = rd_ent[8];
              rd_nit_v[i]       = ~rd_ent[9];

              rd_com_v[i]       = rd_ent[8] &&
                                  ((rd_ent[7:0] == 8'h3C) ||
                                   (rd_ent[7:0] == 8'hBC) ||
                                   (rd_ent[7:0] == 8'hFC));

              if ((rd_cls == 2'd1 && rd_rd_v) || (rd_cls == 2'd2 && !rd_rd_v)) begin
                rd_disp_v[i] = 1'b1;
              end

              if (rd_cls == 2'd1) begin
                rd_rd_v = 1'b1;
              end
              else if (rd_cls == 2'd2) begin
                rd_rd_v = 1'b0;
              end
            end
          end
        end

        rx_data_r  <= rd_data_v;
        rx_k_r     <= rd_k_v;
        rx_comma_r <= rd_com_v;
        rx_nit_r   <= rd_nit_v;
        rx_disp_r  <= rd_disp_v;
        rx_rd      <= rd_rd_v;
      end
    end
  end

  //=========================================================================
  // RX: output pipeline, BHV_RX_PIPE_STAGES deep, to match the vendor latency
  //=========================================================================
  logic [63:0] pipe_data[16];
  logic [ 7:0] pipe_k   [16];
  logic [ 7:0] pipe_com [16];
  logic [ 7:0] pipe_nit [16];
  logic [ 7:0] pipe_disp[16];

  initial begin
    for (int i = 0; i < 16; i++) begin
      pipe_data[i] = 64'h0;
      pipe_k[i]    = 8'h0;
      pipe_com[i]  = 8'h0;
      pipe_nit[i]  = 8'h0;
      pipe_disp[i] = 8'h0;
    end
  end

  always @(posedge clk_core_rx_i or negedge rx_pcs_rst_n) begin
    if (!rx_pcs_rst_n) begin
      for (int i = 0; i < 16; i++) begin
        pipe_data[i] <= 64'h0;
        pipe_k[i]    <= 8'h0;
        pipe_com[i]  <= 8'h0;
        pipe_nit[i]  <= 8'h0;
        pipe_disp[i] <= 8'h0;
      end
    end
    else begin
      pipe_data[0] <= rx_data_r;
      pipe_k[0]    <= rx_k_r;
      pipe_com[0]  <= rx_comma_r;
      pipe_nit[0]  <= rx_nit_r;
      pipe_disp[0] <= rx_disp_r;
      for (int i = 1; i < 16; i++) begin
        pipe_data[i] <= pipe_data[i-1];
        pipe_k[i]    <= pipe_k[i-1];
        pipe_com[i]  <= pipe_com[i-1];
        pipe_nit[i]  <= pipe_nit[i-1];
        pipe_disp[i] <= pipe_disp[i-1];
      end
    end
  end

  assign #(BHV_RX_TCO_NS) rx_data_o = (BHV_RX_PIPE_STAGES == 0) ? rx_data_r
                                                                 : pipe_data[BHV_RX_PIPE_STAGES-1];
  assign #(BHV_RX_TCO_NS) rx_char_is_k_o = (BHV_RX_PIPE_STAGES == 0) ? rx_k_r
                                                                      : pipe_k[BHV_RX_PIPE_STAGES-1];
  assign #(BHV_RX_TCO_NS) rx_char_is_comma_o = (BHV_RX_PIPE_STAGES == 0) ? rx_comma_r
                                                          : pipe_com[BHV_RX_PIPE_STAGES-1];
  assign #(BHV_RX_TCO_NS) rx_not_in_table_o = (BHV_RX_PIPE_STAGES == 0) ? rx_nit_r
                                                         : pipe_nit[BHV_RX_PIPE_STAGES-1];
  assign #(BHV_RX_TCO_NS) rx_disp_err_o = (BHV_RX_PIPE_STAGES == 0) ? rx_disp_r
                                                     : pipe_disp[BHV_RX_PIPE_STAGES-1];

  //=========================================================================
  // Receiver detection
  //=========================================================================
  logic rx_detect_done_r;
  logic rx_present_r;

  assign rx_detect_done_o = rx_detect_done_r;
  assign rx_present_o     = rx_present_r;

  initial begin
    rx_detect_done_r = 1'b0;
    rx_present_r     = 1'b0;
  end

  always @(posedge tx_detect_rx_i) begin : rx_detect_seq
    rx_detect_done_r = 1'b0;
    #(BHV_RX_DETECT_TIME_NS);
    if (tx_detect_rx_i) begin
      rx_present_r     = (BHV_RX_PRESENT != 0);
      rx_detect_done_r = 1'b1;
      if (BHV_VERBOSE) begin
        $display("[%0t] %m: receiver detect done, present=%b", $time, rx_present_r);
      end
    end
  end

  always @(negedge tx_detect_rx_i) begin
    rx_detect_done_r = 1'b0;
    rx_present_r     = 1'b0;
  end

  assign scan_out_o = scan_enable_i ? scan_in_i : 7'h0;

endmodule

// -----------------------------------------------------------------------------
// Project:     openCologne-PCIE
// Description: NLnet-sponsored open-source implementation
// Version:     1.0
// Date:        April 2025
// -----------------------------------------------------------------------------
