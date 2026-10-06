// SPEAKER: TONES, MELODY, ARRAYS + FOR LOOP
// A = play scale (C D E F G A B C) | B = beep | C = volume up (cycles 1..8)
#include <M5Stack.h>

// Note frequencies (Hz)
int notes[] = {262, 294, 330, 349, 392, 440, 494, 524};
int volume = 2;

void setup() {
  M5.begin();
  M5.Speaker.setVolume(volume);
  M5.Lcd.setTextSize(4);
  M5.Lcd.println("A:scale B:beep");
  M5.Lcd.println("C:volume");
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    for (int i = 0; i < 8; i++) {
      M5.Speaker.tone(notes[i]);
      delay(300);
    }
    M5.Speaker.mute();
  }
  if (M5.BtnB.wasPressed()) {
    M5.Speaker.tone(1000, 200);   // tone(freq, duration_ms)
  }
  if (M5.BtnC.wasPressed()) {
    volume++;
    if (volume > 8) volume = 1;
    M5.Speaker.setVolume(volume);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 100);
    M5.Lcd.print("Vol ");
    M5.Lcd.print(volume);
    M5.Speaker.tone(440, 200);
  }
}
