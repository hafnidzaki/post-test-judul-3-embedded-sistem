
// Template 16_Relay_Control
// Ganti dengan sensor dan pin sesuai kebutuhan

#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "16_Relay_Control"
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
