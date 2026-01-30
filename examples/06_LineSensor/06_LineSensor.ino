#include "garcia.h"

LineSensor line(LINE_S1, LINE_S2, LINE_S3, LINE_S4, LINE_S5);

void setup() {
  setupGarcia();
  Serial.begin(9600);
}

void loop() {
  bool s1, s2, s3, s4, s5;
  line.readSensors(s1, s2, s3, s4, s5);

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.println(s5);

  delay(100);
}
