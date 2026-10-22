// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

//==========================================================================
// openCologne * NLnet-sponsored open-source design ware for GateMate
//--------------------------------------------------------------------------
// Description: GateMate SerDes PHY of the IC Link, LiteICLink's SerDes PHY
// interface on CC_SERDES: a data stream of 8 bytes + 8 K flags per clock
// each way, PRBS7/15/31 instead of the data, ready flags, comma alignment.
//
//   TX: data -> PRBS TX -> 8b/10b encoder (fabric, iclink_8b10b_enc, as
//       LiteICLink) -> CC_SERDES with its 8b/10b off: per symbol, bits 7:0
//       on TX_DATA_I, bit 8 on TX_CHAR_DISPMODE_I, bit 9 on TX_CHAR_DISPVAL_I.
//   RX: CC_SERDES comma alignment and 8b/10b decoder -> data + K + invalid
//       -> PRBS checker (fabric, iclink_prbs_rx). The RX decodes in the hard
//       macro: with its 8b/10b off, CC_SERDES hands out only bits 7:0 of
//       each symbol, so the fabric cannot see whole symbols.
//   PRBS: over the 64 payload bits, sent as D characters through 8b/10b,
//       not raw on the line as in LiteICLink; the RX checks the decoded
//       bytes. Send commas first (rx_align), then switch to PRBS.
//
//   Flops at the CC_SERDES boundary, no logic in between:
//     TX: one flop stage (tx_ser) drives every TX datapath input of CC_SERDES;
//         the controls (resets, comma align, regfile) come from flops too;
//     RX: one flop stage (rx_ser) takes every RX datapath and status output
//         first; TX_RESET_DONE_O goes into a synchronizer flop.
//   Latency, TX data in to RX data out: 1 (tx_enc) + 2 (encoder) + 1 (tx_ser) + CC_SERDES
//   + 1 (rx_ser) + 1 (rx) clocks; with TX_HARD_8B10B the 2 encoder clocks go.
//
//   LINE_RATE (Mb/s): 1250, 2500 or 5000, the PLL setting; the core clocks
//   run at LINE_RATE / 80. TX_HARD_8B10B: CC_SERDES encodes TX instead of the
//   fabric encoder, whose 8-word running-disparity chain closes ~33 MHz; on
//   by default at 5 Gb/s (62.5 MHz).
//
//   Clocks: clk_tx = PLL_CLK_O (line rate / 80, 31.25 MHz at 2.5 Gb/s);
//   clk_rx = RX_CLK_O. clk_reg (the board clock) runs the bring-up: three
//   regfile writes (iclink_phy_pkg::CFG_SEQ), then TX and RX out of reset.
//
//   On the chip CC_SERDES connects to its own serial pins and reference
//   clock. In simulation the SerDes BFM (ccfpga_serdes, same name and ports
//   as Cologne Chip's model) takes its place: serial pins and the reference
//   are ports, and the SerDes enable goes through its config port.
//==========================================================================

module iclink_serdes_gm
  import iclink_pkg::*;
  import iclink_phy_pkg::*;
