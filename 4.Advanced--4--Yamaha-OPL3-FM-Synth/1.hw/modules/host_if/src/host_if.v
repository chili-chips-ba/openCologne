`default_nettype none
module host_if (
	clk,
	reset,
	clk_host,
	ic_n,
	cs_n,
	rd_n,
	wr_n,
	address,
	din,
	dout,
	opl3_reg_wr,
	status,
	force_timer_overflow
);
	reg _sv2v_0;
	input wire clk;
	input wire reset;
	input wire clk_host;
	input wire ic_n;
	input wire cs_n;
	input wire rd_n;
	input wire wr_n;
	input wire [1:0] address;
	localparam opl3_pkg_REG_FILE_DATA_WIDTH = 8;
	input wire [7:0] din;
	output reg [7:0] dout = 0;
	output reg [17:0] opl3_reg_wr = 0;
	input wire [7:0] status;
	output reg force_timer_overflow;
	reg cs_p1_n = 1;
	reg wr_p1_n = 1;
	reg [1:0] address_p1 = 0;
	reg [7:0] din_p1 = 0;
	wire opl3_fifo_empty;
	wire [1:0] opl3_address;
	wire [7:0] opl3_data;
	reg wr_p1;
	reg wr_p2 = 0;
	wire [7:0] host_status;
	reg [7:0] host_status_p1 = 0;
	always @(posedge clk_host) begin
		cs_p1_n <= cs_n;
		wr_p1_n <= wr_n;
		address_p1 <= address;
		din_p1 <= din;
		wr_p2 <= wr_p1;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		wr_p1 = !cs_p1_n && !wr_p1_n;
	end
	afifo #(
		.LGFIFO(6),
		.WIDTH(10)
	) afifo(
		.i_wclk(clk_host),
		.i_wr_reset_n(ic_n),
		.i_wr(wr_p1 && !wr_p2),
		.i_wr_data({address_p1, din_p1}),
		.o_wr_full(),
		.i_rclk(clk),
		.i_rd_reset_n(!reset),
		.i_rd(!opl3_fifo_empty),
		.o_rd_data({opl3_address, opl3_data}),
		.o_rd_empty(opl3_fifo_empty)
	);
	always @(posedge clk) begin
		opl3_reg_wr[17] <= 0;
		if (!opl3_fifo_empty) begin
			if (!opl3_address[0]) begin
				opl3_reg_wr[16] <= opl3_address[1];
				opl3_reg_wr[15-:8] <= opl3_data;
			end
			else begin
				opl3_reg_wr[7-:opl3_pkg_REG_FILE_DATA_WIDTH] <= opl3_data;
				opl3_reg_wr[17] <= 1;
			end
		end
		if (reset)
			opl3_reg_wr <= 0;
	end
	synchronizer #(.DATA_WIDTH(opl3_pkg_REG_FILE_DATA_WIDTH)) dout_sync(
		.clk(clk_host),
		.in(status),
		.out(host_status)
	);
	always @(posedge clk_host) host_status_p1 <= host_status;
	always @(*) begin
		if (_sv2v_0)
			;
		dout = (address_p1 == 0 ? host_status_p1 : {8 {1'sb1}});
	end
	localparam opl3_pkg_INSTANTIATE_TIMERS = 0;
	generate
		if (opl3_pkg_INSTANTIATE_TIMERS) begin : genblk1
			wire [1:1] sv2v_tmp_trick_sw_detection_force_timer_overflow;
			always @(*) force_timer_overflow = sv2v_tmp_trick_sw_detection_force_timer_overflow;
			trick_sw_detection trick_sw_detection(
				.clk(clk),
				.clk_host(clk_host),
				.ic_n(ic_n),
				.cs_n(cs_n),
				.rd_n(rd_n),
				.wr_n(wr_n),
				.address(address),
				.din(din),
				.force_timer_overflow(sv2v_tmp_trick_sw_detection_force_timer_overflow)
			);
		end
		else begin : genblk1
			always @(*) begin
				if (_sv2v_0)
					;
				force_timer_overflow = 0;
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
