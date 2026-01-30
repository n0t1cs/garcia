#include "garcia.h"

ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);

void setup() {
  setupGarcia();
  Serial.begin(9600);

  // Calibration examples (replace with your measured values)
  color.setupColor(RED, 100, 120, 130, 10);
  color.setupColor(GREEN, 140, 90, 110, 10);
  color.setupColor(BLUE, 90, 110, 160, 10);
}

void loop() {
  color.readColor();
  color.showColor();

  if (color.isColor(RED)) {
    Serial.println("Detected RED");
  } else if (color.isColor(GREEN)) {
    Serial.println("Detected GREEN");
  } else if (color.isColor(BLUE)) {
    Serial.println("Detected BLUE");
  } else {
    Serial.println("Unknown color");
  }

  delay(200);
}
