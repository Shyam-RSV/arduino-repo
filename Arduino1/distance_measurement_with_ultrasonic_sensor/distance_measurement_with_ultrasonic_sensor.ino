// defines pins numbers
const int trigPin = 14;
const int echoPin = 12;
// defines variables
long duration;
int distance;
int motorPin = 16;
void setup() {
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(motorPin, OUTPUT);
 Serial.begin(9600); // Starts the serial communication
}
void loop() {
 // Clears the trigPin
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin, HIGH);
 // Calculating the distance
 distance = duration * 0.034 / 2;
 // Prints the distance on the Serial Monitor
 Serial.print("Distance: ");
 Serial.println(distance);
 delay(100);

if(distance > 20){
  digitalWrite(motorPin, HIGH);
  }else if(distance < 5){
    digitalWrite(motorPin, LOW);
    }else{
      delay(1); 
      }
 
} 
