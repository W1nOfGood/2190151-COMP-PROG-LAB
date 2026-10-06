#include <M5Unified.h>
const int ledPin = 21;
int ledState = LOW;
void setup() {
  M5.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}
void loop() {
  M5.update();  // must call this every loop to read button states
  if (M5.BtnA.wasPressed() || M5.BtnB.wasPressed() || M5.BtnC.wasPressed()) {
    ledState = !ledState;  // flip: LOW becomes HIGH, HIGH becomes LOW
    digitalWrite(ledPin, ledState);
  }
}