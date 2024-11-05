#include <Wire.h>  //scl-D1; sda-D2
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

const int buttonPin1  = 16;
const int buttonPin2  = 14;
const int buttonPin3  = 12;
const int buttonPin4  = 0;
const int buttonPin5  = 2;

int R1 = 0;
int R2 = 0;
int R3 = 0;
int R4 = 0;
int R5 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
pinMode(buttonPin3, INPUT);
pinMode(buttonPin4, INPUT);
pinMode(buttonPin5, INPUT);

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
  Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }



R1_call();
R2_call();
R3_call();
R4_call();
R5_call();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}


void R1_call () {
  
while(R1 == 0){
  R1 = digitalRead(buttonPin1);
  continue;
  }
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("S");

  Serial.println("S");

  display.display();
  }


void R2_call() {  
    
while(R2 == 0){
  R2 = digitalRead(buttonPin2);
  continue;
  }
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("H");

    Serial.println("H");

  display.display();
    }


void R3_call() {
      
      
while(R3 == 0){
  R3 = digitalRead(buttonPin3);
  continue;
  }
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("Y");

    Serial.println("Y");

  display.display();
      }


void R4_call (){
        
while(R4 == 0){
  R4 = digitalRead(buttonPin4);
  continue;
  }
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("A");

    Serial.println("A");

  display.display();
        }


void R5_call () {
  
  while(R5 == 0){
  R5 = digitalRead(buttonPin5);
  continue;
  }Serial.print("S");
  display.clearDisplay(); 
  display.setTextSize(2);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("M");

    Serial.println("M");

  display.display();
  }
