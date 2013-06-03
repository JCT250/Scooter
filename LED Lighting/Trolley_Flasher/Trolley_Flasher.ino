#include <LiquidCrystal.h>
volatile int modeint = 1; //int to store the current mode
volatile int activeint = 0; //int to determine whether we are currently active
volatile int runonce = 0; // used to determine whether we have already run one mode 
                          //(if it is 0 then we setup the LED levles, if it is 1 then we run through the loop because the levels have already been set)
const int T = 100; //t=to make it easier to change a global time variable
volatile unsigned long previous_interrupt = 0;
volatile unsigned long current_interrupt = 0;
volatile unsigned long previous_interrupt1 = 0;
volatile unsigned long current_interrupt1 = 0;

const int debounce = 100;
const int Lred = 6; //pin numbers for the various outputs
const int Lgreen = 11;
const int Lblue = 9;
const int Rred = 10;
const int Rgreen = 13;
const int Rblue = 5;

int LrM = 0; //these hold the master values for the respective channels
int LgM = 0;
int LbM = 0;
int RrM = 0;
int RgM = 0;
int RbM = 0;

volatile int LrW = 0; //these hold the working values for the respective channels
volatile int LgW = 0;
volatile int LbW = 0;
volatile int RrW = 0;
volatile int RgW = 0;
volatile int RbW = 0;
LiquidCrystal lcd(A0, A1, A3, A2, A5, A4);

void setup() {
  // put your setup code here, to run once:

pinMode (Lred, OUTPUT);
pinMode (Lgreen, OUTPUT);
pinMode (Lblue, OUTPUT);
pinMode (Rred, OUTPUT);
pinMode (Rgreen, OUTPUT);
pinMode (Rblue, OUTPUT);
pinMode (1, INPUT_PULLUP);
pinMode (2, INPUT_PULLUP);
pinMode (0, OUTPUT);
pinMode (3, OUTPUT);

attachInterrupt(1,mode,LOW);
attachInterrupt(3,active,LOW);

void active();
void mode();

lcd.begin(8, 2);
Serial.begin(115200);
digitalWrite(0, HIGH);
digitalWrite(1, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);

lcd.setCursor(0,0);
lcd.print("Mode");
lcd.setCursor(0,1);
lcd.print("I/O");
}

