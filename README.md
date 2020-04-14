# Tesla-Model-3-Battery-BMS
Reverse engineering of the Tesla Model 3 battery bms control


03/04/20 : Uploaded a design to receive ISO SPI data and convert to 3.3v level Pos and Neg pulses for feeding to an FPGA or MCU. Based on the DC1907A design : https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/dc1907a.html#eb-overview

PCB files in DesignSpark PCB 9 format. Also included CPL and BOM files for use at https://jlcpcb.com/

06/04/20 : Added some logic analyser captures for hvcon batman while connected to one of 3 battery modules.
 The unknown pin on the header comes to life when connected to a slave module. Log files taken with a Digilent Analog Discovery 2 and Saleae Logic.

Also uploaded scope captures taken on a HV controller on its own.

13/04/20 : Experimented with an LTC6820 IC. Uploaded new scope captures. Short version : The Tesla version of ISO-SPI uses chip select and data pulses with widths far outside of the spec for the LTC6820 so off the shelf LTC hardware will not work with Tesla Model 3 battery modules.

14/04/20 : Analog front end circuit works. We can now translate Musk-spi into 3.3v pulses ready to feed into an fpga or micro for decoding into data.
