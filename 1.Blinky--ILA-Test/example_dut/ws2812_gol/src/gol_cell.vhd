-- #################################################################################################
-- #   << ws2812gol - gol >>                                               					              #
-- #   implements the typical behaviour of a Game of Life cell                                     #
-- # ********************************************************************************************* #
-- #    Copyright (C) 2023 Cologne Chip AG & TH Köln                             				  	      #
-- #    Developed by Dave Fohrn                                                                    #
-- #                                                                                               #
-- #    This program is free software: you can redistribute it and/or modify                       #
-- #    it under the terms of the GNU General Public License as published by                       #
-- #    the Free Software Foundation, either version 3 of the License, or                          #
-- #    (at your option) any later version.                                                        #
-- #                                                                                               #
-- #    This program is distributed in the hope that it will be useful,                            #
-- #    but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
-- #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
-- #    GNU General Public License for more details.                                               #
-- #                                                                                               #
-- #    You should have received a copy of the GNU General Public License                          #
-- #    along with this program.  If not, see <https://www.gnu.org/licenses/>.                     #
-- #                                                                                               #
-- # ********************************************************************************************* #
-- #################################################################################################


library ieee;
use ieee.std_logic_1164.all;

entity gol is
  port (
    N       : in std_ulogic_vector(0 to 7);
    reset   : in std_ulogic;
    clk     : in std_ulogic;
    set    : in std_ulogic;
    nextGen : in std_ulogic;
    CPUin   : in std_ulogic;
    L       : out std_ulogic);
end gol;

architecture behv of gol is
  signal s, r, tmp, logik_1, logik_2, logik_3, logik_4, logik_5, logik_6, logik_7: std_logic;
begin

  logik_1 <= (((N(0) and N(1)) or (N(2) and (N(0) xor N(1)))) xor ((N(3) and N(4)) or ((N(3) xor N(4)) and N(5))));
  logik_2 <= (((N(0) and N(1)) or (N(2) and (N(0) xor N(1)))) and ((N(3) and N(4)) or ((N(3) xor N(4)) and N(5))));
  logik_3 <= (logik_1 and (((N(5) xor (N(3) xor N(4))) and N(6)) or (((N(5) xor (N(3) xor N(4))) xor N(6)) and N(7))));
  logik_4 <= (logik_1 xor (((N(5) xor (N(3) xor N(4))) and N(6)) or (((N(5) xor (N(3) xor N(4))) xor N(6)) and N(7))));
  logik_5 <= (logik_2 or logik_3);
  logik_6 <= ((N(2) xor (N(0) xor N(1))) and (((N(5) xor (N(3) xor N(4))) xor N(6)) xor N(7)));
  logik_7 <= (logik_4 xor logik_6);

  s <= (not (logik_5 and (logik_4 and logik_6))) and (not (logik_5 xor (logik_4 and logik_6))) and logik_7 and ((N(2) xor (N(0) xor N(1))) xor (((N(5) xor (N(3) xor N(4))) xor N(6)) xor N(7)));

  r <= not logik_7 or (logik_7 and (logik_5 xor (logik_4 and logik_6)));
  
  
    gol_p : process (clk)
    begin
	if falling_edge(clk) then
		if (reset = '0') then 
			tmp <= '0';
        elsif (set = '1') then
            tmp <= CPUin;
        elsif (nextGen = '1') then
            if(s='1')then
                tmp <= '1';
            elsif(r='1')then
                tmp <= '0';
            end if; 
        end if;
    end if;
    end PROCESS;

    L <= tmp;
    
    
end behv;
  