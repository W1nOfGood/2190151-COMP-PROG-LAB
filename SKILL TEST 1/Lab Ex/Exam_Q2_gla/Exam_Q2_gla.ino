#include <M5Stack.h>
int ledPin = 21;
int ledState = LOW;

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}
void loop() {
  M5.update();
  if (Serial.available() > 0) {
    int text = Serial.read();

    // add code here
    switch (text) {
      case 'o':
      case 'O':

        digitalWrite(ledPin, HIGH);
        break;
      case 't':
      case 'T':
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        break;
      case 'b':
      case 'B':
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(500);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);

        break;
        // add more cases here
      default:
        digitalWrite(ledPin, LOW);

        break;
    }
  }
}