`default_nettype none
module mem_multi_bank (
	clk,
	wea,
	reb,
	banka,
	addra,
	bankb,
	addrb,
	dia,
	dob
);
	reg _sv2v_0;
	parameter DATA_WIDTH = 0;
	parameter DEPTH = 0;
	parameter OUTPUT_DELAY = 0;
	parameter DEFAULT_VALUE = 0;
	parameter NUM_BANKS = 0;
	parameter BANK_WIDTH = $clog2(NUM_BANKS);
	input wire clk;
	input wire wea;
	input wire reb;
	input wire [BANK_WIDTH - 1:0] banka;
	input wire [$clog2(DEPTH) - 1:0] addra;
	input wire [BANK_WIDTH - 1:0] bankb;
	input wire [$clog2(DEPTH) - 1:0] addrb;
	input wire [DATA_WIDTH - 1:0] dia;
	output reg [DATA_WIDTH - 1:0] dob;
	localparam PIPELINE_DELAY = 2;
	reg [NUM_BANKS - 1:0] wea_array;
	wire [DATA_WIDTH - 1:0] dob_array [0:NUM_BANKS - 1];
	wire [(2 * BANK_WIDTH) - 1:0] bankb_p;
	pipeline_sr #(
		.DATA_WIDTH(BANK_WIDTH),
		.ENDING_CYCLE(PIPELINE_DELAY)
	) bankb_sr(
		.clk(clk),
		.in(bankb),
		.out(bankb_p)
	);
	genvar _gv_i_1;
	generate
		for (_gv_i_1 = 0; _gv_i_1 < NUM_BANKS; _gv_i_1 = _gv_i_1 + 1) begin : bankgen
			localparam i = _gv_i_1;
			always @(*) begin
				if (_sv2v_0)
					;
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
					.addra(addra),
					.addrb(addrb),
					.dia(dia),
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
					.addra(addra),
					.addrb(addrb),
					.dia(dia),
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
