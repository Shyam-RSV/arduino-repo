int mq135 = A0; 
int data = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
data = analogRead(mq135);
  if (data > 500){
    Serial.print("HARMFULL GAS FOUND !!!!   ");
    Serial.println(data);
  }
  else
  {
     Serial.println("Air Quality : GOOD   ");
  }
}
