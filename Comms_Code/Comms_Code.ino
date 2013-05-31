#include <SoftwareSerial.h>

#include <TinyGPS.h>

//sets the security code
#define code_1 0x01 
#define code_2 0x02
#define code_3 0x03
#define code_4 0x04
#define code_5 0x05

//sets the comparison comands
byte cmd_comms_read_location[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x52, 0x41};
byte cmd_comms_write_remotelock[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x41};
byte cmd_comms_write_cameramove[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x42};
byte cmd_comms_write_cameraheight[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x30, 0x57, 0x43};

byte cmd_throttle_read_speed[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x52, 0x41};
byte cmd_throttle_write_speed[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x57, 0x41};

byte cmd_mega_read_state[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x52, 0x41};
byte cmd_mega_write_buttons[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x57, 0x41};
byte cmd_mega_write_powerstate[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x57, 0x42};

byte cmd_lighting_read_state[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x33, 0x52, 0x41};
byte cmd_lighting_write_state[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x33, 0x57, 0x41};
byte cmd_lighting_write_mode[] = {
  0x1B, code_1, code_2, code_3, code_4, code_5, 0x33, 0x57, 0x42};

byte start_byte = 0x1B;
byte stop_byte = 0x0A;
byte inArray[18];
bool authenticated = false;

TinyGPS gps; //Create GPS device

SoftwareSerial serial_gps(9, 8); // Attach Software Serial devices
SoftwareSerial serial_gsm(10, 11);
SoftwareSerial serial_throttle(0,0);
SoftwareSerial serial_mega(0,0);
SoftwareSerial serial_camera(0,0);
SoftwareSerial serial_lighting(0,0);

static void gpsdump(TinyGPS &gps);
static bool feedgps();
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);

static int lock_pin = A7; //remote lock Mega
static int gsm_reset = A0;
static int gsm_power = A1;


void setup()
{
  pinMode(gsm_power, OUTPUT);
  digitalWrite(gsm_power, HIGH);
  pinMode(gsm_reset, OUTPUT);
  digitalWrite(gsm_reset, LOW);

  pinMode(lock_pin, OUTPUT);
  digitalWrite(lock_pin, HIGH);

  Serial.begin(9600);  
  serial_gps.begin(9600);
  serial_gsm.begin(9600);
  serial_throttle.begin(9600);
  serial_mega.begin(9600);
  serial_camera.begin(9600);
  serial_lighting.begin(9600);


  //turn on gsm module
  digitalWrite(gsm_power,LOW);
  delay(1500);
  digitalWrite(gsm_power,HIGH);
}

void loop()
{
  for(int i=0; i<18; i++) //clear the input array
  {
    inArray[i] = 0xFF;
    authenticated = false;
  }
  
  read_HW_serial(); //
  authenticate();
  process();
  
  
}

  void read_HW_serial()
  /*
  Check to see if there is data at the serial port ready to read. 
  If there is then read the first byte and check to see if it is a 
  valid start byte. If so then read 17 more bytes. Check each byte
  to make sure that it isn't a stop byte.
  If it is not a valid start byte then read teh contents of the serial
  buffer into a trash variable
  */
  {
   if(Serial.available() > 0)
    {
      byte inData = Serial.read();
      if(inData == start_byte)
      {
        int i;
        inArray[0] = inData;
        for(i=1; i<18; i++)
          inData = Serial.read();
        if(inData != stop_byte)
        {
          inArray[i] = inData;
        }
        else if(inData == stop_byte)
        {
          inArray[18] = inData;
          i = 19;
        }
      }
      else if(Serial.read() != start_byte)
      {
        while(Serial.available() > 0)
        {
          byte trash = Serial.read();
        }
      }
    }
  }
  
  
  void authenticate()
  /*
  checks bytes 1-5 of the incoming dta array to make sure 
  that the authentication code matches
  */
  {
    authenticated = false;
    if(inArray[1] == code_1){
      if(inArray[2] == code_2){
        if(inArray[3] == code_3){
          if(inArray[4] == code_4){
            if(inArray[5] == code_5){
              authenticated == true;
            }
          }
        }
      }
    }
  }
  
  void process()
  {
   /*
   Begins processing the incoming string
   */
   // Nano Commands
   if(inArray[6] == cmd_comms_read_location[6] && inArray[7] == cmd_comms_read_location[7] && inArray[8] == cmd_comms_read_location[8])
    {
      
    }
   if(inArray[6] == cmd_comms_write_remotelock[6] && inArray[7] == cmd_comms_write_remotelock[7] && inArray[8] == cmd_comms_write_remotelock[8])
    {
      
    }
   if(inArray[6] == cmd_comms_write_cameramove[6] && inArray[7] == cmd_comms_write_cameramove[7] && inArray[8] == cmd_comms_write_cameramove[8])
    {
      
    }
   if(inArray[6] == cmd_comms_write_cameraheight[6] && inArray[7] == cmd_comms_write_cameraheight[7] && inArray[8] == cmd_comms_write_cameraheight[8])
    {
      
    }
   // Throttle Commands 
   if(inArray[6] == cmd_throttle_read_speed[6] && inArray[7] == cmd_throttle_read_speed[7] && inArray[8] == cmd_throttle_read_speed[8])
    {
      
    }
   if(inArray[6] == cmd_throttle_write_speed[6] && inArray[7] == cmd_throttle_write_speed[7] && inArray[8] == cmd_throttle_write_speed[8])
    {
      
    }
   // Mega Commands 
   if(inArray[6] == cmd_mega_read_state[6] && inArray[7] == cmd_mega_read_state[7] && inArray[8] == cmd_mega_read_state[8])
    {
      
    }
   if(inArray[6] == cmd_mega_write_buttons[6] && inArray[7] == cmd_mega_write_buttons[7] && inArray[8] == cmd_mega_write_buttons[8])
    {
      
    }
   if(inArray[6] == cmd_mega_write_powerstate[6] && inArray[7] == cmd_mega_write_powerstate[7] && inArray[8] == cmd_mega_write_powerstate[8])
    {
      
    }
   // Lighting Commands 
   if(inArray[6] == cmd_lighting_read_state[6] && inArray[7] == cmd_lighting_read_state[7] && inArray[8] == cmd_lighting_read_state[8])
    {
      
    }
   if(inArray[6] == cmd_lighting_write_state[6] && inArray[7] == cmd_lighting_write_state[7] && inArray[8] == cmd_lighting_write_state[8])
    {
      
    }
   if(inArray[6] == cmd_lighting_write_mode[6] && inArray[7] == cmd_lighting_write_mode[7] && inArray[8] == cmd_lighting_write_mode[8])
    {
      
    }
  }
    

