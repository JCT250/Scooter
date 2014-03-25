#include <SoftwareSerial.h>
char inchar;

SoftwareSerial serial_gsm(3, 2); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  serial_gsm.begin(9600);
}
void gsm_process()
{
  inchar=serial_gsm.read();

  if(inchar == '%'){
    delay(2);
    inchar=serial_gsm.read();

    if(inchar == '$'){
      delay(2);
      inchar=serial_gsm.read();

      if(inchar == '1'){
        delay(2);
        inchar=serial_gsm.read();

        if(inchar == '2'){
          delay(2);
          inchar=serial_gsm.read();

          if(inchar == '3'){
            delay(2);

            if(inchar == '5'){
              delay(2);
              inchar=serial_gsm.read();

              if(inchar == '9'){
                delay(2);
                inchar=serial_gsm.read();

                if(inchar == '0') Serial.write(0x30);
                if(inchar == '1') Serial.write(0x31);
                if(inchar == '2') locate;
                serial_gsm.println("AT+CMGDA=\"DEL ALL\""); // delete all SMS
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
  serial_gsm.print("AT+CMGF=1\r");
  delay(100);
  serial_gsm.println("AT + CMGS = \"+6421809596\" ");
  delay(100);
  serial_gsm.println("this is the text");
  delay(100);
  serial_gsm.println((char)26);
  delay(100);
  serial_gsm.println();
  delay(100);  
}


