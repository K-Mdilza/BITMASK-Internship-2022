#define BLYNK_TEMPLATE_ID "TMPL-Yu4i3w_"
#define BLYNK_DEVICE_NAME "HOMEAUTOMATION"
#define BLYNK_AUTH_TOKEN "OFtT8jPkLDNkWe4Fx4THUgKycu8HwtqC"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht.h>

#define pin1 2 // ESP32 pin GIOP16 connected to the IN pin of relay
#define pin2 4
// the code in setup function runs only one time when ESP32 starts
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MKYBdilza";
char pass[] = "kunaldilza01";

void setup() {
  // initialize digital pin as an output.
  Serial.begin(115200);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.run();
}

BLYNK_WRITE(V2)
{
  int pinValue1 = param.asInt();
  Blynk.virtualWrite(V3,pinValue1);
  digitalWrite(pin1,pinValue1);
  Serial.println("RECEIVED");
  Serial.print(pinValue1);
//  display.setCursor(0,60);
//  display.println("L1 :"); 
//  display.print(pinValue1);
}


// the code in loop function is executed repeatedly infinitely
void loop() {
//  digitalWrite(pin1, HIGH);
//  delay(1000);
//  digitalWrite(pin1, LOW);
//  delay(1000);
//   digitalWrite(pin2, HIGH);
//  delay(1000);
//  digitalWrite(pin2, LOW);
//  delay(1000);
}
