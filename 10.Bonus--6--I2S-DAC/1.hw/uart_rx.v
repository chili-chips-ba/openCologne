//////////////////////////////////////////////////////////////////////
// File Downloaded from http://www.nandland.com
//////////////////////////////////////////////////////////////////////
// This file contains the UART Receiver. This receiver can handle
// 8 bits of serial data, one start bit, one stop bit, and no parity bit.
// When reception is complete, rx_dv will be driven high for one clock cycle.
//
// Set the parameter CLKS_PER_BIT as follows:
// CLKS_PER_BIT = (Frequency of osc_clk) / (Frequency of UART)
// Example: 10 MHz Clock, 115200 baud UART
// (10000000)/(115200) = 87

// Clock 133000000 - 115200 baud = 1155
// Clock 136000000 - 115200 baud = 1181
// Clock 120000000 - Clock div 8 (bit 2) - 115200 baud = 130
// Clock 80000000  - Clock div 8 (bit 2) - 115200 baud = 87

module uart_rx #(
    parameter CLKS_PER_BIT = 1181
) (
    input            osc_clk,
    input            rx_serial,
    output reg       rx_dv,
    output reg [7:0] rx_byte
);

  localparam IDLE         = 3'b000;
  localparam RX_START_BIT = 3'b001;
  localparam RX_DATA_BITS = 3'b010;
  localparam RX_STOP_BIT  = 3'b011;
  localparam CLEANUP      = 3'b100;

  reg        rx_data_r    = 1'b1;
  reg        rx_data      = 1'b1;

  reg [15:0] clock_count  = 0;
  reg [ 2:0] bit_index    = 0;  // 8 bits total
  reg [ 7:0] rx_temp_byte = 0;
  reg        rx_done      = 0;
  reg [ 2:0] state        = 0;
  reg        rx_done_last;

  // Edge detection for rx_dv signal
  always @(posedge osc_clk) begin
    rx_dv <= rx_done && !rx_done_last;
    rx_done_last <= rx_done;
  end

  // Double-register the incoming data to avoid metastability issues
  always @(posedge osc_clk) begin
    rx_data_r <= rx_serial;
    rx_data   <= rx_data_r;
  end

  // UART RX State Machine
  always @(posedge osc_clk) begin
    case (state)
      IDLE: begin
        rx_done      <= 1'b0;
        clock_count  <= 0;
        bit_index    <= 0;

        // Start bit detection
        if (rx_data == 1'b0) 
          state <= RX_START_BIT;
        else 
          state <= IDLE;
      end

      // Check the middle of the start bit to confirm it's low
      RX_START_BIT: begin
        if (clock_count == (CLKS_PER_BIT - 1) / 2) begin
          if (rx_data == 1'b0) begin
            clock_count <= 0;
            state       <= RX_DATA_BITS;
          end else 
            state <= IDLE;
        end else begin
          clock_count <= clock_count + 1'b1;
          state       <= RX_START_BIT;
        end
      end

      // Receive data bits
      RX_DATA_BITS: begin
        if (clock_count < CLKS_PER_BIT - 1) begin
          clock_count <= clock_count + 1'b1;
        end else begin
          clock_count           <= 0;
          rx_temp_byte[bit_index] <= rx_data;

          if (bit_index < 7) begin
            bit_index <= bit_index + 1'b1;
          end else begin
            bit_index <= 0;
            state     <= RX_STOP_BIT;
          end
        end
      end

      // Stop bit reception
      RX_STOP_BIT: begin
        if (clock_count < CLKS_PER_BIT - 1) begin
          clock_count <= clock_count + 1'b1;
        end else begin
          rx_done      <= 1'b1;
          rx_byte      <= rx_temp_byte;
          clock_count  <= 0;
          state        <= CLEANUP;
        end
      end

      // Cleanup state
      CLEANUP: begin
        state    <= IDLE;
        rx_done  <= 1'b0;
      end

      default: state <= IDLE;
    endcase
  end
endmodule  // uart_rx
