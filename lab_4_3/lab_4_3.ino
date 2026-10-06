#include <M5Unified.h>
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494
#define MSEC_PER_MIN 60000
#define DEFAULT_TEMPO 120
int melody[] = { G4, G4, G4, D4, E4, E4, D4, B4, B4, A4, A4, G4 };
int noteValues[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2 };
int numNotes = sizeof(melody) / sizeof(melody[0]);
int tempo = DEFAULT_TEMPO;
int currentIndex = 0;    // which note to play next
bool isPlaying = false;  // true = playing, false = paused
void setup() {
  M5.begin();
  M5.Speaker.setVolume(160);
  Serial.begin(115200);
  M5.Display.setTextSize(3);
  showInfo(tempo);
}
void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    M5.Speaker.stop();
    tempo = DEFAULT_TEMPO;
    showInfo(tempo);
    for (int i = 0; i < numNotes; i++) {
      int playTime = noteValues[i] * (MSEC_PER_MIN / tempo);
      M5.Speaker.tone(melody[i], playTime);
      delay(playTime);
      delay(50);
    }
  }
  if (M5.BtnB.wasPressed()) {
    M5.Speaker.stop();
    int half_tempo = DEFAULT_TEMPO / 2;
    showInfo(half_tempo);
    for (int i = 0; i < numNotes; i++) {
      int playTimeHALF = noteValues[i] * (MSEC_PER_MIN / half_tempo);
      M5.Speaker.tone(melody[i], playTimeHALF);
      delay(playTimeHALF);
      delay(50);
    }
  }
    if (M5.BtnC.wasPressed()) {
      M5.Speaker.stop();
    int fasttempo = DEFAULT_TEMPO * 2;
    showInfo(fasttempo);
    for (int i = 0; i < numNotes; i++) {
      int playTimeFULL = noteValues[i] * (MSEC_PER_MIN / fasttempo);
      M5.Speaker.tone(melody[i], playTimeFULL);
      delay(playTimeFULL);
      delay(50);
    }
  }
}

void showInfo(int currentTempo) {
  M5.Display.setTextSize(2);
  M5.Display.setCursor(0,0);
  M5.Display.clear();
  M5.Display.println("Lab 4 - Task 3");
  M5.Display.print("BPM: ");
  M5.Display.println(currentTempo);
  M5.Display.println("A = 1x , B = / 2 , C = 2x");
}