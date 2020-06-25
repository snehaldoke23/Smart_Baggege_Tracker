#include "TinyGPS++.h" 
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(11,10);
TinyGPSPlus gps;

float latitude, longitude;
void setup()
{
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS start");
}

void loop()
{
 
  while(serial_connection.available())
  {
    
    gps.encode(serial_connection.read());
    Serial.println("GPS available");

  if(gps.location.isUpdated())
  {
   Serial.println("GPS updated"); 
    Serial.begin(9600);
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    Serial.print("AT+CMGS=\"+917769086933\"\r");
    Serial.print("I'm lost!Please help me im here");
    Serial.print("www.google.com.ph/maps/place/");
    Serial.print(gps.location.lat(),6);
    Serial.print(",");
    Serial.print(gps.location.lng(),6);
    Serial.print("\r");
    delay(1000);                               
    Serial.print((char)26);
    delay(1000);  
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A); 
  }
}
}
