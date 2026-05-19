#define BLYNK_TEMPLATE_ID "ISI_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Room"
#define BLYNK_AUTH_TOKEN "ISI_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR 34
#define LAMPU 5
#define BUZZER 18

float batasSuhu = 30.0;
int batasGelap = 1000;

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

BLYNK_WRITE(V5) {
  batasSuhu = param.asFloat();
}

BLYNK_WRITE(V6) {
  batasGelap = param.asInt();
}

void sendSensor() {
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();
  int cahaya = analogRead(LDR);

  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Sensor DHT tidak terbaca");
    return;
  }

  Blynk.virtualWrite(V0, suhu);
  Blynk.virtualWrite(V1, kelembaban);
  Blynk.virtualWrite(V2, cahaya);

  if (cahaya < batasGelap) {
    digitalWrite(LAMPU, HIGH);
    Blynk.virtualWrite(V3, 1);
  } else {
    digitalWrite(LAMPU, LOW);
    Blynk.virtualWrite(V3, 0);
  }

  if (suhu >= batasSuhu) {
    tone(BUZZER, 1000);
    Blynk.virtualWrite(V4, "SUHU PANAS");
  } else {
    noTone(BUZZER);
    Blynk.virtualWrite(V4, "NORMAL");
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" | RH: ");
  Serial.print(kelembaban);
  Serial.print(" | LDR: ");
  Serial.println(cahaya);
}

void setup() {
  Serial.begin(115200);
  pinMode(LAMPU, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
