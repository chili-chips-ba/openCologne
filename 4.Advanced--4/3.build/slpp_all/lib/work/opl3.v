`default_nettype none
module opl3 (
	clk,
	clk_host,
	clk_dac,
	ic_n,
	cs_n,
	rd_n,
	wr_n,
	address,
	din,
	dout,
	sample_valid,
	sample_l,
	sample_r,
	led,
	irq_n
);
	reg _sv2v_0;
	input wire clk;
	input wire clk_host;
	input wire clk_dac;
	input wire ic_n;
	input wire cs_n;
	input wire rd_n;
	input wire wr_n;
	input wire [1:0] address;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [7:0] din;
	output wire [7:0] dout;
	output wire sample_valid;
	localparam opl3_pkg_DAC_OUTPUT_WIDTH = 24;
	output wire signed [23:0] sample_l;
	output wire signed [23:0] sample_r;
	localparam opl3_pkg_NUM_LEDS = 4;
	output wire [3:0] led;
	output reg irq_n;
	wire reset;
	wire sample_clk_en;
	wire [17:0] opl3_reg_wr;
	wire [7:0] status;
	wire force_timer_overflow;
	reset_sync reset_sync(
		.clk(clk),
		.arst_n(ic_n),
		.reset(reset)
	);
	host_if host_if(.*);
	localparam signed [31:0] opl3_pkg_CLK_DIV_COUNT = 256;
	clk_div #(.CLK_DIV_COUNT(opl3_pkg_CLK_DIV_COUNT)) sample_clk_gen(
		.clk_en(sample_clk_en),
		.*
	);
	channels channels(.*);
	leds leds(.*);
	localparam opl3_pkg_INSTANTIATE_TIMERS = 0;
	generate
		if (opl3_pkg_INSTANTIATE_TIMERS) begin : genblk1
			timers timers(.*);
		end
		else begin : genblk1
			always @(*) begin
				if (_sv2v_0)
					;
				irq_n = 1;
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
