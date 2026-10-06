#include <M5Unified.h>
void setup() {
  M5.begin();
  Serial.begin(115200);
  M5.Display.setTextSize(3);
  M5.Display.println("Lab 2 - Task 1");
  Serial.println("Lab 2 - Task 1");
}
void loop() {
  if (M5.BtnA.wasPressed()) {
    M5.Display.clear();
    M5.Display.setCursor(130, 100);
    Serial.println("Button A.");
    M5.Display.print("Hello");
  }
  if (M5.BtnB.wasPressed()) {
    M5.Display.clear();
    M5.Display.setCursor(100, 100);
    Serial.println("Button B.");
    M5.Display.print("Welcome");
  }
  if (M5.BtnC.wasPressed()) {
    M5.Display.clear();
    Serial.println("Button C.");
  }
  M5.update();
}