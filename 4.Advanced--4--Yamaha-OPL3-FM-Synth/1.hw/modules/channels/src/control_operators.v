`default_nettype none
module control_operators (
	clk,
	reset,
	sample_clk_en,
	opl3_reg_wr,
	connection_sel,
	is_new,
	ryt,
	operator_out,
	ops_done_pulse
);
	reg _sv2v_0;
	input wire clk;
	input wire reset;
	input wire sample_clk_en;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [17:0] opl3_reg_wr;
	localparam opl3_pkg_REG_CONNECTION_SEL_WIDTH = 6;
	input wire [5:0] connection_sel;
	input wire is_new;
	input wire ryt;
	localparam opl3_pkg_NUM_OPERATORS_PER_BANK = 18;
	localparam opl3_pkg_OP_OUT_WIDTH = 13;
	output reg [19:0] operator_out;
	output reg ops_done_pulse = 0;
	localparam PIPELINE_DELAY = 6;
	localparam MODULATION_DELAY = 1;
	localparam DELAY_COUNTER_WIDTH = 1;
	localparam opl3_pkg_NUM_BANKS = 2;
	localparam NUM_OPERATOR_UPDATE_STATES = 37;
	reg [0:0] delay_counter = 0;
	reg [5:0] state = 0;
	reg [5:0] next_state;
	localparam opl3_pkg_BANK_NUM_WIDTH = 1;
	reg [0:0] bank_num;
	reg [0:0] bank_num_p1 = 0;
	localparam opl3_pkg_OP_NUM_WIDTH = 5;
	reg [4:0] op_num;
	reg [4:0] op_num_p1 = 0;
	reg use_feedback_p1 = 0;
	reg signed [12:0] modulation_p1;
	wire signed [12:0] out_p6;
	reg signed [12:0] modulation_out_p1;
	reg op_sample_clk_en;
	wire [PIPELINE_DELAY:1] op_sample_clk_en_p;
	wire [6:1] bank_num_p;
	wire [34:5] op_num_p;
	reg [5:0] connection_sel_p1 = 0;
	reg ryt_p1 = 0;
	wire am;
	wire vib;
	wire egt;
	wire ksr;
	localparam opl3_pkg_REG_MULT_WIDTH = 4;
	wire [3:0] mult;
	localparam opl3_pkg_REG_KSL_WIDTH = 2;
	wire [1:0] ksl;
	localparam opl3_pkg_REG_TL_WIDTH = 6;
	wire [5:0] tl;
	localparam opl3_pkg_REG_ENV_WIDTH = 4;
	wire [3:0] ar;
	wire [3:0] dr;
	wire [3:0] sl;
	wire [3:0] rr;
	localparam opl3_pkg_REG_WS_WIDTH = 3;
	wire [2:0] ws;
	reg [$clog2('h16) - 1:0] operator_mem_rd_address;
	localparam opl3_pkg_REG_FNUM_WIDTH = 10;
	wire [9:0] fnum;
	localparam opl3_pkg_REG_BLOCK_WIDTH = 3;
	wire [2:0] block;
	wire kon;
	localparam opl3_pkg_REG_FB_WIDTH = 3;
	wire [2:0] fb_p1;
	wire cnt0_p1;
	wire cnt1_p1;
	reg [$clog2('h9) - 1:0] kon_block_fnum_channel_mem_rd_address;
	reg [$clog2('h9) - 1:0] fb_cnt0_channel_mem_rd_address;
	reg [$clog2('h9) - 1:0] cnt1_channel_mem_rd_address;
	reg nts = 0;
	reg dvb = 0;
	reg dam = 0;
	reg bd = 0;
	reg sd = 0;
	reg tom = 0;
	reg tc = 0;
	reg hh = 0;
	always @(posedge clk)
		if (opl3_reg_wr[17]) begin
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 8))
				nts <= opl3_reg_wr[6];
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 'hbd)) begin
				dam <= opl3_reg_wr[7];
				dvb <= opl3_reg_wr[6];
				bd <= opl3_reg_wr[4];
				sd <= opl3_reg_wr[3];
				tom <= opl3_reg_wr[2];
				tc <= opl3_reg_wr[1];
				hh <= opl3_reg_wr[0];
			end
		end
	always @(*) begin
		if (_sv2v_0)
			;
		if (op_num < 6)
			operator_mem_rd_address = op_num;
		else if (op_num < 12)
			operator_mem_rd_address = op_num + 2;
		else
			operator_mem_rd_address = op_num + 4;
	end
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h16),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) am_vib_egt_ksr_mult_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'h20)) && (opl3_reg_wr[15-:8] <= 'h35)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h16):8]),
		.bankb(bank_num),
		.addrb(operator_mem_rd_address),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob({am, vib, egt, ksr, mult})
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h16),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) ksl_tl_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'h40)) && (opl3_reg_wr[15-:8] <= 'h55)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h16):8]),
		.bankb(bank_num),
		.addrb(operator_mem_rd_address),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob({ksl, tl})
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h16),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) ar_dr_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'h60)) && (opl3_reg_wr[15-:8] <= 'h75)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h16):8]),
		.bankb(bank_num),
		.addrb(operator_mem_rd_address),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob({ar, dr})
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h16),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) sl_rr_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'h80)) && (opl3_reg_wr[15-:8] <= 'h95)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h16):8]),
		.bankb(bank_num),
		.addrb(operator_mem_rd_address),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob({sl, rr})
	);
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_WS_WIDTH),
		.DEPTH('h16),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) ws_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'he0)) && (opl3_reg_wr[15-:8] <= 'hf5)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h16):8]),
		.bankb(bank_num),
		.addrb(operator_mem_rd_address),
		.dia(opl3_reg_wr[2:0]),
		.dob(ws)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		cnt1_channel_mem_rd_address = 0;
		(* full_case, parallel_case *)
		case (op_num)
			0, 3: begin
				kon_block_fnum_channel_mem_rd_address = 0;
				fb_cnt0_channel_mem_rd_address = 0;
			end
			1, 4: begin
				kon_block_fnum_channel_mem_rd_address = 1;
				fb_cnt0_channel_mem_rd_address = 1;
			end
			2, 5: begin
				kon_block_fnum_channel_mem_rd_address = 2;
				fb_cnt0_channel_mem_rd_address = 2;
			end
			6, 9: begin
				cnt1_channel_mem_rd_address = 3;
				if (bank_num == 0) begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[0] ? 0 : 3);
					fb_cnt0_channel_mem_rd_address = (connection_sel[0] ? 0 : 3);
				end
				else begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[3] ? 0 : 3);
					fb_cnt0_channel_mem_rd_address = (connection_sel[3] ? 0 : 3);
				end
			end
			7, 10: begin
				cnt1_channel_mem_rd_address = 4;
				if (bank_num == 0) begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[1] ? 1 : 4);
					fb_cnt0_channel_mem_rd_address = (connection_sel[1] ? 1 : 4);
				end
				else begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[4] ? 1 : 4);
					fb_cnt0_channel_mem_rd_address = (connection_sel[4] ? 1 : 4);
					cnt1_channel_mem_rd_address = 4;
				end
			end
			8, 11: begin
				cnt1_channel_mem_rd_address = 5;
				if (bank_num == 0) begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[2] ? 2 : 5);
					fb_cnt0_channel_mem_rd_address = (connection_sel[2] ? 2 : 5);
				end
				else begin
					kon_block_fnum_channel_mem_rd_address = (connection_sel[5] ? 2 : 5);
					fb_cnt0_channel_mem_rd_address = (connection_sel[2] ? 2 : 5);
				end
			end
			12, 15: begin
				kon_block_fnum_channel_mem_rd_address = 6;
				fb_cnt0_channel_mem_rd_address = 6;
			end
			13, 16: begin
				kon_block_fnum_channel_mem_rd_address = 7;
				fb_cnt0_channel_mem_rd_address = 7;
			end
			14, 17: begin
				kon_block_fnum_channel_mem_rd_address = 8;
				fb_cnt0_channel_mem_rd_address = 8;
			end
		endcase
	end
	mem_multi_bank #(
		.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH),
		.DEPTH('h9),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) fnum_low_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'ha0)) && (opl3_reg_wr[15-:8] <= 'ha8)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h9):8]),
		.bankb(bank_num),
		.addrb(kon_block_fnum_channel_mem_rd_address),
		.dia(opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH]),
		.dob(fnum[7:0])
	);
	localparam kon_block_fnum_high_mem_width = 6;
	mem_multi_bank #(
		.DATA_WIDTH(kon_block_fnum_high_mem_width),
		.DEPTH('h9),
		.OUTPUT_DELAY(0),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) kon_block_fnum_high_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'hb0)) && (opl3_reg_wr[15-:8] <= 'hb8)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h9):8]),
		.bankb(bank_num),
		.addrb(kon_block_fnum_channel_mem_rd_address),
		.dia(opl3_reg_wr[5:0]),
		.dob({kon, block, fnum[9:8]})
	);
	localparam fb_cnt_mem_width = 4;
	mem_multi_bank #(
		.DATA_WIDTH(fb_cnt_mem_width),
		.DEPTH('h9),
		.OUTPUT_DELAY(1),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) fb_cnt0_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'hc0)) && (opl3_reg_wr[15-:8] <= 'hc8)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h9):8]),
		.bankb(bank_num),
		.addrb(fb_cnt0_channel_mem_rd_address),
		.dia(opl3_reg_wr[3:0]),
		.dob({fb_p1, cnt0_p1})
	);
	localparam cnt_mem_width = 1;
	mem_multi_bank #(
		.DATA_WIDTH(cnt_mem_width),
		.DEPTH('h9),
		.OUTPUT_DELAY(1),
		.DEFAULT_VALUE(0),
		.NUM_BANKS(opl3_pkg_NUM_BANKS)
	) fb_cnt1_mem(
		.clk(clk),
		.wea((opl3_reg_wr[17] && (opl3_reg_wr[15-:8] >= 'hc0)) && (opl3_reg_wr[15-:8] <= 'hc8)),
		.reb(op_sample_clk_en),
		.banka(opl3_reg_wr[16]),
		.addra(opl3_reg_wr[7 + $clog2('h9):8]),
		.bankb(bank_num),
		.addrb(cnt1_channel_mem_rd_address),
		.dia(opl3_reg_wr[0:0]),
		.dob(cnt1_p1)
	);
	always @(posedge clk)
		(* full_case, parallel_case *)
		case (op_num)
			0, 1, 2, 12: use_feedback_p1 <= 1;
			3, 4, 5, 9, 10, 11, 15, 16, 17: use_feedback_p1 <= 0;
			6:
				if (bank_num == 0)
					use_feedback_p1 <= !connection_sel[0];
				else
					use_feedback_p1 <= !connection_sel[3];
			7:
				if (bank_num == 0)
					use_feedback_p1 <= !connection_sel[1];
				else
					use_feedback_p1 <= !connection_sel[4];
			8:
				if (bank_num == 0)
					use_feedback_p1 <= !connection_sel[2];
				else
					use_feedback_p1 <= !connection_sel[5];
			13, 14: use_feedback_p1 <= !((bank_num == 0) && ryt);
		endcase
	always @(posedge clk) begin
		bank_num_p1 <= bank_num;
		connection_sel_p1 <= connection_sel;
		ryt_p1 <= ryt;
		op_num_p1 <= op_num;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (op_num_p1)
			0, 1, 2, 12, 13, 14: modulation_p1 = 0;
			3, 4, 5, 15: modulation_p1 = (cnt0_p1 ? 0 : modulation_out_p1);
			6:
				if (((bank_num_p1 == 0) && connection_sel_p1[0]) || ((bank_num_p1 == 1) && connection_sel_p1[3]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b10, 'b11: modulation_p1 = modulation_out_p1;
						'b1: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = 0;
			7:
				if (((bank_num_p1 == 0) && connection_sel_p1[1]) || ((bank_num_p1 == 1) && connection_sel_p1[4]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b10, 'b11: modulation_p1 = modulation_out_p1;
						'b1: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = 0;
			8:
				if (((bank_num_p1 == 0) && connection_sel_p1[2]) || ((bank_num_p1 == 1) && connection_sel_p1[5]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b10, 'b11: modulation_p1 = modulation_out_p1;
						'b1: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = 0;
			9:
				if (((bank_num_p1 == 0) && connection_sel_p1[0]) || ((bank_num_p1 == 1) && connection_sel_p1[3]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b1, 'b10: modulation_p1 = modulation_out_p1;
						'b11: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = (cnt0_p1 ? 0 : modulation_out_p1);
			10:
				if (((bank_num_p1 == 0) && connection_sel_p1[1]) || ((bank_num_p1 == 1) && connection_sel_p1[4]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b1, 'b10: modulation_p1 = modulation_out_p1;
						'b11: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = (cnt0_p1 ? 0 : modulation_out_p1);
			11:
				if (((bank_num_p1 == 0) && connection_sel_p1[2]) || ((bank_num_p1 == 1) && connection_sel_p1[5]))
					(* full_case, parallel_case *)
					case ({cnt0_p1, cnt1_p1})
						'b0, 'b1, 'b10: modulation_p1 = modulation_out_p1;
						'b11: modulation_p1 = 0;
					endcase
				else
					modulation_p1 = (cnt0_p1 ? 0 : modulation_out_p1);
			16, 17: modulation_p1 = (cnt0_p1 || (ryt_p1 && (bank_num_p1 == 0)) ? 0 : modulation_out_p1);
		endcase
	end
	always @(posedge clk) state <= next_state;
	always @(*) begin
		if (_sv2v_0)
			;
		if (state == 0)
			next_state = sample_clk_en;
		else if (delay_counter == MODULATION_DELAY) begin
			if (state == 36)
				next_state = 0;
			else
				next_state = state + 1;
		end
		else
			next_state = state;
	end
	always @(posedge clk)
		if (next_state != state)
			delay_counter <= 0;
		else if (delay_counter == MODULATION_DELAY)
			delay_counter <= 0;
		else
			delay_counter <= delay_counter + 1;
	always @(*) begin
		if (_sv2v_0)
			;
		bank_num = state > opl3_pkg_NUM_OPERATORS_PER_BANK;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		if (state == 0)
			op_num = 0;
		else if (state > opl3_pkg_NUM_OPERATORS_PER_BANK)
			op_num = (state - opl3_pkg_NUM_OPERATORS_PER_BANK) - 1;
		else
			op_num = state - 1;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		op_sample_clk_en = (state != 0) && (delay_counter == 0);
	end
	operator operator(
		.sample_clk_en(op_sample_clk_en),
		.clk(clk),
		.reset(reset),
		.is_new(is_new),
		.bank_num(bank_num),
		.op_num(op_num),
		.fnum(fnum),
		.mult(mult),
		.block(block),
		.ws(ws),
		.vib(vib),
		.dvb(dvb),
		.kon(kon),
		.ar(ar),
		.dr(dr),
		.sl(sl),
		.rr(rr),
		.tl(tl),
		.ksr(ksr),
		.ksl(ksl),
		.egt(egt),
		.am(am),
		.dam(dam),
		.nts(nts),
		.bd(bd),
		.sd(sd),
		.tom(tom),
		.tc(tc),
		.hh(hh),
		.ryt(ryt),
		.use_feedback_p1(use_feedback_p1),
		.fb_p1(fb_p1),
		.modulation_p1(modulation_p1),
		.out_p6(out_p6)
	);
	pipeline_sr #(.ENDING_CYCLE(PIPELINE_DELAY)) sample_clk_en_sr(
		.clk(clk),
		.in(op_sample_clk_en),
		.out(op_sample_clk_en_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_BANK_NUM_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) bank_num_sr(
		.clk(clk),
		.in(bank_num),
		.out(bank_num_p)
	);
	pipeline_sr #(
		.DATA_WIDTH(opl3_pkg_OP_NUM_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) op_num_sr(
		.clk(clk),
		.in(op_num),
		.out(op_num_p)
	);
	always @(posedge clk) modulation_out_p1 <= out_p6;
	always @(*) begin
		if (_sv2v_0)
			;
		operator_out[19] = op_sample_clk_en_p[6];
		operator_out[18] = bank_num_p[6+:1];
		operator_out[17-:5] = op_num_p[30+:5];
		operator_out[12-:opl3_pkg_OP_OUT_WIDTH] = out_p6;
	end
	always @(posedge clk) ops_done_pulse <= (operator_out[19] && (operator_out[18] == 1)) && (operator_out[17-:5] == 17);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
