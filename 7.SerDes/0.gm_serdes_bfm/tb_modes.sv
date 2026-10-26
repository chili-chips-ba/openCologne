// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerDes BFM modes: one BFM, its TX looped to its RX at 2.5 Gb/s, with the
// 8b/10b in the BFM. A counter stream with a K28.5 comma every 16 words, in
// lane +comma=N. Checks the bytes come out in order, then writes the
// latency of each comma, TX word in to RX word out, to +words=FILE.
// With ALIGN = ALIGN_COMMA_WORD 01 or 1X, the comma must come out in an
// even lane, or lane 0 or 4. At time 0 it also checks the BFM's decode
// table against dec8b10b(), the decoder under proof (formal_8b10b), and
// its comma defaults against the encoder. Every run also checks:
// - register readback: PLL_CFG0, PLL_CFG1, PLL_CFG5 (PLL_LOCKED);
// - no TX_BUF_ERR_O or RX_BUF_ERR_O once the stream is found, no stall.
// Options:
//   +cfg1=HEX    PLL_CFG1, another line rate (100 MHz reference): 063A is
//                3 Gb/s, a UI the 100 fs time step can't hold
//   +run_us=N    run N us at least, the data checked all along
//   +prbs=SEL    PRBS instead of data (TX and RX _PRBS_SEL_I): error-free,
//                then 4 forced errors (TX_PRBS_FORCE_ERR_I) count 3 each
//                and flag RX_PRBS_ERR_O once each; the receiver never stops
// make sim_modes runs it for each CDR_MODEL, datapath width and comma lane,
// and compares the latencies across the modes; make sim_icarus runs it in
// Icarus.
//==========================================================================
module tb_modes #(
    parameter int       DP_SEL = 3,     // datapath: 0 = 16, 1 = 32, 3 = 64 bits
    parameter bit [1:0] ALIGN  = 2'b00  // the BFM's ALIGN_COMMA_WORD
);

  localparam int LANES = (DP_SEL == 0) ? 2 : (DP_SEL == 1) ? 4 : 8;
  localparam int COMMAS = 64;  // latencies written
  localparam int COMMA_LANES = ALIGN[1] ? 4 : ALIGN[0] ? 2 : 1;  // a comma lands on a multiple
  // PLL_CFG1: 2.5 Gb/s; the word clock is 2 UI x M1 x M4 (DS1001 Eq. 2.2):
  // FCNTRL 58 (M1 = 20) for 32 and 64 bits (M4 = 2), 26 (M1 = 10) for 16
  localparam logic [15:0] PLL_CFG1 = (DP_SEL == 0) ? 16'h16DA : 16'h16FA;

  logic clk_ref, clk_reg, arst_n;
  logic clk_tx, clk_rx, rst_core_n;
  logic txp, txn, rxp, rxn;
  logic serdes_reset;
  logic reg_en, reg_we, cfg_en;
  logic [7:0] reg_addr;
  logic [15:0] reg_data, rf_do;
  logic rf_rdy;
  logic [63:0] tx_d, rx_d;
  logic [7:0] tx_k, rx_k, rx_nit, rx_disp, NC_rx_comma;
  logic tx_ready, rx_ready, rx_aligned;
  logic tx_err, rx_err, prbs_err;
  logic [2:0] prbs_sel;
  logic force_err;
  logic [15:0] cfg1;
  int comma = 0;
  int words_fd = 0;
  int errors = 0;
  int prbs = 0;  // +prbs=SEL
  int run_us = 0;

  initial begin : _clk_ref
    clk_ref = 1'b0;
    forever #5 clk_ref = ~clk_ref;  // 100 MHz reference
  end : _clk_ref

  initial begin : _clk_reg
    clk_reg = 1'b0;
    forever #50 clk_reg = ~clk_reg;  // 10 MHz regfile clock
  end : _clk_reg

  always_comb begin
    rxp = txp;
    rxn = txn;
  end

  ccfpga_serdes #(
      .RX_DATAPATH_SEL (2'(DP_SEL)),
      .TX_DATAPATH_SEL (2'(DP_SEL)),
      .ALIGN_COMMA_WORD(ALIGN)
  ) u_serdes (
      .clk_ref_i           (clk_ref),
      .clk_reg_i           (clk_reg),
      .clk_cfg_i           (clk_reg),
      .clk_core_tx_i       (clk_tx),
      .clk_core_rx_i       (clk_rx),
      .clk_core_rx_o       (clk_rx),
      .reset_n_i           (arst_n),
      .reset_reg_n_i       (arst_n),
      .reset_core_tx_n_i   (rst_core_n),
      .reset_core_rx_n_i   (rst_core_n),
      .testmode_i          (1'b0),
      .scan_enable_i       (1'b0),
      .scan_in_i           (7'h0),
      .scan_out_o          (),
      .loopback_i          (3'b000),
      .pll_reset_i         (1'b0),
      .clk_core_pll_o      (clk_tx),
      .reset_core_pll_n_o  (rst_core_n),
      .refclk_sel_o        (),
      .refclk_rterm_o      (),
      .RX_SERIO_P_B        (rxp),
      .RX_SERIO_N_B        (rxn),
      .TX_SERIO_P_B        (txp),
      .TX_SERIO_N_B        (txn),
      .regfile_we_i        (reg_we),
      .regfile_en_i        (reg_en),
      .regfile_addr_i      (reg_addr),
      .regfile_mask_i      (16'hFFFF),
      .regfile_di_i        (reg_data),
      .regfile_do_o        (rf_do),
      .regfile_rdy_o       (rf_rdy),
      .cfg_en_i            (cfg_en),
      .reset_cfg_i         (1'b0),
      .cfgfile_di_i        (reg_data),
      .cfgfile_valid_i     (cfg_en),
      .cfgfile_addr_i      (reg_addr),
      .tx_reset_i          (serdes_reset),
      .tx_pcs_reset_i      (1'b0),
      .tx_pma_reset_i      (1'b0),
      .tx_elec_idle_i      (1'b0),
      .tx_detect_rx_i      (1'b0),
      .tx_prbs_sel_i       (prbs_sel),
      .tx_prbs_force_err_i (force_err),
      .tx_powerdown_n_i    (1'b1),
      .tx_data_i           (tx_d),
      .tx_char_is_k_i      (tx_k),
      .tx_polarity_i       (1'b0),
      .tx_8b10b_en_i       (1'b1),
      .tx_8b10b_bypass_i   ('0),
      .tx_char_dispmode_i  ('0),
      .tx_char_dispval_i   ('0),
      .tx_buf_err_o        (tx_err),
      .tx_resetdone_o      (tx_ready),
      .rx_detect_done_o    (),
      .rx_present_o        (),
      .TERM_SERIO_O        (),
      .rx_reset_i          (serdes_reset),
      .rx_pma_reset_i      (1'b0),
      .rx_eqa_reset_i      (1'b0),
      .rx_cdr_reset_i      (1'b0),
      .rx_pcs_reset_i      (1'b0),
      .rx_buf_reset_i      (1'b0),
      .rx_prbs_sel_i       (prbs_sel),
      .rx_prbs_cnt_reset_i (1'b0),
      .rx_powerdown_n_i    (1'b1),
      .rx_en_ei_detector_i (1'b0),
      .rx_comma_detect_en_i(prbs == 0),  // PRBS data holds commas: no aligning on them
      .rx_slide_i          (1'b0),
      .rx_polarity_i       (1'b0),
      .rx_8b10b_en_i       (1'b1),
      .rx_8b10b_bypass_i   ('0),
      .rx_mcomma_align_i   (1'b1),
      .rx_pcomma_align_i   (1'b1),
      .rx_prbs_err_o       (prbs_err),
      .rx_data_o           (rx_d),
      .rx_char_is_k_o      (rx_k),
      .rx_char_is_comma_o  (NC_rx_comma),
      .rx_not_in_table_o   (rx_nit),
      .rx_disp_err_o       (rx_disp),
      .rx_buf_err_o        (rx_err),
      .rx_byte_is_aligned_o(rx_aligned),
      .rx_byte_realign_o   (),
      .rx_resetdone_o      (rx_ready),
      .rx_ei_en_o          ()
  );

  // one register write: the SerDes enable through the config port
  task automatic reg_write(logic [7:0] a, logic [15:0] d);
    @(posedge clk_reg);
    reg_addr <= a;
    reg_data <= d;
    reg_en   <= (a != 8'h5C);
    reg_we   <= 1'b1;
    cfg_en   <= (a == 8'h5C);
    @(posedge clk_reg);
    reg_en <= 1'b0;
    reg_we <= 1'b0;
    cfg_en <= 1'b0;
    repeat (16) @(posedge clk_reg);
  endtask

  // one register read, against what it must be
  int rf_bad = 0;

  task automatic reg_check(logic [7:0] a, logic [15:0] want);
    logic [15:0] got_d;
    @(posedge clk_reg);
    reg_addr <= a;
    reg_en   <= 1'b1;
    @(posedge clk_reg);
    reg_en <= 1'b0;
    do begin
      @(posedge clk_reg);
    end while (!rf_rdy);
    got_d = rf_do;
    if (got_d !== want) begin
      rf_bad++;
      $display("ERROR: register 0x%02h reads 0x%04h, not 0x%04h", a, got_d, want);
    end
  endtask

  //-----------------------------------------------------------------------
  // TX: a counter, the last lane counting words / 32, so the stream repeats
  // only after 8192 words; a comma every 16 words in lane `comma` (in the
  // last lane, it hides that count in 1 word of 16). A symbol is {K flag,
  // byte}.
  //-----------------------------------------------------------------------
  int       tx_n = 0;
  bit [8:0] sent[$];  // symbols sent, in lane order
  realtime  sent_t[$];  // when their word went in

  initial forever begin : _tx
    logic [63:0] d;
    logic [ 7:0] k;
    @(posedge clk_tx);
    d = '0;
    k = '0;
    for (int b = 0; b < LANES; b++) begin
      d[b*8+:8] = 8'(tx_n * LANES + b);
    end
    d[(LANES-1)*8+:8] = 8'(tx_n >> 5);
    if (tx_n % 16 == 0) begin
      d[comma*8+:8] = 8'hBC;
      k[comma]      = 1'b1;
    end
    tx_d <= d;
    tx_k <= k;
    if (tx_ready) begin
      for (int b = 0; b < LANES; b++) begin
        sent.push_back({k[b], d[b*8+:8]});
        sent_t.push_back($realtime);
      end
      if (sent.size() > 32768) begin
        void'(sent.pop_front());
        void'(sent_t.pop_front());
      end
    end
    tx_n++;
  end : _tx

  //-----------------------------------------------------------------------
  // RX: from the first comma, find the stream in `sent`, then symbol for
  // symbol; each comma out gives its latency
  //-----------------------------------------------------------------------
  localparam int FIND = 64;  // symbols to find the stream by
  bit [8:0] got_q[$];  // received, until found
  realtime  got_t[$];
  bit       locked = 1'b0;
  int       got = 0, bad = 0, lat_n = 0, lane_bad = 0;

  function automatic bit found_at(int i);
    for (int j = 0; j < got_q.size(); j++) begin
      if (sent[i+j] != got_q[j]) begin
        return 1'b0;
      end
    end
    return 1'b1;
  endfunction

  realtime last_t = 0;  // the last symbol checked

  task automatic check(bit [8:0] s, realtime t, bit err);
    got++;
    last_t = t;
    if (sent.size() == 0 || sent[0] != s || err) begin
      bad++;
    end
    else if (s[8] && lat_n < COMMAS) begin
      if (words_fd != 0) begin
        $fdisplay(words_fd, "%0.3f", t - sent_t[0]);
      end
      lat_n++;
    end
    if (sent.size() > 0) begin
      void'(sent.pop_front());
      void'(sent_t.pop_front());
    end
  endtask

  initial forever begin : _rx
    bit [8:0] s;
    @(posedge clk_rx);
    if (rx_ready && rx_aligned && prbs == 0) begin
      for (int b = 0; b < LANES; b++) begin
        s = {rx_k[b], rx_d[b*8+:8]};
        if ((s == 9'h1BC) && (b % COMMA_LANES != 0)) begin
          lane_bad++;  // a comma off the ALIGN_COMMA_WORD boundary
        end
        if (locked) begin
          check(s, $realtime, rx_nit[b] | rx_disp[b]);
        end
        else if (got_q.size() > 0 || s[8]) begin
          got_q.push_back(s);
          got_t.push_back($realtime);
          if (got_q.size() == FIND) begin
            for (int i = 0; i + FIND <= sent.size(); i++) begin
              if (found_at(i)) begin
                repeat (i) begin
                  void'(sent.pop_front());
                  void'(sent_t.pop_front());
                end
                locked = 1'b1;
                break;
              end
            end
            if (locked) begin
              for (int j = 0; j < FIND; j++) begin
                check(got_q[j], got_t[j], 1'b0);
              end
            end
            got_q.delete();
            got_t.delete();
          end
        end
      end
    end
  end : _rx

  //-----------------------------------------------------------------------
  // The BFM decodes with a table built at time 0; the proofs cover
  // dec8b10b(). They must agree on all 1024 symbols. The comma defaults
  // must be K28.5 from the encoder, RD- and RD+. +nolut skips the table.
  //-----------------------------------------------------------------------
  int lut_bad = 0;

  initial begin : _lut
    bit [10:0] e;
    #1;
    for (int s = 0; s < 1024 && !$test$plusargs("nolut"); s++) begin
      if (u_serdes.dec_lut[s] != ccfpga_serdes_pkg::dec8b10b(s[9:0])) begin
        lut_bad++;
      end
    end
    e = ccfpga_serdes_pkg::enc8b10b(8'hBC, 1'b1, 1'b0);
    if (e[9:0] != 10'(u_serdes.ALIGN_PCOMMA_VALUE)) begin
      lut_bad++;
    end
    e = ccfpga_serdes_pkg::enc8b10b(8'hBC, 1'b1, 1'b1);
    if (e[9:0] != 10'(u_serdes.ALIGN_MCOMMA_VALUE)) begin
      lut_bad++;
    end
  end : _lut

  //-----------------------------------------------------------------------
  // TX_BUF_ERR_O, RX_BUF_ERR_O: never once the link runs (the stream is
  // found, or in PRBS mode settled); the receiver never stops (electrical
  // idle) once it runs
  //-----------------------------------------------------------------------
  bit settled = 1'b0;  // PRBS mode: the link runs
  int buf_err = 0, stops = 0;

  initial forever begin : _buf
    @(posedge clk_tx or posedge clk_rx);
    if ((locked || settled) && (tx_err || rx_err)) begin
      buf_err++;
    end
  end : _buf

  initial forever begin : _stops
    @(negedge u_serdes.rx_sampler_run);
    if (locked || settled) begin
      stops++;
    end
  end : _stops

  //-----------------------------------------------------------------------
  // PRBS mode: 2 us to settle, 2 us error-free, then 4 forced errors, each
  // 3 counted and one RX_PRBS_ERR_O flag (one or two clocks)
  //-----------------------------------------------------------------------
  localparam int FORCED = 4;
  int prbs_before = 0, prbs_forced = 0, prbs_flags = 0;
  bit prbs_err_d = 1'b0;

  initial forever begin : _prbs_flags
    @(posedge clk_rx);
    if (settled && prbs_err && !prbs_err_d) begin
      prbs_flags++;
    end
    prbs_err_d = prbs_err;
  end : _prbs_flags

  task automatic prbs_test();
    int c0;
    prbs_sel = 3'(prbs);
    #2us;
    settled = 1'b1;
    c0 = u_serdes.rx_prbs_err_cnt;
    #2us;
    prbs_before = u_serdes.rx_prbs_err_cnt - c0;
    c0          = u_serdes.rx_prbs_err_cnt;
    prbs_flags  = 0;
    repeat (FORCED) begin
      @(posedge clk_tx);
      force_err <= 1'b1;
      @(posedge clk_tx);
      force_err <= 1'b0;
      #1us;
    end
    prbs_forced = u_serdes.rx_prbs_err_cnt - c0;
  endtask

  initial begin
    string f;
    string model;  // +model=NAME, e.g. the vendor model in its place
    model = (ccfpga_serdes_pkg::CDR_MODEL == ccfpga_serdes_pkg::NONE) ? "NONE" :
            (ccfpga_serdes_pkg::CDR_MODEL == ccfpga_serdes_pkg::FAST) ? "FAST" : "ACCURATE";
    void'($value$plusargs("model=%s", model));
    if (!$value$plusargs("comma=%d", comma)) begin
      comma = 0;
    end
    if ($value$plusargs("words=%s", f)) begin
      words_fd = $fopen(f, "w");
    end
    cfg1 = PLL_CFG1;
    void'($value$plusargs("cfg1=%h", cfg1));
    void'($value$plusargs("run_us=%d", run_us));
    void'($value$plusargs("prbs=%d", prbs));
    arst_n       = 1'b0;
    serdes_reset = 1'b1;
    reg_en       = 1'b0;
    reg_we       = 1'b0;
    cfg_en       = 1'b0;
    reg_addr     = '0;
    reg_data     = '0;
    tx_d         = '0;
    tx_k         = '0;
    prbs_sel     = 3'b000;
    force_err    = 1'b0;
    repeat (4) @(posedge clk_reg);
    arst_n = 1'b1;
    reg_write(8'h51, cfg1);      // the line rate and word clock
    reg_write(8'h5C, 16'h0001);  // SerDes enable
    reg_check(8'h55, 16'h0000);  // PLL_CFG5: not locked
    reg_write(8'h50, 16'h0C03);  // PLL on: CONFIG_SEL, SET_OP_LOCK, and on
    reg_check(8'h50, 16'h0C03);
    reg_check(8'h51, cfg1 & 16'h3FFF);
    reg_check(8'h55, 16'h0001);  // locked, 500 ns on
    serdes_reset = 1'b0;
    if (prbs != 0) begin
      wait (rx_ready && tx_ready);
      prbs_test();
      if (prbs_before != 0 || prbs_forced != 3 * FORCED || prbs_flags != FORCED || stops != 0 ||
          buf_err != 0 || rf_bad != 0) begin
        errors++;
      end
      $display("TB_MODES: %s, %0d-bit, PRBS sel %0d: %0d errors for %0d forced, %0d flags, %0d before, %0d stops, %0d buf err, %0d reg: %s",
               model, LANES * 8, prbs, prbs_forced, FORCED, prbs_flags, prbs_before, stops, buf_err,
               rf_bad, (errors == 0) ? "PASS" : "FAIL");
      $finish;
    end
    fork
      wait (lat_n >= COMMAS && $realtime >= run_us * 1us);
      repeat (run_us + 200) #1us;
    join_any
    // stalled: nothing checked for a microsecond at the end
    if (lat_n < COMMAS || bad != 0 || lane_bad != 0 || lut_bad != 0 || rf_bad != 0 ||
        buf_err != 0 || stops != 0 || $realtime - last_t > 1us) begin
      errors++;
    end
    if (words_fd != 0) begin
      $fclose(words_fd);
    end
    if (cfg1 != PLL_CFG1) begin  // a string, not ?: in $display: Icarus 13.0 aborts on that
      f = $sformatf(", PLL_CFG1 %h", cfg1);
    end
    else begin
      f = "";
    end
    $display("TB_MODES: %s, %0d-bit, comma in lane %0d, ALIGN %b%s: %0d bytes, %0d wrong, %0d commas, %0d off-lane, %0d table, %0d reg, %0d buf err, %0d stops: %s",
             model, LANES * 8, comma, ALIGN, f, got, bad, lat_n, lane_bad, lut_bad, rf_bad, buf_err,
             stops, (errors == 0) ? "PASS" : "FAIL");
    $finish;
  end

endmodule : tb_modes

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
