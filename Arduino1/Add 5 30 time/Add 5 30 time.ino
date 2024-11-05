int givhour = 15;
int givmin = 35;
int minu = 330;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int givTotalMin = (givhour*60) + givmin ;
int totalMinutes = (givTotalMin + minu);

int hours = totalMinutes / 60;
int minutes = totalMinutes % 60;
Serial.print("Hour ");
Serial.println(hours);
Serial.print("Minutes ");
Serial.println(minutes);

delay(5000);
}
