`default_nettype none
module timer (
	clk,
	timer_reg,
	start_timer,
	timer_overflow_pulse
);
	reg _sv2v_0;
	parameter TIMER_TICK_INTERVAL = 0;
	input wire clk;
	localparam opl3_pkg_REG_TIMER_WIDTH = 8;
	input wire [7:0] timer_reg;
	input wire start_timer;
	output reg timer_overflow_pulse = 0;
	localparam opl3_pkg_CLK_FREQ = 12727000;
	localparam signed [31:0] TICK_TIMER_COUNT_VALUE = opl3_pkg_CLK_FREQ * TIMER_TICK_INTERVAL;
	reg [$clog2(TICK_TIMER_COUNT_VALUE) - 1:0] tick_counter = 0;
	reg tick_pulse = 0;
	reg [7:0] timer = 0;
	wire start_timer_set_pulse;
	edge_detector #(
		.EDGE_LEVEL(1),
		.CLK_DLY(0)
	) start_timer_edge_detect(
		.clk(clk),
		.clk_en(1'b1),
		.in(start_timer),
		.edge_detected(start_timer_set_pulse)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		tick_pulse = tick_counter == (TICK_TIMER_COUNT_VALUE - 1);
	end
	always @(posedge clk)
		if (start_timer) begin
			if (tick_pulse || start_timer_set_pulse)
				tick_counter <= 0;
			else
				tick_counter <= tick_counter + 1;
		end
	always @(posedge clk)
		if (start_timer_set_pulse)
			timer <= timer_reg;
		else if (tick_pulse) begin
			if (timer == 255)
				timer <= timer_reg;
			else
				timer <= timer + 1;
		end
	always @(posedge clk) timer_overflow_pulse <= (timer == 255) && tick_pulse;
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
