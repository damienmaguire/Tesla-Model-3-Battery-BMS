# Tesla-Model-3-Battery-BMS
Reverse engineering of the Tesla Model 3 battery bms control


03/04/20 : Uploaded a design to receive ISO SPI data and convert to 3.3v level Pos and Neg pulses for feeding to an FPGA or MCU. Based on the DC1907A design : https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/dc1907a.html#eb-overview

PCB files in DesignSpark PCB 9 format. Also included CPL and BOM files for use at https://jlcpcb.com/

06/04/20 : Added some logic analyser captures for hvcon batman while connected to one of 3 battery modules.
 The unknown pin on the header comes to life when connected to a slave module. Log files taken with a Digilent Analog Discovery 2 and Saleae Logic.

Also uploaded scope captures taken on a HV controller on its own.

13/04/20 : Experimented with an LTC6820 IC. Uploaded new scope captures. Short version : The Tesla version of ISO-SPI uses chip select and data pulses with widths far outside of the spec for the LTC6820 so off the shelf LTC hardware will not work with Tesla Model 3 battery modules.

14/04/20 : Analog front end circuit works. We can now translate Musk-spi into 3.3v pulses ready to feed into an fpga or micro for decoding into data.

06/08/20 : Now sending and receiving to one slave using the Tesla "Batman" chip. Details on Openinverter forum :<br>
https://openinverter.org/forum/viewtopic.php?f=10&t=577&p=14979#p14979


02/09/20 : Communicating with full pack using "batman". Also uploaded initial batman chip pinout.
Uploaded captures.

11/10/20 : Batman board now fully opensourced. 
Demo : https://www.youtube.com/watch?v=iv_-qdLMsMA


16/10/20 : In the hopes of encouraging colaboration and furthering the effort, I have released the full sources for an FPGA based Model 3 Iso-Spi decoder. At this time it works in receive only and does have some glitches. FPGA used is a Xilinx Spartan 6 at 50MHz. Design done using Xilinx ISE. Also includes BOM and placement file for JLCPCB.

To Do : Clean up receive and implement transmit and debug.

17/06/23 : Almost 3 years later and still no sign of a solution for talking to the M3 BMS? Oh well, just as well I've done a new STM32 based design. Prototypes on the way so let's see if (how) I screwed up ...

12/10/23 : And it works. Software development started for the controllere here : https://github.com/damienmaguire/Tesla-M3-Bms-Software
