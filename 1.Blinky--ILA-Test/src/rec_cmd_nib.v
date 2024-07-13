/*
#################################################################################################
#   << CologneChip GateMate ILA - receive cmd nibble >>                                         #
#   This module checks if a nibble matches a defined pattern, activates an output signal and    #
#   output the other 4 Bit from the byte once a match is found and disable output signal upon   #
#   specific input activation.                                                                  #
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

module rec_cmd_nib#(
    parameter ADDR = 4'b0000 // Bit Pattern
)
(
    input i_clk,
    input i_wr_en,
    input [3:0] i_nib,
    output reg o_hold
);

wire addr_sig;
assign addr_sig = (ADDR == i_nib);

always @(posedge i_clk) begin
    if (!i_wr_en) begin
        o_hold <= 0;
    end else begin
        o_hold <= addr_sig;
    end
end

endmodule