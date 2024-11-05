#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
float temperature;
float humidity;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // start working...
  //Serial.println("=================================");
  //Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  //Serial.print("Sample OK: ");
  temperature = ((int)temperature); 
  humidity = ((int)humidity);

  Serial.print(temperature);
   //Serial.print(" in Celcius , ");
   Serial.print("  ");
  Serial.println(humidity);
   //Serial.print(" H");
   
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
