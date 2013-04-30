//Test comment put in by Matt to test he can edit in github
int throttle_input = 0; //input pin from the throttle lever
int throttle_output = 0; //output pin to the scooter controller
int incoming_byte = 0; //stores the incoming serial data
int serial_active = 0; //determines whether we stay in the serial loop
int throttle_output_val = 0; // holds mapped output value
int old_throttle_output_val = 0; //holds old throttle output val

void setup() {
  // put your setup code here, to run once:
  
  pinMode(throttle_input, INPUT);
  pinMode(throttle_output, OUTPUT);
  
Serial.begin(115200);
}

void serial_control(){
  while(incoming_byte != 500){
    if (Serial.available() > 0) {
      incoming_byte = Serial.read();
      if(incoming_byte >=0){
        if(incoming_byte <= 0){
          analogWrite(throttle_output, incoming_byte);
        }
      }
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly: 
  
  if (Serial.available() > 0) {
       incoming_byte = Serial.read();
       if(incoming_byte == 500){
          incoming_byte = 0;
          serial_control();
       }
  }
  
  throttle_output_val = map(analogRead(throttle_input), 0, 0123, 0, 255);
  analogWrite(throttle_output, throttle_output_val);
  if(throttle_output_val != old_throttle_output_val){
    Serial.println(throttle_output_val);
    old_throttle_output_val = throttle_output_val;
  }
  
  delay(2);
  
}
