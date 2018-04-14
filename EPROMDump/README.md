# EPROM dump

This code is used to dump the content of the EEPROM (it can only read from 0 to 63, but is really easy to make it read the whole memory).

It outputs the data as CELL; BITS (example 0; 01010101)

## How to install and use

Open a terminal and write: 

make menuconfig -> Save without changes
make flash
make monitor

## GPIO connections:
* GPIO_26 (Output) -> 1° bit of the address
* GPIO_21 (Output) -> 2° bit of the address
* GPIO_22 (Output) -> 3° bit of the address
* GPIO_23 (Output) -> 4° bit of the address
* GPIO_32 (Output) -> 5° bit of the address

* GPIO_12 (Input)  -> 1° bit of the output from EPROM
* GPIO_25 (Input)  -> 2° bit of the output from EPROM
* GPIO_14 (Input)  -> 3° bit of the output from EPROM
* GPIO_15 (Input)  -> 4° bit of the output from EPROM
* GPIO_16 (Input)  -> 5° bit of the output from EPROM
* GPIO_17 (Input)  -> 6° bit of the output from EPROM
* GPIO_18 (Input)  -> 7° bit of the output from EPROM
* GPIO_19 (Input)  -> 8° bit of the output from EPROM
