// inslude the SPI library:
#include <SPI.h>
#define SS 10
uint16_t send1=0x2ad4;
uint16_t send2=0x0000;
uint16_t req47_a=0x4700;
uint16_t req47_b=0x7000;
uint16_t padding=0x0000;
uint16_t receive1=0;
uint16_t receive2=0;
byte count1=0;
byte count2=0;


void setup() {
  // put your setup code here, to run once:
SPI.begin();
pinMode(SS,OUTPUT); //select pin
SerialUSB.begin(115200);//normal port

}

void loop() {
  for(count1=0; count1<=8; count1++)
  {
SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));//1mhz clock,msb first, mode 3
digitalWrite (SS, LOW);        // assert Slave Select
receive1 = SPI.transfer16(send1);  // do a transfer
receive2 = SPI.transfer16(send2);  // do a transfer
//if (receive2!=65535) SerialUSB.println(receive2,HEX);
digitalWrite (SS, HIGH);       // de-assert Slave Select
SPI.endTransaction ();         // transaction over
delayMicroseconds(20);

  }


SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));//1mhz clock,msb first, mode 3
digitalWrite (SS, LOW);        // assert Slave Select
receive1 = SPI.transfer16(req47_a);  // do a transfer
receive2 = SPI.transfer16(req47_b);  // do a transfer

for(count2=0; count2<=36; count2++)
{
 
receive1 = SPI.transfer16(padding);  // do a transfer
if (receive1!=0xffff) SerialUSB.println(receive1,HEX);
}
  digitalWrite (SS, HIGH);       // de-assert Slave Select
  SPI.endTransaction ();         // transaction over
delayMicroseconds(35);
delay(75);
}
