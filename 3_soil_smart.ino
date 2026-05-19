#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define SOIL 34
#define POMPA 5
#define LED 18

int batasKering = 1500;
bool modeManual = false;
int pompaManual = 0;

BlynkTimer timer;

BLYNK_WRITE(V3) {
  batasKering = param.asInt();
}

BLYNK_WRITE(V4) {
  modeManual = param.asInt();
}

BLYNK_WRITE(V5) {
  pompaManual = param.asInt();
}

void sendSensor() {
  int nilaiTanah = analogRead(SOIL);
  Blynk.virtualWrite(V0, nilaiTanah);

  if (modeManual) {
    digitalWrite(POMPA, pompaManual);
    digitalWrite(LED, pompaManual);
    Blynk.virtualWrite(V1, pompaManual);
    Blynk.virtualWrite(V2, pompaManual ? "POMPA ON MANUAL" : "POMPA OFF MANUAL");
  } else {
    if (nilaiTanah < batasKering) {
      digitalWrite(POMPA, HIGH);
      digitalWrite(LED, HIGH);
      Blynk.virtualWrite(V1, 1);
      Blynk.virtualWrite(V2, "TANAH KERING");
    } else {
      digitalWrite(POMPA, LOW);
      digitalWrite(LED, LOW);
      Blynk.virtualWrite(V1, 0);
      Blynk.virtualWrite(V2, "TANAH BASAH");
    }
  }

  Serial.print("Kelembaban tanah: ");
  Serial.println(nilaiTanah);
}

void setup() {
  Serial.begin(115200);
  pinMode(POMPA, OUTPUT);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
