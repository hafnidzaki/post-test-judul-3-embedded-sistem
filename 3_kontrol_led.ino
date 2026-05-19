#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Kontrol Lampu"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define LAMPU 5

BLYNK_WRITE(V0) {
  int nilaiSwitch = param.asInt();

  if (nilaiSwitch == 1) {
    digitalWrite(LAMPU, HIGH);
  } else {
    digitalWrite(LAMPU, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LAMPU, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
