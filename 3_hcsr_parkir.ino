#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Parking"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define TRIG 5
#define ECHO 18
#define BUZZER 19
#define LED 21

int batasJarak = 20;
BlynkTimer timer;

BLYNK_WRITE(V3) {
  batasJarak = param.asInt();
}

float bacaJarak() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long durasi = pulseIn(ECHO, HIGH);
  float jarak = durasi * 0.034 / 2;

  return jarak;
}

void sendSensor() {
  float jarak = bacaJarak();

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  Blynk.virtualWrite(V0, jarak);

  if (jarak <= batasJarak) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1200);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, "TERLALU DEKAT");
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, "AMAN");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
