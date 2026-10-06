#include <M5Unified.h>

int ledPin = 21;
int ledState = LOW;

// Write a state to the LED AND remember it in ledState
void setLed(int state) {
  ledState = state;
  digitalWrite(ledPin, ledState);
}

// Blink 3 times (500 ms on / 500 ms off), then leave the LED ON
void blinkThree() {
  for (int i = 0; i < 3; i++) {
    setLed(HIGH);
    delay(500);
    setLed(LOW);
    delay(500);
  }
  setLed(HIGH);
}

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  setLed(LOW);
}

void loop() {
  M5.update();

  if (Serial.available() > 0) {
    int key = Serial.read();
    Serial.write(key);           // echo the key back

    switch (key) {
      case 'o':
      case 'O':
        setLed(HIGH);
        break;

      case 'b':
      case 'B':
        blinkThree();
        break;

      case 't':
      case 'T':
        setLed(!ledState);
        break;

      case '\n':                 // ignore Enter / newline characters
      case '\r':
        break;

      default:
        setLed(LOW);             // any other key: LED off
        break;
    }
  }
}
