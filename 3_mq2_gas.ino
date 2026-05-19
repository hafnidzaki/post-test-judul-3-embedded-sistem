#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Gas Detector"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define MQ2 34
#define BUZZER 5
#define LED 18

int batasGas = 1800;
BlynkTimer timer;

BLYNK_WRITE(V3) {
  batasGas = param.asInt();
}

void sendSensor() {
  int gasValue = analogRead(MQ2);

  Serial.print("Nilai Gas: ");
  Serial.println(gasValue);

  Blynk.virtualWrite(V0, gasValue);

  if (gasValue > batasGas) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, "BAHAYA");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, "AMAN");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
