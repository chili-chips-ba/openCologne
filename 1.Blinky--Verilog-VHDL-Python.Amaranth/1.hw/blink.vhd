library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity blink is
	port (
		clk : in std_logic;
		rst : in std_logic;
		led : out std_logic
	);
end entity;

architecture rtl of blink is

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
		CLK_REF             : in  std_logic;
		USR_CLK_REF         : in  std_logic;
		CLK_FEEDBACK        : in  std_logic;
		USR_LOCKED_STDY_RST : in  std_logic;
		USR_PLL_LOCKED_STDY : out std_logic;
		USR_PLL_LOCKED      : out std_logic;
		CLK0                : out std_logic;
		CLK90               : out std_logic;
		CLK180              : out std_logic;
		CLK270              : out std_logic;
		CLK_REF_OUT         : out std_logic
	);
	end component;

	signal clk0    : std_logic;
	signal counter : unsigned(26 downto 0);

begin
	socket_pll : CC_PLL
	generic map (
		REF_CLK         => "10.0",
		OUT_CLK         => "100.0",
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

	process(clk0)
	begin
		if rising_edge(clk0) then
			if rst = '0' then
				counter <= (others => '0');
			else
				counter <= counter + 1;
			end if;
		end if;
	end process;

	led <= counter(26);

end architecture;
