#include <SoftwareSerial.h>

#include <TinyGPS.h>

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
byte cmd_throttle_write_speed[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x57, 0x41};

byte cmd_mega_read_status[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x32, 0x52, 0x41};
byte cmd_mega_write_buttons[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x57, 0x41};
byte cmd_mega_write_powerstate[] = {0x1B, code_1, code_2, code_3, code_4, code_5, 0x31, 0x57, 0x42};

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

static int lock_pin = A7; //digital pin connected to Mega for remote lock 
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
    
   /*
    if(Serial.available() > 1)
    {
      //if(Serial.read() == 49){
        //gsm.print("AT+IPR=?");
        //gsm.print('\r');
      //}
      if(Serial.read() == 50){
        gsm.print("AT+IPR?");
        gsm.print('\r');
      }
      if(Serial.read() == 49){
        gsm.print("AT+IPR=9600");
        gsm.print('\r');
      }
      if(Serial.read() == 52){
        digitalWrite(gsm_power,LOW);
        delay(1500);
        digitalWrite(gsm_power,HIGH);
      }
      if(Serial.read() == 53){
        gsm.print("ATE0");
        gsm.print('\r');
      }
      if(Serial.read() == 54){
        gsm.print("ATE0");
        gsm.print('\r');
      }
      if(Serial.read() == 55){
        gsm.print("AT+IPR?");
        gsm.print('\r');
      }
    }
     */
if (serial_gsm.available())
 Serial.write(serial_gsm.read());
if (Serial.available())
 serial_gsm.write(Serial.read());
}
 /* bool newdata = false;
  unsigned long start = millis();
  
  // Every second we print an update
  while (millis() - start < 1000)
  {
    if (feedgps())
      newdata = true;
  }
  
  gpsdump(gps);
}

static void gpsdump(TinyGPS &gps)
{
  float flat, flon;
  unsigned long age, date, time, chars = 0;
  unsigned short sentences = 0, failed = 0;
  static const float LONDON_LAT = 51.508131, LONDON_LON = -0.128002;
  
  print_int(gps.satellites(), TinyGPS::GPS_INVALID_SATELLITES, 5);
  print_int(gps.hdop(), TinyGPS::GPS_INVALID_HDOP, 5);
  gps.f_get_position(&flat, &flon, &age);
  print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 9, 5);
  print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 10, 5);
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);

  print_date(gps);

  print_float(gps.f_altitude(), TinyGPS::GPS_INVALID_F_ALTITUDE, 8, 2);
  print_float(gps.f_course(), TinyGPS::GPS_INVALID_F_ANGLE, 7, 2);
  print_float(gps.f_speed_kmph(), TinyGPS::GPS_INVALID_F_SPEED, 6, 2);
  print_str(gps.f_course() == TinyGPS::GPS_INVALID_F_ANGLE ? "*** " : TinyGPS::cardinal(gps.f_course()), 6);
  print_int(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0UL : (unsigned long)TinyGPS::distance_between(flat, flon, LONDON_LAT, LONDON_LON) / 1000, 0xFFFFFFFF, 9);
  print_float(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : TinyGPS::course_to(flat, flon, 51.508131, -0.128002), TinyGPS::GPS_INVALID_F_ANGLE, 7, 2);
  print_str(flat == TinyGPS::GPS_INVALID_F_ANGLE ? "*** " : TinyGPS::cardinal(TinyGPS::course_to(flat, flon, LONDON_LAT, LONDON_LON)), 6);

  gps.stats(&chars, &sentences, &failed);
  print_int(chars, 0xFFFFFFFF, 6);
  print_int(sentences, 0xFFFFFFFF, 10);
  print_int(failed, 0xFFFFFFFF, 9);
  Serial.println();
}

static void print_int(unsigned long val, unsigned long invalid, int len)
{
  char sz[32];
  if (val == invalid)
    strcpy(sz, "*******");
  else
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  feedgps();
}

static void print_float(float val, float invalid, int len, int prec)
{
  char sz[32];
  if (val == invalid)
  {
    strcpy(sz, "*******");
    sz[len] = 0;
        if (len > 0) 
          sz[len-1] = ' ';
    for (int i=7; i<len; ++i)
        sz[i] = ' ';
    Serial.print(sz);
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1);
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(" ");
  }
  feedgps();
}

static void print_date(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age == TinyGPS::GPS_INVALID_AGE)
    Serial.print("*******    *******    ");
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d   ",
        month, day, year, hour, minute, second);
    Serial.print(sz);
  }
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  feedgps();
}

static void print_str(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
  feedgps();
}

static bool feedgps()
{
  while (serial_gps.available())
  {
    if (gps.encode(serial_gps.read()))
      return true;
  }
  return false;
}

*/
