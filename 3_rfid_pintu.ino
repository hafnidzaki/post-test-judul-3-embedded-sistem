
// Template 13_RFID_Smart_Door
// Ganti dengan sensor dan pin sesuai kebutuhan

#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "13_RFID_Smart_Door"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[]="Wokwi-GUEST";
char pass[]="";

void setup(){
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
}

void loop(){
  Blynk.run();
}
