// BUTTONS CONTROL LED + REPORT OVER SERIAL
// A = LED on | B = LED off | C = toggle. Also prints state to Serial Monitor.
#include <M5Stack.h>

int ledPin = 21;
int ledState = LOW;

void setLed(int s) {
  ledState = s;
  digitalWrite(ledPin, s);
  Serial.println(s == HIGH ? "LED ON" : "LED OFF");
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 100);
  M5.Lcd.print(s == HIGH ? "ON" : "OFF");
}

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  M5.Lcd.setTextSize(8);
  setLed(LOW);
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) setLed(HIGH);
  if (M5.BtnB.wasPressed()) setLed(LOW);
  if (M5.BtnC.wasPressed()) setLed(!ledState);
}
