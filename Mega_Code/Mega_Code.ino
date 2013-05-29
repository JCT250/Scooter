
/*
  Trolley Debugger
 
 Version Number: 5.0

 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
unsigned long time;

volatile boolean busy = false;
volatile int updatespeed = 0;

int relay1 = 22; // output pin to relay1 via darlington
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 26;
int relay6 = 27;
int relay7 = 28;
int relay8 = 29;
int relaypower = 52;

int scooter_lock = 47; //pin coming from nano to trigger remote lock 
int scooter_key = 46; // pin coming from key to trigger local lock

int indicateval = 2;
int updateindicate = 0;

unsigned long oldisr0; // time ISR1 was last called and run
unsigned long newisr0; // time ISR1 was just called, compared to the above to debounce
unsigned long oldisr1;
unsigned long newisr1;
unsigned long oldisr2;
unsigned long newisr2;
unsigned long oldisr3;
unsigned long newisr3;
unsigned long oldisr4;
unsigned long newisr4;
unsigned long oldisr5;
unsigned long newisr5;

int Stat_Speed1 = 30; //Speed 1
int Stat_Speed2 = 31; //Speed 2
int Stat_Speed3 = 32; //Speed 3
int Stat_Speed4 = 33; //Speed 4
int Stat_Headlights = 34; //Headlights
int Stat_Battery1 = 35; //Battery 1
int Stat_Battery2 = 36; //Battery 2
int Stat_Battery3 = 37; //Battery 3
int Stat_Battery4 = 38; //Battery 4
int Stat_BatteryCharging = 39; //Battery Charging

int oldStat_Speed1 = 0; //Speed 1
int oldStat_Speed2 = 0; //Speed 2
int oldStat_Speed3 = 0; //Speed 3
int oldStat_Speed4 = 0; //Speed 4
int oldStat_Headlights = 0; //Headlights
int oldStat_Battery1 = 0; //Battery 1
int oldStat_Battery2 = 0; //Battery 2
int oldStat_Battery3 = 0; //Battery 3
int oldStat_Battery4 = 0; //Battery 4
int oldStat_BatteryCharging = 0; //Battery Charging

boolean refreshstatus = true;

volatile int currentspeed = 0; 
volatile int oldcurrentspeed = 0;

volatile int headlights = 0;

volatile int indicateright = 0;

volatile int indicateleft = 0;


void setup() {

  // initialize serial ports
  Serial.begin(115200); // Connection through to computer
  Serial3.begin(9600); // Connection through to LCD
  
  // initialize the digital pin as an output.
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(relaypower, OUTPUT);
  
  Serial.println("Outputs Set");
  
  // Configure interrupt pins  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  
  Serial.println("Interrupts Set");
  
  // Configure input pins
  pinMode(Stat_Speed1, INPUT);
  pinMode(Stat_Speed2, INPUT);
  pinMode(Stat_Speed3, INPUT);
  pinMode(Stat_Speed4, INPUT);
  pinMode(Stat_Headlights, INPUT);
  pinMode(Stat_Battery1, INPUT);
  pinMode(Stat_Battery2, INPUT);
  pinMode(Stat_Battery3, INPUT);
  pinMode(Stat_Battery4, INPUT);
  pinMode(Stat_BatteryCharging, INPUT);
  pinMode(scooter_lock, INPUT_PULLUP);
  pinMode(scooter_key, INPUT_PULLUP);
  
  Serial.println("Inputs Set");

  
  // Attach interupt pins to ISR's
  //attachInterrupt(5, isr_Horn, CHANGE);
  attachInterrupt(0, isr_Headlights, RISING);
  attachInterrupt(2, isr_ShiftUp, RISING);
  attachInterrupt(3, isr_ShiftDown, RISING);
  attachInterrupt(4, isr_IndicateLeft, RISING);
  attachInterrupt(1, isr_IndicateRight, RISING);
  
  Serial.println("ISRs Attached");
    
  // set the size of the display if it isn't 16x2 (you only have to do this once)
  Serial3.write(0xFE);
  Serial3.write(0xD1);
  Serial3.write(16); // 16 columns
  Serial3.write(2); // 2 rows
  delay(10);
  // we suggest putting delays after each command to make sure the data is sent and the Serial3 is updated.
  Serial3.write(0xFE);
  Serial3.write(0x50); // contrast set command
  Serial3.write(200); // contrast set variable
  delay(10);
  // set the brightness - we'll max it (255 is max brightness)
  Serial3.write(0xFE);
  Serial3.write(0x99);
  Serial3.write(255);
  delay(10);
  // turn off cursors
  Serial3.write(0xFE);
  Serial3.write(0x4B);
  Serial3.write(0xFE);
  Serial3.write(0x54);
  
  Serial.println("LCD setup complete");
  
  // create a custom character for battery level 1
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)0); // location #0
  Serial3.write((uint8_t)0x00); // 8 bytes of character data
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0xFF);
  Serial3.write((uint8_t)0xFF);
  delay(10);
  
  // create a custom character for battery level 2
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)1); // location #1
  Serial3.write((uint8_t)0x00); // 8 bytes of character data
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0x00);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write((uint8_t)0xFF);
  delay(10);
  
  // create a custom character for battery level 3
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)2); // location #2
  Serial3.write((uint8_t)0x00); // 8 bytes of character data
  Serial3.write(0x00);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write((uint8_t)0xFF);
  delay(10);
  
  // create a custom character for battery level 4
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)3); // location #3
  Serial3.write((uint8_t)0xFF); // 8 bytes of character data
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write((uint8_t)0xFF);
  delay(10);
  
  // create a custom character for battery charging
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)4); // location #4
  Serial3.write((uint8_t)0x15); // 8 bytes of character data
  Serial3.write(0x15);
  Serial3.write(0x1F);
  Serial3.write(0x1F);
  Serial3.write(0x0E);
  Serial3.write(0x04);
  Serial3.write(0x04);
  Serial3.write((uint8_t)0x04);
  delay(10);
  
  // create a custom character for Headlights
  Serial3.write(0xFE);
  Serial3.write(0x4E);
  Serial3.write((uint8_t)5); // location #5
  Serial3.write((uint8_t)0x0E); // 8 bytes of character data
  Serial3.write(0x11);
  Serial3.write(0x11);
  Serial3.write(0x15);
  Serial3.write(0x15);
  Serial3.write(0x0E);
  Serial3.write(0x0E);
  Serial3.write((uint8_t)0x0E);
  delay(10);
  
  Serial.println("LCD custom characters written");
  
  // clear screen
  Serial3.write(0xFE);
  Serial3.write(0x58);
  delay(10); 
  // go 'home'
  Serial3.write(0xFE);
  Serial3.write(0x48);
  delay(10); 
  Serial3.println("Trolley OS 0.1");
  Serial3.print("Loading...");
  delay(1000);
  
  
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  time = 0;
  
  if(digitalRead(Stat_Speed1) == HIGH) {
    currentspeed = 1;
    oldcurrentspeed = 1;
  }
  if(digitalRead(Stat_Speed2) == HIGH) {
    currentspeed = 2;
    oldcurrentspeed = 2;
  }
  if(digitalRead(Stat_Speed3) == HIGH) {
    currentspeed = 3;
    oldcurrentspeed = 3;
  }
  if(digitalRead(Stat_Speed4) == HIGH) {
    currentspeed = 4;
    oldcurrentspeed = 4;
  }
  
  digitalWrite(relaypower, 1);
  
lcd_clear(); 
  Serial.println("Entering Loop");
}

void loop() {


  digitalWrite(relay7, (digitalRead(18)));
  
  if(digitalRead(scooter_lock) == LOW){
    isr_detach();
    scooter_lock_screen_remote();
    lcd_update(); //update the LCD
    digitalWrite(relaypower, HIGH); 
    isr_attach();
   
  }
 
 
   if(digitalRead(scooter_key) == 1){
    isr_detach();
    scooter_lock_screen_key();
    lcd_update(); //update the LCD
    digitalWrite(relaypower, HIGH); 
    isr_attach();
   
  }
    
  
  if (stringComplete) {
    Serial.println(inputString);
   
   if (inputString[0] == 'R') {
     //We have a relay command
     if (inputString[1] == '1') {
       digitalWrite(relay1, HIGH);
       delay(500);
       digitalWrite(relay1, LOW);
     }
     if (inputString[1] == '2') {
       digitalWrite(relay2, HIGH);
       delay(500);
       digitalWrite(relay2, LOW);
     }
     if (inputString[1] == '3') {
       digitalWrite(relay3, HIGH);
       delay(500);
       digitalWrite(relay3, LOW);
     }
     if (inputString[1] == '4') {
       digitalWrite(relay4, HIGH);
       delay(500);
       digitalWrite(relay4, LOW);
     }
     if (inputString[1] == '5') {
       digitalWrite(relay5, HIGH);
       delay(500);
       digitalWrite(relay5, LOW);
     }
     if (inputString[1] == '6') {
       digitalWrite(relay6, HIGH);
       delay(500);
       digitalWrite(relay6, LOW);
     }
     if (inputString[1] == '7') {
       digitalWrite(relay7, HIGH);
       delay(500);
       digitalWrite(relay7, LOW);
     }
     if (inputString[1] == '8') {
       digitalWrite(relay8, HIGH);
       delay(500);
       digitalWrite(relay8, LOW);
     }
    if (inputString[1] =='I'){
        digitalWrite(relaypower, HIGH);
    }
    if (inputString[1] =='O'){
        digitalWrite(relaypower, LOW);
    }
    if (inputString[1] =='C'){
        calibration_menu();
    }
   }
   
    
    // clear the string:
    inputString = "";
    stringComplete = false;
    

  }
  //Now we need to query the LED's
  
  if (oldStat_Speed1 != digitalRead(Stat_Speed1)) refreshstatus = true;
  if (oldStat_Speed2 != digitalRead(Stat_Speed2)) refreshstatus = true;
  if (oldStat_Speed3 != digitalRead(Stat_Speed3)) refreshstatus = true;
  if (oldStat_Speed4 != digitalRead(Stat_Speed4)) refreshstatus = true;
  if (oldStat_Headlights != digitalRead(Stat_Headlights)) refreshstatus = true;
  if (oldStat_Battery1 != digitalRead(Stat_Battery1)) refreshstatus = true;
  if (oldStat_Battery2 != digitalRead(Stat_Battery2)) refreshstatus = true;
  if (oldStat_Battery3 != digitalRead(Stat_Battery3)) refreshstatus = true;
  if (oldStat_Battery4 != digitalRead(Stat_Battery4)) refreshstatus = true;
  if (oldStat_BatteryCharging != digitalRead(Stat_BatteryCharging)) refreshstatus = true;
  
  if (refreshstatus) {
    oldStat_Speed1 = digitalRead(Stat_Speed1);
    oldStat_Speed2 = digitalRead(Stat_Speed2);
    oldStat_Speed3 = digitalRead(Stat_Speed3);
    oldStat_Speed4 = digitalRead(Stat_Speed4);
    oldStat_Headlights = digitalRead(Stat_Headlights);
    oldStat_Battery1 = digitalRead(Stat_Battery1);
    oldStat_Battery2 = digitalRead(Stat_Battery2);
    oldStat_Battery3 = digitalRead(Stat_Battery3);
    oldStat_Battery4 = digitalRead(Stat_Battery4);
    oldStat_BatteryCharging = digitalRead(Stat_BatteryCharging);
    
    
  Serial.print("Speed 1 = ");
  Serial.println(digitalRead(Stat_Speed1));
  Serial.print("Speed 2 = ");
  Serial.println(digitalRead(Stat_Speed2));
  Serial.print("Speed 3 = ");
  Serial.println(digitalRead(Stat_Speed3));
  Serial.print("Speed 4 = ");
  Serial.println(digitalRead(Stat_Speed4));
  Serial.print("Headlights = ");
  Serial.println(digitalRead(Stat_Headlights));
  Serial.print("Battery 1 = ");
  Serial.println(digitalRead(Stat_Battery1));
  Serial.print("Battery 2 = ");
  Serial.println(digitalRead(Stat_Battery2));
  Serial.print("Battery 3 = ");
  Serial.println(digitalRead(Stat_Battery3));
  Serial.print("Battery 4 = ");
  Serial.println(digitalRead(Stat_Battery4));
  Serial.print("Battery Charging = ");
  Serial.println(digitalRead(Stat_BatteryCharging));
  refreshstatus=false;
  }
  
  if (updatespeed == 1) {
   isr_detach();
    if (currentspeed == 1) {
      Serial.println("R1H");
      digitalWrite(relay1, HIGH);
      delay(150);
      Serial.println("R1L");
      digitalWrite(relay1, LOW);
      oldcurrentspeed = currentspeed;
      updatespeed = 0;
    }
    
  if (currentspeed == 2) {
    Serial.println("R2H");
      digitalWrite(relay2, HIGH);
      delay(150);
      Serial.println("R2L");
      digitalWrite(relay2, LOW);
      oldcurrentspeed = currentspeed;
      updatespeed = 0;
    }
    
  if (currentspeed == 3) {
    Serial.println("R3H");
      digitalWrite(relay3, HIGH);
      delay(150);
      Serial.println("R3L");
      digitalWrite(relay3, LOW);
      oldcurrentspeed = currentspeed;
      updatespeed = 0;
    }
    
  if (currentspeed == 4) {
    Serial.println("R4H");
      digitalWrite(relay4, HIGH);
      delay(150);
      Serial.println("R4L");
      digitalWrite(relay4, LOW);
      oldcurrentspeed = currentspeed;
      updatespeed = 0;
    }
    isr_attach();
  }

  if (headlights == 1) {
    isr_detach();
    Serial.println("HLH");
    digitalWrite(relay8, HIGH);
    delay(150);
    Serial.println("HLL");
    digitalWrite(relay8, LOW);
    headlights = 0;
    isr_attach();
  }
  

   if (indicateleft == 1) {
     isr_detach();
     Serial.println("ILH");
     digitalWrite(relay5, HIGH);
     delay(150);
     Serial.println("ILL");
     digitalWrite(relay5, LOW);
     indicateleft = 0;
     isr_attach();
   }
      
   if (indicateright == 1) {
     isr_detach();
     Serial.println("IRH");
     digitalWrite(relay6, HIGH);
     delay(150);
     Serial.println("IRL");
     digitalWrite(relay6, LOW);
     indicateright = 0;
     isr_attach();
   }  
      

 lcd_update(); 
  
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

/*
void isr_Horn() {
  Serial.println("Horn Selected");
  if(digitalRead(3) == LOW) {
    digitalWrite(relay7, HIGH);
  }else{
    digitalWrite(relay7, LOW);
  }
  
}
*/


