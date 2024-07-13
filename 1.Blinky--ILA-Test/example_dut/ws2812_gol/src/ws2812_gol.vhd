library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ws2812_gol is
port (
    i_sclk              : in std_ulogic;
    i_ss                : in std_ulogic;
    i_mosi              : in std_ulogic;
	o_miso              : out std_ulogic;
	led					: out std_ulogic_vector(7 downto 0);
	clk : in std_ulogic;  
	reset : in std_ulogic; 
	ws2812_out : out std_ulogic  
	);
end entity;


architecture beh of ws2812_gol is



TYPE STATE_NextGen_Type IS (IDLE, Data_to_WS2812, wait_for_finish); 
SIGNAL state_nextGen   : STATE_NextGen_Type := IDLE;




-- Signals for RAM
signal write_en_s 		: std_ulogic;		
signal waddr_s 			: std_ulogic_vector(7 downto 0) := "00000000";
signal raddr_s 			: std_ulogic_vector(7 downto 0) := "00000000";
signal din_s 			: std_ulogic_vector(7 downto 0);
signal dout_s  			: std_ulogic_vector(7 downto 0);

signal wnr_led : std_ulogic := '0'; 

signal start_ram_to_bit : std_ulogic;

signal ws2812_out_s : std_ulogic;

signal write_ws2812_s : std_ulogic;

signal ws2812_busy_s : std_ulogic;

signal byte_send : std_ulogic_vector (7 downto 0);
signal byte_receive : std_ulogic_vector (7 downto 0);
signal rec_byte_ready : std_ulogic;

signal read_ready, start_write : std_ulogic;

signal write_en_init_bram : std_ulogic;
signal waddr_init_bram : std_ulogic_vector(2 downto 0);
signal spi_cycle, wr_done_cnt : std_ulogic;
component CC_USR_RSTN is 
	port(
		USR_RSTN : out std_ulogic
	);
end component;
component CC_PLL is
	generic (
		REF_CLK         : string;  -- reference input in MHz
		OUT_CLK         : string;  -- pll output frequency in MHz
		PERF_MD         : string;  -- LOWPOWER, ECONOMY, SPEED
		LOW_JITTER      : integer; -- 0: disable, 1: enable low jitter mode
		CI_FILTER_CONST : integer; -- optional CI filter constant
		CP_FILTER_CONST : integer  -- optional CP filter constant
	);
	port (
		CLK_REF             : in  std_ulogic;
		USR_CLK_REF         : in  std_ulogic;
		CLK_FEEDBACK        : in  std_ulogic;
		USR_LOCKED_STDY_RST : in  std_ulogic;
		USR_PLL_LOCKED_STDY : out std_ulogic;
		USR_PLL_LOCKED      : out std_ulogic;
		CLK0                : out std_ulogic;
		CLK90               : out std_ulogic;
		CLK180              : out std_ulogic;
		CLK270              : out std_ulogic;
		CLK_REF_OUT         : out std_ulogic
	);
	end component;

signal CC_reset, reset_all, clk0 : std_ulogic;

begin

	ws2812_pll : CC_PLL
	generic map (
		REF_CLK         => "10.0",
		OUT_CLK         => "10.0",
		PERF_MD         => "ECONOMY",
		LOW_JITTER      => 1,
		CI_FILTER_CONST => 2,
		CP_FILTER_CONST => 4
	)
	port map (
		CLK_REF             => clk,
		USR_CLK_REF         => '0',
		CLK_FEEDBACK        => '0',
		USR_LOCKED_STDY_RST => '0',
		USR_PLL_LOCKED_STDY => open,
		USR_PLL_LOCKED      => open,
		CLK0                => clk0,
		CLK90               => open,
		CLK180              => open,
		CLK270              => open,
		CLK_REF_OUT         => open
	);

	usr_rstn_inst: CC_USR_RSTN
	port map (
		USR_RSTN => CC_reset -- reset signal to CPE array
	);

	reset_all <= CC_reset AND reset;

ram_to_bit : entity work.ram_to_bit
	port map(
		    reset => reset_all,
			clk => clk0,
			start => start_ram_to_bit,
			working => wnr_led,
			raddr => raddr_s,
			dataRead => dout_s,
			ws2812_out => ws2812_out_s
	);


