// BUTTONS + SCREEN BASICS
// A = show "A pressed" (red), B = show "B pressed" (blue), C = clear screen
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.println("Press a button");
}

void loop() {
  M5.update();                       // MUST be called every loop

  if (M5.BtnA.wasPressed()) {        // true ONCE per press
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 100);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.println("A pressed");
  }
  if (M5.BtnB.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 100);
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.println("B pressed");
  }
  if (M5.BtnC.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);        // clear
  }

  // Other button functions:
  //   M5.BtnA.isPressed()      true WHILE held down
  //   M5.BtnA.wasReleased()    true once when let go
  //   M5.BtnA.pressedFor(1000) true if held 1000 ms
}
