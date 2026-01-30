/*
    * garcia.h
    * Library Header File
    * Used only for Garcia de Orta School robotics workshops (2025)
    * Created on: Dec 12, 2025
*/

#ifndef GARCIA_H
#define GARCIA_H

/*
    Includes
*/

#include <Arduino.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "TimerOne.h"

/*
    Definitions
*/

#define MOTOR_LEFT_DIR 12
#define MOTOR_LEFT_PWM 3
#define MOTOR_RIGHT_DIR 13
#define MOTOR_RIGHT_PWM 11

#define FORWARD 1
#define BACKWARD 0

#define TRIGGER_PIN_RIGHT 34
#define ECHO_PIN_RIGHT 35
#define TRIGGER_PIN_LEFT 32
#define ECHO_PIN_LEFT 33

#define LINE_S1 36
#define LINE_S2 37
#define LINE_S3 38
#define LINE_S4 39
#define LINE_S5 40

#define RGB_R 50
#define RGB_G 51
#define RGB_B 52

#define COLOR_S2 42
#define COLOR_S3 43
#define COLOR_OUT 44

#define BUZZER_PIN 45

#define LCD_ADDRESS 0x27
#define LCD_SDA 20
#define LCD_SCL 21

/* -------------------------------------------------------------------------------
    SONAR class
------------------------------------------------------------------------------- */

class SONAR
{
public:
    SONAR(int triggerPin, int echoPin);
    unsigned int dist_cm();

private:
    int triggerPin;
    int echoPin;
};


/* -------------------------------------------------------------------------------
    Line sensor class
------------------------------------------------------------------------------- */

class LineSensor
{
public:
    LineSensor(int s1Pin, int s2Pin, int s3Pin, int s4Pin, int s5Pin);
    void readSensors(bool &s1Value, bool &s2Value, bool &s3Value, bool &s4Value, bool &s5Value);

private:
    int s1Pin;
    int s2Pin;
    int s3Pin;
    int s4Pin;
    int s5Pin;
};

/*
    Function declarations
*/

void setupGarcia(); //Initialize the Garcia library
void MotorRight(int speed, bool direction); //Control the right motor
void MotorLeft(int speed, bool direction); //Control the left motor
void StopMotors(); //Stop both motors

void RGB_setColor(unsigned char R, unsigned char G, unsigned char B); //Set RGB LED color

void lcd_write(String text, int row, int column); //Write text to LCD at specified position

extern SONAR sonar_right;
extern SONAR sonar_left;

#endif // GARCIA_H