#(
    parameter int LINE_RATE     = 2500,
    parameter bit TX_HARD_8B10B = (LINE_RATE >= 5000)
) (
`ifndef SYNTHESIS
    input  logic clk_ref,  // SerDes reference, 100 MHz
    input  logic ser_rxp,
    input  logic ser_rxn,
    output logic ser_txp,
    output logic ser_txn,
`endif

    input logic      clk_reg,  // bring-up clock, the board clock
    input logic      arst_n,   // reset, released on clk_reg
    input phy_ctrl_t ctrl,     // any clock

    output logic      clk_tx,
    output logic      tx_ready,  // on clk_tx: TX out of reset
    input  phy_word_t tx,        // on clk_tx, taken every clock

    output logic                       clk_rx,
    output logic                       rx_ready,       // on clk_rx: RX out of reset, CDR locked
    output logic                       rx_aligned,     // on clk_rx: comma alignment acquired
    output phy_word_t                  rx,             // on clk_rx, every clock
    output logic      [PHY_NWORDS-1:0] rx_invalid,     // on clk_rx: not in table or disparity error
    output logic      [          31:0] rx_prbs_errors  // on clk_rx: clocks with a PRBS error
);

  //-----------------------------------------------------------------------
  // Bring-up on clk_reg: the regfile writes, then TX and RX out of reset
  //-----------------------------------------------------------------------
  localparam cfg_seq_t CFG_SEQ = cfg_seq(LINE_RATE);

  if (!(LINE_RATE inside {1250, 2500, 5000})) begin : g_bad_rate
    $error("iclink_serdes_gm: LINE_RATE %0d: use 1250, 2500 or 5000", LINE_RATE);
  end : g_bad_rate

  typedef enum logic [2:0] {
    CFG_IDLE,
    CFG_WRITE,
    CFG_WAIT,
    CFG_NEXT,
    CFG_DONE
  } cfg_state_t;

  cfg_state_t                  cfg_state;
  logic       [ CFG_IDX_W-1:0] cfg_idx;
  logic       [CFG_WAIT_W-1:0] cfg_wait;
  logic                        reg_en;  // one-clock regfile write strobe
  cfg_write_t                  reg_wr;
  logic                        pll_reset;  // PLL in reset until the board clock runs
  logic                        serdes_reset;  // TX and RX in reset until the bring-up is done
`ifndef SYNTHESIS
  logic cfg_en;  // the BFM: the SerDes enable goes to its config port
`endif

  always_ff @(posedge clk_reg or negedge arst_n) begin
    if (!arst_n) begin
      cfg_state    <= CFG_IDLE;
      cfg_idx      <= '0;
      cfg_wait     <= '0;
      reg_en       <= 1'b0;
      reg_wr       <= '0;
      pll_reset    <= 1'b1;
      serdes_reset <= 1'b1;
`ifndef SYNTHESIS
      cfg_en <= 1'b0;
`endif
    end
    else begin
      reg_en    <= 1'b0;
      pll_reset <= 1'b0;
