const int debounce = 100;
const int Lred = 6; //pin numbers for the various outputs
const int Lgreen = 11;
const int Lblue = 9;
const int Rred = 10;
const int Rgreen = 13;
const int Rblue = 5;

int lg = 0;
int lr = 0;
int lb = 0;
int rg = 0;
int rr = 0;
int rb = 0;

void setup() {
  // put your setup code here, to run once:

pinMode (Lred, OUTPUT);
pinMode (Lgreen, OUTPUT);
pinMode (Lblue, OUTPUT);
pinMode (Rred, OUTPUT);
pinMode (Rgreen, OUTPUT);
pinMode (Rblue, OUTPUT);


Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly: 


lb = 256;


for(int a=0; a<256; a++){
  lg ++;
  analogWrite(Lgreen,lg);
  //analogWrite(Lred,lr);
  //analogWrite(Lblue,lb);
  delay(1);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
}

for(int f=0; f<256; f++){
  lb --;
  digitalWrite(Lgreen,HIGH);
  //analogWrite(Lred,lr);
  analogWrite(Lblue,lb);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
  delay(1);
}

for(int b=0; b<256; b++){
  lr ++;
  digitalWrite(Lgreen,HIGH);
  analogWrite(Lred,lr);
  //analogWrite(Lblue,lb);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
  delay(1);
}

for(int c=0; c<256; c++){
  lg --;
  analogWrite(Lgreen,lg);
  digitalWrite(Lred,HIGH);
  //analogWrite(Lblue,lb);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
  delay(1);
}

for(int d=0; d<256; d++){
  lb ++;
  //analogWrite(Lgreen,lg);
  digitalWrite(Lred,HIGH);
  analogWrite(Lblue,lb);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
  delay(1);
}

for(int e=0; e<256; e++){
  lr --;
  //analogWrite(Lgreen,lg);
  analogWrite(Lred,lr);
  digitalWrite(Lblue,HIGH);
  Serial.print(lg);
  Serial.print(",");
  Serial.print(lr);
  Serial.print(",");
  Serial.println(lb);
  delay(1);
}



}

