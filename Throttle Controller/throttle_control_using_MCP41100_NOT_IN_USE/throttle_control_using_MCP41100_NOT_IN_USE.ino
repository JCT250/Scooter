/* 
 Arduino pin    MCP41100 pin
   10      -->    1  
   11      -->    3
   13      -->    2
*/


#define DATAOUT 11//MOSI
#define DATAIN 12//MISO - not used, but part of builtin SPI
#define SPICLOCK  13//sck
#define SLAVESELECT 10//ss

byte throttle_position = 0;

char spi_transfer(volatile char data)
{
  SPDR = data;                    // Start the transmission
  while (!(SPSR & (1<<SPIF)))     // Wait the end of the transmission
  {
  };
  return SPDR;                    // return the received byte
}

void setup()
{
  byte clr;
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK,OUTPUT);
  pinMode(SLAVESELECT,OUTPUT);
  digitalWrite(SLAVESELECT,HIGH); //disable device  
  // SPCR = 01010000
  //interrupt disabled,spi enabled,msb 1st,master,clk low when idle,
  //sample on leading edge of clk,system clock/4 (fastest)
  SPCR = (1<<SPE)|(1<<MSTR);
  clr=SPSR; // read the status register into the clr variable to remove any crap left in there
  clr=SPDR; // read the data register into the clr variable to remove and crap left in there
  delay(10);
  write_pot(255);
}

byte write_pot(int value)
{
  digitalWrite(SLAVESELECT,LOW); //select the chip, start transfer
  spi_transfer(0x11); //command byte
  spi_transfer(value); //data byte
  digitalWrite(SLAVESELECT,HIGH); //release chip, signal end transfer
}

void loop()
{ 
  throttle_position = 0;
  write_pot(throttle_position);
  delay(10);
}
