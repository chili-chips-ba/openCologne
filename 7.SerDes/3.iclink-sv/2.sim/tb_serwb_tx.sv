// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// SerWB packetizer (iclink_serwb_tx) against LiteICLink's own Packetizer:
// the same packets in (vectors/serwb_packets.txt), the same words out
// (vectors/serwb_wire.hex, written by gen_serwb_vectors.py from LiteICLink),
// bit for bit, with random gaps between packets and random stalls on the
// line (o_ready, as XOFF would). W (2 or 4) is the words a clock.
module tb_serwb_tx;
  import iclink_serwb_pkg::*;

  parameter int W = 2;
  localparam int TW = $clog2(W + 1);
  localparam int MAX_PACKETS = 256;
  localparam int MAX_WIRE    = 8192;

  logic clk;
  logic arst_n;

  initial begin : _clk
    clk = 1'b0;
    forever #16 clk = ~clk;  // 31.25 MHz
  end : _clk

  logic hdr_valid, hdr_ready, o_ready;
  logic  [   7:0] hdr_port;
  logic  [  13:0] hdr_words;
  word_t [ W-1:0] d_word, o_word;
  logic  [TW-1:0] d_take;
  logic  [ W-1:0] o_valid;

  iclink_serwb_tx #(.W(W)) dut (.*);

  // vectors; the payload words of all packets also as one stream, as the
  // TX FIFO holds them
  int n_packets, n_wire;
  logic  [7:0] pk_port  [MAX_PACKETS];
  int          pk_words [MAX_PACKETS];
  word_t       stream   [$];
  word_t       ref_words[MAX_WIRE];

  initial begin : _load
    int fd, port, words;
    word_t w;
    n_packets = 0;
    n_wire    = 0;
    fd        = $fopen("vectors/serwb_packets.txt", "r");
    while ($fscanf(
        fd, "%h %h", port, words
    ) == 2) begin
      pk_port[n_packets]  = 8'(port);
      pk_words[n_packets] = words;
      for (int i = 0; i < words; i++) begin
        void'($fscanf(fd, "%h", w));
        stream.push_back(w);
      end
      n_packets++;
    end
    $fclose(fd);
    $readmemh("vectors/serwb_wire.hex", ref_words);
    for (int k = 0; k < n_packets; k++) begin
      n_wire += pk_words[k] + 3;  // preamble, port / length, CRC
    end
  end : _load

  // line stalls, about one clock in five
  always_ff @(posedge clk) begin : _stall
    o_ready <= ($urandom % 5) != 0;
  end : _stall

  initial begin : _reset
    arst_n = 1'b0;
    repeat (3) @(posedge clk);
    arst_n = 1'b1;
  end : _reset

  // the FIFO model: the next W words of the stream, d_take of them taken
  int rd;

  always_comb begin : _window
    for (int i = 0; i < W; i++) begin
      d_word[i] = (rd + i < stream.size()) ? stream[rd+i] : 32'hDEAD_BEEF;
    end
  end : _window

  // driver, clocked: one header per packet, with random gaps between them
  int p;  // packet

  always_ff @(posedge clk or negedge arst_n) begin : _drive
    if (!arst_n) begin
      p         <= 0;
      rd        <= 0;
      hdr_valid <= 1'b0;
      hdr_port  <= '0;
      hdr_words <= '0;
    end
    else begin
      rd <= rd + int'(d_take);
      if (hdr_valid && hdr_ready) begin  // header taken
        hdr_valid <= 1'b0;
        p         <= p + 1;
      end
      else if (!hdr_valid && p < n_packets && ($urandom % 4) != 0) begin
        hdr_valid <= 1'b1;
        hdr_port  <= pk_port[p];
        hdr_words <= 14'(pk_words[p]);
      end
    end
  end : _drive

  // checker: every valid slot, slot 0 first, against the wire words
  int got, bad;

  always_ff @(posedge clk or negedge arst_n) begin : _check
    int g, e;
    if (!arst_n) begin
      got <= 0;
      bad <= 0;
    end
    else begin
      g = got;
      e = bad;
      for (int s = 0; s < W; s++) begin
        if (o_valid[s] && o_ready) begin
          if (g < n_wire && o_word[s] !== ref_words[g]) begin
            if (e < 10) begin
              $display("ERROR: word %0d: got %h, LiteICLink %h", g, o_word[s], ref_words[g]);
            end
            e++;
          end
          g++;
        end
      end
      got <= g;
      bad <= e;
    end
  end : _check

  initial begin : _end
    wait (n_wire > 0);
    fork
      wait (got >= n_wire);
      begin
        repeat (100000) @(posedge clk);
      end
    join_any
    disable fork;
    $display("TB_SERWB_TX: %s  W=%0d, %0d packets, %0d words bit-exact with LiteICLink, %0d wrong",
             (got == n_wire && bad == 0 && rd == stream.size()) ? "PASS" : "FAIL", W, n_packets,
             got - bad, bad);
    $finish;
  end : _end

endmodule : tb_serwb_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
