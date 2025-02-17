library ieee;
use ieee.std_logic_1164.all;

entity fpga_torture_tb is
end fpga_torture_tb;

architecture fpga_torture_tb_rtl of fpga_torture_tb is

  -- configuration --
  constant num_cells_c : positive := 64;

  -- dut --
  component fpga_torture
    generic (
      NUM_CELLS : positive
    );
    port (
      clk_i  : in  std_ulogic;
      rstn_i : in  std_ulogic;
      out_o  : out std_ulogic
    );
  end component;

  -- generators --
  signal clk_gen, rstn_gen : std_ulogic := '0';

  -- dummy output --
  signal dummy_out : std_ulogic;

begin

  -- generators --
  clk_gen  <= not clk_gen after 10 ns;
  rstn_gen <= '0', '1' after 60 ns;

  -- dut --
  fpga_torture_inst: fpga_torture
  generic map (
    NUM_CELLS => num_cells_c
  )
  port map (
    clk_i  => clk_gen,
    rstn_i => rstn_gen,
    out_o  => dummy_out
  );


end fpga_torture_tb_rtl;
