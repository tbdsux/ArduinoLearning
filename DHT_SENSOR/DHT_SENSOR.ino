#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define DELAY_TIME 2000

DHT dht(DHTPIN, DHTTYPE);

float temp;
int humidity;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(DELAY_TIME);

  temp = dht.readTemperature();
  humidity = dht.readHumidity();

  // display temp
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" \xDF""C");

  // display humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");
}
