#include <M5Stack.h>
#define C 524
#define c 131
#define C1 262
int x = 5;
void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.setTextSize(10);
  M5.Lcd.setTextColor(0x07E0);
  M5.Lcd.println(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  if (M5.BtnA.wasPressed()) {
    while (x < 10) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      x++;
      M5.Lcd.println(x);
      delay(500);
    }
    if (x = 10) {
      M5.Speaker.tone(C);
      delay(500);
      M5.Speaker.mute();
    }
  }

  if (M5.BtnB.wasPressed()) {
    if (x > 0) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      x--;
      M5.Lcd.println(x);

    }
    if (x = 0) {
      M5.Speaker.tone(c);
      delay(500);
      M5.Speaker.mute();
    }


    if (M5.BtnC.wasPressed()) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      int x = 5;
      M5.Lcd.println(x);
      M5.Speaker.tone(C1);
      delay(500);
      M5.Speaker.mute();
    }
  }
}
