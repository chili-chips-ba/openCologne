library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity ram is
	generic (
		 addr_width : natural := 8;--512x8
		 data_width : natural := 8);
	port (
		 write_en : in std_ulogic;
		 waddr : in std_ulogic_vector (addr_width - 1 downto 0);
		 clk : in std_ulogic;
		 raddr : in std_ulogic_vector (addr_width - 1 downto 0);
		 din : in std_ulogic_vector (data_width - 1 downto 0);
		 dout : out std_ulogic_vector (data_width - 1 downto 0));
	end ram;
architecture rtl of ram is
	 type mem_type is array ((2** addr_width) - 1 downto 0) of std_ulogic_vector(data_width - 1 downto 0);
	 signal mem : mem_type;
	begin
	 process (clk) 
	 -- Write memory.
	 begin
		if (clk'event and clk = '1') then
			if (write_en = '1') then
				mem(to_integer(unsigned(waddr))) <= din;
			end if;
		end if;
	 end process;
	 
	 
	 -- Read memory.
	 process (clk) 
	 begin
	 if (clk'event and clk = '1') then
	 dout <= mem(to_integer(unsigned(raddr)));
	 end if;
	 end process;
end rtl;