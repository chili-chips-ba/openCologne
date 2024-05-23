////////////////////////////////////////////////////////////////////////////////
//
// Filename:	rtl/afifo.v
// {{{
// Project:	10Gb Ethernet switch
//
// Purpose:	A basic asynchronous FIFO.
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
// }}}
// Copyright (C) 2023-2024, Gisselquist Technology, LLC
// {{{
// This file is part of the ETH10G project.
//
// The ETH10G project contains free software and gateware, licensed under the
// terms of the 3rd version of the GNU General Public License as published by
// the Free Software Foundation.
//
// This project is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
// }}}
// License:	GPL, v3, as defined and found on www.gnu.org,
// {{{
//		http://www.gnu.org/licenses/gpl.html
//
////////////////////////////////////////////////////////////////////////////////
//
`timescale		1ns/1ps
`default_nettype	none
// }}}
module afifo #(
		// {{{
		// LGFIFO is the log based-two of the number of entries
		//	in the FIFO, log_2(fifo size)
		parameter	LGFIFO = 3,
		//
		// WIDTH is the number of data bits in each entry
		parameter	WIDTH  = 16,
		//
		// NFF is the number of flip flops used to cross clock domains.
		// 2 is a minimum.  Some applications appreciate the better
		parameter	NFF    = 2,
		//
		// This core can either write on the positive edge of the clock
		// or the negative edge.  Set WRITE_ON_POSEDGE (the default)
		// to write on the positive edge of the clock.
		parameter [0:0]	WRITE_ON_POSEDGE = 1'b1,
		//
		// Many  logic elements can read from memory asynchronously.
		// This burdens any following logic.  By setting
		// OPT_REGISTER_READS, we force all reads to be synchronous and
		// not burdened by any logic.  You can spare a clock of latency
		// by clearing this register.
		parameter [0:0]	OPT_REGISTER_READS = 1'b1










		// }}}
	) (
		// {{{
		//
		// The (incoming) write data interface
		input	wire			i_wclk,
		// Verilator lint_off SYNCASYNCNET
		input	wire			i_wr_reset_n,
		// Verilator lint_on  SYNCASYNCNET
		input	wire			i_wr,
		input	wire	[WIDTH-1:0]	i_wr_data,
		output	reg			o_wr_full,
		//
		// The (incoming) write data interface
		input	wire			i_rclk,
		// Verilator lint_off SYNCASYNCNET
		input	wire			i_rd_reset_n,
		// Verilator lint_on  SYNCASYNCNET
		input	wire			i_rd,
		output	reg	[WIDTH-1:0]	o_rd_data,
		output	reg			o_rd_empty



		// }}}
	);

	// Register/net declarations
	// {{{
	// MSB = most significant bit of the FIFO address vector.  It's
	// just short-hand for LGFIFO, and won't work any other way.
	localparam	MSB = LGFIFO;
	//
	reg	[WIDTH-1:0]		mem	[(1<<LGFIFO)-1:0];
	reg	[LGFIFO:0]		rd_addr, wr_addr,
					rd_wgray, wr_rgray;
	wire	[LGFIFO:0]		next_rd_addr, next_wr_addr;
	reg	[LGFIFO:0]		rgray, wgray;
	(* ASYNC_REG = "TRUE" *) reg	[(LGFIFO+1)*(NFF-1)-1:0]
					rgray_cross, wgray_cross;
	wire				wclk;
	reg	[WIDTH-1:0]		lcl_rd_data;
	reg				lcl_read, lcl_rd_empty;
	// }}}

	// wclk - Write clock generation
	// {{{
	generate if (WRITE_ON_POSEDGE)
	begin : GEN_POSEDGE_WRITES

		assign	wclk = i_wclk;

	end else begin : GEN_NEGEDGE_WRITES

		assign	wclk = !i_wclk;

	end endgenerate
	// }}}

	////////////////////////////////////////////////////////////////////////
	//
	// Write to and read from memory
	// {{{
	////////////////////////////////////////////////////////////////////////
	//
	//

	// wr_addr, wgray
	// {{{
	assign	next_wr_addr = wr_addr + 1;
	always @(posedge wclk or negedge i_wr_reset_n)
	if (!i_wr_reset_n)
	begin
		wr_addr <= 0;
		wgray   <= 0;
	end else if (i_wr && !o_wr_full)
	begin
		wr_addr <= next_wr_addr;
		wgray   <= next_wr_addr ^ (next_wr_addr >> 1);
	end
	// }}}

	// Write to memory
	// {{{
	always @(posedge wclk)
	if (i_wr && !o_wr_full)
		mem[wr_addr[LGFIFO-1:0]] <= i_wr_data;
	// }}}

	// rd_addr, rgray
	// {{{
	assign	next_rd_addr = rd_addr + 1;
	always @(posedge i_rclk or negedge i_rd_reset_n)
	if (!i_rd_reset_n)
	begin
		rd_addr <= 0;
		rgray   <= 0;
	end else if (lcl_read && !lcl_rd_empty)
	begin
		rd_addr <= next_rd_addr;
		rgray   <= next_rd_addr ^ (next_rd_addr >> 1);
	end
	// }}}

	// Read from memory
	// {{{
	always @(*)
		lcl_rd_data = mem[rd_addr[LGFIFO-1:0]];
	// }}}
	// }}}
	////////////////////////////////////////////////////////////////////////
	//
	// Cross clock domains
	// {{{
	////////////////////////////////////////////////////////////////////////
	//
	//

	// read pointer -> wr_rgray
	// {{{
	always @(posedge wclk or negedge i_wr_reset_n)
	if (!i_wr_reset_n)
		{ wr_rgray, rgray_cross } <= 0;
	else
		{ wr_rgray, rgray_cross } <= { rgray_cross, rgray };
	// }}}

	// write pointer -> rd_wgray
	// {{{
	always @(posedge i_rclk or negedge i_rd_reset_n)
	if (!i_rd_reset_n)
		{ rd_wgray, wgray_cross } <= 0;
	else
		{ rd_wgray, wgray_cross } <= { wgray_cross, wgray };
	// }}}

	// }}}
	////////////////////////////////////////////////////////////////////////
	//
	// Flag generation
	// {{{
	////////////////////////////////////////////////////////////////////////
	//
	//

	always @(*)
		o_wr_full = (wr_rgray == { ~wgray[MSB:MSB-1], wgray[MSB-2:0] });

	always @(*)
		lcl_rd_empty = (rd_wgray == rgray);

	// o_rd_empty, o_rd_data
	// {{{
	generate if (OPT_REGISTER_READS)
	begin : GEN_REGISTERED_READ
		// {{{
		always @(*)
			lcl_read = (o_rd_empty || i_rd);

		always @(posedge i_rclk or negedge i_rd_reset_n)
		if (!i_rd_reset_n)
			o_rd_empty <= 1'b1;
		else if (lcl_read)
			o_rd_empty <= lcl_rd_empty;

		always @(posedge i_rclk)
		if (lcl_read)
			o_rd_data <= lcl_rd_data;
		// }}}
	end else begin : GEN_COMBINATORIAL_FLAGS
		// {{{
		always @(*)
			lcl_read = i_rd;

		always @(*)
			o_rd_empty = lcl_rd_empty;

		always @(*)
			o_rd_data = lcl_rd_data;
		// }}}
	end endgenerate
	// }}}
	// }}}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Formal properties
// {{{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


































































































































































































































































































































































































































































































































































// }}}
endmodule
