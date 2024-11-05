
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLPXV1j_P4"
#define BLYNK_DEVICE_NAME "NodeMCU"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

int temp;



BLYNK_CONNECTED()
{
  
  Blynk.virtualWrite(V1, temp);  
}

void setup()
{
  pinMode(2, OUTPUT); // Initialise digital pin 2 as an output pin
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  temp= analogRead(A0)*0.32;
  BlynkEdgent.run();
}
