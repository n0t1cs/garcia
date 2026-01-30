# Garcia Robotics Library

Library maintained by the Garcia da Orta School Robotics Team.

## Overview
This library provides a simple API to control common robot components used in the Garcia da Orta School robotics workshops. It includes helpers for motors, ultrasonic sensors, line sensors, RGB LED control, and LCD output.

## Features
- Motor control (left/right, speed and direction)
- Ultrasonic distance measurement (SONAR)
- Line sensor reading (5-channel)
- RGB LED color control
- LCD text output

## Library Structure
- `garcia.h` / `garcia.cpp`: core library source
- `examples/`: Arduino example sketches

## Examples Folder
Ready-to-run sketches are included in `examples/`:
- `examples/01_BasicSetup/01_BasicSetup.ino`
- `examples/02_Motors/02_Motors.ino`
- `examples/03_RGB_LED/03_RGB_LED.ino`
- `examples/04_LCD/04_LCD.ino`
- `examples/05_Sonar/05_Sonar.ino`
- `examples/06_LineSensor/06_LineSensor.ino`
- `examples/07_ColorSensor/07_ColorSensor.ino`

## Quick Start
1. Place this folder in your Arduino `libraries` directory.
2. Restart the Arduino IDE.
3. Include the library in your sketch:

```cpp
#include "garcia.h"
```

4. Call `setupGarcia()` inside `setup()`.

## API Summary
- `setupGarcia()`
- `MotorRight(speed, direction)`
- `MotorLeft(speed, direction)`
- `StopMotors()`
- `RGB_setColor(R, G, B)`
- `lcd_write(text, row, column)`
- `SONAR` class: `dist_cm()`
- `LineSensor` class: `readSensors(...)`
- `ColorSensor` class: `readColor()`, `showColor()`, `setupColor(...)`, `isColor(...)`

## Code Examples
Each snippet is ready to copy and paste into an Arduino sketch.

### setupGarcia()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
}
```

### MotorRight(), MotorLeft(), StopMotors()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
  MotorRight(180, FORWARD);
  MotorLeft(180, FORWARD);
  delay(1000);

  StopMotors();
  delay(500);

  MotorRight(180, BACKWARD);
  MotorLeft(180, BACKWARD);
  delay(1000);

  StopMotors();
  delay(1000);
}
```

### RGB_setColor()
```cpp
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
```

### lcd_write()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  lcd_write("Hello!", 0, 0);
  lcd_write("Garcia Robot", 1, 0);
}

void loop() {
}
```

### SONAR::dist_cm()
```cpp
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
```

### LineSensor::readSensors()
```cpp
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
```

### ColorSensor
```cpp
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
```

## Notes
- Pin assignments are defined in `garcia.h`.
- Direction constants: `FORWARD` and `BACKWARD`.

## License
Add your preferred license here.

---

# Biblioteca Garcia Robotics (Português)

Biblioteca mantida pela Equipa de Robotica da Escola Garcia da Orta.

## Visao geral
Esta biblioteca fornece uma API simples para controlar componentes comuns de robots usados nas oficinas de robotica da Escola Garcia da Orta. Inclui funcoes para motores, sensores ultrassonicos, sensores de linha, controlo de LED RGB e saida no LCD.

## Funcionalidades
- Controlo de motores (esquerdo/direito, velocidade e direcao)
- Medicao de distancia com ultrassons (SONAR)
- Leitura de sensor de linha (5 canais)
- Controlo de LED RGB
- Escrita no LCD

## Estrutura da biblioteca
- `garcia.h` / `garcia.cpp`: codigo principal da biblioteca
- `examples/`: exemplos Arduino

## Pasta de exemplos
Os sketches prontos a usar estao em `examples/`:
- `examples/01_BasicSetup/01_BasicSetup.ino`
- `examples/02_Motors/02_Motors.ino`
- `examples/03_RGB_LED/03_RGB_LED.ino`
- `examples/04_LCD/04_LCD.ino`
- `examples/05_Sonar/05_Sonar.ino`
- `examples/06_LineSensor/06_LineSensor.ino`
- `examples/07_ColorSensor/07_ColorSensor.ino`

## Inicio rapido
1. Coloca esta pasta no diretorio `libraries` do Arduino.
2. Reinicia o Arduino IDE.
3. Inclui a biblioteca no teu sketch:

```cpp
#include "garcia.h"
```

4. Chama `setupGarcia()` dentro de `setup()`.

## Resumo da API
- `setupGarcia()`
- `MotorRight(speed, direction)`
- `MotorLeft(speed, direction)`
- `StopMotors()`
- `RGB_setColor(R, G, B)`
- `lcd_write(text, row, column)`
- Classe `SONAR`: `dist_cm()`
- Classe `LineSensor`: `readSensors(...)`
- Classe `ColorSensor`: `readColor()`, `showColor()`, `setupColor(...)`, `isColor(...)`

## Exemplos de codigo
Cada snippet esta pronto para copiar e colar num sketch Arduino.

### setupGarcia()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
}
```

### MotorRight(), MotorLeft(), StopMotors()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
  MotorRight(180, FORWARD);
  MotorLeft(180, FORWARD);
  delay(1000);

  StopMotors();
  delay(500);

  MotorRight(180, BACKWARD);
  MotorLeft(180, BACKWARD);
  delay(1000);

  StopMotors();
  delay(1000);
}
```

### RGB_setColor()
```cpp
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
```

### lcd_write()
```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  lcd_write("Hello!", 0, 0);
  lcd_write("Garcia Robot", 1, 0);
}

void loop() {
}
```

### SONAR::dist_cm()
```cpp
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
```

### LineSensor::readSensors()
```cpp
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
```

### ColorSensor
```cpp
#include "garcia.h"

ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);

void setup() {
  setupGarcia();
  Serial.begin(9600);

  // Exemplos de calibracao (substituir pelos teus valores)
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
```

## Notas
- As atribuicoes de pinos estao em `garcia.h`.
- Constantes de direcao: `FORWARD` e `BACKWARD`.

## Licenca
Adiciona aqui a licenca que preferires.
