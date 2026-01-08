#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define INDOOR_TEST true  // Indoor mock GPS

#define GREEN_LED 7      // GPS update / moving
#define RED_LED 9        // Satellite searching
#define BUZZER 8

TinyGPSPlus gps;
SoftwareSerial gpsSerial(4, 3); // RX, TX

// Simulated coordinates
double latitudes[]  = {26.123400, 26.123420, 26.123450, 26.123480, 26.123500};
double longitudes[] = {85.123400, 85.123420, 85.123450, 85.123480, 85.123500};
int steps = 5;
int indexPos = 0;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Indoor Moving GPS Tracking Started...");
}

void loop() {
  if (INDOOR_TEST) {
    // --- Mock coordinates (Indoor) ---
    digitalWrite(RED_LED, LOW); // Searching not needed in mock
    digitalWrite(GREEN_LED, HIGH);
    tone(BUZZER, 1000, 200);

    double lat = latitudes[indexPos];
    double lng = longitudes[indexPos];

    Serial.print("Coordinates: ");
    Serial.print(lat, 6);
    Serial.print(", ");
    Serial.println(lng, 6);

    Serial.print("Google Maps Link: ");
    Serial.print("https://maps.google.com/?q=");
    Serial.print(lat, 6);
    Serial.print(",");
    Serial.println(lng, 6);

    Serial.println("----------------------");

    delay(200);
    digitalWrite(GREEN_LED, LOW);
    delay(1800); // total 2s per update

    // Move to next coordinate
    indexPos++;
    if(indexPos >= steps) indexPos = 0;
  }
  else {
    // --- Real GPS Mode ---
    bool searching = true;

    while (gpsSerial.available()) {
      gps.encode(gpsSerial.read());

      if (gps.satellites.value() > 0) searching = false;

      if (searching) {
        digitalWrite(RED_LED, HIGH); // Searching
      } else {
        digitalWrite(RED_LED, LOW);
      }

      if (gps.location.isUpdated()) {
        digitalWrite(GREEN_LED, HIGH); // GPS update
        tone(BUZZER, 1000, 200);

        Serial.print("Coordinates: ");
        Serial.print(gps.location.lat(), 6);
        Serial.print(", ");
        Serial.println(gps.location.lng(), 6);

        Serial.print("Satellites: ");
        Serial.println(gps.satellites.value());

        Serial.print("Google Maps Link: ");
        Serial.print("https://maps.google.com/?q=");
        Serial.print(gps.location.lat(), 6);
        Serial.print(",");
        Serial.println(gps.location.lng(), 6);

        Serial.println("----------------------");

        delay(200);
        digitalWrite(GREEN_LED, LOW);
      }
    }
  }
}
