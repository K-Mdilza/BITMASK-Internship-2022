#define BLYNK_TEMPLATE_ID "TMPL-Yu4i3w_"
#define BLYNK_DEVICE_NAME "HOMEAUTOMATION"
#define BLYNK_AUTH_TOKEN "OFtT8jPkLDNkWe4Fx4THUgKycu8HwtqC"

#include <Wire.h>
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MKYBdilza";
char pass[] = "kunaldilza01";
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
unsigned long delayTime;

// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT21 // DHT 21 (AM2301)
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//DHT Sensor;
uint8_t DHTPin = 27;
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;
String L1="off";
String L2="off";
#define pinL1 12
#define pinL2 14

void setup() {
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
   // init done
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
  display.setTextSize(1.75);
  display.setTextColor(WHITE);
}
void loop() {

  Humidity = dht.readHumidity();
  
  Temperature = dht.readTemperature();
  
  
  if (isnan(Humidity) || isnan(Temperature))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.println(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.println(F("°C "));
  Serial.print(F("L1 "));
  Serial.println(L1);
  Serial.print(F("L2 "));
   Serial.println(L2);
 
  display.setCursor(0,0);
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(Temperature);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(Humidity);
  display.print(" %");

   
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 45);
  display.print("L1: ");
  display.setTextSize(2);
  display.setCursor(0, 55);
  display.print(L1);
  display.print(" %");

   
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 55);
  display.print("L2: ");
  display.setTextSize(2);
  display.setCursor(0, 65);
  display.print(L2);
  display.print(" %");

  
   display.display();
  delay(10);

}
BLYNK_WRITE(V2)
{
  int i= param.asInt();
  if(i)
  {
    digitalWrite(pinL2,HIGH);
    L2= "ON";
  }
  else
  {
   digitalWrite(pinL2,LOW);
   L2= "OFF";
  }
}
BLYNK_WRITE(V3)
{
  int i= param.asInt();
  if(i)
  {
    digitalWrite(pinL2,HIGH);
    L2= "ON";
  }
  else
  {
   digitalWrite(pinL2,LOW);
   L2= "OFF";
  }
}
