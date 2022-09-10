#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht.h>

#define dht_apin 19
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
dht DHT;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

}

void loop() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    display.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.println("HI!");
  delay(3000);
//  display.startscrollright(0x00, 0x0F);
//  display.startscrolldiagright(0x00, 0x07);
//  display.display(); 
  DHT.read11(dht_apin);
  display.setCursor(0,20);
  display.println("Current humidity = "); 
  display.print(DHT.humidity);
  display.println("%  ");
  display.setCursor(0,40);
  display.println("temperature = ");
  display.print(DHT.temperature); 
  display.println("C  ");
  delay(5000);
  display.display();
  
}
