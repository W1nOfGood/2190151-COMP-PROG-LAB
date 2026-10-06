#include <M5Unified.h>
int count = 0;  // counts how many strings have been received
void setup() {
  M5.begin();
  Serial.begin(115200);
  Serial.println("Lab 3 - Task 4");
  M5.Display.setTextSize(3);
}
void loop() {
  M5.update();
  if (Serial.available() > 0) {
    String text = Serial.readString();  // read the whole input
    count++;                            // increment counter
    Serial.print(count);
    Serial.print(" - ");
    Serial.println(text);      // show in Serial Monitor
    if (count % 2 == 0) {
      M5.Display.print(count);
      M5.Display.print(": ");
      M5.Display.println(text);
    }
    else {
      M5.Display.print("Odd: ");
      M5.Display.println(text);
    }
  }
}