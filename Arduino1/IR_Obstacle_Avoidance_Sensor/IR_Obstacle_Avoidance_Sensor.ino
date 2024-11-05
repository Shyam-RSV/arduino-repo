int pinIR = 2; 

void setup(){
  Serial.begin(9600);
  pinMode(pinIR, INPUT);
  Serial.println("Detect IR Sensor");
  delay(1000);
}
void loop(){
  int IRstate = digitalRead(pinIR);
  
  if(IRstate == LOW){
    Serial.println("Detected");
    
  }
  else if(IRstate == HIGH){
     Serial.println("Not Detected");
  }
  delay(1000);
}
