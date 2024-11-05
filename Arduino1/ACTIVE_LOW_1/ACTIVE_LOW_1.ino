int ledD4 = 2;
int ledD2 = 4;
void setup() {
  // put your setup code here, to run once:
pinMode(ledD2, OUTPUT);
pinMode(ledD4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(ledD4, LOW);
delay(3000);
digitalWrite(ledD4, HIGH);

digitalWrite(ledD2, LOW);
delay(3000);
digitalWrite(ledD2, HIGH);

}
