`default_nettype none
module trick_sw_detection (
	clk,
	clk_host,
	ic_n,
	cs_n,
	rd_n,
	wr_n,
	address,
	din,
	force_timer_overflow
);
	reg _sv2v_0;
	input wire clk;
	input wire clk_host;
	input wire ic_n;
	input wire cs_n;
	input wire rd_n;
	input wire wr_n;
	input wire [1:0] address;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [7:0] din;
	output wire force_timer_overflow;
	localparam NUM_READS_TO_TRIGGER_OVERFLOW = 50;
	reg cs_p1_n = 1;
	reg wr_p1_n = 1;
	reg rd_p1_n = 1;
	reg [1:0] address_p1 = 0;
	reg [7:0] din_p1 = 0;
	reg wr_p1;
	reg wr_p2 = 0;
	reg [5:0] host_rd_counter = 0;
	reg [17:0] host_reg_wr;
	reg rd_p1;
	reg rd_p2 = 0;
	reg host_force_timer_overflow = 0;
	reg start_counter = 0;
	localparam opl3_pkg_REG_TIMER_WIDTH = 8;
	reg [7:0] timer1 = 0;
	always @(posedge clk_host) begin
		cs_p1_n <= cs_n;
		wr_p1_n <= wr_n;
		rd_p1_n <= rd_n;
		address_p1 <= address;
		din_p1 <= din;
		wr_p2 <= wr_p1;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		wr_p1 = !cs_p1_n && !wr_p1_n;
	end
	always @(posedge clk_host) begin
		host_reg_wr[17] <= 0;
		if (wr_p1 && !wr_p2) begin
			if (!address_p1[0]) begin
				host_reg_wr[16] <= address_p1[1];
				host_reg_wr[15-:8] <= din_p1;
			end
			else begin
				host_reg_wr[17] <= 1;
				host_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH] <= din_p1;
			end
		end
		if ((host_reg_wr[17] && (host_reg_wr[16] == 0)) && (host_reg_wr[15-:8] == 'h2))
			timer1 <= host_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH];
		if (!ic_n) begin
			host_reg_wr <= 0;
			timer1 <= 0;
		end
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rd_p1 = !cs_p1_n && !rd_p1_n;
	end
	always @(posedge clk_host) begin
		rd_p2 <= rd_p1;
		if ((((host_reg_wr[17] && (host_reg_wr[16] == 0)) && (host_reg_wr[15-:8] == 'h4)) && host_reg_wr[0]) && (timer1 == 'hff)) begin
			start_counter <= 1;
			host_rd_counter <= 0;
			host_force_timer_overflow <= 0;
		end
		if ((start_counter && rd_p1) && !rd_p2)
			host_rd_counter <= host_rd_counter + 1;
		if (host_rd_counter == NUM_READS_TO_TRIGGER_OVERFLOW)
			host_force_timer_overflow <= 1;
		if (!ic_n || (host_reg_wr[17] && !(((host_reg_wr[16] == 0) && (host_reg_wr[15-:8] == 'h4)) && host_reg_wr[0]))) begin
			start_counter <= 0;
			host_rd_counter <= 0;
			host_force_timer_overflow <= 0;
		end
	end
	synchronizer force_timer_overflow_sync(
		.clk(clk),
		.in(host_force_timer_overflow),
		.out(force_timer_overflow)
	);
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
