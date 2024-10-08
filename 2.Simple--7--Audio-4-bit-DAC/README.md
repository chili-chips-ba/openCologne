# 4-bit DAC Audio Example

## Introduction
This project demonstrates a simple audio example where a 4-bit DAC is used to generate either a sinewave or a triangle wave as output. The DAC can be built on a breadboard or a custom-designed PCB, like the one used in this case. The PCB is specially designed with four additional buttons and eight extra LEDs, addressing the limitations of the Olimex GateMate board, which has only one button and one LED.

The added buttons and LEDs make this setup versatile and useful for various projects and examples. The schematic for the SimpleIO extension board, which includes the additional buttons, LEDs, and the 4-bit DAC, can be found in the 0.doc folder. The DAC also features an AUX output for connecting headphones or speakers.

The project includes a constraints file to map the buttons and LEDs of the SimpleIO extension board, although they aren't strictly necessary for this particular example. When the button on the extension board is pressed, the output waveform switches between a sinewave and a triangle wave, which can be heard through connected headphones or speakers.

## SimpleIO Extension Board
