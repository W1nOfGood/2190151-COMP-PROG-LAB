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

int melody[] = {
  G4, G4, G4, D4,
  E4, E4, D4,
  B4, B4, A4, A4, G4
};

int noteValues[] = {
  1, 1, 1, 1,
  1, 1, 2,
  1, 1, 1, 1, 2
};

int numNotes = sizeof(melody) / sizeof(melody[0]);

int tempo = DEFAULT_TEMPO;
int currentIndex = 0;
bool isPlaying = false;

void setup() {
  M5.begin();

  M5.Speaker.setVolume(180);

  Serial.begin(115200);

  M5.Display.setTextSize(3);

  showInfo(isPlaying);
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    isPlaying = true;

    showInfo(isPlaying);

    Serial.println(isPlaying);
  }

  if (M5.BtnB.wasPressed()) {
    isPlaying = false;
    M5.Speaker.stop();

    showInfo(isPlaying);
    Serial.println(isPlaying);
  }

  if (isPlaying) {

    int currentNote = melody[currentIndex];
    int noteValue = noteValues[currentIndex];
    int beatTime = MSEC_PER_MIN / tempo;
    int playTime = beatTime * noteValue;

    M5.Speaker.tone(currentNote, playTime);
    delay(playTime);
    delay(50);

    currentIndex++;
    if (currentIndex >= numNotes) {
      currentIndex = 0;
    }
  }
}

void showInfo(bool currentIsPlaying) {
  M5.Display.clear();
  M5.Display.setCursor(0, 0);

  M5.Display.println("Lab 4 - Task 4");

  // TODO 4.4
  if (currentIsPlaying) {
    M5.Display.println("B to pause");
  }
  else {
    M5.Display.println("A to play");
  }
}