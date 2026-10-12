#include <M5Unified.h>
#include <WiFi.h>

// --- WiFi Credentials --- (replace with your own network)
#define WIFI_SSID "YourWiFiName"
#define WIFI_PASSWORD "YourWiFiPassword"

const long connectionTimeout = 15000; // Timeout 15 seconds
const int statusCheckDelay = 500;     // Delay between checks

void startWiFi();

void setup() {
  M5.begin();
  Serial.begin(115200);
  M5.Display.setTextSize(2);
  M5.Display.println("Lab 6 - WiFi Client");
  startWiFi();
}

void loop() {
  // Nothing to do here for this part
}

void startWiFi() {
  M5.Display.printf("Connecting to %s ", WIFI_SSID);
  Serial.printf("Connecting to %s ", WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED && (millis() - startTime) < connectionTimeout) {
    delay(statusCheckDelay);
    M5.Display.print(".");
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    M5.Display.setTextColor(TFT_GREEN);
    M5.Display.println("\nWiFi Connected!");
    M5.Display.print("IP: ");
    M5.Display.println(WiFi.localIP());
    M5.Display.setTextColor(TFT_WHITE);

    Serial.println("\nWiFi Connected!");
    Serial.printf("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    M5.Display.setTextColor(TFT_RED);
    M5.Display.println("\nWiFi Connection Failed!");
    M5.Display.println("Please check credentials or network and reset.");
    M5.Display.setTextColor(TFT_WHITE);
    Serial.println("\nWiFi connection failed after 15 seconds.");
  }
}
