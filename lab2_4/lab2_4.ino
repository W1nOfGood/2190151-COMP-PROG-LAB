#include <M5Unified.h>
const int ledPinBlue = 21;
const int ledPinGreen = 22;
int ledStateB = LOW;
int ledStateG = LOW;
void setup() {
  M5.begin();
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  digitalWrite(ledPinBlue, ledStateB);
  digitalWrite(ledPinGreen, ledStateG);
}
void loop() {
  M5.update();  // must call this every loop to read button states
  if (M5.BtnA.wasPressed()) {
    ledStateB = !ledStateB;  // flip: LOW becomes HIGH, HIGH becomes LOW
    digitalWrite(ledPinBlue, ledStateB);
  }
  if (M5.BtnB.wasPressed()) {
    ledStateG = !ledStateG;
    digitalWrite(ledPinGreen, ledStateG);
  }
  if (M5.BtnC.wasPressed()) {
    ledStateB = LOW;
    ledStateG = LOW;
    digitalWrite(ledPinBlue, ledStateB);
    digitalWrite(ledPinGreen, ledStateG);
  }
}