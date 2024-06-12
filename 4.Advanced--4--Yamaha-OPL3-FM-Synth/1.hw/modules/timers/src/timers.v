`default_nettype none
module timers (
	clk,
	reset,
	opl3_reg_wr,
	irq_n,
	status,
	force_timer_overflow
);
	reg _sv2v_0;
	input wire clk;
	input wire reset;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [17:0] opl3_reg_wr;
	output reg irq_n = 0;
	output reg [7:0] status;
	input wire force_timer_overflow;
	localparam opl3_pkg_REG_TIMER_WIDTH = 8;
	reg [7:0] timer1 = 0;
	reg [7:0] timer2 = 0;
	reg irq_rst = 0;
	reg mt1 = 0;
	reg mt2 = 0;
	reg st1 = 0;
	reg st2 = 0;
	wire timer1_overflow_pulse;
	wire timer2_overflow_pulse;
	reg ft1 = 0;
	reg ft2 = 0;
	reg irq;
	always @(posedge clk) begin
		if (opl3_reg_wr[17]) begin
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 2))
				timer1 <= opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH];
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 3))
				timer2 <= opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH];
			if ((opl3_reg_wr[16] == 0) && (opl3_reg_wr[15-:8] == 4)) begin
				irq_rst <= opl3_reg_wr[7];
				mt1 <= opl3_reg_wr[6];
				mt2 <= opl3_reg_wr[5];
				st2 <= opl3_reg_wr[1];
				st1 <= opl3_reg_wr[0];
			end
		end
		if (reset) begin
			timer1 <= 0;
			timer2 <= 0;
			irq_rst <= 0;
			mt1 <= 0;
			mt2 <= 0;
			st2 <= 0;
			st1 <= 0;
		end
	end
	localparam opl3_pkg_CLK_FREQ = 12727000;
	localparam signed [31:0] opl3_pkg_TIMER1_TICK_INTERVAL = opl3_pkg_CLK_FREQ * 80e-6;
	timer #(.TIMER_TICK_INTERVAL(opl3_pkg_TIMER1_TICK_INTERVAL)) timer1_inst(
		.clk(clk),
		.timer_reg(timer1),
		.start_timer(st1),
		.timer_overflow_pulse(timer1_overflow_pulse)
	);
	localparam signed [31:0] opl3_pkg_TIMER2_TICK_INTERVAL = opl3_pkg_CLK_FREQ * 320e-6;
	timer #(.TIMER_TICK_INTERVAL(opl3_pkg_TIMER2_TICK_INTERVAL)) timer2_inst(
		.clk(clk),
		.timer_reg(timer2),
		.start_timer(st2),
		.timer_overflow_pulse(timer2_overflow_pulse)
	);
	always @(posedge clk) begin
		if ((timer1_overflow_pulse || force_timer_overflow) && !mt1)
			ft1 <= 1;
		if (timer2_overflow_pulse && !mt2)
			ft2 <= 1;
		if (reset || irq_rst) begin
			ft1 <= 0;
			ft2 <= 0;
		end
	end
	always @(*) begin
		if (_sv2v_0)
			;
		irq = ft1 || ft2;
	end
	always @(posedge clk) irq_n <= !irq;
	always @(*) begin
		if (_sv2v_0)
			;
		status = 0;
		status[7] = irq;
		status[6] = ft1;
		status[5] = ft2;
	end
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
