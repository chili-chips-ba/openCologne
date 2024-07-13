library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity ws2812_gol_tb is

end ws2812_gol_tb;



architecture dut of ws2812_gol_tb is
	constant CLKFRQ           : natural := 10_000_000;
	constant clk_half_periode : time    := 0.5 sec / CLKFRQ;
	-- component ports
	signal  reset_s            : std_ulogic;
	signal clk_s              : std_ulogic;
	signal ws2812_out_s, send_r, cnt_end       : std_ulogic;
	signal spi_clk, mosi_r, miso_r, ss_r, spi_receive_byte, spi_periode	: std_ulogic;
	signal led_w, send_byte, spy_rec_byte : std_ulogic_vector(7 downto 0);
  	 

	begin  -- architecture dut
	-- component instantiation
	DUT : entity work.ws2812_gol
	port map (
		i_sclk => spi_clk,
		i_ss => ss_r,
		i_mosi => mosi_r,
		o_miso => miso_r,
		clk   => clk_s,
		reset => reset_s,
		ws2812_out => ws2812_out_s

	);

	spi_mater_dut : entity work.spi_master
	port map(
		i_sclk => spi_clk,
		i_reset => reset_s,
		o_ss => ss_r,
		i_miso => miso_r,
		o_mosi => mosi_r,
		i_send => send_r,
		i_send_byte => send_byte,
		i_receive => spi_receive_byte,
		o_receive_byte => spy_rec_byte,
		o_period => spi_periode,
		o_cnt_end => cnt_end);

	p_clock : process
	begin
		clk_s <= '0'; 
		spi_clk <= '0';
		wait for clk_half_periode;
		spi_clk <= '1';
		clk_s <= '1'; 
		wait for clk_half_periode;
	end process p_clock;
	
	wnr_start : process
	begin
		reset_s <= '0';
		wait for 4 * clk_half_periode;
		reset_s <= '1';
		wait for 4 * clk_half_periode;
		send_r <= '1';
        spi_receive_byte <= '0';
        send_byte <= "01010101"; 
        wait on spi_periode;
        wait on spi_periode;
		send_byte <= "00011000";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "00111100";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "01000010";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "11000011";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "11000011";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "01000010";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "00111100";
		wait on spi_periode;
        wait on spi_periode;
		send_byte <= "00011000";
		wait on spi_periode;
        wait on spi_periode;
		wait on spi_periode;
        wait on spi_periode;
		send_r <= '0';
        spi_receive_byte <= '0';
		wait;
	end process wnr_start;
	
end architecture dut;
