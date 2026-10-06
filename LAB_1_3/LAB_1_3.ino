#include <M5Unified.h>
/* the setup routine runs once when
M5Stack is started or reset */
int um;
void setup() {

  M5.begin();            // initialize M5Stack
  Serial.begin(115200);  // initialize serial communication

  um = 0;

  M5.Display.setTextSize(3);
  M5.Display.setCursor(10, 30);

  delay(1000);
  M5.Display.setTextColor(TFT_GREEN);
  M5.Display.println(um);
  delay(1000);
  M5.Display.setTextColor(TFT_CYAN);
  M5.Display.println("Lab 1");
  M5.Display.setTextColor(TFT_WHITE);
  M5.Display.println("Task 3");

  Serial.println("Lab 1 - Task 3");
}

void loop() {
  Serial.println(um);
  um++;
  delay(500);
  M5.Display.clear();
  M5.Display.setTextColor(TFT_GREEN);
  M5.Display.println(um);
  
  delay(1000);
}