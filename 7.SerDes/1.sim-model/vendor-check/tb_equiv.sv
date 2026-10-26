// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// SerDes model equivalence, side by side: the open BFM (ccfpga_serdes) and
// the vendor model (ccfpga_serdes_ref), each its own TX to RX, or crossed
// (CROSS: each TX into the other's RX). Run by vendor-check.sh equiv;
// based on openCologne-PCIE tb_phy.sv TB_PHY_EQUIV.
//   DP          datapath: 0 16, 1 32, 3 64 bits
//   HARD        1: the TX 8b/10b in the SerDes; 0: in the fabric, the word
//               in every quarter / half (default for 16/32 bits)
//   COMMA_LANE  the lane of the training comma
//   PRBS        1: then PRBS-7 with forced errors
// Prints EQUIV: ... PASS/FAIL. CDR_MODEL by define (FAST, ACCURATE).
//==========================================================================
`timescale 1ns/100fs

module tb_equiv;
   parameter integer DP         = 3;
   parameter integer HARD       = (DP == 3);
   parameter integer COMMA_LANE = 0;
   parameter integer PRBS       = 0;
   parameter integer N_TRAIN    = 64;
   parameter integer N_PAYLOAD  = 200;
   parameter real    WIRE_NS    = 10.0;

   localparam integer LANES = (DP == 0) ? 2 : (DP == 1) ? 4 : 8;
   localparam [7:0]   LMASK = (DP == 0) ? 8'h03 : (DP == 1) ? 8'h0F : 8'hFF;
   localparam [5:0]   FCNTRL = (DP == 0) ? 6'd26 : 6'd58;

   function [63:0] mask64(input [7:0] m);
      integer i;
      begin for (i = 0; i < 8; i = i + 1) mask64[i*8 +: 8] = {8{m[i]}}; end
   endfunction
   localparam [63:0] DMASK = mask64(LMASK);

   reg clk_ref = 1, clk_reg = 1, clk_cfg = 1;
   always #5.0 clk_ref = ~clk_ref;
   always #4.0 clk_reg = ~clk_reg;
   always #20.0 clk_cfg = ~clk_cfg;
   reg reset_n, reset_reg_n;  // X to 0 at time 0: the vendor model needs that falling edge
   initial begin reset_n = 0; #101 reset_n = 1; end
   initial begin reset_reg_n = 0; #81 reset_reg_n = 1; end

   reg        regfile_we = 0, regfile_en = 0;
   reg  [7:0] regfile_addr = 0;
   reg [15:0] regfile_mask = 0, regfile_di = 0;
   reg        cfg_en = 0, cfgfile_valid = 0;
   reg [15:0] cfgfile_di = 0;
   reg  [7:0] cfgfile_addr = 0;

   task writeCfg(input [7:0] a, input [15:0] d);
      begin
         @(posedge clk_cfg); #1; cfg_en = 1;
         @(posedge clk_cfg); #1; cfgfile_valid = 1; cfgfile_di = d; cfgfile_addr = a;
         @(posedge clk_cfg); #1; cfgfile_valid = 0;
         @(posedge clk_cfg); #1; cfg_en = 0;
      end
   endtask

   task writeRegfile(input [7:0] a, input [15:0] d, input [15:0] m);
      integer i;
      begin
         @(posedge clk_reg); #1.5;
         regfile_en = 1; regfile_we = 1; regfile_addr = a; regfile_mask = m; regfile_di = d;
         @(posedge clk_reg); #1.5;
         regfile_en = 0; regfile_we = 0;
         for (i = 0; i < 40; i = i + 1) @(posedge clk_reg);
      end
   endtask

   localparam [7:0] COMMA = 8'hBC, MARKER = 8'h1C, FILLER = 8'h4A;

   function [31:0] xs32(input [31:0] s);
      reg [31:0] v;
      begin v = s; v = v ^ (v << 13); v = v ^ (v >> 17); v = v ^ (v << 5); xs32 = v; end
   endfunction

   // the payload, LANES lanes a word
   reg [63:0] exp_d [0:N_PAYLOAD-1];
   reg  [7:0] exp_k [0:N_PAYLOAD-1];
   initial begin : build
      integer i, j; reg [31:0] s; reg [7:0] b;
      s = 32'h1234_5678;
      for (i = 0; i < N_PAYLOAD; i = i + 1) begin
         exp_d[i] = 0; exp_k[i] = 0;
         for (j = 0; j < LANES; j = j + 1) begin
            s = xs32(s);
            if (s[31:29] == 3'b000) begin
               case (s[2:0])
                 0: b = 8'h1C; 1: b = 8'h3C; 2: b = 8'h5C; 3: b = 8'h7C;
                 4: b = 8'h9C; 5: b = 8'hBC; 6: b = 8'hFB; default: b = 8'hFD;
               endcase
               exp_k[i][j] = 1;
            end
            else b = s[15:8];
            exp_d[i][j*8 +: 8] = b;
         end
      end
   end

   // one side: TX state, its word, and the RX capture
   localparam ST_IDLE = 0, ST_TRAIN = 1, ST_MARK = 2, ST_PAY = 3, ST_TAIL = 4;

`define SIDE(P, DUTMOD, RXP, RXN) \
   wire P``_clk, P``_rst_n, P``_rxclk; \
   wire P``_txp, P``_txn; \
   reg  P``_rxp_w = 0, P``_rxn_w = 1; \
   wire P``_txdone, P``_rxdone, P``_aligned, P``_txerr, P``_rxerr, P``_prbs_err; \
   wire [63:0] P``_rxd; wire [7:0] P``_rxk, P``_rxc, P``_rxnit, P``_rxdisp; \
   wire [15:0] P``_do; wire P``_rdy; \
   reg [63:0] P``_txd = 0; reg [7:0] P``_txk = 0, P``_dm = 0, P``_dv = 0; \
   reg P``_ei = 1, P``_comma_en = 0, P``_mc = 0, P``_pc = 0; \
   reg [2:0] P``_tprbs = 0, P``_rprbs = 0; reg P``_force = 0; \
   DUTMOD #( \
      .PLL_FCNTRL(FCNTRL), .PLL_MAIN_DIVSEL(6'b011011), .PLL_OUT_DIVSEL(2'b01), \
      .RX_DATAPATH_SEL(DP[1:0]), .TX_DATAPATH_SEL(DP[1:0]), .ALIGN_COMMA_WORD(2'b11), \
      .PLL_SET_OP_LOCK(1'b0), .PLL_CI(5'h3), .PLL_CP(10'h50), .PLL_BISC_TIMER_MAX(4'hC), \
      .PLL_BISC_CP_MAX(5'h1E), .PLL_BISC_CP_START(5'h6), .PLL_BISC_CAL_SIGN(1'h1) \
   ) P``_dut ( \
      .clk_ref_i(clk_ref), .clk_reg_i(clk_reg), .clk_cfg_i(clk_cfg), \
      .clk_core_tx_i(P``_clk), .clk_core_rx_i(P``_clk), .clk_core_rx_o(P``_rxclk), \
      .reset_n_i(reset_n), .reset_reg_n_i(reset_reg_n), .reset_core_tx_n_i(P``_rst_n), .reset_core_rx_n_i(P``_rst_n), \
      .testmode_i(1'b0), .scan_enable_i(1'b0), .scan_in_i(7'h0), .scan_out_o(), .loopback_i(3'b000), .pll_reset_i(1'b0), \
      .clk_core_pll_o(P``_clk), .reset_core_pll_n_o(P``_rst_n), .refclk_sel_o(), .refclk_rterm_o(), \
      .RX_SERIO_P_B(RXP), .RX_SERIO_N_B(RXN), .TX_SERIO_P_B(P``_txp), .TX_SERIO_N_B(P``_txn), \
      .regfile_we_i(regfile_we), .regfile_en_i(regfile_en), .regfile_addr_i(regfile_addr), .regfile_mask_i(regfile_mask), \
      .regfile_di_i(regfile_di), .regfile_do_o(P``_do), .regfile_rdy_o(P``_rdy), \
      .cfg_en_i(cfg_en), .reset_cfg_i(1'b0), .cfgfile_di_i(cfgfile_di), .cfgfile_valid_i(cfgfile_valid), .cfgfile_addr_i(cfgfile_addr), \
      .tx_reset_i(1'b0), .tx_pcs_reset_i(1'b0), .tx_pma_reset_i(1'b0), .tx_elec_idle_i(P``_ei), .tx_detect_rx_i(1'b0), \
      .tx_prbs_sel_i(P``_tprbs), .tx_prbs_force_err_i(P``_force), .tx_powerdown_n_i(1'b1), .tx_data_i(P``_txd), \
      .tx_char_is_k_i(P``_txk), .tx_polarity_i(1'b0), .tx_8b10b_en_i(1'b1), .tx_8b10b_bypass_i(HARD ? 8'h00 : 8'hFF), \
      .tx_char_dispmode_i(P``_dm), .tx_char_dispval_i(P``_dv), .tx_buf_err_o(P``_txerr), .tx_resetdone_o(P``_txdone), \
      .rx_detect_done_o(), .rx_present_o(), .TERM_SERIO_O(), \
      .rx_reset_i(1'b0), .rx_pma_reset_i(1'b0), .rx_eqa_reset_i(1'b0), .rx_cdr_reset_i(1'b0), .rx_pcs_reset_i(1'b0), \
      .rx_buf_reset_i(1'b0), .rx_prbs_sel_i(P``_rprbs), .rx_prbs_cnt_reset_i(1'b0), .rx_powerdown_n_i(1'b1), \
      .rx_en_ei_detector_i(1'b0), .rx_comma_detect_en_i(P``_comma_en), .rx_slide_i(1'b0), .rx_polarity_i(1'b0), \
      .rx_8b10b_en_i(1'b1), .rx_8b10b_bypass_i(8'h0), .rx_mcomma_align_i(P``_mc), .rx_pcomma_align_i(P``_pc), \
      .rx_prbs_err_o(P``_prbs_err), .rx_data_o(P``_rxd), .rx_char_is_k_o(P``_rxk), .rx_char_is_comma_o(P``_rxc), \
      .rx_not_in_table_o(P``_rxnit), .rx_disp_err_o(P``_rxdisp), .rx_buf_err_o(P``_rxerr), \
      .rx_byte_is_aligned_o(P``_aligned), .rx_byte_realign_o(), .rx_resetdone_o(P``_rxdone), .rx_ei_en_o()); \
   always @(posedge P``_clk) if (P``_comma_en) begin P``_mc <= ~P``_aligned; P``_pc <= ~P``_aligned; end \
   integer P``_st = ST_IDLE, P``_cnt = 0; reg P``_rd = 1; real P``_mark_tx_t = 0; \
   always @(posedge P``_clk) begin : P``_tx \
      reg [63:0] d; reg [7:0] k, dm, dv; reg [10:0] e; integer b, c; \
      d = 0; k = 0; \
      case (P``_st) \
        ST_IDLE: if (P``_txdone) begin P``_ei <= 0; P``_comma_en <= 1; P``_mc <= 1; P``_pc <= 1; P``_st = ST_TRAIN; P``_cnt = 0; end \
        ST_TRAIN: begin for (b = 0; b < 8; b = b + 1) d[b*8 +: 8] = FILLER; d[COMMA_LANE*8 +: 8] = COMMA; k[COMMA_LANE] = 1; \
                    if (!link_ready) P``_cnt = 0; else if (P``_cnt == N_TRAIN - 1) begin P``_st = ST_MARK; P``_cnt = 0; end else P``_cnt = P``_cnt + 1; end \
        ST_MARK: begin d = {8{MARKER}}; k = 8'hFF; if (P``_cnt == 0) P``_mark_tx_t = $realtime; \
                   if (P``_cnt == 1) begin P``_st = ST_PAY; P``_cnt = 0; end else P``_cnt = P``_cnt + 1; end \
        ST_PAY: begin d = exp_d[P``_cnt]; k = exp_k[P``_cnt]; if (P``_cnt == N_PAYLOAD - 1) begin P``_st = ST_TAIL; P``_cnt = 0; end else P``_cnt = P``_cnt + 1; end \
        default: begin for (b = 0; b < 8; b = b + 1) d[b*8 +: 8] = COMMA; k = 8'hFF; end \
      endcase \
      dm = 0; dv = 0; \
      if (!HARD) begin \
         for (b = 0; b < LANES; b = b + 1) begin \
            e = ccfpga_serdes_pkg::enc8b10b(d[b*8 +: 8], k[b], P``_rd); P``_rd = e[10]; \
            for (c = b; c < 8; c = c + LANES) begin d[c*8 +: 8] = e[7:0]; dv[c] = e[8]; dm[c] = e[9]; end \
         end \
      end \
      else if (LANES < 8) begin \
         for (b = LANES; b < 8; b = b + 1) begin d[b*8 +: 8] = d[(b % LANES)*8 +: 8]; k[b] = k[b % LANES]; end \
      end \
      P``_txd <= d; P``_txk <= k; P``_dm <= dm; P``_dv <= dv; \
   end \
   reg [63:0] P``_cd [0:N_PAYLOAD-1]; reg [7:0] P``_ck [0:N_PAYLOAD-1], P``_cc [0:N_PAYLOAD-1], P``_ce [0:N_PAYLOAD-1], P``_cp [0:N_PAYLOAD-1]; \
   integer P``_cn = 0; reg P``_seen = 0, P``_cap = 0; real P``_mark_rx_t = 0; \
   always @(posedge P``_clk) begin \
      if (!P``_cap) begin \
         if (P``_aligned && ((P``_rxd & DMASK) === ({8{MARKER}} & DMASK)) && ((P``_rxk & LMASK) === LMASK)) begin \
            if (!P``_seen) begin P``_seen = 1; P``_mark_rx_t = $realtime; end end \
         else if (P``_seen) begin P``_cap = 1; P``_cd[0] = P``_rxd; P``_ck[0] = P``_rxk; P``_cc[0] = P``_rxc; P``_ce[0] = P``_rxnit; P``_cp[0] = P``_rxdisp; P``_cn = 1; end \
      end \
      else if (P``_cn < N_PAYLOAD) begin P``_cd[P``_cn] = P``_rxd; P``_ck[P``_cn] = P``_rxk; P``_cc[P``_cn] = P``_rxc; P``_ce[P``_cn] = P``_rxnit; P``_cp[P``_cn] = P``_rxdisp; P``_cn = P``_cn + 1; end \
   end \
   integer P``_perr = 0; reg P``_pcount = 0; integer P``_bufe = 0, P``_txe = 0, P``_drops = 0;    always @(posedge P``_clk) begin if (P``_rxerr === 1'b1) P``_bufe = P``_bufe + 1; if (P``_txerr === 1'b1) P``_txe = P``_txe + 1;       if (P``_cap && P``_aligned !== 1'b1) P``_drops = P``_drops + 1; end \
   always @(posedge P``_clk) if (P``_pcount && P``_prbs_err === 1'b1) P``_perr = P``_perr + 1;

   wire link_ready;
