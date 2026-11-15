#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// הגדרת פינים ל-I2C וכתובת המסך (בדרך כלל 0x27)
#define I2C_SDA 4
#define I2C_SCL 5
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // אתחול ערוץ ה-I2C בפינים שבחרנו
  Wire.begin(I2C_SDA, I2C_SCL);

  // אתחול המסך והדלקת תאורה אחורית
  lcd.init();

  // כתיבה בשורה הראשונה
  lcd.setCursor(0, 0);
  lcd.print("eyal ya homo");
}

void loop()
{
  // כתיבה בשורה השנייה: ספירת שניות
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis() / 1000);
  lcd.print("s   ");

  delay(500);
}

/* led on\off every sec
void loop()
{
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED State: ON");
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED State: OFF");
  delay(1000);
}*/