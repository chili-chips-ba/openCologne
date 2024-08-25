# 4.Advanced--1--SPI-LCD

The top_checkered module is designed to drive two different displays simultaneously, producing a checkered pattern on both screens. This module interfaces with the displays using SPI communication and controls the necessary signals for proper display initialization and operation.

Ensure the appropriate initialization files are available in the project directory and placed in the same folder as the Makefile.

Adjust the Makefile to ensure the correct paths to the toolchain are set.

Adjust the constraint file to match the board (OLIMEX or GateMate EVB).

The checkered pattern will be displayed on both the SSD1331 OLED and ST7789 TFT displays. 

The pictures below show expected results. 

 <img src="https://github.com/user-attachments/assets/0b848695-ef76-469c-b52a-f559f629584c" width="400">


 <img src="https://github.com/user-attachments/assets/0143bf72-9290-487f-890b-e4656e350a45" width="400">
