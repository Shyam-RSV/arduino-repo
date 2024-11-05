const int sensor = 4;
int state;

void setup()
{
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLUP); // Setting the baud rate of GSM Module Serial.begin(9600);
  delay(100);
}

void loop()
{
  	state = digitalRead(sensor);
	
	  if (state == HIGH){

      delay(20000);
      Serial.println("AT+CMGF=1");
      delay(1000); // Delay of 1000 milli seconds or 1 second
      Serial.println("AT+CMGS=\"+919840126253\"\r"); // Replace x with mobile number
      delay(1000);
      Serial.println("DOOR OPENED - Alert!!!");
      delay(100);
      Serial.println((char) 26); // ASCII code of CTRL+Z
      delay(1000);
      while(1); //Wait forever
    }
    else{
      Serial.println("DOOR CLOSED");
      delay(1000);
    }
}