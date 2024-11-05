const int sensor = 4;

int state; // 0 close - 1 open wwitch

void setup()
{
	pinMode(sensor, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
	state = digitalRead(sensor);
	
	if (state == HIGH){
		Serial.println("DOOR OPEN - ALERT"); 
	}
	else{
		Serial.println("DOOR CLOSED");
	}
	delay(200);
}

