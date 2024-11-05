void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);

}

void loop() {
  float temp = analogRead(A0) * 0.28;
  Serial.print("Temperature in C ");
  Serial.println(temp);
  delay(2000);
  

}
