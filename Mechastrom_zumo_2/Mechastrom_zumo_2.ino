// MechaStorm Zumo 2 code. Programmed by Mehataj Uddin Ahmed. Founder of MechStorm.
// for contact: mehatajahmed001@gmail.com
//This is a efficient code for sumo bot competetion.
//Components used in this project: ARDUINO NANO, TB1266FNG, IR SENSOR, SONAR SENSOR, BUTTON, VL53L0X.
// This code is used in several competetion and won as well!

#include <NewPing.h>
#include <Wire.h>
#include <VL53L0X.h>

const int button = 2;
const int ir1 = 3;
const int ir2 = 4;
const int ir3 = A2;
// motor pins
const int pwma = 5;
const int pwmb = 6;
const int a1 = 7;
const int a2 = 8;
const int b1 = 9;
const int b2 = 10;

#define s_trig 12
#define s_echo 13
#define s2_trig A0
#define s2_echo A1

NewPing s1(s_trig, s_echo, 30);
NewPing s2(s2_trig, s2_echo, 30);

unsigned long startTime = 0;  // for the start time when button pressed
bool timerun = false;         // for knowing is time running?
bool s = false;               // for knowing if can start?
int b_state = digitalRead(button);
int r_sensor = s1.ping_cm();
int l_sensor = s2.ping_cm();
VL53L0X lox;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(button, INPUT_PULLUP);

  lox.setTimeout(500);
  if (!lox.init()) {
    Serial.println(",L0x Failed,");
  }
  lox.startContinuous();
}

void loop() {
  // convertion of the value of the vl53l0x
  float range_mil = lox.readRangeContinuousMillimeters();
  float range_centi = 0;
  if (range_mil != 65535) {
    range_centi = range_mil / 10.0;  // range of lox in cm.
    range_centi = constrain(range_centi, 3.0, 30.0);
  }

  if (lox.timeoutOccurred()) { Serial.print("TIMEOUT!!"); }

  if (b_state == LOW) {
    Serial.println("Pressed");
    startTime = millis();
    timerun = true;
  }

  if (timerun == true && millis() - startTime >= 5000) {
    Serial.println("Start!");
    s = true;
  }

  if (s == true) {
    search(r_sensor, l_sensor, range_centi, a1, a2, b1, b2, pwma, pwmb);
    edge_a(ir1, ir2, ir3, a1, a2, b1, b2, pwma, pwmb);
  }
}