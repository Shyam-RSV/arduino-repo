
const float referenceVolts = 5.0; // the default reference on a 5-volt board
const int batteryPin = 0;         // battery is connected to analog pin 0

void setup() 
{
Serial.begin(9600);
}

void loop()
{
  int val = analogRead(batteryPin); // read the value from the sensor 
  float volts = (val / 1023.0) * referenceVolts; // calculate the ratio
  Serial.println(volts); // print the value in volts
  delay(500);
  }