void isr_Headlights() {
  newisr0 = millis();
  
  if((oldisr0+150) < newisr0) {
  headlights = 1;
  oldisr0 = newisr0;
  }
  
}

void isr_ShiftUp() {
  newisr2 = millis();
  if((oldisr2+300) < newisr2) {
  if(currentspeed < 4) currentspeed++;
  oldisr2=newisr2;
  updatespeed = 1;
  }
}

void isr_ShiftDown() {
  newisr3 = millis();
  if((oldisr3+300) < newisr3) {
  if(currentspeed > 1) currentspeed--;
  oldisr3=newisr3;
  updatespeed = 1;
 }
}

void isr_IndicateLeft() {
   newisr4 = millis();
  
  if((oldisr4+300) < newisr4) {
  indicateleft = 1;
  oldisr4=newisr4;
  }
}

void isr_IndicateRight() {
   newisr5 = millis();
  
  if((oldisr5+300) < newisr5) {
  indicateright = 1;
  oldisr5=newisr5;
  }
}

void lcd_clear(){
  Serial3.write(0xFE);
  Serial3.write(0x58);
}


void calibration_menu(){
    
    Serial.println("Turning Scooter Off");
    delay(500);
    digitalWrite(relaypower, LOW);
    delay(1000);
    
    Serial.println("Presetting for calibration");
    delay(500);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    delay(1000);

    Serial.println("Turning Scooter On");
    delay(500);
    digitalWrite(relaypower, HIGH);
    delay(3000);
    
    Serial.println("Presetting complete");
    delay(500);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(1000);
    
    Serial.println("Entering Calibration"); //begin calibration
    delay(1000);
    digitalWrite(relay1, HIGH); //enter service menu option 1
    delay(150);
    digitalWrite(relay1, LOW);
    delay(1000);
    
    Serial.println("Please pull lever CCW");
    delay(3000);
    digitalWrite(relay1, HIGH);
    delay(150);
    digitalWrite(relay1, LOW);
    delay(1000);
    
    Serial.println("Please center the lever");
    delay(3000);
    digitalWrite(relay2, HIGH);
    delay(150);
    digitalWrite(relay2, LOW);
    delay(1000);
    
    Serial.println("Please pull lever CW");
    delay(3000);
    digitalWrite(relay4, HIGH);
    delay(150);
    digitalWrite(relay4, LOW);
    delay(1000);
    
    Serial.println("Please center the lever");
    delay(3000);
    digitalWrite(relay3, HIGH);
    delay(150);
    digitalWrite(relay3, LOW);
    delay(2000);
    
    Serial.println("Turning Scooter Off");
    delay(1000);
    digitalWrite(relaypower, LOW);
    delay(3000);
    Serial.println("Turning Scooter On");
    delay(1000);
    digitalWrite(relaypower, HIGH);
    
    delay(1000);
    Serial.println("Auto calibration complete");
    delay(3000);

}
  
