int temperature = A0;
void setup() {
  Serial.print(9600);
  pinMode(temperature,INPUT);
}

void loop() {
  int result = 0;
result = temp(temperature);
Serial.println(result);
}

float temp(float x){
  float tempInCel = analogRead(x)*0.28;
  return tempInCel; 
  }
