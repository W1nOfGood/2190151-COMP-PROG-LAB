#include <M5Unified.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define WIFI_SSID "YourWiFiName"
#define WIFI_PASSWORD "YourWiFiPassword"

const long connectionTimeout = 15000;
const int statusCheckDelay = 500;

int responseCount = 0; // number of successful API responses

void startWiFi();
void handleButtonAPressed();
String performApiRequest(String url);

void setup() {
  M5.begin();
  Serial.begin(115200);
  M5.Display.setTextSize(2);
  M5.Display.println("Lab 6 - WiFi Client");
  startWiFi();
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    Serial.println("Button A is pressed");
    handleButtonAPressed();
    Serial.println("-------------------");
  }
  delay(200); // small delay to deal with slower network access
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

void handleButtonAPressed() {
  String apiURL = "http://official-joke-api.appspot.com/random_joke";
  String payload = performApiRequest(apiURL);
  if (payload != "") {
    // --- Display on Serial Monitor ---
    Serial.printf("--- RAW RESPONSE #%d --- \n", responseCount);
    Serial.println(payload);

    // --- Display on LCD ---
    M5.Display.clear();
    M5.Display.setCursor(0, 0);
    M5.Display.printf("Got a new joke! #%d\n", responseCount);
    M5.Display.println("Check Serial Monitor for the full text.");
  } else {
    M5.Display.setTextColor(TFT_RED);
    M5.Display.println("Request failed.");
    M5.Display.setTextColor(TFT_WHITE);
  }
}

String performApiRequest(String url) {
  Serial.print("Making request to: ");
  Serial.println(url);

  HTTPClient http;
  String payload = "";
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    payload = http.getString();
    ++responseCount; // count successful response
  } else {
    Serial.printf("Request to %s failed, error: %s\n",
                  url.c_str(), http.errorToString(httpCode).c_str());
  }
  http.end();
  return payload;
}