void loop() {
  // put your main code here, to run repeatedly: 

lcd.setCursor(5,0);
lcd.print(modeint);
lcd.setCursor(4,1);
lcd.print(activeint);

 do{
   delay(200);
 }while(activeint == 0); 
  
 if(modeint == 1){ //police
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 255; //sets left master green value
     LbM = 255; //sets left master blue value     
     RrM = 255;
     RgM = 255;
     RbM = 255;
     
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 1){
     if(activeint ==1){   
        delay(T);
        analogWrite(Lred, LrW); //red on 
        delay(T);
        analogWrite(Lred, 0); //red off
        delay(T);
        analogWrite(Lred, LrW); //red on 
        delay(T);
        analogWrite(Lred, 0); //red off
        analogWrite(Rblue, LbW); //blue on 
        delay(T);    
        analogWrite(Rblue, 0); //blue off
        delay(T);
        analogWrite(Rblue, LbW); //blue on 
        delay(T);    
        analogWrite(Rblue, 0); //blue off
        delay(T);
        analogWrite(Lred, LrW);
        analogWrite(Rblue, RbW);
        delay(T);
        analogWrite(Lred, 0);
        analogWrite(Rblue, 0);
       } //close active if
   
       else{
          break;
       }
     } //close mode while
   } //close mode if
 

 if(modeint == 2){ //wide load
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 0; //sets left master green value
     LbM = 255; //sets left master blue value
     RrM = 255;
     RgM = 50;
     RbM = 0;
     
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 2){
     if(activeint == 1){
        delay(T);   
        analogWrite(Lred, LrW); //red on 
        analogWrite(Lblue, LbW); //blue on
        delay(T);
        analogWrite(Lred, 0); //red off
        analogWrite(Lblue, 0); //blue off
        delay(T);
        analogWrite(Rred, RrW); //red on 
        analogWrite(Rgreen, RgW); //green on 
        delay(T);
        analogWrite(Rred, 0); //red off
        analogWrite(Rgreen, 0); //green off
     } //close active if
     else{
        break;
     }
   } //close mode while
 }//close mode if
 
 if(modeint == 3){ //red flashing
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 255; //sets left master green value
     LbM = 255; //sets left master blue value
     RrM = 255;
     RgM = 255;
     RbM = 255;
     
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 3){
     if(activeint == 1){
        delay(T);   
        analogWrite(Lred, LrW); //red on 
        delay(T);
        analogWrite(Lred, 0); //red off
        delay(T);
        analogWrite(Lred, LrW); //red on 
        delay(T);
        analogWrite(Lred, 0); //red off
        delay(T);
        analogWrite(Rred, RrW); //red on 
        delay(T);
        analogWrite(Rred, 0); //red off
        delay(T);
        analogWrite(Rred, RrW); //red on 
        delay(T);
        analogWrite(Rred, 0); //red off
     } //close active if
     else{
        break;
     }
   } //close mode while
 }//close mode if
 
  if(modeint == 4){ //orange flashing
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 50; //sets left master green value
     LbM = 0; //sets left master blue value
     RrM = 255;
     RgM = 50;
     RbM = 0;
     
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 4){
     if(activeint == 1){
        delay(T);   
        analogWrite(Lred, LrW); //red on 
        analogWrite(Lgreen, LgW); //blue on
        delay(T);
        analogWrite(Lred, 0); //red off
        analogWrite(Lgreen, 0); //blue off
        delay(T);
        analogWrite(Rred, RrW); //red on 
        analogWrite(Rgreen, RgW); //green on 
        delay(T);
        analogWrite(Rred, 0); //red off
        analogWrite(Rgreen, 0); //green off
     } //close active if
     else{
        break;
     }
   } //close mode while
 }//close mode if
 
 if(modeint == 5){ //green flashing
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 255; //sets left master green value
     LbM = 255; //sets left master blue value
     RrM = 255;
     RgM = 255;
     RbM = 255;
     
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 5){
     if(activeint == 1){  
        delay(T); 
        analogWrite(Lgreen, LgW); //red on 
        delay(T);
        analogWrite(Lgreen, 0); //red off
        delay(T); 
        analogWrite(Rgreen, RgW); //red on 
        delay(T);
        analogWrite(Rgreen, 0); //red off
     } //close active if
     else{
        break;
     }
   } //close mode while
 }//close mode if

 if(modeint == 6){ //white headlights
  if(runonce == 0){
     runonce = 1;
     LrM = 255; //sets left master red value
     LgM = 255; //sets left master green value
     LbM = 255; //sets left master blue value
     RrM = 255;
     RgM = 255;
     RbM = 255;
       
     LrW = LrM;
     LgW = LgM;
     LbW = LbM;
     RrW = RrM;
     RgW = RgM;
     RbW = RbM;
  }
   while(modeint == 6){
     if(activeint == 1){   
     delay(T);
     analogWrite(Lred, LrW); //red on 
     analogWrite(Lgreen, LgW);
     analogWrite(Lblue, LbW);
     analogWrite(Rred, RrW); //red on 
     analogWrite(Rgreen, RgW);
     analogWrite(Rblue, RbW);
     } //close active if
     else{
        break;
     }
   } //close mode while
 }//close mode if
}

void active(){
  current_interrupt1 = millis();
  if(previous_interrupt1 + debounce < current_interrupt1){
    activeint = !activeint;
    if(activeint == 0){
       Serial.println("Pins Off");
       digitalWrite(Lred, 0);
       digitalWrite(Lgreen, 0);
       digitalWrite(Lblue, 0);
       digitalWrite(Rred, 0);
       digitalWrite(Rgreen, 0);
       digitalWrite(Rblue, 0);
       Serial.println("Working values set to 0");   
       LrW = 0;
       LgW = 0;
       LbW = 0;
       RrW = 0;
       RgW = 0;
       RbW = 0;
    }
    
    else if(activeint == 1){
       LrW = LrM;
       LgW = LgM;
       LbW = LbM;
       RrW = RrM;
       RgW = RgM;
       RbW = RbM;
    }     
    Serial.print("Activeint =  ");
    Serial.println(activeint);
    lcd.setCursor(5,0);
    lcd.print(modeint);
    lcd.setCursor(4,1);
    lcd.print(activeint);
 
    previous_interrupt1 = millis();
    //Put one line of LCD commands here
  }
  
}

void mode(){
  current_interrupt = millis();
  if(previous_interrupt + debounce < current_interrupt){
    modeint = modeint + 1; //increment the mode by one
    if(modeint >= 7){ //if the mode equal to or above 6 then wrap around to 1
      modeint = 1;
    }
  Serial.println("Pins Off");
    digitalWrite(Lred, 0);
    digitalWrite(Lgreen, 0);
    digitalWrite(Lblue, 0);
    digitalWrite(Rred, 0);
    digitalWrite(Rgreen, 0);
    digitalWrite(Rblue, 0);
  
  Serial.println("Working values set to 0");   
     LrW = 0;
     LgW = 0;
     LbW = 0;
     RrW = 0;
     RgW = 0;
     RbW = 0;
    runonce = 0;
    activeint = 0;
    Serial.print("Modeint =  ");
    Serial.println(modeint);
    lcd.setCursor(5,0);
    lcd.print(modeint);
    lcd.setCursor(4,1);
    lcd.print(activeint);
    previous_interrupt = millis();  
  }

}

