// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

// FIFO pump, two sides, SerDes out of the loop: pump A's phy_tx goes to
// pump B's phy_rx and back, on the 64-bit + 8 K digital bus, through a
// LINE_LAT-clock delay that stands for PHY TX + CC_SERDES + PHY RX (as
// measured on the SerDes BFM, PHY data in to PHY data out). One clock for
// the pumps and both CPUs: the line clock (W = 2), or half of it (W = 4),
// with 2:1 gearboxes (iclink_gearbox) to the line, as for 5 Gb/s.
//
//   1. both ways at once, random push and pop: every word arrives, in order
//   2. B stops reading while A floods: B's RX FIFO fills to XOFF_LEVEL, the
//      XOFF stops A, A's TX FIFO fills and pushes back on A's CPU; B's RX
//      FIFO must not overflow. Then B reads again: XON, A drains, all
//      words arrive in order. The hold outlasts the depacketizer timeout
//      (TIMEOUT_CLKS, short here), so a packet paused mid-way must wait, not
//      drop.
//   3. line rate: A's TX is held (tx_hold) while A's CPU fills the TX FIFO (1024
//      words, 64 packets); then the burst goes out with no CPU in the way,
//      and B's depacketizer must see BURST_RATE words a clock or more.
//
// The fill levels are logged (pump_levels.csv) for the End2End Flow
// section of the README, with the peak RX level above XOFF_LEVEL.
module tb_serwb_pump;
  import iclink_phy_pkg::*;
  import iclink_serwb_pkg::*;

  parameter int W = 2;  // words a pump clock
  localparam int NP         = W / 2;
  localparam int DEPTH      = 1024;
  localparam int XOFF_LEVEL = DEPTH - 96 * W;  // the pump's default (RT_CLKS = 96)
  localparam int LINE_LAT   = 27;  // line clocks, PHY data in to out on the BFM (sim_phy_oneway)
  localparam int TIMEOUT    = 500;            // pump clocks: well under the phase 2 hold
  localparam int N_RANDOM   = 6000;           // words each way, phase 1
  localparam int N_FLOOD    = 4000;           // words A -> B, phase 2
  localparam int N_BURST    = DEPTH;          // words A -> B, phase 3: a full TX FIFO
  localparam int N_MEASURE  = 800;            // words timed, before B's XOFF level
  localparam real BURST_RATE = 1.59 * W / 2;  // words a clock: 16 per packet of 10 (W = 2) or 5 clocks
  localparam int AW         = $clog2(DEPTH);

  logic clk_line;
  logic clk_div, clk;  // the pumps' clock: the line clock, or half of it (W = 4)
  logic arst_n;

  initial begin : _clocks
    clk_line = 1'b0;
    forever #(32.0 / W) clk_line = ~clk_line;  // 31.25 MHz (W = 2), 62.5 MHz (W = 4)
  end : _clocks

  always_ff @(posedge clk_line or negedge arst_n) begin : _div
    if (!arst_n) begin
      clk_div <= 1'b0;
    end
    else begin
      clk_div <= ~clk_div;
    end
  end : _div

  assign clk = (W == 2) ? clk_line : clk_div;

  initial begin : _reset
    arst_n = 1'b0;
    #200;
    arst_n = 1'b1;
  end : _reset

  // CPU ports of each side
  logic a_push, a_full, a_pop, a_empty, b_push, b_full, b_pop, b_empty;
  word_t a_wdata, a_rdata, b_wdata, b_rdata;
  logic [AW:0] a_used, a_avail, b_used, b_avail;
  phy_word_t [NP-1:0] a_tx, b_tx, a_rx, b_rx;  // on the pumps' clock
  phy_word_t a_ltx, b_ltx, a_lrx, b_lrx;  // on the line clock
  phy_word_t line_ab[LINE_LAT], line_ba[LINE_LAT];
  logic a_paused, b_paused, a_pause, b_pause;
  logic [15:0] a_crc, b_crc, a_drops, b_drops, a_ovf, b_ovf;
  logic link_en;
  logic a_tx_hold;  // phase 3: A's tx_hold while its FIFO fills

  iclink_serwb_pump #(
      .W           (W),
      .DEPTH       (DEPTH),
      .TIMEOUT_CLKS(TIMEOUT)
  ) u_a (
      .clk          (clk),
      .arst_n       (arst_n),
      .tx_push      (a_push),
      .tx_data      (a_wdata),
      .tx_full      (a_full),
      .tx_used      (a_used),
      .tx_hold      (a_tx_hold),
      .rx_pop       (a_pop),
      .rx_data      (a_rdata),
      .rx_empty     (a_empty),
      .rx_avail     (a_avail),
      .tx_en        (link_en),
      .phy_tx       (a_tx),
      .rx_en        (link_en),
      .phy_rx       (a_rx),
      .remote_paused(a_paused),
      .pause        (a_pause),
      .crc_errors   (a_crc),
      .drops        (a_drops),
      .overflows    (a_ovf)
  );

  iclink_serwb_pump #(
      .W           (W),
      .DEPTH       (DEPTH),
      .TIMEOUT_CLKS(TIMEOUT)
  ) u_b (
      .clk          (clk),
      .arst_n       (arst_n),
      .tx_push      (b_push),
      .tx_data      (b_wdata),
      .tx_full      (b_full),
      .tx_used      (b_used),
      .tx_hold      (1'b0),
      .rx_pop       (b_pop),
      .rx_data      (b_rdata),
      .rx_empty     (b_empty),
      .rx_avail     (b_avail),
      .tx_en        (link_en),
      .phy_tx       (b_tx),
      .rx_en        (link_en),
      .phy_rx       (b_rx),
      .remote_paused(b_paused),
      .pause        (b_pause),
      .crc_errors   (b_crc),
      .drops        (b_drops),
      .overflows    (b_ovf)
  );

  // the line, both ways, LINE_LAT clocks
  always_ff @(posedge clk_line) begin : _line
    line_ab[0] <= a_ltx;
    line_ba[0] <= b_ltx;
    for (int i = 1; i < LINE_LAT; i++) begin
      line_ab[i] <= line_ab[i-1];
      line_ba[i] <= line_ba[i-1];
    end
  end : _line

  assign b_lrx = line_ab[LINE_LAT-1];
  assign a_lrx = line_ba[LINE_LAT-1];

  // between the pumps and the line: direct (W = 2), or gearboxes (W = 4)
  if (W == 2) begin : g_direct
    assign a_ltx = a_tx;
    assign b_ltx = b_tx;
    assign a_rx  = a_lrx;
    assign b_rx  = b_lrx;
  end : g_direct
  else begin : g_gearbox
    iclink_gearbox #(
        .IN_N (2),
        .OUT_N(1)
    ) u_a_tx (
        .w_clk   (clk),
        .w_arst_n(arst_n),
        .w_word  (a_tx),
        .r_clk   (clk_line),
        .r_arst_n(arst_n),
        .r_word  (a_ltx)
    );

    iclink_gearbox #(
        .IN_N (2),
        .OUT_N(1)
    ) u_b_tx (
        .w_clk   (clk),
        .w_arst_n(arst_n),
        .w_word  (b_tx),
        .r_clk   (clk_line),
        .r_arst_n(arst_n),
        .r_word  (b_ltx)
    );

    iclink_gearbox #(
        .IN_N (1),
        .OUT_N(2)
    ) u_a_rx (
        .w_clk   (clk_line),
        .w_arst_n(arst_n),
        .w_word  (a_lrx),
        .r_clk   (clk),
        .r_arst_n(arst_n),
        .r_word  (a_rx)
    );

    iclink_gearbox #(
        .IN_N (1),
        .OUT_N(2)
    ) u_b_rx (
        .w_clk   (clk_line),
        .w_arst_n(arst_n),
        .w_word  (b_lrx),
        .r_clk   (clk),
        .r_arst_n(arst_n),
        .r_word  (b_rx)
    );
  end : g_gearbox

  // the words: a known sequence per direction
  function automatic word_t pattern(input logic dir, input int n);
    return word_t'(n * 32'h9E37_79B1) ^ (dir ? 32'hB0B0_0000 : 32'hA0A0_0000);
  endfunction

  // phase control
  int   phase;  // 1 random both ways, 2 flood A -> B, 3 burst A -> B, 4 done
  logic b_reads;  // B's CPU reads (low: phase 2 stall)

  // CPU A: pushes A -> B; pops B -> A
  int a_sent, a_got, a_bad, b_sent, b_got, b_bad;
  int a_goal, b_goal;  // words to send

  always_ff @(posedge clk or negedge arst_n) begin : _cpu_a
    if (!arst_n) begin
      a_push  <= 1'b0;
      a_wdata <= '0;
      a_pop   <= 1'b0;
      a_sent  <= 0;
      a_got   <= 0;
      a_bad   <= 0;
    end
    else begin
      if (a_push && !a_full) begin
        a_sent <= a_sent + 1;
      end
      a_push  <= (a_sent + (a_push && !a_full) < a_goal) && (phase >= 2 || ($urandom % 3) != 0);
      a_wdata <= pattern(1'b0, a_sent + (a_push && !a_full));
      if (a_pop && !a_empty) begin
        if (a_rdata !== pattern(1'b1, a_got)) begin
          if (a_bad < 5) begin
            $display("ERROR: A got %h, word %0d should be %h", a_rdata, a_got, pattern(1'b1, a_got
                     ));
          end
          a_bad <= a_bad + 1;
        end
        a_got <= a_got + 1;
      end
      a_pop <= ($urandom % 4) != 0;
    end
  end : _cpu_a

  always_ff @(posedge clk or negedge arst_n) begin : _cpu_b
    if (!arst_n) begin
      b_push  <= 1'b0;
      b_wdata <= '0;
      b_pop   <= 1'b0;
      b_sent  <= 0;
      b_got   <= 0;
      b_bad   <= 0;
    end
    else begin
      if (b_push && !b_full) begin
        b_sent <= b_sent + 1;
      end
      b_push  <= (b_sent + (b_push && !b_full) < b_goal) && ($urandom % 3) != 0;
      b_wdata <= pattern(1'b1, b_sent + (b_push && !b_full));
      if (b_pop && !b_empty) begin
        if (b_rdata !== pattern(1'b0, b_got)) begin
          if (b_bad < 5) begin
            $display("ERROR: B got %h, word %0d should be %h", b_rdata, b_got, pattern(1'b0, b_got
                     ));
          end
          b_bad <= b_bad + 1;
        end
        b_got <= b_got + 1;
      end
      b_pop <= b_reads && ($urandom % 4) != 0;
    end
  end : _cpu_b

  // levels, every line clock in phase 2: time, B RX FIFO, A TX FIFO, flags
  int fd_lvl, b_rx_peak, a_tx_peak, a_full_clks;

  always_ff @(posedge clk or negedge arst_n) begin : _levels
    if (!arst_n) begin
      b_rx_peak <= 0;
      a_tx_peak <= 0;
    end
    else if (phase == 2) begin
      $fwrite(fd_lvl, "%0t,%0d,%0d,%0d,%0d,%0d\n", $time, u_b.rxf_used, u_a.tx_used, b_pause,
              a_paused, a_full);
      if (int'(u_b.rxf_used) > b_rx_peak) begin
        b_rx_peak <= int'(u_b.rxf_used);
      end
      if (int'(u_a.tx_used) > a_tx_peak) begin
        a_tx_peak <= int'(u_a.tx_used);
      end
    end
  end : _levels

  // burst meter: words out of B's depacketizer, from the first one of the burst
  int burst_words, burst_clks;

  always_ff @(posedge clk or negedge arst_n) begin : _burst
    if (!arst_n) begin
      burst_words <= 0;
      burst_clks  <= 0;
    end
    else if (phase == 3 && !a_tx_hold && burst_words < N_MEASURE) begin
      if (burst_words > 0 || u_b.dp_valid != '0) begin
        burst_words <= burst_words + $countones(u_b.dp_valid);
        burst_clks  <= burst_clks + 1;
      end
    end
  end : _burst

  initial begin : _run
    logic pass;
    phase   = 0;
    b_reads = 1'b1;
    link_en = 1'b0;
    a_goal  = 0;
    a_tx_hold = 1'b0;
    b_goal  = 0;
    fd_lvl  = $fopen("pump_levels.csv", "w");
    $fwrite(fd_lvl, "time_ps,b_rx_used,a_tx_used,b_pause,a_paused,a_tx_full\n");
    wait (arst_n);
    repeat (20) @(posedge clk_line);
    link_en = 1'b1;

    // 1. both ways
    phase   = 1;
    a_goal  = N_RANDOM;
    b_goal  = N_RANDOM;
    wait (a_got == N_RANDOM && b_got == N_RANDOM);
    $display("phase 1: %0d words each way, A bad %0d, B bad %0d at %0t", N_RANDOM, a_bad, b_bad,
             $time);

    // 2. B stops reading, A floods
    repeat (100) @(posedge clk_line);
    b_reads = 1'b0;
    phase   = 2;
    a_goal  = N_RANDOM + N_FLOOD;
    wait (a_full);
    repeat (2000) @(posedge clk_line);  // hold, past TIMEOUT: everything must stay put
    b_reads = 1'b1;
    wait (b_got == N_RANDOM + N_FLOOD);
    repeat (200) @(posedge clk_line);

    // 3. A's TX held, its FIFO filled, then let go
    a_tx_hold = 1'b1;
    phase     = 3;
    a_goal    = N_RANDOM + N_FLOOD + N_BURST;
    wait (a_sent == a_goal);
    repeat (50) @(posedge clk_line);
    a_tx_hold = 1'b0;
    wait (b_got == N_RANDOM + N_FLOOD + N_BURST);
    repeat (200) @(posedge clk_line);
    phase = 4;
    $fclose(fd_lvl);

    pass = a_bad == 0 && b_bad == 0 && a_got == N_RANDOM && b_got == N_RANDOM + N_FLOOD + N_BURST &&
        real'(burst_words) / real'(burst_clks) >= BURST_RATE &&
        a_drops == 0 && b_drops == 0 && a_ovf == 0 && b_ovf == 0 && a_crc == 0 && b_crc == 0 &&
        b_rx_peak <= DEPTH;
    $display("phase 2: B RX FIFO peak %0d of %0d (XOFF at %0d: +%0d words after XOFF)", b_rx_peak,
             DEPTH, XOFF_LEVEL, b_rx_peak - XOFF_LEVEL);
    $display("         A TX FIFO peak %0d (pushback on A's CPU); drops %0d/%0d, overflows %0d/%0d",
             a_tx_peak, a_drops, b_drops, a_ovf, b_ovf);
    $display("phase 3: burst of %0d words: %0d words in %0d clocks = %0.3f a clock (line: %0d)",
             N_BURST, burst_words, burst_clks, real'(burst_words) / real'(burst_clks), W);
    $display("TB_SERWB_PUMP: %s  A->B %0d words, B->A %0d words, in order, none lost",
             pass ? "PASS" : "FAIL", b_got, a_got);
    $finish;
  end : _run

  initial begin : _watchdog
    #20ms;
    $display("TB_SERWB_PUMP: FAIL  timeout: A sent %0d got %0d, B sent %0d got %0d", a_sent, a_got,
             b_sent, b_got);
    $finish;
  end : _watchdog

endmodule : tb_serwb_pump

// -----------------------------------------------------------------------------
// Project:     openCologne
// Description: NLnet-sponsored open-source design ware for GateMate
// -----------------------------------------------------------------------------
