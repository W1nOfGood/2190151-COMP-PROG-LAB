// Public copy: fill in the placeholders below locally before uploading to your board.
#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
#define BLYNK_PRINT Serial

#include <M5Unified.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

const int LED_PIN = 22;
int ledState = LOW;
const int GREEN_LED_PIN = 21;

void showLedState(int state) {
  M5.Display.setCursor(0, 80);
  if (state == HIGH) {
    M5.Display.print("LED: ON ");
  } else {
    M5.Display.print("LED: OFF");
  }
}

BlynkTimer timer;

BLYNK_WRITE(V0) {
  ledState = param.asInt();
  digitalWrite(LED_PIN, ledState);
  Blynk.virtualWrite(V1, ledState);
  showLedState(ledState);
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
  Blynk.setProperty(V4, "color", M5.BtnC.isPressed() ? "#00FF00" : "#FF0000");
  Blynk.virtualWrite(V4, M5.BtnC.isPressed() ? HIGH : LOW);
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void myTimerEvent() {
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup() {
  M5.begin();
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.setCursor(0, 0);
  M5.Display.setTextSize(2);
  M5.Display.setTextColor(TFT_WHITE, TFT_BLACK);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(GREEN_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
  M5.Display.println("Lab 7 - Blynk");
  M5.Display.println("Connecting...");
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  M5.Display.setCursor(0, 48);
  M5.Display.println("Connected to Blynk!");
  showLedState(ledState);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  M5.update();

  if (M5.BtnB.wasPressed()) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    showLedState(ledState);
    Blynk.virtualWrite(V1, ledState);
    Blynk.virtualWrite(V0, ledState);
    Serial.print("Button B: LED ");
    Serial.println(ledState ? "ON" : "OFF");
  }
  Blynk.run();
  timer.run();

  if (M5.BtnC.wasPressed()) {
    Serial.println("Button C: 1 (pressed)");
    Blynk.setProperty(V4, "color", "#00FF00");
    Blynk.virtualWrite(V4, HIGH);
  }
  if (M5.BtnC.wasReleased()) {
    Serial.println("Button C: 0 (released)");
    Blynk.setProperty(V4, "color", "#FF0000");
    Blynk.virtualWrite(V4, LOW);
  }
}
