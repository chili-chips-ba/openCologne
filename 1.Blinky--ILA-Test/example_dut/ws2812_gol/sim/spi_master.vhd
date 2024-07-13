library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity spi_master is
port (
    i_sclk              : in std_ulogic;
    i_reset             : in std_ulogic;
    o_ss                : out std_ulogic;
    i_miso              : in std_ulogic;
	o_mosi              : out std_ulogic;
    i_send              : in std_ulogic;
    i_send_byte         : in std_ulogic_vector(7 downto 0);
    i_receive           : in  std_ulogic;
    o_receive_byte      : out std_ulogic_vector(7 downto 0);
    o_period            : out std_ulogic;
    o_cnt_end           : out std_ulogic);
end entity;

architecture verhalten of spi_master is

TYPE state_color_to_ram_Type IS (s_Idle_M, s_Master_send, s_Master_receive);
SIGNAL stCur_master_spi   : state_color_to_ram_Type := s_Idle_M;

signal byte_send, rec_byte, receive_byte_r : std_ulogic_vector(7 downto 0);

signal counter_end, o_ss_r, counter_end_send : std_ulogic;


signal counter : integer range 0 to 7;

begin
    write_bram_cnt : process (i_sclk) is
	begin
	if rising_edge(i_sclk) then
		if i_reset = '0' then
            stCur_master_spi <= s_Idle_M;
			rec_byte <= (others => '0');
            byte_send <= (others => '0');
            o_ss_r <= '1';
        else
            case stCur_master_spi IS
					when s_Idle_M =>
                    if i_send = '1' then
                        byte_send <= i_send_byte;
                        stCur_master_spi <= s_Master_send;
                        o_ss_r <= '0';
                    elsif i_receive = '1' then
                        stCur_master_spi <= s_Master_receive;
                        rec_byte <= rec_byte(7 downto 1) & i_miso;
                        receive_byte_r <= rec_byte(7 downto 1) & i_miso;
                        o_ss_r <= '0';
                    elsif o_ss_r = '0' then
                        o_ss_r <= '1';
                        rec_byte <= rec_byte(6 downto 0) & i_miso;
                        receive_byte_r <= rec_byte(6 downto 0) & i_miso;
                    end if;
                    when s_Master_send =>
                    byte_send <= byte_send(6 downto 0) & '0';
                    if counter_end_send = '1' then
                        stCur_master_spi <= s_Idle_M;
                    end if;
                    when s_Master_receive =>
                    rec_byte <= rec_byte(6 downto 0) & i_miso;
                    if (counter_end = '1') then
                        if (i_send = '1') then
                            byte_send <= i_send_byte;
                            stCur_master_spi <= s_Master_send;
                        else 
                            stCur_master_spi <= s_Idle_M;
                        end if;
                    end if;
                end case;
	        end if;
        end if;
end process;

write_bram_cnt_n : process (i_sclk) is
begin
if rising_edge(i_sclk) then
    if i_reset = '0' then
        counter <= 0;
    else
        if o_ss_r = '0' then
            if counter < 7 then 
                counter <= counter + 1;
            else
                counter <= 0;
            end if;
        else
            counter <= 0;
        end if;
    end if;

end if;
end process;

 o_ss <= o_ss_r;
 o_mosi <= byte_send(7);
 counter_end <= '1' when (counter = 7) else '0';
 counter_end_send <= '1' when (counter = 6) else '0';
 o_cnt_end <= '1' when (stCur_master_spi = s_Idle_M) else '0';
 o_period <= '1' when (counter = 1) else '0';
 o_receive_byte <= receive_byte_r;



end architecture;
