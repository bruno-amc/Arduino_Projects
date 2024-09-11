/*
MATERIAL LIST:
⚫ Micro Servo 9g SG90 TowerPro;
⚫ Arduino UNO + USB cable;
⚫ Potentiometer 10k;
⚫ 5V source to power the servo;
⚫ Jumpers;
⚫ Push button;
*/

#include <Servo.h>
Servo myservo; //cria o objeto meuservo / creates the object myservo
#define potpin A0 //define o pino analógico A0

int val;
void setup(){
  myservo.attach(6); //configura o pino D6 - Controle do servo / set pin 6 - servo control
  Serial.begin(9600);
}

void loop()
{
val = analogRead(potpin); // leitura da tensão no pino A0
Serial.print("valor da leitura analógica: ");
Serial.println(val); //valor da leitura analógica
val = map(val, 0, 1023, 0, 179); // converte a leitura em números (0-179)
myservo.write(val); // controle PWM do servo
Serial.println(val);
delay(15); // atraso de 15 milisegundos
}

