#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Object Detector"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define IR 4
#define LED 5
#define BUZZER 18

BlynkTimer timer;

void sendSensor() {
  int objek = digitalRead(IR);

  // Modul IR biasanya LOW saat objek terdeteksi
  if (objek == LOW) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V1, "OBJEK TERDETEKSI");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, "TIDAK ADA OBJEK");
  }

  Serial.print("Status IR: ");
  Serial.println(objek);
}

void setup() {
  Serial.begin(115200);
  pinMode(IR, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
