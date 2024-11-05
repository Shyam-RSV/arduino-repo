#define tempPin A0
double temperature;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(tempPin, INPUT);
}

void loop() {
  tempFunction();

}

void tempFunction(){
  temperature = analogRead(tempPin) * 0.29;
  Serial.print( "Temperature in C " );
  Serial.println(temperature);
  delay(2000);
  }
