// Hi! This is the code to put in the Arduino UNO R3 for my Upcycler project! This is currently version 3.0, as of 6/24/2025. I hope you find my Upcycler helpful!
#include <math.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define WIDTH 128
#define HEIGHT 64
Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, -1);
#define JX A3
#define JY A2
#define JSW 4
#define MOSFET 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define THERMISTOR A0
#define SERIESRESISTOR 100000
#define THERMISTORNOMINAL 100000
#define TEMPERATURENOMINAL 25
#define BCOEFFICIENT 3950
int menuIndex = 0;
bool editing = false;
const int menuSize = 3;
bool motorEnabled = false;
float targetTemp = 210;
int stepsPerSecond = 150;
const float TEMP_OFFSET = 11.0;
float Kp = 5.2;
float Ki = 0.055;
float Kd = 14.0;
float integral = 0;
float lastError = 0;
unsigned long lastMoveTime = 0;
const int moveDelay = 180;
unsigned long lastStepTime = 0;
unsigned long stepInterval = 1000000 / 150;
int stepIndex = 0;
float smoothedTemp = 25.0;
unsigned long lastControlUpdate = 0;
int seq[8][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,1},
    {0,0,0,1},
    {1,0,0,1}
};
float readTemperature() {
    long total = 0;
    for (int i = 0; i < 10; i++) total += analogRead(THERMISTOR);
    float adc = total / 10.0;
    float resistance = SERIESRESISTOR / ((1023.0 / adc) - 1.0);
    float t = resistance / THERMISTORNOMINAL;
    t = log(t);
    t /= BCOEFFICIENT;
    t += 1.0 / (TEMPERATURENOMINAL + 273.15);
    t = 1.0 / t;
    t -= 273.15;
    return t;
}
void stepMotor() {
    digitalWrite(IN1, seq[stepIndex][0]);
    digitalWrite(IN2, seq[stepIndex][1]);
    digitalWrite(IN3, seq[stepIndex][2]);
    digitalWrite(IN4, seq[stepIndex][3]);
    stepIndex++;
    if (stepIndex >= 8) stepIndex = 0;
}
void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(MOSFET, OUTPUT);
    analogWrite(MOSFET, 0);
    pinMode(JSW, INPUT_PULLUP);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.setTextColor(SSD1306_WHITE);
    Serial.begin(115200);
}
void loop() {
    runMotor();
    if (motorEnabled) {
        lockedMode();
    } else {
        handleJoystick();
        runPID();
        drawMenu();
    }
}
void runMotor() {
    if (!motorEnabled) return;
    unsigned long now = micros();
    stepInterval = 1000000 / stepsPerSecond;
    if (now - lastStepTime >= stepInterval) {
        lastStepTime = now;
        stepMotor();
    }
}
void lockedMode() {
    unsigned long now = millis();
    if (now - lastControlUpdate > 500) {
        lastControlUpdate = now;
        runPID();
        if (digitalRead(JSW) == LOW) {
            delay(200);
            motorEnabled = false;
        }
        drawLockedScreen();
    }
}
void runPID() {
    float rawTemp = readTemperature();
    smoothedTemp = 0.85 * smoothedTemp + 0.15 * rawTemp;
    float controlTarget = targetTemp + TEMP_OFFSET;
    float error = controlTarget - smoothedTemp;
    if (abs(error) < 2) integral *= 0.98;
    else integral += error * 0.5;
    if (integral > 150) integral = 150;
    if (integral < -150) integral = -150;
    float derivative = error - lastError;
    lastError = error;
    float output = Kp * error + Ki * integral + Kd * derivative;
    int pwm = output;
    if (pwm < 0) pwm = 0;
    if (pwm > 255) pwm = 255;
    if (!motorEnabled) pwm = 0;
    analogWrite(MOSFET, pwm);
}
void handleJoystick() {
    int xVal = analogRead(JX);
    int yVal = analogRead(JY);
    unsigned long now = millis();
    if (!editing) {
        if (yVal < 400 && now - lastMoveTime > moveDelay) {
            menuIndex--;
            if (menuIndex < 0) menuIndex = menuSize - 1;
            lastMoveTime = now;
        } else if (yVal > 600 && now - lastMoveTime > moveDelay) {
            menuIndex++;
            if (menuIndex >= menuSize) menuIndex = 0;
            lastMoveTime = now;
        }
    } else {
        if (menuIndex == 1) {
            if (xVal > 600 && now - lastMoveTime > moveDelay) {
                targetTemp += 5;
                if (targetTemp > 240) targetTemp = 240;
                lastMoveTime = now;
            } else if (xVal < 400 && now - lastMoveTime > moveDelay) {
                targetTemp -= 5;
                if (targetTemp < 180) targetTemp = 180;
                lastMoveTime = now;
            }
        }
    }
    if (digitalRead(JSW) == LOW) {
        delay(200);
        if (menuIndex == 0 && !editing) {
            motorEnabled = !motorEnabled;
        } else {
            editing = !editing;
        }
    }
}
void drawMenu() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("UPCYCLER");
    display.setTextSize(1);
    display.println("v3.0");
    display.setTextSize(1);
    display.setCursor(0, 18);
    display.print("Current_Temp: ");
    display.print(smoothedTemp, 1);
    display.print("C");
    display.setCursor(0, 34);
    display.print(menuIndex == 0 ? "> " : "  ");
    display.print("Motor_Status: ");
    display.print(motorEnabled ? "ON" : "OFF");
    display.setCursor(0, 46);
    display.print(menuIndex == 1 ? "> " : "  ");
    display.print("Target_Temp: ");
    display.print((int)targetTemp);
    display.print("C");
    display.setCursor(0, 58);
    display.print(menuIndex == 2 ? "> " : "  ");
    display.print("Steps/s: ");
    display.println(stepsPerSecond);
    display.display();
}
void drawLockedScreen() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("RUNNING");
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print("Current_Temp: ");
    display.print(smoothedTemp, 1);
    display.print("C");
    display.setCursor(0, 35);
    display.print("Target_Temp: ");
    display.print(targetTemp);
    display.print("C");
    display.setCursor(0, 50);
    display.println("Hold to STOP");
    display.display();
}
