#include "garcia.h"

AnalogLineSensor lineArray(LINE_A1, LINE_A2, LINE_A3, LINE_A4,
                           LINE_A5, LINE_A6, LINE_A7, LINE_A8);

void setup()
{
    setupGarcia();
    Serial.begin(9600);
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
