int pin_D2 = 4;
int pin_D0 = 16;

void setup() {
  Serial.begin(9600);
  pinMode(pin_D0, OUTPUT);
  pinMode(pin_D2, OUTPUT);
  pinMode(A0, INPUT);
  }

void loop() {
  digitalWrite(pin_D0, HIGH);
  temperature = analogRead(A0)* 0.30;
  Serial.print("Temperature is C ");
  Serial.println(temperature);
  delay(2000);
  digitalWrite(pin_D0, LOW);



  digitalWrite(pin_D2, HIGH);
  delay(5000);
  gas = ((analogRead(A0)* 3.3) / 1024)* 100;
  Serial.print("Gas in PPM ");
  Serial.println(gas);
  digitalWrite(pin_D2, LOW); 
  }
