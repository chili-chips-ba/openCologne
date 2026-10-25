// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
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
//   The SerDes BFM: an open-source behavioural model of the GateMate SerDes
//   hard macro, for simulation only (hardware instantiates CC_SERDES).
//   Module name, ports, parameters and defaults are those of the Cologne
//   Chip simulation model, so it is a drop-in replacement. Developed in
//   openCologne, then ported to openCologne-PCIE. What is modelled:
//   7.SerDes/README.md, Simulation.
//
//   It takes all 115 parameters of the vendor model. It acts on 34:
//   resets, comma alignment and slide, RX buffer and clock correction,
//   datapath widths, loopback, PLL rates and lock, the TX buffer. 9 more
//   only set a register value to read back (PLL_CFG0). The other 72 tune
//   what a digital model doesn't have: analog front end, equaliser, TX
//   driver, CDR and PLL loops and their calibration, eye monitor, debug.
//   A value the datasheet doesn't allow, or the BFM doesn't model, stops
//   the simulation (param_check), and so does a bad PLL_CFG1 or RX_BUF_CFG
//   written at run time, when it applies. ALIGN_COMMA_WORD is
//   RX_ALIGN_COMMA_WORD of CC_SERDES; the other names are the same.
//
//   The line: idle (electrical idle) is P = N for 20 UI; TX_ELEC_IDLE_I
//   drives both low. Idle stops the receiver, as a lost signal would;
//   RX_EN_EI_DETECTOR_I gates RX_EI_EN_O only. CDR_MODEL = NONE carries no
//   bits on the pins (ccfpga_serdes_pkg), so its latency leaves out any
//   wire delay the testbench puts on them. NONE BFMs tell each other who
//   they are in the first 10 ns (enumeration).
//
//   A behavioural model, not RTL: # delays (the serializer, sampler, CDR,
//   clocks and PLL lock run in real time), queues and events; processes
//   are plain always, no always_ff/always_comb. Assignments are blocking,
//   in reverse pipeline order. Non-blocking only where another process
//   samples the same clock edge: outputs to the fabric, and what crosses
//   between the RX buffer's two sides. The 8b/10b codec and the PRBS are
//   ccfpga_serdes_pkg.
//==========================================================================

