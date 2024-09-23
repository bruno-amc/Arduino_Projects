#include <LiquidCrystal.h>

// Definir os pinos do LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Definir variáveis para horas, minutos e segundos
int segundos = 0;
int minutos = 0;
int horas = 0;

void setup() {
  lcd.begin(16, 2); // Inicializa o LCD 16x2
  delay(500); // Atraso de 0,5 segundos
  lcd.clear(); // Limpa a tela do LCD
  lcd.setCursor(0, 0); // Seleciona coluna 0 e linha 0
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

  // Atraso de 1 segundo para a próxima contagem
  delay(1000);
}