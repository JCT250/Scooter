byte incomingByte = 0;   // for incoming serial data

byte r = 114;
byte g = 103;
byte b =98;

int x = 0;
int y = 0;
int z = 0;
int output = 0;

int red_output = 0;
int green_output = 0;
int blue_output = 0;

int new_data = 0;



void setup() {
         Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
pinMode (6, OUTPUT);
pinMode (11, OUTPUT);
pinMode (9, OUTPUT);
 
 }
 
void loop() {
 
        // send data only when you receive data:
         if (Serial.available() > 0) {
                 // read the incoming byte:
                 incomingByte = Serial.read();
                 
                 if(incomingByte == r){
                   x = Serial.read()-48;
                   y = Serial.read()-48;
                   z = Serial.read()-48;
                   output = (x*100)+(y*10)+z;
                 //Serial.print("Red = ");
                 //Serial.println(output);
                 //Serial.print(x);
                 //Serial.print(y);
                 //Serial.print(z);
                 //Serial.println();
                 red_output = output;
                 }
                 
                 //incomingByte = Serial.read();
                 if(incomingByte == g){
                   x = Serial.read()-48;
                   y = Serial.read()-48;
                   z = Serial.read()-48;
                   output = (x*100)+(y*10)+z;
                 //Serial.print("Green = ");
                 //Serial.println(output);
                 //Serial.print(x);
                 //Serial.print(y);
                 //Serial.print(z);
                 //Serial.println();
                 green_output = output;
                 }
                 
                 //incomingByte = Serial.read();
                 if(incomingByte == b){
                   x = Serial.read()-48;
                   y = Serial.read()-48;
                   z = Serial.read()-48;
                   output = (x*100)+(y*10)+z;
                 //Serial.print("Blue = ");
                 //Serial.println(output);
                 //Serial.print(x);
                 //Serial.print(y);
                 //Serial.print(z);
                 //Serial.println();
                 blue_output = output;
                 }
  Serial.println();
  Serial.print("Red = ");
  Serial.println(red_output);
  Serial.print("Green = ");
  Serial.println(green_output);
  Serial.print("Blue = ");
  Serial.println(blue_output);
  
  analogWrite(6, red_output);
  analogWrite(11, green_output);
  analogWrite(9, blue_output);
         }

}