`timescale 1ns / 100fs

module ccfpga_serdes
  import ccfpga_serdes_pkg::*;
#(
    parameter int TX_BUFFER_ADDR_WIDTH = 5,                                    // TX buffer, 2^N words deep: must be 5

    parameter int          RX_WAIT_CDR_LOCK         = 1,                       // RX reset done waits for the CDR lock
    parameter int          RX_RESETDONE_GATE        = 0,                       // 1: RX reset done stays low
    parameter logic [ 4:0] RX_RESET_TIMER_PRESC     = 0,                       // TX and RX reset timers count every 2^N clocks
    parameter logic [ 4:0] RX_PMA_RESET_TIME        = 3,                       // RX reset sequence: PMA, timer ticks
    parameter logic [ 4:0] RX_EQA_RESET_TIME        = 3,                       // ... equaliser
    parameter logic [ 4:0] RX_CDR_RESET_TIME        = 3,                       // ... CDR
    parameter logic [ 4:0] RX_PCS_RESET_TIME        = 3,                       // ... PCS
    parameter logic [ 4:0] RX_BUF_RESET_TIME        = 3,                       // ... RX buffer
    parameter int          RX_CALIB_OVR             = 0,                       // RX termination calibration override: analog, not modelled
    parameter logic [ 3:0] RX_CALIB_VAL             = 0,                       // ... its value: analog, not modelled
    parameter logic [ 2:0] RX_RTERM_VCMSEL          = 4,                       // RX termination common mode: analog, not modelled
    parameter int          RX_RTERM_PD              = 0,                       // RX termination power down: analog, not modelled
    parameter logic [ 7:0] RX_EQA_CKP_HF            = 8'b101_00011,            // RX equaliser adaptation: analog, not modelled
    parameter logic [ 7:0] RX_EQA_CKP_LF            = 8'b101_00011,            // ... analog, not modelled
    parameter logic [15:0] RX_EQA_CONFIG            = 16'h01C0,                // ... analog, not modelled
    parameter logic [ 7:0] RX_EQA_CKP_OFFSET        = 8'b000_00001,            // ... analog, not modelled
    parameter int          RX_EN_EQA                = 0,                       // RX equaliser adaptation on: analog, not modelled
    parameter logic [ 3:0] RX_EQA_LOCK_CFG          = 0,                       // ... its lock detector: analog, not modelled
    parameter int          RX_TH_MON1_OVR           = 0,                       // RX monitor thresholds, overrides: analog, not modelled
    parameter int          RX_TH_MON2_OVR           = 0,                       // ... analog, not modelled
    parameter int          RX_TAPW_OVR              = 0,                       // RX equaliser tap weight, override: analog, not modelled
    parameter int          RX_AFE_OFFSET_OVR        = 0,                       // RX front-end offset, override: analog, not modelled
    parameter logic [ 4:0] RX_TH_MON1               = 8,                       // RX monitor threshold 1: analog, not modelled
    parameter logic [ 4:0] RX_TH_MON2               = 8,                       // RX monitor threshold 2: analog, not modelled
    parameter logic [ 4:0] RX_TAPW                  = 8,                       // RX equaliser tap weight: analog, not modelled
    parameter logic [ 4:0] RX_AFE_OFFSET            = 8,                       // RX front end: offset, analog, not modelled
    parameter logic [ 2:0] RX_AFE_VCMSEL            = 4,                       // ... common mode, analog, not modelled
    parameter logic [ 3:0] RX_AFE_GAIN              = 8,                       // ... gain, analog, not modelled
    parameter logic [ 4:0] RX_AFE_PEAK              = 16,                      // ... peaking, analog, not modelled
    parameter logic [ 7:0] RX_CDR_CKP               = {3'b101, 5'b01111},      // CDR loop gains: not modelled (BHV_CDR_KP)
    parameter logic [ 7:0] RX_CDR_CKI               = {3'b000, 5'b00000},      // ... not modelled
    parameter logic [14:0] RX_CDR_LOCK_CFG          = 15'b000_1000_1101_0101,  // CDR lock detector: not modelled (BHV_CDR_LOCK_EDGES)
    parameter logic [ 1:0] RX_CDR_SET_ACC_CONFIG    = 2'b00,                   // CDR accumulator presets: not modelled
    parameter int          RX_CDR_FORCE_LOCK        = 0,                       // 1: the CDR reports lock at once
    parameter logic [14:0] RX_CDR_FREQ_ACC          = 15'h0,                   // CDR accumulator preset: not modelled
    parameter logic [15:0] RX_CDR_PHASE_ACC         = 16'h0,                   // ... not modelled
    parameter logic [ 9:0] ALIGN_MCOMMA_VALUE       = 10'b1010000011,          // minus comma, 10 bits in line order
    parameter logic [ 9:0] ALIGN_PCOMMA_VALUE       = 10'b0101111100,          // plus comma
    parameter logic [ 9:0] ALIGN_COMMA_ENABLE       = 10'b1111111111,          // comma bits compared
    parameter logic [ 1:0] ALIGN_COMMA_WORD         = 2'b00,                   // comma lane: 00 any, 01 even, 1x 0 or 4
    parameter logic [ 1:0] RX_SLIDE_MODE            = 0,                       // RX_SLIDE_I: 0 off, 1 one bit, 2 one byte; not 3
    parameter logic [14:0] RX_EYE_MEAS_CFG          = 0,                       // eye monitor: not modelled
    parameter logic [ 5:0] RX_MON_PH_OFFSET         = 0,                       // ... not modelled
    parameter logic [ 3:0] RX_EI_BIAS               = 4,                       // electrical-idle detector: analog, not modelled
    parameter logic [ 3:0] RX_EI_BW_SEL             = 4,                       // ... analog, not modelled
    parameter int          RX_BUF_BYPASS            = 0,                       // 1: no RX elastic buffer
    parameter int          RX_CLKCOR_USE            = 0,                       // 1: clock correction on
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_0        = 10'b0111110111,          // clock-correction sequence, symbol 0
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_1        = 10'b0111110111,          // ... symbol 1
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_2        = 10'b0111110111,          // ... symbol 2
    parameter logic [ 9:0] RX_CLKCOR_SEQ_1_3        = 10'b0111110111,          // ... symbol 3
    parameter logic [ 5:0] RX_CLKCOR_MIN_LAT        = 32,                      // RX buffer fill: reads start here; a sequence goes in below it - 1
    parameter logic [ 5:0] RX_CLKCOR_MAX_LAT        = 39,                      // ... and one comes out above it
    parameter logic [ 1:0] RX_DATAPATH_SEL          = 3,                       // RX word: 0 16, 1 32, 2 or 3 64 bits
    parameter logic [ 5:0] RX_DBG_SRAM_DELAY        = 6'b00_01_01,             // RX debug: not modelled
    parameter logic [ 3:0] RX_DBG_SEL               = 0,                       // ... not modelled
    parameter int          RX_DBG_MODE              = 0,                       // ... not modelled
    parameter logic [ 4:0] TX_SEL_PRE               = 0,                       // TX driver, de-emphasis: analog, not modelled
    parameter logic [ 4:0] TX_SEL_POST              = 0,                       // ... analog, not modelled
    parameter logic [ 2:0] TX_TAIL_CASCODE          = 3'b100,                  // TX driver: analog, not modelled
    parameter logic [ 4:0] TX_BRANCH_EN_PRE         = 0,                       // TX driver branches: analog, not modelled
    parameter logic [ 5:0] TX_BRANCH_EN_MAIN        = 6'b111111,               // ... analog, not modelled
    parameter logic [ 4:0] TX_BRANCH_EN_POST        = 0,                       // ... analog, not modelled
    parameter logic [ 6:0] TX_DC_ENABLE             = 63,                      // TX driver: analog, not modelled
    parameter logic [ 4:0] TX_AMP                   = 15,                      // TX swing: analog, not modelled
    parameter logic [ 4:0] TX_DC_OFFSET             = 0,                       // TX driver: analog, not modelled
    parameter logic [ 4:0] TX_CM_RAISE              = 0,                       // TX common mode: analog, not modelled
    parameter logic [ 4:0] TX_CM_THRESHOLD_0        = 14,                      // ... analog, not modelled
    parameter logic [ 4:0] TX_CM_THRESHOLD_1        = 16,                      // ... analog, not modelled
    parameter int          TX_CALIB_OVR             = 0,                       // TX termination calibration override: analog, not modelled
    parameter logic [ 3:0] TX_CALIB_VAL             = 0,                       // ... its value: analog, not modelled
    parameter int          TX_CM_REG_EN             = 1,                       // TX common-mode regulator: analog, not modelled
    parameter logic [ 7:0] TX_CM_REG_KI             = 8'h80,                   // ... analog, not modelled
    parameter logic [ 4:0] TX_PMA_RESET_TIME        = 3,                       // TX reset sequence: PMA, timer ticks
    parameter logic [ 4:0] TX_PCS_RESET_TIME        = 3,                       // ... PCS
    parameter int          TX_PMA_LOOPBACK          = 0,                       // TX to RX in the PMA (also LOOPBACK_I)
    parameter logic [ 1:0] TX_DATAPATH_SEL          = 3,                       // TX word, as RX_DATAPATH_SEL; bit 1: M4 = 2
    parameter int          PLL_EN_ADPLL_CTRL        = 0,                       // PLL_CFG0 after reset: bit 0, PLL on
    parameter int          PLL_CONFIG_SEL           = 0,                       // ... read back only
    parameter int          PLL_SET_OP_LOCK          = 1,                       // ... read back only
    parameter int          PLL_ENFORCE_LOCK         = 0,                       // ... read back only
    parameter int          PLL_DISABLE_LOCK         = 0,                       // ... read back only
    parameter int          PLL_LOCK_WINDOW          = 1,                       // ... read back only
    parameter int          PLL_FAST_LOCK            = 1,                       // ... read back only
    parameter int          PLL_SYNC_BYPASS          = 0,                       // ... read back only
    parameter int          PLL_PFD_SELECT           = 0,                       // ... read back only
    parameter int          PLL_REF_BYPASS           = 0,                       // ... read back only
    parameter int          PLL_REF_SEL              = 0,                       // ... bit 10, REFCLK_SEL_O
    parameter int          PLL_REF_RTERM            = 1,                       // ... bit 11, REFCLK_RTERM_O
    parameter logic [ 5:0] PLL_FCNTRL               = 58,                      // word clock divider M1 (DS1001 Table 2.17)
    parameter logic [ 5:0] PLL_MAIN_DIVSEL          = 27,                      // N1, N2, N3: the line rate
    parameter logic [ 1:0] PLL_OUT_DIVSEL           = 0,                       // M3: line rate / 1, 2 or 4
    parameter logic [ 4:0] PLL_CI                   = 1,                       // PLL loop: analog, not modelled
    parameter logic [ 9:0] PLL_CP                   = 60,                      // ... analog, not modelled
    parameter logic [ 3:0] PLL_AO                   = 0,                       // ... analog, not modelled
    parameter logic [ 2:0] PLL_SCAP                 = 0,                       // ... analog, not modelled
    parameter int          PLL_SCAP_AUTO_CAL        = 1,                       // ... analog, not modelled
    parameter logic [ 1:0] PLL_FILTER_SHIFT         = 2,                       // ... analog, not modelled
    parameter logic [ 2:0] PLL_SAR_LIMIT            = 2,                       // ... analog, not modelled
    parameter logic [10:0] PLL_FT                   = 512,                     // ... analog, not modelled
    parameter int          PLL_OPEN_LOOP            = 0,                       // ... analog, not modelled
    parameter logic [ 2:0] PLL_BISC_MODE            = 3'b100,                  // PLL calibration: analog, not modelled
    parameter logic [ 3:0] PLL_BISC_TIMER_MAX       = 15,                      // ... analog, not modelled
    parameter logic [ 4:0] PLL_BISC_CP_MIN          = 4,                       // ... analog, not modelled
    parameter logic [ 4:0] PLL_BISC_CP_MAX          = 18,                      // ... analog, not modelled
    parameter logic [ 4:0] PLL_BISC_CP_START        = 12,                      // ... analog, not modelled
    parameter int          PLL_BISC_OPT_DET_IND     = 0,                       // ... analog, not modelled
    parameter int          PLL_BISC_PFD_SEL         = 0,                       // ... analog, not modelled
    parameter int          PLL_BISC_DLY_DIR         = 0,                       // ... analog, not modelled
    parameter int          PLL_BISC_CAL_SIGN        = 0,                       // ... analog, not modelled
    parameter int          PLL_BISC_CAL_AUTO        = 1,                       // ... analog, not modelled
    parameter logic [ 4:0] PLL_BISC_DLY_PFD_MON_REF = 0,                       // ... analog, not modelled
    parameter logic [ 4:0] PLL_BISC_DLY_PFD_MON_DIV = 2,                       // ... analog, not modelled
    parameter logic [ 2:0] PLL_BISC_COR_DLY         = 1                        // ... analog, not modelled
) (
    input  logic        clk_ref_i,
    input  logic        clk_reg_i,
    input  logic        clk_cfg_i,
    input  logic        clk_core_tx_i,
    input  logic        clk_core_rx_i,
    output logic        clk_core_rx_o = '0,
    input  logic        reset_n_i,
    input  logic        reset_reg_n_i,
    input  logic        reset_core_tx_n_i,
    input  logic        reset_core_rx_n_i,
    input  logic        testmode_i,
    input  logic        scan_enable_i,
    input  logic [ 6:0] scan_in_i,
    output logic [ 6:0] scan_out_o = '0,
    input  logic [ 2:0] loopback_i,
    input  logic        pll_reset_i,
    output logic        clk_core_pll_o = '0,
    output logic        reset_core_pll_n_o = '0,
    output logic        refclk_sel_o = '0,
    output logic        refclk_rterm_o = '0,
    input  logic        RX_SERIO_P_B,
    input  logic        RX_SERIO_N_B,
    output logic        TX_SERIO_P_B = '0,
    output logic        TX_SERIO_N_B = '0,
    input  logic        regfile_we_i,
    input  logic        regfile_en_i,
    input  logic [ 7:0] regfile_addr_i,
    input  logic [15:0] regfile_mask_i,
    input  logic [15:0] regfile_di_i,
    output logic [15:0] regfile_do_o = '0,
    output logic        regfile_rdy_o = '0,
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
    output logic        tx_buf_err_o = '0,
    output logic        tx_resetdone_o = '0,
    output logic        rx_detect_done_o = '0,
    output logic        rx_present_o = '0,
    output logic        TERM_SERIO_O = '0,
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
    output logic        rx_prbs_err_o = '0,
    output logic [63:0] rx_data_o = '0,
    output logic [ 7:0] rx_char_is_k_o = '0,
    output logic [ 7:0] rx_char_is_comma_o = '0,
    output logic [ 7:0] rx_not_in_table_o = '0,
    output logic [ 7:0] rx_disp_err_o = '0,
    output logic        rx_buf_err_o = '0,
    output logic        rx_byte_is_aligned_o = '0,
    output logic        rx_byte_realign_o = '0,
    output logic        rx_resetdone_o = '0,
    output logic        rx_ei_en_o = '0
);

  //#########################################################################
  // 8b/10b decode table, built at time 0 by running the encoder forward,
  // 1000x faster than dec8b10b() (the decoder under proof) for every
  // symbol. tb_modes checks the two agree on all 1024 symbols.
  //#########################################################################
  bit [9:0] dec_lut[1024];  // {valid, k, data}
  bit [3:0] dec_rd [1024];  // dec_disp() at RD+ and RD-: {err, rd_out} x 2

  initial begin : build_dec_lut
    bit [10:0] e;
    for (int s = 0; s < 1024; s++) begin
      dec_lut[s] = 10'h0;
      dec_rd[s]  = {dec_disp(s[9:0], HI), dec_disp(s[9:0], LO)};
    end
    for (int r = 0; r < 2; r++) begin
      for (int d = 0; d < 256; d++) begin
        e                = enc8b10b(d[7:0], FALSE, r[0]);
        dec_lut[e[9:0]] = {2'b10, d[7:0]};
      end
    end
    // K codes last: they win a symbol they share with data
    for (int r = 0; r < 2; r++) begin
      for (int d = 0; d < 12; d++) begin
        e                = enc8b10b(kcode(d), TRUE, r[0]);
        dec_lut[e[9:0]] = {2'b11, kcode(d)};
      end
    end
  end

  //#########################################################################
  // Checks: the values UG1001 (Table 7.12 to 7.14) and DS1001 (Table 2.15
  // to 2.17, 2.51) allow, and what the BFM models. A wrong value is an
  // $error, then $fatal: fix the testbench. Parameters at time 0
  // (param_check); PLL_CFG1 when the PLL turns on, or at a write while it
  // is on; RX_BUF_CFG when an RX buffer reset ends.
  //#########################################################################
  function automatic int chk_range(string name, int v, int lo, int hi);
    if (v < lo || v > hi) begin
      $error("%m: %s = %0d: allowed %0d to %0d", name, v, lo, hi);
      return 1;
    end
    return 0;
  endfunction

  function automatic int chk_bad(bit bad, string name, int v, string why);
    if (bad) begin
      $error("%m: %s = %0d: %s", name, v, why);
    end
    return int'(bad);
  endfunction

  task automatic chk_stop(int n, string what);
    if (n != 0) begin
      $fatal(1, "%m: %0d error(s) in %s", n, what);
    end
  endtask

  // PLL_CFG1 = {OUT_DIVSEL, MAIN_DIVSEL, FCNTRL}
  function automatic int pll_cfg1_errors(bit [13:0] v);
    int n = 0;
    n += chk_bad(v[13:12] == 2'b10, "PLL_OUT_DIVSEL", int'(v[13:12]), "n.a. (DS1001 Table 2.15)");
    n += chk_bad(v[10:9] == 2'b01, "PLL_MAIN_DIVSEL", int'(v[11:6]), "[4:3] = 01 is n.a. (DS1001 Table 2.15)");
    n += chk_bad(v[11], "PLL_MAIN_DIVSEL", int'(v[11:6]), "[5] must stay 0 (DS1001 Table 2.15)");
    n += chk_bad(v[5:0] < 6'd2, "PLL_FCNTRL", int'(v[5:0]), "the alternative clock path is not modelled");
    return n;
  endfunction

  task automatic pll_cfg1_check(bit [13:0] v);
    chk_stop(pll_cfg1_errors(v), "PLL_CFG1");
  endtask

  // RX_BUF_CFG, with clock correction: MIN and MAX within the buffer's error
  // limits (3 and 60), MIN up to MAX
  function automatic int rx_buf_cfg_errors(rx_buf_cfg_t c);
    int n = 0;
    if (c.clkcor_use) begin
      n += chk_range("RX_CLKCOR_MIN_LAT", int'(c.min_lat), 3, 60);
      n += chk_range("RX_CLKCOR_MAX_LAT", int'(c.max_lat), 3, 60);
      n += chk_bad(c.min_lat > c.max_lat, "RX_CLKCOR_MIN_LAT", int'(c.min_lat), "above RX_CLKCOR_MAX_LAT");
    end
    return n;
  endfunction

  //#########################################################################
  // Register file and config file, on CLK_REG_I: the registers the model
  // uses; an access to any other gives a $warning, once per address
  //#########################################################################
  localparam bit [7:0] RX_BUF_CFG_ADDR = 8'h25;
  localparam bit [7:0] PLL_CFG0_ADDR   = 8'h50;
  localparam bit [7:0] PLL_CFG1_ADDR   = 8'h51;
  localparam bit [7:0] PLL_CFG5_ADDR   = 8'h55;  // status, read only
  localparam bit [7:0] PLL_CFG6_ADDR   = 8'h56;  // status, read only
  localparam bit [7:0] SERDES_CFG_ADDR = 8'h5C;

  localparam bit [15:0] RX_BUF_CFG_RESET = {
    2'b00, RX_CLKCOR_MAX_LAT, RX_CLKCOR_MIN_LAT, 1'(RX_CLKCOR_USE), 1'(RX_BUF_BYPASS)
  };

  // PLL_CFG0 / PLL_CFG1 after reset, from the parameters
  localparam bit [11:0] PLL_OP_RESET = {
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
  localparam bit [13:0] PLL_DIV_RESET = {PLL_OUT_DIVSEL, PLL_MAIN_DIVSEL, PLL_FCNTRL};

  csr_t        csr;

  bit          regfile_en_d;
  bit  [255:0] rf_warned;

  bit          pll_enabled;
  bit          pll_locked;  // PLL_CFG5[0], PLL_LOCKED

  task automatic rf_reset();
    csr.rx_buf_cfg       = RX_BUF_CFG_RESET;
    csr.rx_clkcor_seq[0] = {6'h0, RX_CLKCOR_SEQ_1_0};
    csr.rx_clkcor_seq[1] = {6'h0, RX_CLKCOR_SEQ_1_1};
    csr.rx_clkcor_seq[2] = {6'h0, RX_CLKCOR_SEQ_1_2};
    csr.rx_clkcor_seq[3] = {6'h0, RX_CLKCOR_SEQ_1_3};
    csr.pll_cfg0         = PLL_OP_RESET;
    csr.pll_cfg1         = PLL_DIV_RESET;
    csr.serdes_cfg       = '0;
    refclk_sel_o        <= csr.pll_cfg0[10];
    refclk_rterm_o      <= csr.pll_cfg0[11];
  endtask

  // the registers hold their reset values from the start, also with
  // RESET_REG_N_I tied high
  initial rf_reset();

  function automatic bit [15:0] masked(bit [15:0] old, bit [15:0] d, bit [15:0] m);
    return (old & ~m) | (d & m);
  endfunction

  task automatic rf_unmodelled(bit [7:0] a);
    if (!rf_warned[a]) begin
      rf_warned[a] = HI;
      $warning("%m: register 0x%02h is not modelled", a);
    end
  endtask

  // One access per rising REGFILE_EN_I, ready a clock later; the config
  // file writes every clock CFGFILE_VALID_I is high. REGFILE_DO_O and
  // REGFILE_RDY_O are non-blocking: the fabric samples them on this edge.
  always @(posedge clk_reg_i or negedge reset_reg_n_i) begin : regfile
    bit        access, cfg_wr;
    bit [ 7:0] a;
    bit [15:0] d, m;
    if (!reset_reg_n_i) begin
      rf_reset();
      regfile_en_d   = LO;
      regfile_rdy_o <= LO;
      regfile_do_o  <= '0;
    end
    else begin
      access       = regfile_en_i && !regfile_en_d && !cfg_en_i;
      regfile_en_d = regfile_en_i;
      cfg_wr       = cfg_en_i && cfgfile_valid_i;
      if (regfile_rdy_o) begin
        regfile_rdy_o <= LO;
      end

      if (cfg_en_i && reset_cfg_i) begin
        rf_reset();
      end
      else if (cfg_wr || (access && regfile_we_i)) begin
        a = cfg_en_i ? cfgfile_addr_i : regfile_addr_i;
        d = cfg_en_i ? cfgfile_di_i : regfile_di_i;
        m = cfg_en_i ? 16'hFFFF : regfile_mask_i;
        unique case (a)
          RX_BUF_CFG_ADDR: begin
            csr.rx_buf_cfg = masked(csr.rx_buf_cfg, d, m);
          end
          8'h26: begin csr.rx_clkcor_seq[0] = masked(csr.rx_clkcor_seq[0], d, m); end
          8'h27: begin csr.rx_clkcor_seq[1] = masked(csr.rx_clkcor_seq[1], d, m); end
          8'h28: begin csr.rx_clkcor_seq[2] = masked(csr.rx_clkcor_seq[2], d, m); end
          8'h29: begin csr.rx_clkcor_seq[3] = masked(csr.rx_clkcor_seq[3], d, m); end
          SERDES_CFG_ADDR: begin
            if (cfg_wr) begin
              csr.serdes_cfg = d[2:0];
            end
          end
          PLL_CFG0_ADDR: begin
            if (!csr.pll_cfg0[0] || cfg_wr) begin  // the PLL was off: the write that turns it on counts
              csr.pll_cfg0[9:1] = 9'(masked(16'(csr.pll_cfg0[9:1]), 16'(d[9:1]), 16'(m[9:1])));
            end
            if (m[0]) begin
              csr.pll_cfg0[0] = d[0];
            end
            if (m[10]) begin
              csr.pll_cfg0[10] = d[10];
            end
            if (m[11]) begin
              csr.pll_cfg0[11] = d[11];
            end
            refclk_sel_o   <= csr.pll_cfg0[10];
            refclk_rterm_o <= csr.pll_cfg0[11];
          end
          PLL_CFG1_ADDR: begin
            if (!csr.pll_cfg0[0] || cfg_wr) begin
              csr.pll_cfg1 = 14'(masked(16'(csr.pll_cfg1), d, m));
              if (pll_enabled) begin  // in use at once: else when the PLL turns on
                pll_cfg1_check(csr.pll_cfg1);
              end
            end
          end
          default: begin
            rf_unmodelled(a);
          end
        endcase
        if (!cfg_en_i) begin
          regfile_rdy_o <= HI;
        end
      end
      else if (access) begin
        a = regfile_addr_i;
        unique case (a)
          RX_BUF_CFG_ADDR:            begin d = csr.rx_buf_cfg; end
          8'h26:                      begin d = csr.rx_clkcor_seq[0]; end
          8'h27:                      begin d = csr.rx_clkcor_seq[1]; end
          8'h28:                      begin d = csr.rx_clkcor_seq[2]; end
          8'h29:                      begin d = csr.rx_clkcor_seq[3]; end
          PLL_CFG0_ADDR:              begin d = {4'h0, csr.pll_cfg0}; end
          PLL_CFG1_ADDR:              begin d = {2'h0, csr.pll_cfg1}; end
          PLL_CFG5_ADDR:              begin d = {15'h0, pll_locked}; end
          PLL_CFG6_ADDR:              begin d = '0; end  // PLL_SYNC_VALUE: not modelled
          SERDES_CFG_ADDR: begin
            d = {13'h0, csr.serdes_cfg};
          end
          default: begin
            d = '0;
            rf_unmodelled(a);
          end
        endcase
        regfile_do_o  <= d;
        regfile_rdy_o <= HI;
      end
    end
  end

  // words: 2, 4 or 8 symbols
  localparam int TX_BYTES = (TX_DATAPATH_SEL == 2'b00) ? 2 : (TX_DATAPATH_SEL == 2'b01) ? 4 : 8;
  localparam int RX_BYTES = (RX_DATAPATH_SEL == 2'b00) ? 2 : (RX_DATAPATH_SEL == 2'b01) ? 4 : 8;
  localparam int TX_WORD_BITS = TX_BYTES * 10;

  //#########################################################################
  // PLL: line rate f_ref * N1*N2*N3*2 / M3; PLL_CLK_O = 2 UI * M1 * M4
  // (DS1001 Eq. 2.2, 2.3); recovered RX clock = a word of RX_BYTES symbols
  //#########################################################################
  real ui;           // the line UI
  real core_period;  // the recovered RX clock: a word of RX_BYTES symbols
  real pll_period;   // PLL_CLK_O
  real ref_period = (BHV_REF_CLK_MHZ > 0.0) ? (1000.0 / BHV_REF_CLK_MHZ) : 10.0;
  bit  ref_seen = (BHV_REF_CLK_MHZ > 0.0);

  // The reference period is measured unless BHV_REF_CLK_MHZ gives it
  initial if (BHV_REF_CLK_MHZ <= 0.0) begin : ref_meter
    real last;
    @(posedge clk_ref_i);
    last = $realtime;
    forever begin
      @(posedge clk_ref_i);
      ref_period = $realtime - last;
      ref_seen   = TRUE;
      last       = $realtime;
    end
  end

  // The dividers from PLL_CFG1, and the periods; a 0.4 ns UI (Gen1) until
  // the reference period is known
  always @(csr.pll_cfg1 or ref_seen or ref_period) begin : pll_rates
    int n1, n2, n3, m3;
    n1 = csr.pll_cfg1[8] ? 2 : 1;  // MAIN_DIVSEL[2]
    unique case (csr.pll_cfg1[7:6])  // MAIN_DIVSEL[1:0]
      2'b00:   begin n2 = 3; end
      2'b01:   begin n2 = 2; end
      2'b10:   begin n2 = 4; end
      default: begin n2 = 5; end
    endcase
    unique case (csr.pll_cfg1[10:9])  // MAIN_DIVSEL[4:3]
      2'b00:   begin n3 = 3; end
      2'b10:   begin n3 = 4; end
      2'b11:   begin n3 = 5; end
      default: begin n3 = 1; end
    endcase
    unique case (csr.pll_cfg1[13:12])  // OUT_DIVSEL
      2'b01:   begin m3 = 2; end
      2'b11:   begin m3 = 4; end
      default: begin m3 = 1; end
    endcase

    ui = (ref_seen && (ref_period > 0.0)) ? (ref_period * m3) / (2.0 * n1 * n2 * n3) : 0.4;
    core_period = ui * 10.0 * RX_BYTES;
    // DS1001 Eq. 2.2, 2.3: the bit rate clock is 2 UI; M1 from FCNTRL,
    // M4 = 2 for the 64-bit datapath
    pll_period  = ui * 2.0 * (pll_m1_x4(csr.pll_cfg1[5:0]) / 4.0) * (TX_DATAPATH_SEL[1] ? 2.0 : 1.0);
  end

  always @(reset_n_i or pll_reset_i or csr.serdes_cfg or csr.pll_cfg0 or pll_locked) begin : pll_state
    pll_enabled        = reset_n_i & ~pll_reset_i & csr.serdes_cfg.en & csr.pll_cfg0[0];
    reset_core_pll_n_o = pll_locked & reset_n_i;
  end

  // Lock BHV_PLL_LOCK_TIME_NS after the PLL turns on, by level: a zero-width
  // off-on glitch is no restart, a real one restarts the lock time
  always begin : pll_lock_seq
    bit done;
    pll_locked = LO;
    wait (pll_enabled);
    pll_cfg1_check(csr.pll_cfg1);
    done = FALSE;
    fork
      begin
        #(BHV_PLL_LOCK_TIME_NS);
        done = TRUE;
      end
      wait (!pll_enabled);
    join_any
    disable fork;
    if (done && pll_enabled) begin
      pll_locked = HI;
      if (BHV_VERBOSE) begin
        $display("[%0t] %m: PLL locked, line rate %.3f Gb/s, PLL clk %.3f MHz", $time,
                 1.0 / ui, 1000.0 / pll_period);
      end
      wait (!pll_enabled);
    end
  end

  // PLL_CLK_O: its edges on an absolute grid from the lock, so it keeps the
  // serializer's pace at any UI, also one the time precision can't hold
  always begin : core_clk_gen
    real    t0, half;
    longint k;
    clk_core_pll_o = LO;
    wait (pll_locked && (pll_period > 0.0));
    t0   = $realtime;
    half = pll_period / 2.0;
    k    = 0;
    while (pll_locked) begin
      if (pll_period / 2.0 != half) begin  // a new rate: a new grid
        t0   = t0 + k * half;
        half = pll_period / 2.0;
        k    = 0;
      end
      k++;
      #(t0 + k * half - $realtime);
      if (pll_locked) begin
        clk_core_pll_o = ~clk_core_pll_o;
      end
    end
  end

  //#########################################################################
  // Resets and reset-done
  //#########################################################################
  localparam int RST_PRESC = (1 << RX_RESET_TIMER_PRESC);

  bit tx_core_rst_n;
  bit rx_core_rst_n;
  bit tx_pcs_rst_n;
  bit tx_pma_rst_n;
  bit rx_pcs_rst_n;
  bit rx_pma_rst_n;
  bit rx_cdr_rst_n;
  bit rx_buf_rst_n;

  bit tx_rst_off;  // all TX resets released
  bit rx_rst_off;  // all RX resets released

  always @(reset_core_pll_n_o or csr.serdes_cfg or reset_core_tx_n_i or tx_powerdown_n_i or
           tx_reset_i or tx_pcs_reset_i or tx_pma_reset_i or reset_core_rx_n_i or
           rx_powerdown_n_i or rx_reset_i or rx_pcs_reset_i or rx_pma_reset_i or
           rx_cdr_reset_i or rx_buf_reset_i) begin : resets
    tx_core_rst_n = reset_core_pll_n_o & reset_core_tx_n_i & tx_powerdown_n_i & ~tx_reset_i
                    & csr.serdes_cfg.en;
    rx_core_rst_n = reset_core_pll_n_o & reset_core_rx_n_i & rx_powerdown_n_i & ~rx_reset_i
                    & csr.serdes_cfg.en;
    tx_pcs_rst_n  = tx_core_rst_n & ~tx_pcs_reset_i;
    tx_pma_rst_n  = tx_core_rst_n & ~tx_pma_reset_i;
    rx_pcs_rst_n  = rx_core_rst_n & ~rx_pcs_reset_i;
    rx_pma_rst_n  = rx_core_rst_n & ~rx_pma_reset_i;
    rx_cdr_rst_n  = rx_core_rst_n & ~rx_cdr_reset_i;
    rx_buf_rst_n  = rx_core_rst_n & ~rx_buf_reset_i;
    tx_rst_off    = tx_pma_rst_n & tx_pcs_rst_n;
    rx_rst_off    = rx_pma_rst_n & rx_pcs_rst_n & rx_cdr_rst_n & rx_buf_rst_n;
  end

  // PLL clocks from the release of all resets to TX/RX_RESETDONE_O
  localparam int TX_RST_CLKS = (int'(TX_PMA_RESET_TIME) + int'(TX_PCS_RESET_TIME) + 2) * RST_PRESC + 1;
  localparam int RX_RST_CLKS = (int'(RX_PMA_RESET_TIME) + int'(RX_EQA_RESET_TIME) + int'(RX_CDR_RESET_TIME)
                                + int'(RX_PCS_RESET_TIME) + int'(RX_BUF_RESET_TIME) + 5) * RST_PRESC + 1;

  always begin : tx_resetdone_seq
    tx_resetdone_o = LO;  // at once, like an async clear
    wait (tx_rst_off);
    fork
      begin
        repeat (TX_RST_CLKS) @(posedge clk_core_pll_o);
        tx_resetdone_o <= HI;
      end
    join_none
    @(negedge tx_rst_off);
    disable fork;
  end

  bit rx_cdr_locked;

  // RX: then, with RX_WAIT_CDR_LOCK, the CDR lock too; RX_RESETDONE_GATE
  // holds it low
  always begin : rx_resetdone_seq
    rx_resetdone_o = LO;  // at once, like an async clear
    wait (rx_rst_off);
    fork
      begin
        repeat (RX_RST_CLKS) @(posedge clk_core_pll_o);
        while ((RX_WAIT_CDR_LOCK != 0) && !rx_cdr_locked) begin
          @(posedge clk_core_pll_o);
        end
        rx_resetdone_o <= (RX_RESETDONE_GATE == 0);
      end
    join_none
    @(negedge rx_rst_off);
    disable fork;
  end

  // the parameters, with the checks at the top of the module
  initial begin : param_check
    int n;
    n = chk_range("RX_WAIT_CDR_LOCK", RX_WAIT_CDR_LOCK, 0, 1);
    n += chk_range("RX_CDR_FORCE_LOCK", RX_CDR_FORCE_LOCK, 0, 1);
    n += chk_range("RX_BUF_BYPASS", RX_BUF_BYPASS, 0, 1);
    n += chk_range("RX_CLKCOR_USE", RX_CLKCOR_USE, 0, 1);
    n += chk_range("RX_RESETDONE_GATE", RX_RESETDONE_GATE, 0, 1);
    n += chk_range("PLL_EN_ADPLL_CTRL", PLL_EN_ADPLL_CTRL, 0, 1);
    n += chk_range("PLL_CONFIG_SEL", PLL_CONFIG_SEL, 0, 1);
    n += chk_range("PLL_SET_OP_LOCK", PLL_SET_OP_LOCK, 0, 1);
    n += chk_range("PLL_ENFORCE_LOCK", PLL_ENFORCE_LOCK, 0, 1);
    n += chk_range("PLL_DISABLE_LOCK", PLL_DISABLE_LOCK, 0, 1);
    n += chk_range("PLL_LOCK_WINDOW", PLL_LOCK_WINDOW, 0, 1);
    n += chk_range("PLL_FAST_LOCK", PLL_FAST_LOCK, 0, 1);
    n += chk_range("PLL_SYNC_BYPASS", PLL_SYNC_BYPASS, 0, 1);
    n += chk_range("PLL_PFD_SELECT", PLL_PFD_SELECT, 0, 1);
    n += chk_range("PLL_REF_BYPASS", PLL_REF_BYPASS, 0, 1);
    n += chk_range("PLL_REF_SEL", PLL_REF_SEL, 0, 1);
    n += chk_range("PLL_REF_RTERM", PLL_REF_RTERM, 0, 1);
    n += chk_range("TX_PMA_LOOPBACK", TX_PMA_LOOPBACK, 0, 3);
    // a vendor-model parameter, not in UG1001: the TX buffer stays 32
    // words deep (address width 5)
    n += chk_range("TX_BUFFER_ADDR_WIDTH", TX_BUFFER_ADDR_WIDTH, 5, 5);
    n += pll_cfg1_errors(PLL_DIV_RESET);
    n += chk_bad(RX_SLIDE_MODE == 2'b11, "RX_SLIDE_MODE", int'(RX_SLIDE_MODE),
                 "a bit or a byte, not both (DS1001 Table 2.51)");
    // the reset timers count 2^N clocks a tick in an int: RX_RST_CLKS fits
    n += chk_range("RX_RESET_TIMER_PRESC", int'(RX_RESET_TIMER_PRESC), 0, 23);
    n += rx_buf_cfg_errors(RX_BUF_CFG_RESET);
    chk_stop(n, "the parameters");
  end : param_check

  bit pcs_loopback;
  bit pma_loopback;

  task automatic loopbacks();
    pcs_loopback = loopback_i[1] | loopback_i[2];
    pma_loopback = loopback_i[0] | (TX_PMA_LOOPBACK != 0);
  endtask

  initial loopbacks();
  always @(loopback_i) loopbacks();

  //#########################################################################
  // TX: fabric word in, serial line out
  //#########################################################################

  //=========================================================================
  // TX: 8b/10b encoder and elastic buffer
  //=========================================================================
  bit [30:0] tx_prbs_lfsr = 31'h7FFF_FFFF;
  bit        tx_prbs_bit;  // for the waveform

  bit        tx_rd;
  bit        tx_ser_run;    // the serializer runs
  bit        tx_underflow;  // the serializer found the buffer empty

  bit [79:0] tx_q[$];  // the elastic buffer, 1 << TX_BUFFER_ADDR_WIDTH words

  // Until the serializer runs (TX reset done), at most the newest half of
  // the buffer waits: the default reset times fill 9 words, and a large
  // RX_RESET_TIMER_PRESC no longer overflows it
  localparam int TX_BUF_START = (1 << TX_BUFFER_ADDR_WIDTH) / 2;

  // TX_BUF_ERR_O: an overflow here, or an underflow the serializer saw
  // since the last clock; one driver, non-blocking: the fabric samples it
  // on this edge
  always @(posedge clk_core_tx_i or negedge tx_pcs_rst_n) begin : tx_buf
    bit [10:0] enc;
    bit [ 7:0] byte_v;
    bit        k_v;
    bit [79:0] word_v;
    bit        rd_v;
    bit        err_v;
    bit [63:0] src_data;
    bit [ 7:0] src_k;
    if (!tx_pcs_rst_n) begin
      tx_q.delete();
      tx_rd         = LO;
      tx_underflow  = LO;
      tx_buf_err_o <= LO;
    end
    else begin
      err_v        = tx_underflow;
      tx_underflow = LO;
      rd_v         = tx_rd;
      word_v   = 80'h0;
      src_data = pcs_loopback ? rx_data_o : tx_data_i;
      src_k    = pcs_loopback ? rx_char_is_k_o : tx_char_is_k_i;

      for (int i = 0; i < 8; i++) begin
        if (i < TX_BYTES) begin
          byte_v = src_data[i*8+:8];
          k_v    = src_k[i];

          if (!tx_8b10b_en_i || tx_8b10b_bypass_i[i]) begin
            word_v[i*10+:10] = {tx_char_dispmode_i[i], tx_char_dispval_i[i], byte_v};  // DS1001 Fig. 2.34: bit 9 DISPMODE, bit 8 DISPVAL
          end
          else begin
            if (tx_char_dispmode_i[i]) begin
              rd_v = tx_char_dispval_i[i];
            end
            enc              = enc8b10b(byte_v, k_v, rd_v);
            word_v[i*10+:10] = enc[9:0];
            rd_v             = enc[10];
          end
        end
      end

      tx_rd = rd_v;

      if (tx_q.size() < (1 << TX_BUFFER_ADDR_WIDTH)) begin
        tx_q.push_back(word_v);
      end
      else begin
        err_v = HI;
        if (BHV_VERBOSE) begin
          $display("[%0t] %m: TX elastic buffer overflow", $time);
        end
      end
      if (!tx_ser_run) begin
        while (tx_q.size() > TX_BUF_START) begin
          void'(tx_q.pop_front());
        end
      end
      tx_buf_err_o <= err_v;
    end
  end

  // TX_PRBS_FORCE_ERR_I: each rising edge makes one PRBS bit wrong, the
  // next one sent, in every CDR_MODEL
  bit tx_force_pend;

  always @(posedge tx_prbs_force_err_i) begin
    tx_force_pend = HI;
  end

  // DS1001 Table 2.34: 001 PRBS-7, 010 PRBS-15, the rest reserved. The BFM
  // also runs PRBS-23 (011) and PRBS-31 (100); 101 to 111 run PRBS-7.
  bit [1:0] prbs_warned;

  task automatic prbs_sel_check(bit [2:0] sel, int side);
    if (sel > 3'b100 && !prbs_warned[side]) begin
      prbs_warned[side] = HI;
      $warning("%m: %s_PRBS_SEL_I = %b is reserved: PRBS-7", (side == 0) ? "TX" : "RX", sel);
    end
  endtask

  //=========================================================================
  // TX serializer: one bit a UI on the line (CDR_MODEL = FAST, ACCURATE),
  // or one word a word time on the side channel (NONE)
  //=========================================================================
  bit [79:0] tx_shift;
  int        tx_bit_idx;
  bit        tx_bit;

  // the RX pads: the RX pins, or in PMA loopback the TX pins
  bit rx_pad_p;
  bit rx_pad_n;

  // the TX pins, N first: in CDR_MODEL = NONE, P clocks N
  task automatic tx_line(bit p, bit n);
    TX_SERIO_N_B = n;
    TX_SERIO_P_B = p;
    if (pma_loopback) begin
      rx_pad_n = n;
      rx_pad_p = p;
    end
  endtask

  always @(pll_locked or tx_pma_rst_n or tx_resetdone_o) begin : tx_run
    tx_ser_run = pll_locked & tx_pma_rst_n & tx_resetdone_o;
  end

  // CDR_MODEL = NONE: this BFM's ID, and its peer's, the TX at the far end
  // of the RX pins. Both are set once, at the start (enumeration), and
  // survive every reset.
  struct packed {
    int my_id;
    int peer_id;
  } cdr_none = '1;  // -1, -1: none yet

  initial if (CDR_MODEL == NONE) begin
    cdr_none.my_id = cdr_none_new_id(TX_BYTES);
  end

  // the next bit or word time on an absolute grid from t0: it keeps pace
  // with PLL_CLK_O at any UI, also one the time precision can't hold
  task automatic tx_grid_wait(inout real t0, inout real step, inout longint k, input real now_step);
    if (now_step != step) begin  // a new rate: a new grid
      t0   = t0 + k * step;
      step = now_step;
      k    = 0;
    end
    k++;
    #(t0 + k * step - $realtime);
  endtask

  // the next PRBS bit, with a forced error once per TX_PRBS_FORCE_ERR_I
  task automatic tx_prbs_bit_next(output bit b);
    prbs_sel_check(tx_prbs_sel_i, 0);
    tx_prbs_lfsr  = prbs_next(tx_prbs_lfsr, tx_prbs_sel_i);
    b             = tx_prbs_lfsr[0] ^ tx_force_pend;
    tx_force_pend = LO;
  endtask

  // CDR_MODEL = FAST, ACCURATE: a bit a UI on the line
  initial if (CDR_MODEL != NONE) begin : tx_bit_serializer
    real    t0, step;
    longint k;
    forever begin
      tx_bit_idx   = 0;
      tx_line(LO, LO);
      wait (tx_ser_run && (ui > 0.0));
      t0   = $realtime;
      step = ui;
      k    = 0;
      while (tx_ser_run) begin
        tx_grid_wait(t0, step, k, ui);
        if (tx_bit_idx == 0) begin
          if (tx_q.size() != 0) begin
            tx_shift = tx_q.pop_front();
          end
          else begin
            tx_underflow = HI;  // tx_shift is sent again
          end
        end

        if (tx_prbs_sel_i != 3'b000) begin
          tx_prbs_bit_next(tx_prbs_bit);
          tx_bit = tx_prbs_bit;
        end
        else begin
          tx_force_pend = LO;
          tx_bit        = tx_shift[tx_bit_idx];
        end

        tx_bit_idx = (tx_bit_idx + 1) % TX_WORD_BITS;

        if (tx_elec_idle_i || !tx_powerdown_n_i) begin
          tx_line(LO, LO);
        end
        else begin
          tx_line(tx_bit ^ tx_polarity_i, ~(tx_bit ^ tx_polarity_i));
        end
      end
    end
  end

  // CDR_MODEL = NONE. Enumeration first: once, from 1 ns, after every BFM
  // took its ID, a DDR SPI tells the far end who this TX is: a start bit
  // (1), then the ID, LSB first, on N; each bit clocked by an edge of P
  // half a ns later. Then a word a word time, posted as this TX's last
  // word and counted at its start; P and N stay quiet.
  initial if (CDR_MODEL == NONE) begin : tx_none_serializer
    bit [CDR_NONE_ID_BITS:0] frame;
    bit [79:0]               w;
    real                     t0, step;
    longint                  k;
    frame = {CDR_NONE_ID_BITS'(cdr_none.my_id), HI};
    #1.0;
    for (int i = 0; i <= CDR_NONE_ID_BITS; i++) begin
      tx_line(TX_SERIO_P_B, frame[i]);
      #0.5;
      tx_line(~TX_SERIO_P_B, frame[i]);
      #0.5;
    end
    tx_line(TX_SERIO_P_B, LO);

    forever begin
      wait (tx_ser_run && (ui > 0.0));
      t0   = $realtime;
      step = ui;
      k    = 0;
      tx_grid_wait(t0, step, k, ui);  // the first word a UI in, as the bits'
      t0   = $realtime;
      step = ui * TX_WORD_BITS;
      k    = 0;
      while (tx_ser_run) begin
        if (tx_q.size() != 0) begin
          tx_shift = tx_q.pop_front();
        end
        else begin
          tx_underflow = HI;  // tx_shift is sent again
        end
        w = tx_shift;
        if (tx_prbs_sel_i != 3'b000) begin
          for (int i = 0; i < TX_WORD_BITS; i++) begin
            tx_prbs_bit_next(w[i]);
          end
        end
        else begin
          tx_force_pend = LO;
        end

        if (!tx_elec_idle_i && tx_powerdown_n_i) begin
          cdr_none_last[cdr_none.my_id] = w ^ {80{tx_polarity_i}};
          cdr_none_words[cdr_none.my_id]++;
        end
        tx_grid_wait(t0, step, k, ui * TX_WORD_BITS);
      end
    end
  end

  //#########################################################################
  // RX: serial line in, fabric word out
  //#########################################################################

  //=========================================================================
  // RX: electrical-idle detector
  //=========================================================================
  // the RX pins, unless PMA loopback: then tx_line() drives the pads.
  // N first: in CDR_MODEL = NONE, P clocks N.
  always @(RX_SERIO_P_B or RX_SERIO_N_B or pma_loopback) begin : rx_pins
    if (!pma_loopback) begin
      rx_pad_n = RX_SERIO_N_B;
      rx_pad_p = RX_SERIO_P_B;
    end
  end

  // Idle: P = N (TX_ELEC_IDLE_I drives both low) for EI_WINDOW_UI. Data
  // keeps P and N apart, so no run length looks idle. NONE has no bits on
  // the pins: there, idle is no word for EI_WINDOW_UI (rx_none_words).
  localparam real EI_WINDOW_UI = (CDR_MODEL == NONE) ? 200.0 : 20.0;

  bit  rx_ei_filt  = HI;  // idle, filtered
  bit  rx_ei_quiet = HI;  // P = N, or NONE: since rx_ei_deadline - window
  real rx_ei_deadline;

  task automatic rx_ei_out();
    rx_ei_en_o = rx_en_ei_detector_i & rx_ei_filt;
  endtask

  initial rx_ei_out();
  always @(rx_en_ei_detector_i or rx_ei_filt) rx_ei_out();

  always @(rx_pad_p or rx_pad_n) begin : rx_ei_line
    if (CDR_MODEL != NONE) begin
      if (rx_pad_p != rx_pad_n) begin
        rx_ei_filt  = LO;
        rx_ei_quiet = FALSE;
      end
      else if (!rx_ei_quiet) begin
        rx_ei_quiet    = TRUE;
        rx_ei_deadline = $realtime + (EI_WINDOW_UI * ui);
      end
    end
  end

  always begin : ei_watchdog
    if (!rx_ei_filt && rx_ei_quiet) begin
      if ($realtime >= rx_ei_deadline) begin
        rx_ei_filt = HI;
      end
      else begin
        #(rx_ei_deadline - $realtime);  // then again: it may have moved
      end
    end
    else begin
      @(rx_ei_filt or rx_ei_quiet);
    end
  end

  //=========================================================================
  // RX: deserializer, one bit at a time, from any of the three receivers
  // below: comma alignment, slide, PRBS check, words of RX_BYTES symbols
  //=========================================================================
  bit [ 9:0] rx_shift;
  int        rx_bit_cnt;
  int        rx_sym_cnt;
  bit [79:0] rx_word;       // being filled
  bit [79:0] rx_word_q[$];  // complete, for the recovered clock
  bit [79:0] rx_word_c;     // the word on the recovered clock
  event      rx_word_done;  // a word went into rx_word_q

  // bit by bit; the outputs take them on CLK_CORE_RX_I (rx_status)
  bit        rx_aligned;       // RX_BYTE_IS_ALIGNED_O
  bit        rx_realign_pend;  // RX_BYTE_REALIGN_O: the alignment moved
  bit        rx_prbs_err_acc;  // RX_PRBS_ERR_O: a PRBS error

  bit        rx_slide_pending;

  int        rx_bits_seen;

  localparam bit [9:0] COMMA_MASK = ALIGN_COMMA_ENABLE;
  // ALIGN_COMMA_WORD: an aligned comma sits in any lane (00), an even
  // lane (01), or lane 0 or 4 (1x); else bytes are skipped until it does
  localparam int COMMA_LANES = (ALIGN_COMMA_WORD == 2'b00) ? 1 : (ALIGN_COMMA_WORD == 2'b01) ? 2 : 4;

  bit comma_align_en_d;

  bit [30:0] rx_prbs_lfsr = 31'h7FFF_FFFF;  // the bits received, newest in bit 0
  bit        rx_prbs_synced;
  int        rx_prbs_err_cnt;  // PRBS error count, for the waveform
  int        rx_prbs_good;
  bit [ 2:0] rx_prbs_sel_d;    // the PRBS the checker is synced to

  // the PRBS checker starts over: a stop, or a new PRBS
  task automatic rx_prbs_reset();
    rx_prbs_lfsr    = 31'h7FFF_FFFF;
    rx_prbs_synced  = FALSE;
    rx_prbs_good    = 0;
    rx_prbs_err_acc = LO;
  endtask

  bit rx_word_started;  // the word counter is set, since the last stop

  // the word counter at an RX start: random, or 0
  task automatic rx_word_start();
    if (!rx_word_started) begin
      rx_sym_cnt      = BHV_RX_WORD_PHASE_RANDOM ? int'($urandom_range(RX_BYTES - 1)) : 0;
      rx_word_started = TRUE;
    end
  endtask

  task automatic rx_bit_in(bit b);
    bit        matched, comma_align_en;
    bit [30:0] pred;
    rx_word_start();
    comma_align_en = rx_comma_detect_en_i & (rx_mcomma_align_i | rx_pcomma_align_i);
    rx_bits_seen++;
    rx_shift = {b, rx_shift[9:1]};

    if (rx_prbs_sel_i != rx_prbs_sel_d) begin
      rx_prbs_reset();
      rx_prbs_sel_d = rx_prbs_sel_i;
      prbs_sel_check(rx_prbs_sel_i, 1);
    end
    if (rx_prbs_sel_i != 3'b000) begin
      // self-synchronising: the next bit from the bits received, then the
      // bit received shifts in, right or wrong. One line error counts as
      // 3 (the bit, then at each tap).
      pred         = prbs_next(rx_prbs_lfsr, rx_prbs_sel_i);
      rx_prbs_lfsr = {rx_prbs_lfsr[29:0], b};
      if (!rx_prbs_synced) begin
        rx_prbs_good++;
        if (rx_prbs_good > 40) begin
          rx_prbs_synced = TRUE;
        end
      end
      else if (pred[0] != b) begin
        rx_prbs_err_acc = HI;
        rx_prbs_err_cnt++;
      end
      if (rx_prbs_cnt_reset_i) begin
        rx_prbs_err_cnt = 0;
        rx_prbs_err_acc = LO;
      end
    end

    if (comma_align_en && !comma_align_en_d) begin
      rx_aligned = LO;
    end
    comma_align_en_d = comma_align_en;

    // DS1001 Table 2.50: a comma off the boundary realigns, at any time
    // while alignment is on
    matched = FALSE;
    if (comma_align_en && rx_bits_seen >= 10) begin
      if (rx_mcomma_align_i && ((rx_shift & COMMA_MASK) == (ALIGN_MCOMMA_VALUE & COMMA_MASK))) begin
        matched = TRUE;
      end
      if (rx_pcomma_align_i && ((rx_shift & COMMA_MASK) == (ALIGN_PCOMMA_VALUE & COMMA_MASK))) begin
        matched = TRUE;
      end
    end

    if (matched) begin
      // a new bit position, or a new lane (ALIGN_COMMA_WORD)
      if ((rx_bit_cnt != 9) || ((rx_sym_cnt % COMMA_LANES) != 0)) begin
        rx_realign_pend = HI;
        if (BHV_VERBOSE) begin
          $display("[%0t] %m: RX byte alignment %s", $time, rx_aligned ? "moved" : "acquired");
        end
      end
      rx_bit_cnt = 9;
      rx_sym_cnt = rx_sym_cnt - (rx_sym_cnt % COMMA_LANES);
      rx_aligned = HI;
    end

    if (rx_slide_i && !rx_slide_pending && (RX_SLIDE_MODE != 0)) begin
      rx_slide_pending = TRUE;
      rx_aligned       = LO;  // the boundary moved off the comma
      if (RX_SLIDE_MODE[0]) begin
        rx_bit_cnt = (rx_bit_cnt + 9) % 10;  // a bit
      end
      else begin
        rx_sym_cnt = (rx_sym_cnt + RX_BYTES - 1) % RX_BYTES;  // a byte
      end
    end
    if (!rx_slide_i) begin
      rx_slide_pending = FALSE;
    end

    if (rx_bit_cnt == 9) begin
      rx_word[rx_sym_cnt*10+:10] = rx_shift;
      rx_bit_cnt                 = 0;
      if (rx_sym_cnt == (RX_BYTES - 1)) begin
        rx_sym_cnt = 0;
        rx_word_q.push_back(rx_word);
        ->rx_word_done;
      end
      else begin
        rx_sym_cnt++;
      end
    end
    else begin
      rx_bit_cnt++;
    end
  endtask

  task automatic rx_bits_stop();
    rx_bit_cnt      = 0;
    rx_sym_cnt      = 0;
    rx_bits_seen    = 0;
    rx_word_started = FALSE;
    rx_aligned      = LO;
    rx_prbs_reset();
  endtask

  // RX_BYTE_IS_ALIGNED_O, RX_BYTE_REALIGN_O (a clock per move) and
  // RX_PRBS_ERR_O (a clock with an error since the clock before), on
  // CLK_CORE_RX_I. RX_BYTE_IS_ALIGNED_O tells of the aligner: it leads the
  // aligned data out by the RX buffer and BHV_RX_PIPE_STAGES.
  always @(posedge clk_core_rx_i or negedge rx_pcs_rst_n) begin : rx_status
    if (!rx_pcs_rst_n) begin
      rx_realign_pend       = LO;
      rx_prbs_err_acc       = LO;
      rx_byte_is_aligned_o <= LO;
      rx_byte_realign_o    <= LO;
      rx_prbs_err_o        <= LO;
    end
    else begin
      rx_byte_is_aligned_o <= rx_aligned;
      rx_byte_realign_o    <= rx_realign_pend;
      rx_prbs_err_o        <= rx_prbs_err_acc;
      rx_realign_pend       = LO;
      rx_prbs_err_acc       = LO;
    end
  end

  //=========================================================================
  // RX: the receivers, by CDR_MODEL. ACCURATE: a sampler every UI, steered
  // by a CDR loop. FAST: bits from the time between line edges, at the
  // ideal phase. NONE: whole words from the side channel.
  //=========================================================================
  real rx_last_sample_t;
  real rx_phase_adj;
  real rx_err;  // last phase error, for the waveform
  int  rx_lock_cnt;
  int  rx_bad_cnt;  // edges off the bit grid in a row
  bit  rx_cdr_locked_r;
  bit  rx_sampler_run;

  always @(rx_cdr_locked_r or pll_locked or rx_pma_rst_n or rx_cdr_rst_n or rx_ei_filt) begin : rx_run
    rx_cdr_locked  = rx_cdr_locked_r | (RX_CDR_FORCE_LOCK != 0);
    rx_sampler_run = pll_locked & rx_pma_rst_n & rx_cdr_rst_n & ~rx_ei_filt;
  end

  // a receiver stops: the deserializer and the CDR start over
  task automatic rx_stop();
    rx_bits_stop();
    rx_cdr_locked_r = LO;
    rx_lock_cnt     = 0;
    rx_bad_cnt      = 0;
    rx_phase_adj    = 0.0;
  endtask

  // BHV_CDR_LOCK_EDGES edges on the bit grid lock the CDR; as many off it
  // in a row lose the lock
  task automatic rx_lock_count();
    rx_bad_cnt = 0;
    if (rx_lock_cnt < BHV_CDR_LOCK_EDGES) begin
      rx_lock_cnt++;
    end
    else if (!rx_cdr_locked_r) begin
      rx_cdr_locked_r = HI;
      if (BHV_VERBOSE) begin
        $display("[%0t] %m: RX CDR locked", $time);
      end
    end
  endtask

  task automatic rx_bad_edge();
    rx_lock_cnt = 0;
    if (rx_bad_cnt < BHV_CDR_LOCK_EDGES) begin
      rx_bad_cnt++;
    end
    else if (rx_cdr_locked_r) begin
      rx_cdr_locked_r = LO;
      if (BHV_VERBOSE) begin
        $display("[%0t] %m: RX CDR lost lock", $time);
      end
    end
  endtask

  //-------------------------------------------------------------------------
  // CDR_MODEL = ACCURATE: a sampler every UI, steered by a CDR loop
  //-------------------------------------------------------------------------
  always @(rx_pad_p) begin : rx_cdr_phase_detector
    real e;
    if (CDR_MODEL == ACCURATE) begin
      if (rx_sampler_run && (ui > 0.0)) begin
        e = $realtime - (rx_last_sample_t + (ui / 2.0));
        while (e > ui / 2.0) begin
          e = e - ui;
        end
        while (e <= -ui / 2.0) begin
          e = e + ui;
        end

        rx_err       = e;
        rx_phase_adj = rx_phase_adj + e * BHV_CDR_KP;

        if ((e < ui / 4.0) && (e > -ui / 4.0)) begin
          rx_lock_count();
        end
        else begin
          rx_bad_edge();
        end
      end
    end
  end

  initial if (CDR_MODEL == ACCURATE) begin : rx_accurate_sampler
    real step;
    forever begin
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
        rx_bit_in(rx_pad_p ^ rx_polarity_i);
      end
      else begin
        rx_stop();
        @(rx_sampler_run or pll_locked);
      end
    end
  end

  //-------------------------------------------------------------------------
  // CDR_MODEL = FAST: an ideal sampler. Bit centres on a grid of UIs, taken
  // in bulk at each line edge. An edge within UI/4 of the grid moves the
  // grid to it (the CDR, at once); others, like a glitch, do not, until
  // the lock is lost: then the next edge starts a new grid. 8b/10b runs
  // are 5 bits at most, so a word is late by 5 UI at most. At a stop
  // (electrical idle) the bits up to it are taken first, as ACCURATE's
  // sampler does.
  //-------------------------------------------------------------------------
  real rx_fast_grid_t = -1.0;  // a bit boundary; < 0: none yet
  int  rx_fast_grid_n;         // bits taken since it
  bit  rx_fast_level;          // the line since the last edge
  real rx_fast_x;              // now, in UI since the grid

  // the bits whose centres lie before now
  task automatic rx_fast_take();
    int n;
    rx_fast_x = ($realtime - rx_fast_grid_t) / ui;
    n         = int'($ceil(rx_fast_x - 0.5));
    for (int i = rx_fast_grid_n; i < n; i++) begin
      rx_bit_in(rx_fast_level ^ rx_polarity_i);
    end
    rx_fast_grid_n = n;
  endtask

  always @(rx_pad_p or negedge rx_sampler_run) begin : rx_fast_sampler
    real x;
    if (CDR_MODEL == FAST) begin
      if (!rx_sampler_run) begin
        if ((rx_fast_grid_t >= 0.0) && (ui > 0.0)) begin
          rx_fast_take();
        end
        rx_fast_grid_t = -1.0;
        rx_stop();
      end
      else if (ui > 0.0) begin
        if (rx_fast_grid_t >= 0.0) begin
          rx_fast_take();
          x = rx_fast_x;
          if ((x - $floor(x + 0.5) < 0.25) && (x - $floor(x + 0.5) > -0.25)) begin
            rx_fast_grid_t = $realtime;
            rx_fast_grid_n = 0;
            rx_lock_count();
          end
          else begin
            rx_bad_edge();
            if (!rx_cdr_locked_r && (rx_bad_cnt >= BHV_CDR_LOCK_EDGES)) begin
              rx_fast_grid_t = $realtime;  // lost: a new grid from here
              rx_fast_grid_n = 0;
              rx_bad_cnt     = 0;
            end
          end
        end
        else begin
          rx_fast_grid_t = $realtime;
          rx_fast_grid_n = 0;
        end
        rx_fast_level = rx_pad_p;
      end
    end
  end

  //-------------------------------------------------------------------------
  // CDR_MODEL = NONE. Enumeration first: after the start bit, the next
  // CDR_NONE_ID_BITS edges of P clock the peer's ID in from N, for good;
  // not gated by resets or idle, it comes once, before the PLLs lock. Then
  // the peer's words come through the package: at each count of
  // cdr_none_words[peer] a word starts, and this RX reads it from
  // cdr_none_last[peer]; any number of receivers can listen to one TX.
  // Each word is handed to the deserializer as a line would: the bits up
  // to the next word boundary of the comma alignment when that boundary
  // passes, the rest when the next word starts, or half a UI after the
  // word ends if none does (idle). So the latency is a line's at any
  // alignment phase, with no wire delay. TX and RX words must be as wide.
  // P and N are quiet then: an edge on P is a glitch on the line, like the
  // testbench's flip, and inverts the bits it covers.
  //-------------------------------------------------------------------------
  real       rx_none_word_t = -1.0;  // the last word started here
  bit [79:0] rx_none_flips;          // the bits a glitch inverted since
  real       rx_none_glitch_t;       // a glitch started here
  bit        rx_none_glitch;         // ... and is on
  bit        rx_none_open;           // a word started at rx_none_word_t

  // the TX this RX hears: the peer, or with PMA loopback itself
  function automatic int rx_none_peer();
    return pma_loopback ? cdr_none.my_id : cdr_none.peer_id;
  endfunction

  // the bits whose centres lie in [t0, t1), with a margin for rounding
  task automatic rx_none_flip(real t0, real t1);
    int k0, k1;
    k0 = int'($ceil((t0 - rx_none_word_t) / ui - 0.5 - 1.0e-6));
    k1 = int'($ceil((t1 - rx_none_word_t) / ui - 0.5 - 1.0e-6));
    for (int k = (k0 < 0) ? 0 : k0; k < k1 && k < 80; k++) begin
      rx_none_flips[k] = ~rx_none_flips[k];
    end
  endtask

  bit [79:0] rx_none_w;    // the word on the line
  int        rx_none_pos;  // its bits handed to the deserializer so far

  // its bits [rx_none_pos, upto), with what a glitch inverted
  task automatic rx_none_feed(int upto);
    if (rx_none_glitch) begin  // still on: what it covered so far
      rx_none_flip(rx_none_glitch_t, $realtime);
      rx_none_glitch_t = $realtime;
    end
    for (int b = rx_none_pos; b < upto; b++) begin
      rx_bit_in(rx_none_w[b] ^ rx_none_flips[b]);
    end
    rx_none_pos = upto;
  endtask

  real rx_none_last_t = -1.0e9;  // the peer's last word started here

  // the peer's word that started last, from bit pos: the bits up to the
  // next word boundary of the comma alignment when that boundary passes;
  // the rest comes from rx_none_words
  task automatic rx_none_start(int p, int pos);
    int r;
    if (rx_none_open) begin
      rx_none_feed(10 * RX_BYTES);  // the rest of the word before
    end
    rx_none_word_t = rx_none_last_t;
    rx_none_flips  = '0;
    rx_none_pos    = pos;
    rx_none_open   = FALSE;
    if (cdr_none_bytes[p] != RX_BYTES) begin
      $fatal(1, "%m: CDR_MODEL = NONE: the TX sends %0d symbols a word, this RX takes %0d",
             cdr_none_bytes[p], RX_BYTES);
    end
    if (cdr_none_words[p] > 0) begin
      rx_none_w       = cdr_none_last[p] ^ {80{rx_polarity_i}};
      rx_none_open    = TRUE;
      rx_cdr_locked_r = HI;  // no CDR: locked with the first word
      rx_word_start();
      r = (10 - rx_bit_cnt) + 10 * (RX_BYTES - 1 - rx_sym_cnt);
      if (pos + r < 10 * RX_BYTES) begin
        #(rx_none_word_t + (pos + r) * ui - $realtime);
        if (rx_none_open) begin
          rx_none_feed(pos + r);
        end
      end
    end
  endtask

  // the pins: enumeration, then glitches
  initial if (CDR_MODEL == NONE) begin : rx_none_pins
    int id;
    do begin
      @(rx_pad_p);
    end while (!rx_pad_n);
    id = 0;
    for (int i = 0; i < CDR_NONE_ID_BITS; i++) begin
      @(rx_pad_p);
      id[i] = rx_pad_n;
    end
    cdr_none.peer_id = id;
    if (loopback_i[0] && (TX_PMA_LOOPBACK == 0)) begin
      $warning("%m: CDR_MODEL = NONE: PMA loopback at enumeration (1 to 10 ns): the peer is unknown");
    end

    forever begin
      @(rx_pad_p or negedge rx_sampler_run);
      if (!rx_sampler_run) begin
        rx_none_word_t = -1.0;
        rx_none_glitch = FALSE;
        rx_none_open   = FALSE;
        rx_stop();
      end
      else if (rx_none_open && !rx_none_glitch) begin
        rx_none_glitch   = TRUE;
        rx_none_glitch_t = $realtime;
      end
      else if (rx_none_open) begin
        rx_none_glitch = FALSE;
        rx_none_flip(rx_none_glitch_t, $realtime);
      end
    end
  end

  event rx_none_never;  // never triggered

  // the words, once enumeration (by 10.5 ns) found a peer; a TX sends no
  // word before its enumeration ends
  initial if (CDR_MODEL == NONE) begin : rx_none_words
    int  p, n;
    real tail;
    bit  ended;
    fork
      wait ((pma_loopback ? cdr_none.my_id : cdr_none.peer_id) >= 0);
      #20.0;
    join_any
    disable fork;
    if (!cdr_none_valid(rx_none_peer())) begin
      $warning("%m: CDR_MODEL = NONE, but no peer: is the far end NONE too?");
    end
    forever begin
      // the signals themselves: a wait does not look into functions
      wait ((pma_loopback ? cdr_none.my_id : cdr_none.peer_id) >= 0);
      p     = rx_none_peer();
      n     = cdr_none_words[p];
      tail  = rx_none_word_t + (10.0 * RX_BYTES + 0.5) * ui - $realtime;
      ended = FALSE;
      fork
        begin
          @(cdr_none_words[p] or pma_loopback or posedge rx_sampler_run);
        end
        begin
          if (rx_none_open) begin  // no next word: the rest after the word end
            #((tail > 0.0) ? tail : 0.0);
            ended = TRUE;
          end
          else begin
            @(rx_none_never);
          end
        end
      join_any
      disable fork;
      if (ended) begin
        if (rx_none_open) begin
          rx_none_feed(10 * RX_BYTES);
          rx_none_open = FALSE;
        end
      end
      else if (p == rx_none_peer() && cdr_none_words[p] != n) begin  // a word starts
        rx_none_last_t = $realtime;
        rx_ei_filt     = LO;
        rx_ei_quiet    = TRUE;  // idle again unless a word comes in the window
        rx_ei_deadline = $realtime + (EI_WINDOW_UI * ui);
        if (rx_sampler_run && (ui > 0.0)) begin
          rx_none_start(p, 0);
        end
      end
      else if (rx_sampler_run && (ui > 0.0) && !rx_none_open
               && ($realtime < rx_none_last_t + 10 * RX_BYTES * ui)) begin
        // the receiver starts inside a word: the bits still to come
        rx_none_start(p, int'($ceil(($realtime - rx_none_last_t) / ui - 0.5 - 1.0e-6)));
      end
    end
  end

  //=========================================================================
  // RX: recovered clock. It rises with each word the deserializer
  // completes, so it follows the far end's rate (RX_CLK_O); with the
  // sampler stopped it runs from the local PLL. Words wait in rx_word_q, so
  // two that complete within one clock (a slide, a bulk take) both go out.
  //=========================================================================
  always begin : rx_rec_clk_gen
    if (rx_word_q.size() != 0) begin
      if (clk_core_rx_o) begin  // high from the PLL: an edge first
        clk_core_rx_o = LO;
        #(ui);
      end
      rx_word_c     = rx_word_q.pop_front();
      clk_core_rx_o = HI;
      #(ui * 5.0 * RX_BYTES);
      clk_core_rx_o = LO;
      if (rx_word_q.size() != 0) begin
        #(ui);  // a word waits: a short low phase
      end
    end
    else if (rx_sampler_run && (ui > 0.0)) begin
      @(rx_word_done or negedge rx_sampler_run);
    end
    else if (pll_locked && (core_period > 0.0)) begin
      #(core_period / 2.0);
      clk_core_rx_o = ~clk_core_rx_o;
    end
    else begin
      clk_core_rx_o = LO;
      @(pll_locked or rx_sampler_run or rx_word_done);
    end
  end

  //=========================================================================
  // RX: 8b/10b decoder, run by the buffer's write side on the recovered
  // clock, after it took the word before
  //=========================================================================
  rx_word_t rx_dec;     // the decoded word
  bit       rx_dec_rd;  // running disparity

  // Bypassed, a symbol's bits 8 and 9 come out on RX_CHAR_IS_K_O and
  // RX_DISP_ERR_O (DS1001 Figure 2.39). Decoded, the running disparity is
  // checked per 6b and 4b sub-block (dec_disp).
  task automatic rx_decode();
    rx_byte_t b;
    bit [9:0] sym, ent;
    bit [1:0] dr;
    for (int i = 0; i < 8; i++) begin
      b = '0;
      if (i < RX_BYTES) begin
        sym = rx_word_c[i*10+:10];
        if (!rx_8b10b_en_i || rx_8b10b_bypass_i[i]) begin
          b.d    = sym[7:0];
          b.k    = sym[8];
          b.disp = sym[9];
        end
        else begin
          ent       = dec_lut[sym];
          dr        = rx_dec_rd ? dec_rd[sym][3:2] : dec_rd[sym][1:0];
          b.d       = ent[7:0];
          b.k       = ent[8];
          b.nit     = ~ent[9];
          b.comma   = ent[8] && ((ent[7:0] == 8'h3C) || (ent[7:0] == 8'hBC) || (ent[7:0] == 8'hFC));
          b.disp    = dr[1];
          rx_dec_rd = dr[0];
        end
      end
      rx_dec[i] = b;  // Icarus 13.0 takes no rx_dec[i].field with a variable i
    end
  endtask

  //=========================================================================
  // RX: elastic buffer (DS1001 2.5.6.8)
  //
  // A queue of decoded words: written on the recovered clock, read on
  // CLK_CORE_RX_I. Each side takes the other's word count 2 clocks late.
  // - The first words after a buffer reset were never written: 0 here,
  //   flagged by eb_r_stale. Such a word might be a correction word: when
  //   it could stall the read, eb_r_lost flags all until the next reset.
  // - RX_BUF_BYPASS and RX_CLKCOR_USE apply at a buffer reset ($warning
  //   on a change without one); a bad RX_BUF_CFG stops the simulation
  //   there (rx_buf_cfg_errors).
  // - After RX_BUF_ERR_O the data is undefined until a buffer reset.
  // - The queue is bounded (EB_DEPTH): with CLK_CORE_RX_I stopped, the
  //   oldest go, and RX_BUF_ERR_O follows.
  //
  // Buffer mode: reading starts MIN words behind. Occupancy below 3 or
  // above 60 sets RX_BUF_ERR_O. Clock correction (RX_CLKCOR_USE = 1):
  // - above MAX, the second of two correction words in a row is dropped;
  // - below MIN - 1, a correction word stalls the read for a clock, and
  //   the word before it is repeated.
  // Without clock correction MIN and MAX are 4 and 60.
  // Bypass mode: one write stage, reads while not empty, full sets
  // RX_BUF_ERR_O.
  //
  // Each side is one process with blocking assignments, in reverse
  // pipeline order. Only what crosses to the other side is non-blocking.
  //=========================================================================
  bit       eb_w_rst_n, eb_r_rst_n;
  rx_word_t eb_r_word;
  bit       eb_r_stale, eb_r_lost, eb_r_err;

  rx_word_t eb_q[$];    // the words in the buffer
  int       eb_q_head;  // the number of eb_q[0]
  int       eb_w_pub;   // words written, as the read side gets it
  int       eb_r_pub;   // words read, as the write side gets it
  bit       eb_w_full;  // bypass mode: the buffer ran full
  bit       eb_w_ovf;   // the queue overflowed: the read side stopped

  localparam int EB_DEPTH = 64 + 8;  // 64 words, and those still crossing

  // RX_BUF_RESET: on at once, off 2 clocks later on each side
  always begin : eb_w_rst_seq
    eb_w_rst_n = LO;
    wait (rx_buf_rst_n);
    fork
      begin
        repeat (2) @(posedge clk_core_rx_o);
        eb_w_rst_n <= HI;
      end
    join_none
    @(negedge rx_buf_rst_n);
    disable fork;
  end

  always begin : eb_r_rst_seq
    eb_r_rst_n = LO;
    wait (rx_buf_rst_n);
    fork
      begin
        repeat (2) @(posedge clk_core_rx_i);
        eb_r_rst_n <= HI;
        chk_stop(rx_buf_cfg_errors(csr.rx_buf_cfg), "RX_BUF_CFG");
      end
    join_none
    @(negedge rx_buf_rst_n);
    disable fork;
  end

  // MIN after a buffer reset, and the clock-correction sequence
  function automatic bit [5:0] buf_min();
    return csr.rx_buf_cfg.clkcor_use ? csr.rx_buf_cfg.min_lat : 6'd4;
  endfunction

  function automatic bit [3:0][9:0] clkcor_seq();
    return {csr.rx_clkcor_seq[3][9:0], csr.rx_clkcor_seq[2][9:0], csr.rx_clkcor_seq[1][9:0],
            csr.rx_clkcor_seq[0][9:0]};
  endfunction

  always @(csr.rx_buf_cfg.bypass or csr.rx_buf_cfg.clkcor_use) begin
    if (eb_w_rst_n === HI || eb_r_rst_n === HI) begin
      $warning("%m: RX_BUF_BYPASS/RX_CLKCOR_USE change applies at the next RX_BUF_RESET");
    end
  end

  //-------------------------------------------------------------------------
  // write side: two stages, then into the queue; then the decoder
  //-------------------------------------------------------------------------
  bit       eb_w_bypass, eb_w_clkcor;  // taken at the buffer reset
  rx_word_t eb_w_d, eb_w_d2;           // the two stages
  bit       eb_w_match_d;              // eb_w_d2 is a correction word
  bit       eb_w_en;                   // the next word goes in
  int       eb_w_cnt;                  // words written, from MIN (0 in bypass)
  int       eb_w_rcnt[2];              // eb_r_pub, 1 and 2 clocks late
  bit [5:0] eb_w_occ;

  always @(posedge clk_core_rx_o or negedge rx_core_rst_n) begin : eb_write
    bit m, en;
    bit [5:0] max;
    if (!rx_core_rst_n || !eb_w_rst_n) begin
      // a core reset clears the counts, a buffer reset sets them to MIN
      eb_q.delete();
      eb_q_head    = (!rx_core_rst_n || csr.rx_buf_cfg.bypass) ? 0 : int'(buf_min());
      eb_w_bypass  = csr.rx_buf_cfg.bypass;
      eb_w_clkcor  = csr.rx_buf_cfg.clkcor_use;
      eb_w_d       = '0;
      eb_w_d2      = '0;
      eb_w_match_d = LO;
      eb_w_en      = HI;
      eb_w_cnt     = (!rx_core_rst_n || csr.rx_buf_cfg.bypass) ? 0 : int'(buf_min());
      eb_w_pub    <= (!rx_core_rst_n || csr.rx_buf_cfg.bypass) ? 0 : int'(buf_min()) + 2;
      eb_w_rcnt[0] = 0;
      eb_w_rcnt[1] = 0;
      eb_w_occ     = !rx_core_rst_n ? 6'd0 : buf_min();
      eb_w_full   <= LO;
      eb_w_ovf    <= LO;
    end
    else begin
      max = eb_w_clkcor ? csr.rx_buf_cfg.max_lat : 6'd60;
      m   = clkcor_match(eb_w_d, clkcor_seq(), RX_DATAPATH_SEL);
      // the second of two correction words in a row is not written
      en  = !(m && eb_w_match_d && eb_w_clkcor && (eb_w_occ > max));
      if (eb_w_bypass && eb_w_en && !eb_w_full && (7'(eb_w_pub - eb_w_rcnt[1]) == 7'd64)) begin
        eb_w_full <= HI;
      end
      if (eb_w_en) begin
        eb_q.push_back(eb_w_bypass ? eb_w_d : eb_w_d2);
        if (eb_q.size() > EB_DEPTH) begin
          void'(eb_q.pop_front());
          eb_q_head++;
          eb_w_ovf <= HI;
        end
      end
      eb_w_pub <= eb_w_bypass ? eb_w_cnt : eb_w_cnt + 2;
      if (!eb_w_bypass) begin
        eb_w_occ     = 6'(eb_w_cnt - eb_w_rcnt[1]);
        eb_w_d2      = dp_keep(eb_w_d2, eb_w_d, RX_DATAPATH_SEL);
        eb_w_match_d = m;
      end
      eb_w_cnt     = eb_w_cnt + int'(eb_w_en);
      eb_w_en      = en;
      eb_w_rcnt[1] = eb_w_rcnt[0];
      eb_w_rcnt[0] = eb_r_pub;
      eb_w_d       = dp_keep(eb_w_d, rx_dec, RX_DATAPATH_SEL);
    end
    if (rx_pcs_rst_n) begin
      rx_decode();
    end
  end

  //-------------------------------------------------------------------------
  // read side: the front word, two stages to the outputs, then an output
  // delay of BHV_RX_PIPE_STAGES clocks, for data and RX_BUF_ERR_O alike
  //-------------------------------------------------------------------------
  bit       eb_r_bypass, eb_r_clkcor;          // taken at the buffer reset
  rx_word_t eb_r_q, eb_r_d, eb_r_d2;           // front word, next stage, held copy
  bit       eb_r_q_st, eb_r_d_st, eb_r_d2_st;  // ... is stale
  bit       eb_r_match;                        // eb_r_q is a correction word
  bit       eb_r_en, eb_r_en_d;                // the read moves on
  int       eb_r_cnt;                          // words read
  int       eb_r_wcnt[2];                      // eb_w_pub, 1 and 2 clocks late
  bit [5:0] eb_r_occ;
  bit       eb_r_empty_d1, eb_r_empty_d2, eb_r_full1, eb_r_full2;

  rx_word_t rx_pipe[$];
  rx_word_t rx_pipe_o;
  bit       rx_err_pipe[$];
  bit       rx_err_pipe_o;

  // RX_PCS_RESET: the decoder and the output delay start over
  always @(negedge rx_pcs_rst_n) begin
    rx_dec    = '0;
    rx_dec_rd = LO;
    rx_pipe.delete();
    rx_pipe_o = '0;
    rx_err_pipe.delete();
    rx_err_pipe_o = LO;
  end

  always @(posedge clk_core_rx_i or negedge rx_core_rst_n) begin : eb_read
    bit       empty, low, d_st;
    bit [5:0] min;
    rx_word_t d;
    if (!rx_core_rst_n) begin
      eb_r_bypass   = csr.rx_buf_cfg.bypass;
      eb_r_clkcor   = csr.rx_buf_cfg.clkcor_use;
      eb_r_q        = '0;
      eb_r_d        = '0;
      eb_r_d2       = '0;
      eb_r_q_st     = LO;
      eb_r_d_st     = LO;
      eb_r_d2_st    = LO;
      eb_r_en_d     = LO;
      eb_r_cnt      = 0;
      eb_r_pub     <= 0;
      eb_r_wcnt[0]  = 0;
      eb_r_wcnt[1]  = 0;
      eb_r_occ      = '0;
      eb_r_empty_d1 = HI;
      eb_r_empty_d2 = HI;
      eb_r_full1    = LO;
      eb_r_full2    = LO;
      eb_r_err      = LO;
      eb_r_word     = '0;
      eb_r_stale    = LO;
      eb_r_lost     = LO;
    end
    else begin
      if (rx_pcs_rst_n) begin
        rx_pipe.push_back(eb_r_word);
        rx_err_pipe.push_back(eb_r_err);
        if (rx_pipe.size() >= BHV_RX_PIPE_STAGES) begin
          rx_pipe_o     = rx_pipe.pop_front();
          rx_err_pipe_o = rx_err_pipe.pop_front();
        end
      end

      min        = eb_r_clkcor ? csr.rx_buf_cfg.min_lat : 6'd4;
      low        = eb_r_clkcor && !eb_r_bypass && (eb_r_occ < 6'(min - 6'd1));
      eb_r_match = !eb_r_q_st && !eb_r_bypass && clkcor_match(eb_r_q, clkcor_seq(), RX_DATAPATH_SEL);
      empty      = (7'(eb_r_wcnt[1]) == 7'(eb_r_pub));
      eb_r_en    = eb_r_bypass ? (!empty && !eb_r_empty_d2) : !(eb_r_match && low);

      if (!eb_r_rst_n) begin
        eb_r_bypass   = csr.rx_buf_cfg.bypass;
        eb_r_clkcor   = csr.rx_buf_cfg.clkcor_use;
        eb_r_err      = LO;
        eb_r_word     = '0;
        eb_r_stale    = LO;
        eb_r_lost     = LO;
      end
      else begin
        if ((eb_r_occ > 6'd60) || (eb_r_occ < 6'd3 && !eb_r_bypass) || eb_r_full2 || eb_w_ovf) begin
          eb_r_err = HI;
        end
        eb_r_word  = dp_keep(eb_r_word, eb_r_d, RX_DATAPATH_SEL);
        eb_r_stale = eb_r_d_st || eb_r_lost;
        // a stale word might be a correction word, and stall the read
        if (eb_r_q_st && low) begin
          eb_r_lost = HI;
        end
      end

      // after a stall, the held copy unless the word is a correction
      // word; a stale word may be one, so the pick is stale too
      if (!eb_r_en_d && !eb_r_match) begin
        d    = eb_r_d2;
        d_st = eb_r_d2_st || eb_r_q_st;
      end
      else begin
        d    = eb_r_q;
        d_st = eb_r_q_st;
      end

      // the held copy moves in a buffer reset too
      if (!eb_r_en) begin
        eb_r_d2    = dp_keep(eb_r_d2, eb_r_d, RX_DATAPATH_SEL);
        eb_r_d2_st = eb_r_d_st;
      end

      if (!eb_r_rst_n) begin
        eb_r_d        = '0;
        eb_r_d_st     = LO;
        eb_r_en_d     = LO;
        eb_r_cnt      = 0;
        eb_r_pub     <= 0;
        eb_r_wcnt[0]  = csr.rx_buf_cfg.bypass ? 0 : int'(buf_min()) + 2;
        eb_r_wcnt[1]  = eb_r_wcnt[0];
        eb_r_occ      = buf_min();
        eb_r_empty_d1 = HI;
        eb_r_empty_d2 = HI;
        eb_r_full1    = LO;
        eb_r_full2    = LO;
      end
      else begin
        eb_r_d    = dp_keep(eb_r_d, d, RX_DATAPATH_SEL);
        eb_r_d_st = d_st;
        if (!eb_r_bypass) begin
          eb_r_occ = 6'(eb_r_wcnt[1] - eb_r_cnt);
        end
        else begin
          eb_r_empty_d2 = eb_r_empty_d1;
          eb_r_empty_d1 = empty;
          eb_r_full2    = eb_r_full1;
          eb_r_full1    = eb_w_full;
        end
        eb_r_pub    <= eb_r_cnt + 2;
        eb_r_wcnt[1] = eb_r_wcnt[0];
        eb_r_wcnt[0] = eb_w_pub;
      end

      // the word numbered eb_r_cnt, stale if not written yet; it moves in
      // a buffer reset too
      while ((eb_q.size() != 0) && (eb_q_head < eb_r_cnt)) begin
        void'(eb_q.pop_front());
        eb_q_head++;
      end
      if (eb_r_rst_n && (eb_q.size() != 0) && (eb_q_head == eb_r_cnt)) begin
        eb_r_q    = dp_keep(eb_r_q, eb_q[0], RX_DATAPATH_SEL);
        eb_r_q_st = LO;
      end
      else begin
        eb_r_q    = dp_keep(eb_r_q, '0, RX_DATAPATH_SEL);
        eb_r_q_st = HI;
      end

      if (eb_r_rst_n) begin
        eb_r_en_d = eb_r_en;
        eb_r_cnt  = eb_r_cnt + int'(eb_r_en);
      end
    end
  end

  //=========================================================================
  // RX: outputs, BHV_RX_TCO_NS after the clock
  //=========================================================================
  always @(eb_r_word or rx_pipe_o or eb_r_err or rx_err_pipe_o) begin : rx_outputs
    rx_word_t  w;
    rx_byte_t  b;
    bit [63:0] d;
    bit [ 7:0] k, c, nit, disp;
    bit        err;
    w   = (BHV_RX_PIPE_STAGES == 0) ? eb_r_word : rx_pipe_o;
    err = (BHV_RX_PIPE_STAGES == 0) ? eb_r_err : rx_err_pipe_o;
    for (int i = 0; i < 8; i++) begin
      b         = w[i];  // Icarus 13.0 takes no w[i].field
      d[i*8+:8] = b.d;
      k[i]      = b.k;
      c[i]      = b.comma;
      nit[i]    = b.nit;
      disp[i]   = b.disp;
    end
    rx_data_o          <= #(BHV_RX_TCO_NS) d;
    rx_char_is_k_o     <= #(BHV_RX_TCO_NS) k;
    rx_char_is_comma_o <= #(BHV_RX_TCO_NS) c;
    rx_not_in_table_o  <= #(BHV_RX_TCO_NS) nit;
    rx_disp_err_o      <= #(BHV_RX_TCO_NS) disp;
    rx_buf_err_o       <= #(BHV_RX_TCO_NS) err;
  end

  //#########################################################################
  // Receiver detection
  //#########################################################################

  // TX_DETECT_RX_I high for BHV_RX_DETECT_TIME_NS: done, with the far end
  // present or not; low: both clear
  initial begin : rx_detect
    forever begin
      @(posedge tx_detect_rx_i);
      fork
        begin
          #(BHV_RX_DETECT_TIME_NS);
          rx_present_o     = (BHV_RX_PRESENT != 0);
          rx_detect_done_o = HI;
          if (BHV_VERBOSE) begin
            $display("[%0t] %m: receiver detect done, present=%b", $time, rx_present_o);
          end
        end
      join_none
      @(negedge tx_detect_rx_i);
      disable fork;
      rx_detect_done_o = LO;
      rx_present_o     = LO;
    end
  end

  task automatic scan();
    scan_out_o = scan_enable_i ? scan_in_i : 7'h0;
  endtask

  initial scan();
  always @(scan_enable_i or scan_in_i) scan();

endmodule

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
