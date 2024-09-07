# 4.Advanced--1--SPI-LCD

The *top_checkered* module is designed to drive two different displays simultaneously, producing a checkered pattern on both screens. This module interfaces with the displays using _Serial Peripheral Interconnect_ (SPI) communication protocol, through which it controls all necessary signals for proper display initialization and operation.

The checkered pattern is concurrently displayed on both:
- 1.5 inch IPS HD OLED, RGB666, 240x240 [ST7789](https://www.adafruit.com/product/3787)
- 0.95 inch OLED, RGB565, 96x64 [SSD1331](https://done.land/components/humaninterface/display/oled/ssd1331) 

The pictures below show expected results. Also see [this](https://www.linkedin.com/posts/chili-chips_gatemate-spi-lcd-activity-7233383297500733441-F4PM?utm_source=share&utm_medium=member_desktop").

## 1) GateMate EVB
simultaneously driving both 1.5" and 0.95" SPI LCD display 
<img src="https://github.com/user-attachments/assets/f95008b0-0579-4203-8a42-028c8021b3d5" width="400">


## 2) Olimex Board
simultaneously driving both 1.5" and 0.95" SPI LCD display
<img src="https://github.com/user-attachments/assets/b7a9971e-d7d6-4a61-9695-492366c72baf" width="400">


To reproduce, please note the following tips:
- Ensure the appropriate initialization files are available in the project directory and placed in the same folder as the Makefile.
- Adjust the Makefile to ensure the correct paths to the toolchain are set.
- Adjust the Makefile and constraint file to match the board (GateMateEVB, or Olimex).


## 3) Other LCDs

This example is also supported for:
- Waveshare [2.8inch](https://www.waveshare.com/2.8inch-capacitive-touch-lcd.htm) LCD with [Capacitive Touch Sensor](https://www.buydisplay.com/download/ic/CST328_Datasheet.pdf)
- Waveshare [2.4inch](https://www.waveshare.com/product/displays/lcd-oled/lcd-oled-2/2.4inch-lcd-module.htm?___SID=U) LCD Module
- [2.2inch](http://www.lcdwiki.com/2.2inch_SPI_Module_ILI9341_SKU:MSP2202) MSP2202 SPI LCD with ILI9341 Controller


![wavehsatelcds](https://github.com/user-attachments/assets/f4ccde4b-41a3-4033-bf1c-254728c120ac)

<p align="center" width="100%">
    <img width="33%" src="https://github.com/user-attachments/assets/b99cc244-f015-4799-a511-f20549269634">
</p>
