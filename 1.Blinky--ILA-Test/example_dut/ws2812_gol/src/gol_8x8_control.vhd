-- #################################################################################################
-- #   << ws2812gol - gol_8x8_control >>                                               			#
-- #  a matrix is created from individual game of life cells. the initialisation and calculation   #
-- #  of a new generation is also controlled.     													#
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

entity gol_8x8_control is
  port (
    clk         : in  std_ulogic;
    reset       : in std_ulogic;
	write_en_RAM : out std_ulogic;
	ws2812_rgb_byte	: out std_ulogic_vector(7 downto 0);
	ws2812_ram_addr_wr	: out std_ulogic_vector(7 downto 0);
	write_ws2812_out : out std_ulogic;
	ws2812_busy	: in std_ulogic;
	din_spi : in std_ulogic_vector(7 downto 0);
	waddr_spi : in std_ulogic_vector(2 downto 0);
	write_en : in std_ulogic;
	start_sm_new :  in std_ulogic
	);
  end gol_8x8_control;

architecture verhalten of gol_8x8_control is

signal ws2812_rgb_byte_reg : std_ulogic_vector(7 downto 0);

type in_array_t is array (0 to 7) of std_ulogic_vector(0 to 7);
type in_matrix_t is array (0 to 7) of in_array_t;
signal neighbours_in  			: in_matrix_t;

type out_matrix_t is array (0 to 9) of std_ulogic_vector(9 downto 0);
signal life_out 				: out_matrix_t;

signal write_ws2812_s : std_ulogic;

signal write_to_ram_ws28_12_done_hold, write_to_ram_ws28_12_done : std_ulogic;

signal shift_life_row	   : std_ulogic_vector (7 downto 0);

signal life_shift_cnt : integer range 0 to 7; 

signal ws2812_ram_addr_wr_s : std_ulogic_vector(7 downto 0) := "00000000";

signal writeRam 	: std_ulogic := '0'; 

signal write_en_s : std_ulogic;

signal gol_init : std_ulogic;



signal gol_next_gen : std_ulogic := '0';
TYPE state_color_to_ram_Type IS (IDLE, load_shift_reg, load_color_reg, shift, shift_wait);
SIGNAL state_color_to_ram   : state_color_to_ram_Type := IDLE;


signal counter_index : integer range 1 to 8;

TYPE TL_GOL_STATE_TYPE IS ( cpu_load, cpu_load_done, wait_write, write_ram, write_ws2812, wait_ws2812, wait_break, next_gen, next_gen_done);
SIGNAL TL_GOL_STATE : TL_GOL_STATE_TYPE := cpu_load;  

signal rgb_color : integer range 0 to 2;

signal break_counter : integer range 0 to 10000000;

type ram is array (0 to 7) of std_ulogic_vector(7 downto 0);
signal init_pattern : ram;

signal nachbarn    			: std_ulogic_vector (35 downto 0) := "000000000000000000000000000000000000";


begin
gol_row: for i in 0 to 7 generate
   gol_column: for j in 0 to 7 generate
    gol : entity work.gol
    port map (
        N       => neighbours_in(i)(j),
        clk     => clk,
        set    	=> gol_init, 
        nextGen => gol_next_gen,
        CPUin   => init_pattern(i)(j), 
        L       => life_out(i+1)(j+1),
        reset   => reset
    );
    end generate gol_column;
end generate gol_row;


-- BLO
xyIndex: for x in 0 to 8 generate
	-- reihe 0 fehlt 0, 1, 2
		life_out(0)(x) <= Nachbarn(x);                           
		life_out(x)(9) <= Nachbarn(9+x);
		life_out(9)(9-x) <= Nachbarn(18+x);
		life_out(9-x)(0) <= Nachbarn(27+x);
	end generate;


-- Zellen miteinander verbinden
xIndex: for x in 0 to 7 generate
    yIndex: for y in 0 to 7 generate
        neighbours_in(x)(y)(0) <= life_out((x+1)-1)((y+1)-1);	
        neighbours_in(x)(y)(1) <= life_out((x+1)-1)((y+1));	    
        neighbours_in(x)(y)(2) <= life_out((x+1)-1)((y+1)+1);	
        neighbours_in(x)(y)(3) <= life_out((x+1))((y+1)-1);   	
        neighbours_in(x)(y)(4) <= life_out((x+1))((y+1)+1);	    
        neighbours_in(x)(y)(5) <= life_out((x+1)+1)((y+1)-1);   
        neighbours_in(x)(y)(6) <= life_out((x+1)+1)((y+1));	   
        neighbours_in(x)(y)(7) <= life_out((x+1)+1)((y+1)+1); 	         
   end generate;
end generate;

write_ws2812_out <= write_ws2812_s;
state_maschine : process (clk) is   
	begin
	if rising_edge(clk) then
			if reset = '0' or start_sm_new = '1' then
				TL_GOL_STATE <= cpu_load;
				gol_next_gen <= '0';
				writeRam <= '0';
				write_ws2812_s <= '0';
				gol_init <= '0';
			else
				case TL_GOL_STATE IS
					when cpu_load =>
						gol_init <= '1';
						TL_GOL_STATE <= cpu_load_done;
					when cpu_load_done =>
						gol_init <= '0';
						TL_GOL_STATE <= wait_write;
					when wait_write => 
						writeRam <= '1';
							if write_en_s = '1' then
								TL_GOL_STATE <= write_ram;
							end if;
					when write_ram => 
						writeRam <= '0';
						if write_en_s = '0' then
							TL_GOL_STATE <= write_ws2812; 
						end if;
					when write_ws2812 =>
						write_ws2812_s <= '1';
						if (ws2812_busy = '1') then
							TL_GOL_STATE <= wait_ws2812;
						end if;
					when wait_ws2812 =>
						write_ws2812_s <= '0';
						if (ws2812_busy = '0') then
							TL_GOL_STATE <= wait_break;
							break_counter <= 0;
						end if;
					when wait_break =>
						if break_counter < 2000000 then
							break_counter <= break_counter+1;
						else
							TL_GOL_STATE <= next_gen;
						end if; 
					when next_gen =>
						gol_next_gen <= '1';
						TL_GOL_STATE <= next_gen_done;
					when next_gen_done =>
						gol_next_gen <= '0';
						TL_GOL_STATE <= wait_write;
				end case;
			end if;
	end if;
