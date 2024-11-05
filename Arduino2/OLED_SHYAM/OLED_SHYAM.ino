#include <Wire.h>  //scl-D1; sda-D2
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // I2C Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer, set small font size and print 4 lines of text to display
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("SHYAM");  // Println moves the cursor down
  

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
}
//===============================================================================
//  Main
//===============================================================================
void loop() {
}
