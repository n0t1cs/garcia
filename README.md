# Garcia Library

Arduino library for the Garcia da Orta robotics workshop robot.

This README is intentionally detailed and beginner-friendly.

Contents:

1. English documentation
2. Documentacao em Portugues

---

# English Documentation

## 1. What This Library Is

`Garcia Library` is an Arduino library created for the Garcia da Orta School robotics workshops. It groups the robot hardware into simple functions and classes so students can control the robot without having to write low-level pin code every time.

The current library version in [`library.properties`](library.properties) is `1.1.0`.

The latest source code currently supports:

- Two DC motors
- Two ultrasonic distance sensors
- One 5-sensor digital line sensor
- One 8-sensor QTR sensor array helper
- One RGB LED
- One 16x2 I2C LCD
- One color sensor
- One buzzer pin initialization

Important: this library was written for a specific workshop robot. It is not a generic robotics framework for every Arduino board and every wiring layout.

## 2. Who This README Is For

This README was written for people who:

- Are new to Arduino
- Are new to coding
- Need to understand what each function does
- Want step-by-step setup instructions
- Want example code they can start from

If you are completely new, read these sections first:

1. What You Need Before Starting
2. Hardware and Board Assumptions
3. Installation
4. Arduino Basics for Beginners
5. Your First Program

## 3. What You Need Before Starting

Before using this library, you should have:

- Arduino IDE installed on your computer
- The `garcia` library folder inside your Arduino `libraries` folder
- The external dependency libraries installed
- A workshop robot wired like the pin map in [`src/garcia.h`](src/garcia.h), or your own edited pin map
- A compatible board with enough pins

## 4. Hardware and Board Assumptions

The pin numbers in [`src/garcia.h`](src/garcia.h) use high digital pin numbers such as `32`, `34`, `50`, `51`, and `52`, plus analog pins `A0` to `A7`.

That means this library is designed for an Arduino Mega style board, or another compatible board with the same available pins.

If you try to use this library on an Arduino Uno or Nano without changing the pin map, it will not work correctly because those boards do not have all of these pins.

If your robot is wired differently:

1. Open [`src/garcia.h`](src/garcia.h)
2. Find the `#define` pin constants
3. Change them to match your robot wiring
4. Compile and upload again

## 5. Default Pin Map

The current library code uses the following default pin map:

| Hardware | Pin details |
| --- | --- |
| Left motor | `MOTOR_LEFT_DIR = 12`, `MOTOR_LEFT_PWM = 3` |
| Right motor | `MOTOR_RIGHT_DIR = 13`, `MOTOR_RIGHT_PWM = 11` |
| Right sonar | `TRIGGER_PIN_RIGHT = 34`, `ECHO_PIN_RIGHT = 35` |
| Left sonar | `TRIGGER_PIN_LEFT = 32`, `ECHO_PIN_LEFT = 33` |
| Digital line sensor | `LINE_S1 = 36`, `LINE_S2 = 37`, `LINE_S3 = 38`, `LINE_S4 = 39`, `LINE_S5 = 40` |
| Extra line position constants | `LINE_LEFT = 7`, `LINE_CENTER = 6`, `LINE_RIGHT = 5` |
| RGB LED | `RGB_R = 50`, `RGB_G = 51`, `RGB_B = 52` |
| Color sensor | `COLOR_S2 = 42`, `COLOR_S3 = 43`, `COLOR_OUT = 44` |
| Buzzer | `BUZZER_PIN = 45` |
| LCD | `LCD_ADDRESS = 0x27`, `LCD_SDA = 20`, `LCD_SCL = 21` |
| Analog sensor array | `LINE_S1_A = A0` to `LINE_S8_A = A7` |
| QTR emitter | `EMITTER_PIN = 2` |

## 6. External Dependencies

The current source code includes these libraries:

- `Wire`
- `LiquidCrystal_I2C`
- `TimerOne`
- `QTRSensors`

For most Arduino setups:

- `Wire` is included with Arduino already
- `LiquidCrystal_I2C`, `TimerOne`, and `QTRSensors` usually need to be installed through Library Manager

Even though `TimerOne` is not part of the public API, it is included by the header, so it should be installed to avoid compilation problems.

## 7. Installation

### 7.1 Install the Garcia library

1. Close the Arduino IDE if it is open.
2. Copy the `garcia` folder into your Arduino `libraries` directory.
3. Open the Arduino IDE again.

Typical Arduino library folder example:

```text
Documents/Arduino/libraries/garcia
```

### 7.2 Install the dependency libraries

In the Arduino IDE:

1. Open `Sketch`
2. Open `Include Library`
3. Open `Manage Libraries...`
4. Search for `LiquidCrystal_I2C`
5. Install it
6. Search for `QTRSensors`
7. Install it
8. Search for `TimerOne`
9. Install it

### 7.3 Check that the library is visible

In the Arduino IDE:

1. Open `File`
2. Open `Examples`
3. Look for the Garcia library examples

If you can open the example sketches, the library is installed correctly.

## 8. Arduino Basics for Beginners

If you have never programmed Arduino before, these are the most important ideas:

### 8.1 What is a sketch?

A sketch is your Arduino program. It is usually a `.ino` file.

### 8.2 What is `#include "garcia.h"`?

This line tells Arduino to load the Garcia library so your sketch can use its functions and classes.

```cpp
#include "garcia.h"
```

### 8.3 What is `setup()`?