end process state_maschine;



setGol : process (clk) is
begin
	if rising_edge(clk) then
		if reset = '0' then
			init_pattern(0) <= "00011000";
			init_pattern(1) <= "00111100";
			init_pattern(2) <= "01000010";
			init_pattern(3) <= "11000011";
			init_pattern(4) <= "11000011";
			init_pattern(5) <= "01000010";
			init_pattern(6) <= "00111100";
			init_pattern(7) <= "00011000";
		elsif (write_en = '1') then
			init_pattern(to_integer(unsigned(waddr_spi))) <= din_spi;
		end if;
	end if;
end process;


setGen : process (clk) is
begin
	if rising_edge(clk) then
		if reset = '0' then
			state_color_to_ram <= IDLE;
			write_en_s <= '0';
		else
			case  state_color_to_ram is
				when IDLE =>
					write_en_s <= '0';
					if writeRam = '1' then
						state_color_to_ram <= load_shift_reg;
					end if;
				when load_shift_reg =>
					write_en_s <= '1';
					state_color_to_ram <= load_color_reg;
				when load_color_reg =>
					state_color_to_ram <= shift_wait;
				when shift_wait =>
					state_color_to_ram <= shift;
				when shift =>
					if write_to_ram_ws28_12_done = '1' then
						state_color_to_ram <= IDLE;
					end if;
				when others =>
					state_color_to_ram <= IDLE;
			end case;
		end if;
	end if;
end process;


load_life : process (clk) is
begin
	if rising_edge(clk) then
		if reset = '0' then
			shift_life_row<= (others => '0');
		else
			if write_en_s = '0' then
				shift_life_row <= life_out(counter_index)(8 downto 1);
			elsif rgb_color = 2 then
				if life_shift_cnt = 7 then
					shift_life_row <= life_out(counter_index)(8 downto 1);
				else
					shift_life_row <=  shift_life_row(6 downto 0) & '0';
				end if;
			end if;
		end if;
	end if;
end process;
output_counter : process (clk) is
begin
	if rising_edge(clk) then
		if reset = '0' then
			life_shift_cnt <= 0;
			counter_index <= 1;
			write_to_ram_ws28_12_done <= '0';
			write_to_ram_ws28_12_done_hold <= '0';
		else
			if write_en_s = '1' then
				if rgb_color = 2 then
					if life_shift_cnt = 6 then
						life_shift_cnt <= life_shift_cnt+1;
						if counter_index < 8 then 
							counter_index <= counter_index + 1;
						else
							write_to_ram_ws28_12_done_hold <= '1';
							counter_index <= 1;
						end if;
					elsif life_shift_cnt = 7 then
						life_shift_cnt <= 0;
						write_to_ram_ws28_12_done <= write_to_ram_ws28_12_done_hold;
					else
						life_shift_cnt <= life_shift_cnt+1;
					end if;
				end if;
			else
				life_shift_cnt <= 0;
				write_to_ram_ws28_12_done <= '0';
				counter_index <= 1;
				write_to_ram_ws28_12_done_hold <= '0';
			end if;
		end if;
	end if;
end process;

shift_counter : process (clk) is
begin
	if rising_edge(clk) then
		if reset = '0' then
			rgb_color <= 0;
		else
			if write_en_s = '1' then
				if rgb_color = 2 then
					rgb_color <= 0;
				else
					rgb_color <=  rgb_color + 1;
				end if;
			else
				rgb_color <= 0;
			end if;
		end if;
	end if;
end process;

	
	ram_adress_counter : process (clk) is
	begin
		if rising_edge(clk) then
			if reset = '0' then
				ws2812_ram_addr_wr_s <= (others => '0');
				ws2812_ram_addr_wr <= (others => '0');
			else
				if write_en_s = '1' then
					ws2812_ram_addr_wr_s <= std_ulogic_vector((unsigned(ws2812_ram_addr_wr_s)) + 1);
					ws2812_ram_addr_wr <= ws2812_ram_addr_wr_s;
				else
					ws2812_ram_addr_wr_s <= (others => '0');
					ws2812_ram_addr_wr <= (others => '0');
				end if;
			end if;
		end if;
	end process;
	
	shift_process : process (clk) is
	begin
		if rising_edge(clk) then
			if reset = '0' then
				ws2812_rgb_byte_reg <= (others => '0');
			else
						if shift_life_row(7) = '1' then
							case rgb_color is
								when 0 => ws2812_rgb_byte_reg <= "00011111";
								when 1 => ws2812_rgb_byte_reg <= "00000000";
								when 2 => ws2812_rgb_byte_reg <= "00000000";
								when others => ws2812_rgb_byte_reg <= "00000000";
							end case;
							else
							case rgb_color is
								when 0 => ws2812_rgb_byte_reg <= "00000000";
								when 1 => ws2812_rgb_byte_reg <= "00000000";
								when 2 => ws2812_rgb_byte_reg <= "00000001";
								when others => ws2812_rgb_byte_reg <= "00000000";
							end case;
						end if;
				end if;
			end if;
	end process;

	ws2812_rgb_byte <= ws2812_rgb_byte_reg;
	write_en_RAM <= write_en_s;


end verhalten;
