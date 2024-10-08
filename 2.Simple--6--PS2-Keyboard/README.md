# PS/2 Keyboard

The PS/2 port DIN connector used for connecting keyboards and mice to a PC compatible computer system. Its name comes from the IBM Personal System/2 series of personal computers, with which it was introduced in 1987. Here we have a PS/2 keyboard. The project was adapted from the [ulx3s-misc](https://github.com/emard/ulx3s-misc/tree/master/examples/ps2/kbd) repository of examples to work on CologneChip FPGAs.

## The Physical Interface

The physical PS/2 port is one of two styles of connectors:  The 5-pin DIN or the 6-pin mini-DIN.  Both connectors are completely (electrically) similar; the only practical difference between the two is the arrangement of pins.  This means the two types of connectors can easily be changed with simple hard-wired adaptors. If you have a USB keyboard you can buy a USB to PS/2 adapter or [make one yourself](https://www.instructables.com/USB-to-PS2-convertor/).

![image](https://github.com/user-attachments/assets/54bec155-1d92-43a3-8a58-050d2185002c)

## Communication Protocol

The PS/2 mouse and keyboard implement a bidirectional synchronous serial protocol. The bus is "idle" when both lines
are high (open-collector). This is the only state where the keyboard/mouse is allowed begin transmitting data. The host
has ultimate control over the bus and may inhibit communication at any time by pulling the Clock line low.
The device always generates the clock signal. If the host wants to send data, it must first inhibit communication from the
device by pulling Clock low. The host then pulls Data low and releases Clock. This is the "Request-to-Send" state and
signals the device to start generating clock pulses.

Summary: Bus States
* Data = high, Clock = high: Idle state.
* Data = high, Clock = low: Communication Inhibited.
* Data = low, Clock = high: Host Request-to-Send

All data is transmitted one byte at a time and each byte is sent in a frame consisting of 11 bits. These bits are:

* 1 start bit. This is always 0.
* 8 data bits, least significant bit first.
* 1 parity bit (odd parity).
* 1 stop bit. This is always 1.

The parity bit is set if there is an even number of 1's in the data bits and reset (0) if there is an odd number of 1's in the
data bits. The number of 1's in the data bits plus the parity bit always add up to an odd number (odd parity.) This is used
for error detection. The keyboard must check this bit and if incorrect it should respond as if it had received an
invalid command. Data sent from the device to the host is read on the falling edge of the clock signal; data sent from the host to the device is
read on the rising edge. The clock frequency must be in the range 10 - 16.7 kHz.

![image](https://github.com/user-attachments/assets/4808ad5c-2116-4ad3-b57b-0d3a6bcd649b)
## Simulation
Running the simulation in `2.sim/cocotb` with:
```
make
```
You can get a simple waveform of recieving `0X1C` data or `A` from the keyboard. The data is `00011100` in binary it is transmitted LSB first. Also the parity bit is 0 because there are uneven number of 1s in the data.

![ps2_sim](https://github.com/user-attachments/assets/819dba78-73c2-4501-bfc8-fd9616a7b24f)


## See for yourself



https://github.com/user-attachments/assets/506b244b-9b80-48b7-84ce-819b440699d6




## References: 
[PS/2 Protocol Overview](https://www.burtonsys.com/ps2_chapweske.htm)

[PS/2 Port - Wikipedia](https://en.wikipedia.org/wiki/PS/2_port)      


