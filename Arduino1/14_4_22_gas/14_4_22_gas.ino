int light = 12;
int gas;
float analog = A0;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);

}
void loop() {
  gas = analogRead(analog);
  Serial.print("ANALOG :");
  Serial.println(gas);
  if (gas > 500){
  digitalWrite(light,HIGH);
  }
  else{
  digitalWrite(light,LOW);,
  }
  delay(2000);
  
  }
  
