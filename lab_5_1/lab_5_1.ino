#include <M5Unified.h>
#include <DHT.h>
#include <math.h>

#define DHTPIN 21
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int reading_count = 0;
float prev_humid = -100.0f;
float prev_tempC = -100.0f;
const float HUMID_THRESHOLD = 0.2f;
const float TEMP_THRESHOLD = 0.1f;
bool display_enabled = true;
bool showCelsius = true;
bool have_reading = false;
float last_humid, last_tempC, last_tempF;
unsigned long last_read_ms = 0;

void update_LCD(int count, float humidity, float celsius, float fahrenheit) {
  M5.Display.clear();
  M5.Display.setCursor(0, 0);
  M5.Display.printf("Reading #%d\n", count);
  M5.Display.printf("Humidity: %.2f%%\n", humidity);
  if (showCelsius) M5.Display.printf("Temp: %.2fC\n", celsius);
  else M5.Display.printf("Temp: %.2fF\n", fahrenheit);
}

void setup() {
  M5.begin();
  M5.Display.setTextSize(2);
  M5.Display.setBrightness(255);
  M5.Display.println("Lab 5 - DHT Sensor");
  Serial.begin(115200);
  Serial.println("Lab 5 - DHT Sensor");
  dht.begin();
  Serial.println("DHT sensor initialized. Waiting for first reading...");
  last_read_ms = millis();
}

void loop() {
  M5.update();
  // Wait two seconds between reads without blocking button handling.
  unsigned long now = millis();
  if (now - last_read_ms < 2000UL) {
    delay(5);
    return;
  }
  last_read_ms = now;
  float humid = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  if (isnan(humid) || isnan(tempC) || isnan(tempF)) {
    Serial.println("ERROR: Sensor read failed! Skipping this reading.");
    return;
  }
  reading_count++;
  Serial.printf("%03d | Humidity: %.2f%% | Temp: %.2fC / %.2fF\n",
                reading_count, humid, tempC, tempF);
  last_humid = humid;
  last_tempC = tempC;
  last_tempF = tempF;
  have_reading = true;
  update_LCD(reading_count, humid, tempC, tempF);
}
