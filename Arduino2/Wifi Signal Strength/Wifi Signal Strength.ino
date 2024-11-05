#include <ESP8266WiFi.h>

char ssid[] = "Shyam" ;
char pass[] = "shyam@1231";

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
delay(2000);
 Serial.println("WiFi connected");

 Serial.print("Signal Strength in db  ");
 Serial.println(WiFi.RSSI());
}

void loop() {
  // put your main code here, to run repeatedly:

}
