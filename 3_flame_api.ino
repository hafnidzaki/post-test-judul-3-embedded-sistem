#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Fire Alarm"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define FLAME 4
#define BUZZER 5
#define LED 18

BlynkTimer timer;

void sendSensor() {
  int api = digitalRead(FLAME);

  // Flame sensor biasanya LOW saat api terdeteksi
  if (api == LOW) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V1, "API TERDETEKSI");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, "AMAN");
  }

  Serial.print("Status Flame: ");
  Serial.println(api);
}

void setup() {
  Serial.begin(115200);
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
