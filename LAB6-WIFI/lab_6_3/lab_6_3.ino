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
void handleButtonBPressed();
String performApiRequest(String url);
String extractValue(const String &json, const String &key);

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
  if (M5.BtnB.wasPressed()) {
    Serial.println("Button B is pressed");
    handleButtonBPressed();
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

// Button A: random joke -> setup (orange) + punchline (green)
void handleButtonAPressed() {
  String payload = performApiRequest("http://official-joke-api.appspot.com/random_joke");
  if (payload != "") {
    Serial.printf("--- RAW RESPONSE #%d --- \n", responseCount);
    Serial.println(payload);

    String setupText = extractValue(payload, "setup");
    String punchline = extractValue(payload, "punchline");

    M5.Display.clear();
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(TFT_ORANGE);
    M5.Display.println(setupText);
    M5.Display.println();
    M5.Display.setTextColor(TFT_GREEN);
    M5.Display.println(punchline);
    M5.Display.setTextColor(TFT_WHITE);
  } else {
    M5.Display.setTextColor(TFT_RED);
    M5.Display.println("Request failed.");
    M5.Display.setTextColor(TFT_WHITE);
  }
}

// Button B: Bitcoin price in USD (BTCUSDT)
void handleButtonBPressed() {
  String payload = performApiRequest("https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT");
  if (payload != "") {
    Serial.printf("--- RAW RESPONSE #%d --- \n", responseCount);
    Serial.println(payload);

    String price = extractValue(payload, "price");

    M5.Display.clear();
    M5.Display.setCursor(0, 0);
    M5.Display.setTextColor(TFT_YELLOW);
    M5.Display.println("Bitcoin (USD)");
    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.println(price);
  } else {
    M5.Display.setTextColor(TFT_RED);
    M5.Display.println("Request failed.");
    M5.Display.setTextColor(TFT_WHITE);
  }
}

// Extract the string value of "key":"value" using indexOf/substring
String extractValue(const String &json, const String &key) {
  String startPattern = "\"" + key + "\":\"";
  int startIndex = json.indexOf(startPattern);
  if (startIndex < 0) return "";
  startIndex += startPattern.length();

  // find the closing quote, skipping escaped quotes (\")
  int endIndex = startIndex;
  while (true) {
    endIndex = json.indexOf("\"", endIndex);
    if (endIndex < 0) return "";
    if (json.charAt(endIndex - 1) != '\\') break;
    endIndex++;
  }
  String value = json.substring(startIndex, endIndex);
  value.replace("\\\"", "\"");
  return value;
}

// Retry version of the API request (5 tries, 3 s apart)
String performApiRequest(String url) {
  Serial.print("Making request to: ");
  Serial.println(url);
  HTTPClient http;
  for (int i = 0; i < 5; ++i) {
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      ++responseCount;
      String payload = http.getString();
      http.end();
      return payload;
    } else {
      Serial.printf("Request to %s failed, error: %s\n",
                    url.c_str(), http.errorToString(httpCode).c_str());
      Serial.printf("Retry...#%d\n", i + 1);
    }
    delay(3000);
  }
  Serial.println("Server not response.");
  http.end();
  return "";
}
