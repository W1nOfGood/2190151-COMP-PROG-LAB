// SERIAL COMMANDS -> LED (single characters)
// o/O on | f/F off | t/T toggle | b/B blink 3x then on | anything else off
// Open Serial Monitor at 115200 baud. Set line ending to "No line ending"
// (or keep the \n / \r cases below, which ignore Enter).
#include <M5Stack.h>

int ledPin = 21;
int ledState = LOW;

void setLed(int s) {
  ledState = s;
  digitalWrite(ledPin, ledState);
}

void blinkN(int times, int ms) {
  for (int i = 0; i < times; i++) {
    setLed(HIGH);
    delay(ms);
    setLed(LOW);
    delay(ms);
  }
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
    Serial.write(key);                 // echo

    switch (key) {
      case 'o': case 'O': setLed(HIGH); break;
      case 'f': case 'F': setLed(LOW);  break;
      case 't': case 'T': setLed(!ledState); break;
      case 'b': case 'B':
        blinkN(3, 500);
        setLed(HIGH);                  // end ON
        break;
      case '\n': case '\r': break;     // ignore Enter
      default: setLed(LOW); break;
    }
  }
}
