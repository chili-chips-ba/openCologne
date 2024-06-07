-- AUTHOR=EMARD
-- LICENSE=BSD

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.numeric_std.all; -- we need signed type from here
use ieee.math_real.all; -- to calculate log2 bit size

entity fmgen_test is
    generic
    (
        C_addr_bits: integer := 6; -- must fit 2**n >= C_rds_msg_len
        C_rds_msg_len: integer range 2 to 2048 := 52; -- RAM address range 0..n-1 for RDS binary message
        -- some useful values for C_rds_msg_len
        --  13 =        1*13 (CT)
        --  52 =        4*13 (PS)
        -- 260 =   (16+4)*13 (PS+RT)
        -- 273 = (16+4+1)*13 (PS+RT+CT)
        -- PS:  4 groups, main display 8 characters
        -- RT: 16 groups, long display 64 characters
        -- CT:  1 group,  time information
        -- 1 group is 13 bytes long
        C_fmdds_hz:           integer := 240000000; -- Hz clk_fmdds (>2*108 MHz, e.g. 250 MHz)
        --C_rds_clock_multiply: integer := 228; -- multiply and divide from clk 25 MHz
        --C_rds_clock_divide:   integer := 3125 -- to get 1.824 MHz for RDS logic
        C_rds_clock_multiply: integer := 57; -- multiply and divide from clk 40 MHz
        C_rds_clock_divide:   integer := 1250 -- to get 1.824 MHz for RDS logic
    );
    port
    (
	clk: in std_logic;
	clk_fmdds: in std_logic; -- DDS clock, must be > 2x max cw_freq, normally > 216 MHz
	cw_freq: in std_logic_vector(31 downto 0);
	pcm_in_left, pcm_in_right: in ieee.numeric_std.signed(15 downto 0) := (others => '0'); -- PCM audio input
	rds_addr: out std_logic_vector(C_addr_bits-1 downto 0); -- set byte address to RDS RAM
	rds_data: in std_logic_vector(7 downto 0); -- read data byte from RDS RAM
	--led: out std_logic_vector(7 downto 0);
	fm_antenna: out std_logic -- pyhsical output
    );
end;

architecture arch of fmgen_test is
    --constant C_addr_bits: integer := integer(ceil((log2(real(C_rds_msg_len)+1.0E-6))-1.0E-6));
    constant C_set_rds_msg_len: std_logic_vector(C_addr_bits-1 downto 0) := std_logic_vector(to_unsigned(C_rds_msg_len, C_addr_bits));

    -- FM/RDS RADIO
    signal rds_pcm: ieee.numeric_std.signed(15 downto 0); -- modulated PCM with audio and RDS
    --signal rds_addr: std_logic_vector(C_addr_bits-1 downto 0); -- RDS modulator reads BRAM from this addr during transmission
    --signal rds_data: std_logic_vector(7 downto 0); -- BRAM returns value to RDS for transmission
    signal rds_bram_write: std_logic; -- decoded address -> write signal for BRAM
    signal R_rds_bram_write: std_logic := '0'; -- 1 clock delayed write signal to offload timing constraints
    signal from_fmrds: std_logic_vector(31 downto 0); -- debugging for subcarrier phase, not used

begin

    rds_modulator: entity work.rds
    generic map
    (
      c_addr_bits => C_addr_bits, -- number of address bits for RDS message RAM
      -- multiply/divide to produce 1.824 MHz clock
      c_rds_clock_multiply => C_rds_clock_multiply,
      c_rds_clock_divide => C_rds_clock_divide,
      -- example settings for 25 MHz clock
      -- c_rds_clock_multiply => 228,
      -- c_rds_clock_divide   => 3125,
      -- example settings for 40 MHz clock
      -- c_rds_clock_multiply => 57,
      -- c_rds_clock_divide   => 1250,
      -- settings for super slow (100Hz debug) clock
      -- c_rds_clock_multiply => 1,
      -- c_rds_clock_divide => 812500,
      c_filter => true,
      c_downsample => false,
      c_stereo => true
    )
    port map
    (
      clk => clk, -- RDS and PCM processing clock, same as CPU clock
      rds_msg_len => C_set_rds_msg_len, -- R(C_rds_addr)(C_addr_bits-1 downto 0),
      addr => rds_addr,
      data => rds_data,
      pcm_in_left => pcm_in_left,
      pcm_in_right => pcm_in_right,
      pcm_out => rds_pcm
    );

    fm_modulator: entity work.fmgen
    generic map
    (
      c_fdds => real(C_fmdds_hz)
    )
    port map
    (
      clk_pcm => clk, -- PCM processing clock, same as CPU clock
      clk_dds => clk_fmdds, -- DDS clock must be > 2x cw_freq 
      cw_freq => cw_freq, -- Hz FM carrier wave frequency, e.g. 107900000
      pcm_in  => rds_pcm,
      fm_out  => fm_antenna
    );

    --rdsbram: entity work.bram_rds
    --generic map (
    --    c_mem_bytes => C_rds_msg_len, -- allocate RAM for max message size
    --    c_addr_bits => C_addr_bits -- number of address bits for RDS message RAM
    --)
    --port map (
    --    clk => clk,
    --    imem_addr => rds_addr,
    --    imem_data_out => rds_data,
    --    dmem_write => '0', -- R_rds_bram_write,
    --    dmem_addr => (others => '0'), -- R(C_rds_data)(16+C_addr_bits-1 downto 16),
    --    dmem_data_out => open, dmem_data_in => (others => '0') -- R(C_rds_data)(7 downto 0)
    --);
    --led <= rds_data(7 downto 0);
    --led <= rds_addr(7 downto 0);

end;
