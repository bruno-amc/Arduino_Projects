/*

Conexões do Sensor Ultrassônico (HC-SR04):
Trigger (Trig): Conecte ao pino digital 13 do Arduino.
Echo: Conecte ao pino digital 3 do Arduino.
VCC: Conecte ao 5V do Arduino.
GND: Conecte ao GND do Arduino.


Conexões do LCD 16x2:
Pino do LCD	Conexão no Arduino
VSS (Pino 1)	GND
VDD (Pino 2)	5V
VO (Pino 3)	Potenciômetro ou GND (para ajuste de contraste)
RS (Pino 4)	Pino digital 8
RW (Pino 5)	GND
E (Pino 6)	Pino digital 9
D4 (Pino 11)	Pino digital 4
D5 (Pino 12)	Pino digital 5
D6 (Pino 13)	Pino digital 6
D7 (Pino 14)	Pino digital 7
A (Pino 15)	5V (para o backlight)
K (Pino 16)	GND (para o backlight)
*/




#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int PinTrigger = 13; // pino usado para disparar os pulsos do sensor
int PinEcho = 3; // pino usado para ler a saida do sensor
float TempoEcho = 0; // variável tempo do eco
const float velocidadeSom_mps = 340; // em metros por segundo
const float velocidadeSom_mpus = 0.000340; // em metros por microsegundo
void setup() {
pinMode(PinTrigger, OUTPUT); // configura pino Trigger como saída
digitalWrite(PinTrigger, LOW); // pino trigger - nível baixo
pinMode(PinEcho, INPUT); // configura pino ECHO como entrada
Serial.begin(9600); // inicializa monitor serial 9600 Bps
lcd.begin(16, 2);
delay(100); // atraso de 100 milisegundos
}
void loop() {
DisparaPulsoUltrassonico(); // dispara pulso ultrassonico
TempoEcho = pulseIn(PinEcho, HIGH); // mede duração do pulso HIGH de eco em micro seg
Serial.print("Distancia em metros: "); // mostra no monitor serial
Serial.println(CalculaDistancia(TempoEcho)); // mostra o calculo de distancia em metros
Serial.print("Distancia em centimentros: "); // mostra no monitor serial
Serial.println(CalculaDistancia(TempoEcho) * 100); // mostra o calculo de distancia em cm
lcd.clear(); // limpa tela do LCD
  // Exibe a distância em centímetros na primeira linha
lcd.setCursor(0, 0); // Coluna 0, linha 0 (primeira linha)
lcd.print(CalculaDistancia(TempoEcho) * 100);
lcd.print("cm");

  // Exibe a distância em metros na segunda linha
lcd.setCursor(0, 1); // Coluna 0, linha 1 (segunda linha)
lcd.print(CalculaDistancia(TempoEcho));
lcd.print("m");
delay(2000); // atraso de 2 segundos
}


void DisparaPulsoUltrassonico()
{
digitalWrite(PinTrigger, HIGH); // pulso alto de Trigger
delayMicroseconds(10); // atraso de 10 microsegundos
digitalWrite(PinTrigger, LOW); // pulso baixo de Trigger
}
float CalculaDistancia(float tempo_us)
{
return ((tempo_us * velocidadeSom_mpus) / 2 ); // calcula distancia em metros
}