int ledPin = 13;
int pin_D1 =5;
int tempValue = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(pin_D1,OUTPUT);
pinMode(tempValue,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin_D1,LOW);
delay(500);

  float inputValue = analogRead(tempValue);
  float temp = (inputValue / 1024.0) * 3300;
  float celsius = temp / 10;
  Serial.print("Temperature is : " );
  Serial.println(celsius);
delay(100);
digitalWrite(pin_D1,HIGH);
delay(100);

digitalWrite(ledPin,LOW);
delay(1000);
digitalWrite(ledPin,HIGH);
}
