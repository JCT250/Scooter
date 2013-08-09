#include <SoftwareSerial.h>

#include <SPI.h>

const int slaveSelectPin = 10;

int throttle_input = A0 ; //input pin from the throttle lever
byte incoming_byte = 0; //stores the incoming serial data
byte incoming_byte_old = 0;
byte incoming_byte_mapped = 0;
byte throttle_output_val = 0; // holds mapped output value
byte start_byte = 0x1B;
byte stop_byte = 0x0A;
int old_throttle_output_val = 0; //holds old throttle output val


const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0; 

SoftwareSerial serial_throttle (12, 13);

void setup() {
  // put your setup code here, to run once:

  pinMode(throttle_input, INPUT);
  pinMode (slaveSelectPin, OUTPUT);
  SPI.begin();
  Serial.begin(115200);
  serial_throttle.begin(9600);
}

byte throttle_write(byte value)
{
  digitalWrite(slaveSelectPin,LOW); //select the chip, start transfer
  SPI.transfer(0x11); //command byte
  SPI.transfer(value); //data byte
  digitalWrite(slaveSelectPin,HIGH); //release chip, signal end transfer
}

void serial_control(){
  byte inArray[4];
  int i;
  byte inData = 0x00;

  while (inData != 0x1B){ //Dump data in the serial port until reaching the start byte
    inData = serial_throttle.read();
  }

  inArray[0] = inData; //place the start byte in position zero of the array

  for(i=1; i<4; i++) //read three more bytes into positions 1, 2, 3 of the array
  {
    inArray[i] = serial_throttle.read();
  }

  incoming_byte = (inArray[1] * 100) + (inArray[2] * 10) + inArray[3];
  while(incoming_byte != 128 && incoming_byte != 127)
  { 
    if(incoming_byte != incoming_byte_old){
      incoming_byte_mapped = map(incoming_byte, 0, 255, 54, 201);
      throttle_write(incoming_byte_mapped);
      Serial.println(incoming_byte);
      incoming_byte_old = incoming_byte;
    }
    if(serial_throttle.available() > 3){
      inData = 0x00;
      for (i=0; i<4; i++){
        inArray[i] = 0x00;
      }

      while (inData != 0x1B){
        inData = serial_throttle.read();
      }

      inArray[0] = inData;

      for(i=1; i<4; i++)
      {
        inArray[i] = serial_throttle.read();
      }
      incoming_byte = (inArray[1] * 100) + (inArray[2] * 10) + inArray[3];
      while (serial_throttle.available() > 0)
      { 
        byte trash;
        trash = serial_throttle.read();
      }

    }
  }
      incoming_byte_mapped = map(incoming_byte, 0, 255, 54, 201);
      throttle_write(incoming_byte_mapped);
      Serial.println(incoming_byte);
}


void loop() {
  // put your main code here, to run repeatedly: 

  if (serial_throttle.available() > 3) {
    serial_control();
  }

  total = total - readings[index]; //subtract the old reading at this position in the array from the total         
  readings[index] = analogRead(throttle_input); // read from the sensor:  
  total = total + readings[index]; // add the reading to the total:   
  index = index + 1; // advance to the next position in the array:                      
  if (index >= numReadings) // if we're at the end of the array...              
    index = 0; // ...wrap around to the beginning:                           
  average = total / numReadings; // calculate the average:

  throttle_output_val = map(average, 0, 1023, 255, 0); //map the average to the correct range for output
  if(throttle_output_val != old_throttle_output_val){ //check to see if the value has changed
    Serial.println(throttle_output_val); //print the value to the serial port
	serial_throttle.write(start_byte);
    serial_throttle.print(throttle_output_val);
	serial_throttle.write(stop_byte);
    throttle_write(throttle_output_val); //analog write the value to the output pin
    old_throttle_output_val = throttle_output_val; //update the current value
  }

  delay(2);

}






