# GateMate ILA Test: Blink

The following document illustrates the test of the integrated logic analyser developed for the GateMate FPGA and the 'blink' design under test. The test was performed on an Evaluation Board V3.1B with a CCGM1A1.

The design under test has instantiated a PLL, whose output clock signal synchronously increments a 25-bit register. The highest-order bit of the register is connected to an LED. The PLL generates an output frequency of 15 MHz.

## ILA Configuration

In this test, an additional PLL will be instantiated in the ILA az a much higher frequency than the PLL in the DUT. The goal is to analyze the timing differences between the PLL's output frequencies and the external clock. To achieve this, a sample frequency eight times faster is set


The output of the interactive shell can be found in the file [example_output/output_ILACOP_blink.](example_output/output_ILACOP_blink)

The ILA was configured as follows:
- Sampling frequency: 120 MHz.
- Deactivated user reset function.
- Number of selected bits to be analysed: 	30
- Signals under test: 
    1. **clk**  
        External input clock.
    2. **clk0**  
        Frequency generated by the PLL, shifted by 0 degree.
    3. **clk180**
        Frequency generated by the PLL, shifted by 180 degree.
    4. **clk270**
        Frequency generated by the PLL, shifted by 270 degree.
    5. **clk90**
        Frequency generated by the PLL, shifted by 90 degree.
    6. **counter** [24:0]  
        The counter is incremented to the rising edge of clk0.

- Capture duration before Trigger: Sample count = 1015, Capture duration = 8.46 us
- Capture duration after Trigger: Sample count = 1033, Capture duration = 8.61 us


## Generated waveform and images of the hardware

![output waveform](example_output/ILA_blink_trigger.png)

In the waveform, the trigger activated after 1015 samples. The signals clk0, clk90, clk180, and clk270 represent the four output phases of the PLL, each offset by 90 degrees. The counter increments synchronously with the frequency of clk0. At the moment of triggering, the most significant bit of the counter register changes from 0 to 1, causing the connected LED (active LOW) to switch off.

## Utilization Report 

CPEs                    403 /  20480  (  2.0 %)
 -----------------------------------------------
   CPE Registers         195 /  40960  (  0.5 %)
     Flip-flops          195


Block RAMs              2.0 /     32  (  6.3 %)
 -----------------------------------------------
   BRAM_20K                1 /     64  (  1.6 %)
   BRAM_40K                1 /     32  (  3.1 %)

PLLs                      2 /      4  ( 50.0 %)
 GLBs                      2 /      4  ( 50.0 %)
 SerDes                    0 /      1  (  0.0 %)
 USR_RSTN                  1 /      1  (100.0 %)