#include "DHT.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

char pirSt[200] ;

int mq135 = A0;
int flame = 5;
int pir = 0;
float temperature ;
float humidity ;
//pirSt = "No Motion detected";
//gas = 229;


int pirState = LOW;
int val = 0;

int flameValue = 0;

#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
const char* ssid = "Shyam";
const char* password = "Shyam@12312";

const char* MQTT_username = ""; 
const char* MQTT_password = ""; 

const char* mqtt_server = "91.121.93.94";

WiFiClient espClient;
PubSubClient client(espClient);

long now = millis();
long lastMeasure = 0;

void setup_wifi() {
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
   
    if (client.connect("ESP8266Client", MQTT_username, MQTT_password)) {
      Serial.println("connected");  
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(mq135,INPUT);
pinMode(flame,INPUT);
pinMode(pir,INPUT);
dht.begin();

setup_wifi();
client.setServer(mqtt_server, 1883);
}

void loop() {
  // put your main code here, to run repeatedly:
//float gas = analogRead(mq135);
float gas = 229;

  Serial.print("gas : ");
  Serial.print(gas);
  Serial.print("   ");


 temperature = dht.readTemperature();
 humidity = dht.readHumidity();
 Serial.print("temperature  ");
 Serial.print(temperature);
 Serial.print("   ");
 Serial.print("humidity  ");
 Serial.print(humidity);
 Serial.print("   "); 

 flameValue = digitalRead(flame);
 if(flameValue == LOW){
   Serial.print("  Flame detected  ");
 }else{
   Serial.print("  No flame  ");
 }

 val = digitalRead(pir);
 if(val == HIGH){
   delay(100);
   if(pirState == LOW){
    String pirSt = "Motion Detected";
     Serial.print("   Motion Detected    ");
     pirState = HIGH;
    
   }
   
 }
 else{
   delay(200);
   if(pirState == HIGH){
     String pirSt = "No Motion";
     Serial.print("   MotionEnded   ");
     pirState = LOW;
   }
 }

 if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client", MQTT_username, MQTT_password);

  now = millis();

 // if(temperature > 33 || humidity > 55 || gas > 400 || pirSt == "Motion Detected"){
    if (now - lastMeasure > 300000) {
    lastMeasure = now;
   
     DynamicJsonDocument feed(200);
      feed["Temp"] = 29;
      feed["Humi"] = 43;
      feed["Co2"] = 229;
      feed["Pir"] = "Motion Detected";
      feed["Note"] = "Emergency";
      
      String requestBody;
      serializeJsonPretty(feed, requestBody);

      client.publish("esp/twillio", String(requestBody).c_str());
  }
  //else{
   /* if (now - lastMeasure > 21600000) {
      lastMeasure = now;

      DynamicJsonDocument feed(200);
      feed["Temp"] = temperature;
      feed["Humi"] = humidity;
      feed["Co2"] = gas;
      feed["Pir"] = pirSt;
      feed["Note"] = "Normal";

    
      String requestBody;
      client.publish("esp/twillio", String(requestBody).c_str());

  }
  }
 */
}
