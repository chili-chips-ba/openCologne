library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity receive_command is
    generic (
        addr : std_ulogic_vector (7 downto 0) := "00000000"
    );
    port (
        i_clk : in std_ulogic;
        i_reset : in std_ulogic;
        i_ready_read : in std_ulogic;
        i_Byte : in std_ulogic_vector (7 downto 0);
        i_done : in std_ulogic;
        o_hold : out std_ulogic);
    end receive_command;

architecture rtl of receive_command is
    signal start, hold : std_ulogic;
    signal start_1, start_2 :  std_ulogic;
begin
    rec_first : process (i_clk) is
    begin
        if rising_edge(i_clk) then
            if (i_reset = '0') then
                start_1 <= '0';
            elsif (ADDR(3 downto 0) = i_Byte(3 downto 0)) then
                start_1 <= '1';
            else
                start_1 <= '0';
            end if;
        end if;
    end process;

    rec_second : process (i_clk) is
    begin
        if rising_edge(i_clk) then
            if (i_reset = '0') then
                start_2 <= '0';
            elsif (ADDR(7 downto 4) = i_Byte(7 downto 4)) then
                start_2 <= '1';
            else
                start_2 <= '0';
            end if;
        end if;
    end process;

    start <= start_2 and start_1;

    rec_hold : process (i_clk) is
    begin
        if rising_edge(i_clk) then
            if (i_reset = '0' or i_done = '1') then
                hold <= '0';
            elsif (start = '1' and i_ready_read = '1') then
                hold <= '1';
            end if;
        end if;
    end process;

o_hold <= hold;



end architecture rtl;

