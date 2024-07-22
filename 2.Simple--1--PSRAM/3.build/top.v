`default_nettype none
module top (
	clk,
	arst_n,
	tick_1us,
	uart_rx,
	uart_tx,
	sent,
	o_psram_csn,
	o_psram_sclk,
	io_psram_data0,
	io_psram_data1,
	io_psram_data2,
	io_psram_data3,
	io_psram_data4,
	io_psram_data5,
	io_psram_data6,
	io_psram_data7,
	led
);
	input wire clk;
	input wire arst_n;
	output wire tick_1us;
	input wire uart_rx;
	output wire uart_tx;
	output wire sent;
	output wire o_psram_csn;
	output wire o_psram_sclk;
	inout wire io_psram_data0;
	inout wire io_psram_data1;
	inout wire io_psram_data2;
	inout wire io_psram_data3;
	inout wire io_psram_data4;
	inout wire io_psram_data5;
	inout wire io_psram_data6;
	inout wire io_psram_data7;
	output reg led;
	wire clk_out;
	assign clk_out = clk;
	assign sent = uart_tx;
	reg [5:0] counter;
	reg tick_1us_reg;
	always @(posedge clk_out or negedge arst_n)
		if (arst_n == 1'b0)
			counter <= 1'sb0;
		else if (counter == 9) begin
			tick_1us_reg <= 1'b1;
			counter <= 0;
		end
		else begin
			tick_1us_reg <= 1'b0;
			counter <= counter + 1;
		end
	assign tick_1us = tick_1us_reg;
	wire [7:0] uart_tx_data;
	wire uart_tx_write;
	wire uart_rx_read;
	wire uart_tx_busy;
	wire uart_rx_flop;
	wire [9:0] uart_rx_arr;
	uart u_uart(
		.arst_n(arst_n),
		.clk(clk_out),
		.tick_1us(tick_1us),
		.uart_tx_write(uart_tx_write),
		.uart_tx_data(uart_tx_data),
		.uart_rx_read(uart_rx_read),
		.uart_rx(uart_rx),
		.uart_tx_busy(uart_tx_busy),
		.uart_tx(uart_tx),
		.uart_rx_arr(uart_rx_arr)
	);
	reg psram_stb;
	reg psram_we;
	wire psram_busy;
	wire [15:0] psram_rdat;
	reg [7:0] command_bytes [5:0];
	psram u_psram(
		.arst_n(arst_n),
		.i_clk(clk_out),
		.i_stb(psram_stb),
		.i_we(psram_we),
		.i_addr({command_bytes[3], command_bytes[2], command_bytes[1]}),
		.i_din({command_bytes[5], command_bytes[4]}),
		.psram_busy(psram_busy),
		.o_dout(psram_rdat),
		.o_psram_csn(o_psram_csn),
		.o_psram_sclk(o_psram_sclk),
		.io_psram_data0(io_psram_data0),
		.io_psram_data1(io_psram_data1),
		.io_psram_data2(io_psram_data2),
		.io_psram_data3(io_psram_data3),
		.io_psram_data4(io_psram_data4),
		.io_psram_data5(io_psram_data5),
		.io_psram_data6(io_psram_data6),
		.io_psram_data7(io_psram_data7)
	);
	reg [1:0] psram_state;
	reg [2:0] byte_count;
	always @(posedge clk_out or negedge arst_n)
		if (arst_n == 1'b0) begin
			psram_state <= 2'b00;
			byte_count <= 1'sb0;
		end
		else
			(* full_case, parallel_case *)
			case (psram_state)
				2'b00:
					if (uart_rx == 1'b0) begin
						psram_state <= 2'b01;
						byte_count <= 1'sb0;
					end
				2'b01: begin
					if (uart_rx_arr[9] == 1'b1) begin
						command_bytes[byte_count] <= uart_rx_arr[7-:8];
						byte_count <= byte_count + 3'b001;
					end
					if ((byte_count == 3'd6) | ((byte_count == 3'd4) & (command_bytes[0] == {8 {1'sb0}}))) begin
						psram_state <= 2'b10;
						psram_stb <= 1'b1;
						psram_we <= byte_count == 3'd6;
					end
				end
				2'b10: begin
					psram_stb <= 1'b0;
					psram_we <= 1'b0;
					psram_state <= 2'b11;
				end
				2'b11:
					if (psram_busy == 1'b0)
						psram_state <= 2'b00;
			endcase
	reg [15:0] uart_buffer;
	reg [1:0] uart_buffer_state;
	always @(posedge clk_out) begin : _uart_buffer
		if (arst_n == 1'b0) begin
			uart_buffer <= 1'sb0;
			uart_buffer_state <= 1'sb0;
		end
		else begin
			if (((psram_busy == 1'b0) & (psram_state == 2'b11)) & (command_bytes[0] == {8 {1'sb0}})) begin
				uart_buffer <= psram_rdat;
				uart_buffer_state <= 2'd2;
			end
			if (uart_tx_write)
				uart_buffer_state <= uart_buffer_state - 2'b01;
		end
	end
	assign uart_tx_data = (uart_buffer_state == 2'd2 ? uart_buffer[15:8] : uart_buffer[7:0]);
	assign uart_tx_write = (uart_tx_busy == 1'b0) & (uart_buffer_state != 2'b00);
	assign uart_rx_read = uart_rx_arr[9];
	reg [11:0] counter_10;
	always @(posedge clk_out or negedge arst_n)
		if (arst_n == 1'b0)
			counter_10 <= 1'sb0;
		else
			counter_10 <= counter_10 + 12'b000000000001;
	reg [27:0] u_counter;
	always @(posedge clk_out or negedge arst_n)
		if (arst_n == 1'b0)
			u_counter <= 1'sb0;
		else
			u_counter <= u_counter + 28'b0000000000000000000000000001;
	reg buffer [7:0];
	reg buffer_full;
	reg [2:0] in;
	reg uart_tx_prev;
	always @(posedge clk_out) begin
		if ((buffer_full == 1'b0) & (uart_tx_prev != uart_tx)) begin
			buffer[in] <= uart_tx;
			in <= in + 3'b001;
			if (in == {3 {1'sb1}}) begin
				buffer_full <= 1'b1;
				in <= 3'b000;
			end
		end
		else if (u_counter[27:25] == {3 {1'sb1}})
			buffer_full <= 1'b0;
		uart_tx_prev <= uart_tx;
	end
	reg counter_24_prev;
	always @(posedge clk_out) begin
		if (((u_counter[24] == 1'b1) & (counter_24_prev == 1'b0)) & (buffer_full == 1'b1))
			led <= buffer[u_counter[27:25]];
		counter_24_prev <= u_counter[24];
	end
endmodule
