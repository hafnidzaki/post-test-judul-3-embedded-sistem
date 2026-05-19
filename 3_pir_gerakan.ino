#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Motion Detector"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define PIR 4
#define LED 5
#define BUZZER 18

BlynkTimer timer;

void sendSensor() {
  int gerakan = digitalRead(PIR);

  if (gerakan == HIGH) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V1, "GERAKAN TERDETEKSI");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, "AMAN");
  }

  Serial.print("Status PIR: ");
  Serial.println(gerakan);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
