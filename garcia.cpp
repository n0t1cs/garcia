/* 
    * garcia.cpp
    * Library Source File
    * Used only for Garcia de Orta School robotic workshops in (2025)
    *  Created on: Dec 12, 2025
*/

#include "garcia.h"

// Global LCD instance shared across the library
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
SONAR sonar_d(triggerPin_d, echoPin_d);
SONAR sonar_e(triggerPin_e, echoPin_e);

void setupGarcia() {
    // Initialize Motors
    pinMode(Motor_esquerdo_D, OUTPUT);
    pinMode(Motor_esquerdo_PWM, OUTPUT);
    pinMode(Motor_direito_D, OUTPUT);
    pinMode(Motor_direito_PWM, OUTPUT);

    // Initialize Ultrasonic Sensors
    pinMode(triggerPin_d, OUTPUT);
    pinMode(echoPin_d, INPUT);
    pinMode(triggerPin_e, OUTPUT);
    pinMode(echoPin_e, INPUT);

    // Initialize Line Sensors
    pinMode(SP_S1, INPUT);
    pinMode(SP_S2, INPUT);
    pinMode(SP_S3, INPUT);
    pinMode(SP_S4, INPUT);
    pinMode(SP_S5, INPUT);
    
    pinMode(SP_L, INPUT);
    pinMode(SP_C, INPUT);
    pinMode(SP_R, INPUT);
    // Initialize RGB LED
    pinMode(RGB_R, OUTPUT);
    pinMode(RGB_G, OUTPUT);
    pinMode(RGB_B, OUTPUT);

    // Color Sensor
    pinMode(SC_S2, OUTPUT);
    pinMode(SC_S3, OUTPUT);
    pinMode(SC_OUT, INPUT);

    // Initialize Buzzer
    pinMode(BUZZER_PIN, OUTPUT);

    // Initialize LCD
    lcd.init();
    lcd.backlight();
}

void MotorDireito(int velocidade, bool sentido) {
    digitalWrite(Motor_direito_D, sentido);
    analogWrite(Motor_direito_PWM, velocidade);
}

void MotorEsquerdo(int velocidade, bool sentido) {
    digitalWrite(Motor_esquerdo_D, sentido);
    analogWrite(Motor_esquerdo_PWM, velocidade);
}

void PararMotores() {
    analogWrite(Motor_direito_PWM, 0);
    analogWrite(Motor_esquerdo_PWM, 0);
}

SONAR::SONAR(int triggerPin, int echoPin) 
    : triggerPin(triggerPin), echoPin(echoPin) {
}

unsigned int SONAR::dist_cm() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // timeout de 30ms (equivale a ~5m)
    unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

    if (duration == 0) {
        // Sem eco -> demasiado longe ou sem objeto
        return 0;
    }

    unsigned int distancia = duration * 0.034 / 2;
    return distancia;
}

void RGB_setColor(unsigned char R, unsigned char G, unsigned char B) {
    analogWrite(RGB_R, R);
    analogWrite(RGB_G, G);
    analogWrite(RGB_B, B);
}

sensor_pista::sensor_pista(int S1_pin, int S2_pin, int S3_pin, int S4_pin, int S5_pin) 
    : S1_pin(S1_pin), S2_pin(S2_pin), S3_pin(S3_pin), S4_pin(S4_pin), S5_pin(S5_pin) {}

void sensor_pista::ler_sensores(bool &S1_valor, bool &S2_valor, bool &S3_valor, bool &S4_valor, bool &S5_valor) {
    S1_valor = digitalRead(S1_pin);
    S2_valor = digitalRead(S2_pin);
    S3_valor = digitalRead(S3_pin);
    S4_valor = digitalRead(S4_pin);
    S5_valor = digitalRead(S5_pin);
}

// sensor_pista::sensor_pista(int L_pin, int C_pin, int R_pin) 
//     : L_pin(L_pin), C_pin(C_pin), R_pin(R_pin) {}

// // Read function for 3 pins
// void sensor_pista::ler_sensores(bool &L_val, bool &C_val, bool &R_val) {
//     L_val = digitalRead(L_pin);
//     C_val = digitalRead(C_pin);
//     R_val = digitalRead(R_pin);
// }

void lcd_escrever(String texto, int linha, int coluna) {
    lcd.setCursor(coluna, linha);
    lcd.print(texto);
}

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
