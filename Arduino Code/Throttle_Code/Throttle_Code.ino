#include <SoftwareSerial.h>

#include <SPI.h>

const int slaveSelectPin = 10;

int throttle_input = A0 ; //input pin from the throttle lever
byte inData_old = 0;
byte inData_mapped = 0;
byte throttle_output_val = 0; // holds mapped output value
byte start_byte = 0x1B;
byte stop_byte = 0x0A;
int old_throttle_output_val = 0; //holds old throttle output val


const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0; 

SoftwareSerial serial_throttle (7, 8);

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
  int i;
  byte inData = 0x00;
  Serial.println("Going Remote");
  inData = serial_throttle.read();

  while(inData != 128 && inData != 127)
  { 
    if(inData != inData_old){
      inData_mapped = map(inData, 0, 255, 54, 201);
      throttle_write(inData_mapped);
      Serial.println(inData);
      inData_old = inData;
   }
	if(serial_throttle.available()) inData = serial_throttle.read();
  }
  Serial.println("Going Manual");
      inData_mapped = map(inData, 0, 255, 54, 201);
      throttle_write(inData_mapped);
      Serial.println(inData);
}


void loop() {
  // put your main code here, to run repeatedly: 

  if (serial_throttle.available()) {
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
  serial_throttle.write((map(throttle_output_val,63,187,100,-100)));
  if(throttle_output_val != old_throttle_output_val){ //check to see if the value has changed
    Serial.println(throttle_output_val); //print the value to the serial port
    throttle_write(throttle_output_val); //analog write the value to the output pin
    old_throttle_output_val = throttle_output_val; //update the current value
  }
 
  delay(2);

}