`setup()` runs one time when the board starts.

You normally use it to:

- Initialize the library
- Start serial communication
- Configure sensors

### 8.4 What is `loop()`?

`loop()` runs again and again forever while the board is powered.

You normally use it to:

- Read sensors
- Control motors
- Update LEDs or the LCD
- Make robot decisions

### 8.5 What is `Serial.begin(9600)`?

This starts communication with your computer so you can print messages to the Serial Monitor.

This is very useful for beginners because it lets you see sensor values and debug problems.

### 8.6 What is calibration?

Calibration means measuring real values from your own robot and saving them so the robot can recognize a line or a color more reliably.

Calibration is especially important for:

- `LineSensorAnalog`
- `ColorSensor`

## 9. Your First Program

Start with this simple sketch:

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
}
```

### 9.1 What this program does

- Loads the Garcia library
- Initializes the robot hardware
- Does nothing else yet

### 9.2 Why `setupGarcia()` is important

`setupGarcia()` prepares the hardware pins used by the library.

In the current code, it initializes:

- Motor pins
- Ultrasonic sensor pins
- Digital line sensor pins
- RGB LED pins
- Buzzer pin
- Color sensor pins
- 8 analog line sensor pins
- LCD

If you forget to call `setupGarcia()`, many parts of the library may not work correctly.

## 10. Complete API Reference

This section explains the public API that exists in the current code.

### 10.1 `setupGarcia()`

Purpose:

- Initializes the robot hardware used by the library

Syntax:

```cpp
setupGarcia();
```

Parameters:

- None

Returns:

- Nothing

Important notes:

- Call it inside `setup()`
- Call it before using motors, sensors, RGB LED, LCD, or color sensor helpers

Example:

```cpp
void setup() {
  setupGarcia();
}
```

### 10.2 `MotorRight(int speed, bool direction)`

Purpose:

- Controls the right motor

Syntax:

```cpp
MotorRight(speed, direction);
```

Parameters:

- `speed`: PWM speed value, usually from `0` to `255`
- `direction`: use `FORWARD` or `BACKWARD`

Returns:

- Nothing

Important notes:

- `0` means stopped
- `255` means maximum PWM value
- The motor keeps running until you change the speed or call `StopMotors()`

Example:

```cpp
MotorRight(180, FORWARD);
```

### 10.3 `MotorLeft(int speed, bool direction)`

Purpose:

- Controls the left motor

Syntax:

```cpp
MotorLeft(speed, direction);
```

Parameters:

- `speed`: PWM speed value, usually from `0` to `255`
- `direction`: use `FORWARD` or `BACKWARD`

Returns:

- Nothing

Example:

```cpp
MotorLeft(180, BACKWARD);
```

### 10.4 `StopMotors()`

Purpose:

- Stops both motors

Syntax:

```cpp
StopMotors();
```

Parameters:

- None

Returns:

- Nothing

What it does internally:

- Sets both motor PWM values to `0`

Example:

```cpp
StopMotors();
```

### 10.5 `RGB_setColor(unsigned char R, unsigned char G, unsigned char B)`

Purpose:

- Sets the RGB LED color

Syntax:

```cpp
RGB_setColor(R, G, B);
```

Parameters:

- `R`: red intensity from `0` to `255`
- `G`: green intensity from `0` to `255`
- `B`: blue intensity from `0` to `255`

Returns:

- Nothing

Examples:

```cpp
RGB_setColor(255, 0, 0);   // red
RGB_setColor(0, 255, 0);   // green
RGB_setColor(0, 0, 255);   // blue
RGB_setColor(255, 255, 0); // yellow
RGB_setColor(0, 0, 0);     // off
```

### 10.6 `lcd_write(String text, int row, int column)`

Purpose:

- Writes text to the LCD

Syntax:

```cpp
lcd_write(text, row, column);
```

Parameters:

- `text`: the text you want to print
- `row`: LCD row number
- `column`: LCD column number

Returns:

- Nothing

Important notes for beginners:

- The current LCD object is configured as a `16x2` LCD
- That means there are 2 rows and 16 columns
- The usual rows are `0` and `1`
- The usual columns are `0` to `15`
- This function prints text, but it does not clear the screen first

Example:

```cpp
lcd_write("Hello!", 0, 0);
lcd_write("Garcia Robot", 1, 0);
```

### 10.7 `SONAR` class

Two global sonar objects already exist in the library:

- `sonar_right`
- `sonar_left`

You do not need to create them yourself for the default robot.

#### 10.7.1 `dist_cm()`

Purpose:

- Measures distance in centimeters

Syntax:

```cpp
unsigned int distance = sonar_right.dist_cm();
```

Returns:

- Distance in centimeters
- Returns `0` if no echo is received before timeout

Important notes:

- `0` can mean no object detected, object too far away, or a wiring problem
- The current code uses a `30000` microsecond timeout

Full example:

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

### 10.8 `LineSensor` class

This class reads the 5 digital line sensor inputs.

#### 10.8.1 Create the object

```cpp
LineSensor line(LINE_S1, LINE_S2, LINE_S3, LINE_S4, LINE_S5);
```

#### 10.8.2 `readSensors(bool &s1, bool &s2, bool &s3, bool &s4, bool &s5)`

Purpose:

- Reads the 5 sensor values

Syntax:

```cpp
line.readSensors(s1, s2, s3, s4, s5);
```

Parameters:

- Five boolean variables passed by reference

Returns:

- Nothing directly
- The variables you pass in are updated with sensor values

Important notes:

- The values will usually appear as `0` or `1`
- Depending on the sensor module, black/white detection may feel inverted
- The easiest way to learn the meaning is to print the values to Serial Monitor while moving the robot over the floor and the line

Full example:

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

### 10.9 `LineSensorAnalog` class

This class is used for the 8-sensor array handled through `QTRSensors`.

This is more advanced than `LineSensor`, but it is also more powerful because it gives you 8 numeric readings instead of only simple true/false values.

#### 10.9.1 Create the object

```cpp
LineSensorAnalog lineArray(
  LINE_S1_A, LINE_S2_A, LINE_S3_A, LINE_S4_A,
  LINE_S5_A, LINE_S6_A, LINE_S7_A, LINE_S8_A, ANALOG_NUMBER
);
```

#### 10.9.2 `setupLineSensorsAnalog()`

Purpose:

- Configures the QTR sensor array and the emitter pin

Use it in `setup()` before calibration or reading.

Example:

```cpp
lineArray.setupLineSensorsAnalog();
```

#### 10.9.3 `calibrateSensors(uint16_t iterations)`

Purpose:

- Runs sensor calibration

Syntax:

```cpp
lineArray.calibrateSensors(400);
```

Parameter:

- `iterations`: how many calibration cycles to run

Important notes:

- During calibration, move the sensor array over the surfaces you want it to learn
- For example, move it over the line and the background
- If you keep the robot still, calibration may be poor

#### 10.9.4 `PrintCalibrationResults()`

Purpose:

- Prints calibration minimum and maximum values to the Serial Monitor

Important notes:

- Call `Serial.begin(9600)` first

#### 10.9.5 `readSensors(int &s1, ..., int &s8)`

Purpose:

- Reads the 8 current sensor values

Returns:

- Nothing directly
- The 8 integer variables you pass to the function are updated

Typical flow:

```cpp
#include "garcia.h"

