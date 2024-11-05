int LM_35 = A0;
int input_val = 0;
float temp = 0;
int pin_D2 = 4;

int mq135 = A0; 
int data = 0;
int pin_D5 = 14;

bool pirState ;
int pirOut = 16;
int pin_D1 = 5;

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_D1, OUTPUT);
  pinMode(pin_D2, OUTPUT);
  pinMode(pin_D5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(pirOut, INPUT);
}

void loop() {

  digitalWrite(pin_D2,LOW);
  delay(5000);
  input_val = analogRead(LM_35);
  temp = (input_val / 1024.0) * 3300;
  float celsius = temp / 10;
  Serial.print("Temperature is : " );
  Serial.println(celsius);
  digitalWrite(pin_D2,HIGH);
  delay(1000);




  digitalWrite(pin_D5,LOW);
  delay(60000);
  data = analogRead(mq135);
  if (data > 500){
    Serial.print("HARMFULL GAS FOUND !!!!   ");
    Serial.println(data);
  }
  else
  {
     Serial.println("Air Quality : GOOD   ");
  }
  digitalWrite(pin_D5,HIGH);
  delay(100);




  digitalWrite(pin_D1,LOW);
  delay(1000);
  pirState = digitalRead(pirOut);
  Serial.print(pirState);
  if(pirState==1)
  {
    Serial.println("  Motion Detected !!!!");
    delay(5000);
  }
  else
  {
    Serial.println("  Clear....");
  }
  digitalWrite(pin_D1,HIGH);
  delay(1000);
  
}
