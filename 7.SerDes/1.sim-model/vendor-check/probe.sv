// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

`timescale 1ns/100fs
// Port-level probe: the same TB runs the vendor model or our BFM (same
// module name and ports). Run by vendor-check.sh probe; a stimulus from stims/.
module tb;
  parameter int       DP     = 3;      // TX/RX_DATAPATH_SEL
  parameter int       AW     = 0;      // ALIGN_COMMA_WORD
  parameter int       SLIDE  = 0;      // RX_SLIDE_MODE
  parameter int       PRESC  = 0;
  parameter int       WAITL  = 1;
  parameter int       BWSEL  = 4;
  parameter int       EIBIAS = 4;
  parameter int       PMALB  = 0;
  parameter int       CFGSEL = 0;
  parameter int       REFBYP = 0;
  parameter int       CLKCOR = 0;
  parameter int       BUFBYP = 0;
  parameter int       FCNTRL = 58;
  parameter int       TXDP   = DP;

  localparam int LANES = (DP == 0) ? 2 : (DP == 1) ? 4 : 8;

  reg clk_ref = 0, clk_reg = 0;
  always #5 clk_ref = ~clk_ref;
  always #5 clk_reg = ~clk_reg;
  reg arst_n = 1, cfg_en = 0, cfg_valid = 0, cfg_rst = 0;
  reg [7:0] cfg_addr = 0;
  reg [15:0] cfg_di = 0;
  reg tx_rst = 0, rx_rst = 0, tx_pcs = 0, tx_pma = 0, rx_pma = 0, rx_eqa = 0, rx_cdr = 0, rx_pcs = 0, rx_buf = 0;
  reg pll_rst = 0;
  reg [2:0] lb = 0;
  reg txpd = 1, rxpd = 1, tx_ei = 0, tx_det = 0;
  reg [2:0] tx_prbs = 0, rx_prbs = 0;
  reg force_err = 0, prbs_cnt_rst = 0;
  reg ei_det = 0, comma_en = 1, slide = 0, mcomma = 1, pcomma = 1;
  reg tx_pol = 0, rx_pol = 0, tx_8en = 1, rx_8en = 1;
  reg [7:0] tx_byp = 0, rx_byp = 0, dmode = 0, dval = 0;
  reg we = 0, en = 0;
  reg [7:0] addr = 0;
  reg [15:0] di = 0, mask = 16'hFFFF;
  wire clk_pll, rcp_n, clk_rxo;
  wire [15:0] do_;
  wire rdy;
  wire txp, txn, txdone, rxdone, tx_err, rx_err, aligned, realign, prbs_err, ei_o, det_done, det_pres;
  wire [63:0] rxd;
  wire [7:0] rxk, rxc, rxnit, rxdisp;
  reg  [63:0] txd = 0;
  reg  [7:0] txk = 0;
  reg  stop_tx_clk = 0, rx_clk_sel = 0;  // rx_clk_sel 1: RX_CLK_I = RX_CLK_O
  reg own_clk = 0, use_own = 0; real own_half = 16.0;
  always #(own_half) own_clk = ~own_clk;
  wire clk_tx = (use_own ? own_clk : clk_pll) & ~stop_tx_clk;
  wire clk_rx = rx_clk_sel ? clk_rxo : clk_pll;

  // the line: loopback with a delay; line_mode 0 wire, 1 X, 2 Z, 3 both 0
  real wd = 2.0;
  reg rxp_w = 0, rxn_w = 1;
  integer line_mode = 0;
  always @(txp) rxp_w <= #(wd) txp;
  always @(txn) rxn_w <= #(wd) txn;
  wire rxp = (line_mode == 0) ? rxp_w : (line_mode == 1) ? 1'bx : (line_mode == 2) ? 1'bz : 1'b0;
  wire rxn = (line_mode == 0) ? rxn_w : (line_mode == 1) ? 1'bx : (line_mode == 2) ? 1'bz : 1'b0;

  ccfpga_serdes #(
      .RX_DATAPATH_SEL(2'(DP)), .TX_DATAPATH_SEL(2'(TXDP)), .ALIGN_COMMA_WORD(2'(AW)),
      .RX_SLIDE_MODE(2'(SLIDE)), .RX_RESET_TIMER_PRESC(5'(PRESC)), .RX_WAIT_CDR_LOCK(WAITL),
      .RX_EI_BW_SEL(4'(BWSEL)), .RX_EI_BIAS(4'(EIBIAS)), .TX_PMA_LOOPBACK(PMALB),
      .PLL_CONFIG_SEL(CFGSEL), .PLL_REF_BYPASS(REFBYP), .PLL_FCNTRL(6'(FCNTRL)),
      .RX_CLKCOR_USE(CLKCOR), .RX_BUF_BYPASS(BUFBYP)
  ) dut (
    .clk_ref_i(clk_ref), .clk_reg_i(clk_reg), .clk_cfg_i(clk_reg),
    .clk_core_tx_i(clk_tx), .clk_core_rx_i(clk_rx), .clk_core_rx_o(clk_rxo),
    .reset_n_i(arst_n), .reset_reg_n_i(arst_n), .reset_core_tx_n_i(rcp_n), .reset_core_rx_n_i(rcp_n),
    .testmode_i(1'b0), .scan_enable_i(1'b0), .scan_in_i(7'h0), .scan_out_o(),
    .loopback_i(lb), .pll_reset_i(pll_rst), .clk_core_pll_o(clk_pll), .reset_core_pll_n_o(rcp_n),
    .refclk_sel_o(), .refclk_rterm_o(),
    .RX_SERIO_P_B(rxp), .RX_SERIO_N_B(rxn), .TX_SERIO_P_B(txp), .TX_SERIO_N_B(txn),
    .regfile_we_i(we), .regfile_en_i(en), .regfile_addr_i(addr), .regfile_mask_i(mask), .regfile_di_i(di),
    .regfile_do_o(do_), .regfile_rdy_o(rdy),
    .cfg_en_i(cfg_en), .reset_cfg_i(cfg_rst), .cfgfile_di_i(cfg_di), .cfgfile_valid_i(cfg_valid), .cfgfile_addr_i(cfg_addr),
    .tx_reset_i(tx_rst), .tx_pcs_reset_i(tx_pcs), .tx_pma_reset_i(tx_pma), .tx_elec_idle_i(tx_ei), .tx_detect_rx_i(tx_det),
    .tx_prbs_sel_i(tx_prbs), .tx_prbs_force_err_i(force_err), .tx_powerdown_n_i(txpd), .tx_data_i(txd),
    .tx_char_is_k_i(txk), .tx_polarity_i(tx_pol), .tx_8b10b_en_i(tx_8en), .tx_8b10b_bypass_i(tx_byp),
    .tx_char_dispmode_i(dmode), .tx_char_dispval_i(dval), .tx_buf_err_o(tx_err), .tx_resetdone_o(txdone),
    .rx_detect_done_o(det_done), .rx_present_o(det_pres), .TERM_SERIO_O(),
    .rx_reset_i(rx_rst), .rx_pma_reset_i(rx_pma), .rx_eqa_reset_i(rx_eqa), .rx_cdr_reset_i(rx_cdr), .rx_pcs_reset_i(rx_pcs), .rx_buf_reset_i(rx_buf),
    .rx_prbs_sel_i(rx_prbs), .rx_prbs_cnt_reset_i(prbs_cnt_rst), .rx_powerdown_n_i(rxpd), .rx_en_ei_detector_i(ei_det),
    .rx_comma_detect_en_i(comma_en), .rx_slide_i(slide), .rx_polarity_i(rx_pol), .rx_8b10b_en_i(rx_8en), .rx_8b10b_bypass_i(rx_byp),
    .rx_mcomma_align_i(mcomma), .rx_pcomma_align_i(pcomma), .rx_prbs_err_o(prbs_err), .rx_data_o(rxd), .rx_char_is_k_o(rxk), .rx_char_is_comma_o(rxc),
    .rx_not_in_table_o(rxnit), .rx_disp_err_o(rxdisp), .rx_buf_err_o(rx_err), .rx_byte_is_aligned_o(aligned), .rx_byte_realign_o(realign),
    .rx_resetdone_o(rxdone), .rx_ei_en_o(ei_o));

  // config / regfile access
  task cfgw(input [7:0] a, input [15:0] d);
    begin
      @(posedge clk_reg); cfg_en <= 1; cfg_addr <= a; cfg_di <= d; cfg_valid <= 1;
      @(posedge clk_reg); cfg_valid <= 0;
      @(posedge clk_reg); cfg_en <= 0;
      repeat (2) @(posedge clk_reg);
    end
  endtask
  integer rf_lat;
  reg [15:0] rf_v;
  task rd(input [7:0] a);
    begin
      @(posedge clk_reg); addr <= a; en <= 1; we <= 0;
      @(posedge clk_reg); en <= 0; rf_lat = 1;
      while (!rdy && rf_lat < 400) begin @(posedge clk_reg); rf_lat = rf_lat + 1; end
      rf_v = do_;
      repeat (2) @(posedge clk_reg);
    end
  endtask
  task wr(input [7:0] a, input [15:0] d, input [15:0] m);
    begin
      @(posedge clk_reg); addr <= a; di <= d; mask <= m; en <= 1; we <= 1;
      @(posedge clk_reg); en <= 0; we <= 0; rf_lat = 1;
      while (!rdy && rf_lat < 400) begin @(posedge clk_reg); rf_lat = rf_lat + 1; end
      repeat (2) @(posedge clk_reg);
    end
  endtask

  // TX stream: tx_mode 0: counter, comma every cevery words in lane clane;
  // 1: constant txd_c/txk_c
  integer tx_mode = 0, cevery = 4, clane = 0, txn_w = 0, commas_sent = 0;
  reg [63:0] txd_c = 0;
  reg [7:0] txk_c = 0;
  always @(posedge clk_tx) begin : tx_gen
    reg [63:0] d; reg [7:0] k; integer b;
    if (tx_mode == 1) begin d = txd_c; k = txk_c; end
    else if (tx_mode == 2) begin d = 0; k = 8'h55; for (b = 0; b < 8; b = b + 1) d[b*8+:8] = (b % 2 == 0) ? 8'hBC : 8'(txn_w * 8 + b); end
    else begin
      d = 0; k = 0;
      for (b = 0; b < 8; b = b + 1) d[b*8+:8] = 8'(txn_w * 8 + b);
      if (txn_w % cevery == 0) begin d[clane*8+:8] = 8'hBC; k[clane] = 1; if (txdone) commas_sent = commas_sent + 1; end
    end
    txd <= d; txk <= k;
    txn_w = txn_w + 1;
  end

  // monitors
  integer realigns = 0, rxclk_n = 0, dump = 0;
  always @(posedge aligned) $display("%t ALIGNED 1 (commas sent %0d, realigns %0d)", $time, commas_sent, realigns);
  always @(negedge aligned) if ($time > 0) $display("%t ALIGNED 0", $time);
  always @(posedge clk_rx) if (realign === 1'b1) begin realigns = realigns + 1; $display("%t REALIGN pulse (commas sent %0d)", $time, commas_sent); end
  always @(posedge txdone) $display("%t TXDONE 1", $time);
  always @(negedge txdone) if ($time > 0) $display("%t TXDONE 0", $time);
  always @(posedge rxdone) $display("%t RXDONE 1", $time);
  always @(negedge rxdone) if ($time > 0) $display("%t RXDONE 0", $time);
  always @(posedge tx_err) $display("%t TX_BUF_ERR 1", $time);
  always @(negedge tx_err) if ($time > 0) $display("%t TX_BUF_ERR 0", $time);
  always @(posedge clk_rx) begin : rx_dump
    integer b;
    rxclk_n = rxclk_n + 1;
    if (dump) begin
      $write("%t RX al=%b ra=%b pe=%b |", $time, aligned, realign, prbs_err);
      for (b = LANES - 1; b >= 0; b = b - 1) $write(" %s%h%s%s", rxk[b] ? "K" : " ", rxd[b*8+:8], rxnit[b] ? "n" : " ", rxdisp[b] ? "d" : " ");
      $write("\n");
    end
  end

  // line sampler: P bits at a fixed phase (for TX probes), lsb first
  real ui;
  task line_bits(input integer n, input real t_ui);
    integer i;
    begin
      for (i = 0; i < n; i = i + 1) begin #(t_ui); $write("%b", rxp); end
      $write("\n");
    end
  endtask

  integer cfg1 = 16'h16FA, cfg0 = 16'h0C03;
  initial begin
    $timeformat(-9, 1, " ns", 12);
    void'($value$plusargs("cfg1=%h", cfg1));
    void'($value$plusargs("cfg0=%h", cfg0));
    void'($value$plusargs("cevery=%d", cevery));
    void'($value$plusargs("clane=%d", clane));
    #10 arst_n = 0; #90 arst_n = 1; #50;
    cfgw(8'h5C, 16'h0001);
    if (!$test$plusargs("rfonly")) cfgw(8'h51, 16'(cfg1));
    if (!$test$plusargs("norxhold")) rx_rst = 1;
    if (!$test$plusargs("rfonly")) cfgw(8'h50, 16'(cfg0));
    if (!$test$plusargs("norxhold")) fork begin wait (txdone === 1'b1); #200; rx_rst = 0; end join_none
`include "stim.vh"
    $finish;
  end
  initial begin : tmax
    real t; t = 200000.0;
    void'($value$plusargs("tmax=%f", t));
    #(t) $display("%t timeout", $time);
    $finish;
  end
endmodule
