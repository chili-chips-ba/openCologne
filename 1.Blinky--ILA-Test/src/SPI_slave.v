/*
#################################################################################################
#   << CologneChip GateMate ILA - SPI Slave >>                                                  #
#   No global mesh signal trace is wasted for the externally applied clock signal.              #
# ********************************************************************************************* #
#    Copyright (C) 2023 Cologne Chip AG <support@colognechip.com>                               #
#    Developed by Dave Fohrn                                                                    #
#                                                                                               #
#    This program is free software: you can redistribute it and/or modify                       #
#    it under the terms of the GNU General Public License as published by                       #
#    the Free Software Foundation, either version 3 of the License, or                          #
#    (at your option) any later version.                                                        #
#                                                                                               #
#    This program is distributed in the hope that it will be useful,                            #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#    GNU General Public License for more details.                                               #
#                                                                                               #
#    You should have received a copy of the GNU General Public License                          #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.                     #
#                                                                                               #
# ********************************************************************************************* #
#################################################################################################
*/

module spi_slave(
    (* clkbuf_inhibit *) input i_sclk,
    input i_ss,
    input i_mosi,
    input i_echo,
    input [3:0] i_nib_send,
    output o_miso,
    output reg o_rec_nib_ready,
    output reg [3:0] o_nib_rec
);


reg [3:0] tx_shift_reg;
reg [3:0] rx_shift_reg;
reg [1:0] bit_cnt;


always @(posedge i_sclk) begin
    if (i_ss) begin
        rx_shift_reg <= 0;
    end else begin    
        rx_shift_reg <= {rx_shift_reg[2:0], i_mosi};
    end
end

always @(posedge i_sclk) begin
    if (i_ss) begin
        bit_cnt <= 2'b11;
    end
    else begin
        bit_cnt <= bit_cnt + 1'b1;
    end
end 


always @(negedge i_sclk) 
begin
    if (i_ss) begin
        o_rec_nib_ready <= 0;
        o_nib_rec <= 0;
        tx_shift_reg <= 0;
    end
    else if (bit_cnt == 2'b11) begin
        o_rec_nib_ready <= 1;
        o_nib_rec <= rx_shift_reg;
        if (i_echo) begin
            tx_shift_reg <= rx_shift_reg;
        end else begin
            tx_shift_reg <= i_nib_send;
        end
    end
    else begin
        o_rec_nib_ready <= 0;
        tx_shift_reg <= {tx_shift_reg[2:0], 1'b0};
    end
end

assign o_miso = tx_shift_reg[3];

endmodule