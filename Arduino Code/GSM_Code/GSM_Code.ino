#include <SoftwareSerial.h>
char inchar;

SoftwareSerial serial_gsm(3, 2); // RX, TX
char Str1[50];
int LED = 13;

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  serial_gsm.begin(9600);
  Str1[49] = 0x00;
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
void gsm_process()
{
  inchar=serial_gsm.read();
  //Serial.print(inchar);

  if(inchar == '%'){
    delay(2);    
    inchar=serial_gsm.read();
    //Serial.print(inchar);

    if(inchar == '$'){
      delay(2);
      inchar=serial_gsm.read();
      //Serial.print(inchar);

      if(inchar == '1'){
        delay(2);
        inchar=serial_gsm.read();
        //Serial.print(inchar);

        if(inchar == '2'){
          delay(2);
          inchar=serial_gsm.read();
          //Serial.print(inchar);

          if(inchar == '3'){
            delay(2);
            inchar=serial_gsm.read();
            //Serial.print(inchar);

            if(inchar == '5'){
              delay(2);
              inchar=serial_gsm.read();
              //Serial.print(inchar);

              if(inchar == '9'){
                delay(2);
                inchar=serial_gsm.read();
                //Serial.print(inchar);
                flash();
                if(inchar == '0') Serial.write(0x30);
                if(inchar == '1') Serial.write(0x31);
                if(inchar == '2') locate();
                //serial_gsm.println("AT+CMGDA=\"DEL ALL\""); // delete all SMS
              }
            }
          }
        }
      }
      serial_gsm.println("AT+CMGDA=\"DEL ALL\""); // delete all SMS
    }
  }
}


void loop() // run over and over
{
  //  if (Serial.available()) serial_gsm.write(Serial.read());
  if(serial_gsm.available()) gsm_process(); 
}

void locate()
{
  Serial.write(0x32);
  delay(10000);
  for(int i=0; i<49; i++)
  {
    if(Serial.available())
    {
      Str1[i] = Serial.read();
      delay(15);
    }  
    else
    {
      Str1[i] = 0x20;
      delay(15); 
    }
  }
  //Serial.println(Str1);

  serial_gsm.println("AT+CMGF=1\r");
  delay(1000);
  serial_gsm.println("AT+CMGS=\"+6421809596\"");
  delay(1000);
  serial_gsm.print("http://google.com/#q=");
  serial_gsm.println(Str1);
  delay(1000);
  serial_gsm.println((char)26);
  delay(1000);
  serial_gsm.println();
  delay(1000);
  //while(serial_gsm.available()) Serial.write(serial_gsm.read());
  serial_gsm.println("AT+CMGDA=\"DEL ALL\""); // delete all SMS
  flash();
  for(int i=0; i<49; i++)
  {
    Str1[i] = 0x20;
  }
  Str1[49] = 0x00;
  //Serial.println(Str1);
}

void flash()
{
  for(int n=0; n<6; n++)
  {
    digitalWrite(LED, !digitalRead(LED));
    delay(500);
  } 
}



