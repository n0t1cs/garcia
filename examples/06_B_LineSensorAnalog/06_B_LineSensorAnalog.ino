#include "garcia.h"

LineSensorAnalog lineArray(LINE_S1_A, LINE_S2_A, LINE_S3_A, LINE_S4_A, LINE_S5_A, LINE_S6_A, LINE_S7_A, LINE_S8_A, ANALOG_NUMBER);

void setup()
{
    setupGarcia();
    lineArray.setupLineSensorsAnalog();
    Serial.begin(9600);
    lineArray.calibrateSensors(400);
    lineArray.PrintCalibrationResults();
}

void loop()
{
    int s1,s2,s3,s4,s5,s6,s7,s8;
    
    lineArray.readSensors(s1,s2,s3,s4,s5,s6,s7,s8);

    Serial.print(s1); Serial.print(" ");
    Serial.print(s2); Serial.print(" ");
    Serial.print(s3); Serial.print(" ");
    Serial.print(s4); Serial.print(" ");
    Serial.print(s5); Serial.print(" ");
    Serial.print(s6); Serial.print(" ");
    Serial.print(s7); Serial.print(" ");
    Serial.println(s8);

    delay(100);
}
