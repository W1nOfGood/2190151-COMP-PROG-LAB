#include <M5Unified.h>

#define C  524
#define c  131
#define C1 262

int x = 5;

void showNumber() {
  M5.Display.clear();
  M5.Display.setCursor(0, 0);
  M5.Display.println(x);
}

void beep(int freq) {
  M5.Speaker.setVolume(160);
  M5.Speaker.tone(freq);
  delay(500);
  M5.Speaker.setVolume(0);
}

void setup() {
  M5.begin();
  M5.Display.setTextSize(10);
  M5.Display.setTextColor(TFT_GREEN);
  M5.Speaker.setVolume(160);
  showNumber();
}

void loop() {
  M5.update();

  // ---------- Button A: count up to 10 ----------
  if (M5.BtnA.wasPressed()) {
    while (x < 10) {
      x++;
      showNumber();
      delay(500);
    }
    if (x == 10) {
      beep(C);
    }
  }

  // ---------- Button B: count down to 0 ----------
  if (M5.BtnB.wasPressed()) {
    if (x > 0) {
      x--;
      showNumber();
    }
    if (x == 0) {
      beep(c);
    }
  }

  // ---------- Button C: reset to 5 ----------
  if (M5.BtnC.wasPressed()) {
    x = 5;
    showNumber();
    beep(C1);
  }
}




// incase

// if (M5.BtnA.wasPressed()) {
//   if (x < 10) {
//     x++;
//     showNumber();
//   }
//   if (x == 10) {
//     beep(C);                     // plays on the press that reaches 10
//   }
// }
