char t;
int leftForward = 5;
int leftReverse = 6;
int rightForward = 10;
int rightReverse = 11;
 
void setup() {
pinMode(leftForward, OUTPUT);   //left motors forward
pinMode(leftReverse, OUTPUT);   //left motors reverse
pinMode(rightForward, OUTPUT);   //right motors forward
pinMode(rightReverse, OUTPUT);   //right motors reverse
//pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(leftReverse,HIGH);
  digitalWrite(rightReverse,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(rightForward ,HIGH);
  digitalWrite(leftReverse, HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(leftFoward, HIGH);
  digitalWrite(rightReverse, HIGH);
}


 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(leftForward,LOW);
  digitalWrite(leftReverse,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightReverse,LOW);
}
delay(100);
}