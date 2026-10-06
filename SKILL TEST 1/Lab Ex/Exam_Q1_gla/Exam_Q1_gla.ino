#include <M5Stack.h>
#define C 262

int n = 5;
void setup() {
  M5.begin();
  M5.Lcd.setTextSize(10);
  M5.Lcd.setCursor(0, 120);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.println(n);
  M5.Speaker.setVolume(2);
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    while (n < 10) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 120);
      M5.Lcd.print(n);
      delay(500);
      n++;
    }
    if (n = 10) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 120);
      M5.Lcd.print(n);
      M5.Speaker.tone(C * 2);
      delay(500);
      M5.Speaker.mute();
    }
  }
  if (M5.BtnB.wasPressed()) {
    if (n <= 0) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 120);
      M5.Lcd.print(n);
      M5.Speaker.tone(C / 2);
      delay(500);
      M5.Speaker.mute();
    }
    if (n > 0) {
      n--;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 120);
      M5.Lcd.print(n);
    }
  }
  if (M5.BtnC.wasPressed()) {
    n = 5;
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 120);
    M5.Lcd.print(n);
    M5.Speaker.tone(C);
    delay(500);
    M5.Speaker.mute();
  }
}