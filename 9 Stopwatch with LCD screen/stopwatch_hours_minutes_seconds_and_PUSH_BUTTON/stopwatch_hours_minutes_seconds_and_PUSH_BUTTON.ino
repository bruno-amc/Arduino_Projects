/* 
connect the push button to a positive wire (5V) and the other side of it to Pin 2 Digital

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

// Definir os pinos do LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Definir variáveis para horas, minutos e segundos
int segundos = 0;
int minutos = 0;
int horas = 0;

const int buttonPin = 2; // Pino onde o botão está conectado
int buttonState = 0; // Variável para armazenar o estado do botão
unsigned long buttonPressTime = 0; // Tempo de quando o botão foi pressionado
bool buttonHeld = false; // Indica se o botão está sendo mantido pressionado
const unsigned long holdTime = 3000; // Tempo necessário para zerar (3 segundos)

void setup() {
  lcd.begin(16, 2); // Inicializa o LCD 16x2
  pinMode(buttonPin, INPUT_PULLUP); // Configura o pino do botão com pull-up interno
  delay(500); // Atraso de 0,5 segundos
  lcd.setCursor(3, 0); // Seleciona coluna 3 e linha 0
  lcd.print("Bem-vindo"); //mensagem exibida só quando liga
  delay(3000);
}

void loop() {
  lcd.clear(); // Limpa a tela do LCD
  lcd.setCursor(0, 0); // Seleciona coluna 0 e linha 0
  lcd.print("Cronometro:");

  // Exibir horas, minutos e segundos no LCD
  lcd.setCursor(0, 1); // Seleciona coluna 0 e linha 1
  lcd.print(horas);
  lcd.print("h ");
  lcd.print(minutos);
  lcd.print("min ");
  lcd.print(segundos);
  lcd.print("seg");

  // Incrementar o tempo
  segundos++;

  // Lógica para atualizar minutos e horas
  if (segundos == 60) {
    segundos = 0;
    minutos++; // Incrementa minutos quando segundos chegam a 60
  }

  if (minutos == 60) {
    minutos = 0;
    horas++; // Incrementa horas quando minutos chegam a 60
  }

  // Ler o estado do botão
  buttonState = digitalRead(buttonPin);

  // Se o botão estiver pressionado (estado LOW)
  if (buttonState == LOW) {
    if (!buttonHeld) {
      buttonHeld = true; // O botão foi pressionado
      buttonPressTime = millis(); // Armazena o momento em que o botão foi pressionado
    }

    // Verifica se o botão foi mantido pressionado por 3 segundos
    if (millis() - buttonPressTime >= holdTime) {
      // Se o botão estiver pressionado por 3 segundos, zere o cronômetro
      horas = 0;
      minutos = 0;
      segundos = 0;
      buttonHeld = false; // Reseta o estado do botão para evitar zerar repetidamente
    }
  } else {
    // Se o botão foi solto antes de 3 segundos, resete o estado
    buttonHeld = false;
  }

  // Atraso de 1 segundo para a próxima contagem
  delay(1000);
}
