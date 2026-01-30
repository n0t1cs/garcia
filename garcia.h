/*
    * garcia.h
    * Library Header File
    * Used only for Garcia de Orta School robotic workshops in (2025)
    *  Created on: Dec 12, 2025

*/

#ifndef GARCIA_H
#define GARCIA_H

/*
    Necessary Includes
*/
#include <Arduino.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "TimerOne.h"

/*
    Necessary Definitions
*/

#define Motor_esquerdo_D 12
#define Motor_esquerdo_PWM 3
#define Motor_direito_D 13
#define Motor_direito_PWM 11

#define FRENTE 1
#define TRÁS 0

#define triggerPin_d 34
#define echoPin_d 35
#define triggerPin_e 32
#define echoPin_e 33

#define SP_S1 36
#define SP_S2 37
#define SP_S3 38
#define SP_S4 39
#define SP_S5 40

#define RGB_R 50
#define RGB_G 51
#define RGB_B 52

#define SC_S2 42
#define SC_S3 43
#define SC_OUT 44

#define BUZZER_PIN 45

#define LCD_ADDRESS 0x27
#define LCD_SDA 20
#define LCD_SCL 21

/*
    Class Declarations
*/

class SONAR
{
public:
    SONAR(int triggerPin, int echoPin);
    unsigned int dist_cm();

private:
    int triggerPin;
    int echoPin;
};

class sensor_pista
{
public:
    sensor_pista(int S1_pin, int S2_pin, int S3_pin, int S4_pin, int S5_pin);
    void ler_sensores(bool &S1_valor, bool &S2_valor, bool &S3_valor, bool &S4_valor, bool &S5_valor);

private:
    int S1_pin;
    int S2_pin;
    int S3_pin;
    int S4_pin;
    int S5_pin;
};

// class sensor_cor
// {
// public:
//     sensor_cor(int S2_pin, int S3_pin, int OUT_pin);
//     void setup_cor(String cor, unsigned long R, unsigned long G, unsigned long B, unsigned long erro);


// private:
//     int S2_pin;
//     int S3_pin;
//     int OUT_pin;
// };



/*
    Necessary Declarations
*/

void setupGarcia(); //Initialize the Garcia library 
void MotorDireito(int velocidade, bool sentido); //Control the right motor 
void MotorEsquerdo(int velocidade, bool sentido); //Control the left motor 
void PararMotores(); //Stop both motors

void RGB_setColor(unsigned char R, unsigned char G, unsigned char B); //Set RGB LED color

void lcd_escrever(String texto, int linha, int coluna); //Write text to LCD at specified position

extern SONAR sonar_d;
extern SONAR sonar_e;

#endif // GARCIA_H