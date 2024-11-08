#include <ESP8266WiFi.h>

const char* ssid     = "Shyam";
const char* password = "shyam@1231";

void setup() {
  Serial.begin(9600);

  // We start by connecting to a WiFi network
  delay(1000); //Remove after done
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  Serial.print("connecting to ");
  Serial.print("192.168.43.99");
  Serial.print(':');
  Serial.println("8081");

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect("192.168.43.99", 8081))
  {
    Serial.println("Client connect failed");
    delay(5000);
  }
   else
  {
    Serial.println("Connected");
    client.println("Medi-Track");
    Serial.println("Its Working");
    delay(5000);
    }
      
  // Close the connection

  Serial.println("closing connection");
  Serial.println();
  client.stop();

}