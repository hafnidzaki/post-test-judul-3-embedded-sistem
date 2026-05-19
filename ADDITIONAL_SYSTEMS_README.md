# IoT Additional Systems - Post Test Embedded System

Kumpulan sistem tambahan berbasis ESP32 + Blynk + Wokwi yang dapat
digunakan sebagai latihan atau cadangan ketika studi kasus post-test
berbeda dari modul utama.

Semua project menggunakan: - ESP32 - WiFi Wokwi (`Wokwi-GUEST`) -
Blynk - Virtual Pin - Sensor / Aktuator sesuai studi kasus

------------------------------------------------------------------------

## 13. RFID Smart Door

Sistem akses pintu pintar menggunakan RFID.

Komponen: - ESP32 - RFID RC522 - Servo SG90 - LED - Buzzer

Widget Blynk: - V0 → Status kartu - V1 → Status pintu - V2 → LED
indikator

------------------------------------------------------------------------

## 14. Rain Sensor IoT

Komponen: - ESP32 - Rain Sensor - LED - Buzzer

Widget Blynk: - V0 → Intensitas hujan - V1 → Status hujan

------------------------------------------------------------------------

## 15. Servo Control IoT

Komponen: - ESP32 - Servo SG90

Widget Blynk: - V0 → Slider servo (0--180)

------------------------------------------------------------------------

## 16. Relay Control IoT

Komponen: - ESP32 - Relay - Lampu

Widget Blynk: - V0 → Switch ON/OFF

------------------------------------------------------------------------

## 17. LCD I2C + IoT

Komponen: - ESP32 - LCD I2C - Sensor (DHT/LDR/MQ2)

Widget Blynk: - V0 → Sensor utama - V1 → Status sistem

------------------------------------------------------------------------

## 18. Telegram Alert IoT

Contoh pesan: Gas terdeteksi! Nilai = 800

Studi kasus: - Alarm gas - Alarm kebakaran - Deteksi gerakan

------------------------------------------------------------------------

## 19. Blynk Notification

Contoh:

``` cpp
Blynk.logEvent(
"gas_alert",
"Gas terdeteksi!"
);
```

------------------------------------------------------------------------

## 20. Multi Sensor Smart Home

Komponen: - ESP32 - DHT - LDR - PIR - MQ2 - LED - Buzzer

Widget Blynk: - V0 → Suhu - V1 → Kelembaban - V2 → Cahaya - V3 →
Gerakan - V4 → Gas - V5 → Status

------------------------------------------------------------------------

## Tips Post Test

Gunakan pola umum:

``` cpp
bacaSensor();

if(nilai > ambang){
aktifkanAktuator();
}
else{
matikanAktuator();
}
```
