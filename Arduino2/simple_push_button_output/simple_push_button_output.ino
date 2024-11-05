int buttonPin = 5;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead (buttonPin);
  if (buttonState == 1)
  {
    Serial.println("1");
  }
  else
   {
    Serial.println("0");
    }

}
