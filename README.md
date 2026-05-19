# IoT Post Test Blynk + Wokwi

Template ini dibuat untuk latihan post test Praktikum Embedded System bagian IoT.

Semua project memakai:
- ESP32
- WiFi Wokwi: `Wokwi-GUEST`
- Blynk
- Virtual Pin
- Sensor + aktuator LED/Buzzer/Relay

Cara pakai:
1. Buka folder sesuai sensor/studi kasus.
2. Copy `diagram.json` dan `sketch.ino` ke project Wokwi.
3. Ganti:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_TEMPLATE_NAME`
   - `BLYNK_AUTH_TOKEN`
4. Buat widget Blynk sesuai Virtual Pin di README masing-masing folder.
5. Jalankan simulasi.

Catatan:
- Di Wokwi, DHT11 bisa diganti DHT22. Kalau pakai DHT11 asli, ubah `DHTTYPE DHT11`.
- Relay/pompa di Wokwi sering disimulasikan dengan LED.
