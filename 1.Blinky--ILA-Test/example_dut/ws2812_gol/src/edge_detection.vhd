library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity edge_detection is
    port (
        i_clk : in std_ulogic;
        i_reset : in std_ulogic;
        i_signal : in std_ulogic;
        o_post_edge : out std_ulogic
    );
    end edge_detection;

    architecture behv of edge_detection is
        signal signal_new : std_ulogic;
    begin
        rx_shift : process (i_clk) is
        begin
            if rising_edge(i_clk) then
                if i_reset = '0' then
                    o_post_edge <= '0';
                    signal_new <= i_signal;
                else
                    signal_new <= i_signal;
                    o_post_edge <= i_signal and (not signal_new);
                end if;
            end if;
        end process;

    end behv;  