-- automatically generated with rds_msg
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;
package message is
type rds_msg_type is array(0 to 51) of std_logic_vector(7 downto 0);
-- PI=0xCAFE
-- STEREO=No
-- TA=No
-- AF=107.9 MHz
-- PS="TEST1234"
constant rds_msg_map: rds_msg_type := (
x"ca",x"fe",x"a0",x"01",x"00",x"2e",x"8e",x"1c",x"c2",x"31",x"51",x"15",x"fb",
x"ca",x"fe",x"a0",x"01",x"00",x"75",x"1c",x"dc",x"da",x"cd",x"4d",x"51",x"e9",
x"ca",x"fe",x"a0",x"01",x"00",x"99",x"ac",x"dc",x"da",x"cc",x"c4",x"cb",x"c6",
x"ca",x"fe",x"a0",x"01",x"00",x"c2",x"3c",x"dc",x"da",x"cc",x"cc",x"d2",x"51",
others => (others => '0')
);
end message;