dualPortRam : entity work.ram
generic map(
	addr_width => 8,
	data_width => 8
)
	port map(
		write_en => write_en_s,
		waddr => waddr_s,
		clk => clk0,
		raddr => raddr_s,
		din => din_s,
		dout => dout_s
		);

    spi_slave : entity work.spi_slave
    port map(
        i_sclk => i_sclk,
        i_ss => i_ss,
        i_mosi => i_mosi,
        i_byte_send => byte_send,
        o_miso => o_miso,
        o_rec_byte_ready => rec_byte_ready,
        o_byte_rec => byte_receive
    );

	spi_edge_detect : entity work.edge_detection
    port map(
        i_clk => clk0,
        i_reset => reset_all,
        i_signal => rec_byte_ready,
        o_post_edge => spi_cycle
    );

    write_bram_rec_cmd : entity work.receive_command
    generic map(
        addr => "01010101"
    )
    port map(
        i_clk => clk0,
        i_reset => reset_all, 
        i_ready_read  => read_ready,
        i_Byte => byte_receive,
        i_done => wr_done_cnt, 
        o_hold => start_write
    );




Golx64 : entity work.gol_8x8_control
	port map(
	    clk   		=> clk0,
		reset 		=> reset_all,
		write_en_RAM  => write_en_s,
		ws2812_rgb_byte	=> din_s,
		ws2812_ram_addr_wr 	=> waddr_s,
		write_ws2812_out => write_ws2812_s,
		ws2812_busy => ws2812_busy_s,
		din_spi => byte_receive,
		waddr_spi => waddr_init_bram,
		write_en => write_en_init_bram,
		start_sm_new => wr_done_cnt
		);

write_bram_rec : process (clk0) is
		begin
			if rising_edge(clk0) then
				if reset_all = '0' then
					write_en_init_bram <= '0';
				elsif start_write = '1' and spi_cycle = '1'  then
					write_en_init_bram <= '1';
				elsif start_write = '0' then
					write_en_init_bram <= '0';
				end if;
			end if;
		end process write_bram_rec;

		read_ready <= not start_write;

write_bram_cnt : process (clk0) is
	begin
	if rising_edge(clk0) then
		if reset_all = '0' then
			waddr_init_bram <= (others => '0');
		elsif (write_en_init_bram = '1' and spi_cycle = '1' and waddr_init_bram /= "111") then
			waddr_init_bram <=  std_ulogic_vector((unsigned(waddr_init_bram)) + 1);
		elsif (write_en_init_bram = '0') then
			waddr_init_bram <= (others => '0');
		end if;
	end if;
end process;

write_bra_cnt : process (clk0) is
begin
if rising_edge(clk0) then
	if reset_all = '0' then
		wr_done_cnt <= '0';
	elsif waddr_init_bram = "111" and spi_cycle = '1' then
		wr_done_cnt <= '1';
	else
		wr_done_cnt <= '0';
	end if;
end if;
end process;

show_reset : process (clk0) is
begin
if rising_edge(clk0) then      
  if reset_all = '0' then               
	led <= "00001111";
  else
	led <= "11110000";
  end if;
end if;
end process;

nextGen : process (clk0) is
		begin
		if rising_edge(clk0) then      
		  if reset_all = '0' then               
			state_nextGen <= IDLE;
			start_ram_to_bit <= '0';
			ws2812_busy_s <= '0';
		  else
			case state_nextGen is
				when  IDLE =>
					start_ram_to_bit <= '0';
					ws2812_busy_s <= '0';
					if write_ws2812_s = '1' then
						state_nextGen <= Data_to_WS2812;
					end if;
		  		when Data_to_WS2812 =>
				  	ws2812_busy_s <= '1';
					start_ram_to_bit <= '1';
					if  wnr_led = '1' then
						state_nextGen <= wait_for_finish;  
					end if;
				when wait_for_finish =>
					start_ram_to_bit <= '0';
					if wnr_led = '0' then
						state_nextGen <= IDLE;
					end if;
				when others =>
					state_nextGen <= IDLE;
				end case;
			end if;
		end if;
	end process nextGen;


    ws2812_out <= ws2812_out_s;
	
end architecture;
