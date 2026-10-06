// SCREEN DRAWING REFERENCE (320 x 240 pixels)
// A = shapes | B = text sizes/colors | C = clear
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawRect(10, 10, 100, 60, WHITE);            // outline: x,y,w,h
    M5.Lcd.fillRect(130, 10, 100, 60, RED);             // filled
    M5.Lcd.drawCircle(60, 150, 40, GREEN);              // x,y,radius
    M5.Lcd.fillCircle(180, 150, 40, BLUE);
    M5.Lcd.drawLine(0, 239, 319, 0, YELLOW);            // x1,y1,x2,y2
    M5.Lcd.fillTriangle(250, 100, 300, 100, 275, 50, ORANGE);
  }
  if (M5.BtnB.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.println("Size 2");
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.println("Size 4");
    M5.Lcd.setTextColor(YELLOW, BLUE);                  // text color, background
    M5.Lcd.println("Yellow/Blue");
    M5.Lcd.drawString("At 20,200", 20, 200);            // text at x,y
    // Custom color: M5.Lcd.color565(r, g, b)
  }
  if (M5.BtnC.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
  }
}