LineSensorAnalog lineArray(
  LINE_S1_A, LINE_S2_A, LINE_S3_A, LINE_S4_A,
  LINE_S5_A, LINE_S6_A, LINE_S7_A, LINE_S8_A, ANALOG_NUMBER
);

void setup() {
  setupGarcia();
  lineArray.setupLineSensorsAnalog();
  Serial.begin(9600);
  lineArray.calibrateSensors(400);
  lineArray.PrintCalibrationResults();
}

void loop() {
  int s1, s2, s3, s4, s5, s6, s7, s8;

  lineArray.readSensors(s1, s2, s3, s4, s5, s6, s7, s8);

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
```

### 10.10 `ColorSensor` class

This class helps read a color sensor and compare the readings with saved calibration values.

#### 10.10.1 Create the object

```cpp
ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);
```

For the current library version, the default workshop pin constants in [`src/garcia.h`](src/garcia.h) are the intended configuration.

#### 10.10.2 `readColor()`

Purpose:

- Reads the current sensor pulse values related to red, green, and blue

Syntax:

```cpp
color.readColor();
```

Important notes:

- Call this before `showColor()` or `isColor()`

#### 10.10.3 `showColor()`

Purpose:

- Prints the most recent sensor values to the Serial Monitor

Syntax:

```cpp
color.showColor();
```

Important notes:

- You must call `Serial.begin(9600)` first
- You should call `readColor()` before `showColor()`

#### 10.10.4 `setupColor(int color, unsigned long r, unsigned long g, unsigned long b, unsigned long tolerance)`

Purpose:

- Saves calibration values for one color

Parameters:

- `color`: use `RED`, `GREEN`, or `BLUE`
- `r`: stored value for the red reading
- `g`: stored value for the green reading
- `b`: stored value for the blue reading
- `tolerance`: allowed difference around the stored values

Why this matters:

- Real sensors do not return exactly the same number every time
- Tolerance gives some room for small variation

#### 10.10.5 `isColor(int testColor)`

Purpose:

- Tests whether the latest reading matches the requested calibrated color

Syntax:

```cpp
if (color.isColor(RED)) {
  Serial.println("Detected RED");
}
```

Returns:

- `1` if the color matches
- `0` if it does not match

Typical beginner workflow:

1. Start Serial Monitor
2. Call `readColor()`
3. Call `showColor()`
4. Place a known red object in front of the sensor
5. Write down the printed values
6. Save them with `setupColor(RED, ...)`
7. Repeat for green and blue
8. Use `isColor()` in `loop()`

Full example:

```cpp
#include "garcia.h"

ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);

