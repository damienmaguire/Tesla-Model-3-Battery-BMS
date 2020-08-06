// inslude the SPI library:
#include <SPI.h>
#define SS 10
uint16_t send1=0x2ad4;
uint16_t send2=0x0000;
uint16_t send3=0x21f2;
uint16_t send4=0x4d00;
uint16_t send5=0x0008;
uint16_t sendX=0x0000;
uint16_t sendY=0x0000;
uint16_t req47_a=0x4700;
uint16_t req47_b=0x7000;
uint16_t req48_a=0x4800;
uint16_t req48_b=0x3400;
uint16_t req49_a=0x4900;
uint16_t req49_b=0xdd00;
uint16_t req4a_a=0x4a00;
uint16_t req4a_b=0xc900;
uint16_t req4b_a=0x4b00;
uint16_t req4b_b=0x2000;
uint16_t req4c_a=0x4c00;
uint16_t req4c_b=0xe100;
uint16_t req4d_a=0x0100;
uint16_t req4d_b=0x2700;
uint16_t req4e_a=0x0100;
uint16_t req4e_b=0x3300;
uint16_t req4f_a=0x0100;
uint16_t req4f_b=0xda00;
uint16_t req50_a=0x0000;
uint16_t req50_b=0x9400;

uint16_t padding=0x0000;
uint16_t Request_A=0x0000;
uint16_t Request_B=0x0000;
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

StartUP();
sendX=0x21f2;
sendY=0x4d00;
Generic_Send_Once();

sendX=0x0800;
sendY=0x0000;
Generic_Send_Once();

sendX=0x2ad4;
sendY=0x4d00;
Generic_Send_Once();

sendX=0x0800;
sendY=0x0000;
Generic_Send_Once();

Request_A=req47_a;
Request_B=req47_b;
SerialUSB.println("0x47 Request:");
GetData();

StartUP();
Request_A=req48_a;
Request_B=req48_b;
SerialUSB.println("0x48 Request:");
GetData();

StartUP();
Request_A=req49_a;
Request_B=req49_b;
SerialUSB.println("0x49 Request:");
GetData();

StartUP();
Request_A=req4a_a;
Request_B=req4a_b;
SerialUSB.println("0x4A Request:");
GetData();

StartUP();
Request_A=req4b_b;
Request_B=req4b_b;
SerialUSB.println("0x4B Request:");
GetData();

StartUP();
Request_A=req4c_a;
Request_B=req4c_b;
SerialUSB.println("0x4C Request:");
GetData();

StartUP();
Request_A=req4d_a;
Request_B=req4d_b;
SerialUSB.println("0x4D Request:");
GetData();

StartUP();
Request_A=req4e_a;
Request_B=req4e_b;
SerialUSB.println("0x4E Request:");
GetData();

StartUP();
Request_A=req4f_a;
Request_B=req4f_b;
SerialUSB.println("0x4F Request:");
GetData();

StartUP();
Request_A=req50_a;
Request_B=req50_b;
SerialUSB.println("0x50 Request:");
GetData();

}

void GetData()
{
SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));//1mhz clock,msb first, mode 3
digitalWrite (SS, LOW);        // assert Slave Select
receive1 = SPI.transfer16(Request_A);  // do a transfer
receive2 = SPI.transfer16(Request_B);  // do a transfer

for(count2=0; count2<=36; count2++)
{
receive1 = SPI.transfer16(padding);  // do a transfer
if (receive1!=0xffff) SerialUSB.println(receive1,HEX);
//SerialUSB.println(receive1,HEX);
}
  digitalWrite (SS, HIGH);       // de-assert Slave Select
  SPI.endTransaction ();         // transaction over
delay(75);
}

void StartUP()
{
  for(count1=0; count1<=4; count1++)
  {
SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));//1mhz clock,msb first, mode 3
digitalWrite (SS, LOW);        // assert Slave Select
receive1 = SPI.transfer16(send1);  // do a transfer
receive2 = SPI.transfer16(send2);  // do a transfer
digitalWrite (SS, HIGH);       // de-assert Slave Select
SPI.endTransaction ();         // transaction over
delayMicroseconds(20);
}
}

void Generic_Send_Once()
{

SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));//1mhz clock,msb first, mode 3
digitalWrite (SS, LOW);        // assert Slave Select
receive1 = SPI.transfer16(sendX);  // do a transfer
receive2 = SPI.transfer16(sendY);  // do a transfer
digitalWrite (SS, HIGH);       // de-assert Slave Select
SPI.endTransaction ();         // transaction over
delayMicroseconds(20);
}





  
