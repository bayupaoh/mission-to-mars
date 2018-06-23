#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Wire.h>

#define FIREBASE_HOST "friendlychat-5bc76.firebaseio.com"
#define FIREBASE_AUTH "eTnf0PhzjznwjTzTG3ABPYJKwKfYNSbd9veeeMWu"
#define WIFI_SSID "tes"
#define WIFI_PASSWORD ""

int lamp = D1;

void setup() {
    Serial.begin(9600);
    // set pin mode ke output
    pinMode(lamp, OUTPUT);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.set(“lampuOn", 0);

}

void loop()
{
    int event = Firebase.getInt(“lampuOn”);
    if (event == 1) {
        Serial.println("nyala");
        digitalWrite(lamp, HIGH);
        delay(500);
    } else {
        Serial.println("mati");
        digitalWrite(lamp, LOW);
        delay(250);
    }
}

