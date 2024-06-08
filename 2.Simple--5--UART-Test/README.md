# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

Your description goes here

## UART Test for Olimex GateMate Board

### Overview

This example demonstrates a UART test for the Olimex GateMate board.

### Instructions

1. Build the Project
Navigate to the `3.build` directory and run the following command in the terminal:

```
make all
```

Ensure that the paths in the Makefile are properly configured before executing this command.
After the successful synthesis, implementation, and programming of the board, proceed to the next step.

2. Configure Serial Communication

    1.   Open your preferred serial communication terminal, such as PuTTY or Tera Term.
    2.   Set the baud rate to 115200.
    3.   Configure the port to `/dev/ttyACM0`. Verify that this is the correct port name for the USB connection to the Olimex board.

**Note:** Make sure to check and confirm the exact port name that the Olimex board is connected to, as it may vary.

3. Test the UART communication
The test is that everything you write on your keyboard should also appear on the terminal, therefore you are testing the Trasmitter and Reciever at the same time.
   
**<h3>  End of Document </h3>** 