void setup() {
  setupGarcia();
  Serial.begin(9600);

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

### 10.11 Constants You Can Use

The current public header defines these commonly used constants:

- `FORWARD`
- `BACKWARD`
- `RED`
- `GREEN`
- `BLUE`

The header also defines all default pin names such as:

- `LINE_S1`
- `LINE_S2`
- `LINE_S3`
- `LINE_S4`
- `LINE_S5`
- `LINE_S1_A` to `LINE_S8_A`
- `COLOR_S2`
- `COLOR_S3`
- `COLOR_OUT`

See [`src/garcia.h`](src/garcia.h) for the complete list.

## 11. Example Sketches Included

The repository currently includes these example sketches:

- [`examples/01_BasicSetup/01_BasicSetup.ino`](examples/01_BasicSetup/01_BasicSetup.ino)
  Minimal starting point. It only calls `setupGarcia()`.
- [`examples/02_Motors/02_Motors.ino`](examples/02_Motors/02_Motors.ino)
  Shows how to move the motors forward, stop, move backward, and stop again.
- [`examples/03_RGB_LED/03_RGB_LED.ino`](examples/03_RGB_LED/03_RGB_LED.ino)
  Cycles through RGB LED colors.
- [`examples/04_LCD/04_LCD.ino`](examples/04_LCD/04_LCD.ino)
  Writes text to the LCD.
- [`examples/05_Sonar/05_Sonar.ino`](examples/05_Sonar/05_Sonar.ino)
  Reads and prints right and left ultrasonic distance values.
- [`examples/06_A_LineSensor/06_LineSensor.ino`](examples/06_A_LineSensor/06_LineSensor.ino)
  Reads the 5 digital line sensors.
- [`examples/06_B_LineSensorAnalog/06_B_LineSensorAnalog.ino`](examples/06_B_LineSensorAnalog/06_B_LineSensorAnalog.ino)
  Configures, calibrates, and reads the 8-sensor analog array.
- [`examples/07_ColorSensor/07_ColorSensor.ino`](examples/07_ColorSensor/07_ColorSensor.ino)
  Shows color calibration and color matching.

For a beginner, the best order is:

1. `01_BasicSetup`
2. `02_Motors`
3. `03_RGB_LED`
4. `04_LCD`
5. `05_Sonar`
6. `06_A_LineSensor`
7. `06_B_LineSensorAnalog`
8. `07_ColorSensor`

## 12. Beginner Workflows

### 12.1 Make the robot move forward for 1 second

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
  delay(1000);
}
```

### 12.2 Show text on the LCD

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  lcd_write("Hello!", 0, 0);
  lcd_write("Ready to go", 1, 0);
}

void loop() {
}
```

### 12.3 Print distance values to the computer

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  Serial.begin(9600);
}

void loop() {
  Serial.println(sonar_right.dist_cm());
  delay(200);
}
```

### 12.4 Read line sensor values

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

  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.println(s5);

  delay(100);
}
```

## 13. Troubleshooting

### 13.1 Error: `garcia.h: No such file or directory`

Possible causes:

- The library folder is not inside the Arduino `libraries` folder
- The Arduino IDE was open before the library was copied
- The folder name is wrong

What to do:

1. Confirm the folder is named `garcia`
2. Confirm it is inside your Arduino `libraries` folder
3. Restart the Arduino IDE

### 13.2 Error: missing `LiquidCrystal_I2C.h`, `QTRSensors.h`, or `TimerOne.h`

Cause:

- A dependency library is missing

What to do:

- Install the missing library using `Sketch -> Include Library -> Manage Libraries...`

### 13.3 Motors do not move

Check:

- Did you call `setupGarcia()`?
- Is the motor driver powered?
- Is the robot battery connected?
- Are the motor wires connected?
- Are you using a speed above `0`?
- Are your motor pins correct in [`src/garcia.h`](src/garcia.h)?

### 13.4 LCD does not show text

Check:

- Did you call `setupGarcia()`?
- Is the LCD wired to I2C correctly?
- Is the LCD I2C address really `0x27`?
- Is the board using the correct SDA and SCL pins?

### 13.5 Sonar always returns `0`

Possible reasons:

- No object is in range
- The wiring is wrong
- The sensor is not powered correctly
- Echo is timing out

What to do:

- Test with a nearby object
- Check trigger and echo wiring
- Confirm the correct board and pins

### 13.6 Nothing appears in Serial Monitor

Check:

- Did you call `Serial.begin(9600)`?
- Is the Serial Monitor open?
- Is the Serial Monitor set to `9600 baud`?

### 13.7 Analog line sensor values are not useful

Check:

- Did you call `setupLineSensorsAnalog()`?
- Did you run `calibrateSensors(...)`?
- Did you move the sensor during calibration?
- Are the sensor array pins correct?

### 13.8 Color sensor does not detect colors correctly

Check:

- Did you call `readColor()` before `isColor()`?
- Did you measure your own calibration values?
- Is the tolerance too small?
- Is the lighting different from when you calibrated?

## 14. Current Limitations of the Library

Based on the latest source code, these points are important:

- The buzzer pin is initialized in `setupGarcia()`, but there is no public buzzer helper function yet
- The library is strongly tied to the workshop robot pin map
- The examples and intended use assume the pin constants from [`src/garcia.h`](src/garcia.h)
- The LCD helper writes text, but there is no public helper for clearing the display

## 15. Source Files

Main files in this repository:

- [`src/garcia.h`](src/garcia.h)
  Public header with pin definitions, constants, class declarations, and function declarations
- [`src/garcia.cpp`](src/garcia.cpp)
  Library implementation
- [`examples/`](examples/)
  Ready-to-run Arduino sketches
- [`library.properties`](library.properties)
  Arduino library metadata

## 16. License

No license is currently declared in this repository.

If the library will be shared outside the team, a license should be added.

---

# Documentacao em Portugues

## 1. O Que Esta Biblioteca E

A `Garcia Library` e uma biblioteca Arduino criada para os robots usados nas oficinas de robotica da Escola Garcia da Orta. O objetivo e simplificar o codigo: em vez de escrever configuracao de pinos e controlo de hardware de baixo nivel em todos os sketches, podes usar funcoes e classes ja preparadas.

A versao atual definida em [`library.properties`](library.properties) e `1.1.0`.

