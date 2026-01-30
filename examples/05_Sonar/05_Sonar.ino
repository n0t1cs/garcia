#include "garcia.h"

void setup() {
  setupGarcia();
  Serial.begin(9600);
}

void loop() {
  unsigned int dRight = sonar_right.dist_cm();
  unsigned int dLeft = sonar_left.dist_cm();

  Serial.print("Right: ");
  Serial.print(dRight);
  Serial.print(" cm  Left: ");
  Serial.print(dLeft);
  Serial.println(" cm");

  delay(200);
}
