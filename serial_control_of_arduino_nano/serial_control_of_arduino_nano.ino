/*
  Reading a serial ASCII-encoded string.
 
 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and writes then to a digital output
  
 This example code is in the public domain.
 */

// pins for the LEDs:
const int throttle_output = 10;


void setup() {
  // initialize serial:
  Serial.begin(115200);
  // make the pins outputs:
  pinMode(throttle_output, OUTPUT); 
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int throttle_val = Serial.parseInt(); 

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      throttle_val = 255 - constrain(throttle_val, 0, 255);

      // fade the red, green, and blue legs of the LED: 
      analogWrite(throttle_output, throttle_val);

      // print the three numbers in one string as hexadecimal:
      Serial.print(throttle_val, HEX);
    }
  }
}








