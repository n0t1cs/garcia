#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
  MotorRight(180, FORWARD);
  MotorLeft(180, FORWARD);
  delay(1000);

  StopMotors();
  delay(500);

  MotorRight(180, BACKWARD);
  MotorLeft(180, BACKWARD);
  delay(1000);

  StopMotors();
  delay(1000);
}