void isr_detach(){
 
 detachInterrupt(0);
 detachInterrupt(1);
 detachInterrupt(2);
 detachInterrupt(3);
 detachInterrupt(4);
 detachInterrupt(5);
  
}

void isr_attach(){
 // attachInterrupt(5, isr_Horn, CHANGE);
  attachInterrupt(0, isr_Headlights, FALLING);
  attachInterrupt(2, isr_ShiftUp, FALLING);
  attachInterrupt(3, isr_ShiftDown, FALLING);
  attachInterrupt(4, isr_IndicateLeft, FALLING);
  attachInterrupt(1, isr_IndicateRight, FALLING);

}

void lcd_update(){
  
      Serial3.write(0xFE); //Change backlight Color
      Serial3.write(0xD0);
      Serial3.write(0x00); //R
      Serial3.write(0xFF); //G
      Serial3.write(0x00); //B
      delay(10);

      Serial3.write(0xFE); //Move the cursor
      Serial3.write(0x47);
      Serial3.write(0x01); //column
      Serial3.write(0x01); //row
      
      Serial3.print("Speed:");
    
        Serial3.write(0xFE); //Move the cursor
        Serial3.write(0x47);
        Serial3.write(0x07); //column
        Serial3.write(0x01); //row
        
      if(digitalRead(Stat_Speed1) == 1){
    
        Serial3.write((uint8_t)0); //Write 25% icon
        Serial3.print("   "); //Write blanks over the other icon spaces
      }
      
      else if(digitalRead(Stat_Speed2) == 1){
        Serial3.write((uint8_t)0); //Write 25% icon
        Serial3.write((uint8_t)1); //Write 50% icon
        Serial3.print("  "); //Write blanks over the other icon spaces
      }
      
      else if(digitalRead(Stat_Speed3) == 1){
        Serial3.write((uint8_t)0); //Write 25% icon
        Serial3.write((uint8_t)1); //Write 50% icon
        Serial3.write((uint8_t)2); //Write 75% icon
        Serial3.print(" "); //Write blanks over the other icon spaces
      }
      
      else if(digitalRead(Stat_Speed4) == 1){
        Serial3.write((uint8_t)0); //Write 25% icon
        Serial3.write((uint8_t)1); //Write 50% icon
        Serial3.write((uint8_t)2); //Write 75% icon
        Serial3.write((uint8_t)3); //Write 100% icon
      }
      
        Serial3.write(0xFE); // move the cursor
        Serial3.write(0x47);
        Serial3.write(0x01); //column
        Serial3.write(0x02); //row
        
      if(digitalRead(Stat_Battery1) == 1){
        Serial3.write((uint8_t)0);
      }
      else if(digitalRead(Stat_Battery1) == 0){
        Serial3.print(" ");
      }
      if(digitalRead(Stat_Battery2) == 1){
        Serial3.write((uint8_t)1);
      }
      else if(digitalRead(Stat_Battery2) == 0){
        Serial3.print(" ");
      }
      if(digitalRead(Stat_Battery3) == 1){
        Serial3.write((uint8_t)2);
      }
      else if(digitalRead(Stat_Battery3) == 0){
        Serial3.print(" ");
      }
      if(digitalRead(Stat_Battery4) == 1){
        Serial3.write((uint8_t)3);
      }
      else if(digitalRead(Stat_Battery4) == 0){
        Serial3.print(" ");
      }
      
      Serial3.print("        ");
      
      if(digitalRead(Stat_Headlights) == 1){
        Serial3.write((uint8_t)5); //If the headlights are on then write the icon to indicate that
      }
      else if(digitalRead(Stat_Headlights) == 0){
        Serial3.print(" "); //If the headlights are off then write a blank over that space
      }
    
      Serial3.print(" ");
    
      if(digitalRead(Stat_BatteryCharging) == 1){
        Serial3.write((uint8_t)4); //If the battery LED is on then write the icon to indicate that 
      }
      else if(digitalRead(Stat_BatteryCharging) == 0){
        Serial3.print(" "); //If the battery LED is off then write the icon to indicate that 
      }
 }
 


