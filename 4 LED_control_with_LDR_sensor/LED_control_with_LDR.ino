/*
MATERIAL LIST:
⚫ LDR (Light Dependent Resistor);
⚫ Resistor de 10k ohms (10k ohm resistor);
⚫ 1 Arduino UNO;
⚫ Protoboard (Breadboard);
⚫ Jumpers de ligação (Connection jumpers);
*/

#define AnalogLDR A0 // Define o pino analógico A0 para a leitura do sensor LDR (sensor de luz)
                     // Defines analog pin A0 for reading the LDR (Light Dependent Resistor) sensor

#define Limiar 1.5 // Define uma constante de limiar de 1.5 volts para acionar o LED
                   // Defines a threshold constant of 1.5 volts to trigger the LED

#define ledPin 13 // Define o pino digital D13 para o controle do LED
                  // Defines digital pin D13 for LED control

int Leitura = 0; // Declara uma variável inteira chamada 'Leitura' e a inicializa com 0, usada para armazenar o valor lido do LDR
                 // Declares an integer variable named 'Leitura' and initializes it to 0, used to store the value read from the LDR

float VoltageLDR; // Declara uma variável do tipo float chamada 'VoltageLDR', usada para armazenar a tensão calculada com base na leitura do LDR
                  // Declares a float variable named 'VoltageLDR', used to store the voltage calculated based on the LDR reading

void setup() {
  pinMode(ledPin, OUTPUT); // Configura o pino D13 como saída digital, permitindo o controle do LED
                           // Sets pin D13 as a digital output, allowing control of the LED

  Serial.begin(9600); // Inicializa a comunicação serial com o monitor serial a 9600 bits por segundo (bps), para enviar dados ao computador
                      // Initializes serial communication with the serial monitor at 9600 bits per second (bps), to send data to the computer

  delay(100); // Introduz um atraso de 100 milissegundos para garantir que o sistema esteja pronto antes de iniciar o loop principal
              // Introduces a 100 millisecond delay to ensure the system is ready before starting the main loop
}

void loop() {
  Leitura = analogRead(AnalogLDR); // Lê o valor analógico do LDR conectado ao pino A0 e armazena em 'Leitura'
                                   // Reads the analog value from the LDR connected to pin A0 and stores it in 'Leitura'

  VoltageLDR = Leitura * (5.0 / 1024); // Converte o valor lido em uma tensão em volts; 5V/1024 converte 0-1023 para 0-5V
                                       // Converts the read value into a voltage in volts; 5V/1024 converts 0-1023 to 0-5V

  Serial.print("Leitura sensor LDR = "); // Imprime "Leitura sensor LDR = " no monitor serial para indicar a leitura atual do sensor
                                         // Prints "Leitura sensor LDR = " on the serial monitor to indicate the current sensor reading

  Serial.println(VoltageLDR); // Imprime a tensão calculada do LDR no monitor serial e pula para a próxima linha
                              // Prints the calculated LDR voltage on the serial monitor and moves to the next line

  if (VoltageLDR > Limiar) { // Verifica se a tensão do LDR é maior que o limiar; se sim, acende o LED
                             // Checks if the LDR voltage is greater than the threshold; if so, turns on the LED
    digitalWrite(ledPin, HIGH); // Liga o LED aplicando 5V ao pino D13
                                // Turns on the LED by applying 5V to pin D13
  } else { // Se a tensão do LDR for menor ou igual ao limiar, o LED é desligado
           // If the LDR voltage is less than or equal to the threshold, the LED is turned off
    digitalWrite(ledPin, LOW); // Desliga o LED aplicando 0V ao pino D13
                               // Turns off the LED by applying 0V to pin D13
  }

  delay(500); // Introduz um atraso de 500 milissegundos antes de repetir o loop, para leitura estável e controle do LED
              // Introduces a 500 millisecond delay before repeating the loop, for stable reading and LED control
}
