import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from cocotb.binary import BinaryValue

@cocotb.test()
async def test_ps2_keyboard(dut):
    """Test the PS/2 keyboard interface"""

    # Create a clock
    clock = Clock(dut.clk, 10, units="us")  # 100 kHz clock
    cocotb.start_soon(clock.start())  # Start the clock

    # Initialize
    dut.ps2_clk.value = 1
    dut.ps2_data.value = 1

    await RisingEdge(dut.clk)

    # Function to toggle PS/2 clock to simulate the clock line of a PS/2 keyboard
    async def toggle_ps2_clock():
        while True:
            await Timer(50, units="us")  # PS/2 clock around 10 kHz
            dut.ps2_clk.value = not dut.ps2_clk.value

    # Start toggling the PS/2 clock
    cocotb.start_soon(toggle_ps2_clock())

    # Function to simulate PS/2 protocol for sending a byte
    async def send_ps2_byte(byte):
        # Start bit (0)
        dut.ps2_data.value = 0
        await FallingEdge(dut.ps2_clk)
        await RisingEdge(dut.clk)

        # Data bits (8 bits, least significant bit first)
        for i in range(8):
            dut.ps2_data.value = (byte >> i) & 0x1
            await FallingEdge(dut.ps2_clk)
            await RisingEdge(dut.clk)

        # Parity bit (odd parity)
        parity = 1 if bin(byte).count('1') % 2 == 0 else 0
        dut.ps2_data.value = parity
        await FallingEdge(dut.ps2_clk)
        await RisingEdge(dut.clk)

        # Stop bit (1)
        dut.ps2_data.value = 1
        await FallingEdge(dut.ps2_clk)
        await RisingEdge(dut.clk)

    # Send a key scan code (e.g., 0x1C for 'A')
    await send_ps2_byte(0x1C)

    # Additional checks can be uncommented and added here to ensure the output is as expected
