#define sensorPin1 A0 // Define 'sensorPin1' como a entrada analógica A0, onde o primeiro sensor (ou divisor de tensão) está conectado
                     // Defines 'sensorPin1' as the analog input A0, where the first sensor (or voltage divider) is connected

#define sensorPin2 A1 // Define 'sensorPin2' como a entrada analógica A1, onde o segundo sensor (ou divisor de tensão) está conectado
                     // Defines 'sensorPin2' as the analog input A1, where the second sensor (or voltage divider) is connected

int sensorValue1 = 0; // Declara uma variável inteira chamada 'sensorValue1' e a inicializa com 0, usada para armazenar o valor lido do sensor conectado a A0
                      // Declares an integer variable named 'sensorValue1' and initializes it to 0, used to store the value read from the sensor connected to A0

int sensorValue2 = 0; // Declara uma variável inteira chamada 'sensorValue2' e a inicializa com 0, usada para armazenar o valor lido do sensor conectado a A1
                      // Declares an integer variable named 'sensorValue2' and initializes it to 0, used to store the value read from the sensor connected to A1

float voltage1; // Declara uma variável do tipo float chamada 'voltage1', usada para armazenar o valor da tensão calculada com base na leitura de 'sensorValue1'
                // Declares a float variable named 'voltage1', used to store the voltage value calculated based on the reading from 'sensorValue1'

float voltage2; // Declara uma variável do tipo float chamada 'voltage2', usada para armazenar o valor da tensão calculada com base na leitura de 'sensorValue2'
                // Declares a float variable named 'voltage2', used to store the voltage value calculated based on the reading from 'sensorValue2'

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial com o monitor serial a uma velocidade de 9600 bits por segundo (bps), permitindo que o Arduino envie dados para o computador
                      // Initializes serial communication with the serial monitor at a speed of 9600 bits per second (bps), allowing the Arduino to send data to the computer

  delay(100); // Introduz um atraso de 100 milissegundos, garantindo que o sistema esteja pronto antes de iniciar o loop principal
              // Introduces a delay of 100 milliseconds, ensuring the system is ready before starting the main loop
}

void loop() {
  // Leitura dos valores dos sensores (ou divisores de tensão) conectados às entradas analógicas A0 e A1
  // Reading the values from the sensors (or voltage dividers) connected to analog inputs A0 and A1
  sensorValue1 = analogRead(sensorPin1); // Lê o valor da entrada analógica A0 (um valor entre 0 e 1023) e armazena em 'sensorValue1'
                                         // Reads the value from analog input A0 (a value between 0 and 1023) and stores it in 'sensorValue1'
  sensorValue2 = analogRead(sensorPin2); // Lê o valor da entrada analógica A1 (um valor entre 0 e 1023) e armazena em 'sensorValue2'
                                         // Reads the value from analog input A1 (a value between 0 and 1023) and stores it in 'sensorValue2'

  // Conversão dos valores lidos para tensões correspondentes
  // Converting the read values to corresponding voltages
  voltage1 = sensorValue1 * (5.0 / 1024); // Calcula a tensão em volts para 'sensorValue1'; a relação 5.0/1024 converte o valor de 0-1023 para 0-5V
                                          // Calculates the voltage in volts for 'sensorValue1'; the ratio 5.0/1024 converts the value from 0-1023 to 0-5V
  voltage2 = sensorValue2 * (5.0 / 1024); // Calcula a tensão em volts para 'sensorValue2' usando a mesma relação de conversão
                                          // Calculates the voltage in volts for 'sensorValue2' using the same conversion ratio

  // Envia os valores de tensão calculados para o monitor serial para visualização
  // Sends the calculated voltage values to the serial monitor for visualization
  Serial.print("Tensao do divisor 1: "); // Imprime a mensagem "Tensao do divisor 1: " no monitor serial
                                         // Prints the message "Tensao do divisor 1: " to the serial monitor
  Serial.print(voltage1); // Imprime o valor da tensão calculada para o sensor 1 (voltage1) no monitor serial
                          // Prints the calculated voltage value for sensor 1 (voltage1) to the serial monitor
  Serial.print(" Tensao do divisor 2: "); // Imprime a mensagem " Tensao do divisor 2: " no monitor serial
                                          // Prints the message " Tensao do divisor 2: " to the serial monitor
  Serial.println(voltage2); // Imprime o valor da tensão calculada para o sensor 2 (voltage2) e move o cursor para a próxima linha no monitor serial
                            // Prints the calculated voltage value for sensor 2 (voltage2) and moves the cursor to the next line on the serial monitor

  delay(500); // Introduz um atraso de 500 milissegundos antes de repetir o loop, fazendo com que as leituras e a saída no monitor serial ocorram a cada meio segundo
              // Introduces a delay of 500 milliseconds before repeating the loop, causing readings and serial monitor output to occur every half-second
}
