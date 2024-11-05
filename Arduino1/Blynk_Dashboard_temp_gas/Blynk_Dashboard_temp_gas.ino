
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLqxlrOtjQ"
#define BLYNK_DEVICE_NAME "NodeMCU Temp Gas"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

int pin_D2 = 4;
int pin_D0 = 16;

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

float temperature;
float gas;

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(13, pinValue);
}
BLYNK_CONNECTED()
{
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, gas);  
}

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(pin_D0, OUTPUT);
  pinMode(pin_D2, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  digitalWrite(pin_D0, HIGH);
  delay(2000);
  temperature = analogRead(A0)* 0.30;
  Serial.print("Temperature is C ");
  Serial.println(temperature);
  digitalWrite(pin_D0,LOW) ;


  digitalWrite(pin_D2, HIGH);
  delay(5000);
  gas = ((analogRead(A0)* 3.3) / 1024)* 100;
  Serial.print("Gas in PPM ");
  Serial.println(gas);
  digitalWrite(pin_D2, LOW); 
  
  BlynkEdgent.run();
}
