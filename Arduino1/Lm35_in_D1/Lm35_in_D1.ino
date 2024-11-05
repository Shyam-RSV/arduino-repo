int pin_D0 = 16;

void setup() {
  Serial.begin(9600);
  pinMode(pin_D0, OUTPUT);
  }

void loop() {
  digitalWrite(pin_D0, HIGH);
  float temperature = analogRead(A0)* 0.27;
  Serial.print("Temperature is C ");
  Serial.println(temperature);
  
  delay(2000);
  }
