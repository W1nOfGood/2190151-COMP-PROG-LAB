#include <M5Unified.h>
void setup() {
  M5.begin();
  Serial.begin(115200);
  Serial.println("Lab 3 - Task 5");
  M5.Display.setTextSize(3);
}
void loop() {
  M5.update();
  if (Serial.available() > 0) {
    char input = (char)Serial.read();  // read one character
    // TODO: print input to Serial Monitor (one line per character)
    switch (input) {
      case 'r':
      case 'R':  // both 'r' and 'R' reach this
        M5.Display.setTextColor(TFT_RED, TFT_BLACK);
        M5.Display.println("RED");
        break;
      case'b':
      case'B':
        M5.Display.setTextColor(TFT_BLUE, TFT_BLACK);
        M5.Display.println("BLUE");
        break;
      case'g':
      case'G':
        M5.Display.setTextColor(TFT_GREEN, TFT_BLACK);
        M5.Display.println("GREEN");
        break;
      default:
        M5.Display.clear();
        M5.Display.setCursor(0,0);
        M5.Display.setTextColor(TFT_YELLOW, TFT_BLACK);
        M5.Display.println("RESET");
        break;
    }
  }
}