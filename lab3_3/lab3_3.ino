#include <M5Unified.h>
void setup() {
  M5.begin();
  M5.Display.setTextSize(3);
  M5.Display.setTextColor(TFT_BLUE, TFT_YELLOW);
  Serial.begin(115200);
  Serial.println("Lab 3 – Task 3");
}
void loop() {
  M5.update();
  if (Serial.available() > 0) {    // check if data is waiting
    int readByte = Serial.read();  // read one byte
    Serial.print('[');
    Serial.print((char)readByte);  // print ASCII value (integer)
    Serial.print(' ');
    Serial.print(readByte, HEX);  // print ASCII value in HEX
    Serial.println(']');
    M5.Display.print((char)readByte);
    }
}