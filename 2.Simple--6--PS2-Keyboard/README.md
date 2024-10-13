# PS/2 Keyboard

The PS/2 port is a DIN connector used for connecting keyboards and mice peripherals to hosts. Its name comes from the IBM Personal System/2 series of personal computers, which introduced this connector in 1987. This example is about connecting PS/2 keyboard to an FPGA host. 

The project was adapted from the [ulx3s-misc](https://github.com/emard/ulx3s-misc/tree/master/examples/ps2/kbd) repo, and ported to work for CologneChip GateMate FPGA on Olimex board.

## The Physical Interface

The physical PS/2 port is one of two styles of connectors:  The 5-pin DIN or the 6-pin mini-DIN. Both connectors are electrically identical; the only difference is the connecor size, shape and arrangement of pins. 

<p align="center">
  <img src="https://github.com/user-attachments/assets/54bec155-1d92-43a3-8a58-050d2185002c">
</p>

This means that these two types of connectors can easily be changed with simple hard-wired adaptors. 

Moreover, even a modern USB keyboard can easily be connected to a PS/2 host. For that, you can buy a USB-to-PS/2 passive adapter or [make one yourself](https://www.instructables.com/USB-to-PS2-convertor). Given how hard it is to find a PS/2 keyboard these days, we are for this example using a USB keyboard with a passive adapter.

## Communication Protocol

The PS/2 mouse and keyboard implement a bidirectional synchronous serial protocol. The bus is open-collector and "Idle" when both lines are high. The keyboard/mouse peripheral may start transmitting data only from "Idle" state. The host has the ultimate control over the bus and, by pulling the Clock line low, it may inhibit communication at any time.

The peripheral Device always generates the Clock signal. If the Host wants to send data, it must first interrupt the device by pulling the Clock line low. The Host then pulls the Data line low and releases the Clock. This is the _"Request-to-Send"_ signal from Host to Device to start generating clock pulses.

Summary: Bus States
* {Data, Clock} = 11 : **Idle**
* {Data, Clock} = 10 : **Inhibit**
* {Data, Clock} = 01 : **Host Request-to-Send**

All data is transmitted one byte at a time, and each byte is sent in a frame consisting of eleven bits, modeled after UART, but now synchronous. They are:
* 1 **Start** bit. Always 0.
* 8 **Data** bits, the Least Significant Bit (LSB) goes first.
* 1 **Parity** bit (odd parity is used).
* 1 **Stop** bit. Always 1.

The Parity bit is 1 if there is an even number of 1's in the Data bits and 0 if there is an odd number of 1's in the Data bits. In other words, the number of 1's in Data bits plus the Parity bit must always add up to an odd number (hence odd parity). This is used for error detection. 

The keyboard must check Parity bit. If incorrect, it should respond as if it had received an
invalid command. Data sent from the Device to the Host is read on the falling edge of the clock signal; Data sent from the Host to the Device is read on the rising edge. The clock frequency must be in the range 10-to-16.7kHz.

<p align="center">
   <img src="https://github.com/user-attachments/assets/4808ad5c-2116-4ad3-b57b-0d3a6bcd649b">
</p>

## Simulation
Running the simulation in `2.sim/cocotb` with:
```
make
```
You can get a simple waveform of recieving `0X1C` data or ASCII `A` from the keyboard. The Data bits are `0001_1100` in binary, and transmitted the LSB first. The Parity bit is 0, as the Data already contains odd number of 1s.

<p align="center">
  <img src="https://github.com/user-attachments/assets/819dba78-73c2-4501-bfc8-fd9616a7b24f">
</p>

## See for yourself

https://github.com/user-attachments/assets/506b244b-9b80-48b7-84ce-819b440699d6

## References: 
- [PS/2 Protocol Overview](https://www.burtonsys.com/ps2_chapweske.htm)
- [PS/2 Port - Wikipedia](https://en.wikipedia.org/wiki/PS/2_port)      

#### End of Document
