#include <Wire.h>  //scl-D1; sda-D2
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // I2C Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  
}

void loop() {
  digitalWrite(12, HIGH);
  Serial.println("LED ON !");
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("LED ON !");
  display.display();
  delay(2000);



  digitalWrite(12,LOW);
  Serial.println("LED OFF !");
  display.clearDisplay(); 
  display.setTextSize(2); 
  display.setCursor(0, 0);                    // Set cursor to upper left
  display.println("LED OFF !");
  display.display();
  delay(2000);

}
