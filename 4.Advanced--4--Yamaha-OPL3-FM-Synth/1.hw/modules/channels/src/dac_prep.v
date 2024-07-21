`default_nettype none
module dac_prep (
	clk,
	clk_dac,
	channel_valid,
	channel_l,
	channel_r,
	sample_valid,
	sample_l,
	sample_r
);
	reg _sv2v_0;
	input wire clk;
	input wire clk_dac;
	input wire channel_valid;
	localparam opl3_pkg_SAMPLE_WIDTH = 16;
	input wire signed [15:0] channel_l;
	input wire signed [15:0] channel_r;
	output reg sample_valid;
	localparam opl3_pkg_DAC_OUTPUT_WIDTH = 24;
	output reg signed [23:0] sample_l;
	output reg signed [23:0] sample_r;
	reg sample_valid_opl3_p1 = 0;
	reg signed [23:0] sample_opl3_l_p1 = 0;
	reg signed [23:0] sample_opl3_r_p1 = 0;
	localparam opl3_pkg_DAC_LEFT_SHIFT = ($signed(6) < 0 ? 0 : 5);
	always @(posedge clk) begin
		sample_valid_opl3_p1 <= channel_valid;
		sample_opl3_l_p1 <= channel_l <<< opl3_pkg_DAC_LEFT_SHIFT;
		sample_opl3_r_p1 <= channel_r <<< opl3_pkg_DAC_LEFT_SHIFT;
	end
	localparam opl3_pkg_INSTANTIATE_SAMPLE_SYNC_TO_DAC_CLK = 0;
	generate
		if (opl3_pkg_INSTANTIATE_SAMPLE_SYNC_TO_DAC_CLK) begin : genblk1
			reg [2:0] sample_valid_opl3_pulse_extend;
			reg sample_valid_opl3_extended_pulse = 0;
			wire sample_valid_cpu_p0;
			reg sample_valid_cpu_p1 = 0;
			always @(posedge clk) begin
				sample_valid_opl3_pulse_extend <= sample_valid_opl3_pulse_extend << 1;
				sample_valid_opl3_pulse_extend[0] <= sample_valid_opl3_p1;
				sample_valid_opl3_extended_pulse <= sample_valid_opl3_pulse_extend != 0;
			end
			synchronizer channel_valid_sync(
				.clk(clk_dac),
				.in(sample_valid_opl3_extended_pulse),
				.out(sample_valid_cpu_p0)
			);
			always @(posedge clk_dac) begin
				sample_valid_cpu_p1 <= sample_valid_cpu_p0;
				if (sample_valid_cpu_p0) begin
					sample_l <= sample_opl3_l_p1;
					sample_r <= sample_opl3_r_p1;
				end
				sample_valid <= sample_valid_cpu_p0 && !sample_valid_cpu_p1;
			end
		end
		else begin : genblk1
			always @(*) begin
				if (_sv2v_0)
					;
				sample_valid = sample_valid_opl3_p1;
				sample_l = sample_opl3_l_p1;
				sample_r = sample_opl3_r_p1;
			end
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
`default_nettype wire
