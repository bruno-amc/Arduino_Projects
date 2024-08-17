// MATERIAL LIST
// 1 resistor of 330 ohms;
// 1 resistor of 10 kohms;
// 1 red LED (or another color of your choice);
// Push-button (switch button);
// 1 Arduino UNO;
// Breadboard;
// Connection jumpers;


#define PinButton 8 // Define o pino digital D8 como o pino onde o botão está conectado
                   // Defines digital pin D8 as the pin where the button is connected

#define ledPin 7 // Define o pino digital D7 como o pino onde o LED está conectado
                 // Defines digital pin D7 as the pin where the LED is connected

void setup() {
  pinMode(PinButton, INPUT); // Configura o pino D8 como entrada digital, para ler o estado do botão
                             // Sets pin D8 as a digital input, to read the state of the button

  pinMode(ledPin, OUTPUT); // Configura o pino D7 como saída digital, para controlar o LED
                           // Sets pin D7 as a digital output, to control the LED

  Serial.begin(9600); // Inicializa a comunicação serial com o monitor serial a 9600 bits por segundo (bps)
                      // Initializes serial communication with the serial monitor at 9600 bits per second (bps)

  delay(100); // Introduz um atraso de 100 milissegundos para garantir que o sistema esteja estabilizado antes de iniciar o loop principal
              // Introduces a 100 millisecond delay to ensure the system is stabilized before starting the main loop
}

void loop() {
  if (digitalRead(PinButton) == HIGH) // Verifica se o botão está pressionado (nível lógico alto)
                                      // Checks if the button is pressed (logical high level)
  {
    digitalWrite(ledPin, HIGH); // Acende o LED aplicando 5V ao pino D7
                                // Turns on the LED by applying 5V to pin D7

    Serial.print("Acendendo Led"); // Imprime "Acendendo Led" no monitor serial para indicar que o LED está ligado
                                   // Prints "Acendendo Led" on the serial monitor to indicate the LED is on
  }
  else // Caso contrário, se o botão não estiver pressionado (nível lógico baixo)
       // Otherwise, if the button is not pressed (logical low level)
  {
    digitalWrite(ledPin, LOW); // Apaga o LED aplicando 0V ao pino D7
                               // Turns off the LED by applying 0V to pin D7

    Serial.print("Desligando led"); // Imprime "Desligando led" no monitor serial para indicar que o LED está desligado
                                    // Prints "Desligando led" on the serial monitor to indicate the LED is off
  }

  delay(100);
