#include <Servo.h>.
// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
 
  pinMode(trigPin, OUTPUT); // Sets trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets echoPin as an Output
  Serial.begin(9600);
  myServo.attach(12);        // Defines on which pin is the servo attached
}

void loop() {
  
  for(int i=15;i<=165;i++) {
  myServo.write(i);
  delay(30);
  distance = calculateDistance(); //Calls a function for calculating the distance by the Ultrasonic sensor for each degree

  Serial.print(i); // Sends the current degrees into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
  Serial.print(distance); // Sends the distancce value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
  }

}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration*0.034/2;
  return distance;

}
