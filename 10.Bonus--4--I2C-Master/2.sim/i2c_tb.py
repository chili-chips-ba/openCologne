import cocotb
from cocotb.triggers import RisingEdge, FallingEdge
from cocotb.clock import Clock

# Define state constants for better readability
IDLE               = 0
START              = 1
WRITE_SLAVE_ADDR   = 2
CHECK_ACK          = 3
WRITE_REG_ADDR_MSB = 4
WRITE_REG_ADDR     = 5
STOP               = 6
RESTART            = 7

async def init_dut(dut):
    """Initialize the DUT with default values."""
    cocotb.log.info("[INIT] Initializing the DUT")
    dut.areset_n.value = 1
    dut.i2c_scl.value = 1
    dut.i2c_sda.value = 1
    await RisingEdge(dut.clk_10MHz)

async def reset_dut(dut):
    """Reset the DUT."""
    cocotb.log.info("[RESET] Resetting the DUT")
    dut.areset_n.value = 0
    await RisingEdge(dut.clk_10MHz)
    dut.areset_n.value = 1
    await RisingEdge(dut.clk_10MHz)

async def strobe_test(dut):
    """Test the strobe signal for expected behavior."""
    cocotb.log.info("[TEST] Testing strobe signal")

    await RisingEdge(dut.strobe_100kHz)
    assert dut.strobe_100kHz.value == 1, "Strobe should be high"

    await FallingEdge(dut.strobe_100kHz)
    assert dut.strobe_100kHz.value == 0, "Strobe should go low"

async def run_simulation(dut, iterations=200):
    """
    Simulate the clock stretching behavior and control the SDA line.
    """
    cocotb.log.info("[RUN SIMULATION] Simulating clock stretching behavior")

    for _ in range(iterations):
        state = int(dut.u_i2c_top.u_i2c_ctrl.state.value)
        process_cnt = int(dut.u_i2c_top.u_i2c_ctrl.process_cnt.value)

        # Clock Stretching: Control the SCL (clock line)
        if state in {WRITE_SLAVE_ADDR, CHECK_ACK, WRITE_REG_ADDR_MSB, WRITE_REG_ADDR, STOP} and process_cnt == 1:
            dut.u_i2c_top.u_i2c_ctrl.scl_do.value = 1
            cocotb.log.info(f"[CLOCK STRETCHING] Holding SCL high in state {state} with process count {process_cnt}")
        else:
            dut.u_i2c_top.u_i2c_ctrl.scl_do.value = 0

        # Control the SDA (data line)
        if state == CHECK_ACK and process_cnt == 2:
            dut.u_i2c_top.u_i2c_ctrl.sda_do.value = 0
            cocotb.log.info(f"[SDA CONTROL] Driving SDA low in state {state} with process count {process_cnt}")
        else:
            dut.u_i2c_top.u_i2c_ctrl.sda_do.value = 1

        await RisingEdge(dut.strobe_100kHz)

@cocotb.test()
async def main_test(dut):
    """Main test sequence."""
    cocotb.log.info("[START] Starting main test")

    # Start the clock
    clock = Clock(dut.clk_10MHz, 100, units="ns")
    cocotb.start_soon(clock.start())

    # Initialize and reset DUT
    await init_dut(dut)
    await reset_dut(dut)

    # Check initial conditions after reset
    cocotb.log.info("[CHECK] Verifying initial conditions")
    assert dut.counter.value == 0, "Counter should be zero after reset"
    assert dut.strobe_100kHz.value == 0, "Strobe 100kHz should be low after reset"

    # Perform the simulation with the specified number of iterations
    await run_simulation(dut, iterations=200)

    cocotb.log.info("[END] Main test completed")
