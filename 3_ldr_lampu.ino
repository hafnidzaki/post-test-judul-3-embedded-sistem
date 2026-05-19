#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Lampu Otomatis"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define LDR 34
#define LED 5

int batasGelap = 1000;
bool modeManual = false;
int statusManual = 0;

BlynkTimer timer;

BLYNK_WRITE(V2) {
  modeManual = param.asInt();
}

BLYNK_WRITE(V3) {
  statusManual = param.asInt();
}

BLYNK_WRITE(V4) {
  batasGelap = param.asInt();
}

void sendSensor() {
  int nilaiCahaya = analogRead(LDR);
  Blynk.virtualWrite(V0, nilaiCahaya);

  if (modeManual) {
    digitalWrite(LED, statusManual);
    Blynk.virtualWrite(V1, statusManual);
  } else {
    if (nilaiCahaya < batasGelap) {
      digitalWrite(LED, HIGH);
      Blynk.virtualWrite(V1, 1);
    } else {
      digitalWrite(LED, LOW);
      Blynk.virtualWrite(V1, 0);
    }
  }

  Serial.print("Nilai LDR: ");
  Serial.println(nilaiCahaya);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
