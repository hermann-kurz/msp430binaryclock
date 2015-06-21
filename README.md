# msp430binaryclock
## Description
A simple binary clock, using an MSP4302452 on a TI Launchpad.
The Energia IDE (an Arduino clone for MSP430) is used for compiling/uploading the software. Hours and minutes are displayed in binary form.
## Crystal
You have to solder the 32kHz crystal to the designated solder pads on the TI Launchpad.
## LEDs
You need 6 LEDs for the minutes and 5 LEDs for the hours. Connect them using an appropriate resistor (ie 220 Ohms) to these pins:

*Minutes*

Bit | Pin
---|---
0 | P1_5
1 | P2_0
2 | P1_3
3 | P1_2
4 | P1_1
5 | P1_0

*Hours*

Bit | Pin
---|---
0 | P2_3
1 | P2_4
2 | P2_5
3 | P2_6
4 | P2_7

Press  Switch 2 on P1_3 to set the clock.
