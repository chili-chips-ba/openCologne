-- #################################################################################################
-- #   << ws2812gol - aserial >>                                               					          #
-- #   The WS2812 is controlled via a single data line with an asynchronous serial protocol.       #
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
use ieee.math_real.all;
use ieee.numeric_std.all;

library work;
use work.const_image.all; 

entity aserial is
  port (
    reset    : in  std_ulogic;
    clk      : in  std_ulogic;
    wnr      : in  std_ulogic;
    data_in  : in  std_ulogic;
    data_out : out std_ulogic;
    run 	 : out std_ulogic 
    );
end aserial;

architecture behv of aserial is


  constant CLK_count_1250ns     : natural := ((((CLKFRQ*10)/800000)+5)/10)-2; 
  constant CLK_count_350nS      : natural := ((((CLKFRQ*10)/2857143)+5)/10)-1;
  constant CLK_count_900nS      : natural := ((((CLKFRQ*10)/1111111)+5)/10)-1;
  
  signal vcount                                        : natural range 0 to CLK_count_1250ns;
  signal vrun                                          : std_ulogic := '0';
  signal vCLK_count_curr                               : natural range 0 to CLK_count_1250ns;
  
begin

  clkcnt_p : process (clk) is
  begin  
    if rising_edge(clk) then
      if reset = '0' then
        vcount <= 0;
      else
        if vcount /= CLK_count_1250ns and vrun = '1' then
          vcount <= vcount + 1;
        else
          vcount <= 0;
        end if;
      end if;
    end if;
  end process clkcnt_p;

  minifsm_p : process (clk) is
  begin
    if rising_edge(clk) then           
      if reset = '0' then 
        vrun <= '0';
      else
        if vrun = '0' then         
          if wnr = '1' then
            vrun <= '1';
          end if;
        else                           
          if vcount = CLK_count_1250ns then 
            vrun <= '0';
          end if;
        end if;
      end if;
    end if;
  end process minifsm_p;

  vCLK_count_curr <= CLK_count_350nS when data_in = '0' else 
                     CLK_count_900nS;	
  data_out <= '1' when vrun = '1' and vcount <= vCLK_count_curr else '0';

  run <= vrun;

  
end behv;
