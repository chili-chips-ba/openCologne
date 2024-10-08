# FM Transmitter

## Introduction

The FM Transmitter in this example is a simple beep generator that can be picked up at FM frequencies with a valid FM Radio Reciever. The best way to test this out is with an oldschool FM radio reciever and on the chance that you don't have one you can use your phone with headphones that act as an antenna to tune the FM Radio to the Transmitters frequency.

The used VHDL and Verilog modules are:
* top_fm.v
* fmgen_test.vhd
* fmgen.vhd
* rds.vhd
* lowpass.vhd
* message_ps.mem

## Working principle

![FMDiagram drawio](https://github.com/user-attachments/assets/ad2e45c9-fc60-4333-9a17-b5690751e252)


The `top_fm.v` module is the general top module which uses the CologneChips 10MHz clock to generate two clocks: 40MHz and 240MHz. The 40MHz clock is used to drive the beep generator and the RDS processing.The 240MHz clock is used for driving the FM modulator, especially for the high-frequency signal generation needed for FM.
This beep serves as the PCM input to the FM modulator. When the button is not pressed btn, the beep signal is fed into the modulator, simulating an audio input for transmission.

`message_ps.mem` is a memory block that stores the RDS message data. This memory holds the message data that will be transmitted as part of the RDS signal. 

The RDS Modulator in `rds.vhd` modulates the RDS data using DBPSK onto a 57 kHz subcarrier. The lowpass filter in `lowpass.vhd` is used in the RDS module.

The FM Modulator in `fmgen.vhd` modulates the audio signal and the RDS subcarrier onto the main FM carrier frequency (105 MHz, but can be adjusted).

The modulated FM signal, which contains both the audio (beep) and the RDS metadata, is transmitted via the antenna. 

## Build the project

To build and program the project go to `3.build` folder and run 
```
make all
```

You will need an antenna at the dedicated pin in the constraint file, it can be any pin you want and the antenna can be a piece of wire or a jumper wire. And also ofcourse you will need a FM reciever to test out your FM Transmitter.

## Hear for yourself


https://github.com/user-attachments/assets/c4a085f5-0a9a-490d-ac08-d8010da4e512


