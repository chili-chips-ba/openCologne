import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.clock import Clock

@cocotb.test()
async def dac_test(dut):

   # Starting Clock #
   clock = Clock(dut.clk, 20.8, units = "ns") # 48Mhz 
   cocotb.start_soon(clock.start())

   dut._log.info("Test: Starting DAC cocotb simulation")
   dut.arst.value = 1
   await RisingEdge(dut.clk)
   dut.arst.value = 0
   dut._log.info("Test: 1 clock passed")

   for i in range(100000):
      dut._log.info(f"Iteration {i+1}")
      await RisingEdge(dut.clk)
