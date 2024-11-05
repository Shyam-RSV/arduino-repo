
int pin1 = 5; // d1 LM35
int pin2 = 4; // d2 MQ135
int analog = A0; // A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(analog, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin1, HIGH);
delay(2000);
float temp = analogRead(analog);
float cel = (temp/4.11);
Serial.print("temperature is ");
Serial.println(cel);
digitalWrite(pin1, LOW);


digitalWrite(pin2, HIGH);
delay(10000);
int gas = analogRead(analog);
float ppm = ((gas * 3.3) / 1024)* 100; 
Serial.print("Gas Level in PPM  ");
Serial.println(ppm);
digitalWrite(pin2, LOW);

}
