-- #################################################################################################
-- # << FPGA Torture - FPGA Stress Test >>                                                         #
-- # ********************************************************************************************* #
-- # Simple, technology-agnostic and scalable design to utilize *ALL* logic resources of an FPGA   #
-- # (LUTs and FFs). Generates very high (chaotic) switching activity / dynamic power consumption  #
-- # to stress-test the FPGA power supply. Based on a modified "circular" Galois LFSR.             #
-- #                                                                                               #
-- # NUM_CELLS generic defines the number of LUT3 + FF elements.                                   #
-- # Required LUT3s: NUM_CELLS+2                                                                   #
-- # Required FFs:   NUM_CELLS+1                                                                   #
-- # ********************************************************************************************* #
-- # BSD 3-Clause License                                                                          #
-- #                                                                                               #
-- # Copyright (c) 2022, Stephan Nolting. All rights reserved.                                     #
-- #                                                                                               #
-- # Redistribution and use in source and binary forms, with or without modification, are          #
-- # permitted provided that the following conditions are met:                                     #
-- #                                                                                               #
-- # 1. Redistributions of source code must retain the above copyright notice, this list of        #
-- #    conditions and the following disclaimer.                                                   #
-- #                                                                                               #
-- # 2. Redistributions in binary form must reproduce the above copyright notice, this list of     #
-- #    conditions and the following disclaimer in the documentation and/or other materials        #
-- #    provided with the distribution.                                                            #
-- #                                                                                               #
-- # 3. Neither the name of the copyright holder nor the names of its contributors may be used to  #
-- #    endorse or promote products derived from this software without specific prior written      #
-- #    permission.                                                                                #
-- #                                                                                               #
-- # THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS   #
-- # OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF               #
-- # MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE    #
-- # COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,     #
-- # EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE #
-- # GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED    #
-- # AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     #
-- # NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  #
-- # OF THE POSSIBILITY OF SUCH DAMAGE.                                                            #
-- # ********************************************************************************************* #
-- # https://github.com/stnolting/fpga_torture                                 (c) Stephan Nolting #
-- #################################################################################################

library ieee;
use ieee.std_logic_1164.all;

entity fpga_torture is
  generic (
    NUM_CELLS : positive :=28655  -- number of LUT3+FF elements
  );
  port (
    clk_i  : in  std_ulogic; -- clock input
    rstn_i : in  std_ulogic; -- low-active async reset
    out_o  : out std_ulogic  -- dummy output (LED or unconnected FPGA pin)
  );
end fpga_torture;

architecture fpga_torture_rtl of fpga_torture is

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

  -- combining function - mapped to a single LUT3 --
  function combine_f(a, b, c : std_ulogic) return std_ulogic is
    variable res_v : std_ulogic;
  begin
    res_v := a xor b xor c;
    return res_v;
  end function combine_f;

  -- local signals --
  signal toggle_gen : std_ulogic := '0'; -- toggle generator to start chain
  signal chain      : std_ulogic_vector(NUM_CELLS-1 downto 0) := (others => '0'); -- initialize by bitstream
  signal clk0       : std_logic; -- 0° phase  

begin
  pll_inst: CC_PLL
  generic map (
    REF_CLK=>"10.0",--referenceclkinMHz
    OUT_CLK=>"50.0",--outputclkinMHz
    PERF_MD=>"SPEED",--LOWPOWER,ECONOMY,SPEED(optional,global settingofPlace&Routecanbeusedinstead)
    LOW_JITTER=>1,--0:disable,1:enablelowjittermode
    CI_FILTER_CONST=>2,--optionalCIfilterconstant
    CP_FILTER_CONST=>4--optionalCPfilterconstant
  )
  port map (
    CLK_REF            =>clk_i,
    USR_CLK_REF        =>'0',
    CLK_FEEDBACK       =>'0',
    USR_LOCKED_STDY_RST=>'0',
    USR_PLL_LOCKED_STDY=>open,
    USR_PLL_LOCKED     =>open,
    CLK0               =>clk0,
    CLK90              =>open,
    CLK180             =>open,
    CLK270             =>open,
    CLK_REF_OUT        =>open
  );

  -- Intro and Sanity Check -----------------------------------------------------------------
  -- -------------------------------------------------------------------------------------------
  assert false report "FPGA_TORTURE using " & positive'image(NUM_CELLS) & " LUT3+FF cells." severity note;
  assert not (NUM_CELLS < 3) report "<NUM_CELLS> has to be greater than or equal to 3." severity error;


  -- Toggle Chain (single element = LUT3 + FF) ----------------------------------------------
  -- -------------------------------------------------------------------------------------------
  torture_chain: process(clk0, rstn_i)
  begin
    if (rstn_i = '0') then
      toggle_gen <= '0';
      chain      <= (others => '0');
    elsif rising_edge(clk0) then
      toggle_gen <= not toggle_gen;
      for i in 0 to NUM_CELLS-1 loop
        case i is
          when 0      => chain(i) <= combine_f(chain(NUM_CELLS-2), chain(NUM_CELLS-1), toggle_gen); -- chain start 0
          when 1      => chain(i) <= combine_f(chain(NUM_CELLS-1), toggle_gen,         chain(0));   -- chain start 1
          when 2      => chain(i) <= combine_f(toggle_gen,         chain(0),           chain(1));   -- chain start 2
--        when 3      => chain(i) <= combine_f(chain(0),           chain(1),           chain(1));   -- example
          when others => chain(i) <= combine_f(chain(i-3),         chain(i-2),         chain(i-1)); -- inside chain
        end case;
      end loop;
    end if;
  end process torture_chain;

  -- dummy output --
  out_o <= chain(chain'left); -- to prevent synthesis from removing the whole design



end fpga_torture_rtl;
