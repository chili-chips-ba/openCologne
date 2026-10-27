// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// SerWB depacketizer (iclink_serwb_rx) against LiteICLink's own
// CRCDepacketizer: the same stream in (vectors/serwb_rx_wire.hex), the same
// packets out (serwb_rx_expect.txt) and the same CRC error and drop counts
// (serwb_rx_counts.txt), all written by gen_serwb_rx_vectors.py from
// LiteICLink. The words land in random slots with random gaps, so packets
// start in every slot, and with W = 4 the next packet starts next to the
// CRC before it. Then the timeout: a packet cut short must be dropped.
module tb_serwb_rx;
  import iclink_serwb_pkg::*;

  parameter int W = 2;
  localparam int DW = $clog2(W / 2 + 1);
  localparam int TIMEOUT_CLKS = 50;

  logic clk;
  logic arst_n;

  initial begin : _clk
    clk = 1'b0;
    forever #16 clk = ~clk;  // 31.25 MHz
  end : _clk

  word_t [W-1:0] i_word, o_word;
  logic  [W-1:0] i_valid, o_valid;
  logic  [   7:0] o_port;
  logic  [DW-1:0] o_drop;
  logic o_commit, o_rewind, o_crc_error;
  logic i_hold;  // the pause hold: tb_serwb_pump tests it
  logic half_clk_strobe;  // every clock: the depacketizer alone

  assign i_hold = 1'b0;
  assign half_clk_strobe = 1'b1;

  iclink_serwb_rx #(
      .W           (W),
      .MAX_WORDS   (16),
      .TIMEOUT_CLKS(TIMEOUT_CLKS)
  ) dut (
      .*
  );

  // vectors
  word_t       stream  [$];
  word_t       exp_pkt [$] [$];
  logic  [7:0] exp_port[$];
  int exp_crc_errors, exp_drops;

  initial begin : _load
    int fd, port, words;
    word_t w;
    word_t pkt[$];
    fd = $fopen("vectors/serwb_rx_wire.hex", "r");
    while ($fscanf(
        fd, "%h", w
    ) == 1) begin
      stream.push_back(w);
    end
    $fclose(fd);
    fd = $fopen("vectors/serwb_rx_expect.txt", "r");
    while ($fscanf(
        fd, "%h %h", port, words
    ) == 2) begin
      pkt.delete();
      for (int i = 0; i < words; i++) begin
        void'($fscanf(fd, "%h", w));
        pkt.push_back(w);
      end
      exp_pkt.push_back(pkt);
      exp_port.push_back(8'(port));
    end
    $fclose(fd);
    fd = $fopen("vectors/serwb_rx_counts.txt", "r");
    void'($fscanf(fd, "%d %d", exp_crc_errors, exp_drops));
    $fclose(fd);
    // the timeout case: preamble, header for 4 words, 2 words, then silence
    stream.push_back(SERWB_PREAMBLE);
    stream.push_back(serwb_header(8'h77, 14'd4));
    stream.push_back(32'h1111_1111);
    stream.push_back(32'h2222_2222);
    exp_drops++;
  end : _load

  initial begin : _reset
    arst_n = 1'b0;
    repeat (3) @(posedge clk);
    arst_n = 1'b1;
  end : _reset

  // driver: each slot takes the next word, or a gap, at random
  int sent;

  always_ff @(posedge clk or negedge arst_n) begin : _drive
    int n;
    if (!arst_n) begin
      sent    <= 0;
      i_word  <= '0;
      i_valid <= '0;
    end
    else begin
      n = sent;
      for (int s = 0; s < W; s++) begin
        i_valid[s] <= 1'b0;
        if (n < stream.size() && ($urandom % 4) != 0) begin
          i_word[s]  <= stream[n];
          i_valid[s] <= 1'b1;
          n++;
        end
      end
      sent <= n;
    end
  end : _drive

  // checker: words collect until o_commit (compare) or o_drop (discard)
  word_t pend[$];
  int n_pkt, n_bad, n_crc_errors, n_drops;

  always_ff @(posedge clk or negedge arst_n) begin : _check
    if (!arst_n) begin
      pend.delete();
      n_pkt        <= 0;
      n_bad        <= 0;
      n_crc_errors <= 0;
      n_drops      <= 0;
    end
    else begin
      for (int s = 0; s < W; s++) begin
        if (o_valid[s]) begin
          pend.push_back(o_word[s]);
        end
      end
      if (o_commit) begin
        if (n_pkt >= exp_pkt.size() || o_port != exp_port[n_pkt] || pend != exp_pkt[n_pkt]) begin
          if (n_bad < 10) begin
            $display("ERROR: packet %0d: port %h, %0d words, not as LiteICLink", n_pkt, o_port,
                     pend.size());
          end
          n_bad <= n_bad + 1;
        end
        n_pkt <= n_pkt + 1;
        pend.delete();
      end
      if (o_rewind) begin
        pend.delete();
      end
      n_drops <= n_drops + int'(o_drop);
      if (o_crc_error) begin
        n_crc_errors <= n_crc_errors + 1;
      end
    end
  end : _check

  initial begin : _end
    logic pass;
    wait (arst_n && sent == stream.size() && stream.size() > 0);
    repeat (TIMEOUT_CLKS + 10) @(posedge clk);
    pass = n_pkt == exp_pkt.size() && n_bad == 0 && n_crc_errors == exp_crc_errors &&
        n_drops == exp_drops;
    $display("TB_SERWB_RX: %s  W=%0d, %0d of %0d packets as LiteICLink, %0d wrong;",
             pass ? "PASS" : "FAIL", W, n_pkt, exp_pkt.size(), n_bad);
    $display("  CRC errors %0d (%0d); drops %0d (%0d, incl. 1 timeout)", n_crc_errors,
             exp_crc_errors, n_drops, exp_drops);
    $finish;
  end : _end

endmodule : tb_serwb_rx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
