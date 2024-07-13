-- #################################################################################################
-- #   << ws2812gol - spi_slave >>                                               					#
-- #                                                                                               #
-- # ********************************************************************************************* #
-- #    Copyright (C) 2023 Cologne Chip AG & TH Köln                             				  	#
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

entity spi_slave is
  port (
    i_sclk              : in std_ulogic;
    i_ss                : in std_ulogic;
    i_mosi              : in std_ulogic;
    i_byte_send         : in std_ulogic_vector(7 downto 0);
    o_miso              : out std_ulogic;
    o_rec_byte_ready    : out std_ulogic;
    o_byte_rec          : out std_ulogic_vector(7 downto 0));
end spi_slave;

architecture behv of spi_slave is
    signal tx_shift_reg, rx_shift_reg, o_byte_rec_reg, send_byte : std_ulogic_vector(7 downto 0);
    signal bit_cnt : std_ulogic_vector(2 downto 0);
    signal end_byte_s, end_byte_rec_read : std_ulogic;

begin
    rx_shift : process (i_sclk) is
    begin
        if rising_edge(i_sclk) then
            if i_ss = '1' then
                rx_shift_reg <= (others => '0');
            else
                rx_shift_reg <= rx_shift_reg(6 downto 0) & i_mosi;
            end if;
        end if;
    end process;

    bit_count : process (i_sclk) is
    begin
        if rising_edge(i_sclk) then
            if i_ss = '1' then
                bit_cnt <= "111";
            else
                bit_cnt <= std_ulogic_vector((unsigned(bit_cnt)) + 1);
            end if;
        end if;
    end process;

    o_rec_byte : process (i_sclk) is
    begin
        if rising_edge(i_sclk) then
            if i_ss = '1' then
                end_byte_s <= '0';
                o_byte_rec_reg <= (others => '0');
            elsif (bit_cnt = "111") then
                end_byte_s <= '1';
                o_byte_rec_reg <= rx_shift_reg;
            else
                end_byte_s <= '0';
            end if;
        end if;
    end process;

    ende : process (i_sclk) is
    begin
        if rising_edge(i_sclk) then
            if i_ss = '1' or ((bit_cnt = "100")) then
                end_byte_rec_read <= '0';
            elsif (bit_cnt = "000") then
                end_byte_rec_read <= '1';
            end if;
        end if;
    end process;


    o_rec_byte_ready <= end_byte_rec_read;
    o_byte_rec <= o_byte_rec_reg;
    send_byte <= i_byte_send;

    o_send_byte : process (i_sclk) is
    begin
        if rising_edge(i_sclk) then
            if i_ss = '1' then
                tx_shift_reg <= (others => '0');
            elsif (end_byte_s = '1') then
                tx_shift_reg <= send_byte;
            else
                tx_shift_reg <= tx_shift_reg(6 downto 0) & '0';
            end if;
        end if;
    end process;

    o_miso <= tx_shift_reg(7);


end behv;