`ifndef SYNTHESIS
      cfg_en <= 1'b0;
`endif

      unique case (cfg_state)
        CFG_IDLE: begin
          cfg_wait <= cfg_wait + 1'b1;
          if (cfg_wait == '1) begin
            cfg_state <= CFG_WRITE;
          end
        end

        CFG_WRITE: begin
`ifdef SYNTHESIS
          reg_en <= 1'b1;
`else
          reg_en <= CFG_SEQ[cfg_idx].addr != SERDES_CFG_ADDR;
          cfg_en <= CFG_SEQ[cfg_idx].addr == SERDES_CFG_ADDR;
`endif
          reg_wr    <= CFG_SEQ[cfg_idx];
          cfg_state <= CFG_WAIT;
        end

        CFG_WAIT: begin
          cfg_wait <= cfg_wait + 1'b1;
          if (cfg_wait == '1) begin
            cfg_state <= CFG_NEXT;
          end
        end

        CFG_NEXT: begin
          if (cfg_idx == CFG_IDX_W'(CFG_WRITES - 1)) begin
            cfg_state <= CFG_DONE;
          end
          else begin
            cfg_idx   <= cfg_idx + 1'b1;
            cfg_state <= CFG_WRITE;
          end
        end

        CFG_DONE: begin
          serdes_reset <= 1'b0;
        end
      endcase
    end
  end

  //-----------------------------------------------------------------------
  // TX on clk_tx: PRBS or data -> 8b/10b -> tx_ser flops -> CC_SERDES
  //-----------------------------------------------------------------------
  logic tx_ready_meta;
  prbs_cfg_t tx_prbs_meta, tx_prbs;  // for the K mask; PRBS TX syncs its own
  logic [    PHY_DW-1:0] tx_payload;
  logic [    PHY_DW-1:0] tx_enc_d;  // tx_payload, registered: the PRBS mux and the
  logic [PHY_NWORDS-1:0] tx_enc_k;  // encoder tables in one clock miss 31.25 MHz
  logic                  tx_resetdone;  // CC_SERDES output, read only by the sync below

  // tx_ser: the TX datapath into CC_SERDES, straight from these flops
  typedef struct packed {
    byte_t [PHY_NWORDS-1:0] d;
    logic [PHY_NWORDS-1:0]  k;         // TX_HARD_8B10B: K flags
    logic [PHY_NWORDS-1:0]  dispmode;  // else symbol bit 8
    logic [PHY_NWORDS-1:0]  dispval;   // else symbol bit 9
  } tx_ser_t;
  tx_ser_t tx_ser;

  always_ff @(posedge clk_tx or negedge arst_n) begin
    if (!arst_n) begin
      tx_ready_meta <= 1'b0;
      tx_ready      <= 1'b0;
      tx_prbs_meta  <= PRBS_OFF;
      tx_prbs       <= PRBS_OFF;
    end
    else begin
      tx_ready_meta <= tx_resetdone;
      tx_ready      <= tx_ready_meta;
      tx_prbs_meta  <= ctrl.tx_prbs;
      tx_prbs       <= tx_prbs_meta;
    end
  end

  iclink_prbs_tx #(
      .WIDTH(PHY_DW)
  ) u_prbs_tx (
      .clk     (clk_tx),
      .arst_n  (tx_ready),
      .config_i(ctrl.tx_prbs),
      .i       (tx.d),
      .o       (tx_payload)
  );

  always_ff @(posedge clk_tx or negedge tx_ready) begin
    if (!tx_ready) begin
      tx_enc_d <= '0;
      tx_enc_k <= '0;
    end
    else begin
      tx_enc_d <= tx_payload;
      tx_enc_k <= (tx_prbs == PRBS_OFF) ? tx.k : '0;  // PRBS bytes are D characters
    end
  end

  if (TX_HARD_8B10B) begin : g_tx_hard
    // CC_SERDES encodes: bytes and K flags go straight to it
    always_ff @(posedge clk_tx or negedge arst_n) begin
      if (!arst_n) begin
        tx_ser <= '0;
      end
      else begin
        tx_ser.d <= tx_enc_d;
        tx_ser.k <= tx_enc_k;
      end
    end
  end : g_tx_hard
  else begin : g_tx_soft
    symbol_t [PHY_NWORDS-1:0] tx_symbol;
    logic    [PHY_NWORDS-1:0] NC_tx_disparity;  // running disparity: not needed

    iclink_8b10b_enc #(
        .NWORDS(PHY_NWORDS)
    ) u_enc (
        .clk      (clk_tx),
        .arst_n   (tx_ready),
        .ce       (1'b1),
        .d        (tx_enc_d),
        .k        (tx_enc_k),
        .symbol   (tx_symbol),
        .disparity(NC_tx_disparity)
    );

    always_ff @(posedge clk_tx or negedge arst_n) begin
      if (!arst_n) begin
        tx_ser <= '0;
      end
      else begin
        for (int w = 0; w < PHY_NWORDS; w++) begin
          tx_ser.d[w]        <= tx_symbol[w][7:0];
          tx_ser.dispmode[w] <= tx_symbol[w][8];
          tx_ser.dispval[w]  <= tx_symbol[w][9];
        end
      end
    end
  end : g_tx_soft

  //-----------------------------------------------------------------------
  // RX on clk_rx: CC_SERDES -> rx_ser flops -> data, K, invalid; PRBS check
  //-----------------------------------------------------------------------
  // the RX datapath out of CC_SERDES, read only by the rx_ser flops
  typedef struct packed {
    byte_t [PHY_NWORDS-1:0] d;
    logic [PHY_NWORDS-1:0]  k;
    logic [PHY_NWORDS-1:0]  not_in_table;
    logic [PHY_NWORDS-1:0]  disp_err;
    logic                   aligned;
    logic                   resetdone;
  } rx_ser_t;
  rx_ser_t                  rx_hm;  // hard-macro outputs
  rx_ser_t                  rx_ser;  // the same, registered first
  logic    [PHY_NWORDS-1:0] NC_rx_comma;  // RX_CHAR_IS_COMMA_O: K tells the same

  logic                     rx_ready_meta;
  logic rx_pause_meta, rx_pause;
  logic rx_align_meta, rx_align;  // into CC_SERDES, from a flop

  always_ff @(posedge clk_rx or negedge arst_n) begin
    if (!arst_n) begin
      rx_ser        <= '0;
      rx_ready_meta <= 1'b0;
      rx_ready      <= 1'b0;
      rx_aligned    <= 1'b0;
      rx_pause_meta <= 1'b0;
      rx_pause      <= 1'b0;
      rx_align_meta <= 1'b0;
      rx_align      <= 1'b0;
    end
    else begin
      rx_ser        <= rx_hm;
      rx_ready_meta <= rx_ser.resetdone;
      rx_ready      <= rx_ready_meta;
      rx_aligned    <= rx_ser.aligned;
      rx_pause_meta <= ctrl.rx_prbs_pause;
      rx_pause      <= rx_pause_meta;
      rx_align_meta <= ctrl.rx_align;
      rx_align      <= rx_align_meta;
    end
  end

  always_ff @(posedge clk_rx or negedge rx_ready) begin
    if (!rx_ready) begin
      rx         <= '0;
      rx_invalid <= '0;
    end
    else begin
      rx.d       <= rx_ser.d;
      rx.k       <= rx_ser.k;
      rx_invalid <= rx_ser.not_in_table | rx_ser.disp_err;
    end
  end

  iclink_prbs_rx #(
      .WIDTH(PHY_DW)
  ) u_prbs_rx (
      .clk     (clk_rx),
      .arst_n  (rx_ready),
      .config_i(ctrl.rx_prbs),
      .pause   (rx_pause),
      .i       (rx.d),
      .errors  (rx_prbs_errors)
  );

  //-----------------------------------------------------------------------
  // The SerDes
  //-----------------------------------------------------------------------
`ifdef SYNTHESIS

  CC_SERDES #(
      .SERDES_ENABLE   (1'b1),
      .SERDES_AUTO_INIT(1'b0)   // the bring-up above sets the PLL up
  ) u_serdes (
      .PLL_RESET_I           (pll_reset),
      .PLL_CLK_O             (clk_tx),
      .REGFILE_CLK_I         (clk_reg),
      .REGFILE_WE_I          (reg_en),
      .REGFILE_EN_I          (reg_en),
      .REGFILE_ADDR_I        (reg_wr.addr),
      .REGFILE_DI_I          (reg_wr.data),
      .REGFILE_MASK_I        (16'hFFFF),
      .REGFILE_RDY_O         (  /*LINT:OK*/),       // the bring-up waits a fixed time instead
      .REGFILE_DO_O          (  /*LINT:OK*/),       // write-only
      .LOOPBACK_I            (3'b000),
      // TX
      .TX_RESET_I            (serdes_reset),
      .TX_PCS_RESET_I        (1'b0),
      .TX_PMA_RESET_I        (1'b0),
      .TX_CLK_I              (clk_tx),
      .TX_DATA_I             (tx_ser.d),
      .TX_CHAR_IS_K_I        (tx_ser.k),            // 0 unless TX_HARD_8B10B
      .TX_CHAR_DISPMODE_I    (tx_ser.dispmode),
      .TX_CHAR_DISPVAL_I     (tx_ser.dispval),
      .TX_8B10B_EN_I         (TX_HARD_8B10B),
      .TX_8B10B_BYPASS_I     ('0),
      .TX_PRBS_SEL_I         (3'b000),              // PRBS is in the fabric
      .TX_PRBS_FORCE_ERR_I   (1'b0),
      .TX_POWER_DOWN_N_I     (1'b1),
      .TX_POLARITY_I         (1'b0),
      .TX_ELEC_IDLE_I        (1'b0),
      .TX_DETECT_RX_I        (1'b0),
      .TX_RESET_DONE_O       (tx_resetdone),
      .TX_BUF_ERR_O          (  /*LINT:OK*/),       // TX buffer status: not used
      .TX_DETECT_RX_DONE_O   (  /*LINT:OK*/),       // receiver detection is off
      .TX_DETECT_RX_PRESENT_O(  /*LINT:OK*/),       // receiver detection is off
      // RX
      .RX_RESET_I            (serdes_reset),
      .RX_PMA_RESET_I        (1'b0),
      .RX_EQA_RESET_I        (1'b0),
      .RX_CDR_RESET_I        (1'b0),
      .RX_PCS_RESET_I        (1'b0),
      .RX_BUF_RESET_I        (1'b0),
      .RX_CLK_I              (clk_rx),
      .RX_CLK_O              (clk_rx),
      .RX_POWER_DOWN_N_I     (1'b1),
      .RX_POLARITY_I         (1'b0),
      .RX_8B10B_EN_I         (1'b1),
      .RX_8B10B_BYPASS_I     ('0),
      .RX_PRBS_SEL_I         (3'b000),              // PRBS is in the fabric
      .RX_PRBS_CNT_RESET_I   (1'b0),
      .RX_PRBS_ERR_O         (  /*LINT:OK*/),       // PRBS is in the fabric
      .RX_EN_EI_DETECTOR_I   (1'b0),
      .RX_COMMA_DETECT_EN_I  (1'b1),
      .RX_SLIDE_I            (1'b0),
      .RX_MCOMMA_ALIGN_I     (rx_align),
      .RX_PCOMMA_ALIGN_I     (rx_align),
      .RX_DATA_O             (rx_hm.d),
      .RX_CHAR_IS_K_O        (rx_hm.k),
      .RX_NOT_IN_TABLE_O     (rx_hm.not_in_table),
      .RX_DISP_ERR_O         (rx_hm.disp_err),
      .RX_CHAR_IS_COMMA_O    (NC_rx_comma),
      .RX_BYTE_IS_ALIGNED_O  (rx_hm.aligned),
      .RX_BYTE_REALIGN_O     (  /*LINT:OK*/),       // alignment is acquired once
      .RX_RESET_DONE_O       (rx_hm.resetdone),
      .RX_BUF_ERR_O          (  /*LINT:OK*/),       // RX buffer status: not used
      .RX_EI_EN_O            (  /*LINT:OK*/)        // electrical-idle detector is off
  );

`else

  // The BFM: the SerDes enable goes through its config port, the PLL writes
  // through the regfile, as on the chip
  logic        reset_core_pll_n;

  // the BFM's outputs that are not needed
  logic [ 6:0] NC_scan_out_o;
  logic        NC_refclk_sel_o;
  logic        NC_refclk_rterm_o;
  logic [15:0] NC_regfile_do_o;
  logic        NC_regfile_rdy_o;
  logic        NC_tx_buf_err_o;
  logic        NC_rx_detect_done_o;
  logic        NC_rx_present_o;
  logic        NC_term_serio_o;
  logic        NC_rx_prbs_err_o;
  logic        NC_rx_buf_err_o;
  logic        NC_rx_byte_realign_o;
  logic        NC_rx_ei_en_o;

  ccfpga_serdes u_serdes (
      .clk_ref_i           (clk_ref),
      .clk_reg_i           (clk_reg),
      .clk_cfg_i           (clk_reg),
      .clk_core_tx_i       (clk_tx),
      .clk_core_rx_i       (clk_rx),
      .clk_core_rx_o       (clk_rx),
      .reset_n_i           (arst_n),
      .reset_reg_n_i       (arst_n),
      .reset_core_tx_n_i   (reset_core_pll_n),
      .reset_core_rx_n_i   (reset_core_pll_n),
      .testmode_i          (1'b0),
      .scan_enable_i       (1'b0),
      .scan_in_i           (7'h0),
      .scan_out_o          (NC_scan_out_o),
      .loopback_i          (3'b000),
      .pll_reset_i         (pll_reset),
      .clk_core_pll_o      (clk_tx),
      .reset_core_pll_n_o  (reset_core_pll_n),
      .refclk_sel_o        (NC_refclk_sel_o),
      .refclk_rterm_o      (NC_refclk_rterm_o),
      .RX_SERIO_P_B        (ser_rxp),
      .RX_SERIO_N_B        (ser_rxn),
      .TX_SERIO_P_B        (ser_txp),
      .TX_SERIO_N_B        (ser_txn),
      .regfile_we_i        (reg_en),
      .regfile_en_i        (reg_en),
      .regfile_addr_i      (reg_wr.addr),
      .regfile_mask_i      (16'hFFFF),
      .regfile_di_i        (reg_wr.data),
      .regfile_do_o        (NC_regfile_do_o),
      .regfile_rdy_o       (NC_regfile_rdy_o),
      .cfg_en_i            (cfg_en),
      .reset_cfg_i         (1'b0),
      .cfgfile_di_i        (reg_wr.data),
      .cfgfile_valid_i     (cfg_en),
      .cfgfile_addr_i      (reg_wr.addr),
      .tx_reset_i          (serdes_reset),
      .tx_pcs_reset_i      (1'b0),
      .tx_pma_reset_i      (1'b0),
      .tx_elec_idle_i      (1'b0),
      .tx_detect_rx_i      (1'b0),
      .tx_prbs_sel_i       (3'b000),
      .tx_prbs_force_err_i (1'b0),
      .tx_powerdown_n_i    (1'b1),
      .tx_data_i           (tx_ser.d),
      .tx_char_is_k_i      (tx_ser.k),
      .tx_polarity_i       (1'b0),
      .tx_8b10b_en_i       (TX_HARD_8B10B),
      .tx_8b10b_bypass_i   ('0),
      .tx_char_dispmode_i  (tx_ser.dispmode),
      .tx_char_dispval_i   (tx_ser.dispval),
      .tx_buf_err_o        (NC_tx_buf_err_o),
      .tx_resetdone_o      (tx_resetdone),
      .rx_detect_done_o    (NC_rx_detect_done_o),
      .rx_present_o        (NC_rx_present_o),
      .TERM_SERIO_O        (NC_term_serio_o),
      .rx_reset_i          (serdes_reset),
      .rx_pma_reset_i      (1'b0),
      .rx_eqa_reset_i      (1'b0),
      .rx_cdr_reset_i      (1'b0),
      .rx_pcs_reset_i      (1'b0),
      .rx_buf_reset_i      (1'b0),
      .rx_prbs_sel_i       (3'b000),
      .rx_prbs_cnt_reset_i (1'b0),
      .rx_powerdown_n_i    (1'b1),
      .rx_en_ei_detector_i (1'b0),
      .rx_comma_detect_en_i(1'b1),
      .rx_slide_i          (1'b0),
      .rx_polarity_i       (1'b0),
      .rx_8b10b_en_i       (1'b1),
      .rx_8b10b_bypass_i   ('0),
      .rx_mcomma_align_i   (rx_align),
      .rx_pcomma_align_i   (rx_align),
      .rx_prbs_err_o       (NC_rx_prbs_err_o),
      .rx_data_o           (rx_hm.d),
      .rx_char_is_k_o      (rx_hm.k),
      .rx_char_is_comma_o  (NC_rx_comma),
      .rx_not_in_table_o   (rx_hm.not_in_table),
      .rx_disp_err_o       (rx_hm.disp_err),
      .rx_buf_err_o        (NC_rx_buf_err_o),
      .rx_byte_is_aligned_o(rx_hm.aligned),
      .rx_byte_realign_o   (NC_rx_byte_realign_o),
      .rx_resetdone_o      (rx_hm.resetdone),
      .rx_ei_en_o          (NC_rx_ei_en_o)
  );

`endif

endmodule : iclink_serdes_gm

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
