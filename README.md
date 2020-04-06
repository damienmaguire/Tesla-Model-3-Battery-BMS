# Tesla-Model-3-Battery-BMS
Reverse engineering of the Tesla Model 3 battery bms control


03/04/20 : Uploaded a design to receive ISO SPI data and convert to 3.3v level Pos and Neg pulses for feeding to an FPGA or MCU. Based on the DC1907A design : https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/dc1907a.html#eb-overview

PCB files in DesignSpark PCB 9 format. Also included CPL and BOM files for use at https://jlcpcb.com/

06/04/20 : Added some logic analyser captures for hvcon batman while connected to one of 3 battery modules.
 The unknown pin on the header comes to life when connected to a slave module.

Also uploaded scope captures taken on a HV controller on its own.
