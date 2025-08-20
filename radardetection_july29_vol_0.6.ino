#include <Servo.h>.

const int trigPin = 10;  // trigPin for ultrasonic sensor
const int echoPin = 11;  // echoPin for ultrasonic sensor
const int buzzer = 9;    // buzzer alerts when object is detected
const int ledPin = 8;    // ledPin turns on when alert triggered

long duration;
int distance;
int safetyDistance;
Servo myServo;           // creates a servo object for controlling the servo motor
int calculateDistance();

void setup() {
pinMode (trigPin,OUTPUT);  // set trigPin as Output
pinMode (echoPin,INPUT);   // set echoPin as Input
pinMode (buzzer,OUTPUT);   // set buzzer as Output
pinMode (ledPin,OUTPUT);   // set ledPin as Output

Serial.begin (9600);       // start the serial communication
myServo.attach (12);       // servo signal is connected to pin 12

}

void loop() {
   // Sweep from left to right
   for(int i=15;i<=165;i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance(); // Calls a function for calculating the distance by the Ultrasonic sensor for each degree

    Serial.print(i); // Sends the current degrees into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing

    safetyDistance = distance;
    if(safetyDistance <= 20) {
      digitalWrite(buzzer,HIGH);
      digitalWrite(ledPin, HIGH);
      
    }
    else{
      digitalWrite(buzzer,LOW);
      digitalWrite(ledPin,LOW);
      
    }
  }

     // Sweep back to right to left
    for(int i=15;i>=165;i--) {
     myServo.write(i);
     delay(30);
     distance = calculateDistance(); // Calls a function for calculating the distance by the Ultrasonic sensor for each degree

     Serial.print(i); // Sends the current degree into the Serial Port
     Serial.print(","); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
     Serial.print(distance); // Sends the distance value into the Serial Port
     Serial.print("."); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing

     safetyDistance = distance;
     if(safetyDistance <=20) {
      digitalWrite(buzzer,HIGH);
      digitalWrite(ledPin,HIGH);
      
    }
    else{
      digitalWrite(buzzer,LOW);
      digitalWrite(ledPin,LOW);
      
    }
  }
}

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



    









 