O codigo atual suporta:

- Dois motores DC
- Dois sensores ultrassonicos
- Um sensor de linha digital com 5 sensores
- Um array QTR com 8 sensores
- Um LED RGB
- Um LCD I2C 16x2
- Um sensor de cor
- Inicializacao do pino do buzzer

Importante: esta biblioteca foi feita para um robot especifico das oficinas. Nao e uma framework generica para qualquer Arduino e qualquer ligacao.

## 2. Para Quem Este README Foi Escrito

Este README foi escrito para pessoas que:

- Estao a comecar com Arduino
- Estao a comecar a programar
- Precisam de instrucoes passo a passo
- Querem perceber o que cada funcao faz
- Querem exemplos prontos a usar

Se estas mesmo a comecar, le primeiro estas secoes:

1. O Que Precisas Antes de Comecar
2. Compatibilidade e Mapa de Pinos
3. Instalacao
4. Conceitos Arduino Para Iniciantes
5. O Teu Primeiro Programa

## 3. O Que Precisas Antes de Comecar

Antes de usar esta biblioteca, deves ter:

- Arduino IDE instalado no computador
- A pasta `garcia` dentro da pasta `libraries` do Arduino
- As bibliotecas externas instaladas
- Um robot ligado como o mapa de pinos em [`src/garcia.h`](src/garcia.h), ou um mapa de pinos alterado por ti
- Uma placa compativel com pinos suficientes

## 4. Compatibilidade e Mapa de Pinos

Os pinos definidos em [`src/garcia.h`](src/garcia.h) usam valores altos como `32`, `34`, `50`, `51`, `52` e ainda `A0` ate `A7`.

Isto significa que a biblioteca foi pensada para uma placa tipo Arduino Mega, ou outra placa compativel com a mesma disponibilidade de pinos.

Se tentares usar esta biblioteca num Arduino Uno ou Nano sem alterar os pinos, nao vai funcionar corretamente.

Se o teu robot estiver ligado de outra forma:

1. Abre [`src/garcia.h`](src/garcia.h)
2. Procura as constantes `#define`
3. Altera os pinos para corresponder ao teu robot
4. Compila e volta a carregar o codigo

## 5. Mapa de Pinos Atual

O codigo atual usa este mapa de pinos por defeito:

| Hardware | Detalhes dos pinos |
| --- | --- |
| Motor esquerdo | `MOTOR_LEFT_DIR = 12`, `MOTOR_LEFT_PWM = 3` |
| Motor direito | `MOTOR_RIGHT_DIR = 13`, `MOTOR_RIGHT_PWM = 11` |
| Sonar direito | `TRIGGER_PIN_RIGHT = 34`, `ECHO_PIN_RIGHT = 35` |
| Sonar esquerdo | `TRIGGER_PIN_LEFT = 32`, `ECHO_PIN_LEFT = 33` |
| Sensor de linha digital | `LINE_S1 = 36`, `LINE_S2 = 37`, `LINE_S3 = 38`, `LINE_S4 = 39`, `LINE_S5 = 40` |
| Constantes extra de linha | `LINE_LEFT = 7`, `LINE_CENTER = 6`, `LINE_RIGHT = 5` |
| LED RGB | `RGB_R = 50`, `RGB_G = 51`, `RGB_B = 52` |
| Sensor de cor | `COLOR_S2 = 42`, `COLOR_S3 = 43`, `COLOR_OUT = 44` |
| Buzzer | `BUZZER_PIN = 45` |
| LCD | `LCD_ADDRESS = 0x27`, `LCD_SDA = 20`, `LCD_SCL = 21` |
| Array analogico | `LINE_S1_A = A0` ate `LINE_S8_A = A7` |
| Emissor QTR | `EMITTER_PIN = 2` |

## 6. Dependencias Externas

O codigo atual inclui estas bibliotecas:

- `Wire`
- `LiquidCrystal_I2C`
- `TimerOne`
- `QTRSensors`

Na maioria dos casos:

- `Wire` ja vem com o Arduino
- `LiquidCrystal_I2C`, `TimerOne` e `QTRSensors` precisam de ser instaladas no Library Manager

Mesmo que `TimerOne` nao apareca na API publica, esta incluida no header, por isso convem instala-la para evitar erros de compilacao.

## 7. Instalacao

### 7.1 Instalar a Garcia Library

1. Fecha o Arduino IDE se estiver aberto.
2. Copia a pasta `garcia` para a pasta `libraries` do Arduino.
3. Volta a abrir o Arduino IDE.

Exemplo tipico:

```text
Documents/Arduino/libraries/garcia
```

### 7.2 Instalar as bibliotecas dependentes

No Arduino IDE:

1. Abre `Sketch`
2. Abre `Include Library`
3. Abre `Manage Libraries...`
4. Procura `LiquidCrystal_I2C`
5. Instala
6. Procura `QTRSensors`
7. Instala
8. Procura `TimerOne`
9. Instala

### 7.3 Confirmar que a biblioteca aparece

No Arduino IDE:

1. Abre `File`
2. Abre `Examples`
3. Procura os exemplos da Garcia Library

Se conseguires abrir os exemplos, a biblioteca esta instalada corretamente.

## 8. Conceitos Arduino Para Iniciantes

### 8.1 O que e um sketch?

Um sketch e o teu programa Arduino. Normalmente e um ficheiro `.ino`.

