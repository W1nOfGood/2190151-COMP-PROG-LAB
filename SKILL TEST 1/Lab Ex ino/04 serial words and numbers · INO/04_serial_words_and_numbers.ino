// SERIAL: READ WHOLE WORDS AND NUMBERS
// Type a line and press Enter (set Serial Monitor to "Newline").
//   "on" / "off" / "toggle"  -> control LED
//   "blink 5"                -> blink LED 5 times
//   "show hello"             -> print text on the screen
#include <M5Stack.h>

int ledPin = 21;
int ledState = LOW;

void setLed(int s) { ledState = s; digitalWrite(ledPin, s); }

void setup() {
  M5.begin();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  setLed(LOW);
  M5.Lcd.setTextSize(3);
}

void loop() {
  M5.update();
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');   // read until Enter
    line.trim();                                  // remove \r and spaces
    line.toLowerCase();

    if (line == "on")           setLed(HIGH);
    else if (line == "off")     setLed(LOW);
    else if (line == "toggle")  setLed(!ledState);
    else if (line.startsWith("blink ")) {
      int times = line.substring(6).toInt();      // number after "blink "
      for (int i = 0; i < times; i++) {
        setLed(HIGH); delay(300);
        setLed(LOW);  delay(300);
      }
    }
    else if (line.startsWith("show ")) {
      M5.Lcd.fillScreen(BLACK);
      M5.Lcd.setCursor(0, 100);
      M5.Lcd.print(line.substring(5));
    }
    else {
      Serial.println("Unknown command");
    }
  }
}
