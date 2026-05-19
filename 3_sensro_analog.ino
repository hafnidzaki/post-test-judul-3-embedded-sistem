#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Sensor Analog Umum"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define SENSOR_ANALOG 34
#define LED 5
#define BUZZER 18

int batas = 2000;
BlynkTimer timer;

BLYNK_WRITE(V3) {
  batas = param.asInt();
}

void sendSensor() {
  int nilai = analogRead(SENSOR_ANALOG);

  Blynk.virtualWrite(V0, nilai);

  if (nilai > batas) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, "MELEBIHI BATAS");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, "NORMAL");
  }

  Serial.print("Nilai Sensor: ");
  Serial.println(nilai);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