### 8.2 O que faz `#include "garcia.h"`?

Esta linha diz ao Arduino para carregar a biblioteca Garcia.

```cpp
#include "garcia.h"
```

### 8.3 O que e `setup()`?

`setup()` corre uma unica vez quando a placa arranca.

Normalmente usas `setup()` para:

- Inicializar a biblioteca
- Iniciar a comunicacao serie
- Configurar sensores

### 8.4 O que e `loop()`?

`loop()` corre continuamente enquanto a placa estiver ligada.

Normalmente usas `loop()` para:

- Ler sensores
- Controlar motores
- Atualizar LEDs ou LCD
- Tomar decisoes no robot

### 8.5 O que faz `Serial.begin(9600)`?

Inicia a comunicacao com o computador para poderes ver mensagens no Serial Monitor.

Isto e muito util para iniciantes porque permite ver valores de sensores e perceber melhor o que o robot esta a fazer.

### 8.6 O que e calibracao?

Calibracao significa medir valores reais no teu proprio robot e guardar esses valores para obter resultados mais fiaveis.

Isto e especialmente importante para:

- `LineSensorAnalog`
- `ColorSensor`

## 9. O Teu Primeiro Programa

Comeca por este sketch:

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
}

void loop() {
}
```

### 9.1 O que este programa faz

- Carrega a biblioteca Garcia
- Inicializa o hardware do robot
- Nao faz mais nada ainda

### 9.2 Porque `setupGarcia()` e importante

`setupGarcia()` prepara os pinos de hardware usados pela biblioteca.

No codigo atual, inicializa:

- Pinos dos motores
- Pinos dos sensores ultrassonicos
- Pinos do sensor de linha digital
- Pinos do LED RGB
- Pino do buzzer
- Pinos do sensor de cor
- Pinos do array analogico de 8 sensores
- LCD

Se te esqueceres de chamar `setupGarcia()`, varias partes da biblioteca podem nao funcionar corretamente.

## 10. Referencia Completa da API

Esta secao explica a API publica que existe no codigo atual.

### 10.1 `setupGarcia()`

Objetivo:

- Inicializar o hardware do robot usado pela biblioteca

Sintaxe:

```cpp
setupGarcia();
```

Parametros:

- Nenhum

Retorno:

- Nada

Notas importantes:

- Deve ser chamado dentro de `setup()`
- Deve ser chamado antes de usar motores, sensores, LED RGB, LCD ou sensor de cor

### 10.2 `MotorRight(int speed, bool direction)`

Objetivo:

- Controlar o motor direito

Sintaxe:

```cpp
MotorRight(speed, direction);
```

Parametros:

- `speed`: valor PWM, normalmente entre `0` e `255`
- `direction`: usa `FORWARD` ou `BACKWARD`

Retorno:

- Nada

Notas:

- `0` significa parado
- `255` significa valor PWM maximo
- O motor continua a andar ate mudares o valor ou chamares `StopMotors()`

### 10.3 `MotorLeft(int speed, bool direction)`

Objetivo:

- Controlar o motor esquerdo

Sintaxe:

```cpp
MotorLeft(speed, direction);
```

Parametros:

- `speed`: valor PWM, normalmente entre `0` e `255`
- `direction`: usa `FORWARD` ou `BACKWARD`

Retorno:

- Nada

### 10.4 `StopMotors()`

Objetivo:

- Parar os dois motores

Sintaxe:

```cpp
StopMotors();
```

O que faz internamente:

- Coloca ambos os PWM a `0`

### 10.5 `RGB_setColor(unsigned char R, unsigned char G, unsigned char B)`

Objetivo:

- Definir a cor do LED RGB

Parametros:

- `R`: intensidade do vermelho de `0` a `255`
- `G`: intensidade do verde de `0` a `255`
- `B`: intensidade do azul de `0` a `255`

Exemplos:

```cpp
RGB_setColor(255, 0, 0);
RGB_setColor(0, 255, 0);
RGB_setColor(0, 0, 255);
RGB_setColor(255, 255, 0);
RGB_setColor(0, 0, 0);
```

### 10.6 `lcd_write(String text, int row, int column)`

Objetivo:

- Escrever texto no LCD

Parametros:

- `text`: texto a mostrar
- `row`: linha do LCD
- `column`: coluna do LCD

Notas importantes:

- O LCD atual esta configurado como `16x2`
- As linhas normais sao `0` e `1`
- As colunas normais sao `0` ate `15`
- Esta funcao escreve texto, mas nao limpa o ecra antes

Exemplo:

```cpp
lcd_write("Hello!", 0, 0);
lcd_write("Garcia Robot", 1, 0);
```

### 10.7 Classe `SONAR`

Existem dois objetos globais prontos a usar:

- `sonar_right`
- `sonar_left`

#### 10.7.1 `dist_cm()`

Objetivo:

- Medir distancia em centimetros

Sintaxe:

```cpp
unsigned int distancia = sonar_right.dist_cm();
```

Retorno:

- Distancia em centimetros
- `0` se nao houver eco dentro do tempo limite

Notas:

- Um valor `0` pode significar sem objeto, objeto demasiado longe ou problema de ligacao

### 10.8 Classe `LineSensor`

Esta classe le os 5 sensores do sensor de linha digital.

Criacao do objeto:

```cpp
LineSensor line(LINE_S1, LINE_S2, LINE_S3, LINE_S4, LINE_S5);
```

#### 10.8.1 `readSensors(bool &s1, bool &s2, bool &s3, bool &s4, bool &s5)`

Objetivo:

- Ler os 5 valores do sensor

Retorno:

- Nada diretamente
- As variaveis passadas para a funcao ficam atualizadas

Notas:

- Os valores costumam aparecer como `0` ou `1`
- Dependendo do modulo, o significado de preto e branco pode parecer invertido
- O melhor e testar com `Serial.print`

### 10.9 Classe `LineSensorAnalog`

Esta classe serve para o array de 8 sensores com `QTRSensors`.

E mais avancada do que `LineSensor`, mas tambem mais poderosa porque devolve 8 valores numericos.

Criacao do objeto:

```cpp
LineSensorAnalog lineArray(
  LINE_S1_A, LINE_S2_A, LINE_S3_A, LINE_S4_A,
  LINE_S5_A, LINE_S6_A, LINE_S7_A, LINE_S8_A, 8
);
```

#### 10.9.1 `setupLineSensorsAnalog()`

Configura o array QTR e o pino do emissor.

#### 10.9.2 `calibrateSensors(uint16_t iterations)`

Corre a calibracao do sensor.

Nota importante:

- Durante a calibracao, move o array por cima da linha e do fundo
- Se o robot ficar parado, a calibracao pode ficar fraca

#### 10.9.3 `PrintCalibrationResults()`

Mostra os valores minimos e maximos no Serial Monitor.

Nota:

- Chama `Serial.begin(9600)` antes

#### 10.9.4 `readSensors(int &s1, ..., int &s8)`

Le os 8 valores atuais do array.

Fluxo tipico:

```cpp
#include "garcia.h"

