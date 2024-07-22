`default_nettype none
module psram (
	arst_n,
	i_clk,
	i_stb,
	i_we,
	i_addr,
	i_din,
	psram_busy,
	o_done,
	o_dout,
	o_psram_csn,
	o_psram_sclk,
	io_psram_data0,
	io_psram_data1,
	io_psram_data2,
	io_psram_data3,
	io_psram_data4,
	io_psram_data5,
	io_psram_data6,
	io_psram_data7
);
	input wire arst_n;
	input wire i_clk;
	input wire i_stb;
	input wire i_we;
	input wire [23:0] i_addr;
	input wire [15:0] i_din;
	output reg psram_busy;
	output reg o_done;
	output reg [15:0] o_dout;
	output reg o_psram_csn;
	output wire o_psram_sclk;
	inout wire io_psram_data0;
	inout wire io_psram_data1;
	inout wire io_psram_data2;
	inout wire io_psram_data3;
	inout wire io_psram_data4;
	inout wire io_psram_data5;
	inout wire io_psram_data6;
	inout wire io_psram_data7;
	reg [14:0] long_delay;
	reg [5:0] o_state;
	reg [34:0] states_hit;
	reg [3:0] short_delay;
	reg hold_clk_lo;
	reg [7:0] out_enable;
	reg [7:0] data_to_chip;
	assign o_psram_sclk = (hold_clk_lo ? 0 : i_clk);
	assign io_psram_data0 = (out_enable[0] ? data_to_chip[0] : 1'bz);
	assign io_psram_data1 = (out_enable[1] ? data_to_chip[1] : 1'bz);
	assign io_psram_data2 = (out_enable[2] ? data_to_chip[2] : 1'bz);
	assign io_psram_data3 = (out_enable[3] ? data_to_chip[3] : 1'bz);
	assign io_psram_data4 = (out_enable[4] ? data_to_chip[4] : 1'bz);
	assign io_psram_data5 = (out_enable[5] ? data_to_chip[5] : 1'bz);
	assign io_psram_data6 = (out_enable[6] ? data_to_chip[6] : 1'bz);
	assign io_psram_data7 = (out_enable[7] ? data_to_chip[7] : 1'bz);
	always @(negedge arst_n or posedge i_clk)
		if (arst_n == 1'b0) begin
			long_delay <= 0;
			o_state <= 6'd0;
			psram_busy <= 1;
			o_done <= 0;
			o_psram_csn <= 1;
			o_dout <= 0;
			hold_clk_lo <= 1;
			data_to_chip <= 8'd0;
			states_hit <= 0;
			out_enable <= 8'hff;
		end
		else begin
			states_hit[o_state] <= 1;
			case (o_state)
				6'd0:
					if (long_delay == 19999)
						o_state <= 6'd1;
					else
						long_delay <= long_delay + 1;
				6'd1: begin
					hold_clk_lo <= 0;
					o_state <= 6'd2;
				end
				6'd2: begin
					psram_busy <= 0;
					out_enable <= 8'h00;
					o_state <= 6'd3;
				end
				6'd3: begin
					o_psram_csn <= 0;
					out_enable[0] <= 1;
					out_enable[4] <= 1;
					data_to_chip <= 8'h00;
					o_state <= 6'd4;
				end
				6'd4: begin
					data_to_chip <= 8'h00;
					o_state <= 6'd5;
				end
				6'd5: begin
					data_to_chip <= 8'hff;
					o_state <= 6'd6;
				end
				6'd6: begin
					data_to_chip <= 8'hff;
					o_state <= 6'd7;
				end
				6'd7: begin
					data_to_chip <= 8'h00;
					o_state <= 6'd8;
				end
				6'd8: begin
					data_to_chip <= 8'hff;
					o_state <= 6'd9;
				end
				6'd9: begin
					data_to_chip <= 8'h00;
					o_state <= 6'd10;
				end
				6'd10: begin
					data_to_chip <= 8'hff;
					o_state <= 6'd11;
				end
				6'd11: begin
					o_psram_csn <= 1;
					out_enable <= 8'h00;
					psram_busy <= 0;
					o_done <= 1;
					o_state <= 6'd12;
				end
				6'd12:
					if (i_stb) begin
						if (i_we) begin
							data_to_chip[3:0] <= 4'h3;
							data_to_chip[7:4] <= 4'h3;
							o_state <= 6'd24;
						end
						else begin
							data_to_chip[3:0] <= 4'he;
							data_to_chip[7:4] <= 4'he;
							o_state <= 6'd13;
						end
						o_psram_csn <= 0;
						psram_busy <= 1;
						o_done <= 0;
						out_enable <= 8'hff;
					end
				6'd13: begin
					data_to_chip[3:0] <= 4'hb;
					data_to_chip[7:4] <= 4'hb;
					o_state <= 6'd14;
				end
				6'd14: begin
					data_to_chip[3:0] <= i_addr[23:20];
					data_to_chip[7:4] <= i_addr[23:20];
					o_state <= 6'd15;
				end
				6'd15: begin
					data_to_chip[3:0] <= i_addr[19:16];
					data_to_chip[7:4] <= i_addr[19:16];
					o_state <= 6'd16;
				end
				6'd16: begin
					data_to_chip[3:0] <= i_addr[15:12];
					data_to_chip[7:4] <= i_addr[15:12];
					o_state <= 6'd17;
				end
				6'd17: begin
					data_to_chip[3:0] <= i_addr[11:8];
					data_to_chip[7:4] <= i_addr[11:8];
					o_state <= 6'd18;
				end
				6'd18: begin
					data_to_chip[3:0] <= i_addr[7:4];
					data_to_chip[7:4] <= i_addr[7:4];
					o_state <= 6'd19;
				end
				6'd19: begin
					data_to_chip[3:0] <= i_addr[3:0];
					data_to_chip[7:4] <= i_addr[3:0];
					short_delay <= 0;
					o_state <= 6'd20;
				end
				6'd20: begin
					out_enable <= 8'h00;
					if (short_delay == 5)
						o_state <= 6'd21;
					else
						short_delay <= short_delay + 1;
				end
				6'd21: begin
					o_dout[15] <= io_psram_data7;
					o_dout[14] <= io_psram_data6;
					o_dout[13] <= io_psram_data5;
					o_dout[12] <= io_psram_data4;
					o_dout[11] <= io_psram_data3;
					o_dout[10] <= io_psram_data2;
					o_dout[9] <= io_psram_data1;
					o_dout[8] <= io_psram_data0;
					o_state <= 6'd22;
				end
				6'd22: begin
					o_dout[7] <= io_psram_data7;
					o_dout[6] <= io_psram_data6;
					o_dout[5] <= io_psram_data5;
					o_dout[4] <= io_psram_data4;
					o_dout[3] <= io_psram_data3;
					o_dout[2] <= io_psram_data2;
					o_dout[1] <= io_psram_data1;
					o_dout[0] <= io_psram_data0;
					o_state <= 6'd23;
				end
				6'd23: begin
					o_psram_csn <= 1;
					psram_busy <= 0;
					o_done <= 1;
					o_state <= 6'd12;
				end
				6'd24: begin
					data_to_chip[3:0] <= 4'h8;
					data_to_chip[7:4] <= 4'h8;
					o_state <= 6'd25;
				end
				6'd25: begin
					data_to_chip[3:0] <= i_addr[23:20];
					data_to_chip[7:4] <= i_addr[23:20];
					o_state <= 6'd26;
				end
				6'd26: begin
					data_to_chip[3:0] <= i_addr[19:16];
					data_to_chip[7:4] <= i_addr[19:16];
					o_state <= 6'd27;
				end
				6'd27: begin
					data_to_chip[3:0] <= i_addr[15:12];
					data_to_chip[7:4] <= i_addr[15:12];
					o_state <= 6'd28;
				end
				6'd28: begin
					data_to_chip[3:0] <= i_addr[11:8];
					data_to_chip[7:4] <= i_addr[11:8];
					o_state <= 6'd29;
				end
				6'd29: begin
					data_to_chip[3:0] <= i_addr[7:4];
					data_to_chip[7:4] <= i_addr[7:4];
					o_state <= 6'd30;
				end
				6'd30: begin
					data_to_chip[3:0] <= i_addr[3:0];
					data_to_chip[7:4] <= i_addr[3:0];
					o_state <= 6'd31;
				end
				6'd31: begin
					data_to_chip[7:0] <= i_din[15:8];
					o_state <= 6'd32;
				end
				6'd32: begin
					data_to_chip[7:0] <= i_din[7:0];
					o_state <= 6'd33;
				end
				6'd33: begin
					o_psram_csn <= 1;
					out_enable <= 8'h00;
					psram_busy <= 0;
					o_done <= 1;
					o_state <= 6'd12;
				end
				default: o_state <= 6'd12;
			endcase
		end
endmodule
