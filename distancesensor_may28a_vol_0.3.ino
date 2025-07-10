const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

long duration;
int distance;
int safetyDistance;


void setup() {

pinMode (trigPin, OUTPUT);    // set trigPin as an Output
pinMode (echoPin, INPUT);     // set echoPin as an Input
pinMode (buzzer, OUTPUT);     // set buzzer as an Output
pinMode (ledPin, OUTPUT);     // set ledPin as an Output
Serial.begin(9600);           // start the serial communication
}

void loop() {
// Clears the trigpin
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);

// Sets the trigpin on HIGH state for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
}
