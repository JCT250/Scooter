//Test comment put in by Matt to test he can edit in github
int throttle_input = A0 ; //input pin from the throttle lever
int throttle_output = 10; //output pin to the scooter controller
int incoming_byte = 0; //stores the incoming serial data
int throttle_output_val = 0; // holds mapped output value
int old_throttle_output_val = 0; //holds old throttle output val

const int numReadings = 10;
 
 int readings[numReadings];      // the readings from the analog input
 int index = 0;                  // the index of the current reading
 int total = 0;                  // the running total
 int average = 0; 

void setup() {
  // put your setup code here, to run once:
  
  pinMode(throttle_input, INPUT);
  pinMode(throttle_output, OUTPUT);
  
Serial.begin(115200);
}
/*
void serial_control(){
  while(incoming_byte != 500){
    if (Serial.available() > 0) {
      incoming_byte = Serial.read();
      if(incoming_byte >= 0){
        if(incoming_byte <= 255){
          analogWrite(throttle_output, incoming_byte);
        }
      }
    }
  }
}

*/
void loop() {
  // put your main code here, to run repeatedly: 

/*  
  if (Serial.available() > 0) {
       incoming_byte = Serial.read();
       if(incoming_byte == 500){
          incoming_byte = 0;
          serial_control();
       }
  }
  */
  
    total = total - readings[index]; //subtract the old reading at this position in the array from the total         
    readings[index] = analogRead(throttle_input); // read from the sensor:  
    total = total + readings[index]; // add the reading to the total:   
    index = index + 1; // advance to the next position in the array:                      
    if (index >= numReadings) // if we're at the end of the array...              
    index = 0; // ...wrap around to the beginning:                           
    average = total / numReadings; // calculate the average:
   
   
   
  throttle_output_val = map(average, 0, 1023, 26, 230); //map the average to the correct range for output
  if(throttle_output_val != old_throttle_output_val){ //check to see if the value has changed
    Serial.println(throttle_output_val); //print the value to the serial port
    analogWrite(throttle_output, throttle_output_val); //analog write the value to the output pin
    old_throttle_output_val = throttle_output_val; //update the current value
  }
  
  delay(2);
  
}
