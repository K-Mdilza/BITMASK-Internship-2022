#define BLYNK_TEMPLATE_ID "TMPLdbd1tJhG"
#define BLYNK_DEVICE_NAME "Gas detection"
#define BLYNK_AUTH_TOKEN "njlK0_NBC8vIrsoZKKEj13VbqIBPXkQL"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
int pin =33; //This pin is only DAC used because reading analog sensor from mq135
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MKYBdilza";
char pass[] = "kunaldilza01";
void setup()
{
  pinMode(pin,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void loop()
{
 int sensorValue;
  sensorValue = analogRead(pin);
  Blynk.virtualWrite(V0, sensorValue);
  Serial.print("AirQua= ");
  Serial.print(sensorValue, DEC);
  Serial.println("PPM");
  Serial.println();  
  Blynk.run();
 
}
