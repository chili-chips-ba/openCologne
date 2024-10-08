# 4-bit DAC Audio Example

## Introduction
This example is adapted from the [ulx3s-misc](https://github.com/emard/ulx3s-misc/tree/master/examples/audio) repository.

This project demonstrates a simple audio example where a 4-bit DAC is used to generate either a sinewave or a triangle wave as output. The DAC can be built on a breadboard or a custom-designed PCB, like the one used in this case. The PCB is specially designed with four additional buttons and eight extra LEDs, addressing the limitations of the Olimex GateMate board, which has only one button and one LED.

The added buttons and LEDs make this setup versatile and useful for various projects and examples. The schematic for the SimpleIO extension board, which includes the additional buttons, LEDs, and the 4-bit DAC, can be found in the 0.doc folder. The DAC also features an AUX output for connecting headphones or speakers.

The project includes a constraints file to map the buttons and LEDs of the SimpleIO extension board, although they aren't strictly necessary for this particular example. When the button on the extension board is pressed, the output waveform switches between a sinewave and a triangle wave, which can be heard through connected headphones or speakers.

## SimpleIO Extension Board

![simpleIO Olimex](https://github.com/user-attachments/assets/a29ccb74-e560-4b7b-8b7d-6de8e3c9d3e6)

![image](https://github.com/user-attachments/assets/ba7f5a5e-8d39-4a7a-93ba-f29508b2824d)
