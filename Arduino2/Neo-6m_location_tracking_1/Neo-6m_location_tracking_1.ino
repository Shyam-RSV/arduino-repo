#include <SoftwareSerial.h>

int Rx_pin = 4;
int Tx_pin = 5;
SoftwareSerial SerialGPS(Rx_pin, Tx_pin);

void setup()
{
  Serial.begin(9600);
  SerialGPS.begin(9600);
}

void loop()
{
  while (SerialGPS.available() > 0)
  Serial.write(SerialGPS.read());
}