void scooter_lock_screen_key(){
  Serial.println("Scooter locked by Key");
    digitalWrite(relaypower, LOW);
    while(digitalRead(scooter_key) == 1){
    Serial3.write(0xFE); //Change backlight Color
    Serial3.write(0xD0);
    Serial3.write(0xFF); //R
    Serial3.write(0x00); //G
    Serial3.write(0x00); //B
    delay(10);
    Serial3.write(0xFE); //Clear the LCD
    Serial3.write(0x58);
    delay(10);
    Serial3.write(0xFE); //Set the cursor position
    Serial3.write(0x47);
    Serial3.write(0x01); //column
    Serial3.write(0x01); //row
    delay(10);
    Serial3.print(" SCOOTER LOCKED");
    delay(1500);
    Serial3.write(0xFE); //Change backlight Color
    Serial3.write(0xD0);
    Serial3.write(0xFF); //R
    Serial3.write(0x10); //G
    Serial3.write(0x00); //B
    delay(10);
    Serial3.write(0xFE); //Clear the LCD
    Serial3.write(0x58);
    delay(10);
    Serial3.write(0xFE); //Set the cursor position
    Serial3.write(0x47);
    Serial3.write(0x01); //column
    Serial3.write(0x02); //row
    delay(10);
    Serial3.print(" SCOOTER LOCKED");
    delay(1500);
    }
}


