#include <M5Unified.h>

int ledPinB = 21;
int ledPinG = 22;
int ledStateB = LOW;
int ledStateG = LOW;

void setLedB(int state) {
  ledStateB = state;
  digitalWrite(ledPinB, ledStateB);
}

void setLedG(int state) {
  ledStateG = state;
  digitalWrite(ledPinG, ledStateG);
}

void blinkTwo(int state) {
  setLedB(LOW);
  setLedG(LOW);
  for (int i = 0; i < 2; i++) {
    setLedB(HIGH);
    delay(500);
    setLedB(LOW);
    delay(500);
    setLedG(HIGH);
    delay(500);
    setLedG(LOW);
    delay(500);
  }
  setLedB(state);
  setLedG(LOW);
}

void blinkOne() {
  setLedB(LOW);
  setLedG(HIGH);
  delay(500);
  setLedB(LOW);
  setLedG(LOW);
}

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  setLedB(LOW);
  setLedG(LOW);
}

void loop() {
  M5.update();

  if (Serial.available() > 0) {
    int key = Serial.read();
    Serial.write(key);
    switch (key) {
      case '0':
        setLedB(LOW);
        setLedG(LOW);
        break;


      case '1':
        setLedB(!ledStateB);
        break;


      case '2':
        blinkTwo(ledStateB);
        break;

      case '\n':
      case '\r':
        break;

      default:
        blinkOne();
        break;
    }
  }
}
