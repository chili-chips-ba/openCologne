// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// SerWB packetizer (iclink_serwb_tx) against LiteICLink's own Packetizer:
// the same packets in (vectors/serwb_packets.txt), the same words out
// (vectors/serwb_wire.hex, written by gen_serwb_vectors.py from LiteICLink),
// bit for bit, with random gaps on the input (d_valid) and random stalls on
// the line (o_ready, as XOFF would).
module tb_serwb_tx;
  import iclink_serwb_pkg::*;

  localparam int MAX_PACKETS = 256;
  localparam int MAX_WIRE    = 8192;

  logic clk;
  logic arst_n;

  initial begin : _clk
    clk = 1'b0;
    forever #16 clk = ~clk;  // 31.25 MHz
  end : _clk

  logic hdr_valid, hdr_ready, d_valid, d_ready, o_ready;
  logic [ 7:0] hdr_port;
  logic [13:0] hdr_words;
  word_t [1:0] d_word, o_word;
  logic [1:0] o_valid;

  iclink_serwb_tx dut (.*);

  // vectors
  int n_packets, n_wire;
  logic  [7:0] pk_port  [MAX_PACKETS];
  int          pk_words [MAX_PACKETS];
  word_t       pk_data  [MAX_PACKETS] [16];
  word_t       ref_words[   MAX_WIRE];

  initial begin : _load
    int fd, port, words;
    n_packets = 0;
    n_wire    = 0;
    fd        = $fopen("vectors/serwb_packets.txt", "r");
    while ($fscanf(
        fd, "%h %h", port, words
    ) == 2) begin
      pk_port[n_packets]  = 8'(port);
      pk_words[n_packets] = words;
      for (int i = 0; i < words; i++) begin
        void'($fscanf(fd, "%h", pk_data[n_packets][i]));
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

  // driver, clocked: one header per packet, then the words in pairs, with gaps
  int p, i;  // packet, word
  logic in_pkt;

  initial begin : _reset
    arst_n = 1'b0;
    repeat (3) @(posedge clk);
    arst_n = 1'b1;
  end : _reset

  always_ff @(posedge clk or negedge arst_n) begin : _drive
    if (!arst_n) begin
      p         <= 0;
      i         <= 0;
      in_pkt    <= 1'b0;
      hdr_valid <= 1'b0;
      hdr_port  <= '0;
      hdr_words <= '0;
      d_valid   <= 1'b0;
      d_word    <= '0;
    end
    else if (!in_pkt) begin
      if (hdr_valid && hdr_ready) begin  // header taken
        hdr_valid <= 1'b0;
        in_pkt    <= 1'b1;
        i         <= 0;
      end
      else if (!hdr_valid && p < n_packets) begin
        hdr_valid <= 1'b1;
        hdr_port  <= pk_port[p];
        hdr_words <= 14'(pk_words[p]);
      end
    end
    else begin
      if (d_valid && d_ready) begin  // pair taken
        d_valid <= 1'b0;
        if (i + 2 >= pk_words[p]) begin
          in_pkt <= 1'b0;
          p      <= p + 1;
        end
        i <= i + 2;
      end
      else if (!d_valid && ($urandom % 4) != 0) begin  // else an input gap
        d_valid   <= 1'b1;
        d_word[0] <= pk_data[p][i];
        d_word[1] <= (i + 1 < pk_words[p]) ? pk_data[p][i+1] : 32'hDEAD_BEEF;  // unused slot
      end
    end
  end : _drive

  // checker: every valid slot, slot 0 then slot 1, against the wire words
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
      for (int s = 0; s < 2; s++) begin
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
    $display("TB_SERWB_TX: %s  %0d packets, %0d words bit-exact with LiteICLink, %0d wrong",
             (got == n_wire && bad == 0) ? "PASS" : "FAIL", n_packets, got - bad, bad);
    $finish;
  end : _end

endmodule : tb_serwb_tx

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
