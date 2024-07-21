`default_nettype none
module mem_multi_bank_reset (
	clk,
	reset,
	reset_mem,
	wea,
	reb,
	banka,
	addra,
	bankb,
	addrb,
	dia,
	dob,
	reset_mem_done_pulse
);
	reg _sv2v_0;
	parameter DATA_WIDTH = 0;
	parameter DEPTH = 0;
	parameter OUTPUT_DELAY = 0;
	parameter DEFAULT_VALUE = 1'sb0;
	parameter NUM_BANKS = 0;
	parameter BANK_WIDTH = $clog2(NUM_BANKS);
	input wire clk;
	input wire reset;
	input wire reset_mem;
	input wire wea;
	input wire reb;
	input wire [BANK_WIDTH - 1:0] banka;
	input wire [$clog2(DEPTH) - 1:0] addra;
	input wire [BANK_WIDTH - 1:0] bankb;
	input wire [$clog2(DEPTH) - 1:0] addrb;
	input wire [DATA_WIDTH - 1:0] dia;
	output reg [DATA_WIDTH - 1:0] dob;
	output reg reset_mem_done_pulse;
	localparam PIPELINE_DELAY = 2;
	reg [NUM_BANKS - 1:0] wea_array;
	wire [DATA_WIDTH - 1:0] dob_array [0:NUM_BANKS - 1];
	wire [(PIPELINE_DELAY * BANK_WIDTH) + (BANK_WIDTH - 1):BANK_WIDTH] bankb_p;
	reg [31:0] state = 32'd0;
	reg [31:0] next_state;
	reg [(BANK_WIDTH + $clog2(DEPTH)) + 0:0] self = 0;
	reg [(BANK_WIDTH + $clog2(DEPTH)) + 0:0] next_self;
	pipeline_sr #(
		.DATA_WIDTH(BANK_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) bankb_sr(
		.clk(clk),
		.in(bankb),
		.out(bankb_p)
	);
	always @(posedge clk) begin
		state <= next_state;
		self <= next_self;
		if (reset) begin
			state <= 32'd0;
			self <= 0;
		end
	end
	always @(*) begin
		if (_sv2v_0)
			;
		next_state = state;
		next_self = self;
		(* full_case, parallel_case *)
		case (state)
			32'd0: begin
				if (reset_mem)
					next_state = 32'd1;
				next_self = 0;
			end
			32'd1:
				if (self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] == (DEPTH - 1)) begin
					next_self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] = 0;
					if (self[BANK_WIDTH + ($clog2(DEPTH) + 0)-:((BANK_WIDTH + ($clog2(DEPTH) + 0)) >= ($clog2(DEPTH) + 1) ? ((BANK_WIDTH + ($clog2(DEPTH) + 0)) - ($clog2(DEPTH) + 1)) + 1 : (($clog2(DEPTH) + 1) - (BANK_WIDTH + ($clog2(DEPTH) + 0))) + 1)] == (NUM_BANKS - 1)) begin
						next_state = 32'd0;
						next_self[0] = 1;
					end
					else
						next_self[BANK_WIDTH + ($clog2(DEPTH) + 0)-:((BANK_WIDTH + ($clog2(DEPTH) + 0)) >= ($clog2(DEPTH) + 1) ? ((BANK_WIDTH + ($clog2(DEPTH) + 0)) - ($clog2(DEPTH) + 1)) + 1 : (($clog2(DEPTH) + 1) - (BANK_WIDTH + ($clog2(DEPTH) + 0))) + 1)] = self[BANK_WIDTH + ($clog2(DEPTH) + 0)-:((BANK_WIDTH + ($clog2(DEPTH) + 0)) >= ($clog2(DEPTH) + 1) ? ((BANK_WIDTH + ($clog2(DEPTH) + 0)) - ($clog2(DEPTH) + 1)) + 1 : (($clog2(DEPTH) + 1) - (BANK_WIDTH + ($clog2(DEPTH) + 0))) + 1)] + 1;
				end
				else
					next_self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] = self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] + 1;
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		reset_mem_done_pulse = self[0];
	end
	genvar _gv_i_2;
	generate
		for (_gv_i_2 = 0; _gv_i_2 < NUM_BANKS; _gv_i_2 = _gv_i_2 + 1) begin : bankgen
			localparam i = _gv_i_2;
			always @(*) begin
				if (_sv2v_0)
					;
				if (state == 32'd1)
					wea_array[i] = self[BANK_WIDTH + ($clog2(DEPTH) + 0)-:((BANK_WIDTH + ($clog2(DEPTH) + 0)) >= ($clog2(DEPTH) + 1) ? ((BANK_WIDTH + ($clog2(DEPTH) + 0)) - ($clog2(DEPTH) + 1)) + 1 : (($clog2(DEPTH) + 1) - (BANK_WIDTH + ($clog2(DEPTH) + 0))) + 1)] == i;
				else
					wea_array[i] = wea && (banka == i);
			end
			if (OUTPUT_DELAY == 0) begin : genblk1
				mem_simple_dual_port_async_read #(
					.DATA_WIDTH(DATA_WIDTH),
					.DEPTH(DEPTH),
					.DEFAULT_VALUE(DEFAULT_VALUE)
				) mem_bank(
					.clka(clk),
					.wea(wea_array[i]),
					.addra((state == 32'd1 ? self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] : addra)),
					.addrb(addrb),
					.dia((state == 32'd1 ? DEFAULT_VALUE : dia)),
					.dob(dob_array[i])
				);
			end
			else begin : genblk1
				reg reb_mem;
				always @(*) begin
					if (_sv2v_0)
						;
					reb_mem = reb && (bankb == i);
				end
				mem_simple_dual_port #(
					.DATA_WIDTH(DATA_WIDTH),
					.DEPTH(DEPTH),
					.OUTPUT_DELAY(OUTPUT_DELAY),
					.DEFAULT_VALUE(DEFAULT_VALUE)
				) mem_bank(
					.clka(clk),
					.clkb(clk),
					.wea(wea_array[i]),
					.reb(reb_mem),
					.addra((state == 32'd1 ? self[$clog2(DEPTH) + 0-:(($clog2(DEPTH) + 0) >= 1 ? $clog2(DEPTH) + 0 : 2 - ($clog2(DEPTH) + 0))] : addra)),
					.addrb(addrb),
					.dia((state == 32'd1 ? DEFAULT_VALUE : dia)),
					.dob(dob_array[i])
				);
			end
		end
		if (OUTPUT_DELAY == 0) begin : genblk2
			always @(*) begin
				if (_sv2v_0)
					;
				dob = dob_array[bankb];
			end
		end
		else begin : genblk2
			always @(*) begin
				if (_sv2v_0)
					;
				dob = dob_array[bankb_p[OUTPUT_DELAY * BANK_WIDTH+:BANK_WIDTH]];
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
