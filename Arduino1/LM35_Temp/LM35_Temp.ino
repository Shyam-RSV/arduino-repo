int Pin_D5 = 14;
int Pin_D6 = 12;

const int LM_35 = A0;
int input_val = 0;
float temp = 0;

void setup() {
  Serial.begin(9600);


  pinMode(Pin_D5, OUTPUT);
  pinMode(Pin_D6, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {

  digitalWrite(Pin_D5, HIGH);
  delay(1000);


  input_val = analogRead(LM_35);
  temp = (input_val / 1024.0) * 3300;
  float celsius = temp / 10;
  Serial.print("Temperature is : " );
  Serial.println(celsius);

  digitalWrite(Pin_D5, LOW);


}
