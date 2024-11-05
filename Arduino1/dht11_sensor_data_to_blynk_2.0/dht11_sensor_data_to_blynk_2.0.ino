/*
 * This program is property of SME Dehradun. for any query related to this program, contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL_ekxw8qI"
#define BLYNK_DEVICE_NAME "dht 11"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_WEMOS_D1_MINI
#include "BlynkEdgent.h"
#include "DHT.h"
#define DHTPIN D4 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float t, h;

void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature();  
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Serial.print(t);
  Serial.print("  ");
  Serial.println(h);

 delay(1000);

  
}

void setup()
{
  Serial.begin(9600);
  dht.begin();
  BlynkEdgent.begin();
  delay(2000); 
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run(); // Initiates SimpleTimer
}
