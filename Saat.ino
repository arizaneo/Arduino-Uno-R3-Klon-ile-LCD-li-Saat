#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

virtuabotixRTC myRTC(6, 7, 8); // CLK, DAT, RST

// LCD'nin I2C adresini ve boyutunu belirtin
// Genellikle 0x27 veya 0x3F'dir, deneyerek bulabilirsiniz.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  // İlk yüklemede zamanı ayarlamak için:
//myRTC.setDS1302Time(30, 38, 22, 3, 27, 8, 2025); // saniye, dakika, saat, hafta günü, gün, ay, yıl


// LCD'yi başlat ve arka ışığını aç
  lcd.init();
  lcd.backlight();
}

void loop() {
  // RTC modülünden zamanı güncelle
  myRTC.updateTime();

  // Seri Monitör'e saat ve tarihi yazdır
  Serial.print("Tarih: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("   Saat: ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
  
  // LCD'ye saat ve tarihi yazdır
  // Saat ve tarih bilgisi için her seferinde ekranı temizle
  lcd.clear(); 
  
  // İlk satıra saati yazdır
  lcd.setCursor(0, 0);
  lcd.print("Saat ");
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);

  // İkinci satıra tarihi yazdır
  lcd.setCursor(0, 1);
  lcd.print("Tarih ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);

  delay(1000); // 1 saniye bekle
}
