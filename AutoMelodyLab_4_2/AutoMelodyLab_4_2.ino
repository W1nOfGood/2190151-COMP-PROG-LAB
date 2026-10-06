#include <M5Unified.h>
// Note frequencies for octave 4
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494
#define MSEC_PER_MIN 60000
#define DEFAULT_TEMPO 160
// Melody: Old MacDonald Had a Farm (E I E I O)
int melody[] = { G4, G4, G4, D4, E4, E4, D4, B4, B4, A4, A4, G4 };
int noteValues[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2};
// note value 1 = one beat, 2 = two beats (held longer)
// Automatically count the number of notes -- no need to change this
int numNotes = sizeof(melody) / sizeof(melody[0]);
int tempo = DEFAULT_TEMPO;  // BPM - TODO 2.5: try changing this value
void setup() {
  // initialize M5Stack and speaker
  M5.begin();
  M5.Speaker.setVolume(160);
  M5.Display.setTextSize(3);
  showInfo(tempo);
}
void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    for (int i = 0; i < numNotes; i++) {
      int playTime = noteValues[i] * (MSEC_PER_MIN / tempo);
      M5.Speaker.tone(melody[i], playTime);
      delay(playTime);
      delay(50);
      // TODO 2.2: wait for playTime to finish
      // TODO 2.3: wait a short gap between notes
    }
  }
}

void showInfo(int currentTempo) {
  M5.Display.clear();
  M5.Display.println("Lab 4 - Task 2");
  M5.Display.println("Auto Melody");
  M5.Display.print("BPM: ");
  M5.Display.println(currentTempo);
  M5.Display.println("Press BtnA");
}