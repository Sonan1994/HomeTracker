#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht = DHT(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  Serial.begin(9600);

  dht.begin();
  lcd.begin();
}

void loop() 
{
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read data from DHT sensor");
    return;  
  }

  lcd.clear();
  lcd.print("Humidity: ");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");
}
