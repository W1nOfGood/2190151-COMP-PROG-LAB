// BLINK WITHOUT delay() USING millis()
// LED blinks every 500 ms AND buttons still respond instantly.
// A = faster, B = slower, C = pause/resume.
#include <M5Stack.h>

int ledPin = 21;
int ledState = LOW;
unsigned long lastToggle = 0;     // time of last toggle
unsigned long interval = 500;     // ms between toggles
bool running = true;

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed() && interval > 100)  { interval -= 100; Serial.println(interval); }
  if (M5.BtnB.wasPressed() && interval < 2000) { interval += 100; Serial.println(interval); }
  if (M5.BtnC.wasPressed()) running = !running;

  if (running && millis() - lastToggle >= interval) {
    lastToggle = millis();
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
