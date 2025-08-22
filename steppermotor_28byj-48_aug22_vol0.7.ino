#include <Stepper.h>

const int stepsPerRevolution = 2048; // Defines the number of steps per rotation
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12); // Pins entered in sequence IN1-IN2-IN3-IN4 for proper step sequence

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)

}

void loop() {
  // Rotates CW slowly at 5 RPM
  myStepper.setSpeed(5);
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // Rotates CCW quickly at 10 RPM
  myStepper.setSpeed(10);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
