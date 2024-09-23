# PCM5102 Audio DAC Board

The **PCM5102 Audio DAC Board** is s commonly used for audio projects and is sold under various names, including  
[CJMCU-5102](https://www.bestarduino.com/p2327/CJMCU-5102-Stereo-Digital-To-Analog-Converter-PLL-Voice-Module-PCM5102A-DAC.html),
[GY-PCM5102](https://www.amazon.de/iHaospace-Interface-PCM5102-GY-PCM5102-Raspberry/dp/B07V6K9RQ7),
and [DIYMORE-5102](https://www.diymore.cc/products/i2s-pcm5102-dac-decoder-32bit-player-module-than-es9023-pcm1794-for-raspberry-pi).

For this project, the DIYMORE-5102 board is being used. While there isn’t a specific schematic available for this model, 
the CJMCU-5102 has the same pinout and is commonly referenced. You can view the 
[schematic](https://github.com/chili-chips-ba/openCologne/blob/main/10.Bonus--6--I2S-DAC/0.doc/pcm5102.Audio-DAC_schematic.png) 
for the CJMCU-5102, which should be applicable. The datasheet for the PCM5102 chip is also useful for understanding the board’s functionality.

![image](https://github.com/user-attachments/assets/b65447dc-02d2-4038-83d1-7df84db0824d)

This board can be used with various platforms, such as Raspberry Pi, Arduino, ESP32, or even FPGAs.
The code for the PCM5102 module is mostly adapted from the [ice40_audio](https://github.com/noscene/ice40_audio/blob/master/audiotest.v) github.
Overall a good blog for the PCM5102 module can be found [here](https://raspberrypi.stackexchange.com/questions/76188/how-to-make-pcm5102-dac-work-on-raspberry-pi-zerow),
even though it uses Raspberry Pi and the purple CJMCU module there is useful information to be found there.

## Specifications

The PCM5102 chip integrates a PLL (phase-locked loop) that removes the need for a master clock,
simplifying the interface to a 3-wire I2S connection. 
It supports audio data formats from 16-bit to 32-bit with sample rates up to 384kHz.

The Board has the following pins and their functions are listed:
Pinout:
* VCC - Power supply (3.3V)
* GND - Ground
* FLT - Filter select (Normal latency: Low / Low latency: High)
* DMP - De-emphasis control for 44.1kHz (Off: Low / On: High)
* SCL - System clock input
* BCK - Bit clock input
* DIN - Audio data input
* LCK - Word clock input
* FMT - Audio format select (I2S: Low / Left justified: High)
* XST - Soft mute control (Mute: Low / Unmute: High)

The PCM5102 supports common audio sample rates like 8kHz, 44.1kHz, 192kHz, and even up to 384kHz with a ±4% tolerance. The audio interface uses a 3-wire serial connection (LRCK, BCK, and DIN), 
with BCK acting as the bit clock and LRCK as the left/right word clock.

![image](https://github.com/user-attachments/assets/d742eb6a-b2b0-41bd-8068-da662d458fb5)
The chosen I2S Audio format is given below, from the [datasheet](https://github.com/chili-chips-ba/openCologne/blob/main/10.Bonus--6--I2S-DAC/0.doc/pcm5102.Audio-DAC.pdf).
![image](https://github.com/user-attachments/assets/0c154799-707e-4304-88e3-fff8fb95125a)

## How to run the project

In this project, the Verilog code is located in the `1.hw` directory, along with a filelist for compilation found in the `filelists` folder. 
If you need to regenerate the filelist, there is a script available in the `3.build/scripts` directory that automates this process.
You can generate the filelist by running the following command from the `3.build` directory:
```
./scripts/generate_filelists.sh
```
This script adjusts the file paths based on your environment, making it easier to manage your Verilog files.

To configure the PCM5102 Audio DAC for internal system clock generation, connect the `SCL` pin to `GND`.
Additionally, it is recommended to use a ~10kΩ resistor between the `XMT` pin and `VCC` to enable soft mute control.

Next, navigate to the `3.build` directory and run the following command to build the project:
```
make all
```
This command will handle the synthesis, place & route, and programming of the board.

If you don't want to run everything like this step by step, in `3.build` there is a `run.sh` script that runs everything for you, along with opening the terminal,
you just need to install Putty.

```
./run.sh
```

This will execute the entire process step by step. 
However, if you'd prefer not to manually run each step, there's a run.sh script located in `3.build` that automates everything for you, 
including opening the terminal. To use this script, ensure you have [Putty](https://www.putty.org/) installed.

To generate different audio signals:

* Press `a` on your keyboard to output a 1kHz sine wave.
* Press `m` to increase the frequency by 1kHz.
* Press `n` to decrease the frequency by 1kHz.

### Wiring the Module

In this setup, a PMOD extension is used because it operates at 3.3V. You can alternatively use the UEXT connector on the Olimex board. 
The pin mapping is defined in the top.ccf constraint file. Follow this configuration for proper pin assignment:

```
      ___________
 bck  | 1     7 | 
 din  | 2     8 |
 lrck | 3     9 |
      | 4    10 |
 GND -| 5    11 | --- GND
 3.3V-| 6    12 | --- 3.3V
      ___________


```
