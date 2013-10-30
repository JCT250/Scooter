#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define remote_lock 1

//sets the security code
#define code_1 0x01 
#define code_2 0x02
#define code_3 0x03
#define code_4 0x04
#define code_5 0x05

//sets the comparison comands
byte cmd_comms_read_location[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x52, 0x41};
byte cmd_comms_write_remotelock[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x41};
byte cmd_comms_write_cameramove[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x42};
byte cmd_comms_write_cameraheight[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x43};

byte cmd_throttle_read_speed[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x52, 0x41};
byte cmd_throttle_write[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x57, 0x41};

byte cmd_mega_read[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x52};
byte cmd_mega_write[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x57};


byte cmd_lighting_write[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x33, 0x57};

int remote_lock_state = 0;

byte start_byte = 0x1B;
byte stop_byte = 0x0A;
byte inArray[18];
byte inData;
bool authenticated = false; //flag determining whether the incoming string has been authenticated
bool new_data = false; //flag determining whether there is new data to read

TinyGPS gps; //Create GPS device

SoftwareSerial serial_gps(9, 8); // Attach Software Serial devices
SoftwareSerial serial_gsm(11, 10);
SoftwareSerial serial_throttle(13,12);
SoftwareSerial serial_mega(4, 5);
SoftwareSerial serial_camera(0,0);
SoftwareSerial serial_lighting(7,6);

static void gpsdump(TinyGPS &gps);
static bool feedgps();
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);

static int lock_pin = A5; //remote lock signal connected to Mega
static int gsm_reset = A0;
static int gsm_power = A1;


void setup()
{
  pinMode(gsm_power, OUTPUT);
  digitalWrite(gsm_power, HIGH);
  pinMode(gsm_reset, OUTPUT);
  digitalWrite(gsm_reset, LOW);

  pinMode(lock_pin, OUTPUT);
	remote_lock_state = EEPROM.read(remote_lock); //read the remote lock state from the EEPROM and load it into a variable
	digitalWrite(lock_pin,remote_lock_state);

  Serial.begin(9600);  
  serial_gps.begin(9600);
  serial_gsm.begin(9600);
  serial_throttle.begin(9600);
  serial_mega.begin(9600);
  serial_camera.begin(9600);
  serial_lighting.begin(9600);
  Serial.println("Serial connections opened");

  //turn on gsm module
  digitalWrite(gsm_power,LOW);
  delay(1500);
  digitalWrite(gsm_power,HIGH);
  Serial.println("Entering Loop");
}

void loop()
{
  for(int i=0; i<18; i++) //clear the input array
  {
    inArray[i] = 0xFF;
  }
  inArray[0] = 0x00;
    authenticated = false;
    new_data = false;
  read_HW_serial(); //
  if(new_data == true)
  {
    authenticate();
    process();
  }
  serial_gsm_receive();
}

void serial_gsm_receive()
{
	serial_gsm.listen();
	if(serial_gsm.available())
	{
		inData = serial_gsm.read();
		if(inData == 0x30)
		{
			digitalWrite(lock_pin, HIGH);
			EEPROM.write(remote_lock,1);
			Serial.println("GSM Remote Unlock");
		}
		if(inData == 0x31)
		{
			digitalWrite(lock_pin, LOW);
			EEPROM.write(remote_lock,0);
			Serial.println("GSM Remote Lock");
		}
		if(inData == 0x32)
		{
			Serial.println("I should send GPS stuff here");
		}
	}
}


