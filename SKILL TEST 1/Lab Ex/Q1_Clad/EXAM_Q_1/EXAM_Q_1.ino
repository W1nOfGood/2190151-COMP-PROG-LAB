#include <M5Unified.h>

int x = 5;

void showNumber() {
  M5.Display.clear();
  M5.Display.setCursor(0, 0);
  M5.Display.println(x);
}

void setup() {
  M5.begin();
  M5.Display.setTextSize(10);
  M5.Display.setTextColor(TFT_GREEN);
  showNumber();
  Serial.begin(115200);
}

void loop() {
  M5.update();

  if (M5.BtnB.wasPressed() && x < 10) {
    x++;
    showNumber();
  }

  if (M5.BtnB.isHolding() && x < 10) {
    x++;
    showNumber();
    delay(500);
  }

  while (x == 10 && (M5.BtnB.isHolding())) {
    delay(500);
    Serial.println("MAX");
    M5.update();
    if (M5.BtnB.isReleased()) {
      break;
    }
  }

  if (M5.BtnA.wasPressed()) {
    if (x > 0) {
      x--;
      showNumber();
    }
    if (x == 0) {
      Serial.println("MIN");
    }
  }

  if (M5.BtnC.wasPressed()) {
    x = 5;
    showNumber();
    Serial.println("RESET");
  }
}




// incase

// if (M5.BtnA.wasPressed()) {
//   if (x < 10) {
//     x++;
//     showNumber();
//   }
//   if (x == 10) {
//     beep(C);
//   }
// }
