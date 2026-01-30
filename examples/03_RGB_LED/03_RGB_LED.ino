#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
  RGB_setColor(255, 0, 0);   // Red
  delay(500);
  RGB_setColor(0, 255, 0);   // Green
  delay(500);
  RGB_setColor(0, 0, 255);   // Blue
  delay(500);
  RGB_setColor(0, 0, 0);     // Off
  delay(500);
}
