module uart (
	arst_n,
	clk,
	tick_1us,
	uart_rx,
	uart_tx,
	uart_tx_write,
	uart_tx_data,
	uart_rx_read,
	uart_tx_busy,
	uart_rx_arr
);
	input wire arst_n;
	input wire clk;
	input wire tick_1us;
	input wire uart_rx;
	output reg uart_tx;
	input wire uart_tx_write;
	input wire [7:0] uart_tx_data;
	input wire uart_rx_read;
	output wire uart_tx_busy;
	output reg [9:0] uart_rx_arr;
	localparam [3:0] RX_WAIT_D0 = 4'd13;
	localparam [3:0] RX_WAIT_D1 = 4'd7;
	localparam [3:0] RX_WAIT_D2 = 4'd8;
	localparam [3:0] RX_WAIT_D3 = 4'd8;
	localparam [3:0] RX_WAIT_D4 = 4'd7;
	localparam [3:0] RX_WAIT_D5 = 4'd8;
	localparam [3:0] RX_WAIT_D6 = 4'd8;
	localparam [3:0] RX_WAIT_D7 = 4'd7;
	localparam [3:0] RX_WAIT_STOP = 4'd8;
	reg [3:0] rx_state;
	reg [3:0] rx_cnt1us;
	wire rx_cnt1us_is0;
	assign rx_cnt1us_is0 = rx_cnt1us == {4 {1'sb0}};
	wire rx_nextbit;
	assign rx_nextbit = tick_1us & rx_cnt1us_is0;
	reg [7:0] rx_shift;
	always @(negedge arst_n or posedge clk)
		if (arst_n == 1'b0) begin
			rx_state <= 4'd14;
			rx_cnt1us <= 1'sb0;
			rx_shift <= 1'sb0;
			uart_rx_arr[9] <= 1'b0;
			uart_rx_arr[8] <= 1'b0;
			uart_rx_arr[7-:8] <= 1'sb0;
		end
		else begin
			if ((tick_1us == 1'b1) && (rx_state != 4'd14))
				rx_cnt1us <= rx_cnt1us - 4'd1;
			if (uart_rx_read == 1'b1) begin
				uart_rx_arr[9] <= 1'b0;
				uart_rx_arr[8] <= 1'b0;
			end
			(* full_case, parallel_case *)
			case (rx_state)
				4'd14: begin
					rx_cnt1us <= RX_WAIT_D0;
					if (uart_rx == 1'b0)
						rx_state <= 4'd0;
				end
				4'd8:
					if (rx_nextbit == 1'b1) begin
						if (uart_rx_arr[9] == 1'b1)
							uart_rx_arr[8] <= 1'b1;
						else begin
							uart_rx_arr[9] <= 1'b1;
							uart_rx_arr[7-:8] <= rx_shift;
						end
						rx_state <= 4'd14;
					end
				default:
					if (rx_nextbit == 1'b1) begin
						rx_shift <= {uart_rx, rx_shift[7:1]};
						(* full_case, parallel_case *)
						case (rx_state)
							4'd0: begin
								rx_cnt1us <= RX_WAIT_D1;
								rx_state <= 4'd1;
							end
							4'd1: begin
								rx_cnt1us <= RX_WAIT_D2;
								rx_state <= 4'd2;
							end
							4'd2: begin
								rx_cnt1us <= RX_WAIT_D3;
								rx_state <= 4'd3;
							end
							4'd3: begin
								rx_cnt1us <= RX_WAIT_D4;
								rx_state <= 4'd4;
							end
							4'd4: begin
								rx_cnt1us <= RX_WAIT_D5;
								rx_state <= 4'd5;
							end
							4'd5: begin
								rx_cnt1us <= RX_WAIT_D6;
								rx_state <= 4'd6;
							end
							4'd6: begin
								rx_cnt1us <= RX_WAIT_D7;
								rx_state <= 4'd7;
							end
							4'd7: begin
								rx_cnt1us <= RX_WAIT_STOP;
								rx_state <= 4'd8;
							end
							default:
								;
						endcase
					end
			endcase
		end
	localparam [3:0] TX_WAIT_START = 4'd9;
	localparam [3:0] TX_WAIT_D0 = 4'd7;
	localparam [3:0] TX_WAIT_D1 = 4'd8;
	localparam [3:0] TX_WAIT_D2 = 4'd8;
	localparam [3:0] TX_WAIT_D3 = 4'd7;
	localparam [3:0] TX_WAIT_D4 = 4'd8;
	localparam [3:0] TX_WAIT_D5 = 4'd8;
	localparam [3:0] TX_WAIT_D6 = 4'd7;
	localparam [3:0] TX_WAIT_D7 = 4'd8;
	localparam [3:0] TX_WAIT_STOP = 4'd8;
	reg [3:0] tx_state;
	reg [3:0] tx_cnt1us;
	wire tx_cnt1us_is0;
	assign tx_cnt1us_is0 = tx_cnt1us == {4 {1'sb0}};
	wire tx_nextbit;
	assign tx_nextbit = tick_1us & tx_cnt1us_is0;
	reg [7:0] tx_data;
	assign uart_tx_busy = tx_state != 4'd14;
	always @(negedge arst_n or posedge clk)
		if (arst_n == 1'b0) begin
			tx_state <= 4'd14;
			tx_cnt1us <= 1'sb0;
			tx_data <= 1'sb0;
			uart_tx <= 1'b1;
		end
		else begin
			if ((tick_1us == 1'b1) && (tx_state != 4'd14))
				tx_cnt1us <= tx_cnt1us - 4'd1;
			(* full_case, parallel_case *)
			case (tx_state)
				4'd14: begin
					uart_tx <= 1'b1;
					tx_cnt1us <= TX_WAIT_START;
					if (uart_tx_write == 1'b1) begin
						tx_data <= uart_tx_data;
						tx_state <= 4'd15;
					end
				end
				4'd15:
					if (tick_1us == 1'b1) begin
						uart_tx <= 1'b0;
						if (tx_cnt1us_is0 == 1'b1) begin
							uart_tx <= tx_data[0];
							tx_cnt1us <= TX_WAIT_D0;
							tx_state <= 4'd0;
						end
					end
				4'd0:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[1];
						tx_cnt1us <= TX_WAIT_D1;
						tx_state <= 4'd1;
					end
				4'd1:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[2];
						tx_cnt1us <= TX_WAIT_D2;
						tx_state <= 4'd2;
					end
				4'd2:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[3];
						tx_cnt1us <= TX_WAIT_D3;
						tx_state <= 4'd3;
					end
				4'd3:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[4];
						tx_cnt1us <= TX_WAIT_D4;
						tx_state <= 4'd4;
					end
				4'd4:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[5];
						tx_cnt1us <= TX_WAIT_D5;
						tx_state <= 4'd5;
					end
				4'd5:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[6];
						tx_cnt1us <= TX_WAIT_D6;
						tx_state <= 4'd6;
					end
				4'd6:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= tx_data[7];
						tx_cnt1us <= TX_WAIT_D7;
						tx_state <= 4'd7;
					end
				4'd7:
					if (tx_nextbit == 1'b1) begin
						uart_tx <= 1'b1;
						tx_cnt1us <= TX_WAIT_STOP;
						tx_state <= 4'd8;
					end
				4'd8:
					if (tx_nextbit == 1'b1)
						tx_state <= 4'd14;
				default:
					;
			endcase
		end
endmodule
