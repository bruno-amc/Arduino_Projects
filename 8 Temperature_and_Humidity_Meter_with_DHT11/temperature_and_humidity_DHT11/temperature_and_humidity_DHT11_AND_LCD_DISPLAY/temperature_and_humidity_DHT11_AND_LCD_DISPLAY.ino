//Temperature and Humidity Meter with DHT11 AND WITH LCD DISPLAY!!


#include <Adafruit_Sensor.h> // Biblioteca DHT Sensor Adafruit
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h> // Biblioteca para o LCD

// Definições do DHT
#define DHTTYPE DHT11 // Sensor DHT11
#define DHTPIN 8 // Alterado para pino digital 8 do Arduino
DHT_Unified dht(DHTPIN, DHTTYPE); // configurando o Sensor DHT - pino e tipo
uint32_t delayMS = 500; // variável para atraso no tempo

// Definições do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do RS, E, D4, D5, D6, D7

void setup()
{
  // Inicialização do monitor serial e do LCD
  Serial.begin(9600); // monitor serial 9600 bps
  lcd.begin(16, 2); // Inicia o LCD 16x2
  lcd.print("DHT Sensor"); // Mensagem inicial no LCD

  dht.begin(); // inicializa o sensor DHT
  Serial.println("Usando o Sensor DHT");
}

void loop()
{
  delay(delayMS); // atraso entre as medições
  sensors_event_t event;

  // Leitura da Temperatura
  dht.temperature().getEvent(&event); // faz a leitura da Temperatura
  if (isnan(event.temperature)) // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Temperatura!");
    lcd.setCursor(0, 0);
    lcd.print("Erro Temp");
  }
  else // senão
  {
    Serial.print("Temperatura: ");
    Serial.print(event.temperature);
    Serial.println(" *C");

    // Exibir a temperatura no LCD
    lcd.setCursor(0, 0); // Posição no LCD (linha 0, coluna 0)
    lcd.print("Temp: ");
    lcd.print(event.temperature);
    lcd.print(" C");
  }

  // Leitura da Umidade
  dht.humidity().getEvent(&event); // faz a leitura de umidade
  if (isnan(event.relative_humidity)) // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Umidade!");
    lcd.setCursor(0, 1);
    lcd.print("Erro Umidade");
  }
  else // senão
  {
    Serial.print("Umidade: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");

    // Exibir a umidade no LCD
    lcd.setCursor(0, 1); // Posição no LCD (linha 1, coluna 0)
    lcd.print("Umid: ");
    lcd.print(event.relative_humidity);
    lcd.print("%");
  }
}

