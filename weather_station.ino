#include <DHT.h>
#include <Wire.h>                    // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>       // Include the LCD I2C library
#define DHTPIN 8                     // Pin to which DHT11 data pin is connected uno
#define DHTTYPE DHT11                // DHT type is DHT11
DHT dht(DHTPIN, DHTTYPE);            // Initialize DHT sensor object
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16x2 display //A4-sda , A5-SCl

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  dht.begin();         // Initialize DHT sensor
  lcd.init();          // Initialize the LCD display
  lcd.backlight();     // Turn on the backlight
  lcd.setCursor(3, 0);
  lcd.print("welcome to");
  lcd.setCursor(0, 1);           // Set cursor to the first column of the first row
  lcd.print("weather station");  //school name
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("");        //school name line 1
  lcd.setCursor(0, 1);  // Set cursor to the first column of the first row

  lcd.print("");  //school name line 2

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");  // Print "TEMP:" on the LCD
  lcd.setCursor(0, 1);  // Set cursor to the first column of the second row
  lcd.print("HUMI: ");  // Print "HUMI:" on the LCD
}


void loop() {
  delay(2000);  // Wait for 2 seconds between measurements
  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  // Check if any reads failed and exit early (to try again)
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  // Update LCD display
  lcd.setCursor(6, 0);     // Set cursor to the seventh column of the first row
  lcd.print(" ");          // Clear previous temperature reading
  lcd.setCursor(6, 0);     // Reset cursor position
  lcd.print(temperature);  // Print temperature
  lcd.print(" C");         // Print temperature unit
  lcd.setCursor(6, 1);     // Set cursor to the seventh column of the second row
  lcd.print(" ");          // Clear previous humidity reading
  lcd.setCursor(6, 1);     // Reset cursor position
  lcd.print(humidity);     // Print humidity
  lcd.print(" %");         // Print humidity unit
}