LineSensorAnalog lineArray(
  LINE_S1_A, LINE_S2_A, LINE_S3_A, LINE_S4_A,
  LINE_S5_A, LINE_S6_A, LINE_S7_A, LINE_S8_A, 8
);

void setup() {
  setupGarcia();
  lineArray.setupLineSensorsAnalog();
  Serial.begin(9600);
  lineArray.calibrateSensors(400);
  lineArray.PrintCalibrationResults();
}

void loop() {
  int s1, s2, s3, s4, s5, s6, s7, s8;

  lineArray.readSensors(s1, s2, s3, s4, s5, s6, s7, s8);

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
```

### 10.10 Classe `ColorSensor`

Esta classe ajuda a ler o sensor de cor e comparar os valores atuais com valores de calibracao guardados.

Criacao do objeto:

```cpp
ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);
```

Na versao atual da biblioteca, as constantes de pinos definidas em [`src/garcia.h`](src/garcia.h) sao a configuracao prevista.

#### 10.10.1 `readColor()`

Le os valores atuais associados a vermelho, verde e azul.

Deve ser chamado antes de `showColor()` ou `isColor()`.

#### 10.10.2 `showColor()`

Mostra os valores mais recentes no Serial Monitor.

Notas:

- Precisa de `Serial.begin(9600)`
- Deve ser usado depois de `readColor()`

#### 10.10.3 `setupColor(int color, unsigned long r, unsigned long g, unsigned long b, unsigned long tolerance)`

Guarda valores de calibracao para uma cor.

Parametros:

- `color`: usa `RED`, `GREEN` ou `BLUE`
- `r`: valor guardado para vermelho
- `g`: valor guardado para verde
- `b`: valor guardado para azul
- `tolerance`: margem aceite para comparacao

#### 10.10.4 `isColor(int testColor)`

Verifica se a leitura mais recente corresponde a uma cor calibrada.

Retorno:

- `1` se corresponder
- `0` se nao corresponder

Fluxo tipico para iniciantes:

1. Abrir o Serial Monitor
2. Chamar `readColor()`
3. Chamar `showColor()`
4. Colocar um objeto vermelho conhecido em frente ao sensor
5. Apontar os valores mostrados
6. Guardar com `setupColor(RED, ...)`
7. Repetir para verde e azul
8. Usar `isColor()` dentro de `loop()`

Exemplo completo:

```cpp
#include "garcia.h"

ColorSensor color(COLOR_S2, COLOR_S3, COLOR_OUT);