`ifdef CROSS
   `SIDE(bhv, ccfpga_serdes, bhv_rxp_w, bhv_rxn_w)
   `SIDE(ref, ccfpga_serdes_ref, ref_rxp_w, ref_rxn_w)
   always @(ref_txp) bhv_rxp_w <= #(WIRE_NS) ref_txp;
   always @(ref_txn) bhv_rxn_w <= #(WIRE_NS) ref_txn;
   always @(bhv_txp) ref_rxp_w <= #(WIRE_NS) bhv_txp;
   always @(bhv_txn) ref_rxn_w <= #(WIRE_NS) bhv_txn;
`else
   `SIDE(bhv, ccfpga_serdes, bhv_rxp_w, bhv_rxn_w)
   `SIDE(ref, ccfpga_serdes_ref, ref_rxp_w, ref_rxn_w)
   always @(bhv_txp) bhv_rxp_w <= #(WIRE_NS) bhv_txp;
   always @(bhv_txn) bhv_rxn_w <= #(WIRE_NS) bhv_txn;
   always @(ref_txp) ref_rxp_w <= #(WIRE_NS) ref_txp;
   always @(ref_txn) ref_rxn_w <= #(WIRE_NS) ref_txn;
`endif
   assign link_ready = bhv_aligned & ref_aligned;

   // PRBS: TX PRBS-7, RX PRBS-7, settle, then 3 single forced errors and one
   // held 2 clocks; each RX counts its RX_PRBS_ERR_O clocks
   task prbs_phase;
      integer i;
      begin
         bhv_tprbs = 3'b001; ref_tprbs = 3'b001; bhv_rprbs = 3'b001; ref_rprbs = 3'b001;
         #4000;
         bhv_pcount = 1; ref_pcount = 1;
         #1000;
         for (i = 0; i < 4; i = i + 1) begin
            @(posedge bhv_clk); bhv_force <= 1; @(posedge ref_clk); ref_force <= 1;
            if (i == 3) begin @(posedge bhv_clk); @(posedge ref_clk); end
            @(posedge bhv_clk); bhv_force <= 0; @(posedge ref_clk); ref_force <= 0;
            #1000;
         end
         bhv_pcount = 0; ref_pcount = 0;
      end
   endtask

   initial begin : trace
      integer i;
      for (i = 0; i < 16; i = i + 1) begin
         #25_000;
         if ($test$plusargs("trace"))
           $display("EQUIV trace %0t: BHV tx %b rx %b al %b st %0d cn %0d | REF tx %b rx %b al %b st %0d cn %0d", $time,
                    bhv_txdone, bhv_rxdone, bhv_aligned, bhv_st, bhv_cn, ref_txdone, ref_rxdone, ref_aligned, ref_st, ref_cn);
      end
   end

   integer e_bx, e_rx, e_br, ci, tmo, o_br, o_bx, o_rx;
   string  extra;
   reg [11:0] bs [0:N_PAYLOAD*8-1], rs [0:N_PAYLOAD*8-1], xs [0:N_PAYLOAD*8-1];

   // mismatched symbols, fewest over the offsets -LANES+1 .. LANES-1:
   // which 0 BHV vs REF, 1 BHV vs expected, 2 REF vs expected
   task cmp(input integer which, output integer best, output integer boff);
      integer off, i, n, lo, hi;
      reg [11:0] a, b;
      begin
         best = N_PAYLOAD * LANES; boff = 0;
         for (off = -LANES + 1; off < LANES; off = off + 1) begin
            n = 0;
            lo = (off < 0) ? -off : 0;
            hi = N_PAYLOAD * LANES - ((off > 0) ? off : 0);
            for (i = lo; i < hi; i = i + 1) begin
               a = (which == 2) ? rs[i] : bs[i];
               b = (which == 0) ? rs[i + off] : xs[i + off];
               if (a !== b) n = n + 1;
            end
            if (n < best) begin best = n; boff = off; end
         end
      end
   endtask
   string mode;
   initial begin : main
      e_bx = 0; e_rx = 0; e_br = 0; tmo = 0;
      mode = (ccfpga_serdes_pkg::CDR_MODEL == ccfpga_serdes_pkg::ACCURATE) ? "ACCURATE" : "FAST";
      #500;
      writeCfg(8'h5C, 16'h0001);
      #100;
      writeRegfile(8'h50, 16'h0002, 16'h0007);
      writeRegfile(8'h50, 16'h0003, 16'h0003);
      fork : w
         begin wait (bhv_cn == N_PAYLOAD); wait (ref_cn == N_PAYLOAD); end
         begin #400_000; tmo = 1; end
      join_any
      disable w;
      #1000;
      // the captures as symbol streams {comma, nit, disp, k, d}, compared
      // at the lane offset with the fewest mismatches: a lock in another
      // lane (ALIGN_COMMA_WORD 11: 0 or 4) shifts the words, not the stream
      for (ci = 0; ci < N_PAYLOAD * LANES; ci = ci + 1) begin
         bs[ci] = {bhv_cc[ci / LANES][ci % LANES], bhv_ce[ci / LANES][ci % LANES], bhv_cp[ci / LANES][ci % LANES],
                   bhv_ck[ci / LANES][ci % LANES], bhv_cd[ci / LANES][(ci % LANES)*8 +: 8]};
         rs[ci] = {ref_cc[ci / LANES][ci % LANES], ref_ce[ci / LANES][ci % LANES], ref_cp[ci / LANES][ci % LANES],
                   ref_ck[ci / LANES][ci % LANES], ref_cd[ci / LANES][(ci % LANES)*8 +: 8]};
         xs[ci] = {3'b000, exp_k[ci / LANES][ci % LANES], exp_d[ci / LANES][(ci % LANES)*8 +: 8]};
         xs[ci][11] = exp_k[ci / LANES][ci % LANES] && (exp_d[ci / LANES][(ci % LANES)*8 +: 8] == 8'h3C || exp_d[ci / LANES][(ci % LANES)*8 +: 8] == 8'hBC || exp_d[ci / LANES][(ci % LANES)*8 +: 8] == 8'hFC);
      end
      cmp(0, e_br, o_br);
      cmp(1, e_bx, o_bx);
      cmp(2, e_rx, o_rx);
      if (e_br != 0) begin
         for (ci = 0; ci < 3; ci = ci + 1)
           $display("  DIVERGENCE word %0d: BHV d=%h k=%h c=%h n=%h p=%h  REF d=%h k=%h c=%h n=%h p=%h", ci,
                    bhv_cd[ci], bhv_ck[ci], bhv_cc[ci], bhv_ce[ci], bhv_cp[ci],
                    ref_cd[ci], ref_ck[ci], ref_cc[ci], ref_ce[ci], ref_cp[ci]);
      end
      if (PRBS) prbs_phase;
      if (PRBS) extra = $sformatf(", PRBS error clocks BHV %0d REF %0d", bhv_perr, ref_perr);
      else extra = $sformatf(", RX/TX buf err clocks, unaligned: BHV %0d/%0d/%0d REF %0d/%0d/%0d", bhv_bufe, bhv_txe,
                             bhv_drops, ref_bufe, ref_txe, ref_drops);
      $display("EQUIV: %s, %0d-bit, %s 8b/10b, comma lane %0d, %s: %0d words, symbols wrong: BHV-vs-exp %0d (lane %0d), REF-vs-exp %0d (lane %0d), BHV-vs-REF %0d (lane %0d), latency BHV-REF %.1f ns%s%s: %s",
               mode, LANES * 8, HARD ? "SerDes" : "fabric", COMMA_LANE,
`ifdef CROSS
               "crossed",
`else
               "own loop",
`endif
               bhv_cn, e_bx, o_bx, e_rx, o_rx, e_br, o_br,
               (bhv_mark_rx_t - bhv_mark_tx_t) - (ref_mark_rx_t - ref_mark_tx_t),
               extra,
               tmo ? ", TIMEOUT" : "",
               (!tmo && e_br == 0 && (!PRBS || bhv_perr == ref_perr)) ? "PASS" : "FAIL");
      $finish;
   end

endmodule
