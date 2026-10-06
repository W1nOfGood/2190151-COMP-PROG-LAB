#include <M5Stack.h>
int ledPin = 21;
int ledState = LOW;
void setup() {
  M5.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}
void loop() {
if (Serial.available() > 0) {
    int key = Serial.read();
    Serial.write(key);
    switch (key) {
      case 'o':
        digitalWrite(ledPin, HIGH);
        break;
      case 'O':
        digitalWrite(ledPin, HIGH);
        break;


      case 'b':
        if (ledState = LOW) {

          for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          }
          digitalWrite(ledPin, HIGH);
        }
        else {
          digitalWrite(ledPin, LOW);
          for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          }
          digitalWrite(ledPin, HIGH);
        }
        break;
        case 'B':
        if (ledState = LOW) {

          for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          }
          digitalWrite(ledPin, HIGH);
        }
        else {
          digitalWrite(ledPin, LOW);
          for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          }
          digitalWrite(ledPin, HIGH);
        }
        break;

      case 't':
        ledState = !ledState; 
        digitalWrite(ledPin, ledState);
        break;
      case 'T':
        ledState = !ledState; 
        digitalWrite(ledPin, ledState);
        break;


        default:
          digitalWrite(ledPin, LOW);
        break;



      

    }
}
}