void setup() {
  setupGarcia();
  Serial.begin(9600);

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

### 10.11 Constantes Disponiveis

O header publico define estas constantes mais usadas:

- `FORWARD`
- `BACKWARD`
- `RED`
- `GREEN`
- `BLUE`

Tambem define os nomes de pinos por defeito, como:

- `LINE_S1`
- `LINE_S2`
- `LINE_S3`
- `LINE_S4`
- `LINE_S5`
- `LINE_S1_A` ate `LINE_S8_A`
- `COLOR_S2`
- `COLOR_S3`
- `COLOR_OUT`

Consulta [`src/garcia.h`](src/garcia.h) para a lista completa.

## 11. Exemplos Incluidos

O repositorio inclui estes exemplos:

- [`examples/01_BasicSetup/01_BasicSetup.ino`](examples/01_BasicSetup/01_BasicSetup.ino)
  Ponto de partida minimo. So chama `setupGarcia()`.
- [`examples/02_Motors/02_Motors.ino`](examples/02_Motors/02_Motors.ino)
  Mostra como mover os motores para a frente, parar, andar para tras e parar.
- [`examples/03_RGB_LED/03_RGB_LED.ino`](examples/03_RGB_LED/03_RGB_LED.ino)
  Alterna as cores do LED RGB.
- [`examples/04_LCD/04_LCD.ino`](examples/04_LCD/04_LCD.ino)
  Escreve texto no LCD.
- [`examples/05_Sonar/05_Sonar.ino`](examples/05_Sonar/05_Sonar.ino)
  Le e mostra as distancias dos dois ultrassons.
- [`examples/06_A_LineSensor/06_LineSensor.ino`](examples/06_A_LineSensor/06_LineSensor.ino)
  Le os 5 sensores do sensor de linha digital.
- [`examples/06_B_LineSensorAnalog/06_B_LineSensorAnalog.ino`](examples/06_B_LineSensorAnalog/06_B_LineSensorAnalog.ino)
  Configura, calibra e le o array analogico de 8 sensores.
- [`examples/07_ColorSensor/07_ColorSensor.ino`](examples/07_ColorSensor/07_ColorSensor.ino)
  Mostra calibracao e deteccao de cores.

Boa ordem para iniciantes:

1. `01_BasicSetup`
2. `02_Motors`
3. `03_RGB_LED`
4. `04_LCD`
5. `05_Sonar`
6. `06_A_LineSensor`
7. `06_B_LineSensorAnalog`
8. `07_ColorSensor`

## 12. Fluxos Simples Para Iniciantes

### 12.1 Fazer o robot andar para a frente durante 1 segundo

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
  delay(1000);
}
```

### 12.2 Mostrar texto no LCD

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  lcd_write("Hello!", 0, 0);
  lcd_write("Ready to go", 1, 0);
}

void loop() {
}
```

### 12.3 Mostrar distancia no computador

```cpp
#include "garcia.h"

void setup() {
  setupGarcia();
  Serial.begin(9600);
}

void loop() {
  Serial.println(sonar_right.dist_cm());
  delay(200);
}
```

### 12.4 Ler os valores do sensor de linha

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

  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.println(s5);

  delay(100);
}
```

## 13. Resolucao de Problemas

### 13.1 Erro: `garcia.h: No such file or directory`

Possiveis causas:

- A pasta da biblioteca nao esta dentro da pasta `libraries`
- O Arduino IDE estava aberto quando copiaste a biblioteca
- O nome da pasta esta errado

O que fazer:

1. Confirmar que a pasta se chama `garcia`
2. Confirmar que esta dentro da pasta `libraries`
3. Reiniciar o Arduino IDE

### 13.2 Erro: falta `LiquidCrystal_I2C.h`, `QTRSensors.h` ou `TimerOne.h`

Causa:

- Falta uma dependencia

O que fazer:

- Instalar a biblioteca em falta no `Manage Libraries...`

### 13.3 Os motores nao andam

Verifica:

- Chamaste `setupGarcia()`?
- O driver dos motores tem alimentacao?
- A bateria do robot esta ligada?
- Os cabos dos motores estao ligados?
- O valor de velocidade e maior que `0`?
- Os pinos em [`src/garcia.h`](src/garcia.h) estao corretos?

### 13.4 O LCD nao mostra texto

Verifica:

- Chamaste `setupGarcia()`?
- O LCD esta ligado por I2C corretamente?
- O endereco I2C e mesmo `0x27`?
- A placa usa os pinos SDA e SCL corretos?

### 13.5 O sonar devolve sempre `0`

Possiveis razoes:

- Nao ha objeto ao alcance
- A ligacao esta errada
- O sensor nao esta alimentado corretamente
- O eco esta a passar o tempo limite

O que fazer:

- Testar com um objeto proximo
- Confirmar trigger e echo
- Confirmar placa e pinos corretos

### 13.6 Nao aparece nada no Serial Monitor

Verifica:

- Chamaste `Serial.begin(9600)`?
- O Serial Monitor esta aberto?
- A velocidade esta em `9600 baud`?

### 13.7 Os valores do array analogico nao sao uteis

Verifica:

- Chamaste `setupLineSensorsAnalog()`?
- Correste `calibrateSensors(...)`?
- Moveste o sensor durante a calibracao?
- Os pinos do array estao corretos?

### 13.8 O sensor de cor nao deteta corretamente

Verifica:

- Chamaste `readColor()` antes de `isColor()`?
- Mediste os teus proprios valores de calibracao?
- A tolerancia esta demasiado pequena?
- A luz ambiente mudou desde a calibracao?

## 14. Limitacoes Atuais da Biblioteca

Com base no codigo mais recente, estes pontos sao importantes:

- O pino do buzzer e inicializado em `setupGarcia()`, mas ainda nao existe funcao publica para o buzzer
- A biblioteca esta muito ligada ao mapa de pinos do robot das oficinas
- Os exemplos e o uso esperado assumem as constantes de [`src/garcia.h`](src/garcia.h)
- A funcao do LCD escreve texto, mas nao existe funcao publica para limpar o ecra

## 15. Ficheiros Principais

Ficheiros principais deste repositorio:

- [`src/garcia.h`](src/garcia.h)
  Header publico com definicoes de pinos, constantes, declaracoes de classes e funcoes
- [`src/garcia.cpp`](src/garcia.cpp)
  Implementacao da biblioteca
- [`examples/`](examples/)
  Sketches Arduino prontos a usar
- [`library.properties`](library.properties)
  Metadados da biblioteca Arduino

## 16. Licenca

Este repositorio ainda nao declara nenhuma licenca.

Se a biblioteca for partilhada fora da equipa, deve ser adicionada uma licenca.
