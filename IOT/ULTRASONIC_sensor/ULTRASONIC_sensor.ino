#define BLYNK_TEMPLATE_ID "TMPLLatQzbb0"
#define BLYNK_DEVICE_NAME "ULTRASONIC sensor"
#define BLYNK_AUTH_TOKEN "Gnv3FHlIcbxebUX4kNvCZeABxBzBtWzU"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define echoPin 2 // attach pin D2 ESP32 to pin Echo of HC-SR04
#define trigPin 4 //attach pin D4 ESP32 to pin Trig of HC-SR04
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MKYBdilza";
char pass[] = "kunaldilza01";
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with ESP32");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Blynk.virtualWrite(V0, distance); // This statement is responsible for writing distance in V0 variable in blynk app or website
  Blynk.run(); // Running blynk and connecting to the wifi and checking for ready state.
}
