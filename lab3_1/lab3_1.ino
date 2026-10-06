#include <M5Unified.h>
int count = 0;  // count total button presses
void setup() {
  M5.begin();
  Serial.begin(115200);
  Serial.println("Lab 3 - Task 2");
  M5.Display.setTextSize(3);
  M5.Display.setCursor(100,150);
}
void loop() {
  if (M5.BtnA.wasPressed()) {
    count++;
    M5.Display.print("A");
    Serial.print("[");
    Serial.print(count);
    Serial.println("] Button A pressed");
  }
  if (M5.BtnB.wasPressed()) {
    count++;
    M5.Display.print("B");
    Serial.print("[");
    Serial.print(count);
    Serial.println("] Button B pressed");
  }
  if (M5.BtnC.wasPressed()) {
    count++;
    M5.Display.clear();
    Serial.print("[");
    Serial.print(count);
    Serial.println("] Screen cleared");
    M5.Display.setCursor(100,150);
  }
  M5.update();
}