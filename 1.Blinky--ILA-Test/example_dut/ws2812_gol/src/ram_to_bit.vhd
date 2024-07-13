-- #################################################################################################
-- #   << ws2812gol - ram_to_bit >>                                               					#
-- #   Reads 8 bytes from the Ram and passes one bit to the Aseriel controller.                    #
-- # ********************************************************************************************* #
-- #    Copyright (C) 2023 Cologne Chip AG & TH Köln                             					#
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
use ieee.numeric_std.all;

entity ram_to_bit is
  port (
    reset            : in  std_ulogic;
    clk              : in  std_ulogic;
    start            : in  std_ulogic;  
    raddr			 : out std_ulogic_vector(7 downto 0);
    dataRead		 : in  std_ulogic_vector(7 downto 0);	
    ws2812_out       : out std_ulogic;  
    working          : out std_logic  
    );
end ram_to_bit;

architecture behv of ram_to_bit is
	signal aserial_wnr 			: std_ulogic := '0';
	signal data_in_s, aserial_run 	: std_ulogic;
	signal dataPuffer			: std_ulogic_vector(7 downto 0) := "00000000";
	
	TYPE STATE_TYPE IS (state_wait_for_signal, state_sfr_load, state_acnt_inc, state_aserial_run, state_sfr_shift);
   	SIGNAL state   : STATE_TYPE := state_wait_for_signal;
	
	signal ws2812_ram_addr_rd			: std_ulogic_vector(7 downto 0) := "00000000";
	signal acnt_rst 		: std_ulogic;
	signal acnt_inc 		: std_ulogic;
	
	
	signal shift_rgb_byte	: std_ulogic_vector(7 downto 0);
	signal sfr_load		: std_ulogic;
	signal sfr_done		: std_ulogic;
	signal acnt_eq191		: std_ulogic;
	signal sfr_shift : std_ulogic := '0';


	begin
		aserial : entity work.aserial
			port map(
				reset 		=> reset,
				clk   		=> clk,
				wnr   		=> aserial_wnr,
				data_in     => data_in_s,
				data_out    => ws2812_out,
				run         => aserial_run);
		
	addrcnt : process(clk) is
		variable cnt : integer range 0 to 192;
		begin
		if rising_edge(clk) then
			if (reset = '0' or acnt_rst = '1') then
				cnt := 0;
				acnt_eq191 <= '0';
			else
				if cnt = 192 then
					acnt_eq191 <= '1';
				elsif acnt_inc = '1' then
					cnt := cnt +1;
				
				end if;
			end if;
		end if;
			ws2812_ram_addr_rd <= std_ulogic_vector(to_unsigned(cnt, 8));
	end process;
	
	raddr <= ws2812_ram_addr_rd;

	dataPuffer <= dataRead;
	
	shiftregister : process(clk) is
		begin
		if rising_edge(clk) then
			if (reset = '0') then
				shift_rgb_byte <= (others => '0');
			else
				if sfr_load = '1' then
					shift_rgb_byte <= dataPuffer;
				elsif sfr_shift = '1' then
					shift_rgb_byte <= shift_rgb_byte(6 downto 0) & '0';
				end if;
			end if;
		end if;
	end process;

	shift_cnt : process(clk) is
		variable cnt_shift : integer range 0 to 7;
	begin
	if rising_edge(clk) then
		if (reset = '0') then
			sfr_done <= '0';
			cnt_shift := 0;
		else
			if cnt_shift < 7 then
				sfr_done <= '0';
				if sfr_shift = '1' then
					cnt_shift := cnt_shift +1;
				end if;
			else 
				sfr_done <= '1';
				if sfr_load = '1' then
					cnt_shift := 0;
				end if;
			end if;
		end if;
	end if;
end process;

	
	FSM : process(clk) is
	begin
		if rising_edge(clk) then
			if (reset = '0') then
				state <= state_wait_for_signal;
				aserial_wnr <= '0';
				acnt_rst <= '0';
				sfr_load <= '0';
				acnt_inc <= '0';
				sfr_shift <= '0';
			else
				CASE state IS
            		WHEN state_wait_for_signal=> 
						if (start = '1') then
					  		state <= state_sfr_load;
					  		aserial_wnr <= '1';
							acnt_rst <= '0';
					  	end if;
					when state_sfr_load => 
						state <= state_acnt_inc;
						sfr_load <= '1';
					when state_acnt_inc=> 
						state <= state_aserial_run;
						sfr_load <= '0';
						acnt_inc <= '1';
					when state_aserial_run=> 
						acnt_inc <= '0';
						sfr_shift <= '0';
						aserial_wnr <= not (sfr_done and acnt_eq191); 
						if aserial_run = '0' then
							if sfr_done = '1' then
								if acnt_eq191 = '1' then
									state <= state_wait_for_signal;
									acnt_rst <= '1';
								else
									state <= state_sfr_load;
								end if;
							else
								state <= state_sfr_shift;
							end if;
						end if;
					when state_sfr_shift => 
						state <= state_aserial_run;
						sfr_shift <= '1';
					when others =>
						state <= state_wait_for_signal;
					END CASE;
			end if;
		end if;
	end process;

	working <= not acnt_rst;
		
	data_in_s <= shift_rgb_byte(7);
end architecture behv;