void read_HW_serial()
/*
  Check to see if there is data at the serial port ready to read. 
 If there is then read the first byte and check to see if it is a 
 valid start byte. If so then read 17 more bytes. Check each byte
 to make sure that it isn't a stop byte.
 If it is not a valid start byte then read the contents of the serial
 buffer into a trash variable
 */
{
  if(Serial.available() > 17)
  {
    inData = Serial.read();
	if(inData!= start_byte)
	{
		while(Serial.available() && inData != start_byte)
		{
			inData = Serial.read();
		}
	}
    if(inData == start_byte)
    {
      int i;
      inArray[0] = inData;
      for(i=1; i<18; i++)
      {
        inData = Serial.read();
        if(inData != stop_byte)
        {
          inArray[i] = inData;
        }
      }
      new_data = true;
    }
    else if(Serial.read() != start_byte)
    {
      while(Serial.available() > 0)
      {
        byte trash = Serial.read();
      }
    }
    Serial.print("Recieved: ");
    int i;
    for(i=0; i<18; i++)
    {
      Serial.print(inArray[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
}


void authenticate()
/*
  checks bytes 1-5 of the incoming dta array to make sure 
 that the authentication code matches
 */
{
  authenticated = false;
  if(inArray[1] == code_1 && inArray[2] == code_2 && inArray[3] == code_3 && inArray[4] == code_4 && inArray[5] == code_5)
  {
    authenticated = true;
    Serial.println("Authenticated");
  }
  else{
    Serial.println("Authentication Error");
  }
}

void process()
{
  /*
   Begins processing the incoming string
   */
  // Nano Commands

    if(authenticated == true){
    Serial.println("Processing");
    if(inArray[6] == cmd_comms_read_location[6] && inArray[7] == cmd_comms_read_location[7] && inArray[8] == cmd_comms_read_location[8])
    {
      if(inArray[9] == 0x43)
      {
        serial_gps.listen();
        bool new_gps_data = false;
        unsigned long gps_chars;
        unsigned short gps_sentences, gps_failed ;

        // For one second we parse GPS data and report some key values
        for (unsigned long start = millis(); millis() - start < 1000;)
        {
          while (serial_gps.available())
          {
            char c = serial_gps.read();
            if (gps.encode(c)) // Did a new valid sentence come in?
              new_gps_data = true;
          }
        }

        if (new_gps_data)
        {
          float flat, flon;
          unsigned long age;
          gps.f_get_position(&flat, &flon, &age);
          Serial.print("LAT=");
          Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
          Serial.print(" LON=");
          Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
          Serial.print(" SAT=");
          Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
          Serial.print(" SPEED=");
          Serial.print(gps.f_speed_kmph());
          Serial.print(" PREC=");
          Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
        }

        gps.stats(&gps_chars, &gps_sentences, &gps_failed);
        Serial.print(" CHARS=");
        Serial.print(gps_chars);
        Serial.print(" SENTENCES=");
        Serial.print(gps_sentences);
        Serial.print(" CSUM ERR=");
        Serial.println(gps_failed);
      }
    }
    if(inArray[6] == cmd_comms_write_remotelock[6] && inArray[7] == cmd_comms_write_remotelock[7] && inArray[8] == cmd_comms_write_remotelock[8])
    {
      if(inArray[9] == 0x31)
      {
        digitalWrite(lock_pin, LOW);
		EEPROM.write(remote_lock,0);
        Serial.println("Remote Lock");
      }
      if(inArray[9] == 0x30)
      {
        digitalWrite(lock_pin, HIGH);
		EEPROM.write(remote_lock,1);
        Serial.println("Remote Unlock");
      }
    }

	//Camera Commands
    if(inArray[6] == cmd_comms_write_cameramove[6] && inArray[7] == cmd_comms_write_cameramove[7] && inArray[8] == cmd_comms_write_cameramove[8]) //Move the camera around
    {
      int i;
      for(i=9; i<16; i++){
        serial_camera.print(inArray[i]);
      }
    }
    if(inArray[6] == cmd_comms_write_cameraheight[6] && inArray[7] == cmd_comms_write_cameraheight[7] && inArray[8] == cmd_comms_write_cameraheight[8]) //Change the camera height
    {

    }

    // Throttle Commands 
    if(inArray[6] == cmd_throttle_read_speed[6] && inArray[7] == cmd_throttle_read_speed[7] && inArray[8] == cmd_throttle_read_speed[8]) //Read the currect speed being output from the throttle Nano
    {
      serial_throttle.listen();
      byte inData = 0x00;
      delay(200);

      if(serial_throttle.available()){ //if there is enough data in the buffer
        Serial.println("Data available");
        Serial.println(serial_throttle.read());
      }
      serial_gps.listen();
    }

    if(inArray[6] == cmd_throttle_write[6] && inArray[7] == cmd_throttle_write[7] && inArray[8] == cmd_throttle_write[8]) //Write a new speed to the throttle Nano
    {
      serial_throttle.listen();
      serial_throttle.write(inArray[9]);
      serial_gps.listen();
    }

    // Mega Commands 
    if(inArray[6] == cmd_mega_read[6] && inArray[7] == cmd_mega_read[7])
    {
      serial_mega.listen();
      serial_mega.write(start_byte); //send to the mega the command to read the led states
      serial_mega.write(inArray[7]);
      serial_mega.write(inArray[8]);
      serial_mega.write(inArray[9]);
      serial_mega.write(inArray[10]);
      serial_mega.write(inArray[11]);
      serial_mega.write(inArray[12]);
      serial_mega.write(inArray[13]);
      serial_mega.write(inArray[14]);
      serial_mega.write(inArray[15]);
      serial_mega.write(inArray[16]);
      delay(1000); //then wait for it to process

      byte inData = 0x00;
      delay(1000);

      if(serial_mega.available()>5){ //if there is enough data in the buffer

        while(inData != start_byte) //while inData is not the start byte
		{
			inData = serial_mega.read(); //read from the buffer and store as inData
		}
		if(inData != stop_byte) //if inData is not the stop byte
		{
			while(inData != stop_byte) //then while it's not
			{
				Serial.write(inData); //write the value to the computer via the hardware serial port
				inData = serial_mega.read(); //and read the next value in the buffer
			}
        }
        Serial.println(" ");
      }
      serial_gps.listen();
    }

	if(inArray[6] == cmd_mega_write[6] && inArray[7] == cmd_mega_write[7]) //Writing button presses to the Mega. The string from the computer will already be in the correct format to be processed by the Mega so all we need to do is fwrd it on
    {
      serial_mega.listen();
      serial_mega.write(start_byte);
      serial_mega.write(inArray[7]);
      serial_mega.write(inArray[8]);
      serial_mega.write(inArray[9]);
      serial_mega.write(inArray[10]);
      serial_mega.write(inArray[11]);
      serial_mega.write(inArray[12]);
      serial_mega.write(inArray[13]);
      serial_mega.write(inArray[14]);
      serial_mega.write(inArray[15]);
      serial_mega.write(inArray[16]);
      serial_gps.listen();
    }

    // Lighting Commands 
    if(inArray[6] == cmd_lighting_write[6] && inArray[7] == cmd_lighting_write[7]) //Controlling the lighting, the second byte determines whether we are changing the mode or the state, the second one is the new mode / state
    {
      serial_lighting.listen();
      serial_lighting.write(start_byte);
      serial_lighting.write(inArray[8]);
      serial_lighting.write(inArray[9]);
      serial_gps.listen();
    }
  }
}








