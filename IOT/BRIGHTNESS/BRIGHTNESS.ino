#define BLYNK_TEMPLATE_ID "TMPLAdAn95ls"
#define BLYNK_DEVICE_NAME "LED brightness"
#define BLYNK_AUTH_TOKEN "Kd10upIZ7LaR-zcrUIwnEQL4LfcPi7g7"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
int pin =25; //This pin is only DAC
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MKYBdilza";
char pass[] = "kunaldilza01";
void setup()
{
  // Debug console
  pinMode(pin,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(pin, pinValue);
  Blynk.virtualWrite(V0, pinValue);
  Serial.print("V0 Slider value is: ");
  Serial.println(pinValue);
}
