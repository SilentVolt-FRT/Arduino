#include <AccelStepper.h>
#define MotorInterfaceType 4  // Define step constant

AccelStepper myStepper(MotorInterfaceType, 9, 10, 11, 12); // Pins entered in sequence IN1-IN2-IN3-IN4 for proper step sequence

void setup() {
  
  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(50.0);
  myStepper.setSpeed(200);
  myStepper.moveTo(2048);
}

void loop(){
  // Change direction once the motor reaches target position
  if (myStepper.distanceToGo() == 0)
    myStepper.moveTo(-myStepper.currentPosition());
  // Move the motor one step
  myStepper.run();
}