void scooter_lock_screen_remote(){
  Serial.println("Scooter locked by Remote");
    digitalWrite(relaypower, LOW);
    while(digitalRead(scooter_lock) == 0){
    Serial3.write(0xFE); //Change backlight Color
    Serial3.write(0xD0);
    Serial3.write(0xFF); //R
    Serial3.write(0x00); //G
    Serial3.write(0x00); //B
    delay(10);
    Serial3.write(0xFE); //Clear the LCD
    Serial3.write(0x58);
    delay(10);
    Serial3.write(0xFE); //Set the cursor position
    Serial3.write(0x47);
    Serial3.write(0x01); //column
    Serial3.write(0x01); //row
    delay(10);
    Serial3.print("  SYSTEM ERROR");
    delay(1500);
    Serial3.write(0xFE); //Change backlight Color
    Serial3.write(0xD0);
    Serial3.write(0xFF); //R
    Serial3.write(0x00); //G
    Serial3.write(0xFF); //B
    delay(10);
    Serial3.write(0xFE); //Clear the LCD
    Serial3.write(0x58);
    delay(10);
    Serial3.write(0xFE); //Set the cursor position
    Serial3.write(0x47);
    Serial3.write(0x01); //column
    Serial3.write(0x02); //row
    delay(10);
    Serial3.print("  SYSTEM ERROR");
    delay(1500);
    }
}
