#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 11, 12);

// Motor driver pins
int IN1 = 8;
int IN2 = 9;
int ENA = 10;

// Button
int buttonPin = 2;
int motorState = 0;

// Potentiometer (speed control)
int potPin = A2;

// Voltage sensing
int sensorPin = A0;

// Debounce
int buttonState;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Energy System");
  delay(1500);
  lcd.clear();
}

void loop() {

  //BUTTON TOGGLE
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        motorState = !motorState;
      }
    }
  }

  lastButtonState = reading;

  //READ POTENTIOMETER
  int potValue = analogRead(potPin);
  int speedValue = map(potValue, 0, 1023, 0, 255);

  //MOTOR ON (INPUT ENERGY)
  if (motorState == 1) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speedValue);

    lcd.setCursor(0, 0);
    lcd.print("INPUT ENERGY   ");

    lcd.setCursor(0, 1);
    lcd.print("Speed: ");
    lcd.print(speedValue);
    lcd.print("   ");
  }

  //MOTOR OFF (RECOVERY)
  else {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    int sensorValue = analogRead(sensorPin);
    float voltage = sensorValue * (5.0 / 1023.0);

    lcd.setCursor(0, 0);
    lcd.print("RECOVER ENERGY ");

    lcd.setCursor(0, 1);
    lcd.print("V: ");
    lcd.print(voltage);
    lcd.print("   ");
  }
}