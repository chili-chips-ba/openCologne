/*
#################################################################################################
# << CologneChip GateMate ILA - sample to byte >>                                               #
# This module is required to split a sample of any size into eight-bit packets                  #
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


module smp_to_byte#(
    parameter sample_width = 24
)(
    input i_clk_ILA,
    input i_read_active,
    input [(sample_width-1):0] i_ram_sample,
    input i_slave_end_byte_post_edge,
    output reg [3:0] o_send_nib,
    output reg o_rd
);


parameter packages_per_sample = ((sample_width-1)/4)+1;
parameter shift_cnt_width = $clog2(packages_per_sample);
parameter zero_padding_bits = (packages_per_sample*4) - sample_width;
reg [((packages_per_sample*4)-1):0] shift_reg;

wire init_reg;

reg [(shift_cnt_width-1):0] shift_counter;
reg rd;
// The data from the BRAM needs to be shifted
always @(posedge i_clk_ILA) begin
    if (init_reg | (!i_read_active)) begin               
        shift_reg <= {{zero_padding_bits{1'b0}}, i_ram_sample};
        rd <= 0;
    end
    else if (i_slave_end_byte_post_edge) begin
        shift_reg <= {4'b0000, shift_reg[((packages_per_sample*4)-1):4]};
    end
    else begin
        rd <= 1;
    end
end
reg signal_old;
always @(posedge i_clk_ILA) begin
    if (!i_read_active) begin
        signal_old <= rd;
        o_rd <= 0;
    end else begin
        signal_old <= rd;
        o_rd <= rd & (~signal_old);
    end
end


// shift counter 
always @(posedge i_clk_ILA) begin
    if (!i_read_active) begin
        shift_counter <= 0;
    end
    else if (i_slave_end_byte_post_edge) begin
        if (init_reg) begin
            shift_counter <= 0;
        end
        else begin
            shift_counter <= shift_counter + 1;
        end
    end
end

assign init_reg = (shift_counter == (packages_per_sample-1) & i_slave_end_byte_post_edge);
//always @(posedge i_clk_ILA) begin
//    if (!i_read_active) begin
//        rd <= 0;
//    end else begin
//        rd <= init_reg & i_read_active;
//    end
//end
//assign o_rd = rd;


always @(posedge i_clk_ILA) begin
    if (!i_read_active) begin
        o_send_nib <= 0;
    end else begin
        o_send_nib <= shift_reg[3:0];
    end
end


endmodule