#include <M5Unified.h>
void setup() {
  M5.begin();
  Serial.begin(9600);  // M5Stack sends at 57600 baud
  Serial.println("Lab 3 - Task 1");
}
void loop() {
  Serial.print("Can you read?");
}