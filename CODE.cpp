#include <LiquidCrystal_I2C.h>
#include "NewPing.h"

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400
#define TOUCH_PIN 2  // TTP223 OUT pin

LiquidCrystal_I2C lcd(0x27, 16, 2);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

bool isEnabled = false;      // Keeps track of toggle state
bool lastTouchState = LOW;   // To detect rising edge
unsigned int lastDistance = 0;
bool wasEnabledLast = false; // To detect change in enabled state

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(TOUCH_PIN, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Touch to Start");
}

void loop() {
  bool currentTouch = digitalRead(TOUCH_PIN);

  // Detect rising edge of touch (i.e., touch press)
  if (currentTouch == HIGH && lastTouchState == LOW) {
    isEnabled = !isEnabled;  // Toggle the state
    delay(100);              // Debounce delay
  }
  lastTouchState = currentTouch;

  if (isEnabled) {
    // Only clear the screen once when switching from off to on
    if (!wasEnabledLast) {
      lcd.clear();
    }

    // Measure and display distance
    lastDistance = sonar.ping_cm();

    lcd.setCursor(2, 0);
    lcd.print("Distance=");
    lcd.print(lastDistance);
    lcd.print("cm");

    Serial.print("Distance: ");
    Serial.print(lastDistance);
    Serial.println(" cm");

    delay(500);
  } else {
    // If just turned off, clear and show idle message once
    if (wasEnabledLast) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Touch to Start");
    }
    delay(100);
  }

  wasEnabledLast = isEnabled; // Track previous state
}
