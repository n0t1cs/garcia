/*
    * garcia.cpp
    * Library Source File
    * Used only for Garcia de Orta School robotics workshops (2025)
    * Created on: Dec 12, 2025
*/

#include "garcia.h"

// Global LCD instance shared across the library
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
SONAR sonar_right(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT);
SONAR sonar_left(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT);


/* -------------------------------------------------------------------------------
    Setup functions
------------------------------------------------------------------------------- */

void setupGarcia() {
    // Initialize Motors
    pinMode(MOTOR_LEFT_DIR, OUTPUT);
    pinMode(MOTOR_LEFT_PWM, OUTPUT);
    pinMode(MOTOR_RIGHT_DIR, OUTPUT);
    pinMode(MOTOR_RIGHT_PWM, OUTPUT);

    // Initialize Ultrasonic Sensors
    pinMode(TRIGGER_PIN_RIGHT, OUTPUT);
    pinMode(ECHO_PIN_RIGHT, INPUT);
    pinMode(TRIGGER_PIN_LEFT, OUTPUT);
    pinMode(ECHO_PIN_LEFT, INPUT);

    // Initialize Line Sensors
    pinMode(LINE_S1, INPUT);
    pinMode(LINE_S2, INPUT);
    pinMode(LINE_S3, INPUT);
    pinMode(LINE_S4, INPUT);
    pinMode(LINE_S5, INPUT);

    // Initialize RGB LED
    pinMode(RGB_R, OUTPUT);
    pinMode(RGB_G, OUTPUT);
    pinMode(RGB_B, OUTPUT);

    // Initialize Buzzer
    pinMode(BUZZER_PIN, OUTPUT);

    // Color Sensor
    pinMode(SC_S2, OUTPUT);
    pinMode(SC_S3, OUTPUT);
    pinMode(SC_OUT, INPUT);

    // Initialize LCD
    lcd.init();
    lcd.backlight();
}

/* -------------------------------------------------------------------------------
    Motor functions
------------------------------------------------------------------------------- */

void MotorRight(int speed, bool direction) {
    digitalWrite(MOTOR_RIGHT_DIR, direction);
    analogWrite(MOTOR_RIGHT_PWM, speed);
}

void MotorLeft(int speed, bool direction) {
    digitalWrite(MOTOR_LEFT_DIR, direction);
    analogWrite(MOTOR_LEFT_PWM, speed);
}

void StopMotors() {
    analogWrite(MOTOR_RIGHT_PWM, 0);
    analogWrite(MOTOR_LEFT_PWM, 0);
}


/* -------------------------------------------------------------------------------
    Sonar functions
------------------------------------------------------------------------------- */

SONAR::SONAR(int triggerPin, int echoPin) 
    : triggerPin(triggerPin), echoPin(echoPin) {
}

unsigned int SONAR::dist_cm() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // 30 ms timeout (~5 m range)
    unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

    if (duration == 0) {
        // No echo -> too far or no object
        return 0;
    }

    unsigned int distance = duration * 0.034 / 2;
    return distance;
}

/* -------------------------------------------------------------------------------
    RGB LED functions
------------------------------------------------------------------------------- */

void RGB_setColor(unsigned char R, unsigned char G, unsigned char B) {
    analogWrite(RGB_R, R);
    analogWrite(RGB_G, G);
    analogWrite(RGB_B, B);
}

/* -------------------------------------------------------------------------------
    Line sensor functions
------------------------------------------------------------------------------- */

LineSensor::LineSensor(int s1Pin, int s2Pin, int s3Pin, int s4Pin, int s5Pin)
    : s1Pin(s1Pin), s2Pin(s2Pin), s3Pin(s3Pin), s4Pin(s4Pin), s5Pin(s5Pin) {}

void LineSensor::readSensors(bool &s1Value, bool &s2Value, bool &s3Value, bool &s4Value, bool &s5Value) {
    s1Value = digitalRead(s1Pin);
    s2Value = digitalRead(s2Pin);
    s3Value = digitalRead(s3Pin);
    s4Value = digitalRead(s4Pin);
    s5Value = digitalRead(s5Pin);
}

/* -------------------------------------------------------------------------------
    LCD functions
------------------------------------------------------------------------------- */

void lcd_write(String text, int row, int column) {
    lcd.setCursor(column, row);
    lcd.print(text);
}

/* -------------------------------------------------------------------------------
    Color sensor functions
------------------------------------------------------------------------------- */
sensor_cor::sensor_cor(int S2_pin, int S3_pin, int OUT_pin)
    : S2_pin(S2_pin), S3_pin(S3_pin), OUT_pin(OUT_pin) {}


void sensor_cor::ReadColor() {
    for (int x=0; x<3; x++) {
        switch(x){
            case 0:
                digitalWrite(SC_S2, LOW);
                digitalWrite(SC_S3, LOW);
                break;
            case 1:
                digitalWrite(SC_S2, HIGH);
                digitalWrite(SC_S3, HIGH);
                break;
            case 2:
                digitalWrite(SC_S2, LOW);
                digitalWrite(SC_S3, HIGH);
                break;
            case 3:
                digitalWrite(SC_S2, HIGH);
                digitalWrite(SC_S3, LOW);
                break;
        }
        VR[x] = pulseIn(SC_OUT, LOW);
    }
} 

void sensor_cor::ShowColor() {
    Serial.print("R:");
    Serial.print(VR[0]);
    Serial.print("-G:");
    Serial.print(VR[1]);
    Serial.print("-B:");
    Serial.print(VR[2]);
    Serial.println("\n");
}
void sensor_cor::setup_cor(int cor, unsigned long R, unsigned long G, unsigned long B, unsigned long erro) {
    //Implementation for color sensor calibration
    switch(cor) {
        case 0:
            Red[0] = R;
            Red[1] = G;
            Red[2] = B;
            Red[3] = erro;
            break;
        case 1:
            Green[0] = R;
            Green[1] = G;
            Green[2] = B;
            Green[3] = erro;
            break;
        case 2:
            Blue[0] = R;
            Blue[1] = B;
            Blue[2] = G;
            Blue[3] = erro;
            break;
    }
}

int sensor_cor::isColor(int testCor) {
    switch (testCor) {
        case 0:
            if((VR[0] > Red[0] - Red[3] && VR[0] < Red[0] + Red[3]) &&  (VR[1] > Red[1] - Red[3] && VR[1] < Red[1] + Red[3]) && (VR[2] > Red[2] - Red[3] && VR[2] < Red[2] + Red[3]))
                return 1;
                else
                    return 0;
        case 1:
            if((VR[0] > Green[0] - Green[3] && VR[0] < Green[0] + Green[3]) &&  (VR[1] > Green[1] - Green[3] && VR[1] < Green[1] + Green[3]) && (VR[2] > Green[2] - Green[3] && VR[2] < Green[2] + Green[3]))
                return 1;
                else 
                    return 0;
        case 2:
            if((VR[0] > Blue[0] - Blue[3] && VR[0] < Blue[0] + Blue[3]) &&  (VR[1] > Blue[1] - Blue[3] && VR[1] < Blue[1] + Blue[3]) && (VR[2] > Blue[2] - Blue[3] && VR[2] < Blue[2] + Blue[3]))
                return 1;
                else
                    return 0;
        default:
            return 0;
    }       
}