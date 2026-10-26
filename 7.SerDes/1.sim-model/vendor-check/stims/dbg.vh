// SPDX-FileCopyrightText: 2026 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause

    wait (rcp_n === 1'b1);
    repeat (30) begin @(posedge clk_rx); $display("%t w=%0d r=%0d occ=%0d wrst=%b rrst=%b rxo=%b samp=%b q=%0d", $time, dut.eb_w_cnt, dut.eb_r_cnt, dut.eb_r_occ, dut.eb_w_rst_n, dut.eb_r_rst_n, clk_rxo, dut.rx_sampler_run, dut.rx_word_q.size()); end
