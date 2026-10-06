#include <M5Unified.h>
#include "DHT.h"
// ===== SENSOR CONFIGURATION =====
// DHTPIN: The GPIO pin that the sensor's DATA line is connected to
// DHTTYPE: The sensor model (DHT22 is more accurate; DHT11 is cheaper)
#define DHTPIN 21
#define DHTTYPE DHT22
// ===== GLOBAL VARIABLES =====
// Create a DHT object to communicate with the sensor
DHT dht(DHTPIN, DHTTYPE);
// Track how many successful readings we've had
int reading_count = 0;
void setup() {
  // Initialize M5Stack display, buttons, and speaker
  M5.begin();
  // Set LCD display preferences
  M5.Display.setTextSize(3);  // Medium text size
  M5.Display.println("Lab 5 - DHT Sensor");
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("Lab 5 - DHT Sensor");
  // Initialize the DHT sensor
  dht.begin();
  Serial.println("DHT sensor initialized. Waiting for first reading...");
}
void loop() {
  // ===== STEP 1: WAIT FOR SENSOR STABILITY =====
  // Don't read too frequently—the sensor needs time to settle
  delay(2000);
  // ===== STEP 2: READ SENSOR VALUES =====
  // readHumidity() returns humidity as a floating-point percentage (e.g.,45.5)
float humid = dht.readHumidity();
// readTemperature() returns temperature in Celsius by default
float tempC = dht.readTemperature();
// readTemperature(true) returns temperature in Fahrenheit
float tempF = dht.readTemperature(true);
// ===== STEP 3: ERROR CHECKING =====
// If the sensor read failed, it returns NaN (Not a Number)
// isnan() checks if a value is NaN
// We should NEVER display NaN to the user—it's meaningless
if (isnan(humid) || isnan(tempC) || isnan(tempF)) {
  Serial.println("ERROR: Sensor read failed! Skipping this reading.");
  return;  // Skip the rest of this loop iteration
}
// ===== STEP 4: PROCESS DATA =====
// Count how many successful readings we've had
reading_count++;
// ===== STEP 5: DISPLAY ON SERIAL MONITOR =====
// Serial.printf() is like printf() in C—it formats text with placeholders
// %03d = integer with leading zeros (e.g., 001, 042, 100)
// %.2f = floating-point number with 2 decimal places (e.g., 23.47)
// %% = a single percent sign (%)
Serial.printf("%03d | ", reading_count);

Serial.printf("Humidity: %.2f%% | ", humid);
Serial.printf("Temp: %.2fC / %.2fF\n", tempC, tempF);
// ===== STEP 6: DISPLAY ON LCD =====
update_LCD(reading_count, humid, tempC, tempF);
}
void update_LCD(int count, float humidity, float celsius, float fahrenheit) {
  // Clear the LCD before displaying new data
  M5.Display.clear();
  M5.Display.setCursor(0, 0);
  // Display the reading number
  M5.Display.print("Reading #");
  M5.Display.println(count);
  // Display humidity with formatting
  M5.Display.printf("Humidity: %.2f%%\n", humidity);
  // Display temperature in Celsius
  M5.Display.printf("Temp: %.2fC\n", celsius);
}