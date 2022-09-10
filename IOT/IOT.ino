
*//https://microcontrollerslab.com/control-esp32-outputs-blynk-app-arduino-ide/
#define BLYNK_TEMPLATE_ID "TMPLaM8zWmAw"
#define BLYNK_DEVICE_NAME "LED BLINK"
#define BLYNK_AUTH_TOKEN "OVnLf4qxwTVPIWpyF1JNRL66zVd6dxmx"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 2;
char auth[] = BLYNK_AUTH_TOKEN ;       // You should get Auth Token in the Blynk App.
char ssid[] = "MKYBdilza";                    // Your Wi-Fi Credentials
char pass[] = "kunaldilza01";
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  ledcWrite(0,pinValue);
// digitalWrite(pin,pinValue);
  Serial.println("RECEIVED");
  Serial.print(pinValue);
}
void setup() { 
  pinMode(pin, OUTPUT); 
  ledcSetup(0, 12000,8);
  ledcAttatchPin(pin,0);
  //pinMode(pin, HIGH);                          
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Blynk.begin(BLYNK_AUTH_TOKEN , ssid, pass);
}
void loop(){
    Blynk.run();
}
