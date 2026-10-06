#include <M5Unified.h>

#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494

int melody[] = {
  G4, G4, G4, D4,
  E4, E4, D4,
  B4, B4, A4, A4, G4
};

int numNotes = sizeof(melody) / sizeof(melody[0]);

int currentIndex = 0;

void setup() {
  M5.begin();

  M5.Speaker.setVolume(180);

  Serial.begin(115200);

  M5.Display.setTextSize(3);

  showCurrentNote();
}

void loop() {
  M5.update();

  // Button C pressed
  if (M5.BtnC.wasPressed()) {
    M5.Speaker.tone(melody[currentIndex]);

    Serial.print("Playing note ");
    Serial.println(currentIndex);
  }

  // Button C released
  if (M5.BtnC.wasReleased()) {
    M5.Speaker.stop();

    // Advance to next note
    currentIndex++;

    // Wrap back to note 0
    if (currentIndex >= numNotes) {
      currentIndex = 0;
    }

    // Update LCD
    showCurrentNote();

    Serial.print("Stopped. Next note: ");
    Serial.println(currentIndex);
  }
}

void showCurrentNote() {
  M5.Display.clear();
  M5.Display.setCursor(0, 0);

  M5.Display.println("Lab 4 - Task 5");
  M5.Display.print("Note: ");
  M5.Display.println(currentIndex);
}