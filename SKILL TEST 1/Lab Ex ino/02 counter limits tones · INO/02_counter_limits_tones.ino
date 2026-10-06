// COUNTER WITH LIMITS + TONES (general template)
// A = +1, B = -1, C = reset. Limits MIN..MAX with different tones.
#include <M5Stack.h>

#define MIN_VAL 0
#define MAX_VAL 10
#define START   5

int n = START;

void show() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 100);
  M5.Lcd.print(n);
}
void beep(int freq, int ms) {
  M5.Speaker.tone(freq);
  delay(ms);
  M5.Speaker.mute();
}

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(10);
  M5.Lcd.setTextColor(GREEN);
  show();
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    if (n < MAX_VAL) {
      n++;
      show();
    }
    if (n == MAX_VAL) beep(524, 500);   // high tone at max
  }
  if (M5.BtnB.wasPressed()) {
    if (n > MIN_VAL) {
      n--;
      show();
    }
    if (n == MIN_VAL) beep(131, 500);   // low tone at min
  }
  if (M5.BtnC.wasPressed()) {
    n = START;
    show();
    beep(262, 500);
  }
}
