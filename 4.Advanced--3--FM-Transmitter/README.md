# FM Transmitter

## Introduction

The _FM Transmitter_ example is a simple, purely digitally-generated 105MHz carrier which is then Frequency Modulated with a cca 1kHz beep signal. It can be picked up, demodulated and heard on a standard FM Radio Reciever, where it sounds like Morse-code. It is however much more than Morse that merely turns the carrier on and off. 

The best way to test its sound component is by using an old-school analog AM/FM "transistor" radio from the seventies. Should you not have one of those oldies, or wish to also see the data component that's transmitted, you can get one of the many "FM Receiver" apps to your new millennium cell phone, where headphones then serve as an antenna, and touch-screen tune to this frequency. [This](https://www.youtube.com/watch?v=4Sj0zigDQHk) is one of the better ones.

This example is ported to Cologne Chip GateMate FPGA and Olimex board from [ulx3s-misc](https://github.com/emard/ulx3s-misc/tree/master/examples/fm). 

We would like to use this occasion to also point interested readers to the complementary fully-digital FM Receiver for FPGAs, known as [flearadio](https://github.com/emard/flearadio). Another interesting, pure digital open source design of FM Receiver is written in PipelineC HLS, check this [post](https://www.linkedin.com/posts/jkemmerer_radio-fpga-sdr-activity-7170424903978971136-rKOv).

## Design structure

This is a mixed-language design, written in a combination of VHDL and Verilog RTL. It consists of the following modules:
* top_fm.v
* fmgen_test.vhd
* fmgen.vhd
* rds.vhd
* lowpass.vhd
* message_ps.mem

![FMDiagram drawio](https://github.com/user-attachments/assets/ad2e45c9-fc60-4333-9a17-b5690751e252)

## Theory of Operation

The `top_fm.v` module instantiates other blocks and uses GateMate PLL to generate 40MHz and 240MHz internal clocks from the 10MHz external clock input on Olimex board. 

The 40MHz clock drives the beep generator and Radio Data System [(RDS)](https://en.wikipedia.org/wiki/Radio_Data_System) processing. The 240MHz clock drives the FM modulator, especially for the high-frequency signal generation needed for FM.

This beep serves as the PCM input to the FM modulator. When the button is not pressed, the beep signal is fed into the modulator, simulating audio input for transmission over `two sound channels` (i.e. we have stereo broadcast).

`message_ps.mem` is a memory block that stores the RDS message data. This memory holds the message data that will be transmitted as part of the cca `1.2kbps digital data transmission channel`. 

The RDS Modulator in `rds.vhd` modulates the RDS data using DBPSK onto a 57 kHz subcarrier. The lowpass filter in `lowpass.vhd` is used in the RDS module.

The FM Modulator in `fmgen.vhd` modulates the audio signal and the RDS subcarrier onto the main FM carrier frequency (105 MHz, but can be adjusted).

The modulated FM signal, which contains both the audio (beep) and the RDS metadata, is transmitted via the antenna. 

## Build flow

To build and program the project go to `3.build` folder and run 
```
make all
```

You will need to attache an antenna to the designated pin in the constraint file. It can be any pin you want, and the antenna can be a piece of loose wire, or even a jumper wire. And, of course, you will need an FM Receiver to listen to the beeps from your FM Transmitter.

## Hear for yourself

https://github.com/user-attachments/assets/c4a085f5-0a9a-490d-ac08-d8010da4e512

## See for yourself

You need a modern digital receiver to see the RDS messaging. We are yet to test it and confirm that the message we intend to send:

> _Radio Tarik, FM Kljuc, FPGA Sevdah on all frequencies_ 😃

indeed comes out to the other end.

### References

This design is mentioned on [LinkedIn](https://www.linkedin.com/feed/update/urn:li:activity:7250920739208323073?commentUrn=urn%3Ali%3Acomment%3A%28activity%3A7250920739208323073%2C7250944136688640000%29&dashCommentUrn=urn%3Ali%3Afsd_comment%3A%287250944136688640000%2Curn%3Ali%3Aactivity%3A7250920739208323073%29)

#### End of